// 程式設計一 !! 第二次上機考試 !! 第 2 題 (2+2分)
//
//  輸入一個數，並列出這個數的所有因數(不含1與本身)
//  同時計算這個數所有因數(不含1與本身)的和與積(不含1與本身)
//
// 計分方式
//   1. 輸出因數與個數     (2 分)
//   2. 完成因數和與因數積 (2 分)
//
// 以下為輸出參考(提示：因數積輸出若非以下的數值，就是【整數溢位】了)
// 提示 ： 因數的乘積使用 float 來儲存，輸出時搭配 %f
//
// 輸入一個數: 144
//   2   72    3   48    4   36    6   24    8   18    9   16   12 共 13 個因數
//   所有的因數和   258 因數積 106993205379072
//

#define p2
#ifdef p2

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int i = 2;
	int k[20] = { 0 };
	int ingPlace = 0;
	int ingCount = 0;
	float sum = 0;
	int pro = 0;

	printf("輸入一個數 : "); scanf("%d", &n);

	while (i * i < n) {
		if (n % i == 0) {
			k[ingPlace] = n / i;
			k[ingPlace + 1] = n / k[ingPlace];
			printf(" %4d %4d", k[ingPlace], k[ingPlace + 1]); // 2 個因數
			ingPlace += 2;
			ingCount += 2;
			i++;
		}
		else {
			i++;
		}
	}
	if (i * i == n) {
		k[ingPlace] = i;
		ingCount += 1;
		printf(" %4d", k[ingPlace]);  // 1 個因數
	}

	ingPlace = 0;
	while (ingPlace <= 20) {
		sum += k[ingPlace];
		ingPlace++;
	}

	
	



	printf(" 共 %d 個因數\n", ingCount);
	printf("所有的因數和 %5.0f 因數積 %10.0f\n", sum, pro);
	system("pause"); return(0);
}

#endif