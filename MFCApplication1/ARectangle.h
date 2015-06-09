#pragma once
#include "Line.h"

class ARectangle : public Line
{
public:
	ARectangle();

	void setColor_l(COLORREF rgb);
	COLORREF getColor_l();
	void setColor_s(COLORREF rgb);
	COLORREF getColor_s();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();

	void move(int move_select, CPoint point, CPoint &prev);

	void draw(CDC* dc, int x, int y);

	void erase();

	int getStart_x();
	int getStart_y();
	void setStart_x(int x);
	void setStart_y(int y);

	int getEnd_x();
	int getEnd_y();
	void setEnd_x(int x);
	void setEnd_y(int y);

	~ARectangle();


	void DrawSelect(CDC *pDC);

public:
	int start_x;
	int start_y;
	int end_x;
	int end_y;

	COLORREF color_l;
	COLORREF color_s;
	double thick;
	int pattern;
};

