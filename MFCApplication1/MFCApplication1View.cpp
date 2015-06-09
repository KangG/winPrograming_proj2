
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
#include "ThickDialog.h"
#include "PatternDialog.h"

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
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Delete, &CMFCApplication1View::OnDelete)
	ON_COMMAND(ID_font, &CMFCApplication1View::OnFont)
	ON_COMMAND(ID_pattern, &CMFCApplication1View::OnPattern)
	ON_COMMAND(ID_Thick, &CMFCApplication1View::OnThick)
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

	//Thick ���̾�α� ����
	l_size = 1;
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

void CMFCApplication1View::OnDraw(CDC* pDC)
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

	for (int i = 0; i < pDoc->Line_array.GetSize(); i++) {										//����� Line �׸���
		if (select_mode == DL)
		{
			pDoc->Line_array[select_num].DrawSelect(&dc);
		}
		pDoc->Line_array[i].draw(&dc, pDoc->Line_array[i].getEnd_x(), pDoc->Line_array[i].getEnd_y());
	}
	for (int i = 0; i < ARect_array.GetSize(); i++) {										//����� Rect �׸���
		if (select_mode == DR)
		{
			ARect_array[select_num].DrawSelect(&dc);
		}
		ARect_array[i].draw(&dc, ARect_array[i].getEnd_x(), ARect_array[i].getEnd_y());
	}
	for (int i = 0; i < AEll_array.GetSize(); i++) {										//����� Ellipse �׸���
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
	for (int i = 0; i < pDoc->Text_array.GetSize(); i++) {
		if (select_mode == DT)
		{
			pDoc->Text_array[select_num].DrawSelect(&dc);
}
		pDoc->Text_array[i].draw(&dc, pDoc->Text_array[i].getEnd_x(), pDoc->Text_array[i].getEnd_y());
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

	CMFCApplication1Doc* pDoc = GetDocument();
	pDoc->temp = point;
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (mode)
	{
	case DL:
	{
			   Line* l = new Line();
			   pDoc->Line_array.Add(*l);
			   current_l = pDoc->Line_array.GetCount() - 1;

			   pDoc->Line_array[current_l].setStart_x(point.x);
			   pDoc->Line_array[current_l].setStart_y(point.y);
			   pDoc->Line_array[current_l].setEnd_x(point.x);
			   pDoc->Line_array[current_l].setEnd_y(point.y);

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
		Text* t = new Text();
		pDoc->Text_array.Add(*t);
		pDoc->m_str.RemoveAll();
		current_t = pDoc->Text_array.GetCount() - 1;
		pDoc->Text_array[current_t].setStart_x(point.x);
		pDoc->Text_array[current_t].setStart_y(point.y);
		pDoc->Text_array[current_t].setEnd_x(point.x);
		pDoc->Text_array[current_t].setEnd_y(point.y);

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
			   if (bpoly_new && bpoly_status)
			   {
				   p_point.setX(point.x);
				   p_point.setY(point.y);
				   APolyline_array[current_p].next(p_point);
				   APolyline_array[current_p].draw(&dc);
				   move = true;
				   break;
			   }
	}
	case S:
	{
			  // ���õ� ��ü ã��
			  //���� +-5�ȼ����� ����
		{
			// ���õ� ���� ������ ���� Ŭ�� �� ���� �� ��ü�� ������� Ȯ����
			//���� ��̿��� �˻�
			if (pDoc->Line_array.GetCount() != 0)
			{
				for (int i = 0; i < pDoc->Line_array.GetCount(); i++)
				{
					double x1, x2, y1, y2;
					double g;			//greadient ����

					x1 = (double)pDoc->Line_array[i].getStart_x();
					x2 = (double)pDoc->Line_array[i].getEnd_x();
					y1 = (double)pDoc->Line_array[i].getStart_y();
					y2 = (double)pDoc->Line_array[i].getEnd_y();
					g = (y2 - y1) / (x2 - x1);
					// �ϳ��� ���� �ȿ� ������ �������� ����
					if ((((double)point.x >= x1 - 5 && (double)point.x <= x2 + 5) || ((double)point.x >= x2 - 5 && (double)point.x <= x1 + 5))
						&& (((double)point.y >= g*((double)point.x - x1) + y1 - 5) && ((double)point.y <= g*((double)point.x - x1) + y1 + 5)))
					{
						if (select_mode == DL && select_num == i)
						{
							mode = ML;
							move = true;
							prev.x = point.x;
							prev.y = point.y;
							//�������ߴ��� �Ǵ�
							if (((point.x >= x1 - 5) && (point.x <= x1 + 5)) && ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 1;		//start�� �ű��
								pDoc->Line_array[i].setStart_x(x2);
								pDoc->Line_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5)) && ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 2;		//end�� �ű��
							}
							else
							{
								move_select = 3;		//�� ��ü �ű��
							}
							return;
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
					if ((point.x >= x1 - 5 && point.x <= x2 + 5)
						&& (point.y >= y1 - 5 && point.y <= y2 + 5))
					{
						if (select_mode == DR && select_num == i)
						{
							mode = MR;
							move = true;
							prev.x = point.x;
							prev.y = point.y;
							//�������ߴ��� �Ǵ�
							//	1 ----- 5 ----- 2
							//	l				l
							//	8		9		6
							//	l				l
							//	4 ----- 7 ----- 3
							if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 1;		//1���� �ű��
								ARect_array[i].setStart_x(x2);
								ARect_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 2;		//2���� �ű��
								ARect_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 3;		//3���� �ű��
							}
							else if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 4;		//4���� �ű��
								ARect_array[i].setStart_x(x2);
							}

							else
							{
								move_select = 9;		//�� ��ü �ű��
							}
							return;
						}
						else
						{
						select_mode = DR;
						select_num = i;
						return;
					}
					}

				}
			}
			//�̸��� ��̿��� �˻�
			if (AEll_array.GetCount() != 0)
			{
					int x1, x2, y1, y2;
					for (int i = 0; i < AEll_array.GetCount(); i++)
					{
						x1 = AEll_array[i].getStart_x();
						x2 = AEll_array[i].getEnd_x();
						y1 = AEll_array[i].getStart_y();
						y2 = AEll_array[i].getEnd_y();

						// �ϳ��� ���� �ȿ� ������ �������� ����
						if ((point.x >= x1 - 5 && point.x <= x2 + 5)
							&& (point.y >= y1 - 5 && point.y <= y2 + 5) )
						{
							if (select_mode == DE && select_num == i)
							{
								mode = ME;
							move = true;
							prev.x = point.x;
							prev.y = point.y;
								//�������ߴ��� �Ǵ�
							//	1 ----- 5 ----- 2
							//	��				��
							//	8		9		6
							//	��				��
							//	4 ----- 7 ----- 3
							//���ű��
							if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 1;		//1���� �ű��
								AEll_array[i].setStart_x(x2);
								AEll_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 2;		//2���� �ű��
								AEll_array[i].setStart_y(y2);
								}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 3;		//3���� �ű��
							}
							else if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 4;		//4���� �ű��
								AEll_array[i].setStart_x(x2);
								}

							//���ű��


							//��ü �ű��
							else
							{
								move_select = 9;		//�� ��ü �ű��
							}
							return;
							}
							else
							{
								select_mode = DE;
								select_num = i;
								return;
							}
						}
					}
				}

			//�������� ��̿��� �˻�
			if (APolyline_array.GetCount() != 0)
			{
				for (int i = 0; i < APolyline_array.GetCount(); i++)
				{
					
					for (int j = 0; j < APolyline_array[i].poly_array.GetCount(); j++)
					{
						int x3, y3;

						x3 = APolyline_array[i].point_array[j].getX();
						y3 = APolyline_array[i].point_array[j].getY();

						if ((point.x >= x3 - 5 && point.x <= x3 + 5) && (point.y >= y3 - 5 && point.y <= y3 + 5))
						{
							mode = MP;
							ispoint = true;			//���̶�� ���� ǥ������.
							select_point = j;		//���� ������ ǥ������.
							move = true;
							select_mode = DP;
							
							Invalidate();
							return;
						}
					}



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
							prev.x = point.x;
							prev.y = point.y;
							mode = MP;
							isall = true;
							select_mode = DP;
							select_num = i;				//���õ� ���������� ����äũ��
							move_select = 3;			//��ü�̵��� ����̱⶧����
							Invalidate();
							return;
						}
					}
				}
			}

			//�ؽ�Ʈ ��̿��� �˻�
			if (pDoc->Text_array.GetSize() != 0)
			{
				int x1, x2, y1, y2;
				for (int i = 0; i < pDoc->Text_array.GetCount(); i++)
				{
					x1 = pDoc->Text_array[i].getStart_x();
					x2 = pDoc->Text_array[i].getEnd_x();
					y1 = pDoc->Text_array[i].getStart_y();
					y2 = pDoc->Text_array[i].getEnd_y();

					// �ϳ��� ���� �ȿ� ������ �������� ����
					if ((point.x >= x1 - 5 && point.x <= x2 + 5)
						&& (point.y >= y1 - 5 && point.y <= y2 + 5))
					{
						if (select_mode == DT && select_num == i)
						{
							mode = MT;
							move = true;
							prev.x = point.x;
							prev.y = point.y;
							//�������ߴ��� �Ǵ�
							//	1 ----- 5 ----- 2
							//	l				l
							//	8		9		6
							//	l				l
							//	4 ----- 7 ----- 3
							if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 1;		//1���� �ű��
								pDoc->Text_array[i].setStart_x(x2);
								pDoc->Text_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y1 - 5) && (point.y <= y1 + 5)))
							{
								move_select = 2;		//2���� �ű��
								pDoc->Text_array[i].setStart_y(y2);
							}
							else if (((point.x >= x2 - 5) && (point.x <= x2 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 3;		//3���� �ű��
							}
							else if (((point.x >= x1 - 5) && (point.x <= x1 + 5))
								&& ((point.y >= y2 - 5) && (point.y <= y2 + 5)))
							{
								move_select = 4;		//4���� �ű��
								pDoc->Text_array[i].setStart_x(x2);
							}

							else
							{
								move_select = 9;		//�� ��ü �ű��
							}
							return;
						}
						else
						{
							select_mode = DT;
							select_num = i;
							return;
						}
					}

				}
			}
		}
		select_mode = 0;
		select_num = -1;
		ispoint = false;
		isall = false;
	}
	}
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CMFCApplication1Doc* pDoc = GetDocument();
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
	case DP:
	{
			   //mode = S;
		move = false;
		break;
	}
	case DT:
	{
		pDoc->Text_array[current_t].setEnd_x(point.x);
		pDoc->Text_array[current_t].setEnd_y(point.y);
		Invalidate();
			   move = false;
			   break;
	}
	case ML:
	case MR:
	case ME:
	case MT:
	{
		mode = S;
		move = false;
		break;
	}
	case MP:
	{
		if (ispoint)
		{
			APolyline_array[select_num].point_array[select_point].setX(point.x);
			APolyline_array[select_num].point_array[select_point].setY(point.y);
			select_point = -1;
			ispoint = false;
			mode = S;

			Invalidate();
			break;
		}
		else
		{
			CPoint temp = prev;
			for (int i = 0; i < APolyline_array[select_num].poly_array.GetSize(); i++)
			{
				APolyline_array[select_num].move(point.x - prev.x, point.y - prev.y, i);
				APolyline_array[select_num].poly_array[i].move(move_select, point, prev);
				TRACE("%d	%d		%d\n", APolyline_array[select_num].point_array[i].getX(), APolyline_array[select_num].point_array[i].getY(), i);
				prev = temp;

	}

			isall = false;
			Invalidate();
		}
		mode = S;
		break;

	}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CMFCApplication1Doc* pDoc = GetDocument();

	if (move == true){
		switch (mode)
		{
		case S:
		{
				  Invalidate();
				  return;

		}
		case DL:
		{
				   pDoc->Line_array[current_l].draw(&dc, point.x, point.y);
				   Invalidate();
				   break;
		}
		case DR:
		{
				   ARect_array[current_r].draw(&dc, point.x, point.y);
				   Invalidate();
				   break;
		}
		case DE:
		{
				   AEll_array[current_e].draw(&dc, point.x, point.y);
				   Invalidate();
				   break;
		}
		case DP:
			break;
		case DT:
		{
			pDoc->Text_array[current_t].draw(&dc, point.x, point.y);
			Invalidate(); 
			break;
		}
		case ML:
		{
				   pDoc->Line_array[select_num].move(move_select, point, prev);
				   if (move_select == 3)
				   {
					   pDoc->Line_array[select_num].draw(&dc, pDoc->Line_array[select_num].getEnd_x(), pDoc->Line_array[select_num].getEnd_y());
					   Invalidate();
					   break;
				   }
				   else
				   {
					   pDoc->Line_array[select_num].draw(&dc, point.x, point.y);
					   Invalidate();
					   break;
				   }

		}
		case MR:
		{
				   ARect_array[select_num].move(move_select, point, prev);
				   if (move_select == 9)
				   {
					   ARect_array[select_num].draw(&dc, ARect_array[select_num].getEnd_x(), ARect_array[select_num].getEnd_y());
					   Invalidate();
					   break;
				   }
				   else
				   {
					   ARect_array[select_num].draw(&dc, point.x, point.y);
					   Invalidate();
					   break;
				   }

		}
		case ME:
		{
				   AEll_array[select_num].move(move_select, point, prev);
				   if (move_select == 9)
				   {
					   AEll_array[select_num].draw(&dc, AEll_array[select_num].getEnd_x(), AEll_array[select_num].getEnd_y());
					   Invalidate();
					   break;
				   }
				   else
				   {
					   AEll_array[select_num].draw(&dc, point.x, point.y);
					   Invalidate();
					   break;
				   }
		}
		case MP:
		{
				   if (ispoint)
				   {
					   if (select_point == 0)
					   {
						   APolyline_array[select_num].poly_array[select_point].draw_start(&dc, point.x, point.y);
					   }
					   if (select_point > 0)
					   {
						   if (select_point == APolyline_array[select_num].point_array.GetSize() - 1)
						   {
							   APolyline_array[select_num].poly_array[select_point - 1].draw(&dc, point.x, point.y);
							   Invalidate();
							   return;
						   }
						   APolyline_array[select_num].poly_array[select_point - 1].draw(&dc, point.x, point.y);
						   APolyline_array[select_num].poly_array[select_point].draw_start(&dc, point.x, point.y);
					   }

					   Invalidate();
					   return;
				   }
				   else
				   {

					   //TRACE("%d\n", APolyline_array[select_num].poly_array.GetSize());
					   for (int i = 0; i < APolyline_array[select_num].poly_array.GetSize() - 1; i++)
					   {
						   TRACE("%d\n", i);


					   }
					   return;
				   }
			}

		case MT:{
			pDoc->Text_array[select_num].move(move_select, point, prev);
			if (move_select == 9)
			{
				pDoc->Text_array[select_num].draw(&dc, pDoc->Text_array[select_num].getEnd_x(), pDoc->Text_array[select_num].getEnd_y());
				Invalidate();
				break;
			}
			else
			{
				pDoc->Text_array[select_num].draw(&dc, point.x, point.y);
				Invalidate();
				break;
			}
		}

		}
		CView::OnMouseMove(nFlags, point);
	}
}

