; =====================================================;
;                                                      ;
;  crypt32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.4)                     ;
;                                                      ;
;            Copyright © Ramon Sala - 2019             ;
;                                                      ;
; =====================================================;

IFNDEF CRYPT32_INC
CRYPT32_INC EQU 1

IFNDEF MACROS_INC
    Include macros.inc
ENDIF

ALG_CLASS_ANY                                   EQU     0
ALG_CLASS_SIGNATURE                             EQU     (1 SHL 13)
ALG_CLASS_MSG_ENCRYPT                           EQU     (2 SHL 13)
ALG_CLASS_DATA_ENCRYPT                          EQU     (3 SHL 13)
ALG_CLASS_HASH                                  EQU     (4 SHL 13)
ALG_CLASS_KEY_EXCHANGE                          EQU     (5 SHL 13)
ALG_CLASS_ALL                                   EQU     (7 SHL 13)

ALG_TYPE_ANY                                    EQU     0
ALG_TYPE_DSS                                    EQU     (1 SHL 9)
ALG_TYPE_RSA                                    EQU     (2 SHL 9)
ALG_TYPE_BLOCK                                  EQU     (3 SHL 9)
ALG_TYPE_STREAM                                 EQU     (4 SHL 9)
ALG_TYPE_DH                                     EQU     (5 SHL 9)
ALG_TYPE_SECURECHANNEL                          EQU     (6 SHL 9)

ALG_SID_ANY                                     EQU     0
ALG_SID_RSA_ANY                                 EQU     0
ALG_SID_RSA_PKCS                                EQU     1
ALG_SID_RSA_MSATWORK                            EQU     2
ALG_SID_RSA_ENTRUST                             EQU     3
ALG_SID_RSA_PGP                                 EQU     4
ALG_SID_DSS_ANY                                 EQU     0
ALG_SID_DSS_PKCS                                EQU     1
ALG_SID_DSS_DMS                                 EQU     2
ALG_SID_ECDSA                                   EQU     3

ALG_SID_DES                                     EQU     1
ALG_SID_3DES                                    EQU     3
ALG_SID_DESX                                    EQU     4
ALG_SID_IDEA                                    EQU     5
ALG_SID_CAST                                    EQU     6
ALG_SID_SAFERSK64                               EQU     7
ALG_SID_SAFERSK128                              EQU     8
ALG_SID_3DES_112                                EQU     9
ALG_SID_CYLINK_MEK                              EQU     12
ALG_SID_RC5                                     EQU     13
ALG_SID_AES_128                                 EQU     14
ALG_SID_AES_192                                 EQU     15
ALG_SID_AES_256                                 EQU     16
ALG_SID_AES                                     EQU     17

ALG_SID_SKIPJACK                                EQU     10
ALG_SID_TEK                                     EQU     11

CRYPT_MODE_CBCI                                 EQU     6
CRYPT_MODE_CFBP                                 EQU     7
CRYPT_MODE_OFBP                                 EQU     8
CRYPT_MODE_CBCOFM                               EQU     9
CRYPT_MODE_CBCOFMI                              EQU     10

ALG_SID_RC2                                     EQU     2
ALG_SID_RC4                                     EQU     1
ALG_SID_SEAL                                    EQU     2
ALG_SID_DH_SANDF                                EQU     1
ALG_SID_DH_EPHEM                                EQU     2
ALG_SID_AGREED_KEY_ANY                          EQU     3
ALG_SID_KEA                                     EQU     4
ALG_SID_ECDH                                    EQU     5

ALG_SID_MD2                                     EQU     1
ALG_SID_MD4                                     EQU     2
ALG_SID_MD5                                     EQU     3
ALG_SID_SHA                                     EQU     4
ALG_SID_SHA1                                    EQU     4
ALG_SID_MAC                                     EQU     5
ALG_SID_RIPEMD                                  EQU     6
ALG_SID_RIPEMD160                               EQU     7
ALG_SID_SSL3SHAMD5                              EQU     8
ALG_SID_HMAC                                    EQU     9
ALG_SID_TLS1PRF                                 EQU     10
ALG_SID_HASH_REPLACE_OWF                        EQU     11
ALG_SID_SHA_256                                 EQU     12
ALG_SID_SHA_384                                 EQU     13
ALG_SID_SHA_512                                 EQU     14
ALG_SID_ECMQV                                   EQU     1

ALG_SID_SSL3_MASTER                             EQU     1
ALG_SID_SCHANNEL_MASTER_HASH                    EQU     2
ALG_SID_SCHANNEL_MAC_KEY                        EQU     3
ALG_SID_PCT1_MASTER                             EQU     4
ALG_SID_SSL2_MASTER                             EQU     5
ALG_SID_TLS1_MASTER                             EQU     6
ALG_SID_SCHANNEL_ENC_KEY                        EQU     7
ALG_SID_EXAMPLE                                 EQU     80

CALG_MD2                                        EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_MD2)
CALG_MD4                                        EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_MD4)
CALG_MD5                                        EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_MD5)
CALG_SHA                                        EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SHA)
CALG_SHA1                                       EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SHA1)
CALG_MAC                                        EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_MAC)
CALG_RSA_SIGN                                   EQU     (ALG_CLASS_SIGNATURE OR ALG_TYPE_RSA OR ALG_SID_RSA_ANY)
CALG_DSS_SIGN                                   EQU     (ALG_CLASS_SIGNATURE OR ALG_TYPE_DSS OR ALG_SID_DSS_ANY)
CALG_NO_SIGN                                    EQU     (ALG_CLASS_SIGNATURE OR ALG_TYPE_ANY OR ALG_SID_ANY)
CALG_RSA_KEYX                                   EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_RSA OR ALG_SID_RSA_ANY)
CALG_DES                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_DES)
CALG_3DES_112                                   EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_3DES_112)
CALG_3DES                                       EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_3DES)
CALG_DESX                                       EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_DESX)
CALG_RC2                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_RC2)
CALG_RC4                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_STREAM OR ALG_SID_RC4)
CALG_SEAL                                       EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_STREAM OR ALG_SID_SEAL)
CALG_DH_SF                                      EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_DH OR ALG_SID_DH_SANDF)
CALG_DH_EPHEM                                   EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_DH OR ALG_SID_DH_EPHEM)
CALG_AGREEDKEY_ANY                              EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_DH OR ALG_SID_AGREED_KEY_ANY)
CALG_KEA_KEYX                                   EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_DH OR ALG_SID_KEA)
CALG_HUGHES_MD5                                 EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_ANY OR ALG_SID_MD5)
CALG_SKIPJACK                                   EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_SKIPJACK)
CALG_TEK                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_TEK)
CALG_CYLINK_MEK                                 EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_CYLINK_MEK)
CALG_SSL3_SHAMD5                                EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SSL3SHAMD5)
CALG_SSL3_MASTER                                EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_SSL3_MASTER)
CALG_SCHANNEL_MASTER_HASH                       EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_SCHANNEL_MASTER_HASH)
CALG_SCHANNEL_MAC_KEY                           EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_SCHANNEL_MAC_KEY)
CALG_SCHANNEL_ENC_KEY                           EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_SCHANNEL_ENC_KEY)
CALG_PCT1_MASTER                                EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_PCT1_MASTER)
CALG_SSL2_MASTER                                EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_SSL2_MASTER)
CALG_TLS1_MASTER                                EQU     (ALG_CLASS_MSG_ENCRYPT OR ALG_TYPE_SECURECHANNEL OR ALG_SID_TLS1_MASTER)
CALG_RC5                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_RC5)
CALG_HMAC                                       EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_HMAC)
CALG_TLS1PRF                                    EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_TLS1PRF)
CALG_HASH_REPLACE_OWF                           EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_HASH_REPLACE_OWF)
CALG_AES_128                                    EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_AES_128)
CALG_AES_192                                    EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_AES_192)
CALG_AES_256                                    EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_AES_256)
CALG_AES                                        EQU     (ALG_CLASS_DATA_ENCRYPT OR ALG_TYPE_BLOCK OR ALG_SID_AES)
CALG_SHA_256                                    EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SHA_256)
CALG_SHA_384                                    EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SHA_384)
CALG_SHA_512                                    EQU     (ALG_CLASS_HASH OR ALG_TYPE_ANY OR ALG_SID_SHA_512)
CALG_ECDH                                       EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_DH OR ALG_SID_ECDH)
CALG_ECMQV                                      EQU     (ALG_CLASS_KEY_EXCHANGE OR ALG_TYPE_ANY OR ALG_SID_ECMQV)
CALG_ECDSA                                      EQU     (ALG_CLASS_SIGNATURE OR ALG_TYPE_DSS OR ALG_SID_ECDSA)

CRYPT_VERIFYCONTEXT                             EQU     0F0000000H
CRYPT_NEWKEYSET                                 EQU     000000008H
CRYPT_DELETEKEYSET                              EQU     000000010H
CRYPT_MACHINE_KEYSET                            EQU     000000020H
CRYPT_SILENT                                    EQU     000000040H
CRYPT_DEFAULT_CONTAINER_OPTIONAL                EQU     000000080H
CRYPT_EXPORTABLE                                EQU     000000001H
CRYPT_USER_PROTECTED                            EQU     000000002H
CRYPT_CREATE_SALT                               EQU     000000004H
CRYPT_UPDATE_KEY                                EQU     000000008H
CRYPT_NO_SALT                                   EQU     000000010H
CRYPT_PREGEN                                    EQU     000000040H
CRYPT_RECIPIENT                                 EQU     000000010H
CRYPT_INITIATOR                                 EQU     000000040H
CRYPT_ONLINE                                    EQU     000000080H
CRYPT_SF                                        EQU     000000100H
CRYPT_CREATE_IV                                 EQU     000000200H
CRYPT_KEK                                       EQU     000000400H
CRYPT_DATA_KEY                                  EQU     000000800H
CRYPT_VOLATILE                                  EQU     000001000H
CRYPT_SGCKEY                                    EQU     000002000H
CRYPT_ARCHIVABLE                                EQU     000004000H
CRYPT_FORCE_KEY_PROTECTION_HIGH                 EQU     000008000H

RSA1024BIT_KEY                                  EQU     004000000H
CRYPT_SERVER                                    EQU     000000400H
KEY_LENGTH_MASK                                 EQU     0FFFF0000H
CRYPT_Y_ONLY                                    EQU     000000001H
CRYPT_SSL2_FALLBACK                             EQU     000000002H
CRYPT_DESTROYKEY                                EQU     000000004H
CRYPT_OAEP                                      EQU     000000040H
CRYPT_BLOB_VER3                                 EQU     000000080H
CRYPT_IPSEC_HMAC_KEY                            EQU     000000100H
CRYPT_DECRYPT_RSA_NO_PADDING_CHECK              EQU     000000020H

CRYPT_SECRETDIGEST                              EQU     000000001H

CRYPT_OWF_REPL_LM_HASH                          EQU     000000001H

CRYPT_LITTLE_ENDIAN                             EQU     000000001H
CRYPT_NOHASHOID                                 EQU     000000001H
CRYPT_TYPE2_FORMAT                              EQU     000000002H
CRYPT_X931_FORMAT                               EQU     000000004H
CRYPT_MACHINE_DEFAULT                           EQU     000000001H
CRYPT_USER_DEFAULT                              EQU     000000002H
CRYPT_DELETE_DEFAULT                            EQU     000000004H

SIMPLEBLOB                                      EQU     01H
PUBLICKEYBLOB                                   EQU     06H
PRIVATEKEYBLOB                                  EQU     07H
PLAINTEXTKEYBLOB                                EQU     08H
OPAQUEKEYBLOB                                   EQU     09H
PUBLICKEYBLOBEX                                 EQU     0AH
SYMMETRICWRAPKEYBLOB                            EQU     0BH
KEYSTATEBLOB                                    EQU     0CH

AT_KEYEXCHANGE                                  EQU     1
AT_SIGNATURE                                    EQU     2

CRYPT_USERDATA                                  EQU     1

KP_IV                                           EQU     1
KP_SALT                                         EQU     2
KP_PADDING                                      EQU     3
KP_MODE                                         EQU     4
KP_MODE_BITS                                    EQU     5
KP_PERMISSIONS                                  EQU     6
KP_ALGID                                        EQU     7
KP_BLOCKLEN                                     EQU     8
KP_KEYLEN                                       EQU     9
KP_SALT_EX                                      EQU     10
KP_P                                            EQU     11
KP_G                                            EQU     12
KP_Q                                            EQU     13
KP_X                                            EQU     14
KP_Y                                            EQU     15
KP_RA                                           EQU     16
KP_RB                                           EQU     17
KP_INFO                                         EQU     18
KP_EFFECTIVE_KEYLEN                             EQU     19
KP_SCHANNEL_ALG                                 EQU     20
KP_CLIENT_RANDOM                                EQU     21
KP_SERVER_RANDOM                                EQU     22
KP_RP                                           EQU     23
KP_PRECOMP_MD5                                  EQU     24
KP_PRECOMP_SHA                                  EQU     25
KP_CERTIFICATE                                  EQU     26
KP_CLEAR_KEY                                    EQU     27
KP_PUB_EX_LEN                                   EQU     28
KP_PUB_EX_VAL                                   EQU     29
KP_KEYVAL                                       EQU     30
KP_ADMIN_PIN                                    EQU     31
KP_KEYEXCHANGE_PIN                              EQU     32
KP_SIGNATURE_PIN                                EQU     33
KP_PREHASH                                      EQU     34
KP_ROUNDS                                       EQU     35
KP_OAEP_PARAMS                                  EQU     36
KP_CMS_KEY_INFO                                 EQU     37
KP_CMS_DH_KEY_INFO                              EQU     38
KP_PUB_PARAMS                                   EQU     39
KP_VERIFY_PARAMS                                EQU     40
KP_HIGHEST_VERSION                              EQU     41
KP_GET_USE_COUNT                                EQU     42
KP_PIN_ID                                       EQU     43
KP_PIN_INFO                                     EQU     44

PKCS5_PADDING                                   EQU     1
RANDOM_PADDING                                  EQU     2
ZERO_PADDING                                    EQU     3

CRYPT_MODE_CBC                                  EQU     1
CRYPT_MODE_ECB                                  EQU     2
CRYPT_MODE_OFB                                  EQU     3
CRYPT_MODE_CFB                                  EQU     4
CRYPT_MODE_CTS                                  EQU     5
CRYPT_ENCRYPT                                   EQU     00001H
CRYPT_DECRYPT                                   EQU     00002H
CRYPT_EXPORT                                    EQU     00004H
CRYPT_READ                                      EQU     00008H
CRYPT_WRITE                                     EQU     00010H
CRYPT_MAC                                       EQU     00020H
CRYPT_EXPORT_KEY                                EQU     00040H
CRYPT_IMPORT_KEY                                EQU     00080H
CRYPT_ARCHIVE                                   EQU     00100H

HP_ALGID                                        EQU     00001H
HP_HASHVAL                                      EQU     00002H
HP_HASHSIZE                                     EQU     00004H
HP_HMAC_INFO                                    EQU     00005H
HP_TLS1PRF_LABEL                                EQU     00006H
HP_TLS1PRF_SEED                                 EQU     00007H

CRYPT_FAILED                                    EQU     FALSE
CRYPT_SUCCEED                                   EQU     TRUE

PP_ENUMALGS                                     EQU     1
PP_ENUMCONTAINERS                               EQU     2
PP_IMPTYPE                                      EQU     3
PP_NAME                                         EQU     4
PP_VERSION                                      EQU     5
PP_CONTAINER                                    EQU     6
PP_CHANGE_PASSWORD                              EQU     7
PP_KEYSET_SEC_DESCR                             EQU     8
PP_CERTCHAIN                                    EQU     9
PP_KEY_TYPE_SUBTYPE                             EQU     10
PP_PROVTYPE                                     EQU     16
PP_KEYSTORAGE                                   EQU     17
PP_APPLI_CERT                                   EQU     18
PP_SYM_KEYSIZE                                  EQU     19
PP_SESSION_KEYSIZE                              EQU     20
PP_UI_PROMPT                                    EQU     21
PP_ENUMALGS_EX                                  EQU     22
PP_ENUMMANDROOTS                                EQU     25
PP_ENUMELECTROOTS                               EQU     26
PP_KEYSET_TYPE                                  EQU     27
PP_ADMIN_PIN                                    EQU     31
PP_KEYEXCHANGE_PIN                              EQU     32
PP_SIGNATURE_PIN                                EQU     33
PP_SIG_KEYSIZE_INC                              EQU     34
PP_KEYX_KEYSIZE_INC                             EQU     35
PP_UNIQUE_CONTAINER                             EQU     36
PP_SGC_INFO                                     EQU     37
PP_USE_HARDWARE_RNG                             EQU     38
PP_KEYSPEC                                      EQU     39
PP_ENUMEX_SIGNING_PROT                          EQU     40
PP_CRYPT_COUNT_KEY_USE                          EQU     41
PP_USER_CERTSTORE                               EQU     42
PP_SMARTCARD_READER                             EQU     43
PP_SMARTCARD_GUID                               EQU     45
PP_ROOT_CERTSTORE                               EQU     46

CRYPT_FIRST                                     EQU     1
CRYPT_NEXT                                      EQU     2
CRYPT_SGC_ENUM                                  EQU     4
CRYPT_IMPL_HARDWARE                             EQU     1
CRYPT_IMPL_SOFTWARE                             EQU     2
CRYPT_IMPL_MIXED                                EQU     3
CRYPT_IMPL_UNKNOWN                              EQU     4
CRYPT_IMPL_REMOVABLE                            EQU     8
CRYPT_SEC_DESCR                                 EQU     000000001H
CRYPT_PSTORE                                    EQU     000000002H
CRYPT_UI_PROMPT                                 EQU     000000004H
CRYPT_FLAG_PCT1                                 EQU     00001H
CRYPT_FLAG_SSL2                                 EQU     00002H
CRYPT_FLAG_SSL3                                 EQU     00004H
CRYPT_FLAG_TLS1                                 EQU     00008H
CRYPT_FLAG_IPSEC                                EQU     00010H
CRYPT_FLAG_SIGNING                              EQU     00020H
CRYPT_SGC                                       EQU     00001H
CRYPT_FASTSGC                                   EQU     00002H

PP_CLIENT_HWND                                  EQU     1
PP_CONTEXT_INFO                                 EQU     11
PP_KEYEXCHANGE_KEYSIZE                          EQU     12
PP_SIGNATURE_KEYSIZE                            EQU     13
PP_KEYEXCHANGE_ALG                              EQU     14
PP_SIGNATURE_ALG                                EQU     15
PP_DELETEKEY                                    EQU     24
PP_PIN_PROMPT_STRING                            EQU     44
PP_SECURE_KEYEXCHANGE_PIN                       EQU     47
PP_SECURE_SIGNATURE_PIN                         EQU     48

PROV_RSA_FULL                                   EQU     1
PROV_RSA_SIG                                    EQU     2
PROV_DSS                                        EQU     3
PROV_FORTEZZA                                   EQU     4
PROV_MS_EXCHANGE                                EQU     5
PROV_SSL                                        EQU     6
PROV_RSA_SCHANNEL                               EQU     12
PROV_DSS_DH                                     EQU     13
PROV_EC_ECDSA_SIG                               EQU     14
PROV_EC_ECNRA_SIG                               EQU     15
PROV_EC_ECDSA_FULL                              EQU     16
PROV_EC_ECNRA_FULL                              EQU     17
PROV_DH_SCHANNEL                                EQU     18
PROV_SPYRUS_LYNKS                               EQU     20
PROV_RNG                                        EQU     21
PROV_INTEL_SEC                                  EQU     22
PROV_REPLACE_OWF                                EQU     23
PROV_RSA_AES                                    EQU     24

PROV_STT_MER                                    EQU     7
PROV_STT_ACQ                                    EQU     8
PROV_STT_BRND                                   EQU     9
PROV_STT_ROOT                                   EQU     10
PROV_STT_ISS                                    EQU     11

MAXUIDLEN                                       EQU     64
EXPO_OFFLOAD_REG_VALUE                          TEXTEQU <"ExpoOffload">
EXPO_OFFLOAD_FUNC_NAME                          TEXTEQU <"OffloadModExpo">
szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS             TEXTEQU <"Software\Policies\Microsoft\Cryptography">

szFORCE_KEY_PROTECTION                          TEXTEQU <"ForceKeyProtection">
dwFORCE_KEY_PROTECTION_DISABLED                 EQU     00H
dwFORCE_KEY_PROTECTION_USER_SELECT              EQU     01H
dwFORCE_KEY_PROTECTION_HIGH                     EQU     02H

szKEY_CACHE_ENABLED                             TEXTEQU <"CachePrivateKeys">
szKEY_CACHE_SECONDS                             TEXTEQU <"PrivateKeyLifetimeSeconds">

szPRIV_KEY_CACHE_MAX_ITEMS                      TEXTEQU <"PrivKeyCacheMaxItems">
cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT               EQU     20

szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS         TEXTEQU <"PrivKeyCachePurgeIntervalSeconds">
cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT  EQU     86400

CUR_BLOB_VERSION                                EQU     2

MS_DEF_PROV_A                                   TEXTEQU <"Microsoft Base Cryptographic Provider v1.0">
MS_DEF_PROV_W                                   EQU     L("Microsoft Base Cryptographic Provider v1.0")
MS_ENHANCED_PROV_A                              TEXTEQU <"Microsoft Enhanced Cryptographic Provider v1.0">
MS_ENHANCED_PROV_W                              EQU     L(Microsoft Enhanced Cryptographic Provider v1.0)
MS_STRONG_PROV_A                                TEXTEQU <"Microsoft Strong Cryptographic Provider">
MS_STRONG_PROV_W                                EQU     L("Microsoft Strong Cryptographic Provider")
MS_DEF_RSA_SIG_PROV_A                           TEXTEQU <"Microsoft RSA Signature Cryptographic Provider">
MS_DEF_RSA_SIG_PROV_W                           EQU     L("Microsoft RSA Signature Cryptographic Provider")
MS_DEF_RSA_SCHANNEL_PROV_A                      TEXTEQU <"Microsoft RSA SChannel Cryptographic Provider">
MS_DEF_RSA_SCHANNEL_PROV_W                      EQU     L("Microsoft RSA SChannel Cryptographic Provider")
MS_DEF_DSS_PROV_A                               TEXTEQU <"Microsoft Base DSS Cryptographic Provider">
MS_DEF_DSS_PROV_W                               EQU     L("Microsoft Base DSS Cryptographic Provider")
MS_DEF_DSS_DH_PROV_A                            TEXTEQU <"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider">
MS_DEF_DSS_DH_PROV_W                            EQU     L("Microsoft Base DSS and Diffie-Hellman Cryptographic Provider")
MS_ENH_DSS_DH_PROV_A                            TEXTEQU <"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider">
MS_ENH_DSS_DH_PROV_W                            EQU     L("Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider")
MS_DEF_DH_SCHANNEL_PROV_A                       TEXTEQU <"Microsoft DH SChannel Cryptographic Provider">
MS_DEF_DH_SCHANNEL_PROV_W                       EQU     L("Microsoft DH SChannel Cryptographic Provider")
MS_SCARD_PROV_A                                 TEXTEQU <"Microsoft Base Smart Card Crypto Provider">
MS_SCARD_PROV_W                                 EQU     L("Microsoft Base Smart Card Crypto Provider")

MS_ENH_RSA_AES_PROV_A                           TEXTEQU <"Microsoft Enhanced RSA and AES Cryptographic Provider">
MS_ENH_RSA_AES_PROV_W                           EQU     L("Microsoft Enhanced RSA and AES Cryptographic Provider")
MS_ENH_RSA_AES_PROV_XP_A                        TEXTEQU <"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)">
MS_ENH_RSA_AES_PROV_XP_W                        EQU     L("Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)")

SCHANNEL_MAC_KEY                                EQU     000000000H
SCHANNEL_ENC_KEY                                EQU     000000001H
INTERNATIONAL_USAGE                             EQU     000000001H

