// 程式設計一 !! 第二次上機考試 !! 第 1 題 (3分)
// 
//  寫一個迴圈執行以下的輸入三次
//  輸入三個數 a b c，找出其大小關係並輸出。
//	
//  要求：必須滿足以下的要求，完成指定功能才算分數
//  1. 找出大小關係的第一次比較必須是 b 與 c
//  2. 使用迴圈完成三次的輸入
//  3. 大小關係的求得不能使用暴力法
// 
// 輸出參考
//
//  第 1 次輸入三個相異的數 a b c : 3 2 1
//  a = 3 > b = 2 > c = 1
//
//  第 2 次輸入三個相異的數 a b c : 2 3 1
//  b = 3 > a = 2 > c = 1
//
//  第 3 次輸入三個相異的數 a b c : 1 2 3
//  c = 3 > b = 2 > a = 1
// 


#define p
#ifdef p1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a, b, c;
	for (int i = 1; i <= 3; i++)
	{
		printf("\n第 %d 次輸入三個相異的數 a b c : ",i);
		scanf("%d%d%d", &a, &b, &c);
		if (b > c)
		{
			if(c>a) printf("b=%d > c=%d > a=%d\n", b, c, a);
			else if (a>b) printf("a=%d > b=%d > c=%d\n", a, b, c);
			else printf("b=%d > a=%d > c=%d\n", b, a, c);
		}
		else
		{
			if(b>a) printf("c=%d > b=%d > a=%d\n", c, b, a);
			else if(c>a) printf("c=%d > a=%d > b=%d\n", c, a, b);
			else printf("a=%d > c=%d > b=%d\n", a, c, b);
		}
	}



	system("pause");
	return 0;
}

//
//printf("b=%d > c=%d > a=%d\n", b, c, a);
//printf("a=%d > b=%d > c=%d\n", a, b, c);
//printf("b=%d > a=%d > c=%d\n", b, a, c);
//printf("a=%d > c=%d > b=%d\n", a, c, b);
//printf("c=%d > a=%d > b=%d\n", c, a, b);
//printf("c=%d > b=%d > a=%d\n", c, b, a);
//

#endif