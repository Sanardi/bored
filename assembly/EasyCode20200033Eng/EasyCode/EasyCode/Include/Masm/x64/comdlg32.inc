; ======================================================;
;                                                       ;
;  comdlg32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.4)                      ;
;                                                       ;
;         Copyright © Ramon Sala - 2015-2020            ;
;                                                       ;
; ======================================================;

IFNDEF COMMDLG32_INC
COMMDLG32_INC   EQU     1

GUID_IID_IPrintDialogCallback                   EQU {05852A2C3H, 06530H, 011D1H, {0B6H, 0A3H, 000H, 000H, 0F8H, 075H, 07BH, 0F9H}}
GUID_IID_IPrintDialogServices                   EQU {0509AAEDAH, 05639H, 011D1H, {0B6H, 0A1H, 000H, 000H, 0F8H, 075H, 07BH, 0F9H}}

OFN_READONLY                                    EQU     000000001H
OFN_OVERWRITEPROMPT                             EQU     000000002H
OFN_HIDEREADONLY                                EQU     000000004H
OFN_NOCHANGEDIR                                 EQU     000000008H
OFN_SHOWHELP                                    EQU     000000010H
OFN_ENABLEHOOK                                  EQU     000000020H
OFN_ENABLETEMPLATE                              EQU     000000040H
OFN_ENABLETEMPLATEHANDLE                        EQU     000000080H
OFN_NOVALIDATE                                  EQU     000000100H
OFN_ALLOWMULTISELECT                            EQU     000000200H
OFN_EXTENSIONDIFFERENT                          EQU     000000400H
OFN_PATHMUSTEXIST                               EQU     000000800H
OFN_FILEMUSTEXIST                               EQU     000001000H
OFN_CREATEPROMPT                                EQU     000002000H
OFN_SHAREAWARE                                  EQU     000004000H
OFN_NOREADONLYRETURN                            EQU     000008000H
OFN_NOTESTFILECREATE                            EQU     000010000H
OFN_NONETWORKBUTTON                             EQU     000020000H
OFN_NOLONGNAMES                                 EQU     000040000H
OFN_EXPLORER                                    EQU     000080000H
OFN_NODEREFERENCELINKS                          EQU     000100000H
OFN_LONGNAMES                                   EQU     000200000H
OFN_ENABLEINCLUDENOTIFY                         EQU     000400000H
OFN_ENABLESIZING                                EQU     000800000H
OFN_DONTADDTORECENT                             EQU     002000000H
OFN_FORCESHOWHIDDEN                             EQU     010000000H
OFN_EX_NOPLACESBAR                              EQU     000000001H

OFN_SHAREFALLTHROUGH                            EQU     2
OFN_SHARENOWARN                                 EQU     1
OFN_SHAREWARN                                   EQU     0

CDN_FIRST                                       EQU     (0 - 601)
CDN_LAST                                        EQU     (0 - 699)

CDN_INITDONE                                    EQU     (CDN_FIRST - 00000H)
CDN_SELCHANGE                                   EQU     (CDN_FIRST - 00001H)
CDN_FOLDERCHANGE                                EQU     (CDN_FIRST - 00002H)
CDN_SHAREVIOLATION                              EQU     (CDN_FIRST - 00003H)
CDN_HELP                                        EQU     (CDN_FIRST - 00004H)
CDN_FILEOK                                      EQU     (CDN_FIRST - 00005H)
CDN_TYPECHANGE                                  EQU     (CDN_FIRST - 00006H)
CDN_INCLUDEITEM                                 EQU     (CDN_FIRST - 00007H)

CDM_FIRST                                       EQU     (WM_USER + 100)
CDM_LAST                                        EQU     (WM_USER + 200)

CDM_GETSPEC                                     EQU     (CDM_FIRST + 00000H)
CDM_GETFILEPATH                                 EQU     (CDM_FIRST + 00001H)
CDM_GETFOLDERPATH                               EQU     (CDM_FIRST + 00002H)
CDM_GETFOLDERIDLIST                             EQU     (CDM_FIRST + 00003H)
CDM_SETCONTROLTEXT                              EQU     (CDM_FIRST + 00004H)
CDM_HIDECONTROL                                 EQU     (CDM_FIRST + 00005H)
CDM_SETDEFEXT                                   EQU     (CDM_FIRST + 00006H)