szOID_RSA                                       TEXTEQU <"1.2.840.113549">
szOID_PKCS                                      TEXTEQU <"1.2.840.113549.1">
szOID_RSA_HASH                                  TEXTEQU <"1.2.840.113549.2">
szOID_RSA_ENCRYPT                               TEXTEQU <"1.2.840.113549.3">
szOID_PKCS_1                                    TEXTEQU <"1.2.840.113549.1.1">
szOID_PKCS_2                                    TEXTEQU <"1.2.840.113549.1.2">
szOID_PKCS_3                                    TEXTEQU <"1.2.840.113549.1.3">
szOID_PKCS_4                                    TEXTEQU <"1.2.840.113549.1.4">
szOID_PKCS_5                                    TEXTEQU <"1.2.840.113549.1.5">
szOID_PKCS_6                                    TEXTEQU <"1.2.840.113549.1.6">
szOID_PKCS_7                                    TEXTEQU <"1.2.840.113549.1.7">
szOID_PKCS_8                                    TEXTEQU <"1.2.840.113549.1.8">
szOID_PKCS_9                                    TEXTEQU <"1.2.840.113549.1.9">
szOID_PKCS_10                                   TEXTEQU <"1.2.840.113549.1.10">
szOID_PKCS_12                                   TEXTEQU <"1.2.840.113549.1.12">
szOID_RSA_RSA                                   TEXTEQU <"1.2.840.113549.1.1.1">
szOID_RSA_MD2RSA                                TEXTEQU <"1.2.840.113549.1.1.2">
szOID_RSA_MD4RSA                                TEXTEQU <"1.2.840.113549.1.1.3">
szOID_RSA_MD5RSA                                TEXTEQU <"1.2.840.113549.1.1.4">
szOID_RSA_SHA1RSA                               TEXTEQU <"1.2.840.113549.1.1.5">
szOID_RSA_SETOAEP_RSA                           TEXTEQU <"1.2.840.113549.1.1.6">
szOID_RSA_DH                                    TEXTEQU <"1.2.840.113549.1.3.1">
szOID_RSA_data                                  TEXTEQU <"1.2.840.113549.1.7.1">
szOID_RSA_signedData                            TEXTEQU <"1.2.840.113549.1.7.2">
szOID_RSA_envelopedData                         TEXTEQU <"1.2.840.113549.1.7.3">
szOID_RSA_signEnvData                           TEXTEQU <"1.2.840.113549.1.7.4">
szOID_RSA_digestedData                          TEXTEQU <"1.2.840.113549.1.7.5">
szOID_RSA_hashedData                            TEXTEQU <"1.2.840.113549.1.7.5">
szOID_RSA_encryptedData                         TEXTEQU <"1.2.840.113549.1.7.6">
szOID_RSA_emailAddr                             TEXTEQU <"1.2.840.113549.1.9.1">
szOID_RSA_unstructName                          TEXTEQU <"1.2.840.113549.1.9.2">
szOID_RSA_contentType                           TEXTEQU <"1.2.840.113549.1.9.3">
szOID_RSA_messageDigest                         TEXTEQU <"1.2.840.113549.1.9.4">
szOID_RSA_signingTime                           TEXTEQU <"1.2.840.113549.1.9.5">
szOID_RSA_counterSign                           TEXTEQU <"1.2.840.113549.1.9.6">
szOID_RSA_challengePwd                          TEXTEQU <"1.2.840.113549.1.9.7">
szOID_RSA_unstructAddr                          TEXTEQU <"1.2.840.113549.1.9.8">
szOID_RSA_extCertAttrs                          TEXTEQU <"1.2.840.113549.1.9.9">
szOID_RSA_certExtensions                        TEXTEQU <"1.2.840.113549.1.9.14">
szOID_RSA_SMIMECapabilities                     TEXTEQU <"1.2.840.113549.1.9.15">
szOID_RSA_preferSignedData                      TEXTEQU <"1.2.840.113549.1.9.15.1">
szOID_RSA_SMIMEalg                              TEXTEQU <"1.2.840.113549.1.9.16.3">
szOID_RSA_SMIMEalgESDH                          TEXTEQU <"1.2.840.113549.1.9.16.3.5">
szOID_RSA_SMIMEalgCMS3DESwrap                   TEXTEQU <"1.2.840.113549.1.9.16.3.6">
szOID_RSA_SMIMEalgCMSRC2wrap                    TEXTEQU <"1.2.840.113549.1.9.16.3.7">
szOID_RSA_MD2                                   TEXTEQU <"1.2.840.113549.2.2">
szOID_RSA_MD4                                   TEXTEQU <"1.2.840.113549.2.4">
szOID_RSA_MD5                                   TEXTEQU <"1.2.840.113549.2.5">
szOID_RSA_RC2CBC                                TEXTEQU <"1.2.840.113549.3.2">
szOID_RSA_RC4                                   TEXTEQU <"1.2.840.113549.3.4">
szOID_RSA_DES_EDE3_CBC                          TEXTEQU <"1.2.840.113549.3.7">
szOID_RSA_RC5_CBCPad                            TEXTEQU <"1.2.840.113549.3.9">
szOID_ANSI_X942                                 TEXTEQU <"1.2.840.10046">
szOID_ANSI_X942_DH                              TEXTEQU <"1.2.840.10046.2.1">
szOID_X957                                      TEXTEQU <"1.2.840.10040">
szOID_X957_DSA                                  TEXTEQU <"1.2.840.10040.4.1">
szOID_X957_SHA1DSA                              TEXTEQU <"1.2.840.10040.4.3">
szOID_DS                                        TEXTEQU <"2.5">
szOID_DSALG                                     TEXTEQU <"2.5.8">
szOID_DSALG_CRPT                                TEXTEQU <"2.5.8.1">
szOID_DSALG_HASH                                TEXTEQU <"2.5.8.2">
szOID_DSALG_SIGN                                TEXTEQU <"2.5.8.3">
szOID_DSALG_RSA                                 TEXTEQU <"2.5.8.1.1">
szOID_OIW                                       TEXTEQU <"1.3.14">
szOID_OIWSEC                                    TEXTEQU <"1.3.14.3.2">
szOID_OIWSEC_md4RSA                             TEXTEQU <"1.3.14.3.2.2">
szOID_OIWSEC_md5RSA                             TEXTEQU <"1.3.14.3.2.3">
szOID_OIWSEC_md4RSA2                            TEXTEQU <"1.3.14.3.2.4">
szOID_OIWSEC_desECB                             TEXTEQU <"1.3.14.3.2.6">
szOID_OIWSEC_desCBC                             TEXTEQU <"1.3.14.3.2.7">
szOID_OIWSEC_desOFB                             TEXTEQU <"1.3.14.3.2.8">
szOID_OIWSEC_desCFB                             TEXTEQU <"1.3.14.3.2.9">
szOID_OIWSEC_desMAC                             TEXTEQU <"1.3.14.3.2.10">
szOID_OIWSEC_rsaSign                            TEXTEQU <"1.3.14.3.2.11">
szOID_OIWSEC_dsa                                TEXTEQU <"1.3.14.3.2.12">
szOID_OIWSEC_shaDSA                             TEXTEQU <"1.3.14.3.2.13">
szOID_OIWSEC_mdc2RSA                            TEXTEQU <"1.3.14.3.2.14">
szOID_OIWSEC_shaRSA                             TEXTEQU <"1.3.14.3.2.15">
szOID_OIWSEC_dhCommMod                          TEXTEQU <"1.3.14.3.2.16">
szOID_OIWSEC_desEDE                             TEXTEQU <"1.3.14.3.2.17">
szOID_OIWSEC_sha                                TEXTEQU <"1.3.14.3.2.18">
szOID_OIWSEC_mdc2                               TEXTEQU <"1.3.14.3.2.19">
szOID_OIWSEC_dsaComm                            TEXTEQU <"1.3.14.3.2.20">
szOID_OIWSEC_dsaCommSHA                         TEXTEQU <"1.3.14.3.2.21">
szOID_OIWSEC_rsaXchg                            TEXTEQU <"1.3.14.3.2.22">
szOID_OIWSEC_keyHashSeal                        TEXTEQU <"1.3.14.3.2.23">
szOID_OIWSEC_md2RSASign                         TEXTEQU <"1.3.14.3.2.24">
szOID_OIWSEC_md5RSASign                         TEXTEQU <"1.3.14.3.2.25">
szOID_OIWSEC_sha1                               TEXTEQU <"1.3.14.3.2.26">
szOID_OIWSEC_dsaSHA1                            TEXTEQU <"1.3.14.3.2.27">
szOID_OIWSEC_dsaCommSHA1                        TEXTEQU <"1.3.14.3.2.28">
szOID_OIWSEC_sha1RSASign                        TEXTEQU <"1.3.14.3.2.29">
szOID_OIWDIR                                    TEXTEQU <"1.3.14.7.2">
szOID_OIWDIR_CRPT                               TEXTEQU <"1.3.14.7.2.1">
szOID_OIWDIR_HASH                               TEXTEQU <"1.3.14.7.2.2">
szOID_OIWDIR_SIGN                               TEXTEQU <"1.3.14.7.2.3">
szOID_OIWDIR_md2                                TEXTEQU <"1.3.14.7.2.2.1">
szOID_OIWDIR_md2RSA                             TEXTEQU <"1.3.14.7.2.3.1">
szOID_INFOSEC                                   TEXTEQU <"2.16.840.1.101.2.1">
szOID_INFOSEC_sdnsSignature                     TEXTEQU <"2.16.840.1.101.2.1.1.1">
szOID_INFOSEC_mosaicSignature                   TEXTEQU <"2.16.840.1.101.2.1.1.2">
szOID_INFOSEC_sdnsConfidentiality               TEXTEQU <"2.16.840.1.101.2.1.1.3">
szOID_INFOSEC_mosaicConfidentiality             TEXTEQU <"2.16.840.1.101.2.1.1.4">
szOID_INFOSEC_sdnsIntegrity                     TEXTEQU <"2.16.840.1.101.2.1.1.5">
szOID_INFOSEC_mosaicIntegrity                   TEXTEQU <"2.16.840.1.101.2.1.1.6">
szOID_INFOSEC_sdnsTokenProtection               TEXTEQU <"2.16.840.1.101.2.1.1.7">
szOID_INFOSEC_mosaicTokenProtection             TEXTEQU <"2.16.840.1.101.2.1.1.8">
szOID_INFOSEC_sdnsKeyManagement                 TEXTEQU <"2.16.840.1.101.2.1.1.9">
szOID_INFOSEC_mosaicKeyManagement               TEXTEQU <"2.16.840.1.101.2.1.1.10">
szOID_INFOSEC_sdnsKMandSig                      TEXTEQU <"2.16.840.1.101.2.1.1.11">
szOID_INFOSEC_mosaicKMandSig                    TEXTEQU <"2.16.840.1.101.2.1.1.12">
szOID_INFOSEC_SuiteASignature                   TEXTEQU <"2.16.840.1.101.2.1.1.13">
szOID_INFOSEC_SuiteAConfidentiality             TEXTEQU <"2.16.840.1.101.2.1.1.14">
szOID_INFOSEC_SuiteAIntegrity                   TEXTEQU <"2.16.840.1.101.2.1.1.15">
szOID_INFOSEC_SuiteATokenProtection             TEXTEQU <"2.16.840.1.101.2.1.1.16">
szOID_INFOSEC_SuiteAKeyManagement               TEXTEQU <"2.16.840.1.101.2.1.1.17">
szOID_INFOSEC_SuiteAKMandSig                    TEXTEQU <"2.16.840.1.101.2.1.1.18">
szOID_INFOSEC_mosaicUpdatedSig                  TEXTEQU <"2.16.840.1.101.2.1.1.19">
szOID_INFOSEC_mosaicKMandUpdSig                 TEXTEQU <"2.16.840.1.101.2.1.1.20">
szOID_INFOSEC_mosaicUpdatedInteg                TEXTEQU <"2.16.840.1.101.2.1.1.21">

szOID_COMMON_NAME                               TEXTEQU <"2.5.4.3">
szOID_SUR_NAME                                  TEXTEQU <"2.5.4.4">
szOID_DEVICE_SERIAL_NUMBER                      TEXTEQU <"2.5.4.5">
szOID_COUNTRY_NAME                              TEXTEQU <"2.5.4.6">
szOID_LOCALITY_NAME                             TEXTEQU <"2.5.4.7">
szOID_STATE_OR_PROVINCE_NAME                    TEXTEQU <"2.5.4.8">
szOID_STREET_ADDRESS                            TEXTEQU <"2.5.4.9">
szOID_ORGANIZATION_NAME                         TEXTEQU <"2.5.4.10">
szOID_ORGANIZATIONAL_UNIT_NAME                  TEXTEQU <"2.5.4.11">
szOID_TITLE                                     TEXTEQU <"2.5.4.12">
szOID_DESCRIPTION                               TEXTEQU <"2.5.4.13">
szOID_SEARCH_GUIDE                              TEXTEQU <"2.5.4.14">
szOID_BUSINESS_CATEGORY                         TEXTEQU <"2.5.4.15">
szOID_POSTAL_ADDRESS                            TEXTEQU <"2.5.4.16">
szOID_POSTAL_CODE                               TEXTEQU <"2.5.4.17">
szOID_POST_OFFICE_BOX                           TEXTEQU <"2.5.4.18">
szOID_PHYSICAL_DELIVERY_OFFICE_NAME             TEXTEQU <"2.5.4.19">
szOID_TELEPHONE_NUMBER                          TEXTEQU <"2.5.4.20">
szOID_TELEX_NUMBER                              TEXTEQU <"2.5.4.21">
szOID_TELETEXT_TERMINAL_IDENTIFIER              TEXTEQU <"2.5.4.22">
szOID_FACSIMILE_TELEPHONE_NUMBER                TEXTEQU <"2.5.4.23">
szOID_X21_ADDRESS                               TEXTEQU <"2.5.4.24">
szOID_INTERNATIONAL_ISDN_NUMBER                 TEXTEQU <"2.5.4.25">
szOID_REGISTERED_ADDRESS                        TEXTEQU <"2.5.4.26">
szOID_DESTINATION_INDICATOR                     TEXTEQU <"2.5.4.27">
szOID_PREFERRED_DELIVERY_METHOD                 TEXTEQU <"2.5.4.28">
szOID_PRESENTATION_ADDRESS                      TEXTEQU <"2.5.4.29">
szOID_SUPPORTED_APPLICATION_CONTEXT             TEXTEQU <"2.5.4.30">
szOID_MEMBER                                    TEXTEQU <"2.5.4.31">
szOID_OWNER                                     TEXTEQU <"2.5.4.32">
szOID_ROLE_OCCUPANT                             TEXTEQU <"2.5.4.33">
szOID_SEE_ALSO                                  TEXTEQU <"2.5.4.34">
szOID_USER_PASSWORD                             TEXTEQU <"2.5.4.35">
szOID_USER_CERTIFICATE                          TEXTEQU <"2.5.4.36">
szOID_CA_CERTIFICATE                            TEXTEQU <"2.5.4.37">
szOID_AUTHORITY_REVOCATION_LIST                 TEXTEQU <"2.5.4.38">
szOID_CERTIFICATE_REVOCATION_LIST               TEXTEQU <"2.5.4.39">
szOID_CROSS_CERTIFICATE_PAIR                    TEXTEQU <"2.5.4.40">
szOID_GIVEN_NAME                                TEXTEQU <"2.5.4.42">
szOID_INITIALS                                  TEXTEQU <"2.5.4.43">
szOID_DN_QUALIFIER                              TEXTEQU <"2.5.4.46">
szOID_DOMAIN_COMPONENT                          TEXTEQU <"0.9.2342.19200300.100.1.25">
szOID_PKCS_12_FRIENDLY_NAME_ATTR                TEXTEQU <"1.2.840.113549.1.9.20">
szOID_PKCS_12_LOCAL_KEY_ID                      TEXTEQU <"1.2.840.113549.1.9.21">
szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR            TEXTEQU <"1.3.6.1.4.1.311.17.1">
szOID_LOCAL_MACHINE_KEYSET                      TEXTEQU <"1.3.6.1.4.1.311.17.2">
szOID_KEYID_RDN                                 TEXTEQU <"1.3.6.1.4.1.311.10.7.1">

CERT_RDN_ANY_TYPE                               EQU     0
CERT_RDN_ENCODED_BLOB                           EQU     1
CERT_RDN_OCTET_STRING                           EQU     2
CERT_RDN_NUMERIC_STRING                         EQU     3
CERT_RDN_PRINTABLE_STRING                       EQU     4
CERT_RDN_TELETEX_STRING                         EQU     5
CERT_RDN_T61_STRING                             EQU     5
CERT_RDN_VIDEOTEX_STRING                        EQU     6
CERT_RDN_IA5_STRING                             EQU     7
CERT_RDN_GRAPHIC_STRING                         EQU     8
CERT_RDN_VISIBLE_STRING                         EQU     9
CERT_RDN_ISO646_STRING                          EQU     9
CERT_RDN_GENERAL_STRING                         EQU     10
CERT_RDN_UNIVERSAL_STRING                       EQU     11
CERT_RDN_INT4_STRING                            EQU     11
CERT_RDN_BMP_STRING                             EQU     12
CERT_RDN_UNICODE_STRING                         EQU     12
CERT_RDN_UTF8_STRING                            EQU     13
CERT_RDN_TYPE_MASK                              EQU     0000000FFH
CERT_RDN_FLAGS_MASK                             EQU     0FF000000H
CERT_RDN_ENABLE_T61_UNICODE_FLAG                EQU     080000000H
CERT_RDN_ENABLE_UTF8_UNICODE_FLAG               EQU     020000000H
CERT_RDN_DISABLE_CHECK_TYPE_FLAG                EQU     040000000H
CERT_RDN_DISABLE_IE4_UTF8_FLAG                  EQU     001000000H

CERT_RSA_PUBLIC_KEY_OBJID                       EQU     szOID_RSA_RSA
CERT_DEFAULT_OID_PUBLIC_KEY_SIGN                EQU     szOID_RSA_RSA
CERT_DEFAULT_OID_PUBLIC_KEY_XCHG                EQU     szOID_RSA_RSA

CERT_V1                                         EQU     0
CERT_V2                                         EQU     1
CERT_V3                                         EQU     2
CERT_INFO_VERSION_FLAG                          EQU     1
CERT_INFO_SERIAL_NUMBER_FLAG                    EQU     2
CERT_INFO_SIGNATURE_ALGORITHM_FLAG              EQU     3
CERT_INFO_ISSUER_FLAG                           EQU     4
CERT_INFO_NOT_BEFORE_FLAG                       EQU     5
CERT_INFO_NOT_AFTER_FLAG                        EQU     6
CERT_INFO_SUBJECT_FLAG                          EQU     7
CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG          EQU     8
CERT_INFO_ISSUER_UNIQUE_ID_FLAG                 EQU     9
CERT_INFO_SUBJECT_UNIQUE_ID_FLAG                EQU     10
CERT_INFO_EXTENSION_FLAG                        EQU     11

CRL_V1                                          EQU     0
CRL_V2                                          EQU     1

CERT_REQUEST_V1                                 EQU     0

CERT_KEYGEN_REQUEST_V1                          EQU     0

CTL_V1                                          EQU     0

CERT_ENCODING_TYPE_MASK                         EQU     00000FFFFH
CMSG_ENCODING_TYPE_MASK                         EQU     0FFFF0000H
CRYPT_ASN_ENCODING                              EQU     000000001H
CRYPT_NDR_ENCODING                              EQU     000000002H
X509_ASN_ENCODING                               EQU     000000001H
X509_NDR_ENCODING                               EQU     000000002H
PKCS_7_ASN_ENCODING                             EQU     000010000H
PKCS_7_NDR_ENCODING                             EQU     000020000H

CRYPT_FORMAT_STR_MULTI_LINE                     EQU     00001H
CRYPT_FORMAT_STR_NO_HEX                         EQU     00010H
CRYPT_FORMAT_SIMPLE                             EQU     00001H
CRYPT_FORMAT_X509                               EQU     00002H
CRYPT_FORMAT_OID                                EQU     00004H
CRYPT_FORMAT_RDN_SEMICOLON                      EQU     00100H
CRYPT_FORMAT_RDN_CRLF                           EQU     00200H
CRYPT_FORMAT_RDN_UNQUOTE                        EQU     00400H
CRYPT_FORMAT_RDN_REVERSE                        EQU     00800H
CRYPT_FORMAT_COMMA                              EQU     01000H
CRYPT_FORMAT_SEMICOLON                          EQU     CRYPT_FORMAT_RDN_SEMICOLON
CRYPT_FORMAT_CRLF                               EQU     CRYPT_FORMAT_RDN_CRLF

CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    EQU     08H
CRYPT_ENCODE_ALLOC_FLAG                         EQU     08000H
CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG EQU       CERT_RDN_ENABLE_T61_UNICODE_FLAG
CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG EQU      CERT_RDN_ENABLE_UTF8_UNICODE_FLAG
CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG EQU       CERT_RDN_DISABLE_CHECK_TYPE_FLAG
CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG EQU      010000H

CRYPT_DECODE_NOCOPY_FLAG                        EQU     01H
CRYPT_DECODE_TO_BE_SIGNED_FLAG                  EQU     02H
CRYPT_DECODE_SHARE_OID_STRING_FLAG              EQU     04H
CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    EQU     08H
CRYPT_DECODE_ALLOC_FLAG                         EQU     08000H
CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG EQU     CERT_RDN_DISABLE_IE4_UTF8_FLAG
CRYPT_ENCODE_DECODE_NONE                        EQU     0

X509_CERT                                       EQU     1
X509_CERT_TO_BE_SIGNED                          EQU     2
X509_CERT_CRL_TO_BE_SIGNED                      EQU     3
X509_CERT_REQUEST_TO_BE_SIGNED                  EQU     4
X509_EXTENSIONS                                 EQU     5
X509_NAME_VALUE                                 EQU     6
X509_NAME                                       EQU     7
X509_PUBLIC_KEY_INFO                            EQU     8
X509_AUTHORITY_KEY_ID                           EQU     9
X509_KEY_ATTRIBUTES                             EQU     10
X509_KEY_USAGE_RESTRICTION                      EQU     11
X509_ALTERNATE_NAME                             EQU     12
X509_BASIC_CONSTRAINTS                          EQU     13
X509_KEY_USAGE                                  EQU     14
X509_BASIC_CONSTRAINTS2                         EQU     15
X509_CERT_POLICIES                              EQU     16
PKCS_UTC_TIME                                   EQU     17
PKCS_TIME_REQUEST                               EQU     18
RSA_CSP_PUBLICKEYBLOB                           EQU     19
X509_UNICODE_NAME                               EQU     20
X509_KEYGEN_REQUEST_TO_BE_SIGNED                EQU     21
PKCS_ATTRIBUTE                                  EQU     22
PKCS_CONTENT_INFO_SEQUENCE_OF_ANY               EQU     23
X509_UNICODE_NAME_VALUE                         EQU     24
X509_ANY_STRING                                 EQU     X509_NAME_VALUE
X509_UNICODE_ANY_STRING                         EQU     X509_UNICODE_NAME_VALUE
X509_OCTET_STRING                               EQU     25
X509_BITS                                       EQU     26
X509_INTEGER                                    EQU     27
X509_MULTI_BYTE_INTEGER                         EQU     28
X509_ENUMERATED                                 EQU     29
X509_CHOICE_OF_TIME                             EQU     30
X509_AUTHORITY_KEY_ID2                          EQU     31
X509_AUTHORITY_INFO_ACCESS                      EQU     32
X509_CRL_REASON_CODE                            EQU     X509_ENUMERATED
PKCS_CONTENT_INFO                               EQU     33
X509_SEQUENCE_OF_ANY                            EQU     34
X509_CRL_DIST_POINTS                            EQU     35
X509_ENHANCED_KEY_USAGE                         EQU     36
PKCS_CTL                                        EQU     37
X509_MULTI_BYTE_UINT                            EQU     38
X509_DSS_PUBLICKEY                              EQU     X509_MULTI_BYTE_UINT
X509_DSS_PARAMETERS                             EQU     39
X509_DSS_SIGNATURE                              EQU     40
PKCS_RC2_CBC_PARAMETERS                         EQU     41
PKCS_SMIME_CAPABILITIES                         EQU     42
PKCS_RSA_PRIVATE_KEY                            EQU     43
PKCS_PRIVATE_KEY_INFO                           EQU     44
PKCS_ENCRYPTED_PRIVATE_KEY_INFO                 EQU     45
X509_PKIX_POLICY_QUALIFIER_USERNOTICE           EQU     46
X509_DH_PUBLICKEY                               EQU     X509_MULTI_BYTE_UINT
X509_DH_PARAMETERS                              EQU     47
PKCS_ATTRIBUTES                                 EQU     48
PKCS_SORTED_CTL                                 EQU     49
X942_DH_PARAMETERS                              EQU     50
X509_BITS_WITHOUT_TRAILING_ZEROES               EQU     51
X942_OTHER_INFO                                 EQU     52
PKCS7_SIGNER_INFO                               EQU     500
CMS_SIGNER_INFO                                 EQU     501

