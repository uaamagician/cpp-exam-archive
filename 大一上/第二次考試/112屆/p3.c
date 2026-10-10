// 程式設計一 !! 第二次上機考試 !! 第 3 題 (3+1分)
//
//  輸入一個大於 3 的奇數
//  並判斷這個數是 3 的幾次方
//
// 計分方式
//   1. 判斷輸入一個大於 3 的奇數   (1 分) 
//      提示：使用 do{ } while (); 來完成
//   2. 判斷這個數是 3 的幾次方 (3 分)
// 
// 輸出參考
// 輸入一個大於 3 的奇數: a
// 輸入一個大於 3 的奇數: 3
// 輸入一個大於 3 的奇數: 8
// 輸入一個大於 3 的奇數: 9
//  9 是 3 的 2 次方
// 
// 輸入一個大於 3 的奇數: 11
//  11 不是是 3 的次方
//

#define p
#ifdef p3
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, r = 1;
	int state;
	int nSave;

	do
	{
		printf("輸入一個大於 3 的奇數: ");
		state = scanf("%d", &n);
		rewind(stdin);
	} while (state == 0 || n <= 3 || n % 2 == 0);

	nSave = n;

	if (n % 3 == 0) {
		while (n != 3) {
			n = n / 3;
			r++;

		}
		printf("%3d 是 3 的 %d 次方\n\n", nSave, r);
	}
	else {
		printf("%3d 不是是 3 的次方\n\n", n);
	}

	
	


	system("pause"); return(0);
}

// printf("%3d 是 3 的 %d 次方\n");
// printf("%3d 不是是 3 的次方\n");

#endif