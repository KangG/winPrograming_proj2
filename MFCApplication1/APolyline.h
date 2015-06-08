#pragma once
#include "Line.h"

class APolyline
{
public:
	APolyline();
	APolyline(COLORREF color);
	APolyline(const APolyline &p);
	APolyline& operator=(const APolyline &p);
	
	void setColor_l(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();

	void next(Point point);
	void moveAll(int x, int y);
	void eraseAt(int index, Point point);
	void eraseAll();
	void draw(CDC* dc);
	void APolyline::DrawSelectLine(CDC *pDC);

	int get_index();

public:
	CArray <Line, Line&> poly_array;
	CArray <Point, Point&> point_array;
	Line temp;
	COLORREF color_p;
	double thick;
	int pattern;
	int index;
	~APolyline();
};

