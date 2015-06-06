# include "stdafx.h"
# include "Text.h"

Text::Text(){
	isInsert = FALSE;

}

void Text::setStart_x(int x){
	this->start_x = x;
	rect.setStart_x(x);
}
void Text::setStart_y(int y){
	this->start_y = y;

	rect.setStart_y(y);
}
void Text::setEnd_x(int x){
	this->end_x = x;
}
void Text::setEnd_y(int y){
	this->end_y = y;
}

int Text::getStart_x(){
	return this->start_x;
}
int Text::getStart_y(){
	return this->start_y;
}
int Text::getEnd_x(){
	return this->end_x;
}
int Text::getEnd_y(){
	return this->end_y;
}

void Text::makeRect(CDC* dc, int x, int y){
	this->rect.draw(dc, x, y);
}

void Text::setRect(ARectangle rect){
	this->rect = rect;
}
ARectangle Text::getRect(void){
	return this->rect;
}

void Text::setColor(COLORREF rgb){
	this->color_t = rgb;
}
COLORREF Text::getColor(){
	return this->color_t;
}

void Text::setThick(double thick){
	this->thick = thick;
}
double Text::getThick(){
	return this->thick;
}

void Text::setPattern(int pattern){
	this->pattern = pattern;
}

int Text::getPattern(){
	return this->pattern;
}

void Text::draw(CDC* dc){
}

void Text::move(){

}

void Text::erase(){

}