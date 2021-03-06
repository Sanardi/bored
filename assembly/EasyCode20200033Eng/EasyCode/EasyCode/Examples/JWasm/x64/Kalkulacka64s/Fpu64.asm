;EasyCodeName=Fpu64,1
;EasyCodeName=Fpu64,1
; 09.04.2021 - 15:13:52 CZ
;Pavlů Zdeněk www.zpavlu.cz

;Security input data:
;	Fld reálné číslo
;	Fxam                    test St (0) to 0.0
;	Fstsw Ax                Symptoms C3 C2 C0 do Ax
;	Fwait					I am waiting for the operation to complete
;	Sahf					save the AH register to the flag register
;	Jz Zero					Symptoms C3= 1 C2= 0 C0= 0
;	Jpo Errx            	C3=0 and C2=0 would be NAN or unsupported
;	Jnc @F					C3= 0 C2= 1 C0= 0  -> real number
;	další					C3= 0 C2= 1 C0= 1 + - --> infinity
;Symptoms:
;	Not supported 0 0 0
;	NAN 0 0 1
;	Normal finite number 0 1 0
;	infinity 0 1 1
;	Nula 1 0 0
;	Empty 1 0 1
;	Denormalized number 1 1 0

;Applies to integers, for work in Dll library we will also use for real numbers
;Procedura Proc FastCall Frame f1:QWord, f2:QWord, f3:QWord, f4:QWord
;	Mov f1, Rcx
;	Mov f2, Rdx
;	Mov f3, R8
;	Mov f4, R9
;.....kód
;	Ret
;Procedura EndP

;Important
;In 64-bit programming all arguments/parameters must be 64-bit values.
;The main difference for static and dynamic libraries is the following:
;
;	- Linking an application with a static library makes the application more compact and with no dependencies, 
;		but the Size of the executable file is bigger.
;
;	- Linking The same application with a dynamic library makes its Size smaller, 
;		but The application does NOT work without The dynamic library.

;***************************************************************************************************************
;***************************************************************************************************************
MOVmq Macro Varq1, Varq2
		Movlpd Xmm5, Varq2
		Movlpd Varq1, Xmm5
EndM

.Const

eSizeM		Equ		127
.Data?
.Data

RegNull			DQ  0.0
qPI_180			DQ	0.01745329251994329576923690768489		;to convert degrees to radians Pi / 180
qarc			DQ  57.295779513082320876798154814105		;for converting radians to degrees 180 / Pi
qJedna			DQ	1.00
qMinusJedna		DQ	-1.0
qMaska			DQ	80000000H

RegTmp			DQ	0.0
hStatic 		DQ	NULL
BazeOut1		DB	0
SizeCela		DB	0

FmtA            DB  '%lu', 0		;Output as ascii string
FmtH            DB  '%lX', 0


;Error texts of functions.
Err1			DB		"Wrong operation !", 0
Err2			DB		"Invalid input", 0
Err3			DB		"Divided by zero", 0
Err4			DB		"Undefined", 0
Err5			DB		"Buffer overfilled", 0
Err6			DB		"Error - negative value", 0
Err8			DB		"± Infinity", 0
Err9			DB		"Invalid operation", 0


.Code

;imported variables hStatic1 and BazeOut1
SetHedit Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
		Mov lpSrc, Rcx
		Mov lpSrc1, Rdx

		Mov hStatic, Rcx
		Mov BazeOut1, Dl
	; maximum length of the decimal number
		.If Dl == 0
			Mov [SizeCela], 16	;dec
		.ElseIf Dl == 1
			Mov [SizeCela], 20	;oct
		.ElseIf Dl == 2
			Mov [SizeCela], 34	;bin
		.ElseIf Dl == 3
			Mov [SizeCela], 14	;hex
		.EndIf
		Mov Rax, lpSrc
		Ret
SetHedit EndP
;******************************************************************************* 
;sin(Src) -> Dest
;RegistrX, DegRad, BazeOutDq,True
;*******************************************************************************
FpuSin64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
		Local content[108]:Byte
		Mov lpSrc, Rcx
		Mov uID, Rdx
		Mov lpSrc1, R8
		Mov lpSrc2, R9

		Xor Rax, Rax
		Fsave content
		Fld qPI_180
		Fld lpSrc
		Fxam                    ;examine value on FPU
		fstsw ax                ;get result
		fwait
		Sahf
		Jz Zero
		Jpo Errx            	;C3=0 and C2=0 would be NAN or unsupported
		Jnc @F
		Frstor content
		Call Infinity
		Ret

@@:		Mov Rax, TRUE			;test Deg/Rad
		Test Rax, uID
		Jnz @F
		Fmul					;St(0)*St(1) převede ne radiány
@@:
		Fsin					;St(0) = sin(x)
		Fstsw Ax
		fwait
		Shr Al, 1				;přenést I nvalid op příznak (bit0 AL) na příznak CF
		Jc Errx
		Fstp [RegTmp]
		Ffree St(0)
		Frstor content
		Nop
		.If lpSrc2 == TRUE
			Invoke FpuBinAsci64, lpSrc1, RegTmp
			Nop
			Lea Rax, [RegTmp]		;RegTmp memory address to RAX
		.EndIf
		Ret
