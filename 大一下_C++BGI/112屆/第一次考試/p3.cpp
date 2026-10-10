//  程式設計二，第一次上機考試 ，第 3 題 (3 分)
// 
//	宣告一個可以指向 draw_c 與 draw_r 的函式指標
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
//  輸出結果 參考圖 p3.jpg
//	圓面積為 125663.703
//	正方形面積為 160000.000
//

#define P
#ifdef P3

#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

using namespace std;

float draw_c(int x, int y, int rad);
float draw_r(int x, int y, int length);

int main(void)
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	int x = 0, y = 0, rad = 200, leng = 400;

	float (*pfunc)(int, int, int);				// 宣告 pfun 為函式指標
	pfunc = draw_c;				// pfun 指向 add 函式
	printf("圓面積為 %10.3f\n", pfunc(x, y, rad)); // 以 pfun 呼叫, 並以 x y rad 為引數
	pfunc = draw_r;				// pfun 指向 product 函式
	printf("正方形面積為 %10.3f\n",	pfunc(x, y, leng)); // 以 pfun 呼叫, 並以 x y length 為引數
	system("pause"); return(0);
}


float draw_c(int x, int y, int rad)
{
	setcolor(COLOR(255, 255, 255));  // 設定顏色
	circle(X(x), Y(y), rad);
	return(3.1415926*rad*rad);
}
float draw_r(int x, int y, int length)
{
	setcolor(COLOR(255, 100, 255));  // 設定顏色
	drawSquare(x, y, length);
	return((float)length*length);
}

#endif