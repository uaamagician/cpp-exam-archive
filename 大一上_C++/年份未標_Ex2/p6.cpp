// 程式設計一 !! 第二次上機考試 !! 第 6 題 (4分)
//
// 持續的輸入字串，當長度為 1 時, 停止以下的輸出
// 1. 以 scanf 搭配 %s 將輸入的字串儲存到字元陣列中, 例如 str1
// 2. 將 str1 反向(字串尾到字串頭)儲存到另外一個字元陣列中(例如 str2), 
// 3. 以 printf 搭配 %s 輸出 str2 的內容
// 例如 : 輸入為 1234, 則 str2 中儲存的是 4321
//
// 要求:上述 2 與 3 的要求完成輸出才算分數
// 需要用到 strlen() 函式, 傳入一個字串，此函式會回傳該字串的長度
// 提示: 記得 str2 最後要補上一個 '\0'
//
// 輸出參考
// 輸入一個字串 : 12345
// 該字串的反向 : 54321
// 輸入一個字串 : qwer
// 該字串的反向 : rewq
// 輸入一個字串 : q
// 該字串的反向 : q


#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char str1[20], str2[20]; 
	int i;
	do {
		printf("輸入一個字串: ");
		scanf("%s",str1 );
		printf("該字串的反向: ");
		for (i = strlen(str1); i >=0 ; i--) {
			str2[strlen(str1) - i - 1] = str1[i];
		}						
				
		str2[strlen(str1)] = '\0';						
		printf("%s\n", str2);
	} while (strlen(str1)!=1);			
	return(0);
}

#endif