Zero:
		Frstor content
		Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 0", 0)
		Lea Rax, [RegNull]
		Ret
Errx:
		Frstor content
		Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
		Lea Rax, [RegNull]
		Ret
FpuSin64 EndP

;*******************************************************************************
;cos(Src) -> Dest
;RegistrX, DegRad, BazeOutDq,True
;*******************************************************************************
FpuCos64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
		Local content[108]:Byte
		Mov lpSrc, Rcx
		Mov uID, Rdx
		Mov lpSrc1, R8
		Mov lpSrc2, R9
	
	    Fsave content
	 	Fld qPI_180
		Fld lpSrc
		Fxam                    ;examine value on FPU
		fstsw ax                ;get result
		fwait
		Sahf
		Jz Zero
		Jpo Errx            	;C3=0 and C2=0 would be NAN or unsupported
		Jnc @F
		Frstor content
		Call Infinity
		Ret

@@:		Mov Rax, TRUE
		Test Rax, uID
		Jnz @F
		Fmul
@@:
		Fldpi
      	Fadd St, St             ;->2pi
      	Fxch
@@:
		Fprem                   ;reduce the angle
	    Fcos
		Fstsw Ax
		fwait
		Shr Al, 1
		Jc Errx
		Sahf                    ;transfer to the CPU flags
      	Jpe @B                	;reduce angle again if necessary
   		Fstp St(1)             	;get rid of the 2pi

		Fstp [RegTmp]
		Ffree St(0)
		Frstor content
		Nop
		.If lpSrc2 == TRUE
			Invoke FpuBinAsci64, lpSrc1, RegTmp
			Nop
			Lea Rax, [RegTmp]
		.EndIf
		Ret
Zero:
		Frstor content
		Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 1", 0)
		Lea Rax, [qJedna]
		Ret
Errx:
		Frstor content
		Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
		Lea Rax, [RegNull]
		Ret

FpuCos64 EndP

;*******************************************************************************
;tg(x) --> Dest
;RegistrX, DegRad, BazeOutDq, True 
;*******************************************************************************
FpuTan64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8
	Mov lpSrc2, R9
	MOVmq RegTmp, RegNull

	Xor Rax, Rax
    Fsave content
 	Fld qPI_180
	Fld lpSrc
	Fxam                    ;examine value on FPU
	fstsw ax                ;get result
	fwait
	Sahf
	Jz Zero
	Jpo Errx            	;C3=0 and C2=0 would be NAN or unsupported
	Jnc @F
	Frstor content
	Call Infinity
	Ret
@@:
	Mov Rax, TRUE
	Test Rax, uID
	Jnz @F
	Fmul
@@:
    fptan
    fstsw ax                ;retrieve exception flags from FPU
    fwait
    shr   al,1              ;test for invalid operation
    Jc Errx          		;clean-up and return error
    Fstp St                 ;get rid of the 1
    Fstp [RegTmp]			; st(1)
	Frstor content
	.If lpSrc2 == TRUE
		Nop
		Invoke FpuBinAsci64, lpSrc1, RegTmp
		Nop
		Lea Rax, [RegTmp]
	.EndIf
	Ret
Zero:
	Frstor content
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 0", 0)
	Lea Rax, [RegNull]
	Ret
Errx:
	Frstor content
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
	Lea Rax, [RegNull]
	Ret
FpuTan64 EndP


;*******************************************************************************
;ctg(x)= 1/tgX(x)
;RegistrX, DegRad, BazeOutDq,False
FpuCoTan64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8
	Mov lpSrc2, R9
	MOVmq RegTmp, RegNull


	Invoke FpuTan64, lpSrc, uID, lpSrc1, lpSrc2
	Movlpd Xmm0, [RegTmp]			;tg(x)
	Comisd Xmm0, [RegNull]			;test whether RegTmp is zero
	Jz @F
	Movlpd Xmm1, [qJedna]			;1
	Divsd Xmm1, Xmm0
	Movlpd [RegTmp], Xmm1
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err3
	Lea Rax, [RegNull]
	Ret
FpuCoTan64 EndP

;********************************************************************************
;sec(x)= 1/cos(x)
;RegistrX, DegRad, BazeOutDq, False
;*******************************************************************************
FpuSecant64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8
	Mov lpSrc2, R9
	MOVmq RegTmp, RegNull


	Invoke FpuCos64, lpSrc, uID, lpSrc1, lpSrc2		;cos(x)
	Movlpd Xmm0, [RegTmp]							;tg(x)
	Comisd Xmm0, [RegNull]							;test whether RegTmp is zero
	Jz @F
	Movlpd Xmm1, [qJedna]							;1.0
	Divsd Xmm1, Xmm0
	Movlpd [RegTmp], Xmm1
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 1", 0)
	Lea Rax, [qJedna]
	Ret
