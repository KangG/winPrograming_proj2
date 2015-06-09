# include "stdafx.h"
# include "Text.h"

Text::Text(){
	isInsert = FALSE;

}Text::Text(const Text &t){
	*this = t;
}

Text& Text::operator=(const Text &t){
	return *this;
}

void Text::setStart_x(int x){
	this->start_x = x;
	rect.setStart_x(x);
	r.left = x + 3;
}
void Text::setStart_y(int y){
	this->start_y = y;
	rect.setStart_y(y);
	r.top = y + 3;
}
void Text::setEnd_x(int x){
	this->end_x = x-3;
	rect.setEnd_x(x);
	r.right = x;
}
void Text::setEnd_y(int y){
	this->end_y = y - 3;
	rect.setEnd_y(y);
	r.bottom = y;
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

void Text::setString(CString str){
	this->s = str;
}

CString Text::getString(){
	return this->s;
}

void Text::makeRect(CDC* dc, CArray<TCHAR, TCHAR>* str){
	m_str.Copy(*str);
	this->rect.draw(dc, getEnd_x(), getEnd_y());
	CFont f;
	//	f.CreateFontW();
	dc->DrawText(m_str.GetData(),m_str.GetCount(), &r, DT_LEFT);
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

}void Text::DrawSelect(CDC *pDC)
{
	//그리기 속성 설정
	pDC->SelectStockObject(NULL_BRUSH);
	CPen pen;
	pen.CreatePen(PS_DOT, 3, color_l);
	CPen* oldPen = pDC->SelectObject(&pen);

	//그리기 속성 설정
	CBrush brush(RGB(51, 94, 168)); //브러쉬 생성
	CBrush* oldBrush = pDC->SelectObject(&brush); //브러쉬 지정
	pDC->SelectStockObject(NULL_PEN);

	//각 꼭지점마다 점을 그림
	pDC->Ellipse(start_x - 5, start_y - 5, start_x + 5, start_y + 5);
	pDC->Ellipse(end_x - 5, end_y - 5, end_x + 5, end_y + 5);
	pDC->Ellipse(start_x - 5, end_y - 5, start_x + 5, end_y + 5);
	pDC->Ellipse(end_x - 5, start_y - 5, end_x + 5, start_y + 5);


	//이전 펜과 브러쉬 속성으로 되돌림
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}