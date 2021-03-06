;EasyCodeName=General,1
.Const


.Data

szString				DB		MAX_PATH	Dup ?	;General purpose
rect					RECT		 				;General purpose

szArial					DB		'Arial', 0	;Normal letter
szQuartzDB				DB		'Quartz DB', 0	;Digital letter
szRegistrySubKey		DB		'Software\RSC Products\EC Player\Settings', 0
szLedFont				DB		'LedFont', 0
szSoundOn				DB		'SoundOn', 0
szAutoPlay				DB		'AutoPlay', 0
szStopWhenExit			DB		'StopWhenExit', 0
szSaveChanges			DB		'SaveChanges', 0
szBothChannels			DB		'BothChannels', 0
szChar					DB		' ', 0

; String for current drive (after initialization, remove backslash)
szCurrentDrive			DB				'C:\', 0

; Flags for EC Player options
bAutoPlay				DD		FALSE
bBothChannels			DD		FALSE
bLedFont				DD		TRUE
bRepeatOff				DD	 	TRUE
bSoundOn				DD		TRUE
bSaveChanges			DD		TRUE
bStopWhenExit			DD		TRUE

; Handle for wndMain Play list
hwndPlayList			DD		NULL
hwndTracks				DD		NULL

; Total tracks for current CD
lCDTracks				DD		0

; Number of channels
lChannels				DD		0

; String for Play list name
szPlayListName			DB		MAX_PATH Dup 0


.Code

AddChar Frame lpszBuffer, sChar
	Push Esi
	Lea Esi, szChar
	Mov Al, [sChar]
	Mov [Esi], Al
	Invoke lstrcat, [lpszBuffer], Esi
	Pop Esi
	Ret
EndF

;Gets / Sets registry settings (depending on bSave flag)
RegistrySettings Frame bSave
	Local hControl:D

	Cmp D[bSave], FALSE
	Je >>
	Invoke StringA, [bLedFont], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szLedFont, Addr szString
	Invoke StringA, [bSoundOn], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSoundOn, Addr szString
	Invoke StringA, [bAutoPlay], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szAutoPlay, Addr szString
	Invoke StringA, [bStopWhenExit], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szStopWhenExit, Addr szString
	Invoke StringA, [bSaveChanges], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSaveChanges, Addr szString
	Invoke StringA, [bBothChannels], Addr szString, ecDecimal
	Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szBothChannels, Addr szString
	Jmp >> L2
:	Xor Ah, Ah
	Mov Al, '0'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szLedFont, Addr szString
	Invoke ValueA, Addr szString
	Mov [bLedFont], Eax
	Xor Ah, Ah
	Mov Al, '1'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSoundOn, Addr szString
	Invoke ValueA, Addr szString
	Mov [bSoundOn], Eax
	Invoke GetWindowItem, [App.Main], IDC_WNDMAIN_IMGSOUND
	Mov Ecx, IDB_SOUND_ON_UP
	Cmp D[bSoundOn], FALSE
	Jne >
	Mov Ecx, IDB_SOUND_OFF
:	Invoke SetPicture, Eax, Ecx
	Xor Ah, Ah
	Mov Al, '1'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szAutoPlay, Addr szString
	Invoke ValueA, Addr szString
	Mov [bAutoPlay], Eax
	Xor Ah, Ah
	Mov Al, '1'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szStopWhenExit, Addr szString
	Invoke ValueA, Addr szString
	Mov [bStopWhenExit], Eax
	Xor Ah, Ah
	Mov Al, '0'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSaveChanges, Addr szString
	Invoke ValueA, Addr szString
	Mov [bSaveChanges], Eax
	Xor Ah, Ah
	Mov Al, '1'
	Lea Ecx, szString
	Mov [Ecx], Ax
	Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szBothChannels, Addr szString
	Invoke ValueA, Addr szString
	Mov [bBothChannels], Eax
L2:	Invoke GetWindowItem, [App.Main], IDC_WNDMAIN_PICTIME
	Mov [hControl], Eax
	Cmp D[bLedFont], FALSE
	Je >
	Invoke GetFontFileName, Addr szString
	Cmp Eax, INVALID_HANDLE_VALUE
	Je >
	Invoke SetLeft, [hControl], 236
	Invoke SetTop, [hControl], 1
	Invoke SetFontName, [hControl], Addr szQuartzDB
	Jmp > L4
:	Invoke SetLeft, [hControl], 235
	Invoke SetTop, [hControl], 3
	Invoke SetFontName, [hControl], Addr szArial
	Invoke SetFontBold, [hControl], FALSE
L4:	Ret
EndF
