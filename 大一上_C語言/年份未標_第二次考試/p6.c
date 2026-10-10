// 程式設計一 !! 第二次上機考試 !! 第 6 題 (3分)
//
//  讀取以下的英文段落(不含負責註解的/**/)，並輸出以下各需求的字元個數
/*
Within calm waters, under Bright Skies, people sTroll along pathways lined wiTh Trees.
These scenes hold momenTs alive with hope, where kind words inspire And uniTe. Birds chirp,
breezes stir leaves, and SunShine graces the landscape. In this setTing, life, vibranT and peAceful,
holds Wonders that Thrill and soothe minds alike.#
*/
//
// 要求：
//   1. 使用 switch case 來分類要計算的的字元出現次數
//
// 參考輸出
// 輸入一段英文句子, 以 # 代表結尾
// Within calm waters, under Bright skies, people sTroll along pathways lined with trees.
// These scenes hold momenTs alive with hope, where kind words inspire And uniTe.Birds chirp,
// breezes stir leaves, and SunShine graces the landscape.In this setTing, life, vibranTand peAceful,
// holds Wonders that Thrill and soothe minds alike.#
// ABTS與空白各有:   A    B    T    S   空白
//                  18    4   21   26   47
//
// 你會用到的指令 getchar()、switch...case...break;
// 

#define P
#ifdef P6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch;

	printf("輸入一段英文句子, 以 # 代表結尾\n");
	int ia ,ib, it, is, ispace;
	ia = ib = it = is = ispace = 0;
	while ( (ch = getchar())!='#')	/* 讀取字元後進行換行字元的判斷 */
	{
		switch (ch)
		{
		case 'a':
				ia++;
				break; 
		case 'A':
				ia++;
				break;
		case'b':
				ib++;
				break;
		case'B':
			ib++;
			break;
		case't':
				it++;
				break;
		case'T':
			it++;
			break;
		case's':
				is++;
				break;
		case'S':
			is++;
			break;
		case ' ':
			ispace++;
			break;
		}
	}
	printf("ABTS與空白各有:   A    B    T    S   空白\n");
	printf("               %4d %4d %4d %4d %4d \n", ia,ib ,it ,is ,ispace );
	system("pause"); return 0;
}

#endif

