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
void Line::setColor_s(COLORREF rgb){
	this->color_s = rgb;
}
COLORREF Line::getColor_s(){
	return this->color_s;
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

void Line::move(Point p, int x, int y){
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

void Line::draw(CDC* dc, int x, int y){

	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = dc->SelectObject(&pen);

	dc->MoveTo(start_x, start_y);
	end_x = x;
	end_y = y;
	dc->LineTo(x, y);

	dc->SelectObject(oldPen);     // 시스템 펜 객체를 돌려줌
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