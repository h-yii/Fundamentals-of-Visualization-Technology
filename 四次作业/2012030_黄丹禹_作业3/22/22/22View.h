
// 22View.h : CMy22View ��Ľӿ�
//

#pragma once


class CMy22View : public CScrollView
{
protected: // �������л�����
	CMy22View();
	DECLARE_DYNCREATE(CMy22View)

// ����
public:
	CMy22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // 22View.cpp �еĵ��԰汾
inline CMy22Doc* CMy22View::GetDocument() const
   { return reinterpret_cast<CMy22Doc*>(m_pDocument); }
#endif

