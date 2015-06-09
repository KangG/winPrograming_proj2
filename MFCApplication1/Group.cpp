#include "stdafx.h"
#include "Group.h"


CGroup::CGroup()
{
}


CGroup::~CGroup()
{
}

CGroup::CGroup(const CGroup &g)
{
	*this = g;
}

CGroup& CGroup::operator=(const CGroup &g)
{
	return *this;
}

void CGroup::add_line(Line line)
{
	this->line.Add(line);
}

void CGroup::add_rect(ARectangle rect)
{
	this->rect.Add(rect);
}

void CGroup::add_ell(AEllipse ell)
{
	this->ell.Add(ell);
}

void CGroup::add_poly(APolyline poly)
{
	this->poly.Add(poly);
}

void CGroup::add_text(Text text)
{
	this->text.Add(text);
}

void CGroup::add_group(CGroup group)
{
	this->group.Add(group);
}