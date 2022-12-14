#include "StdAfx.h"
#include "CCommon_SYSTEM.h"


// ...
int  Macro__CHECK_LPx_INDEX(const CString& stn_name)
{
	CString lp_name;
	int i;

	for(i=0;i<CFG_LPx__SIZE;i++)
	{
		lp_name.Format("LP%1d",i+1);
		if(stn_name.CompareNoCase(lp_name) != 0)		continue;

		return i;
	}
	return -1;
}

int  Macro__CHECK_PMx_INDEX(const CString& stn_name)
{
	CString pm_name;
	int i;

	for(i=0;i<CFG_PMx__SIZE;i++)
	{
		pm_name.Format("PM%1d",i+1);
		if(stn_name.CompareNoCase(pm_name) != 0)		continue;

		return i;
	}
	return -1;
}

int  Macro__CHECK_LLx_INDEX(const CString& stn_name)
{
	if(stn_name.CompareNoCase(STR__LBA) == 0)			return 0;
	if(stn_name.CompareNoCase(STR__LBB) == 0)			return 1;
	if(stn_name.CompareNoCase(STR__LBC) == 0)			return 2;
	if(stn_name.CompareNoCase(STR__LBD) == 0)			return 3;

	return -1;
}
