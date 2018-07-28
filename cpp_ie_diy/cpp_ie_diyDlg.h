
// cpp_ie_diyDlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// Ccpp_ie_diyDlg 对话框
class Ccpp_ie_diyDlg : public CDialogEx
{
// 构造
public:
	Ccpp_ie_diyDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CPP_IE_DIY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnFind();
	afx_msg void OnExit();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_MyIE;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CMenu m_Menu;
	CButton m_Back;
	CButton m_Forward;
	CButton m_Reload;
	CButton m_Stop;
	CEdit m_Url;
	afx_msg void OnChangeEditUrl();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClickedButtonHcyy();
	afx_msg void OnClickedButtonBack();
	afx_msg void OnClickedButtonForward();
	afx_msg void OnClickedButtonReload();
	afx_msg void OnClickedButtonStop();
};
