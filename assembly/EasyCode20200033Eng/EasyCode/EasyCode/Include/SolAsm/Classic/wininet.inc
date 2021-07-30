; ====================================================;
;                                                     ;
;    wininet.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

#ifndef WININET_INC
WININET_INC equ 1

INTERNET_INVALID_PORT_NUMBER                    equ     0
INTERNET_DEFAULT_FTP_PORT                       equ     21
INTERNET_DEFAULT_GOPHER_PORT                    equ     70
INTERNET_DEFAULT_HTTP_PORT                      equ     80
INTERNET_DEFAULT_HTTPS_PORT                     equ     443
INTERNET_DEFAULT_SOCKS_PORT                     equ     1080

INTERNET_MAX_HOST_NAME_LENGTH                   equ     256
INTERNET_MAX_USER_NAME_LENGTH                   equ     128
INTERNET_MAX_PASSWORD_LENGTH                    equ     128
INTERNET_MAX_PORT_NUMBER_LENGTH                 equ     5
INTERNET_MAX_PORT_NUMBER_VALUE                  equ     65535
INTERNET_MAX_PATH_LENGTH                        equ     2048
INTERNET_MAX_SCHEME_LENGTH                      equ     32
INTERNET_MAX_URL_LENGTH                         equ     <INTERNET_MAX_SCHEME_LENGTH+2 or INTERNET_MAX_PATH_LENGTH>

INTERNET_KEEP_ALIVE_UNKNOWN                     equ     (-1)
INTERNET_KEEP_ALIVE_ENABLED                     equ     1
INTERNET_KEEP_ALIVE_DISABLED                    equ     0

INTERNET_REQFLAG_FROM_CACHE                     equ     00000001H
INTERNET_REQFLAG_ASYNC                          equ     00000002H
INTERNET_REQFLAG_VIA_PROXY                      equ     00000004H
INTERNET_REQFLAG_NO_HEADERS                     equ     00000008H
INTERNET_REQFLAG_PASSIVE                        equ     00000010H
INTERNET_REQFLAG_CACHE_WRITE_DISABLED           equ     00000040H
INTERNET_REQFLAG_NET_TIMEOUT                    equ     00000080H

FTP_TRANSFER_TYPE_UNKNOWN                       equ     00000000H
FTP_TRANSFER_TYPE_ASCII                         equ     00000001H
FTP_TRANSFER_TYPE_BINARY                        equ     00000002H
FTP_TRANSFER_TYPE_MASK                          equ     <FTP_TRANSFER_TYPE_ASCII or FTP_TRANSFER_TYPE_BINARY>

INTERNET_FLAG_RELOAD                            equ     80000000H
INTERNET_FLAG_RAW_DATA                          equ     40000000H
INTERNET_FLAG_EXISTING_CONNECT                  equ     20000000H
INTERNET_FLAG_ASYNC                             equ     10000000H
INTERNET_FLAG_PASSIVE                           equ     08000000H
INTERNET_FLAG_NO_CACHE_WRITE                    equ     04000000H
INTERNET_FLAG_DONT_CACHE                        equ     INTERNET_FLAG_NO_CACHE_WRITE
INTERNET_FLAG_MAKE_PERSISTENT                   equ     02000000H
INTERNET_FLAG_FROM_CACHE                        equ     01000000H
INTERNET_FLAG_OFFLINE                           equ     INTERNET_FLAG_FROM_CACHE
INTERNET_FLAG_SECURE                            equ     00800000H
INTERNET_FLAG_KEEP_CONNECTION                   equ     00400000H
INTERNET_FLAG_NO_AUTO_REDIRECT                  equ     00200000H
INTERNET_FLAG_READ_PREFETCH                     equ     00100000H
INTERNET_FLAG_NO_COOKIES                        equ     00080000H
INTERNET_FLAG_NO_AUTH                           equ     00040000H
INTERNET_FLAG_CACHE_IF_NET_FAIL                 equ     00010000H
INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP           equ     00008000H
INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS          equ     00004000H
INTERNET_FLAG_IGNORE_CERT_DATE_INVALID          equ     00002000H
INTERNET_FLAG_IGNORE_CERT_CN_INVALID            equ     00001000H
INTERNET_FLAG_RESYNCHRONIZE                     equ     00000800H
INTERNET_FLAG_HYPERLINK                         equ     00000400H
INTERNET_FLAG_NO_UI                             equ     00000200H
INTERNET_FLAG_PRAGMA_NOCACHE                    equ     00000100H
INTERNET_FLAG_CACHE_ASYNC                       equ     00000080H
INTERNET_FLAG_FORMS_SUBMIT                      equ     00000040H
INTERNET_FLAG_FWD_BACK                          equ     00000020H
INTERNET_FLAG_NEED_FILE                         equ     00000010H
INTERNET_FLAG_BGUPDATE                          equ     00000008H
INTERNET_FLAG_MUST_CACHE_REQUEST                equ     INTERNET_FLAG_NEED_FILE
INTERNET_FLAG_TRANSFER_ASCII                    equ     FTP_TRANSFER_TYPE_ASCII
INTERNET_FLAG_TRANSFER_BINARY                   equ     FTP_TRANSFER_TYPE_BINARY

SECURITY_INTERNET_MASK                          equ     <INTERNET_FLAG_IGNORE_CERT_CN_INVALID or INTERNET_FLAG_IGNORE_CERT_DATE_INVALID or INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS or INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP>
INTERNET_FLAGS_MASK                             equ     <INTERNET_FLAG_RELOAD or INTERNET_FLAG_RAW_DATA or INTERNET_FLAG_EXISTING_CONNECT or INTERNET_FLAG_ASYNC or INTERNET_FLAG_PASSIVE or INTERNET_FLAG_NO_CACHE_WRITE or INTERNET_FLAG_MAKE_PERSISTENT or INTERNET_FLAG_FROM_CACHE or INTERNET_FLAG_SECURE or INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_AUTO_REDIRECT or INTERNET_FLAG_READ_PREFETCH or INTERNET_FLAG_NO_COOKIES or INTERNET_FLAG_NO_AUTH or INTERNET_FLAG_CACHE_IF_NET_FAIL or SECURITY_INTERNET_MASK or INTERNET_FLAG_RESYNCHRONIZE or INTERNET_FLAG_HYPERLINK or INTERNET_FLAG_NO_UI or INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_CACHE_ASYNC or INTERNET_FLAG_FORMS_SUBMIT or INTERNET_FLAG_NEED_FILE or INTERNET_FLAG_TRANSFER_BINARY or INTERNET_FLAG_TRANSFER_ASCII or INTERNET_FLAG_FWD_BACK or INTERNET_FLAG_BGUPDATE>

INTERNET_ERROR_MASK_INSERT_CDROM                equ     01H
INTERNET_ERROR_MASK_COMBINED_SEC_CERT           equ     02H
INTERNET_ERROR_MASK_NEED_MSN_SSPI_PKG           equ     04H
INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY equ   08H
INTERNET_OPTIONS_MASK                           equ     <not INTERNET_FLAGS_MASK>

WININET_API_FLAG_ASYNC                          equ     00000001H
WININET_API_FLAG_SYNC                           equ     00000004H
WININET_API_FLAG_USE_CONTEXT                    equ     00000008H

INTERNET_NO_CALLBACK                            equ     0

INTERNET_PER_CONN_FLAGS                         equ     1
INTERNET_PER_CONN_PROXY_SERVER                  equ     2
INTERNET_PER_CONN_PROXY_BYPASS                  equ     3
INTERNET_PER_CONN_AUTOCONFIG_URL                equ     4
INTERNET_PER_CONN_AUTODISCOVERY_FLAGS           equ     5

PROXY_TYPE_DIRECT                               equ     00000001H
PROXY_TYPE_PROXY                                equ     00000002H
PROXY_TYPE_AUTO_PROXY_URL                       equ     00000004H
PROXY_TYPE_AUTO_DETECT                          equ     00000008H

AUTO_PROXY_FLAG_USER_SET                        equ     00000001H
AUTO_PROXY_FLAG_ALWAYS_DETECT                   equ     00000002H
AUTO_PROXY_FLAG_DETECTION_RUN                   equ     00000004H
AUTO_PROXY_FLAG_MIGRATED                        equ     00000008H
AUTO_PROXY_FLAG_DONT_CACHE_PROXY_RESULT         equ     00000010H
AUTO_PROXY_FLAG_CACHE_INIT_RUN                  equ     00000020H
AUTO_PROXY_FLAG_DETECTION_SUSPECT               equ     00000040H

ISO_FORCE_DISCONNECTED                          equ     00000001H

INTERNET_RFC1123_FORMAT                         equ     0
INTERNET_RFC1123_BUFSIZE                        equ     30

ICU_ESCAPE                                      equ     80000000H
ICU_USERNAME                                    equ     40000000H
ICU_NO_ENCODE                                   equ     20000000H
ICU_DECODE                                      equ     10000000H
ICU_NO_META                                     equ     08000000H
ICU_ENCODE_SPACES_ONLY                          equ     04000000H
ICU_BROWSER_MODE                                equ     02000000H
ICU_ENCODE_PERCENT                              equ     00001000H

INTERNET_OPEN_TYPE_PRECONFIG                    equ     0
INTERNET_OPEN_TYPE_DIRECT                       equ     1
INTERNET_OPEN_TYPE_PROXY                        equ     3
INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY  equ     4

