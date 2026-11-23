// 程式設計一，第三次上機寫題，第 8 題 (4 分)
//
// 八個皇后問題(Eight Queen Problem)
// 在 8×8 的西洋棋棋盤上放置八個皇后，使得任何一個皇后都無法直接吃掉其他的皇后
// 也就是某一個放置皇后的地方，在其【米】字展開的範圍內，都不能有其他的皇后存在
// 寫一個程式，輸出四、六與八個皇后放置方式的一個放法，參考如下的輸出
// 
// 要求: 不能使用遞迴呼叫來實現需求
// 
// 參考輸出
// 
// 4X4 放置方式之一如下 :
// 0  0  1  0
// 1  0  0  0
// 0  0  0  1
// 0  1  0  0
//
// 6X6 放置方式之一如下 :
// 0  0  1  0  0  0
// 0  0  0  0  0  1
// 0  1  0  0  0  0
// 0  0  0  0  1  0
// 1  0  0  0  0  0
// 0  0  0  1  0  0
//
// 8X8 放置方式之一如下 :
// 0  0  1  0  0  0  0  0
// 1  0  0  0  0  0  0  0
// 0  0  0  0  0  0  1  0
// 0  0  0  0  1  0  0  0
// 0  0  0  0  0  0  0  1
// 0  1  0  0  0  0  0  0
// 0  0  0  1  0  0  0  0
// 0  0  0  0  0  1  0  0
//

#define us
#ifdef use
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

bool A[8][8] = { 0 };
int B[9] = { 0 };

void print(int size) {
	for (int k = 0; k < size; k++)A[k][B[k]] = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
	//for (int i = 0; i < size; i++) printf("%3d", B[i]);
	memset(A, 0, sizeof(A));
	printf("\n\n");
}

bool eliminate(int size) {
	int num;
	for (int n = 0; n < size; n++) {
		num = B[n];
		for (int i = n + 1; i < size; i++) {
			if (B[i] == num)return false;
			if (B[i] == num + (i - n))return false;
			if (B[i] == num - (i - n))return false;
		}
	}
	return true;
}

int main() {
	if (eliminate(6))print(6);
	for (int size = 4; size <= 8; size += 2) {
		printf("----%dx%d layer----\n", size, size);
		while (1) {
			for (int i = 0; i < size; i++) {
				if (eliminate(size))print(size);
				B[0]++;
			}
			for (int i = 0; i < size; i++) {
				if (B[i] == size) {
					B[i + 1]++;
					B[i] = 0;
				}
			}
			if (B[size] == 1)break;
		}
		memset(B, 0, sizeof(B));
	}
	return 0;
}

#endif