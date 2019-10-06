
// Pen_rView.h: CPenrView 클래스의 인터페이스
//

#pragma once


class CPenrView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPenrView() noexcept;
	DECLARE_DYNCREATE(CPenrView)

// 특성입니다.
public:
	CPenrDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPenrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSelCol();
	COLORREF col = RGB(0,0,0);
	afx_msg void OnSize10();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint pnt;
	afx_msg void OnSize20();
	afx_msg void OnSize30();
};

#ifndef _DEBUG  // Pen_rView.cpp의 디버그 버전
inline CPenrDoc* CPenrView::GetDocument() const
   { return reinterpret_cast<CPenrDoc*>(m_pDocument); }
#endif

