; ====================================================;
;                                                     ;
;     wininet.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.5)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined WININET_INC
define WININET_INC 1

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
INTERNET_MAX_URL_LENGTH                         equ     (INTERNET_MAX_SCHEME_LENGTH + 2 or INTERNET_MAX_PATH_LENGTH)

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
FTP_TRANSFER_TYPE_MASK                          equ     (FTP_TRANSFER_TYPE_ASCII or FTP_TRANSFER_TYPE_BINARY)

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

SECURITY_INTERNET_MASK                          equ     (INTERNET_FLAG_IGNORE_CERT_CN_INVALID or INTERNET_FLAG_IGNORE_CERT_DATE_INVALID or INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS or INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP)
INTERNET_FLAGS_MASK                             equ     (INTERNET_FLAG_RELOAD or INTERNET_FLAG_RAW_DATA or INTERNET_FLAG_EXISTING_CONNECT or INTERNET_FLAG_ASYNC or INTERNET_FLAG_PASSIVE or INTERNET_FLAG_NO_CACHE_WRITE or \
                                                        INTERNET_FLAG_MAKE_PERSISTENT or INTERNET_FLAG_FROM_CACHE or INTERNET_FLAG_SECURE or INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_AUTO_REDIRECT or INTERNET_FLAG_READ_PREFETCH or \
                                                        INTERNET_FLAG_NO_COOKIES or INTERNET_FLAG_NO_AUTH or INTERNET_FLAG_CACHE_IF_NET_FAIL or SECURITY_INTERNET_MASK or INTERNET_FLAG_RESYNCHRONIZE or INTERNET_FLAG_HYPERLINK or INTERNET_FLAG_NO_UI or \
                                                        INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_CACHE_ASYNC or INTERNET_FLAG_FORMS_SUBMIT or INTERNET_FLAG_NEED_FILE or INTERNET_FLAG_TRANSFER_BINARY or INTERNET_FLAG_TRANSFER_ASCII or \
                                                        INTERNET_FLAG_FWD_BACK or INTERNET_FLAG_BGUPDATE)

INTERNET_ERROR_MASK_INSERT_CDROM                equ     01H
INTERNET_ERROR_MASK_COMBINED_SEC_CERT           equ     02H
INTERNET_ERROR_MASK_NEED_MSN_SSPI_PKG           equ     04H
INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY equ   08H
INTERNET_OPTIONS_MASK                           equ     (not INTERNET_FLAGS_MASK)

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
ISO_VALID_FLAGS                                 equ     (ISO_GLOBAL or ISO_REGISTRY)

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
SECURITY_SET_MASK                               equ     (SECURITY_FLAG_IGNORE_REVOCATION or SECURITY_FLAG_IGNORE_UNKNOWN_CA or SECURITY_FLAG_IGNORE_CERT_CN_INVALID or SECURITY_FLAG_IGNORE_CERT_DATE_INVALID or SECURITY_FLAG_IGNORE_WRONG_USAGE)

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
MAX_GOPHER_LOCATOR_LENGTH                       equ     (1 + MAX_GOPHER_DISPLAY_TEXT + 1 + MAX_GOPHER_SELECTOR_TEXT + 1 + MAX_GOPHER_HOST_NAME + 1 + INTERNET_MAX_PORT_NUMBER_LENGTH + 1 + 1 + 2)

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

GOPHER_TYPE_FILE_MASK                           equ     (GOPHER_TYPE_TEXT_FILE or GOPHER_TYPE_MAC_BINHEX or GOPHER_TYPE_DOS_ARCHIVE or GOPHER_TYPE_UNIX_UUENCODED or GOPHER_TYPE_BINARY or GOPHER_TYPE_GIF or \
                                                        GOPHER_TYPE_IMAGE or GOPHER_TYPE_BITMAP or GOPHER_TYPE_MOVIE or GOPHER_TYPE_SOUND or GOPHER_TYPE_HTML or GOPHER_TYPE_PDF or GOPHER_TYPE_CALENDAR or GOPHER_TYPE_INLINE)

MAX_GOPHER_CATEGORY_NAME                        equ     128
MAX_GOPHER_ATTRIBUTE_NAME                       equ     128
MIN_GOPHER_ATTRIBUTE_LENGTH                     equ     256

GOPHER_INFO_CATEGORY                            equ     '+INFO'
GOPHER_ADMIN_CATEGORY                           equ     '+ADMIN'
GOPHER_VIEWS_CATEGORY                           equ     '+VIEWS'
GOPHER_ABSTRACT_CATEGORY                        equ     '+ABSTRACT'
GOPHER_VERONICA_CATEGORY                        equ     '+VERONICA'
GOPHER_ADMIN_ATTRIBUTE                          equ     'Admin'
GOPHER_MOD_DATE_ATTRIBUTE                       equ     'Mod-Date'
GOPHER_TTL_ATTRIBUTE                            equ     'TTL'
GOPHER_SCORE_ATTRIBUTE                          equ     'Score'
GOPHER_RANGE_ATTRIBUTE                          equ     'Score-range'
GOPHER_SITE_ATTRIBUTE                           equ     'Site'
GOPHER_ORG_ATTRIBUTE                            equ     'Org'
GOPHER_LOCATION_ATTRIBUTE                       equ     'Loc'
GOPHER_GEOG_ATTRIBUTE                           equ     'Geog'
GOPHER_TIMEZONE_ATTRIBUTE                       equ     'TZ'
GOPHER_PROVIDER_ATTRIBUTE                       equ     'Provider'
GOPHER_VERSION_ATTRIBUTE                        equ     'Version'
GOPHER_ABSTRACT_ATTRIBUTE                       equ     'Abstract'
GOPHER_VIEW_ATTRIBUTE                           equ     'View'
GOPHER_TREEWALK_ATTRIBUTE                       equ     'treewalk'

GOPHER_ATTRIBUTE_ID_BASE                        equ     0ABCCCC00H
GOPHER_CATEGORY_ID_ALL                          equ     (GOPHER_ATTRIBUTE_ID_BASE + 1)
GOPHER_CATEGORY_ID_INFO                         equ     (GOPHER_ATTRIBUTE_ID_BASE + 2)
GOPHER_CATEGORY_ID_ADMIN                        equ     (GOPHER_ATTRIBUTE_ID_BASE + 3)
GOPHER_CATEGORY_ID_VIEWS                        equ     (GOPHER_ATTRIBUTE_ID_BASE + 4)
GOPHER_CATEGORY_ID_ABSTRACT                     equ     (GOPHER_ATTRIBUTE_ID_BASE + 5)
GOPHER_CATEGORY_ID_VERONICA                     equ     (GOPHER_ATTRIBUTE_ID_BASE + 6)
GOPHER_CATEGORY_ID_ASK                          equ     (GOPHER_ATTRIBUTE_ID_BASE + 7)
GOPHER_CATEGORY_ID_UNKNOWN                      equ     (GOPHER_ATTRIBUTE_ID_BASE + 8)
GOPHER_ATTRIBUTE_ID_ALL                         equ     (GOPHER_ATTRIBUTE_ID_BASE + 9)
GOPHER_ATTRIBUTE_ID_ADMIN                       equ     (GOPHER_ATTRIBUTE_ID_BASE + 10)
GOPHER_ATTRIBUTE_ID_MOD_DATE                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 11)
GOPHER_ATTRIBUTE_ID_TTL                         equ     (GOPHER_ATTRIBUTE_ID_BASE + 12)
GOPHER_ATTRIBUTE_ID_SCORE                       equ     (GOPHER_ATTRIBUTE_ID_BASE + 13)
GOPHER_ATTRIBUTE_ID_RANGE                       equ     (GOPHER_ATTRIBUTE_ID_BASE + 14)
GOPHER_ATTRIBUTE_ID_SITE                        equ     (GOPHER_ATTRIBUTE_ID_BASE + 15)
GOPHER_ATTRIBUTE_ID_ORG                         equ     (GOPHER_ATTRIBUTE_ID_BASE + 16)
GOPHER_ATTRIBUTE_ID_LOCATION                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 17)
GOPHER_ATTRIBUTE_ID_GEOG                        equ     (GOPHER_ATTRIBUTE_ID_BASE + 18)
GOPHER_ATTRIBUTE_ID_TIMEZONE                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 19)
GOPHER_ATTRIBUTE_ID_PROVIDER                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 20)
GOPHER_ATTRIBUTE_ID_VERSION                     equ     (GOPHER_ATTRIBUTE_ID_BASE + 21)
GOPHER_ATTRIBUTE_ID_ABSTRACT                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 22)
GOPHER_ATTRIBUTE_ID_VIEW                        equ     (GOPHER_ATTRIBUTE_ID_BASE + 23)
GOPHER_ATTRIBUTE_ID_TREEWALK                    equ     (GOPHER_ATTRIBUTE_ID_BASE + 24)
GOPHER_ATTRIBUTE_ID_UNKNOWN                     equ     (GOPHER_ATTRIBUTE_ID_BASE + 25)

HTTP_MAJOR_VERSION                              equ     1
HTTP_MINOR_VERSION                              equ     0
HTTP_VERSIONA                                   equ     'HTTP/1.0'
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
HTTP_QUERY_MODIFIER_FLAGS_MASK                  equ     (HTTP_QUERY_FLAG_REQUEST_HEADERS or HTTP_QUERY_FLAG_SYSTEMTIME or HTTP_QUERY_FLAG_NUMBER or HTTP_QUERY_FLAG_COALESCE)
HTTP_QUERY_HEADER_MASK                          equ     (not HTTP_QUERY_MODIFIER_FLAGS_MASK)

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

