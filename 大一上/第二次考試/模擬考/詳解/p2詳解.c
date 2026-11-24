// 程式設計一 第二次上機寫題，第二題 (2+2分)
//
//   需求一：
//      輸入月份 (1~12)，用 switch 印出季節
//      3、4、5 月為春季，6、7、8 月為夏季，9、10、11 月為秋季，12、1、2 月為冬季
//      輸入其他數字則印出「月份錯誤」
//   需求二：
//      輸入一個算式「整數 運算符號 整數」，運算符號是 + - * / 其中一個，用 switch 算出結果
//      除法請印到小數點後 2 位，除數為 0 時印出「除數不能為 0」
//      運算符號不是這四個時印出「不支援的運算符號」
//
//   計分方式
//      1. 完成需求一，2 分
//      2. 完成需求二，2 分
//
//   提示：多個 case 共用同一段程式時，把 case 疊在一起，最後再寫一個 break
//         scanf 讀運算符號時，%c 前面要留一個空白："%d %c %d"
//         輸出結果與下面的參考輸出相同即可。
// ---------------------------------------------------------------------------------------------
//   以下的輸出為本題輸出參考
//   輸入月份(1~12): 4
//   春季
//   輸入算式(例如 12 / 5): 12 / 5
//   12 / 5 = 2.40
//
//   輸入月份(1~12): 13
//   月份錯誤
//   輸入算式(例如 12 / 5): 8 / 0
//   除數不能為 0

#define P2
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m, a, b;
	char op;

	printf("輸入月份(1~12): "); scanf("%d", &m);
	switch (m) {
	case 12: case 1: case 2:
		printf("冬季\n");
		break;
	case 3: case 4: case 5:
		printf("春季\n");
		break;
	case 6: case 7: case 8:
		printf("夏季\n");
		break;
	case 9: case 10: case 11:
		printf("秋季\n");
		break;
	default:
		printf("月份錯誤\n");
	}

	printf("輸入算式(例如 12 / 5): "); scanf("%d %c %d", &a, &op, &b);
	switch (op) {
	case '+':
		printf("%d + %d = %d\n", a, b, a + b);
		break;
	case '-':
		printf("%d - %d = %d\n", a, b, a - b);
		break;
	case '*':
		printf("%d * %d = %d\n", a, b, a * b);
		break;
	case '/':
		if (b == 0) {
			printf("除數不能為 0\n");
		}
		else {
			printf("%d / %d = %.2f\n", a, b, (float)a / b);
		}
		break;
	default:
		printf("不支援的運算符號\n");
	}

	system("pause"); return(0);
}

#endif

// =================================== 詳解 ===================================
// 1. 考點：switch、case 疊在一起共用、字元 case、型別轉換
// 2. 需求一：case 12: case 1: case 2: 疊在一起，共用同一個 printf 與 break；其他數字走 default
// 3. 需求二：scanf("%d %c %d") 中 %c 前面的空白，會先略過空白字元再讀運算符號，不寫的話會讀到空白或換行
// 4. switch (op) 的 case 後面放字元常數 '+'、'-'、'*'、'/'，不能寫變數或範圍
// 5. 除法要先檢查 b == 0；結果寫 (float)a / b 再用 %.2f 輸出，12 / 5 才會是 2.40
// 6. 手算驗證：4 月走 case 4，印春季；12 / 5 = 2.4，印 2.40；13 月走 default；8 / 0 印除數不能為 0
// 7. 易錯點：每個 case 結尾忘了 break，會一路往下執行；寫成 (float)(a / b)，括號位置錯，先做整數除法結果是 2.00
