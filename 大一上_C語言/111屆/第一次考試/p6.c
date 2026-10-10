// 程式設計一 第一次上機寫題，第六題 (3 分)
//
//  讓使用者輸入一段文字，以迴圈依序兩兩交換儲存在字元陣列中的字元，
//	並在每次交換後輸出交換後的字串陣列內容。
// 
//	要求：必須以 strlen 來取得字串的長度，迴圈的執行次數必須以這個長度為依據
// 
// 參考輸出如下：
// 
//  輸入一段文字: 01-1-1-1
//  01-1-1-1
//  10-1-1-1
//  1-01-1-1
//  1-10-1-1
//  1-1-01-1
//  1-1-10-1
//  1-1-1-01
//  1-1-1-10
//

#define E
#ifdef E6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
				// 宣告字元陣列, 建議可存放 20 個元素

	printf("輸入一段文字: "); scanf("%s", ); // 輸入一段文字
	printf("%s\n", );
							// 使用 strlen 取得的字串長度
					// while 條件判斷一定要用到由 strlen 所取得的字串長度
	
	printf("%s\n", );


	system("pause");
	return(0);
}


#endif