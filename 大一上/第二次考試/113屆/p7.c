// 程式設計一 !! 第二次上機考試 !! 第 7 題 (4 分)
//
//  str 字串如以下程式碼所示，pat 字串則是接收使用者的輸入
//  寫一個程式從 str 中找出 pat 字串出現的位置，並統計出現的次數
//  以迴圈執行兩次，分別輸入如下的兩種 01 組合，並得到相同的結果
//
// 輸入6個連續的 0 或是 1 : 010101
// 出現的位置在   14  16  23  25  53  55  68
// 共出現 7 次
//
// 輸入6個連續的 0 或是 1 : 101010
// 出現的位置在   15  17  24  26  54  56  69
// 共出現 7 次
//
//
// 你會用到的指令 strlen()
//

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[100] = "001010010110100101010100101010100011010010100010010100101010100101000101010010";
	char pat[7];


	while(   ) {
		printf("輸入6個連續的 0 或是 1 : "); scanf("%s", pat);
		rewind(stdin);

		printf("出現的位置在  ");
		printf("%3d ", i);

		printf("\n共出現 %d 次\n",);
	}
	system("pause"); return(0);
}

#endif