FpuSecant64 EndP


;*******************************************************************************
;csc(x)= 1/sin(x)
;RegistrX, DegRad, BazeOutDq,False
;*******************************************************************************
FpuCosecant64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord, lpSrc2:QWord
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8
	Mov lpSrc2, R9
	MOVmq RegTmp, RegNull


	Invoke FpuSin64, lpSrc, uID, lpSrc1, lpSrc2				;sin(x)
	Movlpd Xmm0, [RegTmp]
	Comisd Xmm0, [RegNull]									;test whether RegTmp is zero
	Jz @F
	Movlpd Xmm1, [qJedna]									;1
	Divsd Xmm1, Xmm0
	Movlpd [RegTmp], Xmm1
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err3
	Lea Rax, [RegNull]
	Ret
FpuCosecant64 EndP

;***********************************************************************
;							Hyperbolické funkce
;***********************************************************************
;*******************************************************************************
;sinh(Src) = [e^(Src) - e^(-Src)]/2 -> Dest   
;RegistrX, BazeOutDq , True
;*******************************************************************************
FpuSinusHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8
	MOVmq RegTmp, RegNull

    Fsave content
	Fld lpSrc				;st(0) = lpSrc
	Fxam                    ;examine value on FPU
	fstsw ax                ;get result
	fwait
	Sahf
	Jz Zero
	Jpo Errx            	;C3=0 and C2=0 would be NAN or unsupported
	Jnc @F
	Fwait
	Frstor content
	Call Infinity
	Ret
@@:
    Fldl2e					;ln(2)
    fmul                    ;log2(e)*Src
    fld   st(0)
    frndint
    fxch
    fsub  st,st(1)
    f2xm1
    fld1
    fadd
    fscale                  ;-> antilog[log2(e)*Src] = e^(Src)
    fstp  st(1)             ;get rid of scaling factor
    fld   st(0)             ;copy it to get the reciprocal
    fld1
    fdivrp st(1),st         ;1/e^(Src) = e^(-Src)
    fsub                    ;e^(Src) - e^(-Src)
    fld1
    fchs                    ;-1
    fxch
    fscale                  ;-> [e^(Src) - e^(-Src)]/2 = sinh(Src)
    fstp  st(1)             ;get rid of scaling factor
    fstsw ax                ;retrieve exception flags from FPU
    fwait
    shr   al,1              ;test for invalid operation
    Jc @F           		;clean-up and return error

    Fstp [RegTmp]    		;store result at specified address
    Ffree St(0)
    Fwait
    Frstor content         ;restore all previous FPU registers
    Nop
    .If lpSrc2 == TRUE
		Invoke FpuBinAsci64, lpSrc1, RegTmp
	.EndIf
	Lea Rax, [RegTmp]
	Ret
@@:
	Fwait
    Frstor content
    Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
    Lea Rax, [RegNull]
	Ret
Zero:
	Frstor content
	Nop
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 0", 0)
	Lea Rax, [RegNull]
	Ret
Errx:
	Frstor content
	Nop
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
	Lea Rax, [RegNull]
	Ret
FpuSinusHyp64 EndP


;*******************************************************************************
;cosh(Src) = [e^(Src) + e^(-Src)]/2 -> Dest  
;RegistrX, BazeOutDq , True
;*******************************************************************************
FpuCosHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8
	MOVmq RegTmp, RegNull

    Fsave content
    Fld lpSrc				;st(0) = lpSrc
	Fxam                    ;examine value on FPU
	fstsw ax                ;get result
	fwait
	Sahf
	Jz @F
	Jpo Errx            	;C3=0 and C2=0 would be NAN or unsupported
	Jnc @F
	Fwait
	Frstor content
	Call Infinity
	Ret
@@:
    fldl2e
    fmul                    ;log2(e)*Src
    fld   st(0)
    frndint
    fxch
    fsub  st,st(1)
    f2xm1
    fld1
    fadd
    fscale                  ;-> antilog[log2(e)*Src] = e^(Src)
    fstp  st(1)             ;get rid of scaling factor

    fld   st                ;copy it to get the reciprocal
    fld1
    fdivrp st(1),st         ;1/e^(Src) = e^(-Src)
    fadd                    ;e^(Src) + e^(-Src)
    fld1
    fchs                    ;-1
    fxch
    fscale                  ;-> [e^(Src) + e^(-Src)]/2 = cosh(Src)
    fstp  st(1)             ;get rid of scaling factor

    fstsw ax                ;retrieve exception flags from FPU
    fwait
    shr   al,1              ;test for invalid operation
    Jc @F            		;clean-up and return error

    Fstp [RegTmp]    		;store result at specified address
    Ffree St(0)
    Fwait
    Frstor content          ;restore all previous FPU registers
    Nop
    .If lpSrc2 == TRUE
		Invoke FpuBinAsci64, lpSrc1, RegTmp
	.EndIf
	Lea Rax, [RegTmp]
	Ret
@@:
    Frstor content
    Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
    Lea Rax, [RegNull]
    Ret