szOID_AUTHORITY_KEY_IDENTIFIER                  TEXTEQU <"2.5.29.1">
szOID_KEY_ATTRIBUTES                            TEXTEQU <"2.5.29.2">
szOID_CERT_POLICIES_95                          TEXTEQU <"2.5.29.3">
szOID_KEY_USAGE_RESTRICTION                     TEXTEQU <"2.5.29.4">
szOID_SUBJECT_ALT_NAME                          TEXTEQU <"2.5.29.7">
szOID_ISSUER_ALT_NAME                           TEXTEQU <"2.5.29.8">
szOID_BASIC_CONSTRAINTS                         TEXTEQU <"2.5.29.10">
szOID_KEY_USAGE                                 TEXTEQU <"2.5.29.15">
szOID_PRIVATEKEY_USAGE_PERIOD                   TEXTEQU <"2.5.29.16">
szOID_BASIC_CONSTRAINTS2                        TEXTEQU <"2.5.29.19">
szOID_CERT_POLICIES                             TEXTEQU <"2.5.29.32">
szOID_AUTHORITY_KEY_IDENTIFIER2                 TEXTEQU <"2.5.29.35">
szOID_SUBJECT_KEY_IDENTIFIER                    TEXTEQU <"2.5.29.14">
szOID_SUBJECT_ALT_NAME2                         TEXTEQU <"2.5.29.17">
szOID_ISSUER_ALT_NAME2                          TEXTEQU <"2.5.29.18">
szOID_CRL_REASON_CODE                           TEXTEQU <"2.5.29.21">
szOID_CRL_DIST_POINTS                           TEXTEQU <"2.5.29.31">
szOID_ENHANCED_KEY_USAGE                        TEXTEQU <"2.5.29.37">
szOID_RENEWAL_CERTIFICATE                       TEXTEQU <"1.3.6.1.4.1.311.13.1">
szOID_ENROLLMENT_NAME_VALUE_PAIR                TEXTEQU <"1.3.6.1.4.1.311.13.2.1">
szOID_ENROLLMENT_CSP_PROVIDER                   TEXTEQU <"1.3.6.1.4.1.311.13.2.2">
szOID_OS_VERSION                                TEXTEQU <"1.3.6.1.4.1.311.13.2.3">
szOID_ENROLLMENT_AGENT                          TEXTEQU <"1.3.6.1.4.1.311.20.2.1">
szOID_PKIX                                      TEXTEQU <"1.3.6.1.5.5.7">
szOID_PKIX_PE                                   TEXTEQU <"1.3.6.1.5.5.7.1">
szOID_AUTHORITY_INFO_ACCESS                     TEXTEQU <"1.3.6.1.5.5.7.1.1">
szOID_CERT_EXTENSIONS                           TEXTEQU <"1.3.6.1.4.1.311.2.1.14">
szOID_NEXT_UPDATE_LOCATION                      TEXTEQU <"1.3.6.1.4.1.311.10.2">
szOID_CTL                                       TEXTEQU <"1.3.6.1.4.1.311.10.1">
szOID_SORTED_CTL                                TEXTEQU <"1.3.6.1.4.1.311.10.1.1">

IFNDEF szOID_SERIALIZED
    szOID_SERIALIZED                            TEXTEQU <"1.3.6.1.4.1.311.10.3.3.1">
ENDIF

IFNDEF szOID_NT_PRINCIPAL_NAME
    szOID_NT_PRINCIPAL_NAME                     TEXTEQU <"1.3.6.1.4.1.311.20.2.3">
ENDIF

IFNDEF szOID_PRODUCT_UPDATE
    szOID_PRODUCT_UPDATE                        TEXTEQU <"1.3.6.1.4.1.311.31.1">
ENDIF

szOID_AUTO_ENROLL_CTL_USAGE                     TEXTEQU <"1.3.6.1.4.1.311.20.1">
szOID_ENROLL_CERTTYPE_EXTENSION                 TEXTEQU <"1.3.6.1.4.1.311.20.2">
szOID_CERT_MANIFOLD                             TEXTEQU <"1.3.6.1.4.1.311.20.3">

IFNDEF szOID_CERTSRV_CA_VERSION
    szOID_CERTSRV_CA_VERSION                    TEXTEQU <"1.3.6.1.4.1.311.21.1">
ENDIF

szOID_NTDS_REPLICATION                          TEXTEQU <"1.3.6.1.4.1.311.25.1">
szOID_POLICY_MAPPINGS                           TEXTEQU <"2.5.29.5">
szOID_SUBJECT_DIR_ATTRS                         TEXTEQU <"2.5.29.9">
szOID_PKIX_KP                                   TEXTEQU <"1.3.6.1.5.5.7.3">
szOID_PKIX_KP_SERVER_AUTH                       TEXTEQU <"1.3.6.1.5.5.7.3.1">
szOID_PKIX_KP_CLIENT_AUTH                       TEXTEQU <"1.3.6.1.5.5.7.3.2">
szOID_PKIX_KP_CODE_SIGNING                      TEXTEQU <"1.3.6.1.5.5.7.3.3">
szOID_PKIX_KP_EMAIL_PROTECTION                  TEXTEQU <"1.3.6.1.5.5.7.3.4">
szOID_PKIX_KP_IPSEC_END_SYSTEM                  TEXTEQU <"1.3.6.1.5.5.7.3.5">
szOID_PKIX_KP_IPSEC_TUNNEL                      TEXTEQU <"1.3.6.1.5.5.7.3.6">
szOID_PKIX_KP_IPSEC_USER                        TEXTEQU <"1.3.6.1.5.5.7.3.7">
szOID_PKIX_KP_TIMESTAMP_SIGNING                 TEXTEQU <"1.3.6.1.5.5.7.3.8">
szOID_KP_CTL_USAGE_SIGNING                      TEXTEQU <"1.3.6.1.4.1.311.10.3.1">
szOID_KP_TIME_STAMP_SIGNING                     TEXTEQU <"1.3.6.1.4.1.311.10.3.2">

IFNDEF szOID_SERVER_GATED_CRYPTO
    szOID_SERVER_GATED_CRYPTO                   TEXTEQU <"1.3.6.1.4.1.311.10.3.3">
ENDIF
IFNDEF szOID_SGC_NETSCAPE
    szOID_SGC_NETSCAPE                          TEXTEQU <"2.16.840.1.113730.4.1">
ENDIF

szOID_KP_EFS                                    TEXTEQU <"1.3.6.1.4.1.311.10.3.4">
szOID_WHQL_CRYPTO                               TEXTEQU <"1.3.6.1.4.1.311.10.3.5">
szOID_NT5_CRYPTO                                TEXTEQU <"1.3.6.1.4.1.311.10.3.6">
szOID_OEM_WHQL_CRYPTO                           TEXTEQU <"1.3.6.1.4.1.311.10.3.7">
szOID_EMBEDDED_NT_CRYPTO                        TEXTEQU <"1.3.6.1.4.1.311.10.3.8">

IFNDEF szOID_DRM
    szOID_DRM                                   TEXTEQU <"1.3.6.1.4.1.311.10.5.1">
ENDIF

IFNDEF szOID_LICENSES
    szOID_LICENSES                              TEXTEQU <"1.3.6.1.4.1.311.10.6.1">
ENDIF

IFNDEF szOID_LICENSE_SERVER
    szOID_LICENSE_SERVER                        TEXTEQU <"1.3.6.1.4.1.311.10.6.2">
ENDIF

IFNDEF szOID_KP_SMARTCARD_LOGON
    szOID_KP_SMARTCARD_LOGON                    TEXTEQU <"1.3.6.1.4.1.311.20.2.2">
ENDIF

szOID_YESNO_TRUST_ATTR                          TEXTEQU <"1.3.6.1.4.1.311.10.4.1">
szOID_PKIX_POLICY_QUALIFIER_CPS                 TEXTEQU <"1.3.6.1.5.5.7.2.1">
szOID_PKIX_POLICY_QUALIFIER_USERNOTICE          TEXTEQU <"1.3.6.1.5.5.7.2.2">
szOID_CERT_POLICIES_95_QUALIFIER1               TEXTEQU <"2.16.840.1.113733.1.7.1.1">

CERT_UNICODE_RDN_ERR_INDEX_MASK                 EQU     03FFH
CERT_UNICODE_RDN_ERR_INDEX_SHIFT                EQU     22
CERT_UNICODE_ATTR_ERR_INDEX_MASK                EQU     0003FH
CERT_UNICODE_ATTR_ERR_INDEX_SHIFT               EQU     16
CERT_UNICODE_VALUE_ERR_INDEX_MASK               EQU     00000FFFFH
CERT_UNICODE_VALUE_ERR_INDEX_SHIFT              EQU     0

CERT_DIGITAL_SIGNATURE_KEY_USAGE                EQU     080H
CERT_NON_REPUDIATION_KEY_USAGE                  EQU     040H
CERT_KEY_ENCIPHERMENT_KEY_USAGE                 EQU     020H
CERT_DATA_ENCIPHERMENT_KEY_USAGE                EQU     010H
CERT_KEY_AGREEMENT_KEY_USAGE                    EQU     008H
CERT_KEY_CERT_SIGN_KEY_USAGE                    EQU     004H
CERT_OFFLINE_CRL_SIGN_KEY_USAGE                 EQU     002H
CERT_CRL_SIGN_KEY_USAGE                         EQU     002H
CERT_ENCIPHER_ONLY_KEY_USAGE                    EQU     001H
CERT_DECIPHER_ONLY_KEY_USAGE                    EQU     080H

CERT_ALT_NAME_OTHER_NAME                        EQU     1
CERT_ALT_NAME_RFC822_NAME                       EQU     2
CERT_ALT_NAME_DNS_NAME                          EQU     3
CERT_ALT_NAME_X400_ADDRESS                      EQU     4
CERT_ALT_NAME_DIRECTORY_NAME                    EQU     5
CERT_ALT_NAME_EDI_PARTY_NAME                    EQU     6
CERT_ALT_NAME_URL                               EQU     7
CERT_ALT_NAME_IP_ADDRESS                        EQU     8
CERT_ALT_NAME_REGISTERED_ID                     EQU     9

CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK              EQU     0FFH
CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT             EQU     16
CERT_ALT_NAME_VALUE_ERR_INDEX_MASK              EQU     00000FFFFH
CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT             EQU     0

CERT_CA_SUBJECT_FLAG                            EQU     080H
CERT_END_ENTITY_SUBJECT_FLAG                    EQU     040H

szOID_PKIX_ACC_DESCR                            TEXTEQU <"1.3.6.1.5.5.7.48">
szOID_PKIX_OCSP                                 TEXTEQU <"1.3.6.1.5.5.7.48.1">
szOID_PKIX_CA_ISSUERS                           TEXTEQU <"1.3.6.1.5.5.7.48.2">

CRL_REASON_UNSPECIFIED                          EQU     0
CRL_REASON_KEY_COMPROMISE                       EQU     1
CRL_REASON_CA_COMPROMISE                        EQU     2
CRL_REASON_AFFILIATION_CHANGED                  EQU     3
CRL_REASON_SUPERSEDED                           EQU     4
CRL_REASON_CESSATION_OF_OPERATION               EQU     5
CRL_REASON_CERTIFICATE_HOLD                     EQU     6
CRL_REASON_REMOVE_FROM_CRL                      EQU     8

CRL_DIST_POINT_NO_NAME                          EQU     0
CRL_DIST_POINT_FULL_NAME                        EQU     1
CRL_DIST_POINT_ISSUER_RDN_NAME                  EQU     2

CRL_REASON_UNUSED_FLAG                          EQU     080H
CRL_REASON_KEY_COMPROMISE_FLAG                  EQU     040H
CRL_REASON_CA_COMPROMISE_FLAG                   EQU     020H
CRL_REASON_AFFILIATION_CHANGED_FLAG             EQU     010H
CRL_REASON_SUPERSEDED_FLAG                      EQU     008H
CRL_REASON_CESSATION_OF_OPERATION_FLAG          EQU     004H
CRL_REASON_CERTIFICATE_HOLD_FLAG                EQU     002H

CRL_DIST_POINT_ERR_INDEX_MASK                   EQU     07FH
CRL_DIST_POINT_ERR_INDEX_SHIFT                  EQU     24
CRL_DIST_POINT_ERR_CRL_ISSUER_BIT               EQU     080000000H
SORTED_CTL_EXT_FLAGS_OFFSET                     EQU     (0)
SORTED_CTL_EXT_COUNT_OFFSET                     EQU     (4)
SORTED_CTL_EXT_MAX_COLLISION_OFFSET             EQU     (8)
SORTED_CTL_EXT_HASH_BUCKET_OFFSET               EQU     (12)
SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG   EQU     01H

CERT_DSS_R_LEN                                  EQU     20
CERT_DSS_S_LEN                                  EQU     20
CERT_DSS_SIGNATURE_LEN                          EQU     (CERT_DSS_R_LEN + CERT_DSS_S_LEN)
CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN          EQU     48

CRYPT_X942_COUNTER_BYTE_LENGTH                  EQU     4
CRYPT_X942_KEY_LENGTH_BYTE_LENGTH               EQU     4
CRYPT_X942_PUB_INFO_BYTE_LENGTH                 EQU     64

CRYPT_RC2_40BIT_VERSION                         EQU     160
CRYPT_RC2_56BIT_VERSION                         EQU     52
CRYPT_RC2_64BIT_VERSION                         EQU     120
CRYPT_RC2_128BIT_VERSION                        EQU     58

szOID_NETSCAPE                                  TEXTEQU <"2.16.840.1.113730">
szOID_NETSCAPE_CERT_EXTENSION                   TEXTEQU <"2.16.840.1.113730.1">
szOID_NETSCAPE_CERT_TYPE                        TEXTEQU <"2.16.840.1.113730.1.1">
szOID_NETSCAPE_BASE_URL                         TEXTEQU <"2.16.840.1.113730.1.2">
szOID_NETSCAPE_REVOCATION_URL                   TEXTEQU <"2.16.840.1.113730.1.3">
szOID_NETSCAPE_CA_REVOCATION_URL                TEXTEQU <"2.16.840.1.113730.1.4">
szOID_NETSCAPE_CERT_RENEWAL_URL                 TEXTEQU <"2.16.840.1.113730.1.7">
szOID_NETSCAPE_CA_POLICY_URL                    TEXTEQU <"2.16.840.1.113730.1.8">
szOID_NETSCAPE_SSL_SERVER_NAME                  TEXTEQU <"2.16.840.1.113730.1.12">
szOID_NETSCAPE_COMMENT                          TEXTEQU <"2.16.840.1.113730.1.13">
szOID_NETSCAPE_DATA_TYPE                        TEXTEQU <"2.16.840.1.113730.2">
szOID_NETSCAPE_CERT_SEQUENCE                    TEXTEQU <"2.16.840.1.113730.2.5">

NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE              EQU     080H
NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE              EQU     040H
NETSCAPE_SMIME_CERT_TYPE                        EQU     020H
NETSCAPE_SIGN_CERT_TYPE                         EQU     010H
NETSCAPE_SSL_CA_CERT_TYPE                       EQU     004H
NETSCAPE_SMIME_CA_CERT_TYPE                     EQU     002H
NETSCAPE_SIGN_CA_CERT_TYPE                      EQU     001H

CRYPT_OID_ENCODE_OBJECT_FUNC                    TEXTEQU <"CryptDllEncodeObject">
CRYPT_OID_DECODE_OBJECT_FUNC                    TEXTEQU <"CryptDllDecodeObject">
CRYPT_OID_ENCODE_OBJECT_EX_FUNC                 TEXTEQU <"CryptDllEncodeObjectEx">
CRYPT_OID_DECODE_OBJECT_EX_FUNC                 TEXTEQU <"CryptDllDecodeObjectEx">
CRYPT_OID_CREATE_COM_OBJECT_FUNC                TEXTEQU <"CryptDllCreateCOMObject">
CRYPT_OID_VERIFY_REVOCATION_FUNC                TEXTEQU <"CertDllVerifyRevocation">
CRYPT_OID_VERIFY_CTL_USAGE_FUNC                 TEXTEQU <"CertDllVerifyCTLUsage">
CRYPT_OID_FORMAT_OBJECT_FUNC                    TEXTEQU <"CryptDllFormatObject">
CRYPT_OID_FIND_OID_INFO_FUNC                    TEXTEQU <"CryptDllFindOIDInfo">
CRYPT_OID_FIND_LOCALIZED_NAME_FUNC              TEXTEQU <"CryptDllFindLocalizedName">
CRYPT_OID_REGPATH                               TEXTEQU <"Software\Microsoft\Cryptography\OID">
CRYPT_OID_REG_ENCODING_TYPE_PREFIX              TEXTEQU <"EncodingType ">
CRYPT_OID_REG_DLL_VALUE_NAME                    EQU     L("Dll")
CRYPT_OID_REG_FUNC_NAME_VALUE_NAME              EQU     L("FuncName")
CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A            TEXTEQU <"FuncName">
CRYPT_OID_REG_FLAGS_VALUE_NAME                  EQU     L("CryptFlags")
CRYPT_DEFAULT_OID                               EQU     L("DEFAULT")

CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG              EQU     1

CRYPT_GET_INSTALLED_OID_FUNC_FLAG               EQU     1

CRYPT_REGISTER_FIRST_INDEX                      EQU     0
CRYPT_REGISTER_LAST_INDEX                       EQU     0FFFFFFFFH

CRYPT_MATCH_ANY_ENCODING_TYPE                   EQU     0FFFFFFFFH

CRYPT_HASH_ALG_OID_GROUP_ID                     EQU     1
CRYPT_ENCRYPT_ALG_OID_GROUP_ID                  EQU     2
CRYPT_PUBKEY_ALG_OID_GROUP_ID                   EQU     3
CRYPT_SIGN_ALG_OID_GROUP_ID                     EQU     4
CRYPT_RDN_ATTR_OID_GROUP_ID                     EQU     5
CRYPT_EXT_OR_ATTR_OID_GROUP_ID                  EQU     6
CRYPT_ENHKEY_USAGE_OID_GROUP_ID                 EQU     7
CRYPT_POLICY_OID_GROUP_ID                       EQU     8
CRYPT_LAST_OID_GROUP_ID                         EQU     8
CRYPT_FIRST_ALG_OID_GROUP_ID                    EQU     CRYPT_HASH_ALG_OID_GROUP_ID
CRYPT_LAST_ALG_OID_GROUP_ID                     EQU     CRYPT_SIGN_ALG_OID_GROUP_ID
CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG         EQU     01H
CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG        EQU     02H
CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG           EQU     04H

CRYPT_OID_INFO_OID_KEY                          EQU     1
CRYPT_OID_INFO_NAME_KEY                         EQU     2
CRYPT_OID_INFO_ALGID_KEY                        EQU     3
CRYPT_OID_INFO_SIGN_KEY                         EQU     4

CRYPT_INSTALL_OID_INFO_BEFORE_FLAG              EQU     1

CRYPT_LOCALIZED_NAME_ENCODING_TYPE              EQU     0
CRYPT_LOCALIZED_NAME_OID                        TEXTEQU <"LocalizedNames">

szOID_PKCS_7_DATA                               TEXTEQU <"1.2.840.113549.1.7.1">
szOID_PKCS_7_SIGNED                             TEXTEQU <"1.2.840.113549.1.7.2">
szOID_PKCS_7_ENVELOPED                          TEXTEQU <"1.2.840.113549.1.7.3">
szOID_PKCS_7_SIGNEDANDENVELOPED                 TEXTEQU <"1.2.840.113549.1.7.4">
szOID_PKCS_7_DIGESTED                           TEXTEQU <"1.2.840.113549.1.7.5">
szOID_PKCS_7_ENCRYPTED                          TEXTEQU <"1.2.840.113549.1.7.6">
szOID_PKCS_9_CONTENT_TYPE                       TEXTEQU <"1.2.840.113549.1.9.3">
szOID_PKCS_9_MESSAGE_DIGEST                     TEXTEQU <"1.2.840.113549.1.9.4">

CMSG_DATA                                       EQU     1
CMSG_SIGNED                                     EQU     2
CMSG_ENVELOPED                                  EQU     3
CMSG_SIGNED_AND_ENVELOPED                       EQU     4
CMSG_HASHED                                     EQU     5
CMSG_ENCRYPTED                                  EQU     6
CMSG_ALL_FLAGS                                  EQU     (-1)
CMSG_DATA_FLAG                                  EQU     (1 SHL CMSG_DATA)
CMSG_SIGNED_FLAG                                EQU     (1 SHL CMSG_SIGNED)
CMSG_ENVELOPED_FLAG                             EQU     (1 SHL CMSG_ENVELOPED)
CMSG_SIGNED_AND_ENVELOPED_FLAG                  EQU     (1 SHL CMSG_SIGNED_AND_ENVELOPED)
CMSG_HASHED_FLAG                                EQU     (1 SHL CMSG_HASHED)
CMSG_ENCRYPTED_FLAG                             EQU     (1 SHL CMSG_ENCRYPTED)

CERT_ID_ISSUER_SERIAL_NUMBER                    EQU     1
CERT_ID_KEY_IDENTIFIER                          EQU     2
CERT_ID_SHA1_HASH                               EQU     3

CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE             EQU     1
CMSG_KEY_AGREE_STATIC_KEY_CHOICE                EQU     2

CMSG_MAIL_LIST_HANDLE_KEY_CHOICE                EQU     1

CMSG_KEY_TRANS_RECIPIENT                        EQU     1
CMSG_KEY_AGREE_RECIPIENT                        EQU     2
CMSG_MAIL_LIST_RECIPIENT                        EQU     3

CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG                EQU     080000000H

CMSG_RC4_NO_SALT_FLAG                           EQU     040000000H

CMSG_INDEFINITE_LENGTH                          EQU     0FFFFFFFFH

CMSG_BARE_CONTENT_FLAG                          EQU     000000001H
CMSG_LENGTH_ONLY_FLAG                           EQU     000000002H
CMSG_DETACHED_FLAG                              EQU     000000004H
CMSG_AUTHENTICATED_ATTRIBUTES_FLAG              EQU     000000008H
CMSG_CONTENTS_OCTETS_FLAG                       EQU     000000010H
CMSG_MAX_LENGTH_FLAG                            EQU     000000020H
CMSG_CMS_ENCAPSULATED_CONTENT_FLAG              EQU     000000040H
CMSG_CRYPT_RELEASE_CONTEXT_FLAG                 EQU     000008000H

CMSG_TYPE_PARAM                                 EQU     1
CMSG_CONTENT_PARAM                              EQU     2
CMSG_BARE_CONTENT_PARAM                         EQU     3
CMSG_INNER_CONTENT_TYPE_PARAM                   EQU     4
CMSG_SIGNER_COUNT_PARAM                         EQU     5
CMSG_SIGNER_INFO_PARAM                          EQU     6
CMSG_SIGNER_CERT_INFO_PARAM                     EQU     7
CMSG_SIGNER_HASH_ALGORITHM_PARAM                EQU     8
CMSG_SIGNER_AUTH_ATTR_PARAM                     EQU     9
CMSG_SIGNER_UNAUTH_ATTR_PARAM                   EQU     10
CMSG_CERT_COUNT_PARAM                           EQU     11
CMSG_CERT_PARAM                                 EQU     12
CMSG_CRL_COUNT_PARAM                            EQU     13
CMSG_CRL_PARAM                                  EQU     14
CMSG_ENVELOPE_ALGORITHM_PARAM                   EQU     15
CMSG_RECIPIENT_COUNT_PARAM                      EQU     17
CMSG_RECIPIENT_INDEX_PARAM                      EQU     18
CMSG_RECIPIENT_INFO_PARAM                       EQU     19
CMSG_HASH_ALGORITHM_PARAM                       EQU     20
CMSG_HASH_DATA_PARAM                            EQU     21
CMSG_COMPUTED_HASH_PARAM                        EQU     22
CMSG_ENCRYPT_PARAM                              EQU     26
CMSG_ENCRYPTED_DIGEST                           EQU     27
CMSG_ENCODED_SIGNER                             EQU     28
CMSG_ENCODED_MESSAGE                            EQU     29
CMSG_VERSION_PARAM                              EQU     30
CMSG_ATTR_CERT_COUNT_PARAM                      EQU     31
CMSG_ATTR_CERT_PARAM                            EQU     32
CMSG_CMS_RECIPIENT_COUNT_PARAM                  EQU     33
CMSG_CMS_RECIPIENT_INDEX_PARAM                  EQU     34
CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM    EQU     35
CMSG_CMS_RECIPIENT_INFO_PARAM                   EQU     36
CMSG_UNPROTECTED_ATTR_PARAM                     EQU     37
CMSG_SIGNER_CERT_ID_PARAM                       EQU     38
CMSG_CMS_SIGNER_INFO_PARAM                      EQU     39