PRE_CONFIG_INTERNET_ACCESS                      equ     INTERNET_OPEN_TYPE_PRECONFIG
LOCAL_INTERNET_ACCESS                           equ     INTERNET_OPEN_TYPE_DIRECT
CERN_PROXY_INTERNET_ACCESS                      equ     INTERNET_OPEN_TYPE_PROXY

INTERNET_SERVICE_FTP                            equ     1
INTERNET_SERVICE_GOPHER                         equ     2
INTERNET_SERVICE_HTTP                           equ     3

IRF_ASYNC                                       equ     WININET_API_FLAG_ASYNC
IRF_SYNC                                        equ     WININET_API_FLAG_SYNC
IRF_USE_CONTEXT                                 equ     WININET_API_FLAG_USE_CONTEXT
IRF_NO_WAIT                                     equ     00000008H

ISO_GLOBAL                                      equ     00000001H
ISO_REGISTRY                                    equ     00000002H
ISO_VALID_FLAGS                                 equ     <ISO_GLOBAL or ISO_REGISTRY>

INTERNET_OPTION_CALLBACK                        equ     1
INTERNET_OPTION_CONNECT_TIMEOUT                 equ     2
INTERNET_OPTION_CONNECT_RETRIES                 equ     3
INTERNET_OPTION_CONNECT_BACKOFF                 equ     4
INTERNET_OPTION_SEND_TIMEOUT                    equ     5
INTERNET_OPTION_CONTROL_SEND_TIMEOUT            equ     INTERNET_OPTION_SEND_TIMEOUT
INTERNET_OPTION_RECEIVE_TIMEOUT                 equ     6
INTERNET_OPTION_CONTROL_RECEIVE_TIMEOUT         equ     INTERNET_OPTION_RECEIVE_TIMEOUT
INTERNET_OPTION_DATA_SEND_TIMEOUT               equ     7
INTERNET_OPTION_DATA_RECEIVE_TIMEOUT            equ     8
INTERNET_OPTION_HANDLE_TYPE                     equ     9
INTERNET_OPTION_LISTEN_TIMEOUT                  equ     11
INTERNET_OPTION_READ_BUFFER_SIZE                equ     12
INTERNET_OPTION_WRITE_BUFFER_SIZE               equ     13
INTERNET_OPTION_ASYNC_ID                        equ     15
INTERNET_OPTION_ASYNC_PRIORITY                  equ     16
INTERNET_OPTION_PARENT_HANDLE                   equ     21
INTERNET_OPTION_KEEP_CONNECTION                 equ     22
INTERNET_OPTION_REQUEST_FLAGS                   equ     23
INTERNET_OPTION_EXTENDED_ERROR                  equ     24
INTERNET_OPTION_OFFLINE_MODE                    equ     26
INTERNET_OPTION_CACHE_STREAM_HANDLE             equ     27
INTERNET_OPTION_USERNAME                        equ     28
INTERNET_OPTION_PASSWORD                        equ     29
INTERNET_OPTION_ASYNC                           equ     30
INTERNET_OPTION_SECURITY_FLAGS                  equ     31
INTERNET_OPTION_SECURITY_CERTIFICATE_STRUCT     equ     32
INTERNET_OPTION_DATAFILE_NAME                   equ     33
INTERNET_OPTION_URL                             equ     34
INTERNET_OPTION_SECURITY_CERTIFICATE            equ     35
INTERNET_OPTION_SECURITY_KEY_BITNESS            equ     36
INTERNET_OPTION_REFRESH                         equ     37
INTERNET_OPTION_PROXY                           equ     38
INTERNET_OPTION_SETTINGS_CHANGED                equ     39
INTERNET_OPTION_VERSION                         equ     40
INTERNET_OPTION_USER_AGENT                      equ     41
INTERNET_OPTION_END_BROWSER_SESSION             equ     42
INTERNET_OPTION_PROXY_USERNAME                  equ     43
INTERNET_OPTION_PROXY_PASSWORD                  equ     44
INTERNET_OPTION_CONTEXT_VALUE                   equ     45
INTERNET_OPTION_CONNECT_LIMIT                   equ     46
INTERNET_OPTION_SECURITY_SELECT_CLIENT_CERT     equ     47
INTERNET_OPTION_POLICY                          equ     48
INTERNET_OPTION_DISCONNECTED_TIMEOUT            equ     49
INTERNET_OPTION_CONNECTED_STATE                 equ     50
INTERNET_OPTION_IDLE_STATE                      equ     51
INTERNET_OPTION_OFFLINE_SEMANTICS               equ     52
INTERNET_OPTION_SECONDARY_CACHE_KEY             equ     53
INTERNET_OPTION_CALLBACK_FILTER                 equ     54
INTERNET_OPTION_CONNECT_TIME                    equ     55
INTERNET_OPTION_SEND_THROUGHPUT                 equ     56
INTERNET_OPTION_RECEIVE_THROUGHPUT              equ     57
INTERNET_OPTION_REQUEST_PRIORITY                equ     58
INTERNET_OPTION_HTTP_VERSION                    equ     59
INTERNET_OPTION_RESET_URLCACHE_SESSION          equ     60
INTERNET_OPTION_ERROR_MASK                      equ     62
INTERNET_OPTION_FROM_CACHE_TIMEOUT              equ     63
INTERNET_OPTION_BYPASS_EDITED_ENTRY             equ     64
INTERNET_OPTION_CODEPAGE                        equ     68
INTERNET_OPTION_CACHE_TIMESTAMPS                equ     69
INTERNET_OPTION_DISABLE_AUTODIAL                equ     70
INTERNET_OPTION_MAX_CONNS_PER_SERVER            equ     73
INTERNET_OPTION_MAX_CONNS_PER_1_0_SERVER        equ     74
INTERNET_OPTION_PER_CONNECTION_OPTION           equ     75
INTERNET_OPTION_DIGEST_AUTH_UNLOAD              equ     76
INTERNET_OPTION_IGNORE_OFFLINE                  equ     77
INTERNET_FIRST_OPTION                           equ     INTERNET_OPTION_CALLBACK
INTERNET_LAST_OPTION                            equ     INTERNET_OPTION_IGNORE_OFFLINE

INTERNET_PRIORITY_FOREGROUND                    equ     1000

INTERNET_HANDLE_TYPE_INTERNET                   equ     1
INTERNET_HANDLE_TYPE_CONNECT_FTP                equ     2
INTERNET_HANDLE_TYPE_CONNECT_GOPHER             equ     3
INTERNET_HANDLE_TYPE_CONNECT_HTTP               equ     4
INTERNET_HANDLE_TYPE_FTP_FIND                   equ     5
INTERNET_HANDLE_TYPE_FTP_FIND_HTML              equ     6
INTERNET_HANDLE_TYPE_FTP_FILE                   equ     7
INTERNET_HANDLE_TYPE_FTP_FILE_HTML              equ     8
INTERNET_HANDLE_TYPE_GOPHER_FIND                equ     9
INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML           equ     10
INTERNET_HANDLE_TYPE_GOPHER_FILE                equ     11
INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML           equ     12
INTERNET_HANDLE_TYPE_HTTP_REQUEST               equ     13
INTERNET_HANDLE_TYPE_FILE_REQUEST               equ     14

SECURITY_FLAG_SECURE                            equ     00000001H
SECURITY_FLAG_STRENGTH_WEAK                     equ     10000000H
SECURITY_FLAG_STRENGTH_MEDIUM                   equ     40000000H
SECURITY_FLAG_STRENGTH_STRONG                   equ     20000000H
SECURITY_FLAG_UNKNOWNBIT                        equ     80000000H
SECURITY_FLAG_FORTEZZA                          equ     08000000H
SECURITY_FLAG_NORMALBITNESS                     equ     SECURITY_FLAG_STRENGTH_WEAK
SECURITY_FLAG_SSL                               equ     00000002H
SECURITY_FLAG_SSL3                              equ     00000004H
SECURITY_FLAG_PCT                               equ     00000008H
SECURITY_FLAG_PCT4                              equ     00000010H
SECURITY_FLAG_IETFSSL4                          equ     00000020H
SECURITY_FLAG_40BIT                             equ     SECURITY_FLAG_STRENGTH_WEAK
SECURITY_FLAG_128BIT                            equ     SECURITY_FLAG_STRENGTH_STRONG
SECURITY_FLAG_56BIT                             equ     SECURITY_FLAG_STRENGTH_MEDIUM
SECURITY_FLAG_IGNORE_REVOCATION                 equ     00000080H
SECURITY_FLAG_IGNORE_UNKNOWN_CA                 equ     00000100H
SECURITY_FLAG_IGNORE_WRONG_USAGE                equ     00000200H
SECURITY_FLAG_IGNORE_CERT_CN_INVALID            equ     INTERNET_FLAG_IGNORE_CERT_CN_INVALID
SECURITY_FLAG_IGNORE_CERT_DATE_INVALID          equ     INTERNET_FLAG_IGNORE_CERT_DATE_INVALID
SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTPS          equ     INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS
SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTP           equ     INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP
SECURITY_SET_MASK                               equ     <SECURITY_FLAG_IGNORE_REVOCATION or SECURITY_FLAG_IGNORE_UNKNOWN_CA or SECURITY_FLAG_IGNORE_CERT_CN_INVALID or SECURITY_FLAG_IGNORE_CERT_DATE_INVALID or SECURITY_FLAG_IGNORE_WRONG_USAGE>

