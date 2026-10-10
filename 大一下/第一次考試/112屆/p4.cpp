//  程式設計二，第一次上機考試 ，第 4 題 (4 分)
// 
//  宣告一個結構 sCircle，裡面包含成員變數有名稱 name(char:10) 
//                        座標(int) x/y 、顏色(int) r/g/b 與半徑(int) rad
//  在主程式宣告 sCircle 的一維陣列 cx，大小為 5
//  以傳【一維陣列】的方式，將 cx 傳給 genCircles 函式，該函式的功能就是產生圓的相關內容
//	然後【一次傳一個】的將 cx 中的儲存每一個圓，以【傳指標】的方式，
//					    傳給 drawC 函式，該函式的功能就是傳入的圓畫出來
//
//  genCircles 函式: 有 2 個引數，sCircle 的一維陣列與 int 型別的 n，n 儲存傳入陣列的大小
//                   圓的生成可使用預設給的計算方式
//  drawC 函式：有 1 個引數，sCircle 的指標變數
// 
//  要求: 滿足以下要求，且執行達成需求才算分數
//    1. 完成 genCircles 函式與 drawC 函式的撰寫
//    2. genCircles 函式與 drawC 函式必須有【原型宣告】寫在 main() 之前
//    3. 傳入 genCircles 與 drawC 函式的引數必須依照上面【】中的要求
//
//  參考 p4.jpg
//

#define P
#ifdef P4

#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// 宣告 sCircle
struct sCircle {
	char name[10];
	int x, y, rad;
	int r, g, b;
};
// getCircles 與 drawC 函式原形宣告
void genCircles(sCircle[], int);
void drawC(sCircle*);

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P4");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	sCircle k[5];					// 宣告 sCircle 一維陣列
	genCircles(k, 5);				// 呼叫 genCircles 函式 
	for ( i = 0; i < 5; i++)
	{
		drawC(&k[i]);					// 呼叫 drawC 函式，【一次傳一個】以傳指標的方式
	}
	

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}


// getCircles 函式主體
void genCircles(sCircle cc[], int n) {
	for (int i = 0; i < n; i++)
	{
		sprintf(cc[i].name, "%2d", i + 1);
		cc[i].x = rand() % 600 - 300;		// 產生圓的座標
		cc[i].y = rand() % 600 - 300;		// 產生圓的座標
		cc[i].rad = 50 + rand() % 50;		// 產生圓的半徑
		cc[i].r = rand () % 155 + 100;		// 產生圓的顏色
		cc[i].g = rand() % 155 + 100;		// 產生圓的顏色
		cc[i].b = rand() % 155 + 100;		// 產生圓的顏色
	}
}






// drawC 函式主體
void drawC(sCircle* pc) {
	setcolor(COLOR(pc->r, pc->g, pc->b));  // 設定顏色
	outtextxy(X(pc->x), Y(pc->y), pc->name);  // 座標與字串變數名稱
	circle(X(pc->x), Y(pc->y), pc->rad);
}

#endif