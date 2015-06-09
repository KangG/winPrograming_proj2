#include "stdafx.h"
#include "Line.h"

Line::Line(){
}

Line::Line(int a, int b, int c, int d)
{
	start_x = a;
	start_y = b;
	end_x = c;
	end_y = d;
}

void Line::setColor_l(COLORREF rgb){
	this->color_l = rgb;
}
COLORREF Line::getColor_l(){
	return this->color_l;
}

void Line::setThick(double thick){
	this->thick = thick;
}
double Line::getThick(){
	return this->thick;
}

void Line::setPattern(int pattern){
	this->pattern = pattern;
}
int Line::getPattern(){
	return this->pattern;
}

void Line::move(int move_select, CPoint point, CPoint prev){
	if (move_select == 1 || move_select == 2)			//start_x, start_y�� Ŭ��
	{								//end_x, end_y�� Ŭ��
		end_x = point.x;
		end_y = point.y;
	}
	if (move_select == 3)			//�� ������ Ŭ��
	{
		start_x += point.x - prev.x;
		start_y += point.y - prev.y;
		end_x += point.x - prev.x;
		end_y += point.y - prev.y;

		prev.x = point.x;
		prev.y = point.y;
	}
}

void Line::draw(CDC* dc, int x, int y){

	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = dc->SelectObject(&pen);

	dc->MoveTo(start_x, start_y);
	end_x = x;
	end_y = y;
	dc->LineTo(x, y);

	dc->SelectObject(oldPen);     // �ý��� �� ��ü�� ������
}

void Line::draw_start(CDC* dc, int x, int y){

	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = dc->SelectObject(&pen);

	dc->MoveTo(x, y);
	start_x = x;
	start_y = y;
	dc->LineTo(end_x, end_y);

	dc->SelectObject(oldPen);
}


void Line::erase(){
	Line::~Line();
}


int Line::getStart_x(){
	return this->start_x;
}
int Line::getEnd_x(){
	return this->end_x;
}
void Line::setStart_x(int x){
	this->start_x = x;
}
void Line::setEnd_x(int x){
	this->end_x = x;
}
int Line::getStart_y(){
	return this->start_y;
}
int Line::getEnd_y(){
	return this->end_y;
}
void Line::setStart_y(int y){
	this->start_y = y;
}
void Line::setEnd_y(int y){
	this->end_y = y;
}

Line::~Line(){

}

void Line::DrawSelect(CDC *pDC)
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
	

	//���� ��� �귯�� �Ӽ����� �ǵ���
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}