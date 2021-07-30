; ====================================================;
;                                                     ;
;     odbc32.inc for EC v2 Fasm classic projects      ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined ODBC32_INC
define ODBC32_INC  1

SQL_NULL_DATA                                       equ     (-1)
SQL_DATA_AT_EXEC                                    equ     (-2)

SQL_SUCCESS                                         equ     0
SQL_SUCCESS_WITH_INFO                               equ     1
SQL_NO_DATA                                         equ     100
SQL_ERROR                                           equ     (-1)
SQL_INVALID_HANDLE                                  equ     (-2)

SQL_STILL_EXECUTING                                 equ     2
SQL_NEED_DATA                                       equ     99

SQL_NTS                                             equ     (-3)
SQL_NTSL                                            equ     (-3)

SQL_MAX_MESSAGE_LENGTH                              equ     512

SQL_DATE_LEN                                        equ     10
SQL_TIME_LEN                                        equ     8
SQL_TIMESTAMP_LEN                                   equ     19

SQL_HANDLE_ENV                                      equ     1
SQL_HANDLE_DBC                                      equ     2
SQL_HANDLE_STMT                                     equ     3
SQL_HANDLE_DESC                                     equ     4

SQL_ATTR_OUTPUT_NTS                                 equ     10001
SQL_ATTR_AUTO_IPD                                   equ     10001
SQL_ATTR_METADATA_ID                                equ     10014
SQL_ATTR_APP_ROW_DESC                               equ     10010
SQL_ATTR_APP_PARAM_DESC                             equ     10011
SQL_ATTR_IMP_ROW_DESC                               equ     10012
SQL_ATTR_IMP_PARAM_DESC                             equ     10013
SQL_ATTR_CURSOR_SCROLLABLE                          equ     (-1)
SQL_ATTR_CURSOR_SENSITIVITY                         equ     (-2)

SQL_NONSCROLLABLE                                   equ     0
SQL_SCROLLABLE                                      equ     1

SQL_DESC_COUNT                                      equ     1001
SQL_DESC_TYPE                                       equ     1002
SQL_DESC_LENGTH                                     equ     1003
SQL_DESC_OCTET_LENGTH_PTR                           equ     1004
SQL_DESC_PRECISION                                  equ     1005
SQL_DESC_SCALE                                      equ     1006
SQL_DESC_DATETIME_INTERVAL_CODE                     equ     1007
SQL_DESC_NULLABLE                                   equ     1008
SQL_DESC_INDICATOR_PTR                              equ     1009
SQL_DESC_DATA_PTR                                   equ     1010
SQL_DESC_NAME                                       equ     1011
SQL_DESC_UNNAMED                                    equ     1012
SQL_DESC_OCTET_LENGTH                               equ     1013
SQL_DESC_ALLOC_TYPE                                 equ     1099

SQL_DIAG_RETURNCODE                                 equ     1
SQL_DIAG_NUMBER                                     equ     2
SQL_DIAG_ROW_COUNT                                  equ     3
SQL_DIAG_SQLSTATE                                   equ     4
SQL_DIAG_NATIVE                                     equ     5
SQL_DIAG_MESSAGE_TEXT                               equ     6
SQL_DIAG_DYNAMIC_FUNCTION                           equ     7
SQL_DIAG_CLASS_ORIGIN                               equ     8
SQL_DIAG_SUBCLASS_ORIGIN                            equ     9
SQL_DIAG_CONNECTION_NAME                            equ     10
SQL_DIAG_SERVER_NAME                                equ     11
SQL_DIAG_DYNAMIC_FUNCTION_CODE                      equ     12

SQL_DIAG_ALTER_DOMAIN                               equ     3
SQL_DIAG_ALTER_TABLE                                equ     4
SQL_DIAG_CALL                                       equ     7
SQL_DIAG_CREATE_ASSERTION                           equ     6
SQL_DIAG_CREATE_CHARACTER_SET                       equ     8
SQL_DIAG_CREATE_COLLATION                           equ     10
SQL_DIAG_CREATE_DOMAIN                              equ     23
SQL_DIAG_CREATE_INDEX                               equ     (-1)
SQL_DIAG_CREATE_SCHEMA                              equ     64
SQL_DIAG_CREATE_TABLE                               equ     77
SQL_DIAG_CREATE_TRANSLATION                         equ     79
SQL_DIAG_CREATE_VIEW                                equ     84
SQL_DIAG_DELETE_WHERE                               equ     19
SQL_DIAG_DROP_ASSERTION                             equ     24
SQL_DIAG_DROP_CHARACTER_SET                         equ     25
SQL_DIAG_DROP_COLLATION                             equ     26
SQL_DIAG_DROP_DOMAIN                                equ     27
SQL_DIAG_DROP_INDEX                                 equ     (-2)
SQL_DIAG_DROP_SCHEMA                                equ     31
SQL_DIAG_DROP_TABLE                                 equ     32
SQL_DIAG_DROP_TRANSLATION                           equ     33
SQL_DIAG_DROP_VIEW                                  equ     36
SQL_DIAG_DYNAMIC_DELETE_CURSOR                      equ     38
SQL_DIAG_DYNAMIC_UPDATE_CURSOR                      equ     81
SQL_DIAG_GRANT                                      equ     48
SQL_DIAG_INSERT                                     equ     50
SQL_DIAG_REVOKE                                     equ     59
SQL_DIAG_SELECT_CURSOR                              equ     85
SQL_DIAG_UNKNOWN_STATEMENT                          equ     0
SQL_DIAG_UPDATE_WHERE                               equ     82

SQL_UNKNOWN_TYPE                                    equ     0
SQL_CHAR                                            equ     1
SQL_NUMERIC                                         equ     2
SQL_DECIMAL                                         equ     3
SQL_INTEGER                                         equ     4
SQL_SMALLINT                                        equ     5
SQL_FLOAT                                           equ     6
SQL_REAL                                            equ     7
SQL_DOUBLE                                          equ     8
SQL_DATETIME                                        equ     9
SQL_VARCHAR                                         equ     12

SQL_TYPE_DATE                                       equ     91
SQL_TYPE_TIME                                       equ     92
SQL_TYPE_TIMESTAMP                                  equ     93

SQL_UNSPECIFIED                                     equ     0
SQL_INSENSITIVE                                     equ     1
SQL_SENSITIVE                                       equ     2

SQL_ALL_TYPES                                       equ     0

SQL_DEFAULT                                         equ     99

SQL_ARD_TYPE                                        equ     (-99)

SQL_CODE_DATE                                       equ     1
SQL_CODE_TIME                                       equ     2
SQL_CODE_TIMESTAMP                                  equ     3

SQL_FALSE                                           equ     0
SQL_TRUE                                            equ     1

SQL_NO_NULLS                                        equ     0
SQL_NULLABLE                                        equ     1

SQL_NULLABLE_UNKNOWN                                equ     2

SQL_PRED_NONE                                       equ     0
SQL_PRED_CHAR                                       equ     1
SQL_PRED_BASIC                                      equ     2

SQL_NAMED                                           equ     0
SQL_UNNAMED                                         equ     1

SQL_DESC_ALLOC_AUTO                                 equ     1
SQL_DESC_ALLOC_USER                                 equ     2

SQL_CLOSE                                           equ     0
SQL_DROP                                            equ     1
SQL_UNBIND                                          equ     2
SQL_RESET_PARAMS                                    equ     3

SQL_FETCH_NEXT                                      equ     1
SQL_FETCH_FIRST                                     equ     2

SQL_FETCH_LAST                                      equ     3
SQL_FETCH_PRIOR                                     equ     4
SQL_FETCH_ABSOLUTE                                  equ     5
SQL_FETCH_RELATIVE                                  equ     6

SQL_COMMIT                                          equ     0
SQL_ROLLBACK                                        equ     1

SQL_NULL_HENV                                       equ     0
SQL_NULL_HDBC                                       equ     0
SQL_NULL_HSTMT                                      equ     0
SQL_NULL_HDESC                                      equ     0

SQL_NULL_HANDLE                                     equ     0L

SQL_SCOPE_CURROW                                    equ     0
SQL_SCOPE_TRANSACTION                               equ     1
SQL_SCOPE_SESSION                                   equ     2

SQL_PC_UNKNOWN                                      equ     0
SQL_PC_NON_PSEUDO                                   equ     1
SQL_PC_PSEUDO                                       equ     2

SQL_ROW_IDENTIFIER                                  equ     1

SQL_INDEX_UNIQUE                                    equ     0
SQL_INDEX_ALL                                       equ     1

SQL_INDEX_CLUSTERED                                 equ     1
SQL_INDEX_HASHED                                    equ     2
SQL_INDEX_OTHER                                     equ     3

SQL_API_SQLALLOCCONNECT                             equ     1
SQL_API_SQLALLOCENV                                 equ     2
SQL_API_SQLALLOCHANDLE                              equ     1001
SQL_API_SQLALLOCSTMT                                equ     3
SQL_API_SQLBINDCOL                                  equ     4
SQL_API_SQLBINDPARAM                                equ     1002
SQL_API_SQLCANCEL                                   equ     5
SQL_API_SQLCLOSECURSOR                              equ     1003
SQL_API_SQLCOLATTRIBUTE                             equ     6
SQL_API_SQLCOLUMNS                                  equ     40
SQL_API_SQLCONNECT                                  equ     7
SQL_API_SQLCOPYDESC                                 equ     1004
SQL_API_SQLDATASOURCES                              equ     57
SQL_API_SQLDESCRIBECOL                              equ     8
SQL_API_SQLDISCONNECT                               equ     9
SQL_API_SQLENDTRAN                                  equ     1005
SQL_API_SQLERROR                                    equ     10
SQL_API_SQLEXECDIRECT                               equ     11
SQL_API_SQLEXECUTE                                  equ     12
SQL_API_SQLFETCH                                    equ     13
SQL_API_SQLFETCHSCROLL                              equ     1021
SQL_API_SQLFREECONNECT                              equ     14
SQL_API_SQLFREEENV                                  equ     15
SQL_API_SQLFREEHANDLE                               equ     1006
SQL_API_SQLFREESTMT                                 equ     16
SQL_API_SQLGETCONNECTATTR                           equ     1007
SQL_API_SQLGETCONNECTOPTION                         equ     42
SQL_API_SQLGETCURSORNAME                            equ     17
SQL_API_SQLGETDATA                                  equ     43
SQL_API_SQLGETDESCFIELD                             equ     1008
SQL_API_SQLGETDESCREC                               equ     1009
SQL_API_SQLGETDIAGFIELD                             equ     1010
SQL_API_SQLGETDIAGREC                               equ     1011
SQL_API_SQLGETENVATTR                               equ     1012
SQL_API_SQLGETFUNCTIONS                             equ     44
SQL_API_SQLGETINFO                                  equ     45
SQL_API_SQLGETSTMTATTR                              equ     1014
SQL_API_SQLGETSTMTOPTION                            equ     46
SQL_API_SQLGETTYPEINFO                              equ     47
SQL_API_SQLNUMRESULTCOLS                            equ     18
SQL_API_SQLPARAMDATA                                equ     48
SQL_API_SQLPREPARE                                  equ     19
SQL_API_SQLPUTDATA                                  equ     49
SQL_API_SQLROWCOUNT                                 equ     20
SQL_API_SQLSETCONNECTATTR                           equ     1016
SQL_API_SQLSETCONNECTOPTION                         equ     50
SQL_API_SQLSETCURSORNAME                            equ     21
SQL_API_SQLSETDESCFIELD                             equ     1017
SQL_API_SQLSETDESCREC                               equ     1018
SQL_API_SQLSETENVATTR                               equ     1019
SQL_API_SQLSETPARAM                                 equ     22
SQL_API_SQLSETSTMTATTR                              equ     1020
SQL_API_SQLSETSTMTOPTION                            equ     51
SQL_API_SQLSPECIALCOLUMNS                           equ     52
SQL_API_SQLSTATISTICS                               equ     53
SQL_API_SQLTABLES                                   equ     54
SQL_API_SQLTRANSACT                                 equ     23

SQL_MAX_DRIVER_CONNECTIONS                          equ     0
SQL_MAXIMUM_DRIVER_CONNECTIONS                      equ     SQL_MAX_DRIVER_CONNECTIONS
SQL_MAX_CONCURRENT_ACTIVITIES                       equ     1
SQL_MAXIMUM_CONCURRENT_ACTIVITIES                   equ     SQL_MAX_CONCURRENT_ACTIVITIES
SQL_DATA_SOURCE_NAME                                equ     2
SQL_FETCH_DIRECTION                                 equ     8
SQL_SERVER_NAME                                     equ     13
SQL_SEARCH_PATTERN_ESCAPE                           equ     14
SQL_DBMS_NAME                                       equ     17
SQL_DBMS_VER                                        equ     18
SQL_ACCESSIBLE_TABLES                               equ     19
SQL_ACCESSIBLE_PROCEDURES                           equ     20
SQL_CURSOR_COMMIT_BEHAVIOR                          equ     23
SQL_DATA_SOURCE_READ_ONLY                           equ     25
SQL_DEFAULT_TXN_ISOLATION                           equ     26
SQL_IDENTIFIER_CASE                                 equ     28
SQL_IDENTIFIER_QUOTE_CHAR                           equ     29
SQL_MAX_COLUMN_NAME_LEN                             equ     30
SQL_MAXIMUM_COLUMN_NAME_LENGTH                      equ     SQL_MAX_COLUMN_NAME_LEN
SQL_MAX_CURSOR_NAME_LEN                             equ     31
SQL_MAXIMUM_CURSOR_NAME_LENGTH                      equ     SQL_MAX_CURSOR_NAME_LEN
SQL_MAX_SCHEMA_NAME_LEN                             equ     32
SQL_MAXIMUM_SCHEMA_NAME_LENGTH                      equ     SQL_MAX_SCHEMA_NAME_LEN
SQL_MAX_CATALOG_NAME_LEN                            equ     34
SQL_MAXIMUM_CATALOG_NAME_LENGTH                     equ     SQL_MAX_CATALOG_NAME_LEN
SQL_MAX_TABLE_NAME_LEN                              equ     35
SQL_SCROLL_CONCURRENCY                              equ     43
SQL_TXN_CAPABLE                                     equ     46
SQL_TRANSACTION_CAPABLE                             equ     SQL_TXN_CAPABLE
SQL_USER_NAME                                       equ     47
SQL_TXN_ISOLATION_OPTION                            equ     72
SQL_TRANSACTION_ISOLATION_OPTION                    equ     SQL_TXN_ISOLATION_OPTION
SQL_INTEGRITY                                       equ     73
SQL_GETDATA_EXTENSIONS                              equ     81
SQL_NULL_COLLATION                                  equ     85
SQL_ALTER_TABLE                                     equ     86
SQL_ORDER_BY_COLUMNS_IN_SELECT                      equ     90
SQL_SPECIAL_CHARACTERS                              equ     94
SQL_MAX_COLUMNS_IN_GROUP_BY                         equ     97
SQL_MAXIMUM_COLUMNS_IN_GROUP_BY                     equ     SQL_MAX_COLUMNS_IN_GROUP_BY
SQL_MAX_COLUMNS_IN_INDEX                            equ     98
SQL_MAXIMUM_COLUMNS_IN_INDEX                        equ     SQL_MAX_COLUMNS_IN_INDEX
SQL_MAX_COLUMNS_IN_ORDER_BY                         equ     99
SQL_MAXIMUM_COLUMNS_IN_ORDER_BY                     equ     SQL_MAX_COLUMNS_IN_ORDER_BY
SQL_MAX_COLUMNS_IN_SELECT                           equ     100
SQL_MAXIMUM_COLUMNS_IN_SELECT                       equ     SQL_MAX_COLUMNS_IN_SELECT
SQL_MAX_COLUMNS_IN_TABLE                            equ     101
SQL_MAX_INDEX_SIZE                                  equ     102
SQL_MAXIMUM_INDEX_SIZE                              equ     SQL_MAX_INDEX_SIZE
SQL_MAX_ROW_SIZE                                    equ     104
SQL_MAXIMUM_ROW_SIZE                                equ     SQL_MAX_ROW_SIZE
SQL_MAX_STATEMENT_LEN                               equ     105
SQL_MAXIMUM_STATEMENT_LENGTH                        equ     SQL_MAX_STATEMENT_LEN
SQL_MAX_TABLES_IN_SELECT                            equ     106
SQL_MAXIMUM_TABLES_IN_SELECT                        equ     SQL_MAX_TABLES_IN_SELECT
SQL_MAX_USER_NAME_LEN                               equ     107
SQL_MAXIMUM_USER_NAME_LENGTH                        equ     SQL_MAX_USER_NAME_LEN
SQL_OJ_CAPABILITIES                                 equ     115
SQL_OUTER_JOIN_CAPABILITIES                         equ     SQL_OJ_CAPABILITIES

SQL_XOPEN_CLI_YEAR                                  equ     10000
SQL_CURSOR_SENSITIVITY                              equ     10001
SQL_DESCRIBE_PARAMETER                              equ     10002
SQL_CATALOG_NAME                                    equ     10003
SQL_COLLATION_SEQ                                   equ     10004
SQL_MAX_IDENTIFIER_LEN                              equ     10005
SQL_MAXIMUM_IDENTIFIER_LENGTH                       equ     SQL_MAX_IDENTIFIER_LEN

SQL_AT_ADD_COLUMN                                   equ     00000001H
SQL_AT_DROP_COLUMN                                  equ     00000002H
SQL_AT_ADD_CONSTRAINT                               equ     00000008H

SQL_AM_NONE                                         equ     0
SQL_AM_CONNECTION                                   equ     1
SQL_AM_STATEMENT                                    equ     2

SQL_CB_DELETE                                       equ     0
SQL_CB_CLOSE                                        equ     1
SQL_CB_PRESERVE                                     equ     2

SQL_FD_FETCH_NEXT                                   equ     00000001H
SQL_FD_FETCH_FIRST                                  equ     00000002H
SQL_FD_FETCH_LAST                                   equ     00000004H
SQL_FD_FETCH_PRIOR                                  equ     00000008H
SQL_FD_FETCH_ABSOLUTE                               equ     00000010H
SQL_FD_FETCH_RELATIVE                               equ     00000020H

SQL_GD_ANY_COLUMN                                   equ     00000001H
SQL_GD_ANY_ORDER                                    equ     00000002H

SQL_IC_UPPER                                        equ     1
SQL_IC_LOWER                                        equ     2
SQL_IC_SENSITIVE                                    equ     3
SQL_IC_MIXED                                        equ     4

SQL_OJ_LEFT                                         equ     00000001H
SQL_OJ_RIGHT                                        equ     00000002H
SQL_OJ_FULL                                         equ     00000004H
SQL_OJ_NESTED                                       equ     00000008H
SQL_OJ_NOT_ORDERED                                  equ     00000010H
SQL_OJ_INNER                                        equ     00000020H
SQL_OJ_ALL_COMPARISON_OPS                           equ     00000040H

SQL_SCCO_READ_ONLY                                  equ     00000001H
SQL_SCCO_LOCK                                       equ     00000002H
SQL_SCCO_OPT_ROWVER                                 equ     00000004H
SQL_SCCO_OPT_VALUES                                 equ     00000008H

SQL_TC_NONE                                         equ     0
SQL_TC_DML                                          equ     1
SQL_TC_ALL                                          equ     2
SQL_TC_DDL_COMMIT                                   equ     3
SQL_TC_DDL_IGNORE                                   equ     4

SQL_TXN_READ_UNCOMMITTED                            equ     00000001H
SQL_TRANSACTION_READ_UNCOMMITTED                    equ     SQL_TXN_READ_UNCOMMITTED
SQL_TXN_READ_COMMITTED                              equ     00000002H
SQL_TRANSACTION_READ_COMMITTED                      equ     SQL_TXN_READ_COMMITTED
SQL_TXN_REPEATABLE_READ                             equ     00000004H
SQL_TRANSACTION_REPEATABLE_READ                     equ     SQL_TXN_REPEATABLE_READ
SQL_TXN_SERIALIZABLE                                equ     00000008H
SQL_TRANSACTION_SERIALIZABLE                        equ     SQL_TXN_SERIALIZABLE

SQL_NC_HIGH                                         equ     0
SQL_NC_LOW                                          equ     1

SQL_SPEC_MAJOR                                      equ     3
SQL_SPEC_MINOR                                      equ     52
SQL_SPEC_STRING                                     equ     A("03.52")

SQL_SQLSTATE_SIZE                                   equ     5
SQL_MAX_DSN_LENGTH                                  equ     32

SQL_MAX_OPTION_STRING_LENGTH                        equ     256

SQL_NO_DATA_FOUND                                   equ     SQL_NO_DATA

SQL_HANDLE_SENV                                     equ     5

SQL_ATTR_ODBC_VERSION                               equ     200
SQL_ATTR_CONNECTION_POOLING                         equ     201
SQL_ATTR_CP_MATCH                                   equ     202

SQL_CP_OFF                                          equ     0
SQL_CP_ONE_PER_DRIVER                               equ     1
SQL_CP_ONE_PER_HENV                                 equ     2
SQL_CP_DEFAULT                                      equ     SQL_CP_OFF
SQL_CP_STRICT_MATCH                                 equ     0
SQL_CP_RELAXED_MATCH                                equ     1
SQL_CP_MATCH_DEFAULT                                equ     SQL_CP_STRICT_MATCH

SQL_OV_ODBC2                                        equ     2
SQL_OV_ODBC3                                        equ     3

SQL_ACCESS_MODE                                     equ     101
SQL_AUTOCOMMIT                                      equ     102
SQL_LOGIN_TIMEOUT                                   equ     103
SQL_OPT_TRACE                                       equ     104
SQL_OPT_TRACEFILE                                   equ     105
SQL_TRANSLATE_DLL                                   equ     106
SQL_TRANSLATE_OPTION                                equ     107
SQL_TXN_ISOLATION                                   equ     108
SQL_CURRENT_QUALIFIER                               equ     109
SQL_ODBC_CURSORS                                    equ     110
SQL_QUIET_MODE                                      equ     111
SQL_PACKET_SIZE                                     equ     112

SQL_ATTR_ACCESS_MODE                                equ     SQL_ACCESS_MODE
SQL_ATTR_AUTOCOMMIT                                 equ     SQL_AUTOCOMMIT
SQL_ATTR_CONNECTION_TIMEOUT                         equ     113
SQL_ATTR_CURRENT_CATALOG                            equ     SQL_CURRENT_QUALIFIER
SQL_ATTR_DISCONNECT_BEHAVIOR                        equ     114
SQL_ATTR_ENLIST_IN_DTC                              equ     1207
SQL_ATTR_ENLIST_IN_XA                               equ     1208
SQL_ATTR_LOGIN_TIMEOUT                              equ     SQL_LOGIN_TIMEOUT
SQL_ATTR_ODBC_CURSORS                               equ     SQL_ODBC_CURSORS
SQL_ATTR_PACKET_SIZE                                equ     SQL_PACKET_SIZE
SQL_ATTR_QUIET_MODE                                 equ     SQL_QUIET_MODE
SQL_ATTR_TRACE                                      equ     SQL_OPT_TRACE
SQL_ATTR_TRACEFILE                                  equ     SQL_OPT_TRACEFILE
SQL_ATTR_TRANSLATE_LIB                              equ     SQL_TRANSLATE_DLL
SQL_ATTR_TRANSLATE_OPTION                           equ     SQL_TRANSLATE_OPTION
SQL_ATTR_TXN_ISOLATION                              equ     SQL_TXN_ISOLATION

SQL_ATTR_CONNECTION_DEAD                            equ     1209

SQL_ATTR_ANSI_APP                                   equ     115

SQL_MODE_READ_WRITE                                 equ     0
SQL_MODE_READ_ONLY                                  equ     1
SQL_MODE_DEFAULT                                    equ     SQL_MODE_READ_WRITE

SQL_AUTOCOMMIT_OFF                                  equ     0
SQL_AUTOCOMMIT_ON                                   equ     1
SQL_AUTOCOMMIT_DEFAULT                              equ     SQL_AUTOCOMMIT_ON

SQL_LOGIN_TIMEOUT_DEFAULT                           equ     15

SQL_OPT_TRACE_OFF                                   equ     0
SQL_OPT_TRACE_ON                                    equ     1
SQL_OPT_TRACE_DEFAULT                               equ     SQL_OPT_TRACE_OFF
SQL_OPT_TRACE_FILE_DEFAULT                          equ     A("\\SQL.LOG")

SQL_CUR_USE_IF_NEEDED                               equ     0
SQL_CUR_USE_ODBC                                    equ     1
SQL_CUR_USE_DRIVER                                  equ     2
SQL_CUR_DEFAULT                                     equ     SQL_CUR_USE_DRIVER

SQL_DB_RETURN_TO_POOL                               equ     0
SQL_DB_DISCONNECT                                   equ     1
SQL_DB_DEFAULT                                      equ     SQL_DB_RETURN_TO_POOL

SQL_DTC_DONE                                        equ     0

SQL_CD_TRUE                                         equ     1
SQL_CD_FALSE                                        equ     0

SQL_AA_TRUE                                         equ     1
SQL_AA_FALSE                                        equ     0

SQL_QUERY_TIMEOUT                                   equ     0
SQL_MAX_ROWS                                        equ     1
SQL_NOSCAN                                          equ     2
SQL_MAX_LENGTH                                      equ     3
SQL_ASYNC_ENABLE                                    equ     4
SQL_BIND_TYPE                                       equ     5
SQL_CURSOR_TYPE                                     equ     6
SQL_CONCURRENCY                                     equ     7
SQL_KEYSET_SIZE                                     equ     8
SQL_ROWSET_SIZE                                     equ     9
SQL_SIMULATE_CURSOR                                 equ     10
SQL_RETRIEVE_DATA                                   equ     11
SQL_USE_BOOKMARKS                                   equ     12
SQL_GET_BOOKMARK                                    equ     13
SQL_ROW_NUMBER                                      equ     14

SQL_ATTR_ASYNC_ENABLE                               equ     4
SQL_ATTR_CONCURRENCY                                equ     SQL_CONCURRENCY
SQL_ATTR_CURSOR_TYPE                                equ     SQL_CURSOR_TYPE
SQL_ATTR_ENABLE_AUTO_IPD                            equ     15
SQL_ATTR_FETCH_BOOKMARK_PTR                         equ     16
SQL_ATTR_KEYSET_SIZE                                equ     SQL_KEYSET_SIZE
SQL_ATTR_MAX_LENGTH                                 equ     SQL_MAX_LENGTH
SQL_ATTR_MAX_ROWS                                   equ     SQL_MAX_ROWS
SQL_ATTR_NOSCAN                                     equ     SQL_NOSCAN
SQL_ATTR_PARAM_BIND_OFFSET_PTR                      equ     17
SQL_ATTR_PARAM_BIND_TYPE                            equ     18
SQL_ATTR_PARAM_OPERATION_PTR                        equ     19
SQL_ATTR_PARAM_STATUS_PTR                           equ     20
SQL_ATTR_PARAMS_PROCESSED_PTR                       equ     21
SQL_ATTR_PARAMSET_SIZE                              equ     22
SQL_ATTR_QUERY_TIMEOUT                              equ     SQL_QUERY_TIMEOUT
SQL_ATTR_RETRIEVE_DATA                              equ     SQL_RETRIEVE_DATA
SQL_ATTR_ROW_BIND_OFFSET_PTR                        equ     23
SQL_ATTR_ROW_BIND_TYPE                              equ     SQL_BIND_TYPE
SQL_ATTR_ROW_NUMBER                                 equ     SQL_ROW_NUMBER
SQL_ATTR_ROW_OPERATION_PTR                          equ     24
SQL_ATTR_ROW_STATUS_PTR                             equ     25
SQL_ATTR_ROWS_FETCHED_PTR                           equ     26
SQL_ATTR_ROW_ARRAY_SIZE                             equ     27
SQL_ATTR_SIMULATE_CURSOR                            equ     SQL_SIMULATE_CURSOR
SQL_ATTR_USE_BOOKMARKS                              equ     SQL_USE_BOOKMARKS

SQL_COL_PRED_CHAR                                   equ     SQL_LIKE_ONLY
SQL_COL_PRED_BASIC                                  equ     SQL_ALL_EXCEPT_LIKE

SQL_IS_POINTER                                      equ     (-4)
SQL_IS_UINTEGER                                     equ     (-5)
SQL_IS_INTEGER                                      equ     (-6)
SQL_IS_USMALLINT                                    equ     (-7)
SQL_IS_SMALLINT                                     equ     (-8)

SQL_PARAM_BIND_BY_COLUMN                            equ     0
SQL_PARAM_BIND_TYPE_DEFAULT                         equ     SQL_PARAM_BIND_BY_COLUMN

SQL_QUERY_TIMEOUT_DEFAULT                           equ     0

SQL_MAX_ROWS_DEFAULT                                equ     0

SQL_NOSCAN_OFF                                      equ     0
SQL_NOSCAN_ON                                       equ     1
SQL_NOSCAN_DEFAULT                                  equ     SQL_NOSCAN_OFF

SQL_MAX_LENGTH_DEFAULT                              equ     0

SQL_ASYNC_ENABLE_OFF                                equ     0
SQL_ASYNC_ENABLE_ON                                 equ     1
SQL_ASYNC_ENABLE_DEFAULT                            equ     SQL_ASYNC_ENABLE_OFF

SQL_BIND_BY_COLUMN                                  equ     0
SQL_BIND_TYPE_DEFAULT                               equ     SQL_BIND_BY_COLUMN

SQL_CONCUR_READ_ONLY                                equ     1
SQL_CONCUR_LOCK                                     equ     2
SQL_CONCUR_ROWVER                                   equ     3
SQL_CONCUR_VALUES                                   equ     4
SQL_CONCUR_DEFAULT                                  equ     SQL_CONCUR_READ_ONLY

SQL_CURSOR_FORWARD_ONLY                             equ     0
SQL_CURSOR_KEYSET_DRIVEN                            equ     1
SQL_CURSOR_DYNAMIC                                  equ     2
SQL_CURSOR_STATIC                                   equ     3
SQL_CURSOR_TYPE_DEFAULT                             equ     SQL_CURSOR_FORWARD_ONLY

SQL_ROWSET_SIZE_DEFAULT                             equ     1

SQL_KEYSET_SIZE_DEFAULT                             equ     0

SQL_SC_NON_UNIQUE                                   equ     0
SQL_SC_TRY_UNIQUE                                   equ     1
SQL_SC_UNIQUE                                       equ     2

SQL_RD_OFF                                          equ     0
SQL_RD_ON                                           equ     1
SQL_RD_DEFAULT                                      equ     SQL_RD_ON

SQL_UB_OFF                                          equ     0
SQL_UB_ON                                           equ     01
SQL_UB_DEFAULT                                      equ     SQL_UB_OFF

SQL_UB_FIXED                                        equ     SQL_UB_ON
SQL_UB_VARIABLE                                     equ     2

SQL_DESC_ARRAY_SIZE                                 equ     20
SQL_DESC_ARRAY_STATUS_PTR                           equ     21
SQL_DESC_AUTO_UNIQUE_VALUE                          equ     SQL_COLUMN_AUTO_INCREMENT
SQL_DESC_BASE_COLUMN_NAME                           equ     22
SQL_DESC_BASE_TABLE_NAME                            equ     23
SQL_DESC_BIND_OFFSET_PTR                            equ     24
SQL_DESC_BIND_TYPE                                  equ     25
SQL_DESC_CASE_SENSITIVE                             equ     SQL_COLUMN_CASE_SENSITIVE
SQL_DESC_CATALOG_NAME                               equ     SQL_COLUMN_QUALIFIER_NAME
SQL_DESC_CONCISE_TYPE                               equ     SQL_COLUMN_TYPE
SQL_DESC_DATETIME_INTERVAL_PRECISION                equ     26
SQL_DESC_DISPLAY_SIZE                               equ     SQL_COLUMN_DISPLAY_SIZE
SQL_DESC_FIXED_PREC_SCALE                           equ     SQL_COLUMN_MONEY
SQL_DESC_LABEL                                      equ     SQL_COLUMN_LABEL
SQL_DESC_LITERAL_PREFIX                             equ     27
SQL_DESC_LITERAL_SUFFIX                             equ     28
SQL_DESC_LOCAL_TYPE_NAME                            equ     29
SQL_DESC_MAXIMUM_SCALE                              equ     30
SQL_DESC_MINIMUM_SCALE                              equ     31
SQL_DESC_NUM_PREC_RADIX                             equ     32
SQL_DESC_PARAMETER_TYPE                             equ     33
SQL_DESC_ROWS_PROCESSED_PTR                         equ     34
SQL_DESC_ROWVER                                     equ     35
SQL_DESC_SCHEMA_NAME                                equ     SQL_COLUMN_OWNER_NAME
SQL_DESC_SEARCHABLE                                 equ     SQL_COLUMN_SEARCHABLE
SQL_DESC_TYPE_NAME                                  equ     SQL_COLUMN_TYPE_NAME
SQL_DESC_TABLE_NAME                                 equ     SQL_COLUMN_TABLE_NAME
SQL_DESC_UNSIGNED                                   equ     SQL_COLUMN_UNSIGNED
SQL_DESC_UPDATABLE                                  equ     SQL_COLUMN_UPDATABLE

SQL_DIAG_CURSOR_ROW_COUNT                           equ     (-1249)
SQL_DIAG_ROW_NUMBER                                 equ     (-1248)
SQL_DIAG_COLUMN_NUMBER                              equ     (-1247)

SQL_DATE                                            equ     9
SQL_INTERVAL                                        equ     10
SQL_TIME                                            equ     10
SQL_TIMESTAMP                                       equ     11
SQL_LONGVARCHAR                                     equ     (-1)
SQL_BINARY                                          equ     (-2)
SQL_VARBINARY                                       equ     (-3)
SQL_LONGVARBINARY                                   equ     (-4)
SQL_BIGINT                                          equ     (-5)
SQL_TINYINT                                         equ     (-6)
SQL_BIT                                             equ     (-7)
SQL_GUID                                            equ     (-11)

SQL_CODE_YEAR                                       equ     1
SQL_CODE_MONTH                                      equ     2
SQL_CODE_DAY                                        equ     3
SQL_CODE_HOUR                                       equ     4
SQL_CODE_MINUTE                                     equ     5
SQL_CODE_SECOND                                     equ     6
SQL_CODE_YEAR_TO_MONTH                              equ     7
SQL_CODE_DAY_TO_HOUR                                equ     8
SQL_CODE_DAY_TO_MINUTE                              equ     9
SQL_CODE_DAY_TO_SECOND                              equ     10
SQL_CODE_HOUR_TO_MINUTE                             equ     11
SQL_CODE_HOUR_TO_SECOND                             equ     12
SQL_CODE_MINUTE_TO_SECOND                           equ     13

SQL_INTERVAL_YEAR                                   equ     (100 + SQL_CODE_YEAR)
SQL_INTERVAL_MONTH                                  equ     (100 + SQL_CODE_MONTH)
SQL_INTERVAL_DAY                                    equ     (100 + SQL_CODE_DAY)
SQL_INTERVAL_HOUR                                   equ     (100 + SQL_CODE_HOUR)
SQL_INTERVAL_MINUTE                                 equ     (100 + SQL_CODE_MINUTE)
SQL_INTERVAL_SECOND                                 equ     (100 + SQL_CODE_SECOND)
SQL_INTERVAL_YEAR_TO_MONTH                          equ     (100 + SQL_CODE_YEAR_TO_MONTH)
SQL_INTERVAL_DAY_TO_HOUR                            equ     (100 + SQL_CODE_DAY_TO_HOUR)
SQL_INTERVAL_DAY_TO_MINUTE                          equ     (100 + SQL_CODE_DAY_TO_MINUTE)
SQL_INTERVAL_DAY_TO_SECOND                          equ     (100 + SQL_CODE_DAY_TO_SECOND)
SQL_INTERVAL_HOUR_TO_MINUTE                         equ     (100 + SQL_CODE_HOUR_TO_MINUTE)
SQL_INTERVAL_HOUR_TO_SECOND                         equ     (100 + SQL_CODE_HOUR_TO_SECOND)
SQL_INTERVAL_MINUTE_TO_SECOND                       equ     (100 + SQL_CODE_MINUTE_TO_SECOND)

SQL_UNICODE                                         equ     SQL_WCHAR

SQL_UNICODE_VARCHAR                                 equ     SQL_WVARCHAR
SQL_UNICODE_LONGVARCHAR                             equ     SQL_WLONGVARCHAR
SQL_UNICODE_CHAR                                    equ     SQL_WCHAR

SQL_C_CHAR                                          equ     SQL_CHAR
SQL_C_LONG                                          equ     SQL_INTEGER
SQL_C_SHORT                                         equ     SQL_SMALLINT
SQL_C_FLOAT                                         equ     SQL_REAL
SQL_C_DOUBLE                                        equ     SQL_DOUBLE
SQL_C_NUMERIC                                       equ     SQL_NUMERIC
SQL_C_DEFAULT                                       equ     99

SQL_SIGNED_OFFSET                                   equ     (-20)
SQL_UNSIGNED_OFFSET                                 equ     (-22)

SQL_C_DATE                                          equ     SQL_DATE
SQL_C_TIME                                          equ     SQL_TIME
SQL_C_TIMESTAMP                                     equ     SQL_TIMESTAMP
SQL_C_TYPE_DATE                                     equ     SQL_TYPE_DATE
SQL_C_TYPE_TIME                                     equ     SQL_TYPE_TIME
SQL_C_TYPE_TIMESTAMP                                equ     SQL_TYPE_TIMESTAMP
SQL_C_INTERVAL_YEAR                                 equ     SQL_INTERVAL_YEAR
SQL_C_INTERVAL_MONTH                                equ     SQL_INTERVAL_MONTH
SQL_C_INTERVAL_DAY                                  equ     SQL_INTERVAL_DAY
SQL_C_INTERVAL_HOUR                                 equ     SQL_INTERVAL_HOUR
SQL_C_INTERVAL_MINUTE                               equ     SQL_INTERVAL_MINUTE
SQL_C_INTERVAL_SECOND                               equ     SQL_INTERVAL_SECOND
SQL_C_INTERVAL_YEAR_TO_MONTH                        equ     SQL_INTERVAL_YEAR_TO_MONTH
SQL_C_INTERVAL_DAY_TO_HOUR                          equ     SQL_INTERVAL_DAY_TO_HOUR
SQL_C_INTERVAL_DAY_TO_MINUTE                        equ     SQL_INTERVAL_DAY_TO_MINUTE
SQL_C_INTERVAL_DAY_TO_SECOND                        equ     SQL_INTERVAL_DAY_TO_SECOND
SQL_C_INTERVAL_HOUR_TO_MINUTE                       equ     SQL_INTERVAL_HOUR_TO_MINUTE
SQL_C_INTERVAL_HOUR_TO_SECOND                       equ     SQL_INTERVAL_HOUR_TO_SECOND
SQL_C_INTERVAL_MINUTE_TO_SECOND                     equ     SQL_INTERVAL_MINUTE_TO_SECOND
SQL_C_BINARY                                        equ     SQL_BINARY
SQL_C_BIT                                           equ     SQL_BIT
SQL_C_SBIGINT                                       equ     (SQL_BIGINT + SQL_SIGNED_OFFSET)
SQL_C_UBIGINT                                       equ     (SQL_BIGINT + SQL_UNSIGNED_OFFSET)
SQL_C_TINYINT                                       equ     SQL_TINYINT
SQL_C_SLONG                                         equ     (SQL_C_LONG + SQL_SIGNED_OFFSET)
SQL_C_SSHORT                                        equ     (SQL_C_SHORT + SQL_SIGNED_OFFSET)
SQL_C_STINYINT                                      equ     (SQL_TINYINT + SQL_SIGNED_OFFSET)
SQL_C_ULONG                                         equ     (SQL_C_LONG + SQL_UNSIGNED_OFFSET)
SQL_C_USHORT                                        equ     (SQL_C_SHORT + SQL_UNSIGNED_OFFSET)
SQL_C_UTINYINT                                      equ     (SQL_TINYINT + SQL_UNSIGNED_OFFSET)

if defined APP_WIN64
    SQL_C_BOOKMARK                                  equ     SQL_C_UBIGINT
else
    SQL_C_BOOKMARK                                  equ     SQL_C_ULONG
end if

SQL_C_GUID                                          equ     GUID

SQL_TYPE_NULL                                       equ     0
SQL_TYPE_MIN                                        equ     SQL_BIT
SQL_TYPE_MAX                                        equ     SQL_VARCHAR
SQL_C_VARBOOKMARK                                   equ     SQL_C_BINARY
SQL_NO_ROW_NUMBER                                   equ     (-1)
SQL_NO_COLUMN_NUMBER                                equ     (-1)
SQL_ROW_NUMBER_UNKNOWN                              equ     (-2)
SQL_COLUMN_NUMBER_UNKNOWN                           equ     (-2)

SQL_DEFAULT_PARAM                                   equ     (-5)
SQL_IGNORE                                          equ     (-6)
SQL_COLUMN_IGNORE                                   equ     SQL_IGNORE
SQL_LEN_DATA_AT_EXEC_OFFSET                         equ     (-100)
SQL_LEN_BINARY_ATTR_OFFSET                          equ     (-100)
SQL_PARAM_TYPE_DEFAULT                              equ     SQL_PARAM_INPUT_OUTPUT
SQL_SETPARAM_VALUE_MAX                              equ     (-1)

SQL_COLUMN_COUNT                                    equ     0
SQL_COLUMN_NAME                                     equ     1
SQL_COLUMN_TYPE                                     equ     2
SQL_COLUMN_LENGTH                                   equ     3
SQL_COLUMN_PRECISION                                equ     4
SQL_COLUMN_SCALE                                    equ     5
SQL_COLUMN_DISPLAY_SIZE                             equ     6
SQL_COLUMN_NULLABLE                                 equ     7
SQL_COLUMN_UNSIGNED                                 equ     8
SQL_COLUMN_MONEY                                    equ     9
SQL_COLUMN_UPDATABLE                                equ     10
SQL_COLUMN_AUTO_INCREMENT                           equ     11
SQL_COLUMN_CASE_SENSITIVE                           equ     12
SQL_COLUMN_SEARCHABLE                               equ     13
SQL_COLUMN_TYPE_NAME                                equ     14
SQL_COLUMN_TABLE_NAME                               equ     15
SQL_COLUMN_OWNER_NAME                               equ     16
SQL_COLUMN_QUALIFIER_NAME                           equ     17
SQL_COLUMN_LABEL                                    equ     18

SQL_COLATT_OPT_MAX                                  equ     SQL_COLUMN_LABEL
SQL_COLATT_OPT_MIN                                  equ     SQL_COLUMN_COUNT

SQL_ATTR_READONLY                                   equ     0
SQL_ATTR_WRITE                                      equ     1
SQL_ATTR_READWRITE_UNKNOWN                          equ     2

SQL_UNSEARCHABLE                                    equ     0
SQL_LIKE_ONLY                                       equ     1
SQL_ALL_EXCEPT_LIKE                                 equ     2
SQL_SEARCHABLE                                      equ     3
SQL_PRED_SEARCHABLE                                 equ     SQL_SEARCHABLE

SQL_NO_TOTAL                                        equ     (-4)

SQL_API_SQLALLOCHANDLESTD                           equ     73
SQL_API_SQLBULKOPERATIONS                           equ     24
SQL_API_SQLBINDPARAMETER                            equ     72
SQL_API_SQLBROWSECONNECT                            equ     55
SQL_API_SQLCOLATTRIBUTES                            equ     6
SQL_API_SQLCOLUMNPRIVILEGES                         equ     56
SQL_API_SQLDESCRIBEPARAM                            equ     58
SQL_API_SQLDRIVERCONNECT                            equ     41
SQL_API_SQLDRIVERS                                  equ     71
SQL_API_SQLEXTENDEDFETCH                            equ     59
SQL_API_SQLFOREIGNKEYS                              equ     60
SQL_API_SQLMORERESULTS                              equ     61
SQL_API_SQLNATIVESQL                                equ     62
SQL_API_SQLNUMPARAMS                                equ     63
SQL_API_SQLPARAMOPTIONS                             equ     64
SQL_API_SQLPRIMARYKEYS                              equ     65
SQL_API_SQLPROCEDURECOLUMNS                         equ     66
SQL_API_SQLPROCEDURES                               equ     67
SQL_API_SQLSETPOS                                   equ     68
SQL_API_SQLSETSCROLLOPTIONS                         equ     69
SQL_API_SQLTABLEPRIVILEGES                          equ     70
SQL_API_ALL_FUNCTIONS                               equ     0
SQL_API_LOADBYORDINAL                               equ     199

SQL_API_ODBC3_ALL_FUNCTIONS                         equ     999
SQL_API_ODBC3_ALL_FUNCTIONS_SIZE                    equ     250

SQL_INFO_FIRST                                      equ     0
SQL_ACTIVE_CONNECTIONS                              equ     0
SQL_ACTIVE_STATEMENTS                               equ     1
SQL_DRIVER_HDBC                                     equ     3
SQL_DRIVER_HENV                                     equ     4
SQL_DRIVER_HSTMT                                    equ     5
SQL_DRIVER_NAME                                     equ     6
SQL_DRIVER_VER                                      equ     7
SQL_ODBC_API_CONFORMANCE                            equ     9
SQL_ODBC_VER                                        equ     10
SQL_ROW_UPDATES                                     equ     11
SQL_ODBC_SAG_CLI_CONFORMANCE                        equ     12
SQL_ODBC_SQL_CONFORMANCE                            equ     15
SQL_PROCEDURES                                      equ     21
SQL_CONCAT_NULL_BEHAVIOR                            equ     22
SQL_CURSOR_ROLLBACK_BEHAVIOR                        equ     24
SQL_EXPRESSIONS_IN_ORDERBY                          equ     27
SQL_MAX_OWNER_NAME_LEN                              equ     32
SQL_MAX_PROCEDURE_NAME_LEN                          equ     33
SQL_MAX_QUALIFIER_NAME_LEN                          equ     34
SQL_MULT_RESULT_SETS                                equ     36
SQL_MULTIPLE_ACTIVE_TXN                             equ     37
SQL_OUTER_JOINS                                     equ     38
SQL_OWNER_TERM                                      equ     39
SQL_PROCEDURE_TERM                                  equ     40
SQL_QUALIFIER_NAME_SEPARATOR                        equ     41
SQL_QUALIFIER_TERM                                  equ     42
SQL_SCROLL_OPTIONS                                  equ     44
SQL_TABLE_TERM                                      equ     45
SQL_CONVERT_FUNCTIONS                               equ     48
SQL_NUMERIC_FUNCTIONS                               equ     49
SQL_STRING_FUNCTIONS                                equ     50
SQL_SYSTEM_FUNCTIONS                                equ     51
SQL_TIMEDATE_FUNCTIONS                              equ     52
SQL_CONVERT_BIGINT                                  equ     53
SQL_CONVERT_BINARY                                  equ     54
SQL_CONVERT_BIT                                     equ     55
SQL_CONVERT_CHAR                                    equ     56
SQL_CONVERT_DATE                                    equ     57
SQL_CONVERT_DECIMAL                                 equ     58
SQL_CONVERT_DOUBLE                                  equ     59
SQL_CONVERT_FLOAT                                   equ     60
SQL_CONVERT_INTEGER                                 equ     61
SQL_CONVERT_LONGVARCHAR                             equ     62
SQL_CONVERT_NUMERIC                                 equ     63
SQL_CONVERT_REAL                                    equ     64
SQL_CONVERT_SMALLINT                                equ     65
SQL_CONVERT_TIME                                    equ     66
SQL_CONVERT_TIMESTAMP                               equ     67
SQL_CONVERT_TINYINT                                 equ     68
SQL_CONVERT_VARBINARY                               equ     69
SQL_CONVERT_VARCHAR                                 equ     70
SQL_CONVERT_LONGVARBINARY                           equ     71
SQL_ODBC_SQL_OPT_IEF                                equ     73
SQL_CORRELATION_NAME                                equ     74
SQL_NON_NULLABLE_COLUMNS                            equ     75
SQL_DRIVER_HLIB                                     equ     76
SQL_DRIVER_ODBC_VER                                 equ     77
SQL_LOCK_TYPES                                      equ     78
SQL_POS_OPERATIONS                                  equ     79
SQL_POSITIONED_STATEMENTS                           equ     80
SQL_BOOKMARK_PERSISTENCE                            equ     82
SQL_STATIC_SENSITIVITY                              equ     83
SQL_FILE_USAGE                                      equ     84
SQL_COLUMN_ALIAS                                    equ     87
SQL_GROUP_BY                                        equ     88
SQL_KEYWORDS                                        equ     89
SQL_OWNER_USAGE                                     equ     91
SQL_QUALIFIER_USAGE                                 equ     92
SQL_QUOTED_IDENTIFIER_CASE                          equ     93
SQL_SUBQUERIES                                      equ     95
SQL_UNION                                           equ     96
SQL_MAX_ROW_SIZE_INCLUDES_LONG                      equ     103
SQL_MAX_CHAR_LITERAL_LEN                            equ     108
SQL_TIMEDATE_ADD_INTERVALS                          equ     109
SQL_TIMEDATE_DIFF_INTERVALS                         equ     110
SQL_NEED_LONG_DATA_LEN                              equ     111
SQL_MAX_BINARY_LITERAL_LEN                          equ     112
SQL_LIKE_ESCAPE_CLAUSE                              equ     113
SQL_QUALIFIER_LOCATION                              equ     114

SQL_ACTIVE_ENVIRONMENTS                             equ     116
SQL_ALTER_DOMAIN                                    equ     117

SQL_SQL_CONFORMANCE                                 equ     118
SQL_DATETIME_LITERALS                               equ     119

SQL_ASYNC_MODE                                      equ     10021
SQL_BATCH_ROW_COUNT                                 equ     120
SQL_BATCH_SUPPORT                                   equ     121
SQL_CATALOG_LOCATION                                equ     SQL_QUALIFIER_LOCATION
SQL_CATALOG_NAME_SEPARATOR                          equ     SQL_QUALIFIER_NAME_SEPARATOR
SQL_CATALOG_TERM                                    equ     SQL_QUALIFIER_TERM
SQL_CATALOG_USAGE                                   equ     SQL_QUALIFIER_USAGE
SQL_CONVERT_WCHAR                                   equ     122
SQL_CONVERT_INTERVAL_DAY_TIME                       equ     123
SQL_CONVERT_INTERVAL_YEAR_MONTH                     equ     124
SQL_CONVERT_WLONGVARCHAR                            equ     125
SQL_CONVERT_WVARCHAR                                equ     126
SQL_CREATE_ASSERTION                                equ     127
SQL_CREATE_CHARACTER_SET                            equ     128
SQL_CREATE_COLLATION                                equ     129
SQL_CREATE_DOMAIN                                   equ     130
SQL_CREATE_SCHEMA                                   equ     131
SQL_CREATE_TABLE                                    equ     132
SQL_CREATE_TRANSLATION                              equ     133
SQL_CREATE_VIEW                                     equ     134
SQL_DRIVER_HDESC                                    equ     135
SQL_DROP_ASSERTION                                  equ     136
SQL_DROP_CHARACTER_SET                              equ     137
SQL_DROP_COLLATION                                  equ     138
SQL_DROP_DOMAIN                                     equ     139
SQL_DROP_SCHEMA                                     equ     140
SQL_DROP_TABLE                                      equ     141
SQL_DROP_TRANSLATION                                equ     142
SQL_DROP_VIEW                                       equ     143
SQL_DYNAMIC_CURSOR_ATTRIBUTES1                      equ     144
SQL_DYNAMIC_CURSOR_ATTRIBUTES2                      equ     145
SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1                 equ     146
SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2                 equ     147
SQL_INDEX_KEYWORDS                                  equ     148
SQL_INFO_SCHEMA_VIEWS                               equ     149
SQL_KEYSET_CURSOR_ATTRIBUTES1                       equ     150
SQL_KEYSET_CURSOR_ATTRIBUTES2                       equ     151
SQL_MAX_ASYNC_CONCURRENT_STATEMENTS                 equ     10022
SQL_ODBC_INTERFACE_CONFORMANCE                      equ     152
SQL_PARAM_ARRAY_ROW_COUNTS                          equ     153
SQL_PARAM_ARRAY_SELECTS                             equ     154
SQL_SCHEMA_TERM                                     equ     SQL_OWNER_TERM
SQL_SCHEMA_USAGE                                    equ     SQL_OWNER_USAGE
SQL_SQL92_DATETIME_FUNCTIONS                        equ     155
SQL_SQL92_FOREIGN_KEY_DELETE_RULE                   equ     156
SQL_SQL92_FOREIGN_KEY_UPDATE_RULE                   equ     157
SQL_SQL92_GRANT                                     equ     158
SQL_SQL92_NUMERIC_VALUE_FUNCTIONS                   equ     159
SQL_SQL92_PREDICATES                                equ     160
SQL_SQL92_RELATIONAL_JOIN_OPERATORS                 equ     161
SQL_SQL92_REVOKE                                    equ     162
SQL_SQL92_ROW_VALUE_CONSTRUCTOR                     equ     163
SQL_SQL92_STRING_FUNCTIONS                          equ     164
SQL_SQL92_VALUE_EXPRESSIONS                         equ     165
SQL_STANDARD_CLI_CONFORMANCE                        equ     166
SQL_STATIC_CURSOR_ATTRIBUTES1                       equ     167
SQL_STATIC_CURSOR_ATTRIBUTES2                       equ     168

