/*程式設計一 第一次上機模擬，第八題 (4分)

解讀該由二進位碼構成的ASCII陣列
(每八個為一組)(共6字)
011001100110100101101110011010010111001101101000

*/

#define P8
#ifdef P8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Array[48] = {
    0,1,1,0,0,1,1,0, 
    0,1,1,0,1,0,0,1, 
    0,1,1,0,1,1,1,0, 
    0,1,1,0,1,0,0,1, 
    0,1,1,0,0,0,1,1, 
    0,1,1,0,1,0,0,0  
};
char Word[10] = { 0 };
int main() {
    int i = 0;
    int j = 0;
    while (j < 6) {
        while (i < 8) {
            Word[j] <<= 1;
            Word[j] |= Array[j * 8 + i];
            i++;
        }
        i = 0;
        j++;
    }
    }//解析陣列

    printf("%s\n",Word);//列印出答案
    system("pause");
    return 0;
}


#endif