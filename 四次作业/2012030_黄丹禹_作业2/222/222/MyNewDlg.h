#pragma once
#include "afxwin.h"


// CMyNewDlg �Ի���

class CMyNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewDlg)

public:
	CMyNewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyNewDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeEdit1();
	CEdit edit0;	
	CString str0;
	
	
	afx_msg void OnBnClickedOk();
};
