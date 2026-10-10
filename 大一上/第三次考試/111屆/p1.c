// 程式設計一 !! 第三次上機考試 -- 第 1 題 (3分)
//
// 根據輸出的結果，宣告三個二維陣列 A、B、C，並設定其初始值跟輸出的結果一樣，
// 計算並輸出 C = A + B 的結果如同輸出結果
// 
// 符合以下的要求並輸出正確才算分數：
//	1. 陣列在宣告時，給予初始值
//	2. 陣列的宣告與迴圈終止條件的使用都必須使用已經定義好的 ROW 與 COL
//  3. 依照所給的輸出，讓 A 與 B 陣列的兩個 row 對齊
// 
//  參考以下的輸出
// 
// A = 3  2  4
//     6  1  5
//
// B = 2 -1  3
//     3 -4 -2
//
// Matrix C = A + B =
//   5  1  7
//   9 -3  3

#define p
#ifdef p1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define ROW 2	// 定義陣列的列個數
#define COL 3	// 定義陣列的行個數

int main(void)
{
	int i, j;
		// 宣告陣列 A 並設定初值
		// 宣告陣列 B 並設定初值 
		// 宣告陣列 C 並設定初值為 0

	// 輸出 A 與 B 陣列的內容
	printf("A =");
	printf("%3d", ); // 輸出陣列 A 的內容
	printf("\n   "); // 在迴圈內用這個才能對齊喔

	printf("\nB =");
	printf("%3d",); // 輸出陣列 B 的內容
	printf("\n   "); // 在迴圈內用這個才能對齊喔


	printf("\nMatrix C = A + B = \n");
	printf("%3d",); // 輸出陣列 C 的內容
	printf("\n");

	system("pause"); return(0);
}

#endif