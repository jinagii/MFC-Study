#pragma once


// CRightView 보기

class CRightView : public CListView
{
	DECLARE_DYNCREATE(CRightView)

protected:
	CRightView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CRightView();

private:
	CImageList m_ImageList;
	CMenu m_PopMenu;

public:
	afx_msg void ShowDirectory();



public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


