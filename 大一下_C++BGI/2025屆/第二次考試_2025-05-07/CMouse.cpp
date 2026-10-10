#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#include "Header.h"



CMouse::CMouse()
{
	x = 0; y = 0;
	color = NORMAL_COLOR;
	status = 1;
}
int CMouse::getstatus()
{
	return(status);
}
void CMouse::draw()
{
	drawColorBox(x, y, color);
}
int CMouse::update(char ch) {
	switch (ch)
	{
	case 'w':
		y = y + 20;
		break;
	case 'a':
		x = x - 20;
		break;
	case 's':
		y = y - 20;
		break;
	case 'd':
		x = x + 20;
		break;
	}
	if (x<200 && x>-200 && y<200 && y>-200)
	{
		status = 1;
		color = NORMAL_COLOR;
	}
	else if (x > 200 || x < -200 || y>200 || y < -200)
	{
		status = 0;
	}
	else
	{
		status = 2;
		color = DANGER_COLOR;
	}
	return(status);
}
void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}