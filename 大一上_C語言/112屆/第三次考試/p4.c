// 程式設計一 !! 第三次上機考試 -- 第 4 題 (4 分)
//
// 撰寫 gT 與  pT 函式，這兩個函式都只有一個二維陣列維的引數
// gT  負責產生 5 * 5 的乘法表
//     並同時將乘法表的內容每一個row，從右到左加總到最左邊的的儲存格內
// pT  輸出所傳入的二維陣列乘法表，執行如下的功能
//
// 符合以下的要求並輸出正確才算分數：
// 1. 主程式內，記得陣列的陣列的宣告 column 要多一個，以儲存每一個 row 的加總結果
// 2. gT 與 pT 函式主體必須寫在主程式之後，所以必須宣告對應的原型宣告
// 3. gT 與 pT 函式的第一個引數必須是二維陣列，
//		第二與第三個引數分別是 n 與 m (int 型別) ，分別代表陣列的 row 與 column
//      兩個函式內的 for 迴圈的終止條件必須是傳入的 n 與 m
// 4. 二維陣列必須宣告在主程式中，且必須使用函式傳遞二維陣列的方式
// 5. 不能使用全域變數
// 
//  參考以下的輸出
// 1     2     3     4     5    15
// 2     4     6     8    10    30
// 3     6     9    12    15    45
// 4     8    12    16    20    60
// 5    10    15    20    25    75
//

#define p
#ifdef p4

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// gT 與 pT 的原型宣告放在這裡
void gT(int [][6], int, int);
void pT(int[][6], int, int);





int main(void)
{
	int AA[5][6] = { 0 };					// 宣告二維陣列，同時設定初始值為 0
	gT(AA, 5, 6);				// 呼叫 gT 將陣列 AA 傳過去，以及 5 跟 5 傳遞過去
	pT(AA, 5, 6);				// 呼叫 pT 將陣列 AA 傳過去，以及 5 跟 5 傳遞過去
	system("pause");
	return(0);
}

// gT 與 pT 的函式主體放在這裡
void gT(int AA[][6], int n, int m) {
	int i, j;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m-1; j++)
		{
			AA[i][j] = (i + 1) * (j + 1);
			AA[i][m - 1] += AA[i][j];
		}
	}

}

void pT(int AA[][6], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%5d ", AA[i][j]);
		}
		printf("\n");
	}

}


	
	

#endif