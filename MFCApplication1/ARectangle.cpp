#include "stdafx.h"
#include "ARectangle.h"

ARectangle::ARectangle()
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

void ARectangle::setColor_l(COLORREF rgb)
{
	this->color_l = rgb;
}

COLORREF ARectangle::getColor_l()
{
	return this->color_l;
}

void ARectangle::setColor_s(COLORREF rgb)
{
	this->color_s = rgb;
}

COLORREF ARectangle::getColor_s()
{
	return this->color_s;
}

void ARectangle::setThick(double thick)
{
	this->thick = thick;
}

double ARectangle::getThick()
{
	return this->thick;
}

void ARectangle::move(int move_select, CPoint point, CPoint prev){
	if (move_select >=1 || move_select <=4 )			//start_x, start_y를 클릭
	{
		end_x = point.x;
		end_y;  point.y;
	}
	else if (move_select >= 5 || move_select <= 8)			//end_x, end_y를 클릭
	{
		end_x = point.x;
		end_y = point.y;
	}
	else			//사각형 안의 점 클릭
	{
		start_x += point.x - prev.x;
		start_y += point.y - prev.y;
		end_x += point.x - prev.x;
		end_y += point.y - prev.y;

		prev.x = point.x;
		prev.y = point.y;
	}
}

void ARectangle::draw(CDC* dc, int x, int y)
{
	setEnd_x(x);
	setEnd_y(y);

	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(color_s);
	CBrush* oldBrush = dc->SelectObject(&brush);

	dc->Rectangle(getStart_x(), getStart_y(), getEnd_x(), getEnd_y());
	dc->SelectObject(oldBrush);

	dc->Rectangle(getStart_x(), getStart_y(), getEnd_x(), getEnd_y());
	dc->SelectObject(oldPen);     // 시스템 펜 객체를 돌려줌
	dc->SelectObject(oldBrush);    // 시스템 브러시 객체를 돌려줌
}

void ARectangle::erase()
{

}

int ARectangle::getStart_x(){
	return this->start_x;
}
int ARectangle::getEnd_x(){
	return this->end_x;
}
void ARectangle::setStart_x(int x){
	this->start_x = x;
}
void ARectangle::setEnd_x(int x){
	this->end_x = x;
}
int ARectangle::getStart_y(){
	return this->start_y;
}
int ARectangle::getEnd_y(){
	return this->end_y;
}
void ARectangle::setStart_y(int y){
	this->start_y = y;
}
void ARectangle::setEnd_y(int y){
	this->end_y = y;
}

ARectangle::~ARectangle()
{
}

void ARectangle::DrawSelect(CDC *pDC)
{
	//그리기 속성 설정
	pDC->SelectStockObject(NULL_BRUSH);
	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = pDC->SelectObject(&pen);

	//그리기 속성 설정
	CBrush brush(RGB(51, 94, 168)); //브러쉬 생성
	CBrush* oldBrush = pDC->SelectObject(&brush); //브러쉬 지정
	pDC->SelectStockObject(NULL_PEN);

	//각 꼭지점마다 점을 그림
	pDC->Ellipse(start_x - 5, start_y - 5, start_x + 5, start_y + 5);
	pDC->Ellipse(end_x - 5, end_y - 5, end_x + 5, end_y + 5);
	pDC->Ellipse(start_x - 5, end_y - 5, start_x + 5, end_y + 5);
	pDC->Ellipse(end_x - 5, start_y - 5, end_x + 5, start_y + 5);


	//이전 펜과 브러쉬 속성으로 되돌림
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}