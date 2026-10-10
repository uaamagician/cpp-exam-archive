// 程式設計二，第二次考試，題目 8 (4 分)
//
// 設計一個 CTimer 類別，
//		setTime  設定目前的時間，包含時、分、秒，
// 		setAlarm 設定鬧鈴的時間，包含時、分、秒，
// 儲存兩個時間的時分秒的變數必須是私有變數。
// tick 函式每被呼叫一次，就自動增加 1 秒，Show 函式則是在螢幕上顯示目前的時間。
// 根據主程式的註解與需求，完成主程式與類別的內容，
// 讓螢幕上可以不斷的顯示目前的時間，並在鬧鈴時間到時，顯示鬧鈴時間。
// 顯示鬧鈴時間必須持續五秒鐘，之後讓鬧鈴時間顯示消失。
// 
// 提示：想想【舉旗子】跟【放下旗子】的程式邏輯用法
// 
// 參考 p8-1.jpg ~ p8-3.jpg
// p8-1.jpg : 時間的開始計時
// p8-2.jpg : 鬧鈴時間到，顯示鬧鈴時間
// p8-3.jpg : 鬧鈴時間到後5秒鐘，在第六秒鐘，關閉鬧鈴時間顯示
//
//

#define P8
#ifdef P8

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include "functions.h"

using namespace std;

// CTimer 類別
class CTimer {
private:
	int _iHour, _iMin, _iSec;
	int _iaHour, _iaMin, _iaSec;
public:
	void setTime(int, int, int);
	void setAlarm(int, int, int);
	void tick();
	void Show();
};

void CTimer::setTime(int hh, int mm, int ss) {
	this->_iHour = hh;
	this->_iMin = mm;
	this->_iSec = ss;
}

void CTimer::setTime(int hh, int mm, int ss) {
	this->_iaHour = hh;
	this->_iaMin = mm;
	this->_iaSec = ss;
}

void CTimer::tick(void) {
	//if (_iHour < 23) {
	//	if (_iMin < 59) {
	//		if (_iSec < 59) {
	//			_iSec++
	//		}
	//		else {
	//			_iMin++;
	//			_iSec = 0;
	//		}
	//	}
	//	else {
	//		_iHour++;
	//		_iMin = 0;
	//	}
	//}
	if (_iHour < 23 && _iMin < 59 && _iSec < 59) {
		_iSec++;
	}
	else if (_iHour < 23 && _iMin < 59 && _iSec = 59) {

	}
	//考完補

	//考完補
}


	char _buf[80];

	// show 函式包含以下四行程式碼，就能在螢幕顯示目前的時間
	// 時分秒的變數名稱自行修改
		setcolor(10);
		sprintf(_buf, "%02d:%02d:%02d", _iHour, _iMin, _iSec);
		settextstyle(0, HORIZ_DIR, 40);
		outtextxy(X(-200), Y(0), _buf);

	// show 函式包含以下四行程式碼，就能在螢幕顯示鬧鈴的時間
	// 鬧鈴的時分秒的變數名稱自行修改
		setcolor(13);
		sprintf(_buf, "%02d:%02d:%02d", _iaHour, _iaMin, _iaSec);
		settextstyle(0, HORIZ_DIR, 40);
		outtextxy(X(-200), Y(-200), _buf);


int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P8");
	CTimer myTimer;								// 宣告 myTimer 物件
	setTime(23, 59, 53);	// 以時間物件設定目前為 23點59分53秒
	setAlarm(23, 59, 58);	// 以時間物件設定鬧鈴為 23點59分58秒

	while (1) {		// 無窮迴圈
		cleardevice();
		Sleep(998);	// 停 0.998 秒
		system("cls");	// 清除螢幕
		myTimer.tick();		// 呼叫 tick 函式, 讓時鐘增加 1 秒
		myTimer.Show();				// 呼叫 show 函式, 顯示目前的時間與鬧鈴
		swapbuffers();
	}
	system("pause"); return(0);
}

#endif