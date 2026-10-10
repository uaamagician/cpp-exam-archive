// 程式設計一 !! 第三次上機考試 -- 第 9 題 (2/4分)
// 
//  根據輸入的層次(最多到第8層即可)，輸出對應的巴斯卡三角形
// 
//	計分方式：
//		1. 由小到大輸出 2 分
//		2. 由大到小輸出 4 分
// 
// 符合以下的要求並輸出正確才算分數：
//  1. 必須以迴圈連續輸入兩次而且完成對齊的輸出才算分數
// 
// 輸出參考 p9.jpg
//

#define p
#ifdef p9

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	printf("要顯示的層次 : "); scanf("%d", &n);

	printf("   ");
	printf("%3d");
	printf("\n");
	system("pause"); return(0);
}


#endif