#pragma once
#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <vector>
#include <conio.h>
#include <math.h>
#include <thread>
using namespace std;

class Paint
{
public:
	Paint() {
		hwnd = 0;
		if ((hwnd = GetConsoleWindow()) == 0)
		{
			cout << "Window not found!!!" << endl;
			return;
		}
		if ((hdc = GetDC(hwnd)) == 0)
		{
			cout << "Error!!!" << endl;
			return;
		}
	}
protected:
	void ClearSreen() {
		pen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
		brush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);
		Rectangle(hdc, -100, -100, 10000, 900);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	HWND hwnd;
	HDC hdc;
	RECT rt;
	HPEN    pen;
	HBRUSH  brush;
	double CenterX = 900;
	double CenterY = 400;
};
