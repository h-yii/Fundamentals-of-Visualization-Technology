
// 111View.cpp : CMy111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "111.h"
#endif

#include "111Doc.h"
#include "111View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy111View

IMPLEMENT_DYNCREATE(CMy111View, CView)

BEGIN_MESSAGE_MAP(CMy111View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PopMenu_Rec, &CMy111View::OnPopmenuRec)
	ON_COMMAND(ID_PopMenu_Ellipse, &CMy111View::OnPopmenuEllipse)
END_MESSAGE_MAP()

// CMy111View 构造/析构

CMy111View::CMy111View()
	
{
	// TODO: 在此处添加构造代码

}

CMy111View::~CMy111View()
{
}

BOOL CMy111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy111View 绘制

void CMy111View::OnDraw(CDC* pDC)
{
	CMy111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPoint point;
	CString str;
	int length;
	int width;
	pDoc->Get(str,point,length,width);
	str.Format(L"%s,%d,%d,%d,%d",str,point.x,point.y,length,width);

	pDC=GetDC();
/*	pDC->Rectangle(point.x,point.y,point.x+length,point.y+width);
	pDC->Rectangle(500,500,700,600);*/
	CString str1=str.Mid(0,2);
//	pDC->TextOutW(100,100,str1);
	if(str1=="矩形"){
//		pDC->TextOutW(0,0,str);
		pDC->Rectangle(point.x,point.y,point.x+length,point.y+width);
	}
	if(str1=="椭圆"){
//		pDC->TextOutW(0,0,str);
		pDC->Ellipse(point.x,point.y,point.x+length,point.y+width);
	}
}


// CMy111View 打印

BOOL CMy111View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy111View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy111View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy111View 诊断

#ifdef _DEBUG
void CMy111View::AssertValid() const
{
	CView::AssertValid();
}

void CMy111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy111Doc* CMy111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy111Doc)));
	return (CMy111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy111View 消息处理程序


void CMy111View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.CreatePopupMenu();

	menu.AppendMenuW(MF_ENABLED,ID_PopMenu_Ellipse,L"椭圆");
	menu.AppendMenuW(MF_ENABLED,ID_PopMenu_Rec,L"矩形");
	CPoint pt;
	GetCursorPos(&pt);
	menu.TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
	CView::OnRButtonDown(nFlags, point);
}




void CMy111View::OnPopmenuRec()
{
	// TODO: 在此添加命令处理程序代码
	CPoint point1;
	point1.x=100;
	point1.y=100;
	int length1=200;
	int width1=100;

	CMy111Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) return;
	CString str;
	str.Format(L"矩形");
	pDoc->Set(str,point1,length1,width1);
	Invalidate(true);

//	CDC* pDC=GetDC();
//	pDC->Rectangle(point1.x,point1.y,point1.x+length1,point1.y+width1);
}


void CMy111View::OnPopmenuEllipse()
{
	// TODO: 在此添加命令处理程序代码
	CPoint point1;
	point1.x=500;
	point1.y=100;
	int length1=200;
	int width1=100;

	CMy111Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) return;
	CString str;
	str.Format(L"椭圆");
	pDoc->Set(str,point1,length1,width1);

	Invalidate(true);

	//CDC* pDC=GetDC();
//	pDC->Rectangle(point1.x,point1.y,point1.x+length1,point1.y+width1);
}
