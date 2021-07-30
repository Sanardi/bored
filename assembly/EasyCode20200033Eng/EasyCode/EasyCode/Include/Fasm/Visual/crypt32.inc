; ====================================================;
;                                                     ;
;     crypt32.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.7)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2019-2020          ;
;                                                     ;
; ====================================================;

if ~defined CRYPT32_INC
define CRYPT32_INC 1

ALG_CLASS_ANY                                   equ     0
ALG_CLASS_SIGNATURE                             equ     1 shl 13
ALG_CLASS_MSG_ENCRYPT                           equ     2 shl 13
ALG_CLASS_DATA_ENCRYPT                          equ     3 shl 13
ALG_CLASS_HASH                                  equ     4 shl 13
ALG_CLASS_KEY_EXCHANGE                          equ     5 shl 13
ALG_CLASS_ALL                                   equ     7 shl 13

ALG_TYPE_ANY                                    equ     0
ALG_TYPE_DSS                                    equ     1 shl 9
ALG_TYPE_RSA                                    equ     2 shl 9
ALG_TYPE_BLOCK                                  equ     3 shl 9
ALG_TYPE_STREAM                                 equ     4 shl 9
ALG_TYPE_DH                                     equ     5 shl 9
ALG_TYPE_SECURECHANNEL                          equ     6 shl 9

ALG_SID_ANY                                     equ     0
ALG_SID_RSA_ANY                                 equ     0
ALG_SID_RSA_PKCS                                equ     1
ALG_SID_RSA_MSATWORK                            equ     2
ALG_SID_RSA_ENTRUST                             equ     3
ALG_SID_RSA_PGP                                 equ     4
ALG_SID_DSS_ANY                                 equ     0
ALG_SID_DSS_PKCS                                equ     1
ALG_SID_DSS_DMS                                 equ     2
ALG_SID_ECDSA                                   equ     3

ALG_SID_DES                                     equ     1
ALG_SID_3DES                                    equ     3
ALG_SID_DESX                                    equ     4
ALG_SID_IDEA                                    equ     5
ALG_SID_CAST                                    equ     6
ALG_SID_SAFERSK64                               equ     7
ALG_SID_SAFERSK128                              equ     8
ALG_SID_3DES_112                                equ     9
ALG_SID_CYLINK_MEK                              equ     12
ALG_SID_RC5                                     equ     13
ALG_SID_AES_128                                 equ     14
ALG_SID_AES_192                                 equ     15
ALG_SID_AES_256                                 equ     16
ALG_SID_AES                                     equ     17

ALG_SID_SKIPJACK                                equ     10
ALG_SID_TEK                                     equ     11

CRYPT_MODE_CBCI                                 equ     6
CRYPT_MODE_CFBP                                 equ     7
CRYPT_MODE_OFBP                                 equ     8
CRYPT_MODE_CBCOFM                               equ     9
CRYPT_MODE_CBCOFMI                              equ     10

ALG_SID_RC2                                     equ     2
ALG_SID_RC4                                     equ     1
ALG_SID_SEAL                                    equ     2
ALG_SID_DH_SANDF                                equ     1
ALG_SID_DH_EPHEM                                equ     2
ALG_SID_AGREED_KEY_ANY                          equ     3
ALG_SID_KEA                                     equ     4
ALG_SID_ECDH                                    equ     5

ALG_SID_MD2                                     equ     1
ALG_SID_MD4                                     equ     2
ALG_SID_MD5                                     equ     3
ALG_SID_SHA                                     equ     4
ALG_SID_SHA1                                    equ     4
ALG_SID_MAC                                     equ     5
ALG_SID_RIPEMD                                  equ     6
ALG_SID_RIPEMD160                               equ     7
ALG_SID_SSL3SHAMD5                              equ     8
ALG_SID_HMAC                                    equ     9
ALG_SID_TLS1PRF                                 equ     10
ALG_SID_HASH_REPLACE_OWF                        equ     11
ALG_SID_SHA_256                                 equ     12
ALG_SID_SHA_384                                 equ     13
ALG_SID_SHA_512                                 equ     14
ALG_SID_ECMQV                                   equ     1

ALG_SID_SSL3_MASTER                             equ     1
ALG_SID_SCHANNEL_MASTER_HASH                    equ     2
ALG_SID_SCHANNEL_MAC_KEY                        equ     3
ALG_SID_PCT1_MASTER                             equ     4
ALG_SID_SSL2_MASTER                             equ     5
ALG_SID_TLS1_MASTER                             equ     6
ALG_SID_SCHANNEL_ENC_KEY                        equ     7
ALG_SID_EXAMPLE                                 equ     80

CALG_MD2                                        equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD2)
CALG_MD4                                        equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD4)
CALG_MD5                                        equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MD5)
CALG_SHA                                        equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA)
CALG_SHA1                                       equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA1)
CALG_MAC                                        equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_MAC)
CALG_RSA_SIGN                                   equ     (ALG_CLASS_SIGNATURE or ALG_TYPE_RSA or ALG_SID_RSA_ANY)
CALG_DSS_SIGN                                   equ     (ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_DSS_ANY)
CALG_NO_SIGN                                    equ     (ALG_CLASS_SIGNATURE or ALG_TYPE_ANY or ALG_SID_ANY)
CALG_RSA_KEYX                                   equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_RSA or ALG_SID_RSA_ANY)
CALG_DES                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_DES)
CALG_3DES_112                                   equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_3DES_112)
CALG_3DES                                       equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_3DES)
CALG_DESX                                       equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_DESX)
CALG_RC2                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_RC2)
CALG_RC4                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_STREAM or ALG_SID_RC4)
CALG_SEAL                                       equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_STREAM or ALG_SID_SEAL)
CALG_DH_SF                                      equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_DH_SANDF)
CALG_DH_EPHEM                                   equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_DH_EPHEM)
CALG_AGREEDKEY_ANY                              equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_AGREED_KEY_ANY)
CALG_KEA_KEYX                                   equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_KEA)
CALG_HUGHES_MD5                                 equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ANY or ALG_SID_MD5)
CALG_SKIPJACK                                   equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_SKIPJACK)
CALG_TEK                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_TEK)
CALG_CYLINK_MEK                                 equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_CYLINK_MEK)
CALG_SSL3_SHAMD5                                equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SSL3SHAMD5)
CALG_SSL3_MASTER                                equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SSL3_MASTER)
CALG_SCHANNEL_MASTER_HASH                       equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_MASTER_HASH)
CALG_SCHANNEL_MAC_KEY                           equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_MAC_KEY)
CALG_SCHANNEL_ENC_KEY                           equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SCHANNEL_ENC_KEY)
CALG_PCT1_MASTER                                equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_PCT1_MASTER)
CALG_SSL2_MASTER                                equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_SSL2_MASTER)
CALG_TLS1_MASTER                                equ     (ALG_CLASS_MSG_ENCRYPT or ALG_TYPE_SECURECHANNEL or ALG_SID_TLS1_MASTER)
CALG_RC5                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_RC5)
CALG_HMAC                                       equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_HMAC)
CALG_TLS1PRF                                    equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_TLS1PRF)
CALG_HASH_REPLACE_OWF                           equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_HASH_REPLACE_OWF)
CALG_AES_128                                    equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_128)
CALG_AES_192                                    equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_192)
CALG_AES_256                                    equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES_256)
CALG_AES                                        equ     (ALG_CLASS_DATA_ENCRYPT or ALG_TYPE_BLOCK or ALG_SID_AES)
CALG_SHA_256                                    equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_256)
CALG_SHA_384                                    equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_384)
CALG_SHA_512                                    equ     (ALG_CLASS_HASH or ALG_TYPE_ANY or ALG_SID_SHA_512)
CALG_ECDH                                       equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_DH or ALG_SID_ECDH)
CALG_ECMQV                                      equ     (ALG_CLASS_KEY_EXCHANGE or ALG_TYPE_ANY or ALG_SID_ECMQV)
CALG_ECDSA                                      equ     (ALG_CLASS_SIGNATURE or ALG_TYPE_DSS or ALG_SID_ECDSA)

CRYPT_VERIFYCONTEXT                             equ     0F0000000H
CRYPT_NEWKEYSET                                 equ     000000008H
CRYPT_DELETEKEYSET                              equ     000000010H
CRYPT_MACHINE_KEYSET                            equ     000000020H
CRYPT_SILENT                                    equ     000000040H
CRYPT_DEFAULT_CONTAINER_OPTIONAL                equ     000000080H
CRYPT_EXPORTABLE                                equ     000000001H
CRYPT_USER_PROTECTED                            equ     000000002H
CRYPT_CREATE_SALT                               equ     000000004H
CRYPT_UPDATE_KEY                                equ     000000008H
CRYPT_NO_SALT                                   equ     000000010H
CRYPT_PREGEN                                    equ     000000040H
CRYPT_RECIPIENT                                 equ     000000010H
CRYPT_INITIATOR                                 equ     000000040H
CRYPT_ONLINE                                    equ     000000080H
CRYPT_SF                                        equ     000000100H
CRYPT_CREATE_IV                                 equ     000000200H
CRYPT_KEK                                       equ     000000400H
CRYPT_DATA_KEY                                  equ     000000800H
CRYPT_VOLATILE                                  equ     000001000H
CRYPT_SGCKEY                                    equ     000002000H
CRYPT_ARCHIVABLE                                equ     000004000H
CRYPT_FORCE_KEY_PROTECTION_HIGH                 equ     000008000H

RSA1024BIT_KEY                                  equ     004000000H
CRYPT_SERVER                                    equ     000000400H
KEY_LENGTH_MASK                                 equ     0FFFF0000H
CRYPT_Y_ONLY                                    equ     000000001H
CRYPT_SSL2_FALLBACK                             equ     000000002H
CRYPT_DESTROYKEY                                equ     000000004H
CRYPT_OAEP                                      equ     000000040H
CRYPT_BLOB_VER3                                 equ     000000080H
CRYPT_IPSEC_HMAC_KEY                            equ     000000100H
CRYPT_DECRYPT_RSA_NO_PADDING_CHECK              equ     000000020H

CRYPT_SECRETDIGEST                              equ     000000001H

CRYPT_OWF_REPL_LM_HASH                          equ     000000001H

CRYPT_LITTLE_ENDIAN                             equ     000000001H
CRYPT_NOHASHOID                                 equ     000000001H
CRYPT_TYPE2_FORMAT                              equ     000000002H
CRYPT_X931_FORMAT                               equ     000000004H
CRYPT_MACHINE_DEFAULT                           equ     000000001H
CRYPT_USER_DEFAULT                              equ     000000002H
CRYPT_DELETE_DEFAULT                            equ     000000004H

SIMPLEBLOB                                      equ     01H
PUBLICKEYBLOB                                   equ     06H
PRIVATEKEYBLOB                                  equ     07H
PLAINTEXTKEYBLOB                                equ     08H
OPAQUEKEYBLOB                                   equ     09H
PUBLICKEYBLOBEX                                 equ     0AH
SYMMETRICWRAPKEYBLOB                            equ     0BH
KEYSTATEBLOB                                    equ     0CH

AT_KEYEXCHANGE                                  equ     1
AT_SIGNATURE                                    equ     2

CRYPT_USERDATA                                  equ     1

KP_IV                                           equ     1
KP_SALT                                         equ     2
KP_PADDING                                      equ     3
KP_MODE                                         equ     4
KP_MODE_BITS                                    equ     5
KP_PERMISSIONS                                  equ     6
KP_ALGID                                        equ     7
KP_BLOCKLEN                                     equ     8
KP_KEYLEN                                       equ     9
KP_SALT_EX                                      equ     10
KP_P                                            equ     11
KP_G                                            equ     12
KP_Q                                            equ     13
KP_X                                            equ     14
KP_Y                                            equ     15
KP_RA                                           equ     16
KP_RB                                           equ     17
KP_INFO                                         equ     18
KP_EFFECTIVE_KEYLEN                             equ     19
KP_SCHANNEL_ALG                                 equ     20
KP_CLIENT_RANDOM                                equ     21
KP_SERVER_RANDOM                                equ     22
KP_RP                                           equ     23
KP_PRECOMP_MD5                                  equ     24
KP_PRECOMP_SHA                                  equ     25
KP_CERTIFICATE                                  equ     26
KP_CLEAR_KEY                                    equ     27
KP_PUB_EX_LEN                                   equ     28
KP_PUB_EX_VAL                                   equ     29
KP_KEYVAL                                       equ     30
KP_ADMIN_PIN                                    equ     31
KP_KEYEXCHANGE_PIN                              equ     32
KP_SIGNATURE_PIN                                equ     33
KP_PREHASH                                      equ     34
KP_ROUNDS                                       equ     35
KP_OAEP_PARAMS                                  equ     36
KP_CMS_KEY_INFO                                 equ     37
KP_CMS_DH_KEY_INFO                              equ     38
KP_PUB_PARAMS                                   equ     39
KP_VERIFY_PARAMS                                equ     40
KP_HIGHEST_VERSION                              equ     41
KP_GET_USE_COUNT                                equ     42
KP_PIN_ID                                       equ     43
KP_PIN_INFO                                     equ     44

PKCS5_PADDING                                   equ     1
RANDOM_PADDING                                  equ     2
ZERO_PADDING                                    equ     3

CRYPT_MODE_CBC                                  equ     1
CRYPT_MODE_ECB                                  equ     2
CRYPT_MODE_OFB                                  equ     3
CRYPT_MODE_CFB                                  equ     4
CRYPT_MODE_CTS                                  equ     5
CRYPT_ENCRYPT                                   equ     00001H
CRYPT_DECRYPT                                   equ     00002H
CRYPT_EXPORT                                    equ     00004H
CRYPT_READ                                      equ     00008H
CRYPT_WRITE                                     equ     00010H
CRYPT_MAC                                       equ     00020H
CRYPT_EXPORT_KEY                                equ     00040H
CRYPT_IMPORT_KEY                                equ     00080H
CRYPT_ARCHIVE                                   equ     00100H

HP_ALGID                                        equ     00001H
HP_HASHVAL                                      equ     00002H
HP_HASHSIZE                                     equ     00004H
HP_HMAC_INFO                                    equ     00005H
HP_TLS1PRF_LABEL                                equ     00006H
HP_TLS1PRF_SEED                                 equ     00007H

CRYPT_FAILED                                    equ     FALSE
CRYPT_SUCCEED                                   equ     TRUE

PP_ENUMALGS                                     equ     1
PP_ENUMCONTAINERS                               equ     2
PP_IMPTYPE                                      equ     3
PP_NAME                                         equ     4
PP_VERSION                                      equ     5
PP_CONTAINER                                    equ     6
PP_CHANGE_PASSWORD                              equ     7
PP_KEYSET_SEC_DESCR                             equ     8
PP_CERTCHAIN                                    equ     9
PP_KEY_TYPE_SUBTYPE                             equ     10
PP_PROVTYPE                                     equ     16
PP_KEYSTORAGE                                   equ     17
PP_APPLI_CERT                                   equ     18
PP_SYM_KEYSIZE                                  equ     19
PP_SESSION_KEYSIZE                              equ     20
PP_UI_PROMPT                                    equ     21
PP_ENUMALGS_EX                                  equ     22
PP_ENUMMANDROOTS                                equ     25
PP_ENUMELECTROOTS                               equ     26
PP_KEYSET_TYPE                                  equ     27
PP_ADMIN_PIN                                    equ     31
PP_KEYEXCHANGE_PIN                              equ     32
PP_SIGNATURE_PIN                                equ     33
PP_SIG_KEYSIZE_INC                              equ     34
PP_KEYX_KEYSIZE_INC                             equ     35
PP_UNIQUE_CONTAINER                             equ     36
PP_SGC_INFO                                     equ     37
PP_USE_HARDWARE_RNG                             equ     38
PP_KEYSPEC                                      equ     39
PP_ENUMEX_SIGNING_PROT                          equ     40
PP_CRYPT_COUNT_KEY_USE                          equ     41
PP_USER_CERTSTORE                               equ     42
PP_SMARTCARD_READER                             equ     43
PP_SMARTCARD_GUID                               equ     45
PP_ROOT_CERTSTORE                               equ     46

CRYPT_FIRST                                     equ     1
CRYPT_NEXT                                      equ     2
CRYPT_SGC_ENUM                                  equ     4
CRYPT_IMPL_HARDWARE                             equ     1
CRYPT_IMPL_SOFTWARE                             equ     2
CRYPT_IMPL_MIXED                                equ     3
CRYPT_IMPL_UNKNOWN                              equ     4
CRYPT_IMPL_REMOVABLE                            equ     8
CRYPT_SEC_DESCR                                 equ     000000001H
CRYPT_PSTORE                                    equ     000000002H
CRYPT_UI_PROMPT                                 equ     000000004H
CRYPT_FLAG_PCT1                                 equ     00001H
CRYPT_FLAG_SSL2                                 equ     00002H
CRYPT_FLAG_SSL3                                 equ     00004H
CRYPT_FLAG_TLS1                                 equ     00008H
CRYPT_FLAG_IPSEC                                equ     00010H
CRYPT_FLAG_SIGNING                              equ     00020H
CRYPT_SGC                                       equ     00001H
CRYPT_FASTSGC                                   equ     00002H

PP_CLIENT_HWND                                  equ     1
PP_CONTEXT_INFO                                 equ     11
PP_KEYEXCHANGE_KEYSIZE                          equ     12
PP_SIGNATURE_KEYSIZE                            equ     13
PP_KEYEXCHANGE_ALG                              equ     14
PP_SIGNATURE_ALG                                equ     15
PP_DELETEKEY                                    equ     24
PP_PIN_PROMPT_STRING                            equ     44
PP_SECURE_KEYEXCHANGE_PIN                       equ     47
PP_SECURE_SIGNATURE_PIN                         equ     48

PROV_RSA_FULL                                   equ     1
PROV_RSA_SIG                                    equ     2
PROV_DSS                                        equ     3
PROV_FORTEZZA                                   equ     4
PROV_MS_EXCHANGE                                equ     5
PROV_SSL                                        equ     6
PROV_RSA_SCHANNEL                               equ     12
PROV_DSS_DH                                     equ     13
PROV_EC_ECDSA_SIG                               equ     14
PROV_EC_ECNRA_SIG                               equ     15
PROV_EC_ECDSA_FULL                              equ     16
PROV_EC_ECNRA_FULL                              equ     17
PROV_DH_SCHANNEL                                equ     18
PROV_SPYRUS_LYNKS                               equ     20
PROV_RNG                                        equ     21
PROV_INTEL_SEC                                  equ     22
PROV_REPLACE_OWF                                equ     23
PROV_RSA_AES                                    equ     24

PROV_STT_MER                                    equ     7
PROV_STT_ACQ                                    equ     8
PROV_STT_BRND                                   equ     9
PROV_STT_ROOT                                   equ     10
PROV_STT_ISS                                    equ     11

MAXUIDLEN                                       equ     64
EXPO_OFFLOAD_REG_VALUE                          db      "ExpoOffload", 0
EXPO_OFFLOAD_FUNC_NAME                          db      "OffloadModExpo", 0
szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS             db      "Software\\Policies\\Microsoft\\Cryptography", 0

szFORCE_KEY_PROTECTION                          db      "ForceKeyProtection", 0
dwFORCE_KEY_PROTECTION_DISABLED                 equ     00H
dwFORCE_KEY_PROTECTION_USER_SELECT              equ     01H
dwFORCE_KEY_PROTECTION_HIGH                     equ     02H

szKEY_CACHE_ENABLED                             db      "CachePrivateKeys", 0
szKEY_CACHE_SECONDS                             db      "PrivateKeyLifetimeSeconds", 0

szPRIV_KEY_CACHE_MAX_ITEMS                      db      "PrivKeyCacheMaxItems", 0
cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT               equ     20

szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS         db      "PrivKeyCachePurgeIntervalSeconds", 0
cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT  equ     86400

CUR_BLOB_VERSION                                equ     2

MS_DEF_PROV_A                                   db      "Microsoft Base Cryptographic Provider v1.0", 0
MS_DEF_PROV_W                                   du      "Microsoft Base Cryptographic Provider v1.0", 0
MS_ENHANCED_PROV_A                              db      "Microsoft Enhanced Cryptographic Provider v1.0", 0
MS_ENHANCED_PROV_W                              du      "Microsoft Enhanced Cryptographic Provider v1.0", 0
MS_STRONG_PROV_A                                db      "Microsoft Strong Cryptographic Provider", 0
MS_STRONG_PROV_W                                du      "Microsoft Strong Cryptographic Provider", 0
MS_DEF_RSA_SIG_PROV_A                           db      "Microsoft RSA Signature Cryptographic Provider", 0
MS_DEF_RSA_SIG_PROV_W                           du      "Microsoft RSA Signature Cryptographic Provider", 0
MS_DEF_RSA_SCHANNEL_PROV_A                      db      "Microsoft RSA SChannel Cryptographic Provider", 0
MS_DEF_RSA_SCHANNEL_PROV_W                      du      "Microsoft RSA SChannel Cryptographic Provider", 0
MS_DEF_DSS_PROV_A                               db      "Microsoft Base DSS Cryptographic Provider", 0
MS_DEF_DSS_PROV_W                               du      "Microsoft Base DSS Cryptographic Provider", 0
MS_DEF_DSS_DH_PROV_A                            db      "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider", 0
MS_DEF_DSS_DH_PROV_W                            du      "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider", 0
MS_ENH_DSS_DH_PROV_A                            db      "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider", 0
MS_ENH_DSS_DH_PROV_W                            du      "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider", 0
MS_DEF_DH_SCHANNEL_PROV_A                       db      "Microsoft DH SChannel Cryptographic Provider", 0, 0
MS_DEF_DH_SCHANNEL_PROV_W                       du      "Microsoft DH SChannel Cryptographic Provider", 0
MS_SCARD_PROV_A                                 db      "Microsoft Base Smart Card Crypto Provider", 0
MS_SCARD_PROV_W                                 du      "Microsoft Base Smart Card Crypto Provider", 0

MS_ENH_RSA_AES_PROV_A                           db      "Microsoft Enhanced RSA and AES Cryptographic Provider", 0
MS_ENH_RSA_AES_PROV_W                           du      "Microsoft Enhanced RSA and AES Cryptographic Provider", 0
MS_ENH_RSA_AES_PROV_XP_A                        db      "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)", 0
MS_ENH_RSA_AES_PROV_XP_W                        du      "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)", 0

SCHANNEL_MAC_KEY                                equ     000000000H
SCHANNEL_ENC_KEY                                equ     000000001H
INTERNATIONAL_USAGE                             equ     000000001H

