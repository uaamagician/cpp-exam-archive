// 程式設計一，第三次上機考試第 5 題 (4 分)
// 
//  宣告
//       一個 cCircle 結構，裡面包含圓形的 x/y 座標、顏色 r, g, b 
//						    與半徑 radius，都是 int 型別
// 
//  主程式以 sCircle 宣告有 10 個元素的一維結構陣列 cx 與 boss 結構變數
//    利用一個迴圈，並以所提供的亂數公式產生 10 個圓 x/y 座標、顏色 r, g, b 與半徑 radius
//					圓的資料一定要儲存到一維結構陣列 cx 中
//	  利用另一個迴圈計算並產生 boss 的相關資訊如下
//		座標是這 10 個圓座標加總的平均值
//		半徑是這 10 個圓半徑加總的二分之一
//      顏色為這 10 個圓顏色加總的平均值
// 
//	  再利用一個迴圈繪製這 10 個圓，並單獨畫出 boss
// 
//  根據以下的註解完成所需要的程式碼
//  參考 p5.jpg
//


#define p
#ifdef p5

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

struct scircle
{
	int x, y;
	int r, g, b;
	int radius;
};// sCircle 結構宣告


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第三次上機的第 5 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	struct scircle cx[10];
	struct scircle boss = {0};

									// 宣告一維結構陣列 cx 與 boss，boss 記得要將內容都設定成 0

	
	// 產生 10 個圓的內容
	for (int i = 0; i < 11; i++)
	{
		cx[i].x =250 - rand() % 600;
		cx[i].y = 250 - rand() % 600;// for x/y
		cx[i].r = 155 - rand() % 100;
		cx[i].g = 155 - rand() % 100;// for r, g	
		cx[i].b = 200 - rand() % 55;	// for b
		cx[i].radius=20 + rand() % 80; // for radius
	}
	for (int i = 0; i < 11; i++)
	{
		boss.x += (cx[i].x / 10);
		boss.y += (cx[i].y / 10);
		boss.radius += (cx[i].radius / 2);
		boss.r += (cx[i].r / 10);
		boss.g += (cx[i].g / 10);
		boss.b += (cx[i].b / 10);
		
	}
	
	// 計算 boss 內容


	for (int i = 0; i < 11; i++)
	{
		setcolor(COLOR(cx[i].r, cx[i].g, cx[i].b));		// 圓的顏色
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);
	}//畫出 10 個圓
	
		// 畫出圓，X座標, Y座標,半徑
	

	//畫出 boss 圓
	setcolor(COLOR(	boss.r	, boss.g, boss.b));// 圓的顏色
	circle(X(boss.x), Y(boss.y), boss.radius);	  // 畫出圓，X座標, Y座標,半徑

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif