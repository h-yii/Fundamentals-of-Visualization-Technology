
// 111View.h : CMy111View 类的接口
//

#pragma once
#define WM_MY_MESSAGE WM_USER+1

class CMy111View : public CView
{
protected: // 仅从序列化创建
	CMy111View();
	DECLARE_DYNCREATE(CMy111View)

// 特性
public:
	CMy111Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 111View.cpp 中的调试版本
inline CMy111Doc* CMy111View::GetDocument() const
   { return reinterpret_cast<CMy111Doc*>(m_pDocument); }
#endif

