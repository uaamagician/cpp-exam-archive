//  程式設計二，第一次上機考試 ，第 8 題 (5 分)
// 
//  計分方式：建立連結串列並畫出圓 3 分，釋放取得的節點與輸出 2 分
//  宣告一個結構 sCircle，裡面包含成員變數
//		名稱 (char:10) ，x/y 座標(int)、顏色(int) r/g/b 與半徑(int) 
//	宣告 sNode 節點，裡面包含 sCircle 的成員變數與 sNode 結構的指標變數
// 
// 第一個部分：3 分 (參考 p8.jpg)
//  鏈結串列的節點建立同於第 7 題，惟做以下的改變
//  1. 撰寫 genCircle 函式，有 2 個引數，sCircle 指標變數與 int 型別的 n (代表圓的名稱)
//     功能：建立傳入圓的基本資料，參考註解所提供的亂數生成來生成對應的內容
//  2. 撰寫 drawCircle 函式，有 1 個引數為 sCircle 的指標變數，(根據所提供的程式來完成)
// 
//	主程式設定產生5個節點(n = 5)，每一個節點中所儲存的圓，利用 genCircle 函式來建立圓的內容
//  以 while 迴圈來輸出所建立節點的內容，也就是呼叫 drawCircle 函式，傳入 sCircle 的指標變數，
//  drawCircle 函式畫出每一個圓。
// 
// 第二個部分：2 分
//		撰寫 freeNode 函釋，有 1 個引數為 sNode 的指標變數，
//	    功能：釋放所傳入連結串列的每一個節點。
//	          以 while 依序走過每一個節點並輸出所釋放節點的 name，與總共釋放的節點數
//		提示：呼叫端傳入連結串列的 head 節點
// 
// 參考以下的輸出 
// 釋放節點圓的名稱  1
// 釋放節點圓的名稱  2
// 釋放節點圓的名稱  3
// 釋放節點圓的名稱  4
// 釋放節點圓的名稱  5
// 共釋放了 5 個 node
//

#define P8
#ifdef P8

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

struct sCircle
{
	int x, y, r, g, b, radius;
	char name[10];
};// 宣告圓的結構

struct sNode
{
	sCircle cx;
	sNode* link;
};
// 宣告 sNode

// genCircle 函式

void genCircle(sCircle *cx, int n)
{
	
		sprintf(cx->name, "%2d", n); // 第一個引數為結構陣列中每一個元素的 name 陣列名稱
		cx->x = rand() % 600 - 300;		// 產生圓的座標
		cx->y = rand() % 600 - 300;
		cx->radius = 50 + rand() % 50;		// 產生圓的半徑
		cx->r = rand() % 155 + 100;		// 產生圓的顏色
		cx->g = rand() % 155 + 100;
		cx->b = rand() % 155 + 100;
	
}

void drawC(sCircle* cx)
{
	setcolor(COLOR(cx->r, cx->g, cx->b));  // 設定顏色
	outtextxy(X(cx->x), Y(cx->y), cx->name); // 第三個引數為傳入結構的 name 陣列名稱
	circle(X(cx->x), Y(cx->y), cx->radius);
}


int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P8");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	int n = 5;
	int i;
	sNode* head, * tail, * get, * pc;
	get = (sNode*)malloc(sizeof(sNode));
	genCircle(&get->cx,1);					// get 以 malloc 取得節點
	get->link = NULL;
	head = get;
	tail = get;// 呼叫 genCircle 函式產生圓的內容


	// 以下為建立剩下 n - 1 節點的內容
	for (i = 1; i < n; i++) {
		get = (sNode*)malloc(sizeof(sNode));
		genCircle(&get->cx, i+1);				// 呼叫 genCircle 函式產生圓的內容
		get->link = NULL;
		tail->link = get;
		tail = get;

	}
	pc = head;
	// 以下為輸出所建立節點的內容
	 i = 0;
	while ( pc != NULL ) { 

		drawC(&pc->cx);
		pc = pc->link;
		i++;
			// 呼叫 drawCircle 函式

	}
	get = head;
	i = 1;
	while (get!= NULL)
	{
		printf("釋放節點圓的名稱 %d", i);
		get = get->link;
		head = get;
		free(get);
		get = head;
		i++;
	}
	printf("共釋放了%d", i);
	// 呼叫 freeNode 函式釋放所有節點

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
#endif