#include "stdafx.h"
#include "Polyline.h"


Polyline::Polyline()
{
	this->start_x = 0;
	this->start_y = 0;
	this->temp.setStart_x(this->start_x);
	this->temp.setStart_y(this->start_y);
	this->poly_array.Add(this->temp);
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

void Polyline::setColor(COLORREF rgb)
{
	this->color_p = rgb;
}

COLORREF Polyline::getColor()
{
	return this->color_p;
}

void Polyline::setThick(double thick)
{
	this->thick = thick;
}
double Polyline::getThick()
{
	return this->thick;
}

void Polyline::setPattern(int pattern)
{
	this->pattern = pattern;
}
int Polyline::getPattern()
{
	return this->pattern;
}

void Polyline::next(Point point)
{
	if (this->poly_array.GetSize() == 0)
	{
		this->poly_array[0].setEnd_x(point.getX());
		this->poly_array[0].setEnd_y(point.getY());
		this->temp.setStart_x(point.getX());
		this->temp.setStart_y(point.getY());
		this->poly_array.Add(temp);
		this->index = this->poly_array.GetSize();
	}
	else
	{
		this->poly_array[index - 1].setEnd_x(point.getX());
		this->poly_array[index - 1].setEnd_y(point.getY());
		this->temp.setStart_x(point.getX());
		this->temp.setStart_y(point.getY());
		this->poly_array.Add(temp);
		this->index = this->poly_array.GetSize();
	}
}

void Polyline::moveAll()
{

}

void Polyline::eraseAt(int index, Point point)
{

}

void Polyline::eraseAll()
{
	this->~Polyline();
}

Polyline::~Polyline()
{
}
