//  程式設計二，第一次上機考試 ，第 6 題 (4 分)
//
//   開啟並讀取 story.txt 的內容，讀取時同時顯示在螢幕上
//	 計算並輸出以下的內容
//		母音字母共出現的次數
//		出現超過 50 次以及出現 5 次或 0 次的英文字母
// 
//   計分方式：能輸出 story.txt 的內容才開始算分
// 
//  參考以下的輸出
//
// In the book, Rowling introduces an eclectic cast of characters.The first character to be introduced is
// Vernon Dursley, Harry's uncle. Most of the actions centre on the eponymous hero [Harry Potter, an orphan
// who escapes his miserable childhood with the Dursley family. Rowling imagined him as a "scrawny,
// black-haired, bespectacled boy who didn't know he was a wizard"[3] and says she transferred part of her
// pain about losing her mother to him.[8] During the book, Harry makes two close friends, Ronald Weasley and
// Hermione Granger. Ron is described by Rowling as the ultimate best friend, "always there when you need him".[5]
// Rowling has described Hermione as a "very logical, uprightand good" character with "a lot of insecurity and
// a great fear of failure beneath her swottiness".[6]
//
// 母音出現 227 次
// 
// A 出現 54 次
// E 出現 71 次
// R 出現 56 次
// J 出現 0 次
// K 出現 5 次
// Q 出現 0 次
// X 出現 0 次
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
	char ch;	// 存放讀取的字元
	FILE* pfile;			// 宣告指向檔案的結構指標
	char atoz[26] = { 0 };			// 宣告一維陣列來儲存英文字母出現的次數

	pfile = fopen("story.txt", "r");			// 開啟 story.txt 為讀取 "r"
	if ( pfile == NULL) {  // 判斷檔案是否開啟失敗
		printf("story.txt 檔案無法開啟"); system("pause"); return(0);
	}
	while (	!feof(pfile)) {	// 判斷是否讀到檔案尾
		ch = fgetc(pfile);				// 讀取一個字元
		putchar(ch);					// 輸出讀取的字元
		if (ch >= 'a' && ch <= 'z') {					// 計算大小寫出現的次數
			atoz[ch - 'a']++;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			atoz[ch - 'A']++;
		}
	}

	// 計算母音出現的次數
	int tot = 0;
	tot += atoz['a' - 'a'];
	tot += atoz['e' - 'a'];
	tot += atoz['i' - 'a'];
	tot += atoz['o' - 'a'];
	tot += atoz['u' - 'a'];
	printf("\n\n母音出現 %d 次\n", tot);


	for ( int i = 0; i < 26; i++)
	{
		if (atoz[i] >= 50) {
			printf("%c 出現 %d 次\n", i + 65, atoz[i]);
		}
		else if (atoz[i] == 0) {
			printf("%c 出現 %d 次\n", i + 65, 0);
		}
		else if (atoz[i] == 5) {
			printf("%c 出現 %d 次\n", i + 65, 5);
		}
	}
	

	fclose(pfile);		// 關閉檔案
	system("pause"); return(0);
}

#endif