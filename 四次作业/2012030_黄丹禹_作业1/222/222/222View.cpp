
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
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_jia, &CMy222View::OnJia)
	ON_COMMAND(ID_jian, &CMy222View::OnJian)
	ON_COMMAND(ID_STOP, &CMy222View::OnStop)
	ON_COMMAND(ID_CONTINUE, &CMy222View::OnContinue)
	ON_COMMAND(ID_SPEED, &CMy222View::OnSpeed)

END_MESSAGE_MAP()

// CMy222View 构造/析构

CMy222View::CMy222View()
	: x(0)
	, y(0)
	, movex(10)
	, movey(10)
	, speed(500)
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
	//pDC->SelectStockObject(BLACK_BRUSH);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
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


int CMy222View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1,speed,NULL);

	return 0;
}


void CMy222View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	KillTimer(1);
}


void CMy222View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1){
		CDC* pDC=GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+15,y+15);

		//反弹
		CRect rect;
		GetClientRect(&rect);
		if(x<0||x>rect.right-15){
			movex=-movex;
		}
		if(y<0||y>rect.bottom-15){
			movey=-movey;
		}

		//移动
		x=x+movex;
		y=y+movey;
		pDC->Ellipse(x,y,x+15,y+15);
	}
	CView::OnTimer(nIDEvent);
}


void CMy222View::OnJia()
{
	// TODO: 在此添加命令处理程序代码
	//主菜单中的菜单项“加速”
	if(speed-200<=0){
		CString str;
		str="不能再加速啦已经够快了!";
		MessageBox(str);
		return;
	}
	speed=speed-200;
	SetTimer(1,speed,NULL);
}


void CMy222View::OnJian()
{
	// TODO: 在此添加命令处理程序代码
	//主菜单中的菜单项“减速”
	speed=speed+200;
	SetTimer(1,speed,NULL);
}


void CMy222View::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	//工具栏里的“红灯”按钮，使运动的小球停止运动
	KillTimer(1);
}


void CMy222View::OnContinue()
{
	// TODO: 在此添加命令处理程序代码
	//工具栏里的“绿灯”按钮，使暂停的小球恢复运动
	SetTimer(1,speed,NULL);
}


void CMy222View::OnSpeed()
{
	//主菜单中的菜单项“查看当前时间间隔”
	CString str;
	str.Format(L"Now the speed:%d",speed);
	MessageBox(str);
}

