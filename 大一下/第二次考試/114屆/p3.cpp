#define P3
#ifdef P3

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include "functions.h"
using namespace std;

class mouse {
private:
	int x, y, color;
	static int cnt;
public:
	mouse(int x=0, int y=0, int color= COLOR_WHITE) : x(x), y(y), color(color) { cnt++; }
	mouse(const mouse& m) {
		this->x = m.x; this->y = m.y; this->color = m.color;
		cnt++;
	}
	~mouse(){ cnt--; }
	void set_color(int color) { this->color = color; }
	void set_Pos(int x,int y) { this->x = x; this->y = y;}
	static int show_cnt() { return cnt; }
	void draw() { drawBoxMan(x, y, color); }
};
int mouse::cnt = 0;
int main() {
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3 靜態變數與指標物件");

	mouse mx(100,100,COLOR_LIGHTRED);	// 宣告 mx 為一般物件
	mouse* p = new(mouse);
	cout <<	mouse::show_cnt()	 << "隻老鼠被建立" << endl;  // 必須使用類別名稱去呼叫 show_cnt 函式
	mx.draw();			// 呼叫 draw 繪製
	delete p;			// 以 delete 釋放 p 所取得的空間
	mouse* k = new(mouse[2]);			// 以 new 取得 2 個空間
	k[1].set_Pos(-100, 0);		// 設定索引值為 1 的物件座標在 (-100,0);
	k[1].set_color(COLOR_YELLOW);      	// 設定索引值為 1 的物件顏色為 COLOR_YELLOW
	k[0].draw();				// 設定索引值為 0 的物件呼叫 draw 畫出自己
	k[1].draw();				// 設定索引值為 1 的物件呼叫 draw 畫出自己
	cout << mouse::show_cnt() << "隻老鼠被建立" << endl;  // 必須使用類別名稱去呼叫 show_cnt 函式
	delete[] k;			// 釋放 pm 取得的空間
	cout << mouse::show_cnt() << "隻老鼠被建立" << endl;  // 必須使用類別名稱去呼叫 show_cnt 函式
	system("pause"); return(0);
}

#endif