
// 222View.cpp : CMy222View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_text, &CMy222View::OnText)
END_MESSAGE_MAP()

// CMy222View ����/����

CMy222View::CMy222View()
	: str1(_T(""))
{
	// TODO: �ڴ˴���ӹ������

}

CMy222View::~CMy222View()
{
}

BOOL CMy222View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy222View ����

void CMy222View::OnDraw(CDC* pDC)
{
	CMy222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString str;
	pDoc->Get(str);

	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(255, 255, 255));

	pDC->TextOutW(0,0,str);
	pDoc->Set(str);

}


// CMy222View ��ӡ

BOOL CMy222View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy222View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy222View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy222View ���

#ifdef _DEBUG
void CMy222View::AssertValid() const
{
	CView::AssertValid();
}

void CMy222View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy222Doc* CMy222View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy222Doc)));
	return (CMy222Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy222View ��Ϣ�������


void CMy222View::OnText()
{
	// TODO: �ڴ���������������
	
	//����˵�����ԡ���Ĵ������������Ի���
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
