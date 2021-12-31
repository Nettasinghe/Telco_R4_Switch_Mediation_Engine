

///////////////////////////////////////////////////////////////////////////////////////////
// 
// Telco Switch Mediation Engine for Alcate MSC R4 CDR format version (R4 Mediation Engine) –
// --------------------------------------------------------------------------
// Telecom Switches such as MSCs, GGSNs, SMSCs and VAS servers store subscribers Call Detail 
// Record (CDR) data in encoded formats of either proprietary or ASN.1. Switch Mediation Engine
// functions as the intermediary between the Telco Network and the Billing System by decoding 
// the CDRs and transforming (amalgamating, stitching and enhancing) them to the input format 
// expected by the Billing System.
// R4 Mediation Engine decodeds Alcatel MSC CDRs in R4 version (which is proprietary).
//
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
// mediation.cpp
// R4 Mediation Engine
// main method contains here
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "defines.h"
#include "cdr.h"
#include "db.h"
#include "db_data_containers.h"

#include <time.h>

#define DBLOG


r4_cdr_buffer *cdr_store;
bool core_dump;
string original_call_partner_identity; 
int original_call_partner_extension;
char debug_option[128];
int array_insert_size;

ofstream f_log("./logs/R4_Mediation.log", ios::out | ios::app);


// -- db data containers begin
	
	rated_cdr				*gsm_rated_cdr;
	rated_cdr				*gsm_cdr_block;
	rated_cdr				*gsm_no_charge_cdr_block;
	rated_cdr				*gsm_error_cdr_block;
	dyn_7_udr				*gsm_dyn_7_udr;
	dyn_7_udr				*gsm_dyn_7_udr_block;
	call_partner_networks	*gsm_call_partner_networks;
	vm_call_partners		*gsm_vm_call_partners;
	
// --db data containers end

	r4_cdr_decode raw_cdr;			// all the methods to extract data from a cdr

	int global_cdr_counter;
	int global_no_charge_cdr_counter;
	int	global_dyn_7_udr_counter;

