// AFXDROPDOWN.cpp : Implementation of CAFXDROPDOWNApp and DLL registration.

#include "stdafx.h"
#include "AFXDROPDOWN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CAFXDROPDOWNApp theApp;

const GUID CDECL _tlid = { 0x42CA9B2A, 0xEAD8, 0x4A4E, { 0x98, 0x56, 0xA, 0xBB, 0x2E, 0x37, 0xF2, 0x6B } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CAFXDROPDOWNApp::InitInstance - DLL initialization

BOOL CAFXDROPDOWNApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CAFXDROPDOWNApp::ExitInstance - DLL termination

int CAFXDROPDOWNApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
