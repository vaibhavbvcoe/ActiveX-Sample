#if !defined(AFX_AXSHADEBUTTON_H__A446318E_5324_11D6_BB80_444553540000__INCLUDED_)
#define AFX_AXSHADEBUTTON_H__A446318E_5324_11D6_BB80_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AxShadeButton.h : main header file for AXSHADEBUTTON.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonApp : See AxShadeButton.cpp for implementation.

class CAxShadeButtonApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXSHADEBUTTON_H__A446318E_5324_11D6_BB80_444553540000__INCLUDED)
