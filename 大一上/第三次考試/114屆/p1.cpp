// 程式設計一，第三次上機考試第 1 題 3+(2or3)分
// 
// Part 1( 3分 ): 完成計算組合數的遞迴函式 binomial
//         兩個 int 型別引數 n 與 k, 回傳值為 C(n, k)
//         C(n, k) 計算公式如下: 
//         C(n, k) = 1, ​k = 0 或 k = n (終止條件)
//         C(n, k) = C(n−1,k−1) + C(n−1,k) (大問題變小問題)
//         主程式呼叫 binomial 完成 part1 的輸入與輸出(參考輸出)
//
// Part 2 (2 or 3 分) : 以 binomial 函式為基礎, 輸出指定前 row 數的巴斯卡三角形
//        巴斯卡三角形的第 n row 就是 (a+b)^n 展開後的各項係數
//        (a+b)^n = C(n,0)a^n +  C(n,1)a^(n-1)b + C(n,2)a^(n-2)b^2 + ... + C(n,n)b^n
//        也就是第 n row 要輸出的內容就是
//        C(n,0)  C(n,1)  C(n,2)  C(n,3) ...... C(n,n)
//        完成 part 2 的輸入與輸出，其中
//        達成[一般輸出 2分]，[三角形輸出 3分]。此兩種輸出得分二選一：
//        提示 : 輸出前 8 個 row，就是輸出第 0 到第 7 row 的各項
//               第 0 row 就是 (a+b)^0 = 1
//
//  要求:
//      1. binomial 的函式必須使用遞迴函式
//      2. Part2 的輸出必須透過持續呼叫 binomial 函式來計算巴斯卡三角形中的每個輸出項目
// 參考輸出
// 
// ---------- - part 1 ---------- -
// 輸入組合數 n 取 k 中的 n 與 k : 4 2
// C(4, 2) = 6
// ---------- - part 2 一般輸出 -----------
// 輸入巴斯卡三角形的輸出 row 數 : 8
// 1
// 1     1
// 1     2     1
// 1     3     3     1
// 1     4     6     4     1
// 1     5    10    10     5     1
// 1     6    15    20    15     6     1
// 1     7    21    35    35    21     7     1
// 
// ----------- part 2 三角形輸出 -----------
// 輸入巴斯卡三角形的輸出 row 數 : 8
//                       1
//                    1     1
//                 1     2     1
//              1     3     3     1
//           1     4     6     4     1
//        1     5    10    10     5     1
//     1     6    15    20    15     6     1
//  1     7    21    35    35    21     7     1

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int n, int m) {
    return n > m ? n * factorial(n - 1, m) : 1;
}
int c(int n, int k) {
    return factorial(n, n - k) / factorial(k, 1);
}

int main(){
    int n, k;
    printf("----------- part 1 -----------\n");
    printf("輸入組合數 n 取 k 中的 n 與 k: ");
    scanf("%d %d", &n, &k);
    printf("C(%d, %d) = %d\n", n, k, c(n, k));

    printf("--------- part 2 - 1  ---------\n");
    int layer;
    printf("輸入巴斯卡三角形的輸出 row 數: ");
    scanf("%d", &layer);
    for (int i = 0; i < layer; i++) {
        for (int j = 1; j < layer - i; j++) {
            printf("   ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%3d   ", c(i, j));
        }
        printf("\n");
    }
    printf("\n-----------  2 - 2  -----------\n\n");
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d   ", c(i, j));
        }
        printf("\n");
    }
    printf("\n-----------  2 - 3  -----------\n\n");
    for (int i = layer - 1; i >= 0; i--) {
        for (int j = 1; j < layer-i; j++) {
            printf("      ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%3d   ", c(i, j));
        }
        printf("\n");
    }
    printf("\n-----------  2 - 4  -----------\n\n");
    for (int i = layer-1; i >=0; i--) {
        for (int j = 1; j < layer-i; j++) {
            printf("   ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%3d   ", c(i, j));
        }
        printf("\n");
    }

    return 0;
}
#endif