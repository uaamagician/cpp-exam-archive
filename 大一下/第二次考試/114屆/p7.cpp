#define P
#ifdef P7

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;

class mouse {
private:
	float x, y;
	int* colorptr;
public:
	mouse(float x =0, float y=0 , int color= COLOR_WHITE):x(x),y(y),colorptr(nullptr) {
		colorptr = new(int);
		*colorptr = color;
	}
	~mouse() { if (colorptr != nullptr)delete colorptr; }
	void draw() { drawBoxMan(x, y, *colorptr); };
};

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7 動態記憶體配置的處理");
	mouse m1(0,0);	
	mouse m2(-200, 0, COLOR_RED);	
	mouse m3(200, 0, COLOR_RED);	
	mouse m4(m1), m5;
	m3.draw();
	m4.draw();
	m5 = m1 = m2;
	m5.draw();
	system("pause"); return(0);
}

#endif