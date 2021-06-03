
// CalculatorDlg.h: 헤더 파일
//
#pragma once

// CCalculatorDlg 대화 상자
class CCalculatorDlg : public CDialogEx
{
	// 생성입니다.
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	// 버튼 변수 (일단 만들어둠)
	CButton Button_1;
	CButton Button_2;
	CButton Button_3;
	CButton Button_4;
	CButton Button_5;
	CButton Botton_6;
	CButton Button_7;
	CButton Button_8;
	CButton Button_9;
	CButton Button_0;
	CButton Button_PlusMinus;
	CButton Button_Backspace;
	CButton Button_Divide;
	CButton Button_Multiply;
	CButton Button_Minus;
	CButton Button_Plus;
	CButton Button_Result;

	// EditDisplay
	CString m_EditDisplayValue;
	CEdit Edit;

	// StaticDisplay
	CStatic m_StaticDisplay;
	CString m_StaticDisplayString;

	// 계산할때 저장되는 변수들
	int m_SelectedOperator = 0;	// 선택된 연산
	int m_NowValueTyped = 0;	// 지금 입력한 수
	int m_BeforeValueTyped = 0;	// 이전에 입력한 수
	bool m_IsFirstValue = true;	// 첫번째 입력인가
	int m_LastOperator = 0;		// 마지막 연산
	int m_ResultSaved = 0;		// 계산 결과 저장

	// 에러메세지 처리용
	CString errormsg = _T("Calculating error. \n Type other number.");

	// 버튼 클릭 메세지 함수
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonPlusminus();
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnEnChangeEdit1();

	void ContinueCalculating();
};

/// Psuedo code
// 1. 숫자 클릭
//		- m_EditDisplayValue -> m_NowValueTyped
//
// 2. 연산자 클릭
//		- 처음 클릭 시 -> 숫자만 staticdisplay에 출력
//		- 이후 클릭 시 -> m_ResultSaved와 m_BeforeValueTyped를 계산
// 3. 결과 클릭
//		- m_Now
//		음... 왜안돼...


