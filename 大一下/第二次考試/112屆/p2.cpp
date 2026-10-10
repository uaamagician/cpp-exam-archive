//  程式設計二，第二次上機考試 ，第 2 題 (6 分)
// 
// 宣告 CMouse 類別裡面包含
//   私有包含(都是整數型別)
//      座標 x/y，顏色 color , 狀態 status;  1:正常狀態, 2:在邊界上, 0: 死亡
//      上面三個都是 int 型別
//   公有包含
//      建構元：設定位置在 (0,0), 狀態為 正常狀態，顏色為 NORMAL_COLOR
//      getStatus 函式，傳回目前老鼠的狀態
//      draw 函式，呼叫 drawColorBox(x, y, color); 在 x/y 畫出指定顏色的老鼠
//      update() 函式，只有一個引數，型別為 char，
//                     回傳值為目前老鼠移動後的狀態
//          功能是依照輸入的 w、a、s、d 四個按鍵，讓老鼠上下左右個移動 20 個單位
//          同時判斷 老鼠是否在 X/Y 正負 200 的範圍內(不含)
//				狀態設定成 正常狀態 顏色為 NORMAL_COLOR
//			剛好在 X/Y 正負 200 的位置上
//				狀態設定成 在邊界上 顏色為 DANGER_COLOR
//			超出 X/Y 正負 200 (X_MAX/Y_MAX)的範圍外  狀態設定成死亡
// 
// 根據主程式的需求，完成可利用鍵盤 w、a、s、d 四個按鍵，控制老鼠的移動，走到邊界改變顏色，移除並顯示死亡
// 
// 要求:所有成員函式都必須寫在類別外，且程式正常執行並完成指定的功能才計分
// 
// 善意提醒 : 
//   1. 【不要】在成員函式內又再次宣告成員變數了
//  

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

// CMouse 類別
class CMouse {
private:
	int _ix, _iy, _icolor, _istatus;
public:
	CMouse();
	int getStatus();
	void draw();
	int update(char);
};

CMouse::CMouse() {
	_ix = 0; _iy = 0;
	_icolor = NORMAL_COLOR;
}

// 1:正常狀態, 2:在邊界上, 0: 死亡
int CMouse::getStatus() {
	return(_istatus);
}

// CMouse 類別 draw 函式的內容
void CMouse::draw(){
	drawColorBox(_ix, _iy, _icolor); // 畫出老鼠
}

// CMouse 類別 update 函式的內容
int CMouse::update(char cin) {
	switch (cin) {
	case 'w':			// 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_iy += 20;
		break;
	case 'a' :// 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_ix -= 20;
		break;
	case 's' :// 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_iy -= 20;
		break;
	case 'd' :// 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_ix += 20;
		break;
	default:
		break;
	}
	if (_ix > -X_MAX && _ix < X_MAX && _iy > -Y_MAX && _iy < Y_MAX) {
		_istatus = 1; _icolor = NORMAL_COLOR;
	}
	else if (_ix > X_MAX || _ix < -X_MAX || _iy > Y_MAX || _iy < -Y_MAX) {
		_istatus = 0;
	}
	else {
		_istatus = 2; _icolor = DANGER_COLOR;
	}
	return(_istatus);
}


// 安全區域內
// 跑到邊界外，老鼠死亡，遊戲結束			
// 在邊界上

int main()
{
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2");
	CMouse mx;	// 宣告 mx 建立時就會自動呼叫 CMouse 建構
	status = mx.getStatus();	// 透過 mx 呼叫 getStatus, 取得老鼠的狀態, 並給變數 status 
	while (status) { // 老鼠還活者,可繼續操作
		cleardevice();
		drawFence(); // 畫出範圍
		mx.draw();			 // 畫出老鼠
		swapbuffers();
		cIn = getch();	// 取得使用者的輸入
		status = mx.update(cIn);				// 讓老鼠自己更新狀態，並接收傳回的老鼠狀態
		rewind(stdin);	// 清除輸入緩衝區
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