
// MFC_proj2View.cpp : CMFC_proj2View Ŭ������ ����
//

#include "stdafx.h"
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

// CMFC_proj2View ����/�Ҹ�

CMFC_proj2View::CMFC_proj2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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

	dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);

	for (int i = 0; i < Line_array.GetCount(); i++) {										//����� Line �׸���
		Line_array[i].draw(&dc, Line_array[i].getEnd_x(), Line_array[i].getEnd_y());
	}
	for (int i = 0; i < ARect_array.GetCount(); i++) {										//����� Rect �׸���
		ARect_array[i].draw(&dc, ARect_array[i].getEnd_x(), ARect_array[i].getEnd_y());
	}
	for (int i = 0; i < AEll_array.GetCount(); i++) {										//����� Ellipse �׸���
		AEll_array[i].draw(&dc, AEll_array[i].getEnd_x(), AEll_array[i].getEnd_y());
	}
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

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
		bpoly_status = false;
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
		bpoly_status = false;
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
		bpoly_status = false;
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
		bpoly_status = false;
	}
	else
	{
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}

}


void CMFC_proj2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

	//// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	else if (mode == DP)
	{
		pCmdUI->Enable(bpoly_status);
	}
}


void CMFC_proj2View::OnBpolyline()
{
	mode = DP;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}


//void CMFC_proj2View::OnUpdateBpolyline(CCmdUI *pCmdUI)
//{
//	pCmdUI->Enable(bpoly_status);
//	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
//}