Errx:
	Frstor content
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
	Lea Rax, [RegNull]
	Ret
FpuCosHyp64 EndP

;*******************************************************************************
;                           sinh(Src)
;               tanh(Src) = ---------  -> Dest    
;                           cosh(Src)
;RegistrX, BazeOutDq,True
 ;*******************************************************************************
FpuTanHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8

	MOVmq RegTmp, RegNull
	Invoke FpuSinusHyp64, lpSrc, lpSrc1, FALSE
	Movlpd Xmm0, [RegTmp]
	MOVmq RegTmp, RegNull								;sinh
	Invoke FpuCosHyp64, lpSrc, lpSrc1, FALSE			;cosh
	Movlpd Xmm1, [RegTmp]
	Comisd Xmm1, [RegNull]								;test whether RegTmp is zero
	Jz @F
	Divsd Xmm0, Xmm1									;sinh/cosh
	Movlpd [RegTmp], Xmm0
	.If lpSrc2 == TRUE
		Invoke FpuBinAsci64, lpSrc1, RegTmp
		Lea Rax, [RegTmp]
	.EndIf
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
	Lea Rax, [RegNull]
	Ret

FpuTanHyp64 EndP
;*******************************************************************************
;					ctngh(x)= 1/tngHyp(x)
;RegistrX, BazeOutDq, False
;*******************************************************************************
FCoTanHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8

	MOVmq RegTmp, RegNull
	Invoke FpuTanHyp64, lpSrc, lpSrc1, lpSrc2
	Movlpd Xmm3, [RegTmp]
	Comisd Xmm3, [RegNull]					;test whether RegTmp is zero
	Jz @F

	Movlpd Xmm1, [qJedna]					;1.0
	Divsd Xmm1, Xmm3	   					;1/tngHyp(x)
	Movlpd [RegTmp], Xmm1
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
@@:
	Nop
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err9
	Lea Rax, [RegNull]
	Ret
FCoTanHyp64 EndP


;*******************************************************************************
;					asinh (Src) = ln [Src + sqrt (Src ^ 2 + 1)] -> Dest
;RegistrX, BazeOutDq
;*******************************************************************************
FArSinHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Local mTmp:QWord
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	Xorpd Xmm0, Xmm0
	Movlpd Xmm0, [lpSrc]		;x
	Mulsd Xmm0, Xmm0			;x^2
	Addsd Xmm0, [qJedna]		;x^2+1
	Sqrtsd Xmm1, Xmm0			;sqrt(x^2+1)
	Addsd Xmm1, [lpSrc]			;[x + sqrt (x ^ 2 + 1)]
	Movlpd [mTmp], Xmm1
	Fsave content				;coprocessor initialization
	Fwait
    Fld [mTmp]          		;[x + sqrt (x ^ 2 + 1)]
    Fldln2                 		;->ln(2)=1/[log2(e)]
    Fxch				    	;Swap the contents of the top of the numeric coprocessor stack with the source operand.
    Fyl2x						;y * log_2(x)
    Fstp [RegTmp]
    fwait
	Frstor content
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Lea Rax, [RegTmp]
	Ret
FArSinHyp64 EndP

;*******************************************************************************
;*******************************************************************************
;					acosh(Src) = ln[Src + sqrt(Src^2 - 1)] -> Dest
;RegistrX, BazeOutDq
;*******************************************************************************
FArcCosHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Local mTmp:QWord
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	Fsave content
	Fld lpSrc				;st(0) = lpSrc
  	Fld St(0)             	;copy it
    fmul  st,st(0)          ;Src^2
    fld1
    fsub                    ;Src^2-1
    fsqrt                   ;sqrt(Src^2-1)
    fadd                    ;Src+sqrt(Src^2-1)
    fldln2                  ;->ln(2)=1/[log2(e)]
    fxch
    fyl2x                   ;->[log2(Src+sqrt(Src^2-1))]/[log2(e)]
                            ; = ln[Src+sqrt(Src^2-1)]
    fstsw ax                ;retrieve exception flags from FPU
    fwait
    shr   eax,1             ;test for invalid operation
    Jc @F            		;clean-up and return error
    Fstp [mTmp]
    Fstp St
    Frstor content         ;restore all previous FPU registers
    Nop
	Invoke FpuBinAsci64, lpSrc1, mTmp
	Lea Rax, [mTmp]
	Ret

@@:
    Frstor content
    Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err4
    Lea Rax, [RegNull]
	Ret
FArcCosHyp64 EndP

