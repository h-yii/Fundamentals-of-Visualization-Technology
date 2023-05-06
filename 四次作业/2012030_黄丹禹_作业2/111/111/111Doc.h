
// 111Doc.h : CMy111Doc ��Ľӿ�
//


#pragma once


class CMy111Doc : public CDocument
{
protected: // �������л�����
	CMy111Doc();
	DECLARE_DYNCREATE(CMy111Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy111Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

private:
	CString m_name;
	CPoint m_point;
	int m_length;
	int m_width;

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void Set(CString& str, CPoint& point, int& length, int& width);
	void Get(CString& str, CPoint& point, int& length, int& width);
};
