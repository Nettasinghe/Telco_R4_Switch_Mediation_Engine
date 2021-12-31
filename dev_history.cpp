
/*
Any note worthy changes with warts and all.


15-dec-2002 ver 1.0.1 
1) Accomodated changes for  additional cdr generation for Optimal Routing Calls

18-feb-2003 ver 1.0.2 
1) Removed Voice Mail Number db-search for Roaming Calls

20-feb-2003 1.0.3 
1) Further changes to OR calls processing - appended "9477" to call partner
2) Log to "../logs/R4_Mediation.log" file

30-sep-2003 ver 1.0.4
1) 'D' allowed in call partner and ms location TBCD decoding for USSD

30-sep-2003 ver 1.0.5
1) SMS calls with local imsi blocked from db login 

06-jan-2004 ver 1.1.0
1) SMS MT calls with local imsi & from non-dialog service centers logged to dyn_7_udr 

09-jan-2004 ver 1.1.1
1) Corrected the bug in TERMI and ORIGIN swap in SMS cdrs 

12-jan-2004 ver 1.1.2
1) Logged SMS cdrs file statistics to sys_smsc_secondary_dump_files 

13-jan-2004 ver 1.1.3
1) Populate traffic_event_time and accept_time in dyn_7_udr with call_time 

16-jan-2004 ver 1.1.4
1) db logging of cdrs changed to insert any partial block size before updating sys_*_dump_files 
2) transfer_date inserted to sys_smsc_secondary_dump_files
3) Oracle errors logged to ../logs/R4_Mediation.log

19-jan-2004 1.1.5 
1) Log location changed to "./logs/R4_Mediation.log" 

29-jan-2004 1.1.6
1) Remoded service resolution failure from "./logs/R4_Mediation.log" 

24-feb-2004 1.1.6.1
1) Introduced BCD check for cct allocation and call time stamps

23-feb-2004 1.1.7
1) Parametarised no charge threshold using MED_THRESHOLD db table.
2) Logging of no charge CDRs to NON_CHARGING_CDR table.
3) Insert of mediated_time to DYN_X_UDR and NON_CHARGING_CDR.

27-feb-2004 1.1.8
1) WIP - Auditing & Error Logging

*/