WM_CHOOSEFONT_GETLOGFONT                        EQU     (WM_USER + 1)
WM_CHOOSEFONT_SETLOGFONT                        EQU     (WM_USER + 101)
WM_CHOOSEFONT_SETFLAGS                          EQU     (WM_USER + 102)

CC_RGBINIT                                      EQU     000000001H
CC_FULLOPEN                                     EQU     000000002H
CC_PREVENTFULLOPEN                              EQU     000000004H
CC_SHOWHELP                                     EQU     000000008H
CC_ENABLEHOOK                                   EQU     000000010H
CC_ENABLETEMPLATE                               EQU     000000020H
CC_ENABLETEMPLATEHANDLE                         EQU     000000040H
CC_SOLIDCOLOR                                   EQU     000000080H
CC_ANYCOLOR                                     EQU     000000100H

FR_DOWN                                         EQU     000000001H
FR_WHOLEWORD                                    EQU     000000002H
FR_MATCHCASE                                    EQU     000000004H
FR_FINDNEXT                                     EQU     000000008H
FR_REPLACE                                      EQU     000000010H
FR_REPLACEALL                                   EQU     000000020H
FR_DIALOGTERM                                   EQU     000000040H
FR_SHOWHELP                                     EQU     000000080H
FR_ENABLEHOOK                                   EQU     000000100H
FR_ENABLETEMPLATE                               EQU     000000200H
FR_NOUPDOWN                                     EQU     000000400H
FR_NOMATCHCASE                                  EQU     000000800H
FR_NOWHOLEWORD                                  EQU     000001000H
FR_ENABLETEMPLATEHANDLE                         EQU     000002000H
FR_HIDEUPDOWN                                   EQU     000004000H
FR_HIDEMATCHCASE                                EQU     000008000H
FR_HIDEWHOLEWORD                                EQU     000010000H
FR_RAW                                          EQU     000020000H
FR_MATCHDIAC                                    EQU     020000000H
FR_MATCHKASHIDA                                 EQU     040000000H
FR_MATCHALEFHAMZA                               EQU     080000000H

CF_SCREENFONTS                                  EQU     000000001H
CF_PRINTERFONTS                                 EQU     000000002H
CF_BOTH                                         EQU     (CF_SCREENFONTS OR CF_PRINTERFONTS)
CF_SHOWHELP                                     EQU     000000004H
CF_ENABLEHOOK                                   EQU     000000008H
CF_ENABLETEMPLATE                               EQU     000000010H
CF_ENABLETEMPLATEHANDLE                         EQU     000000020H
CF_INITTOLOGFONTSTRUCT                          EQU     000000040H
CF_USESTYLE                                     EQU     000000080H
CF_EFFECTS                                      EQU     000000100H
CF_APPLY                                        EQU     000000200H
CF_ANSIONLY                                     EQU     000000400H
CF_SCRIPTSONLY                                  EQU     CF_ANSIONLY
CF_NOVECTORFONTS                                EQU     000000800H
CF_NOOEMFONTS                                   EQU     CF_NOVECTORFONTS
CF_NOSIMULATIONS                                EQU     000001000H
CF_LIMITSIZE                                    EQU     000002000H
CF_FIXEDPITCHONLY                               EQU     000004000H
CF_WYSIWYG                                      EQU     000008000H
CF_FORCEFONTEXIST                               EQU     000010000H
CF_SCALABLEONLY                                 EQU     000020000H
CF_TTONLY                                       EQU     000040000H
CF_NOFACESEL                                    EQU     000080000H
CF_NOSTYLESEL                                   EQU     000100000H
CF_NOSIZESEL                                    EQU     000200000H
CF_SELECTSCRIPT                                 EQU     000400000H
CF_NOSCRIPTSEL                                  EQU     000800000H
CF_NOVERTFONTS                                  EQU     001000000H

SIMULATED_FONTTYPE                              EQU     08000H
PRINTER_FONTTYPE                                EQU     04000H
SCREEN_FONTTYPE                                 EQU     02000H
BOLD_FONTTYPE                                   EQU     00100H
ITALIC_FONTTYPE                                 EQU     00200H
REGULAR_FONTTYPE                                EQU     00400H

OPENTYPE_FONTTYPE                               EQU     010000H
TYPE1_FONTTYPE                                  EQU     020000H
DSIG_FONTTYPE                                   EQU     040000H

