
// 111View.h : CMy111View ��Ľӿ�
//

#pragma once
#define WM_MY_MESSAGE WM_USER+1

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	LRESULT OnMyMessag(WPARAM wParam, LPARAM lParam);
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // 111View.cpp �еĵ��԰汾
inline CMy111Doc* CMy111View::GetDocument() const
   { return reinterpret_cast<CMy111Doc*>(m_pDocument); }
#endif

