
// 111Doc.cpp : CMy111Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CMy111Doc 构造/析构

CMy111Doc::CMy111Doc()
{
	// TODO: 在此添加一次性构造代码
	
}

CMy111Doc::~CMy111Doc()
{
}

BOOL CMy111Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy111Doc 序列化

void CMy111Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<m_name<<m_point<<m_length<<m_width;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>m_name>>m_point>>m_length>>m_width;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy111Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CMy111Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CMy111Doc 诊断

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


// CMy111Doc 命令


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
