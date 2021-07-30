;===================================================================;
;                                                                   ;
;   accctrl.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF ACCCTRL_INC
ACCCTRL_INC Equ 1

IFNDEF WTYPES_INC
    Include wtypes.inc
ENDIF

AccFree                                     Equ     <LocalFree>

;TRUSTEE_TYPE Enumeration
TRUSTEE_TYPE                                TypeDef DWord
TRUSTEE_IS_UNKNOWN                          Equ     0
TRUSTEE_IS_USER                             Equ     1
TRUSTEE_IS_GROUP                            Equ     2
TRUSTEE_IS_DOMAIN                           Equ     3
TRUSTEE_IS_ALIAS                            Equ     4
TRUSTEE_IS_WELL_KNOWN_GROUP                 Equ     5
TRUSTEE_IS_DELETED                          Equ     6
TRUSTEE_IS_INVALID                          Equ     7

;TRUSTEE_FORM Enumeration
TRUSTEE_FORM                                TypeDef DWord
TRUSTEE_IS_SID                              Equ     0
TRUSTEE_IS_NAME                             Equ     1
TRUSTEE_BAD_FORM                            Equ     2

;MULTIPLE_TRUSTEE_OPERATION Enumeration
MULTIPLE_TRUSTEE_OPERATION                  TypeDef DWord
NO_MULTIPLE_TRUSTEE                         Equ     0
TRUSTEE_IS_IMPERSONATE                      Equ     1

;SE_OBJECT_TYPE Enumeration
SE_OBJECT_TYPE                              TypeDef DWord
SE_UNKNOWN_OBJECT_TYPE                      Equ     0
SE_FILE_OBJECT                              Equ     1
SE_SERVICE                                  Equ     2
SE_PRINTER                                  Equ     3
SE_REGISTRY_KEY                             Equ     4
SE_LMSHARE                                  Equ     5
SE_KERNEL_OBJECT                            Equ     6
SE_WINDOW_OBJECT                            Equ     7
SE_DS_OBJECT                                Equ     8
SE_DS_OBJECT_ALL                            Equ     9
SE_PROVIDER_DEFINED_OBJECT                  Equ     10

OBJECTS_AND_SID Struct
    ObjectsPresent                          DWord   ?
    ObjectTypeGuid                          GUID    <>
    InheritedObjectTypeGuid                 GUID    <>
    pSid                                    PVOID   ?
OBJECTS_AND_SID EndS

OBJECTS_AND_NAME_A Struct
    ObjectsPresent                          DWord   ?
    ObjectType                              SE_OBJECT_TYPE ?
    ObjectTypeName                          LPSTR   ?
    InheritedObjectTypeName                 LPSTR   ?
    ptstrName                               LPSTR   ?
OBJECTS_AND_NAME_A EndS
POBJECTS_AND_NAME_A                         TypeDef DWord

OBJECTS_AND_NAME_W Struct
    ObjectsPresent                          DWord   ?
    ObjectType                              SE_OBJECT_TYPE ?
    ObjectTypeName                          LPWSTR  ?
    InheritedObjectTypeName                 LPWSTR  ?
    ptstrName                               LPWSTR  ?
OBJECTS_AND_NAME_W EndS
POBJECTS_AND_NAME_W                         TypeDef DWord

PTRUSTEE_A                                  TypeDef DWord
TRUSTEE_A Struct
    pMultipleTrustee                        PTRUSTEE_A ?
    MultipleTrusteeOperation                MULTIPLE_TRUSTEE_OPERATION ?
    TrusteeForm                             TRUSTEE_FORM ?
    TrusteeType                             TRUSTEE_TYPE ?
    ptstrName                               LPSTR   ?
TRUSTEE_A EndS
TRUSTEEA                                    Equ     <TRUSTEE_A>
PTRUSTEEA                                   Equ     <PTRUSTEE_A>

PTRUSTEE_W                                  TypeDef DWord
TRUSTEE_W Struct
    pMultipleTrustee                        PTRUSTEE_W ?
    MultipleTrusteeOperation                MULTIPLE_TRUSTEE_OPERATION ?
    TrusteeForm                             TRUSTEE_FORM ?
    TrusteeType                             TRUSTEE_TYPE ?
    ptstrName                               LPWSTR  ?
