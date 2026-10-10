// 程式設計一 !! 第三次上機考試 -- 第 5 題 (3分)
//
//  撰寫以下三個類函式功能的巨集
//  CUBIC(x)   計算 x^3 的巨集
//  MIN(x,y)   求取 x, y 兩數最小數的巨集
//  DIFSQU(x, y) 計算 x^2 - y^2 的巨集
//
// 符合以下的要求並輸出正確才算分數： 
//		1. MIN(x,y) 必須以 ? : 運算子撰寫
//      2. z 的計算必須依照下面註解的說明，否則本題不予計分
//
//  主程式計算三個方式式的計算結果並輸出，請參考註解的說明，並完成指定的輸出結果
//
//  參考以下的輸出
// 
//  x = 0.03704
//  y = 5.40000
//  z = 0.20000
//

#define p
#ifdef p5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
// 計算 x^3 的巨集：CUBIC(x)
// 求取 x, y 兩數最小數的巨集：MIN(x, y)  
// 計算 x^2 - y^2 的巨集：DIFSQU(x, y)

int main() {
	float a = 3.0f, b = -2.0f;
	float x, y, z;
	x = 1 / CUBIC(a);
	printf("x = %3.5f\n", x);
	y = CUBIC(a)/ DIFSQU(a, b);
	printf("y = %3.5f\n", y);
	// z 為 a-b 與 a+b 的最小值再除上(a^2 - b^2)
	// a-b 與 a+b 的最小值呼叫 MIN(x,y)
	// a^2 - b^2 呼叫 DIFSQU(a,b)
	// 根據上述註解寫成對應 z 的程式碼，必須寫成一行，
	// 且 MIN(x,y) 與 DIFSQU(a,b) 不能另外儲存到其他的變數，再進行兩數的相除，否則本題不予計分

	printf("z = %3.5f\n", z);
	system("pause"); return(0);
}

#endif
