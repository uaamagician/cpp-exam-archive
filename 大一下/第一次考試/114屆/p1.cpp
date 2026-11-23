//  程式設計二，第一次上機考試 ，第 1 題 (3 + 3 分)
//
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容，每個部分都 3 分。
//  -----------  Part 1 ------------ 
// //  宣告一個結構 sCircle，裡面包含成員變數有名稱 name(char:12) 
//                           座標(int) x/y 、顏色(int) r/g/b 與半徑(int) rad
//  主程式以 sCircle 宣告一個結構陣列包含 10 個儲存元素
//  開啟並讀取 circles.txt 的內容，並將圓畫在螢幕上。circles.txt 的資料包含如下
//		第一筆資料為所儲存圓的個數
//		後續則是每一個圓的基本資料包含，名稱、X/Y座標、半徑與顏色
//	
//  要求：滿足以下要求，且執行達成需求才算分數
//      1. 先讀入 circles.txt 第一筆資料
//		2. 讀取所有圓資料的 for 迴圈，其終止條件必須來自於 1 所讀取的圓的個數
//      3.  不可修改 circles.txt 的資料內容，特別是第一筆數值。
//          for 迴圈終止條件必須來自 circles.txt 讀取的第一筆資料
// 
//  輸出參考 p1.jpg 
// 
//  -----------  Part 2 ------------ 
//   再次開啟並讀取 circles.txt 的內容，以字元的方式一個字元一個字元讀入
//	 計算每一個數字 0 到 9 的出現次數，輸出次數為偶數的數字與出現次數
// 
// 參考以下的輸出
//  0 出現 24 次
//  3 出現 10 次
//  6 出現 16 次
//  9 出現 10 次
//
// 你會用到的型別與函式
// FILE 型別
// fopen(,) 開啟檔案  "r" 為讀取檔案
// fclose() 關閉檔案
// feof()   判斷檔案是否已經到檔案尾，() 裡面放檔案指標變數，記得前面要加上 !
// fgetc()  從檔案讀取一個字元，() 裡面放檔案指標變數
// fscanf( ," ", ); 讀取檔案內容

#define P
#ifdef P1

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "functions.h"

// 宣告 sCircle 結構

int main(void)
{
	int i, n;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P1");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式

				// 宣告指向檔案的結構指標

	//------------------------- Part 1 -------------------------
	// 開啟檔案
	FILE* file = fopen("circles.txt", "r");
	if ( file    == NULL) {  // 判斷檔案是否開啟失敗
		printf("circles.txt 檔案無法開啟"); system("pause"); return(0);
	}

	struct Circle {
		char name[12];
		int x, y, r, g, b, rad;
	};				// 宣告一個結構陣列包含 10 個儲存元素
	Circle c[10];
	int times;
	fscanf(file, "%d", &times); // 讀取第一筆資料	
	for (int i = 0; i < times;i++ ) // 讀取 circles.txt 並劃出圓
	{
		fscanf(file, "%s %d %d %d", c[i].name, &c[i].x, &c[i].y, &c[i].rad);
		fscanf(file, "%d %d %d", &c[i].r, &c[i].g, &c[i].b);
		setcolor(COLOR(c[i].r, c[i].g, c[i].b));  // 設定顏色
		outtextxy(X(c[i].x), Y(c[i].y), c[i].name);
		circle(X(c[i].x), Y(c[i].y), c[i].rad);
	}
	// 關閉檔案
	fclose(file);
	//------------------------- Part 2 -------------------------
	char ch=0;
	int count[10] = { 0 };							// 宣告儲存 0 到 9 出現次數的一維陣列
	fopen("circles.txt", "r");						    // 開啟 circles.txt 檔案
	while ((ch =fgetc(file))!= EOF) {	// 判斷是否讀到檔案尾
		if ('0' <= ch && ch <= '9') {
			count[ch - '0']++;
		}
						// 判斷 0 到 9 字元 
	}
	for (i = 0; i < 10; i++) {  // 輸出偶數次數的數字，此行不能改
		if (count[i] % 2 == 0) {
			printf("%c 出現 %d 次\n",i+'0', count[i]);
		}

	}
	fclose(file);	// 關閉檔案

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
#endif