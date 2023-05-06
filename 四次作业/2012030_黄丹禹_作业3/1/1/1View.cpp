
// 1View.cpp : CMy1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "1.h"
#endif

#include "1Doc.h"
#include "1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POPMENU_R, &CMy1View::OnPopmenuR)
	ON_COMMAND(ID_POPMENU_P, &CMy1View::OnPopmenuP)
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy1View ����/����

CMy1View::CMy1View()
	: flag(0)
	, move(false)
	, x(0)
	, y(0)
	, count1(false)
	, count2(false)
{
	// TODO: �ڴ˴���ӹ������

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy1View ����
void CMy1View::OnDraw(CDC* pDC)
{
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if(flag==1){
		pDC->Rectangle(100,100,500,500);
		x=100;
		y=100;
	}
		
	else if(flag==2){
		pDC->MoveTo(800,100);
		pDC->LineTo(1000,100);
		pDC->LineTo(1150,300);
		pDC->LineTo(1000,500);
		pDC->LineTo(800,500);
		pDC->LineTo(650,300);
		pDC->LineTo(800,100);
		x=800;
		y=100;
	}
	
	pDC->SetROP2(R2_XORPEN);
	if(move==true){
		pDC->SetROP2(R2_XORPEN);
		CBitmap bm; bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC; memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info; bm.GetBitmap(&info);
		pDC->BitBlt(x,y,info.bmWidth, 
		info.bmHeight,&memDC,0,0,SRCCOPY);
		bm.DeleteObject();
	}
}


// CMy1View ��ӡ
BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo){
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy1View ���

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View ��Ϣ�������


void CMy1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.CreatePopupMenu();

	menu.AppendMenuW(MF_ENABLED,ID_POPMENU_R,L"����");
	menu.AppendMenuW(MF_ENABLED,ID_POPMENU_P,L"�����");
	CPoint pt;
	GetCursorPos(&pt);
	menu.TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
	CView::OnRButtonDown(nFlags, point);
}


void CMy1View::OnPopmenuR()
{
	// TODO: �ڴ���������������
	flag=1;
	count2=false;
/*	CPoint point;
	point.x=100;
	point.y=100;
	int length=200;
	int width=100;
	CDC* pDC=GetDC();

	pDC->Rectangle(100,100,300,200);
	CMy111Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) return;
	CString str;
	str.Format(L"����");
	pDoc->Set(str,point1,length1,width1);*/
	Invalidate(true);
}


void CMy1View::OnPopmenuP()
{
	// TODO: �ڴ���������������
	flag=2;
	count1=false;
/*	CPoint point;
	point.x=100;
	point.y=100;
	int length=200;
	int width=100;
	CDC* pDC=GetDC();
	pDC->Ellipse(100,100,300,200);*/
	Invalidate(true);
}




void CMy1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(move==true) move=false;
	else move=true;
	CDC* pDC = this->GetDC();

	

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1&&move==true){
		CDC* pDC=GetDC();
	//	pDC->SetROP2(R2_XORPEN);	
		if(flag==1){
			CBitmap bm; bm.LoadBitmap(IDB_BITMAP1);
			CDC memDC; memDC.CreateCompatibleDC(pDC);
			BITMAP info; bm.GetBitmap(&info);
			if(count1==true){
				memDC.SelectObject(&bm);
				pDC->BitBlt(x,y,info.bmWidth, 
				info.bmHeight,&memDC,0,0,SRCINVERT);
				bm.DeleteObject();
			}
			if(x<500&&y==100){
				x=x+5;
			}
			else if(x>=496&&y<=496){
				y=y+5;
			}
			else if(y>=496&&x>=104){
				x=x-5;
			}
			else if(x<=104&&y>=104){
				y=y-5;
			}
			
			count1=true;
			memDC.SelectObject(&bm);
			pDC->BitBlt(x,y,info.bmWidth, 
			info.bmHeight,&memDC,0,0,SRCINVERT);
			bm.DeleteObject();
		}
		if(flag==2){
			CBitmap bm; bm.LoadBitmap(IDB_BITMAP1);
			CDC memDC; memDC.CreateCompatibleDC(pDC);
			BITMAP info; bm.GetBitmap(&info);
			if(count2==true){
				memDC.SelectObject(&bm);
				pDC->BitBlt(x,y,info.bmWidth, 
				info.bmHeight,&memDC,0,0,SRCINVERT);
				bm.DeleteObject();
			}
			if(x<1000&&y==100){
				x=x+5;
			}
			else if(x>=1000&&x<=1145&&y<=295){
				x=x+3;
				y=y+4;
			}
			else if(y>=295&&y<=495&&x>=996){
				x=x-3;
				y=y+4;
			}
			else if(x>=800){
				x=x-5;
			}
			else if(x<=800&&x>=650&&y>=296){
				x=x-3;
				y=y-4;
			}
			else if(y>=96){
				x=x+3;
				y=y-4;
			}
			count2=true;
			pDC->SetROP2(R2_XORPEN);
			memDC.SelectObject(&bm);
			pDC->BitBlt(x,y,info.bmWidth, 
			info.bmHeight,&memDC,0,0,SRCINVERT);
			bm.DeleteObject();
		}
	}
	CView::OnTimer(nIDEvent);
}


int CMy1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,20,NULL);
	return 0;
}


void CMy1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	KillTimer(1);
}