void CMFCApplication1View::OnDline()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Invalidate();
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
	Invalidate();
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
	Invalidate();
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
	Invalidate();
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
		mode = S;
		bpoly_new = false;
		bpoly_status = false;
		mode = 100;
	}
}


void CMFCApplication1View::OnDtext()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Invalidate();
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
	CMFCApplication1Doc* pDoc = GetDocument();
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
			pDoc->Line_array[select_num].setColor_l(color);
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
	if (mode == DT || select_mode==DT){
		if (nChar == _T('\b')){
			if (select_mode==DT){
				if (pDoc->Text_array[select_num].m_str.GetSize() > 0)
					pDoc->Text_array[select_num].m_str.RemoveAt(pDoc->Text_array[select_num].m_str.GetSize() - 1);
				}
			if(mode==DT){
				if (pDoc->Text_array[current_t].m_str.GetSize() > 0)
					pDoc->Text_array[current_t].m_str.RemoveAt(pDoc->Text_array[current_t].m_str.GetSize() - 1);
			}
			}
		else{
			if (select_mode == DT){
				pDoc->Text_array[select_num].m_str.Add(nChar);
			}
			if (mode == DT){
			pDoc->Text_array[current_t].m_str.Add(nChar);
		}
	}
	}
	pDoc->SetModifiedFlag();

	pDoc->UpdateAllViews(NULL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
	switch (mode)
	{
	case DP:
	{

	}
	case MP:
	{
			   if (ispoint)
			   {
				   select_point = -1;
				   ispoint = false;
				   mode = S;
				   break;
			   }
	}
	}
}

