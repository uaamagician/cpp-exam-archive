// 程式設計一 !! 第三次上機考試 -- 第 7 題 (6 分)
// 
//       power 函式：有兩個引數, 第一個為 float 型別的 x, 第二個 int 型別的 n
//					  回傳值為 x^n ，型別為 float
//       factor 函式：有 1 個引數, int 型別的 n
//                    回傳值為 n!，型別為 float
//       fCos 函式：有一個引數, float 型別的弧度值 x
//             功能是依照下面的公式, 呼叫 power 與 factor, 算出 cos(x) 的值
//             fCos 只需要計算到前 n = 9 的總和即可
//       回傳值為 cos(x) 的計算結果, 回傳值型別為 float
// 
//       cos 函式的公式為 cos(x) = 1 - x^2/2!+ x^4/4!- x^6/6!+ ... + (-1)^n*x^(2n)/(2n)!
//           x 是弧度(0 ~ 2*3.1415926) 不是角度(0 ~ 360) 
// 
// 主程式呼叫 fCos(角度*(PI/180.0f)) 並輸出對應的計算結果
//   
// 符合以下的要求並輸出正確才算分數： 
//	 1. 必須完成上述的三個函式，並透過公式計算求得結果完成參考輸出的執行才算分數 
//	 2. 這三個函式都必須寫在 main() 函式之後
//	 3. 這三個函式都需要原型宣告
//   4. 不能使用內建的 pow 函式 
//
//  參考以下的輸出
// 
//    Cos(25) = 0.906308
//

#define p
#ifdef p7

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926f

// 這三個函式的原型宣告

						// power 函式的原型宣告
						// factor 函式的原型宣告
						// fCos 函式的原型宣告

						// factor 函式，計算 n!

						// power 函式, 計算 x^n

						// fCos 函式

	// 每次累加 2, 此處僅計算後 8 項的合, 別忘記第一項的 1
	for (i = 2; i <= 16; i += 2) { 

	}


int main(void)
{
	printf("Cos(25) = %f\n", fCos(25*PI / 180.0f));
	system("pause"); return(0);
}

#endif