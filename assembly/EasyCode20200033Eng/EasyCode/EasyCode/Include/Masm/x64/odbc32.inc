; ======================================================;
;                                                       ;
;   odbc32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.3)                      ;
;                                                       ;
;         Copyright © Ramon Sala - 2017-2018            ;
;                                                       ;
; ======================================================;

IFNDEF ODBC32_INC
ODBC32_INC EQU 1

SQL_NULL_DATA                                       EQU     (-1)
SQL_DATA_AT_EXEC                                    EQU     (-2)

SQL_SUCCESS                                         EQU     0
SQL_SUCCESS_WITH_INFO                               EQU     1
SQL_NO_DATA                                         EQU     100
SQL_ERROR                                           EQU     (-1)
SQL_INVALID_HANDLE                                  EQU     (-2)

SQL_STILL_EXECUTING                                 EQU     2
SQL_NEED_DATA                                       EQU     99

SQL_NTS                                             EQU     (-3)
SQL_NTSL                                            EQU     (-3)

SQL_MAX_MESSAGE_LENGTH                              EQU     512

SQL_DATE_LEN                                        EQU     10
SQL_TIME_LEN                                        EQU     8
SQL_TIMESTAMP_LEN                                   EQU     19

SQL_HANDLE_ENV                                      EQU     1
SQL_HANDLE_DBC                                      EQU     2
SQL_HANDLE_STMT                                     EQU     3
SQL_HANDLE_DESC                                     EQU     4

SQL_ATTR_OUTPUT_NTS                                 EQU     10001
SQL_ATTR_AUTO_IPD                                   EQU     10001
SQL_ATTR_METADATA_ID                                EQU     10014
SQL_ATTR_APP_ROW_DESC                               EQU     10010
SQL_ATTR_APP_PARAM_DESC                             EQU     10011
SQL_ATTR_IMP_ROW_DESC                               EQU     10012
SQL_ATTR_IMP_PARAM_DESC                             EQU     10013
SQL_ATTR_CURSOR_SCROLLABLE                          EQU     (-1)
SQL_ATTR_CURSOR_SENSITIVITY                         EQU     (-2)

SQL_NONSCROLLABLE                                   EQU     0
SQL_SCROLLABLE                                      EQU     1

SQL_DESC_COUNT                                      EQU     1001
SQL_DESC_TYPE                                       EQU     1002
SQL_DESC_LENGTH                                     EQU     1003
SQL_DESC_OCTET_LENGTH_PTR                           EQU     1004
SQL_DESC_PRECISION                                  EQU     1005
SQL_DESC_SCALE                                      EQU     1006
SQL_DESC_DATETIME_INTERVAL_CODE                     EQU     1007
SQL_DESC_NULLABLE                                   EQU     1008
SQL_DESC_INDICATOR_PTR                              EQU     1009
SQL_DESC_DATA_PTR                                   EQU     1010
SQL_DESC_NAME                                       EQU     1011
SQL_DESC_UNNAMED                                    EQU     1012
SQL_DESC_OCTET_LENGTH                               EQU     1013
SQL_DESC_ALLOC_TYPE                                 EQU     1099

SQL_DIAG_RETURNCODE                                 EQU     1
SQL_DIAG_NUMBER                                     EQU     2
SQL_DIAG_ROW_COUNT                                  EQU     3
SQL_DIAG_SQLSTATE                                   EQU     4
SQL_DIAG_NATIVE                                     EQU     5
SQL_DIAG_MESSAGE_TEXT                               EQU     6
SQL_DIAG_DYNAMIC_FUNCTION                           EQU     7
SQL_DIAG_CLASS_ORIGIN                               EQU     8
SQL_DIAG_SUBCLASS_ORIGIN                            EQU     9
SQL_DIAG_CONNECTION_NAME                            EQU     10
SQL_DIAG_SERVER_NAME                                EQU     11
SQL_DIAG_DYNAMIC_FUNCTION_CODE                      EQU     12

SQL_DIAG_ALTER_DOMAIN                               EQU     3
SQL_DIAG_ALTER_TABLE                                EQU     4
SQL_DIAG_CALL                                       EQU     7
SQL_DIAG_CREATE_ASSERTION                           EQU     6
SQL_DIAG_CREATE_CHARACTER_SET                       EQU     8
SQL_DIAG_CREATE_COLLATION                           EQU     10
SQL_DIAG_CREATE_DOMAIN                              EQU     23
SQL_DIAG_CREATE_INDEX                               EQU     (-1)
SQL_DIAG_CREATE_SCHEMA                              EQU     64
SQL_DIAG_CREATE_TABLE                               EQU     77
SQL_DIAG_CREATE_TRANSLATION                         EQU     79
SQL_DIAG_CREATE_VIEW                                EQU     84
SQL_DIAG_DELETE_WHERE                               EQU     19
SQL_DIAG_DROP_ASSERTION                             EQU     24
SQL_DIAG_DROP_CHARACTER_SET                         EQU     25
SQL_DIAG_DROP_COLLATION                             EQU     26
SQL_DIAG_DROP_DOMAIN                                EQU     27
SQL_DIAG_DROP_INDEX                                 EQU     (-2)
SQL_DIAG_DROP_SCHEMA                                EQU     31
SQL_DIAG_DROP_TABLE                                 EQU     32
SQL_DIAG_DROP_TRANSLATION                           EQU     33
SQL_DIAG_DROP_VIEW                                  EQU     36
SQL_DIAG_DYNAMIC_DELETE_CURSOR                      EQU     38
SQL_DIAG_DYNAMIC_UPDATE_CURSOR                      EQU     81
SQL_DIAG_GRANT                                      EQU     48
SQL_DIAG_INSERT                                     EQU     50
SQL_DIAG_REVOKE                                     EQU     59
SQL_DIAG_SELECT_CURSOR                              EQU     85
SQL_DIAG_UNKNOWN_STATEMENT                          EQU     0
SQL_DIAG_UPDATE_WHERE                               EQU     82

SQL_UNKNOWN_TYPE                                    EQU     0
SQL_CHAR                                            EQU     1
SQL_NUMERIC                                         EQU     2
SQL_DECIMAL                                         EQU     3
SQL_INTEGER                                         EQU     4
SQL_SMALLINT                                        EQU     5
SQL_FLOAT                                           EQU     6
SQL_REAL                                            EQU     7
SQL_DOUBLE                                          EQU     8
SQL_DATETIME                                        EQU     9
SQL_VARCHAR                                         EQU     12

SQL_TYPE_DATE                                       EQU     91
SQL_TYPE_TIME                                       EQU     92
SQL_TYPE_TIMESTAMP                                  EQU     93

SQL_UNSPECIFIED                                     EQU     0
SQL_INSENSITIVE                                     EQU     1
SQL_SENSITIVE                                       EQU     2

SQL_ALL_TYPES                                       EQU     0

SQL_DEFAULT                                         EQU     99

SQL_ARD_TYPE                                        EQU     (-99)

SQL_CODE_DATE                                       EQU     1
SQL_CODE_TIME                                       EQU     2
SQL_CODE_TIMESTAMP                                  EQU     3

SQL_FALSE                                           EQU     0
SQL_TRUE                                            EQU     1

SQL_NO_NULLS                                        EQU     0
SQL_NULLABLE                                        EQU     1

SQL_NULLABLE_UNKNOWN                                EQU     2

SQL_PRED_NONE                                       EQU     0
SQL_PRED_CHAR                                       EQU     1
SQL_PRED_BASIC                                      EQU     2

SQL_NAMED                                           EQU     0
SQL_UNNAMED                                         EQU     1

SQL_DESC_ALLOC_AUTO                                 EQU     1
SQL_DESC_ALLOC_USER                                 EQU     2

SQL_CLOSE                                           EQU     0
SQL_DROP                                            EQU     1
SQL_UNBIND                                          EQU     2
SQL_RESET_PARAMS                                    EQU     3

SQL_FETCH_NEXT                                      EQU     1
SQL_FETCH_FIRST                                     EQU     2

SQL_FETCH_LAST                                      EQU     3
SQL_FETCH_PRIOR                                     EQU     4
SQL_FETCH_ABSOLUTE                                  EQU     5
SQL_FETCH_RELATIVE                                  EQU     6

SQL_COMMIT                                          EQU     0
SQL_ROLLBACK                                        EQU     1

SQL_NULL_HENV                                       EQU     0
SQL_NULL_HDBC                                       EQU     0
SQL_NULL_HSTMT                                      EQU     0
SQL_NULL_HDESC                                      EQU     0

SQL_NULL_HANDLE                                     EQU     0L

SQL_SCOPE_CURROW                                    EQU     0
SQL_SCOPE_TRANSACTION                               EQU     1
SQL_SCOPE_SESSION                                   EQU     2

SQL_PC_UNKNOWN                                      EQU     0
SQL_PC_NON_PSEUDO                                   EQU     1
SQL_PC_PSEUDO                                       EQU     2

SQL_ROW_IDENTIFIER                                  EQU     1

SQL_INDEX_UNIQUE                                    EQU     0
SQL_INDEX_ALL                                       EQU     1

SQL_INDEX_CLUSTERED                                 EQU     1
SQL_INDEX_HASHED                                    EQU     2
SQL_INDEX_OTHER                                     EQU     3

SQL_API_SQLALLOCCONNECT                             EQU     1
SQL_API_SQLALLOCENV                                 EQU     2
SQL_API_SQLALLOCHANDLE                              EQU     1001
SQL_API_SQLALLOCSTMT                                EQU     3
SQL_API_SQLBINDCOL                                  EQU     4
SQL_API_SQLBINDPARAM                                EQU     1002
SQL_API_SQLCANCEL                                   EQU     5
SQL_API_SQLCLOSECURSOR                              EQU     1003
SQL_API_SQLCOLATTRIBUTE                             EQU     6
SQL_API_SQLCOLUMNS                                  EQU     40
SQL_API_SQLCONNECT                                  EQU     7
SQL_API_SQLCOPYDESC                                 EQU     1004
SQL_API_SQLDATASOURCES                              EQU     57
SQL_API_SQLDESCRIBECOL                              EQU     8
SQL_API_SQLDISCONNECT                               EQU     9
SQL_API_SQLENDTRAN                                  EQU     1005
SQL_API_SQLERROR                                    EQU     10
SQL_API_SQLEXECDIRECT                               EQU     11
SQL_API_SQLEXECUTE                                  EQU     12
SQL_API_SQLFETCH                                    EQU     13
SQL_API_SQLFETCHSCROLL                              EQU     1021
SQL_API_SQLFREECONNECT                              EQU     14
SQL_API_SQLFREEENV                                  EQU     15
SQL_API_SQLFREEHANDLE                               EQU     1006
SQL_API_SQLFREESTMT                                 EQU     16
SQL_API_SQLGETCONNECTATTR                           EQU     1007
SQL_API_SQLGETCONNECTOPTION                         EQU     42
SQL_API_SQLGETCURSORNAME                            EQU     17
SQL_API_SQLGETDATA                                  EQU     43
SQL_API_SQLGETDESCFIELD                             EQU     1008
SQL_API_SQLGETDESCREC                               EQU     1009
SQL_API_SQLGETDIAGFIELD                             EQU     1010
SQL_API_SQLGETDIAGREC                               EQU     1011
SQL_API_SQLGETENVATTR                               EQU     1012
SQL_API_SQLGETFUNCTIONS                             EQU     44
SQL_API_SQLGETINFO                                  EQU     45
SQL_API_SQLGETSTMTATTR                              EQU     1014
SQL_API_SQLGETSTMTOPTION                            EQU     46
SQL_API_SQLGETTYPEINFO                              EQU     47
SQL_API_SQLNUMRESULTCOLS                            EQU     18
SQL_API_SQLPARAMDATA                                EQU     48
SQL_API_SQLPREPARE                                  EQU     19
SQL_API_SQLPUTDATA                                  EQU     49
SQL_API_SQLROWCOUNT                                 EQU     20
SQL_API_SQLSETCONNECTATTR                           EQU     1016
SQL_API_SQLSETCONNECTOPTION                         EQU     50
SQL_API_SQLSETCURSORNAME                            EQU     21
SQL_API_SQLSETDESCFIELD                             EQU     1017
SQL_API_SQLSETDESCREC                               EQU     1018
SQL_API_SQLSETENVATTR                               EQU     1019
SQL_API_SQLSETPARAM                                 EQU     22
SQL_API_SQLSETSTMTATTR                              EQU     1020
SQL_API_SQLSETSTMTOPTION                            EQU     51
SQL_API_SQLSPECIALCOLUMNS                           EQU     52
SQL_API_SQLSTATISTICS                               EQU     53
SQL_API_SQLTABLES                                   EQU     54
SQL_API_SQLTRANSACT                                 EQU     23

