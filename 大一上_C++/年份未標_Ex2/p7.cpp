

// 程式設計一 !! 第二次上機考試 !! 第 7 題 (4分)
// 
// 完成以下的功能與對應的輸出
// 1. 初始化一個字元陣列, 長度為 41，裡面僅包含 40 個 0 或 1
//    初始內容為 1100110100101110010110101100100111010011
// 2. 以 4 個字元為一組形成一個一個二進位數值，計算對應的 10 個數值, 之後再輸出此組數值的加總
// 3. 以 5 個字元為一組形成一個一個二進位數值，計算對應的  8 個數值, 之後再輸出此組數值的加總
// 4. 上述的 2 與 3 各轉換數值結果先儲存到陣列中，之後以迴圈讀取這個陣列進行加總再輸出
// 5. 二進位轉換成 10 進位,不能使用任何內建函式, 必須以迴圈來完成轉換
// 6. 4 與 5 的改變必須以迴圈來完成
// 
// 參考輸出
// 輸入字串: 1100110100101110010110101100100111010011
// 4個一組     12  13   2  14   5  10  12   9  13   3  加總 = 93
// 5個一組      25   20   23    5   21   18   14   19  加總 = 145
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    char input[41];
    int sum, num[10] = { 0 };



    printf("輸入字串 : ");
    scanf("%s", input);
    for (int i = 4; i <= 5; i++) {

        printf("%2d個一組   ", i);
        for (int j = 0; j < 40 / i; j++) {
            sum = 0;
            int buffer = 1;
            for (int k = i - 1; k >= 0; k--) {
                sum += buffer * (input[i * j + k] - '0');
                buffer *= 2;
            }
            if (i == 4) printf("%4d", sum);
            else printf("%5d", sum);
            num[j] = sum;
        }


        sum = 0;
        for (int j = 0; j < 40 / i; j++) {
            sum += num[j];
        }
        printf("  加總 = %d\n", sum);
    }
    return 0;
}

#endif