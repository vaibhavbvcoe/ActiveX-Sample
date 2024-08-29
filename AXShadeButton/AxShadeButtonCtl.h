#if !defined(AFX_AXSHADEBUTTONCTL_H__A4463195_5324_11D6_BB80_444553540000__INCLUDED_)
#define AFX_AXSHADEBUTTONCTL_H__A4463195_5324_11D6_BB80_444553540000__INCLUDED_

#include "xShadeButton.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AxShadeButtonCtl.h : Declaration of the CAxShadeButtonCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CAxShadeButtonCtrl : See AxShadeButtonCtl.cpp for implementation.

class CAxShadeButtonCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAxShadeButtonCtrl)

// Constructor
public:
	CAxShadeButtonCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAxShadeButtonCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:
	CFont	m_Font;		//font object
	LOGFONT* m_pLF;		//font structure
	CString m_ToolTipUp,m_ToolTipDw;
	bool	m_Checked;		//radio & check buttons
	bool	m_IsPushLike;	//radio & check buttons
	DWORD	m_Style,m_sh_style;
	CxDib	m_dNormal,m_dDown,m_dDisabled,m_dOver,m_dh,m_dv;
    bool	m_tracking;
    bool	m_button_down;
	void	RelayEvent(UINT message, WPARAM wParam, LPARAM lParam);
	CToolTipCtrl m_tooltip;
	short	m_FocusRectMargin;	//dotted margin offset
	COLORREF m_TextColor;		//button text color
	BOOL	m_Border;			//0=flat; 1=3D;
	HICON	m_Icon,m_IconDown,m_IconHighLight;
	CRect	m_IconBox;
	UINT	m_TextAlign;
	UINT	m_IconAlign;
	bool	m_flat;
	BYTE	m_sh_granularity, m_sh_highlight, m_sh_coloring;
	COLORREF m_sh_color;
	

	~CAxShadeButtonCtrl();

	DECLARE_OLECREATE_EX(CAxShadeButtonCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CAxShadeButtonCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAxShadeButtonCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAxShadeButtonCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);
	LRESULT OnOcmDrawItem(WPARAM wParam, LPARAM lParam);

// Message maps
	//{{AFX_MSG(CAxShadeButtonCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	afx_msg LRESULT OnRadioInfo(WPARAM, LPARAM);
	afx_msg LRESULT OnBMSetCheck(WPARAM, LPARAM);
	afx_msg LRESULT OnBMGetCheck(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CAxShadeButtonCtrl)
	afx_msg void SetShade1(long shadeID, long granularity, long highlight, long coloring, long color);
	afx_msg void SetToolTipText(LPCTSTR sUp, LPCTSTR sDown);
	afx_msg OLE_COLOR SetTextColor(OLE_COLOR new_color);
	afx_msg void SetTextAlign2(long nTextAlign);
	afx_msg void SetIcon(OLE_HANDLE hicon, long nalign, OLE_HANDLE hicondown, OLE_HANDLE hicinhighlight);
	afx_msg void SetFlat(BOOL bflat);
	afx_msg BOOL SetFont(LPCTSTR sFontName, long lSize, long lWeight, BOOL bItalic, BOOL bUnderline);
	afx_msg void SetStyle(long nStyle, BOOL bFlat, BOOL bPushLike, BOOL bRedraw);
	afx_msg BOOL GetCheck();
	afx_msg long GetState();
	afx_msg void SetCheck(BOOL bCheck);
	afx_msg void Refresh();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CAxShadeButtonCtrl)
	void FireClick()
	{
			FireEvent(DISPID_CLICK,EVENT_PARAM(VTS_NONE));
	}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	void SetShade(UINT shadeID=0,BYTE granularity=8,BYTE highlight=10,BYTE coloring=0,COLORREF color=0);
	void SetTextAlign(UINT nTextAlign);
	enum {
	//{{AFX_DISP_ID(CAxShadeButtonCtrl)
	dispidSetShade = 1L,
	dispidSetToolTipText = 2L,
	dispidSetTextColor = 3L,
	dispidSetTextAlign = 4L,
	dispidSetIcon = 5L,
	dispidSetFlat = 6L,
	dispidSetFont = 7L,
	dispidSetStyle = 8L,
	dispidGetCheck = 9L,
	dispidGetState = 10L,
	dispidSetCheck = 11L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXSHADEBUTTONCTL_H__A4463195_5324_11D6_BB80_444553540000__INCLUDED)
