
// 22View.cpp : CMy22View 类的实现
//

#include "stdafx.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "22.h"
#include "MyDialog.h"
//#include "bits/stdc++.h"

#include <CString>
#endif

#include "22Doc.h"
#include "22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy22View

IMPLEMENT_DYNCREATE(CMy22View, CScrollView)

BEGIN_MESSAGE_MAP(CMy22View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_BMP1, &CMy22View::OnBmp1)
	ON_COMMAND(ID_BMP2, &CMy22View::OnBmp2)
	ON_COMMAND(ID_BMP3, &CMy22View::OnBmp3)
	ON_COMMAND(ID_free, &CMy22View::OnFree)
END_MESSAGE_MAP()

// CMy22View 构造/析构

CMy22View::CMy22View()
	: flag(0)
	, str1(_T(""))
	, num(0)
{
	// TODO: 在此处添加构造代码

}

CMy22View::~CMy22View()
{
}

BOOL CMy22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CMy22View 绘制

void CMy22View::OnDraw(CDC* /*pDC*/)
{
	CMy22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	/*
	if(flag==1){
		OnBmp1();
	}
	else if(flag==2){
		OnBmp2();
	}
	else if(flag==3){
		OnBmp3();
	}*/
}

void CMy22View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小

	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy22View 打印

BOOL CMy22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy22View 诊断

#ifdef _DEBUG
void CMy22View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy22View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy22Doc* CMy22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy22Doc)));
	return (CMy22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy22View 消息处理程序


void CMy22View::OnBmp1()
{
	// TODO: 在此添加命令处理程序代码
	RedrawWindow();
	flag=1;
	CDC* pDC = this->GetDC();
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info;
	bm.GetBitmap(&info);
	pDC->StretchBlt(0,0,info.bmWidth, 
	info.bmHeight,&memDC,0,0,info.bmWidth, 
	info.bmHeight,SRCCOPY);
	bm.DeleteObject();
}


void CMy22View::OnBmp2()
{
	// TODO: 在此添加命令处理程序代码
	RedrawWindow();
	flag=2;
	CDC* pDC = this->GetDC();
	CBitmap bm; bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC; memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; bm.GetBitmap(&info);
	pDC->StretchBlt(0,0,info.bmWidth*4, 
	info.bmHeight*4,&memDC,0,0,info.bmWidth, 
	info.bmHeight,SRCCOPY);
	bm.DeleteObject();
}


void CMy22View::OnBmp3()
{
	// TODO: 在此添加命令处理程序代码
	RedrawWindow();
	flag=3;
	CDC* pDC = this->GetDC();
	CBitmap bm; bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC; memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; bm.GetBitmap(&info);
	pDC->StretchBlt(0,0,info.bmWidth/4, 
	info.bmHeight/4,&memDC,0,0,info.bmWidth, 
	info.bmHeight,SRCCOPY);
	bm.DeleteObject();
}


void CMy22View::OnFree()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	dlg.DoModal();
	str1=dlg.str1;
	num=_ttoi(str1);
	
	CDC* pDC = this->GetDC();
	pDC->TextOutW(0,0,str1);
	

	
	RedrawWindow();
	flag=4;
	
	CBitmap bm; bm.LoadBitmap(IDB_BITMAP2);
	CDC memDC; memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; bm.GetBitmap(&info);
	pDC->StretchBlt(0,0,info.bmWidth*num/100, 
	info.bmHeight*num/100,&memDC,0,0,info.bmWidth, 
	info.bmHeight,SRCCOPY);
	bm.DeleteObject();
}
