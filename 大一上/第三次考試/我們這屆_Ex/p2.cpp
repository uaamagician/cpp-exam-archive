// 程式設計一，第三次上機考試第 2 題 (4 分)
//
// 宣告一個一維陣列可以儲存 8 個整數(int)，
// 並設定初始值為 67, 23, 3, 96, 45, 11, 36, 55  
// 
// 函式 maxmin 有三個引數，第一個為傳入的陣列，第二個為該陣列的大小，
//     第三個引數代表要找尋的是陣列中的最大數(傳入值為 1)還是最小數(傳入值為 0)
//     回傳值是以第三個引數內容回傳入值為 1 則回傳最大數、傳入值為 0 則回傳最小數
// 
// 主程式功能
//    宣告並產生兩個一維陣列
//      一個陣列可儲存 8 個整數(int)，設定初始值如前述
//      主程式呼叫兩次 maxmin，並接收回傳的最大數與最小數
//      然後印出所求得的最大數與最小數
//
// 要求: 本題不能使用排序法，否則不予計分
//       主程式的呼叫順序不能改變
//
// 輸出參考
//
// 67  23   3  96  45  11  36  55
// 最大數 = 96
// 最小數 = 3
//

#define us
#ifdef use

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxmin(int input[], int size, int function) {
	switch (function) {
		int buffer;
	case 0:
		buffer=input[0];
		for (int i = 1; i < size; i++) {
			buffer = input[i] > buffer ? buffer : input[i];
		}
		return buffer;
	case 1:
		buffer = input[0];
		for (int i = 1; i < size; i++) {
			buffer = input[i] > buffer ? input[i] : buffer;
		}
		return buffer;
	default:
		printf("Error");
		return 404;
	}
}// maxmin 函式主體


int main(){
	int array[] = { 67, 23, 3, 96, 45, 11, 36, 55 };		
	for (int i = 0; i < 8; i++)printf("%3d ", array[i]); 

	// 以下兩行不能刪除
	int min = maxmin(array, 8, 0);// 呼叫 maxmin，其中第三個引數給 0，然後接收最小數
	int max = maxmin(array, 8, 1);// 呼叫 maxmin，其中第三個引數給 1，然後接收最大數

	printf("\n最大數 = %3d \n最小數 = %3d\n",max ,min );

	return(0);
}


#endif