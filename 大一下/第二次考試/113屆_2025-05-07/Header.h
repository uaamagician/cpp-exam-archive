#pragma once
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
using namespace std;
#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
class CMouse
{
public:
	CMouse();
	int getstatus();
	void draw();
	int update(char ch);
private:
	int x, y, color, status;
};
void drawFence();
