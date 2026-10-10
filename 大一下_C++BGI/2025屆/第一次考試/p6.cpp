//  程式設計二，第一次上機考試 ，第 6 題 (4 分)
//
//   開啟並讀取 story.txt 的內容，讀取時同時顯示在螢幕上
//	 計算並輸出以下的內容
//		英文字母(含大小寫)出現的次數
//      字母 o (含大小寫)出現的次數
// 
//   計分方式：能輸出 story.txt 的內容才開始算分
//   參考以下的輸出(不用理會最後輸出的一個奇怪字元)
// Harry Potterand the Philosopher's Stone is a fantasy novel written by British author J.K.Rowling.
// The first novel in the Harry Potter series and Rowling's debut novel, it follows Harry Potter,
// a young wizard who discovers his magical heritage on his eleventh birthday,
// when he receives a letter of acceptance to Hogwarts School of Witchcraftand Wizardry.
// Harry makes close friendsand a few enemies during his first year at the school, and with the help of his friends,
// Harry faces an attempted comeback by the dark wizard Lord Voldemort,
// who killed Harry's parents, but failed to kill Harry when he was just fifteen months old.
//
// 共 510 個英文字母，o 出現 36 次
//
// 你會用到的型別與函式
// FILE 型別
// fopen(,) 開啟檔案
// fclose() 關閉檔案
// feof()   判斷檔案是否已經到檔案尾，() 裡面放檔案指標變數，記得前面要加上 !
// fgetc()  從檔案讀取一個字元，() 裡面放檔案指標變數
// putchar(ch) 輸出 ch 所儲存的字元

#define P
#ifdef P6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch;		// 存放讀取的字元
	FILE *pfile;				// 以 FILE 宣告指向檔案的結構指標 pfile
	int n =0;
	int no = 0;
	pfile = fopen("story.txt", "r");				// 以 fopen 開啟 story.txt 並以設定為讀取 "r"
	if ( pfile == NULL) {  // 判斷檔案是否開啟失敗
		printf("story.txt 檔案無法開啟"); system("pause"); return(0);
	}

	while (! feof(pfile) ) {	// 判斷是否讀到檔案尾
		ch =fgetc(pfile);				// 以 fgetc 讀取一個字元，回傳值給 ch
		putchar(ch);			// 以 putchar 輸出讀取的字元
		if (ch>='A'&&ch<='Z')
		{
			n++;
		}				// 計算英文字母出現的次數
		if (ch >= 'a' && ch <= 'z')
		{
			n++;
		}
		if (ch == 'o'|| ch =='O')
		{
			no++;
		}
						// 計算英文字母 o 出現的次數

	}
	printf("\n\n\n共 %d 個英文字母，o 出現 %d 次\n", n ,no );

	fclose(pfile); // 關閉檔案
	system("pause"); return(0);
}

#endif