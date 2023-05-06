
// 111View.cpp : CMy111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PopMenu_Rec, &CMy111View::OnPopmenuRec)
	ON_COMMAND(ID_PopMenu_Ellipse, &CMy111View::OnPopmenuEllipse)
END_MESSAGE_MAP()

// CMy111View ����/����

CMy111View::CMy111View()
	
{
	// TODO: �ڴ˴���ӹ������

}

CMy111View::~CMy111View()
{
}

BOOL CMy111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy111View ����

void CMy111View::OnDraw(CDC* pDC)
{
	CMy111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
	if(str1=="����"){
//		pDC->TextOutW(0,0,str);
		pDC->Rectangle(point.x,point.y,point.x+length,point.y+width);
	}
	if(str1=="��Բ"){
//		pDC->TextOutW(0,0,str);
		pDC->Ellipse(point.x,point.y,point.x+length,point.y+width);
	}
}


// CMy111View ��ӡ

BOOL CMy111View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy111View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy111View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy111View ���

#ifdef _DEBUG
void CMy111View::AssertValid() const
{
	CView::AssertValid();
}

void CMy111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy111Doc* CMy111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy111Doc)));
	return (CMy111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy111View ��Ϣ�������


void CMy111View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.CreatePopupMenu();

	menu.AppendMenuW(MF_ENABLED,ID_PopMenu_Ellipse,L"��Բ");
	menu.AppendMenuW(MF_ENABLED,ID_PopMenu_Rec,L"����");
	CPoint pt;
	GetCursorPos(&pt);
	menu.TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
	CView::OnRButtonDown(nFlags, point);
}




void CMy111View::OnPopmenuRec()
{
	// TODO: �ڴ���������������
	CPoint point1;
	point1.x=100;
	point1.y=100;
	int length1=200;
	int width1=100;

	CMy111Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) return;
	CString str;
	str.Format(L"����");
	pDoc->Set(str,point1,length1,width1);
	Invalidate(true);

//	CDC* pDC=GetDC();
//	pDC->Rectangle(point1.x,point1.y,point1.x+length1,point1.y+width1);
}


void CMy111View::OnPopmenuEllipse()
{
	// TODO: �ڴ���������������
	CPoint point1;
	point1.x=500;
	point1.y=100;
	int length1=200;
	int width1=100;

	CMy111Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc) return;
	CString str;
	str.Format(L"��Բ");
	pDoc->Set(str,point1,length1,width1);

	Invalidate(true);

	//CDC* pDC=GetDC();
//	pDC->Rectangle(point1.x,point1.y,point1.x+length1,point1.y+width1);
}