SQL_MAX_DRIVER_CONNECTIONS                          EQU     0
SQL_MAXIMUM_DRIVER_CONNECTIONS                      EQU     SQL_MAX_DRIVER_CONNECTIONS
SQL_MAX_CONCURRENT_ACTIVITIES                       EQU     1
SQL_MAXIMUM_CONCURRENT_ACTIVITIES                   EQU     SQL_MAX_CONCURRENT_ACTIVITIES
SQL_DATA_SOURCE_NAME                                EQU     2
SQL_FETCH_DIRECTION                                 EQU     8
SQL_SERVER_NAME                                     EQU     13
SQL_SEARCH_PATTERN_ESCAPE                           EQU     14
SQL_DBMS_NAME                                       EQU     17
SQL_DBMS_VER                                        EQU     18
SQL_ACCESSIBLE_TABLES                               EQU     19
SQL_ACCESSIBLE_PROCEDURES                           EQU     20
SQL_CURSOR_COMMIT_BEHAVIOR                          EQU     23
SQL_DATA_SOURCE_READ_ONLY                           EQU     25
SQL_DEFAULT_TXN_ISOLATION                           EQU     26
SQL_IDENTIFIER_CASE                                 EQU     28
SQL_IDENTIFIER_QUOTE_CHAR                           EQU     29
SQL_MAX_COLUMN_NAME_LEN                             EQU     30
SQL_MAXIMUM_COLUMN_NAME_LENGTH                      EQU     SQL_MAX_COLUMN_NAME_LEN
SQL_MAX_CURSOR_NAME_LEN                             EQU     31
SQL_MAXIMUM_CURSOR_NAME_LENGTH                      EQU     SQL_MAX_CURSOR_NAME_LEN
SQL_MAX_SCHEMA_NAME_LEN                             EQU     32
SQL_MAXIMUM_SCHEMA_NAME_LENGTH                      EQU     SQL_MAX_SCHEMA_NAME_LEN
SQL_MAX_CATALOG_NAME_LEN                            EQU     34
SQL_MAXIMUM_CATALOG_NAME_LENGTH                     EQU     SQL_MAX_CATALOG_NAME_LEN
SQL_MAX_TABLE_NAME_LEN                              EQU     35
SQL_SCROLL_CONCURRENCY                              EQU     43
SQL_TXN_CAPABLE                                     EQU     46
SQL_TRANSACTION_CAPABLE                             EQU     SQL_TXN_CAPABLE
SQL_USER_NAME                                       EQU     47
SQL_TXN_ISOLATION_OPTION                            EQU     72
SQL_TRANSACTION_ISOLATION_OPTION                    EQU     SQL_TXN_ISOLATION_OPTION
SQL_INTEGRITY                                       EQU     73
SQL_GETDATA_EXTENSIONS                              EQU     81
SQL_NULL_COLLATION                                  EQU     85
SQL_ALTER_TABLE                                     EQU     86
SQL_ORDER_BY_COLUMNS_IN_SELECT                      EQU     90
SQL_SPECIAL_CHARACTERS                              EQU     94
SQL_MAX_COLUMNS_IN_GROUP_BY                         EQU     97
SQL_MAXIMUM_COLUMNS_IN_GROUP_BY                     EQU     SQL_MAX_COLUMNS_IN_GROUP_BY
SQL_MAX_COLUMNS_IN_INDEX                            EQU     98
SQL_MAXIMUM_COLUMNS_IN_INDEX                        EQU     SQL_MAX_COLUMNS_IN_INDEX
SQL_MAX_COLUMNS_IN_ORDER_BY                         EQU     99
SQL_MAXIMUM_COLUMNS_IN_ORDER_BY                     EQU     SQL_MAX_COLUMNS_IN_ORDER_BY
SQL_MAX_COLUMNS_IN_SELECT                           EQU     100
SQL_MAXIMUM_COLUMNS_IN_SELECT                       EQU     SQL_MAX_COLUMNS_IN_SELECT
SQL_MAX_COLUMNS_IN_TABLE                            EQU     101
SQL_MAX_INDEX_SIZE                                  EQU     102
SQL_MAXIMUM_INDEX_SIZE                              EQU     SQL_MAX_INDEX_SIZE
SQL_MAX_ROW_SIZE                                    EQU     104
SQL_MAXIMUM_ROW_SIZE                                EQU     SQL_MAX_ROW_SIZE
SQL_MAX_STATEMENT_LEN                               EQU     105
SQL_MAXIMUM_STATEMENT_LENGTH                        EQU     SQL_MAX_STATEMENT_LEN
SQL_MAX_TABLES_IN_SELECT                            EQU     106
SQL_MAXIMUM_TABLES_IN_SELECT                        EQU     SQL_MAX_TABLES_IN_SELECT
SQL_MAX_USER_NAME_LEN                               EQU     107
SQL_MAXIMUM_USER_NAME_LENGTH                        EQU     SQL_MAX_USER_NAME_LEN
SQL_OJ_CAPABILITIES                                 EQU     115
SQL_OUTER_JOIN_CAPABILITIES                         EQU     SQL_OJ_CAPABILITIES

SQL_XOPEN_CLI_YEAR                                  EQU     10000
SQL_CURSOR_SENSITIVITY                              EQU     10001
SQL_DESCRIBE_PARAMETER                              EQU     10002
SQL_CATALOG_NAME                                    EQU     10003
SQL_COLLATION_SEQ                                   EQU     10004
SQL_MAX_IDENTIFIER_LEN                              EQU     10005
SQL_MAXIMUM_IDENTIFIER_LENGTH                       EQU     SQL_MAX_IDENTIFIER_LEN

SQL_AT_ADD_COLUMN                                   EQU     00000001H
SQL_AT_DROP_COLUMN                                  EQU     00000002H
SQL_AT_ADD_CONSTRAINT                               EQU     00000008H

SQL_AM_NONE                                         EQU     0
SQL_AM_CONNECTION                                   EQU     1
SQL_AM_STATEMENT                                    EQU     2

SQL_CB_DELETE                                       EQU     0
SQL_CB_CLOSE                                        EQU     1
SQL_CB_PRESERVE                                     EQU     2

SQL_FD_FETCH_NEXT                                   EQU     00000001H
SQL_FD_FETCH_FIRST                                  EQU     00000002H
SQL_FD_FETCH_LAST                                   EQU     00000004H
SQL_FD_FETCH_PRIOR                                  EQU     00000008H
SQL_FD_FETCH_ABSOLUTE                               EQU     00000010H
SQL_FD_FETCH_RELATIVE                               EQU     00000020H

SQL_GD_ANY_COLUMN                                   EQU     00000001H
SQL_GD_ANY_ORDER                                    EQU     00000002H

SQL_IC_UPPER                                        EQU     1
SQL_IC_LOWER                                        EQU     2
SQL_IC_SENSITIVE                                    EQU     3
SQL_IC_MIXED                                        EQU     4

SQL_OJ_LEFT                                         EQU     00000001H
SQL_OJ_RIGHT                                        EQU     00000002H
SQL_OJ_FULL                                         EQU     00000004H
SQL_OJ_NESTED                                       EQU     00000008H
SQL_OJ_NOT_ORDERED                                  EQU     00000010H
SQL_OJ_INNER                                        EQU     00000020H
SQL_OJ_ALL_COMPARISON_OPS                           EQU     00000040H

SQL_SCCO_READ_ONLY                                  EQU     00000001H
SQL_SCCO_LOCK                                       EQU     00000002H
SQL_SCCO_OPT_ROWVER                                 EQU     00000004H
SQL_SCCO_OPT_VALUES                                 EQU     00000008H

SQL_TC_NONE                                         EQU     0
SQL_TC_DML                                          EQU     1
SQL_TC_ALL                                          EQU     2
SQL_TC_DDL_COMMIT                                   EQU     3
SQL_TC_DDL_IGNORE                                   EQU     4

SQL_TXN_READ_UNCOMMITTED                            EQU     00000001H
SQL_TRANSACTION_READ_UNCOMMITTED                    EQU     SQL_TXN_READ_UNCOMMITTED
SQL_TXN_READ_COMMITTED                              EQU     00000002H
SQL_TRANSACTION_READ_COMMITTED                      EQU     SQL_TXN_READ_COMMITTED
SQL_TXN_REPEATABLE_READ                             EQU     00000004H
SQL_TRANSACTION_REPEATABLE_READ                     EQU     SQL_TXN_REPEATABLE_READ
SQL_TXN_SERIALIZABLE                                EQU     00000008H
SQL_TRANSACTION_SERIALIZABLE                        EQU     SQL_TXN_SERIALIZABLE

SQL_NC_HIGH                                         EQU     0
SQL_NC_LOW                                          EQU     1

SQL_SPEC_MAJOR                                      EQU     3
SQL_SPEC_MINOR                                      EQU     52
SQL_SPEC_STRING                                     EQU     A("03.52")

SQL_SQLSTATE_SIZE                                   EQU     5
SQL_MAX_DSN_LENGTH                                  EQU     32

SQL_MAX_OPTION_STRING_LENGTH                        EQU     256

SQL_NO_DATA_FOUND                                   EQU     SQL_NO_DATA

SQL_HANDLE_SENV                                     EQU     5

SQL_ATTR_ODBC_VERSION                               EQU     200
SQL_ATTR_CONNECTION_POOLING                         EQU     201
SQL_ATTR_CP_MATCH                                   EQU     202

SQL_CP_OFF                                          EQU     0
SQL_CP_ONE_PER_DRIVER                               EQU     1
SQL_CP_ONE_PER_HENV                                 EQU     2
SQL_CP_DEFAULT                                      EQU     SQL_CP_OFF
SQL_CP_STRICT_MATCH                                 EQU     0
SQL_CP_RELAXED_MATCH                                EQU     1
SQL_CP_MATCH_DEFAULT                                EQU     SQL_CP_STRICT_MATCH

SQL_OV_ODBC2                                        EQU     2
SQL_OV_ODBC3                                        EQU     3

SQL_ACCESS_MODE                                     EQU     101
SQL_AUTOCOMMIT                                      EQU     102
SQL_LOGIN_TIMEOUT                                   EQU     103
SQL_OPT_TRACE                                       EQU     104
SQL_OPT_TRACEFILE                                   EQU     105
SQL_TRANSLATE_DLL                                   EQU     106
SQL_TRANSLATE_OPTION                                EQU     107
SQL_TXN_ISOLATION                                   EQU     108
SQL_CURRENT_QUALIFIER                               EQU     109
SQL_ODBC_CURSORS                                    EQU     110
SQL_QUIET_MODE                                      EQU     111
SQL_PACKET_SIZE                                     EQU     112

SQL_ATTR_ACCESS_MODE                                EQU     SQL_ACCESS_MODE
SQL_ATTR_AUTOCOMMIT                                 EQU     SQL_AUTOCOMMIT
SQL_ATTR_CONNECTION_TIMEOUT                         EQU     113
SQL_ATTR_CURRENT_CATALOG                            EQU     SQL_CURRENT_QUALIFIER
SQL_ATTR_DISCONNECT_BEHAVIOR                        EQU     114
SQL_ATTR_ENLIST_IN_DTC                              EQU     1207
SQL_ATTR_ENLIST_IN_XA                               EQU     1208
SQL_ATTR_LOGIN_TIMEOUT                              EQU     SQL_LOGIN_TIMEOUT
SQL_ATTR_ODBC_CURSORS                               EQU     SQL_ODBC_CURSORS
SQL_ATTR_PACKET_SIZE                                EQU     SQL_PACKET_SIZE
SQL_ATTR_QUIET_MODE                                 EQU     SQL_QUIET_MODE
SQL_ATTR_TRACE                                      EQU     SQL_OPT_TRACE
SQL_ATTR_TRACEFILE                                  EQU     SQL_OPT_TRACEFILE
SQL_ATTR_TRANSLATE_LIB                              EQU     SQL_TRANSLATE_DLL
SQL_ATTR_TRANSLATE_OPTION                           EQU     SQL_TRANSLATE_OPTION
SQL_ATTR_TXN_ISOLATION                              EQU     SQL_TXN_ISOLATION

SQL_ATTR_CONNECTION_DEAD                            EQU     1209

SQL_ATTR_ANSI_APP                                   EQU     115

SQL_MODE_READ_WRITE                                 EQU     0
SQL_MODE_READ_ONLY                                  EQU     1
SQL_MODE_DEFAULT                                    EQU     SQL_MODE_READ_WRITE

SQL_AUTOCOMMIT_OFF                                  EQU     0
SQL_AUTOCOMMIT_ON                                   EQU     1
SQL_AUTOCOMMIT_DEFAULT                              EQU     SQL_AUTOCOMMIT_ON

SQL_LOGIN_TIMEOUT_DEFAULT                           EQU     15

SQL_OPT_TRACE_OFF                                   EQU     0
SQL_OPT_TRACE_ON                                    EQU     1
SQL_OPT_TRACE_DEFAULT                               EQU     SQL_OPT_TRACE_OFF
SQL_OPT_TRACE_FILE_DEFAULT                          EQU     A("\SQL.LOG")

SQL_CUR_USE_IF_NEEDED                               EQU     0
SQL_CUR_USE_ODBC                                    EQU     1
SQL_CUR_USE_DRIVER                                  EQU     2
SQL_CUR_DEFAULT                                     EQU     SQL_CUR_USE_DRIVER

SQL_DB_RETURN_TO_POOL                               EQU     0
SQL_DB_DISCONNECT                                   EQU     1
SQL_DB_DEFAULT                                      EQU     SQL_DB_RETURN_TO_POOL

SQL_DTC_DONE                                        EQU     0

SQL_CD_TRUE                                         EQU     1
SQL_CD_FALSE                                        EQU     0

SQL_AA_TRUE                                         EQU     1
SQL_AA_FALSE                                        EQU     0

SQL_QUERY_TIMEOUT                                   EQU     0
SQL_MAX_ROWS                                        EQU     1
SQL_NOSCAN                                          EQU     2
SQL_MAX_LENGTH                                      EQU     3
SQL_ASYNC_ENABLE                                    EQU     4
SQL_BIND_TYPE                                       EQU     5
SQL_CURSOR_TYPE                                     EQU     6
SQL_CONCURRENCY                                     EQU     7
SQL_KEYSET_SIZE                                     EQU     8
SQL_ROWSET_SIZE                                     EQU     9
SQL_SIMULATE_CURSOR                                 EQU     10
SQL_RETRIEVE_DATA                                   EQU     11
SQL_USE_BOOKMARKS                                   EQU     12
SQL_GET_BOOKMARK                                    EQU     13
SQL_ROW_NUMBER                                      EQU     14

