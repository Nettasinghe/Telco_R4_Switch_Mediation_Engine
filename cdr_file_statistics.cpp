

/////////////////////////////////////////////////////////////////////
//
// cdr_file_statistics.cpp: 
//			implementation of the cdr_file_statistics class.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "defines.h"


extern int  data_size;

// keeps the essential set of statistics on cdr extraction
// from the switch (ALCATEL EB10 ex ITT software) generated files


void cdr_file_statistics::init()
{
	file_id				= 0;
	valid_cdr_count		= 0;
	error_count			= 0;
	bytes_read			= 0;
	reject_cdr_count	= 0;
	first_cdr_date		= "20300407235959";	   // high value for lowest to get picked
	last_cdr_date		= "19720710235959";	   // low value for heighest to get picked
	rating_start_date	= "19720710235959";
	rating_duration		= 0;

	file_name			= "";
}


ostream& operator<<(ostream& out, cdr_file_statistics x)
{
    out<<"file id           = {"<<x.file_id<<"}"<<endl;
    out<<"valid cdr count   = {"<<x.valid_cdr_count<<"}"<<endl;
    out<<"error count       = {"<<x.error_count<<"}"<<endl;
    out<<"bytes read        = {"<<x.bytes_read<<"}"<<endl;
    out<<"reject cdr count  = {"<<x.reject_cdr_count<<"}"<<endl;
    out<<"first cdr date    = {"<<x.first_cdr_date<<"}"<<endl;
    out<<"last cdr date     = {"<<x.last_cdr_date<<"}"<<endl;
    out<<"rated start time  = {"<<x.rating_start_date<<"}"<<endl;
    out<<"rating duration   = {"<<x.rating_duration<<"}"<<endl;

	return out;
}

bool cdr_file_statistics::get_sms_min_max_time(string circuit_allocation_time_stamp)
{
	string min_max_time=circuit_allocation_time_stamp;

	if (min_max_time < first_cdr_date)
		first_cdr_date = min_max_time;
	
	if (min_max_time > last_cdr_date)
		last_cdr_date = min_max_time;


	return true;
}

