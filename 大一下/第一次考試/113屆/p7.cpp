//  程式設計二，第一次上機考試 ，第 7 題 (6 分)
// 
// 宣告 sNode 結構，裡面包含 2 個成員變數，n (int)與指向 sNode 結構的指標變數
// 
// 第一個部分：
//		讓使用者輸入要建立鏈結串列的節點數
//		然後依序的讓使用者輸入節點數每一個節點的儲存內容
//		完成鏈結串列後，以 while 迴圈從鏈結串列的頭走向尾，依序輸出每一個節點的內容
// 第二個部分：
//		以 while 迴圈從鏈結串列的頭走向尾，依序釋放每一個節點，並計算目前已經釋放的節點數
// 
// 參考以下的輸出完成鏈結串列。
// 第 1 個 node 的內容是 10
// 第 2 個 node 的內容是 2
// 第 3 個 node 的內容是 4
// 第 4 個 node 的內容是 6
// 第 5 個 node 的內容是 8
//

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct sNode
{
	int num;
	sNode *link;
};

int main(void)
{
	int n = 5;
	int i ;
	sNode* head, * tail,*get,*pc;
								// n 輸入的節點個數
	printf("要幾個節點數"); scanf("%d", &n);
	
	
	get = (sNode*)malloc(sizeof(sNode));
	printf("請輸入第1個值:"); scanf("%d",& get->num);
	get->link = NULL;//  head 指向第一個 node, tail 指向最後一個 node, get 用以取得新的節點
	head  = get;
	tail = get;// 先讓 head tail 設定成 NULL
	 // 建立 5 個節點


								// get 以 malloc 取得節點
	

	// 以下為建立剩下 n - 1 節點的內容
	for (i = 0; i < n-1; i++) { 
		get = (sNode*)malloc(sizeof(sNode));
		printf("請輸入第%d個值:",i+2); scanf("%d", &get->num);
		get->link = NULL;
		tail->link = get;
		tail = get;
	}
	pc = head;
	// 以下為輸出所建立節點的內容
	while (pc !=NULL)
	{
		i = 1;
		printf("第 %d 個 node 的內容是 %d\n", i, pc->num);
		pc = pc->link;
		i++;
	}
	free(get);
		


	system("pause"); return(0);
}
#endif