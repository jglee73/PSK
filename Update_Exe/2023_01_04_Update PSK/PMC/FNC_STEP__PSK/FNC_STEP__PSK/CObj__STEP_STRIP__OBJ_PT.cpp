#include "StdAfx.h"
#include "CObj__STEP_STRIP.h"
#include "CObj__STEP_STRIP__DEF.h"


// ...
int CObj__STEP_STRIP
::PT_OBJ__Check_ERROR()
{
	for(int i=0; i<iDATA__PT_SIZE; i++)
	{
		if(dEXT_CH__PT_X__MON_ABORT_ACTIVE[i]->Check__DATA(STR__ON) > 0)		return 1;
	}

	return -1;
}
