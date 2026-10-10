//  程式設計二，第二次上機考試 ，第 1 題 (3分)
//
// 以函式多載的方式宣告三個 pc 函式
// 第一個函式沒有引數，固定輸出 3 個 * (含換行 endl)
// 第二個函式有一個引數 ch (char 型別)，輸出 3 個 ch 字元 (不含換行)
// 第三個函式有兩個引數，第 1 個為 n (int 型別)，第 2 個為 ch (char 型別), (不含換行)  
//       n 無預設值，ch 預設值為 '#'， 功能是印出 n 個 ch 字元
//
// 要求：
//     1. 三個函式的宣告，依照上面的要求，且必須有【原型宣告】寫在 main 之前。
//     2. 程式能正常執行並能輸出指定的結果
//     3. 不能修改主程式的任何對函式的呼叫
// 
//  輸出參考
// 
//  $$$***
//  #***
//  333***
//  @@@@@***
//  
// 提示: 
//      1. 可以在 cout 透過 << 連結使用 setw(整數) 與 setfill('') 與 '字元' 省去使用 for
//      2. 換行用 endl
//       

#define P
#ifdef P1

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// 原型宣告寫在這裡
void pc();
void pc(char);
void pc(int, char ch = '#');


int main(void)
{
	pc('$'); pc();
	pc(1); pc();
	pc(3, '3'); pc();
	pc(5, '@'); pc();
	system("pause"); return(0);
}

// pc 函式的主體寫在這裡
void pc() {
	cout << setw(3) << setfill('*') << "" << endl;
}

void pc(char ch) {
	cout << ch << ch << ch;
}

void pc(int n, char ch) {
	cout << setw(n) << setfill(ch) << ch;
}


#endif