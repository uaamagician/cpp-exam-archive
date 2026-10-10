//  程式設計II，第三次上機考試 ，第 4 題 (5 分)
//
// 繼承子類別呼叫父類別的拷貝建構元
//
//  完成以下兩個類別的內容， 
//  CCharacter 類別
//     【被保護的(protected)】成員變數 x/y 座標(int 型別)，與顏色 (int 型別的【指標變數】)
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_WHITE
//                 記得要【為顏色取的空間】，並設定變數的內容
//		  拷貝建構元 
//        解構元：釋放 顏色 所取得的空間
//        draw() 函式 : 呼叫 drawBoxMan()函式，給座標跟顏色
//        setPos()函式 : 兩個引數，設定 x/y 座標
// 
//  CMouse 類別公有繼承自 CCharacter 類別 
//     私有的成員變數儲存【攻擊力】，int 型別
//     公有的成員函式
//        建構元 : 有四個引數，x/y 座標、顏色與攻擊力，
//                 其中 x/y 座標與顏色，不能給引數預設值，攻擊力必須給預設值 10
//                 指定呼叫 CCharacter 類別的建構元
//		  拷貝建構元 : 【指定呼叫】 CCharacter 的拷貝建構元
//		  showAttack() 函式：(已經給了)
//
//   讓主程式能正常執行，並顯示如圖 p4.jpg 的結果【三個顏色要一樣喔】
//	 且結束時不會出現錯誤訊息
//

#define P
#ifdef P4
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

// CCharacter 類別
class CCharacter {
protected:
	int x, y;			// 座標與顏色，顏色變數必須是指標變數
	int* pcolor;
public:
	// 建構元，
	CCharacter(int xx = 0, int yy = 0, int collor = COLOR_WHITE) {
		x = xx; y = yy;
		pcolor = new int;
		*pcolor = collor;
	}
	// 拷貝建構元	
		// 設定老鼠的起始位置
		// 取得空間與設定圖示
	CCharacter(const CCharacter& ccc) {
		this->x = ccc.x;
		this->y = ccc.y;
		this->pcolor = new int;
		*(this->pcolor) = *(ccc.pcolor);
	}
	// 解構元
	virtual ~CCharacter() {
		delete pcolor;
	}
	void draw() { drawBoxMan(x, y, *pcolor); }// 給座標跟顏色
		
	void setPos(int xx, int yy) { x = xx; y = yy; }// 函式
};

// CMouse 公有(public)繼承自 CCharacter 類別
class CMouse: public CCharacter {
private:
	// 設定攻擊力
	int atk;
public:
	// CMouse 建構元，攻擊力預設為 10，記得往上呼叫  CCharacter 建構元，並給予對應的引數
	CMouse(int xx, int yy, int collor, int attk = 10) :CCharacter(xx, yy, collor) {
		atk = attk;
	}
	// CMouse 拷貝建構元，記得呼叫 CCharacter 拷貝建構元
	CMouse(const CMouse& mm):CCharacter(mm) {
		this->atk = mm.atk;
	}
	void showAttack() {
		char str[80];
		sprintf(str, "攻擊力=%2d", atk);  // 空格填上所宣告的攻擊力的變數名稱
		settextstyle(3, 0, 24);
		setcolor(COLOR_WHITE);
		outtextxy(X(x + 80), Y(y), str);
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P4");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0, 120); my.draw(); my.showAttack();
	mz.setPos(0, -120); mz.draw(); mz.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}

#endif