INTERNET_ERROR_BASE                             equ     12000
ERROR_INTERNET_OUT_OF_HANDLES                   equ     (INTERNET_ERROR_BASE + 1)
ERROR_INTERNET_TIMEOUT                          equ     (INTERNET_ERROR_BASE + 2)
ERROR_INTERNET_EXTENDED_ERROR                   equ     (INTERNET_ERROR_BASE + 3)
ERROR_INTERNET_INTERNAL_ERROR                   equ     (INTERNET_ERROR_BASE + 4)
ERROR_INTERNET_INVALID_URL                      equ     (INTERNET_ERROR_BASE + 5)
ERROR_INTERNET_UNRECOGNIZED_SCHEME              equ     (INTERNET_ERROR_BASE + 6)
ERROR_INTERNET_NAME_NOT_RESOLVED                equ     (INTERNET_ERROR_BASE + 7)
ERROR_INTERNET_PROTOCOL_NOT_FOUND               equ     (INTERNET_ERROR_BASE + 8)
ERROR_INTERNET_INVALID_OPTION                   equ     (INTERNET_ERROR_BASE + 9)
ERROR_INTERNET_BAD_OPTION_LENGTH                equ     (INTERNET_ERROR_BASE + 10)
ERROR_INTERNET_OPTION_NOT_SETTABLE              equ     (INTERNET_ERROR_BASE + 11)
ERROR_INTERNET_SHUTDOWN                         equ     (INTERNET_ERROR_BASE + 12)
ERROR_INTERNET_INCORRECT_USER_NAME              equ     (INTERNET_ERROR_BASE + 13)
ERROR_INTERNET_INCORRECT_PASSWORD               equ     (INTERNET_ERROR_BASE + 14)
ERROR_INTERNET_LOGIN_FAILURE                    equ     (INTERNET_ERROR_BASE + 15)
ERROR_INTERNET_INVALID_OPERATION                equ     (INTERNET_ERROR_BASE + 16)
ERROR_INTERNET_OPERATION_CANCELLED              equ     (INTERNET_ERROR_BASE + 17)
ERROR_INTERNET_INCORRECT_HANDLE_TYPE            equ     (INTERNET_ERROR_BASE + 18)
ERROR_INTERNET_INCORRECT_HANDLE_STATE           equ     (INTERNET_ERROR_BASE + 19)
ERROR_INTERNET_NOT_PROXY_REQUEST                equ     (INTERNET_ERROR_BASE + 20)
ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND         equ     (INTERNET_ERROR_BASE + 21)
ERROR_INTERNET_BAD_REGISTRY_PARAMETER           equ     (INTERNET_ERROR_BASE + 22)
ERROR_INTERNET_NO_DIRECT_ACCESS                 equ     (INTERNET_ERROR_BASE + 23)
ERROR_INTERNET_NO_CONTEXT                       equ     (INTERNET_ERROR_BASE + 24)
ERROR_INTERNET_NO_CALLBACK                      equ     (INTERNET_ERROR_BASE + 25)
ERROR_INTERNET_REQUEST_PENDING                  equ     (INTERNET_ERROR_BASE + 26)
ERROR_INTERNET_INCORRECT_FORMAT                 equ     (INTERNET_ERROR_BASE + 27)
ERROR_INTERNET_ITEM_NOT_FOUND                   equ     (INTERNET_ERROR_BASE + 28)
ERROR_INTERNET_CANNOT_CONNECT                   equ     (INTERNET_ERROR_BASE + 29)
ERROR_INTERNET_CONNECTION_ABORTED               equ     (INTERNET_ERROR_BASE + 30)
ERROR_INTERNET_CONNECTION_RESET                 equ     (INTERNET_ERROR_BASE + 31)
ERROR_INTERNET_FORCE_RETRY                      equ     (INTERNET_ERROR_BASE + 32)
ERROR_INTERNET_INVALID_PROXY_REQUEST            equ     (INTERNET_ERROR_BASE + 33)
ERROR_INTERNET_NEED_UI                          equ     (INTERNET_ERROR_BASE + 34)
ERROR_INTERNET_HANDLE_EXISTS                    equ     (INTERNET_ERROR_BASE + 36)
ERROR_INTERNET_SEC_CERT_DATE_INVALID            equ     (INTERNET_ERROR_BASE + 37)
ERROR_INTERNET_SEC_CERT_CN_INVALID              equ     (INTERNET_ERROR_BASE + 38)
ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR           equ     (INTERNET_ERROR_BASE + 39)
ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR           equ     (INTERNET_ERROR_BASE + 40)
ERROR_INTERNET_MIXED_SECURITY                   equ     (INTERNET_ERROR_BASE + 41)
ERROR_INTERNET_CHG_POST_IS_NON_SECURE           equ     (INTERNET_ERROR_BASE + 42)
ERROR_INTERNET_POST_IS_NON_SECURE               equ     (INTERNET_ERROR_BASE + 43)
ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED          equ     (INTERNET_ERROR_BASE + 44)
ERROR_INTERNET_INVALID_CA                       equ     (INTERNET_ERROR_BASE + 45)
ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP            equ     (INTERNET_ERROR_BASE + 46)
ERROR_INTERNET_ASYNC_THREAD_FAILED              equ     (INTERNET_ERROR_BASE + 47)
ERROR_INTERNET_REDIRECT_SCHEME_CHANGE           equ     (INTERNET_ERROR_BASE + 48)
ERROR_INTERNET_DIALOG_PENDING                   equ     (INTERNET_ERROR_BASE + 49)
ERROR_INTERNET_RETRY_DIALOG                     equ     (INTERNET_ERROR_BASE + 50)
ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR          equ     (INTERNET_ERROR_BASE + 52)
ERROR_INTERNET_INSERT_CDROM                     equ     (INTERNET_ERROR_BASE + 53)
ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED            equ     (INTERNET_ERROR_BASE + 54)
ERROR_INTERNET_SEC_CERT_ERRORS                  equ     (INTERNET_ERROR_BASE + 55)
ERROR_INTERNET_SEC_CERT_NO_REV                  equ     (INTERNET_ERROR_BASE + 56)
ERROR_INTERNET_SEC_CERT_REV_FAILED              equ     (INTERNET_ERROR_BASE + 57)
ERROR_FTP_TRANSFER_IN_PROGRESS                  equ     (INTERNET_ERROR_BASE + 110)
ERROR_FTP_DROPPED                               equ     (INTERNET_ERROR_BASE + 111)
ERROR_FTP_NO_PASSIVE_MODE                       equ     (INTERNET_ERROR_BASE + 112)
ERROR_GOPHER_PROTOCOL_ERROR                     equ     (INTERNET_ERROR_BASE + 130)
ERROR_GOPHER_NOT_FILE                           equ     (INTERNET_ERROR_BASE + 131)
ERROR_GOPHER_DATA_ERROR                         equ     (INTERNET_ERROR_BASE + 132)
ERROR_GOPHER_END_OF_DATA                        equ     (INTERNET_ERROR_BASE + 133)
ERROR_GOPHER_INVALID_LOCATOR                    equ     (INTERNET_ERROR_BASE + 134)
ERROR_GOPHER_INCORRECT_LOCATOR_TYPE             equ     (INTERNET_ERROR_BASE + 135)
ERROR_GOPHER_NOT_GOPHER_PLUS                    equ     (INTERNET_ERROR_BASE + 136)
ERROR_GOPHER_ATTRIBUTE_NOT_FOUND                equ     (INTERNET_ERROR_BASE + 137)
ERROR_GOPHER_UNKNOWN_LOCATOR                    equ     (INTERNET_ERROR_BASE + 138)
ERROR_HTTP_HEADER_NOT_FOUND                     equ     (INTERNET_ERROR_BASE + 150)
ERROR_HTTP_DOWNLEVEL_SERVER                     equ     (INTERNET_ERROR_BASE + 151)
ERROR_HTTP_INVALID_SERVER_RESPONSE              equ     (INTERNET_ERROR_BASE + 152)
ERROR_HTTP_INVALID_HEADER                       equ     (INTERNET_ERROR_BASE + 153)
ERROR_HTTP_INVALID_QUERY_REQUEST                equ     (INTERNET_ERROR_BASE + 154)
ERROR_HTTP_HEADER_ALREADY_EXISTS                equ     (INTERNET_ERROR_BASE + 155)
ERROR_HTTP_REDIRECT_FAILED                      equ     (INTERNET_ERROR_BASE + 156)
ERROR_HTTP_NOT_REDIRECTED                       equ     (INTERNET_ERROR_BASE + 160)
ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION            equ     (INTERNET_ERROR_BASE + 161)
ERROR_HTTP_COOKIE_DECLINED                      equ     (INTERNET_ERROR_BASE + 162)
ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION          equ     (INTERNET_ERROR_BASE + 168)
ERROR_INTERNET_SECURITY_CHANNEL_ERROR           equ     (INTERNET_ERROR_BASE + 157)
ERROR_INTERNET_UNABLE_TO_CACHE_FILE             equ     (INTERNET_ERROR_BASE + 158)
ERROR_INTERNET_TCPIP_NOT_INSTALLED              equ     (INTERNET_ERROR_BASE + 159)
ERROR_INTERNET_DISCONNECTED                     equ     (INTERNET_ERROR_BASE + 163)
ERROR_INTERNET_SERVER_UNREACHABLE               equ     (INTERNET_ERROR_BASE + 164)
ERROR_INTERNET_PROXY_SERVER_UNREACHABLE         equ     (INTERNET_ERROR_BASE + 165)
ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT            equ     (INTERNET_ERROR_BASE + 166)
ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT        equ     (INTERNET_ERROR_BASE + 167)
ERROR_INTERNET_SEC_INVALID_CERT                 equ     (INTERNET_ERROR_BASE + 169)
ERROR_INTERNET_SEC_CERT_REVOKED                 equ     (INTERNET_ERROR_BASE + 170)
ERROR_INTERNET_FAILED_DUETOSECURITYCHECK        equ     (INTERNET_ERROR_BASE + 171)
ERROR_INTERNET_NOT_INITIALIZED                  equ     (INTERNET_ERROR_BASE + 172)
ERROR_INTERNET_NEED_MSN_SSPI_PKG                equ     (INTERNET_ERROR_BASE + 173)
ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY equ    (INTERNET_ERROR_BASE + 174)
INTERNET_ERROR_LAST                             equ     ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY

