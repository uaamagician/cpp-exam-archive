//  程式設計II，第三次上機考試 ，第 5 題 (6 分)
//
//  完成以下三個類別的內容， 
//  CCharacter 類別
//     【被保護的(protected)】成員變數都是(int 型別) x/y 座標與顏色
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_LIGHTGREEN
//        setPos()函式 : 兩個引數，設定 x/y 座標
//        draw() 函式 : 呼叫 drawBoxMan()函式，給座標跟顏色【成員變數名稱可自行修改】
//  CMouse 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//					分別是 0,0, COLOR_LIGHTRED
//				    呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容
//  CRabbit 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_YELLOW
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容
//
//  主程式依照註解的說明，完成指定的程式碼
//	宣告 CCharacter 可以儲存五個元素的一維指標陣列，
//  這五個儲存內容，依照主程式的註解，使用 new 為其取得相對應的物件與初始值
//  單獨畫出 [0] 所指向的第一個儲存內容 (呼叫 draw 函式)
//	搭配迴圈依序的讓 [1] 到 [4] 這四個所指向的物件被畫出來 (呼叫 draw 函式)
//  以 delete 單獨釋放 [0] 所取得的空間，陣列形式
//  搭配迴圈使用 delete 釋放 [1] 到 [4] 的資源
//
//  輸出的結果參考 p5.jpg、記得改寫的 draw 函式必須宣告成虛擬的
//  

#define P
#ifdef P5

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;

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

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P5");
	CCharacter* pc[5];									// 宣告 CCharacter 可以儲存五個元素的一維指標陣列
	pc[0] = new CCharacter[3];							// [0]，指向可以儲存【3 個】 CCharacter 物件的一維陣列
	pc[1] = new CMouse(-150, 0);						// [1]，指向 1 個 CMoouse 物件，宣告物件時給初始值 (-150, 0)
	pc[2] = new CMouse(150, 0, COLOR_GREEN);			// [2]，指向 1 個 CMoouse 物件，宣告物件時給初始值 (150, 0, COLOR_GREEN)
	pc[3] = new CRabbit(0, -150, COLOR_LIGHTCYAN);		// [3]，指向 1 個 CRabbit 物件，宣告物件時給初始值 (0, -150, COLOR_LIGHTCYAN)
	pc[4] = new CRabbit(150, -150, COLOR_BROWN);						// [4]，指向 1 個 CRabbit 物件，宣告物件時給初始值 (150, -150, COLOR_BROWN)
	pc[0][0].draw();						// [0]  所指向的 第 0 個物件，呼叫 draw() 函式
	for (i = 1; i < 5; i++) {	// 搭配迴圈 [i] 所指向物件，呼叫 draw() 函式
		(*pc[i]).draw();
	}
	delete[] pc[0];// 釋放 [0] 所取得的內容，記得是陣列
	for (i = 1; i < 5; i++) { // 搭配迴圈釋放 [i] 所取得的內容
		delete pc[i];
	}
	while (!kbhit()) { delay(200); } return 0;
}

#endif