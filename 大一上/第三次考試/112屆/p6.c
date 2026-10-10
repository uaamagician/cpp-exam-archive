// 程式設計一 !! 第三次上機考試 -- 第 6 題 (4 分)
//    
//	宣告一個結構包含以下的資料成員
//    姓名：char 型別的一維陣列，大小為 12
//    儲存國文、英文、數學成績的三個 int 型別的變數
//    儲存平均成績的 float 型別的變數
// 
// 主程式
//    以這個結構宣告一個結構變數
//    然後輸入姓名、三科成績，並計算平均成績儲存到這個結構變數內
//    並根據下面的參考輸出結構變數的內容
// 
// 符合以下的要求並輸出正確才算分數： 
//    1. 平均成績的計算來源必須是來是所宣告的結構變數
//    2. 姓名、三科成績與平均成績都必須儲存在所需告的結構變數
//    3. 所有的輸出都必來自所宣告的結構變數
// 
// 輸入姓名: ABC
// 國文成績 : 70
// 英文成績 : 80
// 數學成績 : 85
//
// 學生 : ABC  國文 : 70, 英文 : 80, 數學 : 85
// 平均成績為 78.33
//

#define p
#ifdef p6
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct StuScores
{
	char cName[12];
	int iChi;
	int iEng;
	int iMath;
	float fAvg;
};

// 定義儲存學生基本資料的結構

	// 姓名, char 字元陣列
	// 國文成績, int 型別
	// 英文成績, int 型別
	// 數學成績, int 型別
	// 平均成績, float 型別

int main(void)
{
	struct StuScores stu;				// 宣告結構變數stu
	printf("輸入姓名: "); scanf("%s", stu.cName);  // 輸入姓名
	printf("國文成績: "); scanf("%d",&stu.iChi); // 輸入國文成績
	printf("英文成績: "); scanf("%d",&stu.iEng); // 輸入英文成績
	printf("數學成績: "); scanf("%d",&stu.iMath); // 輸入數學成績
										 // 計算平均
	printf("\n學生: %s  ", stu.cName);
	printf("國文: %2d,  英文: %2d,  數學: %2d \n", stu.iChi, stu.iEng, stu.iMath);
	printf("平均成績為 %5.2f\n", (stu.iChi + stu.iEng + stu.iMath)/3.0f);
	system("pause"); return(0);
}
#endif