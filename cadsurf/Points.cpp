// Points.cpp: 实现文件
//

#include "stdafx.h"
#include "CadSurf.h"
#include "afxdialogex.h"
#include "Points.h"

#include "GLView.h"



// Points 对话框

IMPLEMENT_DYNAMIC(Points, CDialogEx)

Points::Points(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Points, pParent)
	, point1_x(0)
	, point4_z(0)
	, point1_y(0)
	, point1_z(0)
	, point2_x(0)
	, point2_y(0)
	, point2_z(0)
	, point3_x(0)
	, point3_y(0)
	, point3_z(0)
	, point4_x(0)
	, point4_y(0)
	, point5_x(0)
	, point5_y(0)
	, point5_z(0)
	, point6_x(0)
	, point6_y(0)
	, point6_z(0)
	, point7_x(0)
	, point7_y(0)
	, point7_z(0)
	, point8_x(0)
	, point8_y(0)
	, point8_z(0)
	, point9_x(0)
	, point9_y(0)
	, point9_z(0)
	, point10_x(0)
	, point10_y(0)
	, point10_z(0)
	, point11_x(0)
	, point11_y(0)
	, point11_z(0)
	, point12_x(0)
	, point12_y(0)
	, point12_z(0)
	, point13_x(0)
	, point13_y(0)
	, point13_z(0)
	, point14_x(0)
	, point14_y(0)
	, point14_z(0)
	, point15_x(0)
	, point15_y(0)
	, point15_z(0)
	, point16_x(0)
	, point16_y(0)
	, point16_z(0)
{

}

Points::~Points()
{
}

void Points::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, point1_x);
	DDX_Text(pDX, IDC_EDIT13, point4_z);
	DDX_Text(pDX, IDC_EDIT3, point1_y);
	DDX_Text(pDX, IDC_EDIT6, point1_z);
	DDX_Text(pDX, IDC_EDIT7, point2_x);
	DDX_Text(pDX, IDC_EDIT8, point2_y);
	DDX_Text(pDX, IDC_EDIT4, point2_z);
	DDX_Text(pDX, IDC_EDIT9, point3_x);
	DDX_Text(pDX, IDC_EDIT5, point3_y);
	DDX_Text(pDX, IDC_EDIT10, point3_z);
	DDX_Text(pDX, IDC_EDIT11, point4_x);
	DDX_Text(pDX, IDC_EDIT12, point4_y);
	DDX_Text(pDX, IDC_EDIT22, point5_x);
	DDX_Text(pDX, IDC_EDIT15, point5_y);
	DDX_Text(pDX, IDC_EDIT16, point5_z);
	DDX_Text(pDX, IDC_EDIT24, point6_x);
	DDX_Text(pDX, IDC_EDIT17, point6_y);
	DDX_Text(pDX, IDC_EDIT19, point6_z);
	DDX_Text(pDX, IDC_EDIT20, point7_x);
	DDX_Text(pDX, IDC_EDIT14, point7_y);
	DDX_Text(pDX, IDC_EDIT23, point7_z);
	DDX_Text(pDX, IDC_EDIT21, point8_x);
	DDX_Text(pDX, IDC_EDIT18, point8_y);
	DDX_Text(pDX, IDC_EDIT25, point8_z);
	DDX_Text(pDX, IDC_EDIT2, point9_x);
	DDX_Text(pDX, IDC_EDIT26, point9_y);
	DDX_Text(pDX, IDC_EDIT27, point9_z);
	DDX_Text(pDX, IDC_EDIT28, point10_x);
	DDX_Text(pDX, IDC_EDIT29, point10_y);
	DDX_Text(pDX, IDC_EDIT30, point10_z);
	DDX_Text(pDX, IDC_EDIT31, point11_x);
	DDX_Text(pDX, IDC_EDIT32, point11_y);
	DDX_Text(pDX, IDC_EDIT33, point11_z);
	DDX_Text(pDX, IDC_EDIT34, point12_x);
	DDX_Text(pDX, IDC_EDIT35, point12_y);
	DDX_Text(pDX, IDC_EDIT36, point12_z);
	DDX_Text(pDX, IDC_EDIT37, point13_x);
	DDX_Text(pDX, IDC_EDIT38, point13_y);
	DDX_Text(pDX, IDC_EDIT39, point13_z);
	DDX_Text(pDX, IDC_EDIT40, point14_x);
	DDX_Text(pDX, IDC_EDIT41, point14_y);
	DDX_Text(pDX, IDC_EDIT42, point14_z);
	DDX_Text(pDX, IDC_EDIT43, point15_x);
	DDX_Text(pDX, IDC_EDIT44, point15_y);
	DDX_Text(pDX, IDC_EDIT45, point15_z);
	DDX_Text(pDX, IDC_EDIT46, point16_x);
	DDX_Text(pDX, IDC_EDIT47, point16_y);
	DDX_Text(pDX, IDC_EDIT48, point16_z);
}


BEGIN_MESSAGE_MAP(Points, CDialogEx)
	ON_BN_CLICKED(IDOK, &Points::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT33, &Points::OnEnChangeEdit33)
END_MESSAGE_MAP()




void Points::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void Points::OnEnChangeEdit33()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
