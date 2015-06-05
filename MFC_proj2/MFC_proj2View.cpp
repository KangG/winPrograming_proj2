
// MFC_proj2View.cpp : CMFC_proj2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_proj2.h"
#endif

#include "MFC_proj2Doc.h"
#include "MFC_proj2View.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mode 번호
#define DL 1		//line 그리기
#define DR 2		//rect 그리기
#define DE 3		//ellipse 그리기
#define DT 4		//text 그리기
#define DP 5		//polyline 그리기

// CMFC_proj2View

IMPLEMENT_DYNCREATE(CMFC_proj2View, CView)

BEGIN_MESSAGE_MAP(CMFC_proj2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_BLine, &CMFC_proj2View::OnBline)
	ON_COMMAND(ID_BRect, &CMFC_proj2View::OnBrect)
	ON_COMMAND(ID_BEllipse, &CMFC_proj2View::OnBellipse)
	ON_COMMAND(ID_BText, &CMFC_proj2View::OnBtext)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(AFX_IDP_ASK_TO_UPDATE, &CMFC_proj2View::OnUpdateAfxIdpAskToUpdate)
	ON_COMMAND(ID_BPolyline, &CMFC_proj2View::OnBpolyline)
END_MESSAGE_MAP()

// CMFC_proj2View 생성/소멸

CMFC_proj2View::CMFC_proj2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_ptPrev = 0;
	current_l = -1;
	current_r = -1;
	current_e = -1;
	current_t = -1;
	move = false;
}

CMFC_proj2View::~CMFC_proj2View()
{
}

BOOL CMFC_proj2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC_proj2View 그리기

void CMFC_proj2View::OnDraw(CDC* pDC)
{
	CMFC_proj2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CPaintDC dc(this);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMFC_proj2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC_proj2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC_proj2View 진단

#ifdef _DEBUG
void CMFC_proj2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_proj2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_proj2Doc* CMFC_proj2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_proj2Doc)));
	return (CMFC_proj2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_proj2View 메시지 처리기


void CMFC_proj2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

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
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

}


void CMFC_proj2View::OnBline()
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
	/*
		모드를 끌때는 다시한번 툴바를 눌러주어서 끄는데,
		이때 모드를 다시 0으로 초기화 해준다.
		->다른 버튼 클릭시 자동으로 꺼지도록 변경
		*/
}


void CMFC_proj2View::OnBrect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DR;
	if (!brect_status)
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
	/*
	모드를 끌때는 다시한번 툴바를 눌러주어서 끄는데,
	이때 모드를 다시 0으로 초기화 해준다.
	->다른 버튼 클릭시 자동으로 꺼지도록 변경
	*/
}


void CMFC_proj2View::OnBellipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DE;
	if (!bellipse_status)
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


void CMFC_proj2View::OnBtext()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mode = DT;
	if (!btext_status)
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


void CMFC_proj2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

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
			   Text* t = new Text;
			   Text_array.Add(*t);
			   current_t = Text_array.GetCount() - 1;
			   Text_array[current_t].setStart_x(point.x);
			   Text_array[current_t].setStart_y(point.y);

			   move = true;
			   break;
	}
	}
}


void CMFC_proj2View::OnLButtonUp(UINT nFlags, CPoint point)
{
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
			   Point temp;
			   temp.setX(point.x);
			   temp.setY(point.y);
			   if (poly.get_index() == 0)
			   {
				   poly.temp.setStart_x(temp.getX());
				   poly.temp.setStart_y(temp.getY());
				   break;
			   }
			   else
			   {
				   poly.next(temp);
				   poly.draw(&dc);
				   break;
			   }
	}
	}
}


void CMFC_proj2View::OnMouseMove(UINT nFlags, CPoint point)
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
			Text_array[current_t].makeRect(&dc, point.x, point.y);
		}
	//	Invalidate();
		break;
	}
	}
}


void CMFC_proj2View::OnUpdateAfxIdpAskToUpdate(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	// 버튼 활성화 비활성화를 여기서 담당해 준다.
	if (mode == DL)
	{
		pCmdUI->Enable(bline_status);
	}
	else if (mode == DR)
	{
		pCmdUI->Enable(brect_status);
	}
	else if (mode == DP)
	{
		pCmdUI->Enable(bpoly_status);
	}
}


void CMFC_proj2View::OnBpolyline()
{
	mode = DP;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!bpoly_status)
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


//void CMFC_proj2View::OnUpdateBpolyline(CCmdUI *pCmdUI)
//{
//	pCmdUI->Enable(bpoly_status);
//	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
//}
