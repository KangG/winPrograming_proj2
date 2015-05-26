#include "stdafx.h"
#include "Rectangle.h"


Rectangle::Rectangle()
{
	this->start_x = 0;
	this->start_y = 0;
	this->end_x = 0;
	this->end_y = 0;

	this->start_p = new Point(this->start_x, this->start_y);
	this->end_p = new Point(this->end_x, this->end_y);

	this->color_r = new COLORREF(RGB(0, 0, 0));
	this->thick = 0.5;
	this->pattern = 0;
}

void Rectangle::setColor(COLORREF rgb)
{
	this->color_r = rgb;
}

COLORREF Rectangle::getColor()
{
	return this->color_r;
}

void Rectangle::setThick(double thick)
{
	this->thick = thick;
}

double Rectangle::getThick()
{
	return this->thick;
}

void Rectangle::move(Point p, int x, int y){
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

void Rectangle::draw()
{

}

void Rectangle::erase()
{

}

int Rectangle::getStart_x(){
	return this->start_x;
}
int Rectangle::getEnd_x(){
	return this->end_x;
}
void Rectangle::setStart_x(int x){
	this->start_x = x;
}
void Rectangle::setEnd_x(int x){
	this->end_x = x;
}
int Rectangle::getStart_y(){
	return this->start_y;
}
int Rectangle::getEnd_y(){
	return this->end_y;
}
void Rectangle::setStart_y(int y){
	this->start_y = y;
}
void Rectangle::setEnd_y(int y){
	this->end_y = y;
}
Rectangle::~Rectangle()
{
}
