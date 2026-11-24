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
	while ((ch = getchar()) != '#') {
		if (ch >= '0' && ch <= '9') {
			digit[ch - '0']++;
		}
		else {
			switch (ch) {
			case 'a': case 'A':
				vowel[0]++;
				break;
			case 'e': case 'E':
				vowel[1]++;
				break;
			case 'i': case 'I':
				vowel[2]++;
				break;
			case 'o': case 'O':
				vowel[3]++;
				break;
			case 'u': case 'U':
				vowel[4]++;
				break;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		if (digit[i] != 0) {
			printf("數字 %d 出現 %d 次\n", i, digit[i]);
		}
	}
	printf("a:%d e:%d i:%d o:%d u:%d\n", vowel[0], vowel[1], vowel[2], vowel[3], vowel[4]);

	system("pause"); return(0);
}

#endif

// =================================== 詳解 ===================================
// 1. 考點：getchar、一維陣列計數、字元運算 ch - '0'、switch 疊 case
// 2. while ((ch = getchar()) != '#')：先讀一個字元存進 ch，再比較；括號不能省
// 3. 數字用 if 判斷範圍 (ch >= '0' && ch <= '9')，因為 switch 的 case 只能是單一常數，不能寫範圍
// 4. ch - '0' 把字元 '0' 到 '9' 對應成 0 到 9，直接當索引：digit[ch - '0']++
// 5. 母音用 switch，大小寫疊在一起：case 'a': case 'A': vowel[0]++; break;
// 6. 輸出時數字只印 != 0 的，母音五個都印
// 7. 手算驗證：I love 2025 apples, 11 eggs，母音 i 在 I；o、e 在 love；a、e 在 apples；e 在 eggs，所以 a 1、e 3、i 1、o 1、u 0；數字 2 兩次、0 一次、5 一次、1 兩次
// 8. 易錯點：陣列沒有歸零，次數從亂數開始；數字判斷漏了引號，寫成 ch >= 0 && ch <= 9，比的是 ASCII 0 到 9；case 後面漏掉 break
