
// cpp_ie_diyDlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// Ccpp_ie_diyDlg �Ի���
class Ccpp_ie_diyDlg : public CDialogEx
{
// ����
public:
	Ccpp_ie_diyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CPP_IE_DIY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
