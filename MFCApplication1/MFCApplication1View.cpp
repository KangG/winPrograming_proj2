
// MFCApplication1View.cpp : CMFCApplication1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mode ��ȣ
#define S 0
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

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ǥ�� �μ� ����Դϴ�.
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
	ON_COMMAND(ID_Select, &CMFCApplication1View::OnSelect)
	ON_COMMAND(ID_OC, &CMFCApplication1View::OnOc)
	ON_COMMAND(ID_IC, &CMFCApplication1View::OnIc)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCApplication1View ����/�Ҹ�

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View �׸���

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFCApplication1View �μ�


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CMFCApplication1View ����

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View �޽��� ó����


void CMFCApplication1View::OnPaint()
{
	CMFCApplication1Doc* pDoc = GetDocument();
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);

	for (int i = 0; i < Line_array.GetCount(); i++) {										//����� Line �׸���
		if (select_mode == DL)
		{
			Line_array[select_num].DrawSelect(&dc);
		}
		Line_array[i].draw(&dc, Line_array[i].getEnd_x(), Line_array[i].getEnd_y());
	}
	for (int i = 0; i < ARect_array.GetCount(); i++) {										//����� Rect �׸���
		if (select_mode == DR)
		{
			ARect_array[select_num].DrawSelect(&dc);
		}
		ARect_array[i].draw(&dc, ARect_array[i].getEnd_x(), ARect_array[i].getEnd_y());
	}
	for (int i = 0; i < AEll_array.GetCount(); i++) {										//����� Ellipse �׸���
		if (select_mode == DE)
		{
			AEll_array[select_num].DrawSelect(&dc);
		}
		AEll_array[i].draw(&dc, AEll_array[i].getEnd_x(), AEll_array[i].getEnd_y());
	}
	for (int i = 0; i < APolyline_array.GetCount(); i++) {
		if (select_mode == DP)
		{
			APolyline_array[select_num].DrawSelectLine(&dc);
		}
		APolyline_array[i].draw(&dc);
	}
	for (int i = 0; i < Text_array.GetCount(); i++) {
		if (select_mode == DT)
		{
		//	Text_array[select_num].DrawSelectLine(&dc);
}
		Text_array[i].makeRect(&dc,&(pDoc->m_str));
	}
}


