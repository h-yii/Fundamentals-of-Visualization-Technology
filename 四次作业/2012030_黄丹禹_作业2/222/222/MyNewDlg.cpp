// MyNewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "222.h"
#include "MyNewDlg.h"
#include "afxdialogex.h"


// CMyNewDlg �Ի���

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyNewDlg::IDD, pParent)
{

}

CMyNewDlg::~CMyNewDlg()
{
}

void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit0);
}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
//	ON_EN_CHANGE(IDC_EDIT1, &CMyNewDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CMyNewDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyNewDlg ��Ϣ�������




void CMyNewDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	edit0.GetWindowTextW(str0);

	
	CDialogEx::OnOK();
	
}
