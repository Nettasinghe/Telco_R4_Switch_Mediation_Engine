
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[34];
};
static const struct sqlcxp sqlfpn =
{
    33,
    "d:\\src\\r4_mediation_1_1_7_3\\db.pc"
};


static unsigned long sqlctx = 875294891;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[31];
   unsigned int   sqhstl[31];
            int   sqhsts[31];
            void  *sqindv[31];
            int   sqinds[31];
   unsigned int   sqharm[31];
   unsigned int   *sqharc[31];
   unsigned short  sqadto[31];
   unsigned short  sqtdso[31];
} sqlstm = {10,31};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned long *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0005 = 
"select FILE_NAME ,CDR_FILE_ID_NO ,TRANSFER_DATE  from sys_cdr_dump_files whe\
re DECODED_DATE is null            ";

 static const char *sq0011 = 
"select NETWORK_ID ,LOCALE_ID  from MEDV_NETWORKS            ";

 static const char *sq0012 = 
"select CALL_PARTNER  from MED_VM_CALL_PARTNERS            ";

 static const char *sq0013 = 
"select SERVICE_CENTER  from MED_DIALOG_SERVICE_CENTERS            ";

 static const char *sq0014 = 
"select SERVICE_CENTER  from MED_LOCAL_SERVICE_CENTERS            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{10,4146,0,0,0,
5,0,0,1,0,0,32,67,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,83,0,0,4,4,0,1,0,1,5,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
51,0,0,3,59,0,1,84,0,0,0,0,0,1,0,
66,0,0,4,0,0,30,95,0,0,0,0,0,1,0,
81,0,0,5,111,0,9,131,0,0,0,0,0,1,0,
96,0,0,5,0,0,13,137,0,0,3,0,0,1,0,2,5,0,0,2,3,0,0,2,5,0,0,
123,0,0,5,0,0,15,154,0,0,0,0,0,1,0,
138,0,0,6,242,0,5,214,0,0,7,7,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,
3,0,0,1,3,0,0,
181,0,0,7,0,0,29,228,0,0,0,0,0,1,0,
196,0,0,8,35,0,4,370,0,0,1,0,0,1,0,2,5,0,0,
215,0,0,9,532,0,3,378,0,0,29,29,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,
0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
346,0,0,10,0,0,29,411,0,0,0,0,0,1,0,
361,0,0,11,60,0,9,440,0,0,0,0,0,1,0,
376,0,0,11,0,0,13,446,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
399,0,0,11,0,0,15,450,0,0,0,0,0,1,0,
414,0,0,12,58,0,9,476,0,0,0,0,0,1,0,
429,0,0,12,0,0,13,482,0,0,1,0,0,1,0,2,5,0,0,
448,0,0,12,0,0,15,486,0,0,0,0,0,1,0,
463,0,0,13,66,0,9,511,0,0,0,0,0,1,0,
478,0,0,13,0,0,13,517,0,0,1,0,0,1,0,2,5,0,0,
497,0,0,13,0,0,15,521,0,0,0,0,0,1,0,
512,0,0,14,65,0,9,547,0,0,0,0,0,1,0,
527,0,0,14,0,0,13,553,0,0,1,0,0,1,0,2,5,0,0,
546,0,0,14,0,0,15,557,0,0,0,0,0,1,0,
561,0,0,15,35,0,4,648,0,0,1,0,0,1,0,2,5,0,0,
580,0,0,16,256,0,3,656,0,0,11,11,0,1,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,
639,0,0,17,0,0,29,672,0,0,0,0,0,1,0,
654,0,0,18,301,0,3,713,0,0,8,8,0,1,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
5,0,0,1,5,0,0,1,5,0,0,
701,0,0,19,0,0,29,739,0,0,0,0,0,1,0,
716,0,0,20,35,0,4,878,0,0,1,0,0,1,0,2,5,0,0,
735,0,0,21,539,0,3,886,0,0,29,29,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,
0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
866,0,0,22,0,0,29,919,0,0,0,0,0,1,0,
881,0,0,23,35,0,4,1059,0,0,1,0,0,1,0,2,5,0,0,
900,0,0,24,551,0,3,1067,0,0,31,31,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,
0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1039,0,0,25,0,0,29,1100,0,0,0,0,0,1,0,
1054,0,0,26,75,0,4,1118,0,0,1,0,0,1,0,2,3,0,0,
};




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <sqlda.h>
#include <sqlca.h>

//#include "defines.h"				// CJN
#define CDR_INSERT_BLOCK_SIZE 1000	// CJN


#ifndef ORA_PROC
#include "db.h"
#include "db_data_containers.h"
#include "cdr.h"
#include <fstream>
#endif


extern rated_cdr *gsm_rated_cdr;
extern rated_cdr *gsm_cdr_block;
extern rated_cdr *gsm_error_cdr_block;
extern rated_cdr *gsm_no_charge_cdr_block;
extern dyn_7_udr *gsm_dyn_7_udr;
extern dyn_7_udr *gsm_dyn_7_udr_block;
extern char debug_option[128];
extern int array_insert_size;
extern int global_cdr_counter;
extern int global_no_charge_cdr_counter;
extern ofstream f_log;


#define BUF_LEN 	100
#define FETCH_SIZE	1000
#define BUF_LENTH	20		


/* EXEC SQL DECLARE CDR DATABASE; */ 
 
/* EXEC SQL DECLARE RATING DATABASE; */ 



/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char *login;
/* EXEC SQL END DECLARE SECTION; */ 



void sql_error(char *msg)
{
	cout << endl << msg << endl;
	f_log << msg << endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout << sqlca.sqlerrm.sqlerrmc << endl;
	f_log << sqlca.sqlerrm.sqlerrmc << endl;
	cout << "in " << oraca.orastxt.orastxtc << endl;
	f_log << "in " << oraca.orastxt.orastxtc << endl;
	cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		<< endl << endl;
	f_log << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		<< endl << endl;
	
	//-- Roll back any pending changes and disconnect from Oracle.
	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(1);
}


