#pragma once


// CThickDialog ��ȭ �����Դϴ�.

class CThickDialog : public CDialog
{
	DECLARE_DYNAMIC(CThickDialog)

public:
	CThickDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CThickDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int l_size;
};