SQL_ATTR_ASYNC_ENABLE                               EQU     4
SQL_ATTR_CONCURRENCY                                EQU     SQL_CONCURRENCY
SQL_ATTR_CURSOR_TYPE                                EQU     SQL_CURSOR_TYPE
SQL_ATTR_ENABLE_AUTO_IPD                            EQU     15
SQL_ATTR_FETCH_BOOKMARK_PTR                         EQU     16
SQL_ATTR_KEYSET_SIZE                                EQU     SQL_KEYSET_SIZE
SQL_ATTR_MAX_LENGTH                                 EQU     SQL_MAX_LENGTH
SQL_ATTR_MAX_ROWS                                   EQU     SQL_MAX_ROWS
SQL_ATTR_NOSCAN                                     EQU     SQL_NOSCAN
SQL_ATTR_PARAM_BIND_OFFSET_PTR                      EQU     17
SQL_ATTR_PARAM_BIND_TYPE                            EQU     18
SQL_ATTR_PARAM_OPERATION_PTR                        EQU     19
SQL_ATTR_PARAM_STATUS_PTR                           EQU     20
SQL_ATTR_PARAMS_PROCESSED_PTR                       EQU     21
SQL_ATTR_PARAMSET_SIZE                              EQU     22
SQL_ATTR_QUERY_TIMEOUT                              EQU     SQL_QUERY_TIMEOUT
SQL_ATTR_RETRIEVE_DATA                              EQU     SQL_RETRIEVE_DATA
SQL_ATTR_ROW_BIND_OFFSET_PTR                        EQU     23
SQL_ATTR_ROW_BIND_TYPE                              EQU     SQL_BIND_TYPE
SQL_ATTR_ROW_NUMBER                                 EQU     SQL_ROW_NUMBER
SQL_ATTR_ROW_OPERATION_PTR                          EQU     24
SQL_ATTR_ROW_STATUS_PTR                             EQU     25
SQL_ATTR_ROWS_FETCHED_PTR                           EQU     26
SQL_ATTR_ROW_ARRAY_SIZE                             EQU     27
SQL_ATTR_SIMULATE_CURSOR                            EQU     SQL_SIMULATE_CURSOR
SQL_ATTR_USE_BOOKMARKS                              EQU     SQL_USE_BOOKMARKS

SQL_COL_PRED_CHAR                                   EQU     SQL_LIKE_ONLY
SQL_COL_PRED_BASIC                                  EQU     SQL_ALL_EXCEPT_LIKE

SQL_IS_POINTER                                      EQU     (-4)
SQL_IS_UINTEGER                                     EQU     (-5)
SQL_IS_INTEGER                                      EQU     (-6)
SQL_IS_USMALLINT                                    EQU     (-7)
SQL_IS_SMALLINT                                     EQU     (-8)

SQL_PARAM_BIND_BY_COLUMN                            EQU     0
SQL_PARAM_BIND_TYPE_DEFAULT                         EQU     SQL_PARAM_BIND_BY_COLUMN

SQL_QUERY_TIMEOUT_DEFAULT                           EQU     0

SQL_MAX_ROWS_DEFAULT                                EQU     0

SQL_NOSCAN_OFF                                      EQU     0
SQL_NOSCAN_ON                                       EQU     1
SQL_NOSCAN_DEFAULT                                  EQU     SQL_NOSCAN_OFF

SQL_MAX_LENGTH_DEFAULT                              EQU     0

SQL_ASYNC_ENABLE_OFF                                EQU     0
SQL_ASYNC_ENABLE_ON                                 EQU     1
SQL_ASYNC_ENABLE_DEFAULT                            EQU     SQL_ASYNC_ENABLE_OFF

SQL_BIND_BY_COLUMN                                  EQU     0
SQL_BIND_TYPE_DEFAULT                               EQU     SQL_BIND_BY_COLUMN

SQL_CONCUR_READ_ONLY                                EQU     1
SQL_CONCUR_LOCK                                     EQU     2
SQL_CONCUR_ROWVER                                   EQU     3
SQL_CONCUR_VALUES                                   EQU     4
SQL_CONCUR_DEFAULT                                  EQU     SQL_CONCUR_READ_ONLY

SQL_CURSOR_FORWARD_ONLY                             EQU     0
SQL_CURSOR_KEYSET_DRIVEN                            EQU     1
SQL_CURSOR_DYNAMIC                                  EQU     2
SQL_CURSOR_STATIC                                   EQU     3
SQL_CURSOR_TYPE_DEFAULT                             EQU     SQL_CURSOR_FORWARD_ONLY

SQL_ROWSET_SIZE_DEFAULT                             EQU     1

SQL_KEYSET_SIZE_DEFAULT                             EQU     0

SQL_SC_NON_UNIQUE                                   EQU     0
SQL_SC_TRY_UNIQUE                                   EQU     1
SQL_SC_UNIQUE                                       EQU     2

SQL_RD_OFF                                          EQU     0
SQL_RD_ON                                           EQU     1
SQL_RD_DEFAULT                                      EQU     SQL_RD_ON

SQL_UB_OFF                                          EQU     0
SQL_UB_ON                                           EQU     01
SQL_UB_DEFAULT                                      EQU     SQL_UB_OFF

SQL_UB_FIXED                                        EQU     SQL_UB_ON
SQL_UB_VARIABLE                                     EQU     2

SQL_DESC_ARRAY_SIZE                                 EQU     20
SQL_DESC_ARRAY_STATUS_PTR                           EQU     21
SQL_DESC_AUTO_UNIQUE_VALUE                          EQU     SQL_COLUMN_AUTO_INCREMENT
SQL_DESC_BASE_COLUMN_NAME                           EQU     22
SQL_DESC_BASE_TABLE_NAME                            EQU     23
SQL_DESC_BIND_OFFSET_PTR                            EQU     24
SQL_DESC_BIND_TYPE                                  EQU     25
SQL_DESC_CASE_SENSITIVE                             EQU     SQL_COLUMN_CASE_SENSITIVE
SQL_DESC_CATALOG_NAME                               EQU     SQL_COLUMN_QUALIFIER_NAME
SQL_DESC_CONCISE_TYPE                               EQU     SQL_COLUMN_TYPE
SQL_DESC_DATETIME_INTERVAL_PRECISION                EQU     26
SQL_DESC_DISPLAY_SIZE                               EQU     SQL_COLUMN_DISPLAY_SIZE
SQL_DESC_FIXED_PREC_SCALE                           EQU     SQL_COLUMN_MONEY
SQL_DESC_LABEL                                      EQU     SQL_COLUMN_LABEL
SQL_DESC_LITERAL_PREFIX                             EQU     27
SQL_DESC_LITERAL_SUFFIX                             EQU     28
SQL_DESC_LOCAL_TYPE_NAME                            EQU     29
SQL_DESC_MAXIMUM_SCALE                              EQU     30
SQL_DESC_MINIMUM_SCALE                              EQU     31
SQL_DESC_NUM_PREC_RADIX                             EQU     32
SQL_DESC_PARAMETER_TYPE                             EQU     33
SQL_DESC_ROWS_PROCESSED_PTR                         EQU     34
SQL_DESC_ROWVER                                     EQU     35
SQL_DESC_SCHEMA_NAME                                EQU     SQL_COLUMN_OWNER_NAME
SQL_DESC_SEARCHABLE                                 EQU     SQL_COLUMN_SEARCHABLE
SQL_DESC_TYPE_NAME                                  EQU     SQL_COLUMN_TYPE_NAME
SQL_DESC_TABLE_NAME                                 EQU     SQL_COLUMN_TABLE_NAME
SQL_DESC_UNSIGNED                                   EQU     SQL_COLUMN_UNSIGNED
SQL_DESC_UPDATABLE                                  EQU     SQL_COLUMN_UPDATABLE

SQL_DIAG_CURSOR_ROW_COUNT                           EQU     (-1249)
SQL_DIAG_ROW_NUMBER                                 EQU     (-1248)
SQL_DIAG_COLUMN_NUMBER                              EQU     (-1247)

SQL_DATE                                            EQU     9
SQL_INTERVAL                                        EQU     10
SQL_TIME                                            EQU     10
SQL_TIMESTAMP                                       EQU     11
SQL_LONGVARCHAR                                     EQU     (-1)
SQL_BINARY                                          EQU     (-2)
SQL_VARBINARY                                       EQU     (-3)
SQL_LONGVARBINARY                                   EQU     (-4)
SQL_BIGINT                                          EQU     (-5)
SQL_TINYINT                                         EQU     (-6)
SQL_BIT                                             EQU     (-7)
SQL_GUID                                            EQU     (-11)

SQL_CODE_YEAR                                       EQU     1
SQL_CODE_MONTH                                      EQU     2
SQL_CODE_DAY                                        EQU     3
SQL_CODE_HOUR                                       EQU     4
SQL_CODE_MINUTE                                     EQU     5
SQL_CODE_SECOND                                     EQU     6
SQL_CODE_YEAR_TO_MONTH                              EQU     7
SQL_CODE_DAY_TO_HOUR                                EQU     8
SQL_CODE_DAY_TO_MINUTE                              EQU     9
SQL_CODE_DAY_TO_SECOND                              EQU     10
SQL_CODE_HOUR_TO_MINUTE                             EQU     11
SQL_CODE_HOUR_TO_SECOND                             EQU     12
SQL_CODE_MINUTE_TO_SECOND                           EQU     13

SQL_INTERVAL_YEAR                                   EQU     (100 + SQL_CODE_YEAR)
SQL_INTERVAL_MONTH                                  EQU     (100 + SQL_CODE_MONTH)
SQL_INTERVAL_DAY                                    EQU     (100 + SQL_CODE_DAY)
SQL_INTERVAL_HOUR                                   EQU     (100 + SQL_CODE_HOUR)
SQL_INTERVAL_MINUTE                                 EQU     (100 + SQL_CODE_MINUTE)
SQL_INTERVAL_SECOND                                 EQU     (100 + SQL_CODE_SECOND)
SQL_INTERVAL_YEAR_TO_MONTH                          EQU     (100 + SQL_CODE_YEAR_TO_MONTH)
SQL_INTERVAL_DAY_TO_HOUR                            EQU     (100 + SQL_CODE_DAY_TO_HOUR)
SQL_INTERVAL_DAY_TO_MINUTE                          EQU     (100 + SQL_CODE_DAY_TO_MINUTE)
SQL_INTERVAL_DAY_TO_SECOND                          EQU     (100 + SQL_CODE_DAY_TO_SECOND)
SQL_INTERVAL_HOUR_TO_MINUTE                         EQU     (100 + SQL_CODE_HOUR_TO_MINUTE)
SQL_INTERVAL_HOUR_TO_SECOND                         EQU     (100 + SQL_CODE_HOUR_TO_SECOND)
SQL_INTERVAL_MINUTE_TO_SECOND                       EQU     (100 + SQL_CODE_MINUTE_TO_SECOND)

SQL_UNICODE                                         EQU     SQL_WCHAR

SQL_UNICODE_VARCHAR                                 EQU     SQL_WVARCHAR
SQL_UNICODE_LONGVARCHAR                             EQU     SQL_WLONGVARCHAR
SQL_UNICODE_CHAR                                    EQU     SQL_WCHAR

SQL_C_CHAR                                          EQU     SQL_CHAR
SQL_C_LONG                                          EQU     SQL_INTEGER
SQL_C_SHORT                                         EQU     SQL_SMALLINT
SQL_C_FLOAT                                         EQU     SQL_REAL
SQL_C_DOUBLE                                        EQU     SQL_DOUBLE
SQL_C_NUMERIC                                       EQU     SQL_NUMERIC
SQL_C_DEFAULT                                       EQU     99

SQL_SIGNED_OFFSET                                   EQU     (-20)
SQL_UNSIGNED_OFFSET                                 EQU     (-22)

SQL_C_DATE                                          EQU     SQL_DATE
SQL_C_TIME                                          EQU     SQL_TIME
SQL_C_TIMESTAMP                                     EQU     SQL_TIMESTAMP
SQL_C_TYPE_DATE                                     EQU     SQL_TYPE_DATE
SQL_C_TYPE_TIME                                     EQU     SQL_TYPE_TIME
SQL_C_TYPE_TIMESTAMP                                EQU     SQL_TYPE_TIMESTAMP
SQL_C_INTERVAL_YEAR                                 EQU     SQL_INTERVAL_YEAR
SQL_C_INTERVAL_MONTH                                EQU     SQL_INTERVAL_MONTH
SQL_C_INTERVAL_DAY                                  EQU     SQL_INTERVAL_DAY
SQL_C_INTERVAL_HOUR                                 EQU     SQL_INTERVAL_HOUR
SQL_C_INTERVAL_MINUTE                               EQU     SQL_INTERVAL_MINUTE
SQL_C_INTERVAL_SECOND                               EQU     SQL_INTERVAL_SECOND
SQL_C_INTERVAL_YEAR_TO_MONTH                        EQU     SQL_INTERVAL_YEAR_TO_MONTH
SQL_C_INTERVAL_DAY_TO_HOUR                          EQU     SQL_INTERVAL_DAY_TO_HOUR
SQL_C_INTERVAL_DAY_TO_MINUTE                        EQU     SQL_INTERVAL_DAY_TO_MINUTE
SQL_C_INTERVAL_DAY_TO_SECOND                        EQU     SQL_INTERVAL_DAY_TO_SECOND
SQL_C_INTERVAL_HOUR_TO_MINUTE                       EQU     SQL_INTERVAL_HOUR_TO_MINUTE
SQL_C_INTERVAL_HOUR_TO_SECOND                       EQU     SQL_INTERVAL_HOUR_TO_SECOND
SQL_C_INTERVAL_MINUTE_TO_SECOND                     EQU     SQL_INTERVAL_MINUTE_TO_SECOND
SQL_C_BINARY                                        EQU     SQL_BINARY
SQL_C_BIT                                           EQU     SQL_BIT
SQL_C_SBIGINT                                       EQU     (SQL_BIGINT + SQL_SIGNED_OFFSET)
SQL_C_UBIGINT                                       EQU     (SQL_BIGINT + SQL_UNSIGNED_OFFSET)
SQL_C_TINYINT                                       EQU     SQL_TINYINT
SQL_C_SLONG                                         EQU     (SQL_C_LONG + SQL_SIGNED_OFFSET)
SQL_C_SSHORT                                        EQU     (SQL_C_SHORT + SQL_SIGNED_OFFSET)
SQL_C_STINYINT                                      EQU     (SQL_TINYINT + SQL_SIGNED_OFFSET)
SQL_C_ULONG                                         EQU     (SQL_C_LONG + SQL_UNSIGNED_OFFSET)
SQL_C_USHORT                                        EQU     (SQL_C_SHORT + SQL_UNSIGNED_OFFSET)
SQL_C_UTINYINT                                      EQU     (SQL_TINYINT + SQL_UNSIGNED_OFFSET)

