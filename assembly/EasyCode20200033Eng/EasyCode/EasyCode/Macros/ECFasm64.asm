if ~defined LOCALE_USER_DEFAULT
	LOCALE_NOUSEROVERRIDE equ 080000000H
	LOCALE_USER_DEFAULT equ 0400H
end if

macro Return arg
{
	mov rax, arg
	ret
}

macro HiByte wWord
{
	mov ax, wWord
	shr ax, 8
}

macro LoByte wWord
{
	mov ax, wWord
	and ax, 00FFh
}

macro HiWord dwDword
{
	mov eax, dwDword
	shr eax, 16
}

macro LoWord dwDword
{
	mov eax, dwDword
	and eax, 0000FFFFh
}

macro HiDWord dqDWord
{
    mov rax, dqDWord
    bswap rax
    bswap eax
}

macro LoDWord dqDWord
{
    mov rax, dqDWord
    or eax, eax
}

macro MakeWord byteLow, byteHigh
{
	mov ah, byteHigh
	mov al, byteLow
}

macro MakeLong wordLow, wordHigh
{
	mov ax, wordHigh
	shl eax, 16
	or ax, wordLow
}

macro MakeQWord dwordLow, dwordHigh
{
	push rcx
    mov ecx, dwordHigh
    shl rcx, 32
    mov eax, dwordLow
	or rax, rcx
	pop rcx
}

macro Color byteRed, byteGreen, byteBlue
{
    xor eax, eax
    mov ah, byteBlue
    mov al, byteGreen
    shl eax, 8
    mov al, byteRed
}

macro Move dqValue1, dqValue2
{
	push dqValue2
	pop dqValue1
}

macro TextA Name, quoted_text
{
	jmp @f
	Name:  db quoted_text,0,0
@@:
}

macro TextW Name, quoted_text
{
	jmp @f
	Name:  du quoted_text,0,0
@@:
}

macro Text Name, quoted_text
{
	if defined APP_UNICODE
		TextW Name, quoted_text
	else
		TextA Name, quoted_text
	end if
}

macro Date lpszStrPtr
{
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
}

macro Now lpszStrPtr
{
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
}

macro Time lpszStrPtr
{
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
}

macro Swap dqValue1, dqValue2
{
	push dqValue1
	push dqValue2
	pop dqValue1
	pop dqValue2
}
