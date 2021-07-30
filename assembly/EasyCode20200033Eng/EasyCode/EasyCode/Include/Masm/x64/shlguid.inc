; =====================================================;
;                                                      ;
;      shlguid.inc for Easy Code 2.0 Masm projects     ;
;                  (version 1.0.0)                     ;
;                                                      ;
;             Copyright © Ramon Sala 2021              ;
;                                                      ;
; =====================================================;

IFNDEF SHLGUID_INC
SHLGUID_INC EQU     1

GUID_CLSID_InternetShortcut                     EQU     {0FBF23B40H,0E3F0H,0101BH,{084H,088H,000H,0AAH,000H,03EH,056H,0F8H}}
GUID_IID_IUniformResourceLocatorA               EQU     {0FBF23B80H,0E3F0H,0101BH,{084H,088H,000H,0AAH,000H,03EH,056H,0F8H}}
GUID_IID_IUniformResourceLocatorW               EQU     {0CABB0DA0H,0DA57H,011CFH,{099H,074H,000H,020H,0AFH,0D7H,097H,062H}}

IFDEF APP_UNICODE
    GUID_IID_IUniformResourceLocator EQU <GUID_IID_IUniformResourceLocatorW>
ELSE
    GUID_IID_IUniformResourceLocator EQU <GUID_IID_IUniformResourceLocatorA>
ENDIF

;========================================== exdisp ========================================;
CSC_UPDATECOMMANDS                              EQU     0FFFFFFFFH
CSC_NAVIGATEFORWARD                             EQU     01H
CSC_NAVIGATEBACK                                EQU     02H

SWC_EXPLORER                                    EQU     0
SWC_BROWSER                                     EQU     01H
SWC_3RDPARTY                                    EQU     02H
SWC_CALLBACK                                    EQU     04H

SWFO_NEEDDISPATCH                               EQU     01H
SWFO_INCLUDEPENDING                             EQU     02H
SWFO_COOKIEPASSED                               EQU     04H

navOpenInNewWindow                              EQU     01H
navNoHistory                                    EQU     02H
navNoReadFromCache                              EQU     04H
navNoWriteToCache                               EQU     08H
navAllowAutosearch                              EQU     010H
navBrowserBar                                   EQU     020H

REFRESH_NORMAL                                  EQU     0
REFRESH_IFEXPIRED                               EQU     1
REFRESH_COMPLETELY                              EQU     3

;========================================== shldisp =======================================;
SCEE_PATHNOTFOUND                               EQU     1
SCEE_MAXFILESFOUND                              EQU     2
SCEE_INDEXSEARCH                                EQU     3
SCEE_CONSTRAINT                                 EQU     4
SCEE_SCOPEMISMATCH                              EQU     5
SCEE_CASESENINDEX                               EQU     6
SCEE_INDEXNOTCOMPLETE                           EQU     7

OFS_INACTIVE                                    EQU     (-1)
OFS_ONLINE                                      EQU     0
OFS_OFFLINE                                     EQU     1
OFS_SERVERBACK                                  EQU     2
OFS_DIRTYCACHE                                  EQU     3

SZ_MIGWIZPROGRESS_OK                            EQU     L("")

SZ_MIGWIZCOMPLETE_OK                            EQU     L("")
SZ_MIGWIZCOMPLETE_CANCEL                        EQU     L("Cancel")
SZ_MIGWIZCOMPLETE_FAIL                          EQU     L("Fail")
SZ_MIGWIZCOMPLETE_NODISK                        EQU     L("No Disk")

SFVVO_SHOWALLOBJECTS                            EQU     01H
SFVVO_SHOWEXTENSIONS                            EQU     02H
SFVVO_SHOWCOMPCOLOR                             EQU     08H
SFVVO_SHOWSYSFILES                              EQU     020H
SFVVO_WIN95CLASSIC                              EQU     040H
SFVVO_DOUBLECLICKINWEBVIEW                      EQU     080H
SFVVO_DESKTOPHTML                               EQU     0200H

ssfDESKTOP                                      EQU     0H
ssfPROGRAMS                                     EQU     02H
ssfCONTROLS                                     EQU     03H
ssfPRINTERS                                     EQU     04H
ssfPERSONAL                                     EQU     05H
ssfFAVORITES                                    EQU     06H
ssfSTARTUP                                      EQU     07H
ssfRECENT                                       EQU     08H
ssfSENDTO                                       EQU     09H
ssfBITBUCKET                                    EQU     0AH
ssfSTARTMENU                                    EQU     0BH
ssfDESKTOPDIRECTORY                             EQU     010H
ssfDRIVES                                       EQU     011H
ssfNETWORK                                      EQU     012H
ssfNETHOOD                                      EQU     013H
ssfFONTS                                        EQU     014H
ssfTEMPLATES                                    EQU     015H
ssfCOMMONSTARTMENU                              EQU     016H
ssfCOMMONPROGRAMS                               EQU     017H
ssfCOMMONSTARTUP                                EQU     018H
ssfCOMMONDESKTOPDIR                             EQU     019H
ssfAPPDATA                                      EQU     01AH
ssfPRINTHOOD                                    EQU     01BH
ssfLOCALAPPDATA                                 EQU     01CH
ssfALTSTARTUP                                   EQU     01DH
ssfCOMMONALTSTARTUP                             EQU     01EH
ssfCOMMONFAVORITES                              EQU     01FH
ssfINTERNETCACHE                                EQU     020H
ssfCOOKIES                                      EQU     021H
ssfHISTORY                                      EQU     022H
ssfCOMMONAPPDATA                                EQU     023H
ssfWINDOWS                                      EQU     024H
ssfSYSTEM                                       EQU     025H
ssfPROGRAMFILES                                 EQU     026H
ssfMYPICTURES                                   EQU     027H
ssfPROFILE                                      EQU     028H
ssfSYSTEMx86                                    EQU     029H
ssfPROGRAMFILESx86                              EQU     030H

STR_MYDOCS_CLSID                                EQU     L("{450D8FBA-AD25-11D0-98A8-0800361B1103}")

PID_FINDDATA                                    EQU     0
PID_NETRESOURCE                                 EQU     1
PID_DESCRIPTIONID                               EQU     2
PID_DISPLACED_FROM                              EQU     2
PID_DISPLACED_DATE                              EQU     3
PID_MISC_STATUS                                 EQU     2
PID_MISC_ACCESSCOUNT                            EQU     3
PID_MISC_OWNER                                  EQU     4
PID_HTMLINFOTIPFILE                             EQU     5
PID_VOLUME_FREE                                 EQU     2
PID_QUERY_RANK                                  EQU     2

SCE_SEARCHFORFILES                              EQU     0
SCE_SEARCHFORCOMPUTERS                          EQU     1

ACO_NONE                                        EQU     0
ACO_AUTOSUGGEST                                 EQU     01H
ACO_AUTOAPPEND                                  EQU     02H
ACO_SEARCH                                      EQU     04H
ACO_FILTERPREFIXES                              EQU     08H
ACO_USETAB                                      EQU     010H
ACO_UPDOWNKEYDROPSLIST                          EQU     020H
ACO_RTLREADING                                  EQU     040H

ACEO_NONE                                       EQU     0
ACEO_MOSTRECENTFIRST                            EQU     01H
ACEO_FIRSTUNUSED                                EQU     010000H

