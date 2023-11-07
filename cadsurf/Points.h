#pragma once
#include "afxdialogex.h"
#include "afxwin.h"

// Points 对话框

class Points : public CDialogEx
{
	DECLARE_DYNAMIC(Points)

public:
	Points(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Points();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Points };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double point1_x;
	double point4_z;
	double point1_y;
	double point1_z;
	double point2_x;
	double point2_y;
	double point2_z;
	double point3_x;
	double point3_y;
	double point3_z;
	double point4_x;
	double point4_y;
	double point5_x;
	double point5_y;
	double point5_z;
	double point6_x;
	double point6_y;
	double point6_z;
	double point7_x;
	double point7_y;
	double point7_z;
	double point8_x;
	double point8_y;
	double point8_z;
	afx_msg void OnBnClickedOk();
	double point9_x;
	double point9_y;
	double point9_z;
	double point10_x;
	double point10_y;
	double point10_z;
	double point11_x;
	double point11_y;
	afx_msg void OnEnChangeEdit33();
	double point11_z;
	double point12_x;
	double point12_y;
	double point12_z;
	double point13_x;
	double point13_y;
	double point13_z;
	double point14_x;
	double point14_y;
	double point14_z;
	double point15_x;
	double point15_y;
	double point15_z;
	double point16_x;
	double point16_y;
	double point16_z;
};
