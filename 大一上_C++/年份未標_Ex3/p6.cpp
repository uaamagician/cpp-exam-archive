// 程式設計一，第三次上機考試第 6 題 (4 分)
// 
//  完成以下的宣告與函式，並繪出 p6.jpg 的內容
//
//  1. 宣告全域一維陣列 A (int 型別)與 B(float 型別)，大小都是 6， 
//	   A 儲存圓周上生成六個頂點的角度，初始值為 0, 45, 100, 155, 210, 280
//     B 儲存在[目前圓周]上所生成六個小圓相對於[目前圓半徑]的縮小值，
//       初始值為 0.2f, 0.5f, 0.3f, 0.4f, 0.65f, 0.15f
//
//  2. fractal 為遞迴函式，有四個引數分別是目前圓的半徑 r、圓心 x 與 y , 
//	   以及圓周上生成六個小圓角度的位移角度，沒有回傳值
//	   功能如下:
//	   1). 以傳入的半徑與圓心座標繪製一個圓
//     2). 當傳入的半徑超過(等於) 20 時，在圓周上繪製六個小圓
//        (也就是說:當傳入半徑小於 20，就停止繪製六個小圓 - 遞迴的終止條件)
// 
//     3). 六個(使用 for)小圓的繪製規則為:
//		  a) 圓心在目前的圓周上，生成的位置以陣列 A 所儲存的角度加上傳入的位移角度
//           小圓心的座標 x = r*cosf(), y = r*sinf(); 
//			 () 用 Angle_Rad(X), X 為傳入 A 所儲存每一個圓的生成角度加上傳入的位移角度
//			 [重要提示] : 此處所生成的圓心，必須加上基礎圓的圓心才是畫面上的[絕對座標]
//		  b) 圓心的半徑為目前圓的半徑乘上 B 陣列中的縮小值
//        c) 呼叫 fractal 繪製每一個小圓，其中引數為
//				  此處所生成的半徑、座標、以及傳入位移角度加上45
// 
//  3. 宣告一個全域變數用於設定繪製圓的顏色, 內容循序從 1 到 15、1 到 15...循環
// 
//	4. 主程式呼叫 fractal(200, 0, 0, 0); 繪製出 p6.jpg 的結果
// 
//  [重要提示] : 撰寫時依照 fractal 功能，逐步完成指定子功能，可一次完成一個子功能執行看一下結果
// 
#define us
#ifdef use
#define _CRT_SECURE_NO_WARNINGS
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

#define M_PI 3.1415926f
#define Angle_Rad(X) (X)*(M_PI / 180.0) // 度 -> 弧度

int A[6] = { 0, 45, 100, 155, 210, 280 };// A 陣列：圓周上的 6 個角度位置（度數） 0, 45, 100, 155, 210, 280

float B[6] = { 0.2f, 0.5f, 0.3f, 0.4f, 0.65f, 0.15f };// B 陣列：6 個子圓半徑縮小比例 0.2f, 0.5f, 0.3f, 0.4f, 0.65f, 0.15f

int color = 1;			// 全域變數用於設定繪製圓的顏色, 內容循序從 1 到 15、1 到 15...循環


void fractal(int r, int x, int y, int angle, int count) {
	if (r >= 20) {
		count = count + 7 > 15 ? 1 : count;
		int cx, cr, cy;
		for (int i = 0; i < 6; i++) {
			cr = r * B[i];
			cx = X(x + r * cosf(Angle_Rad(A[i] + angle)));
			cy = Y(y + r * sinf(Angle_Rad(A[i] + angle)));
			setcolor(count + 7);
			circle(cx, cy, cr);
			fractal(cr, cx - 400, 400 - cy, angle + 45, count + 3);
		}

	}
	else return;
}
/*
1.draw a circle
2.when r< 20 return
3.child cricle  -> x = r*cosf(), y = r*sinf(); (all cordination should add father's cordination)
4.
*/




int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "第三次上機的第 6 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	setbkcolor(BLACK);
	cleardevice();

	fractal(200, 0, 0, 0, 0); // 此行不要修改

	setcolor(7);
	circle(X(0), Y(0), 200);
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
#endif
