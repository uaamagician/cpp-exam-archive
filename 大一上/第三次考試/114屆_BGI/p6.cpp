// 程式設計一，第三次上機考試第 6 題 (5 分)
// 
// 撰寫
//       fPower 函式：有兩個引數, 第一個為 float 型別的 x, 第二個 int 型別的 n
//					  回傳值為 x^n ，型別為 float
//       fFactor 函式：有 1 個引數, int 型別的 n
//                    回傳值為 n!，型別為 float
//       fCos 函式：有一個引數, float 型別的弧度值 x
//             功能是依照下面的公式, 呼叫 fPower 與 fFactor, 算出 cos(x) 的值
//             fCos 只需要計算到前 n = 6 的總和即可
//       回傳值為 cos(x) 的計算結果, 回傳值型別為 float
// 
//       cos 函式的公式為 cos(x) = 1 - x^2/2!+ x^4/4!- x^6/6!+ ... + (-1)^n*x^(2*n)/(2*n)!
//           x 是弧度(0 ~ 2*3.1415926) 不是角度(0 ~ 360) 
// 
// 主程式呼叫 fCos(角度*(PI/180.0f)) 並輸出對應的計算結果
//   
// 要求: 
//		1. 必須完成上述函式的撰寫，同時完成參考輸出的執行才算分數 
//		2. 這三個函式都必須寫在 main() 函式之後
//		3. 為這三個函式都需要原型宣告
//      4. 不能使用內建的 pow 函式 
//
//  參考以下的輸出
// 
//     Cos(50) = 0.642788
//

#define p
#ifdef p6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926f

float fPower(float x,int n);// fPower 函式的原型宣告
float fFactor( int n);// fFactor 函式的原型宣告
float fCos(float x);// fCos 函式的原型宣告

float fPower(float x, int n)
{
	float k =1.0f;
	for (int i = 1; i <= n; i++)
	{
		k *= x;
	}
	return(k);
}// fPower 函式 計算 x^n

float fFactor(int n)
{
	int h =1;
	for (int i = 1; i <= n; i++)
	{
		h *= i;
	}
	return(h);
}// fFactor 計算 n!

float fCos(float x)
{
	int flag = 1;
	float b,ans = 1.0f;
	for (int i = 2; i <= 12; i+= 2)
	{
		b = fPower(x, i) / fFactor(i);
		if (flag ==1)
		{
			b = -b;
			flag = 0;
			ans += b;
		}
		else
		{
			flag = 1;
			ans += b;
		}
		
	}
	return(ans);
}// fCos ，計算 cos 值

int main(void)
{
	printf("Cos(50) = %f\n", fCos(50*PI / 180.0f));
	system("pause"); return(0);
}

#endif