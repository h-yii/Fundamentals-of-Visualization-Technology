
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
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MY_MESSAGE,OnMyMessage)
	
	ON_WM_HOTKEY()
	ON_WM_DESTROY()
	ON_WM_CREATE()
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

void CMy111View::OnDraw(CDC* /*pDC*/)
{
	CMy111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


void CMy111View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC=GetDC();
	CString str;
	if(nFlags&MK_CONTROL){
		str.Format(L"������ + Ctrl ,����Ϊ(%d,%d)",point.x,point.y);
	}
	else {
		str.Format(L"������,����Ϊ(%d,%d)",point.x,point.y);
	}
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);

}


void CMy111View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC = this->GetDC();
	CString str;
	str.Format(L"%c Key Entered!",nChar);
	RedrawWindow();
	pDC->TextOutW(0,0,str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CMy111View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
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
	str.Format(L"�Զ�����Ϣ������Ϊ�� %d , %d",wParam,lParam);
	pDC->TextOutW(0,0,str);
	return LRESULT();
}


void CMy111View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nHotKeyId==1001){
		PostMessage(WM_MY_MESSAGE,10,50);
	}
	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CMy111View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	UnregisterHotKey(m_hWnd,1001);
}


int CMy111View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	RegisterHotKey(m_hWnd,1001,MOD_SHIFT,'2');
	return 0;
}
