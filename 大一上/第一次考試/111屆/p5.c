// 程式設計一 第一次上機寫題 第五題 (3 分)
// 
//    設計一個迴圈，讓使用者輸入三次
//	  每次都輸入 a*x^2 + b*x + c = 0 中的 a b c  三個係數(int)
//    根據二次方式式的求解公式，輸出解的個數與解的數值
// 
//  提示：開根號使用 sqrtf() 函式
// 
// 參考輸出如下：
// 輸入 a b c 三個整數中間以空格為間隔 1 3 1
// 兩個解，分別是 -0.382 與 -2.618
//
// 輸入 a b c 三個整數中間以空格為間隔 1 2 1
// 一個解，解為 -1.000
// 
// 輸入 a b c 三個整數中間以空格為間隔 1 1 1
// 無解

#define E
#ifdef E5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) 
{	
					// 宣告三個整數 a b c 


	printf("輸入 a b c 三個整數中間以空格為間隔 "); scanf("%d%d%d", &, &, &); // 輸入 a b c 

	// (float)(2 * a);

	printf("一個解，解為 %6.3f\n\n",);
	
	printf("兩個解，分別是 %6.3f 與 %6.3f\n\n", , );
	
	printf("無解\n\n");
	

	system("pause"); return(0);
}

#endif
