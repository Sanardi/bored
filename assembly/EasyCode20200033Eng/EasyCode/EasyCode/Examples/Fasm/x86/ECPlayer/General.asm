;EasyCodeName=General,1
section '.data' data readable writeable

szString				db		MAX_PATH	dup(0)	;General purpose

szArial					db		'Arial', 0			;Normal letter
szQuartzDB				db		'Quartz DB', 0		;Digital letter
szRegistrySubKey		db		'Software\RSC Products\EC Player\Settings', 0

szChar					db		VK_SPACE, 0

;String for current drive (after initialization, remove backslash)
szCurrentDrive			db		'C:\', 0

;Flags for EC Player options
bAutoPlay				dd		FALSE
bBothChannels			dd		FALSE
bLedFont				dd		TRUE
bRepeatOff				dd	 	TRUE
bSoundOn				dd		TRUE
bSaveChanges			dd		TRUE
bStopWhenExit			dd		TRUE

;Handle for wndMain Play list
hwndPlayList			dd		NULL
hwndTracks				dd		NULL

;Total tracks for current CD
lCDTracks				dd		0

;Number of channels
lChannels				dd		0

;String for Play list name
szPlayListName			db		MAX_PATH dup(0)


section '.text' code readable executable

proc AddChar uses esi, lpszBuffer:DWORD, lChar:DWORD
	mov esi, szChar
	mov al, BYTE [lChar]
	mov [esi], al
	invoke lstrcat, [lpszBuffer], esi
	ret
endp

;Gets / Sets registry settings (depending on bSave flag)
proc RegistrySettings bSave:DWORD
	local hControl:DWORD

	.if [bSave]
		stdcall StringA, [bLedFont], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "LedFont", szString
	.else
		invoke lstrcpy, szString, "0"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "LedFont", szString
		stdcall ValueA, szString
		mov [bLedFont], eax
	.endif
	stdcall GetWindowItem, [App.Main], IDC_WNDMAIN_PICTIME
	mov [hControl], eax
	.if [bLedFont]
		stdcall GetFontFileName, szString
		cmp eax, INVALID_HANDLE_VALUE
		je @f
		stdcall SetLeft, [hControl], 236
		stdcall SetTop, [hControl], 1
		stdcall SetFontName, [hControl], szQuartzDB
	.else
@@:		stdcall SetLeft, [hControl], 235
		stdcall SetTop, [hControl], 3
		stdcall SetFontName, [hControl], szArial
		stdcall SetFontBold, [hControl], FALSE
	.endif
	.if [bSave]
		stdcall StringA, [bSoundOn], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "SoundOn", szString
	.else
		invoke lstrcpy, szString, "1"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "SoundOn", szString
		stdcall ValueA, szString
		mov [bSoundOn], eax
		stdcall GetWindowItem, [App.Main], IDC_WNDMAIN_IMGSOUND
		.if [bSoundOn]
			stdcall SetPicture, eax, IDB_SOUND_ON_UP
		.else
			stdcall SetPicture, eax, IDB_SOUND_OFF
		.endif
	.endif
	.if [bSave]
		stdcall StringA, [bAutoPlay], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "AutoPlay", szString
	.else
		invoke lstrcpy, szString, "1"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "AutoPlay", szString
		stdcall ValueA, szString
		mov [bAutoPlay], eax
	.endif
	.if [bSave]
		stdcall StringA, [bStopWhenExit], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "StopWhenExit", szString
	.else
		invoke lstrcpy, szString, "1"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "StopWhenExit", szString
		stdcall ValueA, szString
		mov [bStopWhenExit], eax
	.endif
	.if [bSave]
		stdcall StringA, [bSaveChanges], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "SaveChanges", szString
	.else
		invoke lstrcpy, szString, "0"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "SaveChanges", szString
		stdcall ValueA, szString
		mov [bSaveChanges], eax
	.endif
	.if [bSave]
		stdcall StringA, [bBothChannels], szString, ecDecimal
		stdcall SetRegistryValueA, ecCurrentUser, szRegistrySubKey, "BothChannels", szString
	.else
		invoke lstrcpy, szString, "1"
		stdcall GetRegistryValueA, ecCurrentUser, szRegistrySubKey, "BothChannels", szString
		stdcall ValueA, szString
		mov [bBothChannels], eax
	.endif
	ret
endp
