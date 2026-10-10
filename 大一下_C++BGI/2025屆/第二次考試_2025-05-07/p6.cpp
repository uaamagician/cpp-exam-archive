//  程式設計二，第二次上機考試，第 6 題 (4 分)
//
//  設計一個 CPeriodicTimer 類別，功能是每隔固定間隔發出週期的訊息。
//  CPeriodicTimer 包含以下成員
//  私有成員
//    char _msg[80]; // 觸發時要顯示的文字
//    自行規劃已達成所需要的顯示功能，同時參考公有成員函式的功能
//    
//  公有成員函式
//    CPeriodicTimer(): 建構元，設定相關變數的初始值
//    setInterval(int sec): 設定幾秒後進入觸發訊息的顯示
//    setMessage(char* msg): 設定觸發訊息的顯示內容
//    setFreq(int sec, int n):  設定觸發訊息的顯示秒數與次數(n)
//    tick(): 每次呼叫就累積秒數，裡面同時處理一般計時與觸發訊息計時
//			  可利用這函式提供回傳值 true 與 false 來辨識一般計時與觸發訊息計時
//    draw():顯示一般計時與觸發訊息
// 
// 參考主程式的執行流程與註解，完成所需要執行功能
// 可執行 p6.exe 了解執行的過程，呈現功能：
// 1. 設定每 3 秒產生一次觸發訊息(第四秒切換到觸發訊息的顯示)
// 2. 設定觸發訊息顯示 3 秒，第四秒後切換回到重新計時(也就是回到 1 的功能)
// 3. 在顯示兩次【觸發訊息】後，停止所有計時，結束程式
// 

#define P
#ifdef P6
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cstring>

#include "functions.h"

// CPeriodicTimer 類別

// CPeriodicTimer();
// setInterval(int sec);
// setMessage(char *msg);
// setFreq(int sec, int n);
// tick();		
// draw();



		//setcolor(COLOR_WHITE);  // 一般計時顯示
		//sprintf(strbuf, "%d秒/%d秒觸發一次",_count, _interval);  
		//settextstyle(0, HORIZ_DIR, 3);
		//outtextxy(X(-200), Y(0), strbuf);

		//setcolor(COLOR_LIGHTGREEN);  // 觸發訊息顯示
		//sprintf(strbuf, "觸發訊息, %d 秒共觸發 %d 次", _tick, _msgOnCnt); 
		//settextstyle(0, HORIZ_DIR, 2);
		//outtextxy(X(-250), Y(0), strbuf);


int main(void)
{
	bool toEnd = false;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");
							// 以 CPeriodicTimer 宣告物件
							// 設定每 3 秒觸發一次
							// 設定觸發時顯示的訊息
							// 設定觸發訊息的顯示 3 秒數與觸發訊息顯示為 2 次
	while (        ) {
		cleardevice();
		Sleep(998);				// 暫停 0.998 秒
								// 呼叫 tick 進行計時，
								// 呼叫 draw函式 顯示一般計時與觸發訊息
		swapbuffers();
	}
	setcolor(COLOR_LIGHTRED);
	outtextxy(X(-100), Y(-100), "計時結束");
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

#endif