#include "stdafx.h"
#include "Point.h"
Point::Point(){
	this->x = 0;
	this->y = 0;
	this->flag = 0;
}
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}
int Point::getX(){
	return this->x;
}
int Point::getY(){
	return this->y;
}
void Point::setX(int x){
	this->x = x;
}
void Point::setY(int y){
	this->y = y;
}
int Point::getFlag(){
	return this->flag;
}
void Point::setFlag(int falg){
	this->flag = falg;
}