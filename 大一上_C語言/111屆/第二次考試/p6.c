// 程式設計一 !! 第二次上機考試 !! 第 6 題 (3+1分)
//
//	isP 函式有一個引數 n (int型別) 
//    功能是判斷 n 是否為質數，是質數傳回 1，不是質數傳回 0
//  主程式呼叫 isP, 並根據回傳值，輸出 500 到 700 間的所有質數 (3分)
//  輸出的時候，每七個質數就換一行輸出 (1 分)
// 
//  要求：
//    1. 必須寫出 isP 函式，並在主程式呼叫完成所需的內容，否則本題不予計分
// 
//  參考輸出如下：
//  
// 503  509  521  523  541  547  547
// 557  563  569  571  577  587  587
// 593  599  601  607  613  617  617
// 619  631  641  643  647  653  653
// 659  661  673  677  683  691  691
//

#define p
#ifdef p6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// isP 函式
int isP(int n)
{
	int flag=0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		return(1);
	}
	else return(0);
}
int main(void)
{
	int a=0;
	for (int i = 500; i <= 700; i++)
	{
		if (isP(i) == 1)
		{
			a++;
			printf("%4d ",i);
			if (a % 6 == 0)
			{
				printf("\n");
			}
		}
	}

	system("pause"); return 0;
}

#endif