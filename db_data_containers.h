

/////////////////////////////////////////////////////////////////////
//
// db_data_containers.h: definitions for main classes.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdio.h>

using namespace std;


static const int MIN_YEAR = 1949;
static const int MAX_YEAR = 2051;
static const char* WILD_CARD="UNDEF";

typedef enum {T_UNDEF, T_ON, T_OFF} e_token_state;


typedef enum
{
	C_NO_INDICATION	= 0x0,
	C_CHARGE		= 0x1,
	C_NO_CHARGE		= 0x2,
	C_NOT_APPLICABLE= 0xf
} e_charging_indicator;

typedef enum
{
	NATIONAL_CALL				= 0x0,
	INTERNATIONAL_CALL			= 0x1,
	MANUAL_NATIONAL_CALL		= 0x2,
	MANUAL_INTERNATIONAL_CALL	= 0x3,
	INDICATOR_NOT_APPLICABLE	= 0xf
} e_origin_of_call_indicator;

typedef enum
{
	ORIGINATING_CALL_RADIO					= 0x0,
	TERMINATING_CALL_RADIO					= 0x1,
	MSC_FORWARDED_TERMINATING_CALL			= 0x2,
	REROUTED_TERMINATING_CALL				= 0x4,
	GMSC_FORWARDED_TERMINATING_CALL			= 0x6,
	ORIGINATING_CALL_RADIO_WITH_HOT_BILLING = 0xd,
	TERMINATING_CALL_WITH_HOT_BILLING		= 0xe,
	MSC_FORWARDED_TERMINATING_CALL_RADIO_WITH_HOT_BILLING=0xf
} e_type_of_call;

typedef enum
{
	MSC				= 0x0,
	GMSC			= 0x1,
	IWGMSC			= 0x3
} e_type_of_msc;

typedef enum
{
	TELEPHONY		= 0x11,
	EMERGENCY_CALLS	= 0x12,
	SMS_MT_PP		= 0x21,
	SMS_MO_PP		= 0x22,
	FAX_G3_SPEECH	= 0x61,
	AUTO_FAX_G3		= 0x62,
	VOICE_MAIL		= 0x77,
	NOT_USED		= 0xff
} e_required_tele_service;

typedef enum
{
	CPE_NATIONAL		= 0xa0, // 160
	CPE_INTERNATIONAL	= 0x90, // 144
	CPE_WAP				= 0x80	// 128
} e_call_partner_ext; 


char* decode_type_msc(int tmsc);
char* decode_type_of_call( int toc);
char* decode_call_termination_type(int ctt);
char* decode_origin_of_call_indicator(int ooci);
char* decode_charging_indicator(int ci);
char* decode_required_tele_service(int rts);
char* decode_required_bearer_service(int rbs);
char* decode_required_bearer_service(int rbs);
char* decode_required_bearer_capability(int rbc);
int decode_decoded_service(const char* decoded_service);

class rating_observer;
class rated_cdr;
class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);




// CDR -- begin ---------------------------------------------------------------
class r4_cdr_decode;

class rated_cdr
{
public:
		
	int file_id;			// the number of the file
	int file_pos;			// the bytes from start of cdr where file started

	// call detail
	int type_of_msc;
	int type_of_call;
	int call_termination_type;
	int origin_of_call_indicator;
	int charging_indicator;
	int required_tele_service;
	int required_bearer_service;

	int call_duration;
	int invoked_supplementary_services;
	string required_bearer_capability;

	string mobile_station_identity;
	string link_information;
	string mobile_subscriber_identity;
	int msc_identity_extension;
	string msc_identity;

	int call_partner_extension;
	int true_cpe;						// this is the correct call_partner_extention
	string call_partner_identity;		// needs unpacking to get all the info
	string ms_location_identity;
	int ms_location_identity_extention;

	// call timing stuff
	string circuit_allocation_time_stamp;
	string call_time_stamp;
	string fixed_network_info;

