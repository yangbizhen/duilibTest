#pragma once

#include "..\DuiLib\UIlib.h"
#include "SecondDialog.h"
using namespace DuiLib;


class CDUIMainFrame : public WindowImplBase
{
public:
	CDUIMainFrame();
	~CDUIMainFrame();
	virtual LPCTSTR GetWindowClassName()const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual void   Notify(TNotifyUI& msg);
private:
	virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
   BOOL IsInStaticControl(CControlUI * pControl);
	
};



