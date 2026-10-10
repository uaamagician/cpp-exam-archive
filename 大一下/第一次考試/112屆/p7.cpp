//  程式設計二，第一次上機考試 ，第 7 題 (3 分)
// 
//  宣告一個結構 sCircle，裡面包含成員變數有名稱 name(char:10) 
//                        座標(int) x/y 、顏色(int) r/g/b 與半徑(int) rad
//  主程式以 sCircle 宣告一個結構陣列包含 10 個儲存元素
//  開啟並讀取 circles.txt 的內容，並將圓畫在螢幕上。circles.txt 的資料包含如下
//		第一筆資料為所儲存圓的個數
//		後續則是每一個圓的基本資料包含，名稱、X/Y座標、半徑與顏色
//	
//  要求：滿足以下要求，且執行達成需求才算分數
//      1. 必須先讀入 circles.txt 第一筆資料，也就是所儲存圓的個數
//		2. 讀取所有圓資料的 for 迴圈，其終止條件必須來自於 1 所讀取的圓的個數
//      
// 不可修改 circles.txt 的資料內容，特別是第一筆數值。
// 直接在 for 迴圈寫終止條件使用 7 ，本題不予計分
// 
//  參考 p7.jpg 的示 意圖
//  你會用到的型別與函式
//  FILE 型別
//  fopen(,) 開啟檔案
//  fclose() 關閉檔案
//  feof()   判斷檔案是否已經到檔案尾，() 裡面放檔案指標變數，記得前面要加上 !
//  fscanf() 
//

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// 宣告 sCircle
struct sCircle {
	char name[10];
	int x, y, rad;
	int r, g, b;
};

int main()
{
	int i, n;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	FILE* pfile;		// 宣告指向檔案的結構指標
	


	pfile = fopen("circles.txt", "r");			// 開啟 circles.txt 為讀取 "r"
	if (pfile == NULL) {  // 判斷檔案是否開啟失敗
		printf("circles.txt 檔案無法開啟"); system("pause"); return(0);
	}

	sCircle cc[10];		// 宣告一個結構陣列包含 10 個儲存元素
	fscanf(pfile, "%d", &n);						// 讀取第一筆資料
	while (!feof(pfile))			// 讀取 circles.txt 並劃出圓					
	{
		for ( i = 0; i < n; i++)
		{
			fscanf(pfile, "%s", cc[i].name);
			fscanf(pfile, "%d %d %d", &cc[i].x, &cc[i].y, &cc[i].rad);
			fscanf(pfile, "%d %d %d", &cc[i].r, &cc[i].g, &cc[i].b);
		}
	}						
	
	for ( i = 0; i < n; i++)
	{
		setcolor(COLOR(cc[i].r, cc[i].g, cc[i].b));  // 設定顏色
		outtextxy(X(cc[i].x), Y(cc[i].y), cc[i].name);
		circle(X(cc[i].x), Y(cc[i].y), cc[i].rad);
	}


	fclose(pfile);			// 關閉檔案

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif