// AxShadeButtonCtl.cpp : Implementation of the CAxShadeButtonCtrl ActiveX Control class.

#include "stdafx.h"
#include "AxShadeButton.h"
#include "AxShadeButtonCtl.h"
#include "AxShadeButtonPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CAxShadeButtonCtrl, COleControl)

/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAxShadeButtonCtrl, COleControl)
	//{{AFX_MSG_MAP(CAxShadeButtonCtrl)
	ON_WM_ERASEBKGND()
	ON_WM_DRAWITEM()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_MESSAGE(OCM_DRAWITEM, OnOcmDrawItem)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
    ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_CXSHADE_RADIO , OnRadioInfo)
	ON_MESSAGE(BM_SETCHECK , OnBMSetCheck)
	ON_MESSAGE(BM_GETCHECK , OnBMGetCheck)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CAxShadeButtonCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAxShadeButtonCtrl)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetShade", SetShade1, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetToolTipText", SetToolTipText, VT_EMPTY, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetTextColor", SetTextColor, VT_COLOR, VTS_COLOR)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetTextAlign", SetTextAlign2, VT_EMPTY, VTS_I4)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetIcon", SetIcon, VT_EMPTY, VTS_HANDLE VTS_I4 VTS_HANDLE VTS_HANDLE)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetFlat", SetFlat, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetFont", SetFont, VT_BOOL, VTS_BSTR VTS_I4 VTS_I4 VTS_BOOL VTS_BOOL)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetStyle", SetStyle, VT_EMPTY, VTS_I4 VTS_BOOL VTS_BOOL VTS_BOOL)
	DISP_FUNCTION(CAxShadeButtonCtrl, "GetCheck", GetCheck, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CAxShadeButtonCtrl, "GetState", GetState, VT_I4, VTS_NONE)
	DISP_FUNCTION(CAxShadeButtonCtrl, "SetCheck", SetCheck, VT_EMPTY, VTS_BOOL)
	DISP_STOCKPROP_CAPTION()
	DISP_STOCKPROP_ENABLED()
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_FUNCTION_ID(CAxShadeButtonCtrl, "Refresh", DISPID_REFRESH, Refresh, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CAxShadeButtonCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAxShadeButtonCtrl)
	EVENT_CUSTOM_ID("Click", DISPID_CLICK, FireClick, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAxShadeButtonCtrl, 1)
	PROPPAGEID(CAxShadeButtonPropPage::guid)