TRUSTEE_W EndS
TRUSTEEW                                    Equ     <TRUSTEE_W>
PTRUSTEEW                                   Equ     <PTRUSTEE_W>

;ACCESS_MODE Enumeration
ACCESS_MODE                                 TypeDef DWord
NOT_USED_ACCESS                             Equ     0
GRANT_ACCESS                                Equ     1
SET_ACCESS                                  Equ     2
DENY_ACCESS                                 Equ     3
REVOKE_ACCESS                               Equ     4
SET_AUDIT_SUCCESS                           Equ     5
SET_AUDIT_FAILURE                           Equ     6

NO_INHERITANCE                              Equ     00H
SUB_OBJECTS_ONLY_INHERIT                    Equ     01H
SUB_CONTAINERS_ONLY_INHERIT                 Equ     02H
SUB_CONTAINERS_AND_OBJECTS_INHERIT          Equ     03H
INHERIT_NO_PROPAGATE                        Equ     04H
INHERIT_ONLY                                Equ     08H

INHERITED_ACCESS_ENTRY                      Equ     010H

INHERITED_PARENT                            Equ     010000000H
INHERITED_GRANDPARENT                       Equ     020000000H

EXPLICIT_ACCESS_A Struct
    grfAccessPermissions                    DWord   ?
    grfAccessMode                           ACCESS_MODE ?
    grfInheritance                          DWord   ?
    Trustee                                 TRUSTEE_A <>
EXPLICIT_ACCESS_A EndS
EXPLICIT_ACCESSA                            Equ     <EXPLICIT_ACCESS_A>
PEXPLICIT_ACCESS_A                          TypeDef DWord
PEXPLICIT_ACCESSA                           Equ     <PEXPLICIT_ACCESS_A>

EXPLICIT_ACCESS_W Struct
    grfAccessPermissions                    DWord   ?
    grfAccessMode                           ACCESS_MODE ?
    grfInheritance                          DWord   ?
    Trustee                                 TRUSTEE_W <>
EXPLICIT_ACCESS_W EndS
EXPLICIT_ACCESSW                            Equ     <EXPLICIT_ACCESS_W>
PEXPLICIT_ACCESS_W                          TypeDef DWord
PEXPLICIT_ACCESSW                           Equ     <PEXPLICIT_ACCESS_W>

ACCCTRL_DEFAULT_PROVIDERA                   Equ     A("Windows NT Access Provider")
ACCCTRL_DEFAULT_PROVIDERW                   Equ     L("Windows NT Access Provider")

ACCESS_RIGHTS                               TypeDef DWord
PACCESS_RIGHTS                              TypeDef DWord

INHERIT_FLAGS                               TypeDef DWord
PINHERIT_FLAGS                              TypeDef DWord

ACTRL_ACCESS_ENTRYA Struct
    Trustee                                 TRUSTEE_A <>
    fAccessFlags                            ULONG   ?
    Access                                  ACCESS_RIGHTS ?
    ProvSpecificAccess                      ACCESS_RIGHTS ?
    Inheritance                             INHERIT_FLAGS ?
    lpInheritProperty                       LPSTR   ?
ACTRL_ACCESS_ENTRYA EndS
PACTRL_ACCESS_ENTRYA                        TypeDef DWord

ACTRL_ACCESS_ENTRYW Struct
    Trustee                                 TRUSTEE_W <>
    fAccessFlags                            ULONG   ?
    Access                                  ACCESS_RIGHTS ?
    ProvSpecificAccess                      ACCESS_RIGHTS ?
    Inheritance                             INHERIT_FLAGS ?
    lpInheritProperty                       LPWSTR  ?
ACTRL_ACCESS_ENTRYW EndS
PACTRL_ACCESS_ENTRYW                        TypeDef DWord

ACTRL_ACCESS_ENTRY_LISTA Struct
    cEntries                                ULONG   ?
    pAccessList                             ACTRL_ACCESS_ENTRYA <>
ACTRL_ACCESS_ENTRY_LISTA EndS
PACTRL_ACCESS_ENTRY_LISTA                   TypeDef DWord

ACTRL_ACCESS_ENTRY_LISTW Struct
    cEntries                                ULONG   ?
    pAccessList                             ACTRL_ACCESS_ENTRYW <>
ACTRL_ACCESS_ENTRY_LISTW EndS
PACTRL_ACCESS_ENTRY_LISTW                   TypeDef DWord

