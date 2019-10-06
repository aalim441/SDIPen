#pragma once
#include <afx.h>
class CLine :
	public CObject
{
	CPoint m_From, m_To;
	COLORREF m_col;
	int size = 10;
	DECLARE_SERIAL(CLine);
public:
	CLine() {

	}
	CLine(CPoint From, CPoint To, COLORREF col, int s){
		m_From = From;
		m_To = To;
		m_col = col;
		size = s;
	}
	void Draw(CDC* pDC) {
		CPen pen(PS_SOLID, size, m_col);
		pDC->SelectObject(&pen);
		pDC->MoveTo(m_From);
		pDC->LineTo(m_To);
	}
	void get_size(int s) {
		size = s;
	}
	virtual void Serialize(CArchive& ar);
};

