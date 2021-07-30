;===================================================================;
;                                                                   ;
;  acpiioct.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF ACPIIOCT_INC
ACPIIOCT_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IOCTL_ACPI_ASYNC_EVAL_METHOD                                Equ         CTL_CODE(FILE_DEVICE_ACPI, 0, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ACPI_EVAL_METHOD                                      Equ         CTL_CODE(FILE_DEVICE_ACPI, 1, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ACPI_ACQUIRE_GLOBAL_LOCK                              Equ         CTL_CODE(FILE_DEVICE_ACPI, 4, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ACPI_RELEASE_GLOBAL_LOCK                              Equ         CTL_CODE(FILE_DEVICE_ACPI, 5, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

IOCTL_ACPI_EVAL_METHOD_EX                                   Equ         CTL_CODE(FILE_DEVICE_ACPI, 6, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ACPI_ASYNC_EVAL_METHOD_EX                             Equ         CTL_CODE(FILE_DEVICE_ACPI, 7, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ACPI_ENUM_CHILDREN                                    Equ         CTL_CODE(FILE_DEVICE_ACPI, 8, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

ACPI_EVAL_INPUT_BUFFER Struct
    Signature                                               DD          ?
    Union DUMMYUNIONNAME
        MethodName                                          DB          4 Dup(?)
        MethodNameAsUlong                                   DD          ?
    EndS
ACPI_EVAL_INPUT_BUFFER EndS
PACPI_EVAL_INPUT_BUFFER                                     TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER Struct
    Signature                                               DD          ?
    Union DUMMYUNIONNAME
        MethodName                                          DB          4 Dup(?)
        MethodNameAsUlong                                   DD          ?
    EndS
    IntegerArgument                                         DD          ?
ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER EndS
PACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER                      TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING Struct
    Signature                                               DD          ?
    Union DUMMYUNIONNAME
        MethodName                                          DB          4 Dup(?)
        MethodNameAsUlong                                   DD          ?
    EndS
    StringLength                                            DD          ?
    String                                                  DB          ANYSIZE_ARRAY Dup(?)
ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING EndS
PACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING                       TypeDef     DWord

ACPI_METHOD_ARGUMENT Struct
    _Type                                                   DW          ?   ;Type
    DataLength                                              DW          ?
    Union DUMMYUNIONNAME
        Argument                                            DD          ?
        Data                                                DB          ANYSIZE_ARRAY Dup(?)
    EndS
ACPI_METHOD_ARGUMENT EndS
PACPI_METHOD_ARGUMENT                                       TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_COMPLEX Struct
    Signature                                               DD          ?
    Union DUMMYUNIONNAME
        MethodName                                          DB          4 Dup(?)
        MethodNameAsUlong                                   DD          ?
    EndS
    _Size                                                   DD          ? ;Size
    ArgumentCount                                           DD          ?
    Argument                                                ACPI_METHOD_ARGUMENT    ANYSIZE_ARRAY Dup(<>)
ACPI_EVAL_INPUT_BUFFER_COMPLEX EndS
PACPI_EVAL_INPUT_BUFFER_COMPLEX                             TypeDef     DWord

ACPI_EVAL_OUTPUT_BUFFER Struct
    Signature                                               DD          ?
    _Length                                                 DD          ?   ;Length
    Count                                                   DD          ?
    Argument                                                ACPI_METHOD_ARGUMENT    ANYSIZE_ARRAY Dup(<>)
ACPI_EVAL_OUTPUT_BUFFER EndS
PACPI_EVAL_OUTPUT_BUFFER                                    TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_SIGNATURE                            Equ         A("BieA")
ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE             Equ         A("IieA")
ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE              Equ         A("SieA")
ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE                    Equ         A("CieA")
ACPI_EVAL_OUTPUT_BUFFER_SIGNATURE                           Equ         A("BoeA")
ACPI_EVAL_INPUT_BUFFER_SIGNATURE_EX                         Equ         A("AieA")
ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE_EX          Equ         A("DieA")
ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE_EX           Equ         A("EieA")
ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE_EX                 Equ         A("FieA")
ACPI_ENUM_CHILDREN_OUTPUT_BUFFER_SIGNATURE                  Equ         A("GieA")
ACPI_ENUM_CHILDREN_INPUT_BUFFER_SIGNATURE                   Equ         A("HieA")

ACPI_METHOD_ARGUMENT_INTEGER                                Equ         00H
ACPI_METHOD_ARGUMENT_STRING                                 Equ         01H
ACPI_METHOD_ARGUMENT_BUFFER                                 Equ         02H
ACPI_METHOD_ARGUMENT_PACKAGE                                Equ         03H
ACPI_METHOD_ARGUMENT_PACKAGE_EX                             Equ         04H

ACPI_MANIPULATE_GLOBAL_LOCK_BUFFER Struct
    Signature                                               DD          ?
    LockObject                                              PVOID       ?
ACPI_MANIPULATE_GLOBAL_LOCK_BUFFER EndS
PACPI_MANIPULATE_GLOBAL_LOCK_BUFFER                         TypeDef     DWord

ACPI_ACQUIRE_GLOBAL_LOCK_SIGNATURE                          Equ         A("LgaA")
ACPI_RELEASE_GLOBAL_LOCK_SIGNATURE                          Equ         A("LgrA")

ACPI_EVAL_INPUT_BUFFER_EX Struct
    Signature                                               DD          ?
    MethodName                                              DB          256 Dup(?)
ACPI_EVAL_INPUT_BUFFER_EX EndS
PACPI_EVAL_INPUT_BUFFER_EX                                  TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_EX Struct
    Signature                                               DD          ?
    MethodName                                              DB          256 Dup(?)
    IntegerArgument                                         DQ          ?
ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_EX EndS
PACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_EX                   TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_EX Struct
    Signature                                               DD          ?
    MethodName                                              DB          256 Dup(?)
    StringLength                                            DD          ?
    String                                                  DB          ANYSIZE_ARRAY Dup (?)
ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_EX EndS
PACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_EX                    TypeDef     DWord

ACPI_EVAL_INPUT_BUFFER_COMPLEX_EX Struct
    Signature                                               DD          ?
    MethodName                                              DB          256 Dup(?)
    _Size                                                   DD          ?   ;Size
    ArgumentCount                                           DD          ?
    Argument                                                ACPI_METHOD_ARGUMENT    ANYSIZE_ARRAY Dup(<>)
ACPI_EVAL_INPUT_BUFFER_COMPLEX_EX EndS
PACPI_EVAL_INPUT_BUFFER_COMPLEX_EX                          TypeDef     DWord

ACPI_ENUM_CHILDREN_INPUT_BUFFER Struct
    Signature                                               DD          ?
    Flags                                                   DD          ?
    NameLength                                              DD          ?
    _Name                                                   DB          ANYSIZE_ARRAY Dup(?)
ACPI_ENUM_CHILDREN_INPUT_BUFFER EndS
PACPI_ENUM_CHILDREN_INPUT_BUFFER                            TypeDef     DWord

ACPI_ENUM_CHILD Struct
    Flags                                                   DD          ?
    NameLength                                              DD          ?
    _Name                                                   DB          ANYSIZE_ARRAY Dup(?)
ACPI_ENUM_CHILD EndS
PACPI_ENUM_CHILD                                            TypeDef     DWord

ACPI_ENUM_CHILDREN_OUTPUT_BUFFER Struct
    Signature                                               DD          ?
    NumberOfChildren                                        DD          ?
    Children                                                ACPI_ENUM_CHILD ANYSIZE_ARRAY Dup(<>)
ACPI_ENUM_CHILDREN_OUTPUT_BUFFER EndS
PACPI_ENUM_CHILDREN_OUTPUT_BUFFER                           TypeDef     DWord

ENUM_CHILDREN_IMMEDIATE_ONLY                                Equ         01H
ENUM_CHILDREN_MULTILEVEL                                    Equ         02H
ENUM_CHILDREN_NAME_IS_FILTER                                Equ         04H

ACPI_OBJECT_HAS_CHILDREN                                    Equ         01H

ENDIF ;ACPIIOCT_INC
