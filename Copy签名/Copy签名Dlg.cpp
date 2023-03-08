
// Copyǩ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Copyǩ��.h"
#include "Copyǩ��Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCopyǩ��Dlg �Ի���



CCopyǩ��Dlg::CCopyǩ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COPY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCopyǩ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCopyǩ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCopyǩ��Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCopyǩ��Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCopyǩ��Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCopyǩ��Dlg ��Ϣ�������

BOOL CCopyǩ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCopyǩ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCopyǩ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCopyǩ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCopyǩ��Dlg::OnBnClickedButton1()
{
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString defaultDir = "";	//Ĭ�ϴ򿪵��ļ�·��
	CString fileName = "";			//Ĭ�ϴ򿪵��ļ���
	CString filter = "�ļ� (*.dll)|*.dll||";	//�ļ����ǵ�����
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = "";
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	CWnd::SetDlgItemTextA(IDC_EDIT1, filePath);
}


void CCopyǩ��Dlg::OnBnClickedButton2()
{
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString defaultDir;	//Ĭ�ϴ򿪵��ļ�·��
	CString fileName;			//Ĭ�ϴ򿪵��ļ���
	CString filter = "�ļ� (*.dll)|*.dll||";	//�ļ����ǵ�����
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	INT_PTR result = openFileDlg.DoModal();
	CString filePath ="";
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	CWnd::SetDlgItemTextA(IDC_EDIT2, filePath);
}


