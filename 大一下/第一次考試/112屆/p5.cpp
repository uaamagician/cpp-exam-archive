//  程式設計二，第一次上機考試 ，第 5 題 (4 分)
// 
//  宣告一個結構 sCircle，裡面包含成員變數有座標(int) x/y 、顏色(int) r/g/b 與半徑(int) rad
//  在主程式宣告 sCircle 的指標變數(pc)，並利用動態記憶體配置為其取得 5 個儲存空間
//  利用所提供的亂數公式，產生這五個圓的座標、顏色與半徑，並將其畫在螢幕上
//  最後釋放配置的記憶體  (提示 : free)
//
//  要求: pc 的所有使用都必須指標的型式，否則本題不予計分
//
//  參考以下的輸出
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

// 宣告 sCircle
struct sCircle {
	int x, y, rad;
	int r, g, b;
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P5");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	int i;
	sCircle* pc;			// 宣告 sCircle 的結構指標變數
	pc = (sCircle*)malloc(sizeof(sCircle) * 5);		// 取得 5 個 sCircle 型別的儲存空間
	
	for ( i = 0; i < 5; i++)
	{
		(pc+i)->x = rand() % 600 - 300;	// 座標
		(pc+i)->y = rand() % 600 - 300;	// 座標
		(pc+i)->r = rand() % 155 + 100;	// 顏色
		(pc+i)->g = rand() % 155 + 100;	// 顏色
		(pc+i)->b = rand() % 155 + 100;	// 顏色
		(pc+i)->rad = rand() % 100 + 50;	// 半徑
	}
			
	
	// 以 for 迴圈畫出圓
	for ( i = 0; i < 5; i++)
	{
		setcolor(COLOR(pc[i].r, pc[i].g, pc[i].b));
		circle(X(pc[i].x), Y(pc[i].y), pc[i].rad);
	}
		
	
	// 釋放配置的記憶體
	free(pc);

	system("pause"); return(0);
}

#endif

