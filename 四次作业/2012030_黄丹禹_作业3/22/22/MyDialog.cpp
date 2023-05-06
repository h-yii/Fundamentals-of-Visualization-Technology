// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "22.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, str1(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &MyDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &MyDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	edit0.GetWindowTextW(str1);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str1); 

	CDialogEx::OnOK();
}
