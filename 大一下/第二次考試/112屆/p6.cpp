//  程式設計二，第二次上機考試 ，第 6 題 (4 分)
// 
//  宣告 CMouse 類別，裡面包含
//   私有成員變數(變數名稱可自行更換)
//     老鼠座標 _x, _y (float 型別)
//     老鼠顏色 _pcol (int 指標型別)
//   公有成員函式 
//		draw 函式 (已經寫好直接使用)
//	 	建構元
//         設定座標 x, y 的預設值為 0, 0 ，預設顏色為 COLOR_WHITE (記得取得空間，並設定其內容)   
//	 	解構元
//			釋放建構元取得的空間
//	 	拷貝建構元 
//      = 運算子
// 
// 要求：
// 1. 不改動主程式下，完成類別的所有內容，同時輸出如結果如圖 p6.jpg
// 2. 程式結束時，不能出現錯誤才有分數
//

#define P
#ifdef P6

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;

// CMouse 類別
class CMouse {
private:
	float _fx, _fy;
	int* _pcolor;
public:
	CMouse(float x = 0, float y = 0, int color = COLOR_WHITE) {
		_fx = x; _fy = y;
		_pcolor = new int;
		*_pcolor = color;
	}
	~CMouse() {
		if (_pcolor != nullptr) delete _pcolor;
	}
	CMouse(const CMouse& mm) {
		this->_fx = mm._fx;
		this->_fy = mm._fy;
		this->_pcolor = new int;
		*(this->_pcolor) = *(mm._pcolor);
	}
	
	CMouse operator=(const CMouse& mm) {
		this->_fx = mm._fx;
		this->_fy = mm._fy;
		*(this->_pcolor) = *(mm._pcolor);
		return(*this);
	}
	void draw();
};


void CMouse::draw() { drawBoxMan((int)_fx, (int)_fy, *_pcolor); } // 這邊要自己補上第三個引數 顏色


int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");
	CMouse m1(0,0);	
	CMouse m2(-200, 0, COLOR_RED);	
	CMouse m3(200, 0, COLOR_RED);	
	CMouse m4(m1), m5;
	m3.draw();
	m4.draw();
	m5 = m1 = m2;
	m5.draw();
	system("pause"); return(0);
}

#endif