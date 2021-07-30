;===================================================================;
;                                                                   ;
;  macrodrv.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF MACRODRV_INC
MACRODRV_INC Equ 1

CTL_CODE Macro DeviceType:=<0>, Function:=<0>, Method:=<0>, Access:=<0>
    ExitM (((DeviceType) Shl 16) Or ((Access) Shl 14) Or ((Function) Shl 2) Or (Method))
EndM

DEVICE_TYPE_FROM_CTL_CODE Macro ctrlCode:REQ
    ExitM ((ctrlCode And 0FFFF0000H) Shr 16)
EndM

METHOD_FROM_CTL_CODE Macro ctrlCode:REQ
    ExitM (ctrlCode And 3)
EndM

.data

DEFINE_GUID Macro name:REQ, l:REQ, w1:REQ, w2:REQ, b1:REQ, b2:REQ, b3:REQ, b4:REQ, b5:REQ, b6:REQ, b7:REQ, b8:REQ

	local segn

	segn TEXTEQU	@CurSeg
	
	.const
		ALIGN 4
		name		dd l
					dw w1
					dw w2
					db b1
					db b2
					db b3
					db b4
					db b5
					db b6
					db b7
					db b8

	@CurSeg ENDS
	IFDEF MASM_COMPILER
		segn SEGMENT
	ENDIF
ENDM

IFNDEF MAKEFOURCC
    MAKEFOURCC Macro ch0, ch1, ch2, ch3
        ExitM (ch0 Or (ch1 Shl 8) Or (ch2 Shl 16) Or (ch3 Shl 24))
    EndM
ENDIF

MANDATORY_LEVEL_TO_MANDATORY_RID Macro IL
    ExitM (IL * 1000H)
EndM

USBD_TRANSFER_DIRECTION_FLAG Macro arg
     Mov Eax, arg
     And Eax, USBD_TRANSFER_DIRECTION
EndM

USBD_SUCCESS Macro arg
    Xor Eax, Eax             ; <  0     EAX == 0
    .If (SDWord Ptr arg >= 0)
       Inc Eax               ; >= 0     EAX == 1
     .EndIf
     ExitM <Eax>
EndM

USBD_PENDING Macro arg
    Xor Eax, Eax
    .If ((arg Shr 30) == 1)
        Inc Eax
    .EndIf
    ExitM <Eax>
EndM

USBD_ERROR Macro arg
    Xor Eax, Eax             ; >=  0     EAX == 0
    .If (SDWord Ptr arg < 0)
       Inc Eax               ; <   0     EAX == 1
     .EndIf
     ExitM <Eax>
EndM

USB_ENDPOINT_DIRECTION_OUT Macro arg
    Mov Eax, arg
    And Eax, USB_ENDPOINT_DIRECTION_MASK
    Not Eax
    ExitM <Eax>
EndM

USB_ENDPOINT_DIRECTION_IN Macro arg
    Mov Eax, arg
    And Eax, USB_ENDPOINT_DIRECTION_MASK
    ExitM <Eax>
EndM

USBD_HALTED Macro arg
    Mov Eax, arg
    Shr Eax 30
    .If Eax == 3
        Mov Eax, 1
    .Else
        Xor Eax, Eax
    .EndIf
    ExitM <Eax>
EndM

USB_CTL Macro arg
    ExitM <CTL_CODE(FILE_DEVICE_USB, arg, METHOD_BUFFERED, FILE_ANY_ACCESS)>
EndM

USB_KERNEL_CTL Macro arg
    ExitM <CTL_CODE(FILE_DEVICE_USB, arg, METHOD_NEITHER, FILE_ANY_ACCESS)>
EndM

USB_KERNEL_CTL_BUFFERED Macro arg
    ExitM <CTL_CODE(FILE_DEVICE_USB, arg, METHOD_BUFFERED, FILE_ANY_ACCESS)>
EndM

A MACRO quoted_text:VARARG
    LOCAL ECDnameA
.data
    ECDnameA db quoted_text,0
.code
    EXITM <offset ECDnameA>
ENDM

L Macro quoted_text:VarArg
	IFDEF POASM_COMPILER
		Local ECvnameW
		Local cnt,arg,carac,wlen,tipo

		strsinpar equ <>
		DWdef  equ <>
		cnt=0

.Data
		Align 4
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
	ELSE
		Local ECDnameW
		Local cnt,comilla
		Local arg

		strsinpar equ <>
		DWdef  equ <>
		cnt=0
		comilla=0

.Data
		Align 4
.Code

	    DWdef CATSTR <ECDnameW DW  >

		FOR strsinpar,<quoted_text>
			FOR arg,<strsinpar>
				IFDIF <arg>,<">
					cnt=cnt+1
					IF cnt NE 1
		    	       DWdef CATSTR DWdef,<,>
					ENDIF
					IF comilla EQ 1
						DWdef CATSTR DWdef,<">,<arg>,<">
					ELSEIF comilla EQ 0
						DWdef CATSTR DWdef,<strsinpar>
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
	ENDIF
.Data
	DWdef
.Code
	ExitM <Offset ECDnameW>
EndM

TEXT MACRO quoted_text:VARARG
    ECTxtName Equ <>
    IFDEF APP_UNICODE
        ECTxtName CatStr  <L>, <(>, <quoted_text>, <)>
    ELSE
        ECTxtName CatStr  <A>, <(>, <quoted_text>, <)>
    ENDIF
    ExitM <ECTxtName>
ENDM

ENDIF ;MACRODRV_INC
