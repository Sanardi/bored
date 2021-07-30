; ====================================================;
;                                                     ;
;   comdlg32.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.1)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef COMMDLG32_INC
COMMDLG32_INC equ 1

OFN_READONLY                                    equ     000000001H
OFN_OVERWRITEPROMPT                             equ     000000002H
OFN_HIDEREADONLY                                equ     000000004H
OFN_NOCHANGEDIR                                 equ     000000008H
OFN_SHOWHELP                                    equ     000000010H
OFN_ENABLEHOOK                                  equ     000000020H
OFN_ENABLETEMPLATE                              equ     000000040H
OFN_ENABLETEMPLATEHANDLE                        equ     000000080H
OFN_NOVALIDATE                                  equ     000000100H
OFN_ALLOWMULTISELECT                            equ     000000200H
OFN_EXTENSIONDIFFERENT                          equ     000000400H
OFN_PATHMUSTEXIST                               equ     000000800H
OFN_FILEMUSTEXIST                               equ     000001000H
OFN_CREATEPROMPT                                equ     000002000H
OFN_SHAREAWARE                                  equ     000004000H
OFN_NOREADONLYRETURN                            equ     000008000H
OFN_NOTESTFILECREATE                            equ     000010000H
OFN_NONETWORKBUTTON                             equ     000020000H
OFN_NOLONGNAMES                                 equ     000040000H
OFN_EXPLORER                                    equ     000080000H
OFN_NODEREFERENCELINKS                          equ     000100000H
OFN_LONGNAMES                                   equ     000200000H
OFN_ENABLEINCLUDENOTIFY                         equ     000400000H
OFN_ENABLESIZING                                equ     000800000H
OFN_DONTADDTORECENT                             equ     002000000H
OFN_FORCESHOWHIDDEN                             equ     010000000H
OFN_EX_NOPLACESBAR                              equ     000000001H

OFN_SHAREFALLTHROUGH                            equ     2
OFN_SHARENOWARN                                 equ     1
OFN_SHAREWARN                                   equ     0

CDN_FIRST                                       equ     (-601)
CDN_LAST                                        equ     (-699)

CDN_INITDONE                                    equ     (CDN_FIRST-00000H)
CDN_SELCHANGE                                   equ     (CDN_FIRST-00001H)
CDN_FOLDERCHANGE                                equ     (CDN_FIRST-00002H)
CDN_SHAREVIOLATION                              equ     (CDN_FIRST-00003H)
CDN_HELP                                        equ     (CDN_FIRST-00004H)
CDN_FILEOK                                      equ     (CDN_FIRST-00005H)
CDN_TYPECHANGE                                  equ     (CDN_FIRST-00006H)
CDN_INCLUDEITEM                                 equ     (CDN_FIRST-00007H)

CDM_FIRST                                       equ     (WM_USER+100)
CDM_LAST                                        equ     (WM_USER+200)

CDM_GETSPEC                                     equ     (CDM_FIRST+00000H)
CDM_GETFILEPATH                                 equ     (CDM_FIRST+00001H)
CDM_GETFOLDERPATH                               equ     (CDM_FIRST+00002H)
CDM_GETFOLDERIDLIST                             equ     (CDM_FIRST+00003H)
CDM_SETCONTROLTEXT                              equ     (CDM_FIRST+00004H)
CDM_HIDECONTROL                                 equ     (CDM_FIRST+00005H)
CDM_SETDEFEXT                                   equ     (CDM_FIRST+00006H)

CC_RGBINIT                                      equ     000000001H
CC_FULLOPEN                                     equ     000000002H
CC_PREVENTFULLOPEN                              equ     000000004H
CC_SHOWHELP                                     equ     000000008H
CC_ENABLEHOOK                                   equ     000000010H
CC_ENABLETEMPLATE                               equ     000000020H
CC_ENABLETEMPLATEHANDLE                         equ     000000040H
CC_SOLIDCOLOR                                   equ     000000080H
CC_ANYCOLOR                                     equ     000000100H

FR_DOWN                                         equ     000000001H
FR_WHOLEWORD                                    equ     000000002H
FR_MATCHCASE                                    equ     000000004H
FR_FINDNEXT                                     equ     000000008H
FR_REPLACE                                      equ     000000010H
FR_REPLACEALL                                   equ     000000020H
FR_DIALOGTERM                                   equ     000000040H
FR_SHOWHELP                                     equ     000000080H
FR_ENABLEHOOK                                   equ     000000100H
FR_ENABLETEMPLATE                               equ     000000200H
FR_NOUPDOWN                                     equ     000000400H
FR_NOMATCHCASE                                  equ     000000800H
FR_NOWHOLEWORD                                  equ     000001000H
FR_ENABLETEMPLATEHANDLE                         equ     000002000H
FR_HIDEUPDOWN                                   equ     000004000H
FR_HIDEMATCHCASE                                equ     000008000H
FR_HIDEWHOLEWORD                                equ     000010000H
FR_RAW                                          equ     000020000H

