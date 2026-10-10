// 程式設計一 !! 第三次上機考試 -- 第 2 題 (3+2分)
//
// 利用遞迴呼叫完成河內塔指定環數的搬動過程，並同時輸出總共的搬動次數
// 
// 計分方式：
//	   輸出搬動過程 : 3 分
//     輸出搬動次數 : 2 分
// 
// 符合以下的要求並輸出正確才算分數： 
//   1. 函式 Hanoi 必須寫在 main 之後，所以必須寫出原型宣告 <- 必要項
//   2. 搬動次數的輸出必須是來自 Hanoi 函式的回傳值
// 
//  參考以下的輸出
//
// 有多少圓盤要搬: 3
// 將第 1 個圓盤從塔 1 搬到塔 3
// 將第 2 個圓盤從塔 1 搬到塔 2
// 將第 1 個圓盤從塔 3 搬到塔 2
// 將第 3 個圓盤從塔 1 搬到塔 3
// 將第 1 個圓盤從塔 2 搬到塔 1
// 將第 2 個圓盤從塔 2 搬到塔 3
// 將第 1 個圓盤從塔 1 搬到塔 3
// 3 個環共搬動 7 次
//

#define p
#ifdef p2
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Hanoi(int, int, int, int);		//函式原型宣告


int main(void)
{
	int n, ret = 0;
	printf("有多少圓盤要搬: ");
	scanf("%d", &n);
	ret = Hanoi(n, 1, 2, 3);// 呼叫 Hanoi 函式，並取得搬動的次數
	
	printf("%d 個環共搬動 %d 次\n", n, ret);
	system("pause"); return(0);
}


int Hanoi(int n, int s, int m, int d) {
	int ret1, ret2;
	if (n == 1) {
		printf("將第%2d 個圓盤從塔%2d 搬到塔%2d\n", n, s, d);
		return(1);
	}
	else {
		ret1 = Hanoi(n - 1, s, d, m);
		printf("將第%2d 個圓盤從塔%2d 搬到塔%2d\n", n, s, d);
		ret2 = Hanoi(n - 1, m, s, d);
		return(ret1 + ret2 + 1);
	}
}


		// 終止條件，遞迴的一定要寫的



#endif