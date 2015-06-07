
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
#define DL 1		//line �׸���
#define DR 2		//rect �׸���
#define DE 3		//ellipse �׸���
#define DT 4		//text �׸���
#define DP 5		//polyline �׸���

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
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
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
}


void CMFCApplication1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
}


void CMFCApplication1View::OnDrect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}


void CMFCApplication1View::OnDell()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}


void CMFCApplication1View::OnDpoly()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}


void CMFCApplication1View::OnDtext()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
		//���߿� ���� ������ ������� �ٲܲ��� ���⿡ �ڵ� �߰�
	}
}