IFDEF APP_WIN64
    SQL_C_BOOKMARK                                  EQU     SQL_C_UBIGINT
ELSE
    SQL_C_BOOKMARK                                  EQU     SQL_C_ULONG
ENDIF

SQL_C_GUID                                          EQU     GUID

SQL_TYPE_NULL                                       EQU     0
SQL_TYPE_MIN                                        EQU     SQL_BIT
SQL_TYPE_MAX                                        EQU     SQL_VARCHAR
SQL_C_VARBOOKMARK                                   EQU     SQL_C_BINARY
SQL_NO_ROW_NUMBER                                   EQU     (-1)
SQL_NO_COLUMN_NUMBER                                EQU     (-1)
SQL_ROW_NUMBER_UNKNOWN                              EQU     (-2)
SQL_COLUMN_NUMBER_UNKNOWN                           EQU     (-2)

SQL_DEFAULT_PARAM                                   EQU     (-5)
SQL_IGNORE                                          EQU     (-6)
SQL_COLUMN_IGNORE                                   EQU     SQL_IGNORE
SQL_LEN_DATA_AT_EXEC_OFFSET                         EQU     (-100)
SQL_LEN_BINARY_ATTR_OFFSET                          EQU     (-100)
SQL_PARAM_TYPE_DEFAULT                              EQU     SQL_PARAM_INPUT_OUTPUT
SQL_SETPARAM_VALUE_MAX                              EQU     (-1)

SQL_COLUMN_COUNT                                    EQU     0
SQL_COLUMN_NAME                                     EQU     1
SQL_COLUMN_TYPE                                     EQU     2
SQL_COLUMN_LENGTH                                   EQU     3
SQL_COLUMN_PRECISION                                EQU     4
SQL_COLUMN_SCALE                                    EQU     5
SQL_COLUMN_DISPLAY_SIZE                             EQU     6
SQL_COLUMN_NULLABLE                                 EQU     7
SQL_COLUMN_UNSIGNED                                 EQU     8
SQL_COLUMN_MONEY                                    EQU     9
SQL_COLUMN_UPDATABLE                                EQU     10
SQL_COLUMN_AUTO_INCREMENT                           EQU     11
SQL_COLUMN_CASE_SENSITIVE                           EQU     12
SQL_COLUMN_SEARCHABLE                               EQU     13
SQL_COLUMN_TYPE_NAME                                EQU     14
SQL_COLUMN_TABLE_NAME                               EQU     15
SQL_COLUMN_OWNER_NAME                               EQU     16
SQL_COLUMN_QUALIFIER_NAME                           EQU     17
SQL_COLUMN_LABEL                                    EQU     18

SQL_COLATT_OPT_MAX                                  EQU     SQL_COLUMN_LABEL
SQL_COLATT_OPT_MIN                                  EQU     SQL_COLUMN_COUNT

SQL_ATTR_READONLY                                   EQU     0
SQL_ATTR_WRITE                                      EQU     1
SQL_ATTR_READWRITE_UNKNOWN                          EQU     2

SQL_UNSEARCHABLE                                    EQU     0
SQL_LIKE_ONLY                                       EQU     1
SQL_ALL_EXCEPT_LIKE                                 EQU     2
SQL_SEARCHABLE                                      EQU     3
SQL_PRED_SEARCHABLE                                 EQU     SQL_SEARCHABLE

SQL_NO_TOTAL                                        EQU     (-4)

SQL_API_SQLALLOCHANDLESTD                           EQU     73
SQL_API_SQLBULKOPERATIONS                           EQU     24
SQL_API_SQLBINDPARAMETER                            EQU     72
SQL_API_SQLBROWSECONNECT                            EQU     55
SQL_API_SQLCOLATTRIBUTES                            EQU     6
SQL_API_SQLCOLUMNPRIVILEGES                         EQU     56
SQL_API_SQLDESCRIBEPARAM                            EQU     58
SQL_API_SQLDRIVERCONNECT                            EQU     41
SQL_API_SQLDRIVERS                                  EQU     71
SQL_API_SQLEXTENDEDFETCH                            EQU     59
SQL_API_SQLFOREIGNKEYS                              EQU     60
SQL_API_SQLMORERESULTS                              EQU     61
SQL_API_SQLNATIVESQL                                EQU     62
SQL_API_SQLNUMPARAMS                                EQU     63
SQL_API_SQLPARAMOPTIONS                             EQU     64
SQL_API_SQLPRIMARYKEYS                              EQU     65
SQL_API_SQLPROCEDURECOLUMNS                         EQU     66
SQL_API_SQLPROCEDURES                               EQU     67
SQL_API_SQLSETPOS                                   EQU     68
SQL_API_SQLSETSCROLLOPTIONS                         EQU     69
SQL_API_SQLTABLEPRIVILEGES                          EQU     70
SQL_API_ALL_FUNCTIONS                               EQU     0
SQL_API_LOADBYORDINAL                               EQU     199

SQL_API_ODBC3_ALL_FUNCTIONS                         EQU     999
SQL_API_ODBC3_ALL_FUNCTIONS_SIZE                    EQU     250

SQL_INFO_FIRST                                      EQU     0
SQL_ACTIVE_CONNECTIONS                              EQU     0
SQL_ACTIVE_STATEMENTS                               EQU     1
SQL_DRIVER_HDBC                                     EQU     3
SQL_DRIVER_HENV                                     EQU     4
SQL_DRIVER_HSTMT                                    EQU     5
SQL_DRIVER_NAME                                     EQU     6
SQL_DRIVER_VER                                      EQU     7
SQL_ODBC_API_CONFORMANCE                            EQU     9
SQL_ODBC_VER                                        EQU     10
SQL_ROW_UPDATES                                     EQU     11
SQL_ODBC_SAG_CLI_CONFORMANCE                        EQU     12
SQL_ODBC_SQL_CONFORMANCE                            EQU     15
SQL_PROCEDURES                                      EQU     21
SQL_CONCAT_NULL_BEHAVIOR                            EQU     22
SQL_CURSOR_ROLLBACK_BEHAVIOR                        EQU     24
SQL_EXPRESSIONS_IN_ORDERBY                          EQU     27
SQL_MAX_OWNER_NAME_LEN                              EQU     32
SQL_MAX_PROCEDURE_NAME_LEN                          EQU     33
SQL_MAX_QUALIFIER_NAME_LEN                          EQU     34
SQL_MULT_RESULT_SETS                                EQU     36
SQL_MULTIPLE_ACTIVE_TXN                             EQU     37
SQL_OUTER_JOINS                                     EQU     38
SQL_OWNER_TERM                                      EQU     39
SQL_PROCEDURE_TERM                                  EQU     40
SQL_QUALIFIER_NAME_SEPARATOR                        EQU     41
SQL_QUALIFIER_TERM                                  EQU     42
SQL_SCROLL_OPTIONS                                  EQU     44
SQL_TABLE_TERM                                      EQU     45
SQL_CONVERT_FUNCTIONS                               EQU     48
SQL_NUMERIC_FUNCTIONS                               EQU     49
SQL_STRING_FUNCTIONS                                EQU     50
SQL_SYSTEM_FUNCTIONS                                EQU     51
SQL_TIMEDATE_FUNCTIONS                              EQU     52
SQL_CONVERT_BIGINT                                  EQU     53
SQL_CONVERT_BINARY                                  EQU     54
SQL_CONVERT_BIT                                     EQU     55
SQL_CONVERT_CHAR                                    EQU     56
SQL_CONVERT_DATE                                    EQU     57
SQL_CONVERT_DECIMAL                                 EQU     58
SQL_CONVERT_DOUBLE                                  EQU     59
SQL_CONVERT_FLOAT                                   EQU     60
SQL_CONVERT_INTEGER                                 EQU     61
SQL_CONVERT_LONGVARCHAR                             EQU     62
SQL_CONVERT_NUMERIC                                 EQU     63
SQL_CONVERT_REAL                                    EQU     64
SQL_CONVERT_SMALLINT                                EQU     65
SQL_CONVERT_TIME                                    EQU     66
SQL_CONVERT_TIMESTAMP                               EQU     67
SQL_CONVERT_TINYINT                                 EQU     68
SQL_CONVERT_VARBINARY                               EQU     69
SQL_CONVERT_VARCHAR                                 EQU     70
SQL_CONVERT_LONGVARBINARY                           EQU     71
SQL_ODBC_SQL_OPT_IEF                                EQU     73
SQL_CORRELATION_NAME                                EQU     74
SQL_NON_NULLABLE_COLUMNS                            EQU     75
SQL_DRIVER_HLIB                                     EQU     76
SQL_DRIVER_ODBC_VER                                 EQU     77
SQL_LOCK_TYPES                                      EQU     78
SQL_POS_OPERATIONS                                  EQU     79
SQL_POSITIONED_STATEMENTS                           EQU     80
SQL_BOOKMARK_PERSISTENCE                            EQU     82
SQL_STATIC_SENSITIVITY                              EQU     83
SQL_FILE_USAGE                                      EQU     84
SQL_COLUMN_ALIAS                                    EQU     87
SQL_GROUP_BY                                        EQU     88
SQL_KEYWORDS                                        EQU     89
SQL_OWNER_USAGE                                     EQU     91
SQL_QUALIFIER_USAGE                                 EQU     92
SQL_QUOTED_IDENTIFIER_CASE                          EQU     93
SQL_SUBQUERIES                                      EQU     95
SQL_UNION                                           EQU     96
SQL_MAX_ROW_SIZE_INCLUDES_LONG                      EQU     103
SQL_MAX_CHAR_LITERAL_LEN                            EQU     108
SQL_TIMEDATE_ADD_INTERVALS                          EQU     109
SQL_TIMEDATE_DIFF_INTERVALS                         EQU     110
SQL_NEED_LONG_DATA_LEN                              EQU     111
SQL_MAX_BINARY_LITERAL_LEN                          EQU     112
SQL_LIKE_ESCAPE_CLAUSE                              EQU     113
SQL_QUALIFIER_LOCATION                              EQU     114

SQL_ACTIVE_ENVIRONMENTS                             EQU     116
SQL_ALTER_DOMAIN                                    EQU     117

SQL_SQL_CONFORMANCE                                 EQU     118
SQL_DATETIME_LITERALS                               EQU     119

SQL_ASYNC_MODE                                      EQU     10021
SQL_BATCH_ROW_COUNT                                 EQU     120
SQL_BATCH_SUPPORT                                   EQU     121
SQL_CATALOG_LOCATION                                EQU     SQL_QUALIFIER_LOCATION
SQL_CATALOG_NAME_SEPARATOR                          EQU     SQL_QUALIFIER_NAME_SEPARATOR
SQL_CATALOG_TERM                                    EQU     SQL_QUALIFIER_TERM
SQL_CATALOG_USAGE                                   EQU     SQL_QUALIFIER_USAGE
SQL_CONVERT_WCHAR                                   EQU     122
SQL_CONVERT_INTERVAL_DAY_TIME                       EQU     123
SQL_CONVERT_INTERVAL_YEAR_MONTH                     EQU     124
SQL_CONVERT_WLONGVARCHAR                            EQU     125
SQL_CONVERT_WVARCHAR                                EQU     126
SQL_CREATE_ASSERTION                                EQU     127
SQL_CREATE_CHARACTER_SET                            EQU     128
SQL_CREATE_COLLATION                                EQU     129
SQL_CREATE_DOMAIN                                   EQU     130
SQL_CREATE_SCHEMA                                   EQU     131
SQL_CREATE_TABLE                                    EQU     132
SQL_CREATE_TRANSLATION                              EQU     133
SQL_CREATE_VIEW                                     EQU     134
SQL_DRIVER_HDESC                                    EQU     135
SQL_DROP_ASSERTION                                  EQU     136
SQL_DROP_CHARACTER_SET                              EQU     137
SQL_DROP_COLLATION                                  EQU     138
SQL_DROP_DOMAIN                                     EQU     139
SQL_DROP_SCHEMA                                     EQU     140
SQL_DROP_TABLE                                      EQU     141
SQL_DROP_TRANSLATION                                EQU     142
SQL_DROP_VIEW                                       EQU     143
SQL_DYNAMIC_CURSOR_ATTRIBUTES1                      EQU     144
SQL_DYNAMIC_CURSOR_ATTRIBUTES2                      EQU     145
SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1                 EQU     146
SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2                 EQU     147
SQL_INDEX_KEYWORDS                                  EQU     148
SQL_INFO_SCHEMA_VIEWS                               EQU     149
SQL_KEYSET_CURSOR_ATTRIBUTES1                       EQU     150
SQL_KEYSET_CURSOR_ATTRIBUTES2                       EQU     151
SQL_MAX_ASYNC_CONCURRENT_STATEMENTS                 EQU     10022
SQL_ODBC_INTERFACE_CONFORMANCE                      EQU     152
SQL_PARAM_ARRAY_ROW_COUNTS                          EQU     153
SQL_PARAM_ARRAY_SELECTS                             EQU     154
SQL_SCHEMA_TERM                                     EQU     SQL_OWNER_TERM
SQL_SCHEMA_USAGE                                    EQU     SQL_OWNER_USAGE
SQL_SQL92_DATETIME_FUNCTIONS                        EQU     155
SQL_SQL92_FOREIGN_KEY_DELETE_RULE                   EQU     156
SQL_SQL92_FOREIGN_KEY_UPDATE_RULE                   EQU     157
SQL_SQL92_GRANT                                     EQU     158
SQL_SQL92_NUMERIC_VALUE_FUNCTIONS                   EQU     159
SQL_SQL92_PREDICATES                                EQU     160
SQL_SQL92_RELATIONAL_JOIN_OPERATORS                 EQU     161
SQL_SQL92_REVOKE                                    EQU     162
SQL_SQL92_ROW_VALUE_CONSTRUCTOR                     EQU     163
SQL_SQL92_STRING_FUNCTIONS                          EQU     164
SQL_SQL92_VALUE_EXPRESSIONS                         EQU     165
SQL_STANDARD_CLI_CONFORMANCE                        EQU     166
SQL_STATIC_CURSOR_ATTRIBUTES1                       EQU     167
SQL_STATIC_CURSOR_ATTRIBUTES2                       EQU     168