CMSG_SIGNED_DATA_V1                             EQU     1
CMSG_SIGNED_DATA_V3                             EQU     3
CMSG_SIGNED_DATA_PKCS_1_5_VERSION               EQU     CMSG_SIGNED_DATA_V1
CMSG_SIGNED_DATA_CMS_VERSION                    EQU     CMSG_SIGNED_DATA_V3
CMSG_SIGNER_INFO_V1                             EQU     1
CMSG_SIGNER_INFO_V3                             EQU     3
CMSG_SIGNER_INFO_PKCS_1_5_VERSION               EQU     CMSG_SIGNER_INFO_V1
CMSG_SIGNER_INFO_CMS_VERSION                    EQU     CMSG_SIGNER_INFO_V3
CMSG_HASHED_DATA_V0                             EQU     0
CMSG_HASHED_DATA_V2                             EQU     2
CMSG_HASHED_DATA_PKCS_1_5_VERSION               EQU     CMSG_HASHED_DATA_V0
CMSG_HASHED_DATA_CMS_VERSION                    EQU     CMSG_HASHED_DATA_V2
CMSG_ENVELOPED_DATA_V0                          EQU     0
CMSG_ENVELOPED_DATA_V2                          EQU     2
CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION            EQU     CMSG_ENVELOPED_DATA_V0
CMSG_ENVELOPED_DATA_CMS_VERSION                 EQU     CMSG_ENVELOPED_DATA_V2

CMSG_KEY_AGREE_ORIGINATOR_CERT                  EQU     1
CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY            EQU     2

CMSG_ENVELOPED_RECIPIENT_V0                     EQU     0
CMSG_ENVELOPED_RECIPIENT_V2                     EQU     2
CMSG_ENVELOPED_RECIPIENT_V3                     EQU     3
CMSG_ENVELOPED_RECIPIENT_V4                     EQU     4
CMSG_KEY_TRANS_PKCS_1_5_VERSION                 EQU     CMSG_ENVELOPED_RECIPIENT_V0
CMSG_KEY_TRANS_CMS_VERSION                      EQU     CMSG_ENVELOPED_RECIPIENT_V2
CMSG_KEY_AGREE_VERSION                          EQU     CMSG_ENVELOPED_RECIPIENT_V3
CMSG_MAIL_LIST_VERSION                          EQU     CMSG_ENVELOPED_RECIPIENT_V4

CMSG_CTRL_VERIFY_SIGNATURE                      EQU     1
CMSG_CTRL_DECRYPT                               EQU     2
CMSG_CTRL_VERIFY_HASH                           EQU     5
CMSG_CTRL_ADD_SIGNER                            EQU     6
CMSG_CTRL_DEL_SIGNER                            EQU     7
CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR                EQU     8
CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR                EQU     9
CMSG_CTRL_ADD_CERT                              EQU     10
CMSG_CTRL_DEL_CERT                              EQU     11
CMSG_CTRL_ADD_CRL                               EQU     12
CMSG_CTRL_DEL_CRL                               EQU     13
CMSG_CTRL_ADD_ATTR_CERT                         EQU     14
CMSG_CTRL_DEL_ATTR_CERT                         EQU     15
CMSG_CTRL_KEY_TRANS_DECRYPT                     EQU     16
CMSG_CTRL_KEY_AGREE_DECRYPT                     EQU     17
CMSG_CTRL_MAIL_LIST_DECRYPT                     EQU     18
CMSG_CTRL_VERIFY_SIGNATURE_EX                   EQU     19
CMSG_CTRL_ADD_CMS_SIGNER_INFO                   EQU     20

CMSG_VERIFY_SIGNER_PUBKEY                       EQU     1
CMSG_VERIFY_SIGNER_CERT                         EQU     2
CMSG_VERIFY_SIGNER_CHAIN                        EQU     3

CMSG_OID_GEN_ENCRYPT_KEY_FUNC                   TEXTEQU <"CryptMsgDllGenEncryptKey">
CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC                TEXTEQU <"CryptMsgDllExportEncryptKey">
CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC                TEXTEQU <"CryptMsgDllImportEncryptKey">
CMSG_DEFAULT_INSTALLABLE_FUNC_OID               EQU     1

CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG       EQU     000000001H
CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG             EQU     000000001H
CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG       EQU     000008000H
CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC           TEXTEQU <"CryptMsgDllGenContentEncryptKey">

CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG           EQU     000000001H
CMSG_OID_EXPORT_KEY_TRANS_FUNC                  TEXTEQU <"CryptMsgDllExportKeyTrans">

CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG           EQU     000000001H
CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG       EQU     000000002H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG     EQU     000000004H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG    EQU     000000008H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG    EQU     000000010H
CMSG_OID_EXPORT_KEY_AGREE_FUNC                  TEXTEQU <"CryptMsgDllExportKeyAgree">

CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG           EQU     000000001H
CMSG_OID_EXPORT_MAIL_LIST_FUNC                  TEXTEQU <"CryptMsgDllExportMailList">
CMSG_OID_IMPORT_KEY_TRANS_FUNC                  TEXTEQU <"CryptMsgDllImportKeyTrans">
CMSG_OID_IMPORT_KEY_AGREE_FUNC                  TEXTEQU <"CryptMsgDllImportKeyAgree">
CMSG_OID_IMPORT_MAIL_LIST_FUNC                  TEXTEQU <"CryptMsgDllImportMailList">

CERT_KEY_PROV_HANDLE_PROP_ID                    EQU     1
CERT_KEY_PROV_INFO_PROP_ID                      EQU     2
CERT_SHA1_HASH_PROP_ID                          EQU     3
CERT_MD5_HASH_PROP_ID                           EQU     4
CERT_HASH_PROP_ID                               EQU     CERT_SHA1_HASH_PROP_ID
CERT_KEY_CONTEXT_PROP_ID                        EQU     5
CERT_KEY_SPEC_PROP_ID                           EQU     6
CERT_IE30_RESERVED_PROP_ID                      EQU     7
CERT_PUBKEY_HASH_RESERVED_PROP_ID               EQU     8
CERT_ENHKEY_USAGE_PROP_ID                       EQU     9
CERT_CTL_USAGE_PROP_ID                          EQU     CERT_ENHKEY_USAGE_PROP_ID
CERT_NEXT_UPDATE_LOCATION_PROP_ID               EQU     10
CERT_FRIENDLY_NAME_PROP_ID                      EQU     11
CERT_PVK_FILE_PROP_ID                           EQU     12
CERT_DESCRIPTION_PROP_ID                        EQU     13
CERT_ACCESS_STATE_PROP_ID                       EQU     14
CERT_SIGNATURE_HASH_PROP_ID                     EQU     15
CERT_SMART_CARD_DATA_PROP_ID                    EQU     16
CERT_EFS_PROP_ID                                EQU     17
CERT_FORTEZZA_DATA_PROP_ID                      EQU     18
CERT_ARCHIVED_PROP_ID                           EQU     19
CERT_KEY_IDENTIFIER_PROP_ID                     EQU     20
CERT_AUTO_ENROLL_PROP_ID                        EQU     21
CERT_PUBKEY_ALG_PARA_PROP_ID                    EQU     22
CERT_FIRST_RESERVED_PROP_ID                     EQU     23
CERT_LAST_RESERVED_PROP_ID                      EQU     000007FFFH
CERT_FIRST_USER_PROP_ID                         EQU     000008000H
CERT_LAST_USER_PROP_ID                          EQU     00000FFFFH
CERT_ACCESS_STATE_WRITE_PERSIST_FLAG            EQU     01H
CERT_ACCESS_STATE_SYSTEM_STORE_FLAG             EQU     02H

CERT_SET_KEY_PROV_HANDLE_PROP_ID                EQU     000000001H
CERT_SET_KEY_CONTEXT_PROP_ID                    EQU     000000001H

CERT_STORE_PROV_MSG                             EQU     (1)
CERT_STORE_PROV_MEMORY                          EQU     (2)
CERT_STORE_PROV_FILE                            EQU     (3)
CERT_STORE_PROV_REG                             EQU     (4)
CERT_STORE_PROV_PKCS7                           EQU     (5)
CERT_STORE_PROV_SERIALIZED                      EQU     (6)
CERT_STORE_PROV_FILENAME_A                      EQU     (7)
CERT_STORE_PROV_FILENAME_W                      EQU     (8)
CERT_STORE_PROV_FILENAME                        EQU     CERT_STORE_PROV_FILENAME_W
CERT_STORE_PROV_SYSTEM_A                        EQU     (9)
CERT_STORE_PROV_SYSTEM_W                        EQU     (10)
CERT_STORE_PROV_SYSTEM                          EQU     CERT_STORE_PROV_SYSTEM_W
CERT_STORE_PROV_COLLECTION                      EQU     (11)
CERT_STORE_PROV_SYSTEM_REGISTRY_A               EQU     (12)
CERT_STORE_PROV_SYSTEM_REGISTRY_W               EQU     (13)
CERT_STORE_PROV_SYSTEM_REGISTRY                 EQU     CERT_STORE_PROV_SYSTEM_REGISTRY_W
CERT_STORE_PROV_PHYSICAL_W                      EQU     (14)
CERT_STORE_PROV_PHYSICAL                        EQU     CERT_STORE_PROV_PHYSICAL_W
CERT_STORE_PROV_SMART_CARD_W                    EQU     (15)
CERT_STORE_PROV_SMART_CARD                      EQU     CERT_STORE_PROV_SMART_CARD_W
CERT_STORE_PROV_LDAP_W                          EQU     (16)
CERT_STORE_PROV_LDAP                            EQU     CERT_STORE_PROV_LDAP_W

sz_CERT_STORE_PROV_MEMORY                       TEXTEQU <"Memory">
sz_CERT_STORE_PROV_FILENAME_W                   TEXTEQU <"File">
sz_CERT_STORE_PROV_FILENAME                     EQU     sz_CERT_STORE_PROV_FILENAME_W
sz_CERT_STORE_PROV_SYSTEM_W                     TEXTEQU <"System">
sz_CERT_STORE_PROV_SYSTEM                       EQU     sz_CERT_STORE_PROV_SYSTEM_W
sz_CERT_STORE_PROV_PKCS7                        TEXTEQU <"PKCS7">
sz_CERT_STORE_PROV_SERIALIZED                   TEXTEQU <"Serialized">
sz_CERT_STORE_PROV_COLLECTION                   TEXTEQU <"Collection">
sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W            TEXTEQU <"SystemRegistry">
sz_CERT_STORE_PROV_SYSTEM_REGISTRY              EQU     sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
sz_CERT_STORE_PROV_PHYSICAL_W                   TEXTEQU <"Physical">
sz_CERT_STORE_PROV_PHYSICAL                     EQU     sz_CERT_STORE_PROV_PHYSICAL_W
sz_CERT_STORE_PROV_SMART_CARD_W                 TEXTEQU <"SmartCard">
sz_CERT_STORE_PROV_SMART_CARD                   EQU     sz_CERT_STORE_PROV_SMART_CARD_W
sz_CERT_STORE_PROV_LDAP_W                       TEXTEQU <"Ldap">
sz_CERT_STORE_PROV_LDAP                         EQU     sz_CERT_STORE_PROV_LDAP_W

CERT_STORE_SIGNATURE_FLAG                       EQU     000000001H
CERT_STORE_TIME_VALIDITY_FLAG                   EQU     000000002H
CERT_STORE_REVOCATION_FLAG                      EQU     000000004H
CERT_STORE_NO_CRL_FLAG                          EQU     000010000H
CERT_STORE_NO_ISSUER_FLAG                       EQU     000020000H
CERT_STORE_NO_CRYPT_RELEASE_FLAG                EQU     000000001H
CERT_STORE_SET_LOCALIZED_NAME_FLAG              EQU     000000002H
CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG     EQU     000000004H
CERT_STORE_DELETE_FLAG                          EQU     000000010H
CERT_STORE_MANIFOLD_FLAG                        EQU     000000100H
CERT_STORE_ENUM_ARCHIVED_FLAG                   EQU     000000200H
CERT_STORE_UPDATE_KEYID_FLAG                    EQU     000000400H
CERT_STORE_READONLY_FLAG                        EQU     000008000H
CERT_STORE_OPEN_EXISTING_FLAG                   EQU     000004000H
CERT_STORE_CREATE_NEW_FLAG                      EQU     000002000H
CERT_STORE_MAXIMUM_ALLOWED_FLAG                 EQU     000001000H
CERT_SYSTEM_STORE_MASK                          EQU     0FFFF0000H
CERT_SYSTEM_STORE_RELOCATE_FLAG                 EQU     080000000H

