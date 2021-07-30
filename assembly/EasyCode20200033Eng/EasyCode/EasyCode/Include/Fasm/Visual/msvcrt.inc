; ====================================================;
;                                                     ;
;      msvcrt.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined MSVCRT_INC
define MSVCRT_INC 1

_CVTBUFSIZE     equ   (309 + 40)

if defined APP_WIN64

    extrn '__imp_??_7__non_rtti_object@@6B@' as ??_7__non_rtti_object@@6B@:qword
    extrn '__imp_??_7bad_cast@@6B@' as ??_7bad_cast@@6B@:qword
    extrn '__imp_??_7bad_typeid@@6B@' as ??_7bad_typeid@@6B@:qword
    extrn '__imp_??_7exception@@6B@' as ??_7exception@@6B@:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??_E__non_rtti_object@@UAEPAXI@Z' as ??_E__non_rtti_object@@UAEPAXI@Z:qword
       extrn '__imp_??_Ebad_cast@@UAEPAXI@Z' as ??_Ebad_cast@@UAEPAXI@Z:qword
       extrn '__imp_??_Ebad_typeid@@UAEPAXI@Z' as ??_Ebad_typeid@@UAEPAXI@Z:qword
       extrn '__imp_??_Eexception@@UAEPAXI@Z' as ??_Eexception@@UAEPAXI@Z:qword
       extrn '__imp_??_Fbad_cast@@QAEXXZ' as ??_Fbad_cast@@QAEXXZ:qword
    end if
    extrn '__imp_??_Fbad_cast@@QEAAXXZ' as ??_Fbad_cast@@QEAAXXZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??_Fbad_typeid@@QAEXXZ' as ??_Fbad_typeid@@QAEXXZ:qword
    end if
    extrn '__imp_??_Fbad_typeid@@QEAAXXZ' as ??_Fbad_typeid@@QEAAXXZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??_G__non_rtti_object@@UAEPAXI@Z' as ??_G__non_rtti_object@@UAEPAXI@Z:qword
       extrn '__imp_??_Gbad_cast@@UAEPAXI@Z' as ??_Gbad_cast@@UAEPAXI@Z:qword
       extrn '__imp_??_Gbad_typeid@@UAEPAXI@Z' as ??_Gbad_typeid@@UAEPAXI@Z:qword
       extrn '__imp_??_Gexception@@UAEPAXI@Z' as ??_Gexception@@UAEPAXI@Z:qword
       extrn '__imp_??_U@YAPAXI@Z' as ??_U@YAPAXI@Z:qword
       extrn '__imp_??_U@YAPAXIHPBDH@Z' as??_U@YAPAXIHPBDH@Z :qword
    end if
    extrn '__imp_??_U@YAPEAX_K@Z' as ??_U@YAPEAX_K@Z:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
       extrn '__imp_??_U@YAPEAX_KHPEBDH@Z' as ??_U@YAPEAX_KHPEBDH@Z:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??_V@YAXPAX@Z' as ??_V@YAXPAX@Z:qword
    end if
    extrn '__imp_??_V@YAXPEAX@Z' as ??_V@YAXPEAX@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??0__non_rtti_object@@QAE@ABV0@@Z' as ??0__non_rtti_object@@QAE@ABV0@@Z:qword
       extrn '__imp_??0__non_rtti_object@@QAE@PBD@Z' as ??0__non_rtti_object@@QAE@PBD@Z:qword
    end if
    extrn '__imp_??0__non_rtti_object@@QEAA@AEBV0@@Z' as ??0__non_rtti_object@@QEAA@AEBV0@@Z:qword
    extrn '__imp_??0__non_rtti_object@@QEAA@PEBD@Z' as ??0__non_rtti_object@@QEAA@PEBD@Z:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
       extrn '__imp_??0bad_cast@@AAE@PBQBD@Z' as ??0bad_cast@@AAE@PBQBD@Z:qword
    end if
    extrn '__imp_??0bad_cast@@AEAA@PEBQEBD@Z' as ??0bad_cast@@AEAA@PEBQEBD@Z:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
       extrn '__imp_??0bad_cast@@QAE@ABQBD@Z' as ??0bad_cast@@QAE@ABQBD@Z:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??0bad_cast@@QAE@ABV0@@Z' as ??0bad_cast@@QAE@ABV0@@Z:qword
       extrn '__imp_??0bad_cast@@QAE@PBD@Z' as ??0bad_cast@@QAE@PBD@Z:qword
    end if
    extrn '__imp_??0bad_cast@@QEAA@AEBQEBD@Z' as ??0bad_cast@@QEAA@AEBQEBD@Z:qword
    extrn '__imp_??0bad_cast@@QEAA@AEBV0@@Z' as ??0bad_cast@@QEAA@AEBV0@@Z:qword
    extrn '__imp_??0bad_cast@@QEAA@PEBD@Z' as ??0bad_cast@@QEAA@PEBD@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??0bad_typeid@@QAE@ABV0@@Z' as ??0bad_typeid@@QAE@ABV0@@Z:qword
       extrn '__imp_??0bad_typeid@@QAE@PBD@Z' as ??0bad_typeid@@QAE@PBD@Z:qword
    end if
    extrn '__imp_??0bad_typeid@@QEAA@AEBV0@@Z' as ??0bad_typeid@@QEAA@AEBV0@@Z:qword
    extrn '__imp_??0bad_typeid@@QEAA@PEBD@Z' as ??0bad_typeid@@QEAA@PEBD@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??0exception@@QAE@ABQBD@Z' as ??0exception@@QAE@ABQBD@Z:qword
       extrn '__imp_??0exception@@QAE@ABQBDH@Z' as ??0exception@@QAE@ABQBDH@Z:qword
       extrn '__imp_??0exception@@QAE@ABV0@@Z' as ??0exception@@QAE@ABV0@@Z:qword
       extrn '__imp_??0exception@@QAE@XZ' as ??0exception@@QAE@XZ:qword
    end if
    extrn '__imp_??0exception@@QEAA@AEBQEBD@Z' as ??0exception@@QEAA@AEBQEBD@Z:qword
    extrn '__imp_??0exception@@QEAA@AEBQEBDH@Z' as ??0exception@@QEAA@AEBQEBDH@Z:qword
    extrn '__imp_??0exception@@QEAA@AEBV0@@Z' as ??0exception@@QEAA@AEBV0@@Z:qword
    extrn '__imp_??0exception@@QEAA@XZ' as ??0exception@@QEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??1__non_rtti_object@@UAE@XZ' as ??1__non_rtti_object@@UAE@XZ:qword
    end if
    extrn '__imp_??1__non_rtti_object@@UEAA@XZ' as ??1__non_rtti_object@@UEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??1bad_cast@@UAE@XZ' as ??1bad_cast@@UAE@XZ:qword
    end if
    extrn '__imp_??1bad_cast@@UEAA@XZ' as ??1bad_cast@@UEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??1bad_typeid@@UAE@XZ' as ??1bad_typeid@@UAE@XZ:qword
    end if
    extrn '__imp_??1bad_typeid@@UEAA@XZ' as ??1bad_typeid@@UEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??1exception@@UAE@XZ' as ??1exception@@UAE@XZ:qword
    end if
    extrn '__imp_??1exception@@UEAA@XZ' as ??1exception@@UEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??1type_info@@UAE@XZ' as ?1type_info@@UAE@XZ:qword
    end if
    extrn '__imp_??1type_info@@UEAA@XZ' as ??1type_info@@UEAA@XZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??2@YAPAXI@Z' as ??2@YAPAXI@Z:qword
       extrn '__imp_??2@YAPAXIHPBDH@Z' as ??2@YAPAXIHPBDH@Z:qword
    end if
    extrn '__imp_??2@YAPEAX_K@Z' as ??2@YAPEAX_K@Z:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
       extrn '__imp_??2@YAPEAX_KHPEBDH@Z' as ??2@YAPEAX_KHPEBDH@Z:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??3@YAXPAX@Z' as ??3@YAXPAX@Z:qword
    end if
    extrn '__imp_??3@YAXPEAX@Z' as ??3@YAXPEAX@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??4__non_rtti_object@@QAEAAV0@ABV0@@Z' as ??4__non_rtti_object@@QAEAAV0@ABV0@@Z:qword
    end if
    extrn '__imp_??4__non_rtti_object@@QEAAAEAV0@AEBV0@@Z' as ??4__non_rtti_object@@QEAAAEAV0@AEBV0@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??4bad_cast@@QAEAAV0@ABV0@@Z' as ??4bad_cast@@QAEAAV0@ABV0@@Z:qword
    end if
    extrn '__imp_??4bad_cast@@QEAAAEAV0@AEBV0@@Z' as ??4bad_cast@@QEAAAEAV0@AEBV0@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??4bad_typeid@@QAEAAV0@ABV0@@Z' as ??4bad_typeid@@QAEAAV0@ABV0@@Z:qword
    end if
    extrn '__imp_??4bad_typeid@@QEAAAEAV0@AEBV0@@Z' as ??4bad_typeid@@QEAAAEAV0@AEBV0@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??4exception@@QAEAAV0@ABV0@@Z' as ??4exception@@QAEAAV0@ABV0@@Z:qword
    end if
    extrn '__imp_??4exception@@QEAAAEAV0@AEBV0@@Z' as ??4exception@@QEAAAEAV0@AEBV0@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??8type_info@@QBEHABV0@@Z' as ??8type_info@@QBEHABV0@@Z:qword
    end if
    extrn '__imp_??8type_info@@QEBAHAEBV0@@Z' as ??8type_info@@QEBAHAEBV0@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_??9type_info@@QBEHABV0@@Z' as ??9type_info@@QBEHABV0@@Z:qword
    end if
    extrn '__imp_??9type_info@@QEBAHAEBV0@@Z' as ??9type_info@@QEBAHAEBV0@@Z:qword
    extrn '__imp_?_query_new_handler@@YAP6AH_K@ZXZ' as ?_query_new_handler@@YAP6AH_K@ZXZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?_query_new_handler@@YAP6AHI@ZXZ' as ?_query_new_handler@@YAP6AHI@ZXZ:qword
    end if
    extrn '__imp_?_query_new_mode@@YAHXZ' as ?_query_new_mode@@YAHXZ:qword
    extrn '__imp_?_set_new_handler@@YAP6AH_K@ZP6AH0@Z@Z' as ?_set_new_handler@@YAP6AH_K@ZP6AH0@Z@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?_set_new_handler@@YAP6AHI@ZP6AHI@Z@Z' as ?_set_new_handler@@YAP6AHI@ZP6AHI@Z@Z:qword
    end if
    extrn '__imp_?_set_new_mode@@YAHH@Z' as ?_set_new_mode@@YAHH@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?_set_se_translator@@YAP6AXIPAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z' as ?_set_se_translator@@YAP6AXIPAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z:qword
    end if
    extrn '__imp_?_set_se_translator@@YAP6AXIPEAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z' as ?_set_se_translator@@YAP6AXIPEAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?before@type_info@@QBEHABV1@@Z' as ?before@type_info@@QBEHABV1@@Z:qword
    end if
    extrn '__imp_?before@type_info@@QEBAHAEBV1@@Z' as ?before@type_info@@QEBAHAEBV1@@Z:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?name@type_info@@QBEPBDXZ' as ?name@type_info@@QBEPBDXZ:qword
    end if
    extrn '__imp_?name@type_info@@QEBAPEBDXZ' as ?name@type_info@@QEBAPEBDXZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?raw_name@type_info@@QBEPBDXZ' as ?raw_name@type_info@@QBEPBDXZ:qword
    end if
    extrn '__imp_?raw_name@type_info@@QEBAPEBDXZ' as ?raw_name@type_info@@QEBAPEBDXZ:qword
    extrn '__imp_?set_new_handler@@YAP6AXXZP6AXXZ@Z' as ?set_new_handler@@YAP6AXXZP6AXXZ@Z:qword
    extrn '__imp_?set_terminate@@YAP6AXXZP6AXXZ@Z' as ?set_terminate@@YAP6AXXZP6AXXZ@Z:qword                                    
    extrn '__imp_?set_unexpected@@YAP6AXXZP6AXXZ@Z' as ?set_unexpected@@YAP6AXXZP6AXXZ@Z:qword                                   
    extrn '__imp_?terminate@@YAXXZ' as ?terminate@@YAXXZ:qword
    extrn '__imp_?unexpected@@YAXXZ' as ?unexpected@@YAXXZ:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
       extrn '__imp_?what@exception@@UBEPBDXZ' as ?what@exception@@UBEPBDXZ:qword
    end if
    extrn '__imp_?what@exception@@UEBAPEBDXZ' as ?what@exception@@UEBAPEBDXZ:qword
    extrn '__imp____lc_codepage_func' as ___lc_codepage_func:qword
    extrn '__imp____lc_collate_cp_func' as ___lc_collate_cp_func:qword
    extrn '__imp____lc_handle_func' as ___lc_handle_func:qword
    extrn '__imp____mb_cur_max_func' as ___mb_cur_max_func:qword
    extrn '__imp____setlc_active_func' as ___setlc_active_func:qword
    extrn '__imp____unguarded_readlc_active_add_func' as ___unguarded_readlc_active_add_func:qword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp___AdjustPointer' as __AdjustPointer:qword
    end if
    extrn '__imp___argc' as __argc:qword
    extrn '__imp___argv' as __argv:qword
    extrn '__imp___badioinfo' as __badioinfo:qword
    extrn '__imp___C_specific_handler' as __C_specific_handler:qword
    extrn '__imp___CppXcptFilter' as __CppXcptFilter:qword
    extrn '__imp___crtCompareStringA' as __crtCompareStringA:qword
    extrn '__imp___crtCompareStringW' as __crtCompareStringW:qword
    extrn '__imp___crtGetLocaleInfoW' as __crtGetLocaleInfoW:qword
    extrn '__imp___crtGetStringTypeW' as __crtGetStringTypeW:qword
    extrn '__imp___crtLCMapStringA' as __crtLCMapStringA:qword
    extrn '__imp___crtLCMapStringW' as __crtLCMapStringW:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp___CxxCallUnwindDelDtor' as __CxxCallUnwindDelDtor:qword
        extrn '__imp___CxxCallUnwindDtor' as __CxxCallUnwindDtor:qword
        extrn '__imp___CxxCallUnwindVecDtor' as __CxxCallUnwindVecDtor:qword
        extrn '__imp___CxxDetectRethrow' as __CxxDetectRethrow:qword
        extrn '__imp___CxxExceptionFilter' as __CxxExceptionFilter:qword
    end if
    extrn '__imp___CxxFrameHandler' as __CxxFrameHandler:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp___CxxFrameHandler2' as __CxxFrameHandler2:qword
        extrn '__imp___CxxFrameHandler3' as __CxxFrameHandler3:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp___CxxLongjmpUnwind' as __CxxLongjmpUnwind:qword
        extrn '__imp___CxxQueryExceptionSize' as __CxxQueryExceptionSize:qword
        extrn '__imp___CxxRegisterExceptionObject' as __CxxRegisterExceptionObject:qword
        extrn '__imp___CxxUnregisterExceptionObject' as __CxxUnregisterExceptionObject:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp___daylight' as __daylight:qword
    end if
    extrn '__imp___DestructExceptionObject' as __DestructExceptionObject:qword
    extrn '__imp___dllonexit' as _dllonexit:qword
    extrn '__imp___doserrno' as __doserrno:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp___dstbias' as _imp___dstbias:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp___ExceptionPtrAssign' as __ExceptionPtrAssign:qword
        extrn '__imp___ExceptionPtrCompare' as __ExceptionPtrCompare:qword
        extrn '__imp___ExceptionPtrCopy' as __ExceptionPtrCopy:qword
        extrn '__imp___ExceptionPtrCopyException' as __ExceptionPtrCopyException:qword
        extrn '__imp___ExceptionPtrCreate' as __ExceptionPtrCreate:qword
        extrn '__imp___ExceptionPtrCurrentException' as __ExceptionPtrCurrentException:qword
        extrn '__imp___ExceptionPtrDestroy' as __ExceptionPtrDestroy:qword
        extrn '__imp___ExceptionPtrRethrow' as __ExceptionPtrRethrow:qword
        extrn '__imp___ExceptionPtrSwap' as __ExceptionPtrSwap:qword
        extrn '__imp___ExceptionPtrToBool' as __ExceptionPtrToBool:qword
    end if
    extrn '__imp___fpecode' as __fpecode:qword
    extrn '__imp___getmainargs' as __getmainargs:qword
    extrn '__imp___initenv' as __initenv:qword
    extrn '__imp___iob_func' as __iob_func:qword
    extrn '__imp___isascii' as __isascii:qword
    extrn '__imp___iscsym' as __iscsym:qword
    extrn '__imp___iscsymf' as __iscsymf:qword
    extrn '__imp___lc_codepage' as _lc_codepage:qword
    extrn '__imp___lc_collate_cp' as __lc_collate_cp:qword
    extrn '__imp___lc_handle' as __lc_handle:qword
    extrn '__imp___lconv_init' as __lconv_init:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp___libm_sse2_acos' as __libm_sse2_acos:qword
        extrn '__imp___libm_sse2_acosf' as __libm_sse2_acosf:qword
        extrn '__imp___libm_sse2_asin' as __libm_sse2_asin:qword
        extrn '__imp___libm_sse2_asinf' as __libm_sse2_asinf:qword
        extrn '__imp___libm_sse2_atan' as __libm_sse2_atan:qword
        extrn '__imp___libm_sse2_atan2' as _libm_sse2_atan2:qword
        extrn '__imp___libm_sse2_atanf' as __libm_sse2_atanf:qword
        extrn '__imp___libm_sse2_cos' as __libm_sse2_cos:qword
        extrn '__imp___libm_sse2_cosf' as __libm_sse2_cosf:qword
        extrn '__imp___libm_sse2_exp' as __libm_sse2_exp:qword
        extrn '__imp___libm_sse2_expf' as __libm_sse2_expf:qword
        extrn '__imp___libm_sse2_log' as __libm_sse2_log:qword
        extrn '__imp___libm_sse2_log10' as __libm_sse2_log10:qword
        extrn '__imp___libm_sse2_log10f' as __libm_sse2_log10f:qword
        extrn '__imp___libm_sse2_logf' as __libm_sse2_logf:qword
        extrn '__imp___libm_sse2_pow' as __libm_sse2_pow:qword
        extrn '__imp___libm_sse2_powf' as __libm_sse2_powf:qword
        extrn '__imp___libm_sse2_sin' as __libm_sse2_sin:qword
        extrn '__imp___libm_sse2_sinf' as __libm_sse2_sinf:qword
        extrn '__imp___libm_sse2_tan' as __libm_sse2_tan:qword
        extrn '__imp___libm_sse2_tanf' as __libm_sse2_tanf:qword
    end if
    extrn '__imp___mb_cur_max' as __mb_cur_max:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp___p___argc' as __p___argc:qword
        extrn '__imp___p___argv' as __p___argv:qword
        extrn '__imp___p___initenv' as __p___initenv:qword
        extrn '__imp___p___mb_cur_max' as __p___mb_cur_max:qword
        extrn '__imp___p___wargv' as __p___wargv:qword
        extrn '__imp___p___winitenv' as __p___winitenv:qword
        extrn '__imp___p__acmdln' as __p__acmdln:qword
        extrn '__imp___p__amblksiz' as __p__amblksiz:qword
        extrn '__imp___p__commode' as __p__commode:qword
        extrn '__imp___p__daylight' as __p__daylight:qword
        extrn '__imp___p__dstbias' as __p__dstbias:qword
        extrn '__imp___p__environ' as __p__environ:qword
        extrn '__imp___p__fileinfo' as __p__fileinfo:qword
        extrn '__imp___p__fmode' as __p__fmode:qword
        extrn '__imp___p__iob' as __p__iob:qword
        extrn '__imp___p__mbcasemap' as __p__mbcasemap:qword
        extrn '__imp___p__mbctype' as __p__mbctype:qword
        extrn '__imp___p__osver' as __p__osver:qword
        extrn '__imp___p__pctype' as __p__pctype:qword
        extrn '__imp___p__pgmptr' as __p__pgmptr:qword
        extrn '__imp___p__pwctype' as __p__pwctype:qword
        extrn '__imp___p__timezone' as __p__timezone:qword
        extrn '__imp___p__tzname' as __p__tzname:qword
        extrn '__imp___p__wcmdln' as __p__wcmdln:qword
        extrn '__imp___p__wenviron' as __p__wenviron:qword
        extrn '__imp___p__winmajor' as __p__winmajor:qword
        extrn '__imp___p__winminor' as __p__winminor:qword
        extrn '__imp___p__winver' as __p__winver:qword
        extrn '__imp___p__wpgmptr' as __p__wpgmptr:qword
    end if
    extrn '__imp___pctype_func' as __pctype_func:qword
    extrn '__imp___pioinfo' as __pioinfo:qword
    extrn '__imp___pwctype_func' as __pwctype_func:qword
    extrn '__imp___pxcptinfoptrs' as __pxcptinfoptrs:qword
    extrn '__imp___RTCastToVoid' as __RTCastToVoid:qword
    extrn '__imp___RTDynamicCast' as __RTDynamicCast:qword
    extrn '__imp___RTtypeid' as __RTtypeid:qword
    extrn '__imp___set_app_type' as __set_app_type:qword
    extrn '__imp___setlc_active' as __setlc_active:qword
    extrn '__imp___setusermatherr' as __setusermatherr:qword
    extrn '__imp___STRINGTOLD' as __STRINGTOLD:qword
    extrn '__imp___strncnt' as __strncnt:qword
    extrn '__imp___threadhandle' as __threadhandle:qword
    extrn '__imp___threadid' as __threadid:qword
    extrn '__imp___toascii' as __toascii:qword
    extrn '__imp___uncaught_exception' as __uncaught_exception:qword
    extrn '__imp___unDName' as __unDName:qword
    extrn '__imp___unDNameEx' as __unDNameEx:qword
    extrn '__imp___unguarded_readlc_active' as __unguarded_readlc_active:qword
    extrn '__imp___wargv' as __wargv:qword
    extrn '__imp___wcserror' as __wcserror:qword
    extrn '__imp___wcserror_s' as __wcserror_s:qword
    extrn '__imp___wcsncnt' as __wcsncnt:qword
    extrn '__imp___wgetmainargs' as __wgetmainargs:qword
    extrn '__imp___winitenv' as __winitenv:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__abnormal_termination' as _abnormal_termination:qword
    end if
    extrn '__imp__abs64' as _abs64:qword
    extrn '__imp__access' as _access:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__access_s' as _access_s:qword
    end if
    extrn '__imp__acmdln' as _acmdln:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__adj_fdiv_m16i' as _adj_fdiv_m16i:qword
        extrn '__imp__adj_fdiv_m32' as _adj_fdiv_m32:qword
        extrn '__imp__adj_fdiv_m32i' as _adj_fdiv_m32i:qword
        extrn '__imp__adj_fdiv_m64' as _adj_fdiv_m64:qword
        extrn '__imp__adj_fdiv_r' as _adj_fdiv_r:qword
        extrn '__imp__adj_fdivr_m16i' as _adj_fdivr_m16i:qword
        extrn '__imp__adj_fdivr_m32' as _adj_fdivr_m32:qword
        extrn '__imp__adj_fdivr_m32i' as _adj_fdivr_m32i:qword
        extrn '__imp__adj_fdivr_m64' as _adj_fdivr_m64:qword
        extrn '__imp__adj_fpatan' as _adj_fpatan:qword
        extrn '__imp__adj_fprem' as _adj_fprem:qword
        extrn '__imp__adj_fprem1' as _adj_fprem1:qword
        extrn '__imp__adj_fptan' as _adj_fptan:qword
        extrn '__imp__adjust_fdiv' as _adjust_fdiv:qword
    end if
    extrn '__imp__aexit_rtn' as _aexit_rtn:qword
    extrn '__imp__aligned_free' as _aligned_free:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__aligned_free_dbg' as _aligned_free_dbg:qword
    end if
    extrn '__imp__aligned_malloc' as _aligned_malloc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__aligned_malloc_dbg' as _aligned_malloc_dbg:qword
    end if
    extrn '__imp__aligned_offset_malloc' as _aligned_offset_malloc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__aligned_offset_malloc_dbg' as _aligned_offset_malloc_dbg:qword
    end if
    extrn '__imp__aligned_offset_realloc' as _aligned_offset_realloc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__aligned_offset_realloc_dbg' as _aligned_offset_realloc_dbg:qword
    end if
    extrn '__imp__aligned_realloc' as _aligned_realloc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__aligned_realloc_dbg' as _aligned_realloc_dbg:qword
    end if
    extrn '__imp__amsg_exit' as _amsg_exit:qword
    extrn '__imp__assert' as _assert:qword
    extrn '__imp__atodbl' as _atodbl:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__atodbl_l' as _atodbl_l:qword
        extrn '__imp__atof_l' as _atof_l:qword
        extrn '__imp__atoflt_l' as _atoflt_l:qword
        extrn '__imp__atoi_l' as _atoi_l:qword
    end if
    extrn '__imp__atoi64' as _atoi64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__atoi64_l' as _atoi64_l:qword
        extrn '__imp__atol_l' as _atol_l:qword
    end if
    extrn '__imp__atoldbl' as _atoldbl:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__atoldbl_l' as _atoldbl_l:qword
    end if
    extrn '__imp__beep' as _beep:qword
    extrn '__imp__beginthread' as _beginthread:qword
    extrn '__imp__beginthreadex' as _beginthreadex:qword
    extrn '__imp__c_exit' as _c_exit:qword
    extrn '__imp__cabs' as _cabs:qword
    extrn '__imp__callnewh' as _callnewh:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__calloc_dbg' as _calloc_dbg:qword
    end if
    extrn '__imp__cexit' as _cexit:qword
    extrn '__imp__cgets' as _cgets:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cgets_s' as _cgets_s:qword
    end if
    extrn '__imp__cgetws' as _cgetws:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cgetws_s' as _cgetws_s:qword
    end if
    extrn '__imp__chdir' as _chdir:qword
    extrn '__imp__chdrive' as _chdrive:qword
    extrn '__imp__chgsign' as _chgsign:qword
    extrn '__imp__chgsignf' as _chgsignf:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__chkesp' as _chkesp:qword
    end if
    extrn '__imp__chmod' as _chmod:qword
    extrn '__imp__chsize' as _chsize:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__chsize_s' as _chsize_s:qword
        extrn '__imp__chvalidator' as _chvalidator:qword
        extrn '__imp__chvalidator_l' as _chvalidator_l:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__CIacos' as _CIacos:qword
        extrn '__imp__CIasin' as _CIasin:qword
        extrn '__imp__CIatan' as _CIatan:qword
        extrn '__imp__CIatan2' as _CIatan2:qword
        extrn '__imp__CIcos' as _CIcos:qword
        extrn '__imp__CIcosh' as _CIcosh:qword
        extrn '__imp__CIexp' as _CIexp:qword
        extrn '__imp__CIfmod' as _CIfmod:qword
        extrn '__imp__CIlog' as _CIlog:qword
        extrn '__imp__CIlog10' as _CIlog10:qword
        extrn '__imp__CIpow' as _CIpow:qword
        extrn '__imp__CIsin' as _CIsin:qword
        extrn '__imp__CIsinh' as _CIsinh:qword
        extrn '__imp__CIsqrt' as _CIsqrt:qword
        extrn '__imp__CItan' as _CItan:qword
        extrn '__imp__CItanh' as _CItanh:qword
    end if
    extrn '__imp__clearfp' as _clearfp:qword
    extrn '__imp__close' as _close:qword
    extrn '__imp__commit' as _commit:qword
    extrn '__imp__commode' as _commode:qword
    extrn '__imp__control87' as _control87:qword
    extrn '__imp__controlfp' as _controlfp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__controlfp_s' as _controlfp_s:qword
    end if
    extrn '__imp__copysign' as _copysign:qword
    extrn '__imp__copysignf' as _copysignf:qword
    extrn '__imp__cprintf' as _cprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cprintf_l' as _cprintf_l:qword
        extrn '__imp__cprintf_p' as _cprintf_p:qword
        extrn '__imp__cprintf_p_l' as _cprintf_p_l:qword
        extrn '__imp__cprintf_s' as _cprintf_s:qword
        extrn '__imp__cprintf_s_l' as _cprintf_s_l:qword
    end if
    extrn '__imp__cputs' as _cputs:qword
    extrn '__imp__cputws' as _cputws:qword
    extrn '__imp__creat' as _creat:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__create_locale' as _create_locale:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__crtAssertBusy' as _crtAssertBusy:qword
        extrn '__imp__crtBreakAlloc' as _crtBreakAlloc:qword
        extrn '__imp__CrtCheckMemory' as _CrtCheckMemory:qword
        extrn '__imp__CrtDbgBreak' as _CrtDbgBreak:qword
        extrn '__imp__crtDbgFlag' as _crtDbgFlag:qword
        extrn '__imp__CrtDbgReport' as _CrtDbgReport:qword
        extrn '__imp__CrtDbgReportV' as _CrtDbgReportV:qword
        extrn '__imp__CrtDbgReportW' as _CrtDbgReportW:qword
        extrn '__imp__CrtDbgReportWV' as _CrtDbgReportWV:qword
        extrn '__imp__CrtDoForAllClientObjects' as _CrtDoForAllClientObjects:qword
        extrn '__imp__CrtDumpMemoryLeaks' as _CrtDumpMemoryLeaks:qword
        extrn '__imp__CrtIsMemoryBlock' as _CrtIsMemoryBlock:qword
        extrn '__imp__CrtIsValidHeapPointer' as _CrtIsValidHeapPointer:qword
        extrn '__imp__CrtIsValidPointer' as _CrtIsValidPointer:qword
        extrn '__imp__CrtMemCheckpoint' as _CrtMemCheckpoint:qword
        extrn '__imp__CrtMemDifference' as _CrtMemDifference:qword
        extrn '__imp__CrtMemDumpAllObjectsSince' as _CrtMemDumpAllObjectsSince:qword
        extrn '__imp__CrtMemDumpStatistics' as _CrtMemDumpStatistics:qword
        extrn '__imp__CrtReportBlockType' as _CrtReportBlockType:qword
        extrn '__imp__CrtSetAllocHook' as _CrtSetAllocHook:qword
        extrn '__imp__CrtSetBreakAlloc' as _CrtSetBreakAlloc:qword
        extrn '__imp__CrtSetDbgBlockType' as _CrtSetDbgBlockType:qword
        extrn '__imp__CrtSetDbgFlag' as _CrtSetDbgFlag:qword
        extrn '__imp__CrtSetDumpClient' as _CrtSetDumpClient:qword
        extrn '__imp__CrtSetReportFile' as _CrtSetReportFile:qword
        extrn '__imp__CrtSetReportHook' as _CrtSetReportHook:qword
        extrn '__imp__CrtSetReportHook2' as _CrtSetReportHook2:qword
        extrn '__imp__CrtSetReportMode' as _CrtSetReportMode:qword
    end if
    extrn '__imp__cscanf' as _cscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cscanf_l' as _cscanf_l:qword
        extrn '__imp__cscanf_s' as _cscanf_s:qword
        extrn '__imp__cscanf_s_l' as _cscanf_s_l:qword
        extrn '__imp__ctime32' as _ctime32:qword
        extrn '__imp__ctime32_s' as _ctime32_s:qword
    end if
    extrn '__imp__ctime64' as _ctime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ctime64_s' as _ctime64_s:qword
    end if
    extrn '__imp__ctype' as _ctype:qword
    extrn '__imp__cwait' as _cwait:qword
    extrn '__imp__cwprintf' as _cwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cwprintf_l' as _cwprintf_l:qword
        extrn '__imp__cwprintf_p' as _cwprintf_p:qword
        extrn '__imp__cwprintf_p_l' as _cwprintf_p_l:qword
        extrn '__imp__cwprintf_s' as _cwprintf_s:qword
        extrn '__imp__cwprintf_s_l' as _cwprintf_s_l:qword
    end if
    extrn '__imp__cwscanf' as _cwscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__cwscanf_l' as _cwscanf_l:qword
        extrn '__imp__cwscanf_s' as _cwscanf_s:qword
        extrn '__imp__cwscanf_s_l' as _cwscanf_s_l:qword
    end if
    extrn '__imp__CxxThrowException' as _CxxThrowException:qword
    extrn '__imp__daylight' as _daylight:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__difftime32' as _difftime32:qword
        extrn '__imp__difftime64' as _difftime64:qword
    end if
    extrn '__imp__dstbias' as _dstbias:qword
    extrn '__imp__dup' as _dup:qword
    extrn '__imp__dup2' as _dup2:qword
    extrn '__imp__ecvt' as _ecvt:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ecvt_s' as _ecvt_s:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__EH_prolog' as _EH_prolog:qword
    end if
    extrn '__imp__endthread' as _endthread:qword
    extrn '__imp__endthreadex' as _endthreadex:qword
    extrn '__imp__environ' as _environ:qword
    extrn '__imp__eof' as _eof:qword
    extrn '__imp__errno' as _errno:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__except_handler2' as _except_handler2:qword
        extrn '__imp__except_handler3' as _except_handler3:qword
        extrn '__imp__except_handler4_common' as _except_handler4_common:qword
    end if
    extrn '__imp__execl' as _execl:qword
    extrn '__imp__execle' as _execle:qword
    extrn '__imp__execlp' as _execlp:qword
    extrn '__imp__execlpe' as _execlpe:qword
    extrn '__imp__execv' as _execv:qword
    extrn '__imp__execve' as _execve:qword
    extrn '__imp__execvp' as _execvp:qword
    extrn '__imp__execvpe' as _execvpe:qword
    extrn '__imp__exit' as _exit:qword
    extrn '__imp__expand' as _expand:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__expand_dbg' as _expand_dbg:qword
    end if
    extrn '__imp__fcloseall' as _fcloseall:qword
    extrn '__imp__fcvt' as _fcvt:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__fcvt_s' as _fcvt_s:qword
    end if
    extrn '__imp__fdopen' as _fdopen:qword
    extrn '__imp__fgetchar' as _fgetchar:qword
    extrn '__imp__fgetwchar' as _fgetwchar:qword
    extrn '__imp__filbuf' as _filbuf:qword
    extrn '__imp__fileinfo' as _fileinfo:qword
    extrn '__imp__filelength' as _filelength:qword
    extrn '__imp__filelengthi64' as _filelengthi64:qword
    extrn '__imp__fileno' as _fileno:qword
    extrn '__imp__findclose' as _findclose:qword
    extrn '__imp__findfirst' as _findfirst:qword
    extrn '__imp__findfirst64' as _findfirst64:qword
    extrn '__imp__findfirsti64' as _findfirsti64:qword
    extrn '__imp__findnext' as _findnext:qword
    extrn '__imp__findnext64' as _findnext64:qword
    extrn '__imp__findnexti64' as _findnexti64:qword
    extrn '__imp__finite' as _finite:qword
    extrn '__imp__finitef' as _finitef:qword
    extrn '__imp__flsbuf' as _flsbuf:qword
    extrn '__imp__flushall' as _flushall:qword
    extrn '__imp__fmode' as _fmode:qword
    extrn '__imp__fpclass' as _fpclass:qword
    extrn '__imp__fpclassf' as _fpclassf:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__fpieee_flt' as _fpieee_flt:qword
    end if
    extrn '__imp__fpreset' as _fpreset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__fprintf_l' as _fprintf_l:qword
        extrn '__imp__fprintf_p' as _fprintf_p:qword
        extrn '__imp__fprintf_p_l' as _fprintf_p_l:qword
        extrn '__imp__fprintf_s_l' as _fprintf_s_l:qword
    end if
    extrn '__imp__fputchar' as _fputchar:qword
    extrn '__imp__fputwchar' as _fputwchar:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__free_dbg' as _free_dbg:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__free_locale' as _free_locale:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__freea' as _freea:qword
        extrn '__imp__freea_s' as _freea_s:qword
        extrn '__imp__fscanf_l' as _fscanf_l:qword
        extrn '__imp__fscanf_s_l' as _fscanf_s_l:qword
        extrn '__imp__fseeki64' as _fseeki64:qword
    end if
    extrn '__imp__fsopen' as _fsopen:qword
    extrn '__imp__fstat' as _fstat:qword
    extrn '__imp__fstat64' as _fstat64:qword
    extrn '__imp__fstati64' as _fstati64:qword
    extrn '__imp__ftime' as _ftime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ftime32' as _ftime32:qword
        extrn '__imp__ftime32_s' as _ftime32_s:qword
    end if
    extrn '__imp__ftime64' as _ftime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ftime64_s' as _ftime64_s:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__ftol' as _ftol:qword
        extrn '__imp__ftol2' as _ftol2:qword
        extrn '__imp__ftol2_sse' as _ftol2_sse:qword
        extrn '__imp__ftol2_sse_excpt' as _ftol2_sse_excpt:qword
    end if
    extrn '__imp__fullpath' as _fullpath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__fullpath_dbg' as _fullpath_dbg:qword
    end if
    extrn '__imp__futime' as _futime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__futime32' as _futime32:qword
    end if
    extrn '__imp__futime64' as _futime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__fwprintf_l' as _fwprintf_l:qword
        extrn '__imp__fwprintf_p' as _fwprintf_p:qword
        extrn '__imp__fwprintf_p_l' as _fwprintf_p_l:qword
        extrn '__imp__fwprintf_s_l' as _fwprintf_s_l:qword
        extrn '__imp__fwscanf_l' as _fwscanf_l:qword
        extrn '__imp__fwscanf_s_l' as _fwscanf_s_l:qword
    end if
    extrn '__imp__gcvt' as _gcvt:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__gcvt_s' as _gcvt_s:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__get_current_locale' as _get_current_locale:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__get_doserrno' as _get_doserrno:qword
        extrn '__imp__get_environ' as _get_environ:qword
        extrn '__imp__get_errno' as _get_errno:qword
        extrn '__imp__get_fileinfo' as _get_fileinfo:qword
        extrn '__imp__get_fmode' as _get_fmode:qword
    end if
    extrn '__imp__get_heap_handle' as _get_heap_handle:qword
    extrn '__imp__get_osfhandle' as _get_osfhandle:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__get_osplatform' as _get_osplatform:qword
        extrn '__imp__get_osver' as _get_osver:qword
        extrn '__imp__get_output_format' as _get_output_format:qword
        extrn '__imp__get_pgmptr' as _get_pgmptr:qword
    end if
    extrn '__imp__get_sbh_threshold' as _get_sbh_threshold:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__get_wenviron' as _get_wenviron:qword
        extrn '__imp__get_winmajor' as _get_winmajor:qword
        extrn '__imp__get_winminor' as _get_winminor:qword
        extrn '__imp__get_winver' as _get_winver:qword
        extrn '__imp__get_wpgmptr' as _get_wpgmptr:qword
    end if
    extrn '__imp__getch' as _getch:qword
    extrn '__imp__getche' as _getche:qword
    extrn '__imp__getcwd' as _getcwd:qword
    extrn '__imp__Getdays' as _Getdays:qword
    extrn '__imp__getdcwd' as _getdcwd:qword
    extrn '__imp__getdiskfree' as _getdiskfree:qword
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__getdllprocaddr' as _getdllprocaddr:qword
    end if
    extrn '__imp__getdrive' as _getdrive:qword
    extrn '__imp__getdrives' as _getdrives:qword
    extrn '__imp__getmaxstdio' as _getmaxstdio:qword
    extrn '__imp__getmbcp' as _getmbcp:qword
    extrn '__imp__Getmonths' as _Getmonths:qword
    extrn '__imp__getpid' as _getpid:qword
    extrn '__imp__getsystime' as _getsystime:qword
    extrn '__imp__Gettnames' as _Gettnames:qword
    extrn '__imp__getw' as _getw:qword
    extrn '__imp__getwch' as _getwch:qword
    extrn '__imp__getwche' as _getwche:qword
    extrn '__imp__getws' as _getws:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__global_unwind2' as _global_unwind2:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__gmtime32' as _gmtime32:qword
        extrn '__imp__gmtime32_s' as _gmtime32_s:qword
    end if
    extrn '__imp__gmtime64' as _gmtime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__gmtime64_s' as _gmtime64_s:qword
    end if
    if (NTDDI_VERSION <= NTDDI_VISTA)
    extrn '__imp__heapadd' as _heapadd:qword
    end if
    extrn '__imp__heapchk' as _heapchk:qword
    extrn '__imp__heapmin' as _heapmin:qword
    extrn '__imp__heapset' as _heapset:qword
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__heapused' as _heapused:qword
    end if
    extrn '__imp__heapwalk' as _heapwalk:qword
    extrn '__imp__HUGE' as _HUGE:qword
    extrn '__imp__hypot' as _hypot:qword
    extrn '__imp__hypotf' as _hypotf:qword
    extrn '__imp__i64toa' as _i64toa:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__i64toa_s' as _i64toa_s:qword
    end if
    extrn '__imp__i64tow' as _i64tow:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__i64tow_s' as _i64tow_s:qword
    end if
    extrn '__imp__initterm' as _initterm:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__initterm_e' as _initterm_e:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__inp' as _inp:qword
        extrn '__imp__inpd' as _inpd:qword
        extrn '__imp__inpw' as _inpw:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__invalid_parameter' as _invalid_parameter:qword
    end if
    extrn '__imp__iob' as _iob:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__isalnum_l' as _isalnum_l:qword
        extrn '__imp__isalpha_l' as _isalpha_l:qword
    end if
    extrn '__imp__isatty' as _isatty:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__iscntrl_l' as _iscntrl_l:qword
    end if
    extrn '__imp__isctype' as _isctype:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__isctype_l' as _isctype_l:qword
        extrn '__imp__isdigit_l' as _isdigit_l:qword
        extrn '__imp__isgraph_l' as _isgraph_l:qword
        extrn '__imp__isleadbyte_l' as _isleadbyte_l:qword
        extrn '__imp__islower_l' as _islower_l:qword
    end if
    extrn '__imp__ismbbalnum' as _ismbbalnum:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbalnum_l' as _ismbbalnum_l:qword
    end if
    extrn '__imp__ismbbalpha' as _ismbbalpha:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbalpha_l' as _ismbbalpha_l:qword
    end if
    extrn '__imp__ismbbgraph' as _ismbbgraph:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbgraph_l' as _ismbbgraph_l:qword
    end if
    extrn '__imp__ismbbkalnum' as _ismbbkalnum:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbkalnum_l' as _ismbbkalnum_l:qword
    end if
    extrn '__imp__ismbbkana' as _ismbbkana:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbkana_l' as _ismbbkana_l:qword
    end if
    extrn '__imp__ismbbkprint' as _ismbbkprint:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbkprint_l' as _ismbbkprint_l:qword
    end if
    extrn '__imp__ismbbkpunct' as _ismbbkpunct:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbkpunct_l' as _ismbbkpunct_l:qword
    end if
    extrn '__imp__ismbblead' as _ismbblead:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbblead_l' as _ismbblead_l:qword
    end if
    extrn '__imp__ismbbprint' as _ismbbprint:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbprint_l' as _ismbbprint_l:qword
    end if
    extrn '__imp__ismbbpunct' as _ismbbpunct:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbpunct_l' as _ismbbpunct_l:qword
    end if
    extrn '__imp__ismbbtrail' as _ismbbtrail:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbbtrail_l' as _ismbbtrail_l:qword
    end if
    extrn '__imp__ismbcalnum' as _ismbcalnum:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcalnum_l' as _ismbcalnum_l:qword
    end if
    extrn '__imp__ismbcalpha' as _ismbcalpha:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcalpha_l' as _ismbcalpha_l:qword
    end if
    extrn '__imp__ismbcdigit' as _ismbcdigit:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcdigit_l' as _ismbcdigit_l:qword
    end if
    extrn '__imp__ismbcgraph' as _ismbcgraph:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcgraph_l' as _ismbcgraph_l:qword
    end if
    extrn '__imp__ismbchira' as _ismbchira:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbchira_l' as _ismbchira_l:qword
    end if
    extrn '__imp__ismbckata' as _ismbckata:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbckata_l' as _ismbckata_l:qword
    end if
    extrn '__imp__ismbcl0' as _ismbcl0:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcl0_l' as _ismbcl0_l:qword
    end if
    extrn '__imp__ismbcl1' as _ismbcl1:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcl1_l' as _ismbcl1_l:qword
    end if
    extrn '__imp__ismbcl2' as _ismbcl2:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcl2_l' as _ismbcl2_l:qword
    end if
    extrn '__imp__ismbclegal' as _ismbclegal:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbclegal_l' as :qword
    end if
    extrn '__imp__ismbclower' as _ismbclower:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbclower_l' as :qword
    end if
    extrn '__imp__ismbcprint' as _ismbcprint:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcprint_l' as _ismbcprint_l:qword
    end if
    extrn '__imp__ismbcpunct' as _ismbcpunct:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcpunct_l' as _ismbcpunct_l:qword
    end if
    extrn '__imp__ismbcspace' as _ismbcspace:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcspace_l' as _ismbcspace_l:qword
    end if
    extrn '__imp__ismbcsymbol' as _ismbcsymbol:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcsymbol_l' as _ismbcsymbol_l:qword
    end if
    extrn '__imp__ismbcupper' as _ismbcupper:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbcupper_l' as _ismbcupper_l:qword
    end if
    extrn '__imp__ismbslead' as _ismbslead:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbslead_l' as _ismbslead_l:qword
    end if
    extrn '__imp__ismbstrail' as _ismbstrail:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ismbstrail_l' as _ismbstrail_l:qword
    end if
    extrn '__imp__isnan' as _isnan:qword
    extrn '__imp__isnanf' as _isnanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__isprint_l' as _isprint_l:qword
        extrn '__imp__isspace_l' as _isspace_l:qword
        extrn '__imp__isupper_l' as _isupper_l:qword
        extrn '__imp__iswalnum_l' as _iswalnum_l:qword
        extrn '__imp__iswalpha_l' as _iswalpha_l:qword
        extrn '__imp__iswcntrl_l' as _iswcntrl_l:qword
        extrn '__imp__iswctype_l' as _iswctype_l:qword
        extrn '__imp__iswdigit_l' as _iswdigit_l:qword
        extrn '__imp__iswgraph_l' as _iswgraph_l:qword
        extrn '__imp__iswlower_l' as _iswlower_l:qword
        extrn '__imp__iswprint_l' as _iswprint_l:qword
        extrn '__imp_swpunct_l' as _iswpunct_l:qword
        extrn '__imp_swspace_l' as _iswspace_l:qword
        extrn '__imp__iswupper_l' as _iswupper_l:qword
        extrn '__imp__iswxdigit_l' as _iswxdigit_l:qword
        extrn '__imp__isxdigit_l' as _isxdigit_l:qword
    end if
    extrn '__imp__itoa' as _itoa:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__itoa_s' as _itoa_s:qword
    end if
    extrn '__imp__itow' as _itow:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__itow_s' as _itow_s:qword
    end if
    extrn '__imp__j0' as _j0:qword
    extrn '__imp__j1' as _j1:qword
    extrn '__imp__jn' as _jn:qword
    extrn '__imp__kbhit' as _kbhit:qword
    extrn '__imp__lfind' as _lfind:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__lfind_s' as _lfind_s:qword
    end if
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__loaddll' as _loaddll:qword
    end if
    extrn '__imp__local_unwind' as _local_unwind:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__local_unwind2' as _local_unwind2:qword
        extrn '__imp__local_unwind4' as _local_unwind4:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__localtime32' as _localtime32:qword
        extrn '__imp__localtime32_s' as _localtime32_s:qword
    end if
    extrn '__imp__localtime64' as _localtime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__localtime64_s' as _localtime64_s:qword
    end if
    extrn '__imp__lock' as _lock:qword
    extrn '__imp__locking' as _locking:qword
    extrn '__imp__logb' as _logb:qword
    extrn '__imp__logbf' as _logbf:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__longjmpex' as _longjmpex:qword
    end if
    extrn '__imp__lrotl' as _lrotl:qword
    extrn '__imp__lrotr' as _lrotr:qword
    extrn '__imp__lsearch' as _lsearch:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__lsearch_s' as _lsearch_s:qword
    end if
    extrn '__imp__lseek' as _lseek:qword
    extrn '__imp__lseeki64' as _lseeki64:qword
    extrn '__imp__ltoa' as _ltoa:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ltoa_s' as _ltoa_s:qword
    end if
    extrn '__imp__ltow' as _ltow:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ltow_s' as _ltow_s:qword
    end if
    extrn '__imp__makepath' as _makepath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__makepath_s' as _makepath_s:qword
        extrn '__imp__malloc_dbg' as _malloc_dbg:qword
    end if
    extrn '__imp__mbbtombc' as _mbbtombc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbbtombc_l' as _mbbtombc_l:qword
    end if
    extrn '__imp__mbbtype' as _mbbtype:qword
    extrn '__imp__mbcasemap' as _mbcasemap:qword                                                    
    extrn '__imp__mbccpy' as _mbccpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbccpy_l' as _mbccpy_l:qword
        extrn '__imp__mbccpy_s' as _mbccpy_s:qword
        extrn '__imp__mbccpy_s_l' as _mbccpy_s_l:qword
    end if
    extrn '__imp__mbcjistojms' as _mbcjistojms:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbcjistojms_l' as _mbcjistojms_l:qword
    end if
    extrn '__imp__mbcjmstojis' as _mbcjmstojis:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbcjmstojis_l' as _mbcjmstojis_l:qword
    end if
    extrn '__imp__mbclen' as _mbclen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbclen_l' as _mbclen_l:qword                                                    
    end if
    extrn '__imp__mbctohira' as _mbctohira:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbctohira_l' as _mbctohira_l:qword
    end if
    extrn '__imp__mbctokata' as _mbctokata:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbctokata_l' as _mbctokata_l:qword
    end if
    extrn '__imp__mbctolower' as _mbctolower:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbctolower_l' as _mbctolower_l:qword
    end if
    extrn '__imp__mbctombb' as _mbctombb:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbctombb_l' as _mbctombb_l:qword
    end if
    extrn '__imp__mbctoupper' as _mbctoupper:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbctoupper_l' as _mbctoupper_l:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mblen_l' as _mblen_l:qword
    end if
    extrn '__imp__mbsbtype' as _mbsbtype:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsbtype_l' as _mbsbtype_l:qword
    end if
    extrn '__imp__mbscat' as _mbscat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbscat_s' as _mbscat_s:qword
        extrn '__imp__mbscat_s_l' as _mbscat_s_l:qword
    end if
    extrn '__imp__mbschr' as _mbschr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbschr_l' as _mbschr_l:qword
    end if
    extrn '__imp__mbscmp' as _mbscmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbscmp_l' as _mbscmp_l:qword
    end if
    extrn '__imp__mbscoll' as _mbscoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbscoll_l' as _mbscoll_l:qword
    end if
    extrn '__imp__mbscpy' as _mbscpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbscpy_s' as _mbscpy_s:qword
        extrn '__imp__mbscpy_s_l' as _mbscpy_s_l:qword
    end if
    extrn '__imp__mbscspn' as _mbscspn:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbscspn_l' as _mbscspn_l:qword
    end if
    extrn '__imp__mbsdec' as _mbsdec:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsdec_l' as _mbsdec_l:qword
    end if
    extrn '__imp__mbsdup' as _mbsdup:qword
    extrn '__imp__mbsicmp' as _mbsicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsicmp_l' as _mbsicmp_l:qword
    end if
    extrn '__imp__mbsicoll' as _mbsicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsicoll_l' as _mbsicoll_l:qword
    end if
    extrn '__imp__mbsinc' as _mbsinc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsinc_l' as _mbsinc_l:qword
    end if
    extrn '__imp__mbslen' as _mbslen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbslen_l' as _mbslen_l:qword
    end if
    extrn '__imp__mbslwr' as _mbslwr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbslwr_l' as _mbslwr_l:qword
        extrn '__imp__mbslwr_s' as _mbslwr_s:qword
        extrn '__imp__mbslwr_s_l' as _mbslwr_s_l:qword
    end if
    extrn '__imp__mbsnbcat' as _mbsnbcat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbcat_l' as _mbsnbcat_l:qword
        extrn '__imp__mbsnbcat_s' as _mbsnbcat_s:qword
        extrn '__imp__mbsnbcat_s_l' as _mbsnbcat_s_l:qword
    end if
    extrn '__imp__mbsnbcmp' as _mbsnbcmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbcmp_l' as _mbsnbcmp_l:qword
    end if
    extrn '__imp__mbsnbcnt' as _mbsnbcnt:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbcnt_l' as _mbsnbcnt_l:qword
    end if
    extrn '__imp__mbsnbcoll' as _mbsnbcoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbcoll_l' as _mbsnbcoll_l:qword
    end if
    extrn '__imp__mbsnbcpy' as _mbsnbcpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbcpy_l' as _mbsnbcpy_l:qword
        extrn '__imp__mbsnbcpy_s' as _mbsnbcpy_s:qword
        extrn '__imp__mbsnbcpy_s_l' as _mbsnbcpy_s_l:qword
    end if
    extrn '__imp__mbsnbicmp' as _mbsnbicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbicmp_l' as _mbsnbicmp_l:qword
    end if
    extrn '__imp__mbsnbicoll' as _mbsnbicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbicoll_l' as _mbsnbicoll_l:qword
    end if
    extrn '__imp__mbsnbset' as _mbsnbset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnbset_l' as _mbsnbset_l:qword
        extrn '__imp__mbsnbset_s' as _mbsnbset_s:qword
        extrn '__imp__mbsnbset_s_l' as _mbsnbset_s_l:qword
    end if
    extrn '__imp__mbsncat' as _mbsncat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsncat_l' as _mbsncat_l:qword
        extrn '__imp__mbsncat_s' as _mbsncat_s:qword
        extrn '__imp__mbsncat_s_l' as _mbsncat_s_l:qword
    end if
    extrn '__imp__mbsnccnt' as _mbsnccnt:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnccnt_l' as _mbsnccnt_l:qword
    end if
    extrn '__imp__mbsncmp' as _mbsncmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsncmp_l' as _mbsncmp_l:qword
    end if
    extrn '__imp__mbsncoll' as _mbsncoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsncoll_l' as _mbsncoll_l:qword
    end if
    extrn '__imp__mbsncpy' as _mbsncpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsncpy_l' as _mbsncpy_l:qword
        extrn '__imp__mbsncpy_s' as _mbsncpy_s:qword
        extrn '__imp__mbsncpy_s_l' as _mbsncpy_s_l:qword
    end if
    extrn '__imp__mbsnextc' as _mbsnextc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnextc_l' as _mbsnextc_l:qword
    end if
    extrn '__imp__mbsnicmp' as _mbsnicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnicmp_l' as _mbsnicmp_l:qword
    end if
    extrn '__imp__mbsnicoll' as _mbsnicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnicoll_l' as _mbsnicoll_l:qword
    end if
    extrn '__imp__mbsninc' as _mbsninc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsninc_l' as _mbsninc_l:qword
    end if
    extrn '__imp__mbsnlen' as _mbsnlen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnlen_l' as _mbsnlen_l:qword
    end if
    extrn '__imp__mbsnset' as _mbsnset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsnset_l' as _mbsnset_l:qword
        extrn '__imp__mbsnset_s' as _mbsnset_s:qword
        extrn '__imp__mbsnset_s_l' as_mbsnset_s_l :qword
    end if
    extrn '__imp__mbspbrk' as _mbspbrk:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbspbrk_l' as _mbspbrk_l:qword
    end if
    extrn '__imp__mbsrchr' as _mbsrchr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsrchr_l' as :qword
    end if
    extrn '__imp__mbsrev' as _mbsrev:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsrev_l' as _mbsrev_l:qword
    end if
    extrn '__imp__mbsset' as _mbsset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsset_l' as _mbsset_l:qword
        extrn '__imp__mbsset_s' as _mbsset_s:qword
        extrn '__imp__mbsset_s_l' as _mbsset_s_l:qword
    end if
    extrn '__imp__mbsspn' as _mbsspn:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsspn_l' as _mbsspn_l:qword
    end if
    extrn '__imp__mbsspnp' as _mbsspnp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsspnp_l' as _mbsspnp_l:qword
    end if
    extrn '__imp__mbsstr' as _mbsstr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsstr_l' as _mbsstr_l:qword
    end if
    extrn '__imp__mbstok' as _mbstok:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbstok_l' as _mbstok_l:qword
        extrn '__imp__mbstok_s' as _mbstok_s:qword
        extrn '__imp__mbstok_s_l' as _mbstok_s_l:qword
        extrn '__imp__mbstowcs_l' as _mbstowcs_l:qword
        extrn '__imp__mbstowcs_s_l' as _mbstowcs_s_l:qword
    end if
    extrn '__imp__mbstrlen' as _mbstrlen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbstrlen_l' as _mbstrlen_l:qword
    end if
    extrn '__imp__mbstrnlen' as _mbstrnlen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbstrnlen_l' as :qword
    end if
    extrn '__imp__mbsupr' as _mbsupr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mbsupr_l' as _mbsupr_l:qword
        extrn '__imp__mbsupr_s' as _mbsupr_s:qword
        extrn '__imp__mbsupr_s_l' as _mbsupr_s_l:qword
        extrn '__imp__mbtowc_l' as _mbtowc_l:qword
    end if
    extrn '__imp__memccpy' as _memccpy:qword
    extrn '__imp__memicmp' as _memicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__memicmp_l' as _memicmp_l:qword
    end if
    extrn '__imp__mkdir' as _mkdir:qword
    extrn '__imp__mkgmtime' as _mkgmtime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mkgmtime32' as _mkgmtime32:qword
    end if
    extrn '__imp__mkgmtime64' as _mkgmtime64:qword
    extrn '__imp__mktemp' as _mktemp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__mktemp_s' as _mktemp_s:qword
        extrn '__imp__mktime32' as _mktime32:qword
    end if
    extrn '__imp__mktime64' as _mktime64:qword
    extrn '__imp__msize' as _msize:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__msize_dbg' as _msize_dbg:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__msize_debug' as _msize_debug:qword
    end if
    extrn '__imp__nextafter' as _nextafter:qword
    extrn '__imp__nextafterf' as _nextafterf:qword
    extrn '__imp__onexit' as _onexit:qword
    extrn '__imp__open' as _open:qword
    extrn '__imp__open_osfhandle' as _open_osfhandle:qword
    extrn '__imp__osplatform' as _osplatform:qword
    extrn '__imp__osver' as _osver:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__outp' as _outp:qword
        extrn '__imp__outpd' as _outpd:qword
        extrn '__imp__outpw' as _outpw:qword
    end if
    extrn '__imp__pclose' as _pclose:qword
    extrn '__imp__pctype' as _pctype:qword
    extrn '__imp__pgmptr' as _pgmptr:qword
    extrn '__imp__pipe' as _pipe:qword
    extrn '__imp__popen' as _popen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__printf_l' as _printf_l:qword
        extrn '__imp__printf_p' as _printf_p:qword
        extrn '__imp__printf_p_l' as _printf_p_l:qword
        extrn '__imp__printf_s_l' as _printf_s_l:qword
    end if
    extrn '__imp__purecall' as _purecall:qword
    extrn '__imp__putch' as _putch:qword
    extrn '__imp__putenv' as _putenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__putenv_s' as _putenv_s:qword
    end if
    extrn '__imp__putw' as _putw:qword
    extrn '__imp__putwch' as _putwch:qword
    extrn '__imp__putws' as _putws:qword
    extrn '__imp__pwctype' as _pwctype:qword
    extrn '__imp__read' as _read:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__realloc_dbg' as _realloc_dbg:qword
    end if
    extrn '__imp__resetstkoflw' as _resetstkoflw:qword
    extrn '__imp__rmdir' as _rmdir:qword
    extrn '__imp__rmtmp' as _rmtmp:qword
    extrn '__imp__rotl' as _rotl:qword
    extrn '__imp__rotl64' as _rotl64:qword
    extrn '__imp__rotr' as _rotr:qword
    extrn '__imp__rotr64' as _rotr64:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__safe_fdiv' as _safe_fdiv:qword
        extrn '__imp__safe_fdivr' as _safe_fdivr:qword
        extrn '__imp__safe_fprem' as _safe_fprem:qword
        extrn '__imp__safe_fprem1' as _safe_fprem1:qword
    end if
    extrn '__imp__scalb' as _scalb:qword
    extrn '__imp__scalbf' as _scalbf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__scanf_l' as _scanf_l:qword
        extrn '__imp__scanf_s_l' as _scanf_s_l:qword
    end if
    extrn '__imp__scprintf' as _scprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__scprintf_l' as _scprintf_l:qword
        extrn '__imp__scprintf_p_l' as _scprintf_p_l:qword
    end if
    extrn '__imp__scwprintf' as _scwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__scwprintf_l' as _scwprintf_l:qword
        extrn '__imp__scwprintf_p_l' as _scwprintf_p_l:qword
    end if
    extrn '__imp__searchenv' as _searchenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__searchenv_s' as _searchenv_s:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__seh_longjmp_unwind' as _seh_longjmp_unwind:qword
        extrn '__imp__seh_longjmp_unwind4' as _seh_longjmp_unwind4:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__set_controlfp' as _set_controlfp:qword
        extrn '__imp__set_doserrno' as _set_doserrno:qword
        extrn '__imp__set_errno' as _set_errno:qword
    end if
    extrn '__imp__set_error_mode' as _set_error_mode:qword
    extrn '__imp__set_fileinfo' as _set_fileinfo:qword
    extrn '__imp__set_fmode' as _set_fmode:qword
    extrn '__imp__set_output_format' as _set_output_format:qword
    extrn '__imp__set_sbh_threshold' as _set_sbh_threshold:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__set_SSE2_enable' as _set_SSE2_enable:qword
    end if
    extrn '__imp__seterrormode' as _seterrormode:qword
    extrn '__imp__setjmp' as _setjmp:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__setjmp3' as _setjmp3:qword
    end if
    extrn '__imp__setjmpex' as _setjmpex:qword
    extrn '__imp__setmaxstdio' as _setmaxstdio:qword
    extrn '__imp__setmbcp' as _setmbcp:qword
    extrn '__imp__setmode' as _setmode:qword
    extrn '__imp__setsystime' as _setsystime:qword
    extrn '__imp__sleep' as _sleep:qword
    extrn '__imp__snprintf' as _snprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__snprintf_c' as _snprintf_c:qword
        extrn '__imp__snprintf_c_l' as _snprintf_c_l:qword
        extrn '__imp__snprintf_l' as _snprintf_l:qword
        extrn '__imp__snprintf_s' as _snprintf_s:qword
        extrn '__imp__snprintf_s_l' as _snprintf_s_l:qword
    end if
    extrn '__imp__snscanf' as _snscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__snscanf_l' as _snscanf_l:qword
        extrn '__imp__snscanf_s' as _snscanf_s:qword
        extrn '__imp__snscanf_s_l' as _snscanf_s_l:qword
    end if
    extrn '__imp__snwprintf' as _snwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__snwprintf_l' as _snwprintf_l:qword
        extrn '__imp__snwprintf_s' as _snwprintf_s:qword
        extrn '__imp__snwprintf_s_l' as _snwprintf_s_l:qword
    end if
    extrn '__imp__snwscanf' as _snwscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__snwscanf_l' as _snwscanf_l:qword
        extrn '__imp__snwscanf_s' as _snwscanf_s:qword
        extrn '__imp__snwscanf_s_l' as _snwscanf_s_l:qword
    end if
    extrn '__imp__sopen' as _sopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__sopen_s' as _sopen_s:qword
    end if
    extrn '__imp__spawnl' as _spawnl:qword
    extrn '__imp__spawnle' as _spawnle:qword
    extrn '__imp__spawnlp' as _spawnlp:qword
    extrn '__imp__spawnlpe' as _spawnlpe:qword
    extrn '__imp__spawnv' as _spawnv:qword
    extrn '__imp__spawnve' as _spawnve:qword
    extrn '__imp__spawnvp' as _spawnvp:qword
    extrn '__imp__spawnvpe' as _spawnvpe:qword
    extrn '__imp__splitpath' as _splitpath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__splitpath_s' as _splitpath_s:qword
        extrn '__imp__sprintf_l' as _sprintf_l:qword
        extrn '__imp__sprintf_p_l' as _sprintf_p_l:qword
        extrn '__imp__sprintf_s_l' as _sprintf_s_l:qword
        extrn '__imp__sscanf_l' as _sscanf_l:qword
        extrn '__imp__sscanf_s_l' as _sscanf_s_l:qword
    end if
    extrn '__imp__stat' as _stat:qword
    extrn '__imp__stat64' as _stat64:qword
    extrn '__imp__stati64' as _stati64:qword
    extrn '__imp__statusfp' as _statusfp:qword
    extrn '__imp__strcmpi' as _strcmpi:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strcoll_l' as _strcoll_l:qword
    end if
    extrn '__imp__strdate' as _strdate:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strdate_s' as _strdate_s:qword
    end if
    extrn '__imp__strdup' as _strdup:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strdup_dbg' as _strdup_dbg:qword
    end if
    extrn '__imp__strerror' as _strerror:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strerror_s' as _strerror_s:qword
    end if
    extrn '__imp__Strftime' as _Strftime:qword
    extrn '__imp__stricmp' as _stricmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__stricmp_l' as _stricmp_l:qword
    end if
    extrn '__imp__stricoll' as _stricoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__stricoll_l' as _stricoll_l:qword
    end if
    extrn '__imp__strlwr' as _strlwr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strlwr_l' as _strlwr_l:qword
        extrn '__imp__strlwr_s' as _strlwr_s:qword
        extrn '__imp__strlwr_s_l' as _strlwr_s_l:qword
    end if
    extrn '__imp__strncoll' as _strncoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strncoll_l' as _strncoll_l:qword
    end if
    extrn '__imp__strnicmp' as _strnicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strnicmp_l' as _strnicmp_l:qword
    end if
    extrn '__imp__strnicoll' as _strnicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strnicoll_l' as _strnicoll_l:qword
    end if
    extrn '__imp__strnset' as _strnset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strnset_s' as _strnset_s:qword
    end if
    extrn '__imp__strrev' as _strrev:qword
    extrn '__imp__strset' as _strset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strset_s' as _strset_s:qword
    end if
    extrn '__imp__strtime' as _strtime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strtime_s' as _strtime_s:qword
        extrn '__imp__strtod_l' as _strtod_l:qword
    end if
    extrn '__imp__strtoi64' as _strtoi64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strtoi64_l' as _strtoi64_l:qword
        extrn '__imp__strtol_l' as _strtol_l:qword
    end if
    extrn '__imp__strtoui64' as _strtoui64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strtoui64_l' as _strtoui64_l:qword
        extrn '__imp__strtoul_l' as _strtoul_l:qword
    end if
    extrn '__imp__strupr' as _strupr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__strupr_l' as _strupr_l:qword
        extrn '__imp__strupr_s' as _strupr_s:qword
        extrn '__imp__strupr_s_l' as _strupr_s_l:qword
        extrn '__imp__strxfrm_l' as _strxfrm_l:qword
    end if
    extrn '__imp__swab' as _swab:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__swprintf' as _swprintf:qword
        extrn '__imp__swprintf_c' as _swprintf_c:qword
        extrn '__imp__swprintf_c_l' as _swprintf_c_l:qword
        extrn '__imp__swprintf_p_l' as _swprintf_p_l:qword
        extrn '__imp__swprintf_s_l' as _swprintf_s_l:qword
        extrn '__imp__swscanf_l' as _swscanf_l:qword
        extrn '__imp__swscanf_s_l' as _swscanf_s_l:qword
    end if
    extrn '__imp__sys_errlist' as _sys_errlist:qword
    extrn '__imp__sys_nerr' as _sys_nerr:qword
    extrn '__imp__tell' as _tell:qword
    extrn '__imp__telli64' as _telli64:qword
    extrn '__imp__tempnam' as _tempnam:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__tempnam_dbg' as _tempnam_dbg:qword
        extrn '__imp__time32' as _time32:qword
    end if
    extrn '__imp__time64' as _time64:qword
    extrn '__imp__timezone' as _timezone:qword
    extrn '__imp__tolower' as _tolower:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__tolower_l' as _tolower_l:qword
    end if
    extrn '__imp__toupper' as _toupper:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__toupper_l' as _toupper_l:qword
        extrn '__imp__towlower_l' as _towlower_l:qword
        extrn '__imp__towupper_l' as _towupper_l:qword
    end if
    extrn '__imp__tzname' as _tzname:qword
    extrn '__imp__tzset' as _tzset:qword
    extrn '__imp__ui64toa' as _ui64toa:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ui64toa_s' as _ui64toa_s:qword
    end if
    extrn '__imp__ui64tow' as _ui64tow:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ui64tow_s' as _ui64tow_s:qword
    end if
    extrn '__imp__ultoa' as _ultoa:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ultoa_s' as _ultoa_s:qword
    end if
    extrn '__imp__ultow' as _ultow:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ultow_s' as _ultow_s:qword
    end if
    extrn '__imp__umask' as _umask:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__umask_s' as _umask_s:qword
    end if
    extrn '__imp__ungetch' as _ungetch:qword
    extrn '__imp__ungetwch' as _ungetwch:qword
    extrn '__imp__unlink' as _unlink:qword
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__unloaddll' as _unloaddll:qword
    end if
    extrn '__imp__unlock' as _unlock:qword
    extrn '__imp__utime' as _utime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__utime32' as _utime32:qword
    end if
    extrn '__imp__utime64' as _utime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__vcprintf' as _vcprintf:qword
        extrn '__imp__vcprintf_l' as _vcprintf_l:qword
        extrn '__imp__vcprintf_p' as _vcprintf_p:qword
        extrn '__imp__vcprintf_p_l' as _vcprintf_p_l:qword
        extrn '__imp__vcprintf_s' as _vcprintf_s:qword
        extrn '__imp__vcprintf_s_l' as _vcprintf_s_l:qword
        extrn '__imp__vcwprintf' as _vcwprintf:qword
        extrn '__imp__vcwprintf_l' as _vcwprintf_l:qword
        extrn '__imp__vcwprintf_p' as _vcwprintf_p:qword
        extrn '__imp__vcwprintf_p_l' as _vcwprintf_p_l:qword
        extrn '__imp__vcwprintf_s' as _vcwprintf_s:qword
        extrn '__imp__vcwprintf_s_l' as _vcwprintf_s_l:qword
        extrn '__imp__vfprintf_l' as _vfprintf_l:qword
        extrn '__imp__vfprintf_p' as _vfprintf_p:qword
        extrn '__imp__vfprintf_p_l' as _vfprintf_p_l:qword
        extrn '__imp__vfprintf_s_l' as _vfprintf_s_l:qword
        extrn '__imp__vfwprintf_l' as _vfwprintf_l:qword
        extrn '__imp__vfwprintf_p' as _vfwprintf_p:qword
        extrn '__imp__vfwprintf_p_l' as _vfwprintf_p_l:qword
        extrn '__imp__vfwprintf_s_l' as _vfwprintf_s_l:qword
        extrn '__imp__vprintf_l' as _vprintf_l:qword
        extrn '__imp__vprintf_p' as _vprintf_p:qword
        extrn '__imp__vprintf_p_l' as _vprintf_p_l:qword
        extrn '__imp__vprintf_s_l' as _vprintf_s_l:qword
    end if
    extrn '__imp__vscprintf' as _vscprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__vscprintf_l' as _vscprintf_l:qword
        extrn '__imp__vscprintf_p_l' as _vscprintf_p_l:qword
    end if
    extrn '__imp__vscwprintf' as _vscwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__vscwprintf_l' as _vscwprintf_l:qword
        extrn '__imp__vscwprintf_p_l' as _vscwprintf_p_l:qword
    end if
    extrn '__imp__vsnprintf' as _vsnprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__vsnprintf_c' as _vsnprintf_c:qword
        extrn '__imp__vsnprintf_c_l' as _vsnprintf_c_l:qword
        extrn '__imp__vsnprintf_l' as _vsnprintf_l:qword
        extrn '__imp__vsnprintf_s' as _vsnprintf_s:qword
        extrn '__imp__vsnprintf_s_l' as _vsnprintf_s_l:qword
    end if
    extrn '__imp__vsnwprintf' as _vsnwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__vsnwprintf_l' as _vsnwprintf_l:qword
        extrn '__imp__vsnwprintf_s' as _vsnwprintf_s:qword
        extrn '__imp__vsnwprintf_s_l' as _vsnwprintf_s_l:qword
        extrn '__imp__vsprintf_l' as _vsprintf_l:qword
        extrn '__imp__vsprintf_p' as _vsprintf_p:qword
        extrn '__imp__vsprintf_p_l' as _vsprintf_p_l:qword
        extrn '__imp__vsprintf_s_l' as _vsprintf_s_l:qword
        extrn '__imp__vswprintf' as _vswprintf:qword
        extrn '__imp__vswprintf_c' as _vswprintf_c:qword
        extrn '__imp__vswprintf_c_l' as _vswprintf_c_l:qword
        extrn '__imp__vswprintf_l' as _vswprintf_l:qword
        extrn '__imp__vswprintf_p_l' as _vswprintf_p_l:qword
        extrn '__imp__vswprintf_s_l' as _vswprintf_s_l:qword
        extrn '__imp__vwprintf_l' as _vwprintf_l:qword
        extrn '__imp__vwprintf_p' as _vwprintf_p:qword
        extrn '__imp__vwprintf_p_l' as _vwprintf_p_l:qword
        extrn '__imp__vwprintf_s_l' as _vwprintf_s_l:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__W_Getdays' as _W_Getdays:qword
        extrn '__imp__W_Getmonths' as _W_Getmonths:qword
        extrn '__imp__W_Gettnames' as _W_Gettnames:qword
    end if
    extrn '__imp__waccess' as _waccess:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__waccess_s' as _waccess_s:qword
    end if
    extrn '__imp__wasctime' as _wasctime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wasctime_s' as _wasctime_s:qword
        extrn '__imp__wassert' as _wassert:qword
    end if
    extrn '__imp__wchdir' as _wchdir:qword
    extrn '__imp__wchmod' as _wchmod:qword
    extrn '__imp__wcmdln' as _wcmdln:qword
    extrn '__imp__wcreat' as _wcreat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcscoll_l' as _wcscoll_l:qword
    end if
    extrn '__imp__wcsdup' as _wcsdup:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsdup_dbg' as _wcsdup_dbg:qword
    end if
    extrn '__imp__wcserror' as _wcserror:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcserror_s' as _wcserror_s:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__Wcsftime' as _Wcsftime:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsftime_l' as _wcsftime_l:qword
    end if
    extrn '__imp__wcsicmp' as _wcsicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsicmp_l' as _wcsicmp_l:qword
    end if
    extrn '__imp__wcsicoll' as _wcsicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsicoll_l' as _wcsicoll_l:qword
    end if
    extrn '__imp__wcslwr' as _wcslwr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcslwr_l' as _wcslwr_l:qword
        extrn '__imp__wcslwr_s' as _wcslwr_s:qword
        extrn '__imp__wcslwr_s_l' as _wcslwr_s_l:qword
    end if
    extrn '__imp__wcsncoll' as _wcsncoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsncoll_l' as _wcsncoll_l:qword
    end if
    extrn '__imp__wcsnicmp' as _wcsnicmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsnicmp_l' as _wcsnicmp_l:qword
    end if
    extrn '__imp__wcsnicoll' as _wcsnicoll:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsnicoll_l' as _wcsnicoll_l:qword
    end if
    extrn '__imp__wcsnset' as _wcsnset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsnset_s' as _wcsnset_s:qword
    end if
    extrn '__imp__wcsrev' as _wcsrev:qword
    extrn '__imp__wcsset' as _wcsset:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsset_s' as _wcsset_s:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__wcstod_l' as _wcstod_l:qword
    end if
    extrn '__imp__wcstoi64' as _wcstoi64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcstoi64_l' as _wcstoi64_l:qword
        extrn '__imp__wcstol_l' as _wcstol_l:qword
        extrn '__imp__wcstombs_l' as _wcstombs_l:qword
        extrn '__imp__wcstombs_s_l' as _wcstombs_s_l:qword
    end if
    extrn '__imp__wcstoui64' as _wcstoui64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcstoui64_l' as _wcstoui64_l:qword
        extrn '__imp__wcstoul_l' as _wcstoul_l:qword
    end if
    extrn '__imp__wcsupr' as _wcsupr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wcsupr_l' as _wcsupr_l:qword
        extrn '__imp__wcsupr_s' as _wcsupr_s:qword
        extrn '__imp__wcsupr_s_l' as _wcsupr_s_l:qword
        extrn '__imp__wcsxfrm_l' as _wcsxfrm_l:qword
    end if
    extrn '__imp__wctime' as _wctime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wctime32' as _wctime32:qword
        extrn '__imp__wctime32_s' as _wctime32_s:qword
    end if
    extrn '__imp__wctime64' as _wctime64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wctime64_s' as _wctime64_s:qword
        extrn '__imp__wctomb_l' as _wctomb_l:qword
        extrn '__imp__wctomb_s_l' as _wctomb_s_l:qword
    end if
    extrn '__imp__wctype' as _wctype:qword
    extrn '__imp__wenviron' as _wenviron:qword
    extrn '__imp__wexecl' as _wexecl:qword
    extrn '__imp__wexecle' as _wexecle:qword
    extrn '__imp__wexeclp' as _wexeclp:qword
    extrn '__imp__wexeclpe' as _wexeclpe:qword
    extrn '__imp__wexecv' as _wexecv:qword
    extrn '__imp__wexecve' as _wexecve:qword
    extrn '__imp__wexecvp' as _wexecvp:qword
    extrn '__imp__wexecvpe' as _wexecvpe:qword
    extrn '__imp__wfdopen' as _wfdopen:qword
    extrn '__imp__wfindfirst' as _wfindfirst:qword
    extrn '__imp__wfindfirst64' as _wfindfirst64:qword
    extrn '__imp__wfindfirsti64' as _wfindfirsti64:qword
    extrn '__imp__wfindnext' as _wfindnext:qword
    extrn '__imp__wfindnext64' as _wfindnext64:qword
    extrn '__imp__wfindnexti64' as _wfindnexti64:qword
    extrn '__imp__wfopen' as _wfopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wfopen_s' as _wfopen_s:qword
    end if
    extrn '__imp__wfreopen' as _wfreopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wfreopen_s' as _wfreopen_s:qword
    end if
    extrn '__imp__wfsopen' as _wfsopen:qword
    extrn '__imp__wfullpath' as _wfullpath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wfullpath_dbg' as _wfullpath_dbg:qword
    end if
    extrn '__imp__wgetcwd' as _wgetcwd:qword
    extrn '__imp__wgetdcwd' as _wgetdcwd:qword
    extrn '__imp__wgetenv' as _wgetenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wgetenv_s' as _wgetenv_s:qword
    end if
    extrn '__imp__winmajor' as _winmajor:qword
    extrn '__imp__winminor' as _winminor:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__winput_s' as _winput_s:qword
    end if
    extrn '__imp__winver' as _winver:qword
    extrn '__imp__wmakepath' as _wmakepath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wmakepath_s' as _wmakepath_s:qword
    end if
    extrn '__imp__wmkdir' as _wmkdir:qword
    extrn '__imp__wmktemp' as _wmktemp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wmktemp_s' as _wmktemp_s:qword
    end if
    extrn '__imp__wopen' as _wopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__woutput_s' as _woutput_s:qword
    end if
    extrn '__imp__wperror' as _wperror:qword
    extrn '__imp__wpgmptr' as _wpgmptr:qword
    extrn '__imp__wpopen' as _wpopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wprintf_l' as _wprintf_l:qword
        extrn '__imp__wprintf_p' as _wprintf_p:qword
        extrn '__imp__wprintf_p_l' as _wprintf_p_l:qword
        extrn '__imp__wprintf_s_l' as _wprintf_s_l:qword
    end if
    extrn '__imp__wputenv' as _wputenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wputenv_s' as _wputenv_s:qword
    end if
    extrn '__imp__wremove' as _wremove:qword
    extrn '__imp__wrename' as _wrename:qword
    extrn '__imp__write' as _write:qword
    extrn '__imp__wrmdir' as _wrmdir:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wscanf_l' as _wscanf_l:qword
        extrn '__imp__wscanf_s_l' as _wscanf_s_l:qword
    end if
    extrn '__imp__wsearchenv' as _wsearchenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wsearchenv_s' as _wsearchenv_s:qword
    end if
    extrn '__imp__wsetlocale' as _wsetlocale:qword
    extrn '__imp__wsopen' as _wsopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wsopen_s' as _wsopen_s:qword
    end if
    extrn '__imp__wspawnl' as _wspawnl:qword
    extrn '__imp__wspawnle' as _wspawnle:qword
    extrn '__imp__wspawnlp' as _wspawnlp:qword
    extrn '__imp__wspawnlpe' as _wspawnlpe:qword
    extrn '__imp__wspawnv' as _wspawnv:qword
    extrn '__imp__wspawnve' as _wspawnve:qword
    extrn '__imp__wspawnvp' as _wspawnvp:qword
    extrn '__imp__wspawnvpe' as _wspawnvpe:qword
    extrn '__imp__wsplitpath' as _wsplitpath:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wsplitpath_s' as _wsplitpath_s:qword
    end if
    extrn '__imp__wstat' as _wstat:qword
    extrn '__imp__wstat64' as _wstat64:qword
    extrn '__imp__wstati64' as _wstati64:qword
    extrn '__imp__wstrdate' as _wstrdate:qword
    extrn '__imp__wstrdate_s' as _wstrdate_s:qword
    extrn '__imp__wstrtime' as _wstrtime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wstrtime_s' as _wstrtime_s:qword
    end if
    extrn '__imp__wsystem' as _wsystem:qword
    extrn '__imp__wtempnam' as _wtempnam:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtempnam_dbg' as _wtempnam_dbg:qword
    end if
    extrn '__imp__wtmpnam' as _wtmpnam:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtmpnam_s' as _wtmpnam_s:qword
    end if
    extrn '__imp__wtof' as _wtof:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtof_l' as _wtof_l:qword
    end if
    extrn '__imp__wtoi' as _wtoi:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtoi_l' as _wtoi_l:qword
    end if
    extrn '__imp__wtoi64' as _wtoi64:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtoi64_l' as _wtoi64_l:qword
    end if
    extrn '__imp__wtol' as _wtol:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wtol_l' as _wtol_l:qword
    end if
    extrn '__imp__wunlink' as _wunlink:qword
    extrn '__imp__wutime' as _wutime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__wutime32' as _wutime32:qword
    end if
    extrn '__imp__wutime64' as _wutime64:qword
    extrn '__imp__XcptFilter' as _XcptFilter:qword
    extrn '__imp__y0' as _y0:qword
    extrn '__imp__y1' as _y1:qword
    extrn '__imp__yn' as _yn:qword
    extrn '__imp_abort' as abort:qword
    extrn '__imp_abs' as abs:qword
    extrn '__imp_acos' as acos:qword
    extrn '__imp_acosf' as acosf:qword
    extrn '__imp_asctime' as asctime:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_asctime_s' as asctime_s:qword
    end if
    extrn '__imp_asin' as asin:qword
    extrn '__imp_asinf' as asinf:qword
    extrn '__imp_atan' as atan:qword
    extrn '__imp_atan2' as atan2:qword
    extrn '__imp_atan2f' as atan2f:qword
    extrn '__imp_atanf' as atanf:qword
    extrn '__imp_atexit' as atexit:qword
    extrn '__imp_atof' as atof:qword
    extrn '__imp_atoi' as atoi:qword
    extrn '__imp_atol' as atol:qword
    extrn '__imp_bsearch' as bsearch:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_bsearch_s' as bsearch_s:qword
        extrn '__imp_btowc' as btowc:qword
    end if
    extrn '__imp_calloc' as calloc:qword
    extrn '__imp_ceil' as ceil:qword
    extrn '__imp_ceilf' as ceilf:qword
    extrn '__imp_clearerr' as clearerr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_clearerr_s' as clearerr_s:qword
    end if
    extrn '__imp_clock' as clock:qword
    extrn '__imp_cos' as cos:qword
    extrn '__imp_cosf' as cosf:qword
    extrn '__imp_cosh' as cosh:qword
    extrn '__imp_coshf' as coshf:qword
    extrn '__imp_ctime' as ctime:qword
    extrn '__imp_difftime' as _difftime:qword
    ;extrn '__imp_div' as div:qword           ;Name conflicts
    ;extrn '__imp_exit' as _exit:qword        ;Name conflicts
    extrn '__imp_exp' as exp:qword
    extrn '__imp_expf' as expf:qword
    ;extrn '__imp_fabs' as fabs:qword         ;Name conflicts
    extrn '__imp_fclose' as fclose:qword
    extrn '__imp_feof' as feof:qword
    extrn '__imp_ferror' as ferror:qword
    extrn '__imp_fflush' as fflush:qword
    extrn '__imp_fgetc' as fgetc:qword
    extrn '__imp_fgetpos' as fgetpos:qword
    extrn '__imp_fgets' as fgets:qword
    extrn '__imp_fgetwc' as fgetwc:qword
    extrn '__imp_fgetws' as fgetws:qword
    extrn '__imp_floor' as floor:qword
    extrn '__imp_floorf' as floorf:qword
    extrn '__imp_fmod' as fmod:qword
    extrn '__imp_fmodf' as fmodf:qword
    extrn '__imp_fopen' as fopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_fopen_s' as fopen_s:qword
    end if
    extrn '__imp_fprintf' as fprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_fprintf_s' as fprintf_s:qword
    end if
    extrn '__imp_fputc' as fputc:qword
    extrn '__imp_fputs' as fputs:qword
    extrn '__imp_fputwc' as fputwc:qword
    extrn '__imp_fputws' as fputws:qword
    extrn '__imp_fread' as fread:qword
    extrn '__imp_free' as free:qword
    extrn '__imp_freopen' as freopen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_freopen_s' as freopen_s:qword
    end if
    extrn '__imp_frexp' as frexp:qword
    extrn '__imp_fscanf' as fscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_fscanf_s' as fscanf_s:qword
    end if
    extrn '__imp_fseek' as fseek:qword
    extrn '__imp_fsetpos' as fsetpos:qword
    extrn '__imp_ftell' as ftell:qword
    extrn '__imp_fwprintf' as fwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_fwprintf_s' as fwprintf_s:qword
    end if
    extrn '__imp_fwrite' as fwrite:qword
    extrn '__imp_fwscanf' as fwscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_fwscanf_s' as fwscanf_s:qword
    end if
    extrn '__imp_getc' as getc:qword
    extrn '__imp_getchar' as getchar:qword
    extrn '__imp_getenv' as getenv:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_getenv_s' as getenv_s:qword
    end if
    extrn '__imp_gets' as gets:qword
    extrn '__imp_getwc' as getwc:qword
    extrn '__imp_getwchar' as getwchar:qword
    extrn '__imp_gmtime' as gmtime:qword
    extrn '__imp_is_wctype' as is_wctype:qword
    extrn '__imp_isalnum' as isalnum:qword
    extrn '__imp_isalpha' as isalpha:qword
    extrn '__imp_iscntrl' as iscntrl:qword
    extrn '__imp_isdigit' as isdigit:qword
    extrn '__imp_isgraph' as isgraph:qword
    extrn '__imp_isleadbyte' as isleadbyte:qword
    extrn '__imp_islower' as islower:qword
    extrn '__imp_isprint' as isprint:qword
    extrn '__imp_ispunct' as ispunct:qword
    extrn '__imp_isspace' as isspace:qword
    extrn '__imp_isupper' as isupper:qword
    extrn '__imp_iswalnum' as iswalnum:qword
    extrn '__imp_iswalpha' as iswalpha:qword
    extrn '__imp_iswascii' as iswascii:qword
    extrn '__imp_iswcntrl' as iswcntrl:qword
    extrn '__imp_iswctype' as iswctype:qword
    extrn '__imp_iswdigit' as iswdigit:qword
    extrn '__imp_iswgraph' as iswgraph:qword
    extrn '__imp_iswlower' as iswlower:qword
    extrn '__imp_iswprint' as iswprint:qword
    extrn '__imp_iswpunct' as iswpunct:qword
    extrn '__imp_iswspace' as iswspace:qword
    extrn '__imp_iswupper' as iswupper:qword
    extrn '__imp_iswxdigit' as iswxdigit:qword
    extrn '__imp_isxdigit' as isxdigit:qword
    extrn '__imp_labs' as labs:qword
    extrn '__imp_ldexp' as ldexp:qword
    extrn '__imp_ldiv' as ldiv:qword
    extrn '__imp_localeconv' as localeconv:qword
    extrn '__imp_localtime' as localtime:qword
    extrn '__imp_log' as log:qword
    extrn '__imp_log10' as log10:qword
    extrn '__imp_log10f' as log10f:qword
    extrn '__imp_logf' as logf:qword
    extrn '__imp_longjmp' as longjmp:qword
    extrn '__imp_malloc' as malloc:qword
    extrn '__imp_mblen' as mblen:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_mbrlen' as mbrlen:qword
        extrn '__imp_mbrtowc' as mbrtowc:qword
        extrn '__imp_mbsdup_dbg' as mbsdup_dbg:qword
        extrn '__imp_mbsrtowcs' as mbsrtowcs:qword
        extrn '__imp_mbsrtowcs_s' as mbsrtowcs_s:qword
    end if
    extrn '__imp_mbstowcs' as mbstowcs:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_mbstowcs_s' as mbstowcs_s:qword
    end if
    extrn '__imp_mbtowc' as mbtowc:qword
    extrn '__imp_memchr' as memchr:qword
    extrn '__imp_memcmp' as memcmp:qword
    extrn '__imp_memcpy' as memcpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_memcpy_s' as memcpy_s:qword
    end if
    extrn '__imp_memmove' as memmove:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_memmove_s' as memmove_s:qword
    end if
    extrn '__imp_memset' as memset:qword
    extrn '__imp_mktime' as mktime:qword
    extrn '__imp_modf' as modf:qword
    extrn '__imp_modff' as modff:qword
    extrn '__imp_perror' as perror:qword
    extrn '__imp_pow' as pow:qword
    extrn '__imp_powf' as powf:qword
    extrn '__imp_printf' as printf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_printf_s' as printf_s:qword
    end if
    extrn '__imp_putc' as putc:qword
    extrn '__imp_putchar' as putchar:qword
    extrn '__imp_puts' as puts:qword
    extrn '__imp_putwc' as putwc:qword
    extrn '__imp_putwchar' as putwchar:qword
    extrn '__imp_qsort' as qsort:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_qsort_s' as qsort_s:qword
    end if
    extrn '__imp_raise' as raise:qword
    extrn '__imp_rand' as rand:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_rand_s' as rand_s:qword
    end if
    extrn '__imp_realloc' as realloc:qword
    extrn '__imp_remove' as remove:qword
    extrn '__imp_rename' as rename:qword
    extrn '__imp_rewind' as rewind:qword
    extrn '__imp_scanf' as scanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_scanf_s' as scanf_s:qword
    end if
    extrn '__imp_setbuf' as setbuf:qword
    extrn '__imp_setjmp' as setjmp:qword
    extrn '__imp_setlocale' as setlocale:qword
    extrn '__imp_setvbuf' as setvbuf:qword
    extrn '__imp_signal' as signal:qword
    extrn '__imp_sin' as sin:qword
    extrn '__imp_sinf' as sinf:qword
    extrn '__imp_sinh' as sinh:qword
    extrn '__imp_sinhf' as sinhf:qword
    extrn '__imp_sprintf' as sprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_sprintf_s' as sprintf_s:qword
    end if
    extrn '__imp_sqrt' as sqrt:qword
    extrn '__imp_sqrtf' as sqrtf:qword
    extrn '__imp_srand' as srand:qword
    extrn '__imp_sscanf' as sscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_sscanf_s' as sscanf_s:qword
    end if
    extrn '__imp_strcat' as strcat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strcat_s' as strcat_s:qword
    end if
    extrn '__imp_strchr' as strchr:qword
    extrn '__imp_strcmp' as strcmp:qword
    extrn '__imp_strcoll' as strcoll:qword
    extrn '__imp_strcpy' as strcpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strcpy_s' as strcpy_s:qword
    end if
    extrn '__imp_strcspn' as strcspn:qword
    extrn '__imp_strerror' as strerror:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strerror_s' as strerror_s:qword
    end if
    extrn '__imp_strftime' as strftime:qword
    extrn '__imp_strlen' as strlen:qword
    extrn '__imp_strncat' as strncat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strncat_s' as strncat_s:qword
    end if
    extrn '__imp_strncmp' as strncmp:qword
    extrn '__imp_strncpy' as strncpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strncpy_s' as strncpy_s:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strnlen' as strnlen:qword
    end if
    extrn '__imp_strpbrk' as strpbrk:qword
    extrn '__imp_strrchr' as strrchr:qword
    extrn '__imp_strspn' as strspn:qword
    extrn '__imp_strstr' as strstr:qword
    extrn '__imp_strtod' as strtod:qword
    extrn '__imp_strtok' as strtok:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_strtok_s' as strtok_s:qword
    end if
    extrn '__imp_strtol' as strtol:qword
    extrn '__imp_strtoul' as strtoul:qword
    extrn '__imp_strxfrm' as strxfrm:qword
    extrn '__imp_swprintf' as swprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_swprintf_s' as swprintf_s:qword
    end if
    extrn '__imp_swscanf' as swscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_swscanf_s' as swscanf_s:qword
    end if
    extrn '__imp_system' as system:qword
    extrn '__imp_tan' as tan:qword
    extrn '__imp_tanf' as tanf:qword
    extrn '__imp_tanh' as tanh:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_tanhf' as tanhf:qword
    end if
    extrn '__imp_time' as time:qword
    extrn '__imp_tmpfile' as tmpfile:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_tmpfile_s' as tmpfile_s:qword
    end if
    extrn '__imp_tmpnam' as tmpnam:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_tmpnam_s' as tmpnam_s:qword
    end if
    extrn '__imp_tolower' as tolower:qword
    extrn '__imp_toupper' as toupper:qword
    extrn '__imp_towlower' as towlower:qword
    extrn '__imp_towupper' as towupper:qword
    extrn '__imp_ungetc' as ungetc:qword
    extrn '__imp_ungetwc' as ungetwc:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_utime' as utime:qword
    end if
    extrn '__imp_vfprintf' as vfprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vfprintf_s' as vfprintf_s:qword
    end if
    extrn '__imp_vfwprintf' as vfwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vfwprintf_s' as vfwprintf_s:qword
    end if
    extrn '__imp_vprintf' as vprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vprintf_s' as vprintf_s:qword
        extrn '__imp_vsnprintf' as vsnprintf:qword
    end if
    extrn '__imp_vsprintf' as vsprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vsprintf_s' as vsprintf_s:qword
    end if
    extrn '__imp_vswprintf' as vswprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vswprintf_s' as vswprintf_s:qword
    end if
    extrn '__imp_vwprintf' as vwprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_vwprintf_s' as vwprintf_s:qword
        extrn '__imp_wcrtomb' as wcrtomb:qword
        extrn '__imp_wcrtomb_s' as wcrtomb_s:qword
    end if
    extrn '__imp_wcscat' as wcscat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcscat_s' as wcscat_s:qword
    end if
    extrn '__imp_wcschr' as wcschr:qword
    extrn '__imp_wcscmp' as wcscmp:qword
    extrn '__imp_wcscoll' as wcscoll:qword
    extrn '__imp_wcscpy' as wcscpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcscpy_s' as wcscpy_s:qword
    end if
    extrn '__imp_wcscspn' as wcscspn:qword
    extrn '__imp_wcsftime' as wcsftime:qword
    extrn '__imp_wcslen' as wcslen:qword
    extrn '__imp_wcsncat' as wcsncat:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcsncat_s' as wcsncat_s:qword
    end if
    extrn '__imp_wcsncmp' as wcsncmp:qword
    extrn '__imp_wcsncpy' as wcsncpy:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcsncpy_s' as wcsncpy_s:qword
        extrn '__imp_wcsnlen' as wcsnlen:qword
    end if
    extrn '__imp_wcspbrk' as wcspbrk:qword
    extrn '__imp_wcsrchr' as wcsrchr:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcsrtombs' as wcsrtombs:qword
        extrn '__imp_wcsrtombs_s' as wcsrtombs_s:qword
    end if
    extrn '__imp_wcsspn' as wcsspn:qword
    extrn '__imp_wcsstr' as wcsstr:qword
    extrn '__imp_wcstod' as wcstod:qword
    extrn '__imp_wcstok' as wcstok:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcstok_s' as wcstok_s:qword
    end if
    extrn '__imp_wcstol' as wcstol:qword
    extrn '__imp_wcstombs' as wcstombs:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wcstombs_s' as wcstombs_s:qword
    end if
    extrn '__imp_wcstoul' as wcstoul:qword
    extrn '__imp_wcsxfrm' as wcsxfrm:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wctob' as wctob:qword
    end if
    extrn '__imp_wctomb' as wctomb:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wctomb_s' as wctomb_s:qword
    end if
    extrn '__imp_wprintf' as wprintf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wprintf_s' as wprintf_s:qword
    end if
    extrn '__imp_wscanf' as wscanf:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_wscanf_s' as wscanf_s:qword
    end if
