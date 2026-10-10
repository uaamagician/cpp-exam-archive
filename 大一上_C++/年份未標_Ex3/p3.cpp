// 程式設計一，第三次上機考試第 3 題 (5 分)
// 
// 撰寫
//       fPower 函式：有兩個引數, 第一個為 float 型別的 x, 第二個 int 型別的 n
//					  回傳值為 x^n ，型別為 float
//       fFactor 函式：有 1 個引數, int 型別的 n
//                    回傳值為 n!，型別為 float
//       fSin 函式：有一個引數, float 型別的弧度值 x
//             功能是依照下面的公式, 呼叫 fPower 與 fFactor, 算出 cos(x) 的值
//             fSin 只需要計算到前 n = 7 的總和即可
//       回傳值為 sin(x) 的計算結果, 回傳值型別為 float
// 
//       sin 函式的公式為 sin(x) = x - x^3/3!+ x^5/5!- x^7/7!+ ... + (-1)^(n+1)*x^(2*n-1)/(2*n-1)!
//           x 是弧度(0 ~ 2*3.1415926) 不是角度(0 ~ 360) , 
//           x 為第 1 項、x^3/3! 為第 2 項...、n 代表第 n 項, n = 7 時 +x^(13)/(13!)
// 
// 主程式呼叫 fSin(角度*(PI/180.0f)) 並輸出對應的計算結果
//   
// 要求: 
//		1. 必須完成上述函式的撰寫，同時完成參考輸出的執行才算分數 	
//		2. 這三個函式都必須寫在 main() 函式之後
//		3. 這三個函式都需要原型宣告
//      4. 不能使用 C/C++ 內建數學函式來計算階乗與次方
//
//  參考以下的輸出
//     Sin(60) = 0.866025
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926f

float fPower(float x, int n);				// fPower 函式的原型宣告
float fFactor(int n);					// fFactor 函式的原型宣告
float fSin(float x,int n);				// fCos 函式的原型宣告

int main(){
	printf("Sin(60) = %f\n", fSin(60 * (PI / 180.0f), 7));
	return(0);
}

float fFactor(int n) {
	return n>1? fFactor(n - 1) * n:1;
}// fFactor 函式的主體, 計算 n!


float fPower(float x, int n) {
	return n>1? fPower(x, n - 1) * x:x;
}// fPower 函式的主體, 計算 x^n


float fSin(float deg,int n) {
	float current = -fPower(-1,n) * fPower(deg, 2 * n - 1) / fFactor(2 * n - 1);
	return n>1? current + fSin(deg,n-1):deg;
}// fSin 函式的主體
#endif