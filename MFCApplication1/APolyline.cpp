#include "stdafx.h"
#include "APolyline.h"


APolyline::APolyline()
{

	//���⼭ temp�� ������
	//���������� Ư���� ������ ������ �����ν�
	//�����ϴ� ���ε� ���� ������� ���� ������ �������� 
	//�������ְ�, �ٽ� �޶����� ���������� �������ִ� �۾�����
	//������ temp�� �������.

	this->color_p = *(new COLORREF(RGB(0, 0, 0)));
	this->thick = 1.5;
	this->pattern = PS_SOLID;
	this->index = 0;
}

APolyline::APolyline(COLORREF color)
{
	color_p = color;
}
APolyline::APolyline(const APolyline &p)
{
	*this = p;
}

APolyline& APolyline::operator=(const APolyline &p)
{
	return *this;
}

void APolyline::setColor_l(COLORREF rgb)
{
	this->color_p = rgb;
}

COLORREF APolyline::getColor()
{
	return this->color_p;
}

void APolyline::setThick(double thick)
{
	this->thick = thick;
}
double APolyline::getThick()
{
	return this->thick;
}

void APolyline::setPattern(int pattern)
{
	this->pattern = pattern;
}
int APolyline::getPattern()
{
	return this->pattern;
}

void APolyline::next(Point point)
{
	if (this->index == 0)
	{
		temp = Line(point.getX(), point.getY(), point.getX(), point.getY());
		poly_array.Add(temp);
		point_array.Add(point);
		index = poly_array.GetSize();
	}
	else
	{
		poly_array[index - 1].setEnd_x(point.getX());
		poly_array[index - 1].setEnd_y(point.getY());
		temp.setStart_x(point.getX());
		temp.setStart_y(point.getY());
		poly_array.Add(temp);
		point_array.Add(point);
		index = poly_array.GetSize();
	}
}

void APolyline::move(int x, int y, int index)
{
	point_array[index].setX(point_array[index].getX() + x);
	point_array[index].setY(point_array[index].getY() + y);
}




void APolyline::moveAll(int x, int y)
{
		int nArraySize = poly_array.GetSize(); 
		if (nArraySize > 0)
		{
			for (int i = 0; i<nArraySize; i++)
			{
				this->poly_array[i].setStart_x(this->poly_array[i].getStart_x() + x);
				this->poly_array[i].setStart_y(this->poly_array[i].getStart_y() + y);
			}
			this->poly_array[nArraySize].setEnd_x(this->poly_array[nArraySize].getEnd_x() + x);
			this->poly_array[nArraySize].setEnd_y(this->poly_array[nArraySize].getEnd_y() + y);
		}
}

void APolyline::eraseAt(int index)
{
	Point temp = point_array.GetAt(index);
	if (index == point_array.GetSize()-1)
	{
		TRACE("yes\n");
		poly_array.RemoveAt(poly_array.GetSize() - 1);
		point_array.RemoveAt(poly_array.GetSize());
		return;
	}
	for (int i = 0; i < poly_array.GetSize(); i++)
	{
		if ((temp.getX() == poly_array[i].getStart_x()) &&
			(temp.getY() == poly_array[i].getStart_y()))
		{
			TRACE("NO\n");
			if (i == 0)
			{
				poly_array.RemoveAt(i);
				point_array.RemoveAt(i);
				return;
			}
			
			poly_array.RemoveAt(i);
			point_array.RemoveAt(i);
			poly_array[i - 1].setEnd_x(poly_array[i].getStart_x());
			poly_array[i - 1].setEnd_y(poly_array[i].getStart_y());
			return;
		}

	}
	
	
	
}

APolyline::~APolyline()
{

}

int APolyline::get_index()
{
	return this->index;
}

void APolyline::draw(CDC* dc)
{
	CPen pen; 
	if (thick > 1)
	{
		LOGBRUSH logBrush;
		logBrush.lbStyle = BS_SOLID;
		logBrush.lbColor = color_p;
		pen.CreatePen(pattern | PS_GEOMETRIC, thick, &logBrush);
	}
	else
	{
		pen.CreatePen(pattern, thick, color_p);
	}
	CPen* oldPen = dc->SelectObject(&pen);

	for (int i = 0; i < poly_array.GetSize()-1; i++){
		dc->MoveTo(poly_array[i].getStart_x(),
			poly_array[i].getStart_y());
		dc->LineTo(poly_array[i].getEnd_x(),
			poly_array[i].getEnd_y());
	}
}

void APolyline::DrawSelectLine(CDC *pDC)
{
	//�׸��� �Ӽ� ����
	pDC->SelectStockObject(NULL_BRUSH);
	CPen pen;
	pen.CreatePen(pattern, thick, color_p);
	CPen* oldPen = pDC->SelectObject(&pen);


	//�׸��� �Ӽ� ����
	CBrush brush(RGB(51, 94, 168)); //�귯�� ����
	CBrush* oldBrush = pDC->SelectObject(&brush); //�귯�� ����
	pDC->SelectStockObject(NULL_PEN);

	//�� ���������� ���� �׸�
	for (int i = 0; i<point_array.GetSize(); i++) //�� �������� �����ŭ �ݺ�
	{
		CPoint sPt = CPoint(point_array[i].getX(), point_array[i].getY());
		pDC->Ellipse(sPt.x - 5, sPt.y - 5, sPt.x + 5, sPt.y + 5); //�� ������ �׸���
	}

	//���� ��� �귯�� �Ӽ����� �ǵ���
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}