Return(%dqValue) MACRO
    Mov Rax, %dqValue
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

HiDWord(%dqDWord) MACRO
    Mov Rax, %dqDWord
    Bswap Rax
    Bswap Eax
ENDM

LoDWord(%dqDWord) MACRO
    Mov Rax, %dqDWord
    Or Eax, Eax
ENDM

MakeWord(%byLow,%byHigh) MACRO
    Push Rcx
    Mov Cl, %byLow
    Mov Ah, %byHigh
    Mov Al, Cl
    Pop Rcx
ENDM

MakeLong(%wLow,%wHigh) MACRO
    Mov Ax, %wHigh
    Shl Eax, 16
	Or Ax, %wLow
ENDM

MakeQWord(%dwLow,%dwHigh) MACRO
    Push Rcx
    Mov Eax, %dwLow
    Mov Ecx, %dwHigh
    Shl Rcx, 32
    Or Rax, Rcx
    Pop Rcx
ENDM

Color(%byRed,%byGreen,%byBlue) MACRO
    Xor Eax, Eax
    Mov Ah, %byBlue
    Mov Al, %byGreen
    Shl Eax, 8
    Mov Al, %byRed
ENDM

Move(%dqValue1,%dqValue2) MACRO
    Push %dqValue2
    Pop %dqValue1
ENDM

Date(%lpszStrPtr) MACRO
    Push Rsi
    Push Rdi
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Rsi
    Mov Rdi, Rsi
    Add Rdi, 64
    Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, %lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Now(%lpszStrPtr) MACRO
    Push Rsi
    Push Rdi
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Rsi
    Mov Rdi, Rsi
    Add Rdi, 64
    Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, %lpszStrPtr, Rdi
    Invoke lstrcat, %lpszStrPtr, TextStr(" - ")
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcat, %lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Time(%lpszStrPtr) MACRO
    Push Rsi
    Push Rdi
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Rsi
    Mov Rdi, Rsi
    Add Rdi, 64
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, %lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Swap(%dqValue1,%dqValue2) MACRO
    Push %dqValue1
    Push %dqValue2
    Pop %dqValue1
    Pop %dqValue2
ENDM
