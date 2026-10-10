// 程式設計一 !! 第二次上機考試 !! 第 2 題 (3分)
//
//  讀取以下的英文段落(不含負責註解的/**/)，並輸出以下各需求的字元個數，
/*
I used MidJourney to make Nintendo characters out of paper.
What do you think ? Do you have a favourite ? --------------
If you work for an agency looking to grow on LinkedIn,
we can help you : https://ln123kd000.com/ejUcQVEy7 --------
#creative1 #nintendo2 #pokemon3 #ai4 #aiart5 #midjourney6 #v4@
*/
//  1. 英文字母 n (含大小寫)的個數
//  2. 英文字母 i (含大小寫)的個數
//  3. 數字字元的出現個數
//  4. 空白字元的出現的個數
//  5. 除了英文、空白與 @ 以外的字元的出現個數
//
// 提示：
//   1. CR 與 LF 的 ASCII 的編碼是 13 與 10，第 5 個需求的字元計算不包含這兩個字元
//   2. 善用 if...else if 計算前四個需求，第五個需求放到最後的 else 中再計算
//   3. 第 5 個需求可用排除法，最後計算總字元數時記得將【數字字元】納入計算
//   4. 你會需要用到 getchar() 函式
//
// 參考輸出
// 輸入一段英文句子, 以 @ 代表結尾
// I used MidJourney to make Nintendo characters out of paper.
// What do you think ? Do you have a favourite ? --------------
// If you work for an agency looking to grow on LinkedIn,
// we can help you : https://ln123kd000.com/ejUcQVEy7 --------
// #creative1 #nintendo2 #pokemon3 #ai4 #aiart5 #midjourney6 #v4@
// 各字元出現的個數:   N    I    0-9   空白  其他
//                     18   14   14    42     53

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch;
	int Nn = 0, Ii = 0, m = 0, s = 0,a = 0;
	printf("輸入一段英文句子, 以 @ 代表結尾\n");
	while ((ch = getchar()) != '@')
	{
		if (ch == 'n' || ch == 'N')
		{
			Nn++;
		}
		else if (ch == 'i' || ch == 'I')
		{
			Ii++;
		}
		else if (ch >= 48 && ch <= 57)
		{
			m++;
		}
		else if (ch == ' ')
		{
			s++;
		}
		else
		{
			if ((ch < 'a' || ch>'z') && (ch < 'A' || ch >'Z') && ch != 13 && ch != 10)
			{
				a++;
			}

		}
	}

	printf("各字元出現的個數:   N    I    0-9   空白  其他\n");
	printf("                  %4d %4d %4d  %4d   %4d \n",Nn,Ii,m,s,a);


	system("pause"); return 0;
}

#endif

