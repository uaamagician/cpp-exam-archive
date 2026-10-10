// 程式設計一，第三次上機考試第 8 題 (4 分)
//    
//	輸入一個十進位數值，然後輸出該數值的二進位
// 
//	要求：撰寫 toBinary 函式，該函式有一個int 型別的引數 n
//	主程式呼叫  toBinary 並將輸入的數值傳給他
// 
//	toBinary 必須以遞迴呼叫來完成二進位的生成
//  主程式輸出該計算所得的二進位結果
//
// 提示：必須透過全域變數(包含字元陣列)來儲存計算的結果
//       0 的 ASCII 編碼是 48
//
// 參考如下的輸出
//
// 輸入一個介於 50 萬 到 100萬間的數 : 999999
// 二進位為  11110100001000111111
// 

#define p8
#ifdef p8

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBinary (int n);
			// toBinary 函式原型宣告

int main(void)
{
	int n;
	printf("輸入一個介於 50 萬 到 100萬間的數 : ");
	scanf("%d", &n);


	printf("二進位為  %s\n",1 );
	system("pause"); return(0);
}

void toBinary(int n)
{
	int a, b, c;
	a = n / 2;
	b = a % 2;
	if (a!=0)
	{
		if (b==1)
		{
			printf("%d", 1);
		}
		else
		{
			printf("%d", 0);
		
		}
		toBinary (a);
	}
	else
	{
		if (n%2==1)
		{
			//最後一位是1
		}
		else
		{
			//最後一位是0
		}
	}
	

	
}
// toBinary 函式主體


#endif