SQL_AGGREGATE_FUNCTIONS                             EQU     169
SQL_DDL_INDEX                                       EQU     170
SQL_DM_VER                                          EQU     171
SQL_INSERT_STATEMENT                                EQU     172
SQL_CONVERT_GUID                                    EQU     173
SQL_UNION_STATEMENT                                 EQU     SQL_UNION

SQL_DTC_TRANSITION_COST                             EQU     1750

SQL_AT_ADD_COLUMN_SINGLE                            EQU     00000020H
SQL_AT_ADD_COLUMN_DEFAULT                           EQU     00000040H
SQL_AT_ADD_COLUMN_COLLATION                         EQU     00000080H
SQL_AT_SET_COLUMN_DEFAULT                           EQU     00000100H
SQL_AT_DROP_COLUMN_DEFAULT                          EQU     00000200H
SQL_AT_DROP_COLUMN_CASCADE                          EQU     00000400H
SQL_AT_DROP_COLUMN_RESTRICT                         EQU     00000800H
SQL_AT_ADD_TABLE_CONSTRAINT                         EQU     00001000H
SQL_AT_DROP_TABLE_CONSTRAINT_CASCADE                EQU     00002000H
SQL_AT_DROP_TABLE_CONSTRAINT_RESTRICT               EQU     00004000H
SQL_AT_CONSTRAINT_NAME_DEFINITION                   EQU     00008000H
SQL_AT_CONSTRAINT_INITIALLY_DEFERRED                EQU     00010000H
SQL_AT_CONSTRAINT_INITIALLY_IMMEDIATE               EQU     00020000H
SQL_AT_CONSTRAINT_DEFERRABLE                        EQU     00040000H
SQL_AT_CONSTRAINT_NON_DEFERRABLE                    EQU     00080000H

SQL_CVT_CHAR                                        EQU     00000001H
SQL_CVT_NUMERIC                                     EQU     00000002H
SQL_CVT_DECIMAL                                     EQU     00000004H
SQL_CVT_INTEGER                                     EQU     00000008H
SQL_CVT_SMALLINT                                    EQU     00000010H
SQL_CVT_FLOAT                                       EQU     00000020H
SQL_CVT_REAL                                        EQU     00000040H
SQL_CVT_DOUBLE                                      EQU     00000080H
SQL_CVT_VARCHAR                                     EQU     00000100H
SQL_CVT_LONGVARCHAR                                 EQU     00000200H
SQL_CVT_BINARY                                      EQU     00000400H
SQL_CVT_VARBINARY                                   EQU     00000800H
SQL_CVT_BIT                                         EQU     00001000H
SQL_CVT_TINYINT                                     EQU     00002000H
SQL_CVT_BIGINT                                      EQU     00004000H
SQL_CVT_DATE                                        EQU     00008000H
SQL_CVT_TIME                                        EQU     00010000H
SQL_CVT_TIMESTAMP                                   EQU     00020000H
SQL_CVT_LONGVARBINARY                               EQU     00040000H
SQL_CVT_INTERVAL_YEAR_MONTH                         EQU     00080000H
SQL_CVT_INTERVAL_DAY_TIME                           EQU     00100000H
SQL_CVT_WCHAR                                       EQU     00200000H
SQL_CVT_WLONGVARCHAR                                EQU     00400000H
SQL_CVT_WVARCHAR                                    EQU     00800000H
SQL_CVT_GUID                                        EQU     01000000H

SQL_FN_CVT_CONVERT                                  EQU     00000001H
SQL_FN_CVT_CAST                                     EQU     00000002H

SQL_FN_STR_CONCAT                                   EQU     00000001H
SQL_FN_STR_INSERT                                   EQU     00000002H
SQL_FN_STR_LEFT                                     EQU     00000004H
SQL_FN_STR_LTRIM                                    EQU     00000008H
SQL_FN_STR_LENGTH                                   EQU     00000010H
SQL_FN_STR_LOCATE                                   EQU     00000020H
SQL_FN_STR_LCASE                                    EQU     00000040H
SQL_FN_STR_REPEAT                                   EQU     00000080H
SQL_FN_STR_REPLACE                                  EQU     00000100H
SQL_FN_STR_RIGHT                                    EQU     00000200H
SQL_FN_STR_RTRIM                                    EQU     00000400H
SQL_FN_STR_SUBSTRING                                EQU     00000800H
SQL_FN_STR_UCASE                                    EQU     00001000H
SQL_FN_STR_ASCII                                    EQU     00002000H
SQL_FN_STR_CHAR                                     EQU     00004000H
SQL_FN_STR_DIFFERENCE                               EQU     00008000H
SQL_FN_STR_LOCATE_2                                 EQU     00010000H
SQL_FN_STR_SOUNDEX                                  EQU     00020000H
SQL_FN_STR_SPACE                                    EQU     00040000H
SQL_FN_STR_BIT_LENGTH                               EQU     00080000H
SQL_FN_STR_CHAR_LENGTH                              EQU     00100000H
SQL_FN_STR_CHARACTER_LENGTH                         EQU     00200000H
SQL_FN_STR_OCTET_LENGTH                             EQU     00400000H
SQL_FN_STR_POSITION                                 EQU     00800000H

SQL_SSF_CONVERT                                     EQU     00000001H
SQL_SSF_LOWER                                       EQU     00000002H
SQL_SSF_UPPER                                       EQU     00000004H
SQL_SSF_SUBSTRING                                   EQU     00000008H
SQL_SSF_TRANSLATE                                   EQU     00000010H
SQL_SSF_TRIM_BOTH                                   EQU     00000020H
SQL_SSF_TRIM_LEADING                                EQU     00000040H
SQL_SSF_TRIM_TRAILING                               EQU     00000080H

SQL_FN_NUM_ABS                                      EQU     00000001H
SQL_FN_NUM_ACOS                                     EQU     00000002H
SQL_FN_NUM_ASIN                                     EQU     00000004H
SQL_FN_NUM_ATAN                                     EQU     00000008H
SQL_FN_NUM_ATAN2                                    EQU     00000010H
SQL_FN_NUM_CEILING                                  EQU     00000020H
SQL_FN_NUM_COS                                      EQU     00000040H
SQL_FN_NUM_COT                                      EQU     00000080H
SQL_FN_NUM_EXP                                      EQU     00000100H
SQL_FN_NUM_FLOOR                                    EQU     00000200H
SQL_FN_NUM_LOG                                      EQU     00000400H
SQL_FN_NUM_MOD                                      EQU     00000800H
SQL_FN_NUM_SIGN                                     EQU     00001000H
SQL_FN_NUM_SIN                                      EQU     00002000H
SQL_FN_NUM_SQRT                                     EQU     00004000H
SQL_FN_NUM_TAN                                      EQU     00008000H
SQL_FN_NUM_PI                                       EQU     00010000H
SQL_FN_NUM_RAND                                     EQU     00020000H
SQL_FN_NUM_DEGREES                                  EQU     00040000H
SQL_FN_NUM_LOG10                                    EQU     00080000H
SQL_FN_NUM_POWER                                    EQU     00100000H
SQL_FN_NUM_RADIANS                                  EQU     00200000H
SQL_FN_NUM_ROUND                                    EQU     00400000H
SQL_FN_NUM_TRUNCATE                                 EQU     00800000H

SQL_SNVF_BIT_LENGTH                                 EQU     00000001H
SQL_SNVF_CHAR_LENGTH                                EQU     00000002H
SQL_SNVF_CHARACTER_LENGTH                           EQU     00000004H
SQL_SNVF_EXTRACT                                    EQU     00000008H
SQL_SNVF_OCTET_LENGTH                               EQU     00000010H
SQL_SNVF_POSITION                                   EQU     00000020H

SQL_FN_TD_NOW                                       EQU     00000001H
SQL_FN_TD_CURDATE                                   EQU     00000002H
SQL_FN_TD_DAYOFMONTH                                EQU     00000004H
SQL_FN_TD_DAYOFWEEK                                 EQU     00000008H
SQL_FN_TD_DAYOFYEAR                                 EQU     00000010H
SQL_FN_TD_MONTH                                     EQU     00000020H
SQL_FN_TD_QUARTER                                   EQU     00000040H
SQL_FN_TD_WEEK                                      EQU     00000080H
SQL_FN_TD_YEAR                                      EQU     00000100H
SQL_FN_TD_CURTIME                                   EQU     00000200H
SQL_FN_TD_HOUR                                      EQU     00000400H
SQL_FN_TD_MINUTE                                    EQU     00000800H
SQL_FN_TD_SECOND                                    EQU     00001000H
SQL_FN_TD_TIMESTAMPADD                              EQU     00002000H
SQL_FN_TD_TIMESTAMPDIFF                             EQU     00004000H
SQL_FN_TD_DAYNAME                                   EQU     00008000H
SQL_FN_TD_MONTHNAME                                 EQU     00010000H
SQL_FN_TD_CURRENT_DATE                              EQU     00020000H
SQL_FN_TD_CURRENT_TIME                              EQU     00040000H
SQL_FN_TD_CURRENT_TIMESTAMP                         EQU     00080000H
SQL_FN_TD_EXTRACT                                   EQU     00100000H

SQL_SDF_CURRENT_DATE                                EQU     00000001H
SQL_SDF_CURRENT_TIME                                EQU     00000002H
SQL_SDF_CURRENT_TIMESTAMP                           EQU     00000004H

SQL_FN_SYS_USERNAME                                 EQU     00000001H
SQL_FN_SYS_DBNAME                                   EQU     00000002H
SQL_FN_SYS_IFNULL                                   EQU     00000004H

SQL_FN_TSI_FRAC_SECOND                              EQU     00000001H
SQL_FN_TSI_SECOND                                   EQU     00000002H
SQL_FN_TSI_MINUTE                                   EQU     00000004H
SQL_FN_TSI_HOUR                                     EQU     00000008H
SQL_FN_TSI_DAY                                      EQU     00000010H
SQL_FN_TSI_WEEK                                     EQU     00000020H
SQL_FN_TSI_MONTH                                    EQU     00000040H
SQL_FN_TSI_QUARTER                                  EQU     00000080H
SQL_FN_TSI_YEAR                                     EQU     00000100H

SQL_CA1_NEXT                                        EQU     00000001H
SQL_CA1_ABSOLUTE                                    EQU     00000002H
SQL_CA1_RELATIVE                                    EQU     00000004H
SQL_CA1_BOOKMARK                                    EQU     00000008H
SQL_CA1_LOCK_NO_CHANGE                              EQU     00000040H
SQL_CA1_LOCK_EXCLUSIVE                              EQU     00000080H
SQL_CA1_LOCK_UNLOCK                                 EQU     00000100H
SQL_CA1_POS_POSITION                                EQU     00000200H
SQL_CA1_POS_UPDATE                                  EQU     00000400H
SQL_CA1_POS_DELETE                                  EQU     00000800H
SQL_CA1_POS_REFRESH                                 EQU     00001000H
SQL_CA1_POSITIONED_UPDATE                           EQU     00002000H
SQL_CA1_POSITIONED_DELETE                           EQU     00004000H
SQL_CA1_SELECT_FOR_UPDATE                           EQU     00008000H
SQL_CA1_BULK_ADD                                    EQU     00010000H
SQL_CA1_BULK_UPDATE_BY_BOOKMARK                     EQU     00020000H
SQL_CA1_BULK_DELETE_BY_BOOKMARK                     EQU     00040000H
SQL_CA1_BULK_FETCH_BY_BOOKMARK                      EQU     00080000H

SQL_CA2_READ_ONLY_CONCURRENCY                       EQU     00000001H
SQL_CA2_LOCK_CONCURRENCY                            EQU     00000002H
SQL_CA2_OPT_ROWVER_CONCURRENCY                      EQU     00000004H
SQL_CA2_OPT_VALUES_CONCURRENCY                      EQU     00000008H
SQL_CA2_SENSITIVITY_ADDITIONS                       EQU     00000010H
SQL_CA2_SENSITIVITY_DELETIONS                       EQU     00000020H
SQL_CA2_SENSITIVITY_UPDATES                         EQU     00000040H
SQL_CA2_MAX_ROWS_SELECT                             EQU     00000080H
SQL_CA2_MAX_ROWS_INSERT                             EQU     00000100H
SQL_CA2_MAX_ROWS_DELETE                             EQU     00000200H
SQL_CA2_MAX_ROWS_UPDATE                             EQU     00000400H
SQL_CA2_MAX_ROWS_CATALOG                            EQU     00000800H
SQL_CA2_MAX_ROWS_AFFECTS_ALL                        EQU     (SQL_CA2_MAX_ROWS_SELECT OR SQL_CA2_MAX_ROWS_INSERT OR SQL_CA2_MAX_ROWS_DELETE OR SQL_CA2_MAX_ROWS_UPDATE OR SQL_CA2_MAX_ROWS_CATALOG)
SQL_CA2_CRC_EXACT                                   EQU     00001000H
SQL_CA2_CRC_APPROXIMATE                             EQU     00002000H
SQL_CA2_SIMULATE_NON_UNIQUE                         EQU     00004000H
SQL_CA2_SIMULATE_TRY_UNIQUE                         EQU     00008000H
SQL_CA2_SIMULATE_UNIQUE                             EQU     00010000H

SQL_OAC_NONE                                        EQU     0000H
SQL_OAC_LEVEL1                                      EQU     0001H
SQL_OAC_LEVEL2                                      EQU     0002H

SQL_OSCC_NOT_COMPLIANT                              EQU     0000H
SQL_OSCC_COMPLIANT                                  EQU     0001H

