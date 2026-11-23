// 程式設計一 第一次上機寫題 第四題 (4 分)
//
//    設計一個迴圈，讓使用者輸入三次
//	  每次都輸入 a*x^2 + b*x + c = 0 中的 a b c  三個係數(int)，a 一定是正整數
//    根據二次方程式的求解公式，輸出解的個數與解的數值
//    有兩個解時，必須由小到大輸出
//
//  提示：開根號使用 sqrtf() 函式，用法如下
//      1. sqrtf(x) 會傳回 x 的平方根，x 與傳回值都是 float 型別
//         例如：sqrtf(9.0f) 的結果是 3.0f
//      2. 判別式 d 是 int，要先轉型再傳進去：sqrtf((float)d)
//      3. 負數不能開根號，所以一定要先判斷 d >= 0 才能呼叫 sqrtf
//      4. 公式的分母 2*a 也要轉型成 float：(float)(2 * a)，否則會變成整數除法
//
// 參考輸出如下：
// 輸入 a b c 三個整數中間以空格為間隔 2 5 2
// 兩個解，由小到大分別是 -2.000 與 -0.500
//
// 輸入 a b c 三個整數中間以空格為間隔 1 -4 4
// 一個解，解為  2.000
//
// 輸入 a b c 三個整數中間以空格為間隔 3 2 1
// 無解


#define E
#ifdef E5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	// 宣告四個 int 變數：三個係數 a b c 與判別式 d，再宣告一個計數用的 int 變數 i，起始值設為 1

	while () {
		printf("輸入 a b c 三個整數中間以空格為間隔 "); scanf("%d%d%d", , , );

		// 計算判別式

		//多重判斷 記得公式是要除以(float)(2 * a);

		printf("兩個解，由小到大分別是 %6.3f 與 %6.3f\n\n", , );

		printf("一個解，解為 %6.3f\n\n", );

		printf("無解\n\n");

		// i 往下一次
	}

	system("pause"); return(0);
}

#endif