ACTRL_PROPERTY_ENTRYA Struct
    lpProperty                              LPSTR   ?
    pAccessEntryList                        PACTRL_ACCESS_ENTRY_LISTA ?
    fListFlags                              ULONG   ?
ACTRL_PROPERTY_ENTRYA EndS
PACTRL_PROPERTY_ENTRYA                      TypeDef DWord

ACTRL_PROPERTY_ENTRYW Struct
    lpProperty                              LPWSTR  ?
    pAccessEntryList                        PACTRL_ACCESS_ENTRY_LISTW ?
    fListFlags                              ULONG   ?
ACTRL_PROPERTY_ENTRYW EndS
PACTRL_PROPERTY_ENTRYW                      TypeDef DWord

ACTRL_ACCESSA Struct
    cEntries                                ULONG   ?
    pPropertyAccessList                     PACTRL_PROPERTY_ENTRYA ?
ACTRL_ACCESSA EndS
ACTRL_AUDITA                                Equ     <ACTRL_ACCESSA>
_ACTRL_ALISTA                               Equ     <ACTRL_ACCESSA>
PACTRL_ACCESSA                              TypeDef DWord
PACTRL_AUDITA                               TypeDef DWord

ACTRL_ACCESSW Struct
    cEntries                                ULONG   ?
    pPropertyAccessList                     PACTRL_PROPERTY_ENTRYW ?
ACTRL_ACCESSW EndS
ACTRL_AUDITW                                Equ     <ACTRL_ACCESSW>
_ACTRL_ALISTW                               Equ     <ACTRL_ACCESSW>
PACTRL_ACCESSW                              TypeDef DWord
PACTRL_AUDITW                               TypeDef DWord

TRUSTEE_ACCESS_ALLOWED                      Equ     00000001H
TRUSTEE_ACCESS_READ                         Equ     00000002H
TRUSTEE_ACCESS_WRITE                        Equ     00000004H

TRUSTEE_ACCESS_EXPLICIT                     Equ     00000001H
TRUSTEE_ACCESS_READ_WRITE                   Equ     (TRUSTEE_ACCESS_READ Or TRUSTEE_ACCESS_WRITE)

TRUSTEE_ACCESS_ALL                          Equ     0FFFFFFFFH

TRUSTEE_ACCESSA Struct
    lpProperty                              LPSTR   ?
    Access                                  ACCESS_RIGHTS ?
    fAccessFlags                            ULONG   ?
    fReturnedAccess                         ULONG   ?
TRUSTEE_ACCESSA EndS
PTRUSTEE_ACCESSA                            TypeDef DWord

TRUSTEE_ACCESSW Struct
    lpProperty                              LPWSTR  ?
    Access                                  ACCESS_RIGHTS ?
    fAccessFlags                            ULONG   ?
    fReturnedAccess                         ULONG   ?
TRUSTEE_ACCESSW EndS
PTRUSTEE_ACCESSW                            TypeDef DWord

ACTRL_RESERVED                              Equ     00000000H
ACTRL_PERM_1                                Equ     00000001H
ACTRL_PERM_2                                Equ     00000002H
ACTRL_PERM_3                                Equ     00000004H
ACTRL_PERM_4                                Equ     00000008H
ACTRL_PERM_5                                Equ     00000010H
ACTRL_PERM_6                                Equ     00000020H
ACTRL_PERM_7                                Equ     00000040H
ACTRL_PERM_8                                Equ     00000080H
ACTRL_PERM_9                                Equ     00000100H
ACTRL_PERM_10                               Equ     00000200H
ACTRL_PERM_11                               Equ     00000400H
ACTRL_PERM_12                               Equ     00000800H
ACTRL_PERM_13                               Equ     00001000H
ACTRL_PERM_14                               Equ     00002000H
ACTRL_PERM_15                               Equ     00004000H
ACTRL_PERM_16                               Equ     00008000H
ACTRL_PERM_17                               Equ     00010000H
ACTRL_PERM_18                               Equ     00020000H
ACTRL_PERM_19                               Equ     00040000H
ACTRL_PERM_20                               Equ     00080000H

ACTRL_ACCESS_ALLOWED                        Equ     00000001H
ACTRL_ACCESS_DENIED                         Equ     00000002H
ACTRL_AUDIT_SUCCESS                         Equ     00000004H
ACTRL_AUDIT_FAILURE                         Equ     00000008H

