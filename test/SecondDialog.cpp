#include "SecondDialog.h"


CSecondDialog::CSecondDialog()
{
}


CSecondDialog::~CSecondDialog()
{
}

LPCTSTR CSecondDialog::GetWindowClassName() const
{
	return "�ڶ����Ի���";
}

DuiLib::CDuiString CSecondDialog::GetSkinFile()
{
	return "jindu.xml";
}

DuiLib::CDuiString CSecondDialog::GetSkinFolder()
{
	return "skin";
}

void CSecondDialog::Notify(TNotifyUI& msg)
{

}

