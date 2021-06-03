
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <string>
//#include <tchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 대화 상자


CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_EditDisplayValue(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Button_1);
	DDX_Control(pDX, IDC_BUTTON2, Button_2);
	DDX_Control(pDX, IDC_BUTTON3, Button_3);
	DDX_Control(pDX, IDC_BUTTON4, Button_4);
	DDX_Control(pDX, IDC_BUTTON5, Button_5);
	DDX_Control(pDX, IDC_BUTTON6, Botton_6);
	DDX_Control(pDX, IDC_BUTTON7, Button_7);
	DDX_Control(pDX, IDC_BUTTON8, Button_8);
	DDX_Control(pDX, IDC_BUTTON9, Button_9);
	DDX_Control(pDX, IDC_BUTTON0, Button_0);
	DDX_Control(pDX, IDC_BUTTON_PLUSMINUS, Button_PlusMinus);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, Button_Backspace);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, Button_Divide);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, Button_Multiply);
	DDX_Control(pDX, IDC_BUTTON_MINUS, Button_Minus);
	DDX_Control(pDX, IDC_BUTTON_PLUS, Button_Plus);
	DDX_Control(pDX, IDC_BUTTON_RESULT, Button_Result);
	DDX_Control(pDX, IDC_STATIC_NUMBER, m_StaticDisplay);
	DDX_Control(pDX, IDC_EDIT1, Edit);
	DDX_Text(pDX, IDC_EDIT1, m_EditDisplayValue);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_PLUSMINUS, &CCalculatorDlg::OnBnClickedButtonPlusminus)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CCalculatorDlg::OnBnClickedButtonResult)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////////////////////////////////////////////////////
// 숫자 버튼 클릭
void CCalculatorDlg::OnBnClickedButton0()
{
	UpdateData(TRUE);	// editdisplay에 숫자를 더한다, 문자열을 +로 수를 붙일수있음
	m_EditDisplayValue = m_EditDisplayValue + '0';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);	// 문자형을 int형으로
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '1';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '2';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '3';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '4';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '5';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '6';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton7()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '7';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton8()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '8';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
void CCalculatorDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	m_EditDisplayValue = m_EditDisplayValue + '9';
	m_NowValueTyped = _ttoi(m_EditDisplayValue);
	UpdateData(FALSE);
}
//////////////////////////////////////////////////////////////////////////

// 클리어 버튼
void CCalculatorDlg::OnBnClickedButtonClear()
{
	UpdateData(TRUE);
	m_EditDisplayValue = ' ';		// editcontrol을 초기화
	m_StaticDisplayString = ' ';
	m_StaticDisplay.SetWindowText(m_StaticDisplayString);
	UpdateData(FALSE);
}

//////////////////////////////////////////////////////////////////////////
// 사칙연산 버튼
void CCalculatorDlg::OnBnClickedButtonPlus()
{
	UpdateData(TRUE);
	m_SelectedOperator = IDC_BUTTON_PLUS;		/// 더하기 선택
	m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '+';

	//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '+';
	//m_StaticDisplay.SetWindowText(m_StaticDisplayString);
	//m_FirstValue = _ttoi(m_EditDisplayValue);	// editcontrol의 문자열을 정수로 바꾼후 저장
	//m_EditDisplayValue = ' ';		// editcontrol을 초기화
	ContinueCalculating();

	UpdateData(FALSE);		// 변경된 변수를 editcontrol로 보낸다
}
void CCalculatorDlg::OnBnClickedButtonMinus()
{
	UpdateData(TRUE);
	m_SelectedOperator = IDC_BUTTON_MINUS;		/// 빼기 선택
	m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '-';

	//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '-';
	//m_StaticDisplay.SetWindowText(m_StaticDisplayString);
	//m_FirstValue = _ttoi(m_EditDisplayValue);	// editcontrol의 문자열을 정수로 바꾼후 저장
	//m_EditDisplayValue = ' ';		// editcontrol을 초기화
	ContinueCalculating();
	UpdateData(FALSE);		// 변경된 변수를 editcontrol로 보낸다
}
void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	UpdateData(TRUE);
	m_SelectedOperator = IDC_BUTTON_MULTIPLY;	/// 곱하기 선택
	m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '*';

	//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '*';
	//m_StaticDisplay.SetWindowText(m_StaticDisplayString);
	//m_FirstValue = _ttoi(m_EditDisplayValue);	// editcontrol의 문자열을 정수로 바꾼후 저장
	//m_EditDisplayValue = ' ';		// editcontrol을 초기화
	ContinueCalculating();
	UpdateData(FALSE);		// 변경된 변수를 editcontrol로 보낸다
}
void CCalculatorDlg::OnBnClickedButtonDivide()
{
	UpdateData(TRUE);
	m_SelectedOperator = IDC_BUTTON_DIVIDE;		/// 나누기 선택
	m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '/';

	//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '/';
	//m_StaticDisplay.SetWindowText(m_StaticDisplayString);
	//m_FirstValue = _ttoi(m_EditDisplayValue);	// editcontrol의 문자열을 정수로 바꾼후 저장
	//m_EditDisplayValue = ' ';		// editcontrol을 초기화
	ContinueCalculating();
	UpdateData(FALSE);		// 변경된 변수를 editcontrol로 보낸다
}
//////////////////////////////////////////////////////////////////////////

