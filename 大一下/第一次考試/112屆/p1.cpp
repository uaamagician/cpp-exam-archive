//  程式設計二，第一次上機考試 ，第 1 題 (4 分)
// 
//  宣告一個結構 sShape，裡面包含成員變數有座標(int) x/y 、顏色(int) r/g/b 
//  再宣告結構 sCircle，裡面包含成員變數有基本資料 info (型別是sShape)以及半徑(int) rad
//  在主程式宣告 sCircle 的一維陣列，可以儲存 5 個圓，以及一個結構變數 boss
//  以所提供的亂數搭配一個迴圈產生圓的基本資料，並儲存到此一維陣列中
//  第二個迴圈則是繪製隨機生成的圓，同時計算 boss 結構變數的內容
//      座標是所有圓座標的平均，顏色是所有圓座標的平均，半徑是所有圓座標總和的一半
//
//  要求：滿足以下要求，且執行達成需求才算分數
//      1. 本題是考【巢狀結構】，必須完成指定的兩個結構宣告與對應的成員變數
//      2. 第一個迴圈產生圓的內容，第二個迴圈畫出所儲存圓的內容，並計算 boss 的參數(加總)
//      3. 第二個迴圈離開後再計算 boss 的正確參數
//   
// 提醒各位： boss 的成員變數記得要先全部都設定成 0 
// 
//  參考 p1.jpg 的示 意圖
//

#define P
#ifdef P1

#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"


// 宣告 sShape
struct sShape {
	int x, y;
	int r, g, b;
};
// 宣告 sCircle
struct sCircle {
	sShape info;
	int rad;
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P1");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	sCircle cc[5], boss = {0};				// 宣告結構陣列與結構變數
	
	for ( i = 0; i < 5; i++)			// 產生圓的內容並儲存到結構陣列中
	{
		cc[i].info.x = rand() % 600 - 300; // 座標
		cc[i].info.y = rand() % 600 - 300; // 座標
		cc[i].rad = 50 + rand() % 50;	// 半徑
		cc[i].info.r = rand() % 155 + 100;	// 顏色
		cc[i].info.g = rand() % 155 + 100;	// 顏色
		cc[i].info.b = rand() % 155 + 100;	// 顏色
	}
	



	// 畫出圓並計算 boss 的相關參數
	for ( i = 0; i < 5; i++)
	{
		setcolor(COLOR(cc[i].info.r, cc[i].info.g, cc[i].info.b));  // 設定顏色
		circle(X(cc[i].info.x), Y(cc[i].info.y), cc[i].rad);
		boss.info.x += cc[i].info.x;
		boss.info.y += cc[i].info.y;
		boss.info.r += cc[i].info.r;
		boss.info.g += cc[i].info.g;
		boss.info.b += cc[i].info.b;
		boss.rad += cc[i].rad;
	}
	
	

	// boss 座標是所有圓座標的平均，顏色是所有顏色的平均，半徑是所有圓半徑總和的一半
	
	boss.info.x = (boss.info.x) / 5;
	boss.info.y = (boss.info.y) / 5;
	boss.info.r = (boss.info.r) / 5;
	boss.info.g = (boss.info.g) / 5;
	boss.info.b = (boss.info.b) / 5;
	boss.rad = (boss.rad) / 2;


	setcolor(COLOR(boss.info.r, boss.info.g, boss.info.b));  // 設定顏色
	circle(X(boss.info.x), Y(boss.info.y), boss.rad);

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif