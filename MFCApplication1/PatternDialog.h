#pragma once
#include "afxwin.h"


// PatternDialog ��ȭ �����Դϴ�.

class PatternDialog : public CDialogEx
{
	DECLARE_DYNAMIC(PatternDialog)

public:
	PatternDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PatternDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;
	CComboBox m_combo2;
	int pattern1;
	int pattern2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
};
