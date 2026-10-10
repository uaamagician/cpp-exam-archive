// 程式設計一，第一次上機寫題，第 7 題 (3 分)
//
//	 輸入指定輸出的層次，並輸出對應的層次
//     每一個層次顯示對應的數字個數，數字從 123...9，然後再從 0 開始循環
//     提示: 
//        1. 0 的 ASCII 編碼是 48
//        2. 記得使用 % 得到 0 到 9 的循環
//
// 輸入顯示層數: 4
// 	    1
// 	   234
// 	  56789
// 	 0123456
//
//輸入顯示層數: 7
//        1
//       234
//      56789
//     0123456
//    789012345
//   67890123456
//  7890123456789
//

#define P7
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void ps(int m) {
	int i = 1;
	while (i <= m) {
		printf(" ");
		i++;
	}
}

void pc(int h) {
	//int cycleNumber;
	//int j;
	//char ck;
	//j = 1;
	//while (j <= h) {
	//	ck = (cycleNumber % 10) + 48;
	//	printf("%c", ck);
	//	cycleNumber++;

	//	
	//	j++;
	//}
}

int main(void)
{
	int n;
	int i = 1;
	int cycleNumber = 0;
	int j;
	char ck;
	printf("輸入顯示層數 : "); scanf("%d", &n);
	while (i <= n) {
		ps(n - i);
		
		
		j = 1;
		while (j <= (2 * n - 1)) {
			ck = (cycleNumber % 10) + 48;
			printf("%c", ck);
			cycleNumber++;


			j++;
		}
		printf("\n");
		i++;
	}



	system("pause");
	return(0);
}
#endif