INTERNET_STATUS_RESOLVING_NAME                  equ     10
INTERNET_STATUS_NAME_RESOLVED                   equ     11
INTERNET_STATUS_CONNECTING_TO_SERVER            equ     20
INTERNET_STATUS_CONNECTED_TO_SERVER             equ     21
INTERNET_STATUS_SENDING_REQUEST                 equ     30
INTERNET_STATUS_REQUEST_SENT                    equ     31
INTERNET_STATUS_RECEIVING_RESPONSE              equ     40
INTERNET_STATUS_RESPONSE_RECEIVED               equ     41
INTERNET_STATUS_CTL_RESPONSE_RECEIVED           equ     42
INTERNET_STATUS_PREFETCH                        equ     43
INTERNET_STATUS_CLOSING_CONNECTION              equ     50
INTERNET_STATUS_CONNECTION_CLOSED               equ     51
INTERNET_STATUS_HANDLE_CREATED                  equ     60
INTERNET_STATUS_HANDLE_CLOSING                  equ     70
INTERNET_STATUS_DETECTING_PROXY                 equ     80
INTERNET_STATUS_REQUEST_COMPLETE                equ     100
INTERNET_STATUS_REDIRECT                        equ     110
INTERNET_STATUS_INTERMEDIATE_RESPONSE           equ     120
INTERNET_STATUS_USER_INPUT_REQUIRED             equ     140
INTERNET_STATUS_STATE_CHANGE                    equ     200

INTERNET_STATE_CONNECTED                        equ     00000001H
INTERNET_STATE_DISCONNECTED                     equ     00000002H
INTERNET_STATE_DISCONNECTED_BY_USER             equ     00000010H
INTERNET_STATE_IDLE                             equ     00000100H
INTERNET_STATE_BUSY                             equ     00000200H

INTERNET_INVALID_STATUS_CALLBACK                equ     (-1)

MAX_GOPHER_DISPLAY_TEXT                         equ     128
MAX_GOPHER_SELECTOR_TEXT                        equ     256
MAX_GOPHER_HOST_NAME                            equ     INTERNET_MAX_HOST_NAME_LENGTH
MAX_GOPHER_LOCATOR_LENGTH                       equ     <1+MAX_GOPHER_DISPLAY_TEXT+1+MAX_GOPHER_SELECTOR_TEXT+1+MAX_GOPHER_HOST_NAME+1+INTERNET_MAX_PORT_NUMBER_LENGTH+1+1+2>

GOPHER_TYPE_TEXT_FILE                           equ     00000001H
GOPHER_TYPE_DIRECTORY                           equ     00000002H
GOPHER_TYPE_CSO                                 equ     00000004H
GOPHER_TYPE_ERROR                               equ     00000008H
GOPHER_TYPE_MAC_BINHEX                          equ     00000010H
GOPHER_TYPE_DOS_ARCHIVE                         equ     00000020H
GOPHER_TYPE_UNIX_UUENCODED                      equ     00000040H
GOPHER_TYPE_INDEX_SERVER                        equ     00000080H
GOPHER_TYPE_TELNET                              equ     00000100H
GOPHER_TYPE_BINARY                              equ     00000200H
GOPHER_TYPE_REDUNDANT                           equ     00000400H
GOPHER_TYPE_TN3270                              equ     00000800H
GOPHER_TYPE_GIF                                 equ     00001000H
GOPHER_TYPE_IMAGE                               equ     00002000H
GOPHER_TYPE_BITMAP                              equ     00004000H
GOPHER_TYPE_MOVIE                               equ     00008000H
GOPHER_TYPE_SOUND                               equ     00010000H
GOPHER_TYPE_HTML                                equ     00020000H
GOPHER_TYPE_PDF                                 equ     00040000H
GOPHER_TYPE_CALENDAR                            equ     00080000H
GOPHER_TYPE_INLINE                              equ     00100000H
GOPHER_TYPE_UNKNOWN                             equ     20000000H
GOPHER_TYPE_ASK                                 equ     40000000H
GOPHER_TYPE_GOPHER_PLUS                         equ     80000000H

GOPHER_TYPE_FILE_MASK                           equ     <GOPHER_TYPE_TEXT_FILE or GOPHER_TYPE_MAC_BINHEX or GOPHER_TYPE_DOS_ARCHIVE or GOPHER_TYPE_UNIX_UUENCODED or GOPHER_TYPE_BINARY or GOPHER_TYPE_GIF or GOPHER_TYPE_IMAGE or GOPHER_TYPE_BITMAP or GOPHER_TYPE_MOVIE or GOPHER_TYPE_SOUND or GOPHER_TYPE_HTML or GOPHER_TYPE_PDF or GOPHER_TYPE_CALENDAR or GOPHER_TYPE_INLINE>

MAX_GOPHER_CATEGORY_NAME                        equ     128
MAX_GOPHER_ATTRIBUTE_NAME                       equ     128
MIN_GOPHER_ATTRIBUTE_LENGTH                     equ     256

GOPHER_INFO_CATEGORY                            db      '+INFO', 0
GOPHER_ADMIN_CATEGORY                           db      '+ADMIN', 0
GOPHER_VIEWS_CATEGORY                           db      '+VIEWS', 0
GOPHER_ABSTRACT_CATEGORY                        db      '+ABSTRACT', 0
GOPHER_VERONICA_CATEGORY                        db      '+VERONICA', 0
GOPHER_ADMIN_ATTRIBUTE                          db      'Admin', 0
GOPHER_MOD_DATE_ATTRIBUTE                       db      'Mod-Date', 0
GOPHER_TTL_ATTRIBUTE                            db      'TTL', 0
GOPHER_SCORE_ATTRIBUTE                          db      'Score', 0
GOPHER_RANGE_ATTRIBUTE                          db      'Score-range', 0
GOPHER_SITE_ATTRIBUTE                           db      'Site', 0
GOPHER_ORG_ATTRIBUTE                            db      'Org', 0
GOPHER_LOCATION_ATTRIBUTE                       db      'Loc', 0
GOPHER_GEOG_ATTRIBUTE                           db      'Geog', 0
GOPHER_TIMEZONE_ATTRIBUTE                       db      'TZ', 0
GOPHER_PROVIDER_ATTRIBUTE                       db      'Provider', 0
GOPHER_VERSION_ATTRIBUTE                        db      'Version', 0
GOPHER_ABSTRACT_ATTRIBUTE                       db      'Abstract', 0
GOPHER_VIEW_ATTRIBUTE                           db      'View', 0
GOPHER_TREEWALK_ATTRIBUTE                       db      'treewalk', 0

GOPHER_ATTRIBUTE_ID_BASE                        equ     0ABCCCC00H
GOPHER_CATEGORY_ID_ALL                          equ     <GOPHER_ATTRIBUTE_ID_BASE+1>
GOPHER_CATEGORY_ID_INFO                         equ     <GOPHER_ATTRIBUTE_ID_BASE+2>
GOPHER_CATEGORY_ID_ADMIN                        equ     <GOPHER_ATTRIBUTE_ID_BASE+3>
GOPHER_CATEGORY_ID_VIEWS                        equ     <GOPHER_ATTRIBUTE_ID_BASE+4>
GOPHER_CATEGORY_ID_ABSTRACT                     equ     <GOPHER_ATTRIBUTE_ID_BASE+5>
GOPHER_CATEGORY_ID_VERONICA                     equ     <GOPHER_ATTRIBUTE_ID_BASE+6>
GOPHER_CATEGORY_ID_ASK                          equ     <GOPHER_ATTRIBUTE_ID_BASE+7>
GOPHER_CATEGORY_ID_UNKNOWN                      equ     <GOPHER_ATTRIBUTE_ID_BASE+8>
GOPHER_ATTRIBUTE_ID_ALL                         equ     <GOPHER_ATTRIBUTE_ID_BASE+9>
GOPHER_ATTRIBUTE_ID_ADMIN                       equ     <GOPHER_ATTRIBUTE_ID_BASE+10>
GOPHER_ATTRIBUTE_ID_MOD_DATE                    equ     <GOPHER_ATTRIBUTE_ID_BASE+11>
GOPHER_ATTRIBUTE_ID_TTL                         equ     <GOPHER_ATTRIBUTE_ID_BASE+12>
GOPHER_ATTRIBUTE_ID_SCORE                       equ     <GOPHER_ATTRIBUTE_ID_BASE+13>
GOPHER_ATTRIBUTE_ID_RANGE                       equ     <GOPHER_ATTRIBUTE_ID_BASE+14>
GOPHER_ATTRIBUTE_ID_SITE                        equ     <GOPHER_ATTRIBUTE_ID_BASE+15>
GOPHER_ATTRIBUTE_ID_ORG                         equ     <GOPHER_ATTRIBUTE_ID_BASE+16>
GOPHER_ATTRIBUTE_ID_LOCATION                    equ     <GOPHER_ATTRIBUTE_ID_BASE+17>
GOPHER_ATTRIBUTE_ID_GEOG                        equ     <GOPHER_ATTRIBUTE_ID_BASE+18>
GOPHER_ATTRIBUTE_ID_TIMEZONE                    equ     <GOPHER_ATTRIBUTE_ID_BASE+19>
GOPHER_ATTRIBUTE_ID_PROVIDER                    equ     <GOPHER_ATTRIBUTE_ID_BASE+20>
GOPHER_ATTRIBUTE_ID_VERSION                     equ     <GOPHER_ATTRIBUTE_ID_BASE+21>
GOPHER_ATTRIBUTE_ID_ABSTRACT                    equ     <GOPHER_ATTRIBUTE_ID_BASE+22>
GOPHER_ATTRIBUTE_ID_VIEW                        equ     <GOPHER_ATTRIBUTE_ID_BASE+23>
GOPHER_ATTRIBUTE_ID_TREEWALK                    equ     <GOPHER_ATTRIBUTE_ID_BASE+24>
GOPHER_ATTRIBUTE_ID_UNKNOWN                     equ     <GOPHER_ATTRIBUTE_ID_BASE+25>