CERT_SYSTEM_STORE_UNPROTECTED_FLAG              EQU     040000000H
CERT_SYSTEM_STORE_LOCATION_MASK                 EQU     000FF0000H
CERT_SYSTEM_STORE_LOCATION_SHIFT                EQU     16
CERT_SYSTEM_STORE_CURRENT_USER_ID               EQU     1
CERT_SYSTEM_STORE_LOCAL_MACHINE_ID              EQU     2
CERT_SYSTEM_STORE_CURRENT_SERVICE_ID            EQU     4
CERT_SYSTEM_STORE_SERVICES_ID                   EQU     5
CERT_SYSTEM_STORE_USERS_ID                      EQU     6
CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID  EQU     7
CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID EQU     8
CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID   EQU     9
CERT_SYSTEM_STORE_CURRENT_USER                  EQU     (CERT_SYSTEM_STORE_CURRENT_USER_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE                 EQU     (CERT_SYSTEM_STORE_LOCAL_MACHINE_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_CURRENT_SERVICE               EQU     (CERT_SYSTEM_STORE_CURRENT_SERVICE_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_SERVICES                      EQU     (CERT_SYSTEM_STORE_SERVICES_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_USERS                         EQU     (CERT_SYSTEM_STORE_USERS_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY     EQU     (CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY    EQU     (CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE      EQU     (CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID SHL CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH          EQU     L("Software\Policies\Microsoft\SystemCertificates")
CERT_EFSBLOB_REGPATH                            EQU     L("Software\Policies\Microsoft\SystemCertificates\EFS")
CERT_EFSBLOB_VALUE_NAME                         EQU     L("EFSBlob")
CERT_PROT_ROOT_FLAGS_REGPATH                    EQU     L("Software\Policies\Microsoft\SystemCertificates\Root\ProtectedRoots")
CERT_PROT_ROOT_FLAGS_VALUE_NAME                 EQU     L("Flags")
CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG        EQU     01H
CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG         EQU     02H
CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG            EQU     04H
CERT_PROT_ROOT_ONLY_LM_GPT_FLAG                 EQU     08H
CERT_REGISTRY_STORE_REMOTE_FLAG                 EQU     010000H
CERT_REGISTRY_STORE_SERIALIZED_FLAG             EQU     020000H
CERT_REGISTRY_STORE_CLIENT_GPT_FLAG             EQU     080000000H
CERT_REGISTRY_STORE_LM_GPT_FLAG                 EQU     001000000H

CERT_REGISTRY_STORE_ROAMING_FLAG                EQU     040000H

CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG            EQU     080000H
CERT_IE_DIRTY_FLAGS_REGPATH                     EQU     L("Software\Microsoft\Cryptography\IEDirtyFlags")
CERT_FILE_STORE_COMMIT_ENABLE_FLAG              EQU     010000H

CRYPT_OID_OPEN_STORE_PROV_FUNC                  TEXTEQU <"CertDllOpenStoreProv">

CERT_STORE_PROV_EXTERNAL_FLAG                   EQU     01H
CERT_STORE_PROV_DELETED_FLAG                    EQU     02H
CERT_STORE_PROV_NO_PERSIST_FLAG                 EQU     04H
CERT_STORE_PROV_SYSTEM_STORE_FLAG               EQU     08H
CERT_STORE_PROV_CLOSE_FUNC                      EQU     0
CERT_STORE_PROV_READ_CERT_FUNC                  EQU     1
CERT_STORE_PROV_WRITE_CERT_FUNC                 EQU     2
CERT_STORE_PROV_DELETE_CERT_FUNC                EQU     3
CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC          EQU     4
CERT_STORE_PROV_READ_CRL_FUNC                   EQU     5
CERT_STORE_PROV_WRITE_CRL_FUNC                  EQU     6
CERT_STORE_PROV_DELETE_CRL_FUNC                 EQU     7
CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC           EQU     8
CERT_STORE_PROV_READ_CTL_FUNC                   EQU     9
CERT_STORE_PROV_WRITE_CTL_FUNC                  EQU     10
CERT_STORE_PROV_DELETE_CTL_FUNC                 EQU     11
CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC           EQU     12
CERT_STORE_PROV_CONTROL_FUNC                    EQU     13
CERT_STORE_PROV_FIND_CERT_FUNC                  EQU     14
CERT_STORE_PROV_FREE_FIND_CERT_FUNC             EQU     15
CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC          EQU     16
CERT_STORE_PROV_FIND_CRL_FUNC                   EQU     17
CERT_STORE_PROV_FREE_FIND_CRL_FUNC              EQU     18
CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC           EQU     19
CERT_STORE_PROV_FIND_CTL_FUNC                   EQU     20
CERT_STORE_PROV_FREE_FIND_CTL_FUNC              EQU     21
CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC           EQU     22

CERT_STORE_PROV_WRITE_ADD_FLAG                  EQU     01H

CERT_STORE_SAVE_AS_STORE                        EQU     1
CERT_STORE_SAVE_AS_PKCS7                        EQU     2
CERT_STORE_SAVE_TO_FILE                         EQU     1
CERT_STORE_SAVE_TO_MEMORY                       EQU     2
CERT_STORE_SAVE_TO_FILENAME_A                   EQU     3
CERT_STORE_SAVE_TO_FILENAME_W                   EQU     4
CERT_STORE_SAVE_TO_FILENAME                     EQU     CERT_STORE_SAVE_TO_FILENAME_W

CERT_CLOSE_STORE_FORCE_FLAG                     EQU     000000001H
CERT_CLOSE_STORE_CHECK_FLAG                     EQU     000000002H

CERT_COMPARE_MASK                               EQU     0FFFFH
CERT_COMPARE_SHIFT                              EQU     16
CERT_COMPARE_ANY                                EQU     0
CERT_COMPARE_SHA1_HASH                          EQU     1
CERT_COMPARE_NAME                               EQU     2
CERT_COMPARE_ATTR                               EQU     3
CERT_COMPARE_MD5_HASH                           EQU     4
CERT_COMPARE_PROPERTY                           EQU     5
CERT_COMPARE_PUBLIC_KEY                         EQU     6
CERT_COMPARE_HASH                               EQU     CERT_COMPARE_SHA1_HASH
CERT_COMPARE_NAME_STR_A                         EQU     7
CERT_COMPARE_NAME_STR_W                         EQU     8
CERT_COMPARE_KEY_SPEC                           EQU     9
CERT_COMPARE_ENHKEY_USAGE                       EQU     10
CERT_COMPARE_CTL_USAGE                          EQU     CERT_COMPARE_ENHKEY_USAGE
CERT_COMPARE_SUBJECT_CERT                       EQU     11
CERT_COMPARE_ISSUER_OF                          EQU     12
CERT_COMPARE_EXISTING                           EQU     13
CERT_COMPARE_SIGNATURE_HASH                     EQU     14
CERT_COMPARE_KEY_IDENTIFIER                     EQU     15
CERT_COMPARE_CERT_ID                            EQU     16

CERT_FIND_ANY                                   EQU     (CERT_COMPARE_ANY SHL CERT_COMPARE_SHIFT)
CERT_FIND_SHA1_HASH                             EQU     (CERT_COMPARE_SHA1_HASH SHL CERT_COMPARE_SHIFT)
CERT_FIND_MD5_HASH                              EQU     (CERT_COMPARE_MD5_HASH SHL CERT_COMPARE_SHIFT)
CERT_FIND_SIGNATURE_HASH                        EQU     (CERT_COMPARE_SIGNATURE_HASH SHL CERT_COMPARE_SHIFT)
CERT_FIND_KEY_IDENTIFIER                        EQU     (CERT_COMPARE_KEY_IDENTIFIER SHL CERT_COMPARE_SHIFT)
CERT_FIND_HASH                                  EQU     CERT_FIND_SHA1_HASH
CERT_FIND_PROPERTY                              EQU     (CERT_COMPARE_PROPERTY SHL CERT_COMPARE_SHIFT)
CERT_FIND_PUBLIC_KEY                            EQU     (CERT_COMPARE_PUBLIC_KEY SHL CERT_COMPARE_SHIFT)
CERT_FIND_SUBJECT_NAME                          EQU     (CERT_COMPARE_NAME SHL CERT_COMPARE_SHIFT OR CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_ATTR                          EQU     (CERT_COMPARE_ATTR SHL CERT_COMPARE_SHIFT OR CERT_INFO_SUBJECT_FLAG)
CERT_FIND_ISSUER_NAME                           EQU     (CERT_COMPARE_NAME SHL CERT_COMPARE_SHIFT OR CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_ATTR                           EQU     (CERT_COMPARE_ATTR SHL CERT_COMPARE_SHIFT OR CERT_INFO_ISSUER_FLAG)
CERT_FIND_SUBJECT_STR_A                         EQU     (CERT_COMPARE_NAME_STR_A SHL CERT_COMPARE_SHIFT OR CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_STR_W                         EQU     (CERT_COMPARE_NAME_STR_W SHL CERT_COMPARE_SHIFT OR CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_STR                           EQU     CERT_FIND_SUBJECT_STR_W
CERT_FIND_ISSUER_STR_A                          EQU     (CERT_COMPARE_NAME_STR_A SHL CERT_COMPARE_SHIFT OR CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_STR_W                          EQU     (CERT_COMPARE_NAME_STR_W SHL CERT_COMPARE_SHIFT OR CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_STR                            EQU     CERT_FIND_ISSUER_STR_W
CERT_FIND_KEY_SPEC                              EQU     (CERT_COMPARE_KEY_SPEC SHL CERT_COMPARE_SHIFT)
CERT_FIND_ENHKEY_USAGE                          EQU     (CERT_COMPARE_ENHKEY_USAGE SHL CERT_COMPARE_SHIFT)
CERT_FIND_CTL_USAGE                             EQU     CERT_FIND_ENHKEY_USAGE
CERT_FIND_SUBJECT_CERT                          EQU     (CERT_COMPARE_SUBJECT_CERT SHL CERT_COMPARE_SHIFT)
CERT_FIND_ISSUER_OF                             EQU     (CERT_COMPARE_ISSUER_OF SHL CERT_COMPARE_SHIFT)
CERT_FIND_EXISTING                              EQU     (CERT_COMPARE_EXISTING SHL CERT_COMPARE_SHIFT)
CERT_FIND_CERT_ID                               EQU     (CERT_COMPARE_CERT_ID SHL CERT_COMPARE_SHIFT)
CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG            EQU     01H
CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG            EQU     02H
CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG           EQU     04H
CERT_FIND_NO_ENHKEY_USAGE_FLAG                  EQU     08H
CERT_FIND_OR_ENHKEY_USAGE_FLAG                  EQU     010H
CERT_FIND_VALID_ENHKEY_USAGE_FLAG               EQU     020H
CERT_FIND_OPTIONAL_CTL_USAGE_FLAG               EQU     CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG
CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG               EQU     CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG
CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG              EQU     CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG
CERT_FIND_NO_CTL_USAGE_FLAG                     EQU     CERT_FIND_NO_ENHKEY_USAGE_FLAG
CERT_FIND_OR_CTL_USAGE_FLAG                     EQU     CERT_FIND_OR_ENHKEY_USAGE_FLAG
CERT_FIND_VALID_CTL_USAGE_FLAG                  EQU     CERT_FIND_VALID_ENHKEY_USAGE_FLAG

CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG     EQU     080000000H

CRL_FIND_ANY                                    EQU     0
CRL_FIND_ISSUED_BY                              EQU     1
CRL_FIND_EXISTING                               EQU     2
CRL_FIND_ISSUED_BY_AKI_FLAG                     EQU     01H
CRL_FIND_ISSUED_BY_SIGNATURE_FLAG               EQU     02H

CERT_STORE_ADD_NEW                              EQU     1
CERT_STORE_ADD_USE_EXISTING                     EQU     2
CERT_STORE_ADD_REPLACE_EXISTING                 EQU     3
CERT_STORE_ADD_ALWAYS                           EQU     4
CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES EQU      5
CERT_STORE_ADD_NEWER                            EQU     6
CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES         EQU     7

CERT_STORE_CERTIFICATE_CONTEXT                  EQU     1
CERT_STORE_CRL_CONTEXT                          EQU     2
CERT_STORE_CTL_CONTEXT                          EQU     3
CERT_STORE_ALL_CONTEXT_FLAG                     EQU     -1
CERT_STORE_CERTIFICATE_CONTEXT_FLAG             EQU     (1 SHL CERT_STORE_CERTIFICATE_CONTEXT)
CERT_STORE_CRL_CONTEXT_FLAG                     EQU     (1 SHL CERT_STORE_CRL_CONTEXT)
CERT_STORE_CTL_CONTEXT_FLAG                     EQU     (1 SHL CERT_STORE_CTL_CONTEXT)

CTL_ANY_SUBJECT_TYPE                            EQU     1
CTL_CERT_SUBJECT_TYPE                           EQU     2

CTL_FIND_ANY                                    EQU     0
CTL_FIND_SHA1_HASH                              EQU     1
CTL_FIND_MD5_HASH                               EQU     2
CTL_FIND_USAGE                                  EQU     3
CTL_FIND_SUBJECT                                EQU     4
CTL_FIND_EXISTING                               EQU     5

CTL_FIND_NO_LIST_ID_CBDATA                      EQU     0FFFFFFFFH
CTL_FIND_NO_SIGNER_PTR                          EQU     PCERT_INFO-1
CTL_FIND_SAME_USAGE_FLAG                        EQU     01H

CERT_STORE_CTRL_RESYNC                          EQU     1
CERT_STORE_CTRL_NOTIFY_CHANGE                   EQU     2
CERT_STORE_CTRL_COMMIT                          EQU     3
CERT_STORE_CTRL_AUTO_RESYNC                     EQU     4
CERT_STORE_CTRL_COMMIT_FORCE_FLAG               EQU     01H
CERT_STORE_CTRL_COMMIT_CLEAR_FLAG               EQU     02H
CERT_STORE_LOCALIZED_NAME_PROP_ID               EQU     01000H

CERT_CREATE_CONTEXT_NOCOPY_FLAG                 EQU     01H
CERT_CREATE_CONTEXT_SORTED_FLAG                 EQU     02H
CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG           EQU     04H
CERT_CREATE_CONTEXT_NO_ENTRY_FLAG               EQU     08H

CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG             EQU     01H
CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG           EQU     02H
CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG    EQU     04H
CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG EQU        08H

CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG        EQU     01H
CERT_PHYSICAL_STORE_DEFAULT_NAME                EQU     L(".Default")
CERT_PHYSICAL_STORE_GROUP_POLICY_NAME           EQU     L(".GroupPolicy")
CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME          EQU     L(".LocalMachine")
CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME    EQU     L(".UserCertificate")
CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME EQU L(".LocalMachineGroupPolicy")
CERT_PHYSICAL_STORE_ENTERPRISE_NAME             EQU     L(".Enterprise")

CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC           TEXTEQU <"CertDllOpenSystemStoreProv">
CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC            TEXTEQU <"CertDllRegisterSystemStore">
CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC          TEXTEQU <"CertDllUnregisterSystemStore">
CRYPT_OID_ENUM_SYSTEM_STORE_FUNC                TEXTEQU <"CertDllEnumSystemStore">
CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC          TEXTEQU <"CertDllRegisterPhysicalStore">
CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC        TEXTEQU <"CertDllUnregisterPhysicalStore">
CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC              TEXTEQU <"CertDllEnumPhysicalStore">
CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME      EQU     L("SystemStoreLocation")

CMSG_TRUSTED_SIGNER_FLAG                        EQU     01H
CMSG_SIGNER_ONLY_FLAG                           EQU     02H
CMSG_USE_SIGNER_INDEX_FLAG                      EQU     04H

CMSG_CMS_ENCAPSULATED_CTL_FLAG                  EQU     000008000H

CMSG_ENCODE_SORTED_CTL_FLAG                     EQU     01H
CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG      EQU     02H

CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG             EQU     01H
CERT_VERIFY_TRUSTED_SIGNERS_FLAG                EQU     02H
CERT_VERIFY_NO_TIME_CHECK_FLAG                  EQU     04H
CERT_VERIFY_ALLOW_MORE_USAGE_FLAG               EQU     08H
CERT_VERIFY_UPDATED_CTL_FLAG                    EQU     01H

CERT_CONTEXT_REVOCATION_TYPE                    EQU     1
CERT_VERIFY_REV_CHAIN_FLAG                      EQU     000000001H
CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION         EQU     000000002H

CERT_UNICODE_IS_RDN_ATTRS_FLAG                  EQU     01H
CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG         EQU     02H

CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB             EQU     1
CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT             EQU     2
CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL              EQU     3
CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY            EQU     1
CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT              EQU     2
CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN             EQU     3

CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG         EQU     000000001H
CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG              EQU     000000002H
CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID             EQU     1
CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID       EQU     2

CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC           TEXTEQU <"CryptDllExportPublicKeyInfoEx">
CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC           TEXTEQU <"CryptDllImportPublicKeyInfoEx">

CRYPT_ACQUIRE_CACHE_FLAG                        EQU     01H
CRYPT_ACQUIRE_USE_PROV_INFO_FLAG                EQU     02H
CRYPT_ACQUIRE_COMPARE_KEY_FLAG                  EQU     04H

CRYPT_FIND_USER_KEYSET_FLAG                     EQU     01H
CRYPT_FIND_MACHINE_KEYSET_FLAG                  EQU     02H

CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC          TEXTEQU <"CryptDllImportPrivateKeyInfoEx">

CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC          TEXTEQU <"CryptDllExportPrivateKeyInfoEx">
CRYPT_DELETE_KEYSET                             EQU     00001H

CERT_SIMPLE_NAME_STR                            EQU     1
CERT_OID_NAME_STR                               EQU     2
CERT_X500_NAME_STR                              EQU     3
CERT_NAME_STR_SEMICOLON_FLAG                    EQU     040000000H
CERT_NAME_STR_NO_PLUS_FLAG                      EQU     020000000H
CERT_NAME_STR_NO_QUOTING_FLAG                   EQU     010000000H
CERT_NAME_STR_CRLF_FLAG                         EQU     008000000H
CERT_NAME_STR_COMMA_FLAG                        EQU     004000000H
CERT_NAME_STR_REVERSE_FLAG                      EQU     002000000H
CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG             EQU     000010000H
CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG           EQU     000020000H
CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG          EQU     000040000H

CERT_NAME_EMAIL_TYPE                            EQU     1
CERT_NAME_RDN_TYPE                              EQU     2
CERT_NAME_ATTR_TYPE                             EQU     3
CERT_NAME_SIMPLE_DISPLAY_TYPE                   EQU     4
CERT_NAME_FRIENDLY_DISPLAY_TYPE                 EQU     5
CERT_NAME_ISSUER_FLAG                           EQU     01H
CERT_NAME_DISABLE_IE4_UTF8_FLAG                 EQU     000010000H

CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG             EQU     01H
CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG     EQU     02H
CRYPT_MESSAGE_KEYID_SIGNER_FLAG                 EQU     04H

CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG              EQU     04H

CERT_QUERY_OBJECT_FILE                          EQU     000000001H
CERT_QUERY_OBJECT_BLOB                          EQU     000000002H
CERT_QUERY_CONTENT_CERT                         EQU     1
CERT_QUERY_CONTENT_CTL                          EQU     2
CERT_QUERY_CONTENT_CRL                          EQU     3
CERT_QUERY_CONTENT_SERIALIZED_STORE             EQU     4
CERT_QUERY_CONTENT_SERIALIZED_CERT              EQU     5
CERT_QUERY_CONTENT_SERIALIZED_CTL               EQU     6
CERT_QUERY_CONTENT_SERIALIZED_CRL               EQU     7
CERT_QUERY_CONTENT_PKCS7_SIGNED                 EQU     8
CERT_QUERY_CONTENT_PKCS7_UNSIGNED               EQU     9
CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED           EQU     10
CERT_QUERY_CONTENT_PKCS10                       EQU     11
CERT_QUERY_CONTENT_PFX                          EQU     12
CERT_QUERY_CONTENT_FLAG_CERT                    EQU     (1 SHL CERT_QUERY_CONTENT_CERT)
CERT_QUERY_CONTENT_FLAG_CTL                     EQU     (1 SHL CERT_QUERY_CONTENT_CTL)
CERT_QUERY_CONTENT_FLAG_CRL                     EQU     (1 SHL CERT_QUERY_CONTENT_CRL)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE        EQU     (1 SHL CERT_QUERY_CONTENT_SERIALIZED_STORE)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT         EQU     (1 SHL CERT_QUERY_CONTENT_SERIALIZED_CERT)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL          EQU     (1 SHL CERT_QUERY_CONTENT_SERIALIZED_CTL)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL          EQU     (1 SHL CERT_QUERY_CONTENT_SERIALIZED_CRL)
CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED            EQU     (1 SHL CERT_QUERY_CONTENT_PKCS7_SIGNED)
CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED          EQU     (1 SHL CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED      EQU     (1 SHL CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
CERT_QUERY_CONTENT_FLAG_PKCS10                  EQU     (1 SHL CERT_QUERY_CONTENT_PKCS10)
CERT_QUERY_CONTENT_FLAG_PFX                     EQU     (1 SHL CERT_QUERY_CONTENT_PFX)
CERT_QUERY_CONTENT_FLAG_ALL_1                   EQU     (CERT_QUERY_CONTENT_FLAG_CERT OR CERT_QUERY_CONTENT_FLAG_CTL OR CERT_QUERY_CONTENT_FLAG_CRL OR CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE OR CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT)
CERT_QUERY_CONTENT_FLAG_ALL_2                   EQU     (CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL OR CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL OR CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED OR CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED)
CERT_QUERY_CONTENT_FLAG_ALL                     EQU     (CERT_QUERY_CONTENT_FLAG_ALL_1 OR CERT_QUERY_CONTENT_FLAG_ALL_2 OR CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED OR CERT_QUERY_CONTENT_FLAG_PKCS10 OR CERT_QUERY_CONTENT_FLAG_PFX)

CERT_QUERY_FORMAT_BINARY                        EQU     1
CERT_QUERY_FORMAT_BASE64_ENCODED                EQU     2
CERT_QUERY_FORMAT_FLAG_BINARY                   EQU     (1 SHL CERT_QUERY_FORMAT_BINARY)
CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED           EQU     (1 SHL CERT_QUERY_FORMAT_BASE64_ENCODED)
CERT_QUERY_FORMAT_FLAG_ALL                      EQU     CERT_QUERY_FORMAT_FLAG_BINARY OR CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED

CREDENTIAL_OID_PASSWORD_CREDENTIALS_A           EQU     1
CREDENTIAL_OID_PASSWORD_CREDENTIALS_W           EQU     2

SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC         TEXTEQU <"SchemeDllRetrieveEncodedObject">

CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC          TEXTEQU <"ContextDllCreateObjectContext">
CONTEXT_OID_CERTIFICATE                         EQU     1
CONTEXT_OID_CRL                                 EQU     2
CONTEXT_OID_CTL                                 EQU     3
CONTEXT_OID_PKCS7                               EQU     4
CONTEXT_OID_CAPI2_ANY                           EQU     5

CRYPT_RETRIEVE_MULTIPLE_OBJECTS                 EQU     000000001H
CRYPT_CACHE_ONLY_RETRIEVAL                      EQU     000000002H
CRYPT_WIRE_ONLY_RETRIEVAL                       EQU     000000004H
CRYPT_DONT_CACHE_RESULT                         EQU     000000008H
CRYPT_ASYNC_RETRIEVAL                           EQU     000000010H
CRYPT_VERIFY_CONTEXT_SIGNATURE                  EQU     000000020H
CRYPT_VERIFY_DATA_HASH                          EQU     000000040H
CRYPT_KEEP_TIME_VALID                           EQU     000000080H
CRYPT_DONT_VERIFY_SIGNATURE                     EQU     000000100H
CRYPT_DONT_CHECK_TIME_VALIDITY                  EQU     000000200H

CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION          EQU     1

CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL              EQU     2

CRYPT_GET_URL_FROM_PROPERTY                     EQU     000000001H
CRYPT_GET_URL_FROM_EXTENSION                    EQU     000000002H
CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE             EQU     000000004H
CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE               EQU     000000008H

URL_OID_GET_OBJECT_URL_FUNC                     TEXTEQU <"UrlDllGetObjectUrl">
URL_OID_CERTIFICATE_ISSUER                      EQU     1
URL_OID_CERTIFICATE_CRL_DIST_POINT              EQU     2
URL_OID_CTL_ISSUER                              EQU     3
URL_OID_CTL_NEXT_UPDATE                         EQU     4
URL_OID_CRL_ISSUER                              EQU     5

TIME_VALID_OID_GET_OBJECT_FUNC                  TEXTEQU <"TimeValidDllGetObject">
TIME_VALID_OID_GET_CTL                          EQU     1
TIME_VALID_OID_GET_CRL                          EQU     2
TIME_VALID_OID_GET_CRL_FROM_CERT                EQU     3

TIME_VALID_OID_FLUSH_OBJECT_FUNC                TEXTEQU <"TimeValidDllFlushObject">
TIME_VALID_OID_FLUSH_CTL                        EQU     1
TIME_VALID_OID_FLUSH_CRL                        EQU     2
TIME_VALID_OID_FLUSH_CRL_FROM_CERT              EQU     3

CRYPTPROTECT_DEFAULT_PROVIDER                   EQU     {0DF9D8CD0H,01501H,011D1H,08CH,07AH,0H,0C0H,04FH,0C2H,097H,0EBH}

CRYPTPROTECT_PROMPT_ON_UNPROTECT                EQU     01H
CRYPTPROTECT_PROMPT_ON_PROTECT                  EQU     02H
CRYPTPROTECT_PROMPT_RESERVED                    EQU     004H
CRYPTPROTECT_PROMPT_STRONG                      EQU     008H
CRYPTPROTECT_UI_FORBIDDEN                       EQU     01H
CRYPTPROTECT_LOCAL_MACHINE                      EQU     04H
CRYPTPROTECT_CRED_SYNC                          EQU     08H
CRYPTPROTECT_FIRST_RESERVED_FLAGVAL             EQU     00FFFFFFFH
CRYPTPROTECT_LAST_RESERVED_FLAGVAL              EQU     0FFFFFFFFH

CERT_CREATE_SELFSIGN_NO_SIGN                    EQU     1
CERT_CREATE_SELFSIGN_NO_KEY_INFO                EQU     2

CRYPT_KEYID_MACHINE_FLAG                        EQU     000000020H
CRYPT_KEYID_ALLOC_FLAG                          EQU     000008000H

CRYPT_KEYID_DELETE_FLAG                         EQU     000000010H
CRYPT_KEYID_SET_NEW_FLAG                        EQU     000002000H

HCCE_CURRENT_USER                               EQU     0
HCCE_LOCAL_MACHINE                              EQU     1
CERT_CHAIN_CACHE_END_CERT                       EQU     000000001H
CERT_CHAIN_THREAD_STORE_SYNC                    EQU     000000002H
CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL             EQU     000000004H
CERT_CHAIN_USE_LOCAL_MACHINE_STORE              EQU     000000008H
CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE             EQU     000000010H

CERT_TRUST_NO_ERROR                             EQU     000000000H
CERT_TRUST_IS_NOT_TIME_VALID                    EQU     000000001H
CERT_TRUST_IS_NOT_TIME_NESTED                   EQU     000000002H
CERT_TRUST_IS_REVOKED                           EQU     000000004H
CERT_TRUST_IS_NOT_SIGNATURE_VALID               EQU     000000008H
CERT_TRUST_IS_NOT_VALID_FOR_USAGE               EQU     000000010H
CERT_TRUST_IS_UNTRUSTED_ROOT                    EQU     000000020H
CERT_TRUST_REVOCATION_STATUS_UNKNOWN            EQU     000000040H
CERT_TRUST_IS_CYCLIC                            EQU     000000080H
CERT_TRUST_IS_PARTIAL_CHAIN                     EQU     000010000H
CERT_TRUST_CTL_IS_NOT_TIME_VALID                EQU     000020000H
CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID           EQU     000040000H
CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE           EQU     000080000H
CERT_TRUST_HAS_EXACT_MATCH_ISSUER               EQU     000000001H
CERT_TRUST_HAS_KEY_MATCH_ISSUER                 EQU     000000002H
CERT_TRUST_HAS_NAME_MATCH_ISSUER                EQU     000000004H
CERT_TRUST_IS_SELF_SIGNED                       EQU     000000008H
CERT_TRUST_IS_COMPLEX_CHAIN                     EQU     000010000H

USAGE_MATCH_TYPE_AND                            EQU     000000000H
USAGE_MATCH_TYPE_OR                             EQU     000000001H

CERT_CHAIN_REVOCATION_CHECK_END_CERT            EQU     010000000H
CERT_CHAIN_REVOCATION_CHECK_CHAIN               EQU     020000000H
CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT  EQU     040000000H
CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY          EQU     080000000H

REVOCATION_OID_CRL_REVOCATION                   EQU     1

CERT_CHAIN_FIND_BY_ISSUER                       EQU     1

CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG      EQU     00001H
CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG    EQU     00002H
CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG   EQU     00004H
CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG    EQU     00008H
CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG           EQU     04000H
CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG       EQU     08000H

CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG    EQU     000000001H
CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG    EQU     000000002H
CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG   EQU     000000004H
CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS   EQU     (CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG OR CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG OR CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG)
CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG         EQU     000000010H
CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG       EQU     000000020H
CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG   EQU     000000100H
CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG    EQU     000000200H
CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG    EQU     000000400H
CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG  EQU     000000800H
CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS  EQU     (CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG OR CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG OR CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG OR CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG)
CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG           EQU     000008000H
CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG           EQU     000004000H

CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC  TEXTEQU <"CertDllVerifyCertificateChainPolicy">
CERT_CHAIN_POLICY_BASE                          EQU     1
CERT_CHAIN_POLICY_AUTHENTICODE                  EQU     2
CERT_CHAIN_POLICY_AUTHENTICODE_TS               EQU     3
CERT_CHAIN_POLICY_SSL                           EQU     4
CERT_CHAIN_POLICY_BASIC_CONSTRAINTS             EQU     5
CERT_CHAIN_POLICY_NT_AUTH                       EQU     6

AUTHTYPE_CLIENT                                 EQU     1
AUTHTYPE_SERVER                                 EQU     2

BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG     EQU     080000000H
BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG EQU     040000000H

CERT_SELECT_BY_ENHKEY_USAGE                     EQU     1
CERT_SELECT_BY_KEY_USAGE                        EQU     2
CERT_SELECT_BY_POLICY_OID                       EQU     3
CERT_SELECT_BY_PROV_NAME                        EQU     4
CERT_SELECT_BY_EXTENSION                        EQU     5
CERT_SELECT_BY_SUBJECT_HOST_NAME                EQU     6
CERT_SELECT_BY_ISSUER_ATTR                      EQU     7
CERT_SELECT_BY_SUBJECT_ATTR                     EQU     8
CERT_SELECT_BY_ISSUER_NAME                      EQU     9
CERT_SELECT_BY_PUBLIC_KEY                       EQU     10
CERT_SELECT_BY_TLS_SIGNATURES                   EQU     11

CERT_SELECT_LAST                                EQU     CERT_SELECT_BY_TLS_SIGNATURES
CERT_SELECT_MAX                                 EQU     (CERT_SELECT_LAST * 3)

CERT_SELECT_ALLOW_EXPIRED                       EQU     000000001H
CERT_SELECT_TRUSTED_ROOT                        EQU     000000002H
CERT_SELECT_DISALLOW_SELFSIGNED                 EQU     000000004H
CERT_SELECT_HAS_PRIVATE_KEY                     EQU     000000008H
CERT_SELECT_HAS_KEY_FOR_SIGNATURE               EQU     000000010H
CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE            EQU     000000020H
CERT_SELECT_HARDWARE_ONLY                       EQU     000000040H
CERT_SELECT_ALLOW_DUPLICATES                    EQU     000000080H

CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC TEXTEQU <"CryptDllExportPublicKeyInfoFromBCryptKeyHandle">
CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC       TEXTEQU <"CryptDllImportPublicKeyInfoEx2">

CERT_SELECT_MAX_PARA                            EQU     500

TIMESTAMP_STATUS_GRANTED                        EQU     0
TIMESTAMP_STATUS_GRANTED_WITH_MODS              EQU     1
TIMESTAMP_STATUS_REJECTED                       EQU     2
TIMESTAMP_STATUS_WAITING                        EQU     3
TIMESTAMP_STATUS_REVOCATION_WARNING             EQU     4
TIMESTAMP_STATUS_REVOKED                        EQU     5

TIMESTAMP_FAILURE_BAD_ALG                       EQU     0
TIMESTAMP_FAILURE_BAD_REQUEST                   EQU     2
TIMESTAMP_FAILURE_BAD_FORMAT                    EQU     5
TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE            EQU     14
TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED          EQU     15
TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED       EQU     16
TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE            EQU     17
TIMESTAMP_FAILURE_SYSTEM_FAILURE                EQU     25

TIMESTAMP_DONT_HASH_DATA                        EQU     000000001H
TIMESTAMP_VERIFY_CONTEXT_SIGNATURE              EQU     000000020H
TIMESTAMP_NO_AUTH_RETRIEVAL                     EQU     000020000H

HCRYPTPROV                                      TYPEDEF XPTR
HCRYPTKEY                                       TYPEDEF XPTR
HCRYPTHASH                                      TYPEDEF XPTR


;======================================== Structures ======================================;

IF (NTDDI_VERSION LT NTDDI_WINXP)
    SIGNATURE_RESOURCE_NUMBER                   EQU     029AH
    
    VTableProvStruc STRUCT ALIGNMODE
        Version         DD   ?
        FuncVerifyImage XPTR ?
        FuncReturnhWnd  XPTR ?
        dwProvType      DD   ?
        pbContextInfo   XPTR ?
        cbContextInfo   DD   ?
        pszProvName     XPTR ?
    VTableProvStruc ENDS
ENDIF

CMS_KEY_INFO STRUCT ALIGNMODE
    dwVersion DD   ?
    Algid     DD   ?
    pbOID     XPTR ?
    cbOID     DD   ?
CMS_KEY_INFO ENDS

HMAC_Info STRUCT ALIGNMODE
    HashAlgid     DD   ?
    pbInnerString XPTR ?
    cbInnerString DD   ?
    pbOuterString XPTR ?
    cbOuterString DD   ?
HMAC_Info ENDS

SCHANNEL_ALG STRUCT ALIGNMODE
    dwUse       DD ?
    Algid       DD ?
    cBits       DD ?
    dwFlags     DD ?
    dwReserved  DD ?
SCHANNEL_ALG ENDS

PROV_ENUMALGS STRUCT ALIGNMODE
    aiAlgid   DD ?
    dwBitLen  DD ?
    dwNameLen DD ?
    szName    DB 20 DUP(?)
PROV_ENUMALGS ENDS

PROV_ENUMALGS_EX STRUCT ALIGNMODE
    aiAlgid        DD ?
    dwDefaultLen   DD ?
    dwMinLen       DD ?
    dwMaxLen       DD ?
    dwProtocols    DD ?
    dwNameLen      DD ?
    szName         DB 20 DUP(?)
    dwLongNameLen  DD ?
    szLongName     DB 40 DUP(?)
PROV_ENUMALGS_EX ENDS

PUBLICKEYSTRUC STRUCT ALIGNMODE
    bType    DB ?
    bVersion DB ?
    reserved DW ?
    aiKeyAlg DD ?
PUBLICKEYSTRUC ENDS

BLOBHEADER EQU <PUBLICKEYSTRUC>

RSAPUBKEY STRUCT ALIGNMODE
    magic  DD ?
    bitlen DD ?
    pubexp DD ?
RSAPUBKEY ENDS

PUBKEY STRUCT ALIGNMODE
    magic  DD ?
    bitlen DD ?
PUBKEY ENDS

DHPUBKEY equ <PUBKEY>
DSSPUBKEY equ <PUBKEY>
KEAPUBKEY equ <PUBKEY>
TEKPUBKEY equ <PUBKEY>

DSSSEED STRUCT ALIGNMODE
    counter DD ?
    seed    DB 20 DUP(?)
DSSSEED ENDS

PUBKEYVER3 STRUCT ALIGNMODE
    magic   DD ?
    bitlenP DD ?
    bitlenQ DD ?
    bitlenJ DD ?
    DSSSeed DSSSEED <>
PUBKEYVER3 ENDS

DHPUBKEY_VER3 EQU <PUBKEYVER3>
DSSPUBKEY_VER3 EQU <PUBKEYVER3>

PRIVKEYVER3 STRUCT ALIGNMODE
    magic   DD ?
    bitlenP DD ?
    bitlenQ DD ?
    bitlenJ DD ?
    bitlenX DD ?
    DSSSeed DSSSEED <>
PRIVKEYVER3 ENDS

DHPRIVKEY_VER3 EQU <PRIVKEYVER3>
DSSPRIVKEY_VER3 EQU <PRIVKEYVER3>

KEY_TYPE_SUBTYPE STRUCT ALIGNMODE
    dwKeySpec DD ?
    _Type     GUID <>
    Subtype   GUID <>
KEY_TYPE_SUBTYPE ENDS

CERT_FORTEZZA_DATA_PROP STRUCT ALIGNMODE
    SerialNumber DB 8 DUP(?)
    CertIndex    DD ?
    CertLabel    DB 36 DUP(?)
CERT_FORTEZZA_DATA_PROP ENDS

CRYPT_RC4_KEY_STATE STRUCT ALIGNMODE
    Key  DB 16 DUP(?)
    SBox DB 256 DUP(?)
    i    DB ?
    j    DB ?
CRYPT_RC4_KEY_STATE ENDS

CRYPT_DES_KEY_STATE STRUCT ALIGNMODE
    Key      DB 8 DUP(?)
    IV       DB 8 DUP(?)
    Feedback DB 8 DUP(?)
CRYPT_DES_KEY_STATE ENDS

CRYPT_3DES_KEY_STATE STRUCT ALIGNMODE
    Key      DB 24 DUP(?)
    IV       DB 8 DUP(?)
    Feedback DB 8 DUP(?)
CRYPT_3DES_KEY_STATE ENDS

CRYPT_AES_128_KEY_STATE STRUCT ALIGNMODE
    Key             DB 16 DUP(?)
    IV              DB 16 DUP(?)
    EncryptionState DB 176 DUP(?)
    DecryptionState DB 176 DUP(?)
    Feedback        DB 16 DUP(?)
CRYPT_AES_128_KEY_STATE ENDS

CRYPT_AES_256_KEY_STATE STRUCT ALIGNMODE
    Key             DB 32 DUP(?)
    IV              DB 16 DUP(?)
    EncryptionState DB 240 DUP(?)
    DecryptionState DB 240 DUP(?)
    Feedback        DB 16 DUP(?)
CRYPT_AES_256_KEY_STATE ENDS

CRYPTOAPI_BLOB STRUCT ALIGNMODE
    cbData DD   ?
    pbData XPTR ?
CRYPTOAPI_BLOB ENDS

CRYPT_BIT_BLOB STRUCT ALIGNMODE
    cbData      DD   ?
    pbData      XPTR ?
    cUnusedBits DD   ?
CRYPT_BIT_BLOB ENDS

CRYPT_INTEGER_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_UINT_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_OBJID_BLOB EQU <CRYPTOAPI_BLOB>
CERT_NAME_BLOB EQU <CRYPTOAPI_BLOB>
CERT_RDN_VALUE_BLOB EQU <CRYPTOAPI_BLOB>
CERT_BLOB EQU <CRYPTOAPI_BLOB>
CRL_BLOB EQU <CRYPTOAPI_BLOB>
DATA_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_DATA_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_HASH_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_DIGEST_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_DER_BLOB EQU <CRYPTOAPI_BLOB>
CRYPT_ATTR_BLOB EQU <CRYPTOAPI_BLOB>

CMS_DH_KEY_INFO STRUCT ALIGNMODE
    dwVersion          DD   ?
    Algid              DD   ?
    pszContentEncObjId XPTR ?
    PubInfo            CRYPT_DATA_BLOB <>
    pReserved          XPTR ?
CMS_DH_KEY_INFO ENDS

CRYPT_ALGORITHM_IDENTIFIER STRUCT ALIGNMODE
    pszObjId   XPTR ?
    Parameters CRYPT_OBJID_BLOB <>
CRYPT_ALGORITHM_IDENTIFIER ENDS

CRYPT_OBJID_TABLE STRUCT ALIGNMODE
    dwAlgId  DD   ?
    pszObjId XPTR ?
CRYPT_OBJID_TABLE ENDS

CRYPT_HASH_INFO STRUCT ALIGNMODE
    HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    Hash          CRYPT_HASH_BLOB <>
CRYPT_HASH_INFO ENDS

CERT_EXTENSION STRUCT ALIGNMODE
    pszObjId  XPTR ?
    fCritical DD   ?
    Value     CRYPT_OBJID_BLOB <>
CERT_EXTENSION ENDS

CRYPT_ATTRIBUTE_TYPE_VALUE STRUCT ALIGNMODE
    pszObjId XPTR ?
    Value    CRYPT_OBJID_BLOB <>
CRYPT_ATTRIBUTE_TYPE_VALUE ENDS

CRYPT_ATTRIBUTE STRUCT ALIGNMODE
    pszObjId XPTR ?
    cValue   DD   ?
    rgValue  XPTR ?
CRYPT_ATTRIBUTE ENDS

CRYPT_ATTRIBUTES STRUCT ALIGNMODE
    cAttr  DD ?
    rgAttr DD ?
CRYPT_ATTRIBUTES ENDS

CERT_RDN_ATTR STRUCT ALIGNMODE
    pszObjId    XPTR ?
    dwValueType DD   ?
    _Value      CERT_RDN_VALUE_BLOB <>
CERT_RDN_ATTR ENDS

CERT_RDN STRUCT ALIGNMODE
    cRDNAttr  DD   ?
    rgRDNAttr XPTR ?
CERT_RDN ENDS

CERT_NAME_INFO STRUCT ALIGNMODE
    cRDN  DD ?
    rgRDN DD ?
CERT_NAME_INFO ENDS

CERT_NAME_VALUE STRUCT ALIGNMODE
    dwValueType DD ?
    Value       CERT_RDN_VALUE_BLOB <>
CERT_NAME_VALUE ENDS

CERT_PUBLIC_KEY_INFO STRUCT ALIGNMODE
    Algorithm CRYPT_ALGORITHM_IDENTIFIER <>
    PublicKey CRYPT_BIT_BLOB <>
CERT_PUBLIC_KEY_INFO ENDS

CRYPT_PRIVATE_KEY_INFO STRUCT ALIGNMODE
    Version     DD ?
    Algorithm   CRYPT_ALGORITHM_IDENTIFIER <>
    PrivateKey  CRYPT_DER_BLOB <>
    pAttributes DD ?
CRYPT_PRIVATE_KEY_INFO ENDS

CRYPT_ENCRYPTED_PRIVATE_KEY_INFO STRUCT ALIGNMODE
    EncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedPrivateKey CRYPT_DATA_BLOB <>
CRYPT_ENCRYPTED_PRIVATE_KEY_INFO ENDS

CRYPT_PKCS8_IMPORT_PARAMS STRUCT ALIGNMODE
    PrivateKey             CRYPT_DIGEST_BLOB <>
    pResolvehCryptProvFunc XPTR ?
    pVoidResolveFunc       XPTR ?
    pDecryptPrivateKeyFunc XPTR ?
    pVoidDecryptFunc       XPTR ?
CRYPT_PKCS8_IMPORT_PARAMS ENDS

CRYPT_PKCS8_EXPORT_PARAMS STRUCT ALIGNMODE
    hCryptProv             XWORD ?
    dwKeySpec              DD    ?
    pszPrivateKeyObjId     XPTR  ?
    pEncryptPrivateKeyFunc XPTR  ?
    pVoidEncryptFunc       XPTR  ?
CRYPT_PKCS8_EXPORT_PARAMS ENDS

CERT_INFO STRUCT ALIGNMODE
    dwVersion            DD ?
    SerialNumber         CRYPT_INTEGER_BLOB <>
    SignatureAlgorithm   CRYPT_ALGORITHM_IDENTIFIER <>
    Issuer               CERT_NAME_BLOB <>
    NotBefore            FILETIME <>
    NotAfter             FILETIME <>
    Subject              CERT_NAME_BLOB <>
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
    IssuerUniqueId       CRYPT_BIT_BLOB <>
    SubjectUniqueId      CRYPT_BIT_BLOB <>
    cExtension           DD ?
    rgExtension          XPTR ?
CERT_INFO ENDS

CRL_ENTRY STRUCT ALIGNMODE
    SerialNumber   CRYPT_INTEGER_BLOB <>
    RevocationDate FILETIME <>
    cExtension     DD   ?
    rgExtension    XPTR ?
CRL_ENTRY ENDS

CRL_INFO STRUCT ALIGNMODE
    dwVersion          DD   ?
    SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    Issuer             CERT_NAME_BLOB <>
    ThisUpdate         FILETIME <>
    NextUpdate         FILETIME <>
    cCRLEntry          DD   ?
    rgCRLEntry         XPTR ?
    cExtension         DD   ?
    rgExtension        XPTR ?
CRL_INFO ENDS

CERT_REQUEST_INFO STRUCT ALIGNMODE
    dwVersion            DD   ?
    Subject              CERT_NAME_BLOB <>
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
    cAttribute           DD   ?
    rgAttribute          XPTR ?
CERT_REQUEST_INFO ENDS

CERT_KEYGEN_REQUEST_INFO STRUCT ALIGNMODE
    dwVersion            DD   ?
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
    pwszChallengeString  XPTR ?
CERT_KEYGEN_REQUEST_INFO ENDS

CERT_SIGNED_CONTENT_INFO STRUCT ALIGNMODE
    ToBeSigned          CRYPT_DER_BLOB <>
    SignatureAlgorithm  CRYPT_ALGORITHM_IDENTIFIER <>
    Signature           CRYPT_BIT_BLOB <>
CERT_SIGNED_CONTENT_INFO ENDS

CTL_USAGE STRUCT ALIGNMODE
    cUsageIdentifier     DD   ?
    rgpszUsageIdentifier XPTR ?
CTL_USAGE ENDS
CERT_ENHKEY_USAGE EQU <CTL_USAGE>

CTL_ENTRY STRUCT ALIGNMODE
    SubjectIdentifier CRYPT_DATA_BLOB <>
    cAttribute        DD   ?
    rgAttribute       XPTR ?
CTL_ENTRY ENDS

CTL_INFO STRUCT ALIGNMODE
    dwVersion        DD   ?
    SubjectUsage     CTL_USAGE <>
    ListIdentifier   CRYPT_DATA_BLOB <>
    SequenceNumber   CRYPT_INTEGER_BLOB <>
    ThisUpdate       FILETIME <>
    NextUpdate       FILETIME <>
    SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    cCTLEntry        DD   ?
    rgCTLEntry       XPTR ?
    cExtension       DD   ?
    rgExtension      XPTR ?
CTL_INFO ENDS

CRYPT_TIME_STAMP_REQUEST_INFO STRUCT ALIGNMODE
    pszTimeStampAlgorithm XPTR ?
    pszContentType        XPTR ?
    Content               CRYPT_OBJID_BLOB <>
    cAttribute            DD   ?
    rgAttribute           XPTR ?
CRYPT_TIME_STAMP_REQUEST_INFO ENDS

CRYPT_ENROLLMENT_NAME_VALUE_PAIR STRUCT ALIGNMODE
    pwszName  XPTR ?
    pwszValue XPTR ?
CRYPT_ENROLLMENT_NAME_VALUE_PAIR ENDS

CRYPT_CSP_PROVIDER STRUCT ALIGNMODE
    dwKeySpec        DD   ?
    pwszProviderName XPTR ?
    Signature        CRYPT_BIT_BLOB <>
CRYPT_CSP_PROVIDER ENDS

CRYPT_ENCODE_PARA STRUCT ALIGNMODE
    cbSize   DD   ?
    pfnAlloc XPTR ?
    pfnFree  XPTR ?
CRYPT_ENCODE_PARA ENDS

CRYPT_DECODE_PARA EQU <CRYPT_ENCODE_PARA>

CERT_EXTENSIONS STRUCT ALIGNMODE
    cExtension  DD   ?
    rgExtension XPTR  ?
CERT_EXTENSIONS ENDS

CERT_AUTHORITY_KEY_ID_INFO STRUCT ALIGNMODE
    KeyId            CRYPT_DATA_BLOB <>
    CertIssuer       CERT_NAME_BLOB <>
    CertSerialNumber CRYPT_INTEGER_BLOB <>
CERT_AUTHORITY_KEY_ID_INFO ENDS

CERT_PRIVATE_KEY_VALIDITY STRUCT ALIGNMODE
    NotBefore FILETIME <>
    NotAfter  FILETIME <>
CERT_PRIVATE_KEY_VALIDITY ENDS

CERT_KEY_ATTRIBUTES_INFO STRUCT ALIGNMODE
    KeyId                  CRYPT_DATA_BLOB <>
    IntendedKeyUsage       CRYPT_BIT_BLOB <>
    pPrivateKeyUsagePeriod XPTR ?
CERT_KEY_ATTRIBUTES_INFO ENDS

CERT_POLICY_ID STRUCT ALIGNMODE
    cCertPolicyElementId     DD   ?
    rgpszCertPolicyElementId XPTR ?
CERT_POLICY_ID ENDS

CERT_KEY_USAGE_RESTRICTION_INFO STRUCT ALIGNMODE
    cCertPolicyId      DD   ?
    rgCertPolicyId     XPTR ?
    RestrictedKeyUsage CRYPT_BIT_BLOB <>
CERT_KEY_USAGE_RESTRICTION_INFO ENDS

CERT_OTHER_NAME STRUCT ALIGNMODE
    pszObjId XPTR ?
    Value    CRYPT_OBJID_BLOB <>
CERT_OTHER_NAME ENDS

CERT_ALT_NAME_ENTRY STRUCT ALIGNMODE
    dwAltNameChoice     DD   ?
    UNION
        pOtherName      XPTR ?
        pwszRfc822Name  XPTR ?
        pwszDNSName     XPTR ?
        DirectoryName   CERT_NAME_BLOB <>
        pwszURL         XPTR ?
        IPAddress       CRYPT_DATA_BLOB <>
        pszRegisteredID XPTR ?
    ENDS
CERT_ALT_NAME_ENTRY ENDS

CERT_ALT_NAME_INFO STRUCT ALIGNMODE
    cAltEntry  DD   ?
    rgAltEntry XPTR ?
CERT_ALT_NAME_INFO ENDS

CERT_BASIC_CONSTRAINTS_INFO STRUCT ALIGNMODE
    SubjectType          CRYPT_BIT_BLOB <>
    fPathLenConstraint   DD ?
    dwPathLenConstraint  DD ?
    cSubtreesConstraint  DD ?
    rgSubtreesConstraint DD ?
CERT_BASIC_CONSTRAINTS_INFO ENDS

CERT_BASIC_CONSTRAINTS2_INFO STRUCT ALIGNMODE
    fCA                 DD ?
    fPathLenConstraint  DD ?
    dwPathLenConstraint DD ?
CERT_BASIC_CONSTRAINTS2_INFO ENDS

CERT_POLICY_QUALIFIER_INFO STRUCT ALIGNMODE
    pszPolicyQualifierId XPTR ?
    Qualifier            CRYPT_OBJID_BLOB <>
CERT_POLICY_QUALIFIER_INFO ENDS

CERT_POLICY_INFO STRUCT ALIGNMODE
    pszPolicyIdentifier XPTR ?
    cPolicyQualifier    DD   ?
    rgPolicyQualifier   XPTR ?
CERT_POLICY_INFO ENDS

CERT_POLICIES_INFO STRUCT ALIGNMODE
    cPolicyInfo  DD   ?
    rgPolicyInfo XPTR ?
CERT_POLICIES_INFO ENDS

CERT_POLICY_QUALIFIER_NOTICE_REFERENCE STRUCT ALIGNMODE
    pszOrganization XPTR ?
    cNoticeNumbers  DD   ?
    rgNoticeNumbers XPTR ?
CERT_POLICY_QUALIFIER_NOTICE_REFERENCE ENDS

CERT_POLICY_QUALIFIER_USER_NOTICE STRUCT ALIGNMODE
    pNoticeReference XPTR ?
    pszDisplayText   XPTR ?
CERT_POLICY_QUALIFIER_USER_NOTICE ENDS

CPS_URLS STRUCT ALIGNMODE
    pszURL     XPTR ?
    pAlgorithm XPTR ?
    pDigest    XPTR ?
CPS_URLS ENDS

CERT_POLICY95_QUALIFIER1 STRUCT ALIGNMODE
    pszPracticesReference  XPTR ?
    pszNoticeIdentifier    XPTR ?
    pszNSINoticeIdentifier XPTR ?
    cCPSURLs               DD   ?
    rgCPSURLs              XPTR ?
CERT_POLICY95_QUALIFIER1 ENDS

CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY STRUCT ALIGNMODE
    pszObjId XPTR ?
    cValue   DD   ?
    rgValue  XPTR ?
CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY ENDS

CRYPT_CONTENT_INFO STRUCT ALIGNMODE
    pszObjId XPTR ?
    Content  CRYPT_DER_BLOB <>
CRYPT_CONTENT_INFO ENDS

CRYPT_SEQUENCE_OF_ANY STRUCT ALIGNMODE
    cValue  DD   ?
    rgValue XPTR ?
CRYPT_SEQUENCE_OF_ANY ENDS

CERT_AUTHORITY_KEY_ID2_INFO STRUCT ALIGNMODE
    KeyId                     CRYPT_DATA_BLOB <>
    AuthorityCertIssuer       CERT_ALT_NAME_INFO <>
    AuthorityCertSerialNumber CRYPT_INTEGER_BLOB <>
CERT_AUTHORITY_KEY_ID2_INFO ENDS

CERT_ACCESS_DESCRIPTION STRUCT ALIGNMODE
    pszAccessMethod XPTR ?
    AccessLocation  CERT_ALT_NAME_ENTRY <>
CERT_ACCESS_DESCRIPTION ENDS

CERT_AUTHORITY_INFO_ACCESS STRUCT ALIGNMODE
    cAccDescr  DD   ?
    rgAccDescr XPTR ?
CERT_AUTHORITY_INFO_ACCESS ENDS

CRL_DIST_POINT_NAME STRUCT ALIGNMODE
    dwDistPointNameChoice DD   ?
    FullName              CERT_ALT_NAME_INFO <>
CRL_DIST_POINT_NAME ENDS

CRL_DIST_POINT STRUCT ALIGNMODE
    DistPointName CRL_DIST_POINT_NAME <>
    ReasonFlags   CRYPT_BIT_BLOB <>
    CRLIssuer     CERT_ALT_NAME_INFO <>
CRL_DIST_POINT ENDS

CRL_DIST_POINTS_INFO STRUCT ALIGNMODE
    cDistPoint  DD   ?
    rgDistPoint XPTR ?
CRL_DIST_POINTS_INFO ENDS

CERT_DSS_PARAMETERS STRUCT ALIGNMODE
    p CRYPT_UINT_BLOB <>
    q CRYPT_UINT_BLOB <>
    g CRYPT_UINT_BLOB <>
CERT_DSS_PARAMETERS ENDS

CERT_DH_PARAMETERS STRUCT ALIGNMODE
    p CRYPT_UINT_BLOB <>
    g CRYPT_UINT_BLOB <>
CERT_DH_PARAMETERS ENDS

CERT_X942_DH_VALIDATION_PARAMS STRUCT ALIGNMODE
    seed        CRYPT_BIT_BLOB <>
    pgenCounter XPTR ?
CERT_X942_DH_VALIDATION_PARAMS ENDS

CERT_X942_DH_PARAMETERS STRUCT ALIGNMODE
    p                 CRYPT_UINT_BLOB <>
    g                 CRYPT_UINT_BLOB <>
    q                 CRYPT_UINT_BLOB <>
    j                 CRYPT_UINT_BLOB <>
    pValidationParams XPTR ?
CERT_X942_DH_PARAMETERS ENDS

CRYPT_X942_OTHER_INFO STRUCT ALIGNMODE
    pszContentEncryptionObjId XPTR ?
    rgbCounter                DB CRYPT_X942_COUNTER_BYTE_LENGTH DUP(?)
    rgbKeyLength              DB CRYPT_X942_COUNTER_BYTE_LENGTH DUP(?)
    PubInfo                   CRYPT_DATA_BLOB <>
CRYPT_X942_OTHER_INFO ENDS

CRYPT_RC2_CBC_PARAMETERS STRUCT ALIGNMODE
    dwVersion DD ?
    fIV       DD ?
    rgbIV     DB 8 DUP(?)
CRYPT_RC2_CBC_PARAMETERS ENDS

CRYPT_SMIME_CAPABILITY STRUCT ALIGNMODE
    pszObjId   XPTR ?
    Parameters CRYPT_OBJID_BLOB <>
CRYPT_SMIME_CAPABILITY ENDS

CRYPT_SMIME_CAPABILITIES STRUCT ALIGNMODE
    cCapability  DD   ?
    rgCapability XPTR ?
CRYPT_SMIME_CAPABILITIES ENDS

CRYPT_OID_FUNC_ENTRY STRUCT ALIGNMODE
    pszOID     DD   ?
    pvFuncAddr XPTR ?
CRYPT_OID_FUNC_ENTRY ENDS

CRYPT_OID_INFO STRUCT ALIGNMODE
    cbSize            DD   ?
    pszOID            XPTR ?
    pwszName          XPTR ?
    dwGroupId         DD   ?
    UNION
        dwValue       DD   ?
        Algid         DD   ?
        dwLength      DD   ?
    ENDS
    ExtraInfo         CRYPT_DATA_BLOB <>
    pwszCNGAlgid      XPTR ?
    pwszCNGExtraAlgid XPTR ?
CRYPT_OID_INFO ENDS

CERT_ISSUER_SERIAL_NUMBER STRUCT ALIGNMODE
    Issuer       CERT_NAME_BLOB <>
    SerialNumber CRYPT_INTEGER_BLOB <>
CERT_ISSUER_SERIAL_NUMBER ENDS

CERT_ID STRUCT ALIGNMODE
    dwIdChoice             DD ?
    UNION
        IssuerSerialNumber CERT_ISSUER_SERIAL_NUMBER <>
        KeyId              CRYPT_HASH_BLOB <>
        HashId             CRYPT_HASH_BLOB <>
    ENDS
CERT_ID ENDS

CMSG_SIGNER_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                  DD    ?
    pCertInfo               XPTR  ?
    UNION
        hCryptProv          XWORD ?
        hNCryptKey          XWORD ?
    ENDS
    dwKeySpec               DD    ?
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashAuxInfo           XPTR  ?
    cAuthAttr               DD    ?
    rgAuthAttr              XPTR  ?
    cUnauthAttr             DD    ?
    rgUnauthAttr            XPTR  ?
    SignerId                CERT_ID <>
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashEncryptionAuxInfo XPTR  ?
CMSG_SIGNER_ENCODE_INFO ENDS

CMSG_SIGNED_ENCODE_INFO STRUCT ALIGNMODE
    cbSize            DD   ?
    cSigners          DD   ?
    rgSigners         XPTR ?
    cCertEncoded      DD   ?
    rgCertEncoded     XPTR ?
    cCrlEncoded       DD   ?
    rgCrlEncoded      XPTR ?
    cAttrCertEncoded  DD   ?
    rgAttrCertEncoded XPTR ?
CMSG_SIGNED_ENCODE_INFO ENDS

CMSG_ENVELOPED_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                     DD    ?
    hCryptProv                 XWORD ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvEncryptionAuxInfo        XPTR  ?
    cRecipients                DD    ?
    rgpRecipients              XPTR  ?
    rgCmsRecipients            XPTR  ?
    cCertEncoded               DD    ?
    rgCertEncoded              XPTR  ?
    cCrlEncoded                DD    ?
    rgCrlEncoded               XPTR  ?
    cAttrCertEncoded           DD    ?
    rgAttrCertEncoded          XPTR  ?
    cUnprotectedAttr           DD    ?
    rgUnprotectedAttr          XPTR  ?
CMSG_ENVELOPED_ENCODE_INFO ENDS

CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                 DD    ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvKeyEncryptionAuxInfo XPTR  ?
    hCryptProv             XWORD ?
    RecipientPublicKey     CRYPT_BIT_BLOB <>
    RecipientId            CERT_ID <>
CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO ENDS

CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO STRUCT ALIGNMODE
    cbSize             DD   ?
    RecipientPublicKey CRYPT_BIT_BLOB <>
    RecipientId        CERT_ID <>
    _Date              FILETIME <>
    pOtherAttr         XPTR ?
CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO ENDS

CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                    DD    ?
    KeyEncryptionAlgorithm    CRYPT_ALGORITHM_IDENTIFIER <>
    pvKeyEncryptionAuxInfo    XPTR  ?
    KeyWrapAlgorithm          CRYPT_ALGORITHM_IDENTIFIER <>
    pvKeyWrapAuxInfo          XPTR  ?
    hCryptProv                XWORD ?
    dwKeySpec                 DD    ?
    dwKeyChoice               DD    ?
    UNION
        pEphemeralAlgorithm   XPTR  ?
        pSenderId             XPTR  ?
    ENDS
    UserKeyingMaterial        CRYPT_DATA_BLOB <>
    cRecipientEncryptedKeys   DD    ?
    rgpRecipientEncryptedKeys XPTR  ?
CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO ENDS

CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                 DD    ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvKeyEncryptionAuxInfo XPTR  ?
    hCryptProv             XWORD ?
    dwKeyChoice            DD    ?
    UNION
        hKeyEncryptionKey  XWORD ?
        pvKeyEncryptionKey XPTR  ?
    ENDS
    KeyId                  CRYPT_DATA_BLOB <>
    _Date                  FILETIME <>
    pOtherAttr             XPTR  ?
CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO ENDS

CMSG_RECIPIENT_ENCODE_INFO STRUCT ALIGNMODE
    dwRecipientChoice DD   ?
    UNION
        pKeyTrans     XPTR ?
        pKeyAgree     XPTR ?
        pMailList     XPTR ?
    ENDS
CMSG_RECIPIENT_ENCODE_INFO ENDS

CMSG_RC2_AUX_INFO STRUCT ALIGNMODE
    cbSize   DD ?
    dwBitLen DD ?
CMSG_RC2_AUX_INFO ENDS

CMSG_SP3_COMPATIBLE_AUX_INFO STRUCT ALIGNMODE
    cbSize  DD ?
    dwFlags DD ?
CMSG_SP3_COMPATIBLE_AUX_INFO ENDS

CMSG_RC4_AUX_INFO STRUCT ALIGNMODE
    cbSize   DD ?
    dwBitLen DD ?
CMSG_RC4_AUX_INFO ENDS

CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO STRUCT ALIGNMODE
    cbSize        DD ?
    SignedInfo    CMSG_SIGNED_ENCODE_INFO <>
    EnvelopedInfo CMSG_ENVELOPED_ENCODE_INFO <>
CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO ENDS

CMSG_HASHED_ENCODE_INFO STRUCT ALIGNMODE
    cbSize        DD    ?
    hCryptProv    XWORD ?
    HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashAuxInfo DD    ?
CMSG_HASHED_ENCODE_INFO ENDS

CMSG_ENCRYPTED_ENCODE_INFO STRUCT ALIGNMODE
    cbSize                     DD   ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvEncryptionAuxInfo        XPTR ?
CMSG_ENCRYPTED_ENCODE_INFO ENDS

CMSG_STREAM_INFO STRUCT ALIGNMODE
    cbContent       DD   ?
    pfnStreamOutput XPTR ?
    pvArg           XPTR ?
CMSG_STREAM_INFO ENDS

CMSG_SIGNER_INFO STRUCT ALIGNMODE
    dwVersion               DD ?
    Issuer                  CERT_NAME_BLOB <>
    SerialNumber            CRYPT_INTEGER_BLOB <>
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER <>
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedHash           CRYPT_DATA_BLOB <>
    AuthAttrs               CRYPT_ATTRIBUTES <>
    UnauthAttrs             CRYPT_ATTRIBUTES <>
CMSG_SIGNER_INFO ENDS

CMSG_CMS_SIGNER_INFO STRUCT ALIGNMODE
    dwVersion               DD ?
    SignerId                CERT_ID <>
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER <>
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedHash           CRYPT_DATA_BLOB <>
    AuthAttrs               CRYPT_ATTRIBUTES <>
    UnauthAttrs             CRYPT_ATTRIBUTES <>
CMSG_CMS_SIGNER_INFO ENDS

CMSG_KEY_TRANS_RECIPIENT_INFO STRUCT ALIGNMODE
    dwVersion              DD ?
    RecipientId            CERT_ID <>
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedKey           CRYPT_DATA_BLOB <>
CMSG_KEY_TRANS_RECIPIENT_INFO ENDS

CMSG_RECIPIENT_ENCRYPTED_KEY_INFO STRUCT ALIGNMODE
    RecipientId  CERT_ID <>
    EncryptedKey CRYPT_DATA_BLOB <>
    _Date        FILETIME <>
    pOtherAttr   XPTR ?
CMSG_RECIPIENT_ENCRYPTED_KEY_INFO ENDS

CMSG_KEY_AGREE_RECIPIENT_INFO STRUCT ALIGNMODE
    dwVersion                   DD   ?
    dwOriginatorChoice          DD   ?
    UNION
        OriginatorCertId        CERT_ID <>
        OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
    ENDS
    UserKeyingMaterial          CRYPT_DATA_BLOB <>
    KeyEncryptionAlgorithm      CRYPT_ALGORITHM_IDENTIFIER <>
    cRecipientEncryptedKeys     DD   ?
    rgpRecipientEncryptedKeys   XPTR ?
CMSG_KEY_AGREE_RECIPIENT_INFO ENDS

CMSG_MAIL_LIST_RECIPIENT_INFO STRUCT ALIGNMODE
    dwVersion              DD   ?
    KeyId                  CRYPT_DATA_BLOB <>
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedKey           CRYPT_DATA_BLOB <>
    _Date                  FILETIME <>
    pOtherAttr             XPTR ?
CMSG_MAIL_LIST_RECIPIENT_INFO ENDS

CMSG_CMS_RECIPIENT_INFO STRUCT ALIGNMODE
    dwRecipientChoice DD   ?
    UNION
        pKeyTrans     XPTR ?
        pKeyAgree     XPTR ?
        pMailList     XPTR ?
    ENDS
CMSG_CMS_RECIPIENT_INFO ENDS

CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA STRUCT ALIGNMODE
    cbSize        DD    ?
    hCryptProv    XWORD ?
    dwSignerIndex DD    ?
    dwSignerType  DD    ?
    pvSigner      XPTR  ?
CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA ENDS

CMSG_CTRL_DECRYPT_PARA STRUCT ALIGNMODE
    cbSize           DD    ?
    hCryptProv       XWORD ?
    dwKeySpec        DD    ?
    dwRecipientIndex DD    ?
CMSG_CTRL_DECRYPT_PARA ENDS

CMSG_CTRL_KEY_TRANS_DECRYPT_PARA STRUCT ALIGNMODE
    cbSize           DD    ?
    hCryptProv       XWORD ?
    dwKeySpec        DD    ?
    pKeyTrans        XPTR  ?
    dwRecipientIndex DD    ?
CMSG_CTRL_KEY_TRANS_DECRYPT_PARA ENDS

CMSG_CTRL_KEY_AGREE_DECRYPT_PARA STRUCT ALIGNMODE
    cbSize                       DD    ?
    hCryptProv                   XWORD ?
    dwKeySpec                    DD    ?
    pKeyAgree                    XPTR  ?
    dwRecipientIndex             DD    ?
    dwRecipientEncryptedKeyIndex DD    ?
    OriginatorPublicKey          CRYPT_BIT_BLOB <>
CMSG_CTRL_KEY_AGREE_DECRYPT_PARA ENDS

CMSG_CTRL_MAIL_LIST_DECRYPT_PARA STRUCT ALIGNMODE
    cbSize                 DD    ?
    hCryptProv             XWORD ?
    pMailList              XPTR  ?
    dwRecipientIndex       DD    ?
    dwKeyChoice            DD    ?
    UNION
        hKeyEncryptionKey  XWORD ?
        pvKeyEncryptionKey XPTR  ?
    ENDS
CMSG_CTRL_MAIL_LIST_DECRYPT_PARA ENDS

CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA STRUCT ALIGNMODE
    cbSize        DD ?
    dwSignerIndex DD ?
    blob          CRYPT_DATA_BLOB <>
CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA ENDS

CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA STRUCT ALIGNMODE
    cbSize            DD ?
    dwSignerIndex     DD ?
    dwUnauthAttrIndex DD ?
CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA ENDS

CMSG_CONTENT_ENCRYPT_INFO STRUCT ALIGNMODE
    cbSize                     DD    ?
    hCryptProv                 XWORD ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvEncryptionAuxInfo        XPTR  ?
    cRecipients                DD    ?
    rgCmsRecipients            XPTR  ?
    pfnAlloc                   XPTR  ?
    pfnFree                    XPTR  ?
    dwEncryptFlags             DD    ?
    hContentEncryptKey         XWORD ?
    dwFlags                    DD    ?
CMSG_CONTENT_ENCRYPT_INFO ENDS

CMSG_KEY_TRANS_ENCRYPT_INFO STRUCT ALIGNMODE
    cbSize                 DD ?
    dwRecipientIndex       DD ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedKey           CRYPT_DATA_BLOB <>
    dwFlags                DD ?
CMSG_KEY_TRANS_ENCRYPT_INFO ENDS

CMSG_KEY_AGREE_KEY_ENCRYPT_INFO STRUCT ALIGNMODE
    cbSize       DD ?
    EncryptedKey CRYPT_DATA_BLOB <>
CMSG_KEY_AGREE_KEY_ENCRYPT_INFO ENDS

CMSG_KEY_AGREE_ENCRYPT_INFO STRUCT ALIGNMODE
    cbSize                      DD   ?
    dwRecipientIndex            DD   ?
    KeyEncryptionAlgorithm      CRYPT_ALGORITHM_IDENTIFIER <>
    UserKeyingMaterial          CRYPT_DATA_BLOB <>
    dwOriginatorChoice          DD   ?
    UNION
        OriginatorCertId        CERT_ID <>
        OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO <>
    ENDS
    cKeyAgreeKeyEncryptInfo     DD   ?
    rgpKeyAgreeKeyEncryptInfo   XPTR ?
    dwFlags                     DD   ?
CMSG_KEY_AGREE_ENCRYPT_INFO ENDS

CMSG_MAIL_LIST_ENCRYPT_INFO STRUCT ALIGNMODE
    cbSize                 DD ?
    dwRecipientIndex       DD ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    EncryptedKey           CRYPT_DATA_BLOB <>
    dwFlags                DD ?
CMSG_MAIL_LIST_ENCRYPT_INFO ENDS

CERT_CONTEXT STRUCT ALIGNMODE
    dwCertEncodingType DD    ?
    pbCertEncoded      XPTR  ?
    cbCertEncoded      DD    ?
    pCertInfo          XPTR  ?
    hCertStore         XWORD ?
CERT_CONTEXT ENDS

CRL_CONTEXT STRUCT ALIGNMODE
    dwCertEncodingType DD    ?
    pbCrlEncoded       XPTR  ?
    cbCrlEncoded       DD    ?
    pCrlInfo           XPTR  ?
    hCertStore         XWORD ?
CRL_CONTEXT ENDS

CTL_CONTEXT STRUCT ALIGNMODE
    dwMsgAndCertEncodingType DD    ?
    pbCtlEncoded             XPTR  ?
    cbCtlEncoded             DD    ?
    pCtlInfo                 XPTR  ?
    hCertStore               XWORD ?
    hCryptMsg                XWORD ?
    pbCtlContent             XPTR  ?
    cbCtlContent             DD    ?
CTL_CONTEXT ENDS

CRYPT_KEY_PROV_PARAM STRUCT ALIGNMODE
    dwParam DD   ?
    pbData  XPTR ?
    cbData  DD   ?
    dwFlags DD   ?
CRYPT_KEY_PROV_PARAM ENDS

CRYPT_KEY_PROV_INFO STRUCT ALIGNMODE
    pwszContainerName XPTR ?
    pwszProvName      XPTR ?
    dwProvType        DD   ?
    dwFlags           DD   ?
    cProvParam        DD   ?
    rgProvParam       XPTR ?
    dwKeySpec         DD   ?
CRYPT_KEY_PROV_INFO ENDS

CERT_KEY_CONTEXT STRUCT ALIGNMODE
    cbSize     DD    ?
    hCryptProv XWORD ?
    dwKeySpec  DD    ?
CERT_KEY_CONTEXT ENDS

CERT_SYSTEM_STORE_RELOCATE_PARA STRUCT ALIGNMODE
    UNION
        hKeyBase        XWORD ?
        pvBase          XPTR  ?
    ENDS
    UNION
        pvSystemStore   XPTR  ?
        pszSystemStore  XPTR  ?
        pwszSystemStore XPTR  ?
    ENDS
CERT_SYSTEM_STORE_RELOCATE_PARA ENDS

CERT_REGISTRY_STORE_CLIENT_GPT_PARA STRUCT ALIGNMODE
    hKeyBase    XWORD ?
    pwszRegPath XPTR  ?
CERT_REGISTRY_STORE_CLIENT_GPT_PARA ENDS

CERT_REGISTRY_STORE_ROAMING_PARA STRUCT ALIGNMODE
    hKey               XWORD ?
    pwszStoreDirectory XPTR  ?
CERT_REGISTRY_STORE_ROAMING_PARA ENDS

CERT_STORE_PROV_INFO STRUCT ALIGNMODE
    cbSize              DD    ?
    cStoreProvFunc      DD    ?
    rgpvStoreProvFunc   XPTR  ?
    hStoreProv          XWORD ?
    dwStoreProvFlags    DD    ?
    hStoreProvFuncAddr2 XWORD ?
CERT_STORE_PROV_INFO ENDS

CERT_STORE_PROV_FIND_INFO STRUCT ALIGNMODE
    cbSize                   DD   ?
    dwMsgAndCertEncodingType DD   ?
    dwFindFlags              DD   ?
    dwFindType               DD   ?
    pvFindPara               XPTR ?
CERT_STORE_PROV_FIND_INFO ENDS

CTL_ANY_SUBJECT_INFO STRUCT ALIGNMODE
    SubjectAlgorithm  CRYPT_ALGORITHM_IDENTIFIER <>
    SubjectIdentifier CRYPT_DATA_BLOB <>
CTL_ANY_SUBJECT_INFO ENDS

CTL_FIND_USAGE_PARA STRUCT ALIGNMODE
    cbSize         DD   ?
    SubjectUsage   CTL_USAGE <>
    ListIdentifier CRYPT_DATA_BLOB <>
    pSigner        XPTR ?
CTL_FIND_USAGE_PARA ENDS

CTL_FIND_SUBJECT_PARA STRUCT ALIGNMODE
    cbSize        DD   ?
    pUsagePara    XPTR ?
    dwSubjectType DD   ?
    pvSubject     XPTR ?
CTL_FIND_SUBJECT_PARA ENDS

CERT_CREATE_CONTEXT_PARA STRUCT ALIGNMODE
    cbSize  DD   ?
    pfnFree XPTR ?
    pvFree  XPTR ?
CERT_CREATE_CONTEXT_PARA ENDS

CERT_SYSTEM_STORE_INFO STRUCT ALIGNMODE
    cbSize DD ?
CERT_SYSTEM_STORE_INFO ENDS

CERT_PHYSICAL_STORE_INFO STRUCT ALIGNMODE
    cbSize               DD   ?
    pszOpenStoreProvider XPTR ?
    dwOpenEncodingType   DD   ?
    dwOpenFlags          DD   ?
    OpenParameters       CRYPT_DATA_BLOB <>
    dwFlags              DD   ?
    dwPriority           DD   ?
CERT_PHYSICAL_STORE_INFO ENDS

CTL_VERIFY_USAGE_PARA STRUCT ALIGNMODE
    cbSize         DD   ?
    ListIdentifier CRYPT_DATA_BLOB <>
    cCtlStore      DD   ?
    rghCtlStore    XPTR ?
    cSignerStore   DD   ?
    rghSignerStore DD   ?
CTL_VERIFY_USAGE_PARA ENDS

CTL_VERIFY_USAGE_STATUS STRUCT ALIGNMODE
    cbSize          DD   ?
    dwError         DD   ?
    dwFlags         DD   ?
    ppCtl           XPTR ?
    dwCtlEntryIndex DD   ?
    ppSigner        XPTR ?
    dwSignerIndex   DD   ?
CTL_VERIFY_USAGE_STATUS ENDS

CERT_REVOCATION_PARA STRUCT ALIGNMODE
    cbSize       DD    ?
    pIssuerCert  XPTR  ?
    cCertStore   DD    ?
    rgCertStore  XPTR  ?
    hCrlStore    XWORD ?
    pftTimeToUse XPTR  ?
CERT_REVOCATION_PARA ENDS

CERT_REVOCATION_STATUS STRUCT ALIGNMODE
    cbSize   DD ?
    dwIndex  DD ?
    dwError  DD ?
    dwReason DD ?
CERT_REVOCATION_STATUS ENDS

CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA STRUCT ALIGNMODE
    cOID     DD   ?
    rgpszOID XPTR ?
CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA ENDS

CRYPT_SIGN_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize                  DD   ?
    dwMsgEncodingType       DD   ?
    pSigningCert            XPTR ?
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashAuxInfo           XPTR ?
    cMsgCert                DD   ?
    rgpMsgCert              XPTR ?
    cMsgCrl                 DD   ?
    rgpMsgCrl               XPTR ?
    cAuthAttr               DD   ?
    rgAuthAttr              XPTR ?
    cUnauthAttr             DD   ?
    rgUnauthAttr            XPTR ?
    dwFlags                 DD   ?
    dwInnerContentType      DD   ?
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashEncryptionAuxInfo XPTR ?
CRYPT_SIGN_MESSAGE_PARA ENDS

CRYPT_VERIFY_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize                   DD    ?
    dwMsgAndCertEncodingType DD    ?
    hCryptProv               XWORD ?
    pfnGetSignerCertificate  XPTR  ?
    pvGetArg                 XPTR  ?
CRYPT_VERIFY_MESSAGE_PARA ENDS

CRYPT_ENCRYPT_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize                     DD    ?
    dwMsgEncodingType          DD    ?
    hCryptProv                 XWORD ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER <>
    pvEncryptionAuxInfo        XPTR  ?
    dwFlags                    DD    ?
    dwInnerContentType         DD    ?
CRYPT_ENCRYPT_MESSAGE_PARA ENDS

CRYPT_DECRYPT_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize                   DD   ?
    dwMsgAndCertEncodingType DD   ?
    cCertStore               DD   ?
    rghCertStore             XPTR ?
CRYPT_DECRYPT_MESSAGE_PARA ENDS

CRYPT_HASH_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize            DD    ?
    dwMsgEncodingType DD    ?
    hCryptProv        XWORD ?
    HashAlgorithm     CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashAuxInfo     XPTR  ?
CRYPT_HASH_MESSAGE_PARA ENDS

CRYPT_KEY_SIGN_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize                   DD    ?
    dwMsgAndCertEncodingType DD    ?
    hCryptProv               XWORD ?
    dwKeySpec                DD    ?
    HashAlgorithm            CRYPT_ALGORITHM_IDENTIFIER <>
    pvHashAuxInfo            XPTR  ?
    PubKeyAlgorithm          CRYPT_ALGORITHM_IDENTIFIER <>
CRYPT_KEY_SIGN_MESSAGE_PARA ENDS

CRYPT_KEY_VERIFY_MESSAGE_PARA STRUCT ALIGNMODE
    cbSize            DD    ?
    dwMsgEncodingType DD    ?
    hCryptProv        XWORD ?
CRYPT_KEY_VERIFY_MESSAGE_PARA ENDS

CERT_CHA STRUCT ALIGNMODE
    cCerts         DD ?
    certs          DD ?
    keyLocatorInfo CRYPT_KEY_PROV_INFO <>
CERT_CHA ENDS

CRYPT_BLOB_ARRAY STRUCT ALIGNMODE
    cBlob  DD   ?
    rgBlob XPTR ?
CRYPT_BLOB_ARRAY ENDS

CRYPT_CREDENTIALS STRUCT ALIGNMODE
    cbSize            DD   ?
    pszCredentialsOid XPTR ?
    pvCredentials     XPTR ?
CRYPT_CREDENTIALS ENDS

CRYPT_PASSWORD_CREDENTIALSA STRUCT ALIGNMODE
    cbSize      DD   ?
    pszUsername XPTR ?
    pszPassword XPTR ?
CRYPT_PASSWORD_CREDENTIALSA ENDS

CRYPT_PASSWORD_CREDENTIALSW STRUCT ALIGNMODE
    cbSize      DD   ?
    pszUsername XPTR ?
    pszPassword XPTR ?
CRYPT_PASSWORD_CREDENTIALSW ENDS

CRYPT_ASYNC_RETRIEVAL_COMPLETION STRUCT ALIGNMODE
    pfnCompletion XPTR ?
    pvCompletion  XPTR ?
CRYPT_ASYNC_RETRIEVAL_COMPLETION ENDS

CRYPT_URL_ARRAY STRUCT ALIGNMODE
    cUrl     DD   ?
    rgwszUrl XPTR ?
CRYPT_URL_ARRAY ENDS

CRYPT_URL_INFO STRUCT ALIGNMODE
    cbSize          DD   ?
    dwSyncDeltaTime DD   ?
    cGroup          DD   ?
    rgcGroupEntry   XPTR ?
CRYPT_URL_INFO ENDS

CRYPTPROTECT_PROMPTSTRUCT STRUCT ALIGNMODE
    cbSize        DD    ?
    dwPromptFlags DD    ?
    hwndApp       XWORD ?
    szPrompt      XPTR  ?
CRYPTPROTECT_PROMPTSTRUCT ENDS

CERT_SERVER_OCSP_RESPONSE_CONTEXT STRUCT ALIGNMODE
    cbSize                DD   ?
    pbEncodedOcspResponse XPTR ?
    cbEncodedOcspResponse DD   ?
CERT_SERVER_OCSP_RESPONSE_CONTEXT ENDS

CERT_CHAIN_ENGINE_CONFIG STRUCT ALIGNMODE
    cbSize                    DD    ?
    hRestrictedRoot           XWORD ?
    hRestrictedTrust          XWORD ?
    hRestrictedOther          XWORD ?
    cAdditionalStore          DD    ?
    rghAdditionalStore        XPTR  ?
    dwFlags                   DD    ?
    dwUrlRetrievalTimeout     DD    ?
    MaximumCachedCertificates DD    ?
    CycleDetectionModulus     DD    ?
    hExclusiveRoot            XWORD ?
    hExclusiveTrustedPeople   XWORD ?
    dwExclusiveFlags          DD    ?
CERT_CHAIN_ENGINE_CONFIG ENDS

CERT_TRUST_STATUS STRUCT ALIGNMODE
    dwErrorStatus DD ?
    dwInfoStatus  DD ?
CERT_TRUST_STATUS ENDS

CERT_REVOCATION_INFO STRUCT ALIGNMODE
    cbSize             DD ?
    dwRevocationResult DD ?
    pszRevocationOid   DD ?
    pvOidSpecificInfo  DD ?
CERT_REVOCATION_INFO ENDS

CERT_TRUST_LIST_INFO STRUCT ALIGNMODE
    cbSize      DD   ?
    pCtlEntry   XPTR ?
    pCtlContext XPTR ?
CERT_TRUST_LIST_INFO ENDS

CERT_CHAIN_ELEMENT STRUCT ALIGNMODE
    cbSize          DD   ?
    pCertContext    XPTR ?
    TrustStatus     CERT_TRUST_STATUS <>
    pRevocationInfo XPTR ?
CERT_CHAIN_ELEMENT ENDS

CERT_SIMPLE_CHAIN STRUCT ALIGNMODE
    cbSize         DD   ?
    TrustStatus    CERT_TRUST_STATUS <>
    cElement       DD   ?
    rgpElement     XPTR ?
    pTrustListInfo XPTR ?
CERT_SIMPLE_CHAIN ENDS

CERT_CHAIN_CONTEXT STRUCT ALIGNMODE
    cbSize                      DD   ?
    TrustStatus                 CERT_TRUST_STATUS <>
    cChain                      DD   ?
    rgpChain                    XPTR ?
    cLowerQualityChainContext   DD   ?
    rgpLowerQualityChainContext XPTR ?
    fHasRevocationFreshnessTime DD   ?
    dwRevocationFreshnessTime   DD   ?
CERT_CHAIN_CONTEXT ENDS

CERT_USAGE_MATCH STRUCT ALIGNMODE
    dwType DD ?
    Usage  CERT_ENHKEY_USAGE <>
CERT_USAGE_MATCH ENDS

CTL_USAGE_MATCH STRUCT ALIGNMODE
    dwType DD ?
    Usage  CTL_USAGE <>
CTL_USAGE_MATCH ENDS

CERT_CHAIN_PARA STRUCT ALIGNMODE
    cbSize         DD ?
    RequestedUsage CERT_USAGE_MATCH <>
CERT_CHAIN_PARA ENDS

CRL_REVOCATION_INFO STRUCT ALIGNMODE
    pCrlEntry       XPTR ?
    pCrlContext     XPTR ?
    pCrlIssuerChain XPTR ?
CRL_REVOCATION_INFO ENDS

CERT_CHAIN_FIND_BY_ISSUER_PARA STRUCT ALIGNMODE
    cbSize                   DD   ?
    pszUsageIdentifier       XPTR ?
    dwKeySpec                DD   ?
    dwAcquirePrivateKeyFlags DD   ?
    cIssuer                  DD   ?
    rgIssuer                 XPTR ?
    pfnFindCallback          XPTR ?
    pvFindArg                XPTR ?
CERT_CHAIN_FIND_BY_ISSUER_PARA ENDS

CERT_CHAIN_POLICY_PARA STRUCT ALIGNMODE
    cbSize            DD   ?
    dwFlags           DD   ?
    pvExtraPolicyPara XPTR ?
CERT_CHAIN_POLICY_PARA ENDS

CERT_CHAIN_POLICY_STATUS STRUCT ALIGNMODE
    cbSize              DD   ?
    dwError             DD   ?
    lChainIndex         DD   ?
    lElementIndex       DD   ?
    pvExtraPolicyStatus XPTR ?
CERT_CHAIN_POLICY_STATUS ENDS

AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA STRUCT ALIGNMODE
    cbSize              DD   ?
    dwRegPolicySettings DD   ?
    pSignerInfo         XPTR ?
AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA ENDS

AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS STRUCT ALIGNMODE
    cbSize      DD ?
    fCommercial DD ?
AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS ENDS

AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA STRUCT ALIGNMODE
    cbSize              DD ?
    dwRegPolicySettings DD ?
    fCommercial         DD ?
AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA ENDS

HTTPSPolicyCallbackData STRUCT ALIGNMODE
    UNION
        cbStruct   DD   ?
        cbSize     DD   ?
    ENDS
    dwAuthType     DD   ?
    fdwChecks      DD   ?
    pwszServerName XPTR ?
HTTPSPolicyCallbackData ENDS

CERT_SELECT_CHAIN_PARA STRUCT ALIGNMODE
    hChainEngine     XWORD ?
    pTime            XPTR  ?
    hAdditionalStore XWORD ?
    pChainPara       XPTR  ?
    dwFlags          DD    ?
CERT_SELECT_CHAIN_PARA ENDS

CERT_SELECT_CRITERIA STRUCT ALIGNMODE
    dwType DD   ?
    cPara  DD   ?
    ppPara XPTR ?
CERT_SELECT_CRITERIA ENDS

CRYPT_TIMESTAMP_REQUEST STRUCT ALIGNMODE
    dwVersion      DD    ?
    HashAlgorithm  CRYPT_ALGORITHM_IDENTIFIER <>
    HashedMessage  CRYPT_DER_BLOB <>
    pszTSAPolicyId XPTR  ?
    Nonce          CRYPT_INTEGER_BLOB <>
    fCertReq       XWORD ?
    cExtension     DD    ?
    rgExtension    XPTR  ?
CRYPT_TIMESTAMP_REQUEST ENDS

CRYPT_TIMESTAMP_RESPONSE STRUCT ALIGNMODE
    dwStatus    DD   ?
    cFreeText   DD   ?
    rgFreeText  XPTR ?
    FailureInfo CRYPT_BIT_BLOB <>
    ContentInfo CRYPT_DER_BLOB <>
CRYPT_TIMESTAMP_RESPONSE ENDS

CRYPT_TIMESTAMP_ACCURACY STRUCT ALIGNMODE
    dwSeconds DD ?
    dwMillis  DD ?
    dwMicros  DD ?
CRYPT_TIMESTAMP_ACCURACY ENDS

CRYPT_TIMESTAMP_INFO STRUCT ALIGNMODE
    dwVersion      DD    ?
    pszTSAPolicyId XPTR  ?
    HashAlgorithm  CRYPT_ALGORITHM_IDENTIFIER <>
    HashedMessage  CRYPT_DER_BLOB <>
    SerialNumber   CRYPT_INTEGER_BLOB <>
    ftTime         FILETIME <>
    pvAccuracy     XPTR  ?
    fOrdering      XWORD ?
    Nonce          CRYPT_DER_BLOB <>
    Tsa            CRYPT_DER_BLOB <>
    cExtension     DD    ?
    rgExtension    XPTR  ?
CRYPT_TIMESTAMP_INFO ENDS

CRYPT_TIMESTAMP_CONTEXT STRUCT ALIGNMODE
    cbEncoded  DD   ?
    pbEncoded  XPTR ?
    pTimeStamp XPTR ?
CRYPT_TIMESTAMP_CONTEXT ENDS

CRYPT_TIMESTAMP_PARA STRUCT ALIGNMODE
    pszTSAPolicyId XPTR  ?
    fRequestCerts  XWORD ?
    Nonce          CRYPT_INTEGER_BLOB <>
    cExtension     DD    ?
    rgExtension    XPTR  ?
CRYPT_TIMESTAMP_PARA ENDS


;======================================== Functions =======================================;
CertAddCRLContextToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddCRLLinkToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddCTLContextToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddCTLLinkToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddCertificateContextToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddCertificateLinkToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAddEncodedCRLToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertAddEncodedCTLToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertAddEncodedCertificateToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertAddEncodedCertificateToSystemStoreA PROTO :XWORD, :XWORD, :XWORD
CertAddEncodedCertificateToSystemStoreW PROTO :XWORD, :XWORD, :XWORD
CertAddEnhancedKeyUsageIdentifier PROTO :XWORD, :XWORD
CertAddRefServerOcspResponse PROTO :XWORD
CertAddRefServerOcspResponseContext PROTO :XPTR
CertAddSerializedElementToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertAddStoreToCollection PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertAlgIdToOID PROTO :XWORD
CertCloseServerOcspResponse PROTO :XWORD, :XWORD
CertCloseStore PROTO :XWORD, :XWORD
CertCompareCertificate PROTO :XWORD, :XWORD, :XWORD
CertCompareCertificateName PROTO :XWORD, :XWORD, :XWORD
CertCompareIntegerBlob PROTO :XWORD, :XWORD
CertComparePublicKeyInfo PROTO :XWORD, :XWORD, :XWORD
CertControlStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertCreateCRLContext PROTO :XWORD, :XWORD, :XWORD
CertCreateCTLContext PROTO :XWORD, :XWORD, :XWORD
CertCreateCTLEntryFromCertificateContextProperties PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertCreateCertificateChainEngine PROTO :XWORD, :XWORD
CertCreateCertificateContext PROTO :XWORD, :XWORD, :XWORD
CertCreateContext PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertCreateSelfSignCertificate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertDeleteCRLFromStore PROTO :XWORD
CertDeleteCTLFromStore PROTO :XWORD
CertDeleteCertificateFromStore PROTO :XWORD
CertDuplicateCRLContext PROTO :XWORD
CertDuplicateCTLContext PROTO :XWORD
CertDuplicateCertificateChain PROTO :XWORD
CertDuplicateCertificateContext PROTO :XWORD
CertDuplicateStore PROTO :XWORD
CertEnumCRLContextProperties PROTO :XWORD, :XWORD
CertEnumCRLsInStore PROTO :XWORD, :XWORD
CertEnumCTLContextProperties PROTO :XWORD, :XWORD
CertEnumCTLsInStore PROTO :XWORD, :XWORD
CertEnumCertificateContextProperties PROTO :XWORD, :XWORD
CertEnumCertificatesInStore PROTO :XWORD, :XWORD
CertEnumPhysicalStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertEnumSubjectInSortedCTL PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertEnumSystemStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertEnumSystemStoreLocation PROTO :XWORD, :XWORD, :XWORD
CertFindAttribute PROTO :XWORD, :XWORD, :XWORD
CertFindCRLInStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindCTLInStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindCertificateInCRL PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindCertificateInStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindChainInStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindExtension PROTO :XWORD, :XWORD, :XWORD
CertFindRDNAttr PROTO :XWORD, :XWORD
CertFindSubjectInCTL PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFindSubjectInSortedCTL PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertFreeCRLContext PROTO :XWORD
CertFreeCTLContext PROTO :XWORD
CertFreeCertificateChain PROTO :XWORD
CertFreeCertificateChainEngine PROTO :XWORD
CertFreeCertificateChainList PROTO :XPTR
CertFreeCertificateContext PROTO :XPTR
CertFreeServerOcspResponseContext PROTO :XPTR
CertGetCRLContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetCRLFromStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetCTLContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetCertificateChain PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertGetCertificateContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetEnhancedKeyUsage PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetIntendedKeyUsage PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetIssuerCertificateFromStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetNameStringA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertGetNameStringW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertGetPublicKeyLength PROTO :XWORD, :XWORD
CertGetServerOcspResponseContext PROTO :XWORD, :XWORD, :XPTR
CertGetStoreProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertGetSubjectCertificateFromStore PROTO :XWORD, :XWORD, :XWORD
CertGetValidUsages PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertIsRDNAttrsInCertificateName PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertIsStrongHashToSign PROTO :XPTR, :XPTR, :XPTR
CertIsValidCRLForCertificate PROTO :XWORD, :XWORD, :XWORD, :XWORD
IF NTDDI_VERSION GE NTDDI_WIN10
    CertIsWeakHash PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
CertNameToStrA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertNameToStrW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertOIDToAlgId PROTO :XWORD
CertOpenServerOcspResponse PROTO :XPTR, :XWORD, :XPTR
CertOpenStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertOpenSystemStoreA PROTO :XWORD, :XPTR
CertOpenSystemStoreW PROTO :XWORD, :XPTR
CertRDNValueToStrA PROTO :XWORD, :XWORD
CertRDNValueToStrW PROTO :XWORD, :XWORD
CertRegisterPhysicalStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertRegisterSystemStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertRemoveEnhancedKeyUsageIdentifier PROTO :XWORD, :XWORD
CertRemoveStoreFromCollection PROTO :XWORD, :XWORD
CertResyncCertificateChainEngine PROTO :XWORD
CertRetrieveLogoOrBiometricInfo PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
CertSaveStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertSelectCertificateChains PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
CertSerializeCRLStoreElement PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSerializeCTLStoreElement PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSerializeCertificateStoreElement PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSetCRLContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSetCTLContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSetCertificateContextPropertiesFromCTLEntry PROTO :XWORD, :XWORD, :XWORD
CertSetCertificateContextProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertSetEnhancedKeyUsage PROTO :XWORD, :XWORD
CertSetStoreProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertStrToNameA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertStrToNameW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertUnregisterPhysicalStore PROTO :XWORD, :XWORD, :XWORD
CertUnregisterSystemStore PROTO :XWORD, :XWORD
CertVerifyCRLRevocation PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertVerifyCRLTimeValidity PROTO :XWORD, :XWORD
CertVerifyCTLUsage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertVerifyCertificateChainPolicy PROTO :XWORD, :XWORD, :XWORD, :XWORD
CertVerifyRevocation PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CertVerifySubjectCertificateContext PROTO :XWORD, :XWORD, :XWORD
CertVerifyTimeValidity PROTO :XWORD, :XWORD
CertVerifyValidityNesting PROTO :XWORD, :XWORD
CryptAcquireCertificatePrivateKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IFNDEF
    CryptAcquireContextA PROTO :XPTR, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
    CryptAcquireContextW PROTO :XPTR, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD
ENDIF
CryptBinaryToStringA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptBinaryToStringW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptCloseAsyncHandle PROTO :XWORD
CryptCreateAsyncHandle PROTO :XWORD, :XWORD
IFNDEF CryptCreateHash
    CryptCreateHash PROTO :HANDLE, :XWORD, :HKEY, :XWORD, :XPTR
ENDIF
CryptCreateKeyIdentifierFromCSP PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptDecodeMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptDecodeObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptDecodeObjectEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IFNDEF CryptDecrypt
    CryptDecrypt PROTO :HANDLE, :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR
ENDIF
CryptDecryptAndVerifyMessageSignature PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptDecryptMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IFNDEF CryptDeriveKey
    CryptDeriveKey PROTO :HANDLE, :XWORD, :HANDLE, :XWORD, :XPTR
ENDIF
IFNDEF CryptDestroyHash
    CryptDestroyHash PROTO :HANDLE
ENDIF
IFNDEF CryptDestroyKey
    CryptDestroyKey PROTO :HANDLE
ENDIF
CryptEncodeObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptEncodeObjectEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IFNDEF CryptEncrypt
    CryptEncrypt PROTO :HANDLE, :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
ENDIF
CryptEncryptMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptEnumKeyIdentifierProperties PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptEnumOIDFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptEnumOIDInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptExportPKCS8 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptExportPublicKeyInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptExportPublicKeyInfoEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptExportPublicKeyInfoFromBCryptKeyHandle PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
CryptFindCertificateKeyProvInfo PROTO :XWORD, :XWORD, :XWORD
CryptFindLocalizedName PROTO :XWORD
CryptFindOIDInfo PROTO :XWORD, :XWORD, :XWORD
CryptFormatObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptFreeOIDFunctionAddress PROTO :XWORD, :XWORD
CryptGetAsyncParam PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptGetDefaultOIDDllList PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptGetDefaultOIDFunctionAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptGetKeyIdentifierProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptGetMessageCertificates PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptGetMessageSignerCount PROTO :XWORD, :XWORD, :XWORD
CryptGetOIDFunctionAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptGetOIDFunctionValue PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptHashCertificate PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
CryptHashCertificate2 PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
IFNDEF CryptHashData
    CryptHashData PROTO :HANDLE, :XPTR, :XWORD, :XWORD
ENDIF
CryptHashMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptHashPublicKeyInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptHashToBeSigned PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptImportPKCS8 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptImportPublicKeyInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptImportPublicKeyInfoEx PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
CryptImportPublicKeyInfoEx2 PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
CryptInitOIDFunctionSet PROTO :XWORD, :XWORD
CryptInstallDefaultContext PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptInstallOIDFunctionAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptLoadSip PROTO :XWORD, :XWORD, :XWORD
CryptMemAlloc PROTO :XWORD
CryptMemFree PROTO :XWORD
CryptMemRealloc PROTO :XWORD, :XWORD
CryptMsgCalculateEncodedLength PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgClose PROTO :XWORD
CryptMsgControl PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgCountersign PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgCountersignEncoded PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgDuplicate PROTO :XWORD
CryptMsgEncodeAndSignCTL PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgGetAndVerifySigner PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgGetParam PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgOpenToDecode PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgOpenToEncode PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgSignCTL PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgUpdate PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgVerifyCountersignatureEncoded PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptMsgVerifyCountersignatureEncodedEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptProtectData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptProtectMemory PROTO :XPTR, :XWORD, :XWORD
IFNDEF CryptReleaseContext
    CryptReleaseContext PROTO :HANDLE, :XWORD
ENDIF
CryptQueryObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptRegisterDefaultOIDFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptRegisterOIDFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptRegisterOIDInfo PROTO :XWORD, :XWORD
CryptRetrieveTimeStamp PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
CryptSIPAddProvider PROTO :XWORD
CryptSIPCreateIndirectData PROTO :XWORD, :XWORD, :XWORD
IF NTDDI_VERSION GE NTDDI_WIN8
    CryptSIPGetCaps PROTO :XPTR, :XPTR
ENDIF
CryptSIPGetSignedDataMsg PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSIPLoad PROTO :XWORD, :XWORD, :XWORD
CryptSIPPutSignedDataMsg PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSIPRemoveProvider PROTO :XWORD
CryptSIPRemoveSignedDataMsg PROTO :XWORD, :XWORD
CryptSIPRetrieveSubjectGuid PROTO :XWORD, :XWORD, :XWORD
CryptSIPRetrieveSubjectGuidForCatalogFile PROTO :XWORD, :XWORD, :XWORD
CryptSIPVerifyIndirectData PROTO :XWORD, :XWORD
CryptSetAsyncParam PROTO :XWORD, :XWORD, :XWORD, :XWORD
CryptSetKeyIdentifierProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSetOIDFunctionValue PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSignAndEncodeCertificate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSignAndEncryptMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSignCertificate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSignMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptSignMessageWithKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptStringToBinaryA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptStringToBinaryW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptUninstallDefaultContext PROTO :XWORD, :XWORD, :XWORD
CryptUnprotectData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptUnprotectMemory PROTO :XPTR, :XWORD, :XWORD
CryptUnregisterDefaultOIDFunction PROTO :XWORD, :XWORD, :XWORD
CryptUnregisterOIDFunction PROTO :XWORD, :XWORD, :XWORD
CryptUnregisterOIDInfo PROTO :XWORD
CryptUpdateProtectedState PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
CryptVerifyCertificateSignature PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyCertificateSignatureEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyDetachedMessageHash PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyDetachedMessageSignature PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyMessageHash PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyMessageSignature PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyMessageSignatureWithKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CryptVerifyTimeStampSignature PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
I_CertProtectFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_CertSrvProtectFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_CertSyncStore PROTO :XWORD, :XWORD
I_CertUpdateStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_CryptAddRefLruEntry PROTO
I_CryptAddSmartCardCertToStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_CryptAllocTls PROTO
I_CryptCreateLruCache PROTO :XWORD, :XWORD
I_CryptCreateLruEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_CryptDetachTls PROTO :XWORD
I_CryptDisableLruOfEntries PROTO :XWORD
I_CryptEnableLruOfEntries PROTO :XWORD, :XWORD
I_CryptEnumMatchingLruEntries PROTO :XWORD
I_CryptFindLruEntry PROTO :XWORD, :XWORD
I_CryptFindLruEntryData PROTO :XWORD, :XWORD, :XWORD
I_CryptFindSmartCardCertInStore PROTO :XWORD
I_CryptFlushLruCache PROTO :XWORD, :XWORD, :XWORD
I_CryptFreeLruCache PROTO :XWORD, :XWORD, :XWORD
I_CryptFreeTls PROTO :XWORD, :XWORD
I_CryptGetAsn1Decoder PROTO :XWORD
I_CryptGetAsn1Encoder PROTO :XWORD
I_CryptGetDefaultCryptProv PROTO :XWORD
I_CryptGetDefaultCryptProvForEncrypt PROTO :XWORD, :XWORD, :XWORD
I_CryptGetFileVersion PROTO :XWORD, :XWORD, :XWORD
I_CryptGetLruEntryData PROTO :XWORD
I_CryptGetLruEntryIdentifier PROTO :XWORD
I_CryptGetOssGlobal PROTO :XWORD
I_CryptGetTls PROTO :XWORD
I_CryptInsertLruEntry PROTO :XWORD, :XWORD
I_CryptInstallAsn1Module PROTO :XWORD, :XWORD, :XWORD
I_CryptInstallOssGlobal PROTO :XWORD, :XWORD, :XWORD
I_CryptReadTrustedPublisherDWORDValueFromRegistry PROTO :XWORD, :XWORD
I_CryptRegisterSmartCardStore PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_CryptReleaseLruEntry PROTO :XWORD
I_CryptRemoveLruEntry PROTO :XWORD, :XWORD, :XWORD
I_CryptSetTls PROTO :XWORD, :XWORD
I_CryptTouchLruEntry PROTO :XWORD, :XWORD
I_CryptUninstallAsn1Module PROTO :XWORD
I_CryptUninstallOssGlobal PROTO :XWORD
I_CryptUnregisterSmartCardStore PROTO :XWORD
I_CryptWalkAllLruCacheEntries PROTO :XWORD, :XWORD, :XWORD
PFXExportCertStore PROTO :XWORD, :XWORD, :XWORD, :XWORD
PFXExportCertStore2 PROTO :XWORD, :XWORD, :XWORD, :XWORD
PFXExportCertStoreEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
PFXImportCertStore PROTO :XWORD, :XWORD, :XWORD
PFXIsPFXBlob PROTO :XWORD
PFXVerifyPassword PROTO :XWORD, :XWORD, :XWORD

IFDEF APP_UNICODE
    CREDENTIAL_OID_PASSWORD_CREDENTIALS EQU <CREDENTIAL_OID_PASSWORD_CREDENTIALS_W>
    CRYPT_PASSWORD_CREDENTIALS EQU <CRYPT_PASSWORD_CREDENTIALSW>
    MS_DEF_PROV EQU <MS_DEF_PROV_W>
    MS_ENHANCED_PROV EQU <MS_ENHANCED_PROV_W>
    MS_STRONG_PROV EQU <MS_STRONG_PROV_W>
    MS_DEF_RSA_SIG_PROV EQU <MS_DEF_RSA_SIG_PROV_W>
    MS_DEF_RSA_SCHANNEL_PROV EQU <MS_DEF_RSA_SCHANNEL_PROV_W>
    MS_DEF_DSS_PROV EQU <MS_DEF_DSS_PROV_W>
    MS_DEF_DSS_DH_PROV EQU <MS_DEF_DSS_DH_PROV_W>
    MS_ENH_DSS_DH_PROV EQU <MS_ENH_DSS_DH_PROV_W>
    MS_DEF_DH_SCHANNEL_PROV EQU <MS_DEF_DH_SCHANNEL_PROV_W>
    MS_SCARD_PROV EQU <MS_SCARD_PROV_W>
    MS_ENH_RSA_AES_PROV_XP EQU <MS_ENH_RSA_AES_PROV_XP_W>
    MS_ENH_RSA_AES_PROV EQU <MS_ENH_RSA_AES_PROV_W>
    CertAddEncodedCertificateToSystemStore EQU <CertAddEncodedCertificateToSystemStoreW>
    CertGetNameString EQU <CertGetNameStringW>
    CertNameToStr EQU <CertNameToStrW>
    CertOpenSystemStore EQU <CertOpenSystemStoreW>
    CertRDNValueToStr EQU <CertRDNValueToStrW>
    CertStrToName EQU <CertStrToNameW>
    IFNDEF CryptAcquireContext
        CryptAcquireContext EQU <CryptAcquireContextW>
    ENDIF
    CryptBinaryToString EQU <CryptBinaryToStringW>
    CryptEnumProviders EQU <CryptEnumProvidersW>
    CryptEnumProviderTypes EQU <CryptEnumProviderTypesW>
    CryptGetDefaultProvider EQU <CryptGetDefaultProviderW>
    CryptRetrieveObjectByUrl EQU <CryptRetrieveObjectByUrlW>
    CryptSetProvider EQU <CryptSetProviderW>
    CryptSetProviderEx EQU <CryptSetProviderExW>
    CryptSignHash EQU <CryptSignHashW>
    CryptStringToBinary EQU <CryptStringToBinaryW>
    CryptVerifySignature EQU <CryptVerifySignatureW>
ELSE
    CREDENTIAL_OID_PASSWORD_CREDENTIALS EQU <CREDENTIAL_OID_PASSWORD_CREDENTIALS_A>
    CRYPT_PASSWORD_CREDENTIALS EQU <CRYPT_PASSWORD_CREDENTIALSA>
    MS_DEF_PROV EQU <MS_DEF_PROV_A>
    MS_ENHANCED_PROV EQU <MS_ENHANCED_PROV_A>
    MS_STRONG_PROV EQU <MS_STRONG_PROV_A>
    MS_DEF_RSA_SIG_PROV EQU <MS_DEF_RSA_SIG_PROV_A>
    MS_DEF_RSA_SCHANNEL_PROV EQU <MS_DEF_RSA_SCHANNEL_PROV_A>
    MS_DEF_DSS_PROV EQU <MS_DEF_DSS_PROV_A>
    MS_DEF_DSS_DH_PROV EQU <MS_DEF_DSS_DH_PROV_A>
    MS_ENH_DSS_DH_PROV EQU <MS_ENH_DSS_DH_PROV_A>
    MS_DEF_DH_SCHANNEL_PROV EQU <MS_DEF_DH_SCHANNEL_PROV_A>
    MS_SCARD_PROV EQU <MS_SCARD_PROV_A>
    MS_ENH_RSA_AES_PROV_XP EQU <MS_ENH_RSA_AES_PROV_XP_A>
    MS_ENH_RSA_AES_PROV EQU <MS_ENH_RSA_AES_PROV_A>
    CertAddEncodedCertificateToSystemStore EQU <CertAddEncodedCertificateToSystemStoreA>
    CertGetNameString EQU <CertGetNameStringA>
    CertNameToStr EQU <CertNameToStrA>
    CertOpenSystemStore EQU <CertOpenSystemStoreA>
    CertRDNValueToStr EQU <CertRDNValueToStrA>
    CertStrToName EQU <CertStrToNameA>
    IFNDEF CryptAcquireContext
        CryptAcquireContext EQU <CryptAcquireContextA>
    ENDIF
    CryptBinaryToString EQU <CryptBinaryToStringA>
    CryptEnumProviders EQU <CryptEnumProvidersA>
    CryptEnumProviderTypes EQU <CryptEnumProviderTypesA>
    CryptGetDefaultProvider EQU <CryptGetDefaultProviderA>
    CryptRetrieveObjectByUrl EQU <CryptRetrieveObjectByUrlA>
    CryptSetProvider EQU <CryptSetProviderA>
    CryptSetProviderEx EQU <CryptSetProviderExA>
    CryptSignHash EQU <CryptSignHashA>
    CryptStringToBinary EQU <CryptStringToBinaryA>
    CryptVerifySignature EQU <CryptVerifySignatureA>
ENDIF


;======================= Undocumented functions (unknown arguments) =======================;
;IF NTDDI_VERSION GE NTDDI_WIN81
;    CryptObjectLocatorFree PROTO
;    CryptObjectLocatorGet PROTO
;    CryptObjectLocatorGetContent PROTO
;    CryptObjectLocatorGetUpdated PROTO
;    CryptObjectLocatorInitialize PROTO
;    CryptObjectLocatorIsChanged PROTO
;    CryptObjectLocatorRelease PROTO
;    I_PFXImportCertStoreEx PROTO
;ENDIF

;I_CertDiagControl PROTO

;IF NTDDI_VERSION GE NTDDI_WIN10
;    I_CertChainEngineIsDisallowedCertificate PROTO
;    I_CertFinishSslHandshake PROTO
;    I_CertProcessSslHandshake PROTO
;    I_CryptAllocTlsEx PROTO
;ENDIF

ENDIF ;CRYPT32_INC
