//  程式設計二，第二次上機考試 ，第 7 題 (2 分) 
// 
// 宣告 CMouse 類別裡面包含
//   公有包含
//      成員變數：座標 x/y，顏色 color (int 型別) 
//      建構元：有三個 int 型別的引數，分別代表 x/y 座標與顏色
//              必須使用引數預設值，設定預設座標與顏色為 0 0 COLOR_WHITE
//		void draw() 函式：題目已經給了，不用寫。
//      函式都可寫在類別宣告內
// 
//   主程式宣告 CMouse 的指標物件 pm，並依照註解完成對應的程式碼，並完成如 p7.jpg 結果
//   
// 要求：
//	1. 必須為 pm 取得 2 個儲存空間，且必須完成正確的釋放寫法
//  2. 所有對於 pm 的使用都必須使用指標
//	3. 依照主程式的註解完成對應的程式碼
//   

#define P
#ifdef P7

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
using namespace std;

// CMouse 類別
class CMouse {
public:
	int ix, iy, icolor;
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) :ix(x), iy(y), icolor(color){}

	void draw() { drawBoxMan(ix, iy, icolor); }
};


int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	// 宣告物件指標變數
	CMouse* pm;
	// 以 new 取得 2 個空間
	pm = new CMouse[2];
	// 設定索引值為 0 的物件座標在 (-100,0);
	pm[0].ix = -100; pm[0].iy = 0;
	// 設定索引值為 0 的物件顏色為 COLOR_YELLOW
	pm[0].icolor = COLOR_YELLOW;
	// 設定索引值為 0 的物件呼叫 draw 畫出自己
	pm[0].draw();
	// 設定索引值為 1 的物件座標在 (100,0);
	pm[1].ix = 100; pm[1].iy = 0;
	// 設定索引值為 1 的物件顏色為 COLOR_GREEN
	pm[1].icolor = COLOR_GREEN;
	// 設定索引值為 1 的物件呼叫 draw 畫出自己
	pm[1].draw();
	// 使用 delete 釋放物件指標變數所取得的 2 個資源
	delete[] pm;
	while (!kbhit()) { delay(200); } return 0;
}

#endif 