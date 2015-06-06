#include "Line.h"

class AEllipse : public Line{
public:
	AEllipse();

	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();

	void move(Point p, int x, int y);

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

	~AEllipse();

public:
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	Point start_p(int start_x, int start_y);
	Point end_p(int end_x, int end_y);

	COLORREF color_r;
	double thick;
	int pattern;
};