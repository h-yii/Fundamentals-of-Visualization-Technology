
// 111Doc.cpp : CMy111Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "111.h"
#endif

#include "111Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy111Doc

IMPLEMENT_DYNCREATE(CMy111Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy111Doc, CDocument)
END_MESSAGE_MAP()


// CMy111Doc ����/����

CMy111Doc::CMy111Doc()
{
	// TODO: �ڴ����һ���Թ������
	
}

CMy111Doc::~CMy111Doc()
{
}

BOOL CMy111Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy111Doc ���л�

void CMy111Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<m_name<<m_point<<m_length<<m_width;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>m_name>>m_point>>m_length>>m_width;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy111Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy111Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy111Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy111Doc ���

#ifdef _DEBUG
void CMy111Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy111Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy111Doc ����


void CMy111Doc::Set(CString& str, CPoint& point, int& length, int& width)
{
	m_name=str;
	m_point=point;
	m_length=length;
	m_width=width;
}

void CMy111Doc::Get(CString& str, CPoint& point, int& length, int& width)
{
	str=m_name;
	point=m_point;
	length=m_length;
	width=m_width;
}
