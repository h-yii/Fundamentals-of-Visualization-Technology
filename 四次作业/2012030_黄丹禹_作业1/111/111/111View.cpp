
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
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MY_MESSAGE,OnMyMessage)
	
	ON_WM_HOTKEY()
	ON_WM_DESTROY()
	ON_WM_CREATE()
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

void CMy111View::OnDraw(CDC* /*pDC*/)
{
	CMy111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


void CMy111View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC=GetDC();
	CString str;
	if(nFlags&MK_CONTROL){
		str.Format(L"鼠标左键 + Ctrl ,坐标为(%d,%d)",point.x,point.y);
	}
	else {
		str.Format(L"鼠标左键,坐标为(%d,%d)",point.x,point.y);
	}
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);

}


void CMy111View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC = this->GetDC();
	CString str;
	str.Format(L"%c Key Entered!",nChar);
	RedrawWindow();
	pDC->TextOutW(0,0,str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CMy111View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CDC* pDC = this->GetDC();
	
	if(pMsg->message==WM_KEYDOWN){
		if(pMsg->wParam==VK_UP){
			RedrawWindow();
			pDC->TextOutW(0,0,L"UP Key!");
		}
		if(pMsg->wParam==VK_DOWN){
			RedrawWindow();
			pDC->TextOutW(0,0,L"DWON Key!");
		}
		if(pMsg->wParam==VK_F1){
			RedrawWindow();
			pDC->TextOutW(0,0,L"F1 Key!");
		}
		if(pMsg->wParam==VK_F2){
			RedrawWindow();
			pDC->TextOutW(0,0,L"F2 Key!");
		}

	}
	return CView::PreTranslateMessage(pMsg);
}




LRESULT CMy111View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CDC* pDC = this->GetDC();
	RedrawWindow();
	CString str;
	str.Format(L"自定义消息，参数为： %d , %d",wParam,lParam);
	pDC->TextOutW(0,0,str);
	return LRESULT();
}


void CMy111View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nHotKeyId==1001){
		PostMessage(WM_MY_MESSAGE,10,50);
	}
	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CMy111View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	UnregisterHotKey(m_hWnd,1001);
}


int CMy111View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	RegisterHotKey(m_hWnd,1001,MOD_SHIFT,'2');
	return 0;
}
