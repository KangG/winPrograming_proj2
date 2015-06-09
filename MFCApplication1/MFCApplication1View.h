
// MFCApplication1View.h : CMFCApplication1View 클래스의 인터페이스
//

#pragma once
#include"MFCApplication1Doc.h"

class CMFCApplication1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// 특성입니다.
public:
	CMFCApplication1Doc* GetDocument() const;
	BOOL bline_status = false;
	BOOL brect_status = false;
	BOOL bellipse_status = false;
	BOOL btext_status = false;
	BOOL bpoly_status = false;
	BOOL bpoly_new = false;
	BOOL group_status = false;



	BOOL isDel = false;
	BOOL ispoint = false;
	BOOL isall = false;	//전체 선택때 사용


	int current_l;		//Line 현재 배열번호
	int current_r;		//Rect 현재 배열번호
	int current_e;		//Ellipse 현재 배열번호
	int current_p;		//poly 현재 배열번호
	int current_t;		//Text 현재 배열번호
	bool move;


	COLORREF color;
	Point p_point;
	Line line;
	ARectangle rect;
	AEllipse ell;
	APolyline poly;

	CArray<Line, Line&> figure;							//모든 객체를 저장할 배열 

	int select_mode;
	int select_num;
	int select_point;									//점선택때 사용
	int move_select;
	CPoint prev;

// 작업입니다.
public:
	int mode;
	CPoint m_ptPrev;
	
	//Thick 다이얼로그 변수
	double l_size;
	//Pattern 다이얼로그 변수
	int pattern1;
	int pattern2;
	

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCApplication1View();
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
	afx_msg void OnFont();
	afx_msg void OnTextcolor();
	afx_msg void OnPattern();
	afx_msg void OnThick();
	afx_msg void OnGroup();
	afx_msg void OnBgcolor();
};

#ifndef _DEBUG  // MFCApplication1View.cpp의 디버그 버전
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

