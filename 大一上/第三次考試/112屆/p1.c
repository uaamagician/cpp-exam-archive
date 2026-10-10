// 程式設計一 !! 第三次上機考試 -- 第 1 題 (2+2 分)
//    
// 輸入一段英文句子並以 # 代表結尾，計算並輸出以下各字母出現的次數
// 功能一(兩分)：輸出次數超過 6 次的字母與個數
// 功能二(兩分)：輸出 'b', 'c', 'f', 'i', 't' 這幾個字母的次數 
//  
// 要求：
//      1. 必須宣告一個一維陣列來儲存每一個字母出現的次數
//      2. 功能二必須搭配另外一個陣列來儲存 'a', 'c', 'o', 'r', 'i' 這幾個字母
//         並以迴圈輸出這幾個字母的出現次數
// 
// 計分方式：功能二必須搭配上述要求才算分數
// 
// A special Collection of magical fairy taLes for yOur children to Read reA#
//

//  輸入一段英文句子, 以#代表結尾
// A special Collection of magical fairy taLes for yOur children to Read reA#
// a 出現  8 次
// e 出現  6 次
// l 出現  6 次
// o 出現  6 次
// r 出現  6 次
// 
// 五個字母出現的次數
// 
// b 出現  0 次
// c 出現  5 次
// f 出現  3 次
// i 出現  5 次
// t 出現  3 次
//

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int A[26] = {0};		// 宣告儲存字元出現次數的一為陣列，設定初始值為 0 
	int B[5] = {'b', 'c', 'f', 'i', 't'};		// 宣告儲存 'b', 'c', 'f', 'i', 't' 的陣列
	char ch;		// 接收輸入的字元 
	printf("輸入一段英文句子,以#代表結尾\n");
	
	while ((ch = getchar()) != '#') {
		if (ch >= 65 && ch <= 90) {
			A[ch - 65] += 1;
		}
		else if (ch >= 97 && ch <= 122) {
			A[ch - 97] += 1;
		}
	}
		

	// 提示：字元輸入使用 getchar() 函式

	// 提示：字母大小寫出現的都要算到
	int i;
	for ( i = 0; i < 26; i++)
	{
		if (A[i] >= 6) {
			printf("%c 出現 %2d 次\n", 97+i, A[i]);
		}
	}
	

	printf("\n五個字母出現的次數 \n\n");
	// 僅輸出5個字母的出現次數 
	int j;
	for ( j = 0; j < 5; j++)
	{
		printf("%c 出現 %2d 次\n", B[j], A[B[j] - 97]);
	}
	

	system("pause"); return(0);
}

#endif
//65
//90
//97
//122