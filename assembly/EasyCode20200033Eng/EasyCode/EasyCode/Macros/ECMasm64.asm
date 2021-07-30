Return MACRO dqValue
    Mov Rax, dqValue
    Ret
ENDM

HiByte MACRO wWord
    Mov Ax, wWord
    Shr Ax, 8
ENDM

LoByte MACRO wWord
    Mov Ax, wWord
    And Ax, 00FFh
ENDM

HiWord MACRO dwDWord
    Mov Eax, dwDWord
    Shr Eax, 16
ENDM

LoWord MACRO dwDWord
    Mov Eax, dwDWord
    And Eax, 0000FFFFH
ENDM

HiDWord MACRO dqDWord
    Mov Rax, dqDWord
    Bswap Rax
    Bswap Eax
ENDM

LoDWord MACRO dqDWord
    Mov Rax, dqDWord
    Or Eax, Eax
ENDM

MakeWord MACRO byLow, byHigh
    Push Cx
    Mov Cl, byLow
    Mov Ah, byHigh
    Mov Al, Cl
    Pop Cx
ENDM

MakeLong MACRO wLow, wHigh
    Push Word Ptr wLow
    Mov Ax, wHigh
    Shl Eax, 16
    Pop Ax
ENDM

MakeQWord MACRO dwLow, dwHigh
    Push Rcx
    Mov Eax, dwLow
    Mov Ecx, dwHigh
    Shl Rcx, 32
    Or Rax, Rcx
    Pop Rcx
ENDM

Color MACRO byteRed, byteGreen, byteBlue
    Xor Eax, Eax
    Mov Ah, byteBlue
    Mov Al, byteGreen
    Shl Eax,8
    Mov Al, byteRed
ENDM

TextAddrA MACRO quoted_text:VARARG
    LOCAL ECvnameA
.Data
    ECvnameA DB quoted_text,0
.Code
    EXITM <Offset ECvnameA>
ENDM

;=====================================
; == Programmed by Héctor A. Medina ==
;=====================================
TextAddrW MACRO quoted_text:VARARG
    Local ECvnameW
    Local cnt,comilla
    Local arg

    strsinpar equ <>
    DWdef  equ <>
    cnt=0
    comilla=0

.Data
    Align 16
.Code

    DWdef CATSTR <ECvnameW DW  >

    FOR strsinpar,<quoted_text>
        FORC arg, <strsinpar>
            IFDIF <arg>,<">
                IF cnt GT 30
                    cnt=0 
.Data
                    DWdef
                    DWdef TEXTEQU < DW >
.Code   
                ENDIF
                cnt=cnt+1
                IF cnt NE 1
                    DWdef CATSTR DWdef,<,>
                ENDIF
                IF comilla EQ 1
                    DWdef CATSTR DWdef,<">,<arg>,<">
                ELSEIF comilla EQ 0
                    DWdef CATSTR DWdef,<strsinpar>
                    EXITM
                ENDIF 
            ELSE
                IF comilla EQ 0
                    comilla=comilla+1
                ELSE
                    comilla=comilla-1
                ENDIF
            ENDIF
        ENDM
    ENDM
    IF cnt NE 0
        DWdef CATSTR DWdef,<,00>
    ELSE
        DWdef CATSTR DWdef,<00>
    ENDIF

.Data
    DWdef
.Code
    ExitM <Offset ECvnameW>
ENDM

TextAddr MACRO quoted_text:VARARG
    IFDEF _EC_1_
        EXITM  TextAddrA(quoted_text)
    ELSEIFDEF APP_UNICODE
        EXITM  TextAddrW(quoted_text)
    ELSE
        EXITM  TextAddrA(quoted_text)
    ENDIF
ENDM

TextA MACRO szName, quoted_text:VARARG
    LOCAL ECLabel1
    Jmp ECLabel1
    szName db quoted_text,0
ECLabel1:
ENDM

