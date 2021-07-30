; ====================================================;
;                                                     ;
;     version.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if  ~defined VERSION_INC
define VERSION_INC 1

import version,\
GetFileVersionInfoA, 'GetFileVersionInfoA',\
GetFileVersionInfoW, 'GetFileVersionInfoW',\
GetFileVersionInfoSizeA, 'GetFileVersionInfoSizeA',\
GetFileVersionInfoSizeW, 'GetFileVersionInfoSizeW',\
VerFindFileA, 'VerFindFileA',\
VerFindFileW, 'VerFindFileW',\
VerInstallFileA, 'VerInstallFileA',\
VerInstallFileW, 'VerInstallFileW',\
VerLanguageNameA, 'VerLanguageNameA',\
VerLanguageNameW, 'VerLanguageNameW',\
VerQueryValueA, 'VerQueryValueA',\
VerQueryValueW, 'VerQueryValueW'

api GetFileVersionInfo,\
    GetFileVersionInfoSize,\
    VerFindFile,\
    VerInstallFile,\
    VerLanguageName,\
    VerQueryValue

end if ;VERSION_INC
