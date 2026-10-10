// 程式設計一 !! 第二次上機考試 !! 第 3 題 (3+2分)
//
//  讀取以下的英文段落(不含負責註解的/**/)，並完成以下的輸出
//  1. 輸出出現次數介於 10 到 19 次而且是偶數次數的英文字母與對應次數 (3分)
//  2. 輸出 x g z k 這四個英文字母與次數 (2分)
// 
//  第 2 項的計分, 必須完成以下的要求才給分
//  1. 將 x g z k 這四個英文字母儲存在字元陣列中
//  2. 以迴圈的方式存取這個字元陣列在輸出對應的內容

/*
Within calm waters, under Bright Skies, people sTroll along pathways lined wiTh Trees.
These scenes hold momenTs alive with hope, where kind words inspire And uniTe. Birds chirp,
breezes stir leaves, and SunShine graces the landscape. In this setTing, life, vibranT and peAceful,
holds Wonders that Thrill and soothe minds alike.#
*/
//
//
// 參考輸出
// 輸入一段英文句子, 以 # 代表結尾
// Within calm waters, under Bright Skies, people sTroll along pathways lined wiTh Trees.
// These scenes hold momenTs alive with hope, where kind words inspire And uniTe.Birds chirp,
// breezes stir leaves, and SunShine graces the landscape.In this setTing, life, vibranTand peAceful,
// holds Wonders that Thrill and soothe minds alike.#
// a 出現 18次
// d 出現 14次
// l 出現 16次
// r 出現 16次
// x 出現  0次
// g 出現  4次
// z 出現  1次
// k 出現  3次
//a=97 A=65

// 提示: 你需要 getchar() 函式

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(){
	char i, xgzk[4] = { 'x','g','z','k' };
	int counter[26] = { 0 }, xgzk_count[4] = { 0 };

	printf("輸入一段英文句子, 以 # 代表結尾\n");
	while ((i = getchar()) != '#') {
		if (i - 'a' >= 0 && i - 'a' <26) {
			counter[i - 'a'] ++;
		}
		if (i - 'A'>=0 && i - 'A' <26) {
			counter[i - 'A'] ++;
		}
		for (int j = 0; j < 4; j++) {
			if (xgzk[j] == i) {
				xgzk_count[j] ++;
			}
		}
	}
	for (int j = 0; j < 26; j++) {
		if (counter[j] > 10 && counter[j] < 19 && counter[j] % 2 == 0) {
			printf("%c 出現 %2d次\n", j+'a', counter[j]);
		}
	}
	for (int j = 0; j < 4; j++) {
		printf("%c 出現 %2d次\n", xgzk[j], xgzk_count[j]);
	}



	return 0;
}

#endif

