//  注意：本題與第 8 題，選一題作答即可，兩題都寫只會以高分題為依據，兩題分數不會相加
// 
//  程式設計二，第一次上機考試 ，第 9 題 (10 分) 
// 
//  計分方式：第一個部分 7 分，第二個部分 3 分
// 
// 宣告 tNode 結構，裡面包含 2 個成員變數，n (int)與指向 tNode 結構的指標變數
// 
// 第一個部分：
//		讓使用者輸入要建立鏈結串列的節點數
//		然後依序的讓使用者輸入節點數每一個節點的儲存內容
//		完成鏈結串列後，以 while 迴圈從鏈結串列的頭走向尾，依序輸出每一個節點的內容
// 第二個部分：
//		以 while 迴圈從鏈結串列的頭走向尾，依序釋放每一個節點，並計算目前已經釋放的節點數
// 
// 參考以下的輸出完成鏈結串列。
//---------第一個部分------ -
// 請輸入需要幾個 node : 4
// 請輸入第 1 個 node 的內容 : 6
// 請輸入第 2 個 node 的內容 : 7
// 請輸入第 3 個 node 的內容 : 3
// 請輸入第 4 個 node 的內容 : 9
// 第 1 個 node 的內容是 6
// 第 2 個 node 的內容是 7
// 第 3 個 node 的內容是 3
// 第 4 個 node 的內容是 9
//
// --------第二個部分------ -
// 釋放節點的內容是 6
// 釋放節點的內容是 7
// 釋放節點的內容是 3
// 釋放節點的內容是 9
// 共釋放了 4 個 node
//

#define P
#ifdef P9

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

// 宣告 tNode
struct tNode {
	int n;
	tNode* plink;
};

int main(void)
{
	int n, in;
	tNode* phead, * ptail, * pget;
	phead = ptail = NULL;

	printf("-------- 第一個部分 -------\n");

	printf("請輸入需要幾個 node : "); scanf("%d", &n);
	phead = (tNode*)malloc(sizeof(tNode));

	printf("請輸入第 1 個 node 的內容: "); scanf("%d", &in);
	phead->n = in;
	phead->plink = NULL;
	ptail = phead;

	// 以下為建立剩下 n - 1 節點的內容
	for (int i = 2; i <= n; i++) {
		pget = (tNode*)malloc(sizeof(tNode));
		printf("請輸入第 %d 個 node 的內容: ", i); scanf("%d", &in);
		pget->n = in;
		pget->plink = NULL;
		ptail->plink = pget;
		ptail = pget;

	}
	// 以下為輸出所建立節點的內容
	pget = phead;
	for (int i = 0; i < n; i++) {
		printf("第 %d 個 node 的內容是 %d\n", i+1, pget->n);
		pget = pget->plink;
	}
	


	printf("\n\n-------- 第二個部分 -------\n");

	// 以下為釋放節點的程式碼
	int clearn = 0;
	pget = phead;
	while (pget != NULL) {
		phead = phead->plink;
		printf("釋放節點的內容是 %d\n", pget->n);
		free(pget);
		clearn++;
		pget = phead;
	}

	printf("共釋放了 %d 個 node\n", clearn);
	system("pause"); return(0);
}
#endif