// 程式設計一 !! 第二次上機考試 !! 第 2 題  (3+1分)
//	計分方式：
//  isPrime 具有一個 int 型別的引數 n , 功能是判斷 n 是否為質數
//          為質數傳回 1 不是質數傳回 0
//  提示: 仿效 int main(){ return xxx; } 的形式就可以了
// 
//  計分要求：質數的判斷必須由 isPrime 函式來負責，否則本題不計分
// 
//  主程式呼叫 isPrimer, 根據回傳值
//  1. 輸出 300 到 400 間的所有質數與總個數 (3分) or
//  2. 輸出 300 到 400 間的所有質數與總個數，但每一行輸出 8 個質數，且對齊如下(4分):
//  
//  307  311  313  317  331  337  347  349
//  353  359  367  373  379  383  389  397
//  300 到 400 間共有 16 個質數
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//  isPrime函式 具有一個 int 型別的引數 n , 功能是判斷 n 是否為質數
//          為質數傳回 1 不是質數傳回 0
bool isPrime(int n) {
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, count = 0;
	for (n = 300; n <= 400; n++) {
		if (isPrime(n)) {
			printf("%d  ", n);
			count ++;
			if (count % 8 == 0) {
				printf("\n");
			}
		}
		
	}


	printf("300 到 400 間共有 %d 個質數\n", count);
	system("pause");
	return 0;
}

#endif