NORMAL_CACHE_ENTRY                              equ     00000001H
STICKY_CACHE_ENTRY                              equ     00000004H
EDITED_CACHE_ENTRY                              equ     00000008H
TRACK_OFFLINE_CACHE_ENTRY                       equ     00000010H
TRACK_ONLINE_CACHE_ENTRY                        equ     00000020H
SPARSE_CACHE_ENTRY                              equ     00010000H
COOKIE_CACHE_ENTRY                              equ     00100000H
URLHISTORY_CACHE_ENTRY                          equ     00200000H
URLCACHE_FIND_DEFAULT_FILTER                    equ     (NORMAL_CACHE_ENTRY or COOKIE_CACHE_ENTRY or URLHISTORY_CACHE_ENTRY or TRACK_OFFLINE_CACHE_ENTRY or TRACK_ONLINE_CACHE_ENTRY or STICKY_CACHE_ENTRY)

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
CACHEGROUP_READWRITE_MASK                       equ     (CACHEGROUP_ATTRIBUTE_TYPE or CACHEGROUP_ATTRIBUTE_QUOTA or CACHEGROUP_ATTRIBUTE_GROUPNAME or CACHEGROUP_ATTRIBUTE_STORAGE)

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
INTERNET_AUTODIAL_FLAGS_MASK                    equ     (INTERNET_AUTODIAL_FORCE_ONLINE or INTERNET_AUTODIAL_FORCE_UNATTENDED or INTERNET_AUTODIAL_FAILIFSECURITYCHECK)

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
INTERNET_SCHEME_UNKNOWN                         equ     -1
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

if defined APP_UNICODE
    HTTP_VERSION                                equ     HTTP_VERSIONW
else
    HTTP_VERSION                                equ     HTTP_VERSIONA
end if

;======================================== Structures ======================================;
struct INTERNET_ASYNC_RESULT
    dwResult    dd  ?
    dwError     dd  ?
ends

struct INTERNET_PROXY_INFO
    dwAccessType    dd   ?
    lpszProxy       xptr ?
    lpszProxyBypass xptr ?
ends

struct INTERNET_PER_CONN_OPTIONA
    dwOption     dd   ?
    union
        dwValue  dd   ?
        pszValue xptr ?
        ftValue  FILETIME
    ends
ends

struct INTERNET_PER_CONN_OPTIONW
    dwOption     dd   ?
    union
        dwValue  dd   ?
        pszValue xptr ?
        ftValue  FILETIME
    ends
ends

struct INTERNET_PER_CONN_OPTION_LISTA
    dwSize        dd    ?
    pszConnection xptr  ?
    dwOptionCount dd    ?
    dwOptionError dd    ?
    pOptions      xptr  ?
ends

struct INTERNET_PER_CONN_OPTION_LISTW
    dwSize        dd    ?
    pszConnection xptr  ?
    dwOptionCount dd    ?
    dwOptionError dd    ?
    pOptions      xptr  ?
ends

struct INTERNET_VERSION_INFO
    dwMajorVersion dd ?
    dwMinorVersion dd ?
ends

struct HTTP_VERSION_INFO
    dwMajorVersion dd ?
    dwMinorVersion dd ?
ends

struct INTERNET_CONNECTED_INFO
    dwConnectedState dd ?
    dwFlags          dd ?
ends

struct URL_COMPONENTSA
    dwStructSize      dd   ?
    lpszScheme        xptr ?
    dwSchemeLength    dd   ?
    nScheme           dd   ?
    lpszHostName      xptr ?
    dwHostNameLength  dd   ?
    nPort             dd   ?
    lpszUserName      xptr ?
    dwUserNameLength  dd   ?
    lpszPassword      xptr ?
    dwPasswordLength  dd   ?
    lpszUrlPath       xptr ?
    dwUrlPathLength   dd   ?
    lpszExtraInfo     xptr ?
    dwExtraInfoLength dd   ?
ends

struct URL_COMPONENTSW
    dwStructSize      dd   ?
    lpszScheme        xptr ?
    dwSchemeLength    dd   ?
    nScheme           dd   ?
    lpszHostName      xptr ?
    dwHostNameLength  dd   ?
    nPort             dd   ?
    lpszUserName      xptr ?
    dwUserNameLength  dd   ?
    lpszPassword      xptr ?
    dwPasswordLength  dd   ?
    lpszUrlPath       xptr ?
    dwUrlPathLength   dd   ?
    lpszExtraInfo     xptr ?
    dwExtraInfoLength dd   ?
ends

struct INTERNET_CERTIFICATE_INFO
    ftExpiry              FILETIME
    ftStart               FILETIME
    lpszSubjectInfo       xptr ?
    lpszIssuerInfo        xptr ?
    lpszProtocolName      xptr ?
    lpszSignatureAlgName  xptr ?
    lpszEncryptionAlgName xptr ?
    dwKeySize             dd   ?
ends

struct INTERNET_BUFFERSA
    dwStructSize    dd   ?
    Next            dd   ?
    lpcszHeader     xptr ?
    dwHeadersLength dd   ?
    dwHeadersTotal  dd   ?
    lpvBuffer       xptr ?
    dwBufferLength  dd   ?
    dwBufferTotal   dd   ?
    dwOffsetLow     dd   ?
    dwOffsetHigh    dd   ?
ends

struct INTERNET_BUFFERSW
    dwStructSize    dd   ?
    Next            dd   ?
    lpcszHeader     xptr ?
    dwHeadersLength dd   ?
    dwHeadersTotal  dd   ?
    lpvBuffer       xptr ?
    dwBufferLength  dd   ?
    dwBufferTotal   dd   ?
    dwOffsetLow     dd   ?
    dwOffsetHigh    dd   ?
ends

struct GOPHER_FIND_DATAA
    DisplayString        db MAX_GOPHER_DISPLAY_TEXT+1 dup(?)
    GopherType           dd ?
    SizeLow              dd ?
    SizeHigh             dd ?
    LastModificationTime FILETIME
    Locator              db MAX_GOPHER_LOCATOR_LENGTH+1 dup(?)
ends

struct GOPHER_FIND_DATAW
    DisplayString        dw MAX_GOPHER_DISPLAY_TEXT+1 dup(?)
    GopherType           dd ?
    SizeLow              dd ?
    SizeHigh             dd ?
    LastModificationTime FILETIME
    Locator              dw MAX_GOPHER_LOCATOR_LENGTH+1 dup(?)
ends

struct GOPHER_ADMIN_ATTRIBUTE_TYPE
    Comment      xptr ?
    EmailAddress xptr ?
ends

struct GOPHER_MOD_DATE_ATTRIBUTE_TYPE
    DateAndTime FILETIME
ends

struct GOPHER_TTL_ATTRIBUTE_TYPE
    Ttl dd ?
ends

struct GOPHER_SCORE_ATTRIBUTE_TYPE
    Score dd ?
ends

struct GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
    LowerBound dd ?
    UpperBound dd ?
ends

struct GOPHER_SITE_ATTRIBUTE_TYPE
    Site xptr ?
ends

struct GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
    Organization xptr ?
ends

struct GOPHER_LOCATION_ATTRIBUTE_TYPE
    Location xptr ?
ends

struct GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
    DegreesNorth dd ?
    MinutesNorth dd ?
    SecondsNorth dd ?
    DegreesEast  dd ?
    MinutesEast  dd ?
    SecondsEast  dd ?
ends

struct GOPHER_TIMEZONE_ATTRIBUTE_TYPE
    Zone dd ?
ends

struct GOPHER_PROVIDER_ATTRIBUTE_TYPE
    Provider dd ?
ends

struct GOPHER_VERSION_ATTRIBUTE_TYPE
    Version dd ?
ends

struct GOPHER_ABSTRACT_ATTRIBUTE_TYPE
    ShortAbstract dd ?
    AbstractFile  dd ?
ends

struct GOPHER_VIEW_ATTRIBUTE_TYPE
    ContentType dd ?
    Language    dd ?
    Size        dd ?
ends

struct GOPHER_VERONICA_ATTRIBUTE_TYPE
    TreeWalk    dd ?
ends

struct GOPHER_ASK_ATTRIBUTE_TYPE
    QuestionType dd ?
    QuestionText dd ?
ends

struct GOPHER_UNKNOWN_ATTRIBUTE_TYPE
    Text  dd ?
ends

struct GOPHER_ATTRIBUTE_TYPE
    CategoryId  dd ?
    AttributeId dd ?
    union
        Admin                GOPHER_ADMIN_ATTRIBUTE_TYPE
        ModDate              GOPHER_MOD_DATE_ATTRIBUTE_TYPE
        Ttl                  GOPHER_TTL_ATTRIBUTE_TYPE
        Score                GOPHER_SCORE_ATTRIBUTE_TYPE
        ScoreRange           GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
        Site                 GOPHER_SITE_ATTRIBUTE_TYPE
        Organization         GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
        Location             GOPHER_LOCATION_ATTRIBUTE_TYPE
        GeographicalLocation GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
        TimeZone             GOPHER_TIMEZONE_ATTRIBUTE_TYPE
        Provider             GOPHER_PROVIDER_ATTRIBUTE_TYPE
        Version              GOPHER_VERSION_ATTRIBUTE_TYPE
        Abstract             GOPHER_ABSTRACT_ATTRIBUTE_TYPE
        View                 GOPHER_VIEW_ATTRIBUTE_TYPE
        Veronica             GOPHER_VERONICA_ATTRIBUTE_TYPE
        Ask                  GOPHER_ASK_ATTRIBUTE_TYPE
        _Unknown              GOPHER_UNKNOWN_ATTRIBUTE_TYPE
    ends
ends

struct INTERNET_AUTH_NOTIFY_DATA
    cbStruct  dd   ?
    dwOptions dd   ?
    pfnNotify xptr ?
    dwContext dd   ?
ends

struct INTERNET_CACHE_ENTRY_INFOA
    dwStructSize      dd   ?
    lpszSourceUrlName xptr ?
    lpszLocalFileName xptr ?
    CacheEntryType    dd   ?
    dwUseCount        dd   ?
    dwHitRate         dd   ?
    dwSizeLow         dd   ?
    dwSizeHigh        dd   ?
    LastModifiedTime  FILETIME
    ExpireTime        FILETIME
    LastAccessTime    FILETIME
    LastSyncTime      FILETIME
    lpHeaderInfo      xptr ?
    dwHeaderInfoSize  dd   ?
    lpszFileExtension xptr ?
    union
        dwReserved    dd   ?
        dwExemptDelta dd   ?
    ends
ends

