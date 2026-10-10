// 程式設計一 !! 第二次上機考試 !! 第 7 題 (3分)
//
//  str 字串如以下程式碼所示，pat 字串則是接收使用者的輸入
//  寫一個程式從 str 中找出 pat 字串出現的位置，並統計出現的次數
//  請執行兩次，分別輸入如下的兩種 01 組合，並得到相同的結果
//  
//  你會用到 strlen() 函式回傳字串的字元個數
// 
//  參考以下的輸出
// 
//  請六個連續的 0 或是 1 : 011011
//  出現的位置在  0  19  22  38  50  62  70
//  共出現 7 次
//
//  請六個連續的 0 或是 1 : 111001
//  出現的位置在  4  13  26  42  54  66
//  共出現 6 次
//

#define p
#ifdef p7
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[100] = "0110111001110111001011011011100101110001101110011101101110010101101110011011";
	char pat[8];
	printf("請六個連續的 0 或是 1 : "); 
	scanf("%s", pat);
	printf("出現的位置在  ");


	printf("%3d ");



	printf("\n共出現 %d 次\n");
	system("pause"); return(0);
}

#endif