SQL_OSC_MINIMUM                                     EQU     0000H
SQL_OSC_CORE                                        EQU     0001H
SQL_OSC_EXTENDED                                    EQU     0002H

SQL_CB_NULL                                         EQU     0000H
SQL_CB_NON_NULL                                     EQU     0001H

SQL_SO_FORWARD_ONLY                                 EQU     00000001H
SQL_SO_KEYSET_DRIVEN                                EQU     00000002H
SQL_SO_DYNAMIC                                      EQU     00000004H
SQL_SO_MIXED                                        EQU     00000008H
SQL_SO_STATIC                                       EQU     00000010H

SQL_FD_FETCH_BOOKMARK                               EQU     00000080H

SQL_CN_NONE                                         EQU     0000H
SQL_CN_DIFFERENT                                    EQU     0001H
SQL_CN_ANY                                          EQU     0002H

SQL_NNC_NULL                                        EQU     0000H
SQL_NNC_NON_NULL                                    EQU     0001H

SQL_NC_START                                        EQU     0002H
SQL_NC_END                                          EQU     0004H

SQL_FILE_NOT_SUPPORTED                              EQU     0000H
SQL_FILE_TABLE                                      EQU     0001H
SQL_FILE_QUALIFIER                                  EQU     0002H
SQL_FILE_CATALOG                                    EQU     SQL_FILE_QUALIFIER

SQL_GD_BLOCK                                        EQU     00000004H
SQL_GD_BOUND                                        EQU     00000008H

SQL_PS_POSITIONED_DELETE                            EQU     00000001H
SQL_PS_POSITIONED_UPDATE                            EQU     00000002H
SQL_PS_SELECT_FOR_UPDATE                            EQU     00000004H

SQL_GB_NOT_SUPPORTED                                EQU     0000H
SQL_GB_GROUP_BY_EQUALS_SELECT                       EQU     0001H
SQL_GB_GROUP_BY_CONTAINS_SELECT                     EQU     0002H
SQL_GB_NO_RELATION                                  EQU     0003H
SQL_GB_COLLATE                                      EQU     0004H

SQL_OU_DML_STATEMENTS                               EQU     00000001H
SQL_OU_PROCEDURE_INVOCATION                         EQU     00000002H
SQL_OU_TABLE_DEFINITION                             EQU     00000004H
SQL_OU_INDEX_DEFINITION                             EQU     00000008H
SQL_OU_PRIVILEGE_DEFINITION                         EQU     00000010H

SQL_SU_DML_STATEMENTS                               EQU     SQL_OU_DML_STATEMENTS
SQL_SU_PROCEDURE_INVOCATION                         EQU     SQL_OU_PROCEDURE_INVOCATION
SQL_SU_TABLE_DEFINITION                             EQU     SQL_OU_TABLE_DEFINITION
SQL_SU_INDEX_DEFINITION                             EQU     SQL_OU_INDEX_DEFINITION
SQL_SU_PRIVILEGE_DEFINITION                         EQU     SQL_OU_PRIVILEGE_DEFINITION

SQL_QU_DML_STATEMENTS                               EQU     00000001H
SQL_QU_PROCEDURE_INVOCATION                         EQU     00000002H
SQL_QU_TABLE_DEFINITION                             EQU     00000004H
SQL_QU_INDEX_DEFINITION                             EQU     00000008H
SQL_QU_PRIVILEGE_DEFINITION                         EQU     00000010H

SQL_CU_DML_STATEMENTS                               EQU     SQL_QU_DML_STATEMENTS
SQL_CU_PROCEDURE_INVOCATION                         EQU     SQL_QU_PROCEDURE_INVOCATION
SQL_CU_TABLE_DEFINITION                             EQU     SQL_QU_TABLE_DEFINITION
SQL_CU_INDEX_DEFINITION                             EQU     SQL_QU_INDEX_DEFINITION
SQL_CU_PRIVILEGE_DEFINITION                         EQU     SQL_QU_PRIVILEGE_DEFINITION

SQL_SQ_COMPARISON                                   EQU     00000001H
SQL_SQ_EXISTS                                       EQU     00000002H
SQL_SQ_IN                                           EQU     00000004H
SQL_SQ_QUANTIFIED                                   EQU     00000008H
SQL_SQ_CORRELATED_SUBQUERIES                        EQU     00000010H

SQL_U_UNION                                         EQU     00000001H
SQL_U_UNION_ALL                                     EQU     00000002H

SQL_BP_CLOSE                                        EQU     00000001H
SQL_BP_DELETE                                       EQU     00000002H
SQL_BP_DROP                                         EQU     00000004H
SQL_BP_TRANSACTION                                  EQU     00000008H
SQL_BP_UPDATE                                       EQU     00000010H
SQL_BP_OTHER_HSTMT                                  EQU     00000020H
SQL_BP_SCROLL                                       EQU     00000040H

SQL_SS_ADDITIONS                                    EQU     00000001H
SQL_SS_DELETIONS                                    EQU     00000002H
SQL_SS_UPDATES                                      EQU     00000004H

SQL_CV_CREATE_VIEW                                  EQU     00000001H
SQL_CV_CHECK_OPTION                                 EQU     00000002H
SQL_CV_CASCADED                                     EQU     00000004H
SQL_CV_LOCAL                                        EQU     00000008H

SQL_LCK_NO_CHANGE                                   EQU     00000001H
SQL_LCK_EXCLUSIVE                                   EQU     00000002H
SQL_LCK_UNLOCK                                      EQU     00000004H

SQL_POS_POSITION                                    EQU     00000001H
SQL_POS_REFRESH                                     EQU     00000002H
SQL_POS_UPDATE                                      EQU     00000004H
SQL_POS_DELETE                                      EQU     00000008H
SQL_POS_ADD                                         EQU     00000010LH

SQL_QL_START                                        EQU     0001H
SQL_QL_END                                          EQU     0002H

SQL_AF_AVG                                          EQU     00000001H
SQL_AF_COUNT                                        EQU     00000002H
SQL_AF_MAX                                          EQU     00000004H
SQL_AF_MIN                                          EQU     00000008H
SQL_AF_SUM                                          EQU     00000010H
SQL_AF_DISTINCT                                     EQU     00000020H
SQL_AF_ALL                                          EQU     00000040H

SQL_SC_SQL92_ENTRY                                  EQU     00000001H
SQL_SC_FIPS127_2_TRANSITIONAL                       EQU     00000002H
SQL_SC_SQL92_INTERMEDIATE                           EQU     00000004H
SQL_SC_SQL92_FULL                                   EQU     00000008H

SQL_DL_SQL92_DATE                                   EQU     00000001H
SQL_DL_SQL92_TIME                                   EQU     00000002H
SQL_DL_SQL92_TIMESTAMP                              EQU     00000004H
SQL_DL_SQL92_INTERVAL_YEAR                          EQU     00000008H
SQL_DL_SQL92_INTERVAL_MONTH                         EQU     00000010H
SQL_DL_SQL92_INTERVAL_DAY                           EQU     00000020H
SQL_DL_SQL92_INTERVAL_HOUR                          EQU     00000040H
SQL_DL_SQL92_INTERVAL_MINUTE                        EQU     00000080H
SQL_DL_SQL92_INTERVAL_SECOND                        EQU     00000100H
SQL_DL_SQL92_INTERVAL_YEAR_TO_MONTH                 EQU     00000200H
SQL_DL_SQL92_INTERVAL_DAY_TO_HOUR                   EQU     00000400H
SQL_DL_SQL92_INTERVAL_DAY_TO_MINUTE                 EQU     00000800H
SQL_DL_SQL92_INTERVAL_DAY_TO_SECOND                 EQU     00001000H
SQL_DL_SQL92_INTERVAL_HOUR_TO_MINUTE                EQU     00002000H
SQL_DL_SQL92_INTERVAL_HOUR_TO_SECOND                EQU     00004000H
SQL_DL_SQL92_INTERVAL_MINUTE_TO_SECOND              EQU     00008000H

SQL_CL_START                                        EQU     SQL_QL_START
SQL_CL_END                                          EQU     SQL_QL_END

SQL_BRC_PROCEDURES                                  EQU     0000001H
SQL_BRC_EXPLICIT                                    EQU     0000002H
SQL_BRC_ROLLED_UP                                   EQU     0000004H

SQL_BS_SELECT_EXPLICIT                              EQU     00000001H
SQL_BS_ROW_COUNT_EXPLICIT                           EQU     00000002H
SQL_BS_SELECT_PROC                                  EQU     00000004H
SQL_BS_ROW_COUNT_PROC                               EQU     00000008H

SQL_PARC_BATCH                                      EQU     1
SQL_PARC_NO_BATCH                                   EQU     2

SQL_PAS_BATCH                                       EQU     1
SQL_PAS_NO_BATCH                                    EQU     2
SQL_PAS_NO_SELECT                                   EQU     3

SQL_IK_NONE                                         EQU     00000000H
SQL_IK_ASC                                          EQU     00000001H
SQL_IK_DESC                                         EQU     00000002H
SQL_IK_ALL                                          EQU     (SQL_IK_ASC OR SQL_IK_DESC)

SQL_ISV_ASSERTIONS                                  EQU     00000001H
SQL_ISV_CHARACTER_SETS                              EQU     00000002H
SQL_ISV_CHECK_CONSTRAINTS                           EQU     00000004H
SQL_ISV_COLLATIONS                                  EQU     00000008H
SQL_ISV_COLUMN_DOMAIN_USAGE                         EQU     00000010H
SQL_ISV_COLUMN_PRIVILEGES                           EQU     00000020H
SQL_ISV_COLUMNS                                     EQU     00000040H
SQL_ISV_CONSTRAINT_COLUMN_USAGE                     EQU     00000080H
SQL_ISV_CONSTRAINT_TABLE_USAGE                      EQU     00000100H
SQL_ISV_DOMAIN_CONSTRAINTS                          EQU     00000200H
SQL_ISV_DOMAINS                                     EQU     00000400H
SQL_ISV_KEY_COLUMN_USAGE                            EQU     00000800H
SQL_ISV_REFERENTIAL_CONSTRAINTS                     EQU     00001000H
SQL_ISV_SCHEMATA                                    EQU     00002000H
SQL_ISV_SQL_LANGUAGES                               EQU     00004000H
SQL_ISV_TABLE_CONSTRAINTS                           EQU     00008000H
SQL_ISV_TABLE_PRIVILEGES                            EQU     00010000H
SQL_ISV_TABLES                                      EQU     00020000H
SQL_ISV_TRANSLATIONS                                EQU     00040000H
SQL_ISV_USAGE_PRIVILEGES                            EQU     00080000H
SQL_ISV_VIEW_COLUMN_USAGE                           EQU     00100000H
SQL_ISV_VIEW_TABLE_USAGE                            EQU     00200000H
SQL_ISV_VIEWS                                       EQU     00400000H

SQL_AM_NONE                                         EQU     0
SQL_AM_CONNECTION                                   EQU     1
SQL_AM_STATEMENT                                    EQU     2

SQL_AD_CONSTRAINT_NAME_DEFINITION                   EQU     00000001H
SQL_AD_ADD_DOMAIN_CONSTRAINT                        EQU     00000002H
SQL_AD_DROP_DOMAIN_CONSTRAINT                       EQU     00000004H
SQL_AD_ADD_DOMAIN_DEFAULT                           EQU     00000008H
SQL_AD_DROP_DOMAIN_DEFAULT                          EQU     00000010H
SQL_AD_ADD_CONSTRAINT_INITIALLY_DEFERRED            EQU     00000020H
SQL_AD_ADD_CONSTRAINT_INITIALLY_IMMEDIATE           EQU     00000040H
SQL_AD_ADD_CONSTRAINT_DEFERRABLE                    EQU     00000080H
SQL_AD_ADD_CONSTRAINT_NON_DEFERRABLE                EQU     00000100H

SQL_CS_CREATE_SCHEMA                                EQU     00000001H
SQL_CS_AUTHORIZATION                                EQU     00000002H
SQL_CS_DEFAULT_CHARACTER_SET                        EQU     00000004H

SQL_CTR_CREATE_TRANSLATION                          EQU     00000001H

SQL_CA_CREATE_ASSERTION                             EQU     00000001H
SQL_CA_CONSTRAINT_INITIALLY_DEFERRED                EQU     00000010H
SQL_CA_CONSTRAINT_INITIALLY_IMMEDIATE               EQU     00000020H
SQL_CA_CONSTRAINT_DEFERRABLE                        EQU     00000040H
SQL_CA_CONSTRAINT_NON_DEFERRABLE                    EQU     00000080H

SQL_CCS_CREATE_CHARACTER_SET                        EQU     00000001H
SQL_CCS_COLLATE_CLAUSE                              EQU     00000002H
SQL_CCS_LIMITED_COLLATION                           EQU     00000004H

SQL_CCOL_CREATE_COLLATION                           EQU     00000001H

SQL_CDO_CREATE_DOMAIN                               EQU     00000001H
SQL_CDO_DEFAULT                                     EQU     00000002H
SQL_CDO_CONSTRAINT                                  EQU     00000004H
SQL_CDO_COLLATION                                   EQU     00000008H
SQL_CDO_CONSTRAINT_NAME_DEFINITION                  EQU     00000010H
SQL_CDO_CONSTRAINT_INITIALLY_DEFERRED               EQU     00000020H
SQL_CDO_CONSTRAINT_INITIALLY_IMMEDIATE              EQU     00000040H
SQL_CDO_CONSTRAINT_DEFERRABLE                       EQU     00000080H
SQL_CDO_CONSTRAINT_NON_DEFERRABLE                   EQU     00000100H

