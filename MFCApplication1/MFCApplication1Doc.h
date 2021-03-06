
// MFCApplication1Doc.h : CMFCApplication1Doc 클래스의 인터페이스
//
#include "Group.h"
#pragma once


class CMFCApplication1Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// 특성입니다.
public:
	CPoint temp;
	CArray<TCHAR, TCHAR> m_str;
	CArray<Text, Text&> Text_array;		//Text 객체를 저장할배열
	CArray<Line, Line&> Line_array;						//Line 객체를 저장할배열
	CArray<ARectangle, ARectangle&> ARect_array;		//Rect 객체를 저장할배열
	CArray<AEllipse, AEllipse&> AEll_array;				//Ellipse 객체를 저장할배열
	CArray<APolyline, APolyline&> APolyline_array;		//PolyLine 객체를 저장할배열
	CArray<CGroup, CGroup&> group_array;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
