
// TestClientDlg.h : header file
//

#pragma once


// CTestClientDlg dialog
class CTestClientDlg : public CDialogEx
{
// Construction
public:
	CTestClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void ClickAxshadebuttonctrl1();
	void OnSelChangeAfxdropdownctrl1();
	void OnSetFocusAfxdropdownctrl1();
};