;*******************************************************************************
;		atanh(Src) = 0.5 * ln[(1+Src)/(1-Src)] -> Dest   (-1 < x < 1)
;RegistrX, BazeOutDq, True
;*******************************************************************************
FArcTanHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8

	MOVmq RegTmp, RegNull
    Fsave content
    Fwait
    Fld lpSrc
	fld   st(0)             ;copy it
	fld1
	fadd                    ;1+Src
	fxch
	fld1
	fsubr                   ;1-Src
	fdiv                    ;(1+Src)/(1-Src)
	fldln2                  ;->ln(2)=1/[log2(e)]
	fxch
	fyl2x                   ;->[log2((1+Src)/(1-Src))]/[log2(e)]
	                        ; = ln[(1+Src)/(1-Src)]
	fld1
	fchs
	fxch
	fscale                  ;->0.5*ln[(1+Src)/(1-Src)] = atanh(Src)
	fstp  st(1)             ;store over scaling factor  
	fstsw ax                ;retrieve exception flags from FPU
	fwait
	shr   eax,1             ;test for invalid operations
	Jc @F	            	;clean-up and return error
	Fstp [RegTmp]    		;store result at specified address
	Ffree St(0)
	Fwait
	Frstor content         ;restore all previous FPU registe
	.If lpSrc2 == TRUE
		Invoke FpuBinAsci64, lpSrc1, RegTmp
		Lea Rax, [RegTmp]
	.EndIf
	Ret
@@:
    Frstor content
    Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
    Lea Rax, [RegNull]
    Ret
FArcTanHyp64 EndP
;*******************************************************************************
;actnh(x)=  1/artanh(x) 
;RegistrX, BazeOutDq, False		-1 > x > 1   
;*******************************************************************************
FArcCotnHyp64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord, lpSrc2:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx
	Mov lpSrc2, R8

	MOVmq RegTmp, RegNull
	Movlpd Xmm0, [qJedna]
	Divsd Xmm0, lpSrc
	Movlpd [RegTmp], Xmm0
	Invoke FArcTanHyp64, RegTmp, lpSrc1, lpSrc2
	Nop
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
FArcCotnHyp64 EndP

;*******************************************************************************
;            asin(Src) = atan(Src/ sqrt(1-Src^2))  -> Dest
;Platnost zdroje je zkontrolována.  Kontrola vstupu -1<< Scr <<1
;RegistrX, DegRad, BazeOutDq
;************************************************************************************************
FArcSinus64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord
	Local content[108] :Byte
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8

	MOVmq RegTmp, RegNull
	Fsave content
	Xor Rax, Rax
	Fld1					;qJedna
	Fld lpSrc				;read real number to st (0)
	Fabs
	Fcom 					;compares st (0) with 1.0
	Fstsw Ax				;saves the state to ax, checks and handles pending unmasked exceptions
	Fwait					;čeká na dokončení operace
	Sahf
	Jnc @F
	Jpe @F

	;výpočet ArcSinus
	Fld lpSrc				;we read the real number after the range test
 	Fmul St, St(0)     	    ;sin^2
    fld1
    fsubr                   ;1-sin^2 = cos^2
    fsqrt                   ;->cos
    fpatan                  ;i.e. arctan(sin/cos) = arcsin
	Fstp [RegTmp]
	Frstor content			;obnoví registry FPU
	Fwait
	.If [uID] == FALSE
		Movlpd Xmm0, [RegTmp]
		Mulsd Xmm0, [qarc]		;převod radiánů na stupně
		Movlpd [RegTmp], Xmm0
	.EndIf
	Pause
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Pause
	Lea Rax, [RegTmp]
	Ret
@@:
	Frstor content
    Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
	Lea Rax, [RegNull]
	Ret
FArcSinus64 EndP

;*******************************************************************************
;                                sqrt(1-Src^2)
;               acos(Src) = atan -------------  -> Dest
;                                     Src
;RegistrX, DegRad, BazeOutDq
;*******************************************************************************
FArcCosinus64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8

	MOVmq RegTmp, RegNull
	Xor Eax, Eax
	Fsave content
	Fld lpSrc               ;copy cosine value
	Fld St                	;copy cosine value
	fmul  st,st             ;cos^2
	Fld1					;1.0
	fsubr                   ;1-cos^2 = sin^2
	fsqrt                   ;->sin
	fxch
	fpatan                  ;i.e. arctan(sin/cos)
	Fstp [RegTmp]   		;store result at specified address

	Fstsw Ax                ;retrieve exception flags from FPU
	fwait
	shr   eax,1             ;test for invalid operation
	Jc L0            		;clean-up and return error
	.If [uID] == FALSE
		Movlpd Xmm0, [RegTmp]
		Mulsd Xmm0, [qarc]		;převod radiánů na stupně
		Movlpd [RegTmp], Xmm0
	.EndIf					;převod radiánů na stupně
	Frstor content         ;restore all previous FPU registers
	Pause
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Pause
	Lea Rax, [RegTmp]
	Ret
L0:
	Frstor content
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
	Lea Rax, [RegNull]
	Ret
FArcCosinus64 EndP

;*******************************************************************************
;atan(Src) -> Dest   Src(max) <-- ± 2^63 
;RegistrX, DegRad, BazeOutDq
;*******************************************************************************
FArcTangent64 Proc  FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8

	MOVmq RegTmp, RegNull
	Xor Eax, Eax
	Fsave content
	Fld lpSrc
	fld1
	fpatan                  ;i.e. arctan(Src/1)
	
	fstsw ax                ;retrieve exception flags from FPU
	fwait
	shr   eax,1             ;test for invalid operation
	jc    srcerr            ;clean-up and return error
	
	Test uID, TRUE
	Jnz @F                	;jump if angle is required in radians
	Fmul [qarc]

	ftst                    ;check for negative angle
	fstsw ax                ;retrieve status word from FPU
	fwait
	sahf
