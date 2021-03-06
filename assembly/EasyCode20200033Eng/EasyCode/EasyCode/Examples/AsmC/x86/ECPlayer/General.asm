;EasyCodeName=General,1
.Const

.Data?

szString				Byte	MAX_PATH	Dup(?)	;General purpose
rect					RECT	<?> 				;General purpose


.Data

szArial					Byte	'Arial', 0	;Normal letter
szQuartzDB				Byte	'Quartz DB', 0	;Digital letter
szRegistrySubKey		Byte	'Software\RSC Products\EC Player\Settings', 0

szChar					Byte	' ', 0

; String for current drive (after initialization, remove backslash)
szCurrentDrive			Byte			'C:\', 0

; Flags for EC Player options
bAutoPlay				BOOL	FALSE
bBothChannels			BOOL	FALSE
bLedFont				BOOL	TRUE
bRepeatOff				BOOL 	TRUE
bSoundOn				BOOL	TRUE
bSaveChanges			BOOL	TRUE
bStopWhenExit			BOOL	TRUE

; Handle for wndMain Play list
hwndPlayList			HWND	NULL
hwndTracks				HWND	NULL

; Total tracks for current CD
lCDTracks				LONG	0

; Number of channels
lChannels				LONG	0

; String for Play list name
szPlayListName			Byte	MAX_PATH Dup(0)


.Code

AddChar Proc Uses Esi lpszBuffer:LPSTR, sChar:CHAR
	Mov Esi, Offset szChar
	Mov Al, sChar
	Mov Byte Ptr [Esi], Al
	Invoke lstrcat, lpszBuffer, Esi
	Ret
AddChar EndP

;Gets / Sets registry settings (depending on bSave flag)
RegistrySettings Proc bSave:BOOL
	Local hControl:HWND

	Text szLedFont, "LedFont"
	.If bSave
		Invoke StringA, bLedFont, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szLedFont, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '0'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szLedFont, Addr szString
		Invoke ValueA, Addr szString
		Mov bLedFont, Eax
	.EndIf
	Invoke GetWindowItem, App.Main, IDC_WNDMAIN_PICTIME
	Mov hControl, Eax
	.If bLedFont
		Invoke GetFontFileName, Addr szString
		Cmp Eax, INVALID_HANDLE_VALUE
		Je @F
		Invoke SetLeft, hControl, 236
		Invoke SetTop, hControl, 1
		Invoke SetFontName, hControl, Addr szQuartzDB
	.Else
@@:		Invoke SetLeft, hControl, 235
		Invoke SetTop, hControl, 3
		Invoke SetFontName, hControl, Addr szArial
		Invoke SetFontBold, hControl, FALSE
	.EndIf
	Text szSoundOn, "SoundOn"
	.If bSave
		Invoke StringA, bSoundOn, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSoundOn, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '1'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSoundOn, Addr szString
		Invoke ValueA, Addr szString
		Mov bSoundOn, Eax
		Invoke GetWindowItem, App.Main, IDC_WNDMAIN_IMGSOUND
		.If bSoundOn
			Invoke SetPicture, Eax, IDB_SOUND_ON_UP
		.Else
			Invoke SetPicture, Eax, IDB_SOUND_OFF
		.EndIf
	.EndIf
	Text szAutoPlay, "AutoPlay"
	.If bSave
		Invoke StringA, bAutoPlay, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szAutoPlay, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '1'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szAutoPlay, Addr szString
		Invoke ValueA, Addr szString
		Mov bAutoPlay, Eax
	.EndIf
	Text szStopWhenExit, "StopWhenExit"
	.If bSave
		Invoke StringA, bStopWhenExit, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szStopWhenExit, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '1'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szStopWhenExit, Addr szString
		Invoke ValueA, Addr szString
		Mov bStopWhenExit, Eax
	.EndIf
	Text szSaveChanges, "SaveChanges"
	.If bSave
		Invoke StringA, bSaveChanges, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSaveChanges, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '0'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szSaveChanges, Addr szString
		Invoke ValueA, Addr szString
		Mov bSaveChanges, Eax
	.EndIf
	Text szBothChannels, "BothChannels"
	.If bSave
		Invoke StringA, bBothChannels, Addr szString, ecDecimal
		Invoke SetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szBothChannels, Addr szString
	.Else
		Xor Ah, Ah
		Mov Al, '1'
		Mov Word Ptr szString[0], Ax
		Invoke GetRegistryValueA, ecCurrentUser, Addr szRegistrySubKey, Addr szBothChannels, Addr szString
		Invoke ValueA, Addr szString
		Mov bBothChannels, Eax
	.EndIf
	Ret
RegistrySettings EndP