HTTP_MAJOR_VERSION                              equ     1
HTTP_MINOR_VERSION                              equ     0
HTTP_VERSIONA                                   db      'HTTP/1.0', 0
HTTP_VERSIONW                                   du      'HTTP/1.0', 0

HTTP_QUERY_MIME_VERSION                         equ     0
HTTP_QUERY_CONTENT_TYPE                         equ     1
HTTP_QUERY_CONTENT_TRANSFER_ENCODING            equ     2
HTTP_QUERY_CONTENT_ID                           equ     3
HTTP_QUERY_CONTENT_DESCRIPTION                  equ     4
HTTP_QUERY_CONTENT_LENGTH                       equ     5
HTTP_QUERY_CONTENT_LANGUAGE                     equ     6
HTTP_QUERY_ALLOW                                equ     7
HTTP_QUERY_PUBLIC                               equ     8
HTTP_QUERY_DATE                                 equ     9
HTTP_QUERY_EXPIRES                              equ     10
HTTP_QUERY_LAST_MODIFIED                        equ     11
HTTP_QUERY_MESSAGE_ID                           equ     12
HTTP_QUERY_URI                                  equ     13
HTTP_QUERY_DERIVED_FROM                         equ     14
HTTP_QUERY_COST                                 equ     15
HTTP_QUERY_LINK                                 equ     16
HTTP_QUERY_PRAGMA                               equ     17
HTTP_QUERY_VERSION                              equ     18
HTTP_QUERY_STATUS_CODE                          equ     19
HTTP_QUERY_STATUS_TEXT                          equ     20
HTTP_QUERY_RAW_HEADERS                          equ     21
HTTP_QUERY_RAW_HEADERS_CRLF                     equ     22
HTTP_QUERY_CONNECTION                           equ     23
HTTP_QUERY_ACCEPT                               equ     24
HTTP_QUERY_ACCEPT_CHARSET                       equ     25
HTTP_QUERY_ACCEPT_ENCODING                      equ     26
HTTP_QUERY_ACCEPT_LANGUAGE                      equ     27
HTTP_QUERY_AUTHORIZATION                        equ     28
HTTP_QUERY_CONTENT_ENCODING                     equ     29
HTTP_QUERY_FORWARDED                            equ     30
HTTP_QUERY_FROM                                 equ     31
HTTP_QUERY_IF_MODIFIED_SINCE                    equ     32
HTTP_QUERY_LOCATION                             equ     33
HTTP_QUERY_ORIG_URI                             equ     34
HTTP_QUERY_REFERER                              equ     35
HTTP_QUERY_RETRY_AFTER                          equ     36
HTTP_QUERY_SERVER                               equ     37
HTTP_QUERY_TITLE                                equ     38
HTTP_QUERY_USER_AGENT                           equ     39
HTTP_QUERY_WWW_AUTHENTICATE                     equ     40
HTTP_QUERY_PROXY_AUTHENTICATE                   equ     41
HTTP_QUERY_ACCEPT_RANGES                        equ     42
HTTP_QUERY_SET_COOKIE                           equ     43
HTTP_QUERY_COOKIE                               equ     44
HTTP_QUERY_REQUEST_METHOD                       equ     45
HTTP_QUERY_REFRESH                              equ     46
HTTP_QUERY_CONTENT_DISPOSITION                  equ     47
HTTP_QUERY_AGE                                  equ     48
HTTP_QUERY_CACHE_CONTROL                        equ     49
HTTP_QUERY_CONTENT_BASE                         equ     50
HTTP_QUERY_CONTENT_LOCATION                     equ     51
HTTP_QUERY_CONTENT_MD5                          equ     52
HTTP_QUERY_CONTENT_RANGE                        equ     53
HTTP_QUERY_ETAG                                 equ     54
HTTP_QUERY_HOST                                 equ     55
HTTP_QUERY_IF_MATCH                             equ     56
HTTP_QUERY_IF_NONE_MATCH                        equ     57
HTTP_QUERY_IF_RANGE                             equ     58
HTTP_QUERY_IF_UNMODIFIED_SINCE                  equ     59
HTTP_QUERY_MAX_FORWARDS                         equ     60
HTTP_QUERY_PROXY_AUTHORIZATION                  equ     61
HTTP_QUERY_RANGE                                equ     62
HTTP_QUERY_TRANSFER_ENCODING                    equ     63
HTTP_QUERY_UPGRADE                              equ     64
HTTP_QUERY_VARY                                 equ     65
HTTP_QUERY_VIA                                  equ     66
HTTP_QUERY_WARNING                              equ     67
HTTP_QUERY_EXPECT                               equ     68
HTTP_QUERY_PROXY_CONNECTION                     equ     69
HTTP_QUERY_UNLESS_MODIFIED_SINCE                equ     70
HTTP_QUERY_ECHO_REQUEST                         equ     71
HTTP_QUERY_ECHO_REPLY                           equ     72
HTTP_QUERY_ECHO_HEADERS                         equ     73
HTTP_QUERY_ECHO_HEADERS_CRLF                    equ     74
HTTP_QUERY_MAX                                  equ     74
HTTP_QUERY_CUSTOM                               equ     65535
HTTP_QUERY_FLAG_REQUEST_HEADERS                 equ     80000000H
HTTP_QUERY_FLAG_SYSTEMTIME                      equ     40000000H
HTTP_QUERY_FLAG_NUMBER                          equ     20000000H
HTTP_QUERY_FLAG_COALESCE                        equ     10000000H
HTTP_QUERY_MODIFIER_FLAGS_MASK                  equ     <HTTP_QUERY_FLAG_REQUEST_HEADERS or HTTP_QUERY_FLAG_SYSTEMTIME or HTTP_QUERY_FLAG_NUMBER or HTTP_QUERY_FLAG_COALESCE>
HTTP_QUERY_HEADER_MASK                          equ     <not HTTP_QUERY_MODIFIER_FLAGS_MASK>

HTTP_STATUS_CONTINUE                            equ     100
HTTP_STATUS_SWITCH_PROTOCOLS                    equ     101
HTTP_STATUS_OK                                  equ     200
HTTP_STATUS_CREATED                             equ     201
HTTP_STATUS_ACCEPTED                            equ     202
HTTP_STATUS_PARTIAL                             equ     203
HTTP_STATUS_NO_CONTENT                          equ     204
HTTP_STATUS_RESET_CONTENT                       equ     205
HTTP_STATUS_PARTIAL_CONTENT                     equ     206
HTTP_STATUS_AMBIGUOUS                           equ     300
HTTP_STATUS_MOVED                               equ     301
HTTP_STATUS_REDIRECT                            equ     302
HTTP_STATUS_REDIRECT_METHOD                     equ     303
HTTP_STATUS_NOT_MODIFIED                        equ     304
HTTP_STATUS_USE_PROXY                           equ     305
HTTP_STATUS_REDIRECT_KEEP_VERB                  equ     307
HTTP_STATUS_BAD_REQUEST                         equ     400
HTTP_STATUS_DENIED                              equ     401
HTTP_STATUS_PAYMENT_REQ                         equ     402
HTTP_STATUS_FORBIDDEN                           equ     403
HTTP_STATUS_NOT_FOUND                           equ     404
HTTP_STATUS_BAD_METHOD                          equ     405
HTTP_STATUS_NONE_ACCEPTABLE                     equ     406
HTTP_STATUS_PROXY_AUTH_REQ                      equ     407
HTTP_STATUS_REQUEST_TIMEOUT                     equ     408
HTTP_STATUS_CONFLICT                            equ     409
HTTP_STATUS_GONE                                equ     410
HTTP_STATUS_LENGTH_REQUIRED                     equ     411
HTTP_STATUS_PRECOND_FAILED                      equ     412
HTTP_STATUS_REQUEST_TOO_LARGE                   equ     413
HTTP_STATUS_URI_TOO_LONG                        equ     414
HTTP_STATUS_UNSUPPORTED_MEDIA                   equ     415
HTTP_STATUS_RETRY_WITH                          equ     449
HTTP_STATUS_SERVER_ERROR                        equ     500
HTTP_STATUS_NOT_SUPPORTED                       equ     501
HTTP_STATUS_BAD_GATEWAY                         equ     502
HTTP_STATUS_SERVICE_UNAVAIL                     equ     503
HTTP_STATUS_GATEWAY_TIMEOUT                     equ     504
HTTP_STATUS_VERSION_NOT_SUP                     equ     505
HTTP_STATUS_FIRST                               equ     HTTP_STATUS_CONTINUE
HTTP_STATUS_LAST                                equ     HTTP_STATUS_VERSION_NOT_SUP

HTTP_ADDREQ_INDEX_MASK                          equ     00000FFFFH
HTTP_ADDREQ_FLAGS_MASK                          equ     0FFFF0000H
HTTP_ADDREQ_FLAG_ADD_IF_NEW                     equ     010000000H
HTTP_ADDREQ_FLAG_ADD                            equ     020000000H
HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA            equ     040000000H
HTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON        equ     001000000H
HTTP_ADDREQ_FLAG_COALESCE                       equ     HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA
HTTP_ADDREQ_FLAG_REPLACE                        equ     080000000H

HSR_ASYNC                                       equ     WININET_API_FLAG_ASYNC
HSR_SYNC                                        equ     WININET_API_FLAG_SYNC
HSR_USE_CONTEXT                                 equ     WININET_API_FLAG_USE_CONTEXT
HSR_INITIATE                                    equ     00000008H
HSR_DOWNLOAD                                    equ     00000010H
HSR_CHUNKED                                     equ     00000020H

FLAG_ICC_FORCE_CONNECTION                       equ     00000001H

FLAGS_ERROR_UI_FILTER_FOR_ERRORS                equ     01H
FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS             equ     02H
FLAGS_ERROR_UI_FLAGS_GENERATE_DATA              equ     04H
FLAGS_ERROR_UI_FLAGS_NO_UI                      equ     08H
FLAGS_ERROR_UI_SERIALIZE_DIALOGS                equ     10H

NORMAL_CACHE_ENTRY                              equ     00000001H
STICKY_CACHE_ENTRY                              equ     00000004H
EDITED_CACHE_ENTRY                              equ     00000008H
TRACK_OFFLINE_CACHE_ENTRY                       equ     00000010H
TRACK_ONLINE_CACHE_ENTRY                        equ     00000020H
SPARSE_CACHE_ENTRY                              equ     00010000H
COOKIE_CACHE_ENTRY                              equ     00100000H
URLHISTORY_CACHE_ENTRY                          equ     00200000H
URLCACHE_FIND_DEFAULT_FILTER                    equ     <NORMAL_CACHE_ENTRY or COOKIE_CACHE_ENTRY or URLHISTORY_CACHE_ENTRY or TRACK_OFFLINE_CACHE_ENTRY or TRACK_ONLINE_CACHE_ENTRY or STICKY_CACHE_ENTRY>

CACHEGROUP_ATTRIBUTE_GET_ALL                    equ     0FFFFFFFFH
CACHEGROUP_ATTRIBUTE_BASIC                      equ     000000001H
CACHEGROUP_ATTRIBUTE_FLAG                       equ     000000002H
CACHEGROUP_ATTRIBUTE_TYPE                       equ     000000004H
CACHEGROUP_ATTRIBUTE_QUOTA                      equ     000000008H
CACHEGROUP_ATTRIBUTE_GROUPNAME                  equ     000000010H
CACHEGROUP_ATTRIBUTE_STORAGE                    equ     000000020H
CACHEGROUP_FLAG_NONPURGEABLE                    equ     000000001H
CACHEGROUP_FLAG_GIDONLY                         equ     000000004H
CACHEGROUP_FLAG_FLUSHURL_ONDELETE               equ     000000002H
CACHEGROUP_SEARCH_ALL                           equ     000000000H
CACHEGROUP_SEARCH_BYURL                         equ     000000001H
CACHEGROUP_TYPE_INVALID                         equ     000000001H
CACHEGROUP_READWRITE_MASK                       equ     <CACHEGROUP_ATTRIBUTE_TYPE or CACHEGROUP_ATTRIBUTE_QUOTA or CACHEGROUP_ATTRIBUTE_GROUPNAME or CACHEGROUP_ATTRIBUTE_STORAGE>

GROUPNAME_MAX_LENGTH                            equ     120
GROUP_OWNER_STORAGE_SIZE                        equ     4

CACHE_ENTRY_ATTRIBUTE_FC                        equ     00000004H
CACHE_ENTRY_HITRATE_FC                          equ     00000010H
CACHE_ENTRY_MODTIME_FC                          equ     00000040H
CACHE_ENTRY_EXPTIME_FC                          equ     00000080H
CACHE_ENTRY_ACCTIME_FC                          equ     00000100H
CACHE_ENTRY_SYNCTIME_FC                         equ     00000200H
CACHE_ENTRY_HEADERINFO_FC                       equ     00000400H
CACHE_ENTRY_EXEMPT_DELTA_FC                     equ     00000800H

INTERNET_CACHE_GROUP_ADD                        equ     0
INTERNET_CACHE_GROUP_REMOVE                     equ     1

INTERNET_DIAL_FORCE_PROMPT                      equ     2000H
INTERNET_DIAL_SHOW_OFFLINE                      equ     4000H
INTERNET_DIAL_UNATTENDED                        equ     8000H

INTERENT_GOONLINE_REFRESH                       equ     00000001H
INTERENT_GOONLINE_MASK                          equ     00000001H

INTERNET_AUTODIAL_FORCE_ONLINE                  equ     1
INTERNET_AUTODIAL_FORCE_UNATTENDED              equ     2
INTERNET_AUTODIAL_FAILIFSECURITYCHECK           equ     4
INTERNET_AUTODIAL_FLAGS_MASK                    equ     <INTERNET_AUTODIAL_FORCE_ONLINE or INTERNET_AUTODIAL_FORCE_UNATTENDED or INTERNET_AUTODIAL_FAILIFSECURITYCHECK>

INTERNET_CONNECTION_MODEM                       equ     01H
INTERNET_CONNECTION_LAN                         equ     02H
INTERNET_CONNECTION_PROXY                       equ     04H
INTERNET_CONNECTION_MODEM_BUSY                  equ     08H
INTERNET_RAS_INSTALLED                          equ     10H
INTERNET_CONNECTION_OFFLINE                     equ     20H
INTERNET_CONNECTION_CONFIGURED                  equ     40H

INTERNET_CUSTOMDIAL_CONNECT                     equ     0
INTERNET_CUSTOMDIAL_UNATTENDED                  equ     1
INTERNET_CUSTOMDIAL_DISCONNECT                  equ     2
INTERNET_CUSTOMDIAL_SHOWOFFLINE                 equ     4
INTERNET_CUSTOMDIAL_SAFE_FOR_UNATTENDED         equ     1
INTERNET_CUSTOMDIAL_WILL_SUPPLY_STATE           equ     2
INTERNET_CUSTOMDIAL_CAN_HANGUP                  equ     4

INTERNET_DIALSTATE_DISCONNECTED                 equ     1

INTERNET_SCHEME_PARTIAL                         equ     (-2)
INTERNET_SCHEME_UNKNOWN                         equ     (-1)
INTERNET_SCHEME_DEFAULT                         equ     0
INTERNET_SCHEME_FTP                             equ     1
INTERNET_SCHEME_GOPHER                          equ     2
INTERNET_SCHEME_HTTP                            equ     3
INTERNET_SCHEME_HTTPS                           equ     4
INTERNET_SCHEME_FILE                            equ     5
INTERNET_SCHEME_NEWS                            equ     6
INTERNET_SCHEME_MAILTO                          equ     7
INTERNET_SCHEME_SOCKS                           equ     8
INTERNET_SCHEME_JAVASCRIPT                      equ     9
INTERNET_SCHEME_VBSCRIPT                        equ     10
INTERNET_SCHEME_FIRST                           equ     INTERNET_SCHEME_FTP,
INTERNET_SCHEME_LAST                            equ     INTERNET_SCHEME_VBSCRIPT

#ifdef APP_UNICODE
    HTTP_VERSION                                equ     HTTP_VERSIONW
#else
    HTTP_VERSION                                equ     HTTP_VERSIONA
#endif

;======================================== Structures ======================================;
struc INTERNET_ASYNC_RESULT
    dwResult    dd  ?
    dwError     dd  ?
ends

struc INTERNET_PROXY_INFO
    dwAccessType    dd    ?
    lpszProxy       xword ?
    lpszProxyBypass xword ?
ends

struc INTERNET_PER_CONN_OPTIONA
    dwOption     dd   ?
    union
        dwValue  dd    ?
        pszValue xword ?
        ftValue  FILETIME ?
    endu
ends

struc INTERNET_PER_CONN_OPTIONW
    dwOption     dd   ?
    union
        dwValue  dd    ?
        pszValue xword ?
        ftValue  FILETIME ?
    endu
ends

struc INTERNET_PER_CONN_OPTION_LISTA
    dwSize        dd     ?
    pszConnection xword  ?
    dwOptionCount dd     ?
    dwOptionError dd     ?
    pOptions      xword  ?
ends

struc INTERNET_PER_CONN_OPTION_LISTW
    dwSize        dd     ?
    pszConnection xword  ?
    dwOptionCount dd     ?
    dwOptionError dd     ?
    pOptions      xword  ?
ends

struc INTERNET_VERSION_INFO
    dwMajorVersion dd ?
    dwMinorVersion dd ?
ends

struc HTTP_VERSION_INFO
    dwMajorVersion dd ?
    dwMinorVersion dd ?
ends

struc INTERNET_CONNECTED_INFO
    dwConnectedState dd ?
    dwFlags          dd ?
ends

struc URL_COMPONENTSA
    dwStructSize      dd    ?
    lpszScheme        xword ?
    dwSchemeLength    dd    ?
    nScheme           dd    ?
    lpszHostName      xword ?
    dwHostNameLength  dd    ?
    nPort             dd    ?
    lpszUserName      xword ?
    dwUserNameLength  dd    ?
    lpszPassword      xword ?
    dwPasswordLength  dd    ?
    lpszUrlPath       xword ?
    dwUrlPathLength   dd    ?
    lpszExtraInfo     xword ?
    dwExtraInfoLength dd    ?
ends

struc URL_COMPONENTSW
    dwStructSize      dd    ?
    lpszScheme        xword ?
    dwSchemeLength    dd    ?
    nScheme           dd    ?
    lpszHostName      xword ?
    dwHostNameLength  dd    ?
    nPort             dd    ?
    lpszUserName      xword ?
    dwUserNameLength  dd    ?
    lpszPassword      xword ?
    dwPasswordLength  dd    ?
    lpszUrlPath       xword ?
    dwUrlPathLength   dd    ?
    lpszExtraInfo     xword ?
    dwExtraInfoLength dd    ?
ends

