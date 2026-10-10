// 程式設計一 !! 第二次上機考試 !! 第 6 題 (3分)
//
//  讀取以下的英文段落(不含負責註解的/**/)，並輸出以下各需求的字元個數，
/*
I used MidJourney to make Nintendo characters out of paper.
What do you think ? Do you have a favourite ? --------------
If you work for an agency looking to grow on LinkedIn,--------
#creative1 #nintendo2 #pokemon3 #ai4 #aiart5 #midjourney6 #v4@
*/
//  1. 英文字母 n (含大小寫)的次數
//  2. 英文字母 i (含大小寫)的次數
//  3. - 字元的出現的次數
//  4. # 字元出現的次數
//
// 要求：
//   1. 使用 switch case 來分類要計算的的字元出現次數
//
// 參考輸出
//輸入一段英文句子, 以 @ 代表結尾
// I used MidJourney to make Nintendo characters out of paper.
// What do you think ? Do you have a favourite ? --------------
// If you work for an agency looking to grow on LinkedIn, --------
// #creative1 #nintendo2 #pokemon3 #ai4 #aiart5 #midjourney6 #v4@
// 各字元出現的個數:   N    I    -     #
//                     16   14   22    7

#define P
#ifdef P6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch;
	int nc, ic, mc, sc;
	nc = ic = mc = sc = 0;

	printf("輸入一段英文句子, 以 @ 代表結尾\n");
	while ( (ch = getchar()) != '@')	/* 讀取字元後進行換行字元的判斷 */
	{
		switch (ch)
		{
			case 'n':
			case 'N':
				nc++;
				break;
			case 'i':
			case 'I':
				ic++;
				break;
			case '-':
				mc++;
				break;
			case '#':
				sc++;
				break;
			default:
				break;
		}
	}
	printf("各字元出現的個數:   N    I    -     #\n");
	printf("                  %4d %4d %4d %4d  \n", nc, ic, mc, sc);
	system("pause"); return 0;
}

#endif

