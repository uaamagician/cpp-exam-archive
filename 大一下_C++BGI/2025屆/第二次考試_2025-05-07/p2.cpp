//  程式設計二，第二次上機考試，第 2 題 (3 分)
//
//	宣告一個結構 sCircle 包含圓的基本資料 
//     中心點(x,y) 半徑(radius)、顏色(cr,cg,cb)與名稱(char:20)
//     除了名稱是一維字元陣列外，其他的都是整數
// 
//   主程式以 sCircle 宣告一個包含 10 個元素的一維陣列
//   開啟並讀取 circles.txt 的內容
//   先以迴圈讀取 10 個圓畫，將資料儲存到一維陣列中
//   再以迴圈將儲存在一維陣列中圓畫出來
//
//   circles.txt 的每一筆資料的存放內容分別是 顏色、半徑、名稱、中心點
//   如 :  238 166 116 60 CC1 -147  -153
//
//  參考 p1.jpg
// 
//   要求：
//		1. 不能變更 circles.txt 內容的放置順序與內容，
//		2. 要以 fclose() 關閉檔案
// 
// 你會用到的函式
// FILE 型別
// fopen(,) 開啟檔案, "r" 為讀取
// fclose() 關閉檔案
// feof()   判斷檔案是否已經到檔案尾
// fscanf() 讀取檔案的內容，格式：fscanf(檔案指標變數, "格式", &讀入的變數名稱....);
//

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "functions.h"

// sCircle 結構的宣告 
struct sCircle
{
	int x, y, r, cr, cg, cb;
	char name[20];
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式

	FILE* pfile;			// 以 FILE 宣告指向檔案的指標變數
	sCircle circles[10];
	if ((pfile = fopen("circles.txt", "r")) == NULL) {  // 以 fopen 開啟檔案，判斷檔案是否開啟失敗
		printf("circles.txt 檔案無法開啟"); system("pause"); return(0);
	}
	
		for (int i = 0; i < 10; i++)
		{
			fscanf(pfile, "%d %d %d", &circles[i].cr, &circles[i].cg, &circles[i].cb);   // 讀取顏色
			fscanf(pfile, "%d %s %d %d", &circles[i].r, circles[i].name, &circles[i].x, &circles[i].y); // 讀取半徑、名稱、x/y 座標

		}
	

				// 以 sCircle 宣告儲存 10 個圓的一維陣列
	// 以 for 迴圈讀取 circles.txt 並將這 10 個圓儲存到一維陣列中
	
		

	// 以迴圈繪製這 10 個圓
	for (int i = 0; i < 10; i++)
	{
		setcolor(COLOR(circles[i].cr, circles[i].cg, circles[i].cb));  // 設定顏色
		outtextxy(X(circles[i].x), Y(circles[i].y), circles[i].name);
		circle(X(circles[i].x), Y(circles[i].y), circles[i].r);
	}
		
	fclose(pfile); 	// 關閉檔案

	while (!kbhit()) { delay(200); } return 0;
}

#endif