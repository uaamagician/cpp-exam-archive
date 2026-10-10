// 程式設計一，第三次上機考試第 3 題 (4 分)
//
// 撰寫 
//		genTT 函式：有三個引數,第一個是二維陣列,2 跟 3 引述為陣列的 row n 與 column m
//					功能在傳入的陣列內，產生 n*(m-1) 的乘法表
//                  並以 row 為單位，將每一row的內容相加到陣列該 row 的最後一個儲存格中 
//		prnTT 函式：有三個引數,第一個是二維陣列,2 跟 3 引述為陣列的 row n 與 column m
//					功能為輸出所傳入陣列的內容
// 
//      genTT 與 prnTT 都沒不用回傳值
// 
//      主程式：宣告一個 6*9 的二維整數陣列 tt
//			    呼叫 genTT 產生乘法表於 tt 中 
//				呼叫 prnTT 輸出 tt 的內容
// 
//  要求: 你的程式必須完成上述函式的撰寫，
//        兩個函式內的迴圈終止條件的判斷都必須使用到傳入的 n 與 m 
//        兩個函式必須寫在 main() 之後，且必須定義這兩個函式的原型宣告
//        完成參考輸出的執行才算分數 
//        不可將 tt 宣告為全域變數
// 
//  你可以宣告 tt 7*10 的矩陣，放棄索引值 0 的使用
//
// 參考以下的輸出
//
// 1   2   3   4   5   6   7   8  36
// 2   4   6   8  10  12  14  16  72
// 3   6   9  12  15  18  21  24 108
// 4   8  12  16  20  24  28  32 144
// 5  10  15  20  25  30  35  40 180
// 6  12  18  24  30  36  42  48 216
//

#define p
#ifdef p3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void genTT(int a[7][10],int n,int m);// genTT 函式的原型宣告
void prnTT(int a[7][10], int n, int m);// prnTT 函式的原型宣告

int main(void)
{
	int tt[7][10] = { 0 };		 // 宣告二維陣列 tt，大小為 6*9 , 設定初始值為 0
	genTT(tt,6,9); // 呼叫 genTT , 產生 n*(m-1) 乘法表於 tt 中，並計算每一row 的和到該 row 的最後一個儲存位置
	prnTT(tt, 6, 9); // 呼叫 prnTT , 輸出 tt 的全部內容

	system("pause"); return(0);
}


void genTT(int a[7][10], int n, int m)
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			a[i][j] = i * j;
		}

	}
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			a[i][9] += a[i][j];
		}
	}
	
	
}// genTT 函式主體
 
 
void prnTT(int a[7][10], int n, int m) 
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}// prnTT 函式主體
// printf("%4d", tt[i][j]);
// printf("\n");
//


#endif
