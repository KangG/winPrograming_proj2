#pragma once
#include "stdafx.h"
#include "Point.h"


class Line : public Point{
public:
	Line();

	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();

	void move(Point p, int x, int y);	//p: 클릭한 점, x : 변화한 x, y : 변화한 y

	virtual void draw(CDC* dc, int x, int y);

	void erase();

	int getStart_x();
	int getEnd_x();
	void setStart_x(int x);
	void setEnd_x(int x);
	int getStart_y();
	int getEnd_y();
	void setStart_y(int y);
	void setEnd_y(int y);
	~Line();

private:
	int start_x;		// 점 관련 변수
	int start_y;
	int end_x;
	int end_y;
	Point start_p(int start_x, int start_y);
	Point end_p(int end_x, int end_y);

	COLORREF color_l;

	double thick;

	int pattern;
};

