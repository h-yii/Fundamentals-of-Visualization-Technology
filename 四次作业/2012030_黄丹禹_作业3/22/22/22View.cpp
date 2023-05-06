
// 22View.cpp : CMy22View ���ʵ��
//

#include "stdafx.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_BMP1, &CMy22View::OnBmp1)
	ON_COMMAND(ID_BMP2, &CMy22View::OnBmp2)
	ON_COMMAND(ID_BMP3, &CMy22View::OnBmp3)
	ON_COMMAND(ID_free, &CMy22View::OnFree)
END_MESSAGE_MAP()

// CMy22View ����/����

CMy22View::CMy22View()
	: flag(0)
	, str1(_T(""))
	, num(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMy22View::~CMy22View()
{
}

BOOL CMy22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CMy22View ����

void CMy22View::OnDraw(CDC* /*pDC*/)
{
	CMy22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
	// TODO: �������ͼ�ĺϼƴ�С

	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy22View ��ӡ

BOOL CMy22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy22View ���

#ifdef _DEBUG
void CMy22View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy22View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy22Doc* CMy22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy22Doc)));
	return (CMy22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy22View ��Ϣ�������


void CMy22View::OnBmp1()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
