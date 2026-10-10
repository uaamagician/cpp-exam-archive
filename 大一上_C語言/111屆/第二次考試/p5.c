// 程式設計一 !! 第二次上機考試 !! 第 5 題 (1+2分)
//
// 宣告一個一維陣列可以儲存 10 個整數 (int)
// 利用亂數產生 100 到 300 間的數值，儲存到這個陣列中
// 找出這個陣列的最大值與最小值，並輸出，參考如下的輸出範例
// 
// 計分規則：
//		1. 產生 100 到 300 間的數值規則必須正確 (1 分)
//		2. 能正確找到最大值與最小值 (2 分)
// 
// 參考輸出
// 
// 188 216 245 153 292 213 220 106 267 117
// 最大值 = 292
// 最小值 = 106
//

#define p
#ifdef p5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	srand((unsigned)time(NULL));
	int a[10];
	int max,min;

	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 201 + 100;;
	}
	max = a[0];
	min = a[0];
	
	for (int i = 1; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		else if (a[i] < min)
		{
			min = a[i];
		}
	}
	// 產生 10 個介於 100 到 300 間的數值的亂數到陣列中
	// 以 rand() 產生介於 100 到 300 間的數值，這個寫對才有 1 分

	for (int i = 0; i < 10; i++)
	{
		printf("%3d ",a[i]);
	}

	printf("\n最大值 = %3d \n最小值 = %3d\n",max,min);
	system("pause"); return(0);
}

#endif
