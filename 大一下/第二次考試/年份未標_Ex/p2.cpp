#define P
#ifdef P2

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;

class ccircle {
private:
	int x, y;
	int r;
	char* name;
public:
	ccircle(int x, int y, int r) :x(x), y(y), r(r),name(nullptr) {};
	ccircle(int x, int y) :x(x), y(y), r(100), name(nullptr) {};
	ccircle(int r) :x(0), y(0), r(r), name(nullptr) {};
	ccircle(const char*, int);
	ccircle(const char*);
	void draw() { 
		setcolor(COLOR_WHITE); circle(X(x), Y(y), r);
		if (name != nullptr) {
			setcolor(COLOR_LIGHTGREEN);
			outtextxy(X(x), Y(y), name);
		}
	}
	~ccircle() {
		if (name != nullptr) { delete name; }
	}	
};
ccircle::ccircle(const char* c,int r):x(200),y(-200),r(r),name(nullptr) {
		name = new char[strlen(c)];
		strcpy( name, c);
}
ccircle::ccircle(const char* c):x(-200), y(-200), r(100), name(nullptr) {
		name = new char[strlen(c)];
		strcpy(name, c);
}



int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2 建構元的多載與動態記憶體的使用");
	// ------------ Part 1  ------------ 
	ccircle c1(100, 100, 150);
	ccircle c2(-100, 100);
	ccircle c3(50);
	c1.draw(); c2.draw(); c3.draw();

	// ------------ Part 2  ------------ 
	ccircle c4("Part2-1", 150);
	ccircle c5("Part2-2");
	c4.draw();
	c5.draw();

	system("pause"); return(0);
}

#endif