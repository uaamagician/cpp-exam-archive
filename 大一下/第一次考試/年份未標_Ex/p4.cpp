//  程式設計二，第一次上機考試 ，第 4 題 ( 3分 )
// 
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
//  要求：輸出的部分都必須使用所宣告的指標變數 pc、但可將 pc 當成陣列方式來使用
//  對應於 %c 或 %s 的寫法則使用陣列型式或指標型式都可以
//
// 參考輸出如下
// 12345678
// 1A2B3C4D5E6F7G8H
// 3C4D5E6F7G8H
// 5E6F7G8H
// 7G8H
// H1 G2 F3 E4
//
//
// 提示 : 搭配 for 迴圈變數 i 的內容, 切換設定輸出填滿字元
// 

#define P
#ifdef P4

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(void)
{
	int	 i;
	char cD[24] = "1A2B3C4D5E6F7G8H";  // 共 16 個字元，索引值從 0 到 15
	char* ch=cD;				// 宣告字元指標變數 pc
	for (int i = 0; i <= 15;i+=2 ) printf("%c", *(ch+i)); printf("\n");      // 輸出第 1 列的結果	
	for (int i = 0; i <= 15; i += 4) {
		for (int j = i; j <= 15; j++) {
			printf("%c", *(ch + j)); 
		}
		printf("\n");
	}
	for (int i = 15; i > 7; i-=2) printf("%c%c ", *(ch+i),  *(ch+(15-i))); printf("\n"); // 輸出第 6 列的結果

	system("pause"); return(0);
}

#endif