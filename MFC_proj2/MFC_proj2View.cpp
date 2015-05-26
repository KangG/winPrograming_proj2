
// MFC_proj2View.cpp : CMFC_proj2View 클래스의 구현
//

#include "stdafx.h"
#include "Line.h"
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
#define ML 6		//line 옮기기
#define MR 7		//rect 옮기기
#define ME 8		//ellipse 옮기기
#define MT 9		//text 옮기기
#define MP 10		//polyline 옮기기

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
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_proj2View 생성/소멸

CMFC_proj2View::CMFC_proj2View()
: m_ptPrev(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	current = -1;
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
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	Line *l = new Line();
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
	}
	else
	{
		//나중에 툴바 눌러진 모양으로 바꿀꺼면 여기에 코드 추가
	}
	
}


void CMFC_proj2View::OnLButtonDown(UINT nFlags, CPoint point)
{

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
		/////////////////////////////bline 부분이다.
	case DL:
	{
		SetCapture();
		m_ptPrev = point;
		CView::OnLButtonDown(nFlags, point);
		break;
	}
	/////////////////////////////rect 부분이다.
	case DR:
	{
		startx = point.x;
		starty = point.y;

		CRect* box = new CRect(point.x, point.y, point.x, point.y);
		boxes.Add(*box);
		current = boxes.GetCount() - 1;
		
		break;
	}
	case DE:
	{
		startx = point.x;
		starty = point.y;

		CRect* box = new CRect(point.x, point.y, point.x, point.y);
		boxes.Add(*box);
		current = boxes.GetCount() - 1;
		
		break;
	}
	case DT:
	{
		startx = point.x;
		starty = point.y;

		CRect* box = new CRect(point.x, point.y, point.x, point.y);
		boxes.Add(*box);
		current = boxes.GetCount() - 1;
		
		break;
	}
	case MR:
	case ME:
	{
		startx = point.x;
		starty = point.y;

		current = -1;
		for (int i = 0; i < boxes.GetCount(); i++) {
			if (boxes[i].left <= point.x && point.x <= boxes[i].right ||
				boxes[i].right <= point.x && point.x <= boxes[i].left) {

				if (boxes[i].top <= point.y && point.y <= boxes[i].bottom ||
					boxes[i].bottom <= point.y && point.y <= boxes[i].top) {

					current = i;
					move = true;
					break;
				}
			}
		}
		break;
	}
	}
}


void CMFC_proj2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
	case DL:
	{
		ReleaseCapture();
		CView::OnLButtonUp(nFlags, point);
		break;
	}
	case DR:
	{
		if (current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_COPYPEN);

			dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			current = -1;
			move = false;
		}
	}
	case DE:
	{
		if (current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_COPYPEN);

			dc.Ellipse(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			current = -1;
			move = false;
		}
	}
	case DT:
	{
		if (current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_COPYPEN);

			dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			current = -1;
			move = false;
		}
	}
	case MR:
	{
		if (current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_COPYPEN);

			dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			current = -1;
			move = false;
		}
	}
	case ME:
	{
		if (current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_COPYPEN);

			dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			current = -1;
			move = false;
		}
	}
	}
}


void CMFC_proj2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
	case DL:
	{
		if (GetCapture() != this)
			return;

		CClientDC dc(this);
		dc.MoveTo(m_ptPrev);
		dc.LineTo(point);

		m_ptPrev = point;
		CView::OnMouseMove(nFlags, point);
		break;
	}
	case DR:
	{
		if (nFlags & MK_LBUTTON == 1 && current != -1) {

				CClientDC dc(this);
				dc.SelectStockObject(NULL_BRUSH);
				dc.SetROP2(R2_NOT);

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

				// 크기 변경
				boxes[current].right = point.x;
				boxes[current].bottom = point.y;

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

		}
		break;
	}
	case DE:
	{
		if (nFlags & MK_LBUTTON == 1 && current != -1) {

				CClientDC dc(this);
				dc.SelectStockObject(NULL_BRUSH);
				dc.SetROP2(R2_NOT);

				dc.Ellipse(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

				// 크기 변경
				boxes[current].right = point.x;
				boxes[current].bottom = point.y;

				dc.Ellipse(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

		}
		break;
	}
	case DT:
	{
		if (nFlags & MK_LBUTTON == 1 && current != -1) {

				CClientDC dc(this);
				dc.SelectStockObject(NULL_BRUSH);
				dc.SetROP2(R2_NOT);

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

				// 크기 변경
				boxes[current].right = point.x;
				boxes[current].bottom = point.y;

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);
		}
		break;
	}
	case MR:
	{
		if (nFlags & MK_LBUTTON == 1 && current != -1) {	
				CClientDC dc(this);
				dc.SelectStockObject(NULL_BRUSH);
				dc.SetROP2(R2_NOT);

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

				// 이동
				boxes[current].left += point.x - startx;
				boxes[current].top += point.y - starty;
				boxes[current].right += point.x - startx;
				boxes[current].bottom += point.y - starty;

				startx = point.x;
				starty = point.y;

				dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);
			
		}
		break;
	}
	case ME:
	{
		if (nFlags & MK_LBUTTON == 1 && current != -1) {

			CClientDC dc(this);
			dc.SelectStockObject(NULL_BRUSH);
			dc.SetROP2(R2_NOT);

			dc.Ellipse(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

			// 이동
			boxes[current].left += point.x - startx;
			boxes[current].top += point.y - starty;
			boxes[current].right += point.x - startx;
			boxes[current].bottom += point.y - starty;

			startx = point.x;
			starty = point.y;

			dc.Ellipse(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

		}
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

}



void CMFC_proj2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	current = -1;
	for (int i = 0; i < boxes.GetCount(); i++) {
		if (boxes[i].left <= point.x && point.x <= boxes[i].right ||
			boxes[i].right <= point.x && point.x <= boxes[i].left) {

			if (boxes[i].top <= point.y && point.y <= boxes[i].bottom ||
				boxes[i].bottom <= point.y && point.y <= boxes[i].top) {

				current = i;
				mode = MR;
				break;
			}
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
