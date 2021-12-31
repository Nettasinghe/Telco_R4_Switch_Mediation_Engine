

/////////////////////////////////////////////////////////////////////
//
// db.h: database interaction related functions.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////



void	db_connect(char *in_login); 
void	db_disconnect(); 
//void	db_insert_rated_cdr();
void	db_insert_rated_cdr(int cdr_count);
void	db_insert_dyn_7_udr(int cdr_count);
void	db_insert_non_charging_cdr(int cdr_count);
void	db_read_med_threshold(int &no_charge_threshold);



void db_connect_rating(char *in_login);
void db_disconnect_rating();
void db_disconnect_cust_care();