void CCopyǩ��Dlg::OnBnClickedButton3()
{
	CString sigFileName;
	CString notSigFileName;
	GetDlgItemTextA(IDC_EDIT1, sigFileName);
	GetDlgItemTextA(IDC_EDIT2, notSigFileName);
	notSigFileName.Trim();
	sigFileName.Trim();
	if (sigFileName.IsEmpty() || notSigFileName.IsEmpty())
	{
		AfxMessageBox(_T("�ļ�·������Ϊ��!!!"));
		return;
	}

	//���ļ�
	PCHAR sigPath = sigFileName.GetBuffer();
	PCHAR notsigPath = notSigFileName.GetBuffer();

	

	do 
	{
		char * sigMem = NULL;
		char * notSigMem = NULL;
		FILE * sigFile = NULL;
		FILE * notSigFile = NULL;
		fopen_s(&sigFile, sigPath, "rb");
		if (!sigFile)
		{
			AfxMessageBox(_T("��ǩ���ļ�ʧ��!!!"));
			break;
		}

		fseek(sigFile, 0, SEEK_END);
		size_t sigFileLength = ftell(sigFile);
		rewind(sigFile);

		sigMem = (char *)malloc(sigFileLength);
		memset(sigMem, 0, sigFileLength);
		fread(sigMem, sigFileLength, 1, sigFile);
		fclose(sigFile);

		fopen_s(&notSigFile, notsigPath, "rb");
		if (!notSigFile)
		{
			free(sigMem);
			AfxMessageBox(_T("��δǩ���ļ�ʧ��!!!"));
			break;
		}

		//��ȡδǩ������
		fseek(notSigFile, 0, SEEK_END);
		size_t notSigFileLength = ftell(notSigFile);
		rewind(notSigFile);
		
		notSigMem = (char *)malloc(notSigFileLength);
		
		memset(notSigMem, 0, notSigFileLength);
		fread(notSigMem, notSigFileLength, 1, notSigFile);
		fclose(notSigFile);

		//��ʼ��ȡǩ��Ŀ¼
		PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)sigMem;
		PIMAGE_NT_HEADERS pNts = (PIMAGE_NT_HEADERS)(sigMem+ pDos->e_lfanew);
		
		PIMAGE_DOS_HEADER pDos1 = (PIMAGE_DOS_HEADER)notSigMem;
		PIMAGE_NT_HEADERS pNts1 = (PIMAGE_NT_HEADERS)(notSigMem + pDos1->e_lfanew);

		if (pNts1->Signature != 0x4550 || pNts->Signature != 0x4550)
		{
			free(sigMem);
			free(notSigMem);
			AfxMessageBox(_T("���PE��ʽ���ļ�!!!"));
			break;
		}

		/*
		if (pNts1->FileHeader.Machine != pNts->FileHeader.Machine)
		{
			free(sigMem);
			free(notSigMem);
			AfxMessageBox(_T("����PE��ʽ��һ�£�����һ����X86 һ����X64 �ļ�"));
			break;
		}
		*/
		PUCHAR fw = NULL;
		ULONG fwisze = NULL;
		ULONG SigVirtualAddress = 0;
		ULONG sigSize = 0;
		if (pNts->OptionalHeader.Magic == 0x20B)
		{
			PIMAGE_NT_HEADERS64 pNts = (PIMAGE_NT_HEADERS64)(sigMem + pDos->e_lfanew);
			PIMAGE_DATA_DIRECTORY Pdir = &pNts->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY];
			SigVirtualAddress = Pdir->VirtualAddress;
			sigSize = Pdir->Size;

			fwisze = notSigFileLength + sigSize;
			fw = (PUCHAR)malloc(fwisze);
			memset(fw, 0, fwisze);
			memcpy(fw, notSigMem, notSigFileLength);

			
		
		}
		else 
		{
			PIMAGE_DOS_HEADER pDos32 = (PIMAGE_DOS_HEADER)sigMem;
			PIMAGE_NT_HEADERS32 pNts32 = (PIMAGE_NT_HEADERS32)(sigMem + pDos32->e_lfanew);
			PIMAGE_DATA_DIRECTORY Pdir = &pNts32->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY];
			SigVirtualAddress = Pdir->VirtualAddress;
			sigSize = Pdir->Size;

			fwisze = notSigFileLength + sigSize;
			fw = (PUCHAR)malloc(fwisze);
			memset(fw, 0, fwisze);
			memcpy(fw, notSigMem, notSigFileLength);

			
		}
		
		if (pNts1->OptionalHeader.Magic == 0x20B)
		{

			PIMAGE_DOS_HEADER pDos64w = (PIMAGE_DOS_HEADER)fw;
			PIMAGE_NT_HEADERS64 pNts64w = (PIMAGE_NT_HEADERS64)(fw + pDos64w->e_lfanew);
			PIMAGE_DATA_DIRECTORY Pdirw = &pNts64w->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY];
			PIMAGE_SECTION_HEADER pImageSection = IMAGE_FIRST_SECTION(pNts64w);
			pImageSection += (pNts64w->FileHeader.NumberOfSections - 1);

			ULONG VirtualAddressW = (pImageSection->PointerToRawData + pImageSection->SizeOfRawData);
			memcpy(fw + VirtualAddressW, sigMem + SigVirtualAddress, sigSize);
			Pdirw->VirtualAddress = VirtualAddressW;
			Pdirw->Size = sigSize;
		}
		else 
		{


			PIMAGE_DOS_HEADER pDos32w = (PIMAGE_DOS_HEADER)fw;
			PIMAGE_NT_HEADERS pNts32w = (PIMAGE_NT_HEADERS)(fw + pDos32w->e_lfanew);
			PIMAGE_DATA_DIRECTORY Pdirw = &pNts32w->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY];
			PIMAGE_SECTION_HEADER pImageSection = IMAGE_FIRST_SECTION(pNts32w);
			pImageSection += (pNts32w->FileHeader.NumberOfSections - 1);

			ULONG VirtualAddressW = (pImageSection->PointerToRawData + pImageSection->SizeOfRawData);
			memcpy(fw + VirtualAddressW, sigMem + SigVirtualAddress, sigSize);
			Pdirw->VirtualAddress = VirtualAddressW;
			Pdirw->Size = sigSize;
		}

		free(notSigMem);
		free(sigMem);

		if (fw)
		{
			FILE * file = NULL;
			fopen_s(&file, "sig.dll","wb");
			if (!file)
			{
				free(fw);
				break;
			}

			fwrite(fw, fwisze, 1, file);
			fclose(file);
			free(fw);
			AfxMessageBox(_T("��ǩ���ɹ�\r\n"));
		}

	} while (0);

	sigFileName.ReleaseBuffer();
	notSigFileName.ReleaseBuffer();
}
