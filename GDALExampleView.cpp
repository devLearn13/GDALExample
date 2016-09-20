
// GDALExampleView.cpp : implementation of the CGDALExampleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GDALExample.h"
#endif

#include "GDALExampleDoc.h"
#include "GDALExampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDALExampleView

IMPLEMENT_DYNCREATE(CGDALExampleView, CView)

BEGIN_MESSAGE_MAP(CGDALExampleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGDALExampleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGDALExampleView construction/destruction

CGDALExampleView::CGDALExampleView()
{
	// TODO: add construction code here
	//  [9/20/2016 minhgioang]	
	GDALAllRegister();
	GDALDataset       *poDS;
}

CGDALExampleView::~CGDALExampleView()
{
}

BOOL CGDALExampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGDALExampleView drawing

void CGDALExampleView::OnDraw(CDC* /*pDC*/)
{
	CGDALExampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CGDALExampleView printing


void CGDALExampleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDALExampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDALExampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDALExampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGDALExampleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGDALExampleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGDALExampleView diagnostics

#ifdef _DEBUG
void CGDALExampleView::AssertValid() const
{
	CView::AssertValid();
}

void CGDALExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDALExampleDoc* CGDALExampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDALExampleDoc)));
	return (CGDALExampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDALExampleView message handlers
