
// MFC_proj2View.cpp : CMFC_proj2View Ŭ������ ����
//

#include "stdafx.h"
#include "Line.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC_proj2.h"
#endif

#include "MFC_proj2Doc.h"
#include "MFC_proj2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mode ��ȣ
#define DL 1		//line �׸���
#define DR 2		//rect �׸���
#define DE 3		//ellipse �׸���
#define DT 4		//text �׸���
#define DP 5		//polyline �׸���
#define ML 6		//line �ű��
#define MR 7		//rect �ű��
#define ME 8		//ellipse �ű��
#define MT 9		//text �ű��
#define MP 10		//polyline �ű��

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

// CMFC_proj2View ����/�Ҹ�

CMFC_proj2View::CMFC_proj2View()
: m_ptPrev(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	current = -1;
	move = false;

}

CMFC_proj2View::~CMFC_proj2View()
{
}

BOOL CMFC_proj2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC_proj2View �׸���

void CMFC_proj2View::OnDraw(CDC* pDC)
{
	CMFC_proj2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CPaintDC dc(this);
	if (!pDoc)
		return;
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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


// CMFC_proj2View ����

#ifdef _DEBUG
void CMFC_proj2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_proj2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_proj2Doc* CMFC_proj2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_proj2Doc)));
	return (CMFC_proj2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_proj2View �޽��� ó����


void CMFC_proj2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	Line *l = new Line();
}


void CMFC_proj2View::OnBline()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
	/*
		��带 ������ �ٽ��ѹ� ���ٸ� �����־ ���µ�,
		�̶� ��带 �ٽ� 0���� �ʱ�ȭ ���ش�.
		->�ٸ� ��ư Ŭ���� �ڵ����� �������� ����
	*/
}


void CMFC_proj2View::OnBrect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
	/*
	��带 ������ �ٽ��ѹ� ���ٸ� �����־ ���µ�,
	�̶� ��带 �ٽ� 0���� �ʱ�ȭ ���ش�.
	->�ٸ� ��ư Ŭ���� �ڵ����� �������� ����
	*/
}


void CMFC_proj2View::OnBellipse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}


void CMFC_proj2View::OnBtext()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
	
}


void CMFC_proj2View::OnLButtonDown(UINT nFlags, CPoint point)
{

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (mode)
	{
		/////////////////////////////bline �κ��̴�.
	case DL:
	{
		SetCapture();
		m_ptPrev = point;
		CView::OnLButtonDown(nFlags, point);
		break;
	}
	/////////////////////////////rect �κ��̴�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

				// ũ�� ����
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

				// ũ�� ����
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

				// ũ�� ����
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

				// �̵�
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

			// �̵�
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
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	// ��ư Ȱ��ȭ ��Ȱ��ȭ�� ���⼭ ����� �ش�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
