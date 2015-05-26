
// MFC_proj2View.h : CMFC_proj2View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMFC_proj2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_proj2View();
	DECLARE_DYNCREATE(CMFC_proj2View)

	// Ư���Դϴ�.
public:
	CMFC_proj2Doc* GetDocument() const;
	///////////////////////////////bline ����Ʈ
	BOOL bline_status = false;
	///////////////////////////////

	///////////////////////////////brect ����Ʈ
	BOOL brect_status = false;
	CArray<CRect, CRect&> boxes; 
	int current;
	bool move;
	int startx;
	int starty;
	///////////////////////////////

	BOOL bellipse_status = false;
	BOOL btext_status = false;
	// �۾��Դϴ�.
public:
	int mode;

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptPrev;
	afx_msg void OnBline();
	afx_msg void OnBrect();
	afx_msg void OnBellipse();
	afx_msg void OnBtext();
	afx_msg void OnUpdateAfxIdpAskToUpdate(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_proj2View.cpp�� ����� ����
inline CMFC_proj2Doc* CMFC_proj2View::GetDocument() const
{
	return reinterpret_cast<CMFC_proj2Doc*>(m_pDocument);
}
#endif

