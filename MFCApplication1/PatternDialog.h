#pragma once
#include "afxwin.h"


// PatternDialog 대화 상자입니다.

class PatternDialog : public CDialogEx
{
	DECLARE_DYNAMIC(PatternDialog)

public:
	PatternDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PatternDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;
	CComboBox m_combo2;
};
