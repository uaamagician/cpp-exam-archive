//  程式設計二，第一次上機考試 ，第 8 題 (5 分)
// 
// 宣告 CMouse 類別裡面包含
//	 成員變數(public:)
//        座標 x/y，顏色 color , 狀態 status;  1:正常狀態, 2:在邊界上, 0: 死亡
//       上面三個都是 int 型別
//	 成員變數
//      init() 函式
//			   沒有引數，設定老鼠的座標在 (0,0), 狀態為 1，顏色為 NORMAL_COLOR
//			   回傳值為老鼠的狀態
//      draw 函式，呼叫 drawColorBox(x, y, color); 在 x/y 畫出指定顏色的老鼠
//      update() 函式(此函示必須寫在類別外)，只有一個引數，型別為 char，
//                     回傳值為目前老鼠移動後的狀態
//          功能是依照輸入的 w、a、s、d 四個按鍵，讓老鼠上下左右個移動 20 個單位
//          同時判斷 老鼠是否在 X/Y 正負 200 的範圍內(不含)
//				狀態設定成 正常狀態 顏色為 NORMAL_COLOR
//			剛好在 X/Y 正負 200 的位置上
//				狀態設定成 在邊界上 顏色為 DANGER_COLOR
//			超出 X/Y 正負 200 的範圍外  狀態設定成死亡
// 
// 根據主程式的需求，完成可利用鍵盤 w、a、s、d 四個按鍵，控制老鼠的移動，走到邊界改變顏色，移除並顯示死亡
// 
// 參考 p8-1.jpg 與 p8-2.jpg 
//

#define P
#ifdef P8

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

//以 class 宣告 CMouse 類別
class Mouse
{
private:
	int x, y, color,status;
public:  // 此行放在所有變數與函式宣告之前
	Mouse() :x(180), y(180), color(NORMAL_COLOR),status(1) {};
	void update(char);
	void draw() {
		switch (status) {
		case 1:
			 color = (NORMAL_COLOR);
			break;
		case 2:
			color = (DANGER_COLOR);
			break;
		}
		drawColorBox(x, y, color);
	}
	int get_status() { return status; }
};

// update 成員函式必須寫在類別外
void Mouse::update(char ch) {

	switch (ch) {
	case 'w':
		y += 20;
		break;
	case 's':
		y -= 20;
		break;
	case 'a':
		x -= 20;
		break;
	case 'd':
		x += 20;
		break;
	}
	if (x < X_MAX && x > -X_MAX && y<Y_MAX && y>-Y_MAX) {
		status = 1;
	}
	else if (x == X_MAX || x == -X_MAX || y == Y_MAX || y == -Y_MAX) {
		status = 2;
	}
	else status = 0;
}




int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P8");
	Mouse M;
	char cIn;
	M.draw();
	while (	M.get_status()!=0)
	{
		cleardevice();
		drawFence();	// 畫出範圍
		cIn = getch();
		M.update(cIn);
		M.draw();
		swapbuffers();
		rewind(stdin);
	}
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
	swapbuffers();
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
