// 程式設計一 !! 第二次上機考試 !! 第 3 題  (3/4分)
//	計分方式：
//  isPrime 具有一個 int 型別的引數 n , 功能是判斷 n 是否為質數
//          為質數傳回 1 不是質數傳回 0
//  主程式呼叫 isPrimer, 根據回傳值
//  1. 輸出 300 到 500 間的所有質數 (3分) or
//  2. 輸出 300 到 500 間的所有質數 (4分)，但每一行輸出 7 個質數，而且必須對齊如下
//  
//  計分要求：質數的判斷必須由 isPrime 函式來負責，否則本題不計分
// 
//  307  311  313  317  331  337  347
//  349  353  359  367  373  379  383
//  389  397  401  409  419  421  431
//  433  439  443  449  457  461  463
//  467  479  487  491  499
//

#define p3
#ifdef p3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 宣告 isPrime 函式，回傳值為 int ，傳回 1 代表傳入的數值為質數, 0 代表傳入的數值不是質數

int isPrime(int n)
{
	int flag = 1;
	int i = 2;
	while  ((i<n)&&flag==1)
	{
		if (n % i == 0)//有因數
		{
			i++;
			flag = 1;
		}

	
	}
	if (flag == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int main(void)
{
	for (int i = 300; i < 501; i++)
	{
		if (isPrime(i) == 1)
		{
			printf("%4d ",i );
		}
	}
	/*printf("%4d ", );
	printf("%4d\n", );	*/		

	printf("\n");
	system("pause"); return 0;
}

#endif