void CMFCApplication1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (mode)
	{
	case DP:
	{
			   mode = S;
			   bpoly_new = false;
			   bpoly_status = false;
	}
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDown(nFlags, point); CClientDC dc(this);

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
			   Line_array[current_l].setEnd_x(point.x);
			   Line_array[current_l].setEnd_y(point.y);

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
			   ARect_array[current_r].setEnd_x(point.x);
			   ARect_array[current_r].setEnd_y(point.y);

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
			   AEll_array[current_e].setEnd_x(point.x);
			   AEll_array[current_e].setEnd_y(point.y);

			   move = true;
			   break;
	}
	case DT:
	{
		CMFCApplication1Doc* pDoc = GetDocument();
		Text* t = new Text();
		Text_array.Add(*t);
		pDoc->m_str.RemoveAll();
		current_t = Text_array.GetCount() - 1;
		Text_array[current_t].setStart_x(point.x);
		Text_array[current_t].setStart_y(point.y);
		Text_array[current_t].setEnd_x(point.x);
		Text_array[current_t].setEnd_y(point.y);

			   move = true;
			   break;
	}

	case DP:
	{
			   if (!bpoly_new){
				   APolyline* p = new APolyline();
				   APolyline_array.Add(*p);
				   current_p = APolyline_array.GetSize() - 1;
				   bpoly_new = true;
			   }
			   if (bpoly_status)
			   {
				   p_point.setX(point.x);
				   p_point.setY(point.y);
				   APolyline_array[current_p].next(p_point);
				   APolyline_array[current_p].draw(&dc);
				   break;
			   }
			   if (select_mode>0)
				APolyline_array[select_mode].moveAll(point.x, point.y);
	}
	case S:
	{
			  // ���õ� ��ü ã��
			  //���� +-5�ȼ����� ����
		{
			// ���õ� ���� ������ ���� Ŭ�� �� ���� �� ��ü�� ������� Ȯ����
			//���� ��̿��� �˻�
			if (Line_array.GetCount() != 0)
			{
				for (int i = 0; i < Line_array.GetCount(); i++)
				{
					double x1, x2, y1, y2;
					double g;			//greadient ����

					x1 = (double)Line_array[i].getStart_x();
					x2 = (double)Line_array[i].getEnd_x();
					y1 = (double)Line_array[i].getStart_y();
					y2 = (double)Line_array[i].getEnd_y();
					g = (y2 - y1) / (x2 - x1);
					// �ϳ��� ���� �ȿ� ������ �������� ����
					if ((((double)point.x >= x1 - 5 && (double)point.x <= x2 + 5) || ((double)point.x >= x2 - 5 && (double)point.x <= x1 + 5))
						&& (((double)point.y >= g*((double)point.x - x1) + y1 - 5) && ((double)point.y <= g*((double)point.x - x1) + y1 + 5)))
					{
						if (select_mode == DL && select_num == i)
						{
							mode = ML;
							//�������ߴ��� �Ǵ�
						}
						else
						{
							select_mode = DL;
							select_num = i;
							return;
						}
					}
				}
			}
			//��Ʈ ��̿��� �˻�
			if (ARect_array.GetCount() != 0)
			{
				int x1, x2, y1, y2;
				for (int i = 0; i < ARect_array.GetCount(); i++)
				{
					x1 = ARect_array[i].getStart_x();
					x2 = ARect_array[i].getEnd_x();
					y1 = ARect_array[i].getStart_y();
					y2 = ARect_array[i].getEnd_y();

					// �ϳ��� ���� �ȿ� ������ �������� ����
					if ((point.x >= x1 - 5 && point.x <= x2 + 5) || (point.x >= x2 - 5 && point.x <= x1 + 5)
						&& (point.y >= y1 - 5 && point.y <= y2 + 5) || (point.y >= y2 - 5 && point.y <= y1 + 5))
					{
						select_mode = DR;
						select_num = i;
						return;
					}

				}
			}
			//�̸��� ��̿��� �˻�
			if (AEll_array.GetCount() != 0)
			{
				for (int i = 0; i < AEll_array.GetCount(); i++)
				{
					int x1, x2, y1, y2;
					for (int i = 0; i < AEll_array.GetCount(); i++)
					{
						x1 = AEll_array[i].getStart_x();
						x2 = AEll_array[i].getEnd_x();
						y1 = AEll_array[i].getStart_y();
						y2 = AEll_array[i].getEnd_y();

						// �ϳ��� ���� �ȿ� ������ �������� ����
						if ((point.x >= x1 - 5 && point.x <= x2 + 5) || (point.x >= x2 - 5 && point.x <= x1 + 5)
							&& (point.y >= y1 - 5 && point.y <= y2 + 5) || (point.y >= y2 - 5 && point.y <= y1 + 5))
						{
							select_mode = DE;
							select_num = i;
							return;
						}

					}

				}
			}
			if (APolyline_array.GetCount() != 0)
			{
				for (int i = 0; i < APolyline_array.GetCount(); i++)
				{
					for (int j = 0; j < APolyline_array[i].poly_array.GetCount(); j++)
					{
						double x1, x2, y1, y2;
						double g;			//greadient ����

						x1 = APolyline_array[i].poly_array[j].getStart_x();
						x2 = APolyline_array[i].poly_array[j].getEnd_x();
						y1 = APolyline_array[i].poly_array[j].getStart_y();
						y2 = APolyline_array[i].poly_array[j].getEnd_y();
						g = (y2 - y1) / (x2 - x1);

						if (((point.x >= x1 - 5 && point.x <= x2 + 5) || (point.x >= x2 - 5 && point.x <= x1 + 5))
							&& ((point.y >= g*(point.x - x1) + y1 - 5) && (point.y <= g*(point.x - x1) + y1 + 5)))
						{
							select_mode = DP;
							select_num = i;
							return;
						}
					}
				}
			}
		}
	}
	}
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	dc.SetDCBrushColor(color);
	//// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (mode)
	{
	case S:
	{
			  Invalidate();
			  break;
	}
	case DL:
	case DR:
	case DE:
		move = false;
		break;
	case DT:
	{
		Text_array[current_t].setEnd_x(point.x);
		Text_array[current_t].setEnd_y(point.y);
		Invalidate();
			   move = false;
			   break;
	}
	case DP:
	{
	}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	switch (mode)
	{
	case S:
	{
			  break;
	}
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
			//   Invalidate();
			   break;
	}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1View::OnDline()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = DL;
	select_mode = 0;
	select_num = -1;
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
		bline_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnDrect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = DR;
	select_mode = 0;
	select_num = -1;
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
		brect_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnDell()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = DE;
	select_mode = 0;
	select_num = -1;
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
		bellipse_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnDpoly()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = DP;
	select_mode = 0;
	select_num = -1;
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
		bpoly_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnDtext()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = DT;
	select_mode = 0;
	select_num = -1;
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
		btext_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnSelect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	mode = S;
	select_mode = 0;
	select_num = -1;
}


void CMFCApplication1View::OnOc()
{
	CColorDialog dlg;
	dlg.DoModal();
	color = dlg.GetColor();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (select_mode != 0)
	{
		/*
		#define DL 1		//line ����
		#define DR 2		//rect ����
		#define DE 3		//ellipse ����
		#define DT 4		//text ����
		#define DP 5		//polyline ����
		*/
		switch (select_mode)
		{
		case DL:
		{
				   Line_array[select_num].setColor_l(color);
				   Invalidate();
				   break;
		}
		case DR:
		{
				   ARect_array[select_num].setColor_l(color);
				   Invalidate();
				   break;
		}
		case DE:
		{
				   AEll_array[select_num].setColor_l(color);
				   Invalidate();
				   break;
		}
		case DT:
		{
				   break;
		}
		case DP:
		{
				   APolyline_array[select_num].setColor_l(color);
				   Invalidate();
				   break;
		}
		}
	}
}


void CMFCApplication1View::OnIc()
{
	CColorDialog dlg;
	dlg.DoModal();
	color = dlg.GetColor();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (select_mode != 0)
	{
		/*
		#define DL 1		//line ����
		#define DR 2		//rect ����
		#define DE 3		//ellipse ����
		#define DT 4		//text ����
		#define DP 5		//polyline ����
		*/
		switch (select_mode)
		{
		case DL:
		case DP:
		case DT:
		{
			break;
		}
		case DR:
		{
			ARect_array[select_num].setColor_s(color);
			Invalidate();
			break;
		}
		case DE:
		{
			AEll_array[select_num].setColor_s(color);
			Invalidate();
			break;
		}
		}
	}
}


void CMFCApplication1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMFCApplication1Doc *pDoc = GetDocument();

	if (nChar == _T('\b')){
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
		}
	else{
		pDoc->m_str.Add(nChar);
	}

	pDoc->SetModifiedFlag();

	pDoc->UpdateAllViews(NULL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