/*

DYN_7_UDR fields changed to "null"

(1)    DESTINATION_ADDRESS
(2)    RATE_ADDRESS

 

Following are the additional db tables.

CREATE TABLE MED_DIALOG_SERVICE_CENTERS ( 
SERVICE_CENTER VARCHAR2 (20))


CREATE TABLE MED_LOCAL_SERVICE_CENTERS ( 
SERVICE_CENTER VARCHAR2 (20))

CREATE TABLE DYN_1_UDR ( 
  IMSI                VARCHAR2 (20), 
  CALL_TYPE_ID        VARCHAR2 (10)  NOT NULL, 
  DAY_TYPE_ID         VARCHAR2 (5), 
  BEARER_CAPABILITY   VARCHAR2 (10), 
  REGION_CODE_ID      VARCHAR2 (5), 
  IMEI                VARCHAR2 (20), 
  NETWORK_GROUP_ID    VARCHAR2 (5), 
  LOCALE_ID           NUMBER (3), 
  CELL_ID             NUMBER (5), 
  DURATION            NUMBER (9), 
  ROUTE_GROUP_ID      VARCHAR2 (5), 
  NETWORK_ID          VARCHAR2 (5), 
  MSC_IDENTITY        VARCHAR2 (20), 
  MNC                 VARCHAR2 (3), 
  LAC                 NUMBER (5), 
  TERMINATION_TYPE    NUMBER (3), 
  CALL_PARTNER        VARCHAR2 (20), 
  LINK_INFORMATION    VARCHAR2 (20), 
  MS_LOCATION         VARCHAR2 (20), 
  BEARER_SERVICE      NUMBER (3), 
  CHARGING_INDICATOR  NUMBER (2), 
  MCC                 VARCHAR2 (5), 
  SERVICE_TYPE_ID     NUMBER (3)    NOT NULL, 
  FILE_ID             NUMBER (9)    NOT NULL, 
  FILE_POS            NUMBER (9)    NOT NULL, 
  CALL_TIME           DATE          NOT NULL, 
  ROAM                NUMBER (1), 
  CALL_PARTNER_EXT    NUMBER (3), 
  MEDIATED_TIME       DATE)

CREATE TABLE DYN_7_UDR ( 
  DESTINATION_ADDRESS            VARCHAR2 (30), 
  ORIGINATING_ADDRESS            VARCHAR2 (30)  NOT NULL, 
  TRAFFIC_EVENT_TYPE             NUMBER (9), 
  TRAFFIC_EVENT_TIME             DATE, 
  DESTINATION_LOGICAL_SME        NUMBER (9), 
  SME_REFERENCE_NUMBER           VARCHAR2 (30), 
  CALL_DIRECTION                 NUMBER (9), 
  DISTRIBUTION                   NUMBER (9), 
  DESTINATION_IMSI               VARCHAR2 (30), 
  ORIGINATING_IMSI               VARCHAR2 (30), 
  FIRST_NETWORK_OPERATION        NUMBER (9), 
  FIRST_DELIVERY_NETWORK         NUMBER (9), 
  SECOND_NETWORK_OPERATION       NUMBER (9), 
  SECOND_DELIVERY_NETWORK        NUMBER (9), 
  PRIORITY                       NUMBER (9), 
  SMSC_REFERENCE_NUMBER          NUMBER (9), 
  SOURCE_NODE_SCCP_ADDRESS       VARCHAR2 (30), 
  DESTINATION_NODE_SCCP_ADDRESS  VARCHAR2 (30), 
  RATE_ADDRESS                   VARCHAR2 (30), 
  RATE_CALL_PARTNER              VARCHAR2 (30)  NOT NULL, 
  RATE_CALL_TYPE_ID              VARCHAR2 (10)  NOT NULL, 
  RATE_SUB_SERVICE_TYPE          NUMBER (2)    NOT NULL, 
  MESSAGE_SOURCE                 VARCHAR2 (10), 
  SERVICE_TYPE_ID                NUMBER (3)    DEFAULT 4 NOT NULL, 
  FILE_ID                        NUMBER (9)    NOT NULL, 
  FILE_POS                       NUMBER (9)    NOT NULL, 
  CALL_TIME                      DATE          NOT NULL, 
  SUB_LOGICAL_SME                NUMBER (9), 
  ACCEPT_TIME                    DATE, 
  MEDIATED_TIME                  DATE)

CREATE TABLE CDR_ERROR_REASON ( 
  IMSI                VARCHAR2 (20), 
  CALL_TYPE_ID        VARCHAR2 (10)  NOT NULL, 
  DAY_TYPE_ID         VARCHAR2 (5), 
  BEARER_CAPABILITY   VARCHAR2 (10), 
  REGION_CODE_ID      VARCHAR2 (5), 
  IMEI                VARCHAR2 (20), 
  NETWORK_GROUP_ID    VARCHAR2 (5), 
  LOCALE_ID           NUMBER (3), 
  CELL_ID             NUMBER (5), 
  DURATION            NUMBER (9), 
  ROUTE_GROUP_ID      VARCHAR2 (5), 
  NETWORK_ID          VARCHAR2 (5), 
  MSC_IDENTITY        VARCHAR2 (20), 
  MNC                 VARCHAR2 (3), 
  LAC                 NUMBER (5), 
  TERMINATION_TYPE    NUMBER (3), 
  CALL_PARTNER        VARCHAR2 (20), 
  LINK_INFORMATION    VARCHAR2 (20), 
  MS_LOCATION         VARCHAR2 (20), 
  BEARER_SERVICE      NUMBER (3), 
  CHARGING_INDICATOR  NUMBER (2), 
  MCC                 VARCHAR2 (5), 
  SERVICE_TYPE_ID     NUMBER (3)    NOT NULL, 
  FILE_ID             NUMBER (9)    NOT NULL, 
  FILE_POS            NUMBER (9)    NOT NULL, 
  CALL_TIME           DATE          NOT NULL, 
  ROAM                NUMBER (1), 
  CALL_PARTNER_EXT    NUMBER (3), 
  ERROR_REASON        VARCHAR2 (20), 
  CORRECTED           VARCHAR2 (1), 
  MEDIATED_TIME       DATE)

  CREATE TABLE SYS_CDR_DUMP_FILES ( 
  FILE_NAME           VARCHAR2 (100), 
  VALID_CDR_COUNT     NUMBER (7), 
  ERROR_COUNT         NUMBER (7), 
  BYTES_READ          NUMBER (9), 
  FIRST_CDR_DATE      DATE, 
  LAST_CDR_DATE       DATE, 
  CDR_FILE_ID_NO      NUMBER (9), 
  CDR_FILE_DATE       DATE, 
  TRANSFER_DATE       DATE, 
  RATING_DURATION     NUMBER (5), 
  RATING_START_DATE   DATE, 
  DECODED_DATE        DATE, 
  ARCHIVE_DATE        DATE, 
  ARCHIVE_PURGE_DATE  DATE, 
  NO_CHARGE_RECORDS   NUMBER (7))

CREATE TABLE MED_THRESHOLD ( 
  DESCRIPTION  VARCHAR2 (20), 
  THRESHOLD    NUMBER (8))

  DESCRIPTION = NO_CHARGE
*/






