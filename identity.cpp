
/////////////////////////////////////////////////////////////////////
//
// identity.cpp: implementation of the no_identity class.
// R4 Mediation Engine
// developer - Chandika Nettasinghe
// development - 2002
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "defines.h"


void no_identity::init()
{
	ext=0;
	id[0]='\0';
}


ostream& operator<<(ostream& out, no_identity x)
{
    out<<x.ext<<", "<<x.id;
    return(out);
}
