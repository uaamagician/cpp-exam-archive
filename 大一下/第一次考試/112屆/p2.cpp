//  程式設計二，第一次上機考試 ，第 2 題 (3 分)
// 
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
//  要求：輸出的部分都必須使用所宣告的指標變數 pc、但可將 pc 當成陣列方式來使用
//  對應於 %c 或 %s 的寫法則使用陣列型式或指標型式都可以
// 
// 參考輸出如下
//	A1
//	B2A1
//	C3B2A1
//	D4C3B2A1
//	FEDCBA
//	1B4E

#define P
#ifdef P2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(void)
{

	int	 i;
	char cDigit[15] = "F6E5D4C3B2A1";
	char* pc;		// 宣告字元指標變數 pc
	pc = cDigit;		// 以 pc 指向 cDigit 字元陣列開頭
	for (i = 10; i >= 4; i -= 2) printf("%s\n", pc+i);  // 輸出第 1 到 第 4 列的結果
	for (i = 0; i <= 10; i += 2) printf("%c", pc[i]); printf("\n");  // 輸出第 5 列的結果
	for (i = 11; i >= 2; i -= 3) printf("%c", pc[i]); printf("\n");// 輸出第  6 列的結果	

	system("pause"); return(0);
}

#endif