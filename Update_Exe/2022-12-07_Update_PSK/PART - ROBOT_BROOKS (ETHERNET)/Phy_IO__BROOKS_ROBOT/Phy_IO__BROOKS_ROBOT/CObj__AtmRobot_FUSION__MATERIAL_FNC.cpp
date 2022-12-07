#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Set__ROBOT_MATERIAL_SLOT(const CString& material_sts)
{
	CString sGet_Mat;

	if(material_sts.CompareNoCase("EXIST") ==0 )
	{
		dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(sGet_Mat);

		if( (sGet_Mat.CompareNoCase("NONE") == 0) || 
		(sGet_Mat.CompareNoCase("UNKNOWN") == 0) ) 
		{
			dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(material_sts);
		}
	}
	else
	{
		dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(material_sts);
	}

	return 1;
}

int  CObj__AtmRobot_FUSION
::Set__ROBOT_ANI(const CString& command,
			     const CString& stn_name)
{
	if((command.CompareNoCase("HOME")   == 0)	
	|| (command.CompareNoCase("PICKED") == 0)
	|| (command.CompareNoCase("PLACED") == 0))
	{
		dCH__OTR_OUT_MON__TRG_MOVE->Set__DATA(stn_name);
		dCH__OTR_OUT_MON__TRG_ROTATE->Set__DATA(stn_name);
		dCH__OTR_OUT_MON__ARM_A_ACT->Set__DATA("RETRACT");
		return 1;
	}

	if((command.CompareNoCase("PICKING")  == 0)	
	|| (command.CompareNoCase("PLACEING") == 0))
	{
		dCH__OTR_OUT_MON__TRG_MOVE->Set__DATA(stn_name);
		dCH__OTR_OUT_MON__TRG_ROTATE->Set__DATA(stn_name);
		dCH__OTR_OUT_MON__ARM_A_ACT->Set__DATA("EXTEND");
		return 1;
	}

	if(command.CompareNoCase("ROTATE") == 0)
	{
		dCH__OTR_OUT_MON__TRG_MOVE->Set__DATA(stn_name);
		dCH__OTR_OUT_MON__TRG_ROTATE->Set__DATA(stn_name);
		return 1;
	}

	return 1;
}
