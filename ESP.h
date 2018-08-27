#pragma once
#include "Header.h"
class esp {
private:
	COLORREF SnapLineColor;
	COLORREF TextColor;
	HWND TargetWnd;
	DWORD TargetProcID;
	HDC HDC_Desktop;
	HBRUSH EnemyBrush;


public:
	void SetupDrawing() {
		EnemyBrush = CreateSolidBrush(RGB(255, 0, 0));
		SnapLineColor = RGB(0, 0, 255);
		TextColor = RGB(0, 255, 0);
	}
	float get3dDistance(float * myCoords, float * enemyCoords) {
		return sqrt(
			pow(double(enemyCoords[0] - myCoords[0]), 2.0) +
			pow(double(enemyCoords[1] - myCoords[1]), 2.0) +
			pow(double(enemyCoords[2] - myCoords[2]), 2.0));
	}
	
	void Run() {

	}

	esp() {
		TargetWnd = FindWindow(0, "AssaultCube");
		HDC_Desktop = GetDC(TargetWnd);
		SetupDrawing();
	}
};