SQL_CT_CREATE_TABLE                                 EQU     00000001H
SQL_CT_COMMIT_PRESERVE                              EQU     00000002H
SQL_CT_COMMIT_DELETE                                EQU     00000004H
SQL_CT_GLOBAL_TEMPORARY                             EQU     00000008H
SQL_CT_LOCAL_TEMPORARY                              EQU     00000010H
SQL_CT_CONSTRAINT_INITIALLY_DEFERRED                EQU     00000020H
SQL_CT_CONSTRAINT_INITIALLY_IMMEDIATE               EQU     00000040H
SQL_CT_CONSTRAINT_DEFERRABLE                        EQU     00000080H
SQL_CT_CONSTRAINT_NON_DEFERRABLE                    EQU     00000100H
SQL_CT_COLUMN_CONSTRAINT                            EQU     00000200H
SQL_CT_COLUMN_DEFAULT                               EQU     00000400H
SQL_CT_COLUMN_COLLATION                             EQU     00000800H
SQL_CT_TABLE_CONSTRAINT                             EQU     00001000H
SQL_CT_CONSTRAINT_NAME_DEFINITION                   EQU     00002000H

SQL_DI_CREATE_INDEX                                 EQU     00000001H
SQL_DI_DROP_INDEX                                   EQU     00000002H

SQL_DC_DROP_COLLATION                               EQU     00000001H

SQL_DD_DROP_DOMAIN                                  EQU     00000001H
SQL_DD_RESTRICT                                     EQU     00000002H
SQL_DD_CASCADE                                      EQU     00000004H

SQL_DS_DROP_SCHEMA                                  EQU     00000001H
SQL_DS_RESTRICT                                     EQU     00000002H
SQL_DS_CASCADE                                      EQU     00000004H

SQL_DCS_DROP_CHARACTER_SET                          EQU     00000001H

SQL_DA_DROP_ASSERTION                               EQU     00000001H

SQL_DT_DROP_TABLE                                   EQU     00000001H
SQL_DT_RESTRICT                                     EQU     00000002H
SQL_DT_CASCADE                                      EQU     00000004H

SQL_DTR_DROP_TRANSLATION                            EQU     00000001H

SQL_DV_DROP_VIEW                                    EQU     00000001H
SQL_DV_RESTRICT                                     EQU     00000002H
SQL_DV_CASCADE                                      EQU     00000004H

SQL_IS_INSERT_LITERALS                              EQU     00000001H
SQL_IS_INSERT_SEARCHED                              EQU     00000002H
SQL_IS_SELECT_INTO                                  EQU     00000004H

SQL_OIC_CORE                                        EQU     1
SQL_OIC_LEVEL1                                      EQU     2
SQL_OIC_LEVEL2                                      EQU     3

SQL_SFKD_CASCADE                                    EQU     00000001H
SQL_SFKD_NO_ACTION                                  EQU     00000002H
SQL_SFKD_SET_DEFAULT                                EQU     00000004H
SQL_SFKD_SET_NULL                                   EQU     00000008H

SQL_SFKU_CASCADE                                    EQU     00000001H
SQL_SFKU_NO_ACTION                                  EQU     00000002H
SQL_SFKU_SET_DEFAULT                                EQU     00000004H
SQL_SFKU_SET_NULL                                   EQU     00000008H

SQL_SG_USAGE_ON_DOMAIN                              EQU     00000001H
SQL_SG_USAGE_ON_CHARACTER_SET                       EQU     00000002H
SQL_SG_USAGE_ON_COLLATION                           EQU     00000004H
SQL_SG_USAGE_ON_TRANSLATION                         EQU     00000008H
SQL_SG_WITH_GRANT_OPTION                            EQU     00000010H
SQL_SG_DELETE_TABLE                                 EQU     00000020H
SQL_SG_INSERT_TABLE                                 EQU     00000040H
SQL_SG_INSERT_COLUMN                                EQU     00000080H
SQL_SG_REFERENCES_TABLE                             EQU     00000100H
SQL_SG_REFERENCES_COLUMN                            EQU     00000200H
SQL_SG_SELECT_TABLE                                 EQU     00000400H
SQL_SG_UPDATE_TABLE                                 EQU     00000800H
SQL_SG_UPDATE_COLUMN                                EQU     00001000H

SQL_SP_EXISTS                                       EQU     00000001H
SQL_SP_ISNOTNULL                                    EQU     00000002H
SQL_SP_ISNULL                                       EQU     00000004H
SQL_SP_MATCH_FULL                                   EQU     00000008H
SQL_SP_MATCH_PARTIAL                                EQU     00000010H
SQL_SP_MATCH_UNIQUE_FULL                            EQU     00000020H
SQL_SP_MATCH_UNIQUE_PARTIAL                         EQU     00000040H
SQL_SP_OVERLAPS                                     EQU     00000080H
SQL_SP_UNIQUE                                       EQU     00000100H
SQL_SP_LIKE                                         EQU     00000200H
SQL_SP_IN                                           EQU     00000400H
SQL_SP_BETWEEN                                      EQU     00000800H
SQL_SP_COMPARISON                                   EQU     00001000H
SQL_SP_QUANTIFIED_COMPARISON                        EQU     00002000H

SQL_SRJO_CORRESPONDING_CLAUSE                       EQU     00000001H
SQL_SRJO_CROSS_JOIN                                 EQU     00000002H
SQL_SRJO_EXCEPT_JOIN                                EQU     00000004H
SQL_SRJO_FULL_OUTER_JOIN                            EQU     00000008H
SQL_SRJO_INNER_JOIN                                 EQU     00000010H
SQL_SRJO_INTERSECT_JOIN                             EQU     00000020H
SQL_SRJO_LEFT_OUTER_JOIN                            EQU     00000040H
SQL_SRJO_NATURAL_JOIN                               EQU     00000080H
SQL_SRJO_RIGHT_OUTER_JOIN                           EQU     00000100H
SQL_SRJO_UNION_JOIN                                 EQU     00000200H

SQL_SR_USAGE_ON_DOMAIN                              EQU     00000001H
SQL_SR_USAGE_ON_CHARACTER_SET                       EQU     00000002H
SQL_SR_USAGE_ON_COLLATION                           EQU     00000004H
SQL_SR_USAGE_ON_TRANSLATION                         EQU     00000008H
SQL_SR_GRANT_OPTION_FOR                             EQU     00000010H
SQL_SR_CASCADE                                      EQU     00000020H
SQL_SR_RESTRICT                                     EQU     00000040H
SQL_SR_DELETE_TABLE                                 EQU     00000080H
SQL_SR_INSERT_TABLE                                 EQU     00000100H
SQL_SR_INSERT_COLUMN                                EQU     00000200H
SQL_SR_REFERENCES_TABLE                             EQU     00000400H
SQL_SR_REFERENCES_COLUMN                            EQU     00000800H
SQL_SR_SELECT_TABLE                                 EQU     00001000H
SQL_SR_UPDATE_TABLE                                 EQU     00002000H
SQL_SR_UPDATE_COLUMN                                EQU     00004000H

SQL_SRVC_VALUE_EXPRESSION                           EQU     00000001H
SQL_SRVC_NULL                                       EQU     00000002H
SQL_SRVC_DEFAULT                                    EQU     00000004H
SQL_SRVC_ROW_SUBQUERY                               EQU     00000008H

SQL_SVE_CASE                                        EQU     00000001H
SQL_SVE_CAST                                        EQU     00000002H
SQL_SVE_COALESCE                                    EQU     00000004H
SQL_SVE_NULLIF                                      EQU     00000008H

SQL_SCC_XOPEN_CLI_VERSION1                          EQU     00000001H
SQL_SCC_ISO92_CLI                                   EQU     00000002H

SQL_US_UNION                                        EQU     SQL_U_UNION
SQL_US_UNION_ALL                                    EQU     SQL_U_UNION_ALL

SQL_DTC_ENLIST_EXPENSIVE                            EQU     00000001H
SQL_DTC_UNENLIST_EXPENSIVE                          EQU     00000002H

SQL_FETCH_FIRST_USER                                EQU     31
SQL_FETCH_FIRST_SYSTEM                              EQU     32

SQL_ENTIRE_ROWSET                                   EQU     0

SQL_POSITION                                        EQU     0
SQL_REFRESH                                         EQU     1
SQL_UPDATE                                          EQU     2
SQL_DELETE                                          EQU     3

SQL_ADD                                             EQU     4
SQL_SETPOS_MAX_OPTION_VALUE                         EQU     SQL_ADD
SQL_UPDATE_BY_BOOKMARK                              EQU     5
SQL_DELETE_BY_BOOKMARK                              EQU     6
SQL_FETCH_BY_BOOKMARK                               EQU     7

SQL_LOCK_NO_CHANGE                                  EQU     0
SQL_LOCK_EXCLUSIVE                                  EQU     1
SQL_LOCK_UNLOCK                                     EQU     2

SQL_SETPOS_MAX_LOCK_VALUE                           EQU     SQL_LOCK_UNLOCK

SQL_BEST_ROWID                                      EQU     1
SQL_ROWVER                                          EQU     2

SQL_PC_NOT_PSEUDO                                   EQU     1

SQL_QUICK                                           EQU     0
SQL_ENSURE                                          EQU     1

SQL_TABLE_STAT                                      EQU     0

SQL_ALL_CATALOGS                                    EQU     A("%")
SQL_ALL_SCHEMAS                                     EQU     A("%")
SQL_ALL_TABLE_TYPES                                 EQU     A("%")

SQL_DRIVER_NOPROMPT                                 EQU     0
SQL_DRIVER_COMPLETE                                 EQU     1
SQL_DRIVER_PROMPT                                   EQU     2
SQL_DRIVER_COMPLETE_REQUIRED                        EQU     3

SQL_FETCH_BOOKMARK                                  EQU     8

SQL_ROW_SUCCESS                                     EQU     0
SQL_ROW_DELETED                                     EQU     1
SQL_ROW_UPDATED                                     EQU     2
SQL_ROW_NOROW                                       EQU     3
SQL_ROW_ADDED                                       EQU     4
SQL_ROW_ERROR                                       EQU     5
SQL_ROW_SUCCESS_WITH_INFO                           EQU     6
SQL_ROW_PROCEED                                     EQU     0
SQL_ROW_IGNORE                                      EQU     1

SQL_PARAM_SUCCESS                                   EQU     0
SQL_PARAM_SUCCESS_WITH_INFO                         EQU     6
SQL_PARAM_ERROR                                     EQU     5
SQL_PARAM_UNUSED                                    EQU     7
SQL_PARAM_DIAG_UNAVAILABLE                          EQU     1

SQL_PARAM_PROCEED                                   EQU     0
SQL_PARAM_IGNORE                                    EQU     1

SQL_CASCADE                                         EQU     0
SQL_RESTRICT                                        EQU     1
SQL_SET_NULL                                        EQU     2
SQL_NO_ACTION                                       EQU     3
SQL_SET_DEFAULT                                     EQU     4

SQL_INITIALLY_DEFERRED                              EQU     5
SQL_INITIALLY_IMMEDIATE                             EQU     6
SQL_NOT_DEFERRABLE                                  EQU     7


SQL_PARAM_TYPE_UNKNOWN                              EQU     0
SQL_PARAM_INPUT                                     EQU     1
SQL_PARAM_INPUT_OUTPUT                              EQU     2
SQL_RESULT_COL                                      EQU     3
SQL_PARAM_OUTPUT                                    EQU     4
SQL_RETURN_VALUE                                    EQU     5

SQL_PT_UNKNOWN                                      EQU     0
SQL_PT_PROCEDURE                                    EQU     1
SQL_PT_FUNCTION                                     EQU     2

SQL_YEAR                                            EQU     SQL_CODE_YEAR
SQL_MONTH                                           EQU     SQL_CODE_MONTH
SQL_DAY                                             EQU     SQL_CODE_DAY
SQL_HOUR                                            EQU     SQL_CODE_HOUR
SQL_MINUTE                                          EQU     SQL_CODE_MINUTE
SQL_SECOND                                          EQU     SQL_CODE_SECOND
SQL_YEAR_TO_MONTH                                   EQU     SQL_CODE_YEAR_TO_MONTH
SQL_DAY_TO_HOUR                                     EQU     SQL_CODE_DAY_TO_HOUR
SQL_DAY_TO_MINUTE                                   EQU     SQL_CODE_DAY_TO_MINUTE
SQL_DAY_TO_SECOND                                   EQU     SQL_CODE_DAY_TO_SECOND
SQL_HOUR_TO_MINUTE                                  EQU     SQL_CODE_HOUR_TO_MINUTE
SQL_HOUR_TO_SECOND                                  EQU     SQL_CODE_HOUR_TO_SECOND
SQL_MINUTE_TO_SECOND                                EQU     SQL_CODE_MINUTE_TO_SECOND

SQL_DATABASE_NAME                                   EQU     16
SQL_FD_FETCH_PREV                                   EQU     SQL_FD_FETCH_PRIOR
SQL_FETCH_PREV                                      EQU     SQL_FETCH_PRIOR
SQL_CONCUR_TIMESTAMP                                EQU     SQL_CONCUR_ROWVER
SQL_SCCO_OPT_TIMESTAMP                              EQU     SQL_SCCO_OPT_ROWVER
SQL_CC_DELETE                                       EQU     SQL_CB_DELETE
SQL_CR_DELETE                                       EQU     SQL_CB_DELETE
SQL_CC_CLOSE                                        EQU     SQL_CB_CLOSE
SQL_CR_CLOSE                                        EQU     SQL_CB_CLOSE
SQL_CC_PRESERVE                                     EQU     SQL_CB_PRESERVE
SQL_CR_PRESERVE                                     EQU     SQL_CB_PRESERVE
SQL_SCROLL_FORWARD_ONLY                             EQU     0
SQL_SCROLL_KEYSET_DRIVEN                            EQU     (-1)
SQL_SCROLL_DYNAMIC                                  EQU     (-2)
SQL_SCROLL_STATIC                                   EQU     (-3)

TRACE_VERSION                                       EQU     1000

TRACE_ON                                            EQU     00000001H
TRACE_VS_EVENT_ON                                   EQU     00000002H

ODBC_VS_FLAG_UNICODE_ARG                            EQU     00000001H
ODBC_VS_FLAG_UNICODE_COR                            EQU     00000002H
ODBC_VS_FLAG_RETCODE                                EQU     00000004H
ODBC_VS_FLAG_STOP                                   EQU     00000008H


