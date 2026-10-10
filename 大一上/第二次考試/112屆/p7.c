// 程式設計一 !! 第二次上機考試 !! 第 7 題 (5 分)
// 
//  寫一個迴圈讓玩家輸入1 2 3，分別代表剪刀、石頭、布
//  利用隨機亂數讓電腦出拳，根據玩家的輸入與電腦的出拳，
//	判斷並輸出輸贏的結果與對應贏家贏的次數，
//	直到有一邊贏的次數為三次則結束程式的執行。
//
//  要求：必須滿足以下的要求，完成指定功能才算分數
//  1. 判斷使用者的輸入必須使用 switch ... case。
//  2. 依照兩邊輸入的結果判定輸贏，並輸出贏的一方目前贏的次數。
//     請依照所給予的輸出作為程式的一部分。
// 
// 參考以下的輸出結果
// 你出的是 1:剪刀, 2 : 石頭, 3 : 布 1
// 你出剪刀, 電腦出剪刀, 平手!
// 
// 你出的是 1 : 剪刀, 2 : 石頭, 3 : 布 2
// 你出石頭, 電腦出剪刀, 你贏了 1 次!
// 
// 你出的是 1 : 剪刀, 2 : 石頭, 3 : 布 3
// 你出布, 電腦出石頭, 你贏了 2 次!
// 
// 你出的是 1 : 剪刀, 2 : 石頭, 3 : 布 1
// 你出剪刀, 電腦出剪刀, 平手!
//
// 你出的是 1 : 剪刀, 2 : 石頭, 3 : 布 2
// 你出石頭, 電腦出剪刀, 你贏了 3 次!
//
// 請按任意鍵繼續 . . .
//

#define p
#ifdef p7
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{

	srand((unsigned)time(NULL));
	int cw = 0;
	int pw = 0;
	int com;
	int player;

	while ( pw < 3 && cw < 3)
	{
		com = rand() % 3 + 1; // 以 rand 取得亂數, 再轉成1,2,3 成為電腦的出拳狀態
		printf("你出的是 1:剪刀, 2:石頭, 3:布 "); scanf("%d", &player);
		switch (player)
		{
			case 1 :
				if (com == 1) {
					printf("你出剪刀,");
					printf("電腦出剪刀,");
					printf("平手!\n\n");

				}
				else if (com == 2) {
					printf("你出剪刀,");
					printf("電腦出石頭,");
					cw++;
					printf("電腦贏了% d 次!\n\n",cw);
				}
				else {
					printf("你出剪刀,");
					printf("電腦出布,");
					pw++;
					printf("你贏了 %d 次!\n\n", pw);
				}
				break;
			case 2 :
				if (com == 1) {
					printf("你出石頭,");
					printf("電腦出剪刀,");
					pw++;
					printf("你贏了 %d 次!\n\n", pw);
				}
				else if (com == 2) {
					printf("你出石頭,");
					printf("電腦出石頭,");
					printf("平手!\n\n");
				}
				else {
					printf("你出石頭,");
					printf("電腦出布,");
					cw++;
					printf("電腦贏了% d 次!\n\n",cw);
				}
				break;
			case 3 :
				if (com == 1) {
					printf("你出布,");
					printf("電腦出剪刀,");
					cw++;
					printf("電腦贏了% d 次!\n\n", cw);
				}
				else if (com == 2) {
					printf("你出布,");
					printf("電腦出石頭,");
					pw++;
					printf("你贏了 %d 次!\n\n", pw);
				}
				else {
					printf("你出布,");
					printf("電腦出布,");
					printf("平手!\n\n");
				}
				break;
		}
	}
	system("pause");
	return 0;
}

#endif

//
// printf("你出剪刀,");
// printf("你出石頭,");
// printf("你出布,");
// printf("電腦出剪刀,");
// printf("電腦出石頭,");
// printf("電腦出布,");
// printf("平手!\n\n");
// printf("電腦贏了% d 次!\n\n");
// printf("你贏了 %d 次!\n\n");
//