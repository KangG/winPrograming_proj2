#include "stdafx.h"
#include "Point.h"


class Line : public Point{
public:
	Line();

	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(int thick);
	int getThick();

	void setPattern(int pattern);
	int getPattern();

	void moveAll();
	void movePoint();

	void draw();

	void erase();

	int getStart_x();
	int getEnd_x();
	void setStart_x(int x);
	void setEnd_x(int x);
	int getStart_y();
	int getEnd_y();
	void setStart_y(int y);
	void setEnd_y(int y);


private:
	int start_x;		// 점 관련 변수
	int start_y;
	int end_x;
	int end_y;
	Point start_p(int start_x, int start_y);
	Point end_p(int end_x, int end_y);

	COLORREF color_l;

	int thick;

	int pattern;
};