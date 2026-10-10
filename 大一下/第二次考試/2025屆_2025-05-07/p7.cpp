//  程式設計二，第二次上機考試，第 7 題 (4 分)
//
//	宣告一個結構 sCircle 包含圓以下的基本資料：中心點(x,y) 半徑(radius)、顏色(cr,cg,cb)與名稱(char:20)
//  宣告 CCircle 類別，裡面包含 的這些基本資料
//  私有成員變數：
//     sCircle 的結構指標變數、儲存圓個數的 n (int 型別)、
//		       儲存上、下、左、右、四個方向移動次數的變數
//  公有成員函式
//		建構元：設定結構指標變數(nullptr)與其他變數的初始值，
//		解構元：釋放結構指標變數所取得的資源
//      readData 函式：無回傳值，有一個【字元指標變數】的引數
//			功能：讀取所傳入名稱的檔案，
//                第一筆資料為圓的個數，讀入後放在成員變數 n 中
//				  以 new 取得 n 個 sCircle 儲存元素
//				  以 for 迴圈讀取每一個圓的資料，並儲存在所取得的一維陣列中
//                關閉讀取的檔案
//		draw 函式：無回傳值，無引數。功能：以for 迴圈繪製每一個圓
//		move函式：回傳值為 bool，有一個字元型別的引數
//          功能：根據  w s a d 四個鍵，變更所有圓的 x 或 y 座標，
//                w : y 軸正向 50，s : y 軸負向 50。
//				  a : x 軸負向 50，d : x 軸正向 50，
//                滿足w s a d 四個方向【都至少移動一次】時，回傳 true，代表四個方向都有觸發過
//				  否則傳回 false;	
// 
//  主程式
//     以 CCircle 宣告 cx 物件，然後參考主程式中的註解，完成所有的程式碼。
//     繳交時的操作方式：w w a a s s d
// 
//  參考 p7.exe 的執行過程
// 
//   要求：
//		1. 建構元必須設定 sCircle 所宣告結構指標物件變數為 nullptr;
//		2. read 函式必須從 circle7.txt 讀取的第一個代表圓個數的整數到成員變數 n 中
//         並透過 new 取得 n 個 sCircle 儲存圓的一維陣列
//		3. 解構元必須以 delete 釋放所取得的一維陣列
//		4. 程式結束條件必須正確達成
// 
// 你會用到的函式
// FILE 型別
// fopen(,) 開啟檔案
// fclose() 關閉檔案
// feof()   判斷檔案是否已經到檔案尾
// fscanf() 讀取檔案的內容，格式：fscanf(檔案指標變數, "格式", &讀入的變數名稱....);
//

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "functions.h"

// 檔案讀取與圓的繪製相關指令自行複製 p2.cpp
struct sCircle
{
	int x, y, r, cr, cg, cb;
	char name[20];
};

class CCircle
{
public:
	CCircle();
	~CCircle();
	void readData(char *ch);
	void draw();
	bool move(char ch);
private:
	sCircle* ccircle;
	int n =7;
	int ww , ss , aa , dd ;
};

CCircle::CCircle()
{ 
	ccircle = nullptr;
	ww = 0; ss = 0; aa = 0; dd = 0;
}

CCircle::~CCircle()
{
	delete ccircle;
}
void CCircle::readData(char* ch)
{
	FILE* pfile;			// 以 FILE 宣告指向檔案的指標變數
	pfile = fopen(ch, "r");
	
	ccircle = new sCircle[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(pfile, "%d %d %d", &ccircle[i].cr, &ccircle[i].cg, &ccircle[i].cb);   // 讀取顏色
		fscanf(pfile, "%d %s %d %d", &ccircle[i].r, ccircle[i].name, &ccircle[i].x, &ccircle[i].y); // 讀取半徑、名稱、x/y 座標
	}
	fclose(pfile);
}
void CCircle::draw()
{
	for (int i = 0; i < n; i++)
	{
		setcolor(COLOR(ccircle[i].cr, ccircle[i].cg, ccircle[i].cb));  // 設定顏色
		outtextxy(X(ccircle[i].x), Y(ccircle[i].y), ccircle[i].name);
		circle(X(ccircle[i].x), Y(ccircle[i].y), ccircle[i].r);
	}
}
bool CCircle::move(char ch)
{
	
		switch (ch)
		{
		case 'w':
			for (int i = 0; i < 7; i++)
			{
				ccircle[i].y = ccircle[i].y + 50;
			}
			
			ww++;
			break;
		case 'a':
			for (int i = 0; i < 7; i++)
			{
				ccircle[i].x = ccircle[i].x -50;
			}
			aa++;
			break;
		case 's':
			for (int i = 0; i < 7; i++)
			{
				ccircle[i].y = ccircle[i].y - 50;
			}
			ss++;
			break;
		case 'd':
			for (int i = 0; i < 7; i++)
			{
				ccircle[i].x = ccircle[i].x + 50;
			}

			dd++; break;
			
		}
		if (ww = 1 && aa >= 1 && ss >= 1 && dd >= 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	
	
}
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式



	char ch;
	bool bt =false;
	CCircle cx;							// 以 CCircle 宣告物件
	cx.readData("circle7.txt");					// 呼叫 readData 函釋，並以 "circle7.txt" 為引數
							// 設定 while 迴圈是否停止的變數內容為 false
	while (	bt==false				) {	// 判斷是否停止
		cleardevice();
		cx.draw();						// 呼叫 draw 畫出所有的圓
		swapbuffers();
		ch = getch();			// 取得使用者的輸入
		bt = cx.move(ch);						// 呼叫 move 並傳入輸入的字元，同時取得回傳值，作為 while 迴圈是否停止的依據
		rewind(stdin);			// 清除輸入緩衝區
	}
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "w s a d 四個方向都有移動過一次，按任意鍵結束!!");
	swapbuffers();
	while (!kbhit()) { 	delay(200); } return 0;
}

#endif