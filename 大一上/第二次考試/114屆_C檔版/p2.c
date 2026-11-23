// 程式設計一 !! 第二次上機考試 !! 第 2 題 (3+3分) 
//
// 輸入一個數
// 1. 計算並輸出這個數的所有因數、因數個數、因數的和與積(注意溢位)
// 2. 計算並輸出 2 到 500 中的完全數。
//	  完全數是指一個數等於其所有正因數（不包括自身）之和。
//    例如：6 的因數有 1 2 3 6, 而 6 = 1 + 2 + 3, 6 是一個完全數
//
// 第 1 個部分 3 分， 第 2 個部分 3 分
//
// 以下為輸出參考
// 輸入一個數: 144
// 因數有 : 2   72    3   48    4   36    6   24    8   18    9   16   12 共 13 個因數
// 所有的因數和   258 因數積 106993205379072
//
// 2 到 500 間的完全數有 : 6   28  496
// 

#define p
#ifdef p2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, count = 0,p = 0;
	float sum= 0,f= 1;
	printf("輸入一個數 : "); scanf("%d",&n);
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i==0)
		{
			if (i == (n/i))
			{
				printf("因數有 :\n ");
				printf(" %4d\n",i );
				count++;
				sum += i;
				f *= i;

			}
			else
			{
				printf("因數有 : \n");
				printf(" %4d %4d\n",i ,n/i );
				count += 2;
				sum += (i + (n / i));
				f*= (i * (n / i));
			}
			
		}
		
	}
	printf(" 共 %d 個因數\n",count );
	printf("所有的因數和 %5.0f 因數積 %10.0f\n",sum ,f );


	
	

	printf("\n");
	system("pause"); return(0);
}

#endif