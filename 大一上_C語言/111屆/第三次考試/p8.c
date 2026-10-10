// 程式設計一 !! 第三次上機考試 -- 第 8 題 (3分)
//
// findingMax 為一【遞迴】函式
//     第一個引數是 int 型別的一維陣列，第二個引數是 int 型別的 n ，代表傳入陣列的大小
//     回傳值是傳入陣列中所儲存數值的最大值
//
// 主程式
//     宣告一個一維陣列包含8 個元素，並設定其初始值為 23, 10, 5, 56, 91, 54, 20, 87
//     呼叫 findingMax 並將傳回執輸出
//
// 符合以下的要求並輸出正確才算分數：
//  1. findingMax 必須以遞迴呼叫(也就是在該函式內呼叫自己)的形式完成
//
//  參考以下的輸出
//  A:  23, 10, 5, 56, 91, 54, 20, 87,
//  最大值為  91
//

#define p
#ifdef p8
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// findingMax 函式原型宣告

int main(void)
{
	// 宣告陣列 A
	int i;
	printf("A : ");
	for (i = 0; i < 8; i++) printf("%3d,");
	printf("\n");
	// 呼叫 findingMax，並接受傳回的最大值
	printf("最大值為%4d\n");
	system("pause"); return(0);
}

//findingMax 函式的主體

#endif