// RightView.cpp: 구현 파일
//

#include "pch.h"
#include "MFCExplorer.h"
#include "RightView.h"



// CRightView

IMPLEMENT_DYNCREATE(CRightView, CListView)

CRightView::CRightView()
{

}

CRightView::~CRightView()
{
}

BEGIN_MESSAGE_MAP(CRightView, CListView)
END_MESSAGE_MAP()


// CRightView 진단

#ifdef _DEBUG


void CRightView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


void CRightView::ShowDirectory()
{
	CListCtrl& rListCtrl = GetListCtrl();

	rListCtrl.DeleteAllItems();

	CFileFind FileFind;
	BOOL bFound = FileFind.FindFile(_T("../*.*"));

	while (bFound)
	{
		bFound = FileFind.FindNextFile();
		// 이름 설정
		CString strName = FileFind.GetFileName();
		// 파일 수정한 시간 설정
		CTime Time;
		CString mdfyTime;
		CString Date[7] = {_T("Sun"), _T("Mon"), _T("Tue"), _T("Wed"),_T("Thu"),_T("Fri"),_T("Sat")};

		FileFind.GetLastWriteTime(Time);

		// 기간, 요일 추가
		mdfyTime.Format(_T("%d-%d-%d"),	Time.GetYear(), Time.GetMonth(), Time.GetDay(), Time.GetDayOfWeek());
		mdfyTime.AppendFormat(_T("(%s)"), Date[Time.GetDayOfWeek()]);
		mdfyTime.AppendFormat(_T(" %d:%d"), Time.GetHour(), Time.GetMinute());

		// 파일 타입, 크기
		CString FileType=strName;
		FileType.Replace(FileFind.GetFileTitle(), _T(""));

		CString FileSize;
		LONGLONG FileByte = (LONGLONG)FileFind.GetLength();
		FileByte = ceil(FileByte / 1000);
		FileSize.Format(_T("%d KB"), FileByte);

		int Fileindex = rListCtrl.GetItemCount();

		// 파일일때 
		if (FileFind.IsArchived())
		{
			rListCtrl.InsertItem(Fileindex, strName.GetBuffer(), 1);	// 파일명
			rListCtrl.SetItemText(Fileindex, 1, mdfyTime.GetBuffer());	// 수정일
			rListCtrl.SetItemText(Fileindex, 2, FileType.GetBuffer());	// 타입
			rListCtrl.SetItemText(Fileindex, 3, FileSize.GetBuffer());	// 파일 사이즈

		}
		// 디렉토리 일때
		else if (FileFind.IsDirectory())
		{
			if (FileFind.IsDots())
			{
				continue;
			}

			rListCtrl.InsertItem(Fileindex, strName.GetBuffer(), 1);	// 파일명
			rListCtrl.SetItemText(Fileindex, 1, mdfyTime.GetBuffer());	// 수정일
			rListCtrl.SetItemText(Fileindex, 2, FileType.GetBuffer());	// 타입
			rListCtrl.SetItemText(Fileindex, 3, FileSize.GetBuffer());	// 파일 사이즈
		}
	}
}

// CRightView 메시지 처리기
void CRightView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	m_PopMenu.LoadMenu(IDR_MENU_LIST);

	CListCtrl& rListCtrl = GetListCtrl();
	rListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	m_ImageList.Create(15, 15, ILC_COLOR24 | ILC_MASK, 2, 0);
	CBitmap bmp; 
	bmp.LoadBitmap(IDB_BITMAP1);
	m_ImageList.Add(&bmp, RGB(255, 0, 255));

	rListCtrl.SetImageList(&m_ImageList, LVSIL_SMALL);

	rListCtrl.SetExtendedStyle(LVS_EX_INFOTIP | LVS_EX_FULLROWSELECT | LVS_EX_UNDERLINEHOT | LVS_EX_ONECLICKACTIVATE);
	
	// 파일 타입 정렬
	rListCtrl.InsertColumn(0, _T("Name"), 0, 200);
	rListCtrl.InsertColumn(1, _T("Modified Date"), 0, 150);
	rListCtrl.InsertColumn(2, _T("Type"), 0, 150);
	rListCtrl.InsertColumn(3, _T("Size"), 0, 100);
		
	ShowDirectory();
}
