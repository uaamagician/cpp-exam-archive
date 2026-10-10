//  程式設計II，第三次上機考試 ，第 6 題 (6 分)
//
//  本題的三個類別與內容同於第五題
//
//	修改所給的 linked list 程式碼，讓它包含五個 node，
//  每一個 node 裡面有一個  CCharacter 的物件指標變數
//	根據以下的要求，將每一個 node 中的物件指標變數，指向一個對應的物件
//	搭配 while 迴圈，在畫面上顯示儲存在 node 中每一個物件
//  搭配 while 迴圈，釋放每一個 node 的資源，包含 CCharacter 的物件指標變數以及 node 本身
//
//	輸出的結果參考 p6.jpg
//

#define P
#ifdef P6
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// 直接複製 p5 的類別內容
// CCharacter 類別
		// 座標與顏色
		// 建構元 0,0, COLOR_LIGHTGREEN
		// setPos()函式
		// draw() { drawBoxMan(_ix, _iy, _icolor); } // 自行修改變數名稱
class CCharacter {
protected:
	int x, y, color;			// 座標與顏色，顏色變數必須是指標變數	
public:
	// 建構元，
	CCharacter(int xx = 0, int yy = 0, int collor = COLOR_LIGHTGREEN) {
		x = xx; y = yy; color = collor;
	}

	virtual void draw() { drawBoxMan(x, y, color); }// 給座標跟顏色

	void setPos(int xx, int yy) { x = xx; y = yy; }
};


// CMouse 類別公有繼承自 CCharacter 類別
class CMouse :public CCharacter {
public:
	// 建構元 0,0, COLOR_LIGHTRED
	CMouse(int xx = 0, int yy = 0, int collor = COLOR_LIGHTRED) :CCharacter(xx, yy, collor) {}
	// draw() 函式
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30); // 頭髮
		drawBoxMan(x, y, color, COLOR_BLUE); // 自行修改變數名稱
	}
};

//  CRabbit 公有繼承自 CCharacter 類別
class CRabbit :public CCharacter {
public:
	// 建構元 0,0,  COLOR_YELLOW
	CRabbit(int xx = 0, int yy = 0, int collor = COLOR_YELLOW) :CCharacter(xx, yy, collor) {}
	// draw() 函式
	void draw() {
		drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
		drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
		drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};

typedef struct tNode {
	CCharacter* pc;				//  CCharacter 的指標變數
	struct tNode* link;
} NODE, * PNODE;

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");

	PNODE pHead, pTail, pGet, pCur;	// 宣告所需要的結構指標變數
	pHead = pTail = NULL;		// 讓指標變數內容為NULL
	pHead = new tNode;					// pHead 指向以 new 取得 1 個 tNode 變數
	pHead->pc = new CCharacter(0, 0, COLOR_WHITE);				// pHead 的指向 CCharacter 物件，宣告物件時給初始值 (0,0, COLOR_WHITE)
	pHead->link = NULL; // 設定 Head 節點的內容
	pTail = pHead;

	// 重複使用以下的程式碼，分別建立另外四個 node，並設定對應所指向的物件如下
	// 第 2 個的指向 CMouse 物件，宣告物件時給初始值 (150,0)
	// 第 3 個的指向 CMouse 物件，宣告物件時給初始值 (-150,0, COLOR_LIGHTCYAN)
	// 第 4 個的指向 CRabbit 物件，宣告物件時給初始值 (-150,100, COLOR_GREEN)
	// 第 5 個的指向 CRabbit 物件，宣告物件時給初始值 (150,100, COLOR_BROWN)



	//-------------------------------------------------------------
	pGet = new tNode;					// pGet 指向以 new 取得 1 個 tNode 變數
	pGet->pc = new CMouse(150, 0);
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;					// pGet 指向以 new 取得 1 個 tNode 變數
	pGet->pc = new CMouse(-150, 0, COLOR_LIGHTCYAN);
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;					// pGet 指向以 new 取得 1 個 tNode 變數
	pGet->pc = new CRabbit(-150, 100, COLOR_GREEN);
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;					// pGet 指向以 new 取得 1 個 tNode 變數
	pGet->pc = new CRabbit(150, 100, COLOR_BROWN);
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結
	//-------------------------------------------------------------

	// 輸出 link list 的內容
	pGet = pHead; 
	while (pGet != NULL) { 
		(*(pGet->pc)).draw();
		pGet = pGet->link;
	}

	// 釋放節點與節點的內容
	pCur = pHead;
	while (pCur != NULL) {
		pCur = pHead->link;
		delete pHead->pc;
		delete pHead;
		pHead = pCur;
	}

	while (!kbhit()) { delay(200); } return 0;
}

#endif