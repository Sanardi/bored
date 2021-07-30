if ~defined LOCALE_USER_DEFAULT
	LOCALE_NOUSEROVERRIDE equ 080000000H
	LOCALE_USER_DEFAULT equ 0400H
end if

macro Return arg
{
	mov eax, arg
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
	and eax, 0000FFFFH
}

macro MakeWord byteLow, byteHigh
{
	push cx
	mov cl, byteLow
	mov ah, byteHigh
	mov al, cl
	pop cx
}

macro MakeLong wordLow, wordHigh
{
	push WORD wordLow
	mov ax, wordHigh
	shl eax, 16
	pop ax
}

macro Color byteRed, byteGreen, byteBlue
{
    xor eax, eax
    mov ah, byteBlue
    mov al, byteGreen
    shl eax,8
    mov al, byteRed
}

macro Move dwValue1, dwValue2
{
	push dwValue2
	pop dwValue1
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
}

macro Now lpszStrPtr
{
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
}

macro Time lpszStrPtr
{
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
}

macro Swap dwValue1, dwValue2
{
	push dwValue1
	push dwValue2
	pop dwValue1
	pop dwValue2
}
