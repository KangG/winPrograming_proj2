
// MFC_proj2View.h : CMFC_proj2View Ŭ������ �������̽�
//

#pragma once


class CMFC_proj2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_proj2View();
	DECLARE_DYNCREATE(CMFC_proj2View)

	// Ư���Դϴ�.
public:
	CMFC_proj2Doc* GetDocument() const;

	// �۾��Դϴ�.
public:

	// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// �����Դϴ�.
public:
	virtual ~CMFC_proj2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC_proj2View.cpp�� ����� ����
inline CMFC_proj2Doc* CMFC_proj2View::GetDocument() const
{
	return reinterpret_cast<CMFC_proj2Doc*>(m_pDocument);
}
#endif

