// 程式設計一 第二次上機寫題，第五題 (4分)
//
//   輸入一段文字，以 # 代表結束，統計：
//      1. 數字 0 到 9 各出現幾次 (只輸出有出現的數字)
//      2. 母音 a e i o u 各出現幾次 (大小寫視為相同)
//   請使用兩個一維陣列存放次數
//
//   提示：1. 用 getchar() 一次讀一個字元，直到讀到 #
//         2. 數字字元 '0' 到 '9'，用 ch - '0' 轉成 0 到 9 當作陣列的索引
//         3. 母音使用 switch，大小寫的 case 疊在一起共用
//         4. 陣列要先歸零：int digit[10] = { 0 };
//         輸出結果與下面的參考輸出相同即可。
//   流程提示
//      while 每讀一個字元，只會走下面三條路的其中一條
//         (1) 是數字  -> digit[ch - '0'] 加 1       (用 if 判斷範圍)
//         (2) 是母音  -> 對應的 vowel 加 1           (用 switch，大小寫疊在一起)
//         (3) 其他字元 -> 什麼都不做                 (switch 沒有符合的 case 就會略過)
//      最後兩個陣列各自用輸出的方式印出來
// ---------------------------------------------------------------------------------------------
//   以下的輸出為本題輸出參考
//   輸入一段文字,以 # 結束:
//   I love 2025 apples, 11 eggs#
//   數字 0 出現 1 次
//   數字 1 出現 2 次
//   數字 2 出現 2 次
//   數字 5 出現 1 次
//   a:1 e:3 i:1 o:1 u:0

#define P5
#ifdef P5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int digit[10] = { 0 };
	int vowel[5] = { 0 };
	int i;
	char ch;

	printf("輸入一段文字,以 # 結束:\n");
	while () {   // 讀一個字元存進 ch，不是 # 才繼續
		if () {   // ch 是數字字元
			// 對應的 digit 次數加 1 (提示：ch - '0')
		}
		else {
			switch (ch) {
			case 'a': case 'A':
				// vowel[0] 加 1
				break;
			case 'e': case 'E':
				// vowel[1] 加 1
				break;
			// i、o、u 也是同樣的寫法，分別放在 vowel[2]、vowel[3]、vowel[4]
			}
		}
	}

	for (i = 0; i < 10; i++) {
		if () {   // 這個數字有出現過
			printf("數字 %d 出現 %d 次\n", , );
		}
	}
	printf("a:%d e:%d i:%d o:%d u:%d\n", , , , , );

	system("pause"); return(0);
}

#endif