struc INTERNET_CERTIFICATE_INFO
    ftExpiry              FILETIME ?
    ftStart               FILETIME ?
    lpszSubjectInfo       xword ?
    lpszIssuerInfo        xword ?
    lpszProtocolName      xword ?
    lpszSignatureAlgName  xword ?
    lpszEncryptionAlgName xword ?
    dwKeySize             dd    ?
ends

struc INTERNET_BUFFERSA
    dwStructSize    dd    ?
    Next            dd    ?
    lpcszHeader     xword ?
    dwHeadersLength dd    ?
    dwHeadersTotal  dd    ?
    lpvBuffer       xword ?
    dwBufferLength  dd    ?
    dwBufferTotal   dd    ?
    dwOffsetLow     dd    ?
    dwOffsetHigh    dd    ?
ends

struc INTERNET_BUFFERSW
    dwStructSize    dd    ?
    Next            dd    ?
    lpcszHeader     xword ?
    dwHeadersLength dd    ?
    dwHeadersTotal  dd    ?
    lpvBuffer       xword ?
    dwBufferLength  dd    ?
    dwBufferTotal   dd    ?
    dwOffsetLow     dd    ?
    dwOffsetHigh    dd    ?
ends

struc GOPHER_FIND_DATAA
    DisplayString        rb MAX_GOPHER_DISPLAY_TEXT+1
    GopherType           dd ?
    SizeLow              dd ?
    SizeHigh             dd ?
    LastModificationTime FILETIME ?
    Locator              rb MAX_GOPHER_LOCATOR_LENGTH+1
ends

struc GOPHER_FIND_DATAW
    DisplayString        rw MAX_GOPHER_DISPLAY_TEXT+1
    GopherType           dd ?
    SizeLow              dd ?
    SizeHigh             dd ?
    LastModificationTime FILETIME ?
    Locator              rw MAX_GOPHER_LOCATOR_LENGTH+1
ends

struc GOPHER_ADMIN_ATTRIBUTE_TYPE
    Comment      xword ?
    EmailAddress xword ?
ends

struc GOPHER_MOD_DATE_ATTRIBUTE_TYPE
    DateAndTime FILETIME ?
ends

struc GOPHER_TTL_ATTRIBUTE_TYPE
    Ttl dd ?
ends

struc GOPHER_SCORE_ATTRIBUTE_TYPE
    Score dd ?
ends

struc GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
    LowerBound dd ?
    UpperBound dd ?
ends

struc GOPHER_SITE_ATTRIBUTE_TYPE
    Site xword ?
ends

struc GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
    Organization xword ?
ends

struc GOPHER_LOCATION_ATTRIBUTE_TYPE
    Location xword ?
ends

struc GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
    DegreesNorth dd ?
    MinutesNorth dd ?
    SecondsNorth dd ?
    DegreesEast  dd ?
    MinutesEast  dd ?
    SecondsEast  dd ?
ends

struc GOPHER_TIMEZONE_ATTRIBUTE_TYPE
    Zone dd ?
ends

struc GOPHER_PROVIDER_ATTRIBUTE_TYPE
    Provider dd ?
ends

struc GOPHER_VERSION_ATTRIBUTE_TYPE
    Version dd ?
ends

struc GOPHER_ABSTRACT_ATTRIBUTE_TYPE
    ShortAbstract dd ?
    AbstractFile  dd ?
ends

struc GOPHER_VIEW_ATTRIBUTE_TYPE
    ContentType dd ?
    Language    dd ?
    Size        dd ?
ends

struc GOPHER_VERONICA_ATTRIBUTE_TYPE
    TreeWalk    dd ?
ends

struc GOPHER_ASK_ATTRIBUTE_TYPE
    QuestionType dd ?
    QuestionText dd ?
ends

struc GOPHER_UNKNOWN_ATTRIBUTE_TYPE
    Text  dd ?
ends

struc GOPHER_ATTRIBUTE_TYPE
    CategoryId  dd ?
    AttributeId dd ?
    union
        Admin                GOPHER_ADMIN_ATTRIBUTE_TYPE ?
        ModDate              GOPHER_MOD_DATE_ATTRIBUTE_TYPE ?
        Ttl                  GOPHER_TTL_ATTRIBUTE_TYPE ?
        Score                GOPHER_SCORE_ATTRIBUTE_TYPE ?
        ScoreRange           GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE ?
        Site                 GOPHER_SITE_ATTRIBUTE_TYPE ?
        Organization         GOPHER_ORGANIZATION_ATTRIBUTE_TYPE ?
        Location             GOPHER_LOCATION_ATTRIBUTE_TYPE ?
        GeographicalLocation GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE ?
        TimeZone             GOPHER_TIMEZONE_ATTRIBUTE_TYPE ?
        Provider             GOPHER_PROVIDER_ATTRIBUTE_TYPE ?
        Version              GOPHER_VERSION_ATTRIBUTE_TYPE ?
        Abstract             GOPHER_ABSTRACT_ATTRIBUTE_TYPE ?
        View                 GOPHER_VIEW_ATTRIBUTE_TYPE ?
        Veronica             GOPHER_VERONICA_ATTRIBUTE_TYPE ?
        Ask                  GOPHER_ASK_ATTRIBUTE_TYPE ?
        _Unknown             GOPHER_UNKNOWN_ATTRIBUTE_TYPE ?
    endu
ends

struc INTERNET_AUTH_NOTIFY_DATA
    cbStruct  dd    ?
    dwOptions dd    ?
    pfnNotify xword ?
    dwContext dd    ?
ends

struc INTERNET_CACHE_ENTRY_INFOA
    dwStructSize      dd    ?
    lpszSourceUrlName xword ?
    lpszLocalFileName xword ?
    CacheEntryType    dd    ?
    dwUseCount        dd    ?
    dwHitRate         dd    ?
    dwSizeLow         dd    ?
    dwSizeHigh        dd    ?
    LastModifiedTime  FILETIME ?
    ExpireTime        FILETIME ?
    LastAccessTime    FILETIME ?
    LastSyncTime      FILETIME ?
    lpHeaderInfo      xword ?
    dwHeaderInfoSize  dd    ?
    lpszFileExtension xword ?
    union
        dwReserved    dd   ?
        dwExemptDelta dd   ?
    endu
ends

struc INTERNET_CACHE_ENTRY_INFOW
    dwStructSize      dd    ?
    lpszSourceUrlName xword ?
    lpszLocalFileName xword ?
    CacheEntryType    dd    ?
    dwUseCount        dd    ?
    dwHitRate         dd    ?
    dwSizeLow         dd    ?
    dwSizeHigh        dd    ?
    LastModifiedTime  FILETIME ?
    ExpireTime        FILETIME ?
    LastAccessTime    FILETIME ?
    LastSyncTime      FILETIME ?
    lpHeaderInfo      xword ?
    dwHeaderInfoSize  dd    ?
    lpszFileExtension xword ?
    union
        dwReserved    dd    ?
        dwExemptDelta dd    ?
    endu
ends

struc INTERNET_CACHE_TIMESTAMPS
    ftExpires      FILETIME ?
    ftLastModified FILETIME ?
ends

struc INTERNET_CACHE_GROUP_INFOA
    dwGroupSize     dd ?
    dwGroupFlags    dd ?
    dwGroupType     dd ?
    dwDiskUsage     dd ?
    dwDiskQuota     dd ?
    dwOwnerStorage  rd GROUP_OWNER_STORAGE_SIZE
    szGroupName     rb GROUPNAME_MAX_LENGTH
ends

struc INTERNET_CACHE_GROUP_INFOW
    dwGroupSize     dd ?
    dwGroupFlags    dd ?
    dwGroupType     dd ?
    dwDiskUsage     dd ?
    dwDiskQuota     dd ?
    dwOwnerStorage  rd GROUP_OWNER_STORAGE_SIZE
    szGroupName     rw GROUPNAME_MAX_LENGTH
ends

#if NTDDI_VERSION > NTDDI_WIN8
    HEAP_OPTIMIZE_RESOURCES_CURRENT_VERSION     equ     1

    struc HEAP_OPTIMIZE_RESOURCES_INFORMATION
        Version dd  ?
        Flags   dd  ?
    ends
#endif

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib wininet.lib
#else
    from_dll wininet.dll
#endif

