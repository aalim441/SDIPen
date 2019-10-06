#include "pch.h"
#include "CLine.h"

IMPLEMENT_SERIAL(CLine, CObject, 1);
void CLine::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_From << m_To << size << m_col;
	}
	else {
		ar >> m_From >> m_To >> size >> m_col;
	}
}