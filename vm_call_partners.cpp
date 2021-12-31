
//////////////////////////////////////////////////////////////////////
//
// vm_call_partners.cpp: 
//			implementation of the vm_call_partners class.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool vm_call_partners::insert(string call_partner)
{
	pair<VM_CALL_PARTNERS_DEF::iterator, bool> p = vm_call_partner_numbers.insert(call_partner);

	if (p.second == false)
	{
		cout<<"ERR: duplicate voice mail call partner number "<<call_partner<<endl;
		return false;
	}
	return true;
}


void vm_call_partners::print()
{
	for(VM_CALL_PARTNERS_DEF::iterator i=vm_call_partner_numbers.begin(); i!=vm_call_partner_numbers.end(); i++)
	{
		//cout<<"{"<<(*i).first<<"}"<<endl;
	}
}


bool vm_call_partners::is_vm_call_partner(string cdr_call_partner)
{
	VM_CALL_PARTNERS_DEF::iterator i;

	i = vm_call_partner_numbers.find(cdr_call_partner);
	if(i == vm_call_partner_numbers.end())
	{
		return false;		
	}
	return true;
}