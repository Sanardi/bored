#ifndef LOCALE_USER_DEFAULT
	LOCALE_USER_DEFAULT equ 0400H
#endif
#ifndef LOCALE_NOUSEROVERRIDE
	LOCALE_NOUSEROVERRIDE equ 080000000H
#endif

macro Return marg dqValue
	mov rax, dqValue
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

macro HiDWord marg dqDWord
    mov rax, dqDWord
    bswap rax
    bswap eax
endm

macro LoDWord marg dqDWord
    mov rax, dqDWord
    or eax, eax
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

macro MakeQWord marg dwordLow, dwordHigh
	push rcx
    mov ecx, dwordHigh
    shl rcx, 32
    mov eax, dwordLow
	or rax, rcx
	pop rcx
endm

macro Color marg byteRed, byteGreen, byteBlue
    xor eax, eax
    mov ah, byteBlue
    mov al, byteGreen
    shl eax, 8
    mov al, byteRed
endm

macro Move marg dqValue1, dqValue2
	push dqValue2
	pop dqValue1
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
	push rsi
	push rdi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov rsi, rax
	invoke GetSystemTime, rsi
	mov rdi, rsi
	add rdi, 64
	invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, rsi, NULL, rdi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, rdi
	invoke GlobalFree, rsi
	pop rdi
	pop rsi
endm

macro Now marg lpszStrPtr
	push rsi
	push rdi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov rsi, rax
	invoke GetSystemTime, rsi
	mov rdi, rsi
	add rdi, 64
	invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, rsi, NULL, rdi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, rdi
	invoke lstrcat, lpszStrPtr, ' - '
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, rsi, NULL, rdi, MAX_PATH - 65
	invoke lstrcat, lpszStrPtr, rdi
	invoke GlobalFree, rsi
	pop rdi
	pop rsi
endm

macro Time marg lpszStrPtr
	push rsi
	push rdi
	invoke GlobalAlloc, GPTR, MAX_PATH
	mov rsi, rax
	invoke GetSystemTime, rsi
	mov rdi, rsi
	add rdi, 64
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, rsi, NULL, rdi, MAX_PATH - 65
	invoke lstrcpy, lpszStrPtr, rdi
	invoke GlobalFree, rsi
	pop rdi
	pop rsi
endm

macro Swap marg dqValue1, dqValue2
	push dqValue1
	push dqValue2
	pop dqValue1
	pop dqValue2
endm
