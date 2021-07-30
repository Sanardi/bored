; ====================================================;
;                                                     ;
;    comdlg32.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined COMDLG32_INC
define COMDLG32_INC 1

import comdlg32,\
ChooseColorA,'ChooseColorA',\
ChooseColorW,'ChooseColorW',\
ChooseFontA,'ChooseFontA',\
ChooseFontW,'ChooseFontW',\
CommDlgExtendedError,'CommDlgExtendedError',\
DllCanUnloadNow, 'DllCanUnloadNow',\
DllGetClassObject, 'DllGetClassObject',\
FindTextA,'FindTextA',\
FindTextW,'FindTextW',\
GetFileTitleA,'GetFileTitleA',\
GetFileTitleW,'GetFileTitleW',\
GetOpenFileNameA,'GetOpenFileNameA',\
GetOpenFileNameW,'GetOpenFileNameW',\
GetSaveFileNameA,'GetSaveFileNameA',\
GetSaveFileNameW,'GetSaveFileNameW',\
LoadAlterBitmap,'LoadAlterBitmap',\
PageSetupDlgA,'PageSetupDlgA',\
PageSetupDlgW,'PageSetupDlgW',\
PrintDlgA,'PrintDlgA',\
PrintDlgW,'PrintDlgW',\
PrintDlgExA,'PrintDlgExA',\
PrintDlgExW,'PrintDlgExW',\
ReplaceTextA,'ReplaceTextA',\
ReplaceTextW,'ReplaceTextW',\
Ssync_ANSI_UNICODE_Struct_For_WOW, 'Ssync_ANSI_UNICODE_Struct_For_WOW',\
WantArrows,'WantArrows',\
dwLBSubclass,'dwLBSubclass',\
dwOKSubclass,'dwOKSubclass'

api ChooseColor,\
	ChooseFont,\
	FindText,\
	GetFileTitle,\
	GetOpenFileName,\
	GetSaveFileName,\
	PageSetupDlg,\
	PrintDlg,\
	ReplaceText

end if ;COMDLG32_INC
