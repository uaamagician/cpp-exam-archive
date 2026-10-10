// 程式設計一，第三次上機考試第 7 題 (4 分)
// 
//  宣告一個 sCircle 結構，結構成員宣告順序，名稱(char:12)、座標(x、y)、顏色(r, g, b)、半徑。
//			 座標、顏色與半徑都是 int 型別
// 
//  主程式以 sCircle 宣告儲存 10 個元素的一維結構陣列 cx，初始值設如下程式碼所給
//  完成 bsorting 函式，兩個引數, 沒有回傳值。第一個引數為結構陣列，第二個為陣列的大小
//	功能如下:
//		1. 針對傳入的結構陣列，以所儲存圓的 x 座標以小到大進行排序，也就是排序後
//	       cx[0] 儲存的圓其 x 座標為最小， cx[9]所儲存的圓其 x 座標為最大
//      2. 針對排序後的圓，[依小到大順序]設定
//				圓的 x 座標從 -350 開始, 每次增加 70
//              圓的半徑為 8 的倍數，也就是 cx[0] 半徑為 8、cx[1] 半徑為 16...依此類推
// 
// 完成 drawC 函式 : 兩個引數, 沒有回傳值。第一個引數為結構陣列，第二個為陣列的大小
//		將傳入的圓繪製出來, 結果如圖 p7.jpg
// 
//  根據以下的註解完成所需要的程式碼
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

typedef struct {
	char name[12];
	int x, y;
	int r, g, b;
	int radius;
}Circle;

void bsorting(Circle input[], int n) {
	bool f;
	do {
		f = false;
		for (int i = 0; i < n - 1; i++) {
			if (input[i].x > input[i + 1].x) {
				Circle buffer = input[i + 1];
				input[i + 1] = input[i];
				input[i] = buffer;
				f = true;
			}
		}
	} while (f);
	for (int i = 0; i < n; i++) {
		input[i].x = -350 + 70 * i;
		input[i].radius = 8 * (i + 1);
	}

}

void drawC(Circle input[], int n) {
	settextstyle(BOLD_FONT, HORIZ_DIR, 3); // 設定字形大小
	for (int i = 0; i < n; i++)
	{
		outtextxy(X(input[i].x), Y(input[i].y), input[i].name);
		setcolor(COLOR(input[i].r, input[i].g, input[i].b));		// 圓的顏色
		circle(X(input[i].x), Y(input[i].y), input[i].radius);	// 畫出圓
	}
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "第三次上機的第 7 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式

	Circle cx[10];// 宣告 cx, 設定 10 個 圓的初始值
	cx[0] = { "1",  -70, 159, 164, 177, 161, 0 };	// "1",  -70, 159, 164, 177, 161, 0,
	cx[1] = { "2",  319, -125, 186, 164, 194, 0 };	// "2",  319, -125, 186, 164, 194, 0,
	cx[2] = { "3",  -89, -182, 166, 170, 147, 0 };	// "3",  -89, -182, 166, 170, 147, 0,
	cx[3] = { "4", -371, 119, 194, 146, 199, 0 };	// "4", -371, 119, 194, 146, 199, 0,
	cx[4] = { "5",   86,  105, 149, 160, 189, 0 };	// "5",   86,  105, 149, 160, 189, 0,
	cx[5] = { "6",  176, -103, 148, 177, 153, 0 };	// "6",  176, -103, 148, 177, 153, 0,
	cx[6] = { "7", -100,  -83, 190, 199, 147, 0 };	// "7", -100,  -83, 190, 199, 147, 0,
	cx[7] = { "8",   32,  -60, 151, 193, 156, 0 };	// "8",   32,  -60, 151, 193, 156, 0,
	cx[8] = { "9",  293,  116, 198, 181, 170, 0 };	// "9",  293,  116, 198, 181, 170, 0,
	cx[9] = { "10", -227, -142, 189, 177, 149, 0 };	//"10", -227, -142, 189, 177, 149, 0 

	bsorting(cx, 10);// 呼叫  bsorting();
	drawC(cx, 10);// 呼叫  drawC();

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif