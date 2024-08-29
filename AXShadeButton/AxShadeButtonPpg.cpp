// AxShadeButtonPpg.cpp : Implementation of the CAxShadeButtonPropPage property page class.

#include "stdafx.h"
#include "AxShadeButton.h"
#include "AxShadeButtonPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAxShadeButtonPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAxShadeButtonPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAxShadeButtonPropPage)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAxShadeButtonPropPage, "AXSHADEBUTTON.AxShadeButtonPropPage.1",
	0xa4463189, 0x5324, 0x11d6, 0xbb, 0x80, 0x44, 0x45, 0x53, 0x54, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonPropPage::CAxShadeButtonPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAxShadeButtonPropPage

BOOL CAxShadeButtonPropPage::CAxShadeButtonPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_AXSHADEBUTTON_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonPropPage::CAxShadeButtonPropPage - Constructor

CAxShadeButtonPropPage::CAxShadeButtonPropPage() :
	COlePropertyPage(IDD, IDS_AXSHADEBUTTON_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAxShadeButtonPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonPropPage::DoDataExchange - Moves data between page and properties

void CAxShadeButtonPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAxShadeButtonPropPage)
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonPropPage message handlers

void CAxShadeButtonPropPage::OnButton1() 
{
	AfxMessageBox("AxShadeButton ver. 1.00\n\r© 2002 - ing.davide.pizzolato@libero.it\n\rwww.aoi.it",MB_OK|MB_ICONINFORMATION);
}

BOOL CAxShadeButtonPropPage::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();
	
	m_btn1.SetShade(SHS_HARDBUMP);
	m_btn1.SetFlat(1);
	m_btn1.SetToolTipText("About this control...");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