#ifndef FR_MATCHDIAC_DEF
    FR_MATCHDIAC_DEF equ 1
    FR_MATCHDIAC                                equ     020000000H
    FR_MATCHKASHIDA                             equ     040000000H
    FR_MATCHALEFHAMZA                           equ     080000000H
#endif

CF_SCREENFONTS                                  equ     000000001H
CF_PRINTERFONTS                                 equ     000000002H
CF_BOTH                                         equ     (CF_SCREENFONTS+CF_PRINTERFONTS)
CF_SHOWHELP                                     equ     000000004H
CF_ENABLEHOOK                                   equ     000000008H
CF_ENABLETEMPLATE                               equ     000000010H
CF_ENABLETEMPLATEHANDLE                         equ     000000020H
CF_INITTOLOGFONTSTRUCT                          equ     000000040H
CF_USESTYLE                                     equ     000000080H
CF_EFFECTS                                      equ     000000100H
CF_APPLY                                        equ     000000200H
CF_ANSIONLY                                     equ     000000400H
CF_SCRIPTSONLY                                  equ     CF_ANSIONLY
CF_NOVECTORFONTS                                equ     000000800H
CF_NOOEMFONTS                                   equ     CF_NOVECTORFONTS
CF_NOSIMULATIONS                                equ     000001000H
CF_LIMITSIZE                                    equ     000002000H
CF_FIXEDPITCHONLY                               equ     000004000H
CF_WYSIWYG                                      equ     000008000H
CF_FORCEFONTEXIST                               equ     000010000H
CF_SCALABLEONLY                                 equ     000020000H
CF_TTONLY                                       equ     000040000H
CF_NOFACESEL                                    equ     000080000H
CF_NOSTYLESEL                                   equ     000100000H
CF_NOSIZESEL                                    equ     000200000H
CF_SELECTSCRIPT                                 equ     000400000H
CF_NOSCRIPTSEL                                  equ     000800000H
CF_NOVERTFONTS                                  equ     001000000H

SIMULATED_FONTTYPE                              equ     08000H
PRINTER_FONTTYPE                                equ     04000H
SCREEN_FONTTYPE                                 equ     02000H
BOLD_FONTTYPE                                   equ     00100H
ITALIC_FONTTYPE                                 equ     00200H
REGULAR_FONTTYPE                                equ     00400H

OPENTYPE_FONTTYPE                               equ     010000H
TYPE1_FONTTYPE                                  equ     020000H
DSIG_FONTTYPE                                   equ     040000H

WM_CHOOSEFONT_GETLOGFONT                        equ     (WM_USER+1)
WM_CHOOSEFONT_SETLOGFONT                        equ     (WM_USER+101)
WM_CHOOSEFONT_SETFLAGS                          equ     (WM_USER+102)

CD_LBSELNOITEMS                                 equ     (-1)
CD_LBSELCHANGE                                  equ     0
CD_LBSELSUB                                     equ     1
CD_LBSELADD                                     equ     2

PD_ALLPAGES                                     equ     000000000H
PD_SELECTION                                    equ     000000001H
PD_PAGENUMS                                     equ     000000002H
PD_NOSELECTION                                  equ     000000004H
PD_NOPAGENUMS                                   equ     000000008H
PD_COLLATE                                      equ     000000010H
PD_PRINTTOFILE                                  equ     000000020H
PD_PRINTSETUP                                   equ     000000040H
PD_NOWARNING                                    equ     000000080H
PD_RETURNDC                                     equ     000000100H
PD_RETURNIC                                     equ     000000200H
PD_RETURNDEFAULT                                equ     000000400H
PD_SHOWHELP                                     equ     000000800H
PD_ENABLEPRINTHOOK                              equ     000001000H
PD_ENABLESETUPHOOK                              equ     000002000H
PD_ENABLEPRINTTEMPLATE                          equ     000004000H
PD_ENABLESETUPTEMPLATE                          equ     000008000H
PD_ENABLEPRINTTEMPLATEHANDLE                    equ     000010000H
PD_ENABLESETUPTEMPLATEHANDLE                    equ     000020000H
PD_USEDEVMODECOPIES                             equ     000040000H
PD_USEDEVMODECOPIESANDCOLLATE                   equ     000040000H
PD_DISABLEPRINTTOFILE                           equ     000080000H
PD_HIDEPRINTTOFILE                              equ     000100000H
PD_NONETWORKBUTTON                              equ     000200000H
PD_CURRENTPAGE                                  equ     000400000H
PD_NOCURRENTPAGE                                equ     000800000H
PD_EXCLUSIONFLAGS                               equ     001000000H
PD_USELARGETEMPLATE                             equ     010000000H
PD_EXCL_COPIESANDCOLLATE                        equ     (DM_COPIES+DM_COLLATE)
PD_RESULT_CANCEL                                equ     0
PD_RESULT_PRINT                                 equ     1
PD_RESULT_APPLY                                 equ     2

