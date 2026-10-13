/*程式設計一 第一次上機模擬，第七題 (2,3分)


完成以下輸出
第一小題，元素要可以向前移動。碰到邊界移動到最後
第二小題，元素必須鏡射對調


第一小題()
範例:
0987654321

輸出範例:
//第一次
9876543210
//第二次
8765432109
//第三次
7654321098

第二小題()
範例:
1234567890

輸出範例:
09887654321


*/

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int Array1[10] = {0,9,8,7,6,5,4,3,2,1};
int Array2[10] = {0,1,2,3,4,5,6,7,8,9};

int main() {
    printf("//--- 第一小題 ---//\n");
    int i = 0;
    while (i < 10) {
        printf("%d", Array1[i]);
        i++;
    }
    printf("\n");


    //作答區
    int j = 0;
    while (j < 3) {
        int k = 0;
        while (k < ) {

        
        }
        j++;
    }



    printf("//--- 第二小題 ---//\n");
    i = 0;
    while (i < 10) {
        printf("%d", Array2[i]);
        i++;
    }
    printf("\n");

    //作答區
    j = 0;
    while (j < ) {

    }


    system("pause");
    return 0;
}

#endif