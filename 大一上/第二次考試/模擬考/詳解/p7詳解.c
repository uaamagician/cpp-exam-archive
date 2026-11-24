// 程式設計一 第二次上機寫題，第七題 (4分)
//
//   宣告 char str[20]，重複執行下面的動作：
//      1. 輸入一個字串 (沒有空白)
//      2. 輸出該字串反向的結果
//      3. 從字串的頭和尾同時往中間比對：頭尾字元相同就一起刪掉，直到遇到第一組不同的字元為止
//         輸出剩下的中間部分；如果整個字串都被刪完，輸出「完全回文」
//      4. 輸入的字串長度只有 1 時，程式結束
//
//   提示：1. 計算長度使用 strlen，需要 #include <string.h>
//         2. 用兩個變數 i、j 分別從頭、尾開始，兩邊相同就 i 加 1、j 減 1
//         3. 剩下的部分請整段往前移到 str 的開頭，再補上 '\0'，然後輸出 str
//         4. 只使用單層迴圈，三個迴圈前後排列即可
//         輸出結果與下面的參考輸出相同即可。
//   流程提示 (abcxyzcba 為例，字串長度 9)
//      i = 0, j = 8 : a 與 a 相同 -> i = 1, j = 7
//      i = 1, j = 7 : b 與 b 相同 -> i = 2, j = 6
//      i = 2, j = 6 : c 與 c 相同 -> i = 3, j = 5
//      i = 3, j = 5 : x 與 z 不同 -> 停止。剩下 str[3] 到 str[5]，長度是 j - i + 1 = 3
//      搬移：str[0] = str[3]，str[1] = str[4]，str[2] = str[5]，然後 str[3] = '\0'
// ---------------------------------------------------------------------------------------------
//   以下的輸出為本題輸出參考
//   輸入一個字串: abcxyzcba
//   反向: abczyxcba
//   剩下: xyz
//   輸入一個字串: hello
//   反向: olleh
//   剩下: hello
//   輸入一個字串: level
//   反向: level
//   完全回文
//   輸入一個字串: a

#define P7
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[20];
	int i, j, k, len;

	do {
		printf("輸入一個字串: "); scanf("%s", str);
		len = strlen(str);
		if (len > 1) {
			printf("反向: ");
			for (i = len - 1; i >= 0; i--) {
				putchar(str[i]);
			}
			printf("\n");

			i = 0;
			j = len - 1;
			while (i < j && str[i] == str[j]) {
				i++;
				j--;
			}

			if (i >= j) {
				printf("完全回文\n");
			}
			else {
				for (k = 0; k <= j - i; k++) {
					str[k] = str[i + k];
				}
				str[j - i + 1] = '\0';
				printf("剩下: %s\n", str);
			}
		}
	} while (len > 1);

	system("pause"); return(0);
}

#endif

// =================================== 詳解 ===================================
// 1. 考點：字元陣列與字串、strlen、do...while、while 配合 && 提早結束、陣列元素搬移
// 2. 反向輸出：str 的索引是 0 到 len - 1，所以從 len - 1 倒著印到 0
// 3. 剝除外層：i 從頭、j 從尾，while (i < j && str[i] == str[j]) 就一起往中間縮
// 4. 迴圈結束後如果 i >= j，代表整個字串都對稱 (奇數長度剩中間一個，偶數長度兩邊交錯)，印完全回文；否則剩下 str[i] 到 str[j]
// 5. 剩下的部分整段複製到 str 的開頭：str[k] = str[i + k]，k 到 j - i 為止，再補 str[j - i + 1] = '\0'
// 6. 手算驗證 (abcxyzcba)：i=0,j=8 a=a；i=1,j=7 b=b；i=2,j=6 c=c；i=3,j=5 x 不等於 z 停止，剩下索引 3 到 5 的 xyz
// 7. 易錯點：先移動字串再輸出反向，反向就不是原本的字串；移動後忘了補 '\0'，後面會留著舊字元；把 i >= j 寫成 i > j，abba 會漏判；scanf 的 %s 前面不加 &
