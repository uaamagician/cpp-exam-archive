//  程式設計二，第二次上機考試 ，第 3 題 (4 分) 
// 
// 宣告 CMouse 類別裡面包含
//   私有包含(都是 int 型別)
//      座標 x/y，顏色 color, 
//   公有包含
//       靜態變數 si (int 型別)
//       建構元有三個 int 型別的引數，分別代表 x/y 座標與顏色
//             必須使用引數預設值，設定預設座標與顏色為 0 0 COLOR_WHITE
//             si 內容加 1
//       拷貝建構元，在拷貝建構元中，
//				x 座標為複製來源 X 座標 -100
//				y 座標與複製來源相同， 
//				顏色為複製來源的顏色 -3
//				si 內容加 1
//       解構元
//             si 內容減 1  
//       函式都可寫在類別宣告內
//
// 要求：
//		1. 主程式的兩個顯示訊息，必須放在對應的建構元中
//		2. 顯示必須顯示在畫面上(參考 p3.jpg)
//   
   
#define P
#ifdef P3

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"

using namespace std;

// CMouse 類別
class CMouse {
private:
	int _ix, _iy, _icolor;
public:
	static int si;
	
	// 建構元
	// 建構元裡面包含以下四行程式碼，才能在螢幕輸出對應的文字
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE):_ix(x), _iy(y), _icolor(color){
		si++;
		char buf[100];
		setcolor(COLOR_WHITE);
		sprintf(buf, "!建構元!宣告 %3d 個物件", si);
		outtextxy(X(0), Y(200), buf);
	}

	// 拷貝建構元
	// 拷貝建構元裡面包含以下四行程式碼，才能在螢幕輸出對應的文字
	CMouse(const CMouse& mm) {
		this->_ix = mm._ix - 100;
		this->_iy = mm._iy;
		this->_icolor = mm._icolor - 3;
		si++;
		char buf[100];
		setcolor(COLOR_LIGHTRED);
		sprintf(buf, "!拷貝建構元!宣告 %3d 個物件", si);
		outtextxy(X(-200), Y(0), buf);
	}

	void draw() { drawBoxMan(_ix, _iy, _icolor); }

	// 解構元
	~CMouse() {
		si--;
	}
};

int CMouse::si = 0;				// 設定靜態變數初始值為 0

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3");
	CMouse mx(0, 100); // 宣告 mx 物件
	CMouse my(mx);  // 宣告 my 物件其內容來自 mx
	mx.draw();
	my.draw();
	while (!kbhit()) { delay(200); } return 0;
}

#endif