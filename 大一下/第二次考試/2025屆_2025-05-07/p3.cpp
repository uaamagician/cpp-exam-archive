//  程式設計二，第二次上機考試，第 3 題 (3 分)
//
// 以 cout 完成以下的輸出
//
//    Apple1.1
//   Orange12.21
//     Pear123.321
// Apple***^^^^^1.1
// Orange**^^^12.21
// Pear****^123.321
//
// 提示:上面的兩邊都有【8】個字元空間
// 你可能會需要用到以下的指令
// setiosflags(ios::left): cout 的輸出改成靠左對齊, 這是永久性的
// resetiosflags(ios::left): cout 的輸出變成預設的靠右對齊
// cout.width(n): 設定資料顯示時必須占用 n 個位置
// setw(n) 函式: 設定資料顯示時必須占用 n 個位置
// cout.fill('a'): 設定填滿的字元為 a
// endl : 換行同時清空緩衝區
// 
// 嚴正提醒：不要在用 printf 或 cout 直接【列印】出答案
//

#define P
#ifdef P3

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	char *cName[3] = { "Apple", "Orange", "Pear" };
	float fVal[] = { 1.1f, 12.21f, 123.321f };

	for (int i = 0; i < 3; i++) {  // 輸出前三排結果
		cout << setw(8)<<cName[i];
		cout<<setiosflags(ios::left)<<fVal[i]<<endl;
		cout<<resetiosflags(ios::left);

	}

	for (int i = 0; i < 3; i++) {  // 輸出後三排結果
		cout << setiosflags(ios::left) << setw(8) << setfill('*') << cName[i];
		cout << resetiosflags(ios::left) << setw(8) << setfill('^') << fVal[i] << endl;
	}
	system("pause"); return(0);
}

#endif