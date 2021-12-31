

//////////////////////////////////////////////////////////////////////
//
// file name	: dyn_7_udr.cpp 
// description	: implementation of the dyn_7_udr class.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "db_data_containers.h"
#include "defines.h"



void dyn_7_udr::init(int f_id, int f_pos, string imsi, string call_partner, string cdr_circuit_allocation_time_stamp)
{
	// cdr management
	file_id		= f_id;				// the number of the file
	file_id		*= -1;				// indicate  to dyn_7_udr from r4 mediation engine
	file_pos	= f_pos;			// the bytes from start of cdr where file started

	// CDR values
	originating_address				= call_partner;			
	destination_IMSI				= imsi;					
	rate_call_partner				= call_partner;
	rate_call_type					= "TERMI";

	if ( is_local_service_center(call_partner) )
		rate_sub_service_type = 0;		// local
	else
		rate_sub_service_type = 1;		// international

	circuit_allocation_time_stamp	= cdr_circuit_allocation_time_stamp; // billed on this time
	
	// after Y2K fix YYYYMMDDHHMISS
	d_circuit_allocation_time.set_time((char*)circuit_allocation_time_stamp.c_str()+8);
	d_circuit_allocation_date.set_date((char*)circuit_allocation_time_stamp.c_str());
}

bool dyn_7_udr::insert_dialog_service_centers(string service_center)
{
	pair<CERVICE_CENTERS_DEF::iterator, bool> p = dialog_service_centers.insert(service_center);

	if (p.second == false)
	{
		cout<<"ERR: duplicate med_dialog_service_centers number"<<service_center<<endl;
		return false;
	}
	return true;
}

bool dyn_7_udr::insert_local_service_centers(string service_center)
{
	pair<CERVICE_CENTERS_DEF::iterator, bool> p = local_service_centers.insert(service_center);

	if (p.second == false)
	{
		cout<<"ERR: duplicate med_local_service_centers number"<<service_center<<endl;
		return false;
	}
	return true;
}


bool dyn_7_udr::is_not_dialog_service_center(string cdr_service_center)
{
	CERVICE_CENTERS_DEF::iterator i;

	i = dialog_service_centers.find(cdr_service_center);
	if(i == dialog_service_centers.end())
	{
		return true;		
	}
	return false;
}

bool dyn_7_udr::is_local_service_center(string cdr_service_center)
{
	CERVICE_CENTERS_DEF::iterator i;

	i = local_service_centers.find(cdr_service_center);
	if(i == local_service_centers.end())
	{
		return false;		
	}
	return true;
}