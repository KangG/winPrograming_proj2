#pragma once
# include "ARectangle.h"

class Text : public ARectangle{
public:
	Text();

	void makeRect(CDC* dc, int x, int y);

	void setRect(ARectangle rect);
	ARectangle getRect(void);

	void setStart_x(int x);
	void setStart_y(int y);
	void setEnd_x(int x);
	void setEnd_y(int y);
	int getStart_x();
	int getStart_y();
	int getEnd_x();
	int getEnd_y();


	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();
	void draw(CDC* dc);
	void move();
	void erase();

	ARectangle rect;
private:
	BOOL isInsert;
	COLORREF color_t;
	double thick;
	int pattern;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
};