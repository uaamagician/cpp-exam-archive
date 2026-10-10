//  程式設計二，第二次上機考試 ，第 4 題 (3 分) 
// 
// 宣告 CMouse 類別裡面包含
//   私有包含一個 float 型別 _iw 代表老鼠的重量
//   公有包含
//       建構元：有 1 個 float 型別的引數，引數的預設值都是 9.0f
//       三個運算子
//       三個 < 運算子：分別執行 物件<物件，物件<數值 與 數值<物件。
//                      數值的型別都是 float，回傳值都是 bool
//		         物件<物件 : 比較兩個物件重量
//               物件<數值 : 比較物件重量是否小於該數值
//				 數值<物件 : 比較數值是否小於該物件的重量
//       show 函式 : 如題目所給，不用撰寫 
// 
//	要求: 數值<物件 的運算子必須宣告成 CMouse 類別的友宜函式
 
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如下的結果
//
//  m1 = 9
//  m2 = 12.5
//  m1 重量比 m2 小
//  m1 重量小於 10
//  m2 重量大於 12
//

#define P
#ifdef P4

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// CMouse 類別
class CMouse {
private:
	float _iw;
public:
	CMouse(float ff = 9.0f): _iw(ff){}
	
	bool operator<(const CMouse& mm) {
		if (this->_iw < mm._iw)return(true);
		else return(false);
	}

	bool operator<(float ff) {
		if (this->_iw < ff)return(true);
		else return(false);
	}

	friend bool operator<(const int n, const CMouse& mm) {
		if (n < mm._iw)return(true);
		else return(false);
	}
	void show();
};


void CMouse::show() {
	cout << _iw << endl;
}

// 運算子 operator
// 友宜函式 friend


int main(void)
{
	CMouse m1, m2(12.5f);
	cout << "m1 = "; m1.show();
	cout << "m2 = "; m2.show();

	if (m1 < m2) cout << "m1 重量比 m2 小" << endl;
	else cout << "m1 重量比 m2 大" << endl;

	if (m1 < 10) cout << "m1 重量小於 10" << endl;
	else cout << "m1 重量大於 10" << endl;

	if (12 < m2 ) cout <<  "m2 重量大於 12" << endl;
	else cout << "m2 重量小於 12" << endl;

	system("pause"); return(0);
}

#endif