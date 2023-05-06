
// 222View.cpp : CMy222View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "222.h"
#endif

#include "222Doc.h"
#include "222View.h"
#include "MyNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy222View

IMPLEMENT_DYNCREATE(CMy222View, CView)

BEGIN_MESSAGE_MAP(CMy222View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_text, &CMy222View::OnText)
END_MESSAGE_MAP()

// CMy222View 构造/析构

CMy222View::CMy222View()
	: str1(_T(""))
{
	// TODO: 在此处添加构造代码

}

CMy222View::~CMy222View()
{
}

BOOL CMy222View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy222View 绘制

void CMy222View::OnDraw(CDC* pDC)
{
	CMy222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString str;
	pDoc->Get(str);

	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(255, 255, 255));

	pDC->TextOutW(0,0,str);
	pDoc->Set(str);

}


// CMy222View 打印

BOOL CMy222View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy222View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy222View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy222View 诊断

#ifdef _DEBUG
void CMy222View::AssertValid() const
{
	CView::AssertValid();
}

void CMy222View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy222Doc* CMy222View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy222Doc)));
	return (CMy222Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy222View 消息处理程序


void CMy222View::OnText()
{
	// TODO: 在此添加命令处理程序代码
	
	//点击菜单项“测试”后的处理函数，弹出对话框
	CMy222Doc* pDoc =GetDocument();
	CMyNewDlg dlg;
	dlg.DoModal();
	str1=dlg.str0;
	
	CDC* pDC=GetDC();
	/*
	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(255, 255, 255));
	*/
	RedrawWindow();
	pDC->TextOutW(0,0,str1);
	pDoc->Set(str1);


}
