#pragma once


// CLeftView 보기

class CLeftView : public CTreeView
{
	DECLARE_DYNCREATE(CLeftView)

protected:
	CLeftView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLeftView();

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

public:
	void FindSubDirectory(HTREEITEM hParentItem, CString strDir);

private:
	CImageList m_ImageTree;
	CMenu m_PopMenu;

public:
	//afx_msg void OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/);
};


