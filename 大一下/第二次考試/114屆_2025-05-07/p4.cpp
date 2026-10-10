//  程式設計二，第二次上機考試，第 4 題 (4 分)
//
// 以函式多載的方式宣告三個 draw 函式
// 第一個函式有 1 個 int 型別引數 n ，預設值為 1，固定輸出 n 個 * (含換行 endl)
// 第二個函式有 2 個引數，第 1 個為 ch (char 型別) 無預設值， 第 2 個為 n (int 型別)，預設值為 6
//			功能：輸出 n 個 ch (含換行 endl)
// 第三個函式有 3 個引數，第 1 個為 s (int 型別)無預設值，第 2 個為 e (int 型別)無預設值，
//		     第 3 個為 ch (char 型別)預設值為 *
//			功能：從 s 開始到 e 的位置填滿 ch 字元。
//	              螢幕左邊的第一個位置為 1
//
// 要求：
//     1. 三個函式的宣告，依照上面的要求，且必須有【原型宣告】寫在 main 之前
//	   2. 引數的預設值【一定】要寫在【原型宣告】中
//     3. 程式能正常執行並能輸出指定的結果
//     4. 不能修改主程式的任何對函式的呼叫
// 
// 嚴正提醒：不要在用 printf 或 cout 直接【列印】出答案
// 
//  輸出參考
// 
//      *
//     ##
//    @@@
//   @@@@
//  @@@@@
// ######
//
// 提示: 
//      1. 可以在 cout 透過 << 連結使用 setw(整數) 與 setfill('') 與 '字元' 省去使用 for
//      2. 換行用 endl
//       

#define P
#ifdef P4

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void draw(int n =1);
void draw(char ch,int n = 6);
void draw(int s  ,int e ,char ch = '*');// 原型宣告寫在這裡
// 第一個函式有 1 個 int 型別引數 n ，預設值為 1，固定輸出 n 個 * (含換行 endl)
void draw(int n )
{
	for (int i = 0; i < n; i++)
	{
		cout << '*' << endl;
	}
}


// 第二個函式有 2 個引數，第 1 個為 ch (char 型別) 無預設值， 第 2 個為 n (int 型別)，預設值為 6
//			功能：輸出 n 個 ch (含換行 endl)
void draw(char ch, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ch ;
	}
	cout  << endl;
}

// 第三個函式有 3 個引數，第 1 個為 s (int 型別)無預設值，第 2 個為 e (int 型別)無預設值，
//		     第 3 個為 ch (char 型別)預設值為 *
void draw(int s,int e, char ch)
{
	
	cout <<setw(e-s+1)<< setfill(ch)<<"";
	
}

int main(void)
{
	int i;
	draw(1, 6, ' '); draw();
	draw(1, 5, ' '); draw('#', 2);
	for (int i = 5; i >= 3; i--) {
		draw(1, i-1, ' ');
		draw(i, 7, '@'); cout << endl;
	}
	draw(1, 1, ' '); draw('#');
	system("pause"); return(0);
}

// draw 函式的主體寫在這裡






#endif