import CommitUrlCacheEntryA
import CommitUrlCacheEntryW
import CreateMD5SSOHash
import CreateUrlCacheContainerA
import CreateUrlCacheContainerW
import CreateUrlCacheEntryA
import CreateUrlCacheEntryW
import CreateUrlCacheGroup
import DeleteIE3Cache
import DeleteUrlCacheContainerA
import DeleteUrlCacheContainerW
import DeleteUrlCacheEntryA
import DeleteUrlCacheEntryW
import DeleteUrlCacheGroup
import DetectAutoProxyUrl
import FindCloseUrlCache
import FindFirstUrlCacheContainerA
import FindFirstUrlCacheContainerW
import FindFirstUrlCacheEntryA
import FindFirstUrlCacheEntryExA
import FindFirstUrlCacheEntryExW
import FindFirstUrlCacheEntryW
import FindFirstUrlCacheGroup
import FindNextUrlCacheContainerA
import FindNextUrlCacheContainerW
import FindNextUrlCacheEntryA
import FindNextUrlCacheEntryExA
import FindNextUrlCacheEntryExW
import FindNextUrlCacheEntryW
import FindNextUrlCacheGroup
import ForceNexusLookup
import ForceNexusLookupExW
import FreeUrlCacheSpaceA
import FreeUrlCacheSpaceW
import FtpCommandA
import FtpCommandW
import FtpCreateDirectoryA
import FtpCreateDirectoryW
import FtpDeleteFileA
import FtpDeleteFileW
import FtpFindFirstFileA
import FtpFindFirstFileW
import FtpGetCurrentDirectoryA
import FtpGetCurrentDirectoryW
import FtpGetFileA
import FtpGetFileEx
import FtpGetFileSize
import FtpGetFileW
import FtpOpenFileA
import FtpOpenFileW
import FtpPutFileA
import FtpPutFileEx
import FtpPutFileW
import FtpRemoveDirectoryA
import FtpRemoveDirectoryW
import FtpRenameFileA
import FtpRenameFileW
import FtpSetCurrentDirectoryA
import FtpSetCurrentDirectoryW
import GetUrlCacheConfigInfoA
import GetUrlCacheConfigInfoW
import GetUrlCacheEntryInfoA
import GetUrlCacheEntryInfoExA
import GetUrlCacheEntryInfoExW
import GetUrlCacheEntryInfoW
import GetUrlCacheGroupAttributeA
import GetUrlCacheGroupAttributeW
import GetUrlCacheHeaderData
import GopherCreateLocatorA
import GopherCreateLocatorW
import GopherFindFirstFileA
import GopherFindFirstFileW
import GopherGetAttributeA
import GopherGetAttributeW
import GopherGetLocatorTypeA
import GopherGetLocatorTypeW
import GopherOpenFileA
import GopherOpenFileW
import HttpAddRequestHeadersA
import HttpAddRequestHeadersW
import HttpCheckDavCompliance
import HttpEndRequestA
import HttpEndRequestW
import HttpOpenRequestA
import HttpOpenRequestW
#if NTDDI_VERSION >= NTDDI_WIN7
    import HttpPushClose
    import HttpPushEnable
    import HttpPushWait
#endif
import HttpQueryInfoA
import HttpQueryInfoW
import HttpSendRequestA
import HttpSendRequestExA
import HttpSendRequestExW
import HttpSendRequestW
#if NTDDI_VERSION >= NTDDI_WIN7
    import HttpWebSocketCompleteUpgrade
    import HttpWebSocketQueryCloseStatus
    import HttpWebSocketReceive
    import HttpWebSocketSend
    import HttpWebSocketShutdown
#endif
import IncrementUrlCacheHeaderData
import InternetAlgIdToStringA
import InternetAlgIdToStringW
import InternetAttemptConnect
import InternetAutodial
import InternetAutodialCallback
import InternetAutodialHangup
import InternetCanonicalizeUrlA
import InternetCanonicalizeUrlW
import InternetCheckConnectionA
import InternetCheckConnectionW
import InternetClearAllPerSiteCookieDecisions
import InternetCloseHandle
import InternetCombineUrlA
import InternetCombineUrlW
import InternetConfirmZoneCrossingA
import InternetConfirmZoneCrossingW
import InternetConnectA
import InternetConnectW
import InternetCrackUrlA
import InternetCrackUrlW
import InternetCreateUrlA
import InternetCreateUrlW
import InternetDialA
import InternetDialW
import InternetEnumPerSiteCookieDecisionA
import InternetEnumPerSiteCookieDecisionW
import InternetErrorDlg
import InternetFindNextFileA
import InternetFindNextFileW
import InternetFortezzaCommand
#if NTDDI_VERSION >= NTDDI_WIN7
    import InternetFreeProxyInfoList
#endif
import InternetGetCertByURL
import InternetGetCertByURLA
import InternetGetConnectedState
import InternetGetConnectedStateExA
import InternetGetConnectedStateExW
import InternetGetCookieA
import InternetGetCookieExA
import InternetGetCookieExW
import InternetGetCookieW
import InternetGetLastResponseInfoA
import InternetGetLastResponseInfoW
import InternetGetPerSiteCookieDecisionA
import InternetGetPerSiteCookieDecisionW
#if NTDDI_VERSION >= NTDDI_WIN7
    import InternetGetProxyForUrl
#endif
import InternetGetSecurityInfoByURLA
import InternetGetSecurityInfoByURLW
import InternetGoOnlineA
import InternetGoOnlineW
import InternetHangUp
import InternetInitializeAutoProxyDll
import InternetLockRequestFile
import InternetOpenA
import InternetOpenUrlA
import InternetOpenUrlW
import InternetOpenW
import InternetQueryDataAvailable
import InternetQueryFortezzaStatus
import InternetQueryOptionA
import InternetQueryOptionW
import InternetReadFile
import InternetReadFileExA
import InternetReadFileExW
import InternetSecurityProtocolToStringA
import InternetSecurityProtocolToStringW
import InternetSetCookieA
import InternetSetCookieExA
import InternetSetCookieExW
import InternetSetCookieW
import InternetSetDialStateA
import InternetSetDialStateW
import InternetSetFilePointer
import InternetSetOptionA
import InternetSetOptionExA
import InternetSetOptionExW
import InternetSetOptionW
import InternetSetPerSiteCookieDecisionA
import InternetSetPerSiteCookieDecisionW
import InternetSetStatusCallbackA
import InternetSetStatusCallbackW
import InternetShowSecurityInfoByURLA
import InternetShowSecurityInfoByURLW
import InternetTimeFromSystemTimeA
import InternetTimeFromSystemTimeW
import InternetTimeToSystemTimeA
import InternetTimeToSystemTimeW
import InternetUnlockRequestFile
import InternetWriteFile
import InternetWriteFileExA
import InternetWriteFileExW
import IsHostInProxyBypassList
import IsUrlCacheEntryExpiredA
import IsUrlCacheEntryExpiredW
import LoadUrlCacheContent
import ParseX509EncodedCertificateForListBoxEntry
import PrivacyGetZonePreferenceW
import PrivacySetZonePreferenceW
import ReadUrlCacheEntryStream
import RegisterUrlCacheNotification
import ResumeSuspendedDownload
import RetrieveUrlCacheEntryFileA
import RetrieveUrlCacheEntryFileW
import RetrieveUrlCacheEntryStreamA
import RetrieveUrlCacheEntryStreamW
import RunOnceUrlCache
import SetUrlCacheConfigInfoA
import SetUrlCacheConfigInfoW
import SetUrlCacheEntryGroupA
import SetUrlCacheEntryGroupW
import SetUrlCacheEntryInfoA
import SetUrlCacheEntryInfoW
import SetUrlCacheGroupAttributeA
import SetUrlCacheGroupAttributeW
import SetUrlCacheHeaderData
import ShowCertificate
import ShowClientAuthCerts
import ShowSecurityInfo
import ShowX509EncodedCertificate
import UnlockUrlCacheEntryFileA
import UnlockUrlCacheEntryFileW
import UnlockUrlCacheEntryStream
import UpdateUrlCacheContentPath
#if NTDDI_VERSION >= NTDDI_WIN7
    import UrlCacheCheckEntriesExist
    import UrlCacheCloseEntryHandle
    import UrlCacheCreateContainer
    import UrlCacheFreeEntryInfo
    import UrlCacheGetEntryInfo
    import UrlCacheGetGlobalLimit
    import UrlCacheRetrieveEntryFile
    import UrlCacheSetGlobalLimit
    import UrlCacheUpdateEntryExtraData
#endif
import UrlZonesDetach

