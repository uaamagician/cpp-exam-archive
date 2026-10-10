//  程式設計二，第二次上機考試，第 1 題 (6+1+2分)
// 
// 宣告 CMouse 類別裡面包含
//   私有包含(都是整數型別)
//      座標 x/y，顏色 color , 狀態 status;  1:正常狀態, 2:在邊界上, 0: 死亡
//      上面三個都是 int 型別
//   公有包含
//      建構元：設定位置在 (0,0), 狀態為 正常狀態，顏色為 NORMAL_COLOR
//      getStatus 函式，傳回目前老鼠的狀態
//      draw 函式，呼叫 drawColorBox(x, y, color); 在 x/y 畫出指定顏色的老鼠
//      update() 函式，只有一個引數，型別為 char，
//                     回傳值為目前老鼠移動後的狀態
//          功能是依照輸入的 w、a、s、d 四個按鍵，讓老鼠上下左右個移動 20 個單位
//          同時判斷 老鼠是否在 X/Y 正負 200 的範圍內(不含)
//				狀態設定成 正常狀態 顏色為 NORMAL_COLOR
//			剛好在 X/Y 正負 200 的位置上
//				狀態設定成 在邊界上 顏色為 DANGER_COLOR
//			超出 X/Y 正負 200 的範圍外  狀態設定成死亡
//      init() 函式：沒有引數，回傳值為老鼠的狀態，型別 init。
// 
// 根據主程式的需求，完成可利用鍵盤 w、a、s、d 四個按鍵，控制老鼠的移動，走到邊界改變顏色，移除並顯示死亡
// 
// 要求:
// 計分方式與要求：
//   1. 6分： 所有成員函式都必須寫在類別外，且程式正常執行並完成指定的功能才計分。
//   2. 1分： 以【迴圈方式】讓遊戲可以進行兩次。
//   3. 2分： 將 CMouse 類別拆解成 CMouse.h 與 CMouse.cpp，且主程式不能含有 CMouse 類別的程式碼
//			  只能透過 #include "CMouse.h"與主程式來完成對應功能。
//   2 與 3 的計分必須在1 完成下才計分
// 
// 善意提醒 : 
//   1. 【不要】在成員函式內又再次宣告成員變數了
//  

#define P
#ifdef P1

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#include "Header.h"


#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

// CMouse 類別



int main()
{
	int k = 1;
	char cIn, strbuf[80];
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P1");
	CMouse mx[2];				// 宣告 mx 建立時就會自動呼叫 CMouse 建構
	
	for (int i = 0; i < 2; i++)
	{
		status = mx[i].getstatus();
		while (status != 0) { // 老鼠還活者,可繼續操作
			cleardevice();
			drawFence();	// 畫出範圍
			mx[i].draw();				// 畫出老鼠
			swapbuffers();
			cIn = getch();	// 取得使用者的輸入
			status = mx[i].update(cIn);				// 讓老鼠自己更新狀態，並接收傳回的老鼠狀態
			rewind(stdin);	// 清除輸入緩衝區
		}
		cleardevice();
		drawFence();
		setcolor(COLOR_WHITE);
		sprintf(strbuf, "第 %02d 次遊戲結束，按任意鍵結束!!", i+1);
		outtextxy(X(-100), Y(0), strbuf);
		swapbuffers();
		while (!kbhit()) { delay(200); }
	}
		
	
	


	//while (!kbhit()) { delay(200); } return 0;
}




#endif