struct INTERNET_CACHE_ENTRY_INFOW
    dwStructSize      dd   ?
    lpszSourceUrlName xptr ?
    lpszLocalFileName xptr ?
    CacheEntryType    dd   ?
    dwUseCount        dd   ?
    dwHitRate         dd   ?
    dwSizeLow         dd   ?
    dwSizeHigh        dd   ?
    LastModifiedTime  FILETIME
    ExpireTime        FILETIME
    LastAccessTime    FILETIME
    LastSyncTime      FILETIME
    lpHeaderInfo      xptr ?
    dwHeaderInfoSize  dd   ?
    lpszFileExtension xptr ?
    union
        dwReserved    dd   ?
        dwExemptDelta dd   ?
    ends
ends

struct INTERNET_CACHE_TIMESTAMPS
    ftExpires      FILETIME
    ftLastModified FILETIME
ends

struct INTERNET_CACHE_GROUP_INFOA
    dwGroupSize     dd ?
    dwGroupFlags    dd ?
    dwGroupType     dd ?
    dwDiskUsage     dd ?
    dwDiskQuota     dd ?
    dwOwnerStorage  dd GROUP_OWNER_STORAGE_SIZE dup(?)
    szGroupName     db GROUPNAME_MAX_LENGTH dup(?)
ends

