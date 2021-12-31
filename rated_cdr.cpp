


//////////////////////////////////////////////////////////////////////
//
// rated_cdr.cpp: 
//			implementation of the rated_cdr class.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "db_data_containers.h"
#include "defines.h"

extern rated_cdr *cdr_block;
extern 	call_partner_networks	*gsm_call_partner_networks;
extern  vm_call_partners		*gsm_vm_call_partners;
extern string original_call_partner_identity; // ???
extern int original_call_partner_extension;
extern ofstream f_log;



extern bool core_dump;
extern 	r4_cdr_decode raw_cdr;			// all the methods to extract data from a cdr


void rated_cdr::init(int f_id, int f_pos)
{
	// cdr management
	file_id = f_id;			// the number of the file
	file_pos  =f_pos;		// the bytes from start of cdr where file started

	// CDR values
	type_of_msc	= 0xf;
    type_of_call = 0xf;
    call_termination_type = 0xf;
    origin_of_call_indicator = 0xf;
    charging_indicator = 0xf;
    required_tele_service = 0xf;
    required_bearer_service = 0xf;
	
	call_duration = 0;
	invoked_supplementary_services = 0;
	required_bearer_capability = "";
	
	mobile_station_identity = "";
	link_information = "";
	mobile_subscriber_identity = "";
	msc_identity_extension = 0;
	msc_identity = "";
	call_partner_identity =WILD_CARD;
	ms_location_identity =WILD_CARD;
	ms_location_identity_extention	= 0;
	
	// call timing stuff
	circuit_allocation_time_stamp	= "";
	call_time_stamp					= "";
	fixed_network_info				= "";
	call_type_id					= "";
	
	// other 
	locale_id="";
	int_decoded_service=99;		// 100 as initial value for testing
	
	// decoded stuff
	d_circuit_allocation_time.init();
	d_circuit_allocation_date.init();

	// call partner info
	call_partner_extension=0;	// the 1A or 19 bits
	true_cpe=0;
	call_partner_network_id=WILD_CARD;
	call_partner_telephone_no="";

	mcc="";					// mobile country code
	mnc="";					// mobile network code
	lac=0;					// location area code
	ci=0;					// cell id

	roam=0;					// set to non-roaming
	db_call_partner_identity="";
	or_indicator = 0;		// Optimal Routed indicator
	sms_local_imsi	= false;	// true = sms calls with local imsi (to prevent sms login to db)

};

