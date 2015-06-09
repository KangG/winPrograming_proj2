// PatternDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "PatternDialog.h"
#include "afxdialogex.h"


// PatternDialog ��ȭ �����Դϴ�.

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


// PatternDialog �޽��� ó�����Դϴ�.


BOOL PatternDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	
	
	m_combo1.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void PatternDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);



	CDialogEx::OnOK();
}
