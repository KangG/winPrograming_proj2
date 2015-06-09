#pragma once
# include "ARectangle.h"

class Text : public ARectangle{
public:
	Text();
	Text(const Text &t);
	Text& operator=(const Text &t);

	void makeRect(CDC* dc);
	void DrawSelect(CDC *pDC);
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
	void setString(CString str);
	CString getString();

	void setColor(COLORREF rgb);
	COLORREF getColor();

	void setThick(double thick);
	double getThick();

	void setPattern(int pattern);
	int getPattern();
	void move(int move_select, CPoint point, CPoint &prev);
	void draw(CDC* dc, int x, int y);
	void erase();

	ARectangle rect;

	CArray<TCHAR, TCHAR> m_str;
private:

	CString s;
	CRect r;
	BOOL isInsert;
	COLORREF color_t;
	CFont font;
	double thick;
	int pattern;
	int start_x;
	int start_y;
	int end_x;
	int end_y;


};