START_PAGE_GENERAL                              equ     0FFFFFFFFH

DN_DEFAULTPRN                                   equ     00001H

WM_PSD_PAGESETUPDLG                             equ     (WM_USER+0)
WM_PSD_FULLPAGERECT                             equ     (WM_USER+1)
WM_PSD_MINMARGINRECT                            equ     (WM_USER+2)
WM_PSD_MARGINRECT                               equ     (WM_USER+3)
WM_PSD_GREEKTEXTRECT                            equ     (WM_USER+4)
WM_PSD_ENVSTAMPRECT                             equ     (WM_USER+5)
WM_PSD_YAFULLPAGERECT                           equ     (WM_USER+6)

PSD_DEFAULTMINMARGINS                           equ     000000000H
PSD_INWININIINTLMEASURE                         equ     000000000H
PSD_MINMARGINS                                  equ     000000001H
PSD_MARGINS                                     equ     000000002H
PSD_INTHOUSANDTHSOFINCHES                       equ     000000004H
PSD_INHUNDREDTHSOFMILLIMETERS                   equ     000000008H
PSD_DISABLEMARGINS                              equ     000000010H
PSD_DISABLEPRINTER                              equ     000000020H
PSD_NOWARNING                                   equ     000000080H
PSD_DISABLEORIENTATION                          equ     000000100H
PSD_RETURNDEFAULT                               equ     000000400H
PSD_DISABLEPAPER                                equ     000000200H
PSD_SHOWHELP                                    equ     000000800H
PSD_ENABLEPAGESETUPHOOK                         equ     000002000H
PSD_ENABLEPAGESETUPTEMPLATE                     equ     000008000H
PSD_ENABLEPAGESETUPTEMPLATEHANDLE               equ     000020000H
PSD_ENABLEPAGEPAINTHOOK                         equ     000040000H
PSD_DISABLEPAGEPAINTING                         equ     000080000H
PSD_NONETWORKBUTTON                             equ     000200000H

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib comdlg32.lib
#else
    from_dll comdlg32.dll
#endif

import ChooseColorA
import ChooseColorW
import ChooseFontA
import ChooseFontW
import CommDlgExtendedError
import FindTextA
import FindTextW
import GetFileTitleA
import GetFileTitleW
import GetOpenFileNameA
import GetOpenFileNameW
import GetSaveFileNameA
import GetSaveFileNameW
import PageSetupDlgA
import PageSetupDlgW
import PrintDlgA
import PrintDlgW
import ReplaceTextA
import ReplaceTextW
#if NTDDI_VERSION >= NTDDI_WIN98_ME
    import LoadAlterBitmap
    import WantArrows
    import dwLBSubclass
    import dwOKSubclass
#endif
#if NTDDI_VERSION >= NTDDI_WIN2K
    import PrintDlgExA
    import PrintDlgExW
    import Ssync_ANSI_UNICODE_Struct_For_WOW
    #ifndef DllCanUnloadNow
        import DllCanUnloadNow
    #endif
    #ifndef DllGetClassObject
        import DllGetClassObject
    #endif
    #ifdef APP_UNICODE
        define PrintDlgEx PrintDlgExW
    #else
        define PrintDlgEx PrintDlgExA
    #endif
#endif

#ifdef APP_UNICODE
    define LBSELCHSTRING LBSELCHSTRINGW
    define SHAREVISTRING SHAREVISTRINGW
    define FILEOKSTRING FILEOKSTRINGW
    define COLOROKSTRING COLOROKSTRINGW
    define SETRGBSTRING SETRGBSTRINGW
    define HELPMSGSTRING HELPMSGSTRINGW
    define FINDMSGSTRING FINDMSGSTRINGW
    define ChooseColor ChooseColorW
    define ChooseFont ChooseFontW
    define FindText FindTextW
    define GetFileTitle GetFileTitleW
    define GetOpenFileName GetOpenFileNameW
    define GetSaveFileName GetSaveFileNameW
    define PageSetupDlg PageSetupDlgW
    define PrintDlg PrintDlgW
    define ReplaceText ReplaceTextW
#else
    define LBSELCHSTRING LBSELCHSTRINGA
    define SHAREVISTRING SHAREVISTRINGA
    define FILEOKSTRING FILEOKSTRINGA
    define COLOROKSTRING COLOROKSTRINGA
    define SETRGBSTRING SETRGBSTRINGA
    define HELPMSGSTRING HELPMSGSTRINGA
    define FINDMSGSTRING FINDMSGSTRINGA
    define ChooseColor ChooseColorA
    define ChooseFont ChooseFontA
    define FindText FindTextA
    define GetFileTitle GetFileTitleA
    define GetOpenFileName GetOpenFileNameA
    define GetSaveFileName GetSaveFileNameA
    define PageSetupDlg PageSetupDlgA
    define PrintDlg PrintDlgA
    define ReplaceText ReplaceTextA
#endif

#endif ;COMMDLG32_INC
