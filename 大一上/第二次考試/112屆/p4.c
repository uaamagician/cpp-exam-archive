// 程式設計一 !! 第二次上機考試 !! 第 4 題 (4分)
//
//	isP 函式有一個引數 n (int型別) 
//  功能是判斷 n 是否為質數，是質數傳回 1，不是質數傳回 0
//  主程式呼叫 isP, 並根據回傳值，輸出 300 到 450 間的所有質數 (4分)
//  輸出的時候，每 5 個質數就換一行輸出 (無法實現沒有關係) 
// 
//  要求：
//    1. 必須寫出 isP 函式，並在主程式呼叫完成所需的內容，否則本題不予計分
//  
// 參考輸出如下：
//    
//  307  311  313  317  331
//  337  347  349  353  359
//  367  373  379  383  389
//  397  401  409  419  421
//  431  433  439  443  449
// 

#define p
#ifdef p4

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// isP 函式 主體
int isP(int n) 
{
	int k;
	int flag = 1;

	for (k = 2; k * k <= n; k++)
	{
		if (n % k == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}



int main(void)
{
	int i;
	int flag;
	int outC = 0;

	for ( i = 300; i <= 450; i++)
	{
		flag = isP(i);
		if (flag == 1) {
			if (outC == 5) {
				printf("\n");
				printf("%4d ", i);
				outC = 1;
			}
			else {
				printf("%4d ", i);
				outC++;
			}
		}
	}

	
	system("pause"); return 0;
}

#endif