// 程式設計一 !! 第二次上機考試 !! 第 8 題 (4 分)
// 
//  str 字串如以下程式碼所示
//  寫一個程式對 str 進行內容壓縮，例如：aaaabbbccd 輸出成 a4b3c2d1
//  假設單一字母不連續出現不超過 10 次
// 
//  要求：必須將壓縮的字串儲存到 str2 中，最後在輸出 str2 中的結果
//
//  輸出參考
//  原始字串 : aafkkkkkddddm
//  壓縮字串 : a2f1k5d4m1
//

#define P
#ifdef P8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char str1[80] = "aafkkkkkddddm";
    char str2[80];


    printf("原始字串: %s\n", str1);
    printf("壓縮字串: %s\n", str2);

    return 0;
}
#endif