void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	switch (mode)
	{
	case S:
	{
			  if (APolyline_array.GetCount() != 0)
			  {
				  for (int i = 0; i < APolyline_array.GetCount(); i++)
				  {

					  for (int j = 0; j < APolyline_array[i].poly_array.GetCount(); j++)
					  {
						  int x3, y3;

						  x3 = APolyline_array[i].point_array[j].getX();
						  y3 = APolyline_array[i].point_array[j].getY();

						  if ((point.x >= x3 - 5 && point.x <= x3 + 5) && (point.y >= y3 - 5 && point.y <= y3 + 5))
						  {
							  TRACE("checking111111111\n");
							  mode = S;
							  ispoint = true;			//���̶�� ���� ǥ������.
							  select_point = j;		//���� ������ ǥ������.
							  move = true;
							  select_mode = DP;

	
							  return;
						  }
					  }

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
							  mode = S;
							  isall = true;
							  select_mode = DP;
							  select_num = i;				//���õ� ���������� ����äũ��
							  //move_select = 3;			//��ü�̵��� ����̱⶧����
							  return;
						  }
					  }
				  }
			  }
	}
	}
	CView::OnRButtonDown(nFlags, point);
}


void CMFCApplication1View::OnDelete()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	int befer_num;
	CMFCApplication1Doc* pDoc = GetDocument();
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (mode == S){
		switch (select_mode){
		case DL:
			befer_num = pDoc->Line_array.GetSize();
			pDoc->Line_array.RemoveAt(select_num);
			select_mode = 100;
			Invalidate();
			break;

		case DR:
			befer_num = ARect_array.GetSize();
			ARect_array.RemoveAt(select_num);
			select_mode = 100;
			Invalidate();
			break;
		case DE:
			befer_num = AEll_array.GetSize();
			AEll_array.RemoveAt(select_num);
			select_mode = 100;
			Invalidate();
			break;
		case DT:
			befer_num = pDoc->Text_array.GetSize();
			pDoc->Text_array.RemoveAt(select_num);
			select_mode = 100;
			Invalidate();
			break;
		case DP:
			if (ispoint)
			{
				APolyline_array[select_num].eraseAt(select_point);
				select_mode = 100;
				ispoint = false;
				Invalidate();
				return;
			}
			TRACE("%d", select_num);
			befer_num = APolyline_array.GetSize();
			APolyline_array.RemoveAt(select_num);
			select_mode = 100;
			Invalidate();
			break;
		}
	}
}


