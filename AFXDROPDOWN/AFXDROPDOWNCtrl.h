#pragma once
#include"Constants.h"

// AFXDROPDOWNCtrl.h : Declaration of the CAFXDROPDOWNCtrl ActiveX Control class.


// CAFXDROPDOWNCtrl : See AFXDROPDOWNCtrl.cpp for implementation.

class CAFXDROPDOWNCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAFXDROPDOWNCtrl)

// Constructor
public:
	CAFXDROPDOWNCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CAFXDROPDOWNCtrl();

	DECLARE_OLECREATE_EX(CAFXDROPDOWNCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CAFXDROPDOWNCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAFXDROPDOWNCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAFXDROPDOWNCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	void FireOnSelChange()
	{
		FireEvent(DISPID_SEL_CHANGE,EVENT_PARAM(VTS_NONE));
	}
	void FireOnSetFocus()
	{
		FireEvent(DISPID_CBN_SET_FOCUS,EVENT_PARAM(VTS_NONE));
	}
// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	};
};

