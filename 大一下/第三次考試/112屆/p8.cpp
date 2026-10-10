//  程式設計II，第三次上機考試 ，第 8 題 (3 分)
//
//  完成以下三個類別的內容， 
//  CCharacter 類別
//     【被保護的(protected)】int 型別的成員變數 x/y 座標與顏色
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//			       分別是 0,0, COLOR_LIGHTGREEN
//		  解構元 ：使用已經給的輸出
//        draw() 函式 : 宣告成【純虛擬函式】
//  CMouse 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_LIGHTRED
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容
//		  解構元：使用已經給的輸出
//  CRabbit 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_YELLOW
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容
//		  解構元：使用已經給的輸出 
//
//	主程式依照註解的說明，完成指定的程式碼
// 
// 圖形與解構元的輸出必須與 p8.jpg 相符
//

#define P8
#ifdef P8
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;

class CCharacter {
protected:
	int x, y, color;			// 座標與顏色，顏色變數必須是指標變數	
public:
	// 建構元，
	CCharacter(int xx = 0, int yy = 0, int collor = COLOR_LIGHTGREEN) {
		x = xx; y = yy; color = collor;
	}
	virtual ~CCharacter() { cout << "CCharacter 解構元被呼叫" << endl; }
	virtual void draw() { drawBoxMan(x, y, color); }// 給座標跟顏色


};


// CMouse 類別公有繼承自 CCharacter 類別
class CMouse :public CCharacter {
public:
	// 建構元 0,0, COLOR_LIGHTRED
	CMouse(int xx = 0, int yy = 0, int collor = COLOR_LIGHTRED) :CCharacter(xx, yy, collor) {}
	~CMouse() { cout << "CMouse 解構元被呼叫" << endl; }
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
	~CRabbit(){ cout << "CRabbit 解構元被呼叫" << endl; }
	// draw() 函式
	void draw() {
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
};
// CCharacter 類別
		// 座標與顏色
		// 建構元 0,0, COLOR_LIGHTGREEN
		// 解構元 { cout << "CCharacter 解構元被呼叫" << endl; }
		// draw() , 宣告成純虛擬函式


// CMouse 類別公有繼承自 CCharacter 類別
		// 建構元 0,0, COLOR_LIGHTRED
		// 解構元 { cout << "CMouse 解構元被呼叫" << endl; }
		// draw() 函式



//  CRabbit 公有繼承自 CCharacter 類別
		// 建構元 0,0, COLOR_YELLOW
		// 解構元 { cout << "CRabbit 解構元被呼叫" << endl; }
		// draw() 函式
			

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P8");
	CCharacter* pc2m = new CMouse(150, 0);						// 宣告 CCharacter 指標變數 pc2m，並以 new 取得 CMouse 物件，初始值為  (150,0)
	CCharacter* pc2r = new CRabbit(-150, 0);						// 宣告 CCharacter 指標變數 pc2r，並以 new 取得 CRabbit 物件，初始值為 (-150,0)
	CMouse* pm = new CMouse;							// 宣告 CMouse 指標變數 pm ，並以 new 取得 CMouse 物件	，不用給初始值
							// pc2m 呼叫 draw 函式
							// pc2r 呼叫 draw 函式
							// pm 呼叫 draw 函式
							// 以 delete 釋放 pc2m 所取得的資源
							// 以 delete 釋放 pc2r 所取得的資源
							// 以 delete 釋放 pm 所取得的資源
	while (!kbhit()) { delay(200); } return 0;
}

#endif