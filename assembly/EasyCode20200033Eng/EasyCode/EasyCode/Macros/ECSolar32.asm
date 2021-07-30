#ifndef LOCALE_USER_DEFAULT
	LOCALE_USER_DEFAULT equ 0400H
#endif
#ifndef LOCALE_NOUSEROVERRIDE
	LOCALE_NOUSEROVERRIDE equ 080000000H
#endif
macro Return marg dwValue
	mov eax, dwValue
	ret
endm

macro HiByte marg wWord
	mov ax, wWord
	shr ax, 8
endm

macro LoByte marg wWord
	mov ax, wWord
	and ax, 00FFh
endm

macro HiWord marg dwDWord
	mov eax, dwDWord
	shr eax, 16
endm

macro LoWord marg dwDWord
	mov eax, dwDWord
	and eax, 0000FFFFH
endm

macro MakeWord marg byteLow, byteHigh
	mov ah, byteHigh
	mov al, byteLow
endm

macro MakeLong marg wordLow, wordHigh
	mov ax, wordHigh
	shl eax, 16
	or ax, wordLow
endm

macro Color marg byteRed, byteGreen, byteBlue
    xor eax, eax
    mov ah, byteBlue
    mov al, byteGreen
    shl eax, 8
    mov al, byteRed
endm

macro Move marg dwValue1, dwValue2
	push dwValue2
	pop dwValue1
endm

macro TextA marg Name, quoted_text
	jmp @L1
	Name db quoted_text,0,0
@L1:
endm

macro TextW marg Name, quoted_text
	jmp @L1
	Name du quoted_text,0,0
@L1:
endm

macro Text marg Name, quoted_text
	#ifdef APP_UNICODE
		TextW Name, quoted_text
	#else
		TextA Name, quoted_text
	#endif
endm

macro TextAddrA marg quoted_text
    .data
    @ECvname db quoted_text,0
    .code
    exitm @ECvname
endm

macro TextAddrW marg quoted_text
    .data
    @ECvname du quoted_text,0
    .code
    exitm @ECvname
endm

macro TextAddr marg quoted_text
	#ifdef APP_UNICODE
    	TextAddrW quoted_text
	#else
    	TextAddrA quoted_text
	#endif
endm

macro TextStrA marg quoted_text
	TextAddrA quoted_text
endm

macro TextStrW marg quoted_text
	TextAddrW quoted_text
endm

macro TextStr marg quoted_text
	#ifdef APP_UNICODE
    	TextAddrW quoted_text
	#else
    	TextAddrA quoted_text
	#endif
endm

macro Date marg lpszStrPtr
	push esi
	push edi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov esi, eax
	invoke GetSystemTime, esi
	mov edi, esi
	add edi, 64
	invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, esi, NULL, edi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, edi
	invoke GlobalFree, esi
	pop edi
	pop esi
endm

macro Now marg lpszStrPtr
	push esi
	push edi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov esi, eax
	invoke GetSystemTime, esi
	mov edi, esi
	add edi, 64
	invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, esi, NULL, edi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, edi
	invoke lstrcat, lpszStrPtr, " - "
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, esi, NULL, edi, MAX_PATH - 65
	invoke lstrcat, lpszStrPtr, edi
	invoke GlobalFree, esi
	pop edi
	pop esi
endm

macro Time marg lpszStrPtr
	push esi
	push edi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov esi, eax
	invoke GetSystemTime, esi
	mov edi, esi
	add edi, 64
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, esi, NULL, edi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, edi
	invoke GlobalFree, esi
	pop edi
	pop esi
endm

macro Swap marg dwValue1, dwValue2
    push dwValue1
    push dwValue2
    pop dwValue1
    pop dwValue2
endm