struct INTERNET_CACHE_GROUP_INFOW
    dwGroupSize     dd ?
    dwGroupFlags    dd ?
    dwGroupType     dd ?
    dwDiskUsage     dd ?
    dwDiskQuota     dd ?
    dwOwnerStorage  dd GROUP_OWNER_STORAGE_SIZE dup(?)
    szGroupName     dw GROUPNAME_MAX_LENGTH dup(?)
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_CommitUrlCacheEntryA' as CommitUrlCacheEntryA:qword
    extrn '__imp_CommitUrlCacheEntryW' as CommitUrlCacheEntryW:qword
    extrn '__imp_CreateMD5SSOHash' as CreateMD5SSOHash:qword
    extrn '__imp_CreateUrlCacheContainerA' as CreateUrlCacheContainerA:qword
    extrn '__imp_CreateUrlCacheContainerW' as CreateUrlCacheContainerW:qword
    extrn '__imp_CreateUrlCacheEntryA' as CreateUrlCacheEntryA:qword
    extrn '__imp_CreateUrlCacheEntryW' as CreateUrlCacheEntryW:qword
    extrn '__imp_CreateUrlCacheGroup' as CreateUrlCacheGroup:qword
    extrn '__imp_DeleteIE3Cache' as DeleteIE3Cache:qword
    extrn '__imp_DeleteUrlCacheContainerA' as DeleteUrlCacheContainerA:qword
    extrn '__imp_DeleteUrlCacheContainerW' as DeleteUrlCacheContainerW:qword
    extrn '__imp_DeleteUrlCacheEntryA' as DeleteUrlCacheEntryA:qword
    extrn '__imp_DeleteUrlCacheEntryW' as DeleteUrlCacheEntryW:qword
    extrn '__imp_DeleteUrlCacheGroup' as DeleteUrlCacheGroup:qword
    extrn '__imp_DetectAutoProxyUrl' as DetectAutoProxyUrl:qword
    extrn '__imp_FindCloseUrlCache' as FindCloseUrlCache:qword
    extrn '__imp_FindFirstUrlCacheContainerA' as FindFirstUrlCacheContainerA:qword
    extrn '__imp_FindFirstUrlCacheContainerW' as FindFirstUrlCacheContainerW:qword
    extrn '__imp_FindFirstUrlCacheEntryA' as FindFirstUrlCacheEntryA:qword
    extrn '__imp_FindFirstUrlCacheEntryExA' as FindFirstUrlCacheEntryExA:qword
    extrn '__imp_FindFirstUrlCacheEntryExW' as FindFirstUrlCacheEntryExW:qword
    extrn '__imp_FindFirstUrlCacheEntryW' as FindFirstUrlCacheEntryW:qword
    extrn '__imp_FindFirstUrlCacheGroup' as FindFirstUrlCacheGroup:qword
    extrn '__imp_FindNextUrlCacheContainerA' as FindNextUrlCacheContainerA:qword
    extrn '__imp_FindNextUrlCacheContainerW' as FindNextUrlCacheContainerW:qword
    extrn '__imp_FindNextUrlCacheEntryA' as FindNextUrlCacheEntryA:qword
    extrn '__imp_FindNextUrlCacheEntryExA' as FindNextUrlCacheEntryExA:qword
    extrn '__imp_FindNextUrlCacheEntryExW' as FindNextUrlCacheEntryExW:qword
    extrn '__imp_FindNextUrlCacheEntryW' as FindNextUrlCacheEntryW:qword
    extrn '__imp_FindNextUrlCacheGroup' as FindNextUrlCacheGroup:qword
    extrn '__imp_ForceNexusLookup' as ForceNexusLookup:qword
    extrn '__imp_ForceNexusLookupExW' as ForceNexusLookupExW:qword
    extrn '__imp_FreeUrlCacheSpaceA' as FreeUrlCacheSpaceA:qword
    extrn '__imp_FreeUrlCacheSpaceW' as FreeUrlCacheSpaceW:qword
    extrn '__imp_FtpCommandA' as FtpCommandA:qword
    extrn '__imp_FtpCommandW' as FtpCommandW:qword
    extrn '__imp_FtpCreateDirectoryA' as FtpCreateDirectoryA:qword
    extrn '__imp_FtpCreateDirectoryW' as FtpCreateDirectoryW:qword
    extrn '__imp_FtpDeleteFileA' as FtpDeleteFileA:qword
    extrn '__imp_FtpDeleteFileW' as FtpDeleteFileW:qword
    extrn '__imp_FtpFindFirstFileA' as FtpFindFirstFileA:qword
    extrn '__imp_FtpFindFirstFileW' as FtpFindFirstFileW:qword
    extrn '__imp_FtpGetCurrentDirectoryA' as FtpGetCurrentDirectoryA:qword
    extrn '__imp_FtpGetCurrentDirectoryW' as FtpGetCurrentDirectoryW:qword
    extrn '__imp_FtpGetFileA' as FtpGetFileA:qword
    extrn '__imp_FtpGetFileEx' as FtpGetFileEx:qword
    extrn '__imp_FtpGetFileSize' as FtpGetFileSize:qword
    extrn '__imp_FtpGetFileW' as FtpGetFileW:qword
    extrn '__imp_FtpOpenFileA' as FtpOpenFileA:qword
    extrn '__imp_FtpOpenFileW' as FtpOpenFileW:qword
    extrn '__imp_FtpPutFileA' as FtpPutFileA:qword
    extrn '__imp_FtpPutFileEx' as FtpPutFileEx:qword
    extrn '__imp_FtpPutFileW' as FtpPutFileW:qword
    extrn '__imp_FtpRemoveDirectoryA' as FtpRemoveDirectoryA:qword
    extrn '__imp_FtpRemoveDirectoryW' as FtpRemoveDirectoryW:qword
    extrn '__imp_FtpRenameFileA' as FtpRenameFileA:qword
    extrn '__imp_FtpRenameFileW' as FtpRenameFileW:qword
    extrn '__imp_FtpSetCurrentDirectoryA' as FtpSetCurrentDirectoryA:qword
    extrn '__imp_FtpSetCurrentDirectoryW' as FtpSetCurrentDirectoryW:qword
    extrn '__imp_GetUrlCacheConfigInfoA' as GetUrlCacheConfigInfoA:qword
    extrn '__imp_GetUrlCacheConfigInfoW' as GetUrlCacheConfigInfoW:qword
    extrn '__imp_GetUrlCacheEntryInfoA' as GetUrlCacheEntryInfoA:qword
    extrn '__imp_GetUrlCacheEntryInfoExA' as GetUrlCacheEntryInfoExA:qword
    extrn '__imp_GetUrlCacheEntryInfoExW' as GetUrlCacheEntryInfoExW:qword
    extrn '__imp_GetUrlCacheEntryInfoW' as GetUrlCacheEntryInfoW:qword
    extrn '__imp_GetUrlCacheGroupAttributeA' as GetUrlCacheGroupAttributeA:qword
    extrn '__imp_GetUrlCacheGroupAttributeW' as GetUrlCacheGroupAttributeW:qword
    extrn '__imp_GetUrlCacheHeaderData' as GetUrlCacheHeaderData:qword
    extrn '__imp_GopherCreateLocatorA' as GopherCreateLocatorA:qword
    extrn '__imp_GopherCreateLocatorW' as GopherCreateLocatorW:qword
    extrn '__imp_GopherFindFirstFileA' as GopherFindFirstFileA:qword
    extrn '__imp_GopherFindFirstFileW' as GopherFindFirstFileW:qword
    extrn '__imp_GopherGetAttributeA' as GopherGetAttributeA:qword
    extrn '__imp_GopherGetAttributeW' as GopherGetAttributeW:qword
    extrn '__imp_GopherGetLocatorTypeA' as GopherGetLocatorTypeA:qword
    extrn '__imp_GopherGetLocatorTypeW' as GopherGetLocatorTypeW:qword
    extrn '__imp_GopherOpenFileA' as GopherOpenFileA:qword
    extrn '__imp_GopherOpenFileW' as GopherOpenFileW:qword
    extrn '__imp_HttpAddRequestHeadersA' as HttpAddRequestHeadersA:qword
    extrn '__imp_HttpAddRequestHeadersW' as HttpAddRequestHeadersW:qword
    extrn '__imp_HttpCheckDavCompliance' as HttpCheckDavCompliance:qword
    extrn '__imp_HttpEndRequestA' as HttpEndRequestA:qword
    extrn '__imp_HttpEndRequestW' as HttpEndRequestW:qword
    extrn '__imp_HttpOpenRequestA' as HttpOpenRequestA:qword
    extrn '__imp_HttpOpenRequestW' as HttpOpenRequestW:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_HttpPushClose' as HttpPushClose:qword
        extrn '__imp_HttpPushEnable' as HttpPushEnable:qword
        extrn '__imp_HttpPushWait' as HttpPushWait:qword
    end if
    extrn '__imp_HttpQueryInfoA' as HttpQueryInfoA:qword
    extrn '__imp_HttpQueryInfoW' as HttpQueryInfoW:qword
    extrn '__imp_HttpSendRequestA' as HttpSendRequestA:qword
    extrn '__imp_HttpSendRequestExA' as HttpSendRequestExA:qword
    extrn '__imp_HttpSendRequestExW' as HttpSendRequestExW:qword
    extrn '__imp_HttpSendRequestW' as HttpSendRequestW:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_HttpWebSocketCompleteUpgrade' as HttpWebSocketCompleteUpgrade:qword
        extrn '__imp_HttpWebSocketQueryCloseStatus' as HttpWebSocketQueryCloseStatus:qword
        extrn '__imp_HttpWebSocketReceive' as HttpWebSocketReceive:qword
        extrn '__imp_HttpWebSocketSend' as HttpWebSocketSend:qword
        extrn '__imp_HttpWebSocketShutdown' as HttpWebSocketShutdown:qword
    end if
    extrn '__imp_IncrementUrlCacheHeaderData' as IncrementUrlCacheHeaderData:qword
    extrn '__imp_InternetAlgIdToStringA' as InternetAlgIdToStringA:qword
    extrn '__imp_InternetAlgIdToStringW' as InternetAlgIdToStringW:qword
    extrn '__imp_InternetAttemptConnect' as InternetAttemptConnect:qword
    extrn '__imp_InternetAutodial' as InternetAutodial:qword
    extrn '__imp_InternetAutodialCallback' as InternetAutodialCallback:qword
    extrn '__imp_InternetAutodialHangup' as InternetAutodialHangup:qword
    extrn '__imp_InternetCanonicalizeUrlA' as InternetCanonicalizeUrlA:qword
    extrn '__imp_InternetCanonicalizeUrlW' as InternetCanonicalizeUrlW:qword
    extrn '__imp_InternetCheckConnectionA' as InternetCheckConnectionA:qword
    extrn '__imp_InternetCheckConnectionW' as InternetCheckConnectionW:qword
    extrn '__imp_InternetClearAllPerSiteCookieDecisions' as InternetClearAllPerSiteCookieDecisions:qword
    extrn '__imp_InternetCloseHandle' as InternetCloseHandle:qword
    extrn '__imp_InternetCombineUrlA' as InternetCombineUrlA:qword
    extrn '__imp_InternetCombineUrlW' as InternetCombineUrlW:qword
    extrn '__imp_InternetConfirmZoneCrossingA' as InternetConfirmZoneCrossingA:qword
    extrn '__imp_InternetConfirmZoneCrossingW' as InternetConfirmZoneCrossingW:qword
    extrn '__imp_InternetConnectA' as InternetConnectA:qword
    extrn '__imp_InternetConnectW' as InternetConnectW:qword
    extrn '__imp_InternetCrackUrlA' as InternetCrackUrlA:qword
    extrn '__imp_InternetCrackUrlW' as InternetCrackUrlW:qword
    extrn '__imp_InternetCreateUrlA' as InternetCreateUrlA:qword
    extrn '__imp_InternetCreateUrlW' as InternetCreateUrlW:qword
    extrn '__imp_InternetDialA' as InternetDialA:qword
    extrn '__imp_InternetDialW' as InternetDialW:qword
    extrn '__imp_InternetEnumPerSiteCookieDecisionA' as InternetEnumPerSiteCookieDecisionA:qword
    extrn '__imp_InternetEnumPerSiteCookieDecisionW' as InternetEnumPerSiteCookieDecisionW:qword
    extrn '__imp_InternetErrorDlg' as InternetErrorDlg:qword
    extrn '__imp_InternetFindNextFileA' as InternetFindNextFileA:qword
    extrn '__imp_InternetFindNextFileW' as InternetFindNextFileW:qword
    extrn '__imp_InternetFortezzaCommand' as InternetFortezzaCommand:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_InternetFreeProxyInfoList' as InternetFreeProxyInfoList:qword
    end if
    extrn '__imp_InternetGetCertByURL' as InternetGetCertByURL:qword
    extrn '__imp_InternetGetCertByURLA' as InternetGetCertByURLA:qword
    extrn '__imp_InternetGetConnectedState' as InternetGetConnectedState:qword
    extrn '__imp_InternetGetConnectedStateExA' as InternetGetConnectedStateExA:qword
    extrn '__imp_InternetGetConnectedStateExW' as InternetGetConnectedStateExW:qword
    extrn '__imp_InternetGetCookieA' as InternetGetCookieA:qword
    extrn '__imp_InternetGetCookieExA' as InternetGetCookieExA:qword
    extrn '__imp_InternetGetCookieExW' as InternetGetCookieExW:qword
    extrn '__imp_InternetGetCookieW' as InternetGetCookieW:qword
    extrn '__imp_InternetGetLastResponseInfoA' as InternetGetLastResponseInfoA:qword
    extrn '__imp_InternetGetLastResponseInfoW' as InternetGetLastResponseInfoW:qword
    extrn '__imp_InternetGetPerSiteCookieDecisionA' as InternetGetPerSiteCookieDecisionA:qword
    extrn '__imp_InternetGetPerSiteCookieDecisionW' as InternetGetPerSiteCookieDecisionW:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_InternetGetProxyForUrl' as InternetGetProxyForUrl:qword
    end if
    extrn '__imp_InternetGetSecurityInfoByURLA' as InternetGetSecurityInfoByURLA:qword
    extrn '__imp_InternetGetSecurityInfoByURLW' as InternetGetSecurityInfoByURLW:qword
    extrn '__imp_InternetGoOnlineA' as InternetGoOnlineA:qword
    extrn '__imp_InternetGoOnlineW' as InternetGoOnlineW:qword
    extrn '__imp_InternetHangUp' as InternetHangUp:qword
    extrn '__imp_InternetInitializeAutoProxyDll' as InternetInitializeAutoProxyDll:qword
    extrn '__imp_InternetLockRequestFile' as InternetLockRequestFile:qword
    extrn '__imp_InternetOpenA' as InternetOpenA:qword
    extrn '__imp_InternetOpenUrlA' as InternetOpenUrlA:qword
    extrn '__imp_InternetOpenUrlW' as InternetOpenUrlW:qword
    extrn '__imp_InternetOpenW' as InternetOpenW:qword
    extrn '__imp_InternetQueryDataAvailable' as InternetQueryDataAvailable:qword
    extrn '__imp_InternetQueryFortezzaStatus' as InternetQueryFortezzaStatus:qword
    extrn '__imp_InternetQueryOptionA' as InternetQueryOptionA:qword
    extrn '__imp_InternetQueryOptionW' as InternetQueryOptionW:qword
    extrn '__imp_InternetReadFile' as InternetReadFile:qword
    extrn '__imp_InternetReadFileExA' as InternetReadFileExA:qword
    extrn '__imp_InternetReadFileExW' as InternetReadFileExW:qword
    extrn '__imp_InternetSecurityProtocolToStringA' as InternetSecurityProtocolToStringA:qword
    extrn '__imp_InternetSecurityProtocolToStringW' as InternetSecurityProtocolToStringW:qword
    extrn '__imp_InternetSetCookieA' as InternetSetCookieA:qword
    extrn '__imp_InternetSetCookieExA' as InternetSetCookieExA:qword
    extrn '__imp_InternetSetCookieExW' as InternetSetCookieExW:qword
    extrn '__imp_InternetSetCookieW' as InternetSetCookieW:qword
    extrn '__imp_InternetSetDialStateA' as InternetSetDialStateA:qword
    extrn '__imp_InternetSetDialStateW' as InternetSetDialStateW:qword
    extrn '__imp_InternetSetFilePointer' as InternetSetFilePointer:qword
    extrn '__imp_InternetSetOptionA' as InternetSetOptionA:qword
    extrn '__imp_InternetSetOptionExA' as InternetSetOptionExA:qword
    extrn '__imp_InternetSetOptionExW' as InternetSetOptionExW:qword
    extrn '__imp_InternetSetOptionW' as InternetSetOptionW:qword
    extrn '__imp_InternetSetPerSiteCookieDecisionA' as InternetSetPerSiteCookieDecisionA:qword
    extrn '__imp_InternetSetPerSiteCookieDecisionW' as InternetSetPerSiteCookieDecisionW:qword
    extrn '__imp_InternetSetStatusCallbackA' as InternetSetStatusCallbackA:qword
    extrn '__imp_InternetSetStatusCallbackW' as InternetSetStatusCallbackW:qword
    extrn '__imp_InternetShowSecurityInfoByURLA' as InternetShowSecurityInfoByURLA:qword
    extrn '__imp_InternetShowSecurityInfoByURLW' as InternetShowSecurityInfoByURLW:qword
    extrn '__imp_InternetTimeFromSystemTimeA' as InternetTimeFromSystemTimeA:qword
    extrn '__imp_InternetTimeFromSystemTimeW' as InternetTimeFromSystemTimeW:qword
    extrn '__imp_InternetTimeToSystemTimeA' as InternetTimeToSystemTimeA:qword
    extrn '__imp_InternetTimeToSystemTimeW' as InternetTimeToSystemTimeW:qword
    extrn '__imp_InternetUnlockRequestFile' as InternetUnlockRequestFile:qword
    extrn '__imp_InternetWriteFile' as InternetWriteFile:qword
    extrn '__imp_InternetWriteFileExA' as InternetWriteFileExA:qword
    extrn '__imp_InternetWriteFileExW' as InternetWriteFileExW:qword
    extrn '__imp_IsHostInProxyBypassList' as IsHostInProxyBypassList:qword
    extrn '__imp_IsUrlCacheEntryExpiredA' as IsUrlCacheEntryExpiredA:qword
    extrn '__imp_IsUrlCacheEntryExpiredW' as IsUrlCacheEntryExpiredW:qword
    extrn '__imp_LoadUrlCacheContent' as LoadUrlCacheContent:qword
    extrn '__imp_ParseX509EncodedCertificateForListBoxEntry' as ParseX509EncodedCertificateForListBoxEntry:qword
    extrn '__imp_PrivacyGetZonePreferenceW' as PrivacyGetZonePreferenceW:qword
    extrn '__imp_PrivacySetZonePreferenceW' as PrivacySetZonePreferenceW:qword
    extrn '__imp_ReadUrlCacheEntryStream' as ReadUrlCacheEntryStream:qword
    extrn '__imp_RegisterUrlCacheNotification' as RegisterUrlCacheNotification:qword
    extrn '__imp_ResumeSuspendedDownload' as ResumeSuspendedDownload:qword
    extrn '__imp_RetrieveUrlCacheEntryFileA' as RetrieveUrlCacheEntryFileA:qword
    extrn '__imp_RetrieveUrlCacheEntryFileW' as RetrieveUrlCacheEntryFileW:qword
    extrn '__imp_RetrieveUrlCacheEntryStreamA' as RetrieveUrlCacheEntryStreamA:qword
    extrn '__imp_RetrieveUrlCacheEntryStreamW' as RetrieveUrlCacheEntryStreamW:qword
    extrn '__imp_RunOnceUrlCache' as RunOnceUrlCache:qword
    extrn '__imp_SetUrlCacheConfigInfoA' as SetUrlCacheConfigInfoA:qword
    extrn '__imp_SetUrlCacheConfigInfoW' as SetUrlCacheConfigInfoW:qword
    extrn '__imp_SetUrlCacheEntryGroupA' as SetUrlCacheEntryGroupA:qword
    extrn '__imp_SetUrlCacheEntryGroupW' as SetUrlCacheEntryGroupW:qword
    extrn '__imp_SetUrlCacheEntryInfoA' as SetUrlCacheEntryInfoA:qword
    extrn '__imp_SetUrlCacheEntryInfoW' as SetUrlCacheEntryInfoW:qword
    extrn '__imp_SetUrlCacheGroupAttributeA' as SetUrlCacheGroupAttributeA:qword
    extrn '__imp_SetUrlCacheGroupAttributeW' as SetUrlCacheGroupAttributeW:qword
    extrn '__imp_SetUrlCacheHeaderData' as SetUrlCacheHeaderData:qword
    extrn '__imp_ShowCertificate' as ShowCertificate:qword
    extrn '__imp_ShowClientAuthCerts' as ShowClientAuthCerts:qword
    extrn '__imp_ShowSecurityInfo' as ShowSecurityInfo:qword
    extrn '__imp_ShowX509EncodedCertificate' as ShowX509EncodedCertificate:qword
    extrn '__imp_UnlockUrlCacheEntryFileA' as UnlockUrlCacheEntryFileA:qword
    extrn '__imp_UnlockUrlCacheEntryFileW' as UnlockUrlCacheEntryFileW:qword
    extrn '__imp_UnlockUrlCacheEntryStream' as UnlockUrlCacheEntryStream:qword
    extrn '__imp_UpdateUrlCacheContentPath' as UpdateUrlCacheContentPath:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_UrlCacheCheckEntriesExist' as UrlCacheCheckEntriesExist:qword
        extrn '__imp_UrlCacheCloseEntryHandle' as UrlCacheCloseEntryHandle:qword
        extrn '__imp_UrlCacheCreateContainer' as UrlCacheCreateContainer:qword
        extrn '__imp_UrlCacheFreeEntryInfo' as UrlCacheFreeEntryInfo:qword
        extrn '__imp_UrlCacheGetEntryInfo' as UrlCacheGetEntryInfo:qword
        extrn '__imp_UrlCacheGetGlobalLimit' as UrlCacheGetGlobalLimit:qword
        extrn '__imp_UrlCacheRetrieveEntryFile' as UrlCacheRetrieveEntryFile:qword
        extrn '__imp_UrlCacheSetGlobalLimit' as UrlCacheSetGlobalLimit:qword
        extrn '__imp_UrlCacheUpdateEntryExtraData' as UrlCacheUpdateEntryExtraData:qword
    end if
    extrn '__imp_UrlZonesDetach' as UrlZonesDetach:qword