int main(int argc,char *argv[])
{
	char *ver = "1.1.8";

	cout<<"CDR Decoding  Engine for R4 "<<ver<<endl
	<<"Build Time "<<__DATE__<<" at "<<__TIME__<<endl
	<<"Millennium IT"<<endl
	<<"Colombo, Sri Lanka"<<endl<<endl;

	// Log start time
	char zTime[30];
	/*------- get time -------*/
	time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	f_log << endl;
	f_log << " ----------------------------------------------------------"  << endl;
	f_log << "ver : " << ver << " Build Time "<<__DATE__<<" at "<<__TIME__<<endl;
	f_log << " start time :" << zTime << endl;
	// Log start time -end


	// db data containers memory allocation startarray_insert_size
	cdr_store					= new r4_cdr_buffer(1024*1024*70); // allocate space in memory for binary read of whole cdr file
	gsm_rated_cdr				= new rated_cdr;
	gsm_dyn_7_udr				= new dyn_7_udr;
	gsm_call_partner_networks	= new call_partner_networks;
	gsm_vm_call_partners		= new vm_call_partners;
	
	// db data containers memory allocation end
	
	// allocate space in memory for binary read of whole cdr file
	cdr_files cdr_f;

//-------------- database logins and print file location -----------------------
FILE *login;
char cdr_login[128];
char cdr_dump_location[128];


	// get config data
	if( (login  = fopen( "./r4_cdr_eng.config", "r" )) == NULL )
	{
		printf( "The file 'r4_cdr_eng.config' was not opened\n" );
		f_log << " 'r4_cdr_eng.config' was not opened "  << endl;
		exit(0);
	}

	fscanf( login, "%s", cdr_login );
	fscanf( login, "%s", cdr_dump_location );
	fscanf( login, "%s", debug_option );
	fscanf( login, "%d", &array_insert_size );



	if( fclose( login ) )
		printf( "The file 'r4_cdr_eng.config' was not closed\n" );

	gsm_cdr_block				= new rated_cdr[array_insert_size]; // memory allocated after reading array_insert_size from file
	gsm_dyn_7_udr_block			= new dyn_7_udr[array_insert_size];
	gsm_no_charge_cdr_block		= new rated_cdr[array_insert_size];
	gsm_error_cdr_block			= new rated_cdr[array_insert_size];

//-------------- database logins and print file location -----------------------


	// login to cdr database
	cout <<"Debug Option = " << debug_option << " insert size = " << array_insert_size << endl; 
	f_log <<"Debug Option = " << debug_option << " insert size = " << array_insert_size << endl; 

	
	printf("\nReady to connect to cdr data base\n");

	db_connect(cdr_login);

	int no_charge_threshold = 0;
	db_read_med_threshold(no_charge_threshold);
	cout << "no_charge_threshold = " << no_charge_threshold << endl;
	f_log << "no_charge_threshold = " << no_charge_threshold << endl;

	gsm_call_partner_networks->db_read();	/// should be in customer care database
	// gsm_call_partner_networks->print();
	gsm_vm_call_partners->db_read();
	gsm_dyn_7_udr->db_read_med_dialog_service_centers();
	gsm_dyn_7_udr->db_read_med_local_service_centers();

	
	cdr_f.db_read();		// read in list of cdrs files to be rated from database
	//cdr_f.print();

	cdr_f.init(cdr_dump_location);
	

	// cdr decoder performance measurement defs

		
	int	total_cdrs_rated = 0;	// cumilative for this run over all cdr files
	int cdrs_pending_insert = 0;// must allways be less than block size
	int no_charge_cdrs_pending_insert = 0;
	int cdrs_inserted = 0;		// must allways be less than block size

	int dyn_7_udrs_pending_insert = 0;
	int	dyn_7_udrs_inserted = 0;



	FILE *fp;
	cdr_file_statistics *s;		// the stuff is stored in a map so dont allocate storage,
								// this gives access to storage area in map, but must assign!!
	cdr_file_statistics *s_sms; // use is very different to s
	s_sms = new cdr_file_statistics;	// therefore storage allocated


	while(cdr_f.get_next_file(&fp,&s))			// get handle of cdr file
	{
		s_sms->init();
		global_cdr_counter = 0;
		global_dyn_7_udr_counter = 0;
		global_no_charge_cdr_counter = 0;
		
		cdr_store->read_cdr_file(fp,s);			// read in whole file to buffer
		cout<<" cdr data "<<s->file_id<<endl;
		raw_cdr.set_statistics_collector(s);	// direct statistics to file statistics area
		
		while(cdr_store->get_cdr_start())		// look for start of a cdr in the file
		{
 			raw_cdr.decode(cdr_store->current);

#ifdef DEBUG
			raw_cdr.dump_screen();
#endif
			//skip emergency calls
			if (EMERGENCY_CALLS == raw_cdr.required_tele_service)
				continue;


			//the call is not to be charged if charge indicator && duration less than 90 seconds
			if (C_NO_CHARGE == raw_cdr.charging_indicator && raw_cdr.call_duration < no_charge_threshold)
			{
				gsm_rated_cdr->init(s->file_id, cdr_store->get_cdr_position());
				gsm_rated_cdr->unpack(&raw_cdr);		// extract all the info from the file format rec
				gsm_rated_cdr->decode_network();
				gsm_rated_cdr->decode_service();
				gsm_rated_cdr->fix_call_partner_identity();

				gsm_no_charge_cdr_block[no_charge_cdrs_pending_insert] = (*gsm_rated_cdr);
				no_charge_cdrs_pending_insert++;
				global_no_charge_cdr_counter++;

				if (array_insert_size == no_charge_cdrs_pending_insert)
				{
					//dyn_7_udrs_inserted += dyn_7_udrs_pending_insert;
#ifdef DBLOG
					db_insert_non_charging_cdr(no_charge_cdrs_pending_insert);
#endif
					no_charge_cdrs_pending_insert = 0;	// must allways be after the insert!!
				}
				continue;
			}
				

			
			

			gsm_rated_cdr->init(s->file_id, cdr_store->get_cdr_position());

			gsm_rated_cdr->unpack(&raw_cdr);			// extract all the info from the file format rec

			// If Optimal Routed MT cdr --> convert to MO
			gsm_rated_cdr->process_optimal_routed_calls();
			
			gsm_rated_cdr->decode_service(); // this is called here because 
											 // (gsm_rated_cdr->int_decoded_service == 99)

			// (1) SMS with local imsi
			// (2) MT
			// (3) from non-dialog service centers (call partner)
			if (	(gsm_rated_cdr->sms_local_imsi == true) && ( strcmp((gsm_rated_cdr->call_type_id).c_str(), "TERMI") == 0 )	
				&& ( gsm_dyn_7_udr->is_not_dialog_service_center(gsm_rated_cdr->call_partner_identity) )	)
			{
				gsm_dyn_7_udr->init(gsm_rated_cdr->file_id, gsm_rated_cdr->file_pos, 
					gsm_rated_cdr->mobile_subscriber_identity, gsm_rated_cdr->call_partner_identity, gsm_rated_cdr->circuit_allocation_time_stamp);
					
				s_sms->get_sms_min_max_time(gsm_rated_cdr->circuit_allocation_time_stamp);

				gsm_dyn_7_udr_block[dyn_7_udrs_pending_insert] = (*gsm_dyn_7_udr);
				global_dyn_7_udr_counter++;
				dyn_7_udrs_pending_insert++;
				s_sms->valid_cdr_count++;

				if (array_insert_size == dyn_7_udrs_pending_insert)
				{
					dyn_7_udrs_inserted += dyn_7_udrs_pending_insert;
#ifdef DBLOG
					db_insert_dyn_7_udr(dyn_7_udrs_pending_insert);
#endif
					dyn_7_udrs_pending_insert = 0;	// must allways be after the insert!!
				}
			}


			// rerouted terminating calls skip & sms calls with local imsi skip
			if  ( ( strcmp((gsm_rated_cdr->call_type_id).c_str(), "REROU_TER") != 0 ) && (gsm_rated_cdr->sms_local_imsi != true) )
			{	
				gsm_rated_cdr->decode_network();
				//gsm_rated_cdr->decode_service();	// this is called earlier because 
														// (gsm_rated_cdr->int_decoded_service != 99)
				gsm_rated_cdr->fix_call_partner_identity();

				total_cdrs_rated++;  
				gsm_cdr_block[cdrs_pending_insert] = (*gsm_rated_cdr);
				cdrs_pending_insert++;
				global_cdr_counter++;

				if (array_insert_size == cdrs_pending_insert)
				{
					cdrs_inserted += cdrs_pending_insert;
#ifdef DBLOG
					db_insert_rated_cdr(cdrs_pending_insert);
#endif
					cdrs_pending_insert = 0;	// must allways be after the insert!!
				}
			}

		
			if  ( gsm_rated_cdr->generate_first_cdr() ) 
			{
				gsm_rated_cdr->decode_network();
				gsm_rated_cdr->decode_service();
				gsm_rated_cdr->fix_call_partner_identity();
					
				total_cdrs_rated++;  
				gsm_cdr_block[cdrs_pending_insert] = (*gsm_rated_cdr);
				cdrs_pending_insert++;
				global_cdr_counter++;
				if (array_insert_size == cdrs_pending_insert)
				{
					cdrs_inserted += cdrs_pending_insert;
#ifdef DBLOG
					db_insert_rated_cdr(cdrs_pending_insert);
#endif
					cdrs_pending_insert = 0;	// must allways be after the insert!!
				}

			}

			if ( gsm_rated_cdr->generate_second_cdr() ) 
			{			
				gsm_rated_cdr->decode_network();
				gsm_rated_cdr->decode_service(); 
				gsm_rated_cdr->fix_call_partner_identity();

				total_cdrs_rated++;  
				gsm_cdr_block[cdrs_pending_insert] = (*gsm_rated_cdr);
				cdrs_pending_insert++;
				global_cdr_counter++;
				if (array_insert_size == cdrs_pending_insert)
				{
					cdrs_inserted += cdrs_pending_insert;
#ifdef DBLOG
					db_insert_rated_cdr(cdrs_pending_insert);
#endif
					cdrs_pending_insert = 0;	// must allways be after the insert!!
				}
			}
		}

//------------------------------------------------------------------------------------------------
		
		if(fclose(fp))
			cout<<"<ERROR> cant close cdr file"<<endl; // only valid files get here

#ifdef DBLOG
		// get any partial block size inserts before updating sys_*_dump_files
		if(cdrs_pending_insert > 0)
		{
			cdrs_inserted += cdrs_pending_insert;
			db_insert_rated_cdr(cdrs_pending_insert);
			cdrs_pending_insert = 0;	// must allways be after the insert!!
		}
	
		if(dyn_7_udrs_pending_insert > 0)
		{
			dyn_7_udrs_inserted += dyn_7_udrs_pending_insert;
			db_insert_dyn_7_udr(dyn_7_udrs_pending_insert);
			dyn_7_udrs_pending_insert = 0;
		}

		if(no_charge_cdrs_pending_insert > 0)
		{
			//dyn_7_udrs_inserted += dyn_7_udrs_pending_insert;
			db_insert_non_charging_cdr(no_charge_cdrs_pending_insert);
			no_charge_cdrs_pending_insert = 0;
		}
#endif
	
		cdr_f.db_update(*s);
		f_log << global_cdr_counter << "		cdrs inserted for file_id :			   " << s->file_id << endl;
		
		cdr_f.db_insert_sys_smsc_secondary(*s, *s_sms);
		f_log << global_dyn_7_udr_counter << "	dyn_7_udrs inserted for file_id		: -" << s->file_id << endl;
		
		if(s->error_count > 0)
			cout<<"         Error count "<<s->error_count<<endl;
		cdr_store->init(); // rest all pointers
	};

#ifdef DBLOG
	// get any partial block size inserts
	if(cdrs_pending_insert > 0)
		db_insert_rated_cdr(cdrs_pending_insert);
	
	if(dyn_7_udrs_pending_insert > 0)
		db_insert_dyn_7_udr(dyn_7_udrs_pending_insert);

	if(no_charge_cdrs_pending_insert > 0)
		db_insert_non_charging_cdr(no_charge_cdrs_pending_insert);
#endif
	
	db_disconnect();

	// Log end time
	/*------- get time -------*/
	//time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	f_log << " total cdrs inserted			= " << cdrs_inserted		<< endl;
	f_log << " total dyn_7_udrs inserted		= " << dyn_7_udrs_inserted	<< endl;
	f_log << " end time :" << zTime << endl;
	f_log << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl;
	f_log << endl;
	// Log start time -end

	return 0;

}