ACTRL_ACCESS_PROTECTED                      Equ     00000001H

ACTRL_SYSTEM_ACCESS                         Equ     004000000H
ACTRL_DELETE                                Equ     008000000H
ACTRL_READ_CONTROL                          Equ     010000000H
ACTRL_CHANGE_ACCESS                         Equ     020000000H
ACTRL_CHANGE_OWNER                          Equ     040000000H
ACTRL_SYNCHRONIZE                           Equ     080000000H
ACTRL_STD_RIGHTS_ALL                        Equ     0F8000000H

ACTRL_DS_OPEN                               Equ     ACTRL_RESERVED
ACTRL_DS_CREATE_CHILD                       Equ     ACTRL_PERM_1
ACTRL_DS_DELETE_CHILD                       Equ     ACTRL_PERM_2
ACTRL_DS_LIST                               Equ     ACTRL_PERM_3
ACTRL_DS_SELF                               Equ     ACTRL_PERM_4
ACTRL_DS_READ_PROP                          Equ     ACTRL_PERM_5
ACTRL_DS_WRITE_PROP                         Equ     ACTRL_PERM_6
ACTRL_FILE_READ                             Equ     ACTRL_PERM_1
ACTRL_FILE_WRITE                            Equ     ACTRL_PERM_2
ACTRL_FILE_APPEND                           Equ     ACTRL_PERM_3
ACTRL_FILE_READ_PROP                        Equ     ACTRL_PERM_4
ACTRL_FILE_WRITE_PROP                       Equ     ACTRL_PERM_5
ACTRL_FILE_EXECUTE                          Equ     ACTRL_PERM_6
ACTRL_FILE_READ_ATTRIB                      Equ     ACTRL_PERM_7
ACTRL_FILE_WRITE_ATTRIB                     Equ     ACTRL_PERM_8
ACTRL_DIR_LIST                              Equ     ACTRL_PERM_1
ACTRL_DIR_CREATE_OBJECT                     Equ     ACTRL_PERM_2
ACTRL_DIR_CREATE_CHILD                      Equ     ACTRL_PERM_3
ACTRL_DIR_DELETE_CHILD                      Equ     ACTRL_PERM_4
ACTRL_DIR_TRAVERSE                          Equ     ACTRL_PERM_6
ACTRL_KERNEL_TERMINATE                      Equ     ACTRL_PERM_1
ACTRL_KERNEL_THREAD                         Equ     ACTRL_PERM_2
ACTRL_KERNEL_VM                             Equ     ACTRL_PERM_3
ACTRL_KERNEL_VM_READ                        Equ     ACTRL_PERM_4
ACTRL_KERNEL_VM_WRITE                       Equ     ACTRL_PERM_5
ACTRL_KERNEL_DUP_HANDLE                     Equ     ACTRL_PERM_6
ACTRL_KERNEL_PROCESS                        Equ     ACTRL_PERM_7
ACTRL_KERNEL_SET_INFO                       Equ     ACTRL_PERM_8
ACTRL_KERNEL_GET_INFO                       Equ     ACTRL_PERM_9
ACTRL_KERNEL_CONTROL                        Equ     ACTRL_PERM_10
ACTRL_KERNEL_ALERT                          Equ     ACTRL_PERM_11
ACTRL_KERNEL_GET_CONTEXT                    Equ     ACTRL_PERM_12
ACTRL_KERNEL_SET_CONTEXT                    Equ     ACTRL_PERM_13
ACTRL_KERNEL_TOKEN                          Equ     ACTRL_PERM_14
ACTRL_KERNEL_IMPERSONATE                    Equ     ACTRL_PERM_15
ACTRL_KERNEL_DIMPERSONATE                   Equ     ACTRL_PERM_16
ACTRL_PRINT_SADMIN                          Equ     ACTRL_PERM_1
ACTRL_PRINT_SLIST                           Equ     ACTRL_PERM_2
ACTRL_PRINT_PADMIN                          Equ     ACTRL_PERM_3
ACTRL_PRINT_PUSE                            Equ     ACTRL_PERM_4
ACTRL_PRINT_JADMIN                          Equ     ACTRL_PERM_5
ACTRL_SVC_GET_INFO                          Equ     ACTRL_PERM_1
ACTRL_SVC_SET_INFO                          Equ     ACTRL_PERM_2
ACTRL_SVC_STATUS                            Equ     ACTRL_PERM_3
ACTRL_SVC_LIST                              Equ     ACTRL_PERM_4
ACTRL_SVC_START                             Equ     ACTRL_PERM_5
ACTRL_SVC_STOP                              Equ     ACTRL_PERM_6
ACTRL_SVC_PAUSE                             Equ     ACTRL_PERM_7
ACTRL_SVC_INTERROGATE                       Equ     ACTRL_PERM_8
ACTRL_SVC_UCONTROL                          Equ     ACTRL_PERM_9
ACTRL_REG_QUERY                             Equ     ACTRL_PERM_1
ACTRL_REG_SET                               Equ     ACTRL_PERM_2
ACTRL_REG_CREATE_CHILD                      Equ     ACTRL_PERM_3
ACTRL_REG_LIST                              Equ     ACTRL_PERM_4
ACTRL_REG_NOTIFY                            Equ     ACTRL_PERM_5
ACTRL_REG_LINK                              Equ     ACTRL_PERM_6
ACTRL_WIN_CLIPBRD                           Equ     ACTRL_PERM_1
ACTRL_WIN_GLOBAL_ATOMS                      Equ     ACTRL_PERM_2
ACTRL_WIN_CREATE                            Equ     ACTRL_PERM_3
ACTRL_WIN_LIST_DESK                         Equ     ACTRL_PERM_4
ACTRL_WIN_LIST                              Equ     ACTRL_PERM_5
ACTRL_WIN_READ_ATTRIBS                      Equ     ACTRL_PERM_6
ACTRL_WIN_WRITE_ATTRIBS                     Equ     ACTRL_PERM_7
ACTRL_WIN_SCREEN                            Equ     ACTRL_PERM_8
ACTRL_WIN_EXIT                              Equ     ACTRL_PERM_9

