
// 222View.h : CMy222View ��Ľӿ�
//

#pragma once


class CMy222View : public CView
{
protected: // �������л�����
	CMy222View();
	DECLARE_DYNCREATE(CMy222View)

// ����
public:
	CMy222Doc* GetDocument() const;

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
	virtual ~CMy222View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int x;
	int y;
	int movex;
	int movey;
public:
	afx_msg void OnJia();
private:
	int speed;
public:
	afx_msg void OnJian();
	afx_msg void OnStop();
	afx_msg void OnContinue();
	afx_msg void OnSpeed();

};

#ifndef _DEBUG  // 222View.cpp �еĵ��԰汾
inline CMy222Doc* CMy222View::GetDocument() const
   { return reinterpret_cast<CMy222Doc*>(m_pDocument); }
#endif

