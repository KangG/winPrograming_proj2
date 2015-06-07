
// MFCApplication1View.cpp : CMFCApplication1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mode 번호
#define DL 1		//line 그리기
#define DR 2		//rect 그리기
#define DE 3		//ellipse 그리기
#define DT 4		//text 그리기
#define DP 5		//polyline 그리기

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DL, &CMFCApplication1View::OnDline)
	ON_COMMAND(ID_DR, &CMFCApplication1View::OnDrect)
	ON_COMMAND(ID_DE, &CMFCApplication1View::OnDell)
	ON_COMMAND(ID_DP, &CMFCApplication1View::OnDpoly)
	ON_COMMAND(ID_DT, &CMFCApplication1View::OnDtext)
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_ptPrev = 0;
	current_l = -1;
	current_r = -1;
	current_e = -1;
	current_p = -1;
	move = false;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplication1View 인쇄


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기


void CMFCApplication1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);

	for (int i = 0; i < Line_array.GetCount(); i++) {										//저장된 Line 그리기
		Line_array[i].draw(&dc, Line_array[i].getEnd_x(), Line_array[i].getEnd_y());
	}
	for (int i = 0; i < ARect_array.GetCount(); i++) {										//저장된 Rect 그리기
		ARect_array[i].draw(&dc, ARect_array[i].getEnd_x(), ARect_array[i].getEnd_y());
	}
	for (int i = 0; i < AEll_array.GetCount(); i++) {										//저장된 Ellipse 그리기
		AEll_array[i].draw(&dc, AEll_array[i].getEnd_x(), AEll_array[i].getEnd_y());
	}
}


void CMFCApplication1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point); CClientDC dc(this);

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
	case DL:
	{
		Line* l = new Line();
		Line_array.Add(*l);
		current_l = Line_array.GetCount() - 1;

		Line_array[current_l].setStart_x(point.x);
		Line_array[current_l].setStart_y(point.y);
		Line_array[current_l].setFlag(1);

		move = true;
		break;
	}
	case DR:
	{
		ARectangle* r = new ARectangle();
		ARect_array.Add(*r);
		current_r = ARect_array.GetCount() - 1;
		ARect_array[current_r].setStart_x(point.x);
		ARect_array[current_r].setStart_y(point.y);
		ARect_array[current_r].setFlag(2);

		move = true;
		break;
	}
	case DE:
	{
		AEllipse* e = new AEllipse();
		AEll_array.Add(*e);
		current_e = AEll_array.GetCount() - 1;
		AEll_array[current_e].setStart_x(point.x);
		AEll_array[current_e].setStart_y(point.y);
		AEll_array[current_e].setFlag(3);

		move = true;
		break;
	}
	case DT:
	{
		Line* t = new Line;
		Line_array.Add(*t);
		/*current_t = figure.GetCount() - 1;
		figure[current].setStart_x(point.x);
		figure[current].setStart_y(point.y);*/

		move = true;
		break;
	}
	}
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	//// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
	case DL:
	case DR:
	case DE:
	case DT:
	{
		move = false;
		break;
	}
	case DP:
	{

			   TRACE("%d", poly.poly_array.GetSize());
		p_point.setX(point.x);
		p_point.setY(point.y);
		poly.next(p_point);
		poly.draw(&dc);
			break;
	}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	switch (mode)
	{
	case DL:
	{
		if (move == true){
			Line_array[current_l].draw(&dc, point.x, point.y);
		}
		Invalidate();
		break;
	}
	case DR:
	{
		if (move == true){
			ARect_array[current_r].draw(&dc, point.x, point.y);
		}
		Invalidate();
		break;
	}
	case DE:
	{
		if (move == true){
			AEll_array[current_e].draw(&dc, point.x, point.y);
		}
		Invalidate();
		break;
	}
	case DT:
	{
		if (move == true){
			// figure[current].draw(&dc, point.x, point.y);
		}
		Invalidate();
		break;
	}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1View::OnDline()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DL; 
	if (!bline_status)
	{
		bline_status = true;
		brect_status = false;
		bellipse_status = false;
		btext_status = false;
		bpoly_status = false;
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
}


void CMFCApplication1View::OnDrect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DR;
	if (!bline_status)
	{
		bline_status = false;
		brect_status = true;
		bellipse_status = false;
		btext_status = false;
		bpoly_status = false;
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
}


void CMFCApplication1View::OnDell()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DE;
	if (!bline_status)
	{
		bline_status = false;
		brect_status = false;
		bellipse_status = true;
		btext_status = false;
		bpoly_status = false;
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
}


void CMFCApplication1View::OnDpoly()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DP;
	if (!bline_status)
	{
		bline_status = false;
		brect_status = false;
		bellipse_status = false;
		btext_status = false;
		bpoly_status = true;
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
}


void CMFCApplication1View::OnDtext()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DT;
	if (!bline_status)
	{
		bline_status = false;
		brect_status = false;
		bellipse_status = false;
		btext_status = true;
		bpoly_status = false;
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
}