	//other
	string locale_id;
	int	int_decoded_service;			// Integer valuse for rating for decoded service

	// decoded stuff
	reng_time d_circuit_allocation_time;
	reng_date d_circuit_allocation_date;
	
	string call_type_id;
										// used only to get a fix on rate group.
	// call partner info
	string call_partner_network_id;		// telephone company 077=dialog, 074=suntel.
	string call_partner_telephone_no;	// 6 digits

	string mcc;							// mobile country code
	string mnc;							// mobile network code
	int lac;							// location area code
	int ci;								// cell id
 
	int roam;							// 1 for roaming and 0 for non-roaming
	string db_call_partner_identity;	// value written to db after fixing for starting 0
	// Optimal Routed indicator
	int or_indicator;					// non or	= 0 -- default value
										// or MT	= 1
										// or MO with Forign IMSI = 2
										// or MO with Local IMSI  = 3

	bool sms_local_imsi;				// true = sms calls with local imsi (to prevent sms login to db)


	

	bool unpack(r4_cdr_decode *a);
	void init(int f_id, int f_pos);
	bool decode_service();
	bool decode_network();
	
	bool print();

	bool generate_first_cdr();
	bool generate_second_cdr();
	bool fix_call_partner_identity();
	bool process_optimal_routed_calls();			// To convert Optimal Routed MT to MO
};

ostream& operator<<(ostream& out, rated_cdr x);


// dyn_7_udr - begin ---------------------------------------------------------------------

typedef set<string> CERVICE_CENTERS_DEF;

class dyn_7_udr
{
public:
		
	int file_id;			// the number of the file
	int file_pos;			// the bytes from start of cdr where file started

	string	originating_address;			
	string	destination_IMSI;					
	string	rate_call_partner;
	string	rate_call_type;
	int		rate_sub_service_type;

	string circuit_allocation_time_stamp;
	// decoded stuff
	reng_time d_circuit_allocation_time;
	reng_date d_circuit_allocation_date;

	CERVICE_CENTERS_DEF	dialog_service_centers;
	CERVICE_CENTERS_DEF	local_service_centers;

	void init(int f_id, int f_pos, string imsi, string call_partner, string cdr_circuit_allocation_time_stamp);
	bool insert_dialog_service_centers(string service_center);
	bool insert_local_service_centers(string service_center);
	bool is_not_dialog_service_center(string cdr_service_center);
	bool is_local_service_center(string cdr_service_center);
	void db_read_med_dialog_service_centers();
	void db_read_med_local_service_centers();
};

// dyn_7_udr - end ---------------------------------------------------------------------

class token
{
public:
	e_token_state token_state;
	string file_name;
	string token_text;

	FILE *token_file;

	bool set_token(e_token_state a);
	token(string f_name);
	bool is_runable(void);
	e_token_state code_token(string a);
	string decode_token(e_token_state a);
};


// networks -- begin ---------------------------------------------------------
// all the networks contacted by the operator

typedef map<string, int, less<string> > N_CALL_PART_DEF;

typedef set<string> VM_CALL_PARTNERS_DEF;

class call_partner_networks
{
public:
	N_CALL_PART_DEF c_partner_networks;
	bool insert(string network_id, int locale);
	bool get_partner_network(string call_partner, string &network_no, string &tel_no);
	bool is_national(string network_id);
	void db_read();
	void print();
};

// networks -- end ------------------------------------------------------------

// voice mail call partners -- begin ---------------------------------------------------------

typedef set<string> VM_CALL_PARTNERS_DEF;

class vm_call_partners
{
public:
	VM_CALL_PARTNERS_DEF vm_call_partner_numbers;
	bool insert(string call_partner);
	bool is_vm_call_partner(string cdr_call_partner);
	void db_read();
	void print();
};

// voice mail call partners -- end ------------------------------------------------------------


