#pragma once
#include "Line.h"
class Polyline : public Line
{
public:

	Polyline();
	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();

	void next(Point point);
	void moveAll();
	void eraseAt(int index, Point point);
	void eraseAll();

	int get_x(Point point);
	int get_y(Point point);

public:
	int start_x;
	int start_y;
	CArray <Line, Line&> poly_array;
	Line temp;
	COLORREF color_p;
	double thick;
	int pattern;
	int index;

	~Polyline();
};