END_PROPPAGEIDS(CAxShadeButtonCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAxShadeButtonCtrl, "AXSHADEBUTTON.AxShadeButtonCtrl.1",
	0xa4463188, 0x5324, 0x11d6, 0xbb, 0x80, 0x44, 0x45, 0x53, 0x54, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CAxShadeButtonCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DAxShadeButton =
		{ 0xa4463186, 0x5324, 0x11d6, { 0xbb, 0x80, 0x44, 0x45, 0x53, 0x54, 0, 0 } };
const IID BASED_CODE IID_DAxShadeButtonEvents =
		{ 0xa4463187, 0x5324, 0x11d6, { 0xbb, 0x80, 0x44, 0x45, 0x53, 0x54, 0, 0 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwAxShadeButtonOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAxShadeButtonCtrl, IDS_AXSHADEBUTTON, _dwAxShadeButtonOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::CAxShadeButtonCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAxShadeButtonCtrl

BOOL CAxShadeButtonCtrl::CAxShadeButtonCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_AXSHADEBUTTON,
			IDB_AXSHADEBUTTON,
			afxRegApartmentThreading,
			_dwAxShadeButtonOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::CAxShadeButtonCtrl - Constructor
CAxShadeButtonCtrl::CAxShadeButtonCtrl()
{
	InitializeIIDs(&IID_DAxShadeButton, &IID_DAxShadeButtonEvents);

	m_Border=1;				//draw 3D border
	m_FocusRectMargin=4;	//focus dotted rect margin
	m_TextColor=GetSysColor(COLOR_BTNTEXT); // default button text color
	m_flat = m_Checked = m_button_down = m_tracking = false;

	m_Icon=m_IconDown=m_IconHighLight=NULL;	// icon handle
	m_IconBox.SetRectEmpty(); //icon location
	m_IconAlign=BS_CENTER;	//icon alignment
	m_TextAlign=DT_CENTER;	//text alignment
	m_pLF=NULL;				//font structure pointer

	m_sh_style = SHS_METAL;
	m_sh_granularity=10;
	m_sh_highlight=10;
	m_sh_coloring=0;
	m_sh_color=0;
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::~CAxShadeButtonCtrl - Destructor
CAxShadeButtonCtrl::~CAxShadeButtonCtrl()
{
	m_Font.DeleteObject();
	if (m_pLF)	free(m_pLF);
	if (m_IconDown!=m_Icon && m_IconDown) DestroyIcon(m_IconDown);
	if (m_IconHighLight!=m_Icon && m_IconHighLight) DestroyIcon(m_IconHighLight);
	if (m_Icon) DestroyIcon(m_Icon);
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::OnDraw - Drawing function
void CAxShadeButtonCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	DoSuperclassPaint(pdc, rcBounds);
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::DoPropExchange - Persistence support
void CAxShadeButtonCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	// TODO: Call PX_ functions for each persistent custom property.
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::OnResetState - Reset control to default state
void CAxShadeButtonCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
	// TODO: Reset any other control state here.
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::PreCreateWindow - Modify parameters for CreateWindowEx
BOOL CAxShadeButtonCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::IsSubclassedControl - This is a subclassed control
BOOL CAxShadeButtonCtrl::IsSubclassedControl()
{
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl::OnOcmCommand - Handle command messages
LRESULT CAxShadeButtonCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	switch (wNotifyCode)
	{
	case BN_CLICKED:
		// Fire click event when button is clicked
		//serve il custom altrimenti lo spazio non viene processato
		FireClick();
		//questo codice viene chiamato prima del messaggio di default della super-class
		break;
	case BM_GETCHECK:
		return m_Checked;
	case BM_GETSTATE:
		return m_button_down;
	case BM_SETCHECK:
		return OnBMSetCheck(wParam,lParam);
	case BN_KILLFOCUS:
		if (::GetCapture() == (HWND)lParam) {
			::ReleaseCapture();
			ASSERT (!m_tracking);
			m_button_down = false;
		}
		break;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl message handlers
void CAxShadeButtonCtrl::PreSubclassWindow() 
{
	m_Style=GetStyle(); //get general button styles
	m_IsPushLike=((m_Style & BS_PUSHLIKE)!=0);
	m_flat=((m_Style & BS_FLAT)!=0);
	SetTextAlign(m_Style & 0x0300);

	m_Style=GetStyle();	///get specific BS_ styles
	if ((m_Style & BS_AUTOCHECKBOX)==BS_AUTOCHECKBOX)
//		||((m_Style & BS_CHECKBOX)==BS_CHECKBOX))
		m_Style=BS_CHECKBOX;
	else if ((m_Style & BS_AUTORADIOBUTTON)==BS_AUTORADIOBUTTON)
//			||((m_Style & BS_RADIOBUTTON)==BS_RADIOBUTTON))
		m_Style=BS_RADIOBUTTON;
	else { m_Style=BS_PUSHBUTTON; m_IsPushLike=true;}

	//default radio & check-box has no border
	if (!m_IsPushLike) m_Border = false;
	
	COleControl::PreSubclassWindow();
	ModifyStyle(0, BS_OWNERDRAW|BS_NOTIFY);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetTextAlign2(long nTextAlign)
{
	switch (nTextAlign){
	case 2:
		SetTextAlign(BS_RIGHT);
		break;
	case 1:
		SetTextAlign(BS_LEFT);
		break;
	default:
		SetTextAlign(BS_CENTER);
	}
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetTextAlign(UINT nTextAlign)
{
//	see DrawText() styles...
	switch (nTextAlign){
	case BS_RIGHT:
		m_TextAlign=DT_RIGHT;
		break;
	case BS_LEFT:
		m_TextAlign=DT_LEFT;
		break;
	default:
		m_TextAlign=DT_CENTER;
	}
	m_TextAlign|=(DT_SINGLELINE|DT_VCENTER);
}
/////////////////////////////////////////////////////////////////////////////
BOOL CAxShadeButtonCtrl::OnEraseBkgnd(CDC* pDC) 
{ return 1; }	// doesn't erase the button background
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
    ASSERT (lpDrawItemStruct);
    //TRACE("* Captured: %08X\n", ::GetCapture());

    //Check if the button state in not in inconsistent mode...
    POINT mouse_position;
    if ((m_button_down) && (::GetCapture() == m_hWnd) && (::GetCursorPos(&mouse_position))){
		if (::WindowFromPoint(mouse_position) == m_hWnd){
			if ((SendMessage(BM_GETSTATE,0,0) & BST_PUSHED) != BST_PUSHED) {
				//TRACE("* Inconsistency up detected! Fixing.\n");
				SendMessage(BM_SETSTATE,1,0);
				return;
			}
		} else {
			if ((SendMessage(BM_GETSTATE,0,0) & BST_PUSHED) == BST_PUSHED) {
				//TRACE("* Inconsistency up detected! Fixing.\n");
				SendMessage(BM_SETSTATE,0,0);
				return;
	}	}	}
	
    //TRACE("* Drawing: %08x\n", lpDrawItemStruct->itemState);
	CString sCaption;
	CDC *pRealDC = CDC::FromHandle(lpDrawItemStruct->hDC);	// get device context
	RECT r=lpDrawItemStruct->rcItem;					// context rectangle
	int cx = r.right  - r.left ;						// get width
	int cy = r.bottom - r.top  ;						// get height
	// get text box position
	RECT tr={r.left+m_FocusRectMargin+2,r.top,r.right-m_FocusRectMargin-2,r.bottom};

	CDC hdcMem;	//create a memory DC to avoid flicker
	hdcMem.CreateCompatibleDC(pRealDC);
	CDC* pDC = &hdcMem; //(just use pRealDC to paint directly the screen)
    CBitmap hBitmap; //create a destination for raster operations
	hBitmap.CreateCompatibleBitmap(pRealDC,cx,cy);
	CBitmap* pOldBitmap = hdcMem.SelectObject(&hBitmap); //select the destination for MemDC

	GetWindowText(sCaption);							// get button text
	pDC->SetBkMode(TRANSPARENT);
	// with MemDC we need to select the font...

	//get text font
	CFont* pOldFont=NULL;
	if (m_Font.m_hObject) pOldFont = pDC->SelectObject(&m_Font);
	else pDC->SelectObject(GetStockObject(DEFAULT_GUI_FONT));
//	TEXTMETRIC tm;
//	pDC->GetTextMetrics(&tm);							// get font metrics

	// accommodate text location
	if (m_Icon){
		switch (m_IconAlign){
		case BS_LEFT:
			tr.left+=m_IconBox.Width();		// shift left
			break;
		case BS_RIGHT:
			tr.right-=m_IconBox.Width();	// shift right
			break;
		case BS_CENTER:
			tr.top+=m_IconBox.bottom;		// shift text under the icon
			tr.bottom-=m_FocusRectMargin + 1;
		}
	}
	// Select the correct skin 
	if (lpDrawItemStruct->itemState & ODS_DISABLED){	// DISABLED BUTTON
		if(m_dDisabled.IsValid())	// paint the skin
			m_dDisabled.Draw(pDC->GetSafeHdc(),0,0);
		else	// no skin selected for disabled state -> standard button
			pDC->FillSolidRect(&r,GetSysColor(COLOR_BTNFACE));

		if (m_Icon)	//draw the icon
			pDC->DrawState(m_IconBox.TopLeft(),m_IconBox.Size(),
				m_Icon,DSS_DISABLED,(CBrush*)NULL);

		// if needed, draw the standard 3D rectangular border
		if ((m_Border)&&(m_flat==FALSE)) pDC->DrawEdge(&r,EDGE_RAISED,BF_RECT);
		// paint the etched button text
		pDC->SetTextColor(GetSysColor(COLOR_3DHILIGHT));
		pDC->DrawText(sCaption,&tr,m_TextAlign);
		pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT));
		OffsetRect(&tr,-1,-1);
		pDC->DrawText(sCaption,&tr,m_TextAlign);
	} else {
//---------------------------------------------------------------------------
		if ((lpDrawItemStruct->itemState & ODS_SELECTED)||m_Checked){ //SELECTED (DOWN) BUTTON
			if(m_dDown.IsValid())	// paint the skin
				m_dDown.Draw(pDC->GetSafeHdc(),m_Border,m_Border);
			else	// no skin selected for selected state -> standard button
				pDC->FillSolidRect(&r,GetSysColor(COLOR_BTNFACE));

			if (m_IconDown){ //draw the pushed icon
				if (m_IsPushLike) m_IconBox.OffsetRect(1,1);
				pDC->DrawState(m_IconBox.TopLeft(),m_IconBox.Size(),
								m_IconDown,DSS_NORMAL,(CBrush*)NULL);
				if (m_IsPushLike) m_IconBox.OffsetRect(-1,-1);
			}
			//shift text
			if (m_IsPushLike) OffsetRect(&tr,1,1);
			// if needed, draw the standard 3D rectangular border
			if (m_Border){
				if (m_flat) pDC->Draw3dRect(&r,GetSysColor(COLOR_BTNSHADOW),GetSysColor(COLOR_BTNHILIGHT));
				else		pDC->DrawEdge(&r,EDGE_SUNKEN,BF_RECT);
			}
		} else {
//---------------------------------------------------------------------------
			if(m_dNormal.IsValid()){ // paint the skin			// DEFAULT BUTTON
                if ((m_tracking)&&(m_dOver.IsValid())){
					m_dOver.Draw(pDC->GetSafeHdc(),0,0);
				} else {
					m_dNormal.Draw(pDC->GetSafeHdc(),0,0);
				}
			} else	// no skin selected for normal state -> standard button
				pDC->FillSolidRect(&r,GetSysColor(COLOR_BTNFACE));

			if (m_IconHighLight && m_tracking) { // draw the highlighted icon
				pDC->DrawState(m_IconBox.TopLeft(),m_IconBox.Size(),
								m_IconHighLight,DSS_NORMAL,(CBrush*)NULL);
			} else if (m_Icon) //draw the icon
				pDC->DrawState(m_IconBox.TopLeft(),m_IconBox.Size(),
								m_Icon,DSS_NORMAL,(CBrush*)NULL);

			// if needed, draw the standard 3D rectangular border
			if ((m_Border)&&((m_tracking)||(m_flat==FALSE))){
				if (lpDrawItemStruct->itemState & ODS_DEFAULT){
					pDC->DrawEdge(&r,EDGE_SUNKEN,BF_RECT);
					InflateRect(&r,-1,-1);
					pDC->DrawEdge(&r,EDGE_RAISED,BF_RECT);
				} else {
					if (m_flat) pDC->Draw3dRect(&r,GetSysColor(COLOR_BTNHILIGHT),GetSysColor(COLOR_BTNSHADOW));
					else		pDC->DrawEdge(&r,EDGE_RAISED,BF_RECT);
				}
			}
//---------------------------------------------------------------------------
		}
		// paint the focus rect
		if ((lpDrawItemStruct->itemState & ODS_FOCUS)&&(m_FocusRectMargin>0)){
			InflateRect(&r,-m_FocusRectMargin,-m_FocusRectMargin);
			m_dh.Draw(pDC->GetSafeHdc(),1+r.left,r.top);
			m_dh.Draw(pDC->GetSafeHdc(),1+r.left,r.bottom);
			m_dv.Draw(pDC->GetSafeHdc(),r.left,1+r.top);
			m_dv.Draw(pDC->GetSafeHdc(),r.right,1+r.top);
		}
		// paint the enabled button text
		pDC->SetTextColor(m_TextColor);
		pDC->DrawText(sCaption,&tr,m_TextAlign);
	}

	if (pOldFont) pDC->SelectObject(pOldFont);	//restore the old font object

	pRealDC->BitBlt(0,0,cx,cy,&hdcMem,0,0,SRCCOPY); //copy in the real world
	//restore the old objects to avoid memory leakage <David Scambler>
	if (pOldBitmap)	hdcMem.SelectObject(pOldBitmap);
//	hdcMem.DeleteDC(); the destructor will do this for us
//	hBitmap.DeleteObject(); the destructor will do this for us

}
/////////////////////////////////////////////////////////////////////////////
LRESULT CAxShadeButtonCtrl::OnOcmDrawItem(WPARAM wParam, LPARAM lParam)
{
	OnDrawItem((UINT) wParam,(LPDRAWITEMSTRUCT) lParam);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetShade1(long shadeID, long granularity, long highlight, long coloring, long color) 
{
	SetShade((UINT)shadeID, (BYTE)granularity, (BYTE)highlight, (BYTE)coloring, (COLORREF)color);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetShade(UINT shadeID, BYTE granularity, BYTE highlight, BYTE coloring, COLORREF color)
{
	m_sh_style=shadeID;
	m_sh_granularity=granularity;
	m_sh_highlight=highlight;
	m_sh_coloring=coloring;
	m_sh_color=color;

	long	sXSize,sYSize,bytes,j,i,k,h;
	BYTE	*iDst ,*posDst;
	
	RECT rect;
	GetWindowRect(&rect);
	sYSize=rect.bottom-rect.top;
	sXSize=rect.right-rect.left ;

	m_dh.Create(max(1,sXSize-2*m_FocusRectMargin-1),1,8);	//create the horizontal focus bitmap
	m_dv.Create(1,max(1,sYSize-2*m_FocusRectMargin),8);	//create the vertical focus bitmap

	m_dNormal.Create(sXSize,sYSize,8);					//create the default bitmap

	COLORREF hicr=GetSysColor(COLOR_BTNHIGHLIGHT);		//get the button base colors
	COLORREF midcr=GetSysColor(COLOR_BTNFACE);
	COLORREF locr=GetSysColor(COLOR_BTNSHADOW);
	long r,g,b;											//build the shaded palette
	for(i=0;i<129;i++){
		r=((128-i)*GetRValue(locr)+i*GetRValue(midcr))/128;
		g=((128-i)*GetGValue(locr)+i*GetGValue(midcr))/128;
		b=((128-i)*GetBValue(locr)+i*GetBValue(midcr))/128;
		m_dNormal.SetPaletteIndex((BYTE)i,(BYTE)r,(BYTE)g,(BYTE)b);
		m_dh.SetPaletteIndex((BYTE)i,(BYTE)r,(BYTE)g,(BYTE)b);
		m_dv.SetPaletteIndex((BYTE)i,(BYTE)r,(BYTE)g,(BYTE)b);
	}
	for(i=1;i<129;i++){
		r=((128-i)*GetRValue(midcr)+i*GetRValue(hicr))/128;
		g=((128-i)*GetGValue(midcr)+i*GetGValue(hicr))/128;
		b=((128-i)*GetBValue(midcr)+i*GetBValue(hicr))/128;
		m_dNormal.SetPaletteIndex((BYTE)(i+127),(BYTE)r,(BYTE)g,(BYTE)b);
		m_dh.SetPaletteIndex((BYTE)(i+127),(BYTE)r,(BYTE)g,(BYTE)b);
		m_dv.SetPaletteIndex((BYTE)(i+127),(BYTE)r,(BYTE)g,(BYTE)b);
	}

	m_dNormal.BlendPalette(color,coloring);	//color the palette

	iDst=m_dh.GetBits();		//build the horiz. dotted focus bitmap
	j=(long)m_dh.GetWidth();
	for(i=0;i<j;i++){
//		iDst[i]=64+127*(i%2);	//soft
		iDst[i]=255*(i%2);		//hard
	}

	iDst=m_dv.GetBits();		//build the vert. dotted focus bitmap
	j=(long)m_dv.GetHeight();
	for(i=0;i<j;i++){
//		*iDst=64+127*(i%2);		//soft
		*iDst=255*(i%2);		//hard
		iDst+=4;
	}

	bytes = m_dNormal.GetLineWidth();
	iDst = m_dNormal.GetBits();
	posDst =iDst;
	long a,x,y,d,xs,idxmax,idxmin;

	int grainx2=RAND_MAX/(max(1,2*granularity));
	idxmax=255-granularity;
	idxmin=granularity;

	switch(shadeID){
//----------------------------------------------------
	case 8:	//SHS_METAL
		m_dNormal.Clear();
		// create the strokes
		k=40;	//stroke granularity
		for(a=0;a<200;a++){
			x=rand()/(RAND_MAX/sXSize); //stroke postion
			y=rand()/(RAND_MAX/sYSize);	//stroke position
			xs=rand()/(RAND_MAX/min(sXSize,sYSize))/2; //stroke lenght
			d=rand()/(RAND_MAX/k);	//stroke color
			for(i=0;i<xs;i++){
				if (((x-i)>0)&&((y+i)<sYSize))
					m_dNormal.SetPixelIndex(x-i,y+i,(BYTE)d);
				if (((x+i)<sXSize)&&((y-i)>0))
					m_dNormal.SetPixelIndex(sXSize-x+i,y-i,(BYTE)d);
			}
		}
		//blend strokes with SHS_DIAGONAL
		posDst =iDst;
		a=(idxmax-idxmin-k)/2;
		for(i = 0; i < sYSize; i++) {
			for(j = 0; j < sXSize; j++) {
				d=posDst[j]+((a*i)/sYSize+(a*(sXSize-j))/sXSize);
				posDst[j]=(BYTE)d;
				posDst[j]+=rand()/grainx2;
			}
			posDst+=bytes;
		}

		break;
//----------------------------------------------------
	case 7:	// SHS_HARDBUMP
		//set horizontal bump
		for(i = 0; i < sYSize; i++) {
			k=(255*i/sYSize)-127;
			k=(k*(k*k)/128)/128;
			k=(k*(128-granularity*2))/128+128;
			for(j = 0; j < sXSize; j++) {
				posDst[j]=(BYTE)k;
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		//set vertical bump
		d=min(16,sXSize/6);	//max edge=16
		a=sYSize*sYSize/4;
		posDst =iDst;
		for(i = 0; i < sYSize; i++) {
			y=i-sYSize/2;
			for(j = 0; j < sXSize; j++) {
				x=j-sXSize/2;
				xs=sXSize/2-d+(y*y*d)/a;
				if (x>xs) posDst[j]=idxmin+(BYTE)(((sXSize-j)*128)/d);
				if ((x+xs)<0) posDst[j]=idxmax-(BYTE)((j*128)/d);
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		break;
//----------------------------------------------------
	case 6: //SHS_SOFTBUMP
		for(i = 0; i < sYSize; i++) {
			h=(255*i/sYSize)-127;
			for(j = 0; j < sXSize; j++) {
				k=(255*(sXSize-j)/sXSize)-127;
				k=(h*(h*h)/128)/128+(k*(k*k)/128)/128;
				k=k*(128-granularity)/128+128;
				if (k<idxmin) k=idxmin;
				if (k>idxmax) k=idxmax;
				posDst[j]=(BYTE)k;
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		break;
//----------------------------------------------------
	case 5: // SHS_VBUMP
		for(j = 0; j < sXSize; j++) {
			k=(255*(sXSize-j)/sXSize)-127;
			k=(k*(k*k)/128)/128;
			k=(k*(128-granularity))/128+128;
			for(i = 0; i < sYSize; i++) {
				posDst[j+i*bytes]=(BYTE)k;
				posDst[j+i*bytes]+=rand()/grainx2-granularity;
			}
		}
		break;
//----------------------------------------------------
	case 4: //SHS_HBUMP
		for(i = 0; i < sYSize; i++) {
			k=(255*i/sYSize)-127;
			k=(k*(k*k)/128)/128;
			k=(k*(128-granularity))/128+128;
			for(j = 0; j < sXSize; j++) {
				posDst[j]=(BYTE)k;
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		break;
//----------------------------------------------------
	case 1:	//SHS_DIAGSHADE
		a=(idxmax-idxmin)/2;
		for(i = 0; i < sYSize; i++) {
			for(j = 0; j < sXSize; j++) {
				posDst[j]=(BYTE)(idxmin+a*i/sYSize+a*(sXSize-j)/sXSize);
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		break;
//----------------------------------------------------
	case 2:	//SHS_HSHADE
		a=idxmax-idxmin;
		for(i = 0; i < sYSize; i++) {
			k=a*i/sYSize+idxmin;
			for(j = 0; j < sXSize; j++) {
				posDst[j]=(BYTE)k;
				posDst[j]+=rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
		break;
//----------------------------------------------------
	case 3:	//SHS_VSHADE:
		a=idxmax-idxmin;
		for(j = 0; j < sXSize; j++) {
			k=a*(sXSize-j)/sXSize+idxmin;
			for(i = 0; i < sYSize; i++) {
				posDst[j+i*bytes]=(BYTE)k;
				posDst[j+i*bytes]+=rand()/grainx2-granularity;
			}
		}
		break;
//----------------------------------------------------
	default:	//SHS_NOISE
		for(i = 0; i < sYSize; i++) {
			for(j = 0; j < sXSize; j++) {
				posDst[j]=128+rand()/grainx2-granularity;
			}
			posDst+=bytes;
		}
	}
//----------------------------------------------------
	m_dDisabled.Clone(&m_dNormal);	//build the other bitmaps
	m_dOver.Clone(&m_dNormal);
	m_dOver.BlendPalette(hicr,highlight);
	m_dDown.Clone(&m_dOver);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnSize(UINT nType, int cx, int cy) 
{
	COleControl::OnSize(nType, cx, cy);
	SetShade(m_sh_style,m_sh_granularity,m_sh_highlight,m_sh_coloring,m_sh_color);	
}
/////////////////////////////////////////////////////////////////////////////
LRESULT CAxShadeButtonCtrl::OnBMGetCheck(WPARAM wparam, LPARAM)
{ return m_Checked; }	//returns the state for check & radio buttons
/////////////////////////////////////////////////////////////////////////////
LRESULT CAxShadeButtonCtrl::OnBMSetCheck(WPARAM wparam, LPARAM)
{
	m_Checked=wparam!=0;
	switch (m_Style)
	{
	case BS_RADIOBUTTON:
		if (m_Checked) { //uncheck the other radio buttons (in the same group)
			HWND hthis,hwnd2,hpwnd;
			hpwnd=GetParent()->GetSafeHwnd();	//get button parent handle
			hwnd2=hthis=GetSafeHwnd();			//get this button handle
			if (hthis && hpwnd){				//consistency check
				for( ; ; ){	//scan the buttons within the group
					hwnd2=::GetNextDlgGroupItem(hpwnd,hwnd2,0);
					//until we reach again this button
					if ((hwnd2==hthis)||(hwnd2==NULL)) break;
					//post the uncheck message
					::SendMessage(hwnd2, WM_CXSHADE_RADIO, 0, 0);
				}
			}
		}
		break;
	case BS_PUSHBUTTON:
		m_Checked=false;
		//ASSERT(false); // Must be a Check or Radio button to use this function
		AfxMessageBox("SetCheck:Must be a Check or Radio button to use this function");
	}

	//set the correct tooltip
	if (m_tooltip.m_hWnd!=NULL){
		m_tooltip.Pop();	//to avoid flicker
		if (m_Checked && !m_ToolTipDw.IsEmpty())
			m_tooltip.UpdateTipText((LPCTSTR)m_ToolTipDw,this);
		else
			m_tooltip.UpdateTipText((LPCTSTR)m_ToolTipUp,this);
	}
	Invalidate();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetToolTipText(LPCTSTR sUp, LPCTSTR sDown) 
{
	CString csUp(sUp);
	CString csDw(sDown);
	m_ToolTipUp = csUp;		//normal tooltip
	m_ToolTipDw = csDw;	//tooltip for checked state

	//select the down tooltip if the button is already checked <Jesper Kinnås>
	if (m_Checked && !m_ToolTipDw.IsEmpty()) csUp = m_ToolTipDw;
	
	if(m_tooltip.m_hWnd==NULL){
		if(m_tooltip.Create(this))	//first assignment
			if(m_tooltip.AddTool(this, (LPCTSTR)csUp)){
				m_tooltip.Activate(1);
				// enable multiline tooltips <Derek Lakin>
				m_tooltip.SendMessage(TTM_SETMAXTIPWIDTH, 0, 300);
			}
	} else {
		m_tooltip.UpdateTipText((LPCTSTR)csUp,this);
	}
}
/////////////////////////////////////////////////////////////////////////////
OLE_COLOR CAxShadeButtonCtrl::SetTextColor(OLE_COLOR new_color) 
{
	COLORREF tmp_color=m_TextColor;
	m_TextColor=new_color;
	return tmp_color;			//returns the previous color
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetIcon(OLE_HANDLE hicon, long nalign, OLE_HANDLE hicondown, OLE_HANDLE hicinhighlight) 
{
	if (m_IconDown!=m_Icon && m_IconDown) DestroyIcon(m_IconDown);
	if (m_IconHighLight!=m_Icon && m_IconHighLight) DestroyIcon(m_IconHighLight);
	if (m_Icon) DestroyIcon(m_Icon);
		
//	m_Icon = (HICON)::LoadImage(AfxGetInstanceHandle(),
//								MAKEINTRESOURCE(nIcon),
//								IMAGE_ICON, 0, 0, 0);
	m_Icon = (HICON) hicon;
	
	if (m_Icon){							// if success...
		ICONINFO iinfo;						// get icon info
		GetIconInfo(m_Icon, &iinfo);
		m_IconBox.left=m_IconBox.top=0;
		m_IconBox.right = iinfo.xHotspot * 2;
		m_IconBox.bottom = iinfo.yHotspot * 2;

		long x,y;
		RECT rect;
		GetWindowRect(&rect);
		y=rect.bottom-rect.top;
		x=rect.right-rect.left;
		switch (nalign){				//set the icon location
		case 2:
			m_IconAlign=BS_RIGHT;
			m_IconBox.OffsetRect(x - iinfo.xHotspot*2 - m_FocusRectMargin,
								 max(0, (long)(y/2 - iinfo.yHotspot)));
			break;
		case 1:
			m_IconAlign=BS_LEFT;
			m_IconBox.OffsetRect(m_FocusRectMargin,
								 max(0, (long)(y/2 - iinfo.yHotspot)));
			break;
		default:
			m_IconAlign=BS_CENTER;
			m_IconBox.OffsetRect(max(0, (long)(x/2 - iinfo.xHotspot)),
								 max(0, (long)(y/2 - 2*iinfo.yHotspot)));
		}

		//release icon mask bitmaps (Orioli Alessandro <aorioli@temaweb.it>)
		if( iinfo.hbmColor ) DeleteObject( iinfo.hbmColor );
		if( iinfo.hbmMask ) DeleteObject( iinfo.hbmMask );

		if (hicondown > 0){	//load down icon
//			m_IconDown = (HICON)::LoadImage(AfxGetInstanceHandle(),
//											MAKEINTRESOURCE(nIconDown),
//											IMAGE_ICON, 0, 0, 0);
//			if (m_IconDown==NULL) m_IconDown= m_Icon;
			m_IconDown = (HICON) hicondown;
		} else { m_IconDown= m_Icon; }	//reuse resource handle

		if (hicinhighlight > 0){	//load highlighted icon
//			m_IconHighLight = (HICON)::LoadImage(AfxGetInstanceHandle(),
//											MAKEINTRESOURCE(nIconHighLight),
//											IMAGE_ICON, 0, 0, 0);
//			if (m_IconHighLight==NULL) m_IconHighLight= m_Icon;
			m_IconHighLight = (HICON) hicinhighlight;
		} else { m_IconHighLight= m_Icon; }	//reuse resource handle
	}
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetFlat(BOOL bflat) 
{ m_flat=(bflat!=0); }	//set flat border mode
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::Refresh() 
{
	Invalidate();
}
/////////////////////////////////////////////////////////////////////////////
BOOL CAxShadeButtonCtrl::SetFont(LPCTSTR sFontName, long lSize, long lWeight, BOOL bItalic, BOOL bUnderline) 
{
	if (m_pLF==NULL) m_pLF=(LOGFONT*)calloc(1,sizeof(LOGFONT));
	if (m_pLF){
		strncpy(m_pLF->lfFaceName,sFontName,31);
		m_pLF->lfHeight=lSize;
		m_pLF->lfWeight=lWeight;
		m_pLF->lfItalic=bItalic;
		m_pLF->lfUnderline=bUnderline;
		m_Font.DeleteObject();
		if (m_Font.CreateFontIndirect(m_pLF)) return TRUE;
	}
	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetStyle(long nStyle, BOOL bFlat, BOOL bPushLike, BOOL bRedraw) 
{
	// see PreSubclassWindow
	m_IsPushLike=(bPushLike!=0);
	m_flat=(bFlat!=0);

	if (nStyle==1)
		m_Style=BS_CHECKBOX;
	else if (nStyle==2)
		m_Style=BS_RADIOBUTTON;
	else { m_Style=BS_PUSHBUTTON; m_IsPushLike=true; m_Checked=false; }

	//default radio & check-box has no border
	if (!m_IsPushLike) m_Border = false;

	if (bRedraw) Invalidate();
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::RelayEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
// This function will create a MSG structure, fill it in a pass it to
// the ToolTip control, m_ttip.  Note that we ensure the point is in window
// coordinates (relative to the control's window).
	if(NULL != m_tooltip.m_hWnd){
		MSG msg;
		msg.hwnd = m_hWnd;
		msg.message = message;
		msg.wParam = wParam;
		msg.lParam = lParam;
		msg.time = 0;
		msg.pt.x = LOWORD(lParam);
		msg.pt.y = HIWORD(lParam);

		m_tooltip.RelayEvent(&msg);
	}
}
/////////////////////////////////////////////////////////////////////////////
LRESULT CAxShadeButtonCtrl::OnRadioInfo(WPARAM wparam, LPARAM)
{
	if (m_Checked){	//only checked buttons need to be unchecked
		m_Checked = false;
		if(m_tooltip.m_hWnd!=NULL)
			m_tooltip.UpdateTipText((LPCTSTR)m_ToolTipUp,this);
		Invalidate();
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
BOOL CAxShadeButtonCtrl::GetCheck() 
{
	return m_Checked;
}
/////////////////////////////////////////////////////////////////////////////
long CAxShadeButtonCtrl::GetState() 
{
	return m_button_down;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::SetCheck(BOOL bCheck) 
{
	OnBMSetCheck(bCheck,0);
	return;
}
/////////////////////////////////////////////////////////////////////////////
//Method......: OnMouseLeave
//Class.......: CxShadeButton
//
//Author......: Milan Gardian
//Created.....: MAR-2001
//
//Return value: NULL
//Parameters..: NOT USED
//Exceptions..: NONE
//------------
//Description :
//  > Handle situation when mouse cursor leaves area of this
//    window (button). This event might be generated ONLY
//    if we explicitely call 'TrackMouseEvent'. This is
//    signalled by setting the m_tracking flag (see the assert
//    precondition) - in 'OnMouseMove' method
//
//  > When a mouse pointer leaves area of this button (i.e.
//    when this method is invoked), presumably the look of
//    the button changes (e.g. when hover/non-hover images are set)
//    and therefore we force the control to redraw.
//---------------------------------------------------------
LRESULT CAxShadeButtonCtrl::OnMouseLeave(WPARAM, LPARAM)
{
    ASSERT (m_tracking);
    //TRACE("* Mouse leave\n");
    m_tracking = false;
    Invalidate();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
    //TRACE("* %08X: Mouse\n", ::GetTickCount());

	//Pass this message to the ToolTip control
	RelayEvent(WM_MOUSEMOVE,(WPARAM)nFlags,MAKELPARAM(LOWORD(point.x),LOWORD(point.y)));

    //If we are in capture mode, button has been pressed down
    //recently and not yet released - therefore check is we are
    //actually over the button or somewhere else. If the mouse
    //position changed considerably (e.g. we moved mouse pointer
    //from the button to some other place outside button area)
    //force the control to redraw
    //
    if ((m_button_down) && (::GetCapture() == m_hWnd)) {
	    POINT p2 = point;
        ::ClientToScreen(m_hWnd, &p2);
        HWND mouse_wnd = ::WindowFromPoint(p2);

        bool pressed = ((GetState() & BST_PUSHED) == BST_PUSHED);
        bool need_pressed = (mouse_wnd == m_hWnd);
        if (pressed != need_pressed) {
            //TRACE("* %08X Redraw\n", GetTickCount());
			SendMessage(BM_SETSTATE,need_pressed ? TRUE : FALSE,0);
            Invalidate();
        }
    } else {

	//Otherwise the button is released. That means we should
    //know when we leave its area - and so if we are not tracking
    //this mouse leave event yet, start now!
    //
        if (!m_tracking) {
            TRACKMOUSEEVENT t = {
                sizeof(TRACKMOUSEEVENT),
                TME_LEAVE,
                m_hWnd,
                0
            };
            if (::_TrackMouseEvent(&t)) {
                //TRACE("* Mouse enter\n");
                m_tracking = true;
                Invalidate();
            }
        }
    }

    //Forward this event to superclass
	COleControl::OnMouseMove(nFlags, point);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //TRACE("* %08X: up\n", ::GetTickCount());

	if (m_Style){ //track mouse for radio & check buttons
		POINT p2 = point;
		::ClientToScreen(m_hWnd, &p2);
		HWND mouse_wnd = ::WindowFromPoint(p2);
		if (mouse_wnd == m_hWnd && m_button_down == true){ // mouse is in button
			if (m_Style==BS_CHECKBOX) SetCheck(m_Checked ? 0 : 1);
			if (m_Style==BS_RADIOBUTTON) SetCheck(1);
		}
	}

	//Pass this message to the ToolTip control
	RelayEvent(WM_LBUTTONUP,(WPARAM)nFlags,MAKELPARAM(LOWORD(point.x),LOWORD(point.y)));

    //Default-process the message
    m_button_down = false;
	
	COleControl::OnLButtonUp(nFlags, point);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
    //TRACE("* %08X: down\n", ::GetTickCount());

	//Pass this message to the ToolTip control
	RelayEvent(WM_LBUTTONDOWN,(WPARAM)nFlags,MAKELPARAM(LOWORD(point.x),LOWORD(point.y)));

    //If we are tracking this button, cancel it
    if (m_tracking) {
        TRACKMOUSEEVENT t = {
            sizeof(TRACKMOUSEEVENT),
            TME_CANCEL | TME_LEAVE,
            m_hWnd, 0
		};
        if (::_TrackMouseEvent(&t)) {
            m_tracking = false;
        }
    }

    //Default-process the message
	COleControl::OnLButtonDown(nFlags, point);
    m_button_down = true;
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    SendMessage(WM_LBUTTONDOWN, nFlags, MAKELPARAM(point.x, point.y));
//	COleControl::OnLButtonDblClk(nFlags, point);
}
/////////////////////////////////////////////////////////////////////////////
void CAxShadeButtonCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ((m_Style)&&(nChar==' ')){ //needed stuff for check & radio buttons
		if (m_Style==BS_CHECKBOX) SetCheck(m_Checked ? 0 : 1);
		if (m_Style==BS_RADIOBUTTON) SetCheck(1);
	}
	COleControl::OnKeyDown(nChar, nRepCnt, nFlags);
}
/////////////////////////////////////////////////////////////////////////////
