//  程式設計II，第三次上機考試 ，第 6 題 (5 分)
//
//  完成以下三個類別 
//  CCharacter 類別
//     【被保護的(protected)】成員變數都是(int 型別) x/y 座標與顏色
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_LIGHTGREEN
//		  解構元 : 輸出訊息
//        setPos()函式 : 兩個引數，設定 x/y 座標
//        draw() 函式 : 呼叫 drawBoxMan()函式，給座標跟顏色【成員變數名稱可自行修改】
//  CMouse 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//					分別是 0,0, COLOR_LIGHTRED
//				    呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//		  解構元 : 輸出訊息
//        draw() 函式 : 直接使用給的呼叫內容
//  CRabbit 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_YELLOW
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//		  解構元 : 輸出訊息 
//        draw() 函式 : 直接使用給的呼叫內容
// 主程式
//      使用 tNode 結構建立 linked list，依序儲存 5 個物件：
//           CCharacter、CMouse、CMouse、CRabbit、CRabbit
//      使用 while 迴圈呼叫各 node 中物件的 draw()，畫出所有物件
//      使用 while 迴圈釋放 linked list 所有節點及各節點指向的物件資源
//
//
//  輸出的結果參考 p6.jpg
//  資源釋放必須如圖 p6.jpg 所顯示才計分
//

#define P
#ifdef P6
#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "functions.h"
int py = 400;
class CCharacter
{
public:
	CCharacter(int ix =0,int iy =0,int icolor=COLOR_GREEN):x(ix),y(iy),color(icolor) {}
	virtual ~CCharacter() {
		{
			settextstyle(4, 0, 12);
			setcolor(COLOR_YELLOW);
			outtextxy(X(-400), Y((py -= 20)), "CCharacter 解構元被呼叫");
		}
	}
	void setPos(int ix, int iy) { x = ix, y = iy; }
	virtual void draw() { drawBoxMan (x, y, color); }

protected:
	int x, y ,color;
};


//  CCharacter 類別
//     【被保護的(protected)】成員變數都是(int 型別) x/y 座標與顏色
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_LIGHTGREEN
//		  解構元 : 輸出訊息
//        setPos()函式 : 兩個引數，設定 x/y 座標
//        draw() 函式 : 呼叫 drawBoxMan()函式，給座標跟顏色【成員變數名稱可自行修改】

		 
	
	// 虛擬解構元
	
class CMouse:public CCharacter
{
public:
	CMouse(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTRED):CCharacter(ix,iy,icolor) {}
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30); // 頭髮
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
	~CMouse() {
		settextstyle(4, 0, 12);
		setcolor(COLOR_LIGHTRED);
		outtextxy(X(-400), Y((py -= 20)), "CMouse 解構元被呼叫");
	}
private:

};

class CRabbit :public CCharacter
{
public:
	CRabbit(int ix = 0, int iy = 0, int icolor = COLOR_YELLOW) :CCharacter(ix, iy, icolor) {}
	void draw() {
		drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
		drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
		drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
	~CRabbit() {
		settextstyle(4, 0, 12);
		setcolor(COLOR_LIGHTGREEN);
		outtextxy(X(-400), Y((py -= 20)), "CRabbit 解構元被呼叫");
	}


};
//  CMouse 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//					分別是 0,0, COLOR_LIGHTRED
//				    呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//  draw() 函式 : 直接使用給的呼叫內容
	
// 解構元
	
//  CRabbit 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_YELLOW
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容
	
//	 解構元 : 輸出訊息 
	


typedef struct tNode {
	CCharacter* pc;				//  CCharacter 的指標變數
	struct tNode* link;
} NODE, * PNODE;

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");

	PNODE pHead, pTail, pGet, pCur;	// 宣告所需要的結構指標變數
	pHead = pTail = NULL;		// 讓指標變數內容為NULL
	pHead = new tNode;
	pHead->pc = new CCharacter(0, 0, COLOR_WHITE);				// pHead 的指向 CCharacter 物件，宣告物件時給初始值 (0,0, COLOR_WHITE)
	pHead->link = NULL; // 設定 Head 節點的內容
	pTail = pHead;

	// 重複使用以下的程式碼，分別建立另外四個 node，並設定對應所指向的物件如下
	// 第 2 個的指向 CMouse 物件，宣告物件時給初始值 (150,0)
	// 第 3 個的指向 CMouse 物件，宣告物件時給初始值 (-150,0, COLOR_LIGHTCYAN)
	// 第 4 個的指向 CRabbit 物件，宣告物件時給初始值 (-150,100, COLOR_GREEN)
	// 第 5 個的指向 CRabbit 物件，宣告物件時給初始值 (150,100, COLOR_BROWN)

	//-------------------------------------------------------------
	pGet = new tNode;
	pGet->pc = new CMouse(150, 0);			// 
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;
	pGet->pc = new CMouse(-150, 0, COLOR_LIGHTCYAN);			// 
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;
	pGet->pc = new CRabbit(-150, 100, COLOR_GREEN);			// 
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結

	pGet = new tNode;
	pGet->pc = new CRabbit(150, 100, COLOR_BROWN);			// 
	pGet->link = NULL;	// 設定目前取得節點的內容
	pTail->link = pGet;
	pTail = pGet;	// 建立節點間的鏈結



	//-------------------------------------------------------------
	pGet = pHead; 
	while (pGet != NULL) {	// 輸出 link list 的內容
		pGet->pc->draw();					// 呼叫 draw() 畫出圖形
		pGet = pGet->link;
	}

	
	while (pHead != NULL) {
		pCur = pHead;
		pHead = pHead->link;
		delete pCur->pc;						// 釋放 CCharacter 指標變數所取得資源
		delete pCur;				// 釋放目前的節點
		
	}

	while (!kbhit()) { delay(200); } return 0;
}

#endif