SQL_AGGREGATE_FUNCTIONS                             equ     169
SQL_DDL_INDEX                                       equ     170
SQL_DM_VER                                          equ     171
SQL_INSERT_STATEMENT                                equ     172
SQL_CONVERT_GUID                                    equ     173
SQL_UNION_STATEMENT                                 equ     SQL_UNION

SQL_DTC_TRANSITION_COST                             equ     1750

SQL_AT_ADD_COLUMN_SINGLE                            equ     00000020H
SQL_AT_ADD_COLUMN_DEFAULT                           equ     00000040H
SQL_AT_ADD_COLUMN_COLLATION                         equ     00000080H
SQL_AT_SET_COLUMN_DEFAULT                           equ     00000100H
SQL_AT_DROP_COLUMN_DEFAULT                          equ     00000200H
SQL_AT_DROP_COLUMN_CASCADE                          equ     00000400H
SQL_AT_DROP_COLUMN_RESTRICT                         equ     00000800H
SQL_AT_ADD_TABLE_CONSTRAINT                         equ     00001000H
SQL_AT_DROP_TABLE_CONSTRAINT_CASCADE                equ     00002000H
SQL_AT_DROP_TABLE_CONSTRAINT_RESTRICT               equ     00004000H
SQL_AT_CONSTRAINT_NAME_DEFINITION                   equ     00008000H
SQL_AT_CONSTRAINT_INITIALLY_DEFERRED                equ     00010000H
SQL_AT_CONSTRAINT_INITIALLY_IMMEDIATE               equ     00020000H
SQL_AT_CONSTRAINT_DEFERRABLE                        equ     00040000H
SQL_AT_CONSTRAINT_NON_DEFERRABLE                    equ     00080000H

SQL_CVT_CHAR                                        equ     00000001H
SQL_CVT_NUMERIC                                     equ     00000002H
SQL_CVT_DECIMAL                                     equ     00000004H
SQL_CVT_INTEGER                                     equ     00000008H
SQL_CVT_SMALLINT                                    equ     00000010H
SQL_CVT_FLOAT                                       equ     00000020H
SQL_CVT_REAL                                        equ     00000040H
SQL_CVT_DOUBLE                                      equ     00000080H
SQL_CVT_VARCHAR                                     equ     00000100H
SQL_CVT_LONGVARCHAR                                 equ     00000200H
SQL_CVT_BINARY                                      equ     00000400H
SQL_CVT_VARBINARY                                   equ     00000800H
SQL_CVT_BIT                                         equ     00001000H
SQL_CVT_TINYINT                                     equ     00002000H
SQL_CVT_BIGINT                                      equ     00004000H
SQL_CVT_DATE                                        equ     00008000H
SQL_CVT_TIME                                        equ     00010000H
SQL_CVT_TIMESTAMP                                   equ     00020000H
SQL_CVT_LONGVARBINARY                               equ     00040000H
SQL_CVT_INTERVAL_YEAR_MONTH                         equ     00080000H
SQL_CVT_INTERVAL_DAY_TIME                           equ     00100000H
SQL_CVT_WCHAR                                       equ     00200000H
SQL_CVT_WLONGVARCHAR                                equ     00400000H
SQL_CVT_WVARCHAR                                    equ     00800000H
SQL_CVT_GUID                                        equ     01000000H

SQL_FN_CVT_CONVERT                                  equ     00000001H
SQL_FN_CVT_CAST                                     equ     00000002H

SQL_FN_STR_CONCAT                                   equ     00000001H
SQL_FN_STR_INSERT                                   equ     00000002H
SQL_FN_STR_LEFT                                     equ     00000004H
SQL_FN_STR_LTRIM                                    equ     00000008H
SQL_FN_STR_LENGTH                                   equ     00000010H
SQL_FN_STR_LOCATE                                   equ     00000020H
SQL_FN_STR_LCASE                                    equ     00000040H
SQL_FN_STR_REPEAT                                   equ     00000080H
SQL_FN_STR_REPLACE                                  equ     00000100H
SQL_FN_STR_RIGHT                                    equ     00000200H
SQL_FN_STR_RTRIM                                    equ     00000400H
SQL_FN_STR_SUBSTRING                                equ     00000800H
SQL_FN_STR_UCASE                                    equ     00001000H
SQL_FN_STR_ASCII                                    equ     00002000H
SQL_FN_STR_CHAR                                     equ     00004000H
SQL_FN_STR_DIFFERENCE                               equ     00008000H
SQL_FN_STR_LOCATE_2                                 equ     00010000H
SQL_FN_STR_SOUNDEX                                  equ     00020000H
SQL_FN_STR_SPACE                                    equ     00040000H
SQL_FN_STR_BIT_LENGTH                               equ     00080000H
SQL_FN_STR_CHAR_LENGTH                              equ     00100000H
SQL_FN_STR_CHARACTER_LENGTH                         equ     00200000H
SQL_FN_STR_OCTET_LENGTH                             equ     00400000H
SQL_FN_STR_POSITION                                 equ     00800000H

SQL_SSF_CONVERT                                     equ     00000001H
SQL_SSF_LOWER                                       equ     00000002H
SQL_SSF_UPPER                                       equ     00000004H
SQL_SSF_SUBSTRING                                   equ     00000008H
SQL_SSF_TRANSLATE                                   equ     00000010H
SQL_SSF_TRIM_BOTH                                   equ     00000020H
SQL_SSF_TRIM_LEADING                                equ     00000040H
SQL_SSF_TRIM_TRAILING                               equ     00000080H

SQL_FN_NUM_ABS                                      equ     00000001H
SQL_FN_NUM_ACOS                                     equ     00000002H
SQL_FN_NUM_ASIN                                     equ     00000004H
SQL_FN_NUM_ATAN                                     equ     00000008H
SQL_FN_NUM_ATAN2                                    equ     00000010H
SQL_FN_NUM_CEILING                                  equ     00000020H
SQL_FN_NUM_COS                                      equ     00000040H
SQL_FN_NUM_COT                                      equ     00000080H
SQL_FN_NUM_EXP                                      equ     00000100H
SQL_FN_NUM_FLOOR                                    equ     00000200H
SQL_FN_NUM_LOG                                      equ     00000400H
SQL_FN_NUM_MOD                                      equ     00000800H
SQL_FN_NUM_SIGN                                     equ     00001000H
SQL_FN_NUM_SIN                                      equ     00002000H
SQL_FN_NUM_SQRT                                     equ     00004000H
SQL_FN_NUM_TAN                                      equ     00008000H
SQL_FN_NUM_PI                                       equ     00010000H
SQL_FN_NUM_RAND                                     equ     00020000H
SQL_FN_NUM_DEGREES                                  equ     00040000H
SQL_FN_NUM_LOG10                                    equ     00080000H
SQL_FN_NUM_POWER                                    equ     00100000H
SQL_FN_NUM_RADIANS                                  equ     00200000H
SQL_FN_NUM_ROUND                                    equ     00400000H
SQL_FN_NUM_TRUNCATE                                 equ     00800000H

SQL_SNVF_BIT_LENGTH                                 equ     00000001H
SQL_SNVF_CHAR_LENGTH                                equ     00000002H
SQL_SNVF_CHARACTER_LENGTH                           equ     00000004H
SQL_SNVF_EXTRACT                                    equ     00000008H
SQL_SNVF_OCTET_LENGTH                               equ     00000010H
SQL_SNVF_POSITION                                   equ     00000020H

SQL_FN_TD_NOW                                       equ     00000001H
SQL_FN_TD_CURDATE                                   equ     00000002H
SQL_FN_TD_DAYOFMONTH                                equ     00000004H
SQL_FN_TD_DAYOFWEEK                                 equ     00000008H
SQL_FN_TD_DAYOFYEAR                                 equ     00000010H
SQL_FN_TD_MONTH                                     equ     00000020H
SQL_FN_TD_QUARTER                                   equ     00000040H
SQL_FN_TD_WEEK                                      equ     00000080H
SQL_FN_TD_YEAR                                      equ     00000100H
SQL_FN_TD_CURTIME                                   equ     00000200H
SQL_FN_TD_HOUR                                      equ     00000400H
SQL_FN_TD_MINUTE                                    equ     00000800H
SQL_FN_TD_SECOND                                    equ     00001000H
SQL_FN_TD_TIMESTAMPADD                              equ     00002000H
SQL_FN_TD_TIMESTAMPDIFF                             equ     00004000H
SQL_FN_TD_DAYNAME                                   equ     00008000H
SQL_FN_TD_MONTHNAME                                 equ     00010000H
SQL_FN_TD_CURRENT_DATE                              equ     00020000H
SQL_FN_TD_CURRENT_TIME                              equ     00040000H
SQL_FN_TD_CURRENT_TIMESTAMP                         equ     00080000H
SQL_FN_TD_EXTRACT                                   equ     00100000H

SQL_SDF_CURRENT_DATE                                equ     00000001H
SQL_SDF_CURRENT_TIME                                equ     00000002H
SQL_SDF_CURRENT_TIMESTAMP                           equ     00000004H

SQL_FN_SYS_USERNAME                                 equ     00000001H
SQL_FN_SYS_DBNAME                                   equ     00000002H
SQL_FN_SYS_IFNULL                                   equ     00000004H

SQL_FN_TSI_FRAC_SECOND                              equ     00000001H
SQL_FN_TSI_SECOND                                   equ     00000002H
SQL_FN_TSI_MINUTE                                   equ     00000004H
SQL_FN_TSI_HOUR                                     equ     00000008H
SQL_FN_TSI_DAY                                      equ     00000010H
SQL_FN_TSI_WEEK                                     equ     00000020H
SQL_FN_TSI_MONTH                                    equ     00000040H
SQL_FN_TSI_QUARTER                                  equ     00000080H
SQL_FN_TSI_YEAR                                     equ     00000100H

SQL_CA1_NEXT                                        equ     00000001H
SQL_CA1_ABSOLUTE                                    equ     00000002H
SQL_CA1_RELATIVE                                    equ     00000004H
SQL_CA1_BOOKMARK                                    equ     00000008H
SQL_CA1_LOCK_NO_CHANGE                              equ     00000040H
SQL_CA1_LOCK_EXCLUSIVE                              equ     00000080H
SQL_CA1_LOCK_UNLOCK                                 equ     00000100H
SQL_CA1_POS_POSITION                                equ     00000200H
SQL_CA1_POS_UPDATE                                  equ     00000400H
SQL_CA1_POS_DELETE                                  equ     00000800H
SQL_CA1_POS_REFRESH                                 equ     00001000H
SQL_CA1_POSITIONED_UPDATE                           equ     00002000H
SQL_CA1_POSITIONED_DELETE                           equ     00004000H
SQL_CA1_SELECT_FOR_UPDATE                           equ     00008000H
SQL_CA1_BULK_ADD                                    equ     00010000H
SQL_CA1_BULK_UPDATE_BY_BOOKMARK                     equ     00020000H
SQL_CA1_BULK_DELETE_BY_BOOKMARK                     equ     00040000H
SQL_CA1_BULK_FETCH_BY_BOOKMARK                      equ     00080000H

SQL_CA2_READ_ONLY_CONCURRENCY                       equ     00000001H
SQL_CA2_LOCK_CONCURRENCY                            equ     00000002H
SQL_CA2_OPT_ROWVER_CONCURRENCY                      equ     00000004H
SQL_CA2_OPT_VALUES_CONCURRENCY                      equ     00000008H
SQL_CA2_SENSITIVITY_ADDITIONS                       equ     00000010H
SQL_CA2_SENSITIVITY_DELETIONS                       equ     00000020H
SQL_CA2_SENSITIVITY_UPDATES                         equ     00000040H
SQL_CA2_MAX_ROWS_SELECT                             equ     00000080H
SQL_CA2_MAX_ROWS_INSERT                             equ     00000100H
SQL_CA2_MAX_ROWS_DELETE                             equ     00000200H
SQL_CA2_MAX_ROWS_UPDATE                             equ     00000400H
SQL_CA2_MAX_ROWS_CATALOG                            equ     00000800H
SQL_CA2_MAX_ROWS_AFFECTS_ALL                        equ     (SQL_CA2_MAX_ROWS_SELECT or SQL_CA2_MAX_ROWS_INSERT or SQL_CA2_MAX_ROWS_DELETE or SQL_CA2_MAX_ROWS_UPDATE or SQL_CA2_MAX_ROWS_CATALOG)
SQL_CA2_CRC_EXACT                                   equ     00001000H
SQL_CA2_CRC_APPROXIMATE                             equ     00002000H
SQL_CA2_SIMULATE_NON_UNIQUE                         equ     00004000H
SQL_CA2_SIMULATE_TRY_UNIQUE                         equ     00008000H
SQL_CA2_SIMULATE_UNIQUE                             equ     00010000H

