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

MakeWord MACRO byteLow, byteHigh
	Mov Ah, byteHigh
	Mov Al, byteLow
ENDM

MakeLong MACRO wordLow, wordHigh
	Mov Ax, wordHigh
	Shl Eax, 16
	Or Ax, wordLow
ENDM

MakeQWord MACRO dwordLow, dwordHigh
    Push Rcx
    Mov Eax, dwordLow
    Mov Ecx, dwordHigh
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
	Local cnt,arg,carac,wlen,tipo

	strsinpar equ <>
	DWdef  equ <>
	cnt=0

.Data
	Align 16
.Code

	DWdef CATSTR <ECvnameW DW  >

	FOR strsinpar, <quoted_text>
		tipo = OpAttr strsinpar
		IF tipo EQ 24H
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
			DWdef CatStr DWdef, strsinpar
		ELSEIF tipo EQ 8020H
			wlen= @SizeStr(strsinpar)
			carac= 0
			While carac LT wlen
				carac = carac + 1
				arg  SubStr strsinpar, carac, 1
				IF cnt GT 30
					cnt=0
.Data
					DWdef
					DWdef TextEqu < DW >
.Code
				ENDIF
				cnt= cnt + 1
				IF cnt NE 1
				    DWdef CatStr DWdef, <,>
				ENDIF
        		DWdef CatStr DWdef, <">,arg,<">
			EndM
		ELSE
		.Echo <ERROR - Invalid Argument>
    	ENDIF
	EndM
	IF cnt NE 0
		DWdef CatStr DWdef, <,>
	ENDIF
	DWdef CATSTR DWdef,<00>
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
TextW Macro szName, quoted_text:VarArg
	Local cnt, arg, carac, wlen, tipo
	Local ECLabel1

	strsinpar EQU <>
	DWdef  EQU <>
	cnt=0
	Jmp ECLabel1
	Align 16
	DWdef TEXTEQU <szName  DW >

	FOR strsinpar, <quoted_text>
		tipo = OpAttr strsinpar
		IF tipo EQ 24H
			IF cnt GT 30
				cnt=0 
				DWdef
				DWdef TEXTEQU < DW >
			ENDIF
			cnt=cnt+1
			IF cnt NE 1
				DWdef CATSTR DWdef,<,>
			ENDIF
			DWdef CatStr DWdef, strsinpar
		ELSEIF tipo EQ 8020H
			wlen= @SizeStr(strsinpar)
			carac= 0
			While carac LT wlen
				carac = carac + 1
				arg  SubStr strsinpar, carac, 1
				IF cnt GT 30
					cnt=0
					DWdef
					DWdef TextEqu < DW >
				ENDIF
				cnt= cnt + 1
				IF cnt NE 1
					DWdef CatStr DWdef, <,>
				ENDIF
				DWdef CatStr DWdef, <">,arg,<">
			EndM
    	ELSE
			.Echo <ERROR - Invalid Argument>
		ENDIF
	EndM
	IF cnt NE 0
		DWdef CatStr DWdef, <,>
	ENDIF
	DWdef CATSTR DWdef,<00>
	DWdef
ECLabel1:

EndM

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
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Esi
    Mov Rdi, Esi
    Add Rdi, 64
    Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Now MACRO lpszStrPtr
    Push Rsi
    Push Rdi
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Rsi
    Mov Rdi, Rsi
    Add Rdi, 64
    Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, lpszStrPtr, Rdi
    Invoke lstrcat, lpszStrPtr, TextStr(" - ")
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcat, lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

Time MACRO lpszStrPtr
    Push Rsi
    Push Rdi
    Invoke GlobalAlloc, GPTR, MAX_PATH
    Mov Rsi, Rax
    Invoke GetSystemTime, Rsi
    Mov Edi, Rsi
    Add Rdi, 64
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Rsi, NULL, Rdi, MAX_PATH - 65
    Invoke lstrcpy, lpszStrPtr, Rdi
    Invoke GlobalFree, Rsi
    Pop Rdi
    Pop Rsi
ENDM

MultiCat MACRO lpszDesPtr:Req, lpszOrgPtr:VARARG
	Local prm

	FOR prm, <lpszOrgPtr>
		IFNB <prm>
			Invoke lstrcat, lpszDesPtr, prm
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
