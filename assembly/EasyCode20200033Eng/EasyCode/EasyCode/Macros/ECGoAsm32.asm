Return(%dqValue) MACRO
	Mov Eax, %dqValue
	Ret
ENDM

HiByte(%wWord) MACRO
	Mov Ax, %wWord
	Shr Ax, 8
ENDM

LoByte(%wWord) MACRO
	Mov Ax, %wWord
	And Ax, 00FFh
ENDM

HiWord(%dwDWord) MACRO
	Mov Eax, %dwDWord
	Shr Eax, 16
ENDM

LoWord(%dwDWord) MACRO
	Mov Eax, %dwDWord
	And Eax, 0000FFFFH
ENDM

MakeWord(%byLow,%byHigh) MACRO
	Pushw Cx
	Mov Cl, %byLow
	Mov Ah, %byHigh
	Mov Al, Cl
	Popw Cx
ENDM

MakeLong(%wLow,%wHigh) MACRO
	Pushw %wLow
    Mov Ax, %wHigh
    Shl Eax, 16
	Popw Ax
ENDM

Color(%byRed,%byGreen,%byBlue) MACRO
	Xor Eax, Eax
	Mov Ah, %byBlue
	Mov Al, %byGreen
	Shl Eax, 8
	Mov Al, %byRed
ENDM

Move(%dwValue1,%dwValue2) MACRO
	Push %dwValue2
	Pop %dwValue1
ENDM

Date(%lpszStrPtr) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Now(%lpszStrPtr) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %lpszStrPtr, Edi
	Invoke lstrcat, %lpszStrPtr, TextStr(" - ")
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcat, %lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Time(%lpszStrPtr) MACRO
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, %lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Swap(%dwValue1,%dwValue2) MACRO
	Push %dwValue1
	Push %dwValue2
	Pop %dwValue1
	Pop %dwValue2
ENDM
