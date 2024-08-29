#pragma once

// AFXDROPDOWN.h : main header file for AFXDROPDOWN.DLL

#if !defined( __AFXCTL_H__ )
#error "include 'afxctl.h' before including this file"
#endif

#include "resource.h"       // main symbols


// CAFXDROPDOWNApp : See AFXDROPDOWN.cpp for implementation.

class CAFXDROPDOWNApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

