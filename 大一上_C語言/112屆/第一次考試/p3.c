// 程式設計一 第一次上機寫題，第 3 題 (2分)
//
// 輸出 1 到 100 間所有數的總和，以及所有偶數的和與所有奇數的和
//
// 參考以下的輸出結果
// 
// 1+...+100 = 5050
// 奇數和 = 2500
// 偶數和 = 2550
//

#define P
#ifdef P3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, sumOdd, sumEven, sumAll;
	i = 1; sumOdd = sumEven = sumAll = 0;

	while (i <= 100) {
		if (i % 2 == 1) {
			sumOdd += i;
		}
		else {
			sumEven += i;
		}
		sumAll += i;
		i++;
	}

	printf("1+...+100 = %d\n奇數和 = %d\n偶數和 = %d\n\n", sumAll, sumOdd, sumEven);

	system("pause"); return(0);
}

#endif