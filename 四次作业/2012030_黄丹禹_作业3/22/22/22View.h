
// 22View.h : CMy22View 类的接口
//

#pragma once


class CMy22View : public CScrollView
{
protected: // 仅从序列化创建
	CMy22View();
	DECLARE_DYNCREATE(CMy22View)

// 特性
public:
	CMy22Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBmp1();
	afx_msg void OnBmp2();
	afx_msg void OnBmp3();
private:
	int flag;
public:
	afx_msg void OnFree();
	CString str1;
	int num;
};

#ifndef _DEBUG  // 22View.cpp 中的调试版本
inline CMy22Doc* CMy22View::GetDocument() const
   { return reinterpret_cast<CMy22Doc*>(m_pDocument); }
#endif

