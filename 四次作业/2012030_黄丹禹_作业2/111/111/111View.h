
// 111View.h : CMy111View ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CMy111View : public CView
{
protected: // �������л�����
	CMy111View();
	DECLARE_DYNCREATE(CMy111View)

// ����
public:
	CMy111Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPopmenuRec();
	afx_msg void OnPopmenuEllipse();
};

#ifndef _DEBUG  // 111View.cpp �еĵ��԰汾
inline CMy111Doc* CMy111View::GetDocument() const
   { return reinterpret_cast<CMy111Doc*>(m_pDocument); }
#endif

