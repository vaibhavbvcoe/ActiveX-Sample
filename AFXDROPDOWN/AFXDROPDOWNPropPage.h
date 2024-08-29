#pragma once

// AFXDROPDOWNPropPage.h : Declaration of the CAFXDROPDOWNPropPage property page class.


// CAFXDROPDOWNPropPage : See AFXDROPDOWNPropPage.cpp for implementation.

class CAFXDROPDOWNPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAFXDROPDOWNPropPage)
	DECLARE_OLECREATE_EX(CAFXDROPDOWNPropPage)

// Constructor
public:
	CAFXDROPDOWNPropPage();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX_AFXDROPDOWN };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

