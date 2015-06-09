// PatternDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "PatternDialog.h"
#include "afxdialogex.h"


// PatternDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PatternDialog, CDialogEx)

PatternDialog::PatternDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(PatternDialog::IDD, pParent)
{

}

PatternDialog::~PatternDialog()
{
}

void PatternDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
}


BEGIN_MESSAGE_MAP(PatternDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &PatternDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// PatternDialog 메시지 처리기입니다.


BOOL PatternDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	
	
	m_combo1.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void PatternDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);



	CDialogEx::OnOK();
}
