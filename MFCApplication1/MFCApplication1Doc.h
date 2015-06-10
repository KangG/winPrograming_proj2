
// MFCApplication1Doc.h : CMFCApplication1Doc Ŭ������ �������̽�
//
#include "Group.h"
#pragma once


class CMFCApplication1Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// Ư���Դϴ�.
public:
	CPoint temp;
	CArray<TCHAR, TCHAR> m_str;
	CArray<Text, Text&> Text_array;		//Text ��ü�� �����ҹ迭
	CArray<Line, Line&> Line_array;						//Line ��ü�� �����ҹ迭
	CArray<ARectangle, ARectangle&> ARect_array;		//Rect ��ü�� �����ҹ迭
	CArray<AEllipse, AEllipse&> AEll_array;				//Ellipse ��ü�� �����ҹ迭
	CArray<APolyline, APolyline&> APolyline_array;		//PolyLine ��ü�� �����ҹ迭
	CArray<CGroup, CGroup&> group_array;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