// unpack the bits
bool rated_cdr::unpack(r4_cdr_decode *cdr)
{
	circuit_allocation_time_stamp = cdr->circuit_allocation_time_stamp; // billed on this time
	
	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(circuit_allocation_time_stamp.substr(0,2) < "50")
		circuit_allocation_time_stamp = "20"+circuit_allocation_time_stamp;
	else
	{
		circuit_allocation_time_stamp = "19"+circuit_allocation_time_stamp;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_circuit_allocation_time.set_time((char*)circuit_allocation_time_stamp.c_str()+8);
	d_circuit_allocation_date.set_date((char*)circuit_allocation_time_stamp.c_str());

	
	mobile_subscriber_identity = cdr->mobile_subscriber_identity;

	if(mobile_subscriber_identity.length() > 20)
	{
		cout<<"mobile_subscriber_identity length bad "<<mobile_subscriber_identity.length()<<endl;
		exit(1);
	}
	
	mobile_station_identity = cdr->mobile_station_identity;

	type_of_msc = cdr->type_of_msc;
	if (type_of_msc <0x0 || type_of_msc > 0x03)
	{
		cout<<"Msc bad "<<type_of_msc<<endl;
		type_of_msc=0x4;
	}
	
    type_of_call = cdr->type_of_call;
	if (type_of_call <0x0 || type_of_call > 0x0f)
	{
		cout<<"type_of_call bad "<<type_of_call<<endl;
		type_of_call=0xa;
	}
	
	
    call_termination_type = cdr->call_termination_type;
	if (call_termination_type <0x0 || call_termination_type > 0x07)
	{
		cout<<"call_termination_type bad "<<call_termination_type<<endl;
		call_termination_type=0xf;
	}
	
	
    origin_of_call_indicator = cdr->origin_of_call_indicator;
	if (origin_of_call_indicator <0x0 || origin_of_call_indicator > 0x0f)
	{
		cout<<"origin_of_call_indicator bad "<<origin_of_call_indicator<<endl;
		origin_of_call_indicator=0xf;
	}
	
	
    charging_indicator = cdr->charging_indicator;
	if (charging_indicator <0x0 || charging_indicator > 0x0f)
	{
		cout<<"charging_indicator bad "<<charging_indicator<<endl;
		charging_indicator=0xf;
	}
	
    required_tele_service = cdr->required_tele_service;
	if (required_tele_service <0x11 || required_tele_service > 0xff)
	{
		cout<<"required tele service bad "<<required_tele_service<<endl;
		required_tele_service=0xff;
	}
	
	
    required_bearer_service = cdr->required_bearer_service;
	if (required_bearer_service <0x00 || required_bearer_service > 0xff)
	{
		cout<<"required_bearer_service bad "<<required_bearer_service<<endl;
		exit(1);
	}
	
	call_duration = cdr->call_duration;
	if (call_duration < 0 || call_duration > 99999999)
	{
		cout<<"call_duration bad "<<call_duration<<endl;
		call_duration=0;
	}
	
	
	call_time_stamp = cdr->call_time_stamp;

	call_partner_extension = cdr->call_partner.ext;
	true_cpe = cdr->true_cpe;
	call_partner_identity= cdr->call_partner.id;

	ms_location_identity=cdr->ms_location.id;
	ms_location_identity_extention=cdr->ms_location.ext;


	msc_identity_extension=cdr->msc.ext;
	//msc_identity = cdr->msc.id;
	msc_identity = cdr->msc_identity;
	
	// If the call type is "terminating (0x01), then "incoming trunk group" from "fixed network info"
	// Else "outgoing trunk group" from required_bearer_capability
	if (type_of_call == 0x01)
	{
		required_bearer_capability = cdr->fixed_network_information;
	}
	else
	{	
		required_bearer_capability = cdr->required_bearer_capability;
	}

	if (ms_location_identity.size() > 40)
	{
		ms_location_identity=ms_location_identity.substr(0,39);
		cout<<" ms location identity truncated"<<endl;
	}

	mcc=cdr->MCC;
	mnc=cdr->MNC;
	lac=cdr->LAC;
	ci=cdr->CI;

	link_information=cdr->link_information;
	return true;
}


bool rated_cdr::print()
{
	/*
	fstream array_log("c:\array_log.doc");
	rated_cdr *a=r_cdr_block;

	for(int i=0; i<CDR_INSERT_BLOCK_SIZE; i++)
	{
	// open a file and write to it before logging
	array_log<<i<<"="<<a[i].result_id<<","<<a[i].account_no<<","<<a[i].termination_type<<","<<a[i].units<<","
	<<a[i].charge<<","<<a[i].call_partner_id<<","<<a[i].duration<<","
	<<endl;
	}
	array_log.close();
	*/
	return true;
}


// Note - Every time return called , call_type_id = decode_type_of_call(type_of_call) called
bool rated_cdr::decode_service()
{

	// using 0xa0 for local and '0x90 for international
	if( NATIONAL_CALL != (e_origin_of_call_indicator)origin_of_call_indicator && 
		(int)CPE_NATIONAL == call_partner_extension  )
	{
		origin_of_call_indicator = (int)NATIONAL_CALL;
	}
	// international roamers get this when making local calls
	else if((int)CPE_INTERNATIONAL == call_partner_extension )  
	{
		if(INDICATOR_NOT_APPLICABLE  == (e_origin_of_call_indicator)origin_of_call_indicator)
		{
			origin_of_call_indicator = (int)INTERNATIONAL_CALL;
		}
	}
	else if ((int)CPE_NATIONAL == call_partner_extension  &&  
		INDICATOR_NOT_APPLICABLE  == (e_origin_of_call_indicator)origin_of_call_indicator )
	{
		origin_of_call_indicator = (int)NATIONAL_CALL;
	}
	else if ((int)CPE_WAP == call_partner_extension && // 0x80 from switch when WAP numbers are used
		INDICATOR_NOT_APPLICABLE  == (e_origin_of_call_indicator)origin_of_call_indicator )
		origin_of_call_indicator = (int)NATIONAL_CALL;



	// set locale with the fixed up origin of call indicator
	locale_id		= decode_origin_of_call_indicator(origin_of_call_indicator);
	
	// execption handler to catch generated calls, the orignal call will have all
	// the parameters properly set, when caller is on roaming without IDD the call will get
	// rejected. This handler will rate the roaming calls for this case. The advantage is roaming
	// can also be seperated from normal IDD rates.
	if (ms_location_identity == "RRI")  // generated call !!!
	{
		int_decoded_service = AIR;
		call_type_id = decode_type_of_call(type_of_call);
		return true;
	}

	// regular call decoding
	if( NATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator &&
		    TELEPHONY == (e_required_tele_service)required_tele_service )
	{
		int_decoded_service = TEL;
	}
	else  if(INTERNATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator &&
				      TELEPHONY == (e_required_tele_service)required_tele_service &&
		 ORIGINATING_CALL_RADIO == (e_type_of_call)type_of_call )
	{
		int_decoded_service = IDD;
	}
	// automatic international roaming 
	else if (
		 (e_type_of_call)type_of_call		== REROUTED_TERMINATING_CALL &&
		 ms_location_identity.substr(0,2)	!= "77"  // non dialog msrn number
		)
	{
		int_decoded_service = AIR;
	}
	else if(SMS_MO_PP == (e_required_tele_service)required_tele_service)
	{
		int_decoded_service = SMS;
	}
	else if(SMS_MT_PP == (e_required_tele_service)required_tele_service ) 
	{
		int_decoded_service = SMS;
	}

	else if (FAX_G3_SPEECH == (e_required_tele_service)required_tele_service ||
			 AUTO_FAX_G3 == (e_required_tele_service)required_tele_service )
	{
		if (NATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator) 
		{
			int_decoded_service = FAX;
		}
		///*
		else if (INTERNATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator)
		{
		  	int_decoded_service = IDDF;
		}
		else
		{
			f_log<<" decode failure for fax "<<endl;
		}
		//*/
	}
	else if (NOT_USED == (e_required_tele_service)required_tele_service && (required_bearer_service != 0xff)) 
	{
		//
		if (NATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator) 
		{
			int_decoded_service = DATA;
		}
		///*
		else if(INTERNATIONAL_CALL == (e_origin_of_call_indicator)origin_of_call_indicator)
		{
		  	int_decoded_service = IDDD;
		}
		else
		{
			f_log<<" decode failure for data "<<endl;
		}
		//*/
	}
	// resolving the balance if any
	else if ( TELEPHONY == (e_required_tele_service)required_tele_service )
		int_decoded_service = TEL;
	else if ( ( SMS_MT_PP == (e_required_tele_service)required_tele_service ) || ( SMS_MO_PP == (e_required_tele_service)required_tele_service ) )
		int_decoded_service = SMS;
	else if ( ( FAX_G3_SPEECH == (e_required_tele_service)required_tele_service ) || ( AUTO_FAX_G3 == (e_required_tele_service)required_tele_service ) )
		int_decoded_service = FAX;
	else if ( VOICE_MAIL == (e_required_tele_service)required_tele_service )
		int_decoded_service = VM;
	else f_log << " <ERROR> : unresolved service "<<endl;


	if ("41302"  != mobile_subscriber_identity.substr(0,5)  )
	{
		roam = 1;
	}
	else if( (int)CPE_NATIONAL == call_partner_extension && (gsm_vm_call_partners->is_vm_call_partner(call_partner_identity)) )
	{
			int_decoded_service = VM;
			call_partner_network_id="077";	// short number  will be skipped by nework decode ( <4) so unscathed
	}
	
	call_type_id = decode_type_of_call(type_of_call);

	if ( (int_decoded_service == SMS) && ("41302"  == mobile_subscriber_identity.substr(0,5) ) )
		sms_local_imsi = true;

	return true;
}


// extract the network from the call partner
// some calls may not get decodede networks but will still get rated for cases
// like voice mail.

bool rated_cdr::decode_network()
{
	if ((int)CPE_NATIONAL == call_partner_extension && call_partner_identity.length() ==0)
	{
		call_partner_network_id = "-1";  // exception handler to for IDD calls that have no call partner 
		return true;				     // -1 belongs to "NONDG" group at the minimum
	}
	else if(call_partner_identity.length() < 4) // abort search as number is not valid, may match wild card rule
	{
		return false;
	}

	// Introduced for Optimal Routing - MO Calls with Local IMSI (or_indicator = 3)
	if(or_indicator == 3)
	{
		call_partner_network_id = "077";
		return true;
	}
	
	string cpi; // call partner identity

	// all local networks start with leading 0 and are in the form 0[0-9][0-9] or 0[0-9] but fixup if doesnt
	// or_indicator checks to avoid adding leading 0 for OR MO Calls with Foreign IMSI (or_indicator = 3)
	if((int)CPE_NATIONAL == call_partner_extension && call_partner_identity.substr(0,1) != "0" && or_indicator != 2)
		cpi = "0"+call_partner_identity; 
	else
		cpi = call_partner_identity;

	gsm_call_partner_networks->get_partner_network(cpi, call_partner_network_id, call_partner_telephone_no);

	return true;
}


bool rated_cdr::fix_call_partner_identity()
{
	// all local networks start with leading 0 and are in the form 0[0-9][0-9] or 0[0-9] but fixup if doesnt
	if (call_partner_identity.length()== 0)
	{
		db_call_partner_identity = "-1";
	}
	else
	{
		if(call_partner_identity.substr(0,1) != "0") 
			db_call_partner_identity = call_partner_identity;
		else
		{
			db_call_partner_identity = call_partner_identity.substr(1, call_partner_identity.length());
		}
	}

	return true;
}




bool rated_cdr::generate_first_cdr()
{
	if( // call-forwarding to a number other than voice mail
				(type_of_call == GMSC_FORWARDED_TERMINATING_CALL ||
				type_of_call == MSC_FORWARDED_TERMINATING_CALL) 	)
	{
		call_partner_identity			= ms_location_identity;
		call_partner_extension			= ms_location_identity_extention;
		// for roaming idd forwards
		if((int)CPE_INTERNATIONAL == call_partner_extension )  
		origin_of_call_indicator = INTERNATIONAL_CALL;

		ms_location_identity				= "FWD"; // possible bomb ??? char in numeric context field :TODO 
		ms_location_identity_extention		= 0;
		type_of_call						= ORIGINATING_CALL_RADIO;
		call_type_id						= "ORIGIN";
		file_pos							*= -1;				// indicate  generated outgoing cdr
		
		return true;
	} 
	else if ( // re-routed terminated international calls for outbound roaming
				type_of_call == REROUTED_TERMINATING_CALL &&
				ms_location_identity.substr(0,2) != "77"  // non dialog msrn number
				)
	{
		original_call_partner_identity	= call_partner_identity; // save for later use
		original_call_partner_extension	= call_partner_extension;
		call_partner_identity			= ms_location_identity;
		call_partner_extension			= ms_location_identity_extention;
		type_of_call					= ORIGINATING_CALL_RADIO;
		call_type_id					= "ORIGIN";
		ms_location_identity			= "RRI";			// possible bomb ??? char in numeric context field :TODO (ajit)
		origin_of_call_indicator		= INTERNATIONAL_CALL;
		file_pos						*= -1;				// indicate  generated outgoing cdr
		
		return true;
	}

	return false;
}

bool rated_cdr::generate_second_cdr()
{
	if ( ms_location_identity == "RRI")
	{
		call_partner_identity			= original_call_partner_identity;
		call_partner_extension			= original_call_partner_extension;
		type_of_call					= TERMINATING_CALL_RADIO;
		call_type_id					= "TERMI";
		ms_location_identity			= "TNN"; // Terminated national call
		origin_of_call_indicator		= NATIONAL_CALL;
		file_pos						+= -1;				// as bytes pos no duplicates will occur

		return true;
	}
		
	return false;
}

bool rated_cdr::process_optimal_routed_calls()
{
	// or MO calls 
	if (type_of_call == 0x0 && call_partner_identity.substr(0,1) == "#" && required_bearer_capability.substr(0,3) == "ORO")
	{
		if("41302"  != mobile_subscriber_identity.substr(0,5) )
		{			
			or_indicator = 2;			// with Forign IMSI (or_indicator = 2)
			
			int call_partner_length = strlen(call_partner_identity.c_str());
			call_partner_identity = "#9477" +  call_partner_identity.substr(1,call_partner_length);
		}
		else 
			or_indicator = 3;			// with Local IMSI  (or_indicator = 3)

		// removing the leading #
		//int call_partner_length = strlen(call_partner_identity.c_str());
		//call_partner_identity = call_partner_identity.substr(1,call_partner_length); 

		return true;
	}
	// or MT calls converting to MO
	else if(type_of_call == 0x01 && required_bearer_capability.substr(0,3) == "ORI")
	{
		or_indicator = 1;

		type_of_call = 0x0;			// originating
		call_partner_extension= (int)CPE_NATIONAL;

		// if call partner is International, then 9477 is appended
		if ( (call_partner_identity.substr(0,2) != "77") && (call_partner_identity.substr(0,3) != "077") )
			call_partner_identity = "9477" +  call_partner_identity;
		
		return true;
	}

	return false;
}

