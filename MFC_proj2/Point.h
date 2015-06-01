#pragma once
#include "stdafx.h"

class Point {
public:
	Point();
	Point(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getFlag();
	void setFlag(int flag);

private:
	int x;
	int y;
	int flag;
};