szOID_RSA                                       db      "1.2.840.113549", 0
szOID_PKCS                                      db      "1.2.840.113549.1", 0
szOID_RSA_HASH                                  db      "1.2.840.113549.2", 0
szOID_RSA_ENCRYPT                               db      "1.2.840.113549.3", 0
szOID_PKCS_1                                    db      "1.2.840.113549.1.1", 0
szOID_PKCS_2                                    db      "1.2.840.113549.1.2", 0
szOID_PKCS_3                                    db      "1.2.840.113549.1.3", 0
szOID_PKCS_4                                    db      "1.2.840.113549.1.4", 0
szOID_PKCS_5                                    db      "1.2.840.113549.1.5", 0
szOID_PKCS_6                                    db      "1.2.840.113549.1.6", 0
szOID_PKCS_7                                    db      "1.2.840.113549.1.7", 0
szOID_PKCS_8                                    db      "1.2.840.113549.1.8", 0
szOID_PKCS_9                                    db      "1.2.840.113549.1.9", 0
szOID_PKCS_10                                   db      "1.2.840.113549.1.10", 0
szOID_PKCS_12                                   db      "1.2.840.113549.1.12", 0
szOID_RSA_RSA                                   db      "1.2.840.113549.1.1.1", 0
szOID_RSA_MD2RSA                                db      "1.2.840.113549.1.1.2", 0
szOID_RSA_MD4RSA                                db      "1.2.840.113549.1.1.3", 0
szOID_RSA_MD5RSA                                db      "1.2.840.113549.1.1.4", 0
szOID_RSA_SHA1RSA                               db      "1.2.840.113549.1.1.5", 0
szOID_RSA_SETOAEP_RSA                           db      "1.2.840.113549.1.1.6", 0
szOID_RSA_DH                                    db      "1.2.840.113549.1.3.1", 0
szOID_RSA_data                                  db      "1.2.840.113549.1.7.1", 0
szOID_RSA_signedData                            db      "1.2.840.113549.1.7.2", 0
szOID_RSA_envelopedData                         db      "1.2.840.113549.1.7.3", 0
szOID_RSA_signEnvData                           db      "1.2.840.113549.1.7.4", 0
szOID_RSA_digestedData                          db      "1.2.840.113549.1.7.5", 0
szOID_RSA_hashedData                            db      "1.2.840.113549.1.7.5", 0
szOID_RSA_encryptedData                         db      "1.2.840.113549.1.7.6", 0
szOID_RSA_emailAddr                             db      "1.2.840.113549.1.9.1", 0
szOID_RSA_unstructName                          db      "1.2.840.113549.1.9.2", 0
szOID_RSA_contentType                           db      "1.2.840.113549.1.9.3", 0
szOID_RSA_messageDigest                         db      "1.2.840.113549.1.9.4", 0
szOID_RSA_signingTime                           db      "1.2.840.113549.1.9.5", 0
szOID_RSA_counterSign                           db      "1.2.840.113549.1.9.6", 0
szOID_RSA_challengePwd                          db      "1.2.840.113549.1.9.7", 0
szOID_RSA_unstructAddr                          db      "1.2.840.113549.1.9.8", 0
szOID_RSA_extCertAttrs                          db      "1.2.840.113549.1.9.9", 0
szOID_RSA_certExtensions                        db      "1.2.840.113549.1.9.14", 0
szOID_RSA_SMIMECapabilities                     db      "1.2.840.113549.1.9.15", 0
szOID_RSA_preferSignedData                      db      "1.2.840.113549.1.9.15.1", 0
szOID_RSA_SMIMEalg                              db      "1.2.840.113549.1.9.16.3", 0
szOID_RSA_SMIMEalgESDH                          db      "1.2.840.113549.1.9.16.3.5", 0
szOID_RSA_SMIMEalgCMS3DESwrap                   db      "1.2.840.113549.1.9.16.3.6", 0
szOID_RSA_SMIMEalgCMSRC2wrap                    db      "1.2.840.113549.1.9.16.3.7", 0
szOID_RSA_MD2                                   db      "1.2.840.113549.2.2", 0
szOID_RSA_MD4                                   db      "1.2.840.113549.2.4", 0
szOID_RSA_MD5                                   db      "1.2.840.113549.2.5", 0
szOID_RSA_RC2CBC                                db      "1.2.840.113549.3.2", 0
szOID_RSA_RC4                                   db      "1.2.840.113549.3.4", 0
szOID_RSA_DES_EDE3_CBC                          db      "1.2.840.113549.3.7", 0
szOID_RSA_RC5_CBCPad                            db      "1.2.840.113549.3.9", 0
szOID_ANSI_X942                                 db      "1.2.840.10046", 0
szOID_ANSI_X942_DH                              db      "1.2.840.10046.2.1", 0
szOID_X957                                      db      "1.2.840.10040", 0
szOID_X957_DSA                                  db      "1.2.840.10040.4.1", 0
szOID_X957_SHA1DSA                              db      "1.2.840.10040.4.3", 0
szOID_DS                                        db      "2.5", 0
szOID_DSALG                                     db      "2.5.8", 0
szOID_DSALG_CRPT                                db      "2.5.8.1", 0
szOID_DSALG_HASH                                db      "2.5.8.2", 0
szOID_DSALG_SIGN                                db      "2.5.8.3", 0
szOID_DSALG_RSA                                 db      "2.5.8.1.1", 0
szOID_OIW                                       db      "1.3.14", 0
szOID_OIWSEC                                    db      "1.3.14.3.2", 0
szOID_OIWSEC_md4RSA                             db      "1.3.14.3.2.2", 0
szOID_OIWSEC_md5RSA                             db      "1.3.14.3.2.3", 0
szOID_OIWSEC_md4RSA2                            db      "1.3.14.3.2.4", 0
szOID_OIWSEC_desECB                             db      "1.3.14.3.2.6", 0
szOID_OIWSEC_desCBC                             db      "1.3.14.3.2.7", 0
szOID_OIWSEC_desOFB                             db      "1.3.14.3.2.8", 0
szOID_OIWSEC_desCFB                             db      "1.3.14.3.2.9", 0
szOID_OIWSEC_desMAC                             db      "1.3.14.3.2.10", 0
szOID_OIWSEC_rsaSign                            db      "1.3.14.3.2.11", 0
szOID_OIWSEC_dsa                                db      "1.3.14.3.2.12", 0
szOID_OIWSEC_shaDSA                             db      "1.3.14.3.2.13", 0
szOID_OIWSEC_mdc2RSA                            db      "1.3.14.3.2.14", 0
szOID_OIWSEC_shaRSA                             db      "1.3.14.3.2.15", 0
szOID_OIWSEC_dhCommMod                          db      "1.3.14.3.2.16", 0
szOID_OIWSEC_desEDE                             db      "1.3.14.3.2.17", 0
szOID_OIWSEC_sha                                db      "1.3.14.3.2.18", 0
szOID_OIWSEC_mdc2                               db      "1.3.14.3.2.19", 0
szOID_OIWSEC_dsaComm                            db      "1.3.14.3.2.20", 0
szOID_OIWSEC_dsaCommSHA                         db      "1.3.14.3.2.21", 0
szOID_OIWSEC_rsaXchg                            db      "1.3.14.3.2.22", 0
szOID_OIWSEC_keyHashSeal                        db      "1.3.14.3.2.23", 0
szOID_OIWSEC_md2RSASign                         db      "1.3.14.3.2.24", 0
szOID_OIWSEC_md5RSASign                         db      "1.3.14.3.2.25", 0
szOID_OIWSEC_sha1                               db      "1.3.14.3.2.26", 0
szOID_OIWSEC_dsaSHA1                            db      "1.3.14.3.2.27", 0
szOID_OIWSEC_dsaCommSHA1                        db      "1.3.14.3.2.28", 0
szOID_OIWSEC_sha1RSASign                        db      "1.3.14.3.2.29", 0
szOID_OIWDIR                                    db      "1.3.14.7.2", 0
szOID_OIWDIR_CRPT                               db      "1.3.14.7.2.1", 0
szOID_OIWDIR_HASH                               db      "1.3.14.7.2.2", 0
szOID_OIWDIR_SIGN                               db      "1.3.14.7.2.3", 0
szOID_OIWDIR_md2                                db      "1.3.14.7.2.2.1", 0
szOID_OIWDIR_md2RSA                             db      "1.3.14.7.2.3.1", 0
szOID_INFOSEC                                   db      "2.16.840.1.101.2.1", 0
szOID_INFOSEC_sdnsSignature                     db      "2.16.840.1.101.2.1.1.1", 0
szOID_INFOSEC_mosaicSignature                   db      "2.16.840.1.101.2.1.1.2", 0
szOID_INFOSEC_sdnsConfidentiality               db      "2.16.840.1.101.2.1.1.3", 0
szOID_INFOSEC_mosaicConfidentiality             db      "2.16.840.1.101.2.1.1.4", 0
szOID_INFOSEC_sdnsIntegrity                     db      "2.16.840.1.101.2.1.1.5", 0
szOID_INFOSEC_mosaicIntegrity                   db      "2.16.840.1.101.2.1.1.6", 0
szOID_INFOSEC_sdnsTokenProtection               db      "2.16.840.1.101.2.1.1.7", 0
szOID_INFOSEC_mosaicTokenProtection             db      "2.16.840.1.101.2.1.1.8", 0
szOID_INFOSEC_sdnsKeyManagement                 db      "2.16.840.1.101.2.1.1.9", 0
szOID_INFOSEC_mosaicKeyManagement               db      "2.16.840.1.101.2.1.1.10", 0
szOID_INFOSEC_sdnsKMandSig                      db      "2.16.840.1.101.2.1.1.11", 0
szOID_INFOSEC_mosaicKMandSig                    db      "2.16.840.1.101.2.1.1.12", 0
szOID_INFOSEC_SuiteASignature                   db      "2.16.840.1.101.2.1.1.13", 0
szOID_INFOSEC_SuiteAConfidentiality             db      "2.16.840.1.101.2.1.1.14", 0
szOID_INFOSEC_SuiteAIntegrity                   db      "2.16.840.1.101.2.1.1.15", 0
szOID_INFOSEC_SuiteATokenProtection             db      "2.16.840.1.101.2.1.1.16", 0
szOID_INFOSEC_SuiteAKeyManagement               db      "2.16.840.1.101.2.1.1.17", 0
szOID_INFOSEC_SuiteAKMandSig                    db      "2.16.840.1.101.2.1.1.18", 0
szOID_INFOSEC_mosaicUpdatedSig                  db      "2.16.840.1.101.2.1.1.19", 0
szOID_INFOSEC_mosaicKMandUpdSig                 db      "2.16.840.1.101.2.1.1.20", 0
szOID_INFOSEC_mosaicUpdatedInteg                db      "2.16.840.1.101.2.1.1.21", 0

szOID_COMMON_NAME                               db      "2.5.4.3", 0
szOID_SUR_NAME                                  db      "2.5.4.4", 0
szOID_DEVICE_SERIAL_NUMBER                      db      "2.5.4.5", 0
szOID_COUNTRY_NAME                              db      "2.5.4.6", 0
szOID_LOCALITY_NAME                             db      "2.5.4.7", 0
szOID_STATE_OR_PROVINCE_NAME                    db      "2.5.4.8", 0
szOID_STREET_ADDRESS                            db      "2.5.4.9", 0
szOID_ORGANIZATION_NAME                         db      "2.5.4.10", 0
szOID_ORGANIZATIONAL_UNIT_NAME                  db      "2.5.4.11", 0
szOID_TITLE                                     db      "2.5.4.12", 0
szOID_DESCRIPTION                               db      "2.5.4.13", 0
szOID_SEARCH_GUIDE                              db      "2.5.4.14", 0
szOID_BUSINESS_CATEGORY                         db      "2.5.4.15", 0
szOID_POSTAL_ADDRESS                            db      "2.5.4.16", 0
szOID_POSTAL_CODE                               db      "2.5.4.17", 0
szOID_POST_OFFICE_BOX                           db      "2.5.4.18", 0
szOID_PHYSICAL_DELIVERY_OFFICE_NAME             db      "2.5.4.19", 0
szOID_TELEPHONE_NUMBER                          db      "2.5.4.20", 0
szOID_TELEX_NUMBER                              db      "2.5.4.21", 0
szOID_TELETEXT_TERMINAL_IDENTIFIER              db      "2.5.4.22", 0
szOID_FACSIMILE_TELEPHONE_NUMBER                db      "2.5.4.23", 0
szOID_X21_ADDRESS                               db      "2.5.4.24", 0
szOID_INTERNATIONAL_ISDN_NUMBER                 db      "2.5.4.25", 0
szOID_REGISTERED_ADDRESS                        db      "2.5.4.26", 0
szOID_DESTINATION_INDICATOR                     db      "2.5.4.27", 0
szOID_PREFERRED_DELIVERY_METHOD                 db      "2.5.4.28", 0
szOID_PRESENTATION_ADDRESS                      db      "2.5.4.29", 0
szOID_SUPPORTED_APPLICATION_CONTEXT             db      "2.5.4.30", 0
szOID_MEMBER                                    db      "2.5.4.31", 0
szOID_OWNER                                     db      "2.5.4.32", 0
szOID_ROLE_OCCUPANT                             db      "2.5.4.33", 0
szOID_SEE_ALSO                                  db      "2.5.4.34", 0
szOID_USER_PASSWORD                             db      "2.5.4.35", 0
szOID_USER_CERTIFICATE                          db      "2.5.4.36", 0
szOID_CA_CERTIFICATE                            db      "2.5.4.37", 0
szOID_AUTHORITY_REVOCATION_LIST                 db      "2.5.4.38", 0
szOID_CERTIFICATE_REVOCATION_LIST               db      "2.5.4.39", 0
szOID_CROSS_CERTIFICATE_PAIR                    db      "2.5.4.40", 0
szOID_GIVEN_NAME                                db      "2.5.4.42", 0
szOID_INITIALS                                  db      "2.5.4.43", 0
szOID_DN_QUALIFIER                              db      "2.5.4.46", 0
szOID_DOMAIN_COMPONENT                          db      "0.9.2342.19200300.100.1.25", 0
szOID_PKCS_12_FRIENDLY_NAME_ATTR                db      "1.2.840.113549.1.9.20", 0
szOID_PKCS_12_LOCAL_KEY_ID                      db      "1.2.840.113549.1.9.21", 0
szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR            db      "1.3.6.1.4.1.311.17.1", 0
szOID_LOCAL_MACHINE_KEYSET                      db      "1.3.6.1.4.1.311.17.2", 0
szOID_KEYID_RDN                                 db      "1.3.6.1.4.1.311.10.7.1", 0

CERT_RDN_ANY_TYPE                               equ     0
CERT_RDN_ENCODED_BLOB                           equ     1
CERT_RDN_OCTET_STRING                           equ     2
CERT_RDN_NUMERIC_STRING                         equ     3
CERT_RDN_PRINTABLE_STRING                       equ     4
CERT_RDN_TELETEX_STRING                         equ     5
CERT_RDN_T61_STRING                             equ     5
CERT_RDN_VIDEOTEX_STRING                        equ     6
CERT_RDN_IA5_STRING                             equ     7
CERT_RDN_GRAPHIC_STRING                         equ     8
CERT_RDN_VISIBLE_STRING                         equ     9
CERT_RDN_ISO646_STRING                          equ     9
CERT_RDN_GENERAL_STRING                         equ     10
CERT_RDN_UNIVERSAL_STRING                       equ     11
CERT_RDN_INT4_STRING                            equ     11
CERT_RDN_BMP_STRING                             equ     12
CERT_RDN_UNICODE_STRING                         equ     12
CERT_RDN_UTF8_STRING                            equ     13
CERT_RDN_TYPE_MASK                              equ     0000000FFH
CERT_RDN_FLAGS_MASK                             equ     0FF000000H
CERT_RDN_ENABLE_T61_UNICODE_FLAG                equ     080000000H
CERT_RDN_ENABLE_UTF8_UNICODE_FLAG               equ     020000000H
CERT_RDN_DISABLE_CHECK_TYPE_FLAG                equ     040000000H
CERT_RDN_DISABLE_IE4_UTF8_FLAG                  equ     001000000H

CERT_RSA_PUBLIC_KEY_OBJID                       equ     szOID_RSA_RSA
CERT_DEFAULT_OID_PUBLIC_KEY_SIGN                equ     szOID_RSA_RSA
CERT_DEFAULT_OID_PUBLIC_KEY_XCHG                equ     szOID_RSA_RSA

CERT_V1                                         equ     0
CERT_V2                                         equ     1
CERT_V3                                         equ     2
CERT_INFO_VERSION_FLAG                          equ     1
CERT_INFO_SERIAL_NUMBER_FLAG                    equ     2
CERT_INFO_SIGNATURE_ALGORITHM_FLAG              equ     3
CERT_INFO_ISSUER_FLAG                           equ     4
CERT_INFO_NOT_BEFORE_FLAG                       equ     5
CERT_INFO_NOT_AFTER_FLAG                        equ     6
CERT_INFO_SUBJECT_FLAG                          equ     7
CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG          equ     8
CERT_INFO_ISSUER_UNIQUE_ID_FLAG                 equ     9
CERT_INFO_SUBJECT_UNIQUE_ID_FLAG                equ     10
CERT_INFO_EXTENSION_FLAG                        equ     11

CRL_V1                                          equ     0
CRL_V2                                          equ     1

CERT_REQUEST_V1                                 equ     0

CERT_KEYGEN_REQUEST_V1                          equ     0

CTL_V1                                          equ     0

CERT_ENCODING_TYPE_MASK                         equ     00000FFFFH
CMSG_ENCODING_TYPE_MASK                         equ     0FFFF0000H
CRYPT_ASN_ENCODING                              equ     000000001H
CRYPT_NDR_ENCODING                              equ     000000002H
X509_ASN_ENCODING                               equ     000000001H
X509_NDR_ENCODING                               equ     000000002H
PKCS_7_ASN_ENCODING                             equ     000010000H
PKCS_7_NDR_ENCODING                             equ     000020000H

CRYPT_FORMAT_STR_MULTI_LINE                     equ     00001H
CRYPT_FORMAT_STR_NO_HEX                         equ     00010H
CRYPT_FORMAT_SIMPLE                             equ     00001H
CRYPT_FORMAT_X509                               equ     00002H
CRYPT_FORMAT_OID                                equ     00004H
CRYPT_FORMAT_RDN_SEMICOLON                      equ     00100H
CRYPT_FORMAT_RDN_CRLF                           equ     00200H
CRYPT_FORMAT_RDN_UNQUOTE                        equ     00400H
CRYPT_FORMAT_RDN_REVERSE                        equ     00800H
CRYPT_FORMAT_COMMA                              equ     01000H
CRYPT_FORMAT_SEMICOLON                          equ     CRYPT_FORMAT_RDN_SEMICOLON
CRYPT_FORMAT_CRLF                               equ     CRYPT_FORMAT_RDN_CRLF

CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    equ     08H
CRYPT_ENCODE_ALLOC_FLAG                         equ     08000H
CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG equ       CERT_RDN_ENABLE_T61_UNICODE_FLAG
CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG equ      CERT_RDN_ENABLE_UTF8_UNICODE_FLAG
CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG equ       CERT_RDN_DISABLE_CHECK_TYPE_FLAG
CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG equ      010000H

CRYPT_DECODE_NOCOPY_FLAG                        equ     01H
CRYPT_DECODE_TO_BE_SIGNED_FLAG                  equ     02H
CRYPT_DECODE_SHARE_OID_STRING_FLAG              equ     04H
CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    equ     08H
CRYPT_DECODE_ALLOC_FLAG                         equ     08000H
CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG equ     CERT_RDN_DISABLE_IE4_UTF8_FLAG
CRYPT_ENCODE_DECODE_NONE                        equ     0

X509_CERT                                       equ     1
X509_CERT_TO_BE_SIGNED                          equ     2
X509_CERT_CRL_TO_BE_SIGNED                      equ     3
X509_CERT_REQUEST_TO_BE_SIGNED                  equ     4
X509_EXTENSIONS                                 equ     5
X509_NAME_VALUE                                 equ     6
X509_NAME                                       equ     7
X509_PUBLIC_KEY_INFO                            equ     8
X509_AUTHORITY_KEY_ID                           equ     9
X509_KEY_ATTRIBUTES                             equ     10
X509_KEY_USAGE_RESTRICTION                      equ     11
X509_ALTERNATE_NAME                             equ     12
X509_BASIC_CONSTRAINTS                          equ     13
X509_KEY_USAGE                                  equ     14
X509_BASIC_CONSTRAINTS2                         equ     15
X509_CERT_POLICIES                              equ     16
PKCS_UTC_TIME                                   equ     17
PKCS_TIME_REQUEST                               equ     18
RSA_CSP_PUBLICKEYBLOB                           equ     19
X509_UNICODE_NAME                               equ     20
X509_KEYGEN_REQUEST_TO_BE_SIGNED                equ     21
PKCS_ATTRIBUTE                                  equ     22
PKCS_CONTENT_INFO_SEQUENCE_OF_ANY               equ     23
X509_UNICODE_NAME_VALUE                         equ     24
X509_ANY_STRING                                 equ     X509_NAME_VALUE
X509_UNICODE_ANY_STRING                         equ     X509_UNICODE_NAME_VALUE
X509_OCTET_STRING                               equ     25
X509_BITS                                       equ     26
X509_INTEGER                                    equ     27
X509_MULTI_BYTE_INTEGER                         equ     28
X509_ENUMERATED                                 equ     29
X509_CHOICE_OF_TIME                             equ     30
X509_AUTHORITY_KEY_ID2                          equ     31
X509_AUTHORITY_INFO_ACCESS                      equ     32
X509_CRL_REASON_CODE                            equ     X509_ENUMERATED
PKCS_CONTENT_INFO                               equ     33
X509_SEQUENCE_OF_ANY                            equ     34
X509_CRL_DIST_POINTS                            equ     35
X509_ENHANCED_KEY_USAGE                         equ     36
PKCS_CTL                                        equ     37
X509_MULTI_BYTE_UINT                            equ     38
X509_DSS_PUBLICKEY                              equ     X509_MULTI_BYTE_UINT
X509_DSS_PARAMETERS                             equ     39
X509_DSS_SIGNATURE                              equ     40
PKCS_RC2_CBC_PARAMETERS                         equ     41
PKCS_SMIME_CAPABILITIES                         equ     42
PKCS_RSA_PRIVATE_KEY                            equ     43
PKCS_PRIVATE_KEY_INFO                           equ     44
PKCS_ENCRYPTED_PRIVATE_KEY_INFO                 equ     45
X509_PKIX_POLICY_QUALIFIER_USERNOTICE           equ     46
X509_DH_PUBLICKEY                               equ     X509_MULTI_BYTE_UINT
X509_DH_PARAMETERS                              equ     47
PKCS_ATTRIBUTES                                 equ     48
PKCS_SORTED_CTL                                 equ     49
X942_DH_PARAMETERS                              equ     50
X509_BITS_WITHOUT_TRAILING_ZEROES               equ     51
X942_OTHER_INFO                                 equ     52
PKCS7_SIGNER_INFO                               equ     500
CMS_SIGNER_INFO                                 equ     501

szOID_AUTHORITY_KEY_IDENTIFIER                  db      "2.5.29.1", 0
szOID_KEY_ATTRIBUTES                            db      "2.5.29.2", 0
szOID_CERT_POLICIES_95                          db      "2.5.29.3", 0
szOID_KEY_USAGE_RESTRICTION                     db      "2.5.29.4", 0
szOID_SUBJECT_ALT_NAME                          db      "2.5.29.7", 0
szOID_ISSUER_ALT_NAME                           db      "2.5.29.8", 0
szOID_BASIC_CONSTRAINTS                         db      "2.5.29.10", 0
szOID_KEY_USAGE                                 db      "2.5.29.15", 0
szOID_PRIVATEKEY_USAGE_PERIOD                   db      "2.5.29.16", 0
szOID_BASIC_CONSTRAINTS2                        db      "2.5.29.19", 0
szOID_CERT_POLICIES                             db      "2.5.29.32", 0
szOID_AUTHORITY_KEY_IDENTIFIER2                 db      "2.5.29.35", 0
szOID_SUBJECT_KEY_IDENTIFIER                    db      "2.5.29.14", 0
szOID_SUBJECT_ALT_NAME2                         db      "2.5.29.17", 0
szOID_ISSUER_ALT_NAME2                          db      "2.5.29.18", 0
szOID_CRL_REASON_CODE                           db      "2.5.29.21", 0
szOID_CRL_DIST_POINTS                           db      "2.5.29.31", 0
szOID_ENHANCED_KEY_USAGE                        db      "2.5.29.37", 0
szOID_RENEWAL_CERTIFICATE                       db      "1.3.6.1.4.1.311.13.1", 0
szOID_ENROLLMENT_NAME_VALUE_PAIR                db      "1.3.6.1.4.1.311.13.2.1", 0
szOID_ENROLLMENT_CSP_PROVIDER                   db      "1.3.6.1.4.1.311.13.2.2", 0
szOID_OS_VERSION                                db      "1.3.6.1.4.1.311.13.2.3", 0
szOID_ENROLLMENT_AGENT                          db      "1.3.6.1.4.1.311.20.2.1", 0
szOID_PKIX                                      db      "1.3.6.1.5.5.7", 0
szOID_PKIX_PE                                   db      "1.3.6.1.5.5.7.1", 0
szOID_AUTHORITY_INFO_ACCESS                     db      "1.3.6.1.5.5.7.1.1", 0
szOID_CERT_EXTENSIONS                           db      "1.3.6.1.4.1.311.2.1.14", 0
szOID_NEXT_UPDATE_LOCATION                      db      "1.3.6.1.4.1.311.10.2", 0
szOID_CTL                                       db      "1.3.6.1.4.1.311.10.1", 0
szOID_SORTED_CTL                                db      "1.3.6.1.4.1.311.10.1.1", 0

szOID_SERIALIZED                                db      "1.3.6.1.4.1.311.10.3.3.1", 0

szOID_NT_PRINCIPAL_NAME                         db      "1.3.6.1.4.1.311.20.2.3", 0

szOID_PRODUCT_UPDATE                            db      "1.3.6.1.4.1.311.31.1", 0

szOID_AUTO_ENROLL_CTL_USAGE                     db      "1.3.6.1.4.1.311.20.1", 0
szOID_ENROLL_CERTTYPE_EXTENSION                 db      "1.3.6.1.4.1.311.20.2", 0
szOID_CERT_MANIFOLD                             db      "1.3.6.1.4.1.311.20.3", 0

szOID_CERTSRV_CA_VERSION                        db      "1.3.6.1.4.1.311.21.1", 0

szOID_NTDS_REPLICATION                          db      "1.3.6.1.4.1.311.25.1", 0
szOID_POLICY_MAPPINGS                           db      "2.5.29.5", 0
szOID_SUBJECT_DIR_ATTRS                         db      "2.5.29.9", 0
szOID_PKIX_KP                                   db      "1.3.6.1.5.5.7.3", 0
szOID_PKIX_KP_SERVER_AUTH                       db      "1.3.6.1.5.5.7.3.1", 0
szOID_PKIX_KP_CLIENT_AUTH                       db      "1.3.6.1.5.5.7.3.2", 0
szOID_PKIX_KP_CODE_SIGNING                      db      "1.3.6.1.5.5.7.3.3", 0
szOID_PKIX_KP_EMAIL_PROTECTION                  db      "1.3.6.1.5.5.7.3.4", 0
szOID_PKIX_KP_IPSEC_END_SYSTEM                  db      "1.3.6.1.5.5.7.3.5", 0
szOID_PKIX_KP_IPSEC_TUNNEL                      db      "1.3.6.1.5.5.7.3.6", 0
szOID_PKIX_KP_IPSEC_USER                        db      "1.3.6.1.5.5.7.3.7", 0
szOID_PKIX_KP_TIMESTAMP_SIGNING                 db      "1.3.6.1.5.5.7.3.8", 0
szOID_KP_CTL_USAGE_SIGNING                      db      "1.3.6.1.4.1.311.10.3.1", 0
szOID_KP_TIME_STAMP_SIGNING                     db      "1.3.6.1.4.1.311.10.3.2", 0

szOID_SERVER_GATED_CRYPTO                       db      "1.3.6.1.4.1.311.10.3.3", 0
szOID_SGC_NETSCAPE                              db      "2.16.840.1.113730.4.1", 0

szOID_KP_EFS                                    db      "1.3.6.1.4.1.311.10.3.4", 0
szOID_WHQL_CRYPTO                               db      "1.3.6.1.4.1.311.10.3.5", 0
szOID_NT5_CRYPTO                                db      "1.3.6.1.4.1.311.10.3.6", 0
szOID_OEM_WHQL_CRYPTO                           db      "1.3.6.1.4.1.311.10.3.7", 0
szOID_EMBEDDED_NT_CRYPTO                        db      "1.3.6.1.4.1.311.10.3.8", 0

szOID_DRM                                       db      "1.3.6.1.4.1.311.10.5.1", 0

szOID_LICENSES                                  db      "1.3.6.1.4.1.311.10.6.1", 0

szOID_LICENSE_SERVER                            db      "1.3.6.1.4.1.311.10.6.2", 0

szOID_KP_SMARTCARD_LOGON                        db      "1.3.6.1.4.1.311.20.2.2", 0

szOID_YESNO_TRUST_ATTR                          db      "1.3.6.1.4.1.311.10.4.1", 0
szOID_PKIX_POLICY_QUALIFIER_CPS                 db      "1.3.6.1.5.5.7.2.1", 0
szOID_PKIX_POLICY_QUALIFIER_USERNOTICE          db      "1.3.6.1.5.5.7.2.2", 0
szOID_CERT_POLICIES_95_QUALIFIER1               db      "2.16.840.1.113733.1.7.1.1", 0

CERT_UNICODE_RDN_ERR_INDEX_MASK                 equ     03FFH
CERT_UNICODE_RDN_ERR_INDEX_SHIFT                equ     22
CERT_UNICODE_ATTR_ERR_INDEX_MASK                equ     0003FH
CERT_UNICODE_ATTR_ERR_INDEX_SHIFT               equ     16
CERT_UNICODE_VALUE_ERR_INDEX_MASK               equ     00000FFFFH
CERT_UNICODE_VALUE_ERR_INDEX_SHIFT              equ     0

CERT_DIGITAL_SIGNATURE_KEY_USAGE                equ     080H
CERT_NON_REPUDIATION_KEY_USAGE                  equ     040H
CERT_KEY_ENCIPHERMENT_KEY_USAGE                 equ     020H
CERT_DATA_ENCIPHERMENT_KEY_USAGE                equ     010H
CERT_KEY_AGREEMENT_KEY_USAGE                    equ     008H
CERT_KEY_CERT_SIGN_KEY_USAGE                    equ     004H
CERT_OFFLINE_CRL_SIGN_KEY_USAGE                 equ     002H
CERT_CRL_SIGN_KEY_USAGE                         equ     002H
CERT_ENCIPHER_ONLY_KEY_USAGE                    equ     001H
CERT_DECIPHER_ONLY_KEY_USAGE                    equ     080H

CERT_ALT_NAME_OTHER_NAME                        equ     1
CERT_ALT_NAME_RFC822_NAME                       equ     2
CERT_ALT_NAME_DNS_NAME                          equ     3
CERT_ALT_NAME_X400_ADDRESS                      equ     4
CERT_ALT_NAME_DIRECTORY_NAME                    equ     5
CERT_ALT_NAME_EDI_PARTY_NAME                    equ     6
CERT_ALT_NAME_URL                               equ     7
CERT_ALT_NAME_IP_ADDRESS                        equ     8
CERT_ALT_NAME_REGISTERED_ID                     equ     9

CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK              equ     0FFH
CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT             equ     16
CERT_ALT_NAME_VALUE_ERR_INDEX_MASK              equ     00000FFFFH
CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT             equ     0

CERT_CA_SUBJECT_FLAG                            equ     080H
CERT_END_ENTITY_SUBJECT_FLAG                    equ     040H

