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

	this->color_r = *(new COLORREF(RGB(0, 0, 0)));
	this->thick = 0.5;
	this->pattern = 0;
}

void ARectangle::setColor(COLORREF rgb)
{
	this->color_r = rgb;
}

COLORREF ARectangle::getColor()
{
	return this->color_r;
}

void ARectangle::setThick(double thick)
{
	this->thick = thick;
}

double ARectangle::getThick()
{
	return this->thick;
}

void ARectangle::move(Point p, int x, int y){
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

void ARectangle::draw(CDC* dc, int x, int y)
{
	setEnd_x(x);
	setEnd_y(y);
	dc->Rectangle(getStart_x(), getStart_y(), getEnd_x(), getEnd_y());
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
