// ThickDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ThickDialog.h"
#include "afxdialogex.h"


// CThickDialog ��ȭ �����Դϴ�.

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


// CThickDialog �޽��� ó�����Դϴ�.
