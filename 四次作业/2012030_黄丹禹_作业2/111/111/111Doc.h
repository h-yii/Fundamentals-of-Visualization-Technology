
// 111Doc.h : CMy111Doc 类的接口
//


#pragma once


class CMy111Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy111Doc();
	DECLARE_DYNCREATE(CMy111Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy111Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	CString m_name;
	CPoint m_point;
	int m_length;
	int m_width;

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void Set(CString& str, CPoint& point, int& length, int& width);
	void Get(CString& str, CPoint& point, int& length, int& width);
};