// 양수 음수 버튼
void CCalculatorDlg::OnBnClickedButtonPlusminus()
{
	UpdateData(TRUE);
	m_NowValueTyped = _ttoi(m_EditDisplayValue) * (-1);
	m_EditDisplayValue = '-'+m_EditDisplayValue;

	UpdateData(FALSE);

}

// 결과 버튼
void CCalculatorDlg::OnBnClickedButtonResult()
{
	UpdateData(TRUE);

	//ContinueCalculating();	

	// 결과 버튼은 현재 연산자로 계산을 마무리
	switch (m_SelectedOperator)	// 계산 스위치문
	{
		case IDC_BUTTON_PLUS:
		{
			m_ResultSaved = m_ResultSaved + m_NowValueTyped;
		}
		break;

		case IDC_BUTTON_MINUS:
		{
			m_ResultSaved = m_ResultSaved - m_NowValueTyped;
		}
		break;

		case IDC_BUTTON_MULTIPLY:
		{
			m_ResultSaved = m_ResultSaved * m_NowValueTyped;
		}
		break;

		case IDC_BUTTON_DIVIDE:
		{
			if (m_NowValueTyped == 0)
			{
				AfxMessageBox(errormsg);

				m_EditDisplayValue = ' ';		// editcontrol을 초기화

				UpdateData(FALSE);

				return;
			}

			m_ResultSaved = m_ResultSaved / m_NowValueTyped;
		}
		break;
	}// end of SelectedOperator

	// staticdisplay에 출력
	m_StaticDisplayString.Format(_T("%d //"), m_ResultSaved);	// 결과 값의 포맷 변경
	m_StaticDisplay.SetWindowText(m_StaticDisplayString);

	m_EditDisplayValue = ' ';		// editcontrol을 초기화

	UpdateData(FALSE);

	// 처음 입력 초기화
	m_IsFirstValue = true;
	m_ResultSaved = 0;
}

void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

// 사칙연산 버튼 클릭 후 연산을 이어나가는 함수
void CCalculatorDlg::ContinueCalculating()
{
	m_BeforeValueTyped = m_NowValueTyped;	// 입력한 숫자를 이전 숫자로 저장

	if (m_IsFirstValue == true)	// 첫 입력값 처리
	{
		m_ResultSaved = m_NowValueTyped;
	}

	if (m_IsFirstValue == false)
	{
		switch (m_LastOperator)	// 이전 연산자 계산 스위치문 
		{
			case IDC_BUTTON_PLUS:
			{
				//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '+';

				m_ResultSaved = m_ResultSaved + m_BeforeValueTyped;
			}
			break;

			case IDC_BUTTON_MINUS:
			{
				//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '-';

				m_ResultSaved = m_ResultSaved - m_BeforeValueTyped;
			}
			break;

			case IDC_BUTTON_MULTIPLY:
			{
				//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '*';

				m_ResultSaved = m_ResultSaved * m_BeforeValueTyped;
			}
			break;

			case IDC_BUTTON_DIVIDE:
			{
				//m_StaticDisplayString = m_StaticDisplayString + m_EditDisplayValue + '/';

				if (m_NowValueTyped == 0)	// 0으로 나눌수 없음 경고문
				{
					AfxMessageBox(errormsg);

					m_EditDisplayValue = ' ';		// editcontrol을 초기화				

					UpdateData(FALSE);

					return;
				}

				m_ResultSaved = m_ResultSaved / m_BeforeValueTyped;
			}
			break;
		}// end of SelectedOperator
	}// end of isfirsttypedvalue

	m_IsFirstValue = false;	// 첫 입력 후 false로 변경
	m_LastOperator = m_SelectedOperator;	// 계산을 이어나가기 위해 이전연산자 저장

	m_StaticDisplay.SetWindowText(m_StaticDisplayString);	// staticdisplay에 입력

	m_EditDisplayValue = ' ';		// editcontrol을 초기화
}

