// ThickDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ThickDialog.h"
#include "afxdialogex.h"


// CThickDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CThickDialog, CDialog)

CThickDialog::CThickDialog(CWnd* pParent /*=NULL*/)
: CDialog(CThickDialog::IDD, pParent)
, l_size(1)
{

}

CThickDialog::~CThickDialog()
{
}

void CThickDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, l_size);
	DDV_MinMaxInt(pDX, l_size, 1, 30);
}


BEGIN_MESSAGE_MAP(CThickDialog, CDialog)
END_MESSAGE_MAP()


// CThickDialog 메시지 처리기입니다.
