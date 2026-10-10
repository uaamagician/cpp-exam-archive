// 程式設計一 !! 第二次上機考試 !! 第 5 題  (3分)
//
// 讓使用者輸入三個相異的數，並輸出其他大小的順序 如下所示
// 搭配迴圈的使用輸入三次
//
// 請輸入三個相異的數，數與數之間用空格分開: 1 2 3
// c = 3 > b = 2 > a = 1
//
// 請輸入三個相異的數，數與數之間用空格分開: 2 3 1
// b = 3 > a = 2 > c = 1
//
// 請輸入三個相異的數，數與數之間用空格分開: 3 2 1
// a = 3 > b = 2 > c = 1
//
// 計分方式： 使用暴力法本題不計分


#define p
#ifdef p5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;
	int i;
	i = 1;
	while ( i<=3)
	{
		printf("\n請輸入三個相異的數，數與數之間用空格分開: ");
		scanf("%d%d%d", &a, &b, &c);
		rewind(stdin);
		if (b>c)
		{
			if (a>b)
			{
				printf("a=%d > b=%d > c=%d\n", a, b, c);
			}
			else if (a>c)
			{
				printf("b=%d > a=%d > c=%d\n", b, a, c);
				
			}
			else
			{
				printf("b=%d > c=%d > a=%d\n", b, c, a);
			}
		}
		else//c>b
		{
			if (b>a)
			{
				printf("c=%d > b=%d > a=%d\n", c, b, a);
			}
			else if (c>a)
			{
				printf("c=%d > a=%d > b=%d\n", c, a, b);
				
			}
			else
			{
				printf("a=%d > c=%d > b=%d\n", a, c, b);
			}
		}
		i++;

		
	}
	system("pause");
	return 0;
}

#endif

// 以下是你會用到的 直接複製貼上使用
// printf("a=%d > b=%d > c=%d\n", a, b, c);
// printf("a=%d > c=%d > b=%d\n", a, c, b); 
// printf("b=%d > a=%d > c=%d\n", b, a, c);
// printf("b=%d > c=%d > a=%d\n", b, c, a);
// printf("c=%d > b=%d > a=%d\n", c, b, a);
// printf("c=%d > a=%d > b=%d\n", c, a, b);