@@:
	
	Fstp [RegTmp]    		;store result at specified address
	Frstor content         	;restore all previous FPU registers
	Pause
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Pause
	Lea Rax, [RegTmp]
	Ret

srcerr:
	Frstor content
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
	Lea Rax, [RegNull]
	Ret
FArcTangent64 EndP

;*******************************************************************************
;arcctg(x) = arctang(1/x))
;RegistrX, DegRad, BazeOutDq
;*******************************************************************************
FArcCotangent64 Proc FastCall Frame lpSrc:QWord, uID:QWord, lpSrc1:QWord
	Mov lpSrc, Rcx
	Mov uID, Rdx
	Mov lpSrc1, R8

	MOVmq RegTmp, RegNull
	Movlpd Xmm0, [qJedna]
	Divsd Xmm0, lpSrc
	Movlpd [RegTmp], Xmm0
	Invoke FArcTangent64, RegTmp, uID, lpSrc1
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Lea Rax, [RegTmp]
	Ret
FArcCotangent64 EndP
;*******************************************************************************
;						Druhá odmocnina SQR(x)
;RegistrX, BazeOutDq
;*******************************************************************************
FSqrt64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	Movlpd Xmm0, lpSrc
	Cvtsd2ss Xmm2, Xmm0											;double to fload conversion - we test the sign
	Movmskps Eax, Xmm2											;Extract the 4-bit sign mask from xmm and save in reg
	.If (Al != 0)
		Jmp fErr
	.EndIf
	Comisd Xmm0, [RegNull]										;test whether RegistrX is zero
Jz fErr1
	Sqrtsd Xmm0, Xmm0
	Movlpd [RegTmp], Xmm0
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
fErr:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err6
	Lea Rax, [RegNull]
	Ret
fErr1:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err4
	Lea Rax, [RegNull]
	Ret
FSqrt64 EndP

;*******************************************************************************
;log(Src) = log2(Src) * log10(2) -> Dest
;RegistrX, BazeOutDq
;*******************************************************************************
FLogx64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	Cvtsd2ss Xmm1, [lpSrc]				;double to float conversion - we test the sign
	Movmskps Eax, Xmm1					;Extract the 4-bit sign mask from xmm and save in reg
	.If (Al != 0)
		Jmp @F
	.EndIf
	Comisd Xmm1, [RegNull]				;we test whether the part is zero
		Jz @F
	Fsave content						;stores FPU registers and status word
	Fld [lpSrc]
	Fldlg2
    Fxch
    Fyl2x                   			;->[log2(Src)]*log10(2) = log(Src) base 10
    Fstp [RegTmp]
    Frstor content
    Nop
    Invoke FpuBinAsci64, lpSrc1, RegTmp
	Nop
	Lea Rax, [RegTmp]
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
	Lea Rax, [RegNull]
	Ret
FLogx64 EndP


;*******************************************************************************
;ln(Src) = log2(Src) * ln(2) -> Dest
;RegistrX, BazeOutDq
;*******************************************************************************
FLnx64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	Cvtsd2ss Xmm1, [lpSrc]				;double to float conversion - we test the sign
	Movmskps Eax, Xmm1					;Extract the 4-bit sign mask from xmm and save in reg
	.If (Al != 0)
		Jmp @F
	.EndIf
	Comisd Xmm1, [RegNull]				;we test whether the part is zero
	Jz @F								;if so then the transfer is over
	Fsave content						;stores FPU registers and status word
	Fld lpSrc
	Fldln2								;ln(2)
    Fxch
    Fyl2x               				;->[log2(Src)]*ln(2) = ln(Src)
    Fstp [RegTmp]
    Frstor content
	Nop
    Invoke FpuBinAsci64, lpSrc1, RegTmp
	Lea Rax, [RegTmp]
	Ret
@@:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err2
	Lea Rax, [RegNull]
	Ret
FLnx64 EndP
;*******************************************************************************
;function 1 / x
;RegistrX, BazeOutDq
;*******************************************************************************
F1DivX64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	Movlpd Xmm1, lpSrc													;loads the contents of RegistruX into Xmm2
	Comisd Xmm1, [RegNull]												;test whether RegistrX is zero
	Jz X0
	Movlpd Xmm1, qJedna
	Divsd Xmm1, lpSrc
	Movlpd [RegTmp], Xmm1
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Lea Rax, [RegTmp]
	Ret
X0:
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err3
	Lea Rax, [RegNull]
	Ret
F1DivX64 EndP


