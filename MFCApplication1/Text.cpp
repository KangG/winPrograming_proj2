# include "stdafx.h"
# include "Text.h"

Text::Text(){
	isInsert = FALSE;
	color_t = RGB(0,0,0);

	color_b = RGB(255, 255,255);

}Text::Text(const Text &t){
	*this = t;
}

Text& Text::operator=(const Text &t){
	return *this;
}

void Text::setStart_x(int x){
	this->start_x = x;
	rect.setStart_x(x);
	r.left =x;
}
void Text::setStart_y(int y){
	this->start_y = y;
	rect.setStart_y(y);
	r.top = y;
}
void Text::setEnd_x(int x){
	this->end_x = x;
	rect.setEnd_x(x);
	r.right = x;
}
void Text::setEnd_y(int y){
	this->end_y = y;
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

void Text::makeRect(CDC* dc){
	//this->rect.draw(dc, getEnd_x(), getEnd_y());
	//	CFont f;
	//	f.CreateFontW();
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

void Text::draw(CDC* dc, int x, int y){
	setEnd_x(x);
	setEnd_y(y);
	rect.draw(dc, getEnd_x(), getEnd_y());
	dc->SetTextColor(color_t);
	dc->SetBkColor(color_b);
	dc->DrawText(m_str.GetData(), m_str.GetCount(), &r, DT_LEFT);
}

void Text::move(int move_select, CPoint point, CPoint &prev){
	if (move_select >= 1 && move_select <= 4)			//start_x, start_y를 클릭
	{
		setEnd_x( point.x);
		end_y;  point.y;
	}
	else if (move_select >= 5 && move_select <= 8)			//end_x, end_y를 클릭
	{
		setEnd_x(point.x); 
		setEnd_y(point.y);
	}
	else if(move_select==9)			//사각형 안의 점 클릭
	{
		setStart_x(getStart_x()+( point.x - prev.x));
		setStart_y(getStart_y()+(point.y - prev.y));
		setEnd_x(getEnd_x()+(point.x - prev.x));
		setEnd_y(getEnd_y()+ (point.y - prev.y));

		prev.x = point.x;
		prev.y = point.y;
	}
}

void Text::erase(){}

void Text::setBkColor(COLORREF bg){
	color_b = bg;
}
COLORREF Text::getBkColor(void){
	return this->color_b;
}

void Text::setThick(double thick)
{
	rect.setThick(thick);
}

double Text::getThick()
{
	return rect.getThick();
}

void Text::setPattern(int pattern){
	rect.setPattern(pattern);
}
int Text::getPattern(){
	return rect.getPattern();
}
void Text::setPattern2(int pattern2){
	rect.setPattern2(pattern2);
}
int Text::getPattern2(){
	return rect.getPattern2();
}

void Text::setColor_l(COLORREF rgb)
{
	rect.setColor_l(rgb);
}

COLORREF Text::getColor_l()
{
	return rect.getColor_l();
}

void Text::setColor_s(COLORREF rgb)
{
	rect.setColor_s(rgb);
}

COLORREF Text::getColor_s()
{
	return rect.getColor_s();
}
void Text::DrawSelect(CDC *pDC)
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

	//선 중앙에 점을 그림
	pDC->Ellipse((start_x + end_x) / 2 - 5, start_y - 5, (start_x + end_x) / 2 + 5, start_y + 5);
	pDC->Ellipse((start_x + end_x) / 2 - 5, end_y - 5, (start_x + end_x) / 2 + 5, end_y + 5);
	pDC->Ellipse(start_x - 5, (start_y + end_y) / 2 - 5, start_x + 5, (start_y + end_y) / 2 + 5);
	pDC->Ellipse(end_x - 5, (start_y + end_y) / 2 - 5, end_x + 5, (start_y + end_y) / 2 + 5);

	//이전 펜과 브러쉬 속성으로 되돌림
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}