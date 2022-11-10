#include "StdAfx.h"
#include "CObj__MFC_IO.h"

#include "CCommon_Utility.h"


//----------------------------------------------------------------------------------------------------
int  CObj__MFC_IO::
Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}

int  CObj__MFC_IO::
Call__OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	double cfg_max  = aCH__CFG_MFC_MAX_VALUE->Get__VALUE();
	double set_flow = cfg_max;
	sCH__MON_MFC_STATE->Set__DATA(STR__OPEN); // KMS


	return Fnc__CONTROL(set_flow, 1, cfg_max);
}
int  CObj__MFC_IO::
Call__CLOSE(CII_OBJECT__VARIABLE* p_variable,
			CII_OBJECT__ALARM* p_alarm)
{
	double cfg_max  = aCH__CFG_MFC_MAX_VALUE->Get__VALUE();
	double set_flow = 0.0;
	sCH__MON_MFC_STATE->Set__DATA(STR__CLOSE); // KMS

	return Fnc__CONTROL(set_flow, -1, cfg_max);
}

int  CObj__MFC_IO::
Call__PURGE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int i;

	if(iSIZE__VLV_PURGE_IN < 1)
	{
		return 0;
	}

	for(i=0; i<iSIZE__VLV_IN; i++)
	{
		dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
	{
		dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
	{
		dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
	{
		dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_PURGE_OUT; i++)
	{
		dEXT_CH__IO_VLV_PURGE_OUT_X[i]->Set__DATA(STR__OPEN);
	}
	for(i=0; i<iSIZE__VLV_PURGE_IN; i++)
	{
		dEXT_CH__IO_VLV_PURGE_IN_X[i]->Set__DATA(STR__OPEN);
	}

	// ...
	double cfg_max = aCH__CFG_MFC_MAX_VALUE->Get__VALUE();

	return Fnc__SET_FLOW(cfg_max);
}

int  CObj__MFC_IO::
Call__LINE_PURGE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm) // KMS ADD
{
	int i;

	for(i=0; i<iSIZE__VLV_IN; i++)
	{
		dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__OPEN);
	}

	for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
	{
		dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
	{
		dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
	{
		dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_PURGE_OUT; i++)
	{
		dEXT_CH__IO_VLV_PURGE_OUT_X[i]->Set__DATA(STR__OPEN);
	}
	for(i=0; i<iSIZE__VLV_PURGE_IN; i++)
	{
		dEXT_CH__IO_VLV_PURGE_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	// ...
	double cfg_max = aCH__CFG_MFC_MAX_VALUE->Get__VALUE();

	return Fnc__SET_FLOW(cfg_max);
}

int  CObj__MFC_IO::
Call__GAS_LINE_PURGE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int i;

	if(iSIZE__VLV_PURGE_IN < 1)
	{
		return 0;
	}

	for(i=0; i<iSIZE__VLV_IN; i++)
	{
		dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
	{
		dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
	{
		dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
	{
		dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_PURGE_OUT; i++)
	{
		dEXT_CH__IO_VLV_PURGE_OUT_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_PURGE_IN; i++)
	{
		dEXT_CH__IO_VLV_PURGE_IN_X[i]->Set__DATA(STR__OPEN);
	}

	//
	return Fnc__SET_FLOW(0.0);
}
int  CObj__MFC_IO::
Call__CHM_LINE_PURGE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int i;

	for(i=0; i<iSIZE__VLV_PURGE_IN; i++)
	{
		dEXT_CH__IO_VLV_PURGE_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_PURGE_OUT; i++)
	{
		dEXT_CH__IO_VLV_PURGE_OUT_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_IN; i++)
	{
		dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
	{
		dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
	{
		dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
	{
		dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__OPEN);
	}

	return Fnc__SET_FLOW(0.0);
}

int  CObj__MFC_IO::Call__CONTROL(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	double cfg_max  = aCH__CFG_MFC_MAX_VALUE->Get__VALUE();
	double set_flow = aCH__PARA_SET_VALUE->Get__VALUE();

	return Fnc__CONTROL(set_flow, 1, cfg_max);
}
int  CObj__MFC_IO
::Fnc__CONTROL(const double set_flow, const int open_mode, const double cfg_max)
{
	Fnc__SET_FLOW(set_flow); // KMS Prevent Range Error
	_Open__VALVE(set_flow, open_mode, cfg_max);
	
	return 1;
}
int  CObj__MFC_IO
::_Open__VALVE(const double set_flow, const int open_mode, const double cfg_max)
{
	int i;

	for(i=0; i<iSIZE__VLV_PURGE_IN; i++)
	{
		dEXT_CH__IO_VLV_PURGE_IN_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_PURGE_OUT; i++)
	{
		dEXT_CH__IO_VLV_PURGE_OUT_X[i]->Set__DATA(STR__CLOSE);
	}

	if(open_mode > 0)
	{
		bool active__flow_center = false;
		bool active__flow_edge   = false;

		CString cfg__flow_mode = dCH__CFG_FLOW_MODE->Get__STRING();

		if(cfg__flow_mode.CompareNoCase("CENTER") == 0)		active__flow_center = true;
		else if(cfg__flow_mode.CompareNoCase("EDGE")   == 0)		active__flow_edge   = true;
		else
		{
			active__flow_center = true;
			active__flow_edge   = true;
		}

		// Out.All ...
		{
			for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
				dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__OPEN);
		}
		// Out.Center ...
		if(active__flow_center)
		{
			for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
				dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__OPEN);
		}
		else
		{
			for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
				dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
		}
		// Out.Edge ...
		if(active__flow_edge)
		{
			for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
				dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__OPEN);
		}
		else
		{
			for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
				dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
		}

		for(i=0; i<iSIZE__VLV_IN; i++)
		{
			dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__OPEN);
		}
	}
	else
	{
		_Close__ALL_VALVE();
	}

	return 1;
}
int  CObj__MFC_IO
::_Close__ALL_VALVE()
{
	int i;

	for(i=0; i<iSIZE__VLV_IN; i++)
	{
		dEXT_CH__IO_VLV_IN_X[i]->Set__DATA(STR__CLOSE);
	}

	for(i=0; i<iSIZE__VLV_OUT_ALL; i++)
	{
		dEXT_CH__IO_VLV_OUT_ALL_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_CENTER; i++)
	{
		dEXT_CH__IO_VLV_OUT_CENTER_X[i]->Set__DATA(STR__CLOSE);
	}
	for(i=0; i<iSIZE__VLV_OUT_EDGE; i++)
	{
		dEXT_CH__IO_VLV_OUT_EDGE_X[i]->Set__DATA(STR__CLOSE);
	}
	return 1;
}

int  CObj__MFC_IO
::Call__RAMP_CTRL(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM*    p_alarm)
{
	double min_value;
	double max_value;
	int i_dec;

	aCH__PARA_SET_VALUE->Get__MIN_MAX_DEC(min_value,max_value,i_dec);
	double set_flow = aCH__PARA_SET_VALUE->Get__VALUE();

	return Fnc__RAMP_CTRL(p_variable, set_flow, 1, max_value);
}
int  CObj__MFC_IO
::Fnc__RAMP_CTRL(CII_OBJECT__VARIABLE* p_variable, const double set_flow, const int open_mode, const double cfg_max)
{
	_Open__VALVE(set_flow, open_mode, cfg_max);

	// ...
	double para__ramp_sec = aCH__PARA_RAMP_SEC->Get__VALUE();

	if(para__ramp_sec > 0.1)
	{
		double ref__loop_sec = 0.1;
		double ref_value;

		if(iLINK_DATA__TYPE == _DATA_TYPE__HEXA)
		{
			CCommon_Utility m_fnc;

			CString ch_data = sEXT_CH__IO_MFC_SET_HEXA->Get__STRING();

			CStringArray l_data;
			m_fnc.Get__StringArrray_From_String(ch_data, " ", l_data);

			double ref_hexa = (double) m_fnc.Get__Hexa_From_String(ch_data);// KMS : ERROR_BROKUP
			ref_value = cfg_max * (ref_hexa / iLINK_DATA__MAX_FLOW);
		}
		else
		{
			ref_value = aEXT_CH__IO_MFC_SET_DEC->Get__VALUE();
		}

		int loop_size = (int) para__ramp_sec / ref__loop_sec;
		double dif_set = set_flow - ref_value;
		double inc_set = dif_set / loop_size;
		double set_value = ref_value;

		double inc_min = cfg_max * 0.01;
		if(abs(dif_set) < inc_min)
		{
			sCH__OBJ_TIMER->Set__DATA("__");
		}
		else
		{
			SCX__TIMER_CTRL x_timer_ctrl;

			SCX__ASYNC_TIMER_CTRL x_timer_count;
			x_timer_count->REGISTER__COUNT_CHANNEL_NAME(sCH__OBJ_TIMER->Get__CHANNEL_NAME());
			x_timer_count->START__COUNT_UP(9999);

			while(loop_size > 0)
			{
				loop_size--;
				x_timer_ctrl->POLL(ref__loop_sec);

				if(p_variable->Check__CTRL_ABORT() > 0)
				{
					return -1;
				}

				// ...
				bool active__trg_set = false;

				set_value += inc_set;
				
				if(inc_set > 0)		
				{
					if(set_value > set_flow)
					{
						set_value = set_flow;

						active__trg_set = true;
					}
				}
				else  if(inc_set < 0)
				{
					if(set_value < set_flow)
					{
						set_value = set_flow;
			
						active__trg_set = true;
					}
				}
				else
				{
					set_value = set_flow;

					active__trg_set = true;
				}

				Fnc__SET_FLOW(set_value);

				if(active__trg_set)			break;
			}
		}
	}

	Fnc__SET_FLOW(set_flow);
	return 1;
}

int  CObj__MFC_IO
::Call__SET_FLOW(CII_OBJECT__VARIABLE* p_variable,
			     CII_OBJECT__ALARM*    p_alarm)
{
	double set_flow = aCH__PARA_SET_VALUE->Get__VALUE();

	return Fnc__SET_FLOW(set_flow);
}
int  CObj__MFC_IO
::Fnc__SET_FLOW(const double set_flow)
{
	double min_value;
	double max_value;
	int i_dec;

	aCH__PARA_SET_VALUE->Get__MIN_MAX_DEC(min_value,max_value,i_dec);

	// ...
	CString ch_data;

	ch_data.Format("%.2f", set_flow);
	aCH__MON_MFC_SET_FLOW->Set__DATA(ch_data);

	if(iLINK_DATA__TYPE == _DATA_TYPE__HEXA)
	{
		CString str__hexa_type = dCH__CFG_HEXA_TYPE_FLOW->Get__STRING();

		if(str__hexa_type.CompareNoCase(STR__REAL) == 0)
		{
			double set_ratio = set_flow / max_value;

			// ...
			{
				ch_data.Format("%.1f", set_ratio*100.0);
				sCH__MON_MFC_SET_PERCENT->Set__DATA(ch_data);
			}

			// ...
			{
				UNION_4_BYTE__FLOAT m_float;
				m_float.fDATA = set_flow;

				CString ch_hexa;
				ch_data = "";

				int i_limit = 4;
				for(int i=0; i<i_limit; i++)
				{
					ch_hexa.Format("%02X ", 0x0ff & m_float.cBYTE[i]);
					ch_data += ch_hexa;
				}
			
				sEXT_CH__IO_MFC_SET_HEXA->Set__DATA(ch_data);

				if(iActive__SIM_MODE > 0)
				{
					sEXT_CH__IO_MFC_READ_HEXA->Set__DATA(ch_data);
				}
			}
		}
		else
		{
			int max_hexa = iLINK_DATA__MAX_FLOW;

			double set_ratio = set_flow / max_value;
			int set_hexa = (int)(max_hexa * set_ratio);

			if(set_hexa > 0x7fff)		set_hexa = 0x7fff;
			if(set_hexa < 0)			set_hexa = 0;

			// ...
			{
				ch_data.Format("%.1f", set_ratio*100.0);
				sCH__MON_MFC_SET_PERCENT->Set__DATA(ch_data);
			}

			// ...
			{
				UNION_2_BYTE__UINT m_uint;
				m_uint.uiDATA = 0xffff & set_hexa;

				CString ch_hexa;
				ch_data = "";

				int i_limit = 2;
				for(int i=0; i<i_limit; i++)
				{
					ch_hexa.Format("%02X ", 0x0ff & m_uint.cBYTE[i]);
					ch_data += ch_hexa;
				}

				sEXT_CH__IO_MFC_SET_HEXA->Set__DATA(ch_data);

				if(iActive__SIM_MODE > 0)
				{
					sEXT_CH__IO_MFC_READ_HEXA->Set__DATA(ch_data);
				}
			}
		}

		// ...
	}
	else
	{
		aEXT_CH__IO_MFC_SET_DEC->Set__DATA(ch_data);

		if(iActive__SIM_MODE > 0)
		{
			aEXT_CH__IO_MFC_READ_DEC->Set__DATA(ch_data);
		}

		// 
		double set_ratio = set_flow / max_value;
		ch_data.Format("%.1f", set_ratio*100.0);

		sCH__MON_MFC_SET_PERCENT->Set__DATA(ch_data);
	}

	return 1;
}