WM_CHOOSEFONT_GETLOGFONT                        EQU     (WM_USER + 1)
WM_CHOOSEFONT_SETLOGFONT                        EQU     (WM_USER + 101)
WM_CHOOSEFONT_SETFLAGS                          EQU     (WM_USER + 102)

LBSELCHSTRINGA                                  EQU     <commdlg_LBSelChangedNotify>
SHAREVISTRINGA                                  EQU     <commdlg_ShareViolation>
FILEOKSTRINGA                                   EQU     <commdlg_FileNameOK>
COLOROKSTRINGA                                  EQU     <commdlg_ColorOK>
SETRGBSTRINGA                                   EQU     <commdlg_SetRGBColor>
HELPMSGSTRINGA                                  EQU     <commdlg_help>
FINDMSGSTRINGA                                  EQU     <commdlg_FindReplace>

LBSELCHSTRINGW                                  EQU     L("commdlg_LBSelChangedNotify")
SHAREVISTRINGW                                  EQU     L("commdlg_ShareViolation")
FILEOKSTRINGW                                   EQU     L("commdlg_FileNameOK")
COLOROKSTRINGW                                  EQU     L("commdlg_ColorOK")
SETRGBSTRINGW                                   EQU     L("commdlg_SetRGBColor")
HELPMSGSTRINGW                                  EQU     L("commdlg_help")
FINDMSGSTRINGW                                  EQU     L("commdlg_FindReplace")

CD_LBSELNOITEMS                                 EQU     (-1)
CD_LBSELCHANGE                                  EQU     0
CD_LBSELSUB                                     EQU     1
CD_LBSELADD                                     EQU     2

PD_ALLPAGES                                     EQU     000000000H
PD_SELECTION                                    EQU     000000001H
PD_PAGENUMS                                     EQU     000000002H
PD_NOSELECTION                                  EQU     000000004H
PD_NOPAGENUMS                                   EQU     000000008H
PD_COLLATE                                      EQU     000000010H
PD_PRINTTOFILE                                  EQU     000000020H
PD_PRINTSETUP                                   EQU     000000040H
PD_NOWARNING                                    EQU     000000080H
PD_RETURNDC                                     EQU     000000100H
PD_RETURNIC                                     EQU     000000200H
PD_RETURNDEFAULT                                EQU     000000400H
PD_SHOWHELP                                     EQU     000000800H
PD_ENABLEPRINTHOOK                              EQU     000001000H
PD_ENABLESETUPHOOK                              EQU     000002000H
PD_ENABLEPRINTTEMPLATE                          EQU     000004000H
PD_ENABLESETUPTEMPLATE                          EQU     000008000H
PD_ENABLEPRINTTEMPLATEHANDLE                    EQU     000010000H
PD_ENABLESETUPTEMPLATEHANDLE                    EQU     000020000H
PD_USEDEVMODECOPIES                             EQU     000040000H
PD_USEDEVMODECOPIESANDCOLLATE                   EQU     000040000H
PD_DISABLEPRINTTOFILE                           EQU     000080000H
PD_HIDEPRINTTOFILE                              EQU     000100000H
PD_NONETWORKBUTTON                              EQU     000200000H
PD_CURRENTPAGE                                  EQU     000400000H
PD_NOCURRENTPAGE                                EQU     000800000H
PD_EXCLUSIONFLAGS                               EQU     001000000H
PD_USELARGETEMPLATE                             EQU     010000000H
PD_EXCL_COPIESANDCOLLATE                        EQU     (DM_COPIES OR DM_COLLATE)
PD_RESULT_CANCEL                                EQU     0
PD_RESULT_PRINT                                 EQU     1
PD_RESULT_APPLY                                 EQU     2

START_PAGE_GENERAL                              EQU     0FFFFFFFFH

DN_DEFAULTPRN                                   EQU     00001H

WM_PSD_PAGESETUPDLG                             EQU     (WM_USER + 0)
WM_PSD_FULLPAGERECT                             EQU     (WM_USER + 1)
WM_PSD_MINMARGINRECT                            EQU     (WM_USER + 2)
WM_PSD_MARGINRECT                               EQU     (WM_USER + 3)
WM_PSD_GREEKTEXTRECT                            EQU     (WM_USER + 4)
WM_PSD_ENVSTAMPRECT                             EQU     (WM_USER + 5)
WM_PSD_YAFULLPAGERECT                           EQU     (WM_USER + 6)

