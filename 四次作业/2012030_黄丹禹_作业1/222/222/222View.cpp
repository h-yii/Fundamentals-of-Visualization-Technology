
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
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_jia, &CMy222View::OnJia)
	ON_COMMAND(ID_jian, &CMy222View::OnJian)
	ON_COMMAND(ID_STOP, &CMy222View::OnStop)
	ON_COMMAND(ID_CONTINUE, &CMy222View::OnContinue)
	ON_COMMAND(ID_SPEED, &CMy222View::OnSpeed)

END_MESSAGE_MAP()

// CMy222View ����/����

CMy222View::CMy222View()
	: x(0)
	, y(0)
	, movex(10)
	, movey(10)
	, speed(500)
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
	//pDC->SelectStockObject(BLACK_BRUSH);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
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


int CMy222View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,speed,NULL);

	return 0;
}


void CMy222View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	KillTimer(1);
}


void CMy222View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1){
		CDC* pDC=GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+15,y+15);

		//����
		CRect rect;
		GetClientRect(&rect);
		if(x<0||x>rect.right-15){
			movex=-movex;
		}
		if(y<0||y>rect.bottom-15){
			movey=-movey;
		}

		//�ƶ�
		x=x+movex;
		y=y+movey;
		pDC->Ellipse(x,y,x+15,y+15);
	}
	CView::OnTimer(nIDEvent);
}


void CMy222View::OnJia()
{
	// TODO: �ڴ���������������
	//���˵��еĲ˵�����١�
	if(speed-200<=0){
		CString str;
		str="�����ټ������Ѿ�������!";
		MessageBox(str);
		return;
	}
	speed=speed-200;
	SetTimer(1,speed,NULL);
}


void CMy222View::OnJian()
{
	// TODO: �ڴ���������������
	//���˵��еĲ˵�����١�
	speed=speed+200;
	SetTimer(1,speed,NULL);
}


void CMy222View::OnStop()
{
	// TODO: �ڴ���������������
	//��������ġ���ơ���ť��ʹ�˶���С��ֹͣ�˶�
	KillTimer(1);
}


void CMy222View::OnContinue()
{
	// TODO: �ڴ���������������
	//��������ġ��̵ơ���ť��ʹ��ͣ��С��ָ��˶�
	SetTimer(1,speed,NULL);
}


void CMy222View::OnSpeed()
{
	//���˵��еĲ˵���鿴��ǰʱ������
	CString str;
	str.Format(L"Now the speed:%d",speed);
	MessageBox(str);
}

