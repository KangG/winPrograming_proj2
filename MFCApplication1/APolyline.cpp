#include "stdafx.h"
#include "APolyline.h"


APolyline::APolyline()
{

	//여기서 temp의 역할은
	//폴리라인의 특성상 라인의 끝점을 찍어냄으로써
	//생성하는 것인데 점을 찍엇을때 앞의 라인의 끝점으로 
	//설정해주고, 다시 뒷라인의 시작점으로 설정해주는 작업에서
	//쓰려고 temp를 만들었다.

	this->color_p = *(new COLORREF(RGB(0, 0, 0)));
	this->thick = 0.5;
	this->pattern = 0;
	this->index = 0;
}

APolyline::APolyline(COLORREF color)
{
	color_p = color;
}
APolyline::APolyline(const APolyline &p)
{
	*this = p;
}

APolyline& APolyline::operator=(const APolyline &p)
{
	return *this;
}

void APolyline::setColor_l(COLORREF rgb)
{
	this->color_p = rgb;
}

COLORREF APolyline::getColor()
{
	return this->color_p;
}

void APolyline::setThick(double thick)
{
	this->thick = thick;
}
double APolyline::getThick()
{
	return this->thick;
}

void APolyline::setPattern(int pattern)
{
	this->pattern = pattern;
}
int APolyline::getPattern()
{
	return this->pattern;
}

void APolyline::next(Point point)
{
	if (this->index == 0)
	{
		temp = Line(point.getX(), point.getY(), point.getX(), point.getY());
		poly_array.Add(temp);
		index = poly_array.GetSize();
	}
	else
	{
		poly_array[index - 1].setEnd_x(point.getX());
		poly_array[index - 1].setEnd_y(point.getY());
		temp.setStart_x(point.getX());
		temp.setStart_y(point.getY());
		poly_array.Add(temp);
		index = poly_array.GetSize();
	}
}

void APolyline::moveAll()
{

}

void APolyline::eraseAt(int index, Point point)
{

}

void APolyline::eraseAll()
{
	this->~APolyline();
}

APolyline::~APolyline()
{

}

int APolyline::get_index()
{
	return this->index;
}

void APolyline::draw(CDC* dc)
{
	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_p);
	CPen* oldPen = dc->SelectObject(&pen);

	for (int i = 0; i < poly_array.GetSize()-1; i++){
		dc->MoveTo(poly_array[i].getStart_x(),
			poly_array[i].getStart_y());
		dc->LineTo(poly_array[i].getEnd_x(),
			poly_array[i].getEnd_y());
	}
}