PSD_DEFAULTMINMARGINS                           EQU     000000000H
PSD_INWININIINTLMEASURE                         EQU     000000000H
PSD_MINMARGINS                                  EQU     000000001H
PSD_MARGINS                                     EQU     000000002H
PSD_INTHOUSANDTHSOFINCHES                       EQU     000000004H
PSD_INHUNDREDTHSOFMILLIMETERS                   EQU     000000008H
PSD_DISABLEMARGINS                              EQU     000000010H
PSD_DISABLEPRINTER                              EQU     000000020H
PSD_NOWARNING                                   EQU     000000080H
PSD_DISABLEORIENTATION                          EQU     000000100H
PSD_RETURNDEFAULT                               EQU     000000400H
PSD_DISABLEPAPER                                EQU     000000200H
PSD_SHOWHELP                                    EQU     000000800H
PSD_ENABLEPAGESETUPHOOK                         EQU     000002000H
PSD_ENABLEPAGESETUPTEMPLATE                     EQU     000008000H
PSD_ENABLEPAGESETUPTEMPLATEHANDLE               EQU     000020000H
PSD_ENABLEPAGEPAINTHOOK                         EQU     000040000H
PSD_DISABLEPAGEPAINTING                         EQU     000080000H
PSD_NONETWORKBUTTON                             EQU     000200000H

IF (NTDDI_VERSION GE NTDDI_VISTA)
    CommDlg_OpenSave_GetSpecA MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETSPEC
            mov r8, wparam
            mov r9, lparam
            call SendMessageA
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETSPEC
            push hwnd
            call SendMessageA
        ENDIF
    ENDM

    CommDlg_OpenSave_GetSpecW MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETSPEC
            mov r8, wparam
            mov r9, lparam
            call SendMessageW
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETSPEC
            push hwnd
            call SendMessageW
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFilePathA MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFILEPATH
            mov r8, wparam
            mov r9, lparam
            call SendMessageA
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFILEPATH
            push hwnd
            call SendMessageA
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFilePathW MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFILEPATH
            mov r8, wparam
            mov r9, lparam
            call SendMessageW
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFILEPATH
            push hwnd
            call SendMessageW
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFolderIDListA MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFOLDERIDLIST
            mov r8, wparam
            mov r9, lparam
            call SendMessageA
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFOLDERIDLIST
            push hwnd
            call SendMessageA
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFolderIDListW MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFOLDERIDLIST
            mov r8, wparam
            mov r9, lparam
            call SendMessageW
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFOLDERIDLIST
            push hwnd
            call SendMessageW
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFolderPathA MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFOLDERPATH
            mov r8, wparam
            mov r9, lparam
            call SendMessageA
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFOLDERPATH
            push hwnd
            call SendMessageA
        ENDIF
    ENDM

    CommDlg_OpenSave_GetFolderPathW MACRO hwnd, lparam, wparam
        IFDEF APP_WIN64
            sub rsp, 20H
            mov rcx, hwnd
            mov rdx, CDM_GETFOLDERPATH
            mov r8, wparam
            mov r9, lparam
            call SendMessageW
            add rsp, 20H
        ELSE
            push lparam
            push wparam
            push CDM_GETFOLDERPATH
            push hwnd
            call SendMessageW
        ENDIF
    ENDM

    IFDEF APP_UNICODE
        CommDlg_OpenSave_GetSpec EQU <CommDlg_OpenSave_GetSpecW>
        CommDlg_OpenSave_GetFilePath EQU <CommDlg_OpenSave_GetFilePathW>
        CommDlg_OpenSave_GetFolderIDList EQU <CommDlg_OpenSave_GetFolderIDListW>
        CommDlg_OpenSave_GetFolderPath EQU <CommDlg_OpenSave_GetFolderPathW>
    ELSE
        CommDlg_OpenSave_GetSpec EQU <CommDlg_OpenSave_GetSpecA>
        CommDlg_OpenSave_GetFilePath EQU <CommDlg_OpenSave_GetFilePathA>
        CommDlg_OpenSave_GetFolderIDList EQU <CommDlg_OpenSave_GetFolderIDListA>
        CommDlg_OpenSave_GetFolderPath EQU <CommDlg_OpenSave_GetFolderPathA>
    ENDIF
ENDIF

;======================================== Structures ======================================;
IPrintDialogCallback STRUCT
    UNION
        STRUCT
            QueryInterface  XPTR    ?
            AddRef          XPTR    ?
            Release         XPTR    ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    InitDone                XPTR    ?
    SelectionChange         XPTR    ?
    HandleMessage           XPTR    ?
