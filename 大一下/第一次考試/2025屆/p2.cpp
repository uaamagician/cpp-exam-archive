//  程式設計二，第一次上機考試 ，第 2 題 (3 分)
// 
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
// 輸出結果
//  x + y = 4
//  x * y = 5
//  fxy(x, y) = 21.160

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h>

int add(float x, float y){ return((int)(x + y)); }
int product(float x, float y){ return((int)(x * y)); }
float fxy(float x, float y) {
	float r = x * x + 2 * x * y + y * y;
	return(r);
}

int main(void)
{
	float x = 2.1f, y = 2.5f;
	int ret;
	int (*pfun1)(float x, float y);							// 宣告 pfun1 為函式指標
	pfun1 = add;							// pfun1 指向 add 函式
	ret = pfun1(x, y);
	printf("x + y = %d\n",ret	);  // 以 pfun1 呼叫, 並以 x  y 為引數
	pfun1 = product;
	ret = pfun1(x, y);// pfun1 指向 product 函式
	printf("x * y = %d\n",ret	);  // 以 pfun1 呼叫, 並以 x  y 為引數

	float fret;
	float(* pfun2)(float x,float y);							// 宣告 pfun2 為函式指標
	pfun2 = fxy;
	fret = pfun2(x, y);// pfun2 指向 fxy 函式
	printf("fxy(x,y) = %6.3f\n",fret		); // 以 pfun2 呼叫, 並以 x  y 為引數

	system("pause"); return(0);
}

#endif