else
;    extrn '__imp__??_7__non_rtti_object@@6B@' as ??_7__non_rtti_object@@6B@:dword
;    extrn '__imp__??_7bad_cast@@6B@' as ??_7bad_cast@@6B@:dword
;    extrn '__imp__??_7bad_typeid@@6B@' as ??_7bad_typeid@@6B@:dword
;    extrn '__imp__??_7exception@@6B@' as ??_7exception@@6B@:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??_E__non_rtti_object@@UAEPAXI@Z' as ??_E__non_rtti_object@@UAEPAXI@Z:dword
;       extrn '__imp__??_Ebad_cast@@UAEPAXI@Z' as ??_Ebad_cast@@UAEPAXI@Z:dword
;       extrn '__imp__??_Ebad_typeid@@UAEPAXI@Z' as ??_Ebad_typeid@@UAEPAXI@Z:dword
;       extrn '__imp__??_Eexception@@UAEPAXI@Z' as ??_Eexception@@UAEPAXI@Z:dword
;       extrn '__imp__??_Fbad_cast@@QAEXXZ' as ??_Fbad_cast@@QAEXXZ:dword
;    end if
;    extrn '__imp__??_Fbad_cast@@QEAAXXZ' as ??_Fbad_cast@@QEAAXXZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??_Fbad_typeid@@QAEXXZ' as ??_Fbad_typeid@@QAEXXZ:dword
;    end if
;    extrn '__imp__??_Fbad_typeid@@QEAAXXZ' as ??_Fbad_typeid@@QEAAXXZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??_G__non_rtti_object@@UAEPAXI@Z' as ??_G__non_rtti_object@@UAEPAXI@Z:dword
;       extrn '__imp__??_Gbad_cast@@UAEPAXI@Z' as ??_Gbad_cast@@UAEPAXI@Z:dword
;       extrn '__imp__??_Gbad_typeid@@UAEPAXI@Z' as ??_Gbad_typeid@@UAEPAXI@Z:dword
;       extrn '__imp__??_Gexception@@UAEPAXI@Z' as ??_Gexception@@UAEPAXI@Z:dword
;       extrn '__imp__??_U@YAPAXI@Z' as ??_U@YAPAXI@Z:dword
;       extrn '__imp__??_U@YAPAXIHPBDH@Z' as??_U@YAPAXIHPBDH@Z :dword
;    end if
;    extrn '__imp__??_U@YAPEAX_K@Z' as ??_U@YAPEAX_K@Z:dword
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;       extrn '__imp__??_U@YAPEAX_KHPEBDH@Z' as ??_U@YAPEAX_KHPEBDH@Z:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??_V@YAXPAX@Z' as ??_V@YAXPAX@Z:dword
;    end if
;    extrn '__imp__??_V@YAXPEAX@Z' as ??_V@YAXPEAX@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??0__non_rtti_object@@QAE@ABV0@@Z' as ??0__non_rtti_object@@QAE@ABV0@@Z:dword
;       extrn '__imp__??0__non_rtti_object@@QAE@PBD@Z' as ??0__non_rtti_object@@QAE@PBD@Z:dword
;    end if
;    extrn '__imp__??0__non_rtti_object@@QEAA@AEBV0@@Z' as ??0__non_rtti_object@@QEAA@AEBV0@@Z:dword
;    extrn '__imp__??0__non_rtti_object@@QEAA@PEBD@Z' as ??0__non_rtti_object@@QEAA@PEBD@Z:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;       extrn '__imp__??0bad_cast@@AAE@PBQBD@Z' as ??0bad_cast@@AAE@PBQBD@Z:dword
;    end if
;    extrn '__imp__??0bad_cast@@AEAA@PEBQEBD@Z' as ??0bad_cast@@AEAA@PEBQEBD@Z:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;       extrn '__imp__??0bad_cast@@QAE@ABQBD@Z' as ??0bad_cast@@QAE@ABQBD@Z:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??0bad_cast@@QAE@ABV0@@Z' as ??0bad_cast@@QAE@ABV0@@Z:dword
;       extrn '__imp__??0bad_cast@@QAE@PBD@Z' as ??0bad_cast@@QAE@PBD@Z:dword
;    end if
;    extrn '__imp__??0bad_cast@@QEAA@AEBQEBD@Z' as ??0bad_cast@@QEAA@AEBQEBD@Z:dword
;    extrn '__imp__??0bad_cast@@QEAA@AEBV0@@Z' as ??0bad_cast@@QEAA@AEBV0@@Z:dword
;    extrn '__imp__??0bad_cast@@QEAA@PEBD@Z' as ??0bad_cast@@QEAA@PEBD@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??0bad_typeid@@QAE@ABV0@@Z' as ??0bad_typeid@@QAE@ABV0@@Z:dword
;       extrn '__imp__??0bad_typeid@@QAE@PBD@Z' as ??0bad_typeid@@QAE@PBD@Z:dword
;    end if
;    extrn '__imp__??0bad_typeid@@QEAA@AEBV0@@Z' as ??0bad_typeid@@QEAA@AEBV0@@Z:dword
;    extrn '__imp__??0bad_typeid@@QEAA@PEBD@Z' as ??0bad_typeid@@QEAA@PEBD@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??0exception@@QAE@ABQBD@Z' as ??0exception@@QAE@ABQBD@Z:dword
;       extrn '__imp__??0exception@@QAE@ABQBDH@Z' as ??0exception@@QAE@ABQBDH@Z:dword
;       extrn '__imp__??0exception@@QAE@ABV0@@Z' as ??0exception@@QAE@ABV0@@Z:dword
;       extrn '__imp__??0exception@@QAE@XZ' as ??0exception@@QAE@XZ:dword
;    end if
;    extrn '__imp__??0exception@@QEAA@AEBQEBD@Z' as ??0exception@@QEAA@AEBQEBD@Z:dword
;    extrn '__imp__??0exception@@QEAA@AEBQEBDH@Z' as ??0exception@@QEAA@AEBQEBDH@Z:dword
;    extrn '__imp__??0exception@@QEAA@AEBV0@@Z' as ??0exception@@QEAA@AEBV0@@Z:dword
;    extrn '__imp__??0exception@@QEAA@XZ' as ??0exception@@QEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??1__non_rtti_object@@UAE@XZ' as ??1__non_rtti_object@@UAE@XZ:dword
;    end if
;    extrn '__imp__??1__non_rtti_object@@UEAA@XZ' as ??1__non_rtti_object@@UEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??1bad_cast@@UAE@XZ' as ??1bad_cast@@UAE@XZ:dword
;    end if
;    extrn '__imp__??1bad_cast@@UEAA@XZ' as ??1bad_cast@@UEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??1bad_typeid@@UAE@XZ' as ??1bad_typeid@@UAE@XZ:dword
;    end if
;    extrn '__imp__??1bad_typeid@@UEAA@XZ' as ??1bad_typeid@@UEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??1exception@@UAE@XZ' as ??1exception@@UAE@XZ:dword
;    end if
;    extrn '__imp__??1exception@@UEAA@XZ' as ??1exception@@UEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??1type_info@@UAE@XZ' as ?1type_info@@UAE@XZ:dword
;    end if
;    extrn '__imp__??1type_info@@UEAA@XZ' as ??1type_info@@UEAA@XZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??2@YAPAXI@Z' as ??2@YAPAXI@Z:dword
;       extrn '__imp__??2@YAPAXIHPBDH@Z' as ??2@YAPAXIHPBDH@Z:dword
;    end if
;    extrn '__imp__??2@YAPEAX_K@Z' as ??2@YAPEAX_K@Z:dword
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;       extrn '__imp__??2@YAPEAX_KHPEBDH@Z' as ??2@YAPEAX_KHPEBDH@Z:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??3@YAXPAX@Z' as ??3@YAXPAX@Z:dword
;    end if
;    extrn '__imp__??3@YAXPEAX@Z' as ??3@YAXPEAX@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??4__non_rtti_object@@QAEAAV0@ABV0@@Z' as ??4__non_rtti_object@@QAEAAV0@ABV0@@Z:dword
;    end if
;    extrn '__imp__??4__non_rtti_object@@QEAAAEAV0@AEBV0@@Z' as ??4__non_rtti_object@@QEAAAEAV0@AEBV0@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??4bad_cast@@QAEAAV0@ABV0@@Z' as ??4bad_cast@@QAEAAV0@ABV0@@Z:dword
;    end if
;    extrn '__imp__??4bad_cast@@QEAAAEAV0@AEBV0@@Z' as ??4bad_cast@@QEAAAEAV0@AEBV0@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??4bad_typeid@@QAEAAV0@ABV0@@Z' as ??4bad_typeid@@QAEAAV0@ABV0@@Z:dword
;    end if
;    extrn '__imp__??4bad_typeid@@QEAAAEAV0@AEBV0@@Z' as ??4bad_typeid@@QEAAAEAV0@AEBV0@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??4exception@@QAEAAV0@ABV0@@Z' as ??4exception@@QAEAAV0@ABV0@@Z:dword
;    end if
;    extrn '__imp__??4exception@@QEAAAEAV0@AEBV0@@Z' as ??4exception@@QEAAAEAV0@AEBV0@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??8type_info@@QBEHABV0@@Z' as ??8type_info@@QBEHABV0@@Z:dword
;    end if
;    extrn '__imp__??8type_info@@QEBAHAEBV0@@Z' as ??8type_info@@QEBAHAEBV0@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__??9type_info@@QBEHABV0@@Z' as ??9type_info@@QBEHABV0@@Z:dword
;    end if
;    extrn '__imp__??9type_info@@QEBAHAEBV0@@Z' as ??9type_info@@QEBAHAEBV0@@Z:dword
;    extrn '__imp__?_query_new_handler@@YAP6AH_K@ZXZ' as ?_query_new_handler@@YAP6AH_K@ZXZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?_query_new_handler@@YAP6AHI@ZXZ' as ?_query_new_handler@@YAP6AHI@ZXZ:dword
;    end if
;    extrn '__imp__?_query_new_mode@@YAHXZ' as ?_query_new_mode@@YAHXZ:dword
;    extrn '__imp__?_set_new_handler@@YAP6AH_K@ZP6AH0@Z@Z' as ?_set_new_handler@@YAP6AH_K@ZP6AH0@Z@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?_set_new_handler@@YAP6AHI@ZP6AHI@Z@Z' as ?_set_new_handler@@YAP6AHI@ZP6AHI@Z@Z:dword
;    end if
;    extrn '__imp__?_set_new_mode@@YAHH@Z' as ?_set_new_mode@@YAHH@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?_set_se_translator@@YAP6AXIPAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z' as ?_set_se_translator@@YAP6AXIPAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z:dword
;    end if
;    extrn '__imp__?_set_se_translator@@YAP6AXIPEAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z' as ?_set_se_translator@@YAP6AXIPEAU_EXCEPTION_POINTERS@@@ZP6AXI0@Z@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?before@type_info@@QBEHABV1@@Z' as ?before@type_info@@QBEHABV1@@Z:dword
;    end if
;    extrn '__imp__?before@type_info@@QEBAHAEBV1@@Z' as ?before@type_info@@QEBAHAEBV1@@Z:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?name@type_info@@QBEPBDXZ' as ?name@type_info@@QBEPBDXZ:dword
;    end if
;    extrn '__imp__?name@type_info@@QEBAPEBDXZ' as ?name@type_info@@QEBAPEBDXZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?raw_name@type_info@@QBEPBDXZ' as ?raw_name@type_info@@QBEPBDXZ:dword
;    end if
;    extrn '__imp__?raw_name@type_info@@QEBAPEBDXZ' as ?raw_name@type_info@@QEBAPEBDXZ:dword
;    extrn '__imp__?set_new_handler@@YAP6AXXZP6AXXZ@Z' as ?set_new_handler@@YAP6AXXZP6AXXZ@Z:dword
;    extrn '__imp__?set_terminate@@YAP6AXXZP6AXXZ@Z' as ?set_terminate@@YAP6AXXZP6AXXZ@Z:dword                                    
;    extrn '__imp__?set_unexpected@@YAP6AXXZP6AXXZ@Z' as ?set_unexpected@@YAP6AXXZP6AXXZ@Z:dword                                   
;    extrn '__imp__?terminate@@YAXXZ' as ?terminate@@YAXXZ:dword
;    extrn '__imp__?unexpected@@YAXXZ' as ?unexpected@@YAXXZ:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;       extrn '__imp__?what@exception@@UBEPBDXZ' as ?what@exception@@UBEPBDXZ:dword
;    end if
;    extrn '__imp__?what@exception@@UEBAPEBDXZ' as ?what@exception@@UEBAPEBDXZ:dword
;    extrn '__imp_____lc_codepage_func' as ___lc_codepage_func:dword
;    extrn '__imp_____lc_collate_cp_func' as ___lc_collate_cp_func:dword
;    extrn '__imp_____lc_handle_func' as ___lc_handle_func:dword
;    extrn '__imp_____mb_cur_max_func' as ___mb_cur_max_func:dword
;    extrn '__imp_____setlc_active_func' as ___setlc_active_func:dword
;    extrn '__imp_____unguarded_readlc_active_add_func' as ___unguarded_readlc_active_add_func:dword
;    if (NTDDI_VERSION >= NTDDI_WIN10)
;        extrn '__imp____AdjustPointer' as __AdjustPointer:dword
;    end if
;    extrn '__imp____argc' as __argc:dword
;    extrn '__imp____argv' as __argv:dword
;    extrn '__imp____badioinfo' as __badioinfo:dword
;    extrn '__imp____CppXcptFilter' as __CppXcptFilter:dword
;    extrn '__imp____crtCompareStringA' as __crtCompareStringA:dword
;    extrn '__imp____crtCompareStringW' as __crtCompareStringW:dword
;    extrn '__imp____crtGetLocaleInfoW' as __crtGetLocaleInfoW:dword
;    extrn '__imp____crtGetStringTypeW' as __crtGetStringTypeW:dword
;    extrn '__imp____crtLCMapStringA' as __crtLCMapStringA:dword
;    extrn '__imp____crtLCMapStringW' as __crtLCMapStringW:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp____CxxCallUnwindDelDtor' as __CxxCallUnwindDelDtor:dword
;        extrn '__imp____CxxCallUnwindDtor' as __CxxCallUnwindDtor:dword
;        extrn '__imp____CxxCallUnwindVecDtor' as __CxxCallUnwindVecDtor:dword
;        extrn '__imp____CxxDetectRethrow' as __CxxDetectRethrow:dword
;        extrn '__imp____CxxExceptionFilter' as __CxxExceptionFilter:dword
;    end if
;    extrn '__imp____CxxFrameHandler' as __CxxFrameHandler:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp____CxxFrameHandler2' as __CxxFrameHandler2:dword
;        extrn '__imp____CxxFrameHandler3' as __CxxFrameHandler3:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp____CxxLongjmpUnwind' as __CxxLongjmpUnwind:dword
;        extrn '__imp____CxxQueryExceptionSize' as __CxxQueryExceptionSize:dword
;        extrn '__imp____CxxRegisterExceptionObject' as __CxxRegisterExceptionObject:dword
;        extrn '__imp____CxxUnregisterExceptionObject' as __CxxUnregisterExceptionObject:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp____daylight' as __daylight:dword
;    end if
;    extrn '__imp____DestructExceptionObject' as __DestructExceptionObject:dword
;    extrn '__imp____dllonexit' as _dllonexit:dword
;    extrn '__imp____doserrno' as __doserrno:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp____dstbias' as _imp___dstbias:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN10)
;        extrn '__imp____ExceptionPtrAssign' as __ExceptionPtrAssign:dword
;        extrn '__imp____ExceptionPtrCompare' as __ExceptionPtrCompare:dword
;        extrn '__imp____ExceptionPtrCopy' as __ExceptionPtrCopy:dword
;        extrn '__imp____ExceptionPtrCopyException' as __ExceptionPtrCopyException:dword
;        extrn '__imp____ExceptionPtrCreate' as __ExceptionPtrCreate:dword
;        extrn '__imp____ExceptionPtrCurrentException' as __ExceptionPtrCurrentException:dword
;        extrn '__imp____ExceptionPtrDestroy' as __ExceptionPtrDestroy:dword
;        extrn '__imp____ExceptionPtrRethrow' as __ExceptionPtrRethrow:dword
;        extrn '__imp____ExceptionPtrSwap' as __ExceptionPtrSwap:dword
;        extrn '__imp____ExceptionPtrToBool' as __ExceptionPtrToBool:dword
;    end if
;    extrn '__imp____fpecode' as __fpecode:dword
;    extrn '__imp____getmainargs' as __getmainargs:dword
;    extrn '__imp____initenv' as __initenv:dword
;    extrn '__imp____iob_func' as __iob_func:dword
;    extrn '__imp____isascii' as __isascii:dword
;    extrn '__imp____iscsym' as __iscsym:dword
;    extrn '__imp____iscsymf' as __iscsymf:dword
;    extrn '__imp____lc_codepage' as _lc_codepage:dword
;    extrn '__imp____lc_collate_cp' as __lc_collate_cp:dword
;    extrn '__imp____lc_handle' as __lc_handle:dword
;    extrn '__imp____lconv_init' as __lconv_init:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp____libm_sse2_acos' as __libm_sse2_acos:dword
;        extrn '__imp____libm_sse2_acosf' as __libm_sse2_acosf:dword
;        extrn '__imp____libm_sse2_asin' as __libm_sse2_asin:dword
;        extrn '__imp____libm_sse2_asinf' as __libm_sse2_asinf:dword
;        extrn '__imp____libm_sse2_atan' as __libm_sse2_atan:dword
;        extrn '__imp____libm_sse2_atan2' as _libm_sse2_atan2:dword
;        extrn '__imp____libm_sse2_atanf' as __libm_sse2_atanf:dword
;        extrn '__imp____libm_sse2_cos' as __libm_sse2_cos:dword
;        extrn '__imp____libm_sse2_cosf' as __libm_sse2_cosf:dword
;        extrn '__imp____libm_sse2_exp' as __libm_sse2_exp:dword
;        extrn '__imp____libm_sse2_expf' as __libm_sse2_expf:dword
;        extrn '__imp____libm_sse2_log' as __libm_sse2_log:dword
;        extrn '__imp____libm_sse2_log10' as __libm_sse2_log10:dword
;        extrn '__imp____libm_sse2_log10f' as __libm_sse2_log10f:dword
;        extrn '__imp____libm_sse2_logf' as __libm_sse2_logf:dword
;        extrn '__imp____libm_sse2_pow' as __libm_sse2_pow:dword
;        extrn '__imp____libm_sse2_powf' as __libm_sse2_powf:dword
;        extrn '__imp____libm_sse2_sin' as __libm_sse2_sin:dword
;        extrn '__imp____libm_sse2_sinf' as __libm_sse2_sinf:dword
;        extrn '__imp____libm_sse2_tan' as __libm_sse2_tan:dword
;        extrn '__imp____libm_sse2_tanf' as __libm_sse2_tanf:dword
;    end if
;    extrn '__imp____mb_cur_max' as __mb_cur_max:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp____p___argc' as __p___argc:dword
;        extrn '__imp____p___argv' as __p___argv:dword
;        extrn '__imp____p___initenv' as __p___initenv:dword
;        extrn '__imp____p___mb_cur_max' as __p___mb_cur_max:dword
;        extrn '__imp____p___wargv' as __p___wargv:dword
;        extrn '__imp____p___winitenv' as __p___winitenv:dword
;        extrn '__imp____p__acmdln' as __p__acmdln:dword
;        extrn '__imp____p__amblksiz' as __p__amblksiz:dword
;        extrn '__imp____p__commode' as __p__commode:dword
;        extrn '__imp____p__daylight' as __p__daylight:dword
;        extrn '__imp____p__dstbias' as __p__dstbias:dword
;        extrn '__imp____p__environ' as __p__environ:dword
;        extrn '__imp____p__fileinfo' as __p__fileinfo:dword
;        extrn '__imp____p__fmode' as __p__fmode:dword
;        extrn '__imp____p__iob' as __p__iob:dword
;        extrn '__imp____p__mbcasemap' as __p__mbcasemap:dword
;        extrn '__imp____p__mbctype' as __p__mbctype:dword
;        extrn '__imp____p__osver' as __p__osver:dword
;        extrn '__imp____p__pctype' as __p__pctype:dword
;        extrn '__imp____p__pgmptr' as __p__pgmptr:dword
;        extrn '__imp____p__pwctype' as __p__pwctype:dword
;        extrn '__imp____p__timezone' as __p__timezone:dword
;        extrn '__imp____p__tzname' as __p__tzname:dword
;        extrn '__imp____p__wcmdln' as __p__wcmdln:dword
;        extrn '__imp____p__wenviron' as __p__wenviron:dword
;        extrn '__imp____p__winmajor' as __p__winmajor:dword
;        extrn '__imp____p__winminor' as __p__winminor:dword
;        extrn '__imp____p__winver' as __p__winver:dword
;        extrn '__imp____p__wpgmptr' as __p__wpgmptr:dword
;    end if
;    extrn '__imp____pctype_func' as __pctype_func:dword
;    extrn '__imp____pioinfo' as __pioinfo:dword
;    extrn '__imp____pwctype_func' as __pwctype_func:dword
;    extrn '__imp____pxcptinfoptrs' as __pxcptinfoptrs:dword
;    extrn '__imp____RTCastToVoid' as __RTCastToVoid:dword
;    extrn '__imp____RTDynamicCast' as __RTDynamicCast:dword
;    extrn '__imp____RTtypeid' as __RTtypeid:dword
;    extrn '__imp____set_app_type' as __set_app_type:dword
;    extrn '__imp____setlc_active' as __setlc_active:dword
;    extrn '__imp____setusermatherr' as __setusermatherr:dword
;    extrn '__imp____STRINGTOLD' as __STRINGTOLD:dword
;    extrn '__imp____strncnt' as __strncnt:dword
;    extrn '__imp____threadhandle' as __threadhandle:dword
;    extrn '__imp____threadid' as __threadid:dword
;    extrn '__imp____toascii' as __toascii:dword
;    extrn '__imp____uncaught_exception' as __uncaught_exception:dword
;    extrn '__imp____unDName' as __unDName:dword
;    extrn '__imp____unDNameEx' as __unDNameEx:dword
;    extrn '__imp____unguarded_readlc_active' as __unguarded_readlc_active:dword
;    extrn '__imp____wargv' as __wargv:dword
;    extrn '__imp____wcserror' as __wcserror:dword
;    extrn '__imp____wcserror_s' as __wcserror_s:dword
;    extrn '__imp____wcsncnt' as __wcsncnt:dword
;    extrn '__imp____wgetmainargs' as __wgetmainargs:dword
;    extrn '__imp____winitenv' as __winitenv:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___abnormal_termination' as _abnormal_termination:dword
;    end if
;    extrn '__imp___abs64' as _abs64:dword
;    extrn '__imp___access' as _access:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___access_s' as _access_s:dword
;    end if
;    extrn '__imp___acmdln' as _acmdln:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___adj_fdiv_m16i' as _adj_fdiv_m16i:dword
;        extrn '__imp___adj_fdiv_m32' as _adj_fdiv_m32:dword
;        extrn '__imp___adj_fdiv_m32i' as _adj_fdiv_m32i:dword
;        extrn '__imp___adj_fdiv_m64' as _adj_fdiv_m64:dword
;        extrn '__imp___adj_fdiv_r' as _adj_fdiv_r:dword
;        extrn '__imp___adj_fdivr_m16i' as _adj_fdivr_m16i:dword
;        extrn '__imp___adj_fdivr_m32' as _adj_fdivr_m32:dword
;        extrn '__imp___adj_fdivr_m32i' as _adj_fdivr_m32i:dword
;        extrn '__imp___adj_fdivr_m64' as _adj_fdivr_m64:dword
;        extrn '__imp___adj_fpatan' as _adj_fpatan:dword
;        extrn '__imp___adj_fprem' as _adj_fprem:dword
;        extrn '__imp___adj_fprem1' as _adj_fprem1:dword
;        extrn '__imp___adj_fptan' as _adj_fptan:dword
;        extrn '__imp___adjust_fdiv' as _adjust_fdiv:dword
;    end if
;    extrn '__imp___aexit_rtn' as _aexit_rtn:dword
;    extrn '__imp___aligned_free' as _aligned_free:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___aligned_free_dbg' as _aligned_free_dbg:dword
;    end if
;    extrn '__imp___aligned_malloc' as _aligned_malloc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___aligned_malloc_dbg' as _aligned_malloc_dbg:dword
;    end if
;    extrn '__imp___aligned_offset_malloc' as _aligned_offset_malloc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___aligned_offset_malloc_dbg' as _aligned_offset_malloc_dbg:dword
;    end if
;    extrn '__imp___aligned_offset_realloc' as _aligned_offset_realloc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___aligned_offset_realloc_dbg' as _aligned_offset_realloc_dbg:dword
;    end if
;    extrn '__imp___aligned_realloc' as _aligned_realloc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___aligned_realloc_dbg' as _aligned_realloc_dbg:dword
;    end if
;    extrn '__imp___amsg_exit' as _amsg_exit:dword
;    extrn '__imp___assert' as _assert:dword
;    extrn '__imp___atodbl' as _atodbl:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___atodbl_l' as _atodbl_l:dword
;        extrn '__imp___atof_l' as _atof_l:dword
;        extrn '__imp___atoflt_l' as _atoflt_l:dword
;        extrn '__imp___atoi_l' as _atoi_l:dword
;    end if
;    extrn '__imp___atoi64' as _atoi64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___atoi64_l' as _atoi64_l:dword
;        extrn '__imp___atol_l' as _atol_l:dword
;    end if
;    extrn '__imp___atoldbl' as _atoldbl:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___atoldbl_l' as _atoldbl_l:dword
;    end if
;    extrn '__imp___beep' as _beep:dword
;    extrn '__imp___beginthread' as _beginthread:dword
;    extrn '__imp___beginthreadex' as _beginthreadex:dword
;    extrn '__imp___c_exit' as _c_exit:dword
;    extrn '__imp___cabs' as _cabs:dword
;    extrn '__imp___callnewh' as _callnewh:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___calloc_dbg' as _calloc_dbg:dword
;    end if
;    extrn '__imp___cexit' as _cexit:dword
;    extrn '__imp___cgets' as _cgets:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cgets_s' as _cgets_s:dword
;    end if
;    extrn '__imp___cgetws' as _cgetws:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cgetws_s' as _cgetws_s:dword
;    end if
;    extrn '__imp___chdir' as _chdir:dword
;    extrn '__imp___chdrive' as _chdrive:dword
;    extrn '__imp___chgsign' as _chgsign:dword
;    extrn '__imp___chgsignf' as _chgsignf:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___chkesp' as _chkesp:dword
;    end if
;    extrn '__imp___chmod' as _chmod:dword
;    extrn '__imp___chsize' as _chsize:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___chsize_s' as _chsize_s:dword
;        extrn '__imp___chvalidator' as _chvalidator:dword
;        extrn '__imp___chvalidator_l' as _chvalidator_l:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___CIacos' as _CIacos:dword
;        extrn '__imp___CIasin' as _CIasin:dword
;        extrn '__imp___CIatan' as _CIatan:dword
;        extrn '__imp___CIatan2' as _CIatan2:dword
;        extrn '__imp___CIcos' as _CIcos:dword
;        extrn '__imp___CIcosh' as _CIcosh:dword
;        extrn '__imp___CIexp' as _CIexp:dword
;        extrn '__imp___CIfmod' as _CIfmod:dword
;        extrn '__imp___CIlog' as _CIlog:dword
;        extrn '__imp___CIlog10' as _CIlog10:dword
;        extrn '__imp___CIpow' as _CIpow:dword
;        extrn '__imp___CIsin' as _CIsin:dword
;        extrn '__imp___CIsinh' as _CIsinh:dword
;        extrn '__imp___CIsqrt' as _CIsqrt:dword
;        extrn '__imp___CItan' as _CItan:dword
;        extrn '__imp___CItanh' as _CItanh:dword
;    end if
;    extrn '__imp___clearfp' as _clearfp:dword
;    extrn '__imp___close' as _close:dword
;    extrn '__imp___commit' as _commit:dword
;    extrn '__imp___commode' as _commode:dword
;    extrn '__imp___control87' as _control87:dword
;    extrn '__imp___controlfp' as _controlfp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___controlfp_s' as _controlfp_s:dword
;    end if
;    extrn '__imp___copysign' as _copysign:dword
;    extrn '__imp___copysignf' as _copysignf:dword
;    extrn '__imp___cprintf' as _cprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cprintf_l' as _cprintf_l:dword
;        extrn '__imp___cprintf_p' as _cprintf_p:dword
;        extrn '__imp___cprintf_p_l' as _cprintf_p_l:dword
;        extrn '__imp___cprintf_s' as _cprintf_s:dword
;        extrn '__imp___cprintf_s_l' as _cprintf_s_l:dword
;    end if
;    extrn '__imp___cputs' as _cputs:dword
;    extrn '__imp___cputws' as _cputws:dword
;    extrn '__imp___creat' as _creat:dword
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp___create_locale' as _create_locale:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___crtAssertBusy' as _crtAssertBusy:dword
;        extrn '__imp___crtBreakAlloc' as _crtBreakAlloc:dword
;        extrn '__imp___CrtCheckMemory' as _CrtCheckMemory:dword
;        extrn '__imp___CrtDbgBreak' as _CrtDbgBreak:dword
;        extrn '__imp___crtDbgFlag' as _crtDbgFlag:dword
;        extrn '__imp___CrtDbgReport' as _CrtDbgReport:dword
;        extrn '__imp___CrtDbgReportV' as _CrtDbgReportV:dword
;        extrn '__imp___CrtDbgReportW' as _CrtDbgReportW:dword
;        extrn '__imp___CrtDbgReportWV' as _CrtDbgReportWV:dword
;        extrn '__imp___CrtDoForAllClientObjects' as _CrtDoForAllClientObjects:dword
;        extrn '__imp___CrtDumpMemoryLeaks' as _CrtDumpMemoryLeaks:dword
;        extrn '__imp___CrtIsMemoryBlock' as _CrtIsMemoryBlock:dword
;        extrn '__imp___CrtIsValidHeapPointer' as _CrtIsValidHeapPointer:dword
;        extrn '__imp___CrtIsValidPointer' as _CrtIsValidPointer:dword
;        extrn '__imp___CrtMemCheckpoint' as _CrtMemCheckpoint:dword
;        extrn '__imp___CrtMemDifference' as _CrtMemDifference:dword
;        extrn '__imp___CrtMemDumpAllObjectsSince' as _CrtMemDumpAllObjectsSince:dword
;        extrn '__imp___CrtMemDumpStatistics' as _CrtMemDumpStatistics:dword
;        extrn '__imp___CrtReportBlockType' as _CrtReportBlockType:dword
;        extrn '__imp___CrtSetAllocHook' as _CrtSetAllocHook:dword
;        extrn '__imp___CrtSetBreakAlloc' as _CrtSetBreakAlloc:dword
;        extrn '__imp___CrtSetDbgBlockType' as _CrtSetDbgBlockType:dword
;        extrn '__imp___CrtSetDbgFlag' as _CrtSetDbgFlag:dword
;        extrn '__imp___CrtSetDumpClient' as _CrtSetDumpClient:dword
;        extrn '__imp___CrtSetReportFile' as _CrtSetReportFile:dword
;        extrn '__imp___CrtSetReportHook' as _CrtSetReportHook:dword
;        extrn '__imp___CrtSetReportHook2' as _CrtSetReportHook2:dword
;        extrn '__imp___CrtSetReportMode' as _CrtSetReportMode:dword
;    end if
;    extrn '__imp___cscanf' as _cscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cscanf_l' as _cscanf_l:dword
;        extrn '__imp___cscanf_s' as _cscanf_s:dword
;        extrn '__imp___cscanf_s_l' as _cscanf_s_l:dword
;        extrn '__imp___ctime32' as _ctime32:dword
;        extrn '__imp___ctime32_s' as _ctime32_s:dword
;    end if
;    extrn '__imp___ctime64' as _ctime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ctime64_s' as _ctime64_s:dword
;    end if
;    extrn '__imp___ctype' as _ctype:dword
;    extrn '__imp___cwait' as _cwait:dword
;    extrn '__imp___cwprintf' as _cwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cwprintf_l' as _cwprintf_l:dword
;        extrn '__imp___cwprintf_p' as _cwprintf_p:dword
;        extrn '__imp___cwprintf_p_l' as _cwprintf_p_l:dword
;        extrn '__imp___cwprintf_s' as _cwprintf_s:dword
;        extrn '__imp___cwprintf_s_l' as _cwprintf_s_l:dword
;    end if
;    extrn '__imp___cwscanf' as _cwscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___cwscanf_l' as _cwscanf_l:dword
;        extrn '__imp___cwscanf_s' as _cwscanf_s:dword
;        extrn '__imp___cwscanf_s_l' as _cwscanf_s_l:dword
;    end if
;    extrn '__imp___CxxThrowException' as _CxxThrowException:dword
;    extrn '__imp___daylight' as _daylight:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___difftime32' as _difftime32:dword
;        extrn '__imp___difftime64' as _difftime64:dword
;    end if
;    extrn '__imp___dstbias' as _dstbias:dword
;    extrn '__imp___dup' as _dup:dword
;    extrn '__imp___dup2' as _dup2:dword
;    extrn '__imp___ecvt' as _ecvt:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ecvt_s' as _ecvt_s:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___EH_prolog' as _EH_prolog:dword
;    end if
;    extrn '__imp___endthread' as _endthread:dword
;    extrn '__imp___endthreadex' as _endthreadex:dword
;    extrn '__imp___environ' as _environ:dword
;    extrn '__imp___eof' as _eof:dword
;    extrn '__imp___errno' as _errno:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___except_handler2' as _except_handler2:dword
;        extrn '__imp___except_handler3' as _except_handler3:dword
;        extrn '__imp___except_handler4_common' as _except_handler4_common:dword
;    end if
;    extrn '__imp___execl' as _execl:dword
;    extrn '__imp___execle' as _execle:dword
;    extrn '__imp___execlp' as _execlp:dword
;    extrn '__imp___execlpe' as _execlpe:dword
;    extrn '__imp___execv' as _execv:dword
;    extrn '__imp___execve' as _execve:dword
;    extrn '__imp___execvp' as _execvp:dword
;    extrn '__imp___execvpe' as _execvpe:dword
;    extrn '__imp___exit' as _exit:dword
;    extrn '__imp___expand' as _expand:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___expand_dbg' as _expand_dbg:dword
;    end if
;    extrn '__imp___fcloseall' as _fcloseall:dword
;    extrn '__imp___fcvt' as _fcvt:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___fcvt_s' as _fcvt_s:dword
;    end if
;    extrn '__imp___fdopen' as _fdopen:dword
;    extrn '__imp___fgetchar' as _fgetchar:dword
;    extrn '__imp___fgetwchar' as _fgetwchar:dword
;    extrn '__imp___filbuf' as _filbuf:dword
;    extrn '__imp___fileinfo' as _fileinfo:dword
;    extrn '__imp___filelength' as _filelength:dword
;    extrn '__imp___filelengthi64' as _filelengthi64:dword
;    extrn '__imp___fileno' as _fileno:dword
;    extrn '__imp___findclose' as _findclose:dword
;    extrn '__imp___findfirst' as _findfirst:dword
;    extrn '__imp___findfirst64' as _findfirst64:dword
;    extrn '__imp___findfirsti64' as _findfirsti64:dword
;    extrn '__imp___findnext' as _findnext:dword
;    extrn '__imp___findnext64' as _findnext64:dword
;    extrn '__imp___findnexti64' as _findnexti64:dword
;    extrn '__imp___finite' as _finite:dword
;    extrn '__imp___finitef' as _finitef:dword
;    extrn '__imp___flsbuf' as _flsbuf:dword
;    extrn '__imp___flushall' as _flushall:dword
;    extrn '__imp___fmode' as _fmode:dword
;    extrn '__imp___fpclass' as _fpclass:dword
;    extrn '__imp___fpclassf' as _fpclassf:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___fpieee_flt' as _fpieee_flt:dword
;    end if
;    extrn '__imp___fpreset' as _fpreset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___fprintf_l' as _fprintf_l:dword
;        extrn '__imp___fprintf_p' as _fprintf_p:dword
;        extrn '__imp___fprintf_p_l' as _fprintf_p_l:dword
;        extrn '__imp___fprintf_s_l' as _fprintf_s_l:dword
;    end if
;    extrn '__imp___fputchar' as _fputchar:dword
;    extrn '__imp___fputwchar' as _fputwchar:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___free_dbg' as _free_dbg:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp___free_locale' as _free_locale:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___freea' as _freea:dword
;        extrn '__imp___freea_s' as _freea_s:dword
;        extrn '__imp___fscanf_l' as _fscanf_l:dword
;        extrn '__imp___fscanf_s_l' as _fscanf_s_l:dword
;        extrn '__imp___fseeki64' as _fseeki64:dword
;    end if
;    extrn '__imp___fsopen' as _fsopen:dword
;    extrn '__imp___fstat' as _fstat:dword
;    extrn '__imp___fstat64' as _fstat64:dword
;    extrn '__imp___fstati64' as _fstati64:dword
;    extrn '__imp___ftime' as _ftime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ftime32' as _ftime32:dword
;        extrn '__imp___ftime32_s' as _ftime32_s:dword
;    end if
;    extrn '__imp___ftime64' as _ftime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ftime64_s' as _ftime64_s:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___ftol' as _ftol:dword
;        extrn '__imp___ftol2' as _ftol2:dword
;        extrn '__imp___ftol2_sse' as _ftol2_sse:dword
;        extrn '__imp___ftol2_sse_excpt' as _ftol2_sse_excpt:dword
;    end if
;    extrn '__imp___fullpath' as _fullpath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___fullpath_dbg' as _fullpath_dbg:dword
;    end if
;    extrn '__imp___futime' as _futime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___futime32' as _futime32:dword
;    end if
;    extrn '__imp___futime64' as _futime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___fwprintf_l' as _fwprintf_l:dword
;        extrn '__imp___fwprintf_p' as _fwprintf_p:dword
;        extrn '__imp___fwprintf_p_l' as _fwprintf_p_l:dword
;        extrn '__imp___fwprintf_s_l' as _fwprintf_s_l:dword
;        extrn '__imp___fwscanf_l' as _fwscanf_l:dword
;        extrn '__imp___fwscanf_s_l' as _fwscanf_s_l:dword
;    end if
;    extrn '__imp___gcvt' as _gcvt:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___gcvt_s' as _gcvt_s:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp___get_current_locale' as _get_current_locale:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___get_doserrno' as _get_doserrno:dword
;        extrn '__imp___get_environ' as _get_environ:dword
;        extrn '__imp___get_errno' as _get_errno:dword
;        extrn '__imp___get_fileinfo' as _get_fileinfo:dword
;        extrn '__imp___get_fmode' as _get_fmode:dword
;    end if
;    extrn '__imp___get_heap_handle' as _get_heap_handle:dword
;    extrn '__imp___get_osfhandle' as _get_osfhandle:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___get_osplatform' as _get_osplatform:dword
;        extrn '__imp___get_osver' as _get_osver:dword
;        extrn '__imp___get_output_format' as _get_output_format:dword
;        extrn '__imp___get_pgmptr' as _get_pgmptr:dword
;    end if
;    extrn '__imp___get_sbh_threshold' as _get_sbh_threshold:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___get_wenviron' as _get_wenviron:dword
;        extrn '__imp___get_winmajor' as _get_winmajor:dword
;        extrn '__imp___get_winminor' as _get_winminor:dword
;        extrn '__imp___get_winver' as _get_winver:dword
;        extrn '__imp___get_wpgmptr' as _get_wpgmptr:dword
;    end if
;    extrn '__imp___getch' as _getch:dword
;    extrn '__imp___getche' as _getche:dword
;    extrn '__imp___getcwd' as _getcwd:dword
;    extrn '__imp___Getdays' as _Getdays:dword
;    extrn '__imp___getdcwd' as _getdcwd:dword
;    extrn '__imp___getdiskfree' as _getdiskfree:dword
;    if (NTDDI_VERSION <= NTDDI_VISTA)
;        extrn '__imp___getdllprocaddr' as _getdllprocaddr:dword
;    end if
;    extrn '__imp___getdrive' as _getdrive:dword
;    extrn '__imp___getdrives' as _getdrives:dword
;    extrn '__imp___getmaxstdio' as _getmaxstdio:dword
;    extrn '__imp___getmbcp' as _getmbcp:dword
;    extrn '__imp___Getmonths' as _Getmonths:dword
;    extrn '__imp___getpid' as _getpid:dword
;    extrn '__imp___getsystime' as _getsystime:dword
;    extrn '__imp___Gettnames' as _Gettnames:dword
;    extrn '__imp___getw' as _getw:dword
;    extrn '__imp___getwch' as _getwch:dword
;    extrn '__imp___getwche' as _getwche:dword
;    extrn '__imp___getws' as _getws:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___global_unwind2' as _global_unwind2:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___gmtime32' as _gmtime32:dword
;        extrn '__imp___gmtime32_s' as _gmtime32_s:dword
;    end if
;    extrn '__imp___gmtime64' as _gmtime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___gmtime64_s' as _gmtime64_s:dword
;    end if
;    if (NTDDI_VERSION <= NTDDI_VISTA)
;    extrn '__imp___heapadd' as _heapadd:dword
;    end if
;    extrn '__imp___heapchk' as _heapchk:dword
;    extrn '__imp___heapmin' as _heapmin:dword
;    extrn '__imp___heapset' as _heapset:dword
;    if (NTDDI_VERSION <= NTDDI_VISTA)
;        extrn '__imp___heapused' as _heapused:dword
;    end if
;    extrn '__imp___heapwalk' as _heapwalk:dword
;    extrn '__imp___HUGE' as _HUGE:dword
;    extrn '__imp___hypot' as _hypot:dword
;    extrn '__imp___hypotf' as _hypotf:dword
;    extrn '__imp___i64toa' as _i64toa:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___i64toa_s' as _i64toa_s:dword
;    end if
;    extrn '__imp___i64tow' as _i64tow:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___i64tow_s' as _i64tow_s:dword
;    end if
;    extrn '__imp___initterm' as _initterm:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___initterm_e' as _initterm_e:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___inp' as _inp:dword
;        extrn '__imp___inpd' as _inpd:dword
;        extrn '__imp___inpw' as _inpw:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___invalid_parameter' as _invalid_parameter:dword
;    end if
;    extrn '__imp___iob' as _iob:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___isalnum_l' as _isalnum_l:dword
;        extrn '__imp___isalpha_l' as _isalpha_l:dword
;    end if
;    extrn '__imp___isatty' as _isatty:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___iscntrl_l' as _iscntrl_l:dword
;    end if
;    extrn '__imp___isctype' as _isctype:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___isctype_l' as _isctype_l:dword
;        extrn '__imp___isdigit_l' as _isdigit_l:dword
;        extrn '__imp___isgraph_l' as _isgraph_l:dword
;        extrn '__imp___isleadbyte_l' as _isleadbyte_l:dword
;        extrn '__imp___islower_l' as _islower_l:dword
;    end if
;    extrn '__imp___ismbbalnum' as _ismbbalnum:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbalnum_l' as _ismbbalnum_l:dword
;    end if
;    extrn '__imp___ismbbalpha' as _ismbbalpha:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbalpha_l' as _ismbbalpha_l:dword
;    end if
;    extrn '__imp___ismbbgraph' as _ismbbgraph:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbgraph_l' as _ismbbgraph_l:dword
;    end if
;    extrn '__imp___ismbbkalnum' as _ismbbkalnum:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbkalnum_l' as _ismbbkalnum_l:dword
;    end if
;    extrn '__imp___ismbbkana' as _ismbbkana:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbkana_l' as _ismbbkana_l:dword
;    end if
;    extrn '__imp___ismbbkprint' as _ismbbkprint:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbkprint_l' as _ismbbkprint_l:dword
;    end if
;    extrn '__imp___ismbbkpunct' as _ismbbkpunct:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbkpunct_l' as _ismbbkpunct_l:dword
;    end if
;    extrn '__imp___ismbblead' as _ismbblead:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbblead_l' as _ismbblead_l:dword
;    end if
;    extrn '__imp___ismbbprint' as _ismbbprint:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbprint_l' as _ismbbprint_l:dword
;    end if
;    extrn '__imp___ismbbpunct' as _ismbbpunct:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbpunct_l' as _ismbbpunct_l:dword
;    end if
;    extrn '__imp___ismbbtrail' as _ismbbtrail:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbbtrail_l' as _ismbbtrail_l:dword
;    end if
;    extrn '__imp___ismbcalnum' as _ismbcalnum:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcalnum_l' as _ismbcalnum_l:dword
;    end if
;    extrn '__imp___ismbcalpha' as _ismbcalpha:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcalpha_l' as _ismbcalpha_l:dword
;    end if
;    extrn '__imp___ismbcdigit' as _ismbcdigit:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcdigit_l' as _ismbcdigit_l:dword
;    end if
;    extrn '__imp___ismbcgraph' as _ismbcgraph:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcgraph_l' as _ismbcgraph_l:dword
;    end if
;    extrn '__imp___ismbchira' as _ismbchira:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbchira_l' as _ismbchira_l:dword
;    end if
;    extrn '__imp___ismbckata' as _ismbckata:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbckata_l' as _ismbckata_l:dword
;    end if
;    extrn '__imp___ismbcl0' as _ismbcl0:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcl0_l' as _ismbcl0_l:dword
;    end if
;    extrn '__imp___ismbcl1' as _ismbcl1:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcl1_l' as _ismbcl1_l:dword
;    end if
;    extrn '__imp___ismbcl2' as _ismbcl2:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcl2_l' as _ismbcl2_l:dword
;    end if
;    extrn '__imp___ismbclegal' as _ismbclegal:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbclegal_l' as :dword
;    end if
;    extrn '__imp___ismbclower' as _ismbclower:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbclower_l' as :dword
;    end if
;    extrn '__imp___ismbcprint' as _ismbcprint:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcprint_l' as _ismbcprint_l:dword
;    end if
;    extrn '__imp___ismbcpunct' as _ismbcpunct:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcpunct_l' as _ismbcpunct_l:dword
;    end if
;    extrn '__imp___ismbcspace' as _ismbcspace:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcspace_l' as _ismbcspace_l:dword
;    end if
;    extrn '__imp___ismbcsymbol' as _ismbcsymbol:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcsymbol_l' as _ismbcsymbol_l:dword
;    end if
;    extrn '__imp___ismbcupper' as _ismbcupper:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbcupper_l' as _ismbcupper_l:dword
;    end if
;    extrn '__imp___ismbslead' as _ismbslead:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbslead_l' as _ismbslead_l:dword
;    end if
;    extrn '__imp___ismbstrail' as _ismbstrail:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ismbstrail_l' as _ismbstrail_l:dword
;    end if
;    extrn '__imp___isnan' as _isnan:dword
;    extrn '__imp___isnanf' as _isnanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___isprint_l' as _isprint_l:dword
;        extrn '__imp___isspace_l' as _isspace_l:dword
;        extrn '__imp___isupper_l' as _isupper_l:dword
;        extrn '__imp___iswalnum_l' as _iswalnum_l:dword
;        extrn '__imp___iswalpha_l' as _iswalpha_l:dword
;        extrn '__imp___iswcntrl_l' as _iswcntrl_l:dword
;        extrn '__imp___iswctype_l' as _iswctype_l:dword
;        extrn '__imp___iswdigit_l' as _iswdigit_l:dword
;        extrn '__imp___iswgraph_l' as _iswgraph_l:dword
;        extrn '__imp___iswlower_l' as _iswlower_l:dword
;        extrn '__imp___iswprint_l' as _iswprint_l:dword
;        extrn '__imp__swpunct_l' as _iswpunct_l:dword
;        extrn '__imp__swspace_l' as _iswspace_l:dword
;        extrn '__imp___iswupper_l' as _iswupper_l:dword
;        extrn '__imp___iswxdigit_l' as _iswxdigit_l:dword
;        extrn '__imp___isxdigit_l' as _isxdigit_l:dword
;    end if
;    extrn '__imp___itoa' as _itoa:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___itoa_s' as _itoa_s:dword
;    end if
;    extrn '__imp___itow' as _itow:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___itow_s' as _itow_s:dword
;    end if
;    extrn '__imp___j0' as _j0:dword
;    extrn '__imp___j1' as _j1:dword
;    extrn '__imp___jn' as _jn:dword
;    extrn '__imp___kbhit' as _kbhit:dword
;    extrn '__imp___lfind' as _lfind:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___lfind_s' as _lfind_s:dword
;    end if
;    if (NTDDI_VERSION <= NTDDI_VISTA)
;        extrn '__imp___loaddll' as _loaddll:dword
;    end if
;    extrn '__imp___local_unwind' as _local_unwind:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___local_unwind2' as _local_unwind2:dword
;        extrn '__imp___local_unwind4' as _local_unwind4:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___localtime32' as _localtime32:dword
;        extrn '__imp___localtime32_s' as _localtime32_s:dword
;    end if
;    extrn '__imp___localtime64' as _localtime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___localtime64_s' as _localtime64_s:dword
;    end if
;    extrn '__imp___lock' as _lock:dword
;    extrn '__imp___locking' as _locking:dword
;    extrn '__imp___logb' as _logb:dword
;    extrn '__imp___logbf' as _logbf:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___longjmpex' as _longjmpex:dword
;    end if
;    extrn '__imp___lrotl' as _lrotl:dword
;    extrn '__imp___lrotr' as _lrotr:dword
;    extrn '__imp___lsearch' as _lsearch:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___lsearch_s' as _lsearch_s:dword
;    end if
;    extrn '__imp___lseek' as _lseek:dword
;    extrn '__imp___lseeki64' as _lseeki64:dword
;    extrn '__imp___ltoa' as _ltoa:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ltoa_s' as _ltoa_s:dword
;    end if
;    extrn '__imp___ltow' as _ltow:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ltow_s' as _ltow_s:dword
;    end if
;    extrn '__imp___makepath' as _makepath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___makepath_s' as _makepath_s:dword
;        extrn '__imp___malloc_dbg' as _malloc_dbg:dword
;    end if
;    extrn '__imp___mbbtombc' as _mbbtombc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbbtombc_l' as _mbbtombc_l:dword
;    end if
;    extrn '__imp___mbbtype' as _mbbtype:dword
;    extrn '__imp___mbcasemap' as _mbcasemap:dword                                                    
;    extrn '__imp___mbccpy' as _mbccpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbccpy_l' as _mbccpy_l:dword
;        extrn '__imp___mbccpy_s' as _mbccpy_s:dword
;        extrn '__imp___mbccpy_s_l' as _mbccpy_s_l:dword
;    end if
;    extrn '__imp___mbcjistojms' as _mbcjistojms:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbcjistojms_l' as _mbcjistojms_l:dword
;    end if
;    extrn '__imp___mbcjmstojis' as _mbcjmstojis:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbcjmstojis_l' as _mbcjmstojis_l:dword
;    end if
;    extrn '__imp___mbclen' as _mbclen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbclen_l' as _mbclen_l:dword                                                    
;    end if
;    extrn '__imp___mbctohira' as _mbctohira:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbctohira_l' as _mbctohira_l:dword
;    end if
;    extrn '__imp___mbctokata' as _mbctokata:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbctokata_l' as _mbctokata_l:dword
;    end if
;    extrn '__imp___mbctolower' as _mbctolower:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbctolower_l' as _mbctolower_l:dword
;    end if
;    extrn '__imp___mbctombb' as _mbctombb:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbctombb_l' as _mbctombb_l:dword
;    end if
;    extrn '__imp___mbctoupper' as _mbctoupper:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbctoupper_l' as _mbctoupper_l:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mblen_l' as _mblen_l:dword
;    end if
;    extrn '__imp___mbsbtype' as _mbsbtype:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsbtype_l' as _mbsbtype_l:dword
;    end if
;    extrn '__imp___mbscat' as _mbscat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbscat_s' as _mbscat_s:dword
;        extrn '__imp___mbscat_s_l' as _mbscat_s_l:dword
;    end if
;    extrn '__imp___mbschr' as _mbschr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbschr_l' as _mbschr_l:dword
;    end if
;    extrn '__imp___mbscmp' as _mbscmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbscmp_l' as _mbscmp_l:dword
;    end if
;    extrn '__imp___mbscoll' as _mbscoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbscoll_l' as _mbscoll_l:dword
;    end if
;    extrn '__imp___mbscpy' as _mbscpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbscpy_s' as _mbscpy_s:dword
;        extrn '__imp___mbscpy_s_l' as _mbscpy_s_l:dword
;    end if
;    extrn '__imp___mbscspn' as _mbscspn:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbscspn_l' as _mbscspn_l:dword
;    end if
;    extrn '__imp___mbsdec' as _mbsdec:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsdec_l' as _mbsdec_l:dword
;    end if
;    extrn '__imp___mbsdup' as _mbsdup:dword
;    extrn '__imp___mbsicmp' as _mbsicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsicmp_l' as _mbsicmp_l:dword
;    end if
;    extrn '__imp___mbsicoll' as _mbsicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsicoll_l' as _mbsicoll_l:dword
;    end if
;    extrn '__imp___mbsinc' as _mbsinc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsinc_l' as _mbsinc_l:dword
;    end if
;    extrn '__imp___mbslen' as _mbslen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbslen_l' as _mbslen_l:dword
;    end if
;    extrn '__imp___mbslwr' as _mbslwr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbslwr_l' as _mbslwr_l:dword
;        extrn '__imp___mbslwr_s' as _mbslwr_s:dword
;        extrn '__imp___mbslwr_s_l' as _mbslwr_s_l:dword
;    end if
;    extrn '__imp___mbsnbcat' as _mbsnbcat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbcat_l' as _mbsnbcat_l:dword
;        extrn '__imp___mbsnbcat_s' as _mbsnbcat_s:dword
;        extrn '__imp___mbsnbcat_s_l' as _mbsnbcat_s_l:dword
;    end if
;    extrn '__imp___mbsnbcmp' as _mbsnbcmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbcmp_l' as _mbsnbcmp_l:dword
;    end if
;    extrn '__imp___mbsnbcnt' as _mbsnbcnt:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbcnt_l' as _mbsnbcnt_l:dword
;    end if
;    extrn '__imp___mbsnbcoll' as _mbsnbcoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbcoll_l' as _mbsnbcoll_l:dword
;    end if
;    extrn '__imp___mbsnbcpy' as _mbsnbcpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbcpy_l' as _mbsnbcpy_l:dword
;        extrn '__imp___mbsnbcpy_s' as _mbsnbcpy_s:dword
;        extrn '__imp___mbsnbcpy_s_l' as _mbsnbcpy_s_l:dword
;    end if
;    extrn '__imp___mbsnbicmp' as _mbsnbicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbicmp_l' as _mbsnbicmp_l:dword
;    end if
;    extrn '__imp___mbsnbicoll' as _mbsnbicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbicoll_l' as _mbsnbicoll_l:dword
;    end if
;    extrn '__imp___mbsnbset' as _mbsnbset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnbset_l' as _mbsnbset_l:dword
;        extrn '__imp___mbsnbset_s' as _mbsnbset_s:dword
;        extrn '__imp___mbsnbset_s_l' as _mbsnbset_s_l:dword
;    end if
;    extrn '__imp___mbsncat' as _mbsncat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsncat_l' as _mbsncat_l:dword
;        extrn '__imp___mbsncat_s' as _mbsncat_s:dword
;        extrn '__imp___mbsncat_s_l' as _mbsncat_s_l:dword
;    end if
;    extrn '__imp___mbsnccnt' as _mbsnccnt:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnccnt_l' as _mbsnccnt_l:dword
;    end if
;    extrn '__imp___mbsncmp' as _mbsncmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsncmp_l' as _mbsncmp_l:dword
;    end if
;    extrn '__imp___mbsncoll' as _mbsncoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsncoll_l' as _mbsncoll_l:dword
;    end if
;    extrn '__imp___mbsncpy' as _mbsncpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsncpy_l' as _mbsncpy_l:dword
;        extrn '__imp___mbsncpy_s' as _mbsncpy_s:dword
;        extrn '__imp___mbsncpy_s_l' as _mbsncpy_s_l:dword
;    end if
;    extrn '__imp___mbsnextc' as _mbsnextc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnextc_l' as _mbsnextc_l:dword
;    end if
;    extrn '__imp___mbsnicmp' as _mbsnicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnicmp_l' as _mbsnicmp_l:dword
;    end if
;    extrn '__imp___mbsnicoll' as _mbsnicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnicoll_l' as _mbsnicoll_l:dword
;    end if
;    extrn '__imp___mbsninc' as _mbsninc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsninc_l' as _mbsninc_l:dword
;    end if
;    extrn '__imp___mbsnlen' as _mbsnlen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnlen_l' as _mbsnlen_l:dword
;    end if
;    extrn '__imp___mbsnset' as _mbsnset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsnset_l' as _mbsnset_l:dword
;        extrn '__imp___mbsnset_s' as _mbsnset_s:dword
;        extrn '__imp___mbsnset_s_l' as_mbsnset_s_l :dword
;    end if
;    extrn '__imp___mbspbrk' as _mbspbrk:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbspbrk_l' as _mbspbrk_l:dword
;    end if
;    extrn '__imp___mbsrchr' as _mbsrchr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsrchr_l' as :dword
;    end if
;    extrn '__imp___mbsrev' as _mbsrev:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsrev_l' as _mbsrev_l:dword
;    end if
;    extrn '__imp___mbsset' as _mbsset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsset_l' as _mbsset_l:dword
;        extrn '__imp___mbsset_s' as _mbsset_s:dword
;        extrn '__imp___mbsset_s_l' as _mbsset_s_l:dword
;    end if
;    extrn '__imp___mbsspn' as _mbsspn:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsspn_l' as _mbsspn_l:dword
;    end if
;    extrn '__imp___mbsspnp' as _mbsspnp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsspnp_l' as _mbsspnp_l:dword
;    end if
;    extrn '__imp___mbsstr' as _mbsstr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsstr_l' as _mbsstr_l:dword
;    end if
;    extrn '__imp___mbstok' as _mbstok:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbstok_l' as _mbstok_l:dword
;        extrn '__imp___mbstok_s' as _mbstok_s:dword
;        extrn '__imp___mbstok_s_l' as _mbstok_s_l:dword
;        extrn '__imp___mbstowcs_l' as _mbstowcs_l:dword
;        extrn '__imp___mbstowcs_s_l' as _mbstowcs_s_l:dword
;    end if
;    extrn '__imp___mbstrlen' as _mbstrlen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbstrlen_l' as _mbstrlen_l:dword
;    end if
;    extrn '__imp___mbstrnlen' as _mbstrnlen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbstrnlen_l' as :dword
;    end if
;    extrn '__imp___mbsupr' as _mbsupr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mbsupr_l' as _mbsupr_l:dword
;        extrn '__imp___mbsupr_s' as _mbsupr_s:dword
;        extrn '__imp___mbsupr_s_l' as _mbsupr_s_l:dword
;        extrn '__imp___mbtowc_l' as _mbtowc_l:dword
;    end if
;    extrn '__imp___memccpy' as _memccpy:dword
;    extrn '__imp___memicmp' as _memicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___memicmp_l' as _memicmp_l:dword
;    end if
;    extrn '__imp___mkdir' as _mkdir:dword
;    extrn '__imp___mkgmtime' as _mkgmtime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mkgmtime32' as _mkgmtime32:dword
;    end if
;    extrn '__imp___mkgmtime64' as _mkgmtime64:dword
;    extrn '__imp___mktemp' as _mktemp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___mktemp_s' as _mktemp_s:dword
;        extrn '__imp___mktime32' as _mktime32:dword
;    end if
;    extrn '__imp___mktime64' as _mktime64:dword
;    extrn '__imp___msize' as _msize:dword
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;        extrn '__imp___msize_dbg' as _msize_dbg:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___msize_debug' as _msize_debug:dword
;    end if
;    extrn '__imp___nextafter' as _nextafter:dword
;    extrn '__imp___nextafterf' as _nextafterf:dword
;    extrn '__imp___onexit' as _onexit:dword
;    extrn '__imp___open' as _open:dword
;    extrn '__imp___open_osfhandle' as _open_osfhandle:dword
;    extrn '__imp___osplatform' as _osplatform:dword
;    extrn '__imp___osver' as _osver:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___outp' as _outp:dword
;        extrn '__imp___outpd' as _outpd:dword
;        extrn '__imp___outpw' as _outpw:dword
;    end if
;    extrn '__imp___pclose' as _pclose:dword
;    extrn '__imp___pctype' as _pctype:dword
;    extrn '__imp___pgmptr' as _pgmptr:dword
;    extrn '__imp___pipe' as _pipe:dword
;    extrn '__imp___popen' as _popen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___printf_l' as _printf_l:dword
;        extrn '__imp___printf_p' as _printf_p:dword
;        extrn '__imp___printf_p_l' as _printf_p_l:dword
;        extrn '__imp___printf_s_l' as _printf_s_l:dword
;    end if
;    extrn '__imp___purecall' as _purecall:dword
;    extrn '__imp___putch' as _putch:dword
;    extrn '__imp___putenv' as _putenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___putenv_s' as _putenv_s:dword
;    end if
;    extrn '__imp___putw' as _putw:dword
;    extrn '__imp___putwch' as _putwch:dword
;    extrn '__imp___putws' as _putws:dword
;    extrn '__imp___pwctype' as _pwctype:dword
;    extrn '__imp___read' as _read:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___realloc_dbg' as _realloc_dbg:dword
;    end if
;    extrn '__imp___resetstkoflw' as _resetstkoflw:dword
;    extrn '__imp___rmdir' as _rmdir:dword
;    extrn '__imp___rmtmp' as _rmtmp:dword
;    extrn '__imp___rotl' as _rotl:dword
;    extrn '__imp___rotl64' as _rotl64:dword
;    extrn '__imp___rotr' as _rotr:dword
;    extrn '__imp___rotr64' as _rotr64:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___safe_fdiv' as _safe_fdiv:dword
;        extrn '__imp___safe_fdivr' as _safe_fdivr:dword
;        extrn '__imp___safe_fprem' as _safe_fprem:dword
;        extrn '__imp___safe_fprem1' as _safe_fprem1:dword
;    end if
;    extrn '__imp___scalb' as _scalb:dword
;    extrn '__imp___scalbf' as _scalbf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___scanf_l' as _scanf_l:dword
;        extrn '__imp___scanf_s_l' as _scanf_s_l:dword
;    end if
;    extrn '__imp___scprintf' as _scprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___scprintf_l' as _scprintf_l:dword
;        extrn '__imp___scprintf_p_l' as _scprintf_p_l:dword
;    end if
;    extrn '__imp___scwprintf' as _scwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___scwprintf_l' as _scwprintf_l:dword
;        extrn '__imp___scwprintf_p_l' as _scwprintf_p_l:dword
;    end if
;    extrn '__imp___searchenv' as _searchenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___searchenv_s' as _searchenv_s:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___seh_longjmp_unwind' as _seh_longjmp_unwind:dword
;        extrn '__imp___seh_longjmp_unwind4' as _seh_longjmp_unwind4:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___set_controlfp' as _set_controlfp:dword
;        extrn '__imp___set_doserrno' as _set_doserrno:dword
;        extrn '__imp___set_errno' as _set_errno:dword
;    end if
;    extrn '__imp___set_error_mode' as _set_error_mode:dword
;    extrn '__imp___set_fileinfo' as _set_fileinfo:dword
;    extrn '__imp___set_fmode' as _set_fmode:dword
;    extrn '__imp___set_output_format' as _set_output_format:dword
;    extrn '__imp___set_sbh_threshold' as _set_sbh_threshold:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___set_SSE2_enable' as _set_SSE2_enable:dword
;    end if
;    extrn '__imp___seterrormode' as _seterrormode:dword
;    extrn '__imp___setjmp' as _setjmp:dword
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp___setjmp3' as _setjmp3:dword
;    end if
;    extrn '__imp___setjmpex' as _setjmpex:dword
;    extrn '__imp___setmaxstdio' as _setmaxstdio:dword
;    extrn '__imp___setmbcp' as _setmbcp:dword
;    extrn '__imp___setmode' as _setmode:dword
;    extrn '__imp___setsystime' as _setsystime:dword
;    extrn '__imp___sleep' as _sleep:dword
;    extrn '__imp___snprintf' as _snprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___snprintf_c' as _snprintf_c:dword
;        extrn '__imp___snprintf_c_l' as _snprintf_c_l:dword
;        extrn '__imp___snprintf_l' as _snprintf_l:dword
;        extrn '__imp___snprintf_s' as _snprintf_s:dword
;        extrn '__imp___snprintf_s_l' as _snprintf_s_l:dword
;    end if
;    extrn '__imp___snscanf' as _snscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___snscanf_l' as _snscanf_l:dword
;        extrn '__imp___snscanf_s' as _snscanf_s:dword
;        extrn '__imp___snscanf_s_l' as _snscanf_s_l:dword
;    end if
;    extrn '__imp___snwprintf' as _snwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___snwprintf_l' as _snwprintf_l:dword
;        extrn '__imp___snwprintf_s' as _snwprintf_s:dword
;        extrn '__imp___snwprintf_s_l' as _snwprintf_s_l:dword
;    end if
;    extrn '__imp___snwscanf' as _snwscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___snwscanf_l' as _snwscanf_l:dword
;        extrn '__imp___snwscanf_s' as _snwscanf_s:dword
;        extrn '__imp___snwscanf_s_l' as _snwscanf_s_l:dword
;    end if
;    extrn '__imp___sopen' as _sopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___sopen_s' as _sopen_s:dword
;    end if
;    extrn '__imp___spawnl' as _spawnl:dword
;    extrn '__imp___spawnle' as _spawnle:dword
;    extrn '__imp___spawnlp' as _spawnlp:dword
;    extrn '__imp___spawnlpe' as _spawnlpe:dword
;    extrn '__imp___spawnv' as _spawnv:dword
;    extrn '__imp___spawnve' as _spawnve:dword
;    extrn '__imp___spawnvp' as _spawnvp:dword
;    extrn '__imp___spawnvpe' as _spawnvpe:dword
;    extrn '__imp___splitpath' as _splitpath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___splitpath_s' as _splitpath_s:dword
;        extrn '__imp___sprintf_l' as _sprintf_l:dword
;        extrn '__imp___sprintf_p_l' as _sprintf_p_l:dword
;        extrn '__imp___sprintf_s_l' as _sprintf_s_l:dword
;        extrn '__imp___sscanf_l' as _sscanf_l:dword
;        extrn '__imp___sscanf_s_l' as _sscanf_s_l:dword
;    end if
;    extrn '__imp___stat' as _stat:dword
;    extrn '__imp___stat64' as _stat64:dword
;    extrn '__imp___stati64' as _stati64:dword
;    extrn '__imp___statusfp' as _statusfp:dword
;    extrn '__imp___strcmpi' as _strcmpi:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strcoll_l' as _strcoll_l:dword
;    end if
;    extrn '__imp___strdate' as _strdate:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strdate_s' as _strdate_s:dword
;    end if
;    extrn '__imp___strdup' as _strdup:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strdup_dbg' as _strdup_dbg:dword
;    end if
;    extrn '__imp___strerror' as _strerror:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strerror_s' as _strerror_s:dword
;    end if
;    extrn '__imp___Strftime' as _Strftime:dword
;    extrn '__imp___stricmp' as _stricmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___stricmp_l' as _stricmp_l:dword
;    end if
;    extrn '__imp___stricoll' as _stricoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___stricoll_l' as _stricoll_l:dword
;    end if
;    extrn '__imp___strlwr' as _strlwr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strlwr_l' as _strlwr_l:dword
;        extrn '__imp___strlwr_s' as _strlwr_s:dword
;        extrn '__imp___strlwr_s_l' as _strlwr_s_l:dword
;    end if
;    extrn '__imp___strncoll' as _strncoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strncoll_l' as _strncoll_l:dword
;    end if
;    extrn '__imp___strnicmp' as _strnicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strnicmp_l' as _strnicmp_l:dword
;    end if
;    extrn '__imp___strnicoll' as _strnicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strnicoll_l' as _strnicoll_l:dword
;    end if
;    extrn '__imp___strnset' as _strnset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strnset_s' as _strnset_s:dword
;    end if
;    extrn '__imp___strrev' as _strrev:dword
;    extrn '__imp___strset' as _strset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strset_s' as _strset_s:dword
;    end if
;    extrn '__imp___strtime' as _strtime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strtime_s' as _strtime_s:dword
;        extrn '__imp___strtod_l' as _strtod_l:dword
;    end if
;    extrn '__imp___strtoi64' as _strtoi64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strtoi64_l' as _strtoi64_l:dword
;        extrn '__imp___strtol_l' as _strtol_l:dword
;    end if
;    extrn '__imp___strtoui64' as _strtoui64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strtoui64_l' as _strtoui64_l:dword
;        extrn '__imp___strtoul_l' as _strtoul_l:dword
;    end if
;    extrn '__imp___strupr' as _strupr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___strupr_l' as _strupr_l:dword
;        extrn '__imp___strupr_s' as _strupr_s:dword
;        extrn '__imp___strupr_s_l' as _strupr_s_l:dword
;        extrn '__imp___strxfrm_l' as _strxfrm_l:dword
;    end if
;    extrn '__imp___swab' as _swab:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___swprintf' as _swprintf:dword
;        extrn '__imp___swprintf_c' as _swprintf_c:dword
;        extrn '__imp___swprintf_c_l' as _swprintf_c_l:dword
;        extrn '__imp___swprintf_p_l' as _swprintf_p_l:dword
;        extrn '__imp___swprintf_s_l' as _swprintf_s_l:dword
;        extrn '__imp___swscanf_l' as _swscanf_l:dword
;        extrn '__imp___swscanf_s_l' as _swscanf_s_l:dword
;    end if
;    extrn '__imp___sys_errlist' as _sys_errlist:dword
;    extrn '__imp___sys_nerr' as _sys_nerr:dword
;    extrn '__imp___tell' as _tell:dword
;    extrn '__imp___telli64' as _telli64:dword
;    extrn '__imp___tempnam' as _tempnam:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___tempnam_dbg' as _tempnam_dbg:dword
;        extrn '__imp___time32' as _time32:dword
;    end if
;    extrn '__imp___time64' as _time64:dword
;    extrn '__imp___timezone' as _timezone:dword
;    extrn '__imp___tolower' as _tolower:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___tolower_l' as _tolower_l:dword
;    end if
;    extrn '__imp___toupper' as _toupper:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___toupper_l' as _toupper_l:dword
;        extrn '__imp___towlower_l' as _towlower_l:dword
;        extrn '__imp___towupper_l' as _towupper_l:dword
;    end if
;    extrn '__imp___tzname' as _tzname:dword
;    extrn '__imp___tzset' as _tzset:dword
;    extrn '__imp___ui64toa' as _ui64toa:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ui64toa_s' as _ui64toa_s:dword
;    end if
;    extrn '__imp___ui64tow' as _ui64tow:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ui64tow_s' as _ui64tow_s:dword
;    end if
;    extrn '__imp___ultoa' as _ultoa:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ultoa_s' as _ultoa_s:dword
;    end if
;    extrn '__imp___ultow' as _ultow:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___ultow_s' as _ultow_s:dword
;    end if
;    extrn '__imp___umask' as _umask:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___umask_s' as _umask_s:dword
;    end if
;    extrn '__imp___ungetch' as _ungetch:dword
;    extrn '__imp___ungetwch' as _ungetwch:dword
;    extrn '__imp___unlink' as _unlink:dword
;    if (NTDDI_VERSION <= NTDDI_VISTA)
;        extrn '__imp___unloaddll' as _unloaddll:dword
;    end if
;    extrn '__imp___unlock' as _unlock:dword
;    extrn '__imp___utime' as _utime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___utime32' as _utime32:dword
;    end if
;    extrn '__imp___utime64' as _utime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___vcprintf' as _vcprintf:dword
;        extrn '__imp___vcprintf_l' as _vcprintf_l:dword
;        extrn '__imp___vcprintf_p' as _vcprintf_p:dword
;        extrn '__imp___vcprintf_p_l' as _vcprintf_p_l:dword
;        extrn '__imp___vcprintf_s' as _vcprintf_s:dword
;        extrn '__imp___vcprintf_s_l' as _vcprintf_s_l:dword
;        extrn '__imp___vcwprintf' as _vcwprintf:dword
;        extrn '__imp___vcwprintf_l' as _vcwprintf_l:dword
;        extrn '__imp___vcwprintf_p' as _vcwprintf_p:dword
;        extrn '__imp___vcwprintf_p_l' as _vcwprintf_p_l:dword
;        extrn '__imp___vcwprintf_s' as _vcwprintf_s:dword
;        extrn '__imp___vcwprintf_s_l' as _vcwprintf_s_l:dword
;        extrn '__imp___vfprintf_l' as _vfprintf_l:dword
;        extrn '__imp___vfprintf_p' as _vfprintf_p:dword
;        extrn '__imp___vfprintf_p_l' as _vfprintf_p_l:dword
;        extrn '__imp___vfprintf_s_l' as _vfprintf_s_l:dword
;        extrn '__imp___vfwprintf_l' as _vfwprintf_l:dword
;        extrn '__imp___vfwprintf_p' as _vfwprintf_p:dword
;        extrn '__imp___vfwprintf_p_l' as _vfwprintf_p_l:dword
;        extrn '__imp___vfwprintf_s_l' as _vfwprintf_s_l:dword
;        extrn '__imp___vprintf_l' as _vprintf_l:dword
;        extrn '__imp___vprintf_p' as _vprintf_p:dword
;        extrn '__imp___vprintf_p_l' as _vprintf_p_l:dword
;        extrn '__imp___vprintf_s_l' as _vprintf_s_l:dword
;    end if
;    extrn '__imp___vscprintf' as _vscprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___vscprintf_l' as _vscprintf_l:dword
;        extrn '__imp___vscprintf_p_l' as _vscprintf_p_l:dword
;    end if
;    extrn '__imp___vscwprintf' as _vscwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___vscwprintf_l' as _vscwprintf_l:dword
;        extrn '__imp___vscwprintf_p_l' as _vscwprintf_p_l:dword
;    end if
;    extrn '__imp___vsnprintf' as _vsnprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___vsnprintf_c' as _vsnprintf_c:dword
;        extrn '__imp___vsnprintf_c_l' as _vsnprintf_c_l:dword
;        extrn '__imp___vsnprintf_l' as _vsnprintf_l:dword
;        extrn '__imp___vsnprintf_s' as _vsnprintf_s:dword
;        extrn '__imp___vsnprintf_s_l' as _vsnprintf_s_l:dword
;    end if
;    extrn '__imp___vsnwprintf' as _vsnwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___vsnwprintf_l' as _vsnwprintf_l:dword
;        extrn '__imp___vsnwprintf_s' as _vsnwprintf_s:dword
;        extrn '__imp___vsnwprintf_s_l' as _vsnwprintf_s_l:dword
;        extrn '__imp___vsprintf_l' as _vsprintf_l:dword
;        extrn '__imp___vsprintf_p' as _vsprintf_p:dword
;        extrn '__imp___vsprintf_p_l' as _vsprintf_p_l:dword
;        extrn '__imp___vsprintf_s_l' as _vsprintf_s_l:dword
;        extrn '__imp___vswprintf' as _vswprintf:dword
;        extrn '__imp___vswprintf_c' as _vswprintf_c:dword
;        extrn '__imp___vswprintf_c_l' as _vswprintf_c_l:dword
;        extrn '__imp___vswprintf_l' as _vswprintf_l:dword
;        extrn '__imp___vswprintf_p_l' as _vswprintf_p_l:dword
;        extrn '__imp___vswprintf_s_l' as _vswprintf_s_l:dword
;        extrn '__imp___vwprintf_l' as _vwprintf_l:dword
;        extrn '__imp___vwprintf_p' as _vwprintf_p:dword
;        extrn '__imp___vwprintf_p_l' as _vwprintf_p_l:dword
;        extrn '__imp___vwprintf_s_l' as _vwprintf_s_l:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN10)
;        extrn '__imp___W_Getdays' as _W_Getdays:dword
;        extrn '__imp___W_Getmonths' as _W_Getmonths:dword
;        extrn '__imp___W_Gettnames' as _W_Gettnames:dword
;    end if
;    extrn '__imp___waccess' as _waccess:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___waccess_s' as _waccess_s:dword
;    end if
;    extrn '__imp___wasctime' as _wasctime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wasctime_s' as _wasctime_s:dword
;        extrn '__imp___wassert' as _wassert:dword
;    end if
;    extrn '__imp___wchdir' as _wchdir:dword
;    extrn '__imp___wchmod' as _wchmod:dword
;    extrn '__imp___wcmdln' as _wcmdln:dword
;    extrn '__imp___wcreat' as _wcreat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcscoll_l' as _wcscoll_l:dword
;    end if
;    extrn '__imp___wcsdup' as _wcsdup:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsdup_dbg' as _wcsdup_dbg:dword
;    end if
;    extrn '__imp___wcserror' as _wcserror:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcserror_s' as _wcserror_s:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN10)
;        extrn '__imp___Wcsftime' as _Wcsftime:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsftime_l' as _wcsftime_l:dword
;    end if
;    extrn '__imp___wcsicmp' as _wcsicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsicmp_l' as _wcsicmp_l:dword
;    end if
;    extrn '__imp___wcsicoll' as _wcsicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsicoll_l' as _wcsicoll_l:dword
;    end if
;    extrn '__imp___wcslwr' as _wcslwr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcslwr_l' as _wcslwr_l:dword
;        extrn '__imp___wcslwr_s' as _wcslwr_s:dword
;        extrn '__imp___wcslwr_s_l' as _wcslwr_s_l:dword
;    end if
;    extrn '__imp___wcsncoll' as _wcsncoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsncoll_l' as _wcsncoll_l:dword
;    end if
;    extrn '__imp___wcsnicmp' as _wcsnicmp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsnicmp_l' as _wcsnicmp_l:dword
;    end if
;    extrn '__imp___wcsnicoll' as _wcsnicoll:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsnicoll_l' as _wcsnicoll_l:dword
;    end if
;    extrn '__imp___wcsnset' as _wcsnset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsnset_s' as _wcsnset_s:dword
;    end if
;    extrn '__imp___wcsrev' as _wcsrev:dword
;    extrn '__imp___wcsset' as _wcsset:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsset_s' as _wcsset_s:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp___wcstod_l' as _wcstod_l:dword
;    end if
;    extrn '__imp___wcstoi64' as _wcstoi64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcstoi64_l' as _wcstoi64_l:dword
;        extrn '__imp___wcstol_l' as _wcstol_l:dword
;        extrn '__imp___wcstombs_l' as _wcstombs_l:dword
;        extrn '__imp___wcstombs_s_l' as _wcstombs_s_l:dword
;    end if
;    extrn '__imp___wcstoui64' as _wcstoui64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcstoui64_l' as _wcstoui64_l:dword
;        extrn '__imp___wcstoul_l' as _wcstoul_l:dword
;    end if
;    extrn '__imp___wcsupr' as _wcsupr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wcsupr_l' as _wcsupr_l:dword
;        extrn '__imp___wcsupr_s' as _wcsupr_s:dword
;        extrn '__imp___wcsupr_s_l' as _wcsupr_s_l:dword
;        extrn '__imp___wcsxfrm_l' as _wcsxfrm_l:dword
;    end if
;    extrn '__imp___wctime' as _wctime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wctime32' as _wctime32:dword
;        extrn '__imp___wctime32_s' as _wctime32_s:dword
;    end if
;    extrn '__imp___wctime64' as _wctime64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wctime64_s' as _wctime64_s:dword
;        extrn '__imp___wctomb_l' as _wctomb_l:dword
;        extrn '__imp___wctomb_s_l' as _wctomb_s_l:dword
;    end if
;    extrn '__imp___wctype' as _wctype:dword
;    extrn '__imp___wenviron' as _wenviron:dword
;    extrn '__imp___wexecl' as _wexecl:dword
;    extrn '__imp___wexecle' as _wexecle:dword
;    extrn '__imp___wexeclp' as _wexeclp:dword
;    extrn '__imp___wexeclpe' as _wexeclpe:dword
;    extrn '__imp___wexecv' as _wexecv:dword
;    extrn '__imp___wexecve' as _wexecve:dword
;    extrn '__imp___wexecvp' as _wexecvp:dword
;    extrn '__imp___wexecvpe' as _wexecvpe:dword
;    extrn '__imp___wfdopen' as _wfdopen:dword
;    extrn '__imp___wfindfirst' as _wfindfirst:dword
;    extrn '__imp___wfindfirst64' as _wfindfirst64:dword
;    extrn '__imp___wfindfirsti64' as _wfindfirsti64:dword
;    extrn '__imp___wfindnext' as _wfindnext:dword
;    extrn '__imp___wfindnext64' as _wfindnext64:dword
;    extrn '__imp___wfindnexti64' as _wfindnexti64:dword
;    extrn '__imp___wfopen' as _wfopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wfopen_s' as _wfopen_s:dword
;    end if
;    extrn '__imp___wfreopen' as _wfreopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wfreopen_s' as _wfreopen_s:dword
;    end if
;    extrn '__imp___wfsopen' as _wfsopen:dword
;    extrn '__imp___wfullpath' as _wfullpath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wfullpath_dbg' as _wfullpath_dbg:dword
;    end if
;    extrn '__imp___wgetcwd' as _wgetcwd:dword
;    extrn '__imp___wgetdcwd' as _wgetdcwd:dword
;    extrn '__imp___wgetenv' as _wgetenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wgetenv_s' as _wgetenv_s:dword
;    end if
;    extrn '__imp___winmajor' as _winmajor:dword
;    extrn '__imp___winminor' as _winminor:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___winput_s' as _winput_s:dword
;    end if
;    extrn '__imp___winver' as _winver:dword
;    extrn '__imp___wmakepath' as _wmakepath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wmakepath_s' as _wmakepath_s:dword
;    end if
;    extrn '__imp___wmkdir' as _wmkdir:dword
;    extrn '__imp___wmktemp' as _wmktemp:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wmktemp_s' as _wmktemp_s:dword
;    end if
;    extrn '__imp___wopen' as _wopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___woutput_s' as _woutput_s:dword
;    end if
;    extrn '__imp___wperror' as _wperror:dword
;    extrn '__imp___wpgmptr' as _wpgmptr:dword
;    extrn '__imp___wpopen' as _wpopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wprintf_l' as _wprintf_l:dword
;        extrn '__imp___wprintf_p' as _wprintf_p:dword
;        extrn '__imp___wprintf_p_l' as _wprintf_p_l:dword
;        extrn '__imp___wprintf_s_l' as _wprintf_s_l:dword
;    end if
;    extrn '__imp___wputenv' as _wputenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wputenv_s' as _wputenv_s:dword
;    end if
;    extrn '__imp___wremove' as _wremove:dword
;    extrn '__imp___wrename' as _wrename:dword
;    extrn '__imp___write' as _write:dword
;    extrn '__imp___wrmdir' as _wrmdir:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wscanf_l' as _wscanf_l:dword
;        extrn '__imp___wscanf_s_l' as _wscanf_s_l:dword
;    end if
;    extrn '__imp___wsearchenv' as _wsearchenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wsearchenv_s' as _wsearchenv_s:dword
;    end if
;    extrn '__imp___wsetlocale' as _wsetlocale:dword
;    extrn '__imp___wsopen' as _wsopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wsopen_s' as _wsopen_s:dword
;    end if
;    extrn '__imp___wspawnl' as _wspawnl:dword
;    extrn '__imp___wspawnle' as _wspawnle:dword
;    extrn '__imp___wspawnlp' as _wspawnlp:dword
;    extrn '__imp___wspawnlpe' as _wspawnlpe:dword
;    extrn '__imp___wspawnv' as _wspawnv:dword
;    extrn '__imp___wspawnve' as _wspawnve:dword
;    extrn '__imp___wspawnvp' as _wspawnvp:dword
;    extrn '__imp___wspawnvpe' as _wspawnvpe:dword
;    extrn '__imp___wsplitpath' as _wsplitpath:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wsplitpath_s' as _wsplitpath_s:dword
;    end if
;    extrn '__imp___wstat' as _wstat:dword
;    extrn '__imp___wstat64' as _wstat64:dword
;    extrn '__imp___wstati64' as _wstati64:dword
;    extrn '__imp___wstrdate' as _wstrdate:dword
;    extrn '__imp___wstrdate_s' as _wstrdate_s:dword
;    extrn '__imp___wstrtime' as _wstrtime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wstrtime_s' as _wstrtime_s:dword
;    end if
;    extrn '__imp___wsystem' as _wsystem:dword
;    extrn '__imp___wtempnam' as _wtempnam:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtempnam_dbg' as _wtempnam_dbg:dword
;    end if
;    extrn '__imp___wtmpnam' as _wtmpnam:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtmpnam_s' as _wtmpnam_s:dword
;    end if
;    extrn '__imp___wtof' as _wtof:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtof_l' as _wtof_l:dword
;    end if
;    extrn '__imp___wtoi' as _wtoi:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtoi_l' as _wtoi_l:dword
;    end if
;    extrn '__imp___wtoi64' as _wtoi64:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtoi64_l' as _wtoi64_l:dword
;    end if
;    extrn '__imp___wtol' as _wtol:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wtol_l' as _wtol_l:dword
;    end if
;    extrn '__imp___wunlink' as _wunlink:dword
;    extrn '__imp___wutime' as _wutime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp___wutime32' as _wutime32:dword
;    end if
;    extrn '__imp___wutime64' as _wutime64:dword
;    extrn '__imp___XcptFilter' as _XcptFilter:dword
;    extrn '__imp___y0' as _y0:dword
;    extrn '__imp___y1' as _y1:dword
;    extrn '__imp___yn' as _yn:dword
;    extrn '__imp__abort' as abort:dword
;    extrn '__imp__abs' as abs:dword
;    extrn '__imp__acos' as acos:dword
;    extrn '__imp__acosf' as acosf:dword
;    extrn '__imp__asctime' as asctime:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__asctime_s' as asctime_s:dword
;    end if
;    extrn '__imp__asin' as asin:dword
;    extrn '__imp__asinf' as asinf:dword
;    extrn '__imp__atan' as atan:dword
;    extrn '__imp__atan2' as atan2:dword
;    extrn '__imp__atan2f' as atan2f:dword
;    extrn '__imp__atanf' as atanf:dword
;    extrn '__imp__atexit' as atexit:dword
;    extrn '__imp__atof' as atof:dword
;    extrn '__imp__atoi' as atoi:dword
;    extrn '__imp__atol' as atol:dword
;    extrn '__imp__bsearch' as bsearch:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__bsearch_s' as bsearch_s:dword
;        extrn '__imp__btowc' as btowc:dword
;    end if
;    extrn '__imp__calloc' as calloc:dword
;    extrn '__imp__ceil' as ceil:dword
;    extrn '__imp__ceilf' as ceilf:dword
;    extrn '__imp__clearerr' as clearerr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__clearerr_s' as clearerr_s:dword
;    end if
;    extrn '__imp__clock' as clock:dword
;    extrn '__imp__cos' as cos:dword
;    extrn '__imp__cosf' as cosf:dword
;    extrn '__imp__cosh' as cosh:dword
;    extrn '__imp__coshf' as coshf:dword
;    extrn '__imp__ctime' as ctime:dword
;    extrn '__imp__difftime' as _difftime:dword
;    ;extrn '__imp__div' as div:dword           ;Name conflicts
;    ;extrn '__imp__exit' as _exit:dword        ;Name conflicts
;    extrn '__imp__exp' as exp:dword
;    extrn '__imp__expf' as expf:dword
;    ;extrn '__imp__fabs' as fabs:dword         ;Name conflicts
;    extrn '__imp__fclose' as fclose:dword
;    extrn '__imp__feof' as feof:dword
;    extrn '__imp__ferror' as ferror:dword
;    extrn '__imp__fflush' as fflush:dword
;    extrn '__imp__fgetc' as fgetc:dword
;    extrn '__imp__fgetpos' as fgetpos:dword
;    extrn '__imp__fgets' as fgets:dword
;    extrn '__imp__fgetwc' as fgetwc:dword
;    extrn '__imp__fgetws' as fgetws:dword
;    extrn '__imp__floor' as floor:dword
;    extrn '__imp__floorf' as floorf:dword
;    extrn '__imp__fmod' as fmod:dword
;    extrn '__imp__fmodf' as fmodf:dword
;    extrn '__imp__fopen' as fopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__fopen_s' as fopen_s:dword
;    end if
;    extrn '__imp__fprintf' as fprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__fprintf_s' as fprintf_s:dword
;    end if
;    extrn '__imp__fputc' as fputc:dword
;    extrn '__imp__fputs' as fputs:dword
;    extrn '__imp__fputwc' as fputwc:dword
;    extrn '__imp__fputws' as fputws:dword
;    extrn '__imp__fread' as fread:dword
;    extrn '__imp__free' as free:dword
;    extrn '__imp__freopen' as freopen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__freopen_s' as freopen_s:dword
;    end if
;    extrn '__imp__frexp' as frexp:dword
;    extrn '__imp__fscanf' as fscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__fscanf_s' as fscanf_s:dword
;    end if
;    extrn '__imp__fseek' as fseek:dword
;    extrn '__imp__fsetpos' as fsetpos:dword
;    extrn '__imp__ftell' as ftell:dword
;    extrn '__imp__fwprintf' as fwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__fwprintf_s' as fwprintf_s:dword
;    end if
;    extrn '__imp__fwrite' as fwrite:dword
;    extrn '__imp__fwscanf' as fwscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__fwscanf_s' as fwscanf_s:dword
;    end if
;    extrn '__imp__getc' as getc:dword
;    extrn '__imp__getchar' as getchar:dword
;    extrn '__imp__getenv' as getenv:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__getenv_s' as getenv_s:dword
;    end if
;    extrn '__imp__gets' as gets:dword
;    extrn '__imp__getwc' as getwc:dword
;    extrn '__imp__getwchar' as getwchar:dword
;    extrn '__imp__gmtime' as gmtime:dword
;    extrn '__imp__is_wctype' as is_wctype:dword
;    extrn '__imp__isalnum' as isalnum:dword
;    extrn '__imp__isalpha' as isalpha:dword
;    extrn '__imp__iscntrl' as iscntrl:dword
;    extrn '__imp__isdigit' as isdigit:dword
;    extrn '__imp__isgraph' as isgraph:dword
;    extrn '__imp__isleadbyte' as isleadbyte:dword
;    extrn '__imp__islower' as islower:dword
;    extrn '__imp__isprint' as isprint:dword
;    extrn '__imp__ispunct' as ispunct:dword
;    extrn '__imp__isspace' as isspace:dword
;    extrn '__imp__isupper' as isupper:dword
;    extrn '__imp__iswalnum' as iswalnum:dword
;    extrn '__imp__iswalpha' as iswalpha:dword
;    extrn '__imp__iswascii' as iswascii:dword
;    extrn '__imp__iswcntrl' as iswcntrl:dword
;    extrn '__imp__iswctype' as iswctype:dword
;    extrn '__imp__iswdigit' as iswdigit:dword
;    extrn '__imp__iswgraph' as iswgraph:dword
;    extrn '__imp__iswlower' as iswlower:dword
;    extrn '__imp__iswprint' as iswprint:dword
;    extrn '__imp__iswpunct' as iswpunct:dword
;    extrn '__imp__iswspace' as iswspace:dword
;    extrn '__imp__iswupper' as iswupper:dword
;    extrn '__imp__iswxdigit' as iswxdigit:dword
;    extrn '__imp__isxdigit' as isxdigit:dword
;    extrn '__imp__labs' as labs:dword
;    extrn '__imp__ldexp' as ldexp:dword
;    extrn '__imp__ldiv' as ldiv:dword
;    extrn '__imp__localeconv' as localeconv:dword
;    extrn '__imp__localtime' as localtime:dword
;    extrn '__imp__log' as log:dword
;    extrn '__imp__log10' as log10:dword
;    extrn '__imp__log10f' as log10f:dword
;    extrn '__imp__logf' as logf:dword
;    extrn '__imp__longjmp' as longjmp:dword
;    extrn '__imp__malloc' as malloc:dword
;    extrn '__imp__mblen' as mblen:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__mbrlen' as mbrlen:dword
;        extrn '__imp__mbrtowc' as mbrtowc:dword
;        extrn '__imp__mbsdup_dbg' as mbsdup_dbg:dword
;        extrn '__imp__mbsrtowcs' as mbsrtowcs:dword
;        extrn '__imp__mbsrtowcs_s' as mbsrtowcs_s:dword
;    end if
;    extrn '__imp__mbstowcs' as mbstowcs:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__mbstowcs_s' as mbstowcs_s:dword
;    end if
;    extrn '__imp__mbtowc' as mbtowc:dword
;    extrn '__imp__memchr' as memchr:dword
;    extrn '__imp__memcmp' as memcmp:dword
;    extrn '__imp__memcpy' as memcpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__memcpy_s' as memcpy_s:dword
;    end if
;    extrn '__imp__memmove' as memmove:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__memmove_s' as memmove_s:dword
;    end if
;    extrn '__imp__memset' as memset:dword
;    extrn '__imp__mktime' as mktime:dword
;    extrn '__imp__modf' as modf:dword
;    extrn '__imp__modff' as modff:dword
;    extrn '__imp__perror' as perror:dword
;    extrn '__imp__pow' as pow:dword
;    extrn '__imp__powf' as powf:dword
;    extrn '__imp__printf' as printf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__printf_s' as printf_s:dword
;    end if
;    extrn '__imp__putc' as putc:dword
;    extrn '__imp__putchar' as putchar:dword
;    extrn '__imp__puts' as puts:dword
;    extrn '__imp__putwc' as putwc:dword
;    extrn '__imp__putwchar' as putwchar:dword
;    extrn '__imp__qsort' as qsort:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__qsort_s' as qsort_s:dword
;    end if
;    extrn '__imp__raise' as raise:dword
;    extrn '__imp__rand' as rand:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__rand_s' as rand_s:dword
;    end if
;    extrn '__imp__realloc' as realloc:dword
;    extrn '__imp__remove' as remove:dword
;    extrn '__imp__rename' as rename:dword
;    extrn '__imp__rewind' as rewind:dword
;    extrn '__imp__scanf' as scanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__scanf_s' as scanf_s:dword
;    end if
;    extrn '__imp__setbuf' as setbuf:dword
;    extrn '__imp__setjmp' as setjmp:dword
;    extrn '__imp__setlocale' as setlocale:dword
;    extrn '__imp__setvbuf' as setvbuf:dword
;    extrn '__imp__signal' as signal:dword
;    extrn '__imp__sin' as sin:dword
;    extrn '__imp__sinf' as sinf:dword
;    extrn '__imp__sinh' as sinh:dword
;    extrn '__imp__sinhf' as sinhf:dword
;    extrn '__imp__sprintf' as sprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__sprintf_s' as sprintf_s:dword
;    end if
;    extrn '__imp__sqrt' as sqrt:dword
;    extrn '__imp__sqrtf' as sqrtf:dword
;    extrn '__imp__srand' as srand:dword
;    extrn '__imp__sscanf' as sscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__sscanf_s' as sscanf_s:dword
;    end if
;    extrn '__imp__strcat' as strcat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strcat_s' as strcat_s:dword
;    end if
;    extrn '__imp__strchr' as strchr:dword
;    extrn '__imp__strcmp' as strcmp:dword
;    extrn '__imp__strcoll' as strcoll:dword
;    extrn '__imp__strcpy' as strcpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strcpy_s' as strcpy_s:dword
;    end if
;    extrn '__imp__strcspn' as strcspn:dword
;    extrn '__imp__strerror' as strerror:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strerror_s' as strerror_s:dword
;    end if
;    extrn '__imp__strftime' as strftime:dword
;    extrn '__imp__strlen' as strlen:dword
;    extrn '__imp__strncat' as strncat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strncat_s' as strncat_s:dword
;    end if
;    extrn '__imp__strncmp' as strncmp:dword
;    extrn '__imp__strncpy' as strncpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strncpy_s' as strncpy_s:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strnlen' as strnlen:dword
;    end if
;    extrn '__imp__strpbrk' as strpbrk:dword
;    extrn '__imp__strrchr' as strrchr:dword
;    extrn '__imp__strspn' as strspn:dword
;    extrn '__imp__strstr' as strstr:dword
;    extrn '__imp__strtod' as strtod:dword
;    extrn '__imp__strtok' as strtok:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__strtok_s' as strtok_s:dword
;    end if
;    extrn '__imp__strtol' as strtol:dword
;    extrn '__imp__strtoul' as strtoul:dword
;    extrn '__imp__strxfrm' as strxfrm:dword
;    extrn '__imp__swprintf' as swprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__swprintf_s' as swprintf_s:dword
;    end if
;    extrn '__imp__swscanf' as swscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__swscanf_s' as swscanf_s:dword
;    end if
;    extrn '__imp__system' as system:dword
;    extrn '__imp__tan' as tan:dword
;    extrn '__imp__tanf' as tanf:dword
;    extrn '__imp__tanh' as tanh:dword
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;        extrn '__imp__tanhf' as tanhf:dword
;    end if
;    extrn '__imp__time' as time:dword
;    extrn '__imp__tmpfile' as tmpfile:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__tmpfile_s' as tmpfile_s:dword
;    end if
;    extrn '__imp__tmpnam' as tmpnam:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__tmpnam_s' as tmpnam_s:dword
;    end if
;    extrn '__imp__tolower' as tolower:dword
;    extrn '__imp__toupper' as toupper:dword
;    extrn '__imp__towlower' as towlower:dword
;    extrn '__imp__towupper' as towupper:dword
;    extrn '__imp__ungetc' as ungetc:dword
;    extrn '__imp__ungetwc' as ungetwc:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__utime' as utime:dword
;    end if
;    extrn '__imp__vfprintf' as vfprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vfprintf_s' as vfprintf_s:dword
;    end if
;    extrn '__imp__vfwprintf' as vfwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vfwprintf_s' as vfwprintf_s:dword
;    end if
;    extrn '__imp__vprintf' as vprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vprintf_s' as vprintf_s:dword
;        extrn '__imp__vsnprintf' as vsnprintf:dword
;    end if
;    extrn '__imp__vsprintf' as vsprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vsprintf_s' as vsprintf_s:dword
;    end if
;    extrn '__imp__vswprintf' as vswprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vswprintf_s' as vswprintf_s:dword
;    end if
;    extrn '__imp__vwprintf' as vwprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__vwprintf_s' as vwprintf_s:dword
;        extrn '__imp__wcrtomb' as wcrtomb:dword
;        extrn '__imp__wcrtomb_s' as wcrtomb_s:dword
;    end if
;    extrn '__imp__wcscat' as wcscat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcscat_s' as wcscat_s:dword
;    end if
;    extrn '__imp__wcschr' as wcschr:dword
;    extrn '__imp__wcscmp' as wcscmp:dword
;    extrn '__imp__wcscoll' as wcscoll:dword
;    extrn '__imp__wcscpy' as wcscpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcscpy_s' as wcscpy_s:dword
;    end if
;    extrn '__imp__wcscspn' as wcscspn:dword
;    extrn '__imp__wcsftime' as wcsftime:dword
;    extrn '__imp__wcslen' as wcslen:dword
;    extrn '__imp__wcsncat' as wcsncat:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcsncat_s' as wcsncat_s:dword
;    end if
;    extrn '__imp__wcsncmp' as wcsncmp:dword
;    extrn '__imp__wcsncpy' as wcsncpy:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcsncpy_s' as wcsncpy_s:dword
;        extrn '__imp__wcsnlen' as wcsnlen:dword
;    end if
;    extrn '__imp__wcspbrk' as wcspbrk:dword
;    extrn '__imp__wcsrchr' as wcsrchr:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcsrtombs' as wcsrtombs:dword
;        extrn '__imp__wcsrtombs_s' as wcsrtombs_s:dword
;    end if
;    extrn '__imp__wcsspn' as wcsspn:dword
;    extrn '__imp__wcsstr' as wcsstr:dword
;    extrn '__imp__wcstod' as wcstod:dword
;    extrn '__imp__wcstok' as wcstok:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcstok_s' as wcstok_s:dword
;    end if
;    extrn '__imp__wcstol' as wcstol:dword
;    extrn '__imp__wcstombs' as wcstombs:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wcstombs_s' as wcstombs_s:dword
;    end if
;    extrn '__imp__wcstoul' as wcstoul:dword
;    extrn '__imp__wcsxfrm' as wcsxfrm:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wctob' as wctob:dword
;    end if
;    extrn '__imp__wctomb' as wctomb:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wctomb_s' as wctomb_s:dword
;    end if
;    extrn '__imp__wprintf' as wprintf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wprintf_s' as wprintf_s:dword
;    end if
;    extrn '__imp__wscanf' as wscanf:dword
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__wscanf_s' as wscanf_s:dword
;    end if
end if

api __crtCompareString,\
    __crtGetLocaleInfo,\
    __crtGetStringType,\
    __crtLCMapString

end if ;MSVCRT_INC
