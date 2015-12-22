// pieChart2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "pieChart2.h"
#include "pieChart2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CpieChart2Dlg dialog




CpieChart2Dlg::CpieChart2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CpieChart2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpieChart2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CpieChart2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CpieChart2Dlg message handlers

BOOL CpieChart2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rect;
	GetClientRect(rect);
	rect.left = 10;
	rect.top = 10;
	rect.bottom -= 50;
	rect.right -= 10;
	m_pieChart.Create(L"Pie Chart", rect, this, 1);
	m_pieChart.SetParentWindowColor(::GetSysColor(COLOR_3DFACE));
	AddItems();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CpieChart2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpieChart2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpieChart2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CpieChart2Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}

void CpieChart2Dlg::AddItems(void)
{
	m_pieChart.InsertItem(L"Item 1", L"Item 1", 20, Color(255, 110, 120, 253));
	m_pieChart.InsertItem(L"Item 2", L"Item 2", 10, Color(255, 255, 123, 50));
	m_pieChart.InsertItem(L"Item 3", L"Item 3", 40, Color(255,  22, 205,  31));

	m_pieChart.SetInclineAngle(60);
	m_pieChart.SetDepth(50);
	m_pieChart.SetBackgrndColor(Color(255,212,212,212));
	m_pieChart.SetDistanceIndex(m_pieChart.GetPieChartItem(L"Item 2"), 5);
	//Lets override the locations of the pie & label :)
	CRect rect;
	m_pieChart.GetClientRect(rect);
	m_pieChart.SetPieChartRectOverride(CRect(80, rect.top + 100, rect.right - 80, rect.bottom + 110));
	m_pieChart.SetLabalRectOverride(CRect(rect.right - 150, rect.top + 80, rect.right, rect.top + 300));
	
}