ACTRL_OVERLAPPED Struct
    Reserved1                               ULONG   ?
    Reserved2                               ULONG   ?
    hEvent                                  HANDLE  ?
ACTRL_OVERLAPPED EndS
PACTRL_OVERLAPPED                           TypeDef DWord

ACTRL_ACCESS_INFOA Struct
    fAccessPermission                       ULONG   ?
    lpAccessPermissionName                  LPSTR   ?
ACTRL_ACCESS_INFOA EndS
PACTRL_ACCESS_INFOA                         TypeDef DWord

ACTRL_ACCESS_INFOW Struct
    fAccessPermission                       ULONG   ?
    lpAccessPermissionName                  LPWSTR  ?
ACTRL_ACCESS_INFOW EndS
PACTRL_ACCESS_INFOW                         TypeDef DWord

ACTRL_CONTROL_INFOA Struct
    lpControlId                             LPSTR   ?
    lpControlName                           LPSTR   ?
ACTRL_CONTROL_INFOA EndS
PACTRL_CONTROL_INFOA                        TypeDef DWord

ACTRL_CONTROL_INFOW Struct
    lpControlId                             LPWSTR  ?
    lpControlName                           LPWSTR  ?
ACTRL_CONTROL_INFOW EndS
PACTRL_CONTROL_INFOW                        TypeDef DWord

ACTRL_ACCESS_NO_OPTIONS                     Equ     00000000H
ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES        Equ     00000001H

