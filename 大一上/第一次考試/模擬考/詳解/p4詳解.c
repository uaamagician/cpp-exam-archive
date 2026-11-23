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

#define E5
#ifdef E5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	int a, b, c, d, i;
	i = 1;

	while (i <= 3) {
		printf("輸入 a b c 三個整數中間以空格為間隔 "); scanf("%d%d%d", &a, &b, &c);

		d = b * b - 4 * a * c;

		if (d > 0) {
			printf("兩個解，由小到大分別是 %6.3f 與 %6.3f\n\n", (-b - sqrtf((float)d)) / (float)(2 * a), (-b + sqrtf((float)d)) / (float)(2 * a));
		}
		else if (d == 0) {
			printf("一個解，解為 %6.3f\n\n", -b / (float)(2 * a));
		}
		else {
			printf("無解\n\n");
		}
		i++;
	}

	system("pause"); return(0);
}

#endif

// =================================== 詳解 ===================================
// 1. 考點：多重 if...else if...else、while、sqrtf、型別轉換
// 2. 判別式 d = b*b - 4*a*c，用 int 就夠。d > 0 兩個解，d == 0 一個解，d < 0 無解
// 3. 兩個解由小到大：a 是正數，所以 (-b - 根號d) / (2a) 比較小，要先輸出
// 4. 型別轉換：d 是 int，sqrtf 要的是 float，寫成 sqrtf((float)d)
//    分母寫 (float)(2 * a)，否則 -b / (2 * a) 兩邊都是 int，會做整數除法，例如 -4 / 8 變成 0
// 5. 要 #include <math.h> 才能用 sqrtf；負數不能開根號，所以 sqrtf 只放在 d > 0 的分支
// 6. 手算驗證：
//      2 5 2：d = 25 - 16 = 9，(-5 - 3) / 4 = -2.000，(-5 + 3) / 4 = -0.500
//      1 -4 4：d = 16 - 16 = 0，-(-4) / 2 = 2.000
//      3 2 1：d = 4 - 12 = -8 < 0，無解
// 7. 易錯點：兩個解的輸出順序寫反；sqrtf 忘了轉型；while 的計數 i 忘了 i++
