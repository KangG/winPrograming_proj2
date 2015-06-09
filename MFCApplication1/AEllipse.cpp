# include "stdafx.h"
# include "AEllipse.h"

AEllipse::AEllipse()
{
	this->start_x = 0;
	this->start_y = 0;
	this->end_x = 0;
	this->end_y = 0;

	Point start_p(this->start_x, this->start_y);
	Point end_p(this->end_x, this->end_y);

	this->color_l = *(new COLORREF(RGB(0, 0, 0)));
	this->color_s = *(new COLORREF(RGB(255,255,255)));

	this->thick = 0.5;
	this->pattern = 0;
}

void AEllipse::setColor_l(COLORREF rgb)
{
	this->color_l = rgb;
}

COLORREF AEllipse::getColor_l()
{
	return this->color_l;
}

void AEllipse::setColor_s(COLORREF rgb)
{
	this->color_s = rgb;
}

COLORREF AEllipse::getColor_s()
{
	return this->color_s;
}

void AEllipse::setThick(double thick)
{
	this->thick = thick;
}

double AEllipse::getThick()
{
	return this->thick;
}

void AEllipse::move(int move_select, CPoint point, CPoint prev){
	if (move_select == 1)			//start_x, start_y�� Ŭ��
	{
		start_x = end_x;
		end_x = point.x;
		start_y = end_y;
		point.y;
	}
	if (move_select == 2)			//end_x, end_y�� Ŭ��
	{
		end_x = point.x;
		end_y = point.y;
	}
	if (move_select == 3)			//�� ������ Ŭ��
	{
		start_x += point.x - prev.x;
		start_y += point.y - prev.y;
		end_x += point.x - prev.x;
		end_y += point.y - prev.y;
	}
}

void AEllipse::draw(CDC* dc, int x, int y)
{
	setEnd_x(x);
	setEnd_y(y);

	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(color_s);
	CBrush* oldBrush = dc->SelectObject(&brush);

	dc->Ellipse(getStart_x(), getStart_y(), getEnd_x(), getEnd_y());
	dc->SelectObject(oldBrush);

	dc->Ellipse(getStart_x(), getStart_y(), getEnd_x(), getEnd_y());
	dc->SelectObject(oldPen);     // �ý��� �� ��ü�� ������
	dc->SelectObject(oldBrush);    // �ý��� �귯�� ��ü�� ������
}

void AEllipse::erase()
{

}

int AEllipse::getStart_x(){
	return this->start_x;
}
int AEllipse::getEnd_x(){
	return this->end_x;
}
void AEllipse::setStart_x(int x){
	this->start_x = x;
}
void AEllipse::setEnd_x(int x){
	this->end_x = x;
}
int AEllipse::getStart_y(){
	return this->start_y;
}
int AEllipse::getEnd_y(){
	return this->end_y;
}
void AEllipse::setStart_y(int y){
	this->start_y = y;
}
void AEllipse::setEnd_y(int y){
	this->end_y = y;
}

AEllipse::~AEllipse()
{
}

void AEllipse::DrawSelect(CDC *pDC)
{
	//�׸��� �Ӽ� ����
	pDC->SelectStockObject(NULL_BRUSH);
	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = pDC->SelectObject(&pen);

	//�׸��� �Ӽ� ����
	CBrush brush(RGB(51, 94, 168)); //�귯�� ����
	CBrush* oldBrush = pDC->SelectObject(&brush); //�귯�� ����
	pDC->SelectStockObject(NULL_PEN);

	//�� ���������� ���� �׸�
	pDC->Ellipse(start_x - 5, start_y - 5, start_x + 5, start_y + 5);
	pDC->Ellipse(end_x - 5, end_y - 5, end_x + 5, end_y + 5);
	pDC->Ellipse(start_x - 5, end_y - 5, start_x + 5, end_y + 5);
	pDC->Ellipse(end_x - 5, start_y - 5, end_x + 5, start_y + 5);


	//���� ��� �귯�� �Ӽ����� �ǵ���
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}