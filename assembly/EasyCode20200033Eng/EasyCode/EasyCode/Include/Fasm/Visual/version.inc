; ====================================================;
;                                                     ;
;     version.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if  ~defined VERSION_INC
define VERSION_INC 1

if defined APP_WIN64
    extrn '__imp_GetFileVersionInfoA' as GetFileVersionInfoA:qword
    extrn '__imp_GetFileVersionInfoSizeA' as GetFileVersionInfoSizeA:qword
    extrn '__imp_GetFileVersionInfoSizeW' as GetFileVersionInfoSizeW:qword
    extrn '__imp_GetFileVersionInfoW' as GetFileVersionInfoW:qword
    extrn '__imp_VerFindFileA' as VerFindFileA:qword
    extrn '__imp_VerFindFileW' as VerFindFileW:qword
    extrn '__imp_VerInstallFileA' as VerInstallFileA:qword
    extrn '__imp_VerInstallFileW' as VerInstallFileW:qword
    if ~defined VerLanguageNameA
        extrn '__imp_VerLanguageNameA' as VerLanguageNameA:qword
        extrn '__imp_VerLanguageNameW' as VerLanguageNameW:qword
    end if
    extrn '__imp_VerQueryValueA' as VerQueryValueA:qword
    extrn '__imp_VerQueryValueW' as VerQueryValueW:qword
else
    extrn '__imp__GetFileVersionInfoA@16' as GetFileVersionInfoA:dword
    extrn '__imp__GetFileVersionInfoSizeA@8' as GetFileVersionInfoSizeA:dword
    extrn '__imp__GetFileVersionInfoSizeW@8' as GetFileVersionInfoSizeW:dword
    extrn '__imp__GetFileVersionInfoW@16' as GetFileVersionInfoW:dword
    extrn '__imp__VerFindFileA@32' as VerFindFileA:dword
    extrn '__imp__VerFindFileW@32' as VerFindFileW:dword
    extrn '__imp__VerInstallFileA@32' as VerInstallFileA:dword
    extrn '__imp__VerInstallFileW@32' as VerInstallFileW:dword
    if ~defined VerLanguageNameA
        extrn '__imp__VerLanguageNameA@12' as VerLanguageNameA:dword
        extrn '__imp__VerLanguageNameW@12' as VerLanguageNameW:dword
    end if
    extrn '__imp__VerQueryValueA@16' as VerQueryValueA:dword
    extrn '__imp__VerQueryValueW@16' as VerQueryValueW:dword
end if

api GetFileVersionInfo,\
    GetFileVersionInfoSize,\
    VerFindFile,\
    VerInstallFile,\
    VerLanguageName,\
    VerQueryValue

end if ;VERSION_INC
