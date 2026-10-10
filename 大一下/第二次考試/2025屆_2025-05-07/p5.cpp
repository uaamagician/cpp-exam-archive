//  程式設計二，第二次上機考試，第 5 題 (3 分)
// 
// 宣告 CMouse 類別裡面包含
//   私有包含(都是整數型別)
//      座標 x/y與顏色 color ，型別都是 init
//   公有包含
//      三個建構元(使用建構元多載，但都不要使用預設值)：
//		第一個：1 個引數 color，設定顏色，建構元中 x 與 y 設定起始位置 0, 0
//		第二個：2 個引數 x 與 y，設定座標，建構元中 color 設定為 COLOR_YELLOW
//		第三個：3 個引數 x、y與color，設定 x 、 y 與 color
//      draw 函式，呼叫 drawBoxMan(x, y, color); 在 x/y 畫出指定顏色的老鼠
//
// 要求：不能修改主程式的內容，完成 CMouse 類別，並輸出如圖 p5.jpg
//	


#define P
#ifdef P5

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "functions.h"

using namespace std;



class CMouse
{
public:
	CMouse(int _color);
	CMouse(int _x,int _y);
	CMouse(int _s,int _e,int _color1);
	void draw();
private:
	int x, y, color;
};


CMouse::CMouse(int _color)
{
	x = 0;
	y = 0;
	color = _color;
}

CMouse::CMouse(int _x, int _y)
{
	x = _x;
	y = _y;
	color = COLOR_YELLOW;
}
CMouse::CMouse(int _s, int _e, int _color1)
{
	x = _s;
	y = _e;
	color = _color1;
}
void CMouse::draw()
{
	drawBoxMan(x, y, color);

}
int main() {
	initwindow(SCREENWIDTH, SCREENWIDTH, "p5");
	CMouse m1(COLOR_RED);
	CMouse m2(-200, 0); // 建立時同時設定老鼠的起始位置與顏色
	CMouse m3(200, 0, COLOR_LIGHTGREEN);
	m1.draw();
	m2.draw();
	m3.draw();
	while (!kbhit()) { delay(200); } return 0;
}

#endif