#ifdef APP_UNICODE
	define INTERNET_PER_CONN_OPTION INTERNET_PER_CONN_OPTIONW
    define INTERNET_PER_CONN_OPTION_LIST INTERNET_PER_CONN_OPTION_LISTW
    define URL_COMPONENTS URL_COMPONENTSW
    define INTERNET_BUFFERS INTERNET_BUFFERSW
    define GOPHER_FIND_DATA GOPHER_FIND_DATAW
    define INTERNET_CACHE_ENTRY_INFO INTERNET_CACHE_ENTRY_INFOW
    define INTERNET_CACHE_GROUP_INFO INTERNET_CACHE_GROUP_INFOW
    define CommitUrlCacheEntry CommitUrlCacheEntryW
    define CreateUrlCacheContainer CreateUrlCacheContainerW
    define CreateUrlCacheEntry CreateUrlCacheEntryW
    define DeleteUrlCacheContainer DeleteUrlCacheContainerW
    define DeleteUrlCacheEntry DeleteUrlCacheEntryW
    define FindFirstUrlCacheContainer FindFirstUrlCacheContainerW
    define FindFirstUrlCacheEntry FindFirstUrlCacheEntryW
    define FindFirstUrlCacheEntryEx FindFirstUrlCacheEntryExW
    define FindNextUrlCacheContainer FindNextUrlCacheContainerW
    define FindNextUrlCacheEntry FindNextUrlCacheEntryW
    define FindNextUrlCacheEntryEx FindNextUrlCacheEntryExW
    define FreeUrlCacheSpace FreeUrlCacheSpaceW
    define FtpCommand FtpCommandW
    define FtpCreateDirectory FtpCreateDirectoryW
    define FtpDeleteFile FtpDeleteFileW
    define FtpFindFirstFile FtpFindFirstFileW
    define FtpGetCurrentDirectory FtpGetCurrentDirectoryW
    define FtpGetFile FtpGetFileW
    define FtpOpenFile FtpOpenFileW
    define FtpPutFile FtpPutFileW
    define FtpRemoveDirectory FtpRemoveDirectoryW
    define FtpRenameFile FtpRenameFileW
    define FtpSetCurrentDirectory FtpSetCurrentDirectoryW
    define GetUrlCacheConfigInfo GetUrlCacheConfigInfoW
    define GetUrlCacheEntryInfo GetUrlCacheEntryInfoW
    define GetUrlCacheEntryInfoEx GetUrlCacheEntryInfoExW
    define GetUrlCacheGroupAttribute GetUrlCacheGroupAttributeW
    define GopherCreateLocator GopherCreateLocatorW
    define GopherFindFirstFile GopherFindFirstFileW
    define GopherGetAttribute GopherGetAttributeW
    define GopherGetLocatorType GopherGetLocatorTypeW
    define GopherOpenFile GopherOpenFileW
    define HttpAddRequestHeaders HttpAddRequestHeadersW
    define HttpCheckDavCompliance HttpCheckDavComplianceW
    define HttpEndRequest HttpEndRequestW
    define HttpOpenRequest HttpOpenRequestW
    define HttpQueryInfo HttpQueryInfoW
    define HttpSendRequest HttpSendRequestW
    define HttpSendRequestEx HttpSendRequestExW
    define InternetAlgIdToString InternetAlgIdToStringW
    define InternetCanonicalizeUrl InternetCanonicalizeUrlW
    define InternetCheckConnection InternetCheckConnectionW
    define InternetCombineUrl InternetCombineUrlW
    define InternetConfirmZoneCrossing InternetConfirmZoneCrossingW
    define InternetConnect InternetConnectW
    define InternetCrackUrl InternetCrackUrlW
    define InternetCreateUrl InternetCreateUrlW
    define InternetDial InternetDialW
    define InternetEnumPerSiteCookieDecision InternetEnumPerSiteCookieDecisionW
    define InternetFindNextFile InternetFindNextFileW
    define InternetGetConnectedStateEx InternetGetConnectedStateExW
    define InternetGetCookie InternetGetCookieW
    define InternetGetCookieEx InternetGetCookieExW
    define InternetGetLastResponseInfo InternetGetLastResponseInfoW
    define InternetGetPerSiteCookieDecision InternetGetPerSiteCookieDecisionW
    define InternetGetSecurityInfoByURL InternetGetSecurityInfoByURLW
    define InternetGoOnline InternetGoOnlineW
    define InternetOpen InternetOpenW
    define InternetOpenUrl InternetOpenUrlW
    define InternetQueryOption InternetQueryOptionW
    define InternetReadFileEx InternetReadFileExW
    define InternetSecurityProtocolToString InternetSecurityProtocolToStringW
    define InternetSetCookie InternetSetCookieW
    define InternetSetCookieEx InternetSetCookieExW
    define InternetSetDialState InternetSetDialStateW
    define InternetSetOption InternetSetOptionW
    define InternetSetOptionEx InternetSetOptionExW
    define InternetSetPerSiteCookieDecision InternetSetPerSiteCookieDecisionW
    define InternetSetStatusCallback InternetSetStatusCallbackW
    define InternetShowSecurityInfoByURL InternetShowSecurityInfoByURLW
    define InternetTimeFromSystemTime InternetTimeFromSystemTimeW
    define InternetTimeToSystemTime InternetTimeToSystemTimeW
    define InternetWriteFileEx InternetWriteFileExW
    define IsUrlCacheEntryExpired IsUrlCacheEntryExpiredW
    define RetrieveUrlCacheEntryFile RetrieveUrlCacheEntryFileW
    define RetrieveUrlCacheEntryStream RetrieveUrlCacheEntryStreamW
    define SetUrlCacheConfigInfo SetUrlCacheConfigInfoW
    define SetUrlCacheEntryGroup SetUrlCacheEntryGroupW
    define SetUrlCacheEntryInfo SetUrlCacheEntryInfoW
    define SetUrlCacheGroupAttribute SetUrlCacheGroupAttributeW
    define UnlockUrlCacheEntryFile UnlockUrlCacheEntryFileW
#else
	define INTERNET_PER_CONN_OPTION INTERNET_PER_CONN_OPTIONA
    define INTERNET_PER_CONN_OPTION_LIST INTERNET_PER_CONN_OPTION_LISTA
    define URL_COMPONENTS URL_COMPONENTSA
    define INTERNET_BUFFERS INTERNET_BUFFERSA
    define GOPHER_FIND_DATA GOPHER_FIND_DATAA
    define INTERNET_CACHE_ENTRY_INFO INTERNET_CACHE_ENTRY_INFOA
    define INTERNET_CACHE_GROUP_INFO INTERNET_CACHE_GROUP_INFOA
    define CommitUrlCacheEntry CommitUrlCacheEntryA
    define CreateUrlCacheContainer CreateUrlCacheContainerA
    define CreateUrlCacheEntry CreateUrlCacheEntryA
    define DeleteUrlCacheContainer DeleteUrlCacheContainerA
    define DeleteUrlCacheEntry DeleteUrlCacheEntryA
    define FindFirstUrlCacheContainer FindFirstUrlCacheContainerA
    define FindFirstUrlCacheEntry FindFirstUrlCacheEntryA
    define FindFirstUrlCacheEntryEx FindFirstUrlCacheEntryExA
    define FindNextUrlCacheContainer FindNextUrlCacheContainerA
    define FindNextUrlCacheEntry FindNextUrlCacheEntryA
    define FindNextUrlCacheEntryEx FindNextUrlCacheEntryExA
    define FreeUrlCacheSpace FreeUrlCacheSpaceA
    define FtpCommand FtpCommandA
    define FtpCreateDirectory FtpCreateDirectoryA
    define FtpDeleteFile FtpDeleteFileA
    define FtpFindFirstFile FtpFindFirstFileA
    define FtpGetCurrentDirectory FtpGetCurrentDirectoryA
    define FtpGetFile FtpGetFileA
    define FtpOpenFile FtpOpenFileA
    define FtpPutFile FtpPutFileA
    define FtpRemoveDirectory FtpRemoveDirectoryA
    define FtpRenameFile FtpRenameFileA
    define FtpSetCurrentDirectory FtpSetCurrentDirectoryA
    define GetUrlCacheConfigInfo GetUrlCacheConfigInfoA
    define GetUrlCacheEntryInfo GetUrlCacheEntryInfoA
    define GetUrlCacheEntryInfoEx GetUrlCacheEntryInfoExA
    define GetUrlCacheGroupAttribute GetUrlCacheGroupAttributeA
    define GopherCreateLocator GopherCreateLocatorA
    define GopherFindFirstFile GopherFindFirstFileA
    define GopherGetAttribute GopherGetAttributeA
    define GopherGetLocatorType GopherGetLocatorTypeA
    define GopherOpenFile GopherOpenFileA
    define HttpAddRequestHeaders HttpAddRequestHeadersA
    define HttpCheckDavCompliance HttpCheckDavComplianceA
    define HttpEndRequest HttpEndRequestA
    define HttpOpenRequest HttpOpenRequestA
    define HttpQueryInfo HttpQueryInfoA
    define HttpSendRequest HttpSendRequestA
    define HttpSendRequestEx HttpSendRequestExA
    define InternetAlgIdToString InternetAlgIdToStringA
    define InternetCanonicalizeUrl InternetCanonicalizeUrlA
    define InternetCheckConnection InternetCheckConnectionA
    define InternetCombineUrl InternetCombineUrlA
    define InternetConfirmZoneCrossing InternetConfirmZoneCrossingA
    define InternetConnect InternetConnectA
    define InternetCrackUrl InternetCrackUrlA
    define InternetCreateUrl InternetCreateUrlA
    define InternetDial InternetDialA
    define InternetEnumPerSiteCookieDecision InternetEnumPerSiteCookieDecisionA
    define InternetFindNextFile InternetFindNextFileA
    define InternetGetConnectedStateEx InternetGetConnectedStateExA
    define InternetGetCookie InternetGetCookieA
    define InternetGetCookieEx InternetGetCookieExA
    define InternetGetLastResponseInfo InternetGetLastResponseInfoA
    define InternetGetPerSiteCookieDecision InternetGetPerSiteCookieDecisionA
    define InternetGetSecurityInfoByURL InternetGetSecurityInfoByURLA
    define InternetGoOnline InternetGoOnlineA
    define InternetOpen InternetOpenA
    define InternetOpenUrl InternetOpenUrlA
    define InternetQueryOption InternetQueryOptionA
    define InternetReadFileEx InternetReadFileExA
    define InternetSecurityProtocolToString InternetSecurityProtocolToStringA
    define InternetSetCookie InternetSetCookieA
    define InternetSetCookieEx InternetSetCookieExA
    define InternetSetDialState InternetSetDialStateA
    define InternetSetOption InternetSetOptionA
    define InternetSetOptionEx InternetSetOptionExA
    define InternetSetPerSiteCookieDecision InternetSetPerSiteCookieDecisionA
    define InternetSetStatusCallback InternetSetStatusCallbackA
    define InternetShowSecurityInfoByURL InternetShowSecurityInfoByURLA
    define InternetTimeFromSystemTime InternetTimeFromSystemTimeA
    define InternetTimeToSystemTime InternetTimeToSystemTimeA
    define InternetWriteFileEx InternetWriteFileExA
    define IsUrlCacheEntryExpired IsUrlCacheEntryExpiredA
    define RetrieveUrlCacheEntryFile RetrieveUrlCacheEntryFileA
    define RetrieveUrlCacheEntryStream RetrieveUrlCacheEntryStreamA
    define SetUrlCacheConfigInfo SetUrlCacheConfigInfoA
    define SetUrlCacheEntryGroup SetUrlCacheEntryGroupA
    define SetUrlCacheEntryInfo SetUrlCacheEntryInfoA
    define SetUrlCacheGroupAttribute SetUrlCacheGroupAttributeA
    define UnlockUrlCacheEntryFile UnlockUrlCacheEntryFileA
#endif

#endif ;WININET_INC