szOID_PKIX_ACC_DESCR                            db      "1.3.6.1.5.5.7.48", 0
szOID_PKIX_OCSP                                 db      "1.3.6.1.5.5.7.48.1", 0
szOID_PKIX_CA_ISSUERS                           db      "1.3.6.1.5.5.7.48.2", 0

CRL_REASON_UNSPECIFIED                          equ     0
CRL_REASON_KEY_COMPROMISE                       equ     1
CRL_REASON_CA_COMPROMISE                        equ     2
CRL_REASON_AFFILIATION_CHANGED                  equ     3
CRL_REASON_SUPERSEDED                           equ     4
CRL_REASON_CESSATION_OF_OPERATION               equ     5
CRL_REASON_CERTIFICATE_HOLD                     equ     6
CRL_REASON_REMOVE_FROM_CRL                      equ     8

CRL_DIST_POINT_NO_NAME                          equ     0
CRL_DIST_POINT_FULL_NAME                        equ     1
CRL_DIST_POINT_ISSUER_RDN_NAME                  equ     2

CRL_REASON_UNUSED_FLAG                          equ     080H
CRL_REASON_KEY_COMPROMISE_FLAG                  equ     040H
CRL_REASON_CA_COMPROMISE_FLAG                   equ     020H
CRL_REASON_AFFILIATION_CHANGED_FLAG             equ     010H
CRL_REASON_SUPERSEDED_FLAG                      equ     008H
CRL_REASON_CESSATION_OF_OPERATION_FLAG          equ     004H
CRL_REASON_CERTIFICATE_HOLD_FLAG                equ     002H

CRL_DIST_POINT_ERR_INDEX_MASK                   equ     07FH
CRL_DIST_POINT_ERR_INDEX_SHIFT                  equ     24
CRL_DIST_POINT_ERR_CRL_ISSUER_BIT               equ     080000000H
SORTED_CTL_EXT_FLAGS_OFFSET                     equ     (0)
SORTED_CTL_EXT_COUNT_OFFSET                     equ     (4)
SORTED_CTL_EXT_MAX_COLLISION_OFFSET             equ     (8)
SORTED_CTL_EXT_HASH_BUCKET_OFFSET               equ     (12)
SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG   equ     01H

CERT_DSS_R_LEN                                  equ     20
CERT_DSS_S_LEN                                  equ     20
CERT_DSS_SIGNATURE_LEN                          equ     (CERT_DSS_R_LEN + CERT_DSS_S_LEN)
CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN          equ     48

CRYPT_X942_COUNTER_BYTE_LENGTH                  equ     4
CRYPT_X942_KEY_LENGTH_BYTE_LENGTH               equ     4
CRYPT_X942_PUB_INFO_BYTE_LENGTH                 equ     64

CRYPT_RC2_40BIT_VERSION                         equ     160
CRYPT_RC2_56BIT_VERSION                         equ     52
CRYPT_RC2_64BIT_VERSION                         equ     120
CRYPT_RC2_128BIT_VERSION                        equ     58

szOID_NETSCAPE                                  db      "2.16.840.1.113730", 0
szOID_NETSCAPE_CERT_EXTENSION                   db      "2.16.840.1.113730.1", 0
szOID_NETSCAPE_CERT_TYPE                        db      "2.16.840.1.113730.1.1", 0
szOID_NETSCAPE_BASE_URL                         db      "2.16.840.1.113730.1.2", 0
szOID_NETSCAPE_REVOCATION_URL                   db      "2.16.840.1.113730.1.3", 0
szOID_NETSCAPE_CA_REVOCATION_URL                db      "2.16.840.1.113730.1.4", 0
szOID_NETSCAPE_CERT_RENEWAL_URL                 db      "2.16.840.1.113730.1.7", 0
szOID_NETSCAPE_CA_POLICY_URL                    db      "2.16.840.1.113730.1.8", 0
szOID_NETSCAPE_SSL_SERVER_NAME                  db      "2.16.840.1.113730.1.12", 0
szOID_NETSCAPE_COMMENT                          db      "2.16.840.1.113730.1.13", 0
szOID_NETSCAPE_DATA_TYPE                        db      "2.16.840.1.113730.2", 0
szOID_NETSCAPE_CERT_SEQUENCE                    db      "2.16.840.1.113730.2.5", 0

NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE              equ     080H
NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE              equ     040H
NETSCAPE_SMIME_CERT_TYPE                        equ     020H
NETSCAPE_SIGN_CERT_TYPE                         equ     010H
NETSCAPE_SSL_CA_CERT_TYPE                       equ     004H
NETSCAPE_SMIME_CA_CERT_TYPE                     equ     002H
NETSCAPE_SIGN_CA_CERT_TYPE                      equ     001H

CRYPT_OID_ENCODE_OBJECT_FUNC                    db      "CryptDllEncodeObject", 0
CRYPT_OID_DECODE_OBJECT_FUNC                    db      "CryptDllDecodeObject", 0
CRYPT_OID_ENCODE_OBJECT_EX_FUNC                 db      "CryptDllEncodeObjectEx", 0
CRYPT_OID_DECODE_OBJECT_EX_FUNC                 db      "CryptDllDecodeObjectEx", 0
CRYPT_OID_CREATE_COM_OBJECT_FUNC                db      "CryptDllCreateCOMObject", 0
CRYPT_OID_VERIFY_REVOCATION_FUNC                db      "CertDllVerifyRevocation", 0
CRYPT_OID_VERIFY_CTL_USAGE_FUNC                 db      "CertDllVerifyCTLUsage", 0
CRYPT_OID_FORMAT_OBJECT_FUNC                    db      "CryptDllFormatObject", 0
CRYPT_OID_FIND_OID_INFO_FUNC                    db      "CryptDllFindOIDInfo", 0
CRYPT_OID_FIND_LOCALIZED_NAME_FUNC              db      "CryptDllFindLocalizedName", 0
CRYPT_OID_REGPATH                               db      "Software\Microsoft\Cryptography\OID", 0
CRYPT_OID_REG_ENCODING_TYPE_PREFIX              db      "EncodingType ", 0
CRYPT_OID_REG_DLL_VALUE_NAME                    du      "Dll", 0
CRYPT_OID_REG_FUNC_NAME_VALUE_NAME              du      "FuncName", 0
CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A            db      "FuncName", 0
CRYPT_OID_REG_FLAGS_VALUE_NAME                  du      "CryptFlags", 0
CRYPT_DEFAULT_OID                               du      "DEFAULT", 0

CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG              equ     1

CRYPT_GET_INSTALLED_OID_FUNC_FLAG               equ     1

CRYPT_REGISTER_FIRST_INDEX                      equ     0
CRYPT_REGISTER_LAST_INDEX                       equ     0FFFFFFFFH

CRYPT_MATCH_ANY_ENCODING_TYPE                   equ     0FFFFFFFFH

CRYPT_HASH_ALG_OID_GROUP_ID                     equ     1
CRYPT_ENCRYPT_ALG_OID_GROUP_ID                  equ     2
CRYPT_PUBKEY_ALG_OID_GROUP_ID                   equ     3
CRYPT_SIGN_ALG_OID_GROUP_ID                     equ     4
CRYPT_RDN_ATTR_OID_GROUP_ID                     equ     5
CRYPT_EXT_OR_ATTR_OID_GROUP_ID                  equ     6
CRYPT_ENHKEY_USAGE_OID_GROUP_ID                 equ     7
CRYPT_POLICY_OID_GROUP_ID                       equ     8
CRYPT_LAST_OID_GROUP_ID                         equ     8
CRYPT_FIRST_ALG_OID_GROUP_ID                    equ     CRYPT_HASH_ALG_OID_GROUP_ID
CRYPT_LAST_ALG_OID_GROUP_ID                     equ     CRYPT_SIGN_ALG_OID_GROUP_ID
CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG         equ     01H
CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG        equ     02H
CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG           equ     04H

CRYPT_OID_INFO_OID_KEY                          equ     1
CRYPT_OID_INFO_NAME_KEY                         equ     2
CRYPT_OID_INFO_ALGID_KEY                        equ     3
CRYPT_OID_INFO_SIGN_KEY                         equ     4

CRYPT_INSTALL_OID_INFO_BEFORE_FLAG              equ     1

CRYPT_LOCALIZED_NAME_ENCODING_TYPE              equ     0
CRYPT_LOCALIZED_NAME_OID                        db      "LocalizedNames", 0

szOID_PKCS_7_DATA                               db      "1.2.840.113549.1.7.1", 0
szOID_PKCS_7_SIGNED                             db      "1.2.840.113549.1.7.2", 0
szOID_PKCS_7_ENVELOPED                          db      "1.2.840.113549.1.7.3", 0
szOID_PKCS_7_SIGNEDANDENVELOPED                 db      "1.2.840.113549.1.7.4", 0
szOID_PKCS_7_DIGESTED                           db      "1.2.840.113549.1.7.5", 0
szOID_PKCS_7_ENCRYPTED                          db      "1.2.840.113549.1.7.6", 0
szOID_PKCS_9_CONTENT_TYPE                       db      "1.2.840.113549.1.9.3", 0
szOID_PKCS_9_MESSAGE_DIGEST                     db      "1.2.840.113549.1.9.4", 0

CMSG_DATA                                       equ     1
CMSG_SIGNED                                     equ     2
CMSG_ENVELOPED                                  equ     3
CMSG_SIGNED_AND_ENVELOPED                       equ     4
CMSG_HASHED                                     equ     5
CMSG_ENCRYPTED                                  equ     6
CMSG_ALL_FLAGS                                  equ     (-1)
CMSG_DATA_FLAG                                  equ     (1 shl CMSG_DATA)
CMSG_SIGNED_FLAG                                equ     (1 shl CMSG_SIGNED)
CMSG_ENVELOPED_FLAG                             equ     (1 shl CMSG_ENVELOPED)
CMSG_SIGNED_AND_ENVELOPED_FLAG                  equ     (1 shl CMSG_SIGNED_AND_ENVELOPED)
CMSG_HASHED_FLAG                                equ     (1 shl CMSG_HASHED)
CMSG_ENCRYPTED_FLAG                             equ     (1 shl CMSG_ENCRYPTED)

CERT_ID_ISSUER_SERIAL_NUMBER                    equ     1
CERT_ID_KEY_IDENTIFIER                          equ     2
CERT_ID_SHA1_HASH                               equ     3

CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE             equ     1
CMSG_KEY_AGREE_STATIC_KEY_CHOICE                equ     2

CMSG_MAIL_LIST_HANDLE_KEY_CHOICE                equ     1

CMSG_KEY_TRANS_RECIPIENT                        equ     1
CMSG_KEY_AGREE_RECIPIENT                        equ     2
CMSG_MAIL_LIST_RECIPIENT                        equ     3

CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG                equ     080000000H

CMSG_RC4_NO_SALT_FLAG                           equ     040000000H

CMSG_INDEFINITE_LENGTH                          equ     0FFFFFFFFH

CMSG_BARE_CONTENT_FLAG                          equ     000000001H
CMSG_LENGTH_ONLY_FLAG                           equ     000000002H
CMSG_DETACHED_FLAG                              equ     000000004H
CMSG_AUTHENTICATED_ATTRIBUTES_FLAG              equ     000000008H
CMSG_CONTENTS_OCTETS_FLAG                       equ     000000010H
CMSG_MAX_LENGTH_FLAG                            equ     000000020H
CMSG_CMS_ENCAPSULATED_CONTENT_FLAG              equ     000000040H
CMSG_CRYPT_RELEASE_CONTEXT_FLAG                 equ     000008000H

CMSG_TYPE_PARAM                                 equ     1
CMSG_CONTENT_PARAM                              equ     2
CMSG_BARE_CONTENT_PARAM                         equ     3
CMSG_INNER_CONTENT_TYPE_PARAM                   equ     4
CMSG_SIGNER_COUNT_PARAM                         equ     5
CMSG_SIGNER_INFO_PARAM                          equ     6
CMSG_SIGNER_CERT_INFO_PARAM                     equ     7
CMSG_SIGNER_HASH_ALGORITHM_PARAM                equ     8
CMSG_SIGNER_AUTH_ATTR_PARAM                     equ     9
CMSG_SIGNER_UNAUTH_ATTR_PARAM                   equ     10
CMSG_CERT_COUNT_PARAM                           equ     11
CMSG_CERT_PARAM                                 equ     12
CMSG_CRL_COUNT_PARAM                            equ     13
CMSG_CRL_PARAM                                  equ     14
CMSG_ENVELOPE_ALGORITHM_PARAM                   equ     15
CMSG_RECIPIENT_COUNT_PARAM                      equ     17
CMSG_RECIPIENT_INDEX_PARAM                      equ     18
CMSG_RECIPIENT_INFO_PARAM                       equ     19
CMSG_HASH_ALGORITHM_PARAM                       equ     20
CMSG_HASH_DATA_PARAM                            equ     21
CMSG_COMPUTED_HASH_PARAM                        equ     22
CMSG_ENCRYPT_PARAM                              equ     26
CMSG_ENCRYPTED_DIGEST                           equ     27
CMSG_ENCODED_SIGNER                             equ     28
CMSG_ENCODED_MESSAGE                            equ     29
CMSG_VERSION_PARAM                              equ     30
CMSG_ATTR_CERT_COUNT_PARAM                      equ     31
CMSG_ATTR_CERT_PARAM                            equ     32
CMSG_CMS_RECIPIENT_COUNT_PARAM                  equ     33
CMSG_CMS_RECIPIENT_INDEX_PARAM                  equ     34
CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM    equ     35
CMSG_CMS_RECIPIENT_INFO_PARAM                   equ     36
CMSG_UNPROTECTED_ATTR_PARAM                     equ     37
CMSG_SIGNER_CERT_ID_PARAM                       equ     38
CMSG_CMS_SIGNER_INFO_PARAM                      equ     39

CMSG_SIGNED_DATA_V1                             equ     1
CMSG_SIGNED_DATA_V3                             equ     3
CMSG_SIGNED_DATA_PKCS_1_5_VERSION               equ     CMSG_SIGNED_DATA_V1
CMSG_SIGNED_DATA_CMS_VERSION                    equ     CMSG_SIGNED_DATA_V3
CMSG_SIGNER_INFO_V1                             equ     1
CMSG_SIGNER_INFO_V3                             equ     3
CMSG_SIGNER_INFO_PKCS_1_5_VERSION               equ     CMSG_SIGNER_INFO_V1
CMSG_SIGNER_INFO_CMS_VERSION                    equ     CMSG_SIGNER_INFO_V3
CMSG_HASHED_DATA_V0                             equ     0
CMSG_HASHED_DATA_V2                             equ     2
CMSG_HASHED_DATA_PKCS_1_5_VERSION               equ     CMSG_HASHED_DATA_V0
CMSG_HASHED_DATA_CMS_VERSION                    equ     CMSG_HASHED_DATA_V2
CMSG_ENVELOPED_DATA_V0                          equ     0
CMSG_ENVELOPED_DATA_V2                          equ     2
CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION            equ     CMSG_ENVELOPED_DATA_V0
CMSG_ENVELOPED_DATA_CMS_VERSION                 equ     CMSG_ENVELOPED_DATA_V2

CMSG_KEY_AGREE_ORIGINATOR_CERT                  equ     1
CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY            equ     2

CMSG_ENVELOPED_RECIPIENT_V0                     equ     0
CMSG_ENVELOPED_RECIPIENT_V2                     equ     2
CMSG_ENVELOPED_RECIPIENT_V3                     equ     3
CMSG_ENVELOPED_RECIPIENT_V4                     equ     4
CMSG_KEY_TRANS_PKCS_1_5_VERSION                 equ     CMSG_ENVELOPED_RECIPIENT_V0
CMSG_KEY_TRANS_CMS_VERSION                      equ     CMSG_ENVELOPED_RECIPIENT_V2
CMSG_KEY_AGREE_VERSION                          equ     CMSG_ENVELOPED_RECIPIENT_V3
CMSG_MAIL_LIST_VERSION                          equ     CMSG_ENVELOPED_RECIPIENT_V4

CMSG_CTRL_VERIFY_SIGNATURE                      equ     1
CMSG_CTRL_DECRYPT                               equ     2
CMSG_CTRL_VERIFY_HASH                           equ     5
CMSG_CTRL_ADD_SIGNER                            equ     6
CMSG_CTRL_DEL_SIGNER                            equ     7
CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR                equ     8
CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR                equ     9
CMSG_CTRL_ADD_CERT                              equ     10
CMSG_CTRL_DEL_CERT                              equ     11
CMSG_CTRL_ADD_CRL                               equ     12
CMSG_CTRL_DEL_CRL                               equ     13
CMSG_CTRL_ADD_ATTR_CERT                         equ     14
CMSG_CTRL_DEL_ATTR_CERT                         equ     15
CMSG_CTRL_KEY_TRANS_DECRYPT                     equ     16
CMSG_CTRL_KEY_AGREE_DECRYPT                     equ     17
CMSG_CTRL_MAIL_LIST_DECRYPT                     equ     18
CMSG_CTRL_VERIFY_SIGNATURE_EX                   equ     19
CMSG_CTRL_ADD_CMS_SIGNER_INFO                   equ     20

CMSG_VERIFY_SIGNER_PUBKEY                       equ     1
CMSG_VERIFY_SIGNER_CERT                         equ     2
CMSG_VERIFY_SIGNER_CHAIN                        equ     3

CMSG_OID_GEN_ENCRYPT_KEY_FUNC                   db      "CryptMsgDllGenEncryptKey", 0
CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC                db      "CryptMsgDllExportEncryptKey", 0
CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC                db      "CryptMsgDllImportEncryptKey", 0
CMSG_DEFAULT_INSTALLABLE_FUNC_OID               equ     1

CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG       equ     000000001H
CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG             equ     000000001H
CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG       equ     000008000H
CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC           db      "CryptMsgDllGenContentEncryptKey", 0

CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG           equ     000000001H
CMSG_OID_EXPORT_KEY_TRANS_FUNC                  db      "CryptMsgDllExportKeyTrans", 0

CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG           equ     000000001H
CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG       equ     000000002H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG     equ     000000004H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG    equ     000000008H
CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG    equ     000000010H
CMSG_OID_EXPORT_KEY_AGREE_FUNC                  db      "CryptMsgDllExportKeyAgree", 0

CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG           equ     000000001H
CMSG_OID_EXPORT_MAIL_LIST_FUNC                  db      "CryptMsgDllExportMailList", 0
CMSG_OID_IMPORT_KEY_TRANS_FUNC                  db      "CryptMsgDllImportKeyTrans", 0
CMSG_OID_IMPORT_KEY_AGREE_FUNC                  db      "CryptMsgDllImportKeyAgree", 0
CMSG_OID_IMPORT_MAIL_LIST_FUNC                  db      "CryptMsgDllImportMailList", 0

CERT_KEY_PROV_HANDLE_PROP_ID                    equ     1
CERT_KEY_PROV_INFO_PROP_ID                      equ     2
CERT_SHA1_HASH_PROP_ID                          equ     3
CERT_MD5_HASH_PROP_ID                           equ     4
CERT_HASH_PROP_ID                               equ     CERT_SHA1_HASH_PROP_ID
CERT_KEY_CONTEXT_PROP_ID                        equ     5
CERT_KEY_SPEC_PROP_ID                           equ     6
CERT_IE30_RESERVED_PROP_ID                      equ     7
CERT_PUBKEY_HASH_RESERVED_PROP_ID               equ     8
CERT_ENHKEY_USAGE_PROP_ID                       equ     9
CERT_CTL_USAGE_PROP_ID                          equ     CERT_ENHKEY_USAGE_PROP_ID
CERT_NEXT_UPDATE_LOCATION_PROP_ID               equ     10
CERT_FRIENDLY_NAME_PROP_ID                      equ     11
CERT_PVK_FILE_PROP_ID                           equ     12
CERT_DESCRIPTION_PROP_ID                        equ     13
CERT_ACCESS_STATE_PROP_ID                       equ     14
CERT_SIGNATURE_HASH_PROP_ID                     equ     15
CERT_SMART_CARD_DATA_PROP_ID                    equ     16
CERT_EFS_PROP_ID                                equ     17
CERT_FORTEZZA_DATA_PROP_ID                      equ     18
CERT_ARCHIVED_PROP_ID                           equ     19
CERT_KEY_IDENTIFIER_PROP_ID                     equ     20
CERT_AUTO_ENROLL_PROP_ID                        equ     21
CERT_PUBKEY_ALG_PARA_PROP_ID                    equ     22
CERT_FIRST_RESERVED_PROP_ID                     equ     23
CERT_LAST_RESERVED_PROP_ID                      equ     000007FFFH
CERT_FIRST_USER_PROP_ID                         equ     000008000H
CERT_LAST_USER_PROP_ID                          equ     00000FFFFH
CERT_ACCESS_STATE_WRITE_PERSIST_FLAG            equ     01H
CERT_ACCESS_STATE_SYSTEM_STORE_FLAG             equ     02H

CERT_SET_KEY_PROV_HANDLE_PROP_ID                equ     000000001H
CERT_SET_KEY_CONTEXT_PROP_ID                    equ     000000001H

CERT_STORE_PROV_MSG                             equ     (1)
CERT_STORE_PROV_MEMORY                          equ     (2)
CERT_STORE_PROV_FILE                            equ     (3)
CERT_STORE_PROV_REG                             equ     (4)
CERT_STORE_PROV_PKCS7                           equ     (5)
CERT_STORE_PROV_SERIALIZED                      equ     (6)
CERT_STORE_PROV_FILENAME_A                      equ     (7)
CERT_STORE_PROV_FILENAME_W                      equ     (8)
CERT_STORE_PROV_FILENAME                        equ     CERT_STORE_PROV_FILENAME_W
CERT_STORE_PROV_SYSTEM_A                        equ     (9)
CERT_STORE_PROV_SYSTEM_W                        equ     (10)
CERT_STORE_PROV_SYSTEM                          equ     CERT_STORE_PROV_SYSTEM_W
CERT_STORE_PROV_COLLECTION                      equ     (11)
CERT_STORE_PROV_SYSTEM_REGISTRY_A               equ     (12)
CERT_STORE_PROV_SYSTEM_REGISTRY_W               equ     (13)
CERT_STORE_PROV_SYSTEM_REGISTRY                 equ     CERT_STORE_PROV_SYSTEM_REGISTRY_W
CERT_STORE_PROV_PHYSICAL_W                      equ     (14)
CERT_STORE_PROV_PHYSICAL                        equ     CERT_STORE_PROV_PHYSICAL_W
CERT_STORE_PROV_SMART_CARD_W                    equ     (15)
CERT_STORE_PROV_SMART_CARD                      equ     CERT_STORE_PROV_SMART_CARD_W
CERT_STORE_PROV_LDAP_W                          equ     (16)
CERT_STORE_PROV_LDAP                            equ     CERT_STORE_PROV_LDAP_W

sz_CERT_STORE_PROV_MEMORY                       db      "Memory", 0
sz_CERT_STORE_PROV_FILENAME_W                   db      "File", 0
sz_CERT_STORE_PROV_FILENAME                     equ     sz_CERT_STORE_PROV_FILENAME_W
sz_CERT_STORE_PROV_SYSTEM_W                     db      "System", 0
sz_CERT_STORE_PROV_SYSTEM                       equ     sz_CERT_STORE_PROV_SYSTEM_W
sz_CERT_STORE_PROV_PKCS7                        db      "PKCS7", 0
sz_CERT_STORE_PROV_SERIALIZED                   db      "Serialized", 0
sz_CERT_STORE_PROV_COLLECTION                   db      "Collection", 0
sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W            db      "SystemRegistry", 0
sz_CERT_STORE_PROV_SYSTEM_REGISTRY              equ     sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
sz_CERT_STORE_PROV_PHYSICAL_W                   db      "Physical", 0
sz_CERT_STORE_PROV_PHYSICAL                     equ     sz_CERT_STORE_PROV_PHYSICAL_W
sz_CERT_STORE_PROV_SMART_CARD_W                 db      "SmartCard", 0
sz_CERT_STORE_PROV_SMART_CARD                   equ     sz_CERT_STORE_PROV_SMART_CARD_W
sz_CERT_STORE_PROV_LDAP_W                       db      "Ldap", 0
sz_CERT_STORE_PROV_LDAP                         equ     sz_CERT_STORE_PROV_LDAP_W

CERT_STORE_SIGNATURE_FLAG                       equ     000000001H
CERT_STORE_TIME_VALIDITY_FLAG                   equ     000000002H
CERT_STORE_REVOCATION_FLAG                      equ     000000004H
CERT_STORE_NO_CRL_FLAG                          equ     000010000H
CERT_STORE_NO_ISSUER_FLAG                       equ     000020000H
CERT_STORE_NO_CRYPT_RELEASE_FLAG                equ     000000001H
CERT_STORE_SET_LOCALIZED_NAME_FLAG              equ     000000002H
CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG     equ     000000004H
CERT_STORE_DELETE_FLAG                          equ     000000010H
CERT_STORE_MANIFOLD_FLAG                        equ     000000100H
CERT_STORE_ENUM_ARCHIVED_FLAG                   equ     000000200H
CERT_STORE_UPDATE_KEYID_FLAG                    equ     000000400H
CERT_STORE_READONLY_FLAG                        equ     000008000H
CERT_STORE_OPEN_EXISTING_FLAG                   equ     000004000H
CERT_STORE_CREATE_NEW_FLAG                      equ     000002000H
CERT_STORE_MAXIMUM_ALLOWED_FLAG                 equ     000001000H
CERT_SYSTEM_STORE_MASK                          equ     0FFFF0000H
CERT_SYSTEM_STORE_RELOCATE_FLAG                 equ     080000000H

