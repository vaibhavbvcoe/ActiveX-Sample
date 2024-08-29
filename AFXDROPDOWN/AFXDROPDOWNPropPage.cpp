// AFXDROPDOWNPropPage.cpp : Implementation of the CAFXDROPDOWNPropPage property page class.

#include "stdafx.h"
#include "AFXDROPDOWN.h"
#include "AFXDROPDOWNPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CAFXDROPDOWNPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CAFXDROPDOWNPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAFXDROPDOWNPropPage, "AFXDROPDOWN.AFXDROPDOWNPropPage.1",
	0xa0aaf91e, 0x9ae1, 0x4f05, 0x90, 0xf5, 0x91, 0x87, 0x39, 0x90, 0x4d, 0x30)



// CAFXDROPDOWNPropPage::CAFXDROPDOWNPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAFXDROPDOWNPropPage

BOOL CAFXDROPDOWNPropPage::CAFXDROPDOWNPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_AFXDROPDOWN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CAFXDROPDOWNPropPage::CAFXDROPDOWNPropPage - Constructor

CAFXDROPDOWNPropPage::CAFXDROPDOWNPropPage() :
	COlePropertyPage(IDD, IDS_AFXDROPDOWN_PPG_CAPTION)
{
}



// CAFXDROPDOWNPropPage::DoDataExchange - Moves data between page and properties

void CAFXDROPDOWNPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CAFXDROPDOWNPropPage message handlers