else
    extrn '__imp_CommitUrlCacheEntryA@44' as CommitUrlCacheEntryA:dword
    extrn '__imp_CommitUrlCacheEntryW@44' as CommitUrlCacheEntryW:dword
    extrn '__imp_CreateMD5SSOHash@16' as CreateMD5SSOHash:dword
    extrn '__imp_CreateUrlCacheContainerA@32' as CreateUrlCacheContainerA:dword
    extrn '__imp_CreateUrlCacheContainerW@32' as CreateUrlCacheContainerW:dword
    extrn '__imp_CreateUrlCacheEntryA@20' as CreateUrlCacheEntryA:dword
    extrn '__imp_CreateUrlCacheEntryW@20' as CreateUrlCacheEntryW:dword
    extrn '__imp_CreateUrlCacheGroup@8' as CreateUrlCacheGroup:dword
    extrn '__imp_DeleteIE3Cache@16' as DeleteIE3Cache:dword
    extrn '__imp_DeleteUrlCacheContainerA@8' as DeleteUrlCacheContainerA:dword
    extrn '__imp_DeleteUrlCacheContainerW@8' as DeleteUrlCacheContainerW:dword
    extrn '__imp_DeleteUrlCacheEntryA@4' as DeleteUrlCacheEntryA:dword
    extrn '__imp_DeleteUrlCacheEntryW@4' as DeleteUrlCacheEntryW:dword
    extrn '__imp_DeleteUrlCacheGroup@16' as DeleteUrlCacheGroup:dword
    extrn '__imp_DetectAutoProxyUrl@12' as DetectAutoProxyUrl:dword
    extrn '__imp_FindCloseUrlCache@4' as FindCloseUrlCache:dword
    extrn '__imp_FindFirstUrlCacheContainerA@16' as FindFirstUrlCacheContainerA:dword
    extrn '__imp_FindFirstUrlCacheContainerW@16' as FindFirstUrlCacheContainerW:dword
    extrn '__imp_FindFirstUrlCacheEntryA@12' as FindFirstUrlCacheEntryA:dword
    extrn '__imp_FindFirstUrlCacheEntryExA@40' as FindFirstUrlCacheEntryExA:dword
    extrn '__imp_FindFirstUrlCacheEntryExW@40' as FindFirstUrlCacheEntryExW:dword
    extrn '__imp_FindFirstUrlCacheEntryW@12' as FindFirstUrlCacheEntryW:dword
    extrn '__imp_FindFirstUrlCacheGroup@24' as FindFirstUrlCacheGroup:dword
    extrn '__imp_FindNextUrlCacheContainerA@12' as FindNextUrlCacheContainerA:dword
    extrn '__imp_FindNextUrlCacheContainerW@12' as FindNextUrlCacheContainerW:dword
    extrn '__imp_FindNextUrlCacheEntryA@12' as FindNextUrlCacheEntryA:dword
    extrn '__imp_FindNextUrlCacheEntryExA@24' as FindNextUrlCacheEntryExA:dword
    extrn '__imp_FindNextUrlCacheEntryExW@24' as FindNextUrlCacheEntryExW:dword
    extrn '__imp_FindNextUrlCacheEntryW@12' as FindNextUrlCacheEntryW:dword
    extrn '__imp_FindNextUrlCacheGroup@12' as FindNextUrlCacheGroup:dword
    extrn '__imp_ForceNexusLookup@0' as ForceNexusLookup:dword
    extrn '__imp_ForceNexusLookupExW@20' as ForceNexusLookupExW:dword
    extrn '__imp_FreeUrlCacheSpaceA@12' as FreeUrlCacheSpaceA:dword
    extrn '__imp_FreeUrlCacheSpaceW@12' as FreeUrlCacheSpaceW:dword
    extrn '__imp_FtpCommandA@24' as FtpCommandA:dword
    extrn '__imp_FtpCommandW@24' as FtpCommandW:dword
    extrn '__imp_FtpCreateDirectoryA@8' as FtpCreateDirectoryA:dword
    extrn '__imp_FtpCreateDirectoryW@8' as FtpCreateDirectoryW:dword
    extrn '__imp_FtpDeleteFileA@8' as FtpDeleteFileA:dword
    extrn '__imp_FtpDeleteFileW@8' as FtpDeleteFileW:dword
    extrn '__imp_FtpFindFirstFileA@20' as FtpFindFirstFileA:dword
    extrn '__imp_FtpFindFirstFileW@20' as FtpFindFirstFileW:dword
    extrn '__imp_FtpGetCurrentDirectoryA@12' as FtpGetCurrentDirectoryA:dword
    extrn '__imp_FtpGetCurrentDirectoryW@12' as FtpGetCurrentDirectoryW:dword
    extrn '__imp_FtpGetFileA@28' as FtpGetFileA:dword
    extrn '__imp_FtpGetFileEx@28' as FtpGetFileEx:dword
    extrn '__imp_FtpGetFileSize@8' as FtpGetFileSize:dword
    extrn '__imp_FtpGetFileW@28' as FtpGetFileW:dword
    extrn '__imp_FtpOpenFileA@20' as FtpOpenFileA:dword
    extrn '__imp_FtpOpenFileW@20' as FtpOpenFileW:dword
    extrn '__imp_FtpPutFileA@20' as FtpPutFileA:dword
    extrn '__imp_FtpPutFileEx@20' as FtpPutFileEx:dword
    extrn '__imp_FtpPutFileW@20' as FtpPutFileW:dword
    extrn '__imp_FtpRemoveDirectoryA@8' as FtpRemoveDirectoryA:dword
    extrn '__imp_FtpRemoveDirectoryW@8' as FtpRemoveDirectoryW:dword
    extrn '__imp_FtpRenameFileA@12' as FtpRenameFileA:dword
    extrn '__imp_FtpRenameFileW@12' as FtpRenameFileW:dword
    extrn '__imp_FtpSetCurrentDirectoryA@8' as FtpSetCurrentDirectoryA:dword
    extrn '__imp_FtpSetCurrentDirectoryW@8' as FtpSetCurrentDirectoryW:dword
    extrn '__imp_GetUrlCacheConfigInfoA@12' as GetUrlCacheConfigInfoA:dword
    extrn '__imp_GetUrlCacheConfigInfoW@12' as GetUrlCacheConfigInfoW:dword
    extrn '__imp_GetUrlCacheEntryInfoA@12' as GetUrlCacheEntryInfoA:dword
    extrn '__imp_GetUrlCacheEntryInfoExA@28' as GetUrlCacheEntryInfoExA:dword
    extrn '__imp_GetUrlCacheEntryInfoExW@28' as GetUrlCacheEntryInfoExW:dword
    extrn '__imp_GetUrlCacheEntryInfoW@12' as GetUrlCacheEntryInfoW:dword
    extrn '__imp_GetUrlCacheGroupAttributeA@28' as GetUrlCacheGroupAttributeA:dword
    extrn '__imp_GetUrlCacheGroupAttributeW@28' as GetUrlCacheGroupAttributeW:dword
    extrn '__imp_GetUrlCacheHeaderData@8' as GetUrlCacheHeaderData:dword
    extrn '__imp_GopherCreateLocatorA@28' as GopherCreateLocatorA:dword
    extrn '__imp_GopherCreateLocatorW@28' as GopherCreateLocatorW:dword
    extrn '__imp_GopherFindFirstFileA@24' as GopherFindFirstFileA:dword
    extrn '__imp_GopherFindFirstFileW@24' as GopherFindFirstFileW:dword
    extrn '__imp_GopherGetAttributeA@32' as GopherGetAttributeA:dword
    extrn '__imp_GopherGetAttributeW@32' as GopherGetAttributeW:dword
    extrn '__imp_GopherGetLocatorTypeA@8' as GopherGetLocatorTypeA:dword
    extrn '__imp_GopherGetLocatorTypeW@8' as GopherGetLocatorTypeW:dword
    extrn '__imp_GopherOpenFileA@20' as GopherOpenFileA:dword
    extrn '__imp_GopherOpenFileW@20' as GopherOpenFileW:dword
    extrn '__imp_HttpAddRequestHeadersA@16' as HttpAddRequestHeadersA:dword
    extrn '__imp_HttpAddRequestHeadersW@16' as HttpAddRequestHeadersW:dword
    extrn '__imp_HttpCheckDavCompliance@20' as HttpCheckDavCompliance:dword
    extrn '__imp_HttpEndRequestA@16' as HttpEndRequestA:dword
    extrn '__imp_HttpEndRequestW@16' as HttpEndRequestW:dword
    extrn '__imp_HttpOpenRequestA@32' as HttpOpenRequestA:dword
    extrn '__imp_HttpOpenRequestW@32' as HttpOpenRequestW:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_HttpPushClose@4' as HttpPushClose:dword
        extrn '__imp_HttpPushEnable@12' as HttpPushEnable:dword
        extrn '__imp_HttpPushWait@12' as HttpPushWait:dword
    end if
    extrn '__imp_HttpQueryInfoA@20' as HttpQueryInfoA:dword
    extrn '__imp_HttpQueryInfoW@20' as HttpQueryInfoW:dword
    extrn '__imp_HttpSendRequestA@20' as HttpSendRequestA:dword
    extrn '__imp_HttpSendRequestExA@20' as HttpSendRequestExA:dword
    extrn '__imp_HttpSendRequestExW@20' as HttpSendRequestExW:dword
    extrn '__imp_HttpSendRequestW@20' as HttpSendRequestW:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_HttpWebSocketCompleteUpgrade@8' as HttpWebSocketCompleteUpgrade:dword
        extrn '__imp_HttpWebSocketQueryCloseStatus@20' as HttpWebSocketQueryCloseStatus:dword
        extrn '__imp_HttpWebSocketReceive@20' as HttpWebSocketReceive:dword
        extrn '__imp_HttpWebSocketSend@16' as HttpWebSocketSend:dword
        extrn '__imp_HttpWebSocketShutdown@16' as HttpWebSocketShutdown:dword
    end if
    extrn '__imp_IncrementUrlCacheHeaderData@8' as IncrementUrlCacheHeaderData:dword
    extrn '__imp_InternetAlgIdToStringA@16' as InternetAlgIdToStringA:dword
    extrn '__imp_InternetAlgIdToStringW@16' as InternetAlgIdToStringW:dword
    extrn '__imp_InternetAttemptConnect@4' as InternetAttemptConnect:dword
    extrn '__imp_InternetAutodial@8' as InternetAutodial:dword
    extrn '__imp_InternetAutodialCallback@8' as InternetAutodialCallback:dword
    extrn '__imp_InternetAutodialHangup@4' as InternetAutodialHangup:dword
    extrn '__imp_InternetCanonicalizeUrlA@16' as InternetCanonicalizeUrlA:dword
    extrn '__imp_InternetCanonicalizeUrlW@16' as InternetCanonicalizeUrlW:dword
    extrn '__imp_InternetCheckConnectionA@12' as InternetCheckConnectionA:dword
    extrn '__imp_InternetCheckConnectionW@12' as InternetCheckConnectionW:dword
    extrn '__imp_InternetClearAllPerSiteCookieDecisions@0' as InternetClearAllPerSiteCookieDecisions:dword
    extrn '__imp_InternetCloseHandle@4' as InternetCloseHandle:dword
    extrn '__imp_InternetCombineUrlA@20' as InternetCombineUrlA:dword
    extrn '__imp_InternetCombineUrlW@20' as InternetCombineUrlW:dword
    extrn '__imp_InternetConfirmZoneCrossingA@16' as InternetConfirmZoneCrossingA:dword
    extrn '__imp_InternetConfirmZoneCrossingW@16' as InternetConfirmZoneCrossingW:dword
    extrn '__imp_InternetConnectA@32' as InternetConnectA:dword
    extrn '__imp_InternetConnectW@32' as InternetConnectW:dword
    extrn '__imp_InternetCrackUrlA@16' as InternetCrackUrlA:dword
    extrn '__imp_InternetCrackUrlW@16' as InternetCrackUrlW:dword
    extrn '__imp_InternetCreateUrlA@16' as InternetCreateUrlA:dword
    extrn '__imp_InternetCreateUrlW@16' as InternetCreateUrlW:dword
    extrn '__imp_InternetDialA@20' as InternetDialA:dword
    extrn '__imp_InternetDialW@20' as InternetDialW:dword
    extrn '__imp_InternetEnumPerSiteCookieDecisionA@16' as InternetEnumPerSiteCookieDecisionA:dword
    extrn '__imp_InternetEnumPerSiteCookieDecisionW@16' as InternetEnumPerSiteCookieDecisionW:dword
    extrn '__imp_InternetErrorDlg@20' as InternetErrorDlg:dword
    extrn '__imp_InternetFindNextFileA@8' as InternetFindNextFileA:dword
    extrn '__imp_InternetFindNextFileW@8' as InternetFindNextFileW:dword
    extrn '__imp_InternetFortezzaCommand@12' as InternetFortezzaCommand:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_InternetFreeProxyInfoList@4' as InternetFreeProxyInfoList:dword
    end if
    extrn '__imp_InternetGetCertByURL@12' as InternetGetCertByURL:dword
    extrn '__imp_InternetGetCertByURLA@12' as InternetGetCertByURLA:dword
    extrn '__imp_InternetGetConnectedState@8' as InternetGetConnectedState:dword
    extrn '__imp_InternetGetConnectedStateExA@16' as InternetGetConnectedStateExA:dword
    extrn '__imp_InternetGetConnectedStateExW@16' as InternetGetConnectedStateExW:dword
    extrn '__imp_InternetGetCookieA@16' as InternetGetCookieA:dword
    extrn '__imp_InternetGetCookieExA@24' as InternetGetCookieExA:dword
    extrn '__imp_InternetGetCookieExW@24' as InternetGetCookieExW:dword
    extrn '__imp_InternetGetCookieW@16' as InternetGetCookieW:dword
    extrn '__imp_InternetGetLastResponseInfoA@12' as InternetGetLastResponseInfoA:dword
    extrn '__imp_InternetGetLastResponseInfoW@12' as InternetGetLastResponseInfoW:dword
    extrn '__imp_InternetGetPerSiteCookieDecisionA@8' as InternetGetPerSiteCookieDecisionA:dword
    extrn '__imp_InternetGetPerSiteCookieDecisionW@8' as InternetGetPerSiteCookieDecisionW:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_InternetGetProxyForUrl@12' as InternetGetProxyForUrl:dword
    end if
    extrn '__imp_InternetGetSecurityInfoByURLA@12' as InternetGetSecurityInfoByURLA:dword
    extrn '__imp_InternetGetSecurityInfoByURLW@12' as InternetGetSecurityInfoByURLW:dword
    extrn '__imp_InternetGoOnlineA@12' as InternetGoOnlineA:dword
    extrn '__imp_InternetGoOnlineW@12' as InternetGoOnlineW:dword
    extrn '__imp_InternetHangUp@8' as InternetHangUp:dword
    extrn '__imp_InternetInitializeAutoProxyDll@4' as InternetInitializeAutoProxyDll:dword
    extrn '__imp_InternetLockRequestFile@8' as InternetLockRequestFile:dword
    extrn '__imp_InternetOpenA@20' as InternetOpenA:dword
    extrn '__imp_InternetOpenUrlA@24' as InternetOpenUrlA:dword
    extrn '__imp_InternetOpenUrlW@24' as InternetOpenUrlW:dword
    extrn '__imp_InternetOpenW@20' as InternetOpenW:dword
    extrn '__imp_InternetQueryDataAvailable@16' as InternetQueryDataAvailable:dword
    extrn '__imp_InternetQueryFortezzaStatus@8' as InternetQueryFortezzaStatus:dword
    extrn '__imp_InternetQueryOptionA@16' as InternetQueryOptionA:dword
    extrn '__imp_InternetQueryOptionW@16' as InternetQueryOptionW:dword
    extrn '__imp_InternetReadFile@16' as InternetReadFile:dword
    extrn '__imp_InternetReadFileExA@16' as InternetReadFileExA:dword
    extrn '__imp_InternetReadFileExW@16' as InternetReadFileExW:dword
    extrn '__imp_InternetSecurityProtocolToStringA@16' as InternetSecurityProtocolToStringA:dword
    extrn '__imp_InternetSecurityProtocolToStringW@16' as InternetSecurityProtocolToStringW:dword
    extrn '__imp_InternetSetCookieA@12' as InternetSetCookieA:dword
    extrn '__imp_InternetSetCookieExA@20' as InternetSetCookieExA:dword
    extrn '__imp_InternetSetCookieExW@20' as InternetSetCookieExW:dword
    extrn '__imp_InternetSetCookieW@12' as InternetSetCookieW:dword
    extrn '__imp_InternetSetDialStateA@12' as InternetSetDialStateA:dword
    extrn '__imp_InternetSetDialStateW@12' as InternetSetDialStateW:dword
    extrn '__imp_InternetSetFilePointer@20' as InternetSetFilePointer:dword
    extrn '__imp_InternetSetOptionA@16' as InternetSetOptionA:dword
    extrn '__imp_InternetSetOptionExA@20' as InternetSetOptionExA:dword
    extrn '__imp_InternetSetOptionExW@20' as InternetSetOptionExW:dword
    extrn '__imp_InternetSetOptionW@16' as InternetSetOptionW:dword
    extrn '__imp_InternetSetPerSiteCookieDecisionA@8' as InternetSetPerSiteCookieDecisionA:dword
    extrn '__imp_InternetSetPerSiteCookieDecisionW@8' as InternetSetPerSiteCookieDecisionW:dword
    extrn '__imp_InternetSetStatusCallbackA@8' as InternetSetStatusCallbackA:dword
    extrn '__imp_InternetSetStatusCallbackW@8' as InternetSetStatusCallbackW:dword
    extrn '__imp_InternetShowSecurityInfoByURLA@8' as InternetShowSecurityInfoByURLA:dword
    extrn '__imp_InternetShowSecurityInfoByURLW@8' as InternetShowSecurityInfoByURLW:dword
    extrn '__imp_InternetTimeFromSystemTimeA@16' as InternetTimeFromSystemTimeA:dword
    extrn '__imp_InternetTimeFromSystemTimeW@16' as InternetTimeFromSystemTimeW:dword
    extrn '__imp_InternetTimeToSystemTimeA@12' as InternetTimeToSystemTimeA:dword
    extrn '__imp_InternetTimeToSystemTimeW@12' as InternetTimeToSystemTimeW:dword
    extrn '__imp_InternetUnlockRequestFile@4' as InternetUnlockRequestFile:dword
    extrn '__imp_InternetWriteFile@16' as InternetWriteFile:dword
    extrn '__imp_InternetWriteFileExA@16' as InternetWriteFileExA:dword
    extrn '__imp_InternetWriteFileExW@16' as InternetWriteFileExW:dword
    extrn '__imp_IsHostInProxyBypassList@12' as IsHostInProxyBypassList:dword
    extrn '__imp_IsUrlCacheEntryExpiredA@12' as IsUrlCacheEntryExpiredA:dword
    extrn '__imp_IsUrlCacheEntryExpiredW@12' as IsUrlCacheEntryExpiredW:dword
    extrn '__imp_LoadUrlCacheContent@0' as LoadUrlCacheContent:dword
    extrn '__imp_ParseX509EncodedCertificateForListBoxEntry@16' as ParseX509EncodedCertificateForListBoxEntry:dword
    extrn '__imp_PrivacyGetZonePreferenceW@20' as PrivacyGetZonePreferenceW:dword
    extrn '__imp_PrivacySetZonePreferenceW@16' as PrivacySetZonePreferenceW:dword
    extrn '__imp_ReadUrlCacheEntryStream@20' as ReadUrlCacheEntryStream:dword
    extrn '__imp_RegisterUrlCacheNotification@24' as RegisterUrlCacheNotification:dword
    extrn '__imp_ResumeSuspendedDownload@8' as ResumeSuspendedDownload:dword
    extrn '__imp_RetrieveUrlCacheEntryFileA@16' as RetrieveUrlCacheEntryFileA:dword
    extrn '__imp_RetrieveUrlCacheEntryFileW@16' as RetrieveUrlCacheEntryFileW:dword
    extrn '__imp_RetrieveUrlCacheEntryStreamA@20' as RetrieveUrlCacheEntryStreamA:dword
    extrn '__imp_RetrieveUrlCacheEntryStreamW@20' as RetrieveUrlCacheEntryStreamW:dword
    extrn '__imp_RunOnceUrlCache@16' as RunOnceUrlCache:dword
    extrn '__imp_SetUrlCacheConfigInfoA@8' as SetUrlCacheConfigInfoA:dword
    extrn '__imp_SetUrlCacheConfigInfoW@8' as SetUrlCacheConfigInfoW:dword
    extrn '__imp_SetUrlCacheEntryGroupA@28' as SetUrlCacheEntryGroupA:dword
    extrn '__imp_SetUrlCacheEntryGroupW@28' as SetUrlCacheEntryGroupW:dword
    extrn '__imp_SetUrlCacheEntryInfoA@12' as SetUrlCacheEntryInfoA:dword
    extrn '__imp_SetUrlCacheEntryInfoW@12' as SetUrlCacheEntryInfoW:dword
    extrn '__imp_SetUrlCacheGroupAttributeA@24' as SetUrlCacheGroupAttributeA:dword
    extrn '__imp_SetUrlCacheGroupAttributeW@24' as SetUrlCacheGroupAttributeW:dword
    extrn '__imp_SetUrlCacheHeaderData@8' as SetUrlCacheHeaderData:dword
    extrn '__imp_ShowCertificate@8' as ShowCertificate:dword
    extrn '__imp_ShowClientAuthCerts@4' as ShowClientAuthCerts:dword
    extrn '__imp_ShowSecurityInfo@8' as ShowSecurityInfo:dword
    extrn '__imp_ShowX509EncodedCertificate@12' as ShowX509EncodedCertificate:dword
    extrn '__imp_UnlockUrlCacheEntryFileA@8' as UnlockUrlCacheEntryFileA:dword
    extrn '__imp_UnlockUrlCacheEntryFileW@8' as UnlockUrlCacheEntryFileW:dword
    extrn '__imp_UnlockUrlCacheEntryStream@8' as UnlockUrlCacheEntryStream:dword
    extrn '__imp_UpdateUrlCacheContentPath@4' as UpdateUrlCacheContentPath:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_UrlCacheCheckEntriesExist@12' as UrlCacheCheckEntriesExist:dword
        extrn '__imp_UrlCacheCloseEntryHandle@4' as UrlCacheCloseEntryHandle:dword
        extrn '__imp_UrlCacheCreateContainer@20' as UrlCacheCreateContainer:dword
        extrn '__imp_UrlCacheFreeEntryInfo@4' as UrlCacheFreeEntryInfo:dword
        extrn '__imp_UrlCacheGetEntryInfo@12' as UrlCacheGetEntryInfo:dword
        extrn '__imp_UrlCacheGetGlobalLimit@8' as UrlCacheGetGlobalLimit:dword
        extrn '__imp_UrlCacheRetrieveEntryFile@16' as UrlCacheRetrieveEntryFile:dword
        extrn '__imp_UrlCacheSetGlobalLimit@8' as UrlCacheSetGlobalLimit:dword
        extrn '__imp_UrlCacheUpdateEntryExtraData@16' as UrlCacheUpdateEntryExtraData:dword
        extrn '__imp_UrlZonesDetach@0' as UrlZonesDetach:dword
    end if
