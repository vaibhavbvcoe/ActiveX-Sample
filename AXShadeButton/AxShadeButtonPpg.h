#if !defined(AFX_AXSHADEBUTTONPPG_H__A4463197_5324_11D6_BB80_444553540000__INCLUDED_)
#define AFX_AXSHADEBUTTONPPG_H__A4463197_5324_11D6_BB80_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AxShadeButtonPpg.h : Declaration of the CAxShadeButtonPropPage property page class.
#include "xShadeButton.h"	// Added by ClassView

////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonPropPage : See AxShadeButtonPpg.cpp.cpp for implementation.

class CAxShadeButtonPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAxShadeButtonPropPage)
	DECLARE_OLECREATE_EX(CAxShadeButtonPropPage)

// Constructor
public:
	CAxShadeButtonPropPage();

// Dialog Data
	//{{AFX_DATA(CAxShadeButtonPropPage)
	enum { IDD = IDD_PROPPAGE_AXSHADEBUTTON };
	CxShadeButton	m_btn1;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAxShadeButtonPropPage)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXSHADEBUTTONPPG_H__A4463197_5324_11D6_BB80_444553540000__INCLUDED)
