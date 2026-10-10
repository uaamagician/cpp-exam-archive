//  程式設計二，第一次上機考試 ，第 9 題 (4 分) 
// 
// 延續第 2 題的鏈結串列的需求與【要求】，但變更如下
// 
// 1. 先完成具有 6 個節點的鏈結串列，節點存放的內容依序由 1 到 6
// 2. 從頭往後數在第 5 與第 6 個節點之間，插入一個新的節點
// 3, 新加入節點存放的內容為 99
// 4. 從頭到尾輸出每一個節點的內容
// 5. 從頭到尾釋放每一個節點的內容
// 
//  參考以下的輸出完成鏈結串列。
//  建立完成的節點內容
//  第 1 個 node 的內容是 1
//  第 2 個 node 的內容是 2
//  第 3 個 node 的內容是 3
//  第 4 個 node 的內容是 4
//  第 5 個 node 的內容是 5
//  第 6 個 node 的內容是 6
//  新增節點後的內容
//  第 1 個 node 的內容是 1
//  第 2 個 node 的內容是 2
//  第 3 個 node 的內容是 3
//  第 4 個 node 的內容是 4
//  第 5 個 node 的內容是 5
//  第 6 個 node 的內容是 99 
//  第 7 個 node 的內容是 6
//  釋放節點的內容 :  1　 2　 3　 4　 5   99　 6　   共釋放了 7 個 node
//

#define P
#ifdef P9

#define _CRT_SECURE_NO_WARNINGS
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

void create(Node** cur, int n) {
	for (int i = 2; i < (n + 1); i++) {
		Node* get = (Node*)malloc(sizeof(Node));
		get->link = NULL;
		get->val = i;
		printf("第 %d 個 node 的內容是 %d\n", i, i);
		(*cur)->link = get;
		(*cur) = get;
	}
}
void read(Node* cur) {
	int i = 1;
	while (cur != NULL) {
		printf("第 %d 個 node 的內容是 %d\n",i,cur->val);
		cur = cur->link;
		i++;
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
	int n = 6; // n 節點個數設定為 6
	Node* tail = (Node*)malloc(sizeof(Node));
	tail->link = NULL;
	tail->val = 1;
	printf("第 1 個 node 的內容是 1\n");
	Node* head = tail;
	create(&head, n);
	Node* temp = tail;
	//增加節點
	while (temp != NULL) {
		if (temp->val==5) {
			Node* create = (Node*)malloc(sizeof(Node));
			create->val = 99;
			create->link = temp->link;
			temp->link = create;
		}
		temp = temp->link;
	}
	printf("新增節點後的內容\n");
	read(tail);

	printf("釋放節點的內容 :");
	printf("共釋放了 %d 個 node\n", clear(tail));
	system("pause"); return(0);
}
#endif