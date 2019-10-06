
// Pen_rView.cpp: CPenrView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "CLine.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pen_r.h"
#endif

#include "Pen_rDoc.h"
#include "Pen_rView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenrView

IMPLEMENT_DYNCREATE(CPenrView, CView)

BEGIN_MESSAGE_MAP(CPenrView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CPenrView::OnSelCol)
	ON_COMMAND(ID_32773, &CPenrView::OnSize10)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32774, &CPenrView::OnSize20)
	ON_COMMAND(ID_32775, &CPenrView::OnSize30)
END_MESSAGE_MAP()

// CPenrView 생성/소멸

CPenrView::CPenrView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenrView::~CPenrView()
{
}

BOOL CPenrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenrView 그리기

void CPenrView::OnDraw(CDC* pDC)
{
	CPenrDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int n = pDoc->m_oa.GetSize();
	CLine* p;
	for (int i = 0; i < n; i++) {
		p = (CLine*)pDoc->m_oa[i];
		p->Draw(pDC);
	}
}


// CPenrView 인쇄

BOOL CPenrView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenrView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenrView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenrView 진단

#ifdef _DEBUG
void CPenrView::AssertValid() const
{
	CView::AssertValid();
}

void CPenrView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenrDoc* CPenrView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenrDoc)));
	return (CPenrDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenrView 메시지 처리기

int size = 5;
void CPenrView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON) {
		CLine* p = new CLine(pnt, point, col, size);
		GetDocument()->m_oa.Add(p);
		Invalidate(false);
	}
	pnt = point;
	CView::OnMouseMove(nFlags, point);
}

void CPenrView::OnSelCol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		col = dlg.GetColor();
	}
}


void CPenrView::OnSize10()
{
	size = 10;
}

void CPenrView::OnSize20()
{
	size = 20;
}


void CPenrView::OnSize30()
{
	size = 30;
}
