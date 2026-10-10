//  程式設計二，第一次上機考試 ，第 1 題 (4 分)
// 
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
//  要求：
//  1. 輸出的部分都必須使用所宣告的指標變數 pc、但可將 pc 當成陣列方式來使用
//  2. 對應於 %c 或 %s 的寫法則使用陣列型式或指標型式都可以
//  3. 不可以改變 for 迴圈中已經給的數值
//  4. 第 5 列必須透過輸出 cDigit 不同位置的內容來實現，不能輸出同一個位置來達成結果
// 
// 提示：設定中斷點來確認對應輸出的對，與 for 迴圈每次要遞增與遞減的值
// 
// 參考輸出如下
// 95137
// 6789
// 23456789
// 210123456789
// 9977553311

#define P1
#ifdef P

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(void)
{

	int	 i;
	char cDigit[20] = "9876543210123456789";
	char* pc;		// 宣告字元指標變數 pc
	pc = &cDigit[0];		// 以 pc 指向 cDigit 字元陣列開頭
	for (i = 0; i <= 18;i+=4 ) printf("%c",*(pc+i) ); printf("\n");  // 輸出第 1 列的結果
	for (i = 15; i >= 4;i-=4 ) printf("%s\n",pc+i); 			   // 輸出第 2 到第 4 列的結果
	for (i = 0; i <= 9;i+=2 ) printf("%c%c",*(pc+i) ,*(pc+18-i)); printf("\n");// 輸出第 5 列的結果	

	system("pause"); return(0);
}

#endif