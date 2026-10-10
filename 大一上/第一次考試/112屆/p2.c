// 程式設計一 第一次上機寫題 第 2 題 (3+1分)
// 
//    設計一個迴圈，讓使用者輸入三次
//	  每次都輸入 a*x^2 + b*x + c = 0 中的 a b c 三個係數(int)
//    然後交換 a 與 b 係數的內容，之後
//    根據二次方式式的求解公式，輸出解的個數與解的數值
// 
//	 計分方式
//      三次輸入都能正確輸出 3 分
//      以迴圈讓讓使用者輸入三次，且能完成指定的輸出結果再多 1 分
// 	注意 :
//      不能在使用 scanf 輸入時，就互換 a 與 b 兩個變數的位置，此方式本題將不予計分。
//	   
//  提示：
//		1. 開根號使用 sqrtf() 函式。
//		2. 因為求解需要得到浮點數，記得進行除法時，記得再分母前加上(float)
//      3. 【必須完成 a 與 b 係數的交換】，才能得到應有的結果。
// 
// 參考輸出如下：
//  輸入 a b c 三個整數中間以空格為間隔 0 1 1
//  無解
//
//  輸入 a b c 三個整數中間以空格為間隔 2 1 1
//  一個解，解為 -1.000
//
//  輸入 a b c 三個整數中間以空格為間隔 3 1 1
//  兩個解，分別是 -0.382 與 -2.618
//

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	// 宣告相關的變數
	int a, b, c, d, t, n;
	float r1, r2, k;

	n = 1;
	while (n <= 3) {
		printf("輸入 a b c 三個整數中間以空格為間隔 "); scanf("%d%d%d", &a, &b, &c); // 輸入 a b c 

		t = b; b = a; a = t;
		d = b * b - 4 * a * c;

		if (d == 0) {
			printf("一個解，解為 %6.3f\n\n", (float)-b / 2 * a);
		}
		else {
			if (d > 0) {
				k = sqrtf(d);
				r1 = (-b + k) / 2 * a;
				r2 = (-b - k) / 2 * a;
				printf("兩個解，分別是 %6.3f 與 %6.3f\n\n", r1, r2);
			}
			else {
				printf("無解\n\n");
			}
		}
		n++;
	}

	

	//while () {

	//}
	// 
	//if () {	}
	//else { }

	system("pause"); return(0);
}

#endif
