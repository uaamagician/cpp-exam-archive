//  程式設計II，第三次上機考試 ，第 3 題 (4 分)
//   
// CMouse 類別包含
//		私有包含
//			int 型別的成員變數 x 、 y 與顏色 color
//			bool 型別的變數 btracer
//			CMouse 的【指標變數】 target
//		公有成員函式 
//         建構元：沒有引數，直接設定 x 與 y 為 0, 0，color 為  COLOR_YELLOW
//                 btracer 為 false (預設為【被】追蹤者)
//				   target 為 nullptr
//         setTracer 函式 : 一個 bool 型別的引數，設定 btracer 為傳入的值
//		   setTarget 函式 : 一個 CMouse 型別的【參照】引數，
//							設定 target 為指向該傳入【物件的位址】
//	 	   getPos 函式   : 兩個 int 型別以【傳指標】的形式傳入。
//                         將目前老鼠的位置利用該傳入的變數傳回給呼叫者
//		   updatePos 函式: 透過 target 所指向的被追蹤者，呼叫其 getPos 函式
//						   取得被追蹤者的座標，並設定給【自己】
// 
//         draw  函式    : 根據自己的狀態(追蹤還是被追蹤)呼叫對應的函式畫出自己，
//						   補強所給的程式內容
// 
//		   update 函式   : 直接使用所給的函式內容

// 
//   完成以下的程式碼，並控制四方塊上下左右移動即可，
//					   追蹤者保持在玩家控制方塊的正下方即可
//   

#define P
#ifdef P3

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;
// CMouse 類別
class CMouse {
private:
	int x, y, color;
	bool btracer;		//true 為追蹤者，false 為被追蹤者
	CMouse* target;		// target 為指標變數
public:
	// 建構元
	CMouse() {															// 老鼠的起始位置
		x = 0; y = 0; color = COLOR_YELLOW;								// 預設為【被】追蹤者 btracer 為 false (預設為【被】追蹤者)
		btracer = false;												// target 為 nullptr
		target = nullptr;												// color 為  COLOR_YELLOW
	}
	// getPos 函式
	// setTracer 函式
	// setTarget 函式 // 傳參照 避免物件複製
	// updatePos 函式  // 透過 target 所指向的被追蹤者，呼叫其 getPos 函式 
	void setTracer(bool bb) { btracer = bb; }
	void setTarget(CMouse& mm) { (target) = (&mm); }
	void getPos(int* xx, int* yy) { *xx = x; *yy = y; }
	void updatePos() {
		target->getPos(&(this->x), &(this->y));
	}
	void update(char);

	// draw 函式
	void draw() {
		// draw 函式
		if (btracer) drawBoxMan(x, y - 100, color); // 追蹤者在 Y 軸往下 100 單位的地方
		else drawColorBox(x, y, color);
	}
};




void CMouse::update(char cIn) // update 函式的內容
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y = y + 20; break;
	case 's': // 往下
		y = y - 20; break;
	case 'a': // 往左
		x = x - 20; break;
	case 'd': // 往右
		x = x + 20; break;
	}
}

int main()
{
	char cIn;
	int i = 0;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3");
	CMouse m1, m2;
	m2.setTarget(m1);					// m2 設定追蹤 m1 
	m2.updatePos();					// m2 呼叫 updatePos 更新自己的位置
	m2.setTracer(true);					// m2 設定本身為追蹤者
	while ( i < 10 ) // 移動 10 次程式就會離開迴圈
	{
		cleardevice();
		m1.draw();	// 畫出老鼠
		m2.draw();
		swapbuffers();
		cIn = getch();
		m1.update(cIn);
		m2.updatePos();
		rewind(stdin);
		i++;
	}
	cleardevice();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

#endif