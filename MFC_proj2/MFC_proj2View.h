
// MFC_proj2View.h : CMFC_proj2View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"
#include "stdafx.h"
#include "Line.h"
#include "ARectangle.h"
#include "AEllipse.h"
#include "APolyline.h"

class CMFC_proj2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC_proj2View();
	DECLARE_DYNCREATE(CMFC_proj2View)

	// 특성입니다.
public:
	CMFC_proj2Doc* GetDocument() const;
	///////////////////////////////
	BOOL bline_status = false;
	BOOL brect_status = false;
	BOOL bellipse_status=false;
	BOOL btext_status = false;
	BOOL bpoly_status = false;

	int current_l;		//Line 현재 배열번호
	int current_r;		//Rect 현재 배열번호
	int current_e;		//Ellipse 현재 배열번호
	bool move;

	Line line;
	ARectangle rect;
	AEllipse ell;
	APolyline poly;

	CArray<Line, Line&> figure;							//모든 객체를 저장할 배열 
	CArray<Line, Line&> Line_array;						//Line 객체를 저장할배열
	CArray<ARectangle, ARectangle&> ARect_array;		//Rect 객체를 저장할배열
	CArray<AEllipse, AEllipse&> AEll_array;				//Ellipse 객체를 저장할배열
	CArray<APolyline, APolyline&> APolyline_array;		//PolyLine 객체를 저장할배열
	///////////////////////////////
	// 작업입니다.
public:
	int mode;

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// 구현입니다.
public:
	virtual ~CMFC_proj2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
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
	afx_msg void OnBpolyline();
};

#ifndef _DEBUG  // MFC_proj2View.cpp의 디버그 버전
inline CMFC_proj2Doc* CMFC_proj2View::GetDocument() const
{
	return reinterpret_cast<CMFC_proj2Doc*>(m_pDocument);
}
#endif