SQL_OAC_NONE                                        equ     0000H
SQL_OAC_LEVEL1                                      equ     0001H
SQL_OAC_LEVEL2                                      equ     0002H

SQL_OSCC_NOT_COMPLIANT                              equ     0000H
SQL_OSCC_COMPLIANT                                  equ     0001H

SQL_OSC_MINIMUM                                     equ     0000H
SQL_OSC_CORE                                        equ     0001H
SQL_OSC_EXTENDED                                    equ     0002H

SQL_CB_NULL                                         equ     0000H
SQL_CB_NON_NULL                                     equ     0001H

SQL_SO_FORWARD_ONLY                                 equ     00000001H
SQL_SO_KEYSET_DRIVEN                                equ     00000002H
SQL_SO_DYNAMIC                                      equ     00000004H
SQL_SO_MIXED                                        equ     00000008H
SQL_SO_STATIC                                       equ     00000010H

SQL_FD_FETCH_BOOKMARK                               equ     00000080H

SQL_CN_NONE                                         equ     0000H
SQL_CN_DIFFERENT                                    equ     0001H
SQL_CN_ANY                                          equ     0002H

SQL_NNC_NULL                                        equ     0000H
SQL_NNC_NON_NULL                                    equ     0001H

SQL_NC_START                                        equ     0002H
SQL_NC_END                                          equ     0004H

SQL_FILE_NOT_SUPPORTED                              equ     0000H
SQL_FILE_TABLE                                      equ     0001H
SQL_FILE_QUALIFIER                                  equ     0002H
SQL_FILE_CATALOG                                    equ     SQL_FILE_QUALIFIER

SQL_GD_BLOCK                                        equ     00000004H
SQL_GD_BOUND                                        equ     00000008H

SQL_PS_POSITIONED_DELETE                            equ     00000001H
SQL_PS_POSITIONED_UPDATE                            equ     00000002H
SQL_PS_SELECT_FOR_UPDATE                            equ     00000004H

SQL_GB_NOT_SUPPORTED                                equ     0000H
SQL_GB_GROUP_BY_EQUALS_SELECT                       equ     0001H
SQL_GB_GROUP_BY_CONTAINS_SELECT                     equ     0002H
SQL_GB_NO_RELATION                                  equ     0003H
SQL_GB_COLLATE                                      equ     0004H

SQL_OU_DML_STATEMENTS                               equ     00000001H
SQL_OU_PROCEDURE_INVOCATION                         equ     00000002H
SQL_OU_TABLE_DEFINITION                             equ     00000004H
SQL_OU_INDEX_DEFINITION                             equ     00000008H
SQL_OU_PRIVILEGE_DEFINITION                         equ     00000010H

SQL_SU_DML_STATEMENTS                               equ     SQL_OU_DML_STATEMENTS
SQL_SU_PROCEDURE_INVOCATION                         equ     SQL_OU_PROCEDURE_INVOCATION
SQL_SU_TABLE_DEFINITION                             equ     SQL_OU_TABLE_DEFINITION
SQL_SU_INDEX_DEFINITION                             equ     SQL_OU_INDEX_DEFINITION
SQL_SU_PRIVILEGE_DEFINITION                         equ     SQL_OU_PRIVILEGE_DEFINITION

SQL_QU_DML_STATEMENTS                               equ     00000001H
SQL_QU_PROCEDURE_INVOCATION                         equ     00000002H
SQL_QU_TABLE_DEFINITION                             equ     00000004H
SQL_QU_INDEX_DEFINITION                             equ     00000008H
SQL_QU_PRIVILEGE_DEFINITION                         equ     00000010H

SQL_CU_DML_STATEMENTS                               equ     SQL_QU_DML_STATEMENTS
SQL_CU_PROCEDURE_INVOCATION                         equ     SQL_QU_PROCEDURE_INVOCATION
SQL_CU_TABLE_DEFINITION                             equ     SQL_QU_TABLE_DEFINITION
SQL_CU_INDEX_DEFINITION                             equ     SQL_QU_INDEX_DEFINITION
SQL_CU_PRIVILEGE_DEFINITION                         equ     SQL_QU_PRIVILEGE_DEFINITION

SQL_SQ_COMPARISON                                   equ     00000001H
SQL_SQ_EXISTS                                       equ     00000002H
SQL_SQ_IN                                           equ     00000004H
SQL_SQ_QUANTIFIED                                   equ     00000008H
SQL_SQ_CORRELATED_SUBQUERIES                        equ     00000010H

SQL_U_UNION                                         equ     00000001H
SQL_U_UNION_ALL                                     equ     00000002H

SQL_BP_CLOSE                                        equ     00000001H
SQL_BP_DELETE                                       equ     00000002H
SQL_BP_DROP                                         equ     00000004H
SQL_BP_TRANSACTION                                  equ     00000008H
SQL_BP_UPDATE                                       equ     00000010H
SQL_BP_OTHER_HSTMT                                  equ     00000020H
SQL_BP_SCROLL                                       equ     00000040H

SQL_SS_ADDITIONS                                    equ     00000001H
SQL_SS_DELETIONS                                    equ     00000002H
SQL_SS_UPDATES                                      equ     00000004H

SQL_CV_CREATE_VIEW                                  equ     00000001H
SQL_CV_CHECK_OPTION                                 equ     00000002H
SQL_CV_CASCADED                                     equ     00000004H
SQL_CV_LOCAL                                        equ     00000008H

SQL_LCK_NO_CHANGE                                   equ     00000001H
SQL_LCK_EXCLUSIVE                                   equ     00000002H
SQL_LCK_UNLOCK                                      equ     00000004H

SQL_POS_POSITION                                    equ     00000001H
SQL_POS_REFRESH                                     equ     00000002H
SQL_POS_UPDATE                                      equ     00000004H
SQL_POS_DELETE                                      equ     00000008H
SQL_POS_ADD                                         equ     00000010LH

SQL_QL_START                                        equ     0001H
SQL_QL_END                                          equ     0002H

SQL_AF_AVG                                          equ     00000001H
SQL_AF_COUNT                                        equ     00000002H
SQL_AF_MAX                                          equ     00000004H
SQL_AF_MIN                                          equ     00000008H
SQL_AF_SUM                                          equ     00000010H
SQL_AF_DISTINCT                                     equ     00000020H
SQL_AF_ALL                                          equ     00000040H

SQL_SC_SQL92_ENTRY                                  equ     00000001H
SQL_SC_FIPS127_2_TRANSITIONAL                       equ     00000002H
SQL_SC_SQL92_INTERMEDIATE                           equ     00000004H
SQL_SC_SQL92_FULL                                   equ     00000008H

SQL_DL_SQL92_DATE                                   equ     00000001H
SQL_DL_SQL92_TIME                                   equ     00000002H
SQL_DL_SQL92_TIMESTAMP                              equ     00000004H
SQL_DL_SQL92_INTERVAL_YEAR                          equ     00000008H
SQL_DL_SQL92_INTERVAL_MONTH                         equ     00000010H
SQL_DL_SQL92_INTERVAL_DAY                           equ     00000020H
SQL_DL_SQL92_INTERVAL_HOUR                          equ     00000040H
SQL_DL_SQL92_INTERVAL_MINUTE                        equ     00000080H
SQL_DL_SQL92_INTERVAL_SECOND                        equ     00000100H
SQL_DL_SQL92_INTERVAL_YEAR_TO_MONTH                 equ     00000200H
SQL_DL_SQL92_INTERVAL_DAY_TO_HOUR                   equ     00000400H
SQL_DL_SQL92_INTERVAL_DAY_TO_MINUTE                 equ     00000800H
SQL_DL_SQL92_INTERVAL_DAY_TO_SECOND                 equ     00001000H
SQL_DL_SQL92_INTERVAL_HOUR_TO_MINUTE                equ     00002000H
SQL_DL_SQL92_INTERVAL_HOUR_TO_SECOND                equ     00004000H
SQL_DL_SQL92_INTERVAL_MINUTE_TO_SECOND              equ     00008000H

SQL_CL_START                                        equ     SQL_QL_START
SQL_CL_END                                          equ     SQL_QL_END

SQL_BRC_PROCEDURES                                  equ     0000001H
SQL_BRC_EXPLICIT                                    equ     0000002H
SQL_BRC_ROLLED_UP                                   equ     0000004H

SQL_BS_SELECT_EXPLICIT                              equ     00000001H
SQL_BS_ROW_COUNT_EXPLICIT                           equ     00000002H
SQL_BS_SELECT_PROC                                  equ     00000004H
SQL_BS_ROW_COUNT_PROC                               equ     00000008H

SQL_PARC_BATCH                                      equ     1
SQL_PARC_NO_BATCH                                   equ     2

SQL_PAS_BATCH                                       equ     1
SQL_PAS_NO_BATCH                                    equ     2
SQL_PAS_NO_SELECT                                   equ     3

SQL_IK_NONE                                         equ     00000000H
SQL_IK_ASC                                          equ     00000001H
SQL_IK_DESC                                         equ     00000002H
SQL_IK_ALL                                          equ     (SQL_IK_ASC or SQL_IK_DESC)

SQL_ISV_ASSERTIONS                                  equ     00000001H
SQL_ISV_CHARACTER_SETS                              equ     00000002H
SQL_ISV_CHECK_CONSTRAINTS                           equ     00000004H
SQL_ISV_COLLATIONS                                  equ     00000008H
SQL_ISV_COLUMN_DOMAIN_USAGE                         equ     00000010H
SQL_ISV_COLUMN_PRIVILEGES                           equ     00000020H
SQL_ISV_COLUMNS                                     equ     00000040H
SQL_ISV_CONSTRAINT_COLUMN_USAGE                     equ     00000080H
SQL_ISV_CONSTRAINT_TABLE_USAGE                      equ     00000100H
SQL_ISV_DOMAIN_CONSTRAINTS                          equ     00000200H
SQL_ISV_DOMAINS                                     equ     00000400H
SQL_ISV_KEY_COLUMN_USAGE                            equ     00000800H
SQL_ISV_REFERENTIAL_CONSTRAINTS                     equ     00001000H
SQL_ISV_SCHEMATA                                    equ     00002000H
SQL_ISV_SQL_LANGUAGES                               equ     00004000H
SQL_ISV_TABLE_CONSTRAINTS                           equ     00008000H
SQL_ISV_TABLE_PRIVILEGES                            equ     00010000H
SQL_ISV_TABLES                                      equ     00020000H
SQL_ISV_TRANSLATIONS                                equ     00040000H
SQL_ISV_USAGE_PRIVILEGES                            equ     00080000H
SQL_ISV_VIEW_COLUMN_USAGE                           equ     00100000H
SQL_ISV_VIEW_TABLE_USAGE                            equ     00200000H
SQL_ISV_VIEWS                                       equ     00400000H

SQL_AD_CONSTRAINT_NAME_DEFINITION                   equ     00000001H
SQL_AD_ADD_DOMAIN_CONSTRAINT                        equ     00000002H
SQL_AD_DROP_DOMAIN_CONSTRAINT                       equ     00000004H
SQL_AD_ADD_DOMAIN_DEFAULT                           equ     00000008H
SQL_AD_DROP_DOMAIN_DEFAULT                          equ     00000010H
SQL_AD_ADD_CONSTRAINT_INITIALLY_DEFERRED            equ     00000020H
SQL_AD_ADD_CONSTRAINT_INITIALLY_IMMEDIATE           equ     00000040H
SQL_AD_ADD_CONSTRAINT_DEFERRABLE                    equ     00000080H
SQL_AD_ADD_CONSTRAINT_NON_DEFERRABLE                equ     00000100H

SQL_CS_CREATE_SCHEMA                                equ     00000001H
SQL_CS_AUTHORIZATION                                equ     00000002H
SQL_CS_DEFAULT_CHARACTER_SET                        equ     00000004H

SQL_CTR_CREATE_TRANSLATION                          equ     00000001H

SQL_CA_CREATE_ASSERTION                             equ     00000001H
SQL_CA_CONSTRAINT_INITIALLY_DEFERRED                equ     00000010H
SQL_CA_CONSTRAINT_INITIALLY_IMMEDIATE               equ     00000020H
SQL_CA_CONSTRAINT_DEFERRABLE                        equ     00000040H
SQL_CA_CONSTRAINT_NON_DEFERRABLE                    equ     00000080H

SQL_CCS_CREATE_CHARACTER_SET                        equ     00000001H
SQL_CCS_COLLATE_CLAUSE                              equ     00000002H
SQL_CCS_LIMITED_COLLATION                           equ     00000004H

SQL_CCOL_CREATE_COLLATION                           equ     00000001H

SQL_CDO_CREATE_DOMAIN                               equ     00000001H
SQL_CDO_DEFAULT                                     equ     00000002H
SQL_CDO_CONSTRAINT                                  equ     00000004H
SQL_CDO_COLLATION                                   equ     00000008H
SQL_CDO_CONSTRAINT_NAME_DEFINITION                  equ     00000010H
SQL_CDO_CONSTRAINT_INITIALLY_DEFERRED               equ     00000020H
SQL_CDO_CONSTRAINT_INITIALLY_IMMEDIATE              equ     00000040H
SQL_CDO_CONSTRAINT_DEFERRABLE                       equ     00000080H
SQL_CDO_CONSTRAINT_NON_DEFERRABLE                   equ     00000100H