IFDEF APP_UNICODE
    OBJECTS_AND_NAME_                       Equ     <OBJECTS_AND_NAME_W>
    POBJECTS_AND_NAME_                      Equ     <POBJECTS_AND_NAME_W>
    TRUSTEE                                 Equ     <TRUSTEE_W>
    TRUSTEE_                                Equ     <TRUSTEE_W>
    PTRUSTEE                                Equ     <PTRUSTEE_W>
    PTRUSTEE_                               Equ     <PTRUSTEE_W>
    EXPLICIT_ACCESS                         Equ     <EXPLICIT_ACCESS_W>
    EXPLICIT_ACCESS_                        Equ     <EXPLICIT_ACCESS_W>
    PEXPLICIT_ACCESS                        Equ     <PEXPLICIT_ACCESSW>
    PEXPLICIT_ACCESS_                       Equ     <PEXPLICIT_ACCESSW>
    ACCCTRL_DEFAULT_PROVIDER                Equ     <ACCCTRL_DEFAULT_PROVIDERW>
    ACTRL_ACCESS_ENTRY                      Equ     <ACTRL_ACCESS_ENTRYW>
    PACTRL_ACCESS_ENTRY                     Equ     <PACTRL_ACCESS_ENTRYW>
    ACTRL_ACCESS_ENTRY_LIST                 Equ     <ACTRL_ACCESS_ENTRY_LISTW>
    PACTRL_ACCESS_ENTRY_LIST                Equ     <PACTRL_ACCESS_ENTRY_LISTW>
    ACTRL_PROPERTY_ENTRY                    Equ     <ACTRL_PROPERTY_ENTRYW>
    PACTRL_PROPERTY_ENTRY                   Equ     <PACTRL_PROPERTY_ENTRYW>
    ACTRL_ACCESS                            Equ     <ACTRL_ACCESSW>
    ACTRL_AUDIT                             Equ     <ACTRL_AUDITW>
    PACTRL_ACCESS                           Equ     <PACTRL_ACCESSW>
    PACTRL_AUDIT                            Equ     <PACTRL_AUDITW>
    TRUSTEE_ACCESS                          Equ     <TRUSTEE_ACCESSW>
    PTRUSTEE_ACCESS                         Equ     <PTRUSTEE_ACCESSW>
    ACTRL_ACCESS_INFO                       Equ     <ACTRL_ACCESS_INFOW>
    PACTRL_ACCESS_INFO                      Equ     <PACTRL_ACCESS_INFOW>
    ACTRL_CONTROL_INFO                      Equ     <ACTRL_CONTROL_INFOW>
    PACTRL_CONTROL_INFO                     Equ     <PACTRL_CONTROL_INFOW>
ELSE
    OBJECTS_AND_NAME_                       Equ     <OBJECTS_AND_NAME_A>
    POBJECTS_AND_NAME_                      Equ     <POBJECTS_AND_NAME_A>
    TRUSTEE                                 Equ     <TRUSTEE_A>
    TRUSTEE_                                Equ     <TRUSTEE_A>
    PTRUSTEE                                Equ     <PTRUSTEE_A>
    PTRUSTEE_                               Equ     <PTRUSTEE_A>
    EXPLICIT_ACCESS                         Equ     <EXPLICIT_ACCESS_A>
    EXPLICIT_ACCESS_                        Equ     <EXPLICIT_ACCESS_A>
    PEXPLICIT_ACCESS                        Equ     <PEXPLICIT_ACCESSA>
    PEXPLICIT_ACCESS_                       Equ     <PEXPLICIT_ACCESSA>
    ACCCTRL_DEFAULT_PROVIDER                Equ     <ACCCTRL_DEFAULT_PROVIDERA>
    ACTRL_ACCESS_ENTRY                      Equ     <ACTRL_ACCESS_ENTRYA>
    PACTRL_ACCESS_ENTRY                     Equ     <PACTRL_ACCESS_ENTRYA>
    ACTRL_ACCESS_ENTRY_LIST                 Equ     <ACTRL_ACCESS_ENTRY_LISTA>
    PACTRL_ACCESS_ENTRY_LIST                Equ     <PACTRL_ACCESS_ENTRY_LISTA>
    ACTRL_PROPERTY_ENTRY                    Equ     <ACTRL_PROPERTY_ENTRYA>
    PACTRL_PROPERTY_ENTRY                   Equ     <PACTRL_PROPERTY_ENTRYA>
    ACTRL_ACCESS                            Equ     <ACTRL_ACCESSA>
    ACTRL_AUDIT                             Equ     <ACTRL_AUDITA>
    PACTRL_ACCESS                           Equ     <PACTRL_ACCESSA>
    PACTRL_AUDIT                            Equ     <PACTRL_AUDITA>
    TRUSTEE_ACCESS                          Equ     <TRUSTEE_ACCESSA>
    PTRUSTEE_ACCESS                         Equ     <PTRUSTEE_ACCESSA>
    ACTRL_ACCESS_INFO                       Equ     <ACTRL_ACCESS_INFOA>
    PACTRL_ACCESS_INFO                      Equ     <PACTRL_ACCESS_INFOA>
    ACTRL_CONTROL_INFO                      Equ     <ACTRL_CONTROL_INFOA>
    PACTRL_CONTROL_INFO                     Equ     <PACTRL_CONTROL_INFOA>
ENDIF

ENDIF ;ACCCTRL_INC
