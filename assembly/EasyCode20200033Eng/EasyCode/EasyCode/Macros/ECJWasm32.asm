Return MACRO dwValue
	Mov Eax, dwValue
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

MakeWord MACRO byteLow, byteHigh
	Push Cx
	Mov Cl, byteLow
	Mov Ah, byteHigh
	Mov Al, Cl
	Pop Cx
ENDM

MakeLong MACRO wordLow, wordHigh
	Push Word Ptr wordLow
	Mov Ax, wordHigh
	Shl Eax, 16
	Pop Ax
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
	Align 4
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

Move MACRO dwValue1, dwValue2
	Push dwValue2
	Pop dwValue1
ENDM

Date MACRO lpszStrPtr
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Now MACRO lpszStrPtr
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, lpszStrPtr, Edi
	Invoke lstrcat, lpszStrPtr, TextStr(" - ")
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcat, lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

Time MACRO lpszStrPtr
	Push Esi
	Push Edi
	Invoke GlobalAlloc, GPTR, MAX_PATH
	Mov Esi, Eax
	Invoke GetSystemTime, Esi
	Mov Edi, Esi
	Add Edi, 64
	Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Esi, NULL, Edi, MAX_PATH - 65
	Invoke lstrcpy, lpszStrPtr, Edi
	Invoke GlobalFree, Esi
	Pop Edi
	Pop Esi
ENDM

MultiCat MACRO lpszDesPtr:Req, lpszOrgPtr:VARARG
	Local prm

	FOR prm, <lpszOrgPtr>
		IFNB <prm>
			Invoke lstrcat, lpszDesPtr, prm
		ELSE
			ExitM
		ENDIF
	ENDM
ENDM

Swap MACRO dwValue1, dwValue2
	Push dwValue1
	Push dwValue2
	Pop dwValue1
	Pop dwValue2
ENDM

;=====================================
; == Programmed by Héctor A. Medina ==
;=====================================
ECCall MACRO name:Req, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, \
             p13,p14,p15,p16,p17,p18,p19,p20,p21,p22
             ;Modificado 20/2/2015
    Local    prm
    Local    spos
    Local    slen
    Local    prmtype
    Local    nametype,nada
    prmstr   equ <>
    paramstr equ <>
    namestr  equ <>
    IF_      equ <>
    ENDIF_   equ <>

    nametype = OpAttr(name)
    nametype = nametype AND 127
    IF (nametype EQ 48) OR (nametype EQ 42) OR (nametype EQ 98)
        IF_     CatStr <.IF >,<name>
        ENDIF_  CatStr <.EndIF>
    ENDIF
    IF_
        %FOR prm, <p22,p21,p20,p19,p18,p17,p16,p15,p14,p13,\
                   p12,p11,p10,p9,p8,p7,p6,p5,p4,p3,p2,p1>
            IFNB <prm>
                spos InStr <prm>, <Addr >
                %IF spos EQ 1
                    slen SIZESTR <prm>
                    prmstr SUBSTR <prm>, 6, slen - 5
                    prmtype = OpAttr(prmstr)
                    prmtype = prmtype AND 127
                    IF (prmtype EQ  42) 
                        paramstr equ <>
                        paramstr CatStr <Push Offset >,<prmstr>
                        paramstr
                    ELSEIF (prmtype EQ  98) OR (prmtype EQ  37) OR (prmtype EQ  34) 
                        Push Eax
                        Lea Eax, prmstr
                        Xchg Eax, [Esp]
                    ELSEIF prmtype EQ  36
                    	Push Dword Ptr prmstr
                    ELSE
                        ECHO ---------------------------
                        %ECHO <prmstr> Argumento Invalido
                        prmstr equ <>
                        prmstr textequ %prmtype
                        %ECHO <prmstr>
                        ECHO ---------------------------
                        .ERR
                        EXITM 
                    ENDIF
                ELSE
                    Push prm
                ENDIF
            ENDIF
        ENDM
        Call name
    ENDIF_
ENDM

;=====================================
; == Programmed by Héctor A. Medina ==
;=====================================
PushD1 MACRO Formula
	Local pos, oldpos, valid, first, largo, prmtype
	oldopcode Equ <>
	opcode Equ <>
	arg Equ <>
	oldpos = 0
	pos = 0
	valid = 0
	first = 0
    largo SizeStr <Formula>       ; Largo de la Formula
    ForC char, <Formula>
	   pos = pos + 1
	   IFIDN <char>, <+>
	     valid = 1
	     opcode TextEqu <Add>
	   ELSEIFIDN <char>, <->
	     valid = 1
	     opcode TextEqu <Sub>
	   ELSEIFIDN <char>, <*>
	     valid = 1
	     opcode TextEqu <Mul>
	   ELSEIFIDN <char>, </>
	     valid = 1
	     opcode TextEqu <Div>
	   ELSE
	     valid = 0
	   ENDIF
       IF valid EQ 1
:arguproc  ;---NUCLEO DEL PROCESAMIENTO DE LOS ARGUMENTOS---
           arg SubStr <Formula>, oldpos + 1, pos - oldpos - 1
           oldpos = pos
           IF first EQ 0
              Push DWord Ptr arg
              first = 1
           ELSEIFIDN oldopcode, <Mul>
              prmtype = OpAttr(arg)
              IF prmtype NE 36        ; NO ES UN INMEDIATO
                Xchg Eax, [Esp]
                Push Edx
                oldopcode arg
                Pop Edx
                Xchg Eax, [Esp]
              ELSE                    ; SI ES UN INMEDIATO
                Push Eax
                Push Edx
                Mov Eax, arg
                oldopcode DWord Ptr [Esp + 8]
                Mov  [Esp + 8], Eax
                Pop Edx
                Pop Eax
              ENDIF
           ELSEIFIDN oldopcode, <Div>
              prmtype = OpAttr(arg)
              IF prmtype NE 36        ; NO ES UN INMEDIATO
                Xchg Eax, [Esp]
                Push Edx
                Xor Edx, Edx
                oldopcode arg
                Pop Edx
                Xchg Eax, [Esp]
              ELSE                    ; SI ES UN INMEDIATO
                Push Edx
                Xor Edx, Edx
                Mov Eax, arg
                Xchg Eax, [Esp + 4]
                oldopcode DWord Ptr [Esp + 4]
                Xchg Eax, [Esp + 4]
                Pop Edx
              ENDIF
           ELSE
              oldopcode DWord Ptr [Esp], arg
           ENDIF
           oldopcode TextEqu opcode
           ;------------------------------------------------
           IF largo EQ 0         ; Si es el ultimo arguemnto se sale de la Macro
              ExitM
           ENDIF
       ENDIF
       largo = largo - 1         ; Conteo descendente de los caaracteres de Formula
       IF largo EQ 0             ; Cuando se llega al final se procesa el ultimo argumento
           pos = pos + 1
           GoTo arguproc
       ENDIF
	ENDM
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

makeword equ <MakeWord>
MAKEWORD equ <MakeWord>

makelong equ <MakeLong>
MAKELONG equ <MakeLong>

color equ <Color>
COLOR equ <Color>

move equ <Move>
MOVE equ <Move>

multicat equ <MultiCat>
MULTICAT equ <MultiCat>

swap equ <Swap>
SWAP equ <Swap>