;*******************************************************************************
; 10^(Src) = antilog2[ log2(10) * Src ] -> Dest
;RegistrX, BazeOutDq
;*******************************************************************************
F10naX64 Proc FastCall Frame lpSrc:QWord, lpSrc1:QWord
	Local content[108]:Byte
	Mov lpSrc, Rcx
	Mov lpSrc1, Rdx

	MOVmq RegTmp, RegNull
	; Saves the current state of the FPU (operating environment and register stack) to a specified location in memory and then reinitializes the FPU.
	; The FSAVE instruction checks and handles pending floating-point exceptions before saving the FPU state.
	Fsave content
	Fld [lpSrc]				;we read a real number (Scr from RegistruX)
	Fldl2t                  ;->log2(10)
    Fmul                    ;->log2(10)*Src
    ; FPU can calculate antilog only with mantissa
	; therefore the logarithmic characteristic must be removed
	Fld St                	;make a copy of the logarithm
    Frndint                 ;let's keep only the characteristic
    Fsub St(1), St          ;we'll keep the mantissa
    Fxch                    ;mantisana on top of a stack
    f2xm1                   ;->2^(mantissa)-1
    Fld1					;1
    Fadd                    ;add 1
    ;the number must now be adjusted for the logarithm characteristic
    Fscale					;Shortens the value in the source operand (toward 0) to an integral value and adds this value to the exponent of the target operand.
    Fstsw Ax                ;retrieve exception flags from the FPU
    Fwait
    Shr Al, 1               ;Invalid operation test
    Jc @F                	;Error cleaning and returning registers

    ;the characteristic is still on the FPU and must be removed
    Fstp [RegTmp]			;It stores the contents of the top of the numeric coprocessor stack in the target operand (real number) and decrements it
    Frstor content         	;Retrieves the state of the FPU (operating environment and register stack) from the memory area specified by the source operand.
	Nop
	Invoke FpuBinAsci64, lpSrc1, RegTmp
	Lea Rax, [RegTmp]
	Ret
@@:
	Frstor content			;Restore a saved state from memory
	Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err1
	Lea Rax, [RegNull]
	Ret
F10naX64 EndP



;*******************************************************************************
;Src1^Src2 = antilog2[ log2(Src1) * Src2 ] -> Dest
;RegistrX, RegistrY, BazeOutDq	
;*******************************************************************************
FXnaY64 Proc FastCall Frame lpSrc1:QWord, lpSrc2:QWord, lpSbaze:QWord
		Local content[108]:Byte
		Mov lpSrc1, Rcx
		Mov lpSrc2, Rdx
		Mov lpSbaze, R8

		MOVmq RegTmp, RegNull
		Fsave content			;stores FPU registers and status word
		Fld lpSrc2				;we read a real number (Scr1)
		Fld lpSrc1				;we read a real number (Scr2)
		Fxch                   	;mantissa on top of the stack
	    Fyl2x                   ;->log2(Src1)*exponent
	    fld   st(0)             ;copy the logarithm
	    Frndint                 ;retain only the characteristic
	    Fsub St(1), St          ;preserve only the mantissa
	    Fxch                    ;get the mantissa to the top
	    f2xm1                   ;->2^(mantissa)-1
	    fld1
	    fadd                    ;add 1 back
		;the number must now be adjusted for the logarithm characteristic
	    Fscale                  ;scale with characteristic
		Fstp [RegTmp]
		Frstor content			;Restore a saved state from memory
		Nop
		Invoke FpuBinAsci64, lpSbaze, RegTmp
		Lea Rax, [RegTmp]
		Ret
FXnaY64 EndP

;-------------------------------------------------------------------------------
;This value is converted to Ascii according to the [Qbase] setting <-> hex, Dec, Oct, Bin
;Převedená hodnota je uložena na adresu [BuffaSCI] A ZOBRAZENA 
;popis jak na převod najdetede zde https://matematika.cz/prevod 
;qBaze = přenáděná báze   lpSrc1 = RegistrX   								           	 
;-------------------------------------------------------------------------------   
FpuBinAsci64 Proc FastCall Frame Uses Rdi Rsi qBaze:QWord, lpSrc1:QWord
			Local Buff1[16]:Byte
			Local LenCela:Byte
			Local RegistrAsci1[128]:Byte
			Local RegTemp0[128]:Byte
			Local RegTemp1[128]:Byte
			Mov qBaze, Rcx
			Mov lpSrc1, Rdx

			;resets RegistrAsci1, RegTemp, deletes data from Static1
			Invoke RtlZeroMemory, Addr (RegistrAsci1), eSizeM
			Invoke RtlZeroMemory, Addr (RegTemp0), eSizeM
			Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr RegistrAsci1

			Movlpd Xmm2, lpSrc1
			Comisd Xmm2, RegNull												;test whether RegistrX is zero
			Jnz @F
			Invoke SendMessage, hStatic, WM_SETTEXT, NULL, TextStr(" 0", 0)
			Ret
																				;if so, it will terminate the transfer
