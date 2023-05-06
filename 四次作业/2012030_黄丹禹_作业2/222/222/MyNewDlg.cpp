// MyNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "222.h"
#include "MyNewDlg.h"
#include "afxdialogex.h"


// CMyNewDlg 对话框

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


// CMyNewDlg 消息处理程序




void CMyNewDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	edit0.GetWindowTextW(str0);

	
	CDialogEx::OnOK();
	
}
