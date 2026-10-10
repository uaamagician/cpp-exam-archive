// 程式設計一，第三次上機考試第 2 題 (4 分)
//    
// 撰寫
//      sort 函式： 有兩個引數，第一個為陣列，第二個 n 為陣列大小
//				    功能是將傳入的陣列內容由小到大排好
//      prnA 函式： 有兩個引數，第一個為陣列，第二個 n 為陣列大小
//					功能就是輸出傳入的陣列內容
//		兩個函式都沒有回傳值
// 
// 主程式
//    1. 宣告一維陣列 A，大小為 6，初始設定為  25, 66, 41, 4, 15, 44
//    2. 呼叫 prnA 輸出陣列 A 內容
//	  3. 呼叫 sort 函式，對 A 進行排序
//    4. 呼叫 prnA 輸出陣列 A 內容 
// 
//  要求: 你的程式必須完成上述函式的撰寫，
//        兩個函式內的迴圈終止條件的判斷都必須使用到傳入陣列大小 n  
//        同時完成參考輸出的執行才算分數 
// 
// 參考書出結果
//
//  25  66  41   4  15  44
//   4  15  25  41  44  66
//

#define p
#ifdef p2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void prna(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d",a[i]);
		
	}
	printf("\n");
}//  prnA 函式
// 
// printf("%4d"); // 輸出目前排序的結果
// printf("\n");


void sort(int a[],int n) 
{
	int t;
	for (int i = 0; i < n-1; i++)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
		
	}
}//  sort 函式


int main(void)
{
	int A[6] = { 25, 66, 41, 4, 15, 44 };		// 宣告一維陣列A，並設定初始值為 25, 66, 41, 4, 15, 44
	prna(A, 6);	// 呼叫  printA 輸出
	sort(A, 6);	// 呼叫  sort   排序
	prna(A, 6);	// 呼叫  printA 輸出
	system("pause"); return (0);
}

#endif