#pragma once
#include "..\DuiLib\UIlib.h"
using namespace DuiLib;

class CSecondDialog :public WindowImplBase
{
public:
	CSecondDialog();
	~CSecondDialog();
	virtual LPCTSTR GetWindowClassName()const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual void   Notify(TNotifyUI& msg);
	
};

