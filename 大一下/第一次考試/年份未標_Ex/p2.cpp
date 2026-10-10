//  注意：本題與第 3 題，選一題作答即可，兩題都寫只會以高分題為依據，兩題分數不會相加
// 
//  程式設計二，第一次上機考試 ，第 2 題 (8 分) 
// 
//  計分方式：第一個部分 6 分，第二個部分 2 分
// 
// 宣告 tNode 結構，裡面包含 2 個成員變數，n (int)與指向 tNode 結構的指標變數
// 
// 第一個部分：
//		建立有 6 個節點的鏈結串列，節點依序儲存 1 到 6 個數值
//     【要求】: 第一個節點單獨取得，後續五個節點必須透過 for 迴圈來建立
//               也就是取得節點、串接到原鏈結串列中。
//		完成鏈結串列後，以 while 迴圈從鏈結串列的頭走向尾，依序輸出每一個節點的內容
// 第二個部分：
//		以 while 迴圈從鏈結串列的頭走向尾，依序釋放每一個節點，並計算目前已經釋放的節點數
// 
// 參考以下的輸出完成鏈結串列。
// --------- 第一個部分 ---------
// 第 1 個 node 的內容是 1
// 第 2 個 node 的內容是 2
// 第 3 個 node 的內容是 3
// 第 4 個 node 的內容是 4
// 第 5 個 node 的內容是 5
// 第 6 個 node 的內容是 6
//
// --------- 第二個部分 ---------
// 釋放節點的內容 :  1  2  3  4  5  6 共釋放了 6 個 node
//

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
//以 struct 宣告 tNode 結構
struct Node {
	int val;
	Node* link;
};

void create(Node** cur,int n) {
	for (int i = 2; i < (n+1); i++) {
		Node* get = (Node*)malloc(sizeof(Node));
		get->link = NULL;
		get->val = i;
		printf("第 %d 個 node 的內容是 %d\n", i, i);
		(*cur)->link = get;
		(*cur) = get;
	}
}
void read(Node* cur) {
	while (cur != NULL) {
		printf("%d ", cur->val);
		cur = cur->link;
	}
}

int clear(Node* cur) {
	int i = 0;
	Node* temp;
	while (cur != NULL) {
		temp = cur;
		cur = cur->link;
		printf("%d ", temp->val);
		free(temp);
		i++;
	}
	return i;
}

int main(void)
{

	printf("--------- 第一個部分 ---------\n");
	int n=6; // n 節點個數設定為 6
	Node* tail = (Node*)malloc(sizeof(Node));
	tail->link = NULL;
	tail->val = 1;
	printf("第 1 個 node 的內容是 1\n");
	Node* head = tail;

	create(&head, n);


	printf("\n--------- 第二個部分 ---------\n");
	printf("釋放節點的內容 :");
	printf("共釋放了 %d 個 node\n", clear(tail));
	system("pause"); return(0);
}
#endif