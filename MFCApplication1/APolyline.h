#pragma once
#include "Line.h"

class APolyline
{
public:
	APolyline();
	APolyline(const APolyline &p);
	APolyline& operator=(const APolyline &p);
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
	void draw(CDC* dc);

	int get_index();

public:
	CArray <Line, Line&> poly_array;
	Line temp;
	COLORREF color_p;
	double thick;
	int pattern;
	int index;
	~APolyline();
};