CERT_SYSTEM_STORE_UNPROTECTED_FLAG              equ     040000000H
CERT_SYSTEM_STORE_LOCATION_MASK                 equ     000FF0000H
CERT_SYSTEM_STORE_LOCATION_SHIFT                equ     16
CERT_SYSTEM_STORE_CURRENT_USER_ID               equ     1
CERT_SYSTEM_STORE_LOCAL_MACHINE_ID              equ     2
CERT_SYSTEM_STORE_CURRENT_SERVICE_ID            equ     4
CERT_SYSTEM_STORE_SERVICES_ID                   equ     5
CERT_SYSTEM_STORE_USERS_ID                      equ     6
CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID  equ     7
CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID equ     8
CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID   equ     9
CERT_SYSTEM_STORE_CURRENT_USER                  equ     (CERT_SYSTEM_STORE_CURRENT_USER_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE                 equ     (CERT_SYSTEM_STORE_LOCAL_MACHINE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_CURRENT_SERVICE               equ     (CERT_SYSTEM_STORE_CURRENT_SERVICE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_SERVICES                      equ     (CERT_SYSTEM_STORE_SERVICES_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_USERS                         equ     (CERT_SYSTEM_STORE_USERS_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY     equ     (CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY    equ     (CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE      equ     (CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID shl CERT_SYSTEM_STORE_LOCATION_SHIFT)
CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH          du      "Software\Policies\Microsoft\SystemCertificates", 0
CERT_EFSBLOB_REGPATH                            du      "Software\Policies\Microsoft\SystemCertificates\EFS", 0
CERT_EFSBLOB_VALUE_NAME                         du      "EFSBlob", 0
CERT_PROT_ROOT_FLAGS_REGPATH                    du      "Software\Policies\Microsoft\SystemCertificates\Root\ProtectedRoots", 0
CERT_PROT_ROOT_FLAGS_VALUE_NAME                 du      "Flags", 0
CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG        equ     01H
CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG         equ     02H
CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG            equ     04H
CERT_PROT_ROOT_ONLY_LM_GPT_FLAG                 equ     08H
CERT_REGISTRY_STORE_REMOTE_FLAG                 equ     010000H
CERT_REGISTRY_STORE_SERIALIZED_FLAG             equ     020000H
CERT_REGISTRY_STORE_CLIENT_GPT_FLAG             equ     080000000H
CERT_REGISTRY_STORE_LM_GPT_FLAG                 equ     001000000H

CERT_REGISTRY_STORE_ROAMING_FLAG                equ     040000H

CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG            equ     080000H
CERT_IE_DIRTY_FLAGS_REGPATH                     du      "Software\Microsoft\Cryptography\IEDirtyFlags", 0
CERT_FILE_STORE_COMMIT_ENABLE_FLAG              equ     010000H

CRYPT_OID_OPEN_STORE_PROV_FUNC                  db      "CertDllOpenStoreProv", 0

CERT_STORE_PROV_EXTERNAL_FLAG                   equ     01H
CERT_STORE_PROV_DELETED_FLAG                    equ     02H
CERT_STORE_PROV_NO_PERSIST_FLAG                 equ     04H
CERT_STORE_PROV_SYSTEM_STORE_FLAG               equ     08H
CERT_STORE_PROV_CLOSE_FUNC                      equ     0
CERT_STORE_PROV_READ_CERT_FUNC                  equ     1
CERT_STORE_PROV_WRITE_CERT_FUNC                 equ     2
CERT_STORE_PROV_DELETE_CERT_FUNC                equ     3
CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC          equ     4
CERT_STORE_PROV_READ_CRL_FUNC                   equ     5
CERT_STORE_PROV_WRITE_CRL_FUNC                  equ     6
CERT_STORE_PROV_DELETE_CRL_FUNC                 equ     7
CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC           equ     8
CERT_STORE_PROV_READ_CTL_FUNC                   equ     9
CERT_STORE_PROV_WRITE_CTL_FUNC                  equ     10
CERT_STORE_PROV_DELETE_CTL_FUNC                 equ     11
CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC           equ     12
CERT_STORE_PROV_CONTROL_FUNC                    equ     13
CERT_STORE_PROV_FIND_CERT_FUNC                  equ     14
CERT_STORE_PROV_FREE_FIND_CERT_FUNC             equ     15
CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC          equ     16
CERT_STORE_PROV_FIND_CRL_FUNC                   equ     17
CERT_STORE_PROV_FREE_FIND_CRL_FUNC              equ     18
CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC           equ     19
CERT_STORE_PROV_FIND_CTL_FUNC                   equ     20
CERT_STORE_PROV_FREE_FIND_CTL_FUNC              equ     21
CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC           equ     22

CERT_STORE_PROV_WRITE_ADD_FLAG                  equ     01H

CERT_STORE_SAVE_AS_STORE                        equ     1
CERT_STORE_SAVE_AS_PKCS7                        equ     2
CERT_STORE_SAVE_TO_FILE                         equ     1
CERT_STORE_SAVE_TO_MEMORY                       equ     2
CERT_STORE_SAVE_TO_FILENAME_A                   equ     3
CERT_STORE_SAVE_TO_FILENAME_W                   equ     4
CERT_STORE_SAVE_TO_FILENAME                     equ     CERT_STORE_SAVE_TO_FILENAME_W

CERT_CLOSE_STORE_FORCE_FLAG                     equ     000000001H
CERT_CLOSE_STORE_CHECK_FLAG                     equ     000000002H

CERT_COMPARE_MASK                               equ     0FFFFH
CERT_COMPARE_SHIFT                              equ     16
CERT_COMPARE_ANY                                equ     0
CERT_COMPARE_SHA1_HASH                          equ     1
CERT_COMPARE_NAME                               equ     2
CERT_COMPARE_ATTR                               equ     3
CERT_COMPARE_MD5_HASH                           equ     4
CERT_COMPARE_PROPERTY                           equ     5
CERT_COMPARE_PUBLIC_KEY                         equ     6
CERT_COMPARE_HASH                               equ     CERT_COMPARE_SHA1_HASH
CERT_COMPARE_NAME_STR_A                         equ     7
CERT_COMPARE_NAME_STR_W                         equ     8
CERT_COMPARE_KEY_SPEC                           equ     9
CERT_COMPARE_ENHKEY_USAGE                       equ     10
CERT_COMPARE_CTL_USAGE                          equ     CERT_COMPARE_ENHKEY_USAGE
CERT_COMPARE_SUBJECT_CERT                       equ     11
CERT_COMPARE_ISSUER_OF                          equ     12
CERT_COMPARE_EXISTING                           equ     13
CERT_COMPARE_SIGNATURE_HASH                     equ     14
CERT_COMPARE_KEY_IDENTIFIER                     equ     15
CERT_COMPARE_CERT_ID                            equ     16

CERT_FIND_ANY                                   equ     (CERT_COMPARE_ANY shl CERT_COMPARE_SHIFT)
CERT_FIND_SHA1_HASH                             equ     (CERT_COMPARE_SHA1_HASH shl CERT_COMPARE_SHIFT)
CERT_FIND_MD5_HASH                              equ     (CERT_COMPARE_MD5_HASH shl CERT_COMPARE_SHIFT)
CERT_FIND_SIGNATURE_HASH                        equ     (CERT_COMPARE_SIGNATURE_HASH shl CERT_COMPARE_SHIFT)
CERT_FIND_KEY_IDENTIFIER                        equ     (CERT_COMPARE_KEY_IDENTIFIER shl CERT_COMPARE_SHIFT)
CERT_FIND_HASH                                  equ     CERT_FIND_SHA1_HASH
CERT_FIND_PROPERTY                              equ     (CERT_COMPARE_PROPERTY shl CERT_COMPARE_SHIFT)
CERT_FIND_PUBLIC_KEY                            equ     (CERT_COMPARE_PUBLIC_KEY shl CERT_COMPARE_SHIFT)
CERT_FIND_SUBJECT_NAME                          equ     (CERT_COMPARE_NAME shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_ATTR                          equ     (CERT_COMPARE_ATTR shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
CERT_FIND_ISSUER_NAME                           equ     (CERT_COMPARE_NAME shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_ATTR                           equ     (CERT_COMPARE_ATTR shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
CERT_FIND_SUBJECT_STR_A                         equ     (CERT_COMPARE_NAME_STR_A shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_STR_W                         equ     (CERT_COMPARE_NAME_STR_W shl CERT_COMPARE_SHIFT or CERT_INFO_SUBJECT_FLAG)
CERT_FIND_SUBJECT_STR                           equ     CERT_FIND_SUBJECT_STR_W
CERT_FIND_ISSUER_STR_A                          equ     (CERT_COMPARE_NAME_STR_A shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_STR_W                          equ     (CERT_COMPARE_NAME_STR_W shl CERT_COMPARE_SHIFT or CERT_INFO_ISSUER_FLAG)
CERT_FIND_ISSUER_STR                            equ     CERT_FIND_ISSUER_STR_W
CERT_FIND_KEY_SPEC                              equ     (CERT_COMPARE_KEY_SPEC shl CERT_COMPARE_SHIFT)
CERT_FIND_ENHKEY_USAGE                          equ     (CERT_COMPARE_ENHKEY_USAGE shl CERT_COMPARE_SHIFT)
CERT_FIND_CTL_USAGE                             equ     CERT_FIND_ENHKEY_USAGE
CERT_FIND_SUBJECT_CERT                          equ     (CERT_COMPARE_SUBJECT_CERT shl CERT_COMPARE_SHIFT)
CERT_FIND_ISSUER_OF                             equ     (CERT_COMPARE_ISSUER_OF shl CERT_COMPARE_SHIFT)
CERT_FIND_EXISTING                              equ     (CERT_COMPARE_EXISTING shl CERT_COMPARE_SHIFT)
CERT_FIND_CERT_ID                               equ     (CERT_COMPARE_CERT_ID shl CERT_COMPARE_SHIFT)
CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG            equ     01H
CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG            equ     02H
CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG           equ     04H
CERT_FIND_NO_ENHKEY_USAGE_FLAG                  equ     08H
CERT_FIND_OR_ENHKEY_USAGE_FLAG                  equ     010H
CERT_FIND_VALID_ENHKEY_USAGE_FLAG               equ     020H
CERT_FIND_OPTIONAL_CTL_USAGE_FLAG               equ     CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG
CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG               equ     CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG
CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG              equ     CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG
CERT_FIND_NO_CTL_USAGE_FLAG                     equ     CERT_FIND_NO_ENHKEY_USAGE_FLAG
CERT_FIND_OR_CTL_USAGE_FLAG                     equ     CERT_FIND_OR_ENHKEY_USAGE_FLAG
CERT_FIND_VALID_CTL_USAGE_FLAG                  equ     CERT_FIND_VALID_ENHKEY_USAGE_FLAG

CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG     equ     080000000H

CRL_FIND_ANY                                    equ     0
CRL_FIND_ISSUED_BY                              equ     1
CRL_FIND_EXISTING                               equ     2
CRL_FIND_ISSUED_BY_AKI_FLAG                     equ     01H
CRL_FIND_ISSUED_BY_SIGNATURE_FLAG               equ     02H

CERT_STORE_ADD_NEW                              equ     1
CERT_STORE_ADD_USE_EXISTING                     equ     2
CERT_STORE_ADD_REPLACE_EXISTING                 equ     3
CERT_STORE_ADD_ALWAYS                           equ     4
CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES equ      5
CERT_STORE_ADD_NEWER                            equ     6
CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES         equ     7

CERT_STORE_CERTIFICATE_CONTEXT                  equ     1
CERT_STORE_CRL_CONTEXT                          equ     2
CERT_STORE_CTL_CONTEXT                          equ     3
CERT_STORE_ALL_CONTEXT_FLAG                     equ     -1
CERT_STORE_CERTIFICATE_CONTEXT_FLAG             equ     (1 shl CERT_STORE_CERTIFICATE_CONTEXT)
CERT_STORE_CRL_CONTEXT_FLAG                     equ     (1 shl CERT_STORE_CRL_CONTEXT)
CERT_STORE_CTL_CONTEXT_FLAG                     equ     (1 shl CERT_STORE_CTL_CONTEXT)

CTL_ANY_SUBJECT_TYPE                            equ     1
CTL_CERT_SUBJECT_TYPE                           equ     2

CTL_FIND_ANY                                    equ     0
CTL_FIND_SHA1_HASH                              equ     1
CTL_FIND_MD5_HASH                               equ     2
CTL_FIND_USAGE                                  equ     3
CTL_FIND_SUBJECT                                equ     4
CTL_FIND_EXISTING                               equ     5

CTL_FIND_NO_LIST_ID_CBDATA                      equ     0FFFFFFFFH
CTL_FIND_NO_SIGNER_PTR                          equ     PCERT_INFO-1
CTL_FIND_SAME_USAGE_FLAG                        equ     01H

CERT_STORE_CTRL_RESYNC                          equ     1
CERT_STORE_CTRL_NOTIFY_CHANGE                   equ     2
CERT_STORE_CTRL_COMMIT                          equ     3
CERT_STORE_CTRL_AUTO_RESYNC                     equ     4
CERT_STORE_CTRL_COMMIT_FORCE_FLAG               equ     01H
CERT_STORE_CTRL_COMMIT_CLEAR_FLAG               equ     02H
CERT_STORE_LOCALIZED_NAME_PROP_ID               equ     01000H

CERT_CREATE_CONTEXT_NOCOPY_FLAG                 equ     01H
CERT_CREATE_CONTEXT_SORTED_FLAG                 equ     02H
CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG           equ     04H
CERT_CREATE_CONTEXT_NO_ENTRY_FLAG               equ     08H

CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG             equ     01H
CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG           equ     02H
CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG    equ     04H
CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG equ        08H

CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG        equ     01H
CERT_PHYSICAL_STORE_DEFAULT_NAME                du      ".Default", 0
CERT_PHYSICAL_STORE_GROUP_POLICY_NAME           du      ".GroupPolicy", 0
CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME          du      ".LocalMachine", 0
CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME    du      ".UserCertificate", 0
CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME du  ".LocalMachineGroupPolicy", 0
CERT_PHYSICAL_STORE_ENTERPRISE_NAME             du      ".Enterprise", 0

CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC           db      "CertDllOpenSystemStoreProv", 0
CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC            db      "CertDllRegisterSystemStore", 0
CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC          db      "CertDllUnregisterSystemStore", 0
CRYPT_OID_ENUM_SYSTEM_STORE_FUNC                db      "CertDllEnumSystemStore", 0
CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC          db      "CertDllRegisterPhysicalStore", 0
CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC        db      "CertDllUnregisterPhysicalStore", 0
CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC              db      "CertDllEnumPhysicalStore", 0
CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME      du      "SystemStoreLocation", 0

CMSG_TRUSTED_SIGNER_FLAG                        equ     01H
CMSG_SIGNER_ONLY_FLAG                           equ     02H
CMSG_USE_SIGNER_INDEX_FLAG                      equ     04H

CMSG_CMS_ENCAPSULATED_CTL_FLAG                  equ     000008000H

CMSG_ENCODE_SORTED_CTL_FLAG                     equ     01H
CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG      equ     02H

CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG             equ     01H
CERT_VERIFY_TRUSTED_SIGNERS_FLAG                equ     02H
CERT_VERIFY_NO_TIME_CHECK_FLAG                  equ     04H
CERT_VERIFY_ALLOW_MORE_USAGE_FLAG               equ     08H
CERT_VERIFY_UPDATED_CTL_FLAG                    equ     01H

CERT_CONTEXT_REVOCATION_TYPE                    equ     1
CERT_VERIFY_REV_CHAIN_FLAG                      equ     000000001H
CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION         equ     000000002H

CERT_UNICODE_IS_RDN_ATTRS_FLAG                  equ     01H
CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG         equ     02H

CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB             equ     1
CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT             equ     2
CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL              equ     3
CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY            equ     1
CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT              equ     2
CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN             equ     3

CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG         equ     000000001H
CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG              equ     000000002H
CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID             equ     1
CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID       equ     2

CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC           db      "CryptDllExportPublicKeyInfoEx", 0
CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC           db      "CryptDllImportPublicKeyInfoEx", 0

CRYPT_ACQUIRE_CACHE_FLAG                        equ     01H
CRYPT_ACQUIRE_USE_PROV_INFO_FLAG                equ     02H
CRYPT_ACQUIRE_COMPARE_KEY_FLAG                  equ     04H

CRYPT_FIND_USER_KEYSET_FLAG                     equ     01H
CRYPT_FIND_MACHINE_KEYSET_FLAG                  equ     02H

CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC          db      "CryptDllImportPrivateKeyInfoEx", 0

CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC          db      "CryptDllExportPrivateKeyInfoEx", 0
CRYPT_DELETE_KEYSET                             equ     00001H

CERT_SIMPLE_NAME_STR                            equ     1
CERT_OID_NAME_STR                               equ     2
CERT_X500_NAME_STR                              equ     3
CERT_NAME_STR_SEMICOLON_FLAG                    equ     040000000H
CERT_NAME_STR_NO_PLUS_FLAG                      equ     020000000H
CERT_NAME_STR_NO_QUOTING_FLAG                   equ     010000000H
CERT_NAME_STR_CRLF_FLAG                         equ     008000000H
CERT_NAME_STR_COMMA_FLAG                        equ     004000000H
CERT_NAME_STR_REVERSE_FLAG                      equ     002000000H
CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG             equ     000010000H
CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG           equ     000020000H
CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG          equ     000040000H

CERT_NAME_EMAIL_TYPE                            equ     1
CERT_NAME_RDN_TYPE                              equ     2
CERT_NAME_ATTR_TYPE                             equ     3
CERT_NAME_SIMPLE_DISPLAY_TYPE                   equ     4
CERT_NAME_FRIENDLY_DISPLAY_TYPE                 equ     5
CERT_NAME_ISSUER_FLAG                           equ     01H
CERT_NAME_DISABLE_IE4_UTF8_FLAG                 equ     000010000H

CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG             equ     01H
CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG     equ     02H
CRYPT_MESSAGE_KEYID_SIGNER_FLAG                 equ     04H

CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG              equ     04H

CERT_QUERY_OBJECT_FILE                          equ     000000001H
CERT_QUERY_OBJECT_BLOB                          equ     000000002H
CERT_QUERY_CONTENT_CERT                         equ     1
CERT_QUERY_CONTENT_CTL                          equ     2
CERT_QUERY_CONTENT_CRL                          equ     3
CERT_QUERY_CONTENT_SERIALIZED_STORE             equ     4
CERT_QUERY_CONTENT_SERIALIZED_CERT              equ     5
CERT_QUERY_CONTENT_SERIALIZED_CTL               equ     6
CERT_QUERY_CONTENT_SERIALIZED_CRL               equ     7
CERT_QUERY_CONTENT_PKCS7_SIGNED                 equ     8
CERT_QUERY_CONTENT_PKCS7_UNSIGNED               equ     9
CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED           equ     10
CERT_QUERY_CONTENT_PKCS10                       equ     11
CERT_QUERY_CONTENT_PFX                          equ     12
CERT_QUERY_CONTENT_FLAG_CERT                    equ     (1 shl CERT_QUERY_CONTENT_CERT)
CERT_QUERY_CONTENT_FLAG_CTL                     equ     (1 shl CERT_QUERY_CONTENT_CTL)
CERT_QUERY_CONTENT_FLAG_CRL                     equ     (1 shl CERT_QUERY_CONTENT_CRL)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE        equ     (1 shl CERT_QUERY_CONTENT_SERIALIZED_STORE)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT         equ     (1 shl CERT_QUERY_CONTENT_SERIALIZED_CERT)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL          equ     (1 shl CERT_QUERY_CONTENT_SERIALIZED_CTL)
CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL          equ     (1 shl CERT_QUERY_CONTENT_SERIALIZED_CRL)
CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED            equ     (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED)
CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED          equ     (1 shl CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED      equ     (1 shl CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
CERT_QUERY_CONTENT_FLAG_PKCS10                  equ     (1 shl CERT_QUERY_CONTENT_PKCS10)
CERT_QUERY_CONTENT_FLAG_PFX                     equ     (1 shl CERT_QUERY_CONTENT_PFX)
CERT_QUERY_CONTENT_FLAG_ALL_1                   equ     (CERT_QUERY_CONTENT_FLAG_CERT or CERT_QUERY_CONTENT_FLAG_CTL or CERT_QUERY_CONTENT_FLAG_CRL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT)
CERT_QUERY_CONTENT_FLAG_ALL_2                   equ     (CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL or CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED or CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED)
CERT_QUERY_CONTENT_FLAG_ALL                     equ     (CERT_QUERY_CONTENT_FLAG_ALL_1 or CERT_QUERY_CONTENT_FLAG_ALL_2 or CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED or CERT_QUERY_CONTENT_FLAG_PKCS10 or CERT_QUERY_CONTENT_FLAG_PFX)

CERT_QUERY_FORMAT_BINARY                        equ     1
CERT_QUERY_FORMAT_BASE64_ENCODED                equ     2
CERT_QUERY_FORMAT_FLAG_BINARY                   equ     (1 shl CERT_QUERY_FORMAT_BINARY)
CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED           equ     (1 shl CERT_QUERY_FORMAT_BASE64_ENCODED)
CERT_QUERY_FORMAT_FLAG_ALL                      equ     CERT_QUERY_FORMAT_FLAG_BINARY or CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED

CREDENTIAL_OID_PASSWORD_CREDENTIALS_A           equ     1
CREDENTIAL_OID_PASSWORD_CREDENTIALS_W           equ     2

SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC         db      "SchemeDllRetrieveEncodedObject", 0

CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC          db      "ContextDllCreateObjectContext", 0
CONTEXT_OID_CERTIFICATE                         equ     1
CONTEXT_OID_CRL                                 equ     2
CONTEXT_OID_CTL                                 equ     3
CONTEXT_OID_PKCS7                               equ     4
CONTEXT_OID_CAPI2_ANY                           equ     5

CRYPT_RETRIEVE_MULTIPLE_OBJECTS                 equ     000000001H
CRYPT_CACHE_ONLY_RETRIEVAL                      equ     000000002H
CRYPT_WIRE_ONLY_RETRIEVAL                       equ     000000004H
CRYPT_DONT_CACHE_RESULT                         equ     000000008H
CRYPT_ASYNC_RETRIEVAL                           equ     000000010H
CRYPT_VERIFY_CONTEXT_SIGNATURE                  equ     000000020H
CRYPT_VERIFY_DATA_HASH                          equ     000000040H
CRYPT_KEEP_TIME_VALID                           equ     000000080H
CRYPT_DONT_VERIFY_SIGNATURE                     equ     000000100H
CRYPT_DONT_CHECK_TIME_VALIDITY                  equ     000000200H

CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION          equ     1

CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL              equ     2

CRYPT_GET_URL_FROM_PROPERTY                     equ     000000001H
CRYPT_GET_URL_FROM_EXTENSION                    equ     000000002H
CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE             equ     000000004H
CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE               equ     000000008H

URL_OID_GET_OBJECT_URL_FUNC                     db      "UrlDllGetObjectUrl", 0
URL_OID_CERTIFICATE_ISSUER                      equ     1
URL_OID_CERTIFICATE_CRL_DIST_POINT              equ     2
URL_OID_CTL_ISSUER                              equ     3
URL_OID_CTL_NEXT_UPDATE                         equ     4
URL_OID_CRL_ISSUER                              equ     5

TIME_VALID_OID_GET_OBJECT_FUNC                  db      "TimeValidDllGetObject", 0
TIME_VALID_OID_GET_CTL                          equ     1
TIME_VALID_OID_GET_CRL                          equ     2
TIME_VALID_OID_GET_CRL_FROM_CERT                equ     3

TIME_VALID_OID_FLUSH_OBJECT_FUNC                db      "TimeValidDllFlushObject", 0
TIME_VALID_OID_FLUSH_CTL                        equ     1
TIME_VALID_OID_FLUSH_CRL                        equ     2
TIME_VALID_OID_FLUSH_CRL_FROM_CERT              equ     3

CRYPTPROTECT_DEFAULT_PROVIDER                   equ     {0DF9D8CD0H,01501H,011D1H,08CH,07AH,0H,0C0H,04FH,0C2H,097H,0EBH}

CRYPTPROTECT_PROMPT_ON_UNPROTECT                equ     01H
CRYPTPROTECT_PROMPT_ON_PROTECT                  equ     02H
CRYPTPROTECT_PROMPT_RESERVED                    equ     004H
CRYPTPROTECT_PROMPT_STRONG                      equ     008H
CRYPTPROTECT_UI_FORBIDDEN                       equ     01H
CRYPTPROTECT_LOCAL_MACHINE                      equ     04H
CRYPTPROTECT_CRED_SYNC                          equ     08H
CRYPTPROTECT_FIRST_RESERVED_FLAGVAL             equ     00FFFFFFFH
CRYPTPROTECT_LAST_RESERVED_FLAGVAL              equ     0FFFFFFFFH

CERT_CREATE_SELFSIGN_NO_SIGN                    equ     1
CERT_CREATE_SELFSIGN_NO_KEY_INFO                equ     2

CRYPT_KEYID_MACHINE_FLAG                        equ     000000020H
CRYPT_KEYID_ALLOC_FLAG                          equ     000008000H

CRYPT_KEYID_DELETE_FLAG                         equ     000000010H
CRYPT_KEYID_SET_NEW_FLAG                        equ     000002000H

HCCE_CURRENT_USER                               equ     0
HCCE_LOCAL_MACHINE                              equ     1
CERT_CHAIN_CACHE_END_CERT                       equ     000000001H
CERT_CHAIN_THREAD_STORE_SYNC                    equ     000000002H
CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL             equ     000000004H
CERT_CHAIN_USE_LOCAL_MACHINE_STORE              equ     000000008H
CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE             equ     000000010H

CERT_TRUST_NO_ERROR                             equ     000000000H
CERT_TRUST_IS_NOT_TIME_VALID                    equ     000000001H
CERT_TRUST_IS_NOT_TIME_NESTED                   equ     000000002H
CERT_TRUST_IS_REVOKED                           equ     000000004H
CERT_TRUST_IS_NOT_SIGNATURE_VALID               equ     000000008H
CERT_TRUST_IS_NOT_VALID_FOR_USAGE               equ     000000010H
CERT_TRUST_IS_UNTRUSTED_ROOT                    equ     000000020H
CERT_TRUST_REVOCATION_STATUS_UNKNOWN            equ     000000040H
CERT_TRUST_IS_CYCLIC                            equ     000000080H
CERT_TRUST_IS_PARTIAL_CHAIN                     equ     000010000H
CERT_TRUST_CTL_IS_NOT_TIME_VALID                equ     000020000H
CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID           equ     000040000H
CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE           equ     000080000H
CERT_TRUST_HAS_EXACT_MATCH_ISSUER               equ     000000001H
CERT_TRUST_HAS_KEY_MATCH_ISSUER                 equ     000000002H
CERT_TRUST_HAS_NAME_MATCH_ISSUER                equ     000000004H
CERT_TRUST_IS_SELF_SIGNED                       equ     000000008H
CERT_TRUST_IS_COMPLEX_CHAIN                     equ     000010000H

USAGE_MATCH_TYPE_AND                            equ     000000000H
USAGE_MATCH_TYPE_OR                             equ     000000001H

CERT_CHAIN_REVOCATION_CHECK_END_CERT            equ     010000000H
CERT_CHAIN_REVOCATION_CHECK_CHAIN               equ     020000000H
CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT  equ     040000000H
CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY          equ     080000000H

REVOCATION_OID_CRL_REVOCATION                   equ     1

CERT_CHAIN_FIND_BY_ISSUER                       equ     1

CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG      equ     00001H
CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG    equ     00002H
CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG   equ     00004H
CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG    equ     00008H
CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG           equ     04000H
CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG       equ     08000H

CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG    equ     000000001H
CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG    equ     000000002H
CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG   equ     000000004H
CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS   equ     (CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG or CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG or CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG)
CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG         equ     000000010H
CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG       equ     000000020H
CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG   equ     000000100H
CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG    equ     000000200H
CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG    equ     000000400H
CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG  equ     000000800H
CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS  equ     (CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG or CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG)
CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG           equ     000008000H
CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG           equ     000004000H

CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC  db      "CertDllVerifyCertificateChainPolicy", 0
CERT_CHAIN_POLICY_BASE                          equ     1
CERT_CHAIN_POLICY_AUTHENTICODE                  equ     2
CERT_CHAIN_POLICY_AUTHENTICODE_TS               equ     3
CERT_CHAIN_POLICY_SSL                           equ     4
CERT_CHAIN_POLICY_BASIC_CONSTRAINTS             equ     5
CERT_CHAIN_POLICY_NT_AUTH                       equ     6

AUTHTYPE_CLIENT                                 equ     1
AUTHTYPE_SERVER                                 equ     2

BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG     equ     080000000H
BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG equ     040000000H

CERT_SELECT_BY_ENHKEY_USAGE                     equ     1
CERT_SELECT_BY_KEY_USAGE                        equ     2
CERT_SELECT_BY_POLICY_OID                       equ     3
CERT_SELECT_BY_PROV_NAME                        equ     4
CERT_SELECT_BY_EXTENSION                        equ     5
CERT_SELECT_BY_SUBJECT_HOST_NAME                equ     6
CERT_SELECT_BY_ISSUER_ATTR                      equ     7
CERT_SELECT_BY_SUBJECT_ATTR                     equ     8
CERT_SELECT_BY_ISSUER_NAME                      equ     9
CERT_SELECT_BY_PUBLIC_KEY                       equ     10
CERT_SELECT_BY_TLS_SIGNATURES                   equ     11

CERT_SELECT_LAST                                equ     CERT_SELECT_BY_TLS_SIGNATURES
CERT_SELECT_MAX                                 equ     (CERT_SELECT_LAST * 3)

CERT_SELECT_ALLOW_EXPIRED                       equ     000000001H
CERT_SELECT_TRUSTED_ROOT                        equ     000000002H
CERT_SELECT_DISALLOW_SELFSIGNED                 equ     000000004H
CERT_SELECT_HAS_PRIVATE_KEY                     equ     000000008H
CERT_SELECT_HAS_KEY_FOR_SIGNATURE               equ     000000010H
CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE            equ     000000020H
CERT_SELECT_HARDWARE_ONLY                       equ     000000040H
CERT_SELECT_ALLOW_DUPLICATES                    equ     000000080H

CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC db      "CryptDllExportPublicKeyInfoFromBCryptKeyHandle", 0
CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC       db      "CryptDllImportPublicKeyInfoEx2", 0

CERT_SELECT_MAX_PARA                            equ     500

TIMESTAMP_STATUS_GRANTED                        equ     0
TIMESTAMP_STATUS_GRANTED_WITH_MODS              equ     1
TIMESTAMP_STATUS_REJECTED                       equ     2
TIMESTAMP_STATUS_WAITING                        equ     3
TIMESTAMP_STATUS_REVOCATION_WARNING             equ     4
TIMESTAMP_STATUS_REVOKED                        equ     5

TIMESTAMP_FAILURE_BAD_ALG                       equ     0
TIMESTAMP_FAILURE_BAD_REQUEST                   equ     2
TIMESTAMP_FAILURE_BAD_FORMAT                    equ     5
TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE            equ     14
TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED          equ     15
TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED       equ     16
TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE            equ     17
TIMESTAMP_FAILURE_SYSTEM_FAILURE                equ     25

TIMESTAMP_DONT_HASH_DATA                        equ     000000001H
TIMESTAMP_VERIFY_CONTEXT_SIGNATURE              equ     000000020H
TIMESTAMP_NO_AUTH_RETRIEVAL                     equ     000020000H

TYPEDEF                                         HCRYPTPROV, xptr
TYPEDEF                                         HCRYPTKEY, xptr
TYPEDEF                                         HCRYPTHASH, xptr


;======================================== Structures ======================================;

if (NTDDI_VERSION < NTDDI_WINXP)
    SIGNATURE_RESOURCE_NUMBER                   equ     029AH
    
    struct VTableProvStruc
        Version         dd   ?
        FuncVerifyImage xptr ?
        FuncReturnhWnd  xptr ?
        dwProvType      dd   ?
        pbContextInfo   xptr ?
        cbContextInfo   dd   ?
        pszProvName     xptr ?
    ends
end if

struct CMS_KEY_INFO
    dwVersion dd   ?
    Algid     dd   ?
    pbOID     xptr ?
    cbOID     dd   ?
ends

struct HMAC_Info
    HashAlgid     dd   ?
    pbInnerString xptr ?
    cbInnerString dd   ?
    pbOuterString xptr ?
    cbOuterString dd   ?
ends

struct SCHANNEL_ALG
    dwUse       dd ?
    Algid       dd ?
    cBits       dd ?
    dwFlags     dd ?
    dwReserved  dd ?
ends

struct PROV_ENUMALGS
    aiAlgid   dd ?
    dwBitLen  dd ?
    dwNameLen dd ?
    szName    db 20 dup(?)
ends

struct PROV_ENUMALGS_EX
    aiAlgid        dd ?
    dwDefaultLen   dd ?
    dwMinLen       dd ?
    dwMaxLen       dd ?
    dwProtocols    dd ?
    dwNameLen      dd ?
    szName         db 20 dup(?)
    dwLongNameLen  dd ?
    szLongName     db 40 dup(?)
ends

struct PUBLICKEYSTRUC
    bType    db ?
    bVersion db ?
    reserved dw ?
    aiKeyAlg dd ?
ends

BLOBHEADER fix PUBLICKEYSTRUC

struct RSAPUBKEY
    magic  dd ?
    bitlen dd ?
    pubexp dd ?
ends

struct PUBKEY
    magic  dd ?
    bitlen dd ?
ends

DHPUBKEY fix PUBKEY
DSSPUBKEY fix PUBKEY
KEAPUBKEY fix PUBKEY
TEKPUBKEY fix PUBKEY

struct DSSSEED
    counter dd ?
    seed    db 20 dup(?)
ends

struct PUBKEYVER3
    magic   dd ?
    bitlenP dd ?
    bitlenQ dd ?
    bitlenJ dd ?
    DSSSeed DSSSEED
ends

DHPUBKEY_VER3 fix PUBKEYVER3
DSSPUBKEY_VER3 fix PUBKEYVER3

struct PRIVKEYVER3
    magic   dd ?
    bitlenP dd ?
    bitlenQ dd ?
    bitlenJ dd ?
    bitlenX dd ?
    DSSSeed DSSSEED
ends

DHPRIVKEY_VER3 fix PRIVKEYVER3
DSSPRIVKEY_VER3 fix PRIVKEYVER3

struct KEY_TYPE_SUBTYPE
    dwKeySpec dd ?
    Type      GUID
    Subtype   GUID
ends

struct CERT_FORTEZZA_DATA_PROP
    SerialNumber db 8 dup(?)
    CertIndex    dd ?
    CertLabel    db 36 dup(?)
ends

struct CRYPT_RC4_KEY_STATE
    Key  db 16 dup(?)
    SBox db 256 dup(?)
    i    db ?
    j    db ?
ends

struct CRYPT_DES_KEY_STATE
    Key      db 8 dup(?)
    IV       db 8 dup(?)
    Feedback db 8 dup(?)
ends

struct CRYPT_3DES_KEY_STATE
    Key      db 24 dup(?)
    IV       db 8 dup(?)
    Feedback db 8 dup(?)
ends

struct CRYPT_AES_128_KEY_STATE
    Key             db 16 dup(?)
    IV              db 16 dup(?)
    EncryptionState db 176 dup(?)
    DecryptionState db 176 dup(?)
    Feedback        db 16 dup(?)
ends

struct CRYPT_AES_256_KEY_STATE
    Key             db 32 dup(?)
    IV              db 16 dup(?)
    EncryptionState db 240 dup(?)
    DecryptionState db 240 dup(?)
    Feedback        db 16 dup(?)
ends

struct CRYPTOAPI_BLOB
    cbData dd   ?
    pbData xptr ?
ends

struct CRYPT_BIT_BLOB
    cbData      dd   ?
    pbData      xptr ?
    cUnusedBits dd   ?
ends

CRYPT_INTEGER_BLOB fix CRYPTOAPI_BLOB
CRYPT_UINT_BLOB fix CRYPTOAPI_BLOB
CRYPT_OBJID_BLOB fix CRYPTOAPI_BLOB
CERT_NAME_BLOB fix CRYPTOAPI_BLOB
CERT_RDN_VALUE_BLOB fix CRYPTOAPI_BLOB
CERT_BLOB fix CRYPTOAPI_BLOB
CRL_BLOB fix CRYPTOAPI_BLOB
DATA_BLOB fix CRYPTOAPI_BLOB
CRYPT_DATA_BLOB fix CRYPTOAPI_BLOB
CRYPT_HASH_BLOB fix CRYPTOAPI_BLOB
CRYPT_DIGEST_BLOB fix CRYPTOAPI_BLOB
CRYPT_DER_BLOB fix CRYPTOAPI_BLOB
CRYPT_ATTR_BLOB fix CRYPTOAPI_BLOB

struct CMS_DH_KEY_INFO
    dwVersion          dd   ?
    Algid              dd   ?
    pszContentEncObjId xptr ?
    PubInfo            CRYPT_DATA_BLOB
    pReserved          xptr ?
ends

struct CRYPT_ALGORITHM_IDENTIFIER
    pszObjId   xptr ?
    Parameters CRYPT_OBJID_BLOB
ends

struct CRYPT_OBJID_TABLE
    dwAlgId  dd   ?
    pszObjId xptr ?
ends

struct CRYPT_HASH_INFO
    HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    Hash          CRYPT_HASH_BLOB
ends

struct CERT_EXTENSION
    pszObjId  xptr ?
    fCritical dd   ?
    Value     CRYPT_OBJID_BLOB
ends

struct CRYPT_ATTRIBUTE_TYPE_VALUE
    pszObjId xptr ?
    Value    CRYPT_OBJID_BLOB
ends

struct CRYPT_ATTRIBUTE
    pszObjId xptr ?
    cValue   dd   ?
    rgValue  xptr ?
ends

struct CRYPT_ATTRIBUTES
    cAttr  dd ?
    rgAttr dd ?
ends

struct CERT_RDN_ATTR
    pszObjId    xptr ?
    dwValueType dd   ?
    _Value      CERT_RDN_VALUE_BLOB
ends

struct CERT_RDN
    cRDNAttr  dd   ?
    rgRDNAttr xptr ?
ends

struct CERT_NAME_INFO
    cRDN  dd ?
    rgRDN dd ?
ends

struct CERT_NAME_VALUE
    dwValueType dd ?
    Value       CERT_RDN_VALUE_BLOB
ends

struct CERT_PUBLIC_KEY_INFO
    Algorithm CRYPT_ALGORITHM_IDENTIFIER
    PublicKey CRYPT_BIT_BLOB
ends

struct CRYPT_PRIVATE_KEY_INFO
    Version     dd ?
    Algorithm   CRYPT_ALGORITHM_IDENTIFIER
    PrivateKey  CRYPT_DER_BLOB
    pAttributes dd ?
ends

struct CRYPT_ENCRYPTED_PRIVATE_KEY_INFO
    EncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedPrivateKey CRYPT_DATA_BLOB
ends

struct CRYPT_PKCS8_IMPORT_PARAMS
    PrivateKey             CRYPT_DIGEST_BLOB
    pResolvehCryptProvFunc xptr ?
    pVoidResolveFunc       xptr ?
    pDecryptPrivateKeyFunc xptr ?
    pVoidDecryptFunc       xptr ?
ends

struct CRYPT_PKCS8_EXPORT_PARAMS
    hCryptProv             xptr  ?
    dwKeySpec              dd    ?
    pszPrivateKeyObjId     xptr  ?
    pEncryptPrivateKeyFunc xptr  ?
    pVoidEncryptFunc       xptr  ?
ends

struct CERT_INFO
    dwVersion            dd ?
    SerialNumber         CRYPT_INTEGER_BLOB
    SignatureAlgorithm   CRYPT_ALGORITHM_IDENTIFIER
    Issuer               CERT_NAME_BLOB
    NotBefore            FILETIME
    NotAfter             FILETIME
    Subject              CERT_NAME_BLOB
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO
    IssuerUniqueId       CRYPT_BIT_BLOB
    SubjectUniqueId      CRYPT_BIT_BLOB
    cExtension           dd ?
    rgExtension          xptr ?
ends

struct CRL_ENTRY
    SerialNumber   CRYPT_INTEGER_BLOB
    RevocationDate FILETIME
    cExtension     dd   ?
    rgExtension    xptr ?
ends

struct CRL_INFO
    dwVersion          dd   ?
    SignatureAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    Issuer             CERT_NAME_BLOB
    ThisUpdate         FILETIME
    NextUpdate         FILETIME
    cCRLEntry          dd   ?
    rgCRLEntry         xptr ?
    cExtension         dd   ?
    rgExtension        xptr ?
ends

struct CERT_REQUEST_INFO
    dwVersion            dd   ?
    Subject              CERT_NAME_BLOB
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO
    cAttribute           dd   ?
    rgAttribute          xptr ?
ends

struct CERT_KEYGEN_REQUEST_INFO
    dwVersion            dd   ?
    SubjectPublicKeyInfo CERT_PUBLIC_KEY_INFO
    pwszChallengeString  xptr ?
ends

struct CERT_SIGNED_CONTENT_INFO
    ToBeSigned          CRYPT_DER_BLOB
    SignatureAlgorithm  CRYPT_ALGORITHM_IDENTIFIER
    Signature           CRYPT_BIT_BLOB
ends

struct CTL_USAGE
    cUsageIdentifier     dd   ?
    rgpszUsageIdentifier xptr ?
ends
CERT_ENHKEY_USAGE fix CTL_USAGE

struct CTL_ENTRY
    SubjectIdentifier CRYPT_DATA_BLOB
    cAttribute        dd   ?
    rgAttribute       xptr ?
ends

struct CTL_INFO
    dwVersion        dd   ?
    SubjectUsage     CTL_USAGE
    ListIdentifier   CRYPT_DATA_BLOB
    SequenceNumber   CRYPT_INTEGER_BLOB
    ThisUpdate       FILETIME
    NextUpdate       FILETIME
    SubjectAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    cCTLEntry        dd   ?
    rgCTLEntry       xptr ?
    cExtension       dd   ?
    rgExtension      xptr ?
ends

struct CRYPT_TIME_STAMP_REQUEST_INFO
    pszTimeStampAlgorithm xptr ?
    pszContentType        xptr ?
    Content               CRYPT_OBJID_BLOB
    cAttribute            dd   ?
    rgAttribute           xptr ?
ends

struct CRYPT_ENROLLMENT_NAME_VALUE_PAIR
    pwszName  xptr ?
    pwszValue xptr ?
ends

struct CRYPT_CSP_PROVIDER
    dwKeySpec        dd   ?
    pwszProviderName xptr ?
    Signature        CRYPT_BIT_BLOB
ends

struct CRYPT_ENCODE_PARA
    cbSize   dd   ?
    pfnAlloc xptr ?
    pfnFree  xptr ?
ends

CRYPT_DECODE_PARA fix CRYPT_ENCODE_PARA

struct CERT_EXTENSIONS
    cExtension  dd   ?
    rgExtension xptr  ?
ends

struct CERT_AUTHORITY_KEY_ID_INFO
    KeyId            CRYPT_DATA_BLOB
    CertIssuer       CERT_NAME_BLOB
    CertSerialNumber CRYPT_INTEGER_BLOB
ends

struct CERT_PRIVATE_KEY_VALIDITY
    NotBefore FILETIME
    NotAfter  FILETIME
ends

struct CERT_KEY_ATTRIBUTES_INFO
    KeyId                  CRYPT_DATA_BLOB
    IntendedKeyUsage       CRYPT_BIT_BLOB
    pPrivateKeyUsagePeriod xptr ?
ends

struct CERT_POLICY_ID
    cCertPolicyElementId     dd   ?
    rgpszCertPolicyElementId xptr ?
ends

struct CERT_KEY_USAGE_RESTRICTION_INFO
    cCertPolicyId      dd   ?
    rgCertPolicyId     xptr ?
    RestrictedKeyUsage CRYPT_BIT_BLOB
ends

struct CERT_OTHER_NAME
    pszObjId xptr ?
    Value    CRYPT_OBJID_BLOB
ends

struct CERT_ALT_NAME_ENTRY
    dwAltNameChoice    dd   ?
    union
        pOtherName      xptr ?
        pwszRfc822Name  xptr ?
        pwszDNSName     xptr ?
        DirectoryName   CERT_NAME_BLOB
        pwszURL         xptr ?
        IPAddress       CRYPT_DATA_BLOB
        pszRegisteredID xptr ?
    ends
ends

struct CERT_ALT_NAME_INFO
    cAltEntry  dd   ?
    rgAltEntry xptr ?
ends

struct CERT_BASIC_CONSTRAINTS_INFO
    SubjectType          CRYPT_BIT_BLOB
    fPathLenConstraint   dd ?
    dwPathLenConstraint  dd ?
    cSubtreesConstraint  dd ?
    rgSubtreesConstraint dd ?
ends

struct CERT_BASIC_CONSTRAINTS2_INFO
    fCA                 dd ?
    fPathLenConstraint  dd ?
    dwPathLenConstraint dd ?
ends

struct CERT_POLICY_QUALIFIER_INFO
    pszPolicyQualifierId xptr ?
    Qualifier            CRYPT_OBJID_BLOB
ends

struct CERT_POLICY_INFO
    pszPolicyIdentifier xptr ?
    cPolicyQualifier    dd   ?
    rgPolicyQualifier   xptr ?
ends

struct CERT_POLICIES_INFO
    cPolicyInfo  dd   ?
    rgPolicyInfo xptr ?
ends

struct CERT_POLICY_QUALIFIER_NOTICE_REFERENCE
    pszOrganization xptr ?
    cNoticeNumbers  dd   ?
    rgNoticeNumbers xptr ?
ends

struct CERT_POLICY_QUALIFIER_USER_NOTICE
    pNoticeReference xptr ?
    pszDisplayText   xptr ?
ends

struct CPS_URLS
    pszURL     xptr ?
    pAlgorithm xptr ?
    pDigest    xptr ?
ends

struct CERT_POLICY95_QUALIFIER1
    pszPracticesReference  xptr ?
    pszNoticeIdentifier    xptr ?
    pszNSINoticeIdentifier xptr ?
    cCPSURLs               dd   ?
    rgCPSURLs              xptr ?
ends

struct CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY
    pszObjId xptr ?
    cValue   dd   ?
    rgValue  xptr ?
ends

struct CRYPT_CONTENT_INFO
    pszObjId xptr ?
    Content  CRYPT_DER_BLOB
ends

struct CRYPT_SEQUENCE_OF_ANY
    cValue  dd   ?
    rgValue xptr ?
ends

struct CERT_AUTHORITY_KEY_ID2_INFO
    KeyId                     CRYPT_DATA_BLOB
    AuthorityCertIssuer       CERT_ALT_NAME_INFO
    AuthorityCertSerialNumber CRYPT_INTEGER_BLOB
ends

struct CERT_ACCESS_DESCRIPTION
    pszAccessMethod xptr ?
    AccessLocation  CERT_ALT_NAME_ENTRY
ends

struct CERT_AUTHORITY_INFO_ACCESS
    cAccDescr  dd   ?
    rgAccDescr xptr ?
ends

struct CRL_DIST_POINT_NAME
    dwDistPointNameChoice dd   ?
    FullName              CERT_ALT_NAME_INFO
ends

struct CRL_DIST_POINT
    DistPointName CRL_DIST_POINT_NAME
    ReasonFlags   CRYPT_BIT_BLOB
    CRLIssuer     CERT_ALT_NAME_INFO
ends

struct CRL_DIST_POINTS_INFO
    cDistPoint  dd   ?
    rgDistPoint xptr ?
ends

struct CERT_DSS_PARAMETERS
    p CRYPT_UINT_BLOB
    q CRYPT_UINT_BLOB
    g CRYPT_UINT_BLOB
ends

struct CERT_DH_PARAMETERS
    p CRYPT_UINT_BLOB
    g CRYPT_UINT_BLOB
ends

struct CERT_X942_DH_VALIDATION_PARAMS
    seed        CRYPT_BIT_BLOB
    pgenCounter xptr ?
ends

struct CERT_X942_DH_PARAMETERS
    p                 CRYPT_UINT_BLOB
    g                 CRYPT_UINT_BLOB
    q                 CRYPT_UINT_BLOB
    j                 CRYPT_UINT_BLOB
    pValidationParams xptr ?
ends

struct CRYPT_X942_OTHER_INFO
    pszContentEncryptionObjId xptr ?
    rgbCounter                db CRYPT_X942_COUNTER_BYTE_LENGTH dup(?)
    rgbKeyLength              db CRYPT_X942_COUNTER_BYTE_LENGTH dup(?)
    PubInfo                   CRYPT_DATA_BLOB
ends

struct CRYPT_RC2_CBC_PARAMETERS
    dwVersion dd ?
    fIV       dd ?
    rgbIV     db 8 dup(?)
ends

struct CRYPT_SMIME_CAPABILITY
    pszObjId   xptr ?
    Parameters CRYPT_OBJID_BLOB
ends

struct CRYPT_SMIME_CAPABILITIES
    cCapability  dd   ?
    rgCapability xptr ?
ends

struct CRYPT_OID_FUNC_ENTRY
    pszOID     dd   ?
    pvFuncAddr xptr ?
ends

struct CRYPT_OID_INFO
    cbSize            dd   ?
    pszOID            xptr ?
    pwszName          xptr ?
    dwGroupId         dd   ?
    union
        dwValue       dd   ?
        Algid         dd   ?
        dwLength      dd   ?
    ends
    ExtraInfo         CRYPT_DATA_BLOB
    pwszCNGAlgid      xptr ?
    pwszCNGExtraAlgid xptr ?
ends

struct CERT_ISSUER_SERIAL_NUMBER
    Issuer       CERT_NAME_BLOB
    SerialNumber CRYPT_INTEGER_BLOB
ends

struct CERT_ID
    dwIdChoice             dd ?
    union
        IssuerSerialNumber CERT_ISSUER_SERIAL_NUMBER
        KeyId              CRYPT_HASH_BLOB
        HashId             CRYPT_HASH_BLOB
    ends
ends

struct CMSG_SIGNER_ENCODE_INFO
    cbSize                  dd    ?
    pCertInfo               xptr  ?
    union
        hCryptProv          xptr  ?
        hNCryptKey          xptr  ?
    ends
    dwKeySpec               dd    ?
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER
    pvHashAuxInfo           xptr  ?
    cAuthAttr               dd    ?
    rgAuthAttr              xptr  ?
    cUnauthAttr             dd    ?
    rgUnauthAttr            xptr  ?
    SignerId                CERT_ID
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvHashEncryptionAuxInfo xptr  ?
ends

struct CMSG_SIGNED_ENCODE_INFO
    cbSize            dd   ?
    cSigners          dd   ?
    rgSigners         xptr ?
    cCertEncoded      dd   ?
    rgCertEncoded     xptr ?
    cCrlEncoded       dd   ?
    rgCrlEncoded      xptr ?
    cAttrCertEncoded  dd   ?
    rgAttrCertEncoded xptr ?
ends

struct CMSG_ENVELOPED_ENCODE_INFO
    cbSize                     dd    ?
    hCryptProv                 xptr  ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvEncryptionAuxInfo        xptr  ?
    cRecipients                dd    ?
    rgpRecipients              xptr  ?
    rgCmsRecipients            xptr  ?
    cCertEncoded               dd    ?
    rgCertEncoded              xptr  ?
    cCrlEncoded                dd    ?
    rgCrlEncoded               xptr  ?
    cAttrCertEncoded           dd    ?
    rgAttrCertEncoded          xptr  ?
    cUnprotectedAttr           dd    ?
    rgUnprotectedAttr          xptr  ?
ends

struct CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO
    cbSize                 dd    ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvKeyEncryptionAuxInfo xptr  ?
    hCryptProv             xptr  ?
    RecipientPublicKey     CRYPT_BIT_BLOB
    RecipientId            CERT_ID
ends

struct CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO
    cbSize             dd   ?
    RecipientPublicKey CRYPT_BIT_BLOB
    RecipientId        CERT_ID
    Date               FILETIME
    pOtherAttr         xptr ?
ends

struct CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO
    cbSize                    dd    ?
    KeyEncryptionAlgorithm    CRYPT_ALGORITHM_IDENTIFIER
    pvKeyEncryptionAuxInfo    xptr  ?
    KeyWrapAlgorithm          CRYPT_ALGORITHM_IDENTIFIER
    pvKeyWrapAuxInfo          xptr  ?
    hCryptProv                xptr  ?
    dwKeySpec                 dd    ?
    dwKeyChoice               dd    ?
    union
        pEphemeralAlgorithm   xptr  ?
        pSenderId             xptr  ?
    ends
    UserKeyingMaterial        CRYPT_DATA_BLOB
    cRecipientEncryptedKeys   dd    ?
    rgpRecipientEncryptedKeys xptr  ?
ends

struct CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO
    cbSize                 dd    ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvKeyEncryptionAuxInfo xptr  ?
    hCryptProv             xptr  ?
    dwKeyChoice            dd    ?
    union
        hKeyEncryptionKey  xptr  ?
        pvKeyEncryptionKey xptr  ?
    ends
    KeyId                  CRYPT_DATA_BLOB
    Date                   FILETIME
    pOtherAttr             xptr  ?
ends

struct CMSG_RECIPIENT_ENCODE_INFO
    dwRecipientChoice dd   ?
    union
        pKeyTrans     xptr ?
        pKeyAgree     xptr ?
        pMailList     xptr ?
    ends
ends

struct CMSG_RC2_AUX_INFO
    cbSize   dd ?
    dwBitLen dd ?
ends

struct CMSG_SP3_COMPATIBLE_AUX_INFO
    cbSize  dd ?
    dwFlags dd ?
ends

struct CMSG_RC4_AUX_INFO
    cbSize   dd ?
    dwBitLen dd ?
ends

struct CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
    cbSize        dd ?
    SignedInfo    CMSG_SIGNED_ENCODE_INFO
    EnvelopedInfo CMSG_ENVELOPED_ENCODE_INFO
ends

struct CMSG_HASHED_ENCODE_INFO
    cbSize        dd    ?
    hCryptProv    xptr  ?
    HashAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvHashAuxInfo dd    ?
ends

struct CMSG_ENCRYPTED_ENCODE_INFO
    cbSize                     dd   ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvEncryptionAuxInfo        xptr ?
ends

struct CMSG_STREAM_INFO
    cbContent       dd   ?
    pfnStreamOutput xptr ?
    pvArg           xptr ?
ends

struct CMSG_SIGNER_INFO
    dwVersion               dd ?
    Issuer                  CERT_NAME_BLOB
    SerialNumber            CRYPT_INTEGER_BLOB
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedHash           CRYPT_DATA_BLOB
    AuthAttrs               CRYPT_ATTRIBUTES
    UnauthAttrs             CRYPT_ATTRIBUTES
ends

struct CMSG_CMS_SIGNER_INFO
    dwVersion               dd ?
    SignerId                CERT_ID
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedHash           CRYPT_DATA_BLOB
    AuthAttrs               CRYPT_ATTRIBUTES
    UnauthAttrs             CRYPT_ATTRIBUTES
ends

struct CMSG_KEY_TRANS_RECIPIENT_INFO
    dwVersion              dd ?
    RecipientId            CERT_ID
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedKey           CRYPT_DATA_BLOB
ends

struct CMSG_RECIPIENT_ENCRYPTED_KEY_INFO
    RecipientId  CERT_ID
    EncryptedKey CRYPT_DATA_BLOB
    Date         FILETIME
    pOtherAttr   xptr ?
ends

struct CMSG_KEY_AGREE_RECIPIENT_INFO
    dwVersion                   dd   ?
    dwOriginatorChoice          dd   ?
    union
        OriginatorCertId        CERT_ID
        OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO
    ends
    UserKeyingMaterial          CRYPT_DATA_BLOB
    KeyEncryptionAlgorithm      CRYPT_ALGORITHM_IDENTIFIER
    cRecipientEncryptedKeys     dd   ?
    rgpRecipientEncryptedKeys   xptr ?
ends

struct CMSG_MAIL_LIST_RECIPIENT_INFO
    dwVersion              dd   ?
    KeyId                  CRYPT_DATA_BLOB
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedKey           CRYPT_DATA_BLOB
    Date                   FILETIME
    pOtherAttr             xptr ?
ends

struct CMSG_CMS_RECIPIENT_INFO
    dwRecipientChoice dd   ?
    union
        pKeyTrans     xptr ?
        pKeyAgree     xptr ?
        pMailList     xptr ?
    ends
ends

struct CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA
    cbSize        dd    ?
    hCryptProv    xptr  ?
    dwSignerIndex dd    ?
    dwSignerType  dd    ?
    pvSigner      xptr  ?
ends

struct CMSG_CTRL_DECRYPT_PARA
    cbSize           dd    ?
    hCryptProv       xptr  ?
    dwKeySpec        dd    ?
    dwRecipientIndex dd    ?
ends

struct CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
    cbSize           dd    ?
    hCryptProv       xptr  ?
    dwKeySpec        dd    ?
    pKeyTrans        xptr  ?
    dwRecipientIndex dd    ?
ends

struct CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
    cbSize                       dd    ?
    hCryptProv                   xptr  ?
    dwKeySpec                    dd    ?
    pKeyAgree                    xptr  ?
    dwRecipientIndex             dd    ?
    dwRecipientEncryptedKeyIndex dd    ?
    OriginatorPublicKey          CRYPT_BIT_BLOB
ends

struct CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
    cbSize                 dd    ?
    hCryptProv             xptr  ?
    pMailList              xptr  ?
    dwRecipientIndex       dd    ?
    dwKeyChoice            dd    ?
    union
        hKeyEncryptionKey  xptr  ?
        pvKeyEncryptionKey xptr  ?
    ends
ends

struct CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA
    cbSize        dd ?
    dwSignerIndex dd ?
    blob          CRYPT_DATA_BLOB
ends

struct CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA
    cbSize            dd ?
    dwSignerIndex     dd ?
    dwUnauthAttrIndex dd ?
ends

struct CMSG_CONTENT_ENCRYPT_INFO
    cbSize                     dd    ?
    hCryptProv                 xptr  ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvEncryptionAuxInfo        xptr  ?
    cRecipients                dd    ?
    rgCmsRecipients            xptr  ?
    pfnAlloc                   xptr  ?
    pfnFree                    xptr  ?
    dwEncryptFlags             dd    ?
    hContentEncryptKey         xptr  ?
    dwFlags                    dd    ?
ends

struct CMSG_KEY_TRANS_ENCRYPT_INFO
    cbSize                 dd ?
    dwRecipientIndex       dd ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedKey           CRYPT_DATA_BLOB
    dwFlags                dd ?
ends

struct CMSG_KEY_AGREE_KEY_ENCRYPT_INFO
    cbSize       dd ?
    EncryptedKey CRYPT_DATA_BLOB
ends

struct CMSG_KEY_AGREE_ENCRYPT_INFO
    cbSize                      dd   ?
    dwRecipientIndex            dd   ?
    KeyEncryptionAlgorithm      CRYPT_ALGORITHM_IDENTIFIER
    UserKeyingMaterial          CRYPT_DATA_BLOB
    dwOriginatorChoice          dd   ?
    union
        OriginatorCertId        CERT_ID
        OriginatorPublicKeyInfo CERT_PUBLIC_KEY_INFO
    ends
    cKeyAgreeKeyEncryptInfo     dd   ?
    rgpKeyAgreeKeyEncryptInfo   xptr ?
    dwFlags                     dd   ?
ends

struct CMSG_MAIL_LIST_ENCRYPT_INFO
    cbSize                 dd ?
    dwRecipientIndex       dd ?
    KeyEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    EncryptedKey           CRYPT_DATA_BLOB
    dwFlags                dd ?
ends

struct CERT_CONTEXT
    dwCertEncodingType dd    ?
    pbCertEncoded      xptr  ?
    cbCertEncoded      dd    ?
    pCertInfo          xptr  ?
    hCertStore         xptr  ?
ends

struct CRL_CONTEXT
    dwCertEncodingType dd    ?
    pbCrlEncoded       xptr  ?
    cbCrlEncoded       dd    ?
    pCrlInfo           xptr  ?
    hCertStore         xptr  ?
ends

struct CTL_CONTEXT
    dwMsgAndCertEncodingType dd    ?
    pbCtlEncoded             xptr  ?
    cbCtlEncoded             dd    ?
    pCtlInfo                 xptr  ?
    hCertStore               xptr  ?
    hCryptMsg                xptr  ?
    pbCtlContent             xptr  ?
    cbCtlContent             dd    ?
ends

struct CRYPT_KEY_PROV_PARAM
    dwParam dd   ?
    pbData  xptr ?
    cbData  dd   ?
    dwFlags dd   ?
ends

struct CRYPT_KEY_PROV_INFO
    pwszContainerName xptr ?
    pwszProvName      xptr ?
    dwProvType        dd   ?
    dwFlags           dd   ?
    cProvParam        dd   ?
    rgProvParam       xptr ?
    dwKeySpec         dd   ?
ends

struct CERT_KEY_CONTEXT
    cbSize     dd    ?
    hCryptProv xptr  ?
    dwKeySpec  dd    ?
ends

struct CERT_SYSTEM_STORE_RELOCATE_PARA
    union
        hKeyBase        xptr  ?
        pvBase          xptr  ?
    ends
    union
        pvSystemStore   xptr  ?
        pszSystemStore  xptr  ?
        pwszSystemStore xptr  ?
    ends
ends

struct CERT_REGISTRY_STORE_CLIENT_GPT_PARA
    hKeyBase    xptr  ?
    pwszRegPath xptr  ?
ends

struct CERT_REGISTRY_STORE_ROAMING_PARA
    hKey               xptr  ?
    pwszStoreDirectory xptr  ?
ends

struct CERT_STORE_PROV_INFO
    cbSize              dd    ?
    cStoreProvFunc      dd    ?
    rgpvStoreProvFunc   xptr  ?
    hStoreProv          xptr  ?
    dwStoreProvFlags    dd    ?
    hStoreProvFuncAddr2 xptr  ?
ends

struct CERT_STORE_PROV_FIND_INFO
    cbSize                   dd   ?
    dwMsgAndCertEncodingType dd   ?
    dwFindFlags              dd   ?
    dwFindType               dd   ?
    pvFindPara               xptr ?
ends

struct CTL_ANY_SUBJECT_INFO
    SubjectAlgorithm  CRYPT_ALGORITHM_IDENTIFIER
    SubjectIdentifier CRYPT_DATA_BLOB
ends

struct CTL_FIND_USAGE_PARA
    cbSize         dd   ?
    SubjectUsage   CTL_USAGE
    ListIdentifier CRYPT_DATA_BLOB
    pSigner        xptr ?
ends

struct CTL_FIND_SUBJECT_PARA
    cbSize        dd   ?
    pUsagePara    xptr ?
    dwSubjectType dd   ?
    pvSubject     xptr ?
ends

struct CERT_CREATE_CONTEXT_PARA
    cbSize  dd   ?
    pfnFree xptr ?
    pvFree  xptr ?
ends

struct CERT_SYSTEM_STORE_INFO
    cbSize dd ?
ends

struct CERT_PHYSICAL_STORE_INFO
    cbSize               dd   ?
    pszOpenStoreProvider xptr ?
    dwOpenEncodingType   dd   ?
    dwOpenFlags          dd   ?
    OpenParameters       CRYPT_DATA_BLOB
    dwFlags              dd   ?
    dwPriority           dd   ?
ends

struct CTL_VERIFY_USAGE_PARA
    cbSize         dd   ?
    ListIdentifier CRYPT_DATA_BLOB
    cCtlStore      dd   ?
    rghCtlStore    xptr ?
    cSignerStore   dd   ?
    rghSignerStore dd   ?
ends

struct CTL_VERIFY_USAGE_STATUS
    cbSize          dd   ?
    dwError         dd   ?
    dwFlags         dd   ?
    ppCtl           xptr ?
    dwCtlEntryIndex dd   ?
    ppSigner        xptr ?
    dwSignerIndex   dd   ?
ends

struct CERT_REVOCATION_PARA
    cbSize       dd    ?
    pIssuerCert  xptr  ?
    cCertStore   dd    ?
    rgCertStore  xptr  ?
    hCrlStore    xptr  ?
    pftTimeToUse xptr  ?
ends

struct CERT_REVOCATION_STATUS
    cbSize   dd ?
    dwIndex  dd ?
    dwError  dd ?
    dwReason dd ?
ends

struct CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA
    cOID     dd   ?
    rgpszOID xptr ?
ends

struct CRYPT_SIGN_MESSAGE_PARA
    cbSize                  dd   ?
    dwMsgEncodingType       dd   ?
    pSigningCert            xptr ?
    HashAlgorithm           CRYPT_ALGORITHM_IDENTIFIER
    pvHashAuxInfo           xptr ?
    cMsgCert                dd   ?
    rgpMsgCert              xptr ?
    cMsgCrl                 dd   ?
    rgpMsgCrl               xptr ?
    cAuthAttr               dd   ?
    rgAuthAttr              xptr ?
    cUnauthAttr             dd   ?
    rgUnauthAttr            xptr ?
    dwFlags                 dd   ?
    dwInnerContentType      dd   ?
    HashEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvHashEncryptionAuxInfo xptr ?
ends

struct CRYPT_VERIFY_MESSAGE_PARA
    cbSize                   dd    ?
    dwMsgAndCertEncodingType dd    ?
    hCryptProv               xptr  ?
    pfnGetSignerCertificate  xptr  ?
    pvGetArg                 xptr  ?
ends

struct CRYPT_ENCRYPT_MESSAGE_PARA
    cbSize                     dd    ?
    dwMsgEncodingType          dd    ?
    hCryptProv                 xptr  ?
    ContentEncryptionAlgorithm CRYPT_ALGORITHM_IDENTIFIER
    pvEncryptionAuxInfo        xptr  ?
    dwFlags                    dd    ?
    dwInnerContentType         dd    ?
ends

struct CRYPT_DECRYPT_MESSAGE_PARA
    cbSize                   dd   ?
    dwMsgAndCertEncodingType dd   ?
    cCertStore               dd   ?
    rghCertStore             xptr ?
ends

struct CRYPT_HASH_MESSAGE_PARA
    cbSize            dd    ?
    dwMsgEncodingType dd    ?
    hCryptProv        xptr  ?
    HashAlgorithm     CRYPT_ALGORITHM_IDENTIFIER
    pvHashAuxInfo     xptr  ?
ends

struct CRYPT_KEY_SIGN_MESSAGE_PARA
    cbSize                   dd    ?
    dwMsgAndCertEncodingType dd    ?
    hCryptProv               xptr  ?
    dwKeySpec                dd    ?
    HashAlgorithm            CRYPT_ALGORITHM_IDENTIFIER
    pvHashAuxInfo            xptr  ?
    PubKeyAlgorithm          CRYPT_ALGORITHM_IDENTIFIER
ends

struct CRYPT_KEY_VERIFY_MESSAGE_PARA
    cbSize            dd    ?
    dwMsgEncodingType dd    ?
    hCryptProv        xptr  ?
ends

struct CERT_CHA
    cCerts         dd ?
    certs          dd ?
    keyLocatorInfo CRYPT_KEY_PROV_INFO
ends

struct CRYPT_BLOB_ARRAY
    cBlob  dd   ?
    rgBlob xptr ?
ends

struct CRYPT_CREDENTIALS
    cbSize            dd   ?
    pszCredentialsOid xptr ?
    pvCredentials     xptr ?
ends

struct CRYPT_PASSWORD_CREDENTIALSA
    cbSize      dd   ?
    pszUsername xptr ?
    pszPassword xptr ?
ends

struct CRYPT_PASSWORD_CREDENTIALSW
    cbSize      dd   ?
    pszUsername xptr ?
    pszPassword xptr ?
ends

struct CRYPT_ASYNC_RETRIEVAL_COMPLETION
    pfnCompletion xptr ?
    pvCompletion  xptr ?
ends

struct CRYPT_URL_ARRAY
    cUrl     dd   ?
    rgwszUrl xptr ?
ends

struct CRYPT_URL_INFO
    cbSize          dd   ?
    dwSyncDeltaTime dd   ?
    cGroup          dd   ?
    rgcGroupEntry   xptr ?
ends

struct CRYPTPROTECT_PROMPTSTRUCT
    cbSize        dd    ?
    dwPromptFlags dd    ?
    hwndApp       xptr  ?
    szPrompt      xptr  ?
ends

struct CERT_SERVER_OCSP_RESPONSE_CONTEXT
    cbSize                dd   ?
    pbEncodedOcspResponse xptr ?
    cbEncodedOcspResponse dd   ?
ends

struct CERT_CHAIN_ENGINE_CONFIG
    cbSize                    dd    ?
    hRestrictedRoot           xptr  ?
    hRestrictedTrust          xptr  ?
    hRestrictedOther          xptr  ?
    cAdditionalStore          dd    ?
    rghAdditionalStore        xptr  ?
    dwFlags                   dd    ?
    dwUrlRetrievalTimeout     dd    ?
    MaximumCachedCertificates dd    ?
    CycleDetectionModulus     dd    ?
    hExclusiveRoot            xptr  ?
    hExclusiveTrustedPeople   xptr  ?
    dwExclusiveFlags          dd    ?
ends

struct CERT_TRUST_STATUS
    dwErrorStatus dd ?
    dwInfoStatus  dd ?
ends

struct CERT_REVOCATION_INFO
    cbSize             dd ?
    dwRevocationResult dd ?
    pszRevocationOid   dd ?
    pvOidSpecificInfo  dd ?
ends

struct CERT_TRUST_LIST_INFO
    cbSize      dd   ?
    pCtlEntry   xptr ?
    pCtlContext xptr ?
ends

struct CERT_CHAIN_ELEMENT
    cbSize          dd   ?
    pCertContext    xptr ?
    TrustStatus     CERT_TRUST_STATUS
    pRevocationInfo xptr ?
ends

struct CERT_SIMPLE_CHAIN
    cbSize         dd   ?
    TrustStatus    CERT_TRUST_STATUS
    cElement       dd   ?
    rgpElement     xptr ?
    pTrustListInfo xptr ?
ends

struct CERT_CHAIN_CONTEXT
    cbSize                      dd   ?
    TrustStatus                 CERT_TRUST_STATUS
    cChain                      dd   ?
    rgpChain                    xptr ?
    cLowerQualityChainContext   dd   ?
    rgpLowerQualityChainContext xptr ?
    fHasRevocationFreshnessTime dd   ?
    dwRevocationFreshnessTime   dd   ?
ends

struct CERT_USAGE_MATCH
    dwType dd ?
    Usage  CERT_ENHKEY_USAGE
ends

struct CTL_USAGE_MATCH
    dwType dd ?
    Usage  CTL_USAGE
ends

struct CERT_CHAIN_PARA
    cbSize         dd ?
    RequestedUsage CERT_USAGE_MATCH
ends

struct CRL_REVOCATION_INFO
    pCrlEntry       xptr ?
    pCrlContext     xptr ?
    pCrlIssuerChain xptr ?
ends

struct CERT_CHAIN_FIND_BY_ISSUER_PARA
    cbSize                   dd   ?
    pszUsageIdentifier       xptr ?
    dwKeySpec                dd   ?
    dwAcquirePrivateKeyFlags dd   ?
    cIssuer                  dd   ?
    rgIssuer                 xptr ?
    pfnFindCallback          xptr ?
    pvFindArg                xptr ?
ends

struct CERT_CHAIN_POLICY_PARA
    cbSize            dd   ?
    dwFlags           dd   ?
    pvExtraPolicyPara xptr ?
ends

struct CERT_CHAIN_POLICY_STATUS
    cbSize              dd   ?
    dwError             dd   ?
    lChainIndex         dd   ?
    lElementIndex       dd   ?
    pvExtraPolicyStatus xptr ?
ends

struct AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
    cbSize              dd   ?
    dwRegPolicySettings dd   ?
    pSignerInfo         xptr ?
ends

struct AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS
    cbSize      dd ?
    fCommercial dd ?
ends

struct AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA
    cbSize              dd ?
    dwRegPolicySettings dd ?
    fCommercial         dd ?
ends

struct HTTPSPolicyCallbackData
    union
        cbStruct   dd   ?
        cbSize     dd   ?
    ends
    dwAuthType     dd   ?
    fdwChecks      dd   ?
    pwszServerName xptr ?
ends

struct CERT_SELECT_CHAIN_PARA
    hChainEngine     xptr  ?
    pTime            xptr  ?
    hAdditionalStore xptr  ?
    pChainPara       xptr  ?
    dwFlags          dd    ?
ends

struct CERT_SELECT_CRITERIA
    dwType dd   ?
    cPara  dd   ?
    ppPara xptr ?
ends

struct CRYPT_TIMESTAMP_REQUEST
    dwVersion      dd    ?
    HashAlgorithm  CRYPT_ALGORITHM_IDENTIFIER
    HashedMessage  CRYPT_DER_BLOB
    pszTSAPolicyId xptr  ?
    Nonce          CRYPT_INTEGER_BLOB
    fCertReq       xptr  ?
    cExtension     dd    ?
    rgExtension    xptr  ?
ends

struct CRYPT_TIMESTAMP_RESPONSE
    dwStatus    dd   ?
    cFreeText   dd   ?
    rgFreeText  xptr ?
    FailureInfo CRYPT_BIT_BLOB
    ContentInfo CRYPT_DER_BLOB
ends

struct CRYPT_TIMESTAMP_ACCURACY
    dwSeconds dd ?
    dwMillis  dd ?
    dwMicros  dd ?
ends

struct CRYPT_TIMESTAMP_INFO
    dwVersion      dd    ?
    pszTSAPolicyId xptr  ?
    HashAlgorithm  CRYPT_ALGORITHM_IDENTIFIER
    HashedMessage  CRYPT_DER_BLOB
    SerialNumber   CRYPT_INTEGER_BLOB
    ftTime         FILETIME
    pvAccuracy     xptr  ?
    fOrdering      xptr  ?
    Nonce          CRYPT_DER_BLOB
    Tsa            CRYPT_DER_BLOB
    cExtension     dd    ?
    rgExtension    xptr  ?
ends

struct CRYPT_TIMESTAMP_CONTEXT
    cbEncoded  dd   ?
    pbEncoded  xptr ?
    pTimeStamp xptr ?
ends

struct CRYPT_TIMESTAMP_PARA
    pszTSAPolicyId xptr  ?
    fRequestCerts  xptr  ?
    Nonce          CRYPT_INTEGER_BLOB
    cExtension     dd    ?
    rgExtension    xptr  ?
ends


;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_CertAddCRLContextToStore' as CertAddCRLContextToStore:qword
    extrn '__imp_CertAddCRLLinkToStore' as CertAddCRLLinkToStore:qword
    extrn '__imp_CertAddCTLContextToStore' as CertAddCTLContextToStore:qword
    extrn '__imp_CertAddCTLLinkToStore' as CertAddCTLLinkToStore:qword
    extrn '__imp_CertAddCertificateContextToStore' as CertAddCertificateContextToStore:qword
    extrn '__imp_CertAddCertificateLinkToStore' as CertAddCertificateLinkToStore:qword
    extrn '__imp_CertAddEncodedCRLToStore' as CertAddEncodedCRLToStore:qword
    extrn '__imp_CertAddEncodedCTLToStore' as CertAddEncodedCTLToStore:qword
    extrn '__imp_CertAddEncodedCertificateToStore' as CertAddEncodedCertificateToStore:qword
    extrn '__imp_CertAddEncodedCertificateToSystemStoreA' as CertAddEncodedCertificateToSystemStoreA:qword
    extrn '__imp_CertAddEncodedCertificateToSystemStoreW' as CertAddEncodedCertificateToSystemStoreW:qword
    extrn '__imp_CertAddEnhancedKeyUsageIdentifier' as CertAddEnhancedKeyUsageIdentifier:qword
    extrn '__imp_CertAddRefServerOcspResponse' as CertAddRefServerOcspResponse:qword
    extrn '__imp_CertAddRefServerOcspResponseContext' as CertAddRefServerOcspResponseContext:qword
    extrn '__imp_CertAddSerializedElementToStore' as CertAddSerializedElementToStore:qword
    extrn '__imp_CertAddStoreToCollection' as CertAddStoreToCollection:qword
    extrn '__imp_CertAlgIdToOID' as CertAlgIdToOID:qword
    extrn '__imp_CertCloseServerOcspResponse' as CertCloseServerOcspResponse:qword
    extrn '__imp_CertCloseStore' as CertCloseStore:qword
    extrn '__imp_CertCompareCertificate' as CertCompareCertificate:qword
    extrn '__imp_CertCompareCertificateName' as CertCompareCertificateName:qword
    extrn '__imp_CertCompareIntegerBlob' as CertCompareIntegerBlob:qword
    extrn '__imp_CertComparePublicKeyInfo' as CertComparePublicKeyInfo:qword
    extrn '__imp_CertControlStore' as CertControlStore:qword
    extrn '__imp_CertCreateCRLContext' as CertCreateCRLContext:qword
    extrn '__imp_CertCreateCTLContext' as CertCreateCTLContext:qword
    extrn '__imp_CertCreateCTLEntryFromCertificateContextProperties' as CertCreateCTLEntryFromCertificateContextProperties:qword
    extrn '__imp_CertCreateCertificateChainEngine' as CertCreateCertificateChainEngine:qword
    extrn '__imp_CertCreateCertificateContext' as CertCreateCertificateContext:qword
    extrn '__imp_CertCreateContext' as CertCreateContext:qword
    extrn '__imp_CertCreateSelfSignCertificate' as CertCreateSelfSignCertificate:qword
    extrn '__imp_CertDeleteCRLFromStore' as CertDeleteCRLFromStore:qword
    extrn '__imp_CertDeleteCTLFromStore' as CertDeleteCTLFromStore:qword
    extrn '__imp_CertDeleteCertificateFromStore' as CertDeleteCertificateFromStore:qword
    extrn '__imp_CertDuplicateCRLContext' as CertDuplicateCRLContext:qword
    extrn '__imp_CertDuplicateCTLContext' as CertDuplicateCTLContext:qword
    extrn '__imp_CertDuplicateCertificateChain' as CertDuplicateCertificateChain:qword
    extrn '__imp_CertDuplicateCertificateContext' as CertDuplicateCertificateContext:qword
    extrn '__imp_CertDuplicateStore' as CertDuplicateStore:qword
    extrn '__imp_CertEnumCRLContextProperties' as CertEnumCRLContextProperties:qword
    extrn '__imp_CertEnumCRLsInStore' as CertEnumCRLsInStore:qword
    extrn '__imp_CertEnumCTLContextProperties' as CertEnumCTLContextProperties:qword
    extrn '__imp_CertEnumCTLsInStore' as CertEnumCTLsInStore:qword
    extrn '__imp_CertEnumCertificateContextProperties' as CertEnumCertificateContextProperties:qword
    extrn '__imp_CertEnumCertificatesInStore' as CertEnumCertificatesInStore:qword
    extrn '__imp_CertEnumPhysicalStore' as CertEnumPhysicalStore:qword
    extrn '__imp_CertEnumSubjectInSortedCTL' as CertEnumSubjectInSortedCTL:qword
    extrn '__imp_CertEnumSystemStore' as CertEnumSystemStore:qword
    extrn '__imp_CertEnumSystemStoreLocation' as CertEnumSystemStoreLocation:qword
    extrn '__imp_CertFindAttribute' as CertFindAttribute:qword
    extrn '__imp_CertFindCRLInStore' as CertFindCRLInStore:qword
    extrn '__imp_CertFindCTLInStore' as CertFindCTLInStore:qword
    extrn '__imp_CertFindCertificateInCRL' as CertFindCertificateInCRL:qword
    extrn '__imp_CertFindCertificateInStore' as CertFindCertificateInStore:qword
    extrn '__imp_CertFindChainInStore' as CertFindChainInStore:qword
    extrn '__imp_CertFindExtension' as CertFindExtension:qword
    extrn '__imp_CertFindRDNAttr' as CertFindRDNAttr:qword
    extrn '__imp_CertFindSubjectInCTL' as CertFindSubjectInCTL:qword
    extrn '__imp_CertFindSubjectInSortedCTL' as CertFindSubjectInSortedCTL:qword
    extrn '__imp_CertFreeCRLContext' as CertFreeCRLContext:qword
    extrn '__imp_CertFreeCTLContext' as CertFreeCTLContext:qword
    extrn '__imp_CertFreeCertificateChain' as CertFreeCertificateChain:qword
    extrn '__imp_CertFreeCertificateChainEngine' as CertFreeCertificateChainEngine:qword
    extrn '__imp_CertFreeCertificateChainList' as CertFreeCertificateChainList:qword
    extrn '__imp_CertFreeCertificateContext' as CertFreeCertificateContext:qword
    extrn '__imp_CertFreeServerOcspResponseContext' as CertFreeServerOcspResponseContext:qword
    extrn '__imp_CertGetCRLContextProperty' as CertGetCRLContextProperty:qword
    extrn '__imp_CertGetCRLFromStore' as CertGetCRLFromStore:qword
    extrn '__imp_CertGetCTLContextProperty' as CertGetCTLContextProperty:qword
    extrn '__imp_CertGetCertificateChain' as CertGetCertificateChain:qword
    extrn '__imp_CertGetCertificateContextProperty' as CertGetCertificateContextProperty:qword
    extrn '__imp_CertGetEnhancedKeyUsage' as CertGetEnhancedKeyUsage:qword
    extrn '__imp_CertGetIntendedKeyUsage' as CertGetIntendedKeyUsage:qword
    extrn '__imp_CertGetIssuerCertificateFromStore' as CertGetIssuerCertificateFromStore:qword
    extrn '__imp_CertGetNameStringA' as CertGetNameStringA:qword
    extrn '__imp_CertGetNameStringW' as CertGetNameStringW:qword
    extrn '__imp_CertGetPublicKeyLength' as CertGetPublicKeyLength:qword
    extrn '__imp_CertGetServerOcspResponseContext' as CertGetServerOcspResponseContext:qword
    extrn '__imp_CertGetStoreProperty' as CertGetStoreProperty:qword
    extrn '__imp_CertGetSubjectCertificateFromStore' as CertGetSubjectCertificateFromStore:qword
    extrn '__imp_CertGetValidUsages' as CertGetValidUsages:qword
    extrn '__imp_CertIsRDNAttrsInCertificateName' as CertIsRDNAttrsInCertificateName:qword
    extrn '__imp_CertIsStrongHashToSign' as CertIsStrongHashToSign:qword
    extrn '__imp_CertIsValidCRLForCertificate' as CertIsValidCRLForCertificate:qword
    if NTDDI_VERSION >= NTDDI_WIN10
        extrn '__imp_CertIsWeakHash' as CertIsWeakHash:qword
    end if
    extrn '__imp_CertNameToStrA' as CertNameToStrA:qword
    extrn '__imp_CertNameToStrW' as CertNameToStrW:qword
    extrn '__imp_CertOIDToAlgId' as CertOIDToAlgId:qword
    extrn '__imp_CertOpenServerOcspResponse' as CertOpenServerOcspResponse:qword
    extrn '__imp_CertOpenStore' as CertOpenStore:qword
    extrn '__imp_CertOpenSystemStoreA' as CertOpenSystemStoreA:qword
    extrn '__imp_CertOpenSystemStoreW' as CertOpenSystemStoreW:qword
    extrn '__imp_CertRDNValueToStrA' as CertRDNValueToStrA:qword
    extrn '__imp_CertRDNValueToStrW' as CertRDNValueToStrW:qword
    extrn '__imp_CertRegisterPhysicalStore' as CertRegisterPhysicalStore:qword
    extrn '__imp_CertRegisterSystemStore' as CertRegisterSystemStore:qword
    extrn '__imp_CertRemoveEnhancedKeyUsageIdentifier' as CertRemoveEnhancedKeyUsageIdentifier:qword
    extrn '__imp_CertRemoveStoreFromCollection' as CertRemoveStoreFromCollection:qword
    extrn '__imp_CertResyncCertificateChainEngine' as CertResyncCertificateChainEngine:qword
    extrn '__imp_CertRetrieveLogoOrBiometricInfo' as CertRetrieveLogoOrBiometricInfo:qword
    extrn '__imp_CertSaveStore' as CertSaveStore:qword
    extrn '__imp_CertSelectCertificateChains' as CertSelectCertificateChains:qword
    extrn '__imp_CertSerializeCRLStoreElement' as CertSerializeCRLStoreElement:qword
    extrn '__imp_CertSerializeCTLStoreElement' as CertSerializeCTLStoreElement:qword
    extrn '__imp_CertSerializeCertificateStoreElement' as CertSerializeCertificateStoreElement:qword
    extrn '__imp_CertSetCRLContextProperty' as CertSetCRLContextProperty:qword
    extrn '__imp_CertSetCTLContextProperty' as CertSetCTLContextProperty:qword
    extrn '__imp_CertSetCertificateContextPropertiesFromCTLEntry' as CertSetCertificateContextPropertiesFromCTLEntry:qword
    extrn '__imp_CertSetCertificateContextProperty' as CertSetCertificateContextProperty:qword
    extrn '__imp_CertSetEnhancedKeyUsage' as CertSetEnhancedKeyUsage:qword
    extrn '__imp_CertSetStoreProperty' as CertSetStoreProperty:qword
    extrn '__imp_CertStrToNameA' as CertStrToNameA:qword
    extrn '__imp_CertStrToNameW' as CertStrToNameW:qword
    extrn '__imp_CertUnregisterPhysicalStore' as CertUnregisterPhysicalStore:qword
    extrn '__imp_CertUnregisterSystemStore' as CertUnregisterSystemStore:qword
    extrn '__imp_CertVerifyCRLRevocation' as CertVerifyCRLRevocation:qword
    extrn '__imp_CertVerifyCRLTimeValidity' as CertVerifyCRLTimeValidity:qword
    extrn '__imp_CertVerifyCTLUsage' as CertVerifyCTLUsage:qword
    extrn '__imp_CertVerifyCertificateChainPolicy' as CertVerifyCertificateChainPolicy:qword
    extrn '__imp_CertVerifyRevocation' as CertVerifyRevocation:qword
    extrn '__imp_CertVerifySubjectCertificateContext' as CertVerifySubjectCertificateContext:qword
    extrn '__imp_CertVerifyTimeValidity' as CertVerifyTimeValidity:qword
    extrn '__imp_CertVerifyValidityNesting' as CertVerifyValidityNesting:qword
    extrn '__imp_CryptAcquireCertificatePrivateKey' as CryptAcquireCertificatePrivateKey:qword
    extrn '__imp_CryptBinaryToStringA' as CryptBinaryToStringA:qword
    extrn '__imp_CryptBinaryToStringW' as CryptBinaryToStringW:qword
    extrn '__imp_CryptCloseAsyncHandle' as CryptCloseAsyncHandle:qword
    extrn '__imp_CryptCreateAsyncHandle' as CryptCreateAsyncHandle:qword
    extrn '__imp_CryptCreateKeyIdentifierFromCSP' as CryptCreateKeyIdentifierFromCSP:qword
    extrn '__imp_CryptDecodeMessage' as CryptDecodeMessage:qword
    extrn '__imp_CryptDecodeObject' as CryptDecodeObject:qword
    extrn '__imp_CryptDecodeObjectEx' as CryptDecodeObjectEx:qword
    extrn '__imp_CryptDecryptAndVerifyMessageSignature' as CryptDecryptAndVerifyMessageSignature:qword
    extrn '__imp_CryptDecryptMessage' as CryptDecryptMessage:qword
    extrn '__imp_CryptEncodeObject' as CryptEncodeObject:qword
    extrn '__imp_CryptEncodeObjectEx' as CryptEncodeObjectEx:qword
    extrn '__imp_CryptEncryptMessage' as CryptEncryptMessage:qword
    extrn '__imp_CryptEnumKeyIdentifierProperties' as CryptEnumKeyIdentifierProperties:qword
    extrn '__imp_CryptEnumOIDFunction' as CryptEnumOIDFunction:qword
    extrn '__imp_CryptEnumOIDInfo' as CryptEnumOIDInfo:qword
    extrn '__imp_CryptExportPKCS8' as CryptExportPKCS8:qword
    extrn '__imp_CryptExportPublicKeyInfo' as CryptExportPublicKeyInfo:qword
    extrn '__imp_CryptExportPublicKeyInfoEx' as CryptExportPublicKeyInfoEx:qword
    extrn '__imp_CryptExportPublicKeyInfoFromBCryptKeyHandle' as CryptExportPublicKeyInfoFromBCryptKeyHandle:qword
    extrn '__imp_CryptFindCertificateKeyProvInfo' as CryptFindCertificateKeyProvInfo:qword
    extrn '__imp_CryptFindLocalizedName' as CryptFindLocalizedName:qword
    extrn '__imp_CryptFindOIDInfo' as CryptFindOIDInfo:qword
    extrn '__imp_CryptFormatObject' as CryptFormatObject:qword
    extrn '__imp_CryptFreeOIDFunctionAddress' as CryptFreeOIDFunctionAddress:qword
    extrn '__imp_CryptGetAsyncParam' as CryptGetAsyncParam:qword
    extrn '__imp_CryptGetDefaultOIDDllList' as CryptGetDefaultOIDDllList:qword
    extrn '__imp_CryptGetDefaultOIDFunctionAddress' as CryptGetDefaultOIDFunctionAddress:qword
    extrn '__imp_CryptGetKeyIdentifierProperty' as CryptGetKeyIdentifierProperty:qword
    extrn '__imp_CryptGetMessageCertificates' as CryptGetMessageCertificates:qword
    extrn '__imp_CryptGetMessageSignerCount' as CryptGetMessageSignerCount:qword
    extrn '__imp_CryptGetOIDFunctionAddress' as CryptGetOIDFunctionAddress:qword
    extrn '__imp_CryptGetOIDFunctionValue' as CryptGetOIDFunctionValue:qword
    extrn '__imp_CryptHashCertificate' as CryptHashCertificate:qword
    extrn '__imp_CryptHashCertificate2' as CryptHashCertificate2:qword
    extrn '__imp_CryptHashMessage' as CryptHashMessage:qword
    extrn '__imp_CryptHashPublicKeyInfo' as CryptHashPublicKeyInfo:qword
    extrn '__imp_CryptHashToBeSigned' as CryptHashToBeSigned:qword
    extrn '__imp_CryptImportPKCS8' as CryptImportPKCS8:qword
    extrn '__imp_CryptImportPublicKeyInfo' as CryptImportPublicKeyInfo:qword
    extrn '__imp_CryptImportPublicKeyInfoEx' as CryptImportPublicKeyInfoEx:qword
    extrn '__imp_CryptImportPublicKeyInfoEx2' as CryptImportPublicKeyInfoEx2:qword
    extrn '__imp_CryptInitOIDFunctionSet' as CryptInitOIDFunctionSet:qword
    extrn '__imp_CryptInstallDefaultContext' as CryptInstallDefaultContext:qword
    extrn '__imp_CryptInstallOIDFunctionAddress' as CryptInstallOIDFunctionAddress:qword
    extrn '__imp_CryptLoadSip' as CryptLoadSip:qword
    extrn '__imp_CryptMemAlloc' as CryptMemAlloc:qword
    extrn '__imp_CryptMemFree' as CryptMemFree:qword
    extrn '__imp_CryptMemRealloc' as CryptMemRealloc:qword
    extrn '__imp_CryptMsgCalculateEncodedLength' as CryptMsgCalculateEncodedLength:qword
    extrn '__imp_CryptMsgClose' as CryptMsgClose:qword
    extrn '__imp_CryptMsgControl' as CryptMsgControl:qword
    extrn '__imp_CryptMsgCountersign' as CryptMsgCountersign:qword
    extrn '__imp_CryptMsgCountersignEncoded' as CryptMsgCountersignEncoded:qword
    extrn '__imp_CryptMsgDuplicate' as CryptMsgDuplicate:qword
    extrn '__imp_CryptMsgEncodeAndSignCTL' as CryptMsgEncodeAndSignCTL:qword
    extrn '__imp_CryptMsgGetAndVerifySigner' as CryptMsgGetAndVerifySigner:qword
    extrn '__imp_CryptMsgGetParam' as CryptMsgGetParam:qword
    extrn '__imp_CryptMsgOpenToDecode' as CryptMsgOpenToDecode:qword
    extrn '__imp_CryptMsgOpenToEncode' as CryptMsgOpenToEncode:qword
    extrn '__imp_CryptMsgSignCTL' as CryptMsgSignCTL:qword
    extrn '__imp_CryptMsgUpdate' as CryptMsgUpdate:qword
    extrn '__imp_CryptMsgVerifyCountersignatureEncoded' as CryptMsgVerifyCountersignatureEncoded:qword
    extrn '__imp_CryptMsgVerifyCountersignatureEncodedEx' as CryptMsgVerifyCountersignatureEncodedEx:qword
    extrn '__imp_CryptProtectData' as CryptProtectData:qword
    extrn '__imp_CryptProtectMemory' as CryptProtectMemory:qword
    extrn '__imp_CryptQueryObject' as CryptQueryObject:qword
    extrn '__imp_CryptRegisterDefaultOIDFunction' as CryptRegisterDefaultOIDFunction:qword
    extrn '__imp_CryptRegisterOIDFunction' as CryptRegisterOIDFunction:qword
    extrn '__imp_CryptRegisterOIDInfo' as CryptRegisterOIDInfo:qword
    extrn '__imp_CryptRetrieveTimeStamp' as CryptRetrieveTimeStamp:qword
    extrn '__imp_CryptSIPAddProvider' as CryptSIPAddProvider:qword
    extrn '__imp_CryptSIPCreateIndirectData' as CryptSIPCreateIndirectData:qword
    if NTDDI_VERSION >= NTDDI_WIN8
        extrn '__imp_CryptSIPGetCaps' as CryptSIPGetCaps:qword
    end if
    extrn '__imp_CryptSIPGetSignedDataMsg' as CryptSIPGetSignedDataMsg:qword
    extrn '__imp_CryptSIPLoad' as CryptSIPLoad:qword
    extrn '__imp_CryptSIPPutSignedDataMsg' as CryptSIPPutSignedDataMsg:qword
    extrn '__imp_CryptSIPRemoveProvider' as CryptSIPRemoveProvider:qword
    extrn '__imp_CryptSIPRemoveSignedDataMsg' as CryptSIPRemoveSignedDataMsg:qword
    extrn '__imp_CryptSIPRetrieveSubjectGuid' as CryptSIPRetrieveSubjectGuid:qword
    extrn '__imp_CryptSIPRetrieveSubjectGuidForCatalogFile' as CryptSIPRetrieveSubjectGuidForCatalogFile:qword
    extrn '__imp_CryptSIPVerifyIndirectData' as CryptSIPVerifyIndirectData:qword
    extrn '__imp_CryptSetAsyncParam' as CryptSetAsyncParam:qword
    extrn '__imp_CryptSetKeyIdentifierProperty' as CryptSetKeyIdentifierProperty:qword
    extrn '__imp_CryptSetOIDFunctionValue' as CryptSetOIDFunctionValue:qword
    extrn '__imp_CryptSignAndEncodeCertificate' as CryptSignAndEncodeCertificate:qword
    extrn '__imp_CryptSignAndEncryptMessage' as CryptSignAndEncryptMessage:qword
    extrn '__imp_CryptSignCertificate' as CryptSignCertificate:qword
    extrn '__imp_CryptSignMessage' as CryptSignMessage:qword
    extrn '__imp_CryptSignMessageWithKey' as CryptSignMessageWithKey:qword
    extrn '__imp_CryptStringToBinaryA' as CryptStringToBinaryA:qword
    extrn '__imp_CryptStringToBinaryW' as CryptStringToBinaryW:qword
    extrn '__imp_CryptUninstallDefaultContext' as CryptUninstallDefaultContext:qword
    extrn '__imp_CryptUnprotectData' as CryptUnprotectData:qword
    extrn '__imp_CryptUnprotectMemory' as CryptUnprotectMemory:qword
    extrn '__imp_CryptUnregisterDefaultOIDFunction' as CryptUnregisterDefaultOIDFunction:qword
    extrn '__imp_CryptUnregisterOIDFunction' as CryptUnregisterOIDFunction:qword
    extrn '__imp_CryptUnregisterOIDInfo' as CryptUnregisterOIDInfo:qword
    extrn '__imp_CryptUpdateProtectedState' as CryptUpdateProtectedState:qword
    extrn '__imp_CryptVerifyCertificateSignature' as CryptVerifyCertificateSignature:qword
    extrn '__imp_CryptVerifyCertificateSignatureEx' as CryptVerifyCertificateSignatureEx:qword
    extrn '__imp_CryptVerifyDetachedMessageHash' as CryptVerifyDetachedMessageHash:qword
    extrn '__imp_CryptVerifyDetachedMessageSignature' as CryptVerifyDetachedMessageSignature:qword
    extrn '__imp_CryptVerifyMessageHash' as CryptVerifyMessageHash:qword
    extrn '__imp_CryptVerifyMessageSignature' as CryptVerifyMessageSignature:qword
    extrn '__imp_CryptVerifyMessageSignatureWithKey' as CryptVerifyMessageSignatureWithKey:qword
    extrn '__imp_CryptVerifyTimeStampSignature' as CryptVerifyTimeStampSignature:qword
    extrn '__imp_I_CertProtectFunction' as I_CertProtectFunction:qword
    extrn '__imp_I_CertSrvProtectFunction' as I_CertSrvProtectFunction:qword
    extrn '__imp_I_CertSyncStore' as I_CertSyncStore:qword
    extrn '__imp_I_CertUpdateStore' as I_CertUpdateStore:qword
    extrn '__imp_I_CryptAddRefLruEntry' as I_CryptAddRefLruEntry:qword
    extrn '__imp_I_CryptAddSmartCardCertToStore' as I_CryptAddSmartCardCertToStore:qword
    extrn '__imp_I_CryptAllocTls' as I_CryptAllocTls:qword
    extrn '__imp_I_CryptCreateLruCache' as I_CryptCreateLruCache:qword
    extrn '__imp_I_CryptCreateLruEntry' as I_CryptCreateLruEntry:qword
    extrn '__imp_I_CryptDetachTls' as I_CryptDetachTls:qword
    extrn '__imp_I_CryptDisableLruOfEntries' as I_CryptDisableLruOfEntries:qword
    extrn '__imp_I_CryptEnableLruOfEntries' as I_CryptEnableLruOfEntries:qword
    extrn '__imp_I_CryptEnumMatchingLruEntries' as I_CryptEnumMatchingLruEntries:qword
    extrn '__imp_I_CryptFindLruEntry' as I_CryptFindLruEntry:qword
    extrn '__imp_I_CryptFindLruEntryData' as I_CryptFindLruEntryData:qword
    extrn '__imp_I_CryptFindSmartCardCertInStore' as I_CryptFindSmartCardCertInStore:qword
    extrn '__imp_I_CryptFlushLruCache' as I_CryptFlushLruCache:qword
    extrn '__imp_I_CryptFreeLruCache' as I_CryptFreeLruCache:qword
    extrn '__imp_I_CryptFreeTls' as I_CryptFreeTls:qword
    extrn '__imp_I_CryptGetAsn1Decoder' as I_CryptGetAsn1Decoder:qword
    extrn '__imp_I_CryptGetAsn1Encoder' as I_CryptGetAsn1Encoder:qword
    extrn '__imp_I_CryptGetDefaultCryptProv' as I_CryptGetDefaultCryptProv:qword
    extrn '__imp_I_CryptGetDefaultCryptProvForEncrypt' as I_CryptGetDefaultCryptProvForEncrypt:qword
    extrn '__imp_I_CryptGetFileVersion' as I_CryptGetFileVersion:qword
    extrn '__imp_I_CryptGetLruEntryData' as I_CryptGetLruEntryData:qword
    extrn '__imp_I_CryptGetLruEntryIdentifier' as I_CryptGetLruEntryIdentifier:qword
    extrn '__imp_I_CryptGetOssGlobal' as I_CryptGetOssGlobal:qword
    extrn '__imp_I_CryptGetTls' as I_CryptGetTls:qword
    extrn '__imp_I_CryptInsertLruEntry' as I_CryptInsertLruEntry:qword
    extrn '__imp_I_CryptInstallAsn1Module' as I_CryptInstallAsn1Module:qword
    extrn '__imp_I_CryptInstallOssGlobal' as I_CryptInstallOssGlobal:qword
    extrn '__imp_I_CryptReadTrustedPublisherDWORDValueFromRegistry' as I_CryptReadTrustedPublisherDWORDValueFromRegistry:qword
    extrn '__imp_I_CryptRegisterSmartCardStore' as I_CryptRegisterSmartCardStore:qword
    extrn '__imp_I_CryptReleaseLruEntry' as I_CryptReleaseLruEntry:qword
    extrn '__imp_I_CryptRemoveLruEntry' as I_CryptRemoveLruEntry:qword
    extrn '__imp_I_CryptSetTls' as I_CryptSetTls:qword
    extrn '__imp_I_CryptTouchLruEntry' as I_CryptTouchLruEntry:qword
    extrn '__imp_I_CryptUninstallAsn1Module' as I_CryptUninstallAsn1Module:qword
    extrn '__imp_I_CryptUninstallOssGlobal' as I_CryptUninstallOssGlobal:qword
    extrn '__imp_I_CryptUnregisterSmartCardStore' as I_CryptUnregisterSmartCardStore:qword
    extrn '__imp_I_CryptWalkAllLruCacheEntries' as I_CryptWalkAllLruCacheEntries:qword
    extrn '__imp_PFXExportCertStore' as PFXExportCertStore:qword
    extrn '__imp_PFXExportCertStore2' as PFXExportCertStore2:qword
    extrn '__imp_PFXExportCertStoreEx' as PFXExportCertStoreEx:qword
    extrn '__imp_PFXImportCertStore' as PFXImportCertStore:qword
    extrn '__imp_PFXIsPFXBlob' as PFXIsPFXBlob:qword
    extrn '__imp_PFXVerifyPassword' as PFXVerifyPassword:qword
else
    extrn '__imp__CertAddCRLContextToStore@16' as CertAddCRLContextToStore:dword
    extrn '__imp__CertAddCRLLinkToStore@16' as CertAddCRLLinkToStore:dword
    extrn '__imp__CertAddCTLContextToStore@16' as CertAddCTLContextToStore:dword
    extrn '__imp__CertAddCTLLinkToStore@16' as CertAddCTLLinkToStore:dword
    extrn '__imp__CertAddCertificateContextToStore@16' as CertAddCertificateContextToStore:dword
    extrn '__imp__CertAddCertificateLinkToStore@16' as CertAddCertificateLinkToStore:dword
    extrn '__imp__CertAddEncodedCRLToStore@24' as CertAddEncodedCRLToStore:dword
    extrn '__imp__CertAddEncodedCTLToStore@24' as CertAddEncodedCTLToStore:dword
    extrn '__imp__CertAddEncodedCertificateToStore@24' as CertAddEncodedCertificateToStore:dword
    extrn '__imp__CertAddEncodedCertificateToSystemStoreA@12' as CertAddEncodedCertificateToSystemStoreA:dword
    extrn '__imp__CertAddEncodedCertificateToSystemStoreW@12' as CertAddEncodedCertificateToSystemStoreW:dword
    extrn '__imp__CertAddEnhancedKeyUsageIdentifier@8' as CertAddEnhancedKeyUsageIdentifier:dword
    ;extrn '__imp__CertAddRefServerOcspResponse@4' as CertAddRefServerOcspResponse:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__CertAddRefServerOcspResponseContext@4' as CertAddRefServerOcspResponseContext:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertAddSerializedElementToStore@32' as CertAddSerializedElementToStore:dword
    extrn '__imp__CertAddStoreToCollection@16' as CertAddStoreToCollection:dword
    extrn '__imp__CertAlgIdToOID@4' as CertAlgIdToOID:dword
    ;extrn '__imp__CertCloseServerOcspResponse@8' as CertCloseServerOcspResponse:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertCloseStore@8' as CertCloseStore:dword
    extrn '__imp__CertCompareCertificate@12' as CertCompareCertificate:dword
    extrn '__imp__CertCompareCertificateName@12' as CertCompareCertificateName:dword
    extrn '__imp__CertCompareIntegerBlob@8' as CertCompareIntegerBlob:dword
    extrn '__imp__CertComparePublicKeyInfo@12' as CertComparePublicKeyInfo:dword
    extrn '__imp__CertControlStore@16' as CertControlStore:dword
    extrn '__imp__CertCreateCRLContext@12' as CertCreateCRLContext:dword
    extrn '__imp__CertCreateCTLContext@12' as CertCreateCTLContext:dword
    extrn '__imp__CertCreateCTLEntryFromCertificateContextProperties@28' as CertCreateCTLEntryFromCertificateContextProperties:dword
    extrn '__imp__CertCreateCertificateChainEngine@8' as CertCreateCertificateChainEngine:dword
    extrn '__imp__CertCreateCertificateContext@12' as CertCreateCertificateContext:dword
    extrn '__imp__CertCreateContext@24' as CertCreateContext:dword
    extrn '__imp__CertCreateSelfSignCertificate@32' as CertCreateSelfSignCertificate:dword
    extrn '__imp__CertDeleteCRLFromStore@4' as CertDeleteCRLFromStore:dword
    extrn '__imp__CertDeleteCTLFromStore@4' as CertDeleteCTLFromStore:dword
    extrn '__imp__CertDeleteCertificateFromStore@4' as CertDeleteCertificateFromStore:dword
    extrn '__imp__CertDuplicateCRLContext@4' as CertDuplicateCRLContext:dword
    extrn '__imp__CertDuplicateCTLContext@4' as CertDuplicateCTLContext:dword
    extrn '__imp__CertDuplicateCertificateChain@4' as CertDuplicateCertificateChain:dword
    extrn '__imp__CertDuplicateCertificateContext@4' as CertDuplicateCertificateContext:dword
    extrn '__imp__CertDuplicateStore@4' as CertDuplicateStore:dword
    extrn '__imp__CertEnumCRLContextProperties@8' as CertEnumCRLContextProperties:dword
    extrn '__imp__CertEnumCRLsInStore@8' as CertEnumCRLsInStore:dword
    extrn '__imp__CertEnumCTLContextProperties@8' as CertEnumCTLContextProperties:dword
    extrn '__imp__CertEnumCTLsInStore@8' as CertEnumCTLsInStore:dword
    extrn '__imp__CertEnumCertificateContextProperties@8' as CertEnumCertificateContextProperties:dword
    extrn '__imp__CertEnumCertificatesInStore@8' as CertEnumCertificatesInStore:dword
    extrn '__imp__CertEnumPhysicalStore@16' as CertEnumPhysicalStore:dword
    extrn '__imp__CertEnumSubjectInSortedCTL@16' as CertEnumSubjectInSortedCTL:dword
    extrn '__imp__CertEnumSystemStore@16' as CertEnumSystemStore:dword
    extrn '__imp__CertEnumSystemStoreLocation@12' as CertEnumSystemStoreLocation:dword
    extrn '__imp__CertFindAttribute@12' as CertFindAttribute:dword
    extrn '__imp__CertFindCRLInStore@24' as CertFindCRLInStore:dword
    extrn '__imp__CertFindCTLInStore@24' as CertFindCTLInStore:dword
    extrn '__imp__CertFindCertificateInCRL@20' as CertFindCertificateInCRL:dword
    extrn '__imp__CertFindCertificateInStore@24' as CertFindCertificateInStore:dword
    extrn '__imp__CertFindChainInStore@24' as CertFindChainInStore:dword
    extrn '__imp__CertFindExtension@12' as CertFindExtension:dword
    extrn '__imp__CertFindRDNAttr@8' as CertFindRDNAttr:dword
    extrn '__imp__CertFindSubjectInCTL@20' as CertFindSubjectInCTL:dword
    extrn '__imp__CertFindSubjectInSortedCTL@20' as CertFindSubjectInSortedCTL:dword
    extrn '__imp__CertFreeCRLContext@4' as CertFreeCRLContext:dword
    extrn '__imp__CertFreeCTLContext@4' as CertFreeCTLContext:dword
    extrn '__imp__CertFreeCertificateChain@4' as CertFreeCertificateChain:dword
    extrn '__imp__CertFreeCertificateChainEngine@4' as CertFreeCertificateChainEngine:dword
    ;extrn '__imp__CertFreeCertificateChainList@4' as CertFreeCertificateChainList:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertFreeCertificateContext@4' as CertFreeCertificateContext:dword
    ;extrn '__imp__CertFreeServerOcspResponseContext@4' as CertFreeServerOcspResponseContext:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertGetCRLContextProperty@16' as CertGetCRLContextProperty:dword
    extrn '__imp__CertGetCRLFromStore@16' as CertGetCRLFromStore:dword
    extrn '__imp__CertGetCTLContextProperty@16' as CertGetCTLContextProperty:dword
    extrn '__imp__CertGetCertificateChain@32' as CertGetCertificateChain:dword
    extrn '__imp__CertGetCertificateContextProperty@16' as CertGetCertificateContextProperty:dword
    extrn '__imp__CertGetEnhancedKeyUsage@16' as CertGetEnhancedKeyUsage:dword
    extrn '__imp__CertGetIntendedKeyUsage@16' as CertGetIntendedKeyUsage:dword
    extrn '__imp__CertGetIssuerCertificateFromStore@16' as CertGetIssuerCertificateFromStore:dword
    extrn '__imp__CertGetNameStringA@24' as CertGetNameStringA:dword
    extrn '__imp__CertGetNameStringW@24' as CertGetNameStringW:dword
    extrn '__imp__CertGetPublicKeyLength@8' as CertGetPublicKeyLength:dword
    ;extrn '__imp__CertGetServerOcspResponseContext@12' as CertGetServerOcspResponseContext:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertGetStoreProperty@16' as CertGetStoreProperty:dword
    extrn '__imp__CertGetSubjectCertificateFromStore@12' as CertGetSubjectCertificateFromStore:dword
    extrn '__imp__CertGetValidUsages@20' as CertGetValidUsages:dword
    extrn '__imp__CertIsRDNAttrsInCertificateName@16' as CertIsRDNAttrsInCertificateName:dword
    ;extrn '__imp__CertIsStrongHashToSign@12' as CertIsStrongHashToSign:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertIsValidCRLForCertificate@16' as CertIsValidCRLForCertificate:dword
    if NTDDI_VERSION >= NTDDI_WIN10
        extrn '__imp__CertIsWeakHash@16' as CertIsValidCRLForCertificate:dword
    end if
    extrn '__imp__CertNameToStrA@20' as CertNameToStrA:dword
    extrn '__imp__CertNameToStrW@20' as CertNameToStrW:dword
    extrn '__imp__CertOIDToAlgId@4' as CertOIDToAlgId:dword
    ;extrn '__imp__CertOpenServerOcspResponse@12' as CertOpenServerOcspResponse:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertOpenStore@20' as CertOpenStore:dword
    extrn '__imp__CertOpenSystemStoreA@8' as CertOpenSystemStoreA:dword
    extrn '__imp__CertOpenSystemStoreW@8' as CertOpenSystemStoreW:dword
    ;extrn '__imp__CertRDNValueToStrA@8' as CertRDNValueToStrA:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__CertRDNValueToStrW@8' as CertRDNValueToStrW:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertRegisterPhysicalStore@20' as CertRegisterPhysicalStore:dword
    extrn '__imp__CertRegisterSystemStore@16' as CertRegisterSystemStore:dword
    extrn '__imp__CertRemoveEnhancedKeyUsageIdentifier@8' as CertRemoveEnhancedKeyUsageIdentifier:dword
    extrn '__imp__CertRemoveStoreFromCollection@8' as CertRemoveStoreFromCollection:dword
    extrn '__imp__CertResyncCertificateChainEngine@4' as CertResyncCertificateChainEngine:dword
    ;extrn '__imp__CertRetrieveLogoOrBiometricInfo@36' as CertRetrieveLogoOrBiometricInfo:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertSaveStore@24' as CertSaveStore:dword
    ;extrn '__imp__CertSelectCertificateChains@32' as CertSelectCertificateChains:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CertSerializeCRLStoreElement@16' as CertSerializeCRLStoreElement:dword
    extrn '__imp__CertSerializeCTLStoreElement@16' as CertSerializeCTLStoreElement:dword
    extrn '__imp__CertSerializeCertificateStoreElement@16' as CertSerializeCertificateStoreElement:dword
    extrn '__imp__CertSetCRLContextProperty@16' as CertSetCRLContextProperty:dword
    extrn '__imp__CertSetCTLContextProperty@16' as CertSetCTLContextProperty:dword
    extrn '__imp__CertSetCertificateContextPropertiesFromCTLEntry@12' as CertSetCertificateContextPropertiesFromCTLEntry:dword
    extrn '__imp__CertSetCertificateContextProperty@16' as CertSetCertificateContextProperty:dword
    extrn '__imp__CertSetEnhancedKeyUsage@8' as CertSetEnhancedKeyUsage:dword
    extrn '__imp__CertSetStoreProperty@16' as CertSetStoreProperty:dword
    extrn '__imp__CertStrToNameA@28' as CertStrToNameA:dword
    extrn '__imp__CertStrToNameW@28' as CertStrToNameW:dword
    extrn '__imp__CertUnregisterPhysicalStore@12' as CertUnregisterPhysicalStore:dword
    extrn '__imp__CertUnregisterSystemStore@8' as CertUnregisterSystemStore:dword
    extrn '__imp__CertVerifyCRLRevocation@16' as CertVerifyCRLRevocation:dword
    extrn '__imp__CertVerifyCRLTimeValidity@8' as CertVerifyCRLTimeValidity:dword
    extrn '__imp__CertVerifyCTLUsage@28' as CertVerifyCTLUsage:dword
    extrn '__imp__CertVerifyCertificateChainPolicy@16' as CertVerifyCertificateChainPolicy:dword
    extrn '__imp__CertVerifyRevocation@28' as CertVerifyRevocation:dword
    extrn '__imp__CertVerifySubjectCertificateContext@12' as CertVerifySubjectCertificateContext:dword
    extrn '__imp__CertVerifyTimeValidity@8' as CertVerifyTimeValidity:dword
    extrn '__imp__CertVerifyValidityNesting@8' as CertVerifyValidityNesting:dword
    extrn '__imp__CryptAcquireCertificatePrivateKey@24' as CryptAcquireCertificatePrivateKey:dword
    extrn '__imp__CryptBinaryToStringA@20' as CryptBinaryToStringA:dword
    extrn '__imp__CryptBinaryToStringW@20' as CryptBinaryToStringW:dword
    extrn '__imp__CryptCloseAsyncHandle@4' as CryptCloseAsyncHandle:dword
    extrn '__imp__CryptCreateAsyncHandle@8' as CryptCreateAsyncHandle:dword
    extrn '__imp__CryptCreateKeyIdentifierFromCSP@32' as CryptCreateKeyIdentifierFromCSP:dword
    extrn '__imp__CryptDecodeMessage@52' as CryptDecodeMessage:dword
    extrn '__imp__CryptDecodeObject@28' as CryptDecodeObject:dword
    extrn '__imp__CryptDecodeObjectEx@32' as CryptDecodeObjectEx:dword
    extrn '__imp__CryptDecryptAndVerifyMessageSignature@36' as CryptDecryptAndVerifyMessageSignature:dword
    extrn '__imp__CryptDecryptMessage@24' as CryptDecryptMessage:dword
    extrn '__imp__CryptEncodeObject@20' as CryptEncodeObject:dword
    extrn '__imp__CryptEncodeObjectEx@28' as CryptEncodeObjectEx:dword
    extrn '__imp__CryptEncryptMessage@28' as CryptEncryptMessage:dword
    extrn '__imp__CryptEnumKeyIdentifierProperties@28' as CryptEnumKeyIdentifierProperties:dword
    extrn '__imp__CryptEnumOIDFunction@24' as CryptEnumOIDFunction:dword
    extrn '__imp__CryptEnumOIDInfo@16' as CryptEnumOIDInfo:dword
    extrn '__imp__CryptExportPKCS8@28' as CryptExportPKCS8:dword
    extrn '__imp__CryptExportPublicKeyInfo@20' as CryptExportPublicKeyInfo:dword
    extrn '__imp__CryptExportPublicKeyInfoEx@32' as CryptExportPublicKeyInfoEx:dword
    ;extrn '__imp__CryptExportPublicKeyInfoFromBCryptKeyHandle@28' as CryptExportPublicKeyInfoFromBCryptKeyHandle:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptFindCertificateKeyProvInfo@12' as CryptFindCertificateKeyProvInfo:dword
    extrn '__imp__CryptFindLocalizedName@4' as CryptFindLocalizedName:dword
    extrn '__imp__CryptFindOIDInfo@12' as CryptFindOIDInfo:dword
    extrn '__imp__CryptFormatObject@36' as CryptFormatObject:dword
    extrn '__imp__CryptFreeOIDFunctionAddress@8' as CryptFreeOIDFunctionAddress:dword
    extrn '__imp__CryptGetAsyncParam@16' as CryptGetAsyncParam:dword
    extrn '__imp__CryptGetDefaultOIDDllList@16' as CryptGetDefaultOIDDllList:dword
    extrn '__imp__CryptGetDefaultOIDFunctionAddress@24' as CryptGetDefaultOIDFunctionAddress:dword
    extrn '__imp__CryptGetKeyIdentifierProperty@28' as CryptGetKeyIdentifierProperty:dword
    extrn '__imp__CryptGetMessageCertificates@20' as CryptGetMessageCertificates:dword
    extrn '__imp__CryptGetMessageSignerCount@12' as CryptGetMessageSignerCount:dword
    extrn '__imp__CryptGetOIDFunctionAddress@24' as CryptGetOIDFunctionAddress:dword
    extrn '__imp__CryptGetOIDFunctionValue@28' as CryptGetOIDFunctionValue:dword
    extrn '__imp__CryptHashCertificate@28' as CryptHashCertificate:dword
    ;extrn '__imp__CryptHashCertificate2@28' as CryptHashCertificate2:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptHashMessage@36' as CryptHashMessage:dword
    extrn '__imp__CryptHashPublicKeyInfo@28' as CryptHashPublicKeyInfo:dword
    extrn '__imp__CryptHashToBeSigned@24' as CryptHashToBeSigned:dword
    extrn '__imp__CryptImportPKCS8@36' as CryptImportPKCS8:dword
    extrn '__imp__CryptImportPublicKeyInfo@16' as CryptImportPublicKeyInfo:dword
    extrn '__imp__CryptImportPublicKeyInfoEx@28' as CryptImportPublicKeyInfoEx:dword
    ;extrn '__imp__CryptImportPublicKeyInfoEx2@20' as CryptImportPublicKeyInfoEx2:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptInitOIDFunctionSet@8' as CryptInitOIDFunctionSet:dword
    extrn '__imp__CryptInstallDefaultContext@24' as CryptInstallDefaultContext:dword
    extrn '__imp__CryptInstallOIDFunctionAddress@24' as CryptInstallOIDFunctionAddress:dword
    extrn '__imp__CryptLoadSip@12' as CryptLoadSip:dword
    extrn '__imp__CryptMemAlloc@4' as CryptMemAlloc:dword
    extrn '__imp__CryptMemFree@4' as CryptMemFree:dword
    extrn '__imp__CryptMemRealloc@8' as CryptMemRealloc:dword
    extrn '__imp__CryptMsgCalculateEncodedLength@24' as CryptMsgCalculateEncodedLength:dword
    extrn '__imp__CryptMsgClose@4' as CryptMsgClose:dword
    extrn '__imp__CryptMsgControl@16' as CryptMsgControl:dword
    extrn '__imp__CryptMsgCountersign@16' as CryptMsgCountersign:dword
    extrn '__imp__CryptMsgCountersignEncoded@28' as CryptMsgCountersignEncoded:dword
    extrn '__imp__CryptMsgDuplicate@4' as CryptMsgDuplicate:dword
    extrn '__imp__CryptMsgEncodeAndSignCTL@24' as CryptMsgEncodeAndSignCTL:dword
    extrn '__imp__CryptMsgGetAndVerifySigner@24' as CryptMsgGetAndVerifySigner:dword
    extrn '__imp__CryptMsgGetParam@20' as CryptMsgGetParam:dword
    extrn '__imp__CryptMsgOpenToDecode@24' as CryptMsgOpenToDecode:dword
    extrn '__imp__CryptMsgOpenToEncode@24' as CryptMsgOpenToEncode:dword
    extrn '__imp__CryptMsgSignCTL@28' as CryptMsgSignCTL:dword
    extrn '__imp__CryptMsgUpdate@16' as CryptMsgUpdate:dword
    extrn '__imp__CryptMsgVerifyCountersignatureEncoded@28' as CryptMsgVerifyCountersignatureEncoded:dword
    extrn '__imp__CryptMsgVerifyCountersignatureEncodedEx@40' as CryptMsgVerifyCountersignatureEncodedEx:dword
    extrn '__imp__CryptProtectData@28' as CryptProtectData:dword
    ;extrn '__imp__CryptProtectMemory@12' as CryptProtectMemory:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptQueryObject@44' as CryptQueryObject:dword
    extrn '__imp__CryptRegisterDefaultOIDFunction@16' as CryptRegisterDefaultOIDFunction:dword
    extrn '__imp__CryptRegisterOIDFunction@20' as CryptRegisterOIDFunction:dword
    extrn '__imp__CryptRegisterOIDInfo@8' as CryptRegisterOIDInfo:dword
    ;extrn '__imp__CryptRetrieveTimeStamp@40' as CryptRetrieveTimeStamp:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptSIPAddProvider@4' as CryptSIPAddProvider:dword
    extrn '__imp__CryptSIPCreateIndirectData@12' as CryptSIPCreateIndirectData:dword
    if NTDDI_VERSION >= NTDDI_WIN8
        extrn '__imp__CryptSIPGetCaps@8' as CryptSIPCreateIndirectData:dword
    end if
    extrn '__imp__CryptSIPGetSignedDataMsg@20' as CryptSIPGetSignedDataMsg:dword
    extrn '__imp__CryptSIPLoad@12' as CryptSIPLoad:dword
    extrn '__imp__CryptSIPPutSignedDataMsg@20' as CryptSIPPutSignedDataMsg:dword
    extrn '__imp__CryptSIPRemoveProvider@4' as CryptSIPRemoveProvider:dword
    extrn '__imp__CryptSIPRemoveSignedDataMsg@8' as CryptSIPRemoveSignedDataMsg:dword
    extrn '__imp__CryptSIPRetrieveSubjectGuid@12' as CryptSIPRetrieveSubjectGuid:dword
    extrn '__imp__CryptSIPRetrieveSubjectGuidForCatalogFile@12' as CryptSIPRetrieveSubjectGuidForCatalogFile:dword
    extrn '__imp__CryptSIPVerifyIndirectData@8' as CryptSIPVerifyIndirectData:dword
    extrn '__imp__CryptSetAsyncParam@16' as CryptSetAsyncParam:dword
    extrn '__imp__CryptSetKeyIdentifierProperty@24' as CryptSetKeyIdentifierProperty:dword
    extrn '__imp__CryptSetOIDFunctionValue@28' as CryptSetOIDFunctionValue:dword
    extrn '__imp__CryptSignAndEncodeCertificate@36' as CryptSignAndEncodeCertificate:dword
    extrn '__imp__CryptSignAndEncryptMessage@32' as CryptSignAndEncryptMessage:dword
    extrn '__imp__CryptSignCertificate@36' as CryptSignCertificate:dword
    extrn '__imp__CryptSignMessage@28' as CryptSignMessage:dword
    extrn '__imp__CryptSignMessageWithKey@20' as CryptSignMessageWithKey:dword
    extrn '__imp__CryptStringToBinaryA@28' as CryptStringToBinaryA:dword
    extrn '__imp__CryptStringToBinaryW@28' as CryptStringToBinaryW:dword
    extrn '__imp__CryptUninstallDefaultContext@12' as CryptUninstallDefaultContext:dword
    extrn '__imp__CryptUnprotectData@28' as CryptUnprotectData:dword
    ;extrn '__imp__CryptUnprotectMemory@12' as CryptUnprotectMemory:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptUnregisterDefaultOIDFunction@12' as CryptUnregisterDefaultOIDFunction:dword
    extrn '__imp__CryptUnregisterOIDFunction@12' as CryptUnregisterOIDFunction:dword
    extrn '__imp__CryptUnregisterOIDInfo@4' as CryptUnregisterOIDInfo:dword
    ;extrn '__imp__CryptUpdateProtectedState@20' as CryptUpdateProtectedState:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__CryptVerifyCertificateSignature@20' as CryptVerifyCertificateSignature:dword
    extrn '__imp__CryptVerifyCertificateSignatureEx@32' as CryptVerifyCertificateSignatureEx:dword
    extrn '__imp__CryptVerifyDetachedMessageHash@32' as CryptVerifyDetachedMessageHash:dword
    extrn '__imp__CryptVerifyDetachedMessageSignature@32' as CryptVerifyDetachedMessageSignature:dword
    extrn '__imp__CryptVerifyMessageHash@28' as CryptVerifyMessageHash:dword
    extrn '__imp__CryptVerifyMessageSignature@28' as CryptVerifyMessageSignature:dword
    extrn '__imp__CryptVerifyMessageSignatureWithKey@24' as CryptVerifyMessageSignatureWithKey:dword
    ;extrn '__imp__CryptVerifyTimeStampSignature@32' as CryptVerifyTimeStampSignature:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CertProtectFunction@28' as I_CertProtectFunction:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CertSrvProtectFunction@40' as I_CertSrvProtectFunction:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CertSyncStore@8' as I_CertSyncStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CertUpdateStore@16' as I_CertUpdateStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptAddRefLruEntry@0' as I_CryptAddRefLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptAddSmartCardCertToStore@20' as I_CryptAddSmartCardCertToStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptAllocTls@0' as I_CryptAllocTls:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptCreateLruCache@8' as I_CryptCreateLruCache:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptCreateLruEntry@16' as I_CryptCreateLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptDetachTls@4' as I_CryptDetachTls:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptDisableLruOfEntries@4' as I_CryptDisableLruOfEntries:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptEnableLruOfEntries@8' as I_CryptEnableLruOfEntries:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptEnumMatchingLruEntries@4' as I_CryptEnumMatchingLruEntries:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFindLruEntry@8' as I_CryptFindLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFindLruEntryData@12' as I_CryptFindLruEntryData:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFindSmartCardCertInStore@4' as I_CryptFindSmartCardCertInStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFlushLruCache@12' as I_CryptFlushLruCache:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFreeLruCache@12' as I_CryptFreeLruCache:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptFreeTls@8' as I_CryptFreeTls:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetAsn1Decoder@4' as I_CryptGetAsn1Decoder:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetAsn1Encoder@4' as I_CryptGetAsn1Encoder:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetDefaultCryptProv@4' as I_CryptGetDefaultCryptProv:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetDefaultCryptProvForEncrypt@12' as I_CryptGetDefaultCryptProvForEncrypt:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetFileVersion@12' as I_CryptGetFileVersion:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetLruEntryData@4' as I_CryptGetLruEntryData:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetLruEntryIdentifier@4' as I_CryptGetLruEntryIdentifier:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetOssGlobal@4' as I_CryptGetOssGlobal:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptGetTls@4' as I_CryptGetTls:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptInsertLruEntry@8' as I_CryptInsertLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptInstallAsn1Module@12' as I_CryptInstallAsn1Module:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptInstallOssGlobal@12' as I_CryptInstallOssGlobal:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptReadTrustedPublisherDWORDValueFromRegistry@8' as I_CryptReadTrustedPublisherDWORDValueFromRegistry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptRegisterSmartCardStore@20' as I_CryptRegisterSmartCardStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptReleaseLruEntry@4' as I_CryptReleaseLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptRemoveLruEntry@12' as I_CryptRemoveLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptSetTls@8' as I_CryptSetTls:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptTouchLruEntry@8' as I_CryptTouchLruEntry:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptUninstallAsn1Module@4' as I_CryptUninstallAsn1Module:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptUninstallOssGlobal@4' as I_CryptUninstallOssGlobal:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptUnregisterSmartCardStore@4' as I_CryptUnregisterSmartCardStore:dword ;Not present in MASM32 crypt32.lib
    ;extrn '__imp__I_CryptWalkAllLruCacheEntries@12' as I_CryptWalkAllLruCacheEntries:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__PFXExportCertStore@16' as PFXExportCertStore:dword
    ;extrn '__imp__PFXExportCertStore2@16' as PFXExportCertStore2:dword ;Not present in MASM32 crypt32.lib
    extrn '__imp__PFXExportCertStoreEx@20' as PFXExportCertStoreEx:dword
    extrn '__imp__PFXImportCertStore@12' as PFXImportCertStore:dword
    extrn '__imp__PFXIsPFXBlob@4' as PFXIsPFXBlob:dword
    extrn '__imp__PFXVerifyPassword@12' as PFXVerifyPassword:dword
end if

if defined APP_UNICODE
    CRYPT_PASSWORD_CREDENTIALS fix CRYPT_PASSWORD_CREDENTIALSW,\
    CREDENTIAL_OID_PASSWORD_CREDENTIALS equ CREDENTIAL_OID_PASSWORD_CREDENTIALS_W,\
    MS_DEF_PROV equ MS_DEF_PROV_W,\
    MS_ENHANCED_PROV equ MS_ENHANCED_PROV_W,\
    MS_STRONG_PROV equ MS_STRONG_PROV_W,\
    MS_DEF_RSA_SIG_PROV equ MS_DEF_RSA_SIG_PROV_W,\
    MS_DEF_RSA_SCHANNEL_PROV equ MS_DEF_RSA_SCHANNEL_PROV_W,\
    MS_DEF_DSS_PROV equ MS_DEF_DSS_PROV_W,\
    MS_DEF_DSS_DH_PROV equ MS_DEF_DSS_DH_PROV_W,\
    MS_ENH_DSS_DH_PROV equ MS_ENH_DSS_DH_PROV_W,\
    MS_DEF_DH_SCHANNEL_PROV equ MS_DEF_DH_SCHANNEL_PROV_W,\
    MS_SCARD_PROV equ MS_SCARD_PROV_W,\
    MS_ENH_RSA_AES_PROV_XP equ MS_ENH_RSA_AES_PROV_XP_W,\
    MS_ENH_RSA_AES_PROV equ MS_ENH_RSA_AES_PROV_W,\
    CertAddEncodedCertificateToSystemStore equ CertAddEncodedCertificateToSystemStoreW,\
    CertGetNameString equ CertGetNameStringW,\
    CertNameToStr equ CertNameToStrW,\
    CertOpenSystemStore equ CertOpenSystemStoreW,\
    if defined APP_WIN64
        CertRDNValueToStr equ CertRDNValueToStrW,\
    end if
    CertStrToName equ CertStrToNameW,\
    CryptAcquireContext equ CryptAcquireContextW,\
    CryptBinaryToString equ CryptBinaryToStringW,\
    CryptEnumProviders equ CryptEnumProvidersW,\
    CryptEnumProviderTypes equ CryptEnumProviderTypesW,\
    CryptGetDefaultProvider equ CryptGetDefaultProviderW,\
    CryptRetrieveObjectByUrl equ CryptRetrieveObjectByUrlW,\
    CryptSetProvider equ CryptSetProviderW,\
    CryptSetProviderEx equ CryptSetProviderExW,\
    CryptSignHash equ CryptSignHashW,\
    CryptStringToBinary equ CryptStringToBinaryW,\
    CryptVerifySignature equ CryptVerifySignatureW
else
    CRYPT_PASSWORD_CREDENTIALS fix CRYPT_PASSWORD_CREDENTIALSA,\
    CREDENTIAL_OID_PASSWORD_CREDENTIALS equ CREDENTIAL_OID_PASSWORD_CREDENTIALS_A,\
    MS_DEF_PROV equ MS_DEF_PROV_A,\
    MS_ENHANCED_PROV equ MS_ENHANCED_PROV_A,\
    MS_STRONG_PROV equ MS_STRONG_PROV_A,\
    MS_DEF_RSA_SIG_PROV equ MS_DEF_RSA_SIG_PROV_A,\
    MS_DEF_RSA_SCHANNEL_PROV equ MS_DEF_RSA_SCHANNEL_PROV_A,\
    MS_DEF_DSS_PROV equ MS_DEF_DSS_PROV_A,\
    MS_DEF_DSS_DH_PROV equ MS_DEF_DSS_DH_PROV_A,\
    MS_ENH_DSS_DH_PROV equ MS_ENH_DSS_DH_PROV_A,\
    MS_DEF_DH_SCHANNEL_PROV equ MS_DEF_DH_SCHANNEL_PROV_A,\
    MS_SCARD_PROV equ MS_SCARD_PROV_A,\
    MS_ENH_RSA_AES_PROV_XP equ MS_ENH_RSA_AES_PROV_XP_A,\
    MS_ENH_RSA_AES_PROV equ MS_ENH_RSA_AES_PROV_A,\
    CertAddEncodedCertificateToSystemStore equ CertAddEncodedCertificateToSystemStoreA,\
    CertGetNameString equ CertGetNameStringA,\
    CertNameToStr equ CertNameToStrA,\
    CertOpenSystemStore equ CertOpenSystemStoreA,\
    if defined APP_WIN64
        CertRDNValueToStr equ CertRDNValueToStrA,\
    end if
    CertStrToName equ CertStrToNameA,\
    CryptAcquireContext equ CryptAcquireContextA,\
    CryptBinaryToString equ CryptBinaryToStringA,\
    CryptEnumProviders equ CryptEnumProvidersA,\
    CryptEnumProviderTypes equ CryptEnumProviderTypesA,\
    CryptGetDefaultProvider equ CryptGetDefaultProviderA,\
    CryptRetrieveObjectByUrl equ CryptRetrieveObjectByUrlA,\
    CryptSetProvider equ CryptSetProviderA,\
    CryptSetProviderEx equ CryptSetProviderExA,\
    CryptSignHash equ CryptSignHashA,\
    CryptStringToBinary equ CryptStringToBinaryA,\
    CryptVerifySignature equ CryptVerifySignatureA
end if


;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    if NTDDI_VERSION >= NTDDI_WIN81
;        extrn '__imp_CryptObjectLocatorFree' as CryptObjectLocatorFree:qword
;        extrn '__imp_CryptObjectLocatorGet' as CryptObjectLocatorGet:qword
;        extrn '__imp_CryptObjectLocatorGetContent' as CryptObjectLocatorGetContent:qword
;        extrn '__imp_CryptObjectLocatorGetUpdated' as CryptObjectLocatorGetUpdated:qword
;        extrn '__imp_CryptObjectLocatorInitialize' as CryptObjectLocatorInitialize:qword
;        extrn '__imp_CryptObjectLocatorIsChanged' as CryptObjectLocatorInitialize:qword
;        extrn '__imp_CryptObjectLocatorRelease' as CryptObjectLocatorRelease:qword
;        extrn '__imp_I_PFXImportCertStoreEx' as I_PFXImportCertStoreEx:qword
;    end if

;    extrn '__imp_I_CertDiagControl' as I_CertDiagControl:qword

;    if NTDDI_VERSION >= NTDDI_WIN10
;        extrn '__imp_I_CertChainEngineIsDisallowedCertificate' as I_CertChainEngineIsDisallowedCertificate:qword
;        extrn '__imp_I_CertFinishSslHandshake' as I_CertFinishSslHandshake:qword
;        extrn '__imp_I_CertProcessSslHandshake' as I_CertProcessSslHandshake:qword
;        extrn '__imp_I_CryptAllocTlsEx' as I_CryptAllocTlsEx:qword
;    end if
;else
;    if NTDDI_VERSION >= NTDDI_WIN81
;        extrn '__imp__CryptObjectLocatorFree@??' as CryptObjectLocatorFree:dword
;        extrn '__imp__CryptObjectLocatorGet@??' as CryptObjectLocatorGet:dword
;        extrn '__imp__CryptObjectLocatorGetContent@??' as CryptObjectLocatorGetContent:dword
;        extrn '__imp__CryptObjectLocatorGetUpdated@??' as CryptObjectLocatorGetUpdated:dword
;        extrn '__imp__CryptObjectLocatorInitialize@??' as CryptObjectLocatorInitialize:dword
;        extrn '__imp__CryptObjectLocatorIsChanged@??' as CryptObjectLocatorInitialize:dword
;        extrn '__imp__CryptObjectLocatorRelease@??' as CryptObjectLocatorRelease:dword
;        extrn '__imp__I_PFXImportCertStoreEx@??' as I_PFXImportCertStoreEx:dword
;    end if

;    extrn '__imp_I_CertDiagControl@??' as I_CertDiagControl:dword

;    if NTDDI_VERSION >= NTDDI_WIN10
;        extrn '__imp__I_CertChainEngineIsDisallowedCertificate@??' as I_CertChainEngineIsDisallowedCertificate:dword
;        extrn '__imp__I_CertFinishSslHandshake@??' as I_CertFinishSslHandshake:dword
;        extrn '__imp__I_CertProcessSslHandshake@??' as I_CertProcessSslHandshake:dword
;        extrn '__imp__I_CryptAllocTlsEx@??' as I_CryptAllocTlsEx:dword
;    end if
;end if

end if ;CRYPT32_INC
