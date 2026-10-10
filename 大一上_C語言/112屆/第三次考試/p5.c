// 程式設計一 !! 第三次上機考試 -- 第 5 題 (4 分)
//    
//      sort 函式： 有兩個引數，第一個為陣列，第二個 n 為陣列大小
//				    功能是將傳入的陣列內容【由大到小】排好
//      prnA 函式： 有兩個引數，第一個為陣列，第二個 n 為陣列大小
//					功能就是輸出傳入的陣列內容
//		兩個函式都沒有回傳值
// 
// 主程式
//    1. 宣告一維陣列 A，大小為 7，初始設定為 23,33,54,5,67,42,82
//    2. 呼叫 prnA 輸出陣列 A 內容
//	  3. 呼叫 sort 函式，對 A 進行排序
//    4. 呼叫 prnA 輸出陣列 A 內容 
// 
// 符合以下的要求並輸出正確才算分數：
//	1. 必須完成上述函式的撰寫，且陣列 A 必須宣告在主程式內
//  2. 兩個函式內的迴圈終止條件的判斷都必須使用到傳入陣列大小 n  
//  3. 同時完成參考輸出的執行才算分數 
//  4. 不能使用全域變數
// 
//  參考以下的輸出
// 
//  23  33  54   5  67  42  82
//  82  67  54  42  33  23   5
//

#define p
#ifdef p5
#define _CRT_SECURE_NO_WARNINGS 1




#include <stdio.h>
#include <stdlib.h>

//  prnA 函式
void prnA(int A[], int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		printf("%4d", A[i]);
	}
	printf("\n");
}

//printf("%4d"); // 輸出目前排序的結果
//printf("\n");

//  sort 函式
void sort(int A[], int n) {
	int iSwitch, t;
	do
	{
		iSwitch = 0;
		int k;
		for ( k = 0; k < n-1; k++)
		{
			if (A[k] < A[k + 1]) {
				t = A[k]; A[k] = A[k + 1]; A[k + 1] = t;
				iSwitch = 1;
			}
		}
	} while (iSwitch == 1);
}


int main(void)
{
	int A[7] = { 23,33,54,5,67,42,82 };		// 宣告一維陣列A，並設定初始值為 23,33,54,5,67,42,82
	prnA(A, 7);		// 呼叫  prnA 輸出
	sort(A, 7);		// 呼叫  sort 排序
	prnA(A, 7);		// 呼叫  prnA 輸出
	system("pause"); return (0);
}

#endif