// 程式設計一 第一次上機寫題，第 6 題 (3 分)
//
//  撰寫 pc 與 ps 兩個函式，兩個函式都沒有回傳且都只接受一個 int 型別的引數 n
//  pc 功能是水平輸出 n 個 * 後【再輸出一個換行】
//  ps 功能是水平輸出 n 個空白即可，【不須額外】輸出換行
//  
//	在主程式透過呼叫 pc 與 ps 函式，顯示包含【7個】層級的 * 三角形如以下的參考輸出所示 
// 
//  必須完成 pc 與 ps 兩個函式的功能，且在主程式呼叫這兩個函式來完成指定的輸出
// 
// 參考輸出如下：
//	     *
//      ***
//     *****
//    *******
//   *********
//  ***********
// *************
//  	
   
#define P
#ifdef P6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


// pc 函式
void pc(int n) {
	int i = 1;
	while (i <= n) {
		printf("*");
		i++;
	}
	printf("\n");
}

// ps 函式
void ps(int m) {
	int i = 1;
	while (i <= m) {
		printf(" ");
		i++;
	}
}


int main(void)
{
	int k = 1;
	while (k <= 7) {
		ps(7 - k);
		pc(2 * k - 1);
		k++;
	}
	system("pause");
	return(0);
}

#endif