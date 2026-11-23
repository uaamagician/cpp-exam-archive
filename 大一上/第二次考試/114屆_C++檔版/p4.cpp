// 程式設計一 !! 第二次上機考試 !! 第 4 題 (3+2分) 
//
// 輸入一個數
// 1.(3分) 計算並輸出這個數的所有因數、因數個數、因數的和與積 [注意溢位] 
//         提示 : 儲存積的變數記得宣告為 float 型別
// 2.(2分) 計算並輸出 2 到 500 中的完全數。
//	       完全數是指一個數等於其所有正因數（不包括自身）之和。
//         例如：6 的因數有 1 2 3 6, 而 6 = 1 + 2 + 3, 6 是一個完全數
//
// 以下為輸出參考
// 輸入一個數: 144
// 因數有 : 2   72    3   48    4   36    6   24    8   18    9   16   12 共 13 個因數
// 所有的因數和   258 因數積 106993205379072
//
// 2 到 500 間的完全數有 : 6   28  496
// 

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int input,count = 0, sum = 0;
	float product = 1;
	printf("輸入一個數 : "); scanf("%d",&input);

	printf("因數有 : ");
	for (int i = 2; i * i <= input; i++) {
		if (input % i == 0) {
			if (i* i == input) {
				printf(" %4d", i);
				count ++;
				sum += i;
				product *= i;
			}
			else {
				printf(" %4d %4d", i, input / i);
				count += 2;
				sum += i + input/i;
				product *= input;
			}
		}
	}
	printf(" 共 %d 個因數\n", count);
	printf("所有的因數和 %5d 因數積 %10.0f\n", sum, product);

	printf("\n\n2 到 500 間的完全數有 : ");
	for (int i = 2; i <= 500; i++) {
		sum = 0;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				if (j * j == i) {
					sum += j;
				}
				else {
					sum += j + i/j;
				}
			}
		}
		if (sum+1 == i) {
			printf("%4d", i);
		}
	}
	

	printf("\n");
	return(0);
}

#endif