GUID_CLSID_ShellDesktop                         EQU     {000021400H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CLSID_ShellLink                            EQU     {000021401H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CLSID_NetworkPlaces                        EQU     {0208D2C60H,03AEAH,01069H,{0A2H,0D7H,008H,000H,02BH,030H,030H,09DH}}
GUID_CLSID_NetworkDomain                        EQU     {046E06680H,04BF0H,011D1H,{083H,0EEH,000H,0A0H,0C9H,00DH,0C8H,049H}}
GUID_CLSID_NetworkServer                        EQU     {0C0542A90H,04BF0H,011D1H,{083H,0EEH,000H,0A0H,0C9H,00DH,0C8H,049H}}
GUID_CLSID_NetworkShare                         EQU     {054A754C0H,04BF0H,011D1H,{083H,0EEH,000H,0A0H,0C9H,00DH,0C8H,049H}}
GUID_CLSID_MyComputer                           EQU     {020D04FE0H,03AEAH,01069H,{0A2H,0D8H,008H,000H,02BH,030H,030H,09DH}}
GUID_CLSID_Internet                             EQU     {0871C5380H,042A0H,01069H,{0A2H,0EAH,008H,000H,02BH,030H,030H,09DH}}
GUID_CLSID_ShellFSFolder                        EQU     {0F3364BA0H,065B9H,011CEH,{0A9H,0BAH,000H,0AAH,000H,04AH,0E8H,037H}}
GUID_CLSID_RecycleBin                           EQU     {0645FF040H,05081H,0101BH,{09FH,008H,000H,0AAH,000H,02FH,095H,04EH}}
GUID_CLSID_ControlPanel                         EQU     {021EC2020H,03AEAH,01069H,{0A2H,0DDH,008H,000H,02BH,030H,030H,09DH}}
GUID_CLSID_Printers                             EQU     {02227A280H,03AEAH,01069H,{0A2H,0DEH,008H,000H,02BH,030H,030H,09DH}}
GUID_CLSID_MyDocuments                          EQU     {0450D8FBAH,0AD25H,011D0H,{098H,0A8H,008H,000H,036H,01BH,011H,003H}}
GUID_CLSID_CFSIconOverlayManager                EQU     {063B51F81H,0C868H,011D0H,{099H,09CH,000H,0C0H,04FH,0D6H,055H,0E1H}}
GUID_CLSID_FolderShortcut                       EQU     {00AFACED1H,0E828H,011D1H,{091H,087H,0B5H,032H,0F1H,0E9H,057H,05DH}}
GUID_CLSID_CURLSearchHook                       EQU     {0CFBFAE00H,017A6H,011D0H,{099H,0CBH,000H,0C0H,04FH,0D6H,044H,097H}}
GUID_CLSID_CUrlHistory                          EQU     {03C374A40H,0BAE4H,011CFH,{0BFH,07DH,000H,0AAH,000H,069H,046H,0EEH}}
GUID_CLSID_AutoComplete                         EQU     {000BB2763H,06A77H,011D0H,{0A5H,035H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_CLSID_ACLHistory                           EQU     {000BB2764H,06A77H,011D0H,{0A5H,035H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_CLSID_ACListISF                            EQU     {003C036F1H,0A186H,011D0H,{082H,04AH,000H,0AAH,000H,05BH,043H,083H}}
GUID_CLSID_ACLMRU                               EQU     {06756A641H,0DE71H,011D0H,{083H,01BH,00H,0AAH,00H,05BH,043H,083H}}
GUID_CLSID_ACLMulti                             EQU     {000BB2765H,06A77H,011D0H,{0A5H,035H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_CLSID_ActiveDesktop                        EQU     {075048700H,0EF1FH,011D0H,{098H,088H,000H,060H,097H,0DEH,0ACH,0F9H}}
GUID_CLSID_TaskbarList                          EQU     {056FDF344H,0FD6DH,011D0H,{095H,08AH,00H,060H,097H,0C9H,0A0H,090H}}
GUID_CLSID_DocFileColumnProvider                EQU     {024F14F01H,07B1CH,011D1H,{083H,08FH,00H,00H,0F8H,04H,061H,0CFH}}
GUID_CLSID_LinkColumnProvider                   EQU     {024F14F02H,07B1CH,011D1H,{083H,08FH,00H,00H,0F8H,04H,061H,0CFH}}
GUID_CLSID_FileSysColumnProvider                EQU     {0D2E74C4H,03C34H,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_CLSID_InternetButtons                      EQU     {01E796980H,09CC5H,011D1H,{0A8H,03FH,000H,0C0H,04FH,0C9H,09DH,061H}}
GUID_CLSID_MSOButtons                           EQU     {0178F34B8H,0A282H,011D2H,{086H,0C5H,00H,0C0H,04FH,08EH,0EAH,099H}}
GUID_CLSID_ToolbarExtButtons                    EQU     {02CE4B5D8H,0A28FH,011D2H,{086H,0C5H,00H,0C0H,04FH,08EH,0EAH,099H}}
GUID_CLSID_DarwinAppPublisher                   EQU     {0CFCCC7A0H,0A282H,011D1H,{090H,082H,000H,060H,008H,005H,093H,082H}}
GUID_CLSID_DocHostUIHandler                     EQU     {07057E952H,0BD1BH,011D1H,{089H,019H,00H,0C0H,04FH,0C2H,0C8H,036H}}
GUID_CLSID_MountedVolume                        EQU     {012518493H,000B2H,011D2H,{09FH,0A5H,09EH,034H,020H,052H,041H,053H}}
GUID_CLSID_DragDropHelper                       EQU     {04657278AH,0411BH,011D2H,{083H,09AH,00H,0C0H,04FH,0D9H,018H,0D0H}}
GUID_CLSID_CAnchorBrowsePropertyPage            EQU     {03050F3BBH,098B5H,011CFH,{0BBH,082H,000H,0AAH,000H,0BDH,0CEH,00BH}}
GUID_CLSID_CImageBrowsePropertyPage             EQU     {03050F3B3H,098B5H,011CFH,{0BBH,082H,000H,0AAH,000H,0BDH,0CEH,00BH}}
GUID_CLSID_CDocBrowsePropertyPage               EQU     {03050F3B4H,098B5H,011CFH,{0BBH,082H,000H,0AAH,000H,0BDH,0CEH,00BH}}
GUID_CLSID_ProgressDialog                       EQU     {0F8383852H,0FCD3H,011D1H,{0A6H,0B9H,00H,060H,097H,0DFH,05BH,0D4H}}

GUID_IID_INewShortcutHookA                      EQU     {0000214E1H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellBrowser                          EQU     {0000214E2H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellView                             EQU     {0000214E3H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IContextMenu                           EQU     {0000214E4H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellIcon                             EQU     {0000214E5H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellFolder                           EQU     {0000214E6H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellExtInit                          EQU     {0000214E8H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellPropSheetExt                     EQU     {0000214E9H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IPersistFolder                         EQU     {0000214EAH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IExtractIconA                          EQU     {0000214EBH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellDetails                          EQU     {0000214ECH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IDelayedRelease                        EQU     {0000214EDH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellLinkA                            EQU     {0000214EEH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellCopyHookA                        EQU     {0000214EFH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IFileViewerA                           EQU     {0000214F0H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_ICommDlgBrowser                        EQU     {0000214F1H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IEnumIDList                            EQU     {0000214F2H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IFileViewerSite                        EQU     {0000214F3H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IContextMenu2                          EQU     {0000214F4H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellExecuteHookA                     EQU     {0000214F5H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IPropSheetPage                         EQU     {0000214F6H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_INewShortcutHookW                      EQU     {0000214F7H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IFileViewerW                           EQU     {0000214F8H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellLinkW                            EQU     {0000214F9H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IExtractIconW                          EQU     {0000214FAH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellExecuteHookW                     EQU     {0000214FBH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IShellCopyHookW                        EQU     {0000214FCH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IRemoteComputer                        EQU     {0000214FEH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IQueryInfo                             EQU     {000021500H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_ICopyHookA                             EQU     {0000214EFH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_ICopyHookW                             EQU     {0000214FCH,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_IID_IBriefcaseStg                          EQU     {08BCE1FA1H,00921H,0101BH,{0B1H,0FFH,000H,0DDH,001H,00CH,0CCH,048H}}
GUID_IID_IShellView2                            EQU     {088E39E80H,03578H,011CFH,{0AEH,069H,008H,000H,02BH,02EH,012H,062H}}
GUID_IID_IShellLinkDataList                     EQU     {045E2B4AEH,0B1C3H,011D0H,{0B9H,02FH,00H,0A0H,0C9H,03H,012H,0E1H}}
GUID_IID_IResolveShellLink                      EQU     {05CD52983H,09449H,011D2H,{096H,03AH,000H,0C0H,04FH,079H,0ADH,0F0H}}
GUID_IID_IURLSearchHook                         EQU     {0AC60F6A0H,00FD9H,011D0H,{099H,0CBH,000H,0C0H,04FH,0D6H,044H,097H}}
GUID_IID_IDelegateFolder                        EQU     {0ADD8BA80H,0002BH,011D0H,{08FH,00FH,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_IID_IInputObject                           EQU     {068284FAAH,06A48H,011D0H,{08CH,078H,00H,0C0H,04FH,0D9H,018H,0B4H}}
GUID_IID_IInputObjectSite                       EQU     {0F1DB8392H,07331H,011D0H,{08CH,099H,00H,0A0H,0C9H,02DH,0BFH,0E8H}}
GUID_IID_IDockingWindow                         EQU     {012DD920H,07B26H,011D0H,{08CH,0A9H,00H,0A0H,0C9H,02DH,0BFH,0E8H}}
GUID_IID_IDockingWindowSite                     EQU     {02A342FC2H,07B26H,011D0H,{08CH,0A9H,00H,0A0H,0C9H,02DH,0BFH,0E8H}}
GUID_IID_IDockingWindowFrame                    EQU     {047D2657AH,07B27H,011D0H,{08CH,0A9H,00H,0A0H,0C9H,02DH,0BFH,0E8H}}
GUID_IID_IShellIconOverlay                      EQU     {07D688A70H,0C613H,011D0H,{099H,09BH,000H,0C0H,04FH,0D6H,055H,0E1H}}
GUID_IID_IShellIconOverlayIdentifier            EQU     {00C6C4200H,0C589H,011D0H,{099H,09AH,000H,0C0H,04FH,0D6H,055H,0E1H}}
GUID_IID_ICommDlgBrowser2                       EQU     {010339516H,02894H,011D2H,{090H,039H,00H,0C0H,04FH,08EH,0EBH,03EH}}
GUID_IID_IPersistFolder2                        EQU     {01AC3D9F0H,0175CH,011D1H,{095H,0BEH,00H,060H,097H,097H,0EAH,04FH}}
GUID_IID_IPersistFolder3                        EQU     {0CEF04FDFH,0FE72H,011D2H,{087H,0A5H,00H,0C0H,04FH,068H,037H,0CFH}}
GUID_IID_IPersistFreeThreadedObject             EQU     {0C7264BF0H,0EDB6H,011D1H,{085H,046H,00H,060H,08H,05H,093H,068H}}
GUID_IID_IExtractImage                          EQU     {0BB2E617CH,0920H,011D1H,{09AH,0BH,00H,0C0H,04FH,0C2H,0D6H,0C1H}}
GUID_IID_IRunnableTask                          EQU     {085788D00H,06807H,011D0H,{0B8H,010H,00H,0C0H,04FH,0D7H,06H,0ECH}}
GUID_IID_IExtractImage2                         EQU     {0953BB1EEH,093B4H,011D1H,{098H,0A3H,00H,0C0H,04FH,0B6H,087H,0DAH}}
GUID_IID_IContextMenu3                          EQU     {0BCFCE0A0H,0EC17H,011D0H,{08DH,010H,00H,0A0H,0C9H,0FH,027H,019H}}
GUID_IID_IDeskBand                              EQU     {0EB0FE172H,01A3AH,011D0H,{089H,0B3H,000H,0A0H,0C9H,00AH,090H,0ACH}}
GUID_IID_IShellToolband                         EQU     {0EB0FE171H,01A3AH,011D0H,{089H,0B3H,000H,0A0H,0C9H,00AH,090H,0ACH}}
GUID_IID_IDiscardableBrowserProperty            EQU     {049C3DE7CH,0D329H,011D0H,{0ABH,073H,000H,0C0H,04FH,0C3H,03EH,080H}}
GUID_IID_IShellChangeNotify                     EQU     {0D82BE2B1H,05764H,011D0H,{0A9H,06EH,000H,0C0H,04FH,0D7H,005H,0A2H}}
GUID_IID_IAutoCompList                          EQU     {000BB2760H,06A77H,011D0H,{0A5H,035H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_IID_IObjMgr                                EQU     {000BB2761H,06A77H,011D0H,{0A5H,035H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_IID_IACList                                EQU     {077A130B0H,094FDH,011D0H,{0A5H,044H,000H,0C0H,04FH,0D7H,0D0H,062H}}
GUID_IID_IACList2                               EQU     {0470141A0H,05186H,011D2H,{0BBH,0B6H,000H,060H,097H,07BH,046H,04CH}}
GUID_IID_ICurrentWorkingDirectory               EQU     {091956D21H,09276H,011D1H,{092H,01AH,000H,060H,097H,0DFH,05BH,0D4H}}
GUID_IID_IProgressDialog                        EQU     {0EBBC7C04H,0315EH,011D2H,{0B6H,02FH,00H,060H,097H,0DFH,05BH,0D4H}}
GUID_IID_IActiveDesktop                         EQU     {0F490EB00H,01240H,011D1H,{098H,088H,000H,060H,097H,0DEH,0ACH,0F9H}}
GUID_IID_ITaskbarList                           EQU     {056FDF342H,0FD6DH,011D0H,{095H,08AH,00H,060H,097H,0C9H,0A0H,090H}}
GUID_IID_ITaskbarList2                          EQU     {0602D4995H,0B13AH,0429BH,{0A6H,06EH,019H,035H,0E4H,04FH,043H,017H}}    
GUID_IID_IDocFindFolder                         EQU     {0A5DF1EA0H,05702H,011D1H,{083H,0FAH,000H,0A0H,0C9H,00DH,0C8H,049H}}
GUID_IID_ISynchronizedCallBack                  EQU     {074C26041H,070D1H,011D1H,{0B7H,05AH,00H,0A0H,0C9H,05H,064H,0FEH}}
GUID_IID_IShellDetails3                         EQU     {0D2A105C0H,087D5H,011D1H,{083H,091H,00H,00H,0F8H,04H,061H,0CFH}}
GUID_IID_IQueryAssociations                     EQU     {0C46CA590H,03C3FH,011D2H,{0BEH,0E6H,000H,000H,0F8H,005H,0CAH,057H}}
GUID_IID_IColumnProvider                        EQU     {0E8025004H,01C42H,011D2H,{0BEH,02CH,00H,0A0H,0C9H,0A8H,03DH,0A1H}}
GUID_IID_IShellFolder2                          EQU     {093F2F68CH,01D1BH,011D3H,{0A3H,0EH,00H,0C0H,04FH,079H,0ABH,0D1H}}
GUID_IID_IEnumExtraSearch                       EQU     {0E700BE1H,09DB6H,011D1H,{0A1H,0CEH,00H,0C0H,04FH,0D7H,05DH,013H}}
GUID_IID_IMountedVolume                         EQU     {012518492H,000B2H,011D2H,{09FH,0A5H,09EH,034H,020H,052H,041H,053H}}
GUID_IID_IDropTargetHelper                      EQU     {04657278BH,0411BH,011D2H,{083H,09AH,00H,0C0H,04FH,0D9H,018H,0D0H}}
GUID_IID_IDragSourceHelper                      EQU     {0DE5BF786H,0477AH,011D2H,{083H,09DH,00H,0C0H,04FH,0D9H,018H,0D0H}}
GUID_IID_IDragSourceHelper2                     EQU     {083E07D0DH,00C5FH,04163H,{0BFH,01AH,060H,0B2H,074H,005H,01EH,040H}}
GUID_IID_IFileSystemBindData                    EQU     {01E18D10H,04D8BH,011D2H,{085H,05DH,00H,060H,08H,05H,093H,067H}}
GUID_IID_IQueryCancelAutoPlay                   EQU     {0DDEFE873H,06997H,04E68H,{0BEH,026H,039H,0B6H,033H,0ADH,0BEH,012H}}
GUID_IID_IDynamicHWHandler                      EQU     {0DC2601D7H,0059EH,042FCH,{0A0H,09DH,02AH,0FDH,021H,0B6H,0D5H,0F7H}}
GUID_IID_IActionProgress                        EQU     {049FF1173H,0EADCH,0446DH,{092H,085H,015H,064H,053H,0A6H,043H,01CH}}
GUID_IID_ISearchFolderItemFactory               EQU     {0A0FFBC28H,05482H,04366H,{0BEH,027H,03EH,081H,0E7H,08EH,006H,0C2H}}

GUID_IID_IShellView3                            EQU     {0EC39FA88H,0F8AFH,041C5H,{084H,021H,038H,0BEH,0D2H,08FH,046H,073H}}
GUID_IID_IFolderView                            EQU     {0CDE725B0H,0CCC9H,04519H,{091H,07EH,032H,05DH,072H,0FAH,0B4H,0CEH}}
GUID_IID_IFolderView2                           EQU     {01AF3A467H,0214FH,04298H,{090H,08EH,006H,0B0H,03EH,00BH,039H,0F9H}}
GUID_IID_IPreviewHandlerVisuals                 EQU     {0196BF9A5H,0B346H,04EF0H,{0AAH,01EH,05DH,0CDH,0B7H,067H,068H,0B1H}}
GUID_IID_IVisualProperties                      EQU     {0E693CF68H,0D967H,04112H,{087H,063H,099H,017H,02AH,0EEH,05EH,05AH}}
GUID_IID_ICommDlgBrowser3                       EQU     {0C8AD25A1H,03294H,041EEH,{081H,065H,071H,017H,04BH,0D0H,01CH,057H}}
GUID_IID_IColumnManager                         EQU     {0D8EC27BBH,03F3BH,04042H,{0B1H,00AH,04AH,0CFH,0D9H,024H,0D4H,053H}}
GUID_IID_IFolderFilterSite                      EQU     {0C0A651F5H,0B48BH,011D2H,{0B5H,0EDH,000H,060H,097H,0C6H,086H,0F6H}}
GUID_IID_IFolderFilter                          EQU     {09CC22886H,0DC8EH,011D2H,{0B1H,0D0H,000H,0C0H,04FH,08EH,0EBH,03EH}}
GUID_IID_IInputObject2                          EQU     {06915C085H,0510BH,044CDH,{094H,0AFH,028H,0DFH,0A5H,06CH,0F9H,02BH}}
GUID_IID_IFolderViewSettings                    EQU     {0AE8C987DH,08797H,04ED3H,{0BEH,072H,02AH,047H,0DDH,093H,08DH,0B0H}}
GUID_IID_ISearchBoxInfo                         EQU     {06AF6E03FH,0D664H,04EF4H,{096H,026H,0F7H,0E0H,0EDH,036H,075H,05EH}}

GUID_IID_IEnumShellImageStore                   EQU     {06DFD582BH,092E3H,011D1H,{098H,0A3H,000H,0C0H,04FH,0B6H,087H,0DAH}}
GUID_IID_IShellImageStore                       EQU     {048C8118CH,0B924H,011D1H,{098H,0D5H,000H,0C0H,04FH,0B6H,087H,0DAH}}
GUID_IID_IThumbnailCapture                      EQU     {04EA39266H,07211H,0409FH,{0B6H,022H,0F6H,03DH,0BDH,016H,0C5H,033H}}

GUID_IID_IShellItemImageFactory                 EQU     {0BCC18B79H,0BA16H,0442FH,{080H,0C4H,08AH,059H,0C3H,00CH,046H,03BH}}

GUID_IID_IContextMenu3                          EQU     {0BCFCE0A0H,0EC17H,011D0H,08DH,010H,00H,0A0H,0C9H,00FH,027H,019H}}
GUID_SID_DefView                                EQU     {06D12FE8H0,07911H,011CFH,095H,034H,00H,000H,0C0H,05BH,0AEH,00BH}}
GUID_CGID_DefView                               EQU     {04AF07F10H,0D231H,011D0H,0B9H,042H,00H,0A0H,0C9H,003H,012H,0E1H}}
GUID_CLSID_MenuBand                             EQU     {05B4DAE26H,0B807H,011D0H,098H,015H,00H,0C0H,04FH,0D9H,019H,072H}}

GUID_IID_IShellFolderBand                       EQU     {07FE80CC8H,0C247H,011D0H,{0B9H,03AH,000H,0A0H,0C9H,003H,012H,0E1H}}
GUID_IID_IDeskBarClient                         EQU     {0EB0FE175H,01A3AH,011D0H,{089H,0B3H,000H,0A0H,0C9H,00AH,090H,0ACH}}

GUID_IID_IDocViewSite                           EQU     {087D605E0H,0C511H,011CFH,{089H,0A9H,000H,0A0H,0C9H,005H,041H,029H}}
GUID_IID_IUserEventTimerCallback                EQU     {0E9EAD8E6H,02A25H,0410EH,{09BH,058H,0A9H,0FBH,0EFH,01DH,0D1H,0A2H}}
GUID_IID_IUserEventTimer                        EQU     {00F504B94H,06E42H,042E6H,{099H,0E0H,0E2H,00FH,0AFH,0E5H,02AH,0B4H}}
GUID_IID_ICDBurn                                EQU     {03D73A659H,0E5D0H,04D42H,{0AFH,0C0H,051H,021H,0BAH,042H,05CH,08DH}}
GUID_IID_ICDBurnExt                             EQU     {02271DCCAH,074FCH,04414H,{08FH,0B7H,0C5H,06BH,005H,0ACH,0E2H,0D7H}}
GUID_IID_IWizardSite                            EQU     {088960F5BH,0422FH,04E7BH,{080H,013H,073H,041H,053H,081H,0C3H,0C3H}}
GUID_IID_IWizardExtension                       EQU     {0C02EA696H,086CCH,0491EH,{09BH,023H,074H,039H,04AH,004H,044H,0A8H}}
GUID_IID_IWebWizardExtension                    EQU     {00E6B3F66H,098D1H,048C0H,{0A2H,022H,0FBH,0DEH,074H,0E2H,0FBH,0C5H}}
GUID_IID_IPublishingWizard                      EQU     {0AA9198BBH,0CCECH,0472DH,{0BEH,0EDH,019H,0A4H,0F6H,073H,03FH,07AH}}
GUID_IID_IFolderViewHost                        EQU     {01EA58F02H,0D55AH,0411DH,{0B0H,09EH,09EH,065H,0ACH,021H,060H,05BH}}
GUID_IID_IAutoCompleteDropDown                  EQU     {03CD141F4H,03C6AH,011D2H,{0BCH,0AAH,000H,0C0H,04FH,0D9H,029H,0DBH}}
GUID_IID_IModalWindow                           EQU     {0B4DB1657H,070D7H,0485EH,{08EH,03EH,06FH,0CBH,05AH,05CH,018H,002H}}
GUID_IID_IPassportWizard                        EQU     {0A09DB586H,09180H,041ACH,{091H,014H,046H,00AH,07FH,036H,02BH,076H}}
GUID_IID_IDVGetEnum                             EQU     {070F55181H,05FEAH,04900H,{0B6H,0B8H,073H,043H,0CBH,00AH,034H,08CH}}
GUID_IID_IInsertItem                            EQU     {0D2B57227H,03D23H,04B95H,{093H,0C0H,049H,02BH,0D4H,054H,0C3H,056H}}
GUID_IID_IDeskBar                               EQU     {0EB0FE173H,01A3AH,011D0H,{089H,0B3H,000H,0A0H,0C9H,00AH,090H,0ACH}}
GUID_IID_IMenuBand                              EQU     {0568804CDH,0CBD7H,011D0H,{098H,016H,000H,0C0H,04FH,0D9H,019H,072H}}
GUID_IID_IFolderBandPriv                        EQU     {047C01F95H,0E185H,0412CH,{0B5H,0C5H,04FH,027H,0DFH,096H,05AH,0EAH}}
GUID_IID_IBandSite                              EQU     {04CF504B0H,0DE96H,011D0H,{08BH,03FH,000H,0A0H,0C9H,011H,0E8H,0E5H}}
GUID_IID_INamespaceWalkCB                       EQU     {0D92995F8H,0CF5EH,04A76H,{0BFH,059H,0EAH,0D3H,09EH,0A2H,0B9H,07EH}}
GUID_IID_INamespaceWalk                         EQU     {057CED8A7H,03F4AH,0432CH,{093H,050H,030H,0F2H,044H,083H,0F7H,04FH}}
GUID_IID_IRegTreeItem                           EQU     {0A9521922H,00812H,04D44H,{09EH,0C3H,07FH,0D3H,08CH,072H,06FH,03DH}}
GUID_IID_IMenuPopup                             EQU     {0D1E7AFEBH,06A2EH,011D0H,{08CH,078H,000H,0C0H,04FH,0D9H,018H,0B4H}}
GUID_IID_IImageRecompress                       EQU     {0505F1513H,06B3EH,04892H,{0A2H,072H,059H,0F8H,088H,09AH,04DH,03EH}}
GUID_IID_IDefViewSafety                         EQU     {09A93B3FBH,04E75H,04C74H,{087H,01AH,02CH,0DAH,066H,07FH,039H,0A5H}}
GUID_IID_IContextMenuSite                       EQU     {00811AEBEH,00B87H,04C54H,{09EH,072H,054H,08CH,0F6H,049H,001H,06BH}}
GUID_IID_IBrowserFrameOptions                   EQU     {010DF43C8H,01DBEH,011D3H,{08BH,034H,000H,060H,097H,0DFH,05BH,0D4H}}
GUID_IID_INewWindowManager                      EQU     {0D2BC4C84H,03F72H,04A52H,{0A6H,004H,07BH,0CBH,0F3H,098H,02CH,0BBH}}
GUID_IID_IKnownFolder                           EQU     {03AA7AF7EH,09B36H,0420CH,{0A8H,0E3H,0F7H,07DH,046H,074H,0A4H,088H}}
GUID_IID_IKnownFolderManager                    EQU     {08BE2D872H,086AAH,04D47H,{0B7H,076H,032H,0CCH,0A4H,00CH,070H,018H}}
GUID_IID_ISharingConfigurationManager           EQU     {0B4CD448AH,09C86H,04466H,{092H,001H,02EH,062H,010H,05BH,087H,0AEH}}
GUID_IID_IPreviousVersionsInfo                  EQU     {076E54780H,0AD74H,048E3H,{0A6H,095H,03BH,0A9H,0A0H,0AFH,0F1H,00DH}}

IF NTDDI_VERSION LT NTDDI_VISTA
    GUID_IID_IDefViewFrame                      EQU     {0710EB7A0H,045EDH,011D0H,{092H,04AH,00H,020H,0AFH,0C7H,0ACH,04DH}}
    CLSID_ShellThumbnailDiskCache               EQU     {01EBDCF80H,0A200H,011D0H,{0A3H,0A4H,00H,0C0H,04FH,0D7H,006H,0ECH}}
ENDIF

GUID_IID_IShellItem                             EQU     {043826D1EH,0E718H,042EEH,{0BCH,055H,0A1H,0E2H,061H,0C3H,07BH,0FEH}}
GUID_IID_IShellItem2                            EQU     {07E9FB0D3H,0919FH,04307H,{0ABH,02EH,09BH,018H,060H,031H,00CH,093H}}

GUID_IID_INamedPropertyBag                      EQU     {0FB700430H,0952CH,011D1H,{094H,06FH,000H,000H,000H,000H,000H,000H}}

GUID_IID_IShellFolderView                       EQU     {037A378C0H,0F82DH,011CEH,{0AEH,065H,008H,000H,02BH,02EH,012H,062H}}

GUID_IID_IInitializeObject                      EQU     {04622AD16H,0FF23H,011D0H,{08DH,034H,000H,0A0H,0C9H,00FH,027H,019H}}
GUID_IID_IBanneredBar                           EQU     {0596A9A94H,0013EH,011D1H,{08DH,034H,000H,0A0H,0C9H,00FH,027H,019H}}
GUID_IID_IShellFolderViewCB                     EQU     {02047E320H,0F2A9H,011CEH,{0AEH,065H,008H,000H,02BH,02EH,012H,062H}}

GUID_IID_IActiveDesktopP                        EQU     {052502EE0H,0EC80H,011D0H,{089H,0ABH,000H,0C0H,04FH,0C2H,097H,02DH}}
GUID_IID_IADesktopP2                            EQU     {0B22754E2H,04574H,011D1H,{098H,088H,000H,060H,097H,0DEH,0ACH,0F9H}}

GUID_IID_IProfferService                        EQU     {0CB728B20H,0F786H,011CEH,{092H,0ADH,000H,0AAH,000H,0A7H,04CH,0D0H}}

IF NTDDI_VERSION GE NTDDI_WIN7
    GUID_IID_IObjectWithFolderEnumMode          EQU     {06A9D9026H,00E6EH,0464CH,{0B0H,000H,042H,0ECH,0C0H,07DH,0E6H,073H}}
    GUID_IID_IParseAndCreateItem                EQU     {067EFED0EH,0E827H,04408H,{0B4H,093H,078H,0F3H,098H,02BH,068H,05CH}}
    GUID_SID_SSearchBoxInfo                     EQU     {0142DAA61H,0516BH,04713H,{0B4H,09CH,0FBH,098H,05EH,0F8H,029H,098H}}
    GUID_SID_CommandsPropertyBag                EQU     {06E043250H,04416H,0485CH,{0B1H,043H,0E6H,02AH,076H,00DH,09FH,0E5H}}
ENDIF

GUID_IID_IEnumFullIDList                        EQU     {0D0191542H,07954H,04908H,{0BCH,006H,0B2H,036H,00BH,0BEH,045H,0BAH}}
GUID_IID_IEnumIDList                            EQU     {0000214F2H,00000H,00000H,{0C0H,000H,000H,000H,000H,000H,000H,046H}}
GUID_IID_IPersistIDList                         EQU     {01079ACFCH,029BDH,011D3H,{08EH,00DH,000H,0C0H,04FH,068H,037H,0D5H}}

GUID_IID_ISearchContext                         EQU     {009F656A2H,041AFH,0480CH,{088H,0F7H,016H,0CCH,00DH,016H,046H,015H}}
GUID_IID_IURLSearchHook2                        EQU     {05EE44DA4H,06D32H,046E3H,{086H,0BCH,007H,054H,00DH,0EDH,0D0H,0E0H}}
GUID_IID_IDefViewID                             EQU     {0985F64F0H,0D410H,04E02H,{0BEH,022H,0DAH,007H,0F2H,0B5H,0C5H,0E1H}}

GUID_IID_IUserAccountChangeCallback             EQU     {0A561E69AH,0B4B8H,04113H,{091H,0A5H,064H,0C6H,0BCH,0CAH,034H,030H}}
GUID_IID_IEnumShellItems                        EQU     {070629033H,0E363H,04A28H,{0A5H,067H,00DH,0B7H,080H,006H,0E6H,0D7H}}

GUID_IID_ITransferAdviseSink                    EQU     {0D594D0D8H,08DA7H,0457BH,{0B3H,0B4H,0CEH,05DH,0BAH,0ACH,00BH,088H}}
GUID_IID_ITransferSource                        EQU     {000ADB003H,0BDE9H,045C6H,{08EH,029H,0D0H,09FH,093H,053H,0E1H,008H}}
GUID_IID_IEnumResources                         EQU     {02DD81FE3H,0A83CH,04DA9H,{0A3H,030H,047H,024H,09DH,034H,05BH,0A1H}}
GUID_IID_IShellItemResources                    EQU     {0FF5693BEH,02CE0H,04D48H,{0B5H,0C5H,040H,081H,07DH,01AH,0CDH,0B9H}}
GUID_IID_ITransferDestination                   EQU     {048ADDD32H,03CA5H,04124H,{0ABH,0E3H,0B5H,0A7H,025H,031H,0B2H,007H}}
GUID_IID_IStreamAsync                           EQU     {0FE0B6665H,0E0CAH,049B9H,{0A1H,078H,02BH,05CH,0B4H,08DH,092H,0A5H}}
GUID_IID_IStreamUnbufferedInfo                  EQU     {08A68FDDAH,01FDCH,04C20H,{08CH,0EBH,041H,066H,043H,0B5H,0A6H,025H}}
GUID_IID_IFileOperationProgressSink             EQU     {004B0F1A7H,09490H,044BCH,{096H,0E1H,042H,096H,0A3H,012H,052H,0E2H}}
GUID_IID_IShellItemArray                        EQU     {0B63EA76DH,01F85H,0456FH,{0A1H,09CH,048H,015H,09EH,0FAH,085H,08BH}}
GUID_IID_IInitializeWithItem                    EQU     {07F73BE3FH,0FB79H,0493CH,{0A6H,0C7H,07EH,0E1H,04EH,024H,058H,041H}}
GUID_IID_IObjectWithSelection                   EQU     {01C9CD5BBH,098E9H,04491H,{0A6H,00FH,031H,0AAH,0CCH,072H,0B8H,03CH}}
GUID_IID_IObjectWithBackReferences              EQU     {0321A6A6AH,0D61FH,04BF3H,{097H,0AEH,014H,0BEH,029H,086H,0BBH,036H}}
GUID_IID_IPropertyUI                            EQU     {0757A7D9FH,0919AH,04118H,{099H,0D7H,0DBH,0B2H,008H,0C8H,0CCH,066H}}
GUID_IID_ICategoryProvider                      EQU     {09AF64809H,05864H,04C26H,{0A7H,020H,0C1H,0F7H,08CH,008H,06EH,0E3H}}
GUID_IID_ICategorizer                           EQU     {0A3B14589H,09174H,049A8H,{089H,0A3H,006H,0A1H,0AEH,02BH,09BH,0A7H}}

GUID_PSGUID_SHELLDETAILS                        EQU     {028636AA6H,0953DH,011D2H,{0B5H,0D6H,00H,0C0H,04FH,0D9H,018H,0D0H}}
GUID_PSGUID_DISPLACED                           EQU     {09B174B33H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_PSGUID_MISC                                EQU     {09B174B34H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_PSGUID_VOLUME                              EQU     {09B174B35H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_PSGUID_QUERY_D                             EQU     {049691C90H,07E17H,0101AH,{0A9H,01CH,008H,000H,02BH,02EH,0CDH,0A9H}}
GUID_PSGUID_SUMMARYINFORMATION                  EQU     {0F29F85E0H,04FF9H,01068H,{0ABH,091H,008H,000H,02BH,027H,0B3H,0D9H}}
GUID_PSGUID_DOCUMENTSUMMARYINFORMATION          EQU     {0D5CDD502H,02E9CH,0101BH,{093H,097H,008H,000H,02BH,02CH,0F9H,0AEH}}
GUID_PSGUID_MEDIAFILESUMMARYINFORMATION         EQU     {064440492H,04C8BH,011D1H,{08BH,070H,008H,000H,036H,0B1H,01AH,003H}}
GUID_PSGUID_INTERNETSHORTCUT                    EQU     {0000214A0H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_PSGUID_INTERNETSITE                        EQU     {0000214A1H,0,0,{0C0H,0,0,0,0,0,0,046H}}

GUID_FMTID_ShellDetails                         EQU     {028636AA6H,0953DH,011D2H,{0B5H,0D6H,00H,0C0H,04FH,0D9H,018H,0D0H}}
GUID_FMTID_Storage                              EQU     {0B725F130H,047EFH,0101AH,{0A5H,0F1H,002H,060H,08CH,09EH,0EBH,0ACH}}
GUID_FMTID_Displaced                            EQU     {09B174B33H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_FMTID_Misc                                 EQU     {09B174B34H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_FMTID_Volume                               EQU     {09B174B35H,040FFH,011D2H,{0A2H,07EH,00H,0C0H,04FH,0C3H,08H,071H}}
GUID_FMTID_Query                                EQU     {049691C90H,07E17H,0101AH,{0A9H,01CH,008H,000H,02BH,02EH,0CDH,0A9H}}
GUID_FMTID_Intshcut                             EQU     {0000214A0H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_FMTID_InternetSite                         EQU     {0000214A1H,0,0,{0C0H,0,0,0,0,0,0,046H}}

GUID_CATID_BrowsableShellExt                    EQU     {000021490H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CATID_BrowseInPlace                        EQU     {000021491H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CATID_DeskBand                             EQU     {000021492H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CATID_InfoBand                             EQU     {000021493H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CATID_CommBand                             EQU     {000021494H,0,0,{0C0H,0,0,0,0,0,0,046H}}

GUID_CGID_Explorer                              EQU     {0000214D0H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CGID_ShellDocView                          EQU     {0000214D1H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CGID_ShellServiceObject                    EQU     {0000214D2H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CGID_ExplorerBarDoc                        EQU     {0000214D3H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_CGID_ShortCut                              EQU     {093A68750H,0951AH,011D1H,{094H,06FH,00H,00H,00H,00H,00H,00H}}
GUID_CGID_DeskBand                              EQU     {0EB0FE172H,01A3AH,011D0H,{089H,0B3H,000H,0A0H,0C9H,00AH,090H,0ACH}}

GUID_SID_ShellFolderViewCB                      EQU     {02047E320H,0F2A9H,011CEH,{0AEH,065H,008H,000H,02BH,02EH,012H,062H}}
GUID_SID_SUrlHistory                            EQU     {03C374A40H,0BAE4H,011CFH,{0BFH,07DH,000H,0AAH,000H,069H,046H,0EEH}}
GUID_SID_SInternetExplorer                      EQU     {00002DF05H,00000H,00000H,{0C0H,000H,000H,000H,000H,000H,000H,046H}}
GUID_SID_SWebBrowserApp                         EQU     {00002DF05H,00000H,00000H,{0C0H,000H,000H,000H,000H,000H,000H,046H}}
GUID_SID_LinkSite                               EQU     {0000214F9H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_SID_STopLevelBrowser                       EQU     {04C96BE40H,0915CH,011CFH,{099H,0D3H,000H,0AAH,000H,04AH,0E8H,037H}}
GUID_SID_SShellBrowser                          EQU     {0000214E2H,0,0,{0C0H,0,0,0,0,0,0,046H}}
GUID_SID_SShellDesktop                          EQU     {000021400H,0,0,{0C0H,0,0,0,0,0,0,046H}}

;======================================== Structures ======================================;
;========================================== exdisp ========================================;
GUID_IID_IWebBrowser                            EQU     {0EAB22AC1H, 030C1H, 011CFH, {0A7H, 0EBH, 000H, 000H, 0C0H, 05BH, 0AEH, 00BH}}
IWebBrowser STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    GoBack                      XPTR ?
    GoForward                   XPTR ?
    GoHome                      XPTR ?
    GoSearch                    XPTR ?
    Navigate                    XPTR ?
    Refresh                     XPTR ?
    Refresh2                    XPTR ?
    Stop                        XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Container               XPTR ?
    get_Document                XPTR ?
    get_TopLevelContainer       XPTR ?
    get_Type                    XPTR ?
    get_Left                    XPTR ?
    put_Left                    XPTR ?
    get_Top                     XPTR ?
    put_Top                     XPTR ?
    get_Width                   XPTR ?
    put_Width                   XPTR ?
    get_Height                  XPTR ?
    put_Height                  XPTR ?
    get_LocationName            XPTR ?
    get_LocationURL             XPTR ?
    get_Busy                    XPTR ?
IWebBrowser ENDS

GUID_IID_DWebBrowserEvents                      EQU     {0EAB22AC2H, 030C1H, 011CFH, {0A7H, 0EBH, 000H, 000H, 0C0H, 05BH, 0AEH, 00BH}}
DWebBrowserEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface   XPTR ?
            AddRef           XPTR ?
            Release          XPTR ?
        ENDS
        IUnknown             Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount XPTR ?
            GetTypeInfo      XPTR ?
            GetIDsOfNames    XPTR ?
            _Invoke          XPTR ?
        ENDS
        IDispatch            Dispatch <>
    ENDS
DWebBrowserEvents ENDS

GUID_IID_IWebBrowserApp                         EQU     {00002DF05H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}
IWebBrowserApp STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    GoBack                      XPTR ?
    GoForward                   XPTR ?
    GoHome                      XPTR ?
    GoSearch                    XPTR ?
    Navigate                    XPTR ?
    Refresh                     XPTR ?
    Refresh2                    XPTR ?
    Stop                        XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Container               XPTR ?
    get_Document                XPTR ?
    get_TopLevelContainer       XPTR ?
    get_Type                    XPTR ?
    get_Left                    XPTR ?
    put_Left                    XPTR ?
    get_Top                     XPTR ?
    put_Top                     XPTR ?
    get_Width                   XPTR ?
    put_Width                   XPTR ?
    get_Height                  XPTR ?
    put_Height                  XPTR ?
    get_LocationName            XPTR ?
    get_LocationURL             XPTR ?
    get_Busy                    XPTR ?
    Quit                        XPTR ?
    ClientToWindow              XPTR ?
    PutProperty                 XPTR ?
    GetProperty                 XPTR ?
    get_Name                    XPTR ?
    get_HWND                    XPTR ?
    get_FullName                XPTR ?
    get_Path                    XPTR ?
    get_Visible                 XPTR ?
    put_Visible                 XPTR ?
    get_StatusBar               XPTR ?
    put_StatusBar               XPTR ?
    get_StatusText              XPTR ?
    put_StatusText              XPTR ?
    get_ToolBar                 XPTR ?
    put_ToolBar                 XPTR ?
    get_MenuBar                 XPTR ?
    put_MenuBar                 XPTR ?
    get_FullScreen              XPTR ?
    put_FullScreen              XPTR ?
IWebBrowserApp ENDS

GUID_IID_IWebBrowser2                           EQU     {0D30C1661H, 0CDAFH, 011D0H, {08AH, 03EH, 000H, 0C0H, 04FH, 0C9H, 0E2H, 06EH}}
IWebBrowser2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    GoBack                      XPTR ?
    GoForward                   XPTR ?
    GoHome                      XPTR ?
    GoSearch                    XPTR ?
    Navigate                    XPTR ?
    Refresh                     XPTR ?
    Refresh2                    XPTR ?
    Stop                        XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Container               XPTR ?
    get_Document                XPTR ?
    get_TopLevelContainer       XPTR ?
    get_Type                    XPTR ?
    get_Left                    XPTR ?
    put_Left                    XPTR ?
    get_Top                     XPTR ?
    put_Top                     XPTR ?
    get_Width                   XPTR ?
    put_Width                   XPTR ?
    get_Height                  XPTR ?
    put_Height                  XPTR ?
    get_LocationName            XPTR ?
    get_LocationURL             XPTR ?
    get_Busy                    XPTR ?
    Quit                        XPTR ?
    ClientToWindow              XPTR ?
    PutProperty                 XPTR ?
    GetProperty                 XPTR ?
    get_Name                    XPTR ?
    get_HWND                    XPTR ?
    get_FullName                XPTR ?
    get_Path                    XPTR ?
    get_Visible                 XPTR ?
    put_Visible                 XPTR ?
    get_StatusBar               XPTR ?
    put_StatusBar               XPTR ?
    get_StatusText              XPTR ?
    put_StatusText              XPTR ?
    get_ToolBar                 XPTR ?
    put_ToolBar                 XPTR ?
    get_MenuBar                 XPTR ?
    put_MenuBar                 XPTR ?
    get_FullScreen              XPTR ?
    put_FullScreen              XPTR ?
    Navigate2                   XPTR ?
    QueryStatusWB               XPTR ?
    ExecWB                      XPTR ?
    ShowBrowserBar              XPTR ?
    get_ReadyState              XPTR ?
    get_Offline                 XPTR ?
    put_Offline                 XPTR ?
    get_Silent                  XPTR ?
    put_Silent                  XPTR ?
    get_RegisterAsBrowser       XPTR ?
    put_RegisterAsBrowser       XPTR ?
    get_RegisterAsDropTarget    XPTR ?
    put_RegisterAsDropTarget    XPTR ?
    get_TheaterMode             XPTR ?
    put_TheaterMode             XPTR ?
    get_AddressBar              XPTR ?
    put_AddressBar              XPTR ?
    get_Resizable               XPTR ?
    put_Resizable               XPTR ?
IWebBrowser2 ENDS

GUID_CLSID_Search                               EQU     {030D02401H, 06A81H, 011D0H, {082H, 074H, 000H, 0C0H, 04FH, 0D5H, 0AEH, 038H}}
GUID_CLSID_Favorites                            EQU     {0EFA24E61H, 0B078H, 011D0H, {089H, 0E4H, 000H, 0C0H, 04FH, 0C9H, 0E2H, 06EH}}
GUID_CLSID_History                              EQU     {0EFA24E62H, 0B078H, 011D0H, {089H, 0E4H, 000H, 0C0H, 04FH, 0C9H, 0E2H, 06EH}}
GUID_CLSID_Channels                             EQU     {0EFA24E63H, 0B078H, 011D0H, {089H, 0E4H, 000H, 0C0H, 04FH, 0C9H, 0E2H, 06EH}}

GUID_IID_DWebBrowserEvents2                     EQU     {034A715A0H, 06587H, 011D0H, {092H, 04AH, 000H, 020H, 0AFH, 0C7H, 0ACH, 04DH}}
DWebBrowserEvents2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
DWebBrowserEvents2 ENDS

GUID_IID_DShellWindowsEvents                    EQU     {0FE4106E0H, 0399AH, 011D0H, {0A4H, 08CH, 000H, 0A0H, 0C9H, 00AH, 08FH, 039H}}
DShellWindowsEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
DShellWindowsEvents ENDS

GUID_IID_IShellWindows                          EQU     {085CB6900H, 04D95H, 011CFH, {096H, 00CH, 000H, 080H, 0C7H, 0F4H, 0EEH, 085H}}
IShellWindows STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
    Register                    XPTR ?
    RegisterPending             XPTR ?
    Revoke                      XPTR ?
    OnNavigate                  XPTR ?
    OnActivated                 XPTR ?
    FindWindow                  XPTR ?
    OnCreated                   XPTR ?
    ProcessAttachDetach         XPTR ?
IShellWindows ENDS

GUID_IID_IShellUIHelper                         EQU     {0729FE2F8H, 01EA8H, 011D1H, {08FH, 085H, 000H, 0C0H, 04FH, 0C2H, 0FBH, 0E1H}}
IShellUIHelper STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    ResetFirstBootMode          XPTR ?
    ResetSafeMode               XPTR ?
    RefreshOfflineDesktop       XPTR ?
    AddFavorite                 XPTR ?
    AddChannel                  XPTR ?
    AddDesktopComponent         XPTR ?
    IsSubscribed                XPTR ?
    NavigateAndFind             XPTR ?
    ImportExportFavorites       XPTR ?
    AutoCompleteSaveForm        XPTR ?
    AutoScan                    XPTR ?
    AutoCompleteAttach          XPTR ?
    ShowBrowserUI               XPTR ?
IShellUIHelper ENDS

GUID_IID_ShellFavoritesNameSpaceEvents          EQU     {055136806H, 0B2DEH, 011D1H, {0B9H, 0F2H, 000H, 0A0H, 0C9H, 08BH, 0C5H, 047H}}
_ShellFavoritesNameSpaceEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
_ShellFavoritesNameSpaceEvents ENDS

GUID_IID_IShellFavoritesNameSpace               EQU     {055136804H, 0B2DEH, 011D1H, {0B9H, 0F2H, 000H, 0A0H, 0C9H, 08BH, 0C5H, 047H}}
IShellFavoritesNameSpace STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface          XPTR ?
            AddRef                  XPTR ?
            Release                 XPTR ?
        ENDS
        IUnknown                    Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount        XPTR ?
            GetTypeInfo             XPTR ?
            GetIDsOfNames           XPTR ?
            _Invoke                 XPTR ?
        ENDS
        IDispatch                   Dispatch <>
    ENDS
    MoveSelectionUp                 XPTR ?
    MoveSelectionDown               XPTR ?
    ResetSort                       XPTR ?
    NewFolder                       XPTR ?
    Synchronize                     XPTR ?
    Import                          XPTR ?
    _Export                         XPTR ?
    InvokeContextMenuCommand        XPTR ?
    MoveSelectionTo                 XPTR ?
    get_FOfflinePackInstalled       XPTR ?
    CreateSubscriptionForSelection  XPTR ?
    DeleteSubscriptionForSelection  XPTR ?
    SetRoot                         XPTR ?
IShellFavoritesNameSpace ENDS

GUID_IID_IScriptErrorList                       EQU     {0F3470F24H, 015FDH, 011D2H, {0BBH, 02EH, 000H, 080H, 05FH, 0F7H, 0EFH, 0CAH}}
IScriptErrorList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    advanceError                XPTR ?
    retreatError                XPTR ?
    canAdvanceError             XPTR ?
    canRetreatError             XPTR ?
    getErrorLine                XPTR ?
    getErrorChar                XPTR ?
    getErrorCode                XPTR ?
    getErrorMsg                 XPTR ?
    getErrorUrl                 XPTR ?
    getAlwaysShowLockState      XPTR ?
    getDetailsPaneOpen          XPTR ?
    setDetailsPaneOpen          XPTR ?
    getPerErrorDisplay          XPTR ?
    setPerErrorDisplay          XPTR ?
IScriptErrorList ENDS

GUID_IID_ISearch                                EQU     {0BA9239A4H, 03DD5H, 011D2H, {0BFH, 08BH, 000H, 0C0H, 04FH, 0B9H, 036H, 061H}}
ISearch STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Title                   XPTR ?
    get_Id                      XPTR ?
    get_Url                     XPTR ?  
ISearch ENDS

GUID_IID_ISearches                              EQU     {047C922A2H, 03DD5H, 011D2H, {0BFH, 08BH, 000H, 0C0H, 04FH, 0B9H, 036H, 061H}}
ISearches STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    get_Default                 XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
ISearches ENDS

GUID_IID_ISearchAssistantOC                     EQU     {072423E8FH, 08011H, 011D2H, {0BEH, 079H, 000H, 0A0H, 0C9H, 0A8H, 03DH, 0A1H}}
ISearchAssistantOC STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    AddNextMenuItem             XPTR ?
    SetDefaultSearchUrl         XPTR ?
    NavigateToDefaultSearch     XPTR ?
    IsRestricted                XPTR ?
    get_ShellFeaturesEnabled    XPTR ?
    get_SearchAssistantDefault  XPTR ?
    get_Searches                XPTR ?
    get_InWebFolder             XPTR ?
    PutProperty                 XPTR ?
    GetProperty                 XPTR ?
    put_EventHandled            XPTR ?
    ResetNextMenu               XPTR ?
    FindOnWeb                   XPTR ?
    FindFilesOrFolders          XPTR ?
    FindComputer                XPTR ?
    FindPrinter                 XPTR ?
    FindPeople                  XPTR ?
    GetSearchAssistantURL       XPTR ?
    NotifySearchSettingsChanged XPTR ?
    put_ASProvider              XPTR ?
    get_ASProvider              XPTR ?
    put_ASSetting               XPTR ?
    get_ASSetting               XPTR ?
    NETDetectNextNavigate       XPTR ?
    PutFindText                 XPTR ?
    get_Version                 XPTR ?
    EncodeString                XPTR ?
ISearchAssistantOC ENDS

GUID_IID_ISearchAssistantOC2                    EQU     {072423E8FH, 08011H, 011D2H, {0BEH, 079H, 000H, 0A0H, 0C9H, 0A8H, 03DH, 0A2H}}
ISearchAssistantOC2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    AddNextMenuItem             XPTR ?
    SetDefaultSearchUrl         XPTR ?
    NavigateToDefaultSearch     XPTR ?
    IsRestricted                XPTR ?
    get_ShellFeaturesEnabled    XPTR ?
    get_SearchAssistantDefault  XPTR ?
    get_Searches                XPTR ?
    get_InWebFolder             XPTR ?
    PutProperty                 XPTR ?
    GetProperty                 XPTR ?
    put_EventHandled            XPTR ?
    ResetNextMenu               XPTR ?
    FindOnWeb                   XPTR ?
    FindFilesOrFolders          XPTR ?
    FindComputer                XPTR ?
    FindPrinter                 XPTR ?
    FindPeople                  XPTR ?
    GetSearchAssistantURL       XPTR ?
    NotifySearchSettingsChanged XPTR ?
    put_ASProvider              XPTR ?
    get_ASProvider              XPTR ?
    put_ASSetting               XPTR ?
    get_ASSetting               XPTR ?
    NETDetectNextNavigate       XPTR ?
    PutFindText                 XPTR ?
    get_Version                 XPTR ?
    EncodeString                XPTR ?
    get_ShowFindPrinter         XPTR ?
ISearchAssistantOC2 ENDS

GUID_IID_SearchAssistantEvents                  EQU     {01611FDDAH, 0445BH, 011D2H, {085H, 0DEH, 000H, 0C0H, 04FH, 0A3H, 05CH, 089H}}
_SearchAssistantEvents Struct ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
_SearchAssistantEvents ENDS

;========================================== shldisp =======================================;
GUID_IID_IFolderViewOC                          EQU     {09BA05970H,0F6A8H,011CFH,{0A4H,042H,000H,0A0H,0C9H,00AH,08FH,039H}}
IFolderViewOC STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    SetFolderView               XPTR ?
IFolderViewOC ENDS

GUID_IID_DShellFolderViewEvents                 EQU     {062112AA2H,0EBE4H,011cfH,{0A5H,0FBH,000H,020H,0AFH,0E7H,029H,02DH}}
DShellFolderViewEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
DShellFolderViewEvents ENDS

GUID_IID_DFConstraint                           EQU     {04a3df050H,023bdH,011d2H,{093H,09fH,000H,0a0H,0c9H,01eH,0edH,0baH}}
DFConstraint STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Name                    XPTR ?
    get_Value                   XPTR ?
DFConstraint ENDS

GUID_IID_ISearchCommandExt                      EQU     {01D2EFD50H,075CEH,011d1H,{0B7H,05AH,000H,0A0H,0C9H,005H,064H,0FEH}}
ISearchCommandExt STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    ClearResults                XPTR ?
    NavigateToSearchResults     XPTR ?
    get_ProgressText            XPTR ?
    SaveSearch                  XPTR ?
    GetErrorInfo                XPTR ?
    SearchFor                   XPTR ?
    GetScopeInfo                XPTR ?
    RestoreSavedSearch          XPTR ?
    Execute                     XPTR ?
    AddConstraint               XPTR ?
    GetNextConstraint           XPTR ?
ISearchCommandExt ENDS

GUID_IID_FolderItem                             EQU     {0FAC32C80H,0CBE4H,011CEH,{083H,050H,044H,045H,053H,054H,000H,000H}}
FolderItem STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Name                    XPTR ?
    put_Name                    XPTR ?
    get_Path                    XPTR ?
    get_GetLink                 XPTR ?
    get_GetFolder               XPTR ?
    get_IsLink                  XPTR ?
    get_IsFolder                XPTR ?
    get_IsFileSystem            XPTR ?
    get_IsBrowsable             XPTR ?
    get_ModifyDate              XPTR ?
    put_ModifyDate              XPTR ?
    get_Size                    XPTR ?
    get_Type                    XPTR ?
    Verbs                       XPTR ?
    InvokeVerb                  XPTR ?
FolderItem ENDS

GUID_IID_FolderItems                            EQU     {0744129E0H,0CBE5H,011CEH,{083H,050H,044H,045H,053H,054H,000H,000H}}
FolderItems STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
FolderItems ENDS

GUID_IID_FolderItemVerb                         EQU     {008EC3E00H,050B0H,011CFH,{096H,00CH,000H,080H,0C7H,0F4H,0EEH,085H}}
FolderItemVerb STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Name                    XPTR ?
    DoIt                        XPTR ?
FolderItemVerb ENDS

GUID_IID_FolderItemVerbs                        EQU     {01F8352C0H,050B0H,011CFH,{096H,00CH,000H,080H,0C7H,0F4H,0EEH,085H}}
FolderItemVerbs STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
FolderItemVerbs ENDS

GUID_IID_Folder                                 EQU     {0BBCBDE60H,0C3FFH,011CEH,{083H,050H,044H,045H,053H,054H,000H,000H}}
Folder STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Title                   XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_ParentFolder            XPTR ?
    Items                       XPTR ?
    ParseName                   XPTR ?
    NewFolder                   XPTR ?
    MoveHere                    XPTR ?
    CopyHere                    XPTR ?
    GetDetailsOf                XPTR ?
Folder ENDS

GUID_IID_Folder2                                EQU     {0f0d2d8efH,03890H,011d2H,{0bfH,08bH,000H,0c0H,04fH,0b9H,036H,061H}}
Folder2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface          XPTR ?
            AddRef                  XPTR ?
            Release                 XPTR ?
        ENDS
        IUnknown                    Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount        XPTR ?
            GetTypeInfo             XPTR ?
            GetIDsOfNames           XPTR ?
            _Invoke                 XPTR ?
        ENDS
        IDispatch                   Dispatch <>
    ENDS
    get_Title                       XPTR ?
    get_Application                 XPTR ?
    get_Parent                      XPTR ?
    get_ParentFolder                XPTR ?
    Items                           XPTR ?
    ParseName                       XPTR ?
    NewFolder                       XPTR ?
    MoveHere                        XPTR ?
    CopyHere                        XPTR ?
    GetDetailsOf                    XPTR ?
    get_Self                        XPTR ?
    get_OfflineStatus               XPTR ?
    Synchronize                     XPTR ?
    get_HaveToShowWebViewBarricade  XPTR ?
    DismissedWebViewBarricade       XPTR ?
Folder2 ENDS

GUID_IID_Folder3                                EQU     {0A7AE5F64H,0C4D7H,04d7fH,{093H,007H,04DH,024H,0EEH,054H,0B8H,041H}}
Folder3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface          XPTR ?
            AddRef                  XPTR ?
            Release                 XPTR ?
        ENDS
        IUnknown                    Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount        XPTR ?
            GetTypeInfo             XPTR ?
            GetIDsOfNames           XPTR ?
            _Invoke                 XPTR ?
        ENDS
        IDispatch                   Dispatch <>
    ENDS
    get_Title                       XPTR ?
    get_Application                 XPTR ?
    get_Parent                      XPTR ?
    get_ParentFolder                XPTR ?
    Items                           XPTR ?
    ParseName                       XPTR ?
    NewFolder                       XPTR ?
    MoveHere                        XPTR ?
    CopyHere                        XPTR ?
    GetDetailsOf                    XPTR ?
    get_Self                        XPTR ?
    get_OfflineStatus               XPTR ?
    Synchronize                     XPTR ?
    get_HaveToShowWebViewBarricade  XPTR ?
    DismissedWebViewBarricade       XPTR ?
    get_ShowWebViewBarricade        XPTR ?
    put_ShowWebViewBarricade        XPTR ?
Folder3 ENDS

GUID_IID_FolderItem2                            EQU     {0edc817aaH,092b8H,011d1H,{0b0H,075H,000H,0c0H,04fH,0c3H,03aH,0a5H}}
FolderItem2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Name                    XPTR ?
    put_Name                    XPTR ?
    get_Path                    XPTR ?
    get_GetLink                 XPTR ?
    get_GetFolder               XPTR ?
    get_IsLink                  XPTR ?
    get_IsFolder                XPTR ?
    get_IsFileSystem            XPTR ?
    get_IsBrowsable             XPTR ?
    get_ModifyDate              XPTR ?
    put_ModifyDate              XPTR ?
    get_Size                    XPTR ?
    get_Type                    XPTR ?
    Verbs                       XPTR ?
    InvokeVerb                  XPTR ?
    InvokeVerbEx                XPTR ?
    ExtendedProperty            XPTR ?
FolderItem2 ENDS

GUID_IID_FolderItems2                           EQU     {0C94F0AD0H,0F363H,011d2H,{0A3H,027H,000H,0C0H,04FH,08EH,0ECH,07FH}}
FolderItems2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
    InvokeVerbEx                XPTR ?
FolderItems2 ENDS

GUID_IID_FolderItems3                           EQU     {0eaa7c309H,0bbecH,049d5H,{082H,01dH,064H,0d9H,066H,0cbH,066H,07fH}}
FolderItems3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Count                   XPTR ?
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    Item                        XPTR ?
    _NewEnum                    XPTR ?
    InvokeVerbEx                XPTR ?
    Filter                      XPTR ?
    get_Verbs                   XPTR ?
FolderItems3 ENDS

GUID_IID_IShellLinkDual                         EQU     {088A05C00H,0F000H,011CEH,{083H,050H,044H,045H,053H,054H,000H,000H}}
IShellLinkDual STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Path                    XPTR ?
    put_Path                    XPTR ?
    get_Description             XPTR ?
    put_Description             XPTR ?
    get_WorkingDirectory        XPTR ?
    put_WorkingDirectory        XPTR ?
    get_Arguments               XPTR ?
    put_Arguments               XPTR ?
    get_Hotkey                  XPTR ?
    put_Hotkey                  XPTR ?
    get_ShowCommand             XPTR ?
    put_ShowCommand             XPTR ?
    Resolve                     XPTR ?
    GetIconLocation             XPTR ?
    SetIconLocation             XPTR ?
    Save                        XPTR ?
IShellLinkDual ENDS

GUID_IID_IShellLinkDual2                        EQU     {0317EE249H,0F12EH,011d2H,{0B1H,0E4H,000H,0C0H,04FH,08EH,0EBH,03EH}}
IShellLinkDual2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Path                    XPTR ?
    put_Path                    XPTR ?
    get_Description             XPTR ?
    put_Description             XPTR ?
    get_WorkingDirectory        XPTR ?
    put_WorkingDirectory        XPTR ?
    get_Arguments               XPTR ?
    put_Arguments               XPTR ?
    get_Hotkey                  XPTR ?
    put_Hotkey                  XPTR ?
    get_ShowCommand             XPTR ?
    put_ShowCommand             XPTR ?
    Resolve                     XPTR ?
    GetIconLocation             XPTR ?
    SetIconLocation             XPTR ?
    Save                        XPTR ?
    get_Target                  XPTR ?
IShellLinkDual2 ENDS

GUID_IID_IShellFolderViewDual                   EQU     {0E7A1AF80H,04D96H,011CFH,{096H,00CH,000H,080H,0C7H,0F4H,0EEH,085H}}
IShellFolderViewDual STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Folder                  XPTR ?
    SelectedItems               XPTR ?
    get_FocusedItem             XPTR ?
    SelectItem                  XPTR ?
    PopupItemMenu               XPTR ?
    get_Script                  XPTR ?
    get_ViewOptions             XPTR ?
IShellFolderViewDual ENDS

GUID_IID_IShellFolderViewDual2                  EQU     {031C147b6H,00ADEH,04A3CH,{0B5H,014H,0DDH,0F9H,032H,0EFH,06DH,017H}}
IShellFolderViewDual2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    get_Folder                  XPTR ?
    SelectedItems               XPTR ?
    get_FocusedItem             XPTR ?
    SelectItem                  XPTR ?
    PopupItemMenu               XPTR ?
    get_Script                  XPTR ?
    get_ViewOptions             XPTR ?
    get_CurrentViewMode         XPTR ?
    put_CurrentViewMode         XPTR ?
    SelectItemRelative          XPTR ?
IShellFolderViewDual2 ENDS

GUID_IID_IMigrationWizardAuto                   EQU     {0CE20DAB9H,0B353H,0469bH,{08BH,04DH,06DH,0BBH,03AH,07BH,0A0H,016H}}
IMigrationWizardAuto STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    CreateToolDisk              XPTR ?
    ApplySettings               XPTR ?
    Cancel                      XPTR ?
IMigrationWizardAuto ENDS

GUID_IID_DMigrationWizardAutoEvents             EQU     {0D2AC137DH,0A6D8H,043b6H,{098H,079H,0EAH,034H,0B6H,07EH,018H,080H}}
DMigrationWizardAutoEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
DMigrationWizardAutoEvents ENDS

GUID_IID_IShellDispatch                         EQU     {0D8F015C0H,0C278H,011CEH,{0A4H,09EH,044H,045H,053H,054H,000H,000H}}
IShellDispatch STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    NameSpace                   XPTR ?
    BrowseForFolder             XPTR ?
    Windows                     XPTR ?
    Open                        XPTR ?
    Explore                     XPTR ?
    MinimizeAll                 XPTR ?
    UndoMinimizeALL             XPTR ?
    FileRun                     XPTR ?
    CascadeWindows              XPTR ?
    TileVertically              XPTR ?
    TileHorizontally            XPTR ?
    ShutdownWindows             XPTR ?
    Suspend                     XPTR ?
    EjectPC                     XPTR ?
    SetTime                     XPTR ?
    TrayProperties              XPTR ?
    Help                        XPTR ?
    FindFiles                   XPTR ?
    FindComputer                XPTR ?
    RefreshMenu                 XPTR ?
    ControlPanelItem            XPTR ?
IShellDispatch ENDS

GUID_IID_IShellDispatch2                        EQU     {0A4C6892CH,03BA9H,011d2H,{09DH,0EAH,000H,0C0H,04FH,0B1H,061H,062H}}
IShellDispatch2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    NameSpace                   XPTR ?
    BrowseForFolder             XPTR ?
    Windows                     XPTR ?
    Open                        XPTR ?
    Explore                     XPTR ?
    MinimizeAll                 XPTR ?
    UndoMinimizeALL             XPTR ?
    FileRun                     XPTR ?
    CascadeWindows              XPTR ?
    TileVertically              XPTR ?
    TileHorizontally            XPTR ?
    ShutdownWindows             XPTR ?
    Suspend                     XPTR ?
    EjectPC                     XPTR ?
    SetTime                     XPTR ?
    TrayProperties              XPTR ?
    Help                        XPTR ?
    FindFiles                   XPTR ?
    FindComputer                XPTR ?
    RefreshMenu                 XPTR ?
    ControlPanelItem            XPTR ?
    IsRestricted                XPTR ?
    ShellExecute                XPTR ?
    FindPrinter                 XPTR ?
    GetSystemInformation        XPTR ?
    ServiceStart                XPTR ?
    ServiceStop                 XPTR ?
    IsServiceRunning            XPTR ?
    CanStartStopService         XPTR ?
    ShowBrowserBar              XPTR ?
IShellDispatch2 ENDS

GUID_IID_IShellDispatch3                        EQU     {0177160caH,0bb5aH,0411cH,{084H,01dH,0bdH,038H,0faH,0cdH,0eaH,0a0H}}
IShellDispatch3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    NameSpace                   XPTR ?
    BrowseForFolder             XPTR ?
    Windows                     XPTR ?
    Open                        XPTR ?
    Explore                     XPTR ?
    MinimizeAll                 XPTR ?
    UndoMinimizeALL             XPTR ?
    FileRun                     XPTR ?
    CascadeWindows              XPTR ?
    TileVertically              XPTR ?
    TileHorizontally            XPTR ?
    ShutdownWindows             XPTR ?
    Suspend                     XPTR ?
    EjectPC                     XPTR ?
    SetTime                     XPTR ?
    TrayProperties              XPTR ?
    Help                        XPTR ?
    FindFiles                   XPTR ?
    FindComputer                XPTR ?
    RefreshMenu                 XPTR ?
    ControlPanelItem            XPTR ?
    IsRestricted                XPTR ?
    ShellExecute                XPTR ?
    FindPrinter                 XPTR ?
    GetSystemInformation        XPTR ?
    ServiceStart                XPTR ?
    ServiceStop                 XPTR ?
    IsServiceRunning            XPTR ?
    CanStartStopService         XPTR ?
    ShowBrowserBar              XPTR ?
    AddToRecent                 XPTR ?
IShellDispatch3 ENDS

GUID_IID_IShellDispatch4                        EQU     {0efd84b2dH,04bcfH,04298H,{0beH,025H,0ebH,054H,02aH,059H,0fbH,0daH}}
IShellDispatch4 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    get_Application             XPTR ?
    get_Parent                  XPTR ?
    NameSpace                   XPTR ?
    BrowseForFolder             XPTR ?
    Windows                     XPTR ?
    Open                        XPTR ?
    Explore                     XPTR ?
    MinimizeAll                 XPTR ?
    UndoMinimizeALL             XPTR ?
    FileRun                     XPTR ?
    CascadeWindows              XPTR ?
    TileVertically              XPTR ?
    TileHorizontally            XPTR ?
    ShutdownWindows             XPTR ?
    Suspend                     XPTR ?
    EjectPC                     XPTR ?
    SetTime                     XPTR ?
    TrayProperties              XPTR ?
    Help                        XPTR ?
    FindFiles                   XPTR ?
    FindComputer                XPTR ?
    RefreshMenu                 XPTR ?
    ControlPanelItem            XPTR ?
    IsRestricted                XPTR ?
    ShellExecute                XPTR ?
    FindPrinter                 XPTR ?
    GetSystemInformation        XPTR ?
    ServiceStart                XPTR ?
    ServiceStop                 XPTR ?
    IsServiceRunning            XPTR ?
    CanStartStopService         XPTR ?
    ShowBrowserBar              XPTR ?
    AddToRecent                 XPTR ?
    WindowsSecurity             XPTR ?
    ToggleDesktop               XPTR ?
    ExplorerPolicy              XPTR ?
    GetSetting                  XPTR ?
IShellDispatch4 ENDS

GUID_IID_DSearchCommandEvents                   EQU     {060890160H,069f0H,011d1H,{0b7H,058H,000H,0a0H,0c9H,005H,064H,0feH}}
DSearchCommandEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
DSearchCommandEvents ENDS

GUID_IID_IFileSearchBand                        EQU     {02D91EEA1H,09932H,011d2H,{0BEH,086H,000H,0A0H,0C9H,0A8H,03DH,0A1H}}
IFileSearchBand STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    SetFocus                    XPTR ?
    SetSearchParameters         XPTR ?
    get_SearchID                XPTR ?
    get_Scope                   XPTR ?
    get_QueryFile               XPTR ?
IFileSearchBand ENDS

GUID_IID_IWebWizardHost                         EQU     {018bcc359H,04990H,04bfbH,{0b9H,051H,03cH,083H,070H,02bH,0e5H,0f9H}}
IWebWizardHost STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    FinalBack                   XPTR ?
    FinalNext                   XPTR ?
    Cancel                      XPTR ?
    put_Caption                 XPTR ?
    get_Caption                 XPTR ?
    put_Property                XPTR ?
    get_Property                XPTR ?
    SetWizardButtons            XPTR ?
    SetHeaderText               XPTR ?
IWebWizardHost ENDS

GUID_IID_INewWDEvents                           EQU     {00751c551H,07568H,041c9H,{08eH,05bH,0e2H,02eH,038H,091H,092H,036H}}
INewWDEvents STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    FinalBack                   XPTR ?
    FinalNext                   XPTR ?
    Cancel                      XPTR ?
    put_Caption                 XPTR ?
    get_Caption                 XPTR ?
    put_Property                XPTR ?
    get_Property                XPTR ?
    SetWizardButtons            XPTR ?
    SetHeaderText               XPTR ?
    PassportAuthenticate        XPTR ?
INewWDEvents ENDS

GUID_IID_IPassportClientServices                EQU     {0b30f7305H,05967H,045d1H,{0b7H,0bcH,0d6H,0ebH,071H,063H,0d7H,070H}}
IPassportClientServices STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UNION
        STRUCT
            GetTypeInfoCount    XPTR ?
            GetTypeInfo         XPTR ?
            GetIDsOfNames       XPTR ?
            _Invoke             XPTR ?
        ENDS
        IDispatch               Dispatch <>
    ENDS
    MemberExists                XPTR ?
IPassportClientServices ENDS

GUID_IID_IAutoComplete                          EQU     {000bb2762H,06a77H,011d0H,{0a5H,035H,000H,0c0H,04fH,0d7H,0d0H,062H}}
IAutoComplete STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Init                        XPTR ?
    Enable                      XPTR ?
IAutoComplete ENDS

GUID_IID_IAutoComplete2                         EQU     {0EAC04BC0H,03791H,011d2H,{0BBH,095H,000H,060H,097H,07BH,046H,04CH}}
IAutoComplete2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Init                    XPTR ?
    Enable                  XPTR ?
    SetOptions              XPTR ?
    GetOptions              XPTR ?
IAutoComplete2 ENDS

GUID_IID_IEnumACString                          EQU     {08E74C210H,0CF9DH,04eafH,{0A4H,003H,073H,056H,042H,08FH,00AH,05AH}}
IEnumACString STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Next                    XPTR ?
    Skip                    XPTR ?
    Reset                   XPTR ?
    Clone                   XPTR ?
    NextItem                XPTR ?
    SetEnumOptions          XPTR ?
    GetEnumOptions          XPTR ?
IEnumACString ENDS

GUID_IID_IAsyncOperation                        EQU     {03D8B0590H,0F691H,011d2H,{08EH,0A9H,000H,060H,097H,0DFH,05BH,0D4H}}
IAsyncOperation STRUCT
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetAsyncMode            XPTR ?
    GetAsyncMode            XPTR ?
    StartOperation          XPTR ?
    InOperation             XPTR ?
    EndOperation            XPTR ?
IAsyncOperation ENDS

IFDEF APP_UNICODE
    GUID_IID_IFileViewer EQU <GUID_IID_IFileViewerW>
    GUID_IID_IShellLink EQU <GUID_IID_IShellLinkW>
    GUID_IID_IExtractIcon EQU <GUID_IID_IExtractIconW>
    GUID_IID_IShellCopyHook EQU <GUID_IID_IShellCopyHookW>
    GUID_IID_IShellExecuteHook EQU <GUID_IID_IShellExecuteHookW>
    GUID_IID_INewShortcutHook EQU <GUID_IID_INewShortcutHookW>
ELSE
    GUID_IID_IFileViewer EQU <GUID_IID_IFileViewerA>
    GUID_IID_IShellLink EQU <GUID_IID_IShellLinkA>
    GUID_IID_IExtractIcon EQU <GUID_IID_IExtractIconA>
    GUID_IID_IShellCopyHook EQU <GUID_IID_IShellCopyHookA>
    GUID_IID_IShellExecuteHook EQU <GUID_IID_IShellExecuteHookA>
    GUID_IID_INewShortcutHook EQU <GUID_IID_INewShortcutHookA>
ENDIF

ENDIF ;SHLGUID_INC
