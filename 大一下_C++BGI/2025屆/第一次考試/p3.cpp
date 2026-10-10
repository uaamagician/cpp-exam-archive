//  程式設計二，第一次上機考試 ，第 3 題 (3 分)
// 
//  宣告一個包含圓基本資訊的結構(名稱自取)
//     該結構內包含：名稱(char:10)、x,y 座標(int), r g b 顏色(int)、半徑(int)、距離(float)
//
//  主程式內以該結構宣告一個結構變數 cx，並設定初始值為 "ABC", -50, 100, 200, 150, 100, 300 
//  然後輸入該圓的，名稱、座標、顏色與半徑
//  在螢幕上畫出該圓的，並在圓中心輸出該圓的名稱
//  計算該圓到原點(0,0)距離，並儲存在結構變數原點距離這個成員變數內
//  輸出該距離在圓心的下方
// 
//  參考 p3.jpg 的輸出結果
//

#define P
#ifdef P3 

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// 宣告圓的結構
struct sCircle
{
	char name[10];
	int x, y, r, g, b, radius;
	float distance;
};

int main()
{
	int i;
	int x, y, r;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第一次上機的第 3 題");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	char buf[20] = "";
	
	struct sCircle cx = {"ABC" , -50, 100, 200, 150, 100, 300 };
	

	// 宣告結構變數 cx，並設定初始值為 "ABC", -50, 100, 200, 150, 100, 300 

	setcolor(COLOR( cx.r,cx.g   ,cx.b  ));   // 設定顏色
	outtextxy(X(cx.x ), Y(cx.y ),cx.name  );	// 在圓心輸出名稱
	circle(X(cx.x ), Y(cx.y ), cx.radius );	// 畫出該圓

	cx.distance = sqrtf(((cx.x * cx.x) + (cx.y * cx.y)));// 圓心(x,y) 到 (0,0) 的距離 sqrtf(x*x+y*y);
	// 將距離指定給 cx 中儲存距離的 float 變數
							
	sprintf(buf, "%8.3f",cx.distance );	// 給 cx 中儲存距離的變數
	outtextxy(X( cx.x  ), Y( cx.y  -20), buf);	// 在圓心下方 -20 位置輸出距離

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif