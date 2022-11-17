#include "StdAfx.h"
#include "CDriver__LPx_ETHERNET.h"


//------------------------------------------------------------------------------------
CString CDriver__LPx_ETHERNET::Get__CANCEL_CODE_OF_NAK(const CString err_hexa)
{
	CString err_msg;

	if(err_hexa.CompareNoCase("01") == 0)
	{
		err_msg = "���� �̿Ϸ� (Initial �̿Ϸ�)";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("02") == 0)
	{
		err_msg = "Check sum[NAK]";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("03") == 0)
	{
		err_msg = "Bad command[NAK]";
		return err_msg;
	}

	if(err_hexa.CompareNoCase("04") == 0)
	{
		err_msg = "������ Arm �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("05") == 0)
	{
		err_msg = "Error �߻� ��";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("06") == 0)
	{
		err_msg = "PAUSE ������";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("07") == 0)
	{
		err_msg = "PAUSE ���°� �ƴ�";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("08") == 0)
	{
		err_msg = "Running ������";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("09") == 0)
	{
		err_msg = "Running ���°� �ƴ�";
		return err_msg;
	}

	if(err_hexa.CompareNoCase("0A") == 0)
	{
		err_msg = "Upper Blade �� Wafer �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("0B") == 0)
	{
		err_msg = "Upper Blade �� Wafer �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("0C") == 0)
	{
		err_msg = "Lower Blade �� Wafer �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("0D") == 0)
	{
		err_msg = "Lower Blade �� Wafer �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("0E") == 0)
	{
		err_msg = "������ Slot �� Wafer �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("0F") == 0)
	{
		err_msg = "������ Slot �� Wafer �� ����";
		return err_msg;
	}

	if(err_hexa.CompareNoCase("10") == 0)
	{
		err_msg = "Robot Arm Extend.";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("11") == 0)
	{
		err_msg = "Port Disable Mode.";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("12") == 0)
	{
		err_msg = "Port Door Closed.";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("13") == 0)
	{
		err_msg = "������ Port �� FOUP �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("14") == 0)
	{
		err_msg = "Mapping �̿Ϸ� ������";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("15") == 0)
	{
		err_msg = "Position �̻�";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("15") == 0)
	{
		err_msg = "Position �̻�";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("16") == 0)
	{
		err_msg = "Port Error �߻� ��";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("17") == 0)
	{
		err_msg = "������ Port �� RFID �� ������� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("18") == 0)
	{
		err_msg = "RFID �� Error �߻� ��";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("19") == 0)
	{
		err_msg = "������ Page �� RFID �� �������� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("1A") == 0)
	{
		err_msg = "RFID	�� ������ Page �� Write �� �� ����";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("1B") == 0)
	{
		err_msg = "RFID Reading";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("1C") == 0)
	{
		err_msg = "AMHS Busy";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("1D") == 0)
	{
		err_msg = "Port �ʱ�ȭ �̿Ϸ�";
		return err_msg;
	}
	if(err_hexa.CompareNoCase("1E") == 0)
	{
		err_msg = "Port Running ���� ��";
		return err_msg;
	}
	
	err_msg = "Unknown Error";
	return err_msg;
}