void CMFCApplication1View::OnFont()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CFontDialog cdlg;
	cdlg.DoModal();

}


void CMFCApplication1View::OnPattern()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCApplication1Doc* pDoc = GetDocument();
	PatternDialog dlg;
	dlg.DoModal();
	/*if (select_mode == DL)
		dlg.l_size = pDoc->Line_array[select_num].getPattern();
	else if (select_mode == DR)
		ARect_array[select_num].getPattern();
	else if (select_mode == DE)
		AEll_array[select_num].getPattern();
	else if (select_mode == DT)
		pDoc->Text_array[select_num].getPattern();
	else if (select_mode == DP)
		APolyline_array[select_num].getPattern();
		*/

}


void CMFCApplication1View::OnThick()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCApplication1Doc* pDoc = GetDocument();
	CThickDialog dlg;

	//������ ��ü�� ���� �����⸦ ������
	if (select_mode == DL)
		dlg.l_size = pDoc->Line_array[select_num].getThick();
	else if (select_mode == DR)
		ARect_array[select_num].getThick();
	else if (select_mode == DE)
		AEll_array[select_num].getThick();
	else if (select_mode == DT)
		pDoc->Text_array[select_num].getThick();
	else if (select_mode == DP)
		APolyline_array[select_num].getThick();
	
	int result = dlg.DoModal();
	if (result == IDOK)
	{
		l_size = dlg.l_size;
		//������ ��ü�� ������ ������ �����ͼ� m_str���� �ٲ��ش�.
		if (select_mode == DL)
		{
			pDoc->Line_array[select_num].setThick(l_size);
		}
		else if (select_mode == DR)
		{
			ARect_array[select_num].setThick(l_size);
		}
		else if (select_mode == DE)
		{
			AEll_array[select_num].setThick(l_size);
		}
		else if (select_mode == DT)
		{
			pDoc->Text_array[select_num].setThick(l_size);
		}
		else if (select_mode == DP)
		{
			APolyline_array[select_num].setThick(l_size);
		}
		Invalidate();
	}
}