;=====================================
; == Programmed by Héctor A. Medina ==
;=====================================
TextW MACRO szName, quoted_text:VARARG
    LOCAL cnt,comilla,arg
    LOCAL ECLabel1

    strsinpar equ <>
    DWdef  equ <>
    cnt=0
    comilla=0

    Jmp ECLabel1
    Align 4
    DWdef TEXTEQU <szName  DW >
                      
    FOR strsinpar,<quoted_text>
        FORC arg,<strsinpar>
            IFDIF <arg>,<">
                IF cnt GT 30
                    cnt=0 
                    DWdef
                    DWdef TEXTEQU < DW >
                ENDIF
                cnt=cnt+1
                IF cnt NE 1
                    DWdef CATSTR DWdef,<,>
                ENDIF
                IF comilla EQ 1
                    DWdef CATSTR DWdef,<">,<arg>,<">
                ELSEIF comilla EQ 0
                    DWdef CATSTR DWdef,<strsinpar>
                    EXITM
                ENDIF 
            ELSE
                IF comilla EQ 0
                    comilla=comilla+1
                ELSE
                    comilla=comilla-1
                ENDIF
            ENDIF
        ENDM
    ENDM
    IF cnt NE 0
        DWdef CATSTR DWdef,<,00>
    ELSE
        DWdef CATSTR DWdef,<00>
    ENDIF

    DWdef
ECLabel1:

ENDM

Text MACRO szName, quoted_text:VARARG
    IFDEF _EC_1_
       TextA szName, quoted_text
    ELSEIFDEF APP_UNICODE
       TextW szName, quoted_text
	ELSE
       TextA szName, quoted_text
    ENDIF
ENDM

TextStr MACRO quoted_text:VARARG
	IFDEF APP_UNICODE
		EXITM TextAddrW(quoted_text)
	ELSE
		EXITM TextAddrA(quoted_text)
	ENDIF
ENDM

TextStrA MACRO quoted_text:VARARG
	EXITM TextAddrA(quoted_text)
ENDM

TextStrW MACRO quoted_text:VARARG
	EXITM TextAddrW(quoted_text)
ENDM

Move MACRO dqValue1, dqValue2
    Push dqValue2
    Pop dqValue1
ENDM

Date MACRO lpszStrPtr
    Push Rsi
    Push Rdi
    ECInvoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    ECInvoke GetSystemTime, Esi
    Mov Rdi, Esi
    Add Rdi, 64
    ECInvoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    ECInvoke lstrcpy, lpszStrPtr, Rdi
    ECInvoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Now MACRO lpszStrPtr
    Push Rsi
    Push Rdi
    ECInvoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    ECInvoke GetSystemTime, Rsi
    Mov Rdi, Rsi
    Add Rdi, 64
    ECInvoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    ECInvoke lstrcpy, lpszStrPtr, Rdi
    ECInvoke lstrcat, lpszStrPtr, TextStr(" - ")
    ECInvoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    ECInvoke lstrcat, lpszStrPtr, Rdi
    ECInvoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Time MACRO lpszStrPtr
    Push Rsi
    Push Rdi
    ECInvoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    ECInvoke GetSystemTime, Rsi
    Mov Edi, Rsi
    Add Rdi, 64
    ECInvoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    ECInvoke lstrcpy, lpszStrPtr, Rdi
    ECInvoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

MultiCat MACRO lpszDesPtr:Req, lpszOrgPtr:VARARG
    Local prm

    FOR prm, <lpszOrgPtr>
        IFNB <prm>
            ECInvoke lstrcat, lpszDesPtr, prm
        ELSE
            ExitM
        ENDIF
    ENDM
ENDM

Swap MACRO dqValue1, dqValue2
    Push dqValue1
    Push dqValue2
    Pop dqValue1
    Pop dqValue2
ENDM

return  equ <Return>
RETURN  equ <Return>

hibyte  equ <HiByte>
HIBYTE  equ <HiByte>

lobyte  equ <LoByte>
LOBYTE  equ <LoByte>

hiword  equ <HiWord>
HIWORD  equ <HiWord>

loword  equ <LoWord>
LOWORD  equ <LoWord>

hidword equ <HiDWord>
HIDWORD equ <HiDWord>

lodword equ <LoDWord>
LODWORD equ <LoDWord>

makeword equ <MakeWord>
MAKEWORD equ <MakeWord>

makelong equ <MakeLong>
MAKELONG equ <MakeLong>

makeqword equ <MakeQWord>
MAKEQWORD equ <MakeQWord>

color equ <Color>
COLOR equ <Color>

move equ <Move>
MOVE equ <Move>

multicat equ <MultiCat>
MULTICAT equ <MultiCat>

swap equ <Swap>
SWAP equ <Swap>