;======================================== Structures ======================================;
IFNDEF DATE_STRUCT
    DATE_STRUCT STRUCT ALIGNMODE
        year  DW ?
        month DW ?
        day   DW ?
    DATE_STRUCT ENDS
ENDIF

SQL_DATE_STRUCT STRUCT ALIGNMODE
    year  DW ?
    month DW ?
    day   DW ?
SQL_DATE_STRUCT ENDS

IFNDEF TIME_STRUCT
    TIME_STRUCT STRUCT ALIGNMODE
        hour   DW ?
        minute DW ?
        second DW ?
    TIME_STRUCT ENDS
ENDIF

SQL_TIME_STRUCT STRUCT ALIGNMODE
    hour   DW ?
    minute DW ?
    second DW ?
SQL_TIME_STRUCT ENDS

IFNDEF TIMESTAMP_STRUCT
    TIMESTAMP_STRUCT STRUCT ALIGNMODE
        year     DW ?
        month    DW ?
        day      DW ?
        hour     DW ?
        minute   DW ?
        second   DW ?
        fraction DD ?
    TIMESTAMP_STRUCT ENDS
ENDIF

SQL_TIMESTAMP_STRUCT STRUCT ALIGNMODE
    year     DW ?
    month    DW ?
    day      DW ?
    hour     DW ?
    minute   DW ?
    second   DW ?
    fraction DD ?
SQL_TIMESTAMP_STRUCT ENDS

SQL_YEAR_MONTH_STRUCT STRUCT ALIGNMODE
    year  DD ?
    month DD ?
SQL_YEAR_MONTH_STRUCT ENDS

SQL_DAY_SECOND_STRUCT STRUCT ALIGNMODE
    day      DD ?
    hour     DD ?
    minute   DD ?
    second   DD ?
    fraction DD ?
SQL_DAY_SECOND_STRUCT ENDS

SQL_INTERVAL_STRUCT STRUCT ALIGNMODE
    interval_type DD ?
    interval_sign DD ?
    UNION intval
        year_month SQL_YEAR_MONTH_STRUCT <>
        day_second SQL_DAY_SECOND_STRUCT <>
     ENDS
SQL_INTERVAL_STRUCT ENDS
SQL_MAX_NUMERIC_LEN EQU 16

SQL_NUMERIC_STRUCT STRUCT ALIGNMODE
    precision DB ?
    scale     DB ?
    sign      DB ?
    val       DB SQL_MAX_NUMERIC_LEN DUP(?)
SQL_NUMERIC_STRUCT ENDS

SQLGUID STRUCT ALIGNMODE
    Data1 DD ?
    Data2 DW ?
    Data3 DW ?
    Data4 DB 8 dup(?)
SQLGUID ENDS

ODBC_VS_ARGS STRUCT ALIGNMODE
    pguidEvent         XWORD ?
    dwFlags            DD    ?
    UNION
        wszArg         XWORD ?
        szArg          XWORD ?
    ENDS
    UNION
        wszCorrelation XWORD ?
        szCorrelation  XWORD ?
    ENDS
    RetCode            DW    ?
ODBC_VS_ARGS ENDS


;======================================== Functions =======================================;
CloseODBCPerfData PROTO
CollectODBCPerfData PROTO :QWORD, :QWORD, :QWORD, :QWORD
CursorLibLockDbc PROTO :QWORD, :QWORD
CursorLibLockDesc PROTO :QWORD, :QWORD
CursorLibLockStmt PROTO :QWORD, :QWORD
CursorLibTransact PROTO :QWORD, :QWORD, :QWORD
DllBidEntryPoint PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
GetODBCSharedData PROTO
LockHandle PROTO :QWORD, :QWORD, :QWORD
ODBCGetTryWaitValue PROTO
ODBCInternalConnectW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
ODBCQualifyFileDSNW PROTO :QWORD
ODBCSetTryWaitValue PROTO :QWORD
OpenODBCPerfData PROTO :QWORD
PostComponentError PROTO :QWORD
PostODBCComponentError PROTO :QWORD
PostODBCError PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLAllocConnect PROTO :QWORD, :QWORD
SQLAllocEnv PROTO :QWORD
SQLAllocHandle PROTO :QWORD, :QWORD, :QWORD
SQLAllocHandleStd PROTO :QWORD, :QWORD, :QWORD
SQLAllocStmt PROTO :QWORD, :QWORD
SQLBindCol PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLBindParam PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLBindParameter PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLBrowseConnectA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLBrowseConnectW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLBulkOperations PROTO :QWORD, :QWORD
SQLCancel PROTO :QWORD
SQLCloseCursor PROTO :QWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    SQLCancelHandle PROTO :QWORD, :QWORD
ENDIF
SQLCloseCursor PROTO :QWORD
SQLColAttributeA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColAttributeW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColAttributesA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColAttributesW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColumnPrivilegesA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColumnPrivilegesW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColumnsA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLColumnsW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    SQLCompleteAsync PROTO :QWORD, :QWORD, :QWORD
ENDIF
SQLConnectA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLConnectW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLCopyDesc PROTO :QWORD, :QWORD
SQLDataSourcesA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDataSourcesW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDescribeColA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDescribeColW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDescribeParam PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDisconnect PROTO :QWORD
SQLDriverConnectA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDriverConnectW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDriversA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLDriversW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLEndTran PROTO :QWORD, :QWORD, :QWORD
SQLErrorA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLErrorW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLExecDirectA PROTO :QWORD, :QWORD, :QWORD
SQLExecDirectW PROTO :QWORD, :QWORD, :QWORD
SQLExecute PROTO :QWORD
SQLExtendedFetch PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLFetch PROTO :QWORD
SQLFetchScroll PROTO :QWORD, :QWORD, :QWORD
SQLForeignKeysA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLForeignKeysW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLFreeConnect PROTO :QWORD
SQLFreeEnv PROTO :QWORD
SQLFreeHandle PROTO :QWORD, :QWORD
SQLFreeStmt PROTO :QWORD, :QWORD
SQLGetConnectAttrA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetConnectAttrW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetConnectOptionA PROTO :QWORD, :QWORD, :QWORD
SQLGetConnectOptionW PROTO :QWORD, :QWORD, :QWORD
SQLGetCursorNameA PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLGetCursorNameW PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLGetData PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDescFieldA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDescFieldW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDescRecA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDescRecW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDiagFieldA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDiagFieldW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDiagRecA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetDiagRecW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetEnvAttr PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetFunctions PROTO :QWORD, :QWORD, :QWORD
SQLGetInfoA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetInfoW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetStmtAttrA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetStmtAttrW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLGetStmtOption PROTO :QWORD, :QWORD, :QWORD
SQLGetTypeInfoA PROTO :QWORD, :QWORD
SQLGetTypeInfoW PROTO :QWORD, :QWORD
SQLMoreResults PROTO :QWORD
SQLNativeSqlA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLNativeSqlW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLNumParams PROTO :QWORD, :QWORD
SQLNumResultCols PROTO :QWORD, :QWORD
SQLParamData PROTO :QWORD, :QWORD
SQLParamOptions PROTO :QWORD, :QWORD, :QWORD
SQLPrepareA PROTO :QWORD, :QWORD, :QWORD
SQLPrepareW PROTO :QWORD, :QWORD, :QWORD
SQLPrimaryKeysA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLPrimaryKeysW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLProcedureColumnsA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLProcedureColumnsW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLProceduresA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLProceduresW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLPutData PROTO :QWORD, :QWORD, :QWORD
SQLRowCount PROTO :QWORD, :QWORD
SQLSetConnectAttrA PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetConnectAttrW PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetConnectOptionA PROTO :QWORD, :QWORD, :QWORD
SQLSetConnectOptionW PROTO :QWORD, :QWORD, :QWORD
SQLSetCursorNameA PROTO :QWORD, :QWORD, :QWORD
SQLSetCursorNameW PROTO :QWORD, :QWORD, :QWORD
SQLSetDescFieldA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLSetDescFieldW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLSetDescRec PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLSetEnvAttr PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetParam PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLSetPos PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetScrollOptions PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetStmtAttrA PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetStmtAttrW PROTO :QWORD, :QWORD, :QWORD, :QWORD
SQLSetStmtOption PROTO :QWORD, :QWORD, :QWORD
SQLSpecialColumnsA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLSpecialColumnsW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLStatisticsA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLStatisticsW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLTablePrivilegesA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLTablePrivilegesW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLTablesA PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLTablesW PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
SQLTransact PROTO :QWORD, :QWORD, :QWORD
SearchStatusCode PROTO :QWORD, :QWORD
VFreeErrors PROTO :QWORD
VRetrieveDriverErrorsRowCol PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
ValidateErrorQueue PROTO :QWORD, :QWORD

IFDEF APP_UNICODE
    SQLBrowseConnect EQU <SQLBrowseConnectW>
    SQLColAttribute EQU <SQLColAttributeW>
    SQLColAttributes EQU <SQLColAttributesW>
    SQLColumnPrivileges EQU <SQLColumnPrivilegesW>
    SQLColumns EQU <SQLColumnsW>
    SQLConnect EQU <SQLConnectW>
    SQLDataSources EQU <SQLDataSourcesW>
    SQLDescribeCol EQU <SQLDescribeColW>
    SQLDriverConnect EQU <SQLDriverConnectW>
    SQLDrivers EQU <SQLDriversW>
    SQLError EQU <SQLErrorW>
    SQLExecDirect EQU <SQLExecDirectW>
    SQLForeignKeys EQU <SQLForeignKeysW>
    SQLGetConnectAttr EQU <SQLGetConnectAttrW>
    SQLGetConnectOption EQU <SQLGetConnectOptionW>
    SQLGetCursorName EQU <SQLGetCursorNameW>
    SQLGetDescField EQU <SQLGetDescFieldW>
    SQLGetDescRec EQU <SQLGetDescRecW>
    SQLGetDiagField EQU <SQLGetDiagFieldW>
    SQLGetDiagRec EQU <SQLGetDiagRecW>
    SQLGetInfo EQU <SQLGetInfoW>
    SQLGetStmtAttr EQU <SQLGetStmtAttrW>
    SQLGetTypeInfo EQU <SQLGetTypeInfoW>
    SQLNativeSql EQU <SQLNativeSqlW>
    SQLPrepare EQU <SQLPrepareW>
    SQLPrimaryKeys EQU <SQLPrimaryKeysW>
    SQLProcedureColumns EQU <SQLProcedureColumnsW>
    SQLProcedures EQU <SQLProceduresW>
    SQLSetConnectAttr EQU <SQLSetConnectAttrW>
    SQLSetConnectOption EQU <SQLSetConnectOptionW>
    SQLSetCursorName EQU <SQLSetCursorNameW>
    SQLSetDescField EQU <SQLSetDescFieldW>
    SQLSetStmtAttr EQU <SQLSetStmtAttrW>
    SQLSpecialColumns EQU <SQLSpecialColumnsW>
    SQLStatistics EQU <SQLStatisticsW>
    SQLTablePrivileges EQU <SQLTablePrivilegesW>
    SQLTables EQU <SQLTablesW>
ELSE
    SQLBrowseConnect EQU <SQLBrowseConnectA>
    SQLColAttribute EQU <SQLColAttributeA>
    SQLColAttributes EQU <SQLColAttributesA>
    SQLColumnPrivileges EQU <SQLColumnPrivilegesA>
    SQLColumns EQU <SQLColumnsA>
    SQLConnect EQU <SQLConnectA>
    SQLDataSources EQU <SQLDataSourcesA>
    SQLDescribeCol EQU <SQLDescribeColA>
    SQLDriverConnect EQU <SQLDriverConnectA>
    SQLDrivers EQU <SQLDriversA>
    SQLError EQU <SQLErrorA>
    SQLExecDirect EQU <SQLExecDirectA>
    SQLForeignKeys EQU <SQLForeignKeysA>
    SQLGetConnectAttr EQU <SQLGetConnectAttrA>
    SQLGetConnectOption EQU <SQLGetConnectOptionA>
    SQLGetCursorName EQU <SQLGetCursorNameA>
    SQLGetDescField EQU <SQLGetDescFieldA>
    SQLGetDescRec EQU <SQLGetDescRecA>
    SQLGetDiagField EQU <SQLGetDiagFieldA>
    SQLGetDiagRec EQU <SQLGetDiagRecA>
    SQLGetInfo EQU <SQLGetInfoA>
    SQLGetStmtAttr EQU <SQLGetStmtAttrA>
    SQLGetTypeInfo EQU <SQLGetTypeInfoA>
    SQLNativeSql EQU <SQLNativeSqlA>
    SQLPrepare EQU <SQLPrepareA>
    SQLPrimaryKeys EQU <SQLPrimaryKeysA>
    SQLProcedureColumns EQU <SQLProcedureColumnsA>
    SQLProcedures EQU <SQLProceduresA>
    SQLSetConnectAttr EQU <SQLSetConnectAttrA>
    SQLSetConnectOption EQU <SQLSetConnectOptionA>
    SQLSetCursorName EQU <SQLSetCursorNameA>
    SQLSetDescField EQU <SQLSetDescFieldA>
    SQLSetStmtAttr EQU <SQLSetStmtAttrA>
    SQLSpecialColumns EQU <SQLSpecialColumnsA>
    SQLStatistics EQU <SQLStatisticsA>
    SQLTablePrivileges EQU <SQLTablePrivilegesA>
    SQLTables EQU <SQLTablesA>
ENDIF


;======================= Undocumented functions (unknown arguments) =======================;
;IF (NTDDI_VERSION EQ NTDDI_WINXP)
;   MpHeapAlloc PROTO
;   MpHeapCompact PROTO
;   MpHeapCreate PROTO
;   MpHeapDestroy PROTO
;   MpHeapFree PROTO
;   MpHeapReAlloc PROTO
;   MpHeapSize PROTO
;   MpHeapValidate PROTO
;ENDIF
;g_hHeapMalloc PROTO

ENDIF ;ODBC32_INC