IPrintDialogCallback ENDS

IPrintDialogServices STRUCT
    UNION
        STRUCT
            QueryInterface  XPTR    ?
            AddRef          XPTR    ?
            Release         XPTR    ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetCurrentDevMode       XPTR    ?
    GetCurrentPrinterName   XPTR    ?
    GetCurrentPortName      XPTR    ?
IPrintDialogServices ENDS

OPENFILENAMEA STRUCT ALIGNMODE
    lStructSize       DD        ?
                      DD        ?   ;Padding
    hwndOwner         HWND      ?
    hInstance         HINSTANCE ?
    lpstrFilter       LPCTSTR   ?
    lpstrCustomFilter LPTSTR    ?
    nMaxCustFilter    DD        ?
    nFilterIndex      DD        ?
    lpstrFile         LPTSTR    ?
    nMaxFile          DD        ?
                      DD        ?   ;Padding
    lpstrFileTitle    LPTSTR    ?
    nMaxFileTitle     DD        ?
                      DD        ?   ;Padding
    lpstrInitialDir   LPCTSTR   ?
    lpstrTitle        LPCTSTR   ?
    Flags             DD        ?
    nFileOffset       DW        ?
    nFileExtension    DW        ?
    lpstrDefExt       LPCTSTR   ?
    lCustData         LPARAM    ?
    lpfnHook          XPTR      ?
    lpTemplateName    LPCTSTR   ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        pvReserved    XPTR      ?
        dwReserved    DD        ?
        FlagsEx       DD        ?
    ENDIF
OPENFILENAMEA ENDS

OPENFILENAMEW STRUCT ALIGNMODE
    lStructSize       DD        ?
                      DD        ?   ;Padding
    hwndOwner         HWND      ?
    hInstance         HINSTANCE ?
    lpstrFilter       LPCWSTR   ?
    lpstrCustomFilter LPWSTR    ?
    nMaxCustFilter    DD        ?
    nFilterIndex      DD        ?
    lpstrFile         LPWSTR    ?
    nMaxFile          DD        ?
                      DD        ?   ;Padding
    lpstrFileTitle    LPWSTR    ?
    nMaxFileTitle     DD        ?
                      DD        ?   ;Padding
    lpstrInitialDir   LPCWSTR   ?
    lpstrTitle        LPCWSTR   ?
    Flags             DD        ?
    nFileOffset       DW        ?
    nFileExtension    DW        ?
    lpstrDefExt       LPCWSTR   ?
    lCustData         LPARAM    ?
    lpfnHook          XPTR      ?
    lpTemplateName    LPCWSTR   ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        pvReserved    XPTR      ?
        dwReserved    DD        ?
        FlagsEx       DD        ?
    ENDIF
OPENFILENAMEW ENDS

OFNOTIFYA STRUCT ALIGNMODE
    hdr     NMHDR  <>
    lpOFN   XPTR   ?
    pszFile LPTSTR ?
OFNOTIFYA ENDS

OFNOTIFYW STRUCT ALIGNMODE
    hdr     NMHDR  <>
    lpOFN   XPTR   ?
    pszFile LPWSTR ?
OFNOTIFYW ENDS

OFNOTIFYEXA STRUCT ALIGNMODE
    hdr     NMHDR  <>
    lpOFN   XPTR   ?
    psf     LPVOID ?
    pidl    LPVOID ?
OFNOTIFYEXA ENDS

OFNOTIFYEXW STRUCT ALIGNMODE
    hdr     NMHDR  <>
    lpOFN   XPTR   ?
    psf     LPVOID ?
    pidl    LPVOID ?
OFNOTIFYEXW ENDS

CHOOSECOLORA STRUCT ALIGNMODE
    lStructSize     DD       ?
    hwndOwner       HWND     ?
    hInstance       HWND     ?
    rgbResult       COLORREF ?
    lpCustColors    XPTR     ?
    Flags           DD       ?
    lCustData       LPARAM   ?
    lpfnHook        XPTR     ?
    lpTemplateName  LPCTSTR  ?
CHOOSECOLORA ENDS

CHOOSECOLORW STRUCT ALIGNMODE
    lStructSize     DD       ?
    hwndOwner       HWND     ?
    hInstance       HWND     ?
    rgbResult       COLORREF ?
    lpCustColors    XPTR     ?
    Flags           DD       ?
    lCustData       LPARAM   ?
    lpfnHook        XPTR     ?
    lpTemplateName  LPCWSTR  ?
