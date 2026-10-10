// 程式設計一 !! 第三次上機考試 -- 第 8 題 (5 分)
//
// 讓使用者輸入一個字串，並反向輸出所輸入的字串
// 當使用者輸入的字串長度為 1 時，則停止程式的執行
// 
// 計分要求：必須以 %s 輸出反轉後的字串
// 
// 提示: 另外宣告一個字元陣列來儲存反轉後的字串
//       查詢字串的長度使用 strlen
//		 將字元陣列當成該函示呼叫的引數就能得到該字串的長度
// 
// 輸出參考
// 
// 輸入一個字串 : string
// 該字串的反向 : gnirts
// 輸入一個字串 : win
// 該字串的反向 : niw
// 輸入一個字串 : q
// 該字串的反向 : q
//
   
#define p
#ifdef p8

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int len;
	char A[20];// 記得宣告儲存字串長度的變數
	char B[20];		// 宣告接收與負責輸出字串
	do
	{
		printf("輸入一個字串: ");
		scanf("%s", A);
		len = strlen(A);
		int i;
		for ( i = 0; i < len; i++)
		{
			B[len - 1 - i] = A[i];
		}
		B[len] = '\0';
		printf("該字串的反向:");

		printf("%s\n", B);

	} while (len > 1);		// 記得使用 do...while(); 指令
		
			// 計算字串長度
		

		// 記得輸出的字元陣列最後一個儲存格補上一個 null 字元 '\0'
		

	// 輸入超過一個字元才會繼續

	system("pause"); return(0);
}


#endif