//-- Connect to ORACLE. 
void db_connect(char *in_login)
{
	login = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 


	//cout<<"\nConnecting to ORACLE  as: "<<login<<endl;
	cout<<"\nConnecting to ORACLE"  <<endl;
	f_log << "Connecting to ORACLE" << endl;
 
    /* EXEC SQL CONNECT :login; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	/* EXEC SQL ALTER SESSION SET NLS_DATE_FORMAT="DD/MM/YYYY HH24:MI:SS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"DD/MM/YYYY HH24:MI:SS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	cout<<"Connected  to Database"<<endl<<endl; 

}



void db_disconnect()
{
	cout<<"\nORACLE  database: DISCONNECT"<<endl;
	f_log << "ORACLE  database: DISCONNECT"<<endl;
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}	




// get cdr files
void cdr_files::db_read()
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - cdr_files::db_read()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		char file_name[BUF_LEN];		// varchar2(123)
		int file_id;					// called id_no in table number(9)
		char transfer_date[BUF_LEN];	// date
	} a[FETCH_SIZE]; 
	int rows_to_fetch, rows_before, rows_this_time; 

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE;
	 
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error: in cdr_files::db_read()"); */ 


    /* EXEC SQL DECLARE c_cdr_file CURSOR FOR 

	SELECT	FILE_NAME,  CDR_FILE_ID_NO, TRANSFER_DATE
	FROM	sys_cdr_dump_files
	WHERE DECODED_DATE IS NULL; */ 

       
    /* EXEC SQL OPEN c_cdr_file; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error: in cdr_files::db_read()");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error: in cdr_files::db_read()"); */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL FETCH c_cdr_file INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )96;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->file_name;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqharc[0] = (unsigned int   *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->file_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqharc[1] = (unsigned int   *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->transfer_date;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct cdr_file_t);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqharc[2] = (unsigned int   *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error: in cdr_files::db_read()");
}

 		 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d to_fetch=%d\n", rows_this_time, rows_before, rows_to_fetch);


		cdr_file_statistics cd;
		cd.init();
		for(i=0; i<rows_this_time; i++)
		{
			cd.file_id = a[i].file_id;
			cd.file_name = a[i].file_name;
			cd.transfer_date = a[i].transfer_date;			
			insert(a[i].file_name, cd);
		}
	} 

    /* EXEC SQL CLOSE c_cdr_file; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )123;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error: in cdr_files::db_read()");
}

 
 
    printf("\n %d  cdr files loaded.\n\n",rows_before);
	f_log << rows_before << " cdr files loaded" << endl;
}



void cdr_files::db_update(cdr_file_statistics s)
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - cdr_files::db_update(cdr_file_statistics s)"); */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		 int valid_cdr_count;					//  number(7)
		 int error_count;						//	number(7)
		 int bytes_read;						//	number(9)
		 char first_cdr_date[BUF_LENTH];		//	varchar2(14)
		 char last_cdr_date[BUF_LENTH];			//	varchar2(14)
		 int rating_duration;
		 char rating_start_date[BUF_LENTH];		//	varchar2(14)
 		 int no_charge_records;					//	number(7)

		 int id_no;								//	number(9)
 	} a; 

	/* EXEC SQL END DECLARE SECTION; */ 


	

	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;
	 a.id_no = s.file_id;
	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;

	 //a.valid_cdr_count = s.valid_cdr_count;
	 a.valid_cdr_count = global_cdr_counter;
	 a.error_count = s.error_count;
	 a.bytes_read = s.bytes_read;
	 strcpy(a.first_cdr_date, s.first_cdr_date.c_str());
	 strcpy(a.last_cdr_date, s.last_cdr_date.c_str());
	 a.rating_duration = s.rating_duration;
	 strcpy(a.rating_start_date, s.rating_start_date.c_str());
	 a.no_charge_records = global_no_charge_cdr_counter;

	 if ( (strcmp(debug_option,"ON"))==0 ) 
	 {
	 	cout << "valid cdr count : " << a.valid_cdr_count << endl;
	 	cout << "error counrt    : " << a.error_count << endl;
	 	cout << "bytes read      : " << a.bytes_read << endl;
	 	cout << "first cdr date   : " << a.first_cdr_date << endl;
	 	cout << "last cdr date   : " << a.last_cdr_date << endl;
	 	cout << "no_charge_records  : " << a.no_charge_records << endl;
	  }
	 
	 	

	 /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - cdr_files::db_update(cdr_file_statistics s)"); */ 

	 /* EXEC SQL	
	 UPDATE sys_cdr_dump_files
	 SET 
		valid_cdr_count			= :a.valid_cdr_count, 
		error_count				= :a.error_count,
		bytes_read				= :a.bytes_read,
		first_cdr_date			= to_date(:a.first_cdr_date,'YYYYMMDDHH24MISS'),
		last_cdr_date			= to_date(:a.last_cdr_date,'YYYYMMDDHH24MISS'),
		//rating_duration			= :a.rating_duration,
		//decoded_date		= to_date(:a.rating_start_date,'YYYYMMDDHH24MISS')
		decoded_date		= SYSDATE,
		no_charge_records	= :a.no_charge_records
	 WHERE cdr_file_id_no  = :a.id_no; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update sys_cdr_dump_files  set valid_cdr_count=:b0,error_co\
unt=:b1,bytes_read=:b2,first_cdr_date=to_date(:b3,'YYYYMMDDHH24MISS'),last_cdr\
_date=to_date(:b4,'YYYYMMDDHH24MISS'),decoded_date=SYSDATE,no_charge_records=:\
b5 where cdr_file_id_no=:b6";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )138;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&(a.valid_cdr_count);
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&(a.error_count);
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&(a.bytes_read);
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)(a.first_cdr_date);
  sqlstm.sqhstl[3] = (unsigned int  )20;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)(a.last_cdr_date);
  sqlstm.sqhstl[4] = (unsigned int  )20;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&(a.no_charge_records);
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&(a.id_no);
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - cdr_files::db_update(cdr_file_statistics s)");
}



	 /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )181;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - cdr_files::db_update(cdr_file_statistics s)");
}


 
    printf("\n cdr file id=%d log updated.\n\n", s.file_id);
	return;

	printf("\n <ERROR> file id = %d  not found to update.\n\n", s.file_id);
}		


void db_insert_rated_cdr(int cdr_count)
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_cdr
	{
		char imsi[BUF_LEN]; 						//	varchar2(20)
		char call_type_id[BUF_LEN];					//	varchar2(10)
		char day_type_id[1];						//	varchar2(5)
		char bearer_capability[BUF_LEN];			//	varchar2(10)
		char region_code_id[1];						// varchar2(5)
		char imei[BUF_LEN]; 						//  varchar2(20)
		char network_group_id[1];					//	varchar2(5)
		int locale_id;								//	number(3)
		int cell_id; 								// number(5)
		int duration;								//	number(9)
		char route_group_id[1];						//	varchar2(5)
 		char network_id[BUF_LEN];					//	varchar2(5)
		char msc_identity[BUF_LEN]; 				//	varchar2(20)
		char mnc[BUF_LEN];							// varchar2(3)
		int lac;									// number(5)
		int termination_type;						//	number(3)
		char call_partner[BUF_LEN];					//	varchar2(20)
		char link_information[BUF_LEN];				// varchar2(20)
		char ms_location[BUF_LEN];					//	varchar2(20)
		int bearer_service; 						//	number(3)
		int charging_indicator; 					// number(2)
		char mcc[BUF_LEN];							// varchar2(5)
		int service_type_id;						//	number(3)
		int file_id;								//  number(9)
		int file_pos;								//	number(9)
		char call_time[BUF_LEN];					//	date
		int roam;									//  number(1)
		int call_partner_ext;						//  number(3)
		char	mediated_time[BUF_LEN];				//	date			- sysdate
	} *a;
	
	char	med_system_date[20]; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		strcpy(a[i].imsi, gsm_cdr_block[i].mobile_subscriber_identity.substr(0,20).c_str());          
		strcpy(a[i].call_type_id,  gsm_cdr_block[i].call_type_id.c_str());   
		a[i].day_type_id[0]='\0';
		strcpy(a[i].bearer_capability, gsm_cdr_block[i].required_bearer_capability.c_str());
		a[i].region_code_id[0]='\0';
		strcpy(a[i].imei, gsm_cdr_block[i].mobile_station_identity.substr(0,20).c_str());  
		a[i].network_group_id[0]='\0';
		a[i].locale_id = gsm_cdr_block[i].origin_of_call_indicator;  
		a[i].cell_id = gsm_cdr_block[i].ci;
		a[i].duration = gsm_cdr_block[i].call_duration;
		a[i].route_group_id[0]='\0';
		strcpy(a[i].network_id, gsm_cdr_block[i].call_partner_network_id.substr(0,5).c_str());  
		strcpy(a[i].msc_identity, gsm_cdr_block[i].msc_identity.substr(0,20).c_str());
		strcpy(a[i].mnc, gsm_cdr_block[i].mnc.c_str());                                                                                     
	    a[i].lac = gsm_cdr_block[i].lac;
		a[i].termination_type  = gsm_cdr_block[i].call_termination_type;
		strcpy(a[i].call_partner,gsm_cdr_block[i].db_call_partner_identity.substr(0,20).c_str()); 
		strcpy(a[i].link_information, gsm_cdr_block[i].link_information.c_str());
		strcpy(a[i].ms_location, gsm_cdr_block[i].ms_location_identity.substr(0,20).c_str() );
		a[i].bearer_service = gsm_cdr_block[i].required_bearer_service;
		a[i].charging_indicator = gsm_cdr_block[i].charging_indicator; 
		strcpy(a[i].mcc, gsm_cdr_block[i].mcc.c_str()); 
		a[i].service_type_id = gsm_cdr_block[i].int_decoded_service;
		a[i].file_id =  gsm_cdr_block[i].file_id;                                                                                           
	    a[i].file_pos = gsm_cdr_block[i].file_pos;  

		reng_date d=gsm_cdr_block[i].d_circuit_allocation_date;                                                                             
		reng_time t=gsm_cdr_block[i].d_circuit_allocation_time;                                                                             
	    char buf[100];                                                                                                                      
	    sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second);                   
	    strcpy(a[i].call_time, buf);      

		a[i].roam =   gsm_cdr_block[i].roam; 
		a[i].call_partner_ext = gsm_cdr_block[i].true_cpe;

		//EXEC SQL
		//select sysdate into :a[i].mediated_time from dual;


		if ( (strcmp(debug_option,"ON"))==0 )
		{
			cout <<"imsi			:" << a[i].imsi 				<< endl;
			cout <<"call_type_id	:" << a[i].call_type_id 		<< endl;
			cout <<"day_type_id		:" << a[i].day_type_id 			<< "should be null"	<<	endl;
			cout <<"bearer_capability:"<< a[i].bearer_capability	<< endl;
			cout <<"region_code_id	:" << a[i].region_code_id		<< "should be null"	<<	endl;
			cout <<"imei			:" << a[i].imei					<< endl;
			cout <<"network_group_id:" << a[i].network_group_id		<< "should be null"	<<	endl;
			cout <<"locale_id		:" << a[i].locale_id			<< endl;
			cout <<"cell_id			:" << a[i].cell_id				<< endl;
			cout <<"duration		:" << a[i].duration				<< endl;
			cout <<"route_group_id	:" << a[i].route_group_id		<< "should be null"	<<	endl;
			cout <<"network_id		:" << a[i].network_id			<< endl;
			cout <<"msc_identity	:" << a[i].msc_identity			<< endl;
			cout <<"mnc				:" << a[i].mnc					<< endl;
			cout <<"lac				:" << a[i].lac					<< endl;
			cout <<"termination_type:" << a[i].termination_type		<< endl;
			cout <<"call_Partner	:" << a[i].call_partner			<< endl;
			cout <<"link_information:" << a[i].link_information 	<< endl;
			cout <<"ms_location		:" << a[i].ms_location			<< endl;
			cout <<"bearer_service	:" << a[i].bearer_service		<< endl;
			cout <<"charging_indicator	:" << a[i].charging_indicator		<< endl;
			cout <<"mcc				:" << a[i].mcc					<< endl;
			cout <<"service_type_id	:" << a[i].service_type_id		<< endl;
			cout <<"file_id			:" << a[i].file_id				<< endl;
			cout <<"file_pos		:" << a[i].file_pos				<< endl;
			cout <<"call_time		:" << a[i].call_time			<< endl;
			cout <<"roam			:" << a[i].roam					<< endl;
			cout <<"call_partner_ext:" << a[i].call_partner_ext		<< endl;
			//cout <<"mediated_time	:" << a[i].mediated_time		<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )196;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	} 

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO DYN_1_UDR (
		imsi, 
		call_type_id, 
		day_type_id, 
		bearer_capability, 
		region_code_id, 
		imei, 
		network_group_id, 
		locale_id, 
		cell_id, 
		duration, 
		route_group_id, 
		network_id, 
		msc_identity, 
		mnc, 
		lac, 
		termination_type, 
		call_partner, 
		link_information, 
		ms_location, 
		bearer_service, 
		charging_indicator, 
		mcc, 
		service_type_id, 
		file_id, 
		file_pos, 
		call_time, 
		roam,
		call_partner_ext,
		mediated_time
	) VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into DYN_1_UDR (imsi,call_type_id,day_type_id,bearer_\
capability,region_code_id,imei,network_group_id,locale_id,cell_id,duration,rou\
te_group_id,network_id,msc_identity,mnc,lac,termination_type,call_partner,link\
_information,ms_location,bearer_service,charging_indicator,mcc,service_type_id\
,file_id,file_pos,call_time,roam,call_partner_ext,mediated_time) values (:s1 ,\
:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15 ,:s\
16 ,:s17 ,:s18 ,:s19 ,:s20 ,:s21 ,:s22 ,:s23 ,:s24 ,:s25 ,:s26 ,:s27 ,:s28 ,:s\
29 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )215;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)a->imsi;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)a->call_type_id;
 sqlstm.sqhstl[1] = (unsigned int  )100;
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->day_type_id;
 sqlstm.sqhstl[2] = (unsigned int  )1;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->bearer_capability;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->region_code_id;
 sqlstm.sqhstl[4] = (unsigned int  )1;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)a->imei;
 sqlstm.sqhstl[5] = (unsigned int  )100;
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->network_group_id;
 sqlstm.sqhstl[6] = (unsigned int  )1;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&a->locale_id;
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&a->cell_id;
 sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&a->duration;
 sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)a->route_group_id;
 sqlstm.sqhstl[10] = (unsigned int  )1;
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)a->network_id;
 sqlstm.sqhstl[11] = (unsigned int  )100;
 sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[11] = (         void  *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)a->msc_identity;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[12] = (         void  *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)a->mnc;
 sqlstm.sqhstl[13] = (unsigned int  )100;
 sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[13] = (         void  *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)&a->lac;
 sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[14] = (         void  *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)&a->termination_type;
 sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[15] = (         void  *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)a->call_partner;
 sqlstm.sqhstl[16] = (unsigned int  )100;
 sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[16] = (         void  *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)a->link_information;
 sqlstm.sqhstl[17] = (unsigned int  )100;
 sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)a->ms_location;
 sqlstm.sqhstl[18] = (unsigned int  )100;
 sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&a->bearer_service;
 sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)&a->charging_indicator;
 sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (         void  *)a->mcc;
 sqlstm.sqhstl[21] = (unsigned int  )100;
 sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[21] = (         void  *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned int  )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (         void  *)&a->service_type_id;
 sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[22] = (         void  *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned int  )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (         void  *)&a->file_id;
 sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[23] = (         void  *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned int  )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[24] = (         void  *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned int  )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (         void  *)a->call_time;
 sqlstm.sqhstl[25] = (unsigned int  )100;
 sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[25] = (         void  *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned int  )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (         void  *)&a->roam;
 sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[26] = (         void  *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned int  )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (         void  *)&a->call_partner_ext;
 sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[27] = (         void  *)0;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned int  )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[28] = (unsigned int  )100;
 sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[28] = (         void  *)0;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned int  )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	
	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )346;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	delete a;
	
}





void call_partner_networks::db_read()
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - call_partner_networks::db_read()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct network_number 
	{ 
		char	network_id[BUF_LEN]; 
		int 	locale_id; 
		
	} a, *n_n_ptr; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	n_n_ptr = &a;
	
	/* EXEC SQL  DECLARE c_call_partner_network CURSOR FOR 
		SELECT NETWORK_ID, LOCALE_ID
		FROM MEDV_NETWORKS; */ 
 
	
	/* EXEC SQL OPEN   c_call_partner_network; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )361;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - call_partner_networks::db_read()");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_call_partner_network INTO :n_n_ptr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )376;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)n_n_ptr->network_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&n_n_ptr->locale_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - call_partner_networks::db_read()");
}

 
		insert(n_n_ptr->network_id, n_n_ptr->locale_id);
	} 
	
	/* EXEC SQL  CLOSE c_call_partner_network; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )399;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - call_partner_networks::db_read()");
}

 
	
	cout<<setw(8)<<i<<" call partner network's loaded."<<endl;
	f_log<<setw(8)<<i<<" call partner network's loaded."<<endl;
}


void vm_call_partners::db_read()
{
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - vm_call_partners::db_read()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct vm_call_partner 
	{ 
		char	call_partner[BUF_LEN]; 
	} a, *vm_cp_ptr; 

	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	vm_cp_ptr = &a;
	
	/* EXEC SQL  DECLARE c_vm_call_partner CURSOR FOR 
		SELECT CALL_PARTNER
		FROM MED_VM_CALL_PARTNERS; */ 
 
	
	/* EXEC SQL OPEN   c_vm_call_partner; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )414;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - vm_call_partners::db_read()");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_vm_call_partner INTO :vm_cp_ptr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )429;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)vm_cp_ptr->call_partner;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - vm_call_partners::db_read()");
}

 
		insert(vm_cp_ptr->call_partner);
	} 
	
	/* EXEC SQL  CLOSE c_vm_call_partner; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )448;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - vm_call_partners::db_read()");
}

 
	
	cout<<setw(8)<<i<<" voice mail call partner numbers loaded."<<endl;
	f_log<<setw(8)<<i<<" voice mail call partner numbers loaded."<<endl;
}

void dyn_7_udr::db_read_med_dialog_service_centers()
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_read_med_dialog_service_centers()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct dialog_service_center 
	{ 
		char	service_center[BUF_LEN]; 
	} a, *dialog_service_center_ptr; 

	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	dialog_service_center_ptr = &a;
	
	/* EXEC SQL  DECLARE c_dialog_service_center CURSOR FOR 
		SELECT SERVICE_CENTER
		FROM MED_DIALOG_SERVICE_CENTERS; */ 
 
	
	/* EXEC SQL OPEN   c_dialog_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )463;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_dialog_service_center INTO :dialog_service_center_ptr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )478;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)dialog_service_center_ptr->service_center;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
		insert_dialog_service_centers(dialog_service_center_ptr->service_center);
	} 
	
	/* EXEC SQL  CLOSE c_dialog_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )497;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_dialog_service_centers()");
}

 
	
	cout<<setw(8)<<i<<" med_dialog_service_centers loaded."<<endl;
	f_log<<setw(8)<<i<<" med_dialog_service_centers loaded."<<endl;
}


void dyn_7_udr::db_read_med_local_service_centers()
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_read_med_local_service_centers()"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct local_service_center 
	{ 
		char	service_center[BUF_LEN]; 
	} a, *local_service_center_ptr; 

	int i;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	local_service_center_ptr = &a;
	
	/* EXEC SQL  DECLARE c_local_service_center CURSOR FOR 
		SELECT SERVICE_CENTER
		FROM MED_LOCAL_SERVICE_CENTERS; */ 
 
	
	/* EXEC SQL OPEN   c_local_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0014;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )512;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_local_service_centers()");
}

 
	
	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 
	
	for (i=0; ;i++) 
	{ 
		/* EXEC SQL FETCH c_local_service_center INTO :local_service_center_ptr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )527;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)local_service_center_ptr->service_center;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_local_service_centers()");
}

 
		insert_local_service_centers(local_service_center_ptr->service_center);
	} 
	
	/* EXEC SQL  CLOSE c_local_service_center; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )546;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_local_service_centers()");
}

 
	
	cout<<setw(8)<<i<<" med_local_service_centers loaded."<<endl;
	f_log<<setw(8)<<i<<" med_local_service_centers loaded."<<endl;
}


void db_insert_dyn_7_udr(int cdr_count)
{
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_insert_dyn_7_udr(int cdr_count)"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	static struct db_cdr
	{	
		int		file_id;								//  number(9)
		int		file_pos;								//	number(9)
		char	originating_address[BUF_LEN];			//	varchar2(30)	- call_partner in dyn_1_udr
		char	call_time[BUF_LEN];						//	date			- call_time in dyn_1_udr
		char	traffic_event_time[BUF_LEN];			//	date			- call_time in dyn_1_udr
		char	accept_time[BUF_LEN];					//	date			- call_time in dyn_1_udr
		char	destination_imsi[BUF_LEN];				//	varchar2(30)	- imsi in dyn_1_udr
		char	rate_call_partner[BUF_LEN];				//	varchar2(30)	- call_partner in dyn_1_udr
		char	rate_call_type[BUF_LEN];				//	varchar2(10)	- "TERMI"
		int		rate_sub_service_type;					//	number(2)
		char	mediated_time[BUF_LEN];					//	date			- sysdate
	} * a;

	char	med_system_date[20]; 

	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		a[i].file_id			= gsm_dyn_7_udr_block[i].file_id; 
		a[i].file_pos			= gsm_dyn_7_udr_block[i].file_pos;

		strncpy(a[i].originating_address, gsm_dyn_7_udr_block[i].originating_address.c_str(), 30);
		
		reng_date d=gsm_dyn_7_udr_block[i].d_circuit_allocation_date;                                                                             
		reng_time t=gsm_dyn_7_udr_block[i].d_circuit_allocation_time;                                                                             
	    char buf[100];
		buf[0] = '\0';                                                                                                                      
	    sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second);                   
	    strcpy(a[i].call_time, buf);
		strcpy(a[i].traffic_event_time, buf);
		strcpy(a[i].accept_time, buf);      	
							
		strncpy(a[i].destination_imsi,	gsm_dyn_7_udr_block[i].destination_IMSI.c_str(), 30);				
		
		strncpy(a[i].rate_call_partner, gsm_dyn_7_udr_block[i].rate_call_partner.c_str(), 30);				
		strncpy(a[i].rate_call_type,	gsm_dyn_7_udr_block[i].rate_call_type.c_str(), 10);						
		a[i].rate_sub_service_type		=gsm_dyn_7_udr_block[i].rate_sub_service_type;

		//EXEC SQL
		//select sysdate into :a[i].mediated_time from dual;

		
		if ( (strcmp(debug_option,"ON"))==0 )
		{					
			cout <<"file_id						:" << a[i].file_id 					<<"|"<< endl;
			cout <<"file_pos					:" << a[i].file_pos 				<<"|"<< endl;
			cout <<"originating_address			:" << a[i].originating_address		<<"|"<< endl;
			cout <<"call_time					:" << a[i].traffic_event_time		<<"|"<< endl;
			cout <<"traffic_event_time			:" << a[i].call_time				<<"|"<< endl;
			cout <<"accept_time					:" << a[i].accept_time				<<"|"<< endl;
			cout <<"destination_imsi			:" << a[i].destination_imsi			<<"|"<< endl;

			cout <<"rate_call_partner			:" << a[i].rate_call_partner		<<"|"<< endl;				
			cout <<"rate_call_type				:" << a[i].rate_call_type			<<"|"<< endl;					
			cout <<"rate_sub_service_type		:" << a[i].rate_sub_service_type	<<"|"<< endl;
			//cout <<"mediated_time				:" << a[i].mediated_time			<<"|"<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )561;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_dyn_7_udr(int cdr_count)");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	} 

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO DYN_7_UDR 
	(
		file_id,
		file_pos,
		originating_address,
		call_time,
		traffic_event_time,	
		accept_time,					
		destination_imsi,
		rate_call_partner,
		rate_call_type_id,
		rate_sub_service_type,
		mediated_time
	) 
	VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into DYN_7_UDR (file_id,file_pos,originating_address,\
call_time,traffic_event_time,accept_time,destination_imsi,rate_call_partner,ra\
te_call_type_id,rate_sub_service_type,mediated_time) values (:s1 ,:s2 ,:s3 ,:s\
4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )580;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&a->file_id;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->originating_address;
 sqlstm.sqhstl[2] = (unsigned int  )100;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->call_time;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->traffic_event_time;
 sqlstm.sqhstl[4] = (unsigned int  )100;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)a->accept_time;
 sqlstm.sqhstl[5] = (unsigned int  )100;
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->destination_imsi;
 sqlstm.sqhstl[6] = (unsigned int  )100;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)a->rate_call_partner;
 sqlstm.sqhstl[7] = (unsigned int  )100;
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)a->rate_call_type;
 sqlstm.sqhstl[8] = (unsigned int  )100;
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&a->rate_sub_service_type;
 sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[10] = (unsigned int  )100;
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_dyn_7_udr(int cdr_count)");
}


	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )639;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_dyn_7_udr(int cdr_count)");
}


	delete a;
}


void cdr_files::db_insert_sys_smsc_secondary(cdr_file_statistics s, cdr_file_statistics s_sms)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct cdr_file_t
	{ 
		char file_name[BUF_LEN];				//	varchar2(100)
		int valid_cdr_count;					//  number(7)
		int error_count;						//	number(7)
		int bytes_read;							//	number(9)
		char first_cdr_date[BUF_LENTH];			//	date
		char last_cdr_date[BUF_LENTH];			//	date
		char transfer_date[BUF_LEN];			//	date

		int id_no;								//	number(9)
 	} a; 

	/* EXEC SQL END DECLARE SECTION; */ 


	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;
	 a.id_no = s.file_id;
	 a.id_no *= -1;				// indicate  from r4 mediation engine
	 cout << "a.id_no :" <<a.id_no<<endl;
	 cout <<"s.file_id : "<<s.file_id<<endl;

	 strcpy(a.file_name, s.file_name.c_str());
	 a.valid_cdr_count = s_sms.valid_cdr_count;
	 a.error_count = s_sms.error_count;
	 a.bytes_read = s.bytes_read;
	 strcpy(a.first_cdr_date, s_sms.first_cdr_date.c_str());
	 strcpy(a.last_cdr_date, s_sms.last_cdr_date.c_str());
	  strcpy(a.transfer_date, s.transfer_date.c_str());


	 /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error: in db_insert_sys_smsc_secondary()"); */ 


	 /* EXEC SQL
	 INSERT INTO sys_smsc_secondary_dump_files 
	(
		cdr_file_id_no,
		file_name,
		valid_cdr_count, 
		error_count,
		bytes_read,
		first_cdr_date,
		last_cdr_date,
		decoded_date,
		transfer_date
	) 
	VALUES 
	(
		:a.id_no,
		:a.file_name,
		:a.valid_cdr_count, 
		:a.error_count,
		:a.bytes_read,
		 to_date(:a.first_cdr_date,'YYYYMMDDHH24MISS'),
		 to_date(:a.last_cdr_date,'YYYYMMDDHH24MISS'),
		 SYSDATE,
		to_date(:a.transfer_date,'DD/MM/YYYY HH24:MI:SS')
	); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into sys_smsc_secondary_dump_files (cdr_file_id_no,f\
ile_name,valid_cdr_count,error_count,bytes_read,first_cdr_date,last_cdr_date,d\
ecoded_date,transfer_date) values (:b0,:b1,:b2,:b3,:b4,to_date(:b5,'YYYYMMDDHH\
24MISS'),to_date(:b6,'YYYYMMDDHH24MISS'),SYSDATE,to_date(:b7,'DD/MM/YYYY HH24:\
MI:SS'))";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )654;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&(a.id_no);
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)(a.file_name);
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&(a.valid_cdr_count);
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&(a.error_count);
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&(a.bytes_read);
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)(a.first_cdr_date);
  sqlstm.sqhstl[5] = (unsigned int  )20;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)(a.last_cdr_date);
  sqlstm.sqhstl[6] = (unsigned int  )20;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)(a.transfer_date);
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
//  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error: in db_insert_sys_smsc_secondary()");
}



	 /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )701;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error: in db_insert_sys_smsc_secondary()");
}


 
    printf("\n sys_smsc_secondary_dump_files file id=%d log inserted.\n\n", s.file_id);

}

void db_insert_non_charging_cdr(int cdr_count)
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_insert_non_charging_cdr(int cdr_count)"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_cdr
	{
		char imsi[BUF_LEN]; 						//	varchar2(20)
		char call_type_id[BUF_LEN];					//	varchar2(10)
		char day_type_id[1];						//	varchar2(5)
		char bearer_capability[BUF_LEN];			//	varchar2(10)
		char region_code_id[1];						// varchar2(5)
		char imei[BUF_LEN]; 						//  varchar2(20)
		char network_group_id[1];					//	varchar2(5)
		int locale_id;								//	number(3)
		int cell_id; 								// number(5)
		int duration;								//	number(9)
		char route_group_id[1];						//	varchar2(5)
 		char network_id[BUF_LEN];					//	varchar2(5)
		char msc_identity[BUF_LEN]; 				//	varchar2(20)
		char mnc[BUF_LEN];							// varchar2(3)
		int lac;									// number(5)
		int termination_type;						//	number(3)
		char call_partner[BUF_LEN];					//	varchar2(20)
		char link_information[BUF_LEN];				// varchar2(20)
		char ms_location[BUF_LEN];					//	varchar2(20)
		int bearer_service; 						//	number(3)
		int charging_indicator; 					// number(2)
		char mcc[BUF_LEN];							// varchar2(5)
		int service_type_id;						//	number(3)
		int file_id;								//  number(9)
		int file_pos;								//	number(9)
		char call_time[BUF_LEN];					//	date
		int roam;									//  number(1)
		int call_partner_ext;						//  number(3)
		char	mediated_time[BUF_LEN];				//	date			- sysdate
	} *a;
	
	char	med_system_date[20]; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		strcpy(a[i].imsi, gsm_no_charge_cdr_block[i].mobile_subscriber_identity.substr(0,20).c_str());          
		strcpy(a[i].call_type_id,  gsm_no_charge_cdr_block[i].call_type_id.c_str());   
		a[i].day_type_id[0]='\0';
		strcpy(a[i].bearer_capability, gsm_no_charge_cdr_block[i].required_bearer_capability.c_str());
		a[i].region_code_id[0]='\0';
		strcpy(a[i].imei, gsm_no_charge_cdr_block[i].mobile_station_identity.substr(0,20).c_str());  
		a[i].network_group_id[0]='\0';
		a[i].locale_id = gsm_no_charge_cdr_block[i].origin_of_call_indicator;  
		a[i].cell_id = gsm_no_charge_cdr_block[i].ci;
		a[i].duration = gsm_no_charge_cdr_block[i].call_duration;
		a[i].route_group_id[0]='\0';
		strcpy(a[i].network_id, gsm_no_charge_cdr_block[i].call_partner_network_id.substr(0,5).c_str());  
		strcpy(a[i].msc_identity, gsm_no_charge_cdr_block[i].msc_identity.substr(0,20).c_str());
		strcpy(a[i].mnc, gsm_no_charge_cdr_block[i].mnc.c_str());                                                                                     
	    a[i].lac = gsm_no_charge_cdr_block[i].lac;
		a[i].termination_type  = gsm_no_charge_cdr_block[i].call_termination_type;
		strcpy(a[i].call_partner,gsm_no_charge_cdr_block[i].db_call_partner_identity.substr(0,20).c_str()); 
		strcpy(a[i].link_information, gsm_no_charge_cdr_block[i].link_information.c_str());
		strcpy(a[i].ms_location, gsm_no_charge_cdr_block[i].ms_location_identity.substr(0,20).c_str() );
		a[i].bearer_service = gsm_no_charge_cdr_block[i].required_bearer_service;
		a[i].charging_indicator = gsm_no_charge_cdr_block[i].charging_indicator; 
		strcpy(a[i].mcc, gsm_no_charge_cdr_block[i].mcc.c_str()); 
		a[i].service_type_id = gsm_no_charge_cdr_block[i].int_decoded_service;
		a[i].file_id =  gsm_no_charge_cdr_block[i].file_id;                                                                                           
	    a[i].file_pos = gsm_no_charge_cdr_block[i].file_pos;  

		reng_date d=gsm_no_charge_cdr_block[i].d_circuit_allocation_date;                                                                             
		reng_time t=gsm_no_charge_cdr_block[i].d_circuit_allocation_time;                                                                             
	    char buf[100];                                                                                                                      
	    sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second);                   
	    strcpy(a[i].call_time, buf);      

		a[i].roam =   gsm_no_charge_cdr_block[i].roam; 
		a[i].call_partner_ext = gsm_no_charge_cdr_block[i].true_cpe;

		//EXEC SQL
		//select sysdate into :a[i].mediated_time from dual;


		if ( (strcmp(debug_option,"ON"))==0 )
		{
			cout <<"imsi			:" << a[i].imsi 				<< endl;
			cout <<"call_type_id	:" << a[i].call_type_id 		<< endl;
			cout <<"day_type_id		:" << a[i].day_type_id 			<< "should be null"	<<	endl;
			cout <<"bearer_capability:"<< a[i].bearer_capability	<< endl;
			cout <<"region_code_id	:" << a[i].region_code_id		<< "should be null"	<<	endl;
			cout <<"imei			:" << a[i].imei					<< endl;
			cout <<"network_group_id:" << a[i].network_group_id		<< "should be null"	<<	endl;
			cout <<"locale_id		:" << a[i].locale_id			<< endl;
			cout <<"cell_id			:" << a[i].cell_id				<< endl;
			cout <<"duration		:" << a[i].duration				<< endl;
			cout <<"route_group_id	:" << a[i].route_group_id		<< "should be null"	<<	endl;
			cout <<"network_id		:" << a[i].network_id			<< endl;
			cout <<"msc_identity	:" << a[i].msc_identity			<< endl;
			cout <<"mnc				:" << a[i].mnc					<< endl;
			cout <<"lac				:" << a[i].lac					<< endl;
			cout <<"termination_type:" << a[i].termination_type		<< endl;
			cout <<"call_Partner	:" << a[i].call_partner			<< endl;
			cout <<"link_information:" << a[i].link_information 	<< endl;
			cout <<"ms_location		:" << a[i].ms_location			<< endl;
			cout <<"bearer_service	:" << a[i].bearer_service		<< endl;
			cout <<"charging_indicator	:" << a[i].charging_indicator		<< endl;
			cout <<"mcc				:" << a[i].mcc					<< endl;
			cout <<"service_type_id	:" << a[i].service_type_id		<< endl;
			cout <<"file_id			:" << a[i].file_id				<< endl;
			cout <<"file_pos		:" << a[i].file_pos				<< endl;
			cout <<"call_time		:" << a[i].call_time			<< endl;
			cout <<"roam			:" << a[i].roam					<< endl;
			cout <<"call_partner_ext:" << a[i].call_partner_ext		<< endl;
			//cout <<"mediated_time	:" << a[i].mediated_time		<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )716;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_non_charging_cdr(int cdr_count)");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	} 

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO NON_CHARGING_CDR (
		imsi, 
		call_type_id, 
		day_type_id, 
		bearer_capability, 
		region_code_id, 
		imei, 
		network_group_id, 
		locale_id, 
		cell_id, 
		duration, 
		route_group_id, 
		network_id, 
		msc_identity, 
		mnc, 
		lac, 
		termination_type, 
		call_partner, 
		link_information, 
		ms_location, 
		bearer_service, 
		charging_indicator, 
		mcc, 
		service_type_id, 
		file_id, 
		file_pos, 
		call_time, 
		roam,
		call_partner_ext,
		mediated_time
	) VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into NON_CHARGING_CDR (imsi,call_type_id,day_type_id,\
bearer_capability,region_code_id,imei,network_group_id,locale_id,cell_id,durat\
ion,route_group_id,network_id,msc_identity,mnc,lac,termination_type,call_partn\
er,link_information,ms_location,bearer_service,charging_indicator,mcc,service_\
type_id,file_id,file_pos,call_time,roam,call_partner_ext,mediated_time) values\
 (:s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:\
s15 ,:s16 ,:s17 ,:s18 ,:s19 ,:s20 ,:s21 ,:s22 ,:s23 ,:s24 ,:s25 ,:s26 ,:s27 ,:\
s28 ,:s29 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )735;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)a->imsi;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)a->call_type_id;
 sqlstm.sqhstl[1] = (unsigned int  )100;
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->day_type_id;
 sqlstm.sqhstl[2] = (unsigned int  )1;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->bearer_capability;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->region_code_id;
 sqlstm.sqhstl[4] = (unsigned int  )1;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)a->imei;
 sqlstm.sqhstl[5] = (unsigned int  )100;
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->network_group_id;
 sqlstm.sqhstl[6] = (unsigned int  )1;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&a->locale_id;
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&a->cell_id;
 sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&a->duration;
 sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)a->route_group_id;
 sqlstm.sqhstl[10] = (unsigned int  )1;
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)a->network_id;
 sqlstm.sqhstl[11] = (unsigned int  )100;
 sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[11] = (         void  *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)a->msc_identity;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[12] = (         void  *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)a->mnc;
 sqlstm.sqhstl[13] = (unsigned int  )100;
 sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[13] = (         void  *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)&a->lac;
 sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[14] = (         void  *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)&a->termination_type;
 sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[15] = (         void  *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)a->call_partner;
 sqlstm.sqhstl[16] = (unsigned int  )100;
 sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[16] = (         void  *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)a->link_information;
 sqlstm.sqhstl[17] = (unsigned int  )100;
 sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)a->ms_location;
 sqlstm.sqhstl[18] = (unsigned int  )100;
 sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&a->bearer_service;
 sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)&a->charging_indicator;
 sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (         void  *)a->mcc;
 sqlstm.sqhstl[21] = (unsigned int  )100;
 sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[21] = (         void  *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned int  )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (         void  *)&a->service_type_id;
 sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[22] = (         void  *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned int  )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (         void  *)&a->file_id;
 sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[23] = (         void  *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned int  )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[24] = (         void  *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned int  )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (         void  *)a->call_time;
 sqlstm.sqhstl[25] = (unsigned int  )100;
 sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[25] = (         void  *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned int  )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (         void  *)&a->roam;
 sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[26] = (         void  *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned int  )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (         void  *)&a->call_partner_ext;
 sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[27] = (         void  *)0;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned int  )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[28] = (unsigned int  )100;
 sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[28] = (         void  *)0;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned int  )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_non_charging_cdr(int cdr_count)");
}


	
	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )866;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_non_charging_cdr(int cdr_count)");
}


	delete a;
	
}

void db_insert_cdr_error_reason(int cdr_count)
{
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)"); */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_cdr
	{
		char imsi[BUF_LEN]; 						//	varchar2(20)
		char call_type_id[BUF_LEN];					//	varchar2(10)
		char day_type_id[1];						//	varchar2(5)
		char bearer_capability[BUF_LEN];			//	varchar2(10)
		char region_code_id[1];						// varchar2(5)
		char imei[BUF_LEN]; 						//  varchar2(20)
		char network_group_id[1];					//	varchar2(5)
		int locale_id;								//	number(3)
		int cell_id; 								// number(5)
		int duration;								//	number(9)
		char route_group_id[1];						//	varchar2(5)
 		char network_id[BUF_LEN];					//	varchar2(5)
		char msc_identity[BUF_LEN]; 				//	varchar2(20)
		char mnc[BUF_LEN];							// varchar2(3)
		int lac;									// number(5)
		int termination_type;						//	number(3)
		char call_partner[BUF_LEN];					//	varchar2(20)
		char link_information[BUF_LEN];				// varchar2(20)
		char ms_location[BUF_LEN];					//	varchar2(20)
		int bearer_service; 						//	number(3)
		int charging_indicator; 					// number(2)
		char mcc[BUF_LEN];							// varchar2(5)
		int service_type_id;						//	number(3)
		int file_id;								//  number(9)
		int file_pos;								//	number(9)
		char call_time[BUF_LEN];					//	date
		int roam;									//  number(1)
		int call_partner_ext;						//  number(3)
		char error_reason[BUF_LEN];					//	varchar2(20)
		char corrected[BUF_LEN];					//	varchar2(1)
		char	mediated_time[BUF_LEN];				//	date			- sysdate
	} *a;
	
	char	med_system_date[20]; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	rows_to_insert = cdr_count;
	
	if((a = new db_cdr[array_insert_size])==NULL)
	{
		cout<<" cant allocate memory for cdr insert"<<endl;
		exit(0);
	}
	
	
	for(int j=0; j<array_insert_size; j++)
	{
		a[j].file_pos = 0;
	}
	
	for(int i=0; i<rows_to_insert; i++)
	{
		strcpy(a[i].imsi, gsm_error_cdr_block[i].mobile_subscriber_identity.substr(0,20).c_str());          
		strcpy(a[i].call_type_id,  gsm_error_cdr_block[i].call_type_id.c_str());   
		a[i].day_type_id[0]='\0';
		strcpy(a[i].bearer_capability, gsm_error_cdr_block[i].required_bearer_capability.c_str());
		a[i].region_code_id[0]='\0';
		strcpy(a[i].imei, gsm_error_cdr_block[i].mobile_station_identity.substr(0,20).c_str());  
		a[i].network_group_id[0]='\0';
		a[i].locale_id = gsm_error_cdr_block[i].origin_of_call_indicator;  
		a[i].cell_id = gsm_error_cdr_block[i].ci;
		a[i].duration = gsm_error_cdr_block[i].call_duration;
		a[i].route_group_id[0]='\0';
		strcpy(a[i].network_id, gsm_error_cdr_block[i].call_partner_network_id.substr(0,5).c_str());  
		strcpy(a[i].msc_identity, gsm_error_cdr_block[i].msc_identity.substr(0,20).c_str());
		strcpy(a[i].mnc, gsm_error_cdr_block[i].mnc.c_str());                                                                                     
	    a[i].lac = gsm_error_cdr_block[i].lac;
		a[i].termination_type  = gsm_error_cdr_block[i].call_termination_type;
		strcpy(a[i].call_partner,gsm_error_cdr_block[i].db_call_partner_identity.substr(0,20).c_str()); 
		strcpy(a[i].link_information, gsm_error_cdr_block[i].link_information.c_str());
		strcpy(a[i].ms_location, gsm_error_cdr_block[i].ms_location_identity.substr(0,20).c_str() );
		a[i].bearer_service = gsm_error_cdr_block[i].required_bearer_service;
		a[i].charging_indicator = gsm_error_cdr_block[i].charging_indicator; 
		strcpy(a[i].mcc, gsm_error_cdr_block[i].mcc.c_str()); 
		a[i].service_type_id = gsm_error_cdr_block[i].int_decoded_service;
		a[i].file_id =  gsm_error_cdr_block[i].file_id;                                                                                           
	    a[i].file_pos = gsm_error_cdr_block[i].file_pos;  

		reng_date d=gsm_error_cdr_block[i].d_circuit_allocation_date;                                                                             
		reng_time t=gsm_error_cdr_block[i].d_circuit_allocation_time;                                                                             
	    char buf[100];                                                                                                                      
	    sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second);                   
	    strcpy(a[i].call_time, buf);      

		a[i].roam =   gsm_error_cdr_block[i].roam; 
		a[i].call_partner_ext = gsm_error_cdr_block[i].true_cpe;

		//EXEC SQL
		//select sysdate into :a[i].mediated_time from dual;


		if ( (strcmp(debug_option,"ON"))==0 )
		{
			cout <<"imsi			:" << a[i].imsi 				<< endl;
			cout <<"call_type_id	:" << a[i].call_type_id 		<< endl;
			cout <<"day_type_id		:" << a[i].day_type_id 			<< "should be null"	<<	endl;
			cout <<"bearer_capability:"<< a[i].bearer_capability	<< endl;
			cout <<"region_code_id	:" << a[i].region_code_id		<< "should be null"	<<	endl;
			cout <<"imei			:" << a[i].imei					<< endl;
			cout <<"network_group_id:" << a[i].network_group_id		<< "should be null"	<<	endl;
			cout <<"locale_id		:" << a[i].locale_id			<< endl;
			cout <<"cell_id			:" << a[i].cell_id				<< endl;
			cout <<"duration		:" << a[i].duration				<< endl;
			cout <<"route_group_id	:" << a[i].route_group_id		<< "should be null"	<<	endl;
			cout <<"network_id		:" << a[i].network_id			<< endl;
			cout <<"msc_identity	:" << a[i].msc_identity			<< endl;
			cout <<"mnc				:" << a[i].mnc					<< endl;
			cout <<"lac				:" << a[i].lac					<< endl;
			cout <<"termination_type:" << a[i].termination_type		<< endl;
			cout <<"call_Partner	:" << a[i].call_partner			<< endl;
			cout <<"link_information:" << a[i].link_information 	<< endl;
			cout <<"ms_location		:" << a[i].ms_location			<< endl;
			cout <<"bearer_service	:" << a[i].bearer_service		<< endl;
			cout <<"charging_indicator	:" << a[i].charging_indicator		<< endl;
			cout <<"mcc				:" << a[i].mcc					<< endl;
			cout <<"service_type_id	:" << a[i].service_type_id		<< endl;
			cout <<"file_id			:" << a[i].file_id				<< endl;
			cout <<"file_pos		:" << a[i].file_pos				<< endl;
			cout <<"call_time		:" << a[i].call_time			<< endl;
			cout <<"roam			:" << a[i].roam					<< endl;
			cout <<"call_partner_ext:" << a[i].call_partner_ext		<< endl;
			//cout <<"mediated_time	:" << a[i].mediated_time		<< endl;
		}
	}

	/* EXEC SQL
	select sysdate into :med_system_date from dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sysdate into :b0  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )881;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)med_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	
	for(int k=0; k<array_insert_size; k++)
	{
		strcpy(a[k].mediated_time, med_system_date);
	} 

	/* EXEC SQL  FOR :rows_to_insert  INSERT INTO CDR_ERROR_REASON (
		imsi, 
		call_type_id, 
		day_type_id, 
		bearer_capability, 
		region_code_id, 
		imei, 
		network_group_id, 
		locale_id, 
		cell_id, 
		duration, 
		route_group_id, 
		network_id, 
		msc_identity, 
		mnc, 
		lac, 
		termination_type, 
		call_partner, 
		link_information, 
		ms_location, 
		bearer_service, 
		charging_indicator, 
		mcc, 
		service_type_id, 
		file_id, 
		file_pos, 
		call_time, 
		roam,
		call_partner_ext,
		mediated_time
	) VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into CDR_ERROR_REASON (imsi,call_type_id,day_type_id,\
bearer_capability,region_code_id,imei,network_group_id,locale_id,cell_id,durat\
ion,route_group_id,network_id,msc_identity,mnc,lac,termination_type,call_partn\
er,link_information,ms_location,bearer_service,charging_indicator,mcc,service_\
type_id,file_id,file_pos,call_time,roam,call_partner_ext,mediated_time) values\
 (:s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:\
s15 ,:s16 ,:s17 ,:s18 ,:s19 ,:s20 ,:s21 ,:s22 ,:s23 ,:s24 ,:s25 ,:s26 ,:s27 ,:\
s28 ,:s29 ,:s30 ,:s31 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )900;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)a->imsi;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)a->call_type_id;
 sqlstm.sqhstl[1] = (unsigned int  )100;
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->day_type_id;
 sqlstm.sqhstl[2] = (unsigned int  )1;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)a->bearer_capability;
 sqlstm.sqhstl[3] = (unsigned int  )100;
 sqlstm.sqhsts[3] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)a->region_code_id;
 sqlstm.sqhstl[4] = (unsigned int  )1;
 sqlstm.sqhsts[4] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)a->imei;
 sqlstm.sqhstl[5] = (unsigned int  )100;
 sqlstm.sqhsts[5] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)a->network_group_id;
 sqlstm.sqhstl[6] = (unsigned int  )1;
 sqlstm.sqhsts[6] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (         void  *)&a->locale_id;
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[7] = (         void  *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned int  )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (         void  *)&a->cell_id;
 sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[8] = (         void  *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned int  )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (         void  *)&a->duration;
 sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[9] = (         void  *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned int  )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (         void  *)a->route_group_id;
 sqlstm.sqhstl[10] = (unsigned int  )1;
 sqlstm.sqhsts[10] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[10] = (         void  *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned int  )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (         void  *)a->network_id;
 sqlstm.sqhstl[11] = (unsigned int  )100;
 sqlstm.sqhsts[11] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[11] = (         void  *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned int  )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (         void  *)a->msc_identity;
 sqlstm.sqhstl[12] = (unsigned int  )100;
 sqlstm.sqhsts[12] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[12] = (         void  *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned int  )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (         void  *)a->mnc;
 sqlstm.sqhstl[13] = (unsigned int  )100;
 sqlstm.sqhsts[13] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[13] = (         void  *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned int  )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (         void  *)&a->lac;
 sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[14] = (         void  *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned int  )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (         void  *)&a->termination_type;
 sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[15] = (         void  *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned int  )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (         void  *)a->call_partner;
 sqlstm.sqhstl[16] = (unsigned int  )100;
 sqlstm.sqhsts[16] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[16] = (         void  *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned int  )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (         void  *)a->link_information;
 sqlstm.sqhstl[17] = (unsigned int  )100;
 sqlstm.sqhsts[17] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[17] = (         void  *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned int  )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (         void  *)a->ms_location;
 sqlstm.sqhstl[18] = (unsigned int  )100;
 sqlstm.sqhsts[18] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[18] = (         void  *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned int  )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (         void  *)&a->bearer_service;
 sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[19] = (         void  *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned int  )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (         void  *)&a->charging_indicator;
 sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[20] = (         void  *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned int  )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (         void  *)a->mcc;
 sqlstm.sqhstl[21] = (unsigned int  )100;
 sqlstm.sqhsts[21] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[21] = (         void  *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned int  )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (         void  *)&a->service_type_id;
 sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[22] = (         void  *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned int  )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (         void  *)&a->file_id;
 sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[23] = (         void  *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned int  )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (         void  *)&a->file_pos;
 sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[24] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[24] = (         void  *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned int  )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (         void  *)a->call_time;
 sqlstm.sqhstl[25] = (unsigned int  )100;
 sqlstm.sqhsts[25] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[25] = (         void  *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned int  )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (         void  *)&a->roam;
 sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[26] = (         void  *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned int  )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (         void  *)&a->call_partner_ext;
 sqlstm.sqhstl[27] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[27] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[27] = (         void  *)0;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned int  )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (         void  *)a->error_reason;
 sqlstm.sqhstl[28] = (unsigned int  )100;
 sqlstm.sqhsts[28] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[28] = (         void  *)0;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned int  )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (         void  *)a->corrected;
 sqlstm.sqhstl[29] = (unsigned int  )100;
 sqlstm.sqhsts[29] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[29] = (         void  *)0;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned int  )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (         void  *)a->mediated_time;
 sqlstm.sqhstl[30] = (unsigned int  )100;
 sqlstm.sqhsts[30] = (         int  )sizeof(struct db_cdr);
 sqlstm.sqindv[30] = (         void  *)0;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned int  )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
// if (sqlca.sqlcode == 1403) break;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	
	
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1039;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_insert_rated_cdr(int cdr_count)");
}


	delete a;
	
}

void db_read_med_threshold(int &no_charge_threshold)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	 int	threshold;				//	NUMBER(8)
			 
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC ORACLE OPTION (char_map=string) ; */ 


	/* EXEC SQL WHENEVER NOT FOUND DO sql_error("No relevant entry in MED_THRESHOLD table for description=NO_CHARGE"); */ 
 
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error - db_read_med_threshold(int no_charge_threshold)"); */ 


	/* EXEC SQL 
	SELECT	THRESHOLD
	INTO	:threshold 
	FROM	MED_THRESHOLD
	WHERE DESCRIPTION = 'NO_CHARGE'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select THRESHOLD into :b0  from MED_THRESHOLD where DESCRIPT\
ION='NO_CHARGE'";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1054;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&threshold;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) sql_error("No relevant entry in MED_THRESHOLD table for description=NO_CHARGE");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error - db_read_med_threshold(int no_charge_threshold)");
}


	
	no_charge_threshold = threshold;
}



