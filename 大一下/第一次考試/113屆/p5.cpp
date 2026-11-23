//  程式設計二，第一次上機考試 ，第 5 題 (6 分)
// 
//  宣告一個包含幾何圖形基本資料的結構 sShape，此結構包含以下資料成員
//      名稱(char:10)、x,y 座標(int), r g b 顏色(int)
//  宣告一個圓基本資訊的結構(sCircle)，圓的基本資料(名稱、座標與顏色)必須
//		來自 sShape 所宣告的成員變數與半徑(int)
//
//  主程式以 sCircle 結構宣告一個結構【指標】變數 cx
//    利用動態記憶體配置 malloc 取得 12 個儲存 sCircle 元素
// 
//    這 12 個圓的中心點座標在以 (0,0) 為中心，半徑 200 的圓上，平均每個 2*PI/12 一個位置
//		 也就是圓的座標為(x, y)，也就是 i = 0 到 11
//			x = 200 * cosf(M_PI * 2 * i / 12.0f); y =  200 * sinf(M_PI * 2 * i / 12.0f);
//	     每一個圓的半徑是 (i+1) 的 10 倍
//       顏色則是 rand() % 155 + 100; 的隨機值
// 提示：你會使用到以下的指令
//        指標變數 = ()malloc();  // 取得空間
//        free(指標變數); // 釋放空間
// 
// 本題需求：
//   1. 一定要宣告 sShape 與 sCircle 結構, sCircle 結構中必須有 sShap e所宣告的成員變數
//   2. 必須使用動態記憶體配置 malloc 來取得 12 個儲存空間
//   3. 必須有兩個迴圈，一個負責建立 12 個圓的基本資料，另外一個負責繪製這 12 個圓
//   4. 必須使用 free 來釋放 malloc 所取得的空間
//  參考 p5.jpg 的輸出結果
//

#define P
#ifdef P5

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// 宣告幾何圖形的 sShape 結構
struct sShape
{
	int x, y, r, g, b;
	char name[10];
};
struct sCirlce {
	sShape info;
	int radius;
};
// 宣告圓的 sCircle 結構


int main()
{
	int i;
	int x, y, r;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第一次上機的第 5 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	
	sCirlce* cx = (sCirlce*)malloc(sizeof(sCirlce) * 12);
	cx = (sCirlce*)malloc(sizeof(sCirlce) * 12);// 以 指標變數 = ()malloc();  為 cx 取得 5 個儲存空間
	for ( i = 0; i < 12; i++)
	{
		sprintf( cx[i].info.name    , "%02d", i+1); // 第一個引數為結構陣列中每一個元素的 name 陣列名稱
		cx[i].info.x = 200 * cosf(M_PI * 2 * i / 12.0f);   // 圓的 X 座標
		cx[i].info.y = 200 * sinf(M_PI * 2 * i / 12.0f);   // 圓的 Y 座標	
		cx[i].radius = 10 * (i + 1);	 	 // 圓的半徑
		cx[i].info.r = rand() % 155 + 100;	 // 產生圓的顏色
		cx[i].info.g = rand() % 155 + 100;
		cx[i].info.b = rand() % 155 + 100;
	}

	for ( i = 0; i < 12; i++)
	{
		setcolor(COLOR( cx[i].info.r   , cx[i].info.g, cx[i].info.b));   // 設定顏色
		outtextxy(X(cx[i].info.x), Y(cx[i].info.y), cx[i].info.name);	// 在圓心輸出名稱
		circle(X(cx[i].info.x), Y(cx[i].info.y), cx[i].radius);	// 畫出該圓
	}

	free(cx);			// 以 free 釋放取得的資源

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif