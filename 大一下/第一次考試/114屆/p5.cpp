//  程式設計二，第一次上機考試 ，第 5 題 ( 3分 )
//  
//  撰寫名稱為 pc 的函式三個，三個都沒有回傳值，功能分別如下
// 
//	1 個引數，int 型別 n: 功能為輸出 n 個 '*' 最後再輸出一個換行
//	
//	2 個引數，第一個為 char ch, 第二個為 int n
//		功能為輸出 n 個 ch，最後再輸出一個換行
// 
//	3 個引數，第一個為 char ch, 第二個與第三個都是 int， 分別是 s 與 e
//		功能是在這次輸出從 e 開始到 s 處，輸出 ch，最後再輸出一個換行
//      s 與 e 的引述預設值分別是 1 與 15
// 
// 主程式依註解說明完成所需要的程式碼，且不能任意修改，輸出以下的內容
// 提示 : 最後一排 * 與  1 的輸出都是從第 5 個字元開始
// 
// 參考輸出如下
//       *
//      ***
//     *****
//    *******
//!!!!!!!!!!!!!!!
//    1111111
//     22222
//      333
//       4
//


#define P
#ifdef P5

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
// 三個 pc() 函式
// 你會用到 width() fill() endl 等 cout 的方法

void pc(int n) {
	cout.width(n);
	cout.fill('*');
	cout << "" << endl;
}
void pc(int n, char ch) {
	cout.width(n);
	cout.fill(ch);
	cout << "";
}
void pc(char ch, int n = 1, int j = 15) {
	cout.width(n);
	cout.fill(' ');
	cout << "";
	cout.width(j - n);
	cout.fill(ch);
	cout << "" << endl;
}
int main(void)
{
	int i;

	for (i = 1; i < 5; i++) // 此行不能修改
	{
		pc(8 - i, ' ');
		pc(i * 2 - 1);
	}
	pc('!'); // 此行不能修改
	for (i = 1; i < 5; i++)// 此行不能修改
	{
		pc(i + '0', i + 3, 12 - i);  // 呼叫 pc 給 3 個引數
	}
	system("pause"); return(0);
}

#endif