SQL_CT_CREATE_TABLE                                 equ     00000001H
SQL_CT_COMMIT_PRESERVE                              equ     00000002H
SQL_CT_COMMIT_DELETE                                equ     00000004H
SQL_CT_GLOBAL_TEMPORARY                             equ     00000008H
SQL_CT_LOCAL_TEMPORARY                              equ     00000010H
SQL_CT_CONSTRAINT_INITIALLY_DEFERRED                equ     00000020H
SQL_CT_CONSTRAINT_INITIALLY_IMMEDIATE               equ     00000040H
SQL_CT_CONSTRAINT_DEFERRABLE                        equ     00000080H
SQL_CT_CONSTRAINT_NON_DEFERRABLE                    equ     00000100H
SQL_CT_COLUMN_CONSTRAINT                            equ     00000200H
SQL_CT_COLUMN_DEFAULT                               equ     00000400H
SQL_CT_COLUMN_COLLATION                             equ     00000800H
SQL_CT_TABLE_CONSTRAINT                             equ     00001000H
SQL_CT_CONSTRAINT_NAME_DEFINITION                   equ     00002000H

SQL_DI_CREATE_INDEX                                 equ     00000001H
SQL_DI_DROP_INDEX                                   equ     00000002H

SQL_DC_DROP_COLLATION                               equ     00000001H

SQL_DD_DROP_DOMAIN                                  equ     00000001H
SQL_DD_RESTRICT                                     equ     00000002H
SQL_DD_CASCADE                                      equ     00000004H

SQL_DS_DROP_SCHEMA                                  equ     00000001H
SQL_DS_RESTRICT                                     equ     00000002H
SQL_DS_CASCADE                                      equ     00000004H

SQL_DCS_DROP_CHARACTER_SET                          equ     00000001H

SQL_DA_DROP_ASSERTION                               equ     00000001H

SQL_DT_DROP_TABLE                                   equ     00000001H
SQL_DT_RESTRICT                                     equ     00000002H
SQL_DT_CASCADE                                      equ     00000004H

SQL_DTR_DROP_TRANSLATION                            equ     00000001H

SQL_DV_DROP_VIEW                                    equ     00000001H
SQL_DV_RESTRICT                                     equ     00000002H
SQL_DV_CASCADE                                      equ     00000004H

SQL_IS_INSERT_LITERALS                              equ     00000001H
SQL_IS_INSERT_SEARCHED                              equ     00000002H
SQL_IS_SELECT_INTO                                  equ     00000004H

SQL_OIC_CORE                                        equ     1
SQL_OIC_LEVEL1                                      equ     2
SQL_OIC_LEVEL2                                      equ     3

SQL_SFKD_CASCADE                                    equ     00000001H
SQL_SFKD_NO_ACTION                                  equ     00000002H
SQL_SFKD_SET_DEFAULT                                equ     00000004H
SQL_SFKD_SET_NULL                                   equ     00000008H

SQL_SFKU_CASCADE                                    equ     00000001H
SQL_SFKU_NO_ACTION                                  equ     00000002H
SQL_SFKU_SET_DEFAULT                                equ     00000004H
SQL_SFKU_SET_NULL                                   equ     00000008H

SQL_SG_USAGE_ON_DOMAIN                              equ     00000001H
SQL_SG_USAGE_ON_CHARACTER_SET                       equ     00000002H
SQL_SG_USAGE_ON_COLLATION                           equ     00000004H
SQL_SG_USAGE_ON_TRANSLATION                         equ     00000008H
SQL_SG_WITH_GRANT_OPTION                            equ     00000010H
SQL_SG_DELETE_TABLE                                 equ     00000020H
SQL_SG_INSERT_TABLE                                 equ     00000040H
SQL_SG_INSERT_COLUMN                                equ     00000080H
SQL_SG_REFERENCES_TABLE                             equ     00000100H
SQL_SG_REFERENCES_COLUMN                            equ     00000200H
SQL_SG_SELECT_TABLE                                 equ     00000400H
SQL_SG_UPDATE_TABLE                                 equ     00000800H
SQL_SG_UPDATE_COLUMN                                equ     00001000H

SQL_SP_EXISTS                                       equ     00000001H
SQL_SP_ISNOTNULL                                    equ     00000002H
SQL_SP_ISNULL                                       equ     00000004H
SQL_SP_MATCH_FULL                                   equ     00000008H
SQL_SP_MATCH_PARTIAL                                equ     00000010H
SQL_SP_MATCH_UNIQUE_FULL                            equ     00000020H
SQL_SP_MATCH_UNIQUE_PARTIAL                         equ     00000040H
SQL_SP_OVERLAPS                                     equ     00000080H
SQL_SP_UNIQUE                                       equ     00000100H
SQL_SP_LIKE                                         equ     00000200H
SQL_SP_IN                                           equ     00000400H
SQL_SP_BETWEEN                                      equ     00000800H
SQL_SP_COMPARISON                                   equ     00001000H
SQL_SP_QUANTIFIED_COMPARISON                        equ     00002000H

SQL_SRJO_CORRESPONDING_CLAUSE                       equ     00000001H
SQL_SRJO_CROSS_JOIN                                 equ     00000002H
SQL_SRJO_EXCEPT_JOIN                                equ     00000004H
SQL_SRJO_FULL_OUTER_JOIN                            equ     00000008H
SQL_SRJO_INNER_JOIN                                 equ     00000010H
SQL_SRJO_INTERSECT_JOIN                             equ     00000020H
SQL_SRJO_LEFT_OUTER_JOIN                            equ     00000040H
SQL_SRJO_NATURAL_JOIN                               equ     00000080H
SQL_SRJO_RIGHT_OUTER_JOIN                           equ     00000100H
SQL_SRJO_UNION_JOIN                                 equ     00000200H

SQL_SR_USAGE_ON_DOMAIN                              equ     00000001H
SQL_SR_USAGE_ON_CHARACTER_SET                       equ     00000002H
SQL_SR_USAGE_ON_COLLATION                           equ     00000004H
SQL_SR_USAGE_ON_TRANSLATION                         equ     00000008H
SQL_SR_GRANT_OPTION_FOR                             equ     00000010H
SQL_SR_CASCADE                                      equ     00000020H
SQL_SR_RESTRICT                                     equ     00000040H
SQL_SR_DELETE_TABLE                                 equ     00000080H
SQL_SR_INSERT_TABLE                                 equ     00000100H
SQL_SR_INSERT_COLUMN                                equ     00000200H
SQL_SR_REFERENCES_TABLE                             equ     00000400H
SQL_SR_REFERENCES_COLUMN                            equ     00000800H
SQL_SR_SELECT_TABLE                                 equ     00001000H
SQL_SR_UPDATE_TABLE                                 equ     00002000H
SQL_SR_UPDATE_COLUMN                                equ     00004000H

SQL_SRVC_VALUE_EXPRESSION                           equ     00000001H
SQL_SRVC_NULL                                       equ     00000002H
SQL_SRVC_DEFAULT                                    equ     00000004H
SQL_SRVC_ROW_SUBQUERY                               equ     00000008H

SQL_SVE_CASE                                        equ     00000001H
SQL_SVE_CAST                                        equ     00000002H
SQL_SVE_COALESCE                                    equ     00000004H
SQL_SVE_NULLIF                                      equ     00000008H

SQL_SCC_XOPEN_CLI_VERSION1                          equ     00000001H
SQL_SCC_ISO92_CLI                                   equ     00000002H

SQL_US_UNION                                        equ     SQL_U_UNION
SQL_US_UNION_ALL                                    equ     SQL_U_UNION_ALL

SQL_DTC_ENLIST_EXPENSIVE                            equ     00000001H
SQL_DTC_UNENLIST_EXPENSIVE                          equ     00000002H

SQL_FETCH_FIRST_USER                                equ     31
SQL_FETCH_FIRST_SYSTEM                              equ     32

SQL_ENTIRE_ROWSET                                   equ     0

SQL_POSITION                                        equ     0
SQL_REFRESH                                         equ     1
SQL_UPDATE                                          equ     2
SQL_DELETE                                          equ     3

SQL_ADD                                             equ     4
SQL_SETPOS_MAX_OPTION_VALUE                         equ     SQL_ADD
SQL_UPDATE_BY_BOOKMARK                              equ     5
SQL_DELETE_BY_BOOKMARK                              equ     6
SQL_FETCH_BY_BOOKMARK                               equ     7

SQL_LOCK_NO_CHANGE                                  equ     0
SQL_LOCK_EXCLUSIVE                                  equ     1
SQL_LOCK_UNLOCK                                     equ     2

SQL_SETPOS_MAX_LOCK_VALUE                           equ     SQL_LOCK_UNLOCK

SQL_BEST_ROWID                                      equ     1
SQL_ROWVER                                          equ     2

SQL_PC_NOT_PSEUDO                                   equ     1

SQL_QUICK                                           equ     0
SQL_ENSURE                                          equ     1

SQL_TABLE_STAT                                      equ     0

SQL_ALL_CATALOGS                                    equ     A("%")
SQL_ALL_SCHEMAS                                     equ     A("%")
SQL_ALL_TABLE_TYPES                                 equ     A("%")

SQL_DRIVER_NOPROMPT                                 equ     0
SQL_DRIVER_COMPLETE                                 equ     1
SQL_DRIVER_PROMPT                                   equ     2
SQL_DRIVER_COMPLETE_REQUIRED                        equ     3

SQL_FETCH_BOOKMARK                                  equ     8

SQL_ROW_SUCCESS                                     equ     0
SQL_ROW_DELETED                                     equ     1
SQL_ROW_UPDATED                                     equ     2
SQL_ROW_NOROW                                       equ     3
SQL_ROW_ADDED                                       equ     4
SQL_ROW_ERROR                                       equ     5
SQL_ROW_SUCCESS_WITH_INFO                           equ     6
SQL_ROW_PROCEED                                     equ     0
SQL_ROW_IGNORE                                      equ     1

SQL_PARAM_SUCCESS                                   equ     0
SQL_PARAM_SUCCESS_WITH_INFO                         equ     6
SQL_PARAM_ERROR                                     equ     5
SQL_PARAM_UNUSED                                    equ     7
SQL_PARAM_DIAG_UNAVAILABLE                          equ     1

SQL_PARAM_PROCEED                                   equ     0
SQL_PARAM_IGNORE                                    equ     1

SQL_CASCADE                                         equ     0
SQL_RESTRICT                                        equ     1
SQL_SET_NULL                                        equ     2
SQL_NO_ACTION                                       equ     3
SQL_SET_DEFAULT                                     equ     4

SQL_INITIALLY_DEFERRED                              equ     5
SQL_INITIALLY_IMMEDIATE                             equ     6
SQL_NOT_DEFERRABLE                                  equ     7


SQL_PARAM_TYPE_UNKNOWN                              equ     0
SQL_PARAM_INPUT                                     equ     1
SQL_PARAM_INPUT_OUTPUT                              equ     2
SQL_RESULT_COL                                      equ     3
SQL_PARAM_OUTPUT                                    equ     4
SQL_RETURN_VALUE                                    equ     5

SQL_PT_UNKNOWN                                      equ     0
SQL_PT_PROCEDURE                                    equ     1
SQL_PT_FUNCTION                                     equ     2

SQL_YEAR                                            equ     SQL_CODE_YEAR
SQL_MONTH                                           equ     SQL_CODE_MONTH
SQL_DAY                                             equ     SQL_CODE_DAY
SQL_HOUR                                            equ     SQL_CODE_HOUR
SQL_MINUTE                                          equ     SQL_CODE_MINUTE
SQL_SECOND                                          equ     SQL_CODE_SECOND
SQL_YEAR_TO_MONTH                                   equ     SQL_CODE_YEAR_TO_MONTH
SQL_DAY_TO_HOUR                                     equ     SQL_CODE_DAY_TO_HOUR
SQL_DAY_TO_MINUTE                                   equ     SQL_CODE_DAY_TO_MINUTE
SQL_DAY_TO_SECOND                                   equ     SQL_CODE_DAY_TO_SECOND
SQL_HOUR_TO_MINUTE                                  equ     SQL_CODE_HOUR_TO_MINUTE
SQL_HOUR_TO_SECOND                                  equ     SQL_CODE_HOUR_TO_SECOND
SQL_MINUTE_TO_SECOND                                equ     SQL_CODE_MINUTE_TO_SECOND

SQL_DATABASE_NAME                                   equ     16
SQL_FD_FETCH_PREV                                   equ     SQL_FD_FETCH_PRIOR
SQL_FETCH_PREV                                      equ     SQL_FETCH_PRIOR
SQL_CONCUR_TIMESTAMP                                equ     SQL_CONCUR_ROWVER
SQL_SCCO_OPT_TIMESTAMP                              equ     SQL_SCCO_OPT_ROWVER
SQL_CC_DELETE                                       equ     SQL_CB_DELETE
SQL_CR_DELETE                                       equ     SQL_CB_DELETE
SQL_CC_CLOSE                                        equ     SQL_CB_CLOSE
SQL_CR_CLOSE                                        equ     SQL_CB_CLOSE
SQL_CC_PRESERVE                                     equ     SQL_CB_PRESERVE
SQL_CR_PRESERVE                                     equ     SQL_CB_PRESERVE
SQL_SCROLL_FORWARD_ONLY                             equ     0
SQL_SCROLL_KEYSET_DRIVEN                            equ     (-1)
SQL_SCROLL_DYNAMIC                                  equ     (-2)
SQL_SCROLL_STATIC                                   equ     (-3)

