// AFXDROPDOWNCtrl.cpp : Implementation of the CAFXDROPDOWNCtrl ActiveX Control class.

#include "stdafx.h"
#include "AFXDROPDOWN.h"
#include "AFXDROPDOWNCtrl.h"
#include "AFXDROPDOWNPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CAFXDROPDOWNCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CAFXDROPDOWNCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CAFXDROPDOWNCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CAFXDROPDOWNCtrl, COleControl)
	DISP_FUNCTION_ID(CAFXDROPDOWNCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CAFXDROPDOWNCtrl, COleControl)
		EVENT_CUSTOM_ID("OnSelChange", DISPID_SEL_CHANGE, FireOnSelChange, VTS_NONE)
		EVENT_CUSTOM_ID("OnSetFocus", DISPID_CBN_SET_FOCUS, FireOnSetFocus, VTS_NONE)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAFXDROPDOWNCtrl, 1)
	PROPPAGEID(CAFXDROPDOWNPropPage::guid)
END_PROPPAGEIDS(CAFXDROPDOWNCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAFXDROPDOWNCtrl, "AFXDROPDOWN.AFXDROPDOWNCtrl.1",
	0x61fa3b1, 0x6249, 0x4b10, 0xbf, 0x85, 0xca, 0xc7, 0x2a, 0x3d, 0xbc, 0x52)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CAFXDROPDOWNCtrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID IID_DAFXDROPDOWN = { 0xBB89747D, 0x60E2, 0x4856, { 0xAD, 0x95, 0x71, 0xA5, 0xE2, 0x92, 0xE8, 0x41 } };
const IID IID_DAFXDROPDOWNEvents = { 0x361FD132, 0x1B21, 0x4FF8, { 0x94, 0xEA, 0x81, 0xD9, 0x5D, 0xAB, 0xB3, 0xDF } };


// Control type information

static const DWORD _dwAFXDROPDOWNOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAFXDROPDOWNCtrl, IDS_AFXDROPDOWN, _dwAFXDROPDOWNOleMisc)



// CAFXDROPDOWNCtrl::CAFXDROPDOWNCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAFXDROPDOWNCtrl

BOOL CAFXDROPDOWNCtrl::CAFXDROPDOWNCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_AFXDROPDOWN,
			IDB_AFXDROPDOWN,
			afxRegApartmentThreading,
			_dwAFXDROPDOWNOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CAFXDROPDOWNCtrl::CAFXDROPDOWNCtrl - Constructor

CAFXDROPDOWNCtrl::CAFXDROPDOWNCtrl()
{
	InitializeIIDs(&IID_DAFXDROPDOWN, &IID_DAFXDROPDOWNEvents);
	// TODO: Initialize your control's instance data here.
}



// CAFXDROPDOWNCtrl::~CAFXDROPDOWNCtrl - Destructor

CAFXDROPDOWNCtrl::~CAFXDROPDOWNCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CAFXDROPDOWNCtrl::OnDraw - Drawing function

void CAFXDROPDOWNCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}



// CAFXDROPDOWNCtrl::DoPropExchange - Persistence support

void CAFXDROPDOWNCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CAFXDROPDOWNCtrl::OnResetState - Reset control to default state

void CAFXDROPDOWNCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CAFXDROPDOWNCtrl::AboutBox - Display an "About" box to the user

void CAFXDROPDOWNCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_AFXDROPDOWN);
	dlgAbout.DoModal();
}



// CAFXDROPDOWNCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CAFXDROPDOWNCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("ComboBox");
	return COleControl::PreCreateWindow(cs);
}



// CAFXDROPDOWNCtrl::IsSubclassedControl - This is a subclassed control

BOOL CAFXDROPDOWNCtrl::IsSubclassedControl()
{
	return TRUE;
}



// CAFXDROPDOWNCtrl::OnOcmCommand - Handle command messages

LRESULT CAFXDROPDOWNCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

switch(wNotifyCode)
{
case CBN_SETFOCUS:
	FireOnSetFocus();
	break;
case CBN_SELCHANGE:
	FireOnSelChange();
	break;
}
	// TODO: Switch on wNotifyCode here.

	return 0;
}



// CAFXDROPDOWNCtrl message handlers
