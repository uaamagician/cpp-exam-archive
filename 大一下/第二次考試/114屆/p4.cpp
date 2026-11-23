#define P
#ifdef P4

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"

using namespace std;

// CCircle 類別宣告
class ccircle {
private:
	int x, y;
	int r;
	int color;
public:
	ccircle(int x=0, int y=0,int r=100,int color= COLOR_WHITE):x(x),y(y),r(r),color(color){}
	ccircle(const ccircle& c){
		this->x = c.x + 100;
		this->y = c.y - 200;
		this->r = c.r;
		this->color = c.color;
	}
	void setPos(int x, int y) { this->x = x; this->y = y; }
	void setRadColor(int r, int color) { this->r = r; this->color = color; }
	ccircle operator=(const ccircle& c) {
		this->x = c.x;
		this->y = c.y;
		this->r = c.r;
		this->color = c.color;
		return(*this);
	}
	void draw() {
		setcolor(color);			
		circle(X(x), Y(y), r);	
	}
};




int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P4 建構元引數、拷貝建構元與指定運算子");
	ccircle c1(0, 100, 150, 12);
	ccircle c2(c1);
	c2.setRadColor(50, 10);
	c1.draw();
	c2.draw();

	ccircle c3;
	c3 = c1 = c2;
	c3.setPos(-250, 100);
	c3.draw();
	system("pause"); return(0);
}

#endif