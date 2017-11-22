#include "DUIMainFrame.h"
#include <algorithm>

CDUIMainFrame::CDUIMainFrame()
{

}

CDUIMainFrame::~CDUIMainFrame()
{

}


LPCTSTR CDUIMainFrame::GetWindowClassName()const //const±ØÐë¼Ó
{
	return _T("DUIMainFrame");
}
CDuiString CDUIMainFrame::GetSkinFile()
{
	return _T("ui.xml");
}
CDuiString CDUIMainFrame::GetSkinFolder()
{
	return _T("skin");
}

void CDUIMainFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == "click")
	{
		if (msg.pSender->GetName() == "closebtn" || msg.pSender->GetName() == "cancelbtn")
		{
			Close();
		}
		else if (msg.pSender->GetName() == "updatebtn"){
			this->ShowWindow(false);
			CSecondDialog secondDlg;
			secondDlg.Create(NULL, _T("secondWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			secondDlg.CenterWindow();
			secondDlg.ShowModal();
		}
	}
}

LRESULT CDUIMainFrame::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	POINT           pt;
	RECT            rcClient;
	CControlUI *    pControl = NULL;
	pt.x = GET_X_LPARAM(lParam);
	pt.y = GET_Y_LPARAM(lParam);
	GetClientRect(m_PaintManager.GetPaintWindow(), &rcClient);
	RECT rcCaption = m_PaintManager.GetCaptionRect();
	if (-1 == rcCaption.bottom)
	{
		rcCaption.bottom = rcClient.bottom;
	}
	
	if (pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right
		&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom)
	{
		CControlUI* pControl = m_PaintManager.FindControl(pt);
		if (IsInStaticControl(pControl))
		{
			return HTCAPTION;
		}
	}

	return HTCLIENT;
}

BOOL CDUIMainFrame::IsInStaticControl(CControlUI * pControl)
{
	BOOL bRet = FALSE;
	if (!pControl)
	{
		return bRet;
	}

	CDuiString strClassName;
	std::vector<CDuiString> vctStaticName;

	strClassName = pControl->GetClass();
	strClassName.MakeLower();
	vctStaticName.push_back(_T("controlui"));
	vctStaticName.push_back(_T("textui"));
	vctStaticName.push_back(_T("labelui"));
	vctStaticName.push_back(_T("containerui"));
	vctStaticName.push_back(_T("horizontallayoutui"));
	vctStaticName.push_back(_T("verticallayoutui"));
	vctStaticName.push_back(_T("tablayoutui"));
	vctStaticName.push_back(_T("childlayoutui"));
	vctStaticName.push_back(_T("dialoglayoutui"));

	std::vector<CDuiString>::iterator it = std::find(vctStaticName.begin(), vctStaticName.end(), strClassName);
	if (vctStaticName.end() != it)
	{
		CControlUI* pParent = pControl->GetParent();
		while (pParent)
		{
			strClassName = pParent->GetClass();
			strClassName.MakeLower();
			it = std::find(vctStaticName.begin(), vctStaticName.end(), strClassName);
			if (vctStaticName.end() == it)
			{
				return bRet;
			}

			pParent = pParent->GetParent();
		}

		bRet = TRUE;
	}

	return bRet;
}

