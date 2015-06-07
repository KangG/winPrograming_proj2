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

void AEllipse::move(Point p, int x, int y){
	int buf_x, buf_y;
	if ((p.getX() == this->getStart_x()) && (p.getY() == this->getStart_y())){		// start만 옮기는 경우
		buf_x = this->getStart_x();
		buf_y = this->getStart_y();
		this->setStart_x(buf_x + x);
		this->setStart_y(buf_y + y);

	}
	else if ((p.getX() == this->getEnd_x()) && (p.getY() == this->getEnd_y())){		//end만 옮기는 경우
		buf_x = this->getEnd_x();
		buf_y = this->getEnd_y();
		this->setEnd_x(buf_x + x);
		this->setEnd_y(buf_y + y);
	}

	else{				//전체 옮기는 경우
		buf_x = this->getStart_x();
		buf_y = this->getStart_y();
		this->setStart_x(buf_x + x);
		this->setStart_y(buf_y + y);

		buf_x = this->getEnd_x();
		buf_y = this->getEnd_y();
		this->setEnd_x(buf_x + x);
		this->setEnd_y(buf_y + y);
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
	dc->SelectObject(oldPen);     // 시스템 펜 객체를 돌려줌
	dc->SelectObject(oldBrush);    // 시스템 브러시 객체를 돌려줌
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