TRACE_VERSION                                       equ     1000

TRACE_ON                                            equ     00000001H
TRACE_VS_EVENT_ON                                   equ     00000002H

ODBC_VS_FLAG_UNICODE_ARG                            equ     00000001H
ODBC_VS_FLAG_UNICODE_COR                            equ     00000002H
ODBC_VS_FLAG_RETCODE                                equ     00000004H
ODBC_VS_FLAG_STOP                                   equ     00000008H


;======================================== Structures ======================================;
if ~defined DATE_STRUCT_DEF
    DATE_STRUCT_DEF equ 1
    struct DATE_STRUCT
        year  dw ?
        month dw ?
        day   dw ?
    ends
end if

struct SQL_DATE_STRUCT
    year  dw ?
    month dw ?
    day   dw ?
ends

if ~defined TIME_STRUCT_DEF
    TIME_STRUCT_DEF equ 1
    struct TIME_STRUCT
        hour   dw ?
        minute dw ?
        second dw ?
    ends
end if

struct SQL_TIME_STRUCT
    hour   dw ?
    minute dw ?
    second dw ?
ends

if ~defined TIMESTAMP_STRUCT_DEF
    TIMESTAMP_STRUCT_DEF equ 1
    struct TIMESTAMP_STRUCT
        year     dw ?
        month    dw ?
        day      dw ?
        hour     dw ?
        minute   dw ?
        second   dw ?
        fraction dd ?
    ends
end if

struct SQL_TIMESTAMP_STRUCT
    year     dw ?
    month    dw ?
    day      dw ?
    hour     dw ?
    minute   dw ?
    second   dw ?
    fraction dd ?
ends

struct SQL_YEAR_MONTH_STRUCT
    year  dd ?
    month dd ?
ends

struct SQL_DAY_SECOND_STRUCT
    day      dd ?
    hour     dd ?
    minute   dd ?
    second   dd ?
    fraction dd ?
ends

struct SQL_INTERVAL_STRUCT
    interval_type dd ?
    interval_sign dd ?
    union
        year_month SQL_YEAR_MONTH_STRUCT
        day_second SQL_DAY_SECOND_STRUCT
     ends
ends
SQL_MAX_NUMERIC_LEN equ 16

struct SQL_NUMERIC_STRUCT
    precision db ?
    scale     db ?
    sign      db ?
    val       db SQL_MAX_NUMERIC_LEN dup(?)
ends

struct SQLGUID
    Data1 dd ?
    Data2 dw ?
    Data3 dw ?
    Data4 db 8 dup(?)
ends

struct ODBC_VS_ARGS
    pguidEvent         xptr  ?
    dwFlags            dd    ?
    union
        wszArg         xptr  ?
        szArg          xptr  ?
    ends
    union
        wszCorrelation xptr  ?
        szCorrelation  xptr  ?
    ends
    RetCode            dw  ?
ends


;======================================== Functions =======================================;
import odbc32,\
    CloseODBCPerfData,'CloseODBCPerfData',\
    CollectODBCPerfData,'CollectODBCPerfData',\
    CursorLibLockDbc,'CursorLibLockDbc',\
    CursorLibLockDesc,'CursorLibLockDesc',\
    CursorLibLockStmt,'CursorLibLockStmt',\
    CursorLibTransact,'CursorLibTransact',\
    DllBidEntryPoint,'DllBidEntryPoint',\
    GetODBCSharedData,'GetODBCSharedData',\
    LockHandle,'LockHandle',\
    ODBCGetTryWaitValue,'ODBCGetTryWaitValue',\
    ODBCInternalConnectW,'ODBCInternalConnectW',\
    ODBCQualifyFileDSNW,'ODBCQualifyFileDSNW',\
    ODBCSetTryWaitValue,'ODBCSetTryWaitValue',\
    OpenODBCPerfData,'OpenODBCPerfData',\
    PostComponentError,'PostComponentError',\
    PostODBCComponentError,'PostODBCComponentError',\
    PostODBCError,'PostODBCError',\
    SQLAllocConnect,'SQLAllocConnect',\
    SQLAllocEnv,'SQLAllocEnv',\
    SQLAllocHandle,'SQLAllocHandle',\
    SQLAllocHandleStd,'SQLAllocHandleStd',\
    SQLAllocStmt,'SQLAllocStmt',\
    SQLBindCol,'SQLBindCol',\
    SQLBindParam,'SQLBindParam',\
    SQLBindParameter,'SQLBindParameter',\
    SQLBrowseConnectA,'SQLBrowseConnectA',\
    SQLBrowseConnectW,'SQLBrowseConnectW',\
    SQLBulkOperations,'SQLBulkOperations',\
    SQLCancel,'SQLCancel',\
    SQLCancelHandle,'SQLCancelHandle',\
    SQLCloseCursor,'SQLCloseCursor',\
    SQLColAttributeA,'SQLColAttributeA',\
    SQLColAttributeW,'SQLColAttributeW',\
    SQLColAttributesA,'SQLColAttributesA',\
    SQLColAttributesW,'SQLColAttributesW',\
    SQLColumnPrivilegesA,'SQLColumnPrivilegesA',\
    SQLColumnPrivilegesW,'SQLColumnPrivilegesW',\
    SQLColumnsA,'SQLColumnsA',\
    SQLColumnsW,'SQLColumnsW',\
    SQLCompleteAsync,'SQLCompleteAsync',\
    SQLConnectA,'SQLConnectA',\
    SQLConnectW,'SQLConnectW',\
    SQLCopyDesc,'SQLCopyDesc',\
    SQLDataSourcesA,'SQLDataSourcesA',\
    SQLDataSourcesW,'SQLDataSourcesW',\
    SQLDescribeColA,'SQLDescribeColA',\
    SQLDescribeColW,'SQLDescribeColW',\
    SQLDescribeParam,'SQLDescribeParam',\
    SQLDisconnect,'SQLDisconnect',\
    SQLDriverConnectA,'SQLDriverConnectA',\
    SQLDriverConnectW,'SQLDriverConnectW',\
    SQLDriversA,'SQLDriversA',\
    SQLDriversW,'SQLDriversW',\
    SQLEndTran,'SQLEndTran',\
    SQLErrorA,'SQLErrorA',\
    SQLErrorW,'SQLErrorW',\
    SQLExecDirectA,'SQLExecDirectA',\
    SQLExecDirectW,'SQLExecDirectW',\
    SQLExecute,'SQLExecute',\
    SQLExtendedFetch,'SQLExtendedFetch',\
    SQLFetch,'SQLFetch',\
    SQLFetchScroll,'SQLFetchScroll',\
    SQLForeignKeysA,'SQLForeignKeysA',\
    SQLForeignKeysW,'SQLForeignKeysW',\
    SQLFreeConnect,'SQLFreeConnect',\
    SQLFreeEnv,'SQLFreeEnv',\
    SQLFreeHandle,'SQLFreeHandle',\
    SQLFreeStmt,'SQLFreeStmt',\
    SQLGetConnectAttrA,'SQLGetConnectAttrA',\
    SQLGetConnectAttrW,'SQLGetConnectAttrW',\
    SQLGetConnectOptionA,'SQLGetConnectOptionA',\
    SQLGetConnectOptionW,'SQLGetConnectOptionW',\
    SQLGetCursorNameA,'SQLGetCursorNameA',\
    SQLGetCursorNameW,'SQLGetCursorNameW',\
    SQLGetData,'SQLGetData',\
    SQLGetDescFieldA,'SQLGetDescFieldA',\
    SQLGetDescFieldW,'SQLGetDescFieldW',\
    SQLGetDescRecA,'SQLGetDescRecA',\
    SQLGetDescRecW,'SQLGetDescRecW',\
    SQLGetDiagFieldA,'SQLGetDiagFieldA',\
    SQLGetDiagFieldW,'SQLGetDiagFieldW',\
    SQLGetDiagRecA,'SQLGetDiagRecA',\
    SQLGetDiagRecW,'SQLGetDiagRecW',\
    SQLGetEnvAttr,'SQLGetEnvAttr',\
    SQLGetFunctions,'SQLGetFunctions',\
    SQLGetInfoA,'SQLGetInfoA',\
    SQLGetInfoW,'SQLGetInfoW',\
    SQLGetStmtAttrA,'SQLGetStmtAttrA',\
    SQLGetStmtAttrW,'SQLGetStmtAttrW',\
    SQLGetStmtOption,'SQLGetStmtOption',\
    SQLGetTypeInfoA,'SQLGetTypeInfoA',\
    SQLGetTypeInfoW,'SQLGetTypeInfoW',\
    SQLMoreResults,'SQLMoreResults',\
    SQLNativeSqlA,'SQLNativeSqlA',\
    SQLNativeSqlW,'SQLNativeSqlW',\
    SQLNumParams,'SQLNumParams',\
    SQLNumResultCols,'SQLNumResultCols',\
    SQLParamData,'SQLParamData',\
    SQLParamOptions,'SQLParamOptions',\
    SQLPrepareA,'SQLPrepareA',\
    SQLPrepareW,'SQLPrepareW',\
    SQLPrimaryKeysA,'SQLPrimaryKeysA',\
    SQLPrimaryKeysW,'SQLPrimaryKeysW',\
    SQLProcedureColumnsA,'SQLProcedureColumnsA',\
    SQLProcedureColumnsW,'SQLProcedureColumnsW',\
    SQLProceduresA,'SQLProceduresA',\
    SQLProceduresW,'SQLProceduresW',\
    SQLPutData,'SQLPutData',\
    SQLRowCount,'SQLRowCount',\
    SQLSetConnectAttrA,'SQLSetConnectAttrA',\
    SQLSetConnectAttrW,'SQLSetConnectAttrW',\
    SQLSetConnectOptionA,'SQLSetConnectOptionA',\
    SQLSetConnectOptionW,'SQLSetConnectOptionW',\
    SQLSetCursorNameA,'SQLSetCursorNameA',\
    SQLSetCursorNameW,'SQLSetCursorNameW',\
    SQLSetDescFieldA,'SQLSetDescFieldA',\
    SQLSetDescFieldW,'SQLSetDescFieldW',\
    SQLSetDescRec,'SQLSetDescRec',\
    SQLSetEnvAttr,'SQLSetEnvAttr',\
    SQLSetParam,'SQLSetParam',\
    SQLSetPos,'SQLSetPos',\
    SQLSetScrollOptions,'SQLSetScrollOptions',\
    SQLSetStmtAttrA,'SQLSetStmtAttrA',\
    SQLSetStmtAttrW,'SQLSetStmtAttrW',\
    SQLSetStmtOption,'SQLSetStmtOption',\
    SQLSpecialColumnsA,'SQLSpecialColumnsA',\
    SQLSpecialColumnsW,'SQLSpecialColumnsW',\
    SQLStatisticsA,'SQLStatisticsA',\
    SQLStatisticsW,'SQLStatisticsW',\
    SQLTablePrivilegesA,'SQLTablePrivilegesA',\
    SQLTablePrivilegesW,'SQLTablePrivilegesW',\
    SQLTablesA,'SQLTablesA',\
    SQLTablesW,'SQLTablesW',\
    SQLTransact,'SQLTransact',\
    SearchStatusCode,'SearchStatusCode',\
    VFreeErrors,'VFreeErrors',\
    VRetrieveDriverErrorsRowCol,'VRetrieveDriverErrorsRowCol',\
    ValidateErrorQueue,'ValidateErrorQueue'

api SQLBrowseConnect,\
    SQLColAttribute,\
    SQLColAttributes,\
    SQLColumnPrivileges,\
    SQLColumns,\
    SQLConnect,\
    SQLDataSources,\
    SQLDescribeCol,\
    SQLDriverConnect,\
    SQLDrivers,\
    SQLError,\
    SQLExecDirect,\
    SQLForeignKeys,\
    SQLGetConnectAttr,\
    SQLGetConnectOption,\
    SQLGetCursorName,\
    SQLGetDescField,\
    SQLGetDescRec,\
    SQLGetDiagField,\
    SQLGetDiagRec,\
    SQLGetInfo,\
    SQLGetStmtAttr,\
    SQLGetTypeInfo,\
    SQLNativeSql,\
    SQLPrepare,\
    SQLPrimaryKeys,\
    SQLProcedureColumns,\
    SQLProcedures,\
    SQLSetConnectAttr,\
    SQLSetConnectOption,\
    SQLSetCursorName,\
    SQLSetDescField,\
    SQLSetStmtAttr,\
    SQLSpecialColumns,\
    SQLStatistics,\
    SQLTablePrivileges,\
    SQLTables


;======================= Undocumented functions (unknown arguments) =======================;
;g_hHeapMalloc,'g_hHeapMalloc'

;if (NTDDI_VERSION = NTDDI_WINXP)
;   MpHeapAlloc,'MpHeapAlloc',\
;   MpHeapCompact,'MpHeapCompact',\
;   MpHeapCreate','MpHeapCreate',\
;   MpHeapDestroy','MpHeapDestroy',\
;   MpHeapFree','MpHeapFree',\
;   MpHeapReAlloc','MpHeapReAlloc',\
;   MpHeapSize','MpHeapSize',\
;   MpHeapValidate','MpHeapValidate',\
;   g_hHeapMalloc','g_hHeapMalloc'
;end if


end if ;ODBC32_INC
