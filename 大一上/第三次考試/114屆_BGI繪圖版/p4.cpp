// 程式設計一，第三次上機考試第 4 題 (4 分)
//
// 宣告一個一維陣列可以儲存 8 個整數(int)，
// 並設定初始值為 20, 63, 88, 1, 72, 81, 36, 22  
// 
// 函式 maxmin 有三個引數，第一個為傳入的陣列，第二個為該陣列的大小，
//     第三個則是一個能儲存兩個整數的一維陣列
//     功能就是找出傳入陣列的最大值與最小值，並將這兩個值儲存在傳入的第三個引數中
// 
// 主程式功能
//    宣告並產生兩個一維陣列
//      一個陣列可儲存 8 個整數(int)以及一個可儲存 2 個整數一維陣列
//      以上述產生陣列的內容，並呼叫 maxmin 找出這 8 個數的最大值與最小值
//    在主程式印出最大數與最小數
//
// 要求: 本題不能使用排序法，否則不予計分
//
// 輸出參考
// 
//  20  63  88   1  72  81  36  22
//  最大值 = 88
//  最小值 = 1
//

#define p
#ifdef p4

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxin(int a[8],int n,int b[2]);// maxmin 函式


int main(void)
{
	int i;
	int A[8] = { 20, 63, 88, 1, 72, 81, 36, 22 };// 宣告 A 陣列，大小為 8，設定初始值為 20, 63, 88, 1, 72, 81, 36, 22
	int mx[2] = { 0 };// 宣告 mx 陣列，大小為 2，設定初始值為 0 
	
	srand((unsigned)time(NULL));
	for (i = 0; i < 8; i++) { printf("%3d ", A[i]);}
	maxin(A,8,mx);					// 呼叫  maxmin
	printf("\n最大值 = %3d \n最小值 = %3d\n",mx[0],mx[1]);

	system("pause"); return(0);
}
void maxin(int a[8], int n, int b[2])
{
	int fmax, fmin;
	fmax = a[0];
	fmin = a[0];
	for (int i = 0; i < n; i++)
	{
		if (fmax < a[i])
		{
			fmax = a[i + 1];
		}
		else if (fmin > a[i])
		{
			fmin = a[i];
		}
	}
	b[0] = fmax;
	b[1] = fmin;
}

#endif