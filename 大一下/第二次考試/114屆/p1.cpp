#define P
#ifdef P1

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define Range 200	// 定義可活動的範圍
using namespace std;
void drawFence();

enum state {
	dead,
	normal,
	board
};

// 宣告 CMouse 類別
class mouse{
private:  // 私有
	int x, y;
	int status;
	int color;

public:   // 公有
	mouse(int x = 0, int y = 0, int color = NORMAL_COLOR) :x(x), y(y), color(color) {};
	void draw();
	void setPosStatus(int,int,int);
	void update(char);
	int const get_status() { return status; }
	
};

void mouse::setPosStatus(int x, int y, int status) {
	this->x = x; this->y = y; this->status = status;
}

void mouse::draw()  // 必須改成寫在類別外
{
	drawColorBox(x, y, color); // 畫出老鼠，自行改變成員變數名稱
}


void mouse::update(char cIn) // 必須改成寫在類別外
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y+=20;
		break;
	case 's': // 往下
		y-= 20;
		break;
	case 'a': // 往左
		x-= 20;
		break;
	case 'd': // 往右
		x+= 20;
		break;
	}
	if (x<Range && x>-Range && y<Range && y>-Range) { status = normal; color = NORMAL_COLOR; }
	else if (x == Range || x == -Range || y == Range || y == -Range) { status = board; color = DANGER_COLOR; }
	else { status = dead; }
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, " P1 ");

	int k = 1;
	char cIn, strbuf[80]; 
	mouse m;
	m.setPosStatus(20, -20, normal);
	for(int i=0;i<2;i++){
		while (	m.get_status()!=dead		) { // 老鼠還活者,可繼續操作
			cleardevice();
			drawFence(); // 畫出範圍
			m.draw();			// 畫出老鼠
			swapbuffers();
			m.update(getch());	// 讓老鼠自己更新狀態，並接收傳回的老鼠狀態
			rewind(stdin);	// 清除輸入緩衝區
		}
		cleardevice();
		drawFence();
		setcolor(COLOR_WHITE);
		sprintf(strbuf, "第 %02d 次遊戲結束，按任意鍵繼續!!", k);
		outtextxy(X(-100), Y(0), strbuf);
		swapbuffers();
		while (!kbhit()) { delay(200); }
		k++;
		m.setPosStatus(0, 0, normal);
	}

	while (!kbhit()) { delay(200); } return 0;
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

#endif