@@:			Cvtsd2si Rax, Xmm2
			And Rax, qMaska
			Jz @F
				Mulsd Xmm2, [qMinusJedna]										;if the number is negative we negate the value in RegistruX = RegistrX * (-1)
				Invoke lstrcat, Addr RegistrAsci1, TextStr('-', 0)				;if the number is negative it writes to the first place BuffAsci sign -
			Jmp L0
@@:				Invoke lstrcat, Addr RegistrAsci1, TextStr(' ', 0)
L0:			Roundsd Xmm1, Xmm2, 1												;Xmm1 = the whole part of the real number
			Subsd Xmm2, Xmm1
			Comisd Xmm1, RegNull												;we test whether the whole part is zero
			Jnz @F
			Invoke lstrcat, Addr RegistrAsci1, TextStr(' 0', 0)
			Jmp L22
@@:			Comisd Xmm1, RegNull												;we test whether the whole part is zero
			Jz L22
			;Xmm2 tenth part of a real number
			;Xmm1 the whole part of the real number
			;transfer the whole part of the number
			Mov [LenCela], 0H

L1:			Pause
			Divsd Xmm1, [qBaze]													;xmm1= xmm1/qbaze
			Movupd Xmm3, Xmm1 													;copy the whole part
			Roundsd Xmm3, Xmm1, 1												;cell
			Subsd Xmm1, Xmm3													;residue
			Mulsd Xmm1, [qBaze]													;the rest after division
			Cvtsd2si Rax, Xmm1													;the rest to Eax
			Movupd Xmm1, Xmm3
			Inc [LenCela]
			.If [BazeOut1] < 3													;dec,bin,oct
				Invoke wsprintf, Addr Buff1, Addr FmtA, Al, NULL
			.ElseIf [BazeOut1] == 3												;hex
				Invoke wsprintf, Addr Buff1, Addr FmtH, Al, NULL
			.EndIf
			Nop
			Invoke lstrcat, Addr RegTemp0, Addr Buff1
			Mov Cl, [LenCela]													;max. number of integer characters
			.If Cl > [SizeCela]
				Jmp L4															;overfilling
			.EndIf
			Comisd Xmm1, RegNull												;if Xmm1 is zero then it ends the cycle
			Jnz L1

			;we have to swap the byte, the first will be the last and so on
			Xor Rcx, Rcx
			Xor Rdx, Rdx
			Std
			Mov Cl, [LenCela]
			Mov Rdx, 1
			Lea Rsi, [RegTemp0 + Rcx - 1]
@@:			Lodsb
			Mov [RegistrAsci1 + Rdx], Al
			Inc Rdx
			Loop @B
			Cld
			;here the whole part will be rewritten in the correct order
L22:		Comisd Xmm2, RegNull												;we test whether the decimal part is zero
			Jz L3
																				;if the transfer is over
			;Xmm2 the decimal part of the number is not zero
			;We will solve the decimal number stored in Xmm2
			Invoke lstrcat, Addr RegistrAsci1, TextStr(".", 0)					;write the decimal point
			Mov Ecx, 15															;max. number of converted characters of the tenth part

L2:			Pause
			Mulsd Xmm2, [qBaze]													;Xmm2 = tenth part * Baze (bin, dec, oct, hex)
			Cvttsd2si Rax, Xmm2
			Cvtsi2sd Xmm1, Rax
			Subsd Xmm2, Xmm1													;decimal part of real number in Xmm0 64 bit
			Push Rcx
			.If [BazeOut1] < 3													;dec,bin,oct
				Invoke wsprintf, Addr Buff1, Addr FmtA, Al, NULL
			.ElseIf [BazeOut1] == 3												;hex
				Invoke wsprintf, Addr Buff1, Addr FmtH, Al, NULL
			.EndIf
			Nop
			Invoke lstrcat, Addr RegTemp1, Addr Buff1							;adds a character to BuffAsci
			Pop Rcx
			Dec Rcx
			Jnz L2

			;We remove trailing zeros
			Invoke lstrlen, Addr RegTemp1
			Mov Rcx, Rax
			Std
			Lea Rsi, [RegTemp1 + Rcx - 6]
			Mov Rdi, Rsi
@@:			Xor Rax, Rax
			Lodsb
			.If (Al == "0")
				Mov Rax, NULL
				Stosb
				Dec Ecx
				Loop @B
			.EndIf
			Cld
			Invoke lstrcat, Addr RegTemp1, TextStr("0", 0)
			Invoke lstrcat, Addr RegistrAsci1, Addr RegTemp1
L3:			Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr RegistrAsci1	;overwrites the character list from BuffAsci to a Static element
			Invoke RtlZeroMemory, Addr RegistrAsci1, eSizeM
			Invoke RtlZeroMemory, Addr RegTemp0, eSizeM
			Ret
L4:
			Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err5			;buffer overfilling
			Lea Rax, [RegNull]
			Ret
FpuBinAsci64 EndP
;***************************************************************************
;***************************************************************************

Infinity Proc FastCall Frame
		Invoke SendMessage, hStatic, WM_SETTEXT, NULL, Addr Err8
		Lea Rax, [RegNull]
		Ret
Infinity EndP

End