CHOOSECOLORW ENDS

FINDREPLACEA STRUCT ALIGNMODE
    lStructSize      DD        ?
    hwndOwner        HWND      ?
    hInstance        HINSTANCE ?
    Flags            LPTSTR    ?
    lpstrFindWhat    LPTSTR    ?
    lpstrReplaceWith DD        ?
    wFindWhatLen     DW        ?
    wReplaceWithLen  DW        ?
    lCustData        LPARAM    ?
    lpfnHook         XPTR      ?
    lpTemplateName   LPCTSTR   ?
FINDREPLACEA ENDS

FINDREPLACEW STRUCT ALIGNMODE
    lStructSize      DD        ?
    hwndOwner        HWND      ?
    hInstance        HINSTANCE ?
    Flags            LPWSTR    ?
    lpstrFindWhat    LPWSTR    ?
    lpstrReplaceWith DD        ?
    wFindWhatLen     DW        ?
    wReplaceWithLen  DW        ?
    lCustData        LPARAM    ?
    lpfnHook         XPTR      ?
    lpTemplateName   LPCWSTR   ?
FINDREPLACEW ENDS

CHOOSEFONTA STRUCT ALIGNMODE
    lStructSize    DD        ?
    hwndOwner      HWND      ?
    hDC            HDC       ?
    lpLogFont      XPTR      ?
    iPointSize     DD        ?
    Flags          DD        ?
    rgbColors      COLORREF  ?
    lCustData      LPARAM    ?
    lpfnHook       XPTR      ?
    lpTemplateName LPCTSTR   ?
    hInstance      HINSTANCE ?
    lpszStyle      LPTSTR    ?
    nFontType      DW        ?
    missAlignment  DW        ?
    nSizeMin       DD        ?
    nSizeMax       DD        ?
CHOOSEFONTA ENDS

CHOOSEFONTW STRUCT ALIGNMODE
    lStructSize    DD        ?
    hwndOwner      HWND      ?
    hDC            HDC       ?
    lpLogFont      XPTR      ?
    iPointSize     DD        ?
    Flags          DD        ?
    rgbColors      COLORREF  ?
    lCustData      LPARAM    ?
    lpfnHook       XPTR      ?
    lpTemplateName LPCWSTR   ?
    hInstance      HINSTANCE ?
    lpszStyle      LPWSTR    ?
    nFontType      DW        ?
    missAlignment  DW        ?
    nSizeMin       DD        ?
    nSizeMax       DD        ?
CHOOSEFONTW ENDS

PRINTDLGA STRUCT ALIGNMODE
    lStructSize         DD        ?
    hwndOwner           HWND      ?
    hDevMode            HGLOBAL   ?
    hDevNames           HGLOBAL   ?
    hDC                 HDC       ?
    Flags               DD        ?
    nFromPage           DW        ?
    nToPage             DW        ?
    nMinPage            DW        ?
    nMaxPage            DW        ?
    nCopies             DW        ?
    hInstance           HINSTANCE ?
    lCustData           LPARAM    ?
    lpfnPrintHook       XPTR      ?
    lpfnSetupHook       XPTR      ?
    lpPrintTemplateName LPCTSTR   ?
    lpSetupTemplateName LPCTSTR   ?
    hPrintTemplate      HGLOBAL   ?
    hSetupTemplate      HGLOBAL   ?
PRINTDLGA ENDS

PRINTDLGW STRUCT ALIGNMODE
    lStructSize         DD        ?
    hwndOwner           HWND      ?
    hDevMode            HGLOBAL   ?
    hDevNames           HGLOBAL   ?
    hDC                 HDC       ?
    Flags               DD        ?
    nFromPage           DW        ?
    nToPage             DW        ?
    nMinPage            DW        ?
    nMaxPage            DW        ?
    nCopies             DW        ?
    hInstance           HINSTANCE ?
    lCustData           LPARAM    ?
    lpfnPrintHook       XPTR      ?
    lpfnSetupHook       XPTR      ?
    lpPrintTemplateName LPCWSTR   ?
    lpSetupTemplateName LPCWSTR   ?
    hPrintTemplate      HGLOBAL   ?
    hSetupTemplate      HGLOBAL   ?
PRINTDLGW ENDS

