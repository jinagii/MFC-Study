// LeftView.cpp: 구현 파일
//

#include "pch.h"
#include "MFCExplorer.h"
#include "LeftView.h"
#include "Resource.h"

// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

CLeftView::CLeftView()
{
}

CLeftView::~CLeftView()
{
}

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	ON_WM_UPDATEUISTATE()
END_MESSAGE_MAP()

// CLeftView 진단

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG

// CLeftView 메시지 처리기

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	m_PopMenu.LoadMenu(IDR_MENU_LIST);

	CTreeCtrl& rTreeCtrl = GetTreeCtrl();
	rTreeCtrl.ModifyStyle(0, TVS_HASBUTTONS | TVS_HASLINES, SWP_FRAMECHANGED);

	m_ImageTree.Create(15, 15, ILC_COLOR24 | ILC_MASK, 2, 0);

	CBitmap bmp; bmp.LoadBitmap(IDB_BITMAP1);
	m_ImageTree.Add(&bmp, RGB(255, 0, 255));

	rTreeCtrl.SetImageList(&m_ImageTree, TVSIL_NORMAL);

	// 트리노드 추가
	HTREEITEM root = rTreeCtrl.InsertItem(_T("C:"), 0, 0, TVI_ROOT, TVI_LAST);

	FindSubDirectory(root, _T("./"));
	
	rTreeCtrl.Expand(root, TVE_EXPAND);

	// 최초실행시에 작업폴더의 내용들을 트리에 보여줌.
}

void CLeftView::FindSubDirectory(HTREEITEM hParentItem, CString strDir)
{
	strDir += _T("/*.*");

	CFileFind FileFind;
	BOOL bFound = FileFind.FindFile(strDir);

	while (bFound)
	{
		bFound = FileFind.FindNextFile();
		// 점일때
		if (FileFind.IsDots())
		{
			continue;
		}
		// 디렉토리일때
		if (FileFind.IsDirectory())
		{
			FindSubDirectory(GetTreeCtrl().InsertItem(FileFind.GetFileName(),
				0, 0, hParentItem, TVI_LAST), FileFind.GetFilePath());
		}
		else
		{
			GetTreeCtrl().InsertItem(FileFind.GetFileName(), 1, 1, hParentItem, TVI_LAST);
		}
	}
}

//
//void CLeftView::OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/)
//{
//	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
//	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	TCHAR Path[256];
//	GetCurrentDirectory(256, Path);
//	CString strPath(Path);
//	strPath=strPath.Right(strPath.GetLength()-)
//
//
//}
