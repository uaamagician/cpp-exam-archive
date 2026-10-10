// 程式設計一，第三次上機考試第 4 題 (4 分)
// 
//  宣告 sCircle 結構，成員變數包含名稱(char:12)、 
//		 x/y 座標、顏色 r, g, b 與半徑 radius，這些都是 int 型別
// 
//  主程式以 sCircle 宣告有 10 個元素的一維結構陣列 cx 與一個  boss 結構變數
//    利用迴圈，並以的亂數公式產生 10 個圓 x/y 座標、顏色 r, g, b 與半徑 radius
//					圓的資料一定要儲存到一維結構陣列 cx 中
//				    圓的名稱編號從 1 到 10 (使用 sprintf( ," ",) 函式)
//	  利用另一個迴圈計算並產生 boss 的相關資訊如下
//		座標是這 10 個圓座標加總的平均值
//		半徑是這 10 個圓半徑加總的[三分之一]
//      顏色為這 10 個圓顏色加總的平均值
// 
//	  再利用一個迴圈繪製這 10 個圓，並單獨畫出 boss 圓
// 
//  根據以下的註解完成所需要的程式碼
//  參考 p4.jpg
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

typedef struct {
	char name[12];
	int x, y;
	int r, g, b;
	int radius;
}Circle;

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "第三次上機的第 4 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	Circle cx[10], boss = { 0 };					// 宣告 cx 與 boss，boss 記得要將內容都設定成 0

	// 產生10個圓的內容
	for (int i = 0; i < 10; i++)
	{
		cx[i].x = 250 - rand() % 600;
		cx[i].y = 250 - rand() % 600;
		cx[i].r = 200 - rand() % 55;
		cx[i].g = 200 - rand() % 55;
		cx[i].b = 200 - rand() % 55;
		cx[i].radius = 20 + rand() % 80;
		sprintf(cx[i].name, "%2d", i + 1);
		boss.x += cx[i].x;
		boss.y += cx[i].y;
		boss.r += cx[i].r;
		boss.g += cx[i].g;
		boss.b += cx[i].b;
		boss.radius += cx[i].radius;
	}
	boss.x /= 10;
	boss.y /= 10;
	boss.r /= 10;
	boss.g /= 10;
	boss.b /= 10;
	boss.radius /= 3;

	strcpy(boss.name, "Boss");

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);

	for (int i = 0; i < 10; i++)
	{
		outtextxy(X(cx[i].x), Y(cx[i].y), cx[i].name);
		setcolor(COLOR(cx[i].r, cx[i].g, cx[i].b));
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);
	}

	// 畫出 boss
	outtextxy(X(boss.x), Y(boss.y), boss.name);
	setcolor(COLOR(boss.r, boss.g, boss.b));
	circle(X(boss.x), Y(boss.y), boss.radius);

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif