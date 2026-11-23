// 程式設計一 !! 第二次上機考試 !! 第 5 題  (3分)
//
// 讓使用者輸入三個相異的數，並輸出其他大小的順序 如下所示
// 要求 : 必須搭配迴圈的使用輸入三次
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


#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int  a, b, c;
	for ( int i=0 ; i<3  ; i++  )
	{
		printf("\n請輸入三個相異的數，數與數之間用空格分開: ");
		scanf("%d%d%d", &a, &b, &c);
		rewind(stdin);
		if (a > b) {
			if (b > c) {
				printf("a = %d > b = %d > c = %d\n", a, b, c);
			}
			else {
				if (a > c) {
					printf("a = %d > c = %d > b = %d\n", a, c, b);
				}
				else {
					printf("c = %d > a = %d > b = %d\n", c, a, b);
				}
			}
		}
		else {
			if (a > c) {
				printf("b = %d > a = %d > c = %d\n", b, a, c);
			}
			else {
				if (b > c) {
					printf("b = %d > c = %d > a = %d\n", b, c, a);
				}
				else {
					printf("c = %d > b = %d > a = %d\n", c, b, a);
				}
			}
		}

	}
	system("pause");
	return 0;
}

#endif

