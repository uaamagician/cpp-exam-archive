// 程式設計一 第一次上機寫題，第一題 (3+2 分)
//
//  輸入：
//      輸入 a b c 三個整數(int)與三個浮點數(float) x 、 y 與 z
//		根據每一個 Part 的要求計算並輸出結果，每一個 Part 都 1 分
//	    自行宣告所有必要的變數，並完成以下的功能與輸出。
//
//  Part 1
//      計算 z = (a*x^2 - b*y)/(c*x + a*y^2 - b)，並輸出 z 的結果
//
//  Part 2
//      b 與 c 內容互換、x 與 y 內容互換
//		計算 z = x^3 + a*x*y^2 - b*x^2*y + c*y^3 ，並輸出 z 的結果
//
//  要求：
//      1. 不能使用 pow 函式、powf 等內建函式
//      2. 一定要先將結果儲存到變數 z，再輸出 z 的內容
//
// 參考以下的輸出
//
// 輸入 a b c 三個整數中間以空格為間隔 3 -2 1
// 輸入 x y 兩個浮點數中間以空格為間隔 1.5 2.0
//
// ------- Part 1 -------
// (a*x^2 - b*y)/(c*x + a*y^2 - b) =  0.69355
//
// ------- Part 2 -------
// x^3 + a*x*y^2 - b*x^2*y + c*y^3 =  8.75000
//

#define P
#ifdef P1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
        //宣告abc (int)
	    //宣告xyz(float)
        //宣告交換用的變數（int）
        //宣告交換用的變數（float）
        
	printf("輸入 a b c 三個整數中間以空格為間隔 "); scanf("%%%", &, &, &);
	printf("輸入 x y 兩個浮點數中間以空格為間隔 "); scanf("%%", &, &);     
	printf("\n------- Part 1 -------\n");
        //運算z = (a*x^2 - b*y)/(c*x + a*y^2 - b)

	printf("(a*x^2 - b*y)/(c*x + a*y^2 - b) = %8.5f\n", );

	printf("\n------- Part 2 -------\n");
        //b 與 c 內容互換、x 與 y 內容互換
        //運算z = x^3 + a*x*y^2 - b*x^2*y + c*y^3


	printf("x^3 + a*x*y^2 - b*x^2*y + c*y^3 = %8.5f\n", );	

	system("pause"); return(0);
}

#endif
