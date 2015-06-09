
// MFCApplication1View.h : CMFCApplication1View Ŭ������ �������̽�
//

#pragma once
#include "Point.h"
#include "Line.h"
#include "AEllipse.h"
#include "ARectangle.h"
#include "APolyline.h"
#include "Text.h"

class CMFCApplication1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// Ư���Դϴ�.
public:
	CMFCApplication1Doc* GetDocument() const;
	BOOL bline_status = false;
	BOOL brect_status = false;
	BOOL bellipse_status = false;
	BOOL btext_status = false;
	BOOL bpoly_status = false;
	BOOL bpoly_new = false;
	
	BOOL isDel = false;
	BOOL ispoint = false;
	BOOL isall = false;	//��ü ���ö� ���


	int current_l;		//Line ���� �迭��ȣ
	int current_r;		//Rect ���� �迭��ȣ
	int current_e;		//Ellipse ���� �迭��ȣ
	int current_p;		//poly ���� �迭��ȣ
	int current_t;		//Text ���� �迭��ȣ
	bool move;


	COLORREF color;
	Point p_point;
	Line line;
	ARectangle rect;
	AEllipse ell;
	APolyline poly;

	CArray<Line, Line&> figure;							//��� ��ü�� ������ �迭 
	CArray<ARectangle, ARectangle&> ARect_array;		//Rect ��ü�� �����ҹ迭
	CArray<AEllipse, AEllipse&> AEll_array;				//Ellipse ��ü�� �����ҹ迭
	CArray<APolyline, APolyline&> APolyline_array;		//PolyLine ��ü�� �����ҹ迭

	int select_mode;
	int select_num;
	int select_point;									//�����ö� ���
	int move_select;
	CPoint prev;

// �۾��Դϴ�.
public:
	int mode;
	CPoint m_ptPrev;

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFCApplication1View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDline();
	afx_msg void OnDrect();
	afx_msg void OnDell();
	afx_msg void OnDpoly();
	afx_msg void OnDtext();
	afx_msg void OnSelect();
	afx_msg void OnOc();
	afx_msg void OnIc();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDelete();
};

#ifndef _DEBUG  // MFCApplication1View.cpp�� ����� ����
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

