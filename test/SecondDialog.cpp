#include "SecondDialog.h"


CSecondDialog::CSecondDialog()
{
}


CSecondDialog::~CSecondDialog()
{
}

LPCTSTR CSecondDialog::GetWindowClassName() const
{
	return "第二个对话框";
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