end if

api INTERNET_PER_CONN_OPTION,\
    INTERNET_PER_CONN_OPTION_LIST,\
    URL_COMPONENTS,\
    INTERNET_BUFFERS,\
    GOPHER_FIND_DATA,\
    INTERNET_CACHE_ENTRY_INFO,\
    INTERNET_CACHE_GROUP_INFO,\
    CommitUrlCacheEntry,\
    CreateUrlCacheContainer,\
    CreateUrlCacheEntry,\
    DeleteUrlCacheContainer,\
    DeleteUrlCacheEntry,\
    FindFirstUrlCacheContainer,\
    FindFirstUrlCacheEntry,\
    FindFirstUrlCacheEntryEx,\
    FindNextUrlCacheContainer,\
    FindNextUrlCacheEntry,\
    FindNextUrlCacheEntryEx,\
    FreeUrlCacheSpace,\
    FtpCommand,\
    FtpCreateDirectory,\
    FtpDeleteFile,\
    FtpFindFirstFile,\
    FtpGetCurrentDirectory,\
    FtpGetFile,\
    FtpOpenFile,\
    FtpPutFile,\
    FtpRemoveDirectory,\
    FtpRenameFile,\
    FtpSetCurrentDirectory,\
    GetUrlCacheConfigInfo,\
    GetUrlCacheEntryInfo,\
    GetUrlCacheEntryInfoEx,\
    GetUrlCacheGroupAttribute,\
    GopherCreateLocator,\
    GopherFindFirstFile,\
    GopherGetAttribute,\
    GopherGetLocatorType,\
    GopherOpenFile,\
    HttpAddRequestHeaders,\
    HttpCheckDavCompliance,\
    HttpEndRequest,\
    HttpOpenRequest,\
    HttpQueryInfo,\
    HttpSendRequest,\
    HttpSendRequestEx,\
    InternetAlgIdToString,\
    InternetCanonicalizeUrl,\
    InternetCheckConnection,\
    InternetCombineUrl,\
    InternetConfirmZoneCrossing,\
    InternetConnect,\
    InternetCrackUrl,\
    InternetCreateUrl,\
    InternetDial,\
    InternetEnumPerSiteCookieDecision,\
    InternetFindNextFile,\
    InternetGetConnectedStateEx,\
    InternetGetCookie,\
    InternetGetCookieEx,\
    InternetGetLastResponseInfo,\
    InternetGetPerSiteCookieDecision,\
    InternetGetSecurityInfoByURL,\
    InternetGoOnline,\
    InternetOpen,\
    InternetOpenUrl,\
    InternetQueryOption,\
    InternetReadFileEx,\
    InternetSecurityProtocolToString,\
    InternetSetCookie,\
    InternetSetCookieEx,\
    InternetSetDialState,\
    InternetSetOption,\
    InternetSetOptionEx,\
    InternetSetPerSiteCookieDecision,\
    InternetSetStatusCallback,\
    InternetShowSecurityInfoByURL,\
    InternetTimeFromSystemTime,\
    InternetTimeToSystemTime,\
    InternetWriteFileEx,\
    IsUrlCacheEntryExpired,\
    RetrieveUrlCacheEntryFile,\
    RetrieveUrlCacheEntryStream,\
    SetUrlCacheConfigInfo,\
    SetUrlCacheEntryGroup,\
    SetUrlCacheEntryInfo,\
    SetUrlCacheGroupAttribute,\
    UnlockUrlCacheEntryFile

end if ;WININET_INC
