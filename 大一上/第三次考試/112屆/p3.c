// 程式設計一 !! 第三次上機考試 -- 第 3 題 (3 分)
//
// 宣告一個一維陣列可以儲存 10 個整數(int)
// 並設定陣列的內容為 54  24  60  96  59  87  25  67  61  12

// 找出這 10 個整數的最大值與最小值
// 
// 要求: 本題不能使用排序法，否則不予計分
//
// 54  14  60  96  59  87  25  67  61  22
// 最大值 = 96
// 最小值 = 14
//

#ifdef p3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int A[10] = { 54, 14, 60, 96, 59, 87, 25, 67, 61, 22 };
	int min, max;
	int j;
	for ( j = 0; j < 10; j++)
	{
		printf("%3d ", A[j]); // 輸出陣列的內容
	}
	
	min = max = A[0];
	int i;
	for ( i = 0; i < 10; i++)
	{
		if (A[i] < min) {
			min = A[i];
		}
		else if (A[i] > max) {
			max = A[i];
		}
	}

	


	printf("\n最大值 = %3d \n最小值 = %3d\n", max, min);

	system("pause"); return(0);
}

#endif
