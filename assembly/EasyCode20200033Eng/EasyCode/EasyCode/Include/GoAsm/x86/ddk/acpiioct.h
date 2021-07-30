;===========================================================;
;                                                           ;
;     acpiioct.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF ACPIIOCT_H
#Define ACPIIOCT_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

IOCTL_ACPI_ASYNC_EVAL_METHOD                                Equ         CTL_CODE(FILE_DEVICE_ACPI, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_ACPI_EVAL_METHOD                                      Equ         CTL_CODE(FILE_DEVICE_ACPI, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_ACPI_ACQUIRE_GLOBAL_LOCK                              Equ         CTL_CODE(FILE_DEVICE_ACPI, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_ACPI_RELEASE_GLOBAL_LOCK                              Equ         CTL_CODE(FILE_DEVICE_ACPI, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_ACPI_EVAL_METHOD_EX                                   Equ         CTL_CODE(FILE_DEVICE_ACPI, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_ACPI_ASYNC_EVAL_METHOD_EX                             Equ         CTL_CODE(FILE_DEVICE_ACPI, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_ACPI_ENUM_CHILDREN                                    Equ         CTL_CODE(FILE_DEVICE_ACPI, 8, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

ACPI_EVAL_INPUT_BUFFER Struct
    Signature                                               DD
    DUMMYUNIONNAME Union
        MethodName                                          DB          4 Dup ?
        MethodNameAsUlong                                   DD
    EndUnion
EndS

ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER Struct
    Signature                                               DD
    DUMMYUNIONNAME Union
        MethodName                                          DB          4 Dup ?
        MethodNameAsUlong                                   DD
    EndUnion
    IntegerArgument                                         DD
EndS

ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING Struct
    Signature                                               DD
    DUMMYUNIONNAME Union
        MethodName                                          DB          4 Dup ?
        MethodNameAsUlong                                   DD
    EndUnion
    StringLength                                            DD
    String                                                  DB          ANYSIZE_ARRAY Dup ?
EndS

ACPI_METHOD_ARGUMENT Struct
    Type                                                    DW
    DataLength                                              DW
    DUMMYUNIONNAME Union
        Argument                                            DD
        Data                                                DB          ANYSIZE_ARRAY Dup ?
    EndUnion
EndS

ACPI_EVAL_INPUT_BUFFER_COMPLEX Struct
    Signature                                               DD
    DUMMYUNIONNAME Union
        MethodName                                          DB          4 Dup ?
        MethodNameAsUlong                                   DD
    EndUnion
    Size                                                    DD
    ArgumentCount                                           DD
    Argument                                                ACPI_METHOD_ARGUMENT ANYSIZE_ARRAY Dup ?
EndS

ACPI_EVAL_OUTPUT_BUFFER Struct
    Signature                                               DD
    Length                                                  DD
    Count                                                   DD
    Argument                                                ACPI_METHOD_ARGUMENT ANYSIZE_ARRAY Dup ?
EndS

#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIGNATURE "BieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE "IieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE "SieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE "CieA"
#Define                                                     ACPI_EVAL_OUTPUT_BUFFER_SIGNATURE "BoeA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIGNATURE_EX "AieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE_EX "DieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE_EX "EieA"
#Define                                                     ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE_EX "FieA"
#Define                                                     ACPI_ENUM_CHILDREN_OUTPUT_BUFFER_SIGNATURE "GieA"
#Define                                                     ACPI_ENUM_CHILDREN_INPUT_BUFFER_SIGNATURE "HieA"

ACPI_METHOD_ARGUMENT_INTEGER                                Equ         00H
ACPI_METHOD_ARGUMENT_STRING                                 Equ         01H
ACPI_METHOD_ARGUMENT_BUFFER                                 Equ         02H
ACPI_METHOD_ARGUMENT_PACKAGE                                Equ         03H
ACPI_METHOD_ARGUMENT_PACKAGE_EX                             Equ         04H

ACPI_MANIPULATE_GLOBAL_LOCK_BUFFER Struct
    Signature                                               DD
    LockObject                                              DD
EndS

#Define                                                     ACPI_ACQUIRE_GLOBAL_LOCK_SIGNATURE "LgaA"
#Define                                                     ACPI_RELEASE_GLOBAL_LOCK_SIGNATURE "LgrA"

ACPI_EVAL_INPUT_BUFFER_EX Struct
    Signature                                               DD
    MethodName                                              DB          256 Dup ?
EndS

ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_EX Struct
    Signature                                               DD
    MethodName                                              DB          256 Dup ?
    IntegerArgument                                         DQ
EndS

ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_EX Struct
    Signature                                               DD
    MethodName                                              DB          256 Dup ?
    StringLength                                            DD
    String                                                  DB          ANYSIZE_ARRAY Dup ? 
EndS

ACPI_EVAL_INPUT_BUFFER_COMPLEX_EX Struct
    Signature                                               DD
    MethodName                                              DB          256 Dup ?
    Size                                                    DD
    ArgumentCount                                           DD
    Argument                                                ACPI_METHOD_ARGUMENT ANYSIZE_ARRAY Dup ?
EndS

ACPI_ENUM_CHILDREN_INPUT_BUFFER Struct
    Signature                                               DD
    Flags                                                   DD
    NameLength                                              DD
    Name                                                    DB          ANYSIZE_ARRAY Dup ?
EndS

ACPI_ENUM_CHILD Struct
    Flags                                                   DD
    NameLength                                              DD
    Name                                                    DB          ANYSIZE_ARRAY Dup ?
EndS

ACPI_ENUM_CHILDREN_OUTPUT_BUFFER Struct
    Signature                                               DD
    NumberOfChildren                                        DD
    Children                                                ACPI_ENUM_CHILD ANYSIZE_ARRAY Dup ?
EndS

ENUM_CHILDREN_IMMEDIATE_ONLY                                Equ         01H
ENUM_CHILDREN_MULTILEVEL                                    Equ         02H
ENUM_CHILDREN_NAME_IS_FILTER                                Equ         04H

ACPI_OBJECT_HAS_CHILDREN                                    Equ         01H

#ENDIF ;ACPIIOCT_H
