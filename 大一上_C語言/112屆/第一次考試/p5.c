// 程式設計一 第一次上機寫題 第 5 題 (3 分)
// 
//  設計一個兌換零錢的程式，讓使用者輸入欲兌換的零錢數目，
//  可兌換硬幣分別是 50、10、5、1 四種，
//  而且輸出時必須由大而小依序的顯示最多的兌換硬幣數目，
//  例如：如果輸入 546 元，則是兌換 10 個 50 元、4 個10元、1 個 5 元跟 1 個1 元。
// 
// 參考以下的輸出結果
//
// 請輸入您的換幣金額: 136
// 可兌換 : 50 圓  2 個
//          10 圓  3 個
//           5 圓  1 個
//           1 圓  1 個
//

#define P
#ifdef P5

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int total, fifty, ten, five, one;
	fifty = ten = five = one = 1;

	printf("請輸入您的換幣金額: "); 	scanf("%d",&total);
	fifty = total / 50;
	ten = (total % 50) / 10;
	five = ((total % 50) % 10) / 5;
	one = (((total % 50) % 10) % 5);


	printf("可兌換: 50 圓%3d 個\n        10 圓%3d 個\n", fifty, ten);
	printf("         5 圓%3d 個\n         1 圓%3d 個\n", five, one);
	system("pause");
	return 0;
}

#endif