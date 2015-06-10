#pragma once

#include "Line.h"
#include "ARectangle.h"
#include "AEllipse.h"
#include "APolyline.h"
#include "Text.h"


class CGroup
{
public:
	CArray<Line, Line&> line;
	CArray<ARectangle, ARectangle&> rect;
	CArray<AEllipse, AEllipse&> ell;
	CArray<APolyline, APolyline&> poly;
	CArray<Text, Text&> text;
	CArray<CGroup, CGroup&> group;

	BOOL isline = false;
	BOOL isrect = false;
	BOOL isell = false;
	BOOL ispoly = false;
	BOOL istext = false;
	BOOL isgroup = false;


public:
	CGroup();
	~CGroup();
	CGroup(const CGroup &g);
	CGroup& operator=(const CGroup &g);

	void add_line(Line line);
	void add_rect(ARectangle rect);
	void add_ell(AEllipse ell);
	void add_poly(APolyline poly);
	void add_text(Text text);
	void add_group(CGroup group);

};

