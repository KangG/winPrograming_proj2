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
END_MESSAGE_MAP()


// PatternDialog �޽��� ó�����Դϴ�.
