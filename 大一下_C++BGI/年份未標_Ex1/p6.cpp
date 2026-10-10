//  程式設計二，第一次上機考試 ，第 6 題 (4 分)
// 
//  宣告一個結構 sCircle，裡面包含成員變數有名稱 name(char:10) 
//                        座標(int) x/y 、顏色(int) r/g/b 與半徑(int) rad
//  在主程式宣告 sCircle 的一維陣列 cx，大小為 6
// 
//  以傳參照的方式，將 cx 每一個元素傳給 genC 函式，來生成每一個圓的內容
//  以傳陣列的方式，將 cx 陣列傳給 drawC 函式，繪製所有的圓
// 
//  genC  函式: 有 2 個引數，【sCircle 單一變數(傳參照)，int 型別 n, n 為圓的順序】
//  drawC 函式：有 2 個引數，【sCircle 的一維陣列, int 型別 n, n 為圓的個數】
// 
//  要求: 滿足以下要求，且執行達成需求才算分數
//    1. 完成 genC 函式與 drawC 函式的撰寫
//    2. genC 函式與 drawC 函式必須有【原型宣告】寫在 main() 之前
//    3. 傳入 genC 與 drawC 函式的引數必須依照上面中的要求
//
//  參考 p6.jpg
//

#define P
#ifdef P6

#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

//以 struct 宣告 sCircle 結構
struct Circle {
	char name[10];
	int x, y, r, g, b, rad;
};
// genC 與 drawC 函式的原型宣告
void genC(Circle&, int);
void drawC(Circle*, int);

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	Circle cx[6];					// sCircle 宣告一維陣列 cx，大小為 6
	for (int i = 0; i < 6; i++) {  // 此不能更動，
		genC(cx[i],i);				// 呼叫 genC , 第一個引數為傳參照，第一個引數為 i+1
	}
	drawC(cx, 6);					// 呼叫 drawC 函式

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

// genC 函式，第二個引數 num 作為部分圓資料的生成基礎
void genC(Circle& cx,int num) {
	sprintf(cx.name, "%2d",num+1);
	cx.x=-400 + num * 120;		// 產生圓的座標
	cx.y=rand() % 200 - 200;
	cx.rad=num*10 + rand() % 20;		// 產生圓的半徑
	cx.r=rand() % 155 + 100;		// 產生圓的顏色
	cx.g=rand() % 155 + 100;
	cx.b=rand() % 155 + 100;
}



// drawC 函式

void drawC(Circle* cx, int n) {
	int i=0;
	for (i; i < n;i++ )  // 迴圈必須使用到傳入的 n
	{
		setcolor((cx + i)->r | (cx + i)->g << 8 | (cx + i)->b << 16);
		//setcolor(COLOR((cx+i)->r,  (cx+i)->g, (cx+i)->b));  // 設定顏色
		outtextxy(X((cx+i)->x), Y((cx+i)->y), (cx+i)->name);
		circle(X((cx+i)->x), Y((cx+i)->y), (cx+i)-> rad);
	}
}

#endif