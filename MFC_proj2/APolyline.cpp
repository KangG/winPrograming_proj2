#include "stdafx.h"
#include "APolyline.h"


APolyline::APolyline()
{

	//���⼭ temp�� ������
	//���������� Ư���� ������ ������ �����ν�
	//�����ϴ� ���ε� ���� ������� ���� ������ �������� 
	//�������ְ�, �ٽ� �޶����� ���������� �������ִ� �۾�����
	//������ temp�� �������.

	this->color_p = *(new COLORREF(RGB(0, 0, 0)));
	this->thick = 0.5;
	this->pattern = 0;
	this->index = 0;
}

void APolyline::setColor(COLORREF rgb)
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
		this->temp.setStart_x(point.getX());
		this->temp.setStart_y(point.getY());
		this->poly_array.Add(temp);
		this->index = this->poly_array.GetSize();
	}
	else
	{
		this->poly_array[index-1].setEnd_x(point.getX());
		this->poly_array[index-1].setEnd_y(point.getY());
		this->temp.setStart_x(point.getX());
		this->temp.setStart_y(point.getY());
		this->temp.setEnd_x(point.getX());
		this->temp.setEnd_y(point.getY());
		this->poly_array.Add(temp);
		this->index = this->poly_array.GetSize();
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
	for (int i=0; i < this->poly_array.GetSize(); i++)
		this->poly_array[i].draw(dc, this->poly_array[i].getEnd_x(), this->poly_array[i].getEnd_y());
}

APolyline APolyline::copy_this(APolyline poly)
{
	APolyline temp;

	for (int i = 0; i < poly.poly_array.GetSize(); i++)
	{

		temp.color_p = poly.color_p;
		temp.thick = poly.thick;
		temp.pattern = poly.pattern;
		temp.index = poly.index;
		temp.poly_array[i].setStart_x(poly.poly_array[i].getStart_x());
		temp.poly_array[i].setStart_y(poly.poly_array[i].getStart_y());
		temp.poly_array[i].setEnd_x(poly.poly_array[i].getEnd_x());
		temp.poly_array[i].setEnd_y(poly.poly_array[i].getEnd_y());
	}

	return temp;
}