PRINTDLGEXA STRUCT ALIGNMODE
    lStructSize         DD        ?
    hwndOwner           HWND      ?
    hDevMode            HGLOBAL   ?
    hDevNames           HGLOBAL   ?
    hDC                 HDC       ?
    Flags               DD        ?
    Flags2              DD        ?
    ExclusionFlags      DD        ?
    nPageRanges         DD        ?
    nMaxPageRanges      DD        ?
    lpPageRanges        XPTR      ?
    nMinPage            DD        ?
    nMaxPage            DD        ?
    nCopies             DD        ?
    hInstance           HINSTANCE ?
    lpPrintTemplateName LPCTSTR   ?
    lpCallback          XPTR      ?
    nPropertyPages      DD        ?
    lphPropertyPages    XPTR      ?
    nStartPage          DD        ?
    dwResultAction      DD        ?
PRINTDLGEXA ENDS

PRINTDLGEXW STRUCT ALIGNMODE
    lStructSize         DD        ?
    hwndOwner           HWND      ?
    hDevMode            HGLOBAL   ?
    hDevNames           HGLOBAL   ?
    hDC                 HDC       ?
    Flags               DD        ?
    Flags2              DD        ?
    ExclusionFlags      DD        ?
    nPageRanges         DD        ?
    nMaxPageRanges      DD        ?
    lpPageRanges        XPTR      ?
    nMinPage            DD        ?
    nMaxPage            DD        ?
    nCopies             DD        ?
    hInstance           HINSTANCE ?
    lpPrintTemplateName LPCWSTR   ?
    lpCallback          XPTR      ?
    nPropertyPages      DD        ?
    lphPropertyPages    XPTR      ?
    nStartPage          DD        ?
    dwResultAction      DD        ?
PRINTDLGEXW ENDS

DEVNAMES STRUCT ALIGNMODE
    wDriverOffset DW  ?
    wDeviceOffset DW  ?
    wOutputOffset DW  ?
    wDefault      DW  ?
DEVNAMES ENDS

PAGESETUPDLGA STRUCT ALIGNMODE
    lStructSize             DD        ?
    hwndOwner               HWND      ?
    hDevMode                HGLOBAL   ?
    hDevNames               HGLOBAL   ?
    Flags                   DD        ?
    ptPaperSize             POINT     <>
    rtMinMargin             RECT      <>
    rtMargin                RECT      <>
    hInstance               HINSTANCE ?
    lCustData               LPARAM    ?
    lpfnPageSetupHook       XPTR      ?
    lpfnPagePaintHook       XPTR      ?
    lpPageSetupTemplateName LPCTSTR   ?
    hPageSetupTemplate      HGLOBAL   ?
PAGESETUPDLGA ENDS

PAGESETUPDLGW STRUCT ALIGNMODE
    lStructSize             DD        ?
    hwndOwner               HWND      ?
    hDevMode                HGLOBAL   ?
    hDevNames               HGLOBAL   ?
    Flags                   DD        ?
    ptPaperSize             POINT     <>
    rtMinMargin             RECT      <>
    rtMargin                RECT      <>
    hInstance               HINSTANCE ?
    lCustData               LPARAM    ?
    lpfnPageSetupHook       XPTR      ?
    lpfnPagePaintHook       XPTR      ?
    lpPageSetupTemplateName LPCWSTR   ?
    hPageSetupTemplate      HGLOBAL   ?
PAGESETUPDLGW ENDS

PRINTPAGERANGE STRUCT ALIGNMODE
    nFromPage DD  ?
    nToPage   DD  ?
PRINTPAGERANGE ENDS

;======================================== Functions =======================================;
ChooseColorA PROTO :XPTR
ChooseColorW PROTO :XPTR
ChooseFontA PROTO :XPTR
ChooseFontW PROTO :XPTR
CommDlgExtendedError PROTO
FindTextA PROTO :XPTR, :XWORD, :XWORD, :XWORD
FindTextW PROTO :XPTR, :XWORD, :XWORD, :XWORD
GetFileTitleA PROTO :LPCTSTR, :LPTSTR, :XWORD
GetFileTitleW PROTO :LPCWSTR, :LPWSTR, :XWORD
GetOpenFileNameA PROTO :XPTR
GetOpenFileNameW PROTO :XPTR
GetSaveFileNameA PROTO :XPTR
GetSaveFileNameW PROTO :XPTR
PageSetupDlgA PROTO :XPTR
PageSetupDlgW PROTO :XPTR
PrintDlgA PROTO :XPTR
PrintDlgW PROTO :XPTR
ReplaceTextA PROTO :XPTR
ReplaceTextW PROTO :XPTR

IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    LoadAlterBitmap PROTO :XWORD, :XWORD, :XWORD
    WantArrows PROTO :XWORD, :XWORD, :XWORD, :XWORD
    dwLBSubclass PROTO :XWORD, :XWORD, :XWORD, :XWORD
    dwOKSubclass PROTO :XWORD, :XWORD, :XWORD, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    PrintDlgExA PROTO :XPTR
    PrintDlgExW PROTO :XPTR
    Ssync_ANSI_UNICODE_Struct_For_WOW PROTO :XWORD, :XWORD, :XWORD
    IFNDEF DllCanUnloadNow
        DllCanUnloadNow PROTO
    ENDIF
    IFNDEF DllGetClassObject
        DllGetClassObject PROTO :XWORD, :XPTR, :XPTR
    ENDIF
    IFDEF APP_UNICODE
        PRINTDLGEX EQU <PRINTDLGEXW>
        PrintDlgEx EQU <PrintDlgExW>
    ELSE
        PRINTDLGEX EQU <PRINTDLGEXA>
        PrintDlgEx EQU <PrintDlgExA>
    ENDIF
ENDIF

IFDEF APP_UNICODE
    OPENFILENAME EQU <OPENFILENAMEW>
    OFNOTIFY EQU <OFNOTIFYW>
    OFNOTIFYEX EQU <OFNOTIFYEXW>
    CHOOSECOLOR EQU <CHOOSECOLORW>
    FINDREPLACE EQU <FINDREPLACEW>
    CHOOSEFONT EQU <CHOOSEFONTW>
    PRINTDLG EQU <PRINTDLGW>
    PAGESETUPDLG EQU <PAGESETUPDLGW>
    LBSELCHSTRING EQU <LBSELCHSTRINGW>
    SHAREVISTRING EQU <SHAREVISTRINGW>
    FILEOKSTRING EQU <FILEOKSTRINGW>
    COLOROKSTRING EQU <COLOROKSTRINGW>
    SETRGBSTRING EQU <SETRGBSTRINGW>
    HELPMSGSTRING EQU <HELPMSGSTRINGW>
    FINDMSGSTRING EQU <FINDMSGSTRINGW>
    ChooseColor EQU <ChooseColorW>
    ChooseFont EQU <ChooseFontW>
    FindText EQU <FindTextW>
    GetFileTitle EQU <GetFileTitleW>
    GetOpenFileName EQU <GetOpenFileNameW>
    GetSaveFileName EQU <GetSaveFileNameW>
    PageSetupDlg EQU <PageSetupDlgW>
    PrintDlg EQU <PrintDlgW>
    ReplaceText EQU <ReplaceTextW>
ELSE
    OPENFILENAME EQU <OPENFILENAMEA>
    OFNOTIFY EQU <OFNOTIFYA>
    OFNOTIFYEX EQU <OFNOTIFYEXA>
    CHOOSECOLOR EQU <CHOOSECOLORA>
    FINDREPLACE EQU <FINDREPLACEA>
    CHOOSEFONT EQU <CHOOSEFONTA>
    PRINTDLG EQU <PRINTDLGA>
    PAGESETUPDLG EQU <PAGESETUPDLGA>
    LBSELCHSTRING EQU <LBSELCHSTRINGA>
    SHAREVISTRING EQU <SHAREVISTRINGA>
    FILEOKSTRING EQU <FILEOKSTRINGA>
    COLOROKSTRING EQU <COLOROKSTRINGA>
    SETRGBSTRING EQU <SETRGBSTRINGA>
    HELPMSGSTRING EQU <HELPMSGSTRINGA>
    FINDMSGSTRING EQU <FINDMSGSTRINGA>
    ChooseColor EQU <ChooseColorA>
    ChooseFont EQU <ChooseFontA>
    FindText EQU <FindTextA>
    GetFileTitle EQU <GetFileTitleA>
    GetOpenFileName EQU <GetOpenFileNameA>
    GetSaveFileName EQU <GetSaveFileNameA>
    PageSetupDlg EQU <PageSetupDlgA>
    PrintDlg EQU <PrintDlgA>
    ReplaceText EQU <ReplaceTextA>
ENDIF

ENDIF ;COMMDLG32_INC
