//  程式設計二，第二次上機考試 ，第 5 題 (4 分) 
// 
// 宣告 CVec2 類別裡面包含
//   私有包含(都是 float 型別)
//       向量的 x y 座標
//   公有包含
//       建構元：有兩個 float 型別的引數，引數的預設值都是 1.0f         
//               也就是設定預設的向量內容為 (1.0f, 1.0f)
//       三個運算子
//       +運算子 ：也就 物件-物件，執行向量的相減，回傳值為 CVec2 型別
//				   也就是 (a,b)+(c,d)的結果是 傳回 (a+c, b+d)
//       *運算子 ：也就 物件*物件，執行向量的內積，回傳值為 float 型別
//				   也就是 (a,b)*(c,d)的結果是 傳回 a*c+b*d
//       ~運算子 ：也就 ~物件，計算向量的長度，回傳值為 float 型別
//				   也就是 sqrtf(a*a+b*b)，傳回這個計算的結果 
//                 NOTE: ~運算子為一元運算子，【不需要引數】
//       show 函式 : 如題目所給，不用撰寫 
// 
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如下的結果
//
//  v1 = (1, 1)
//  v2 = (2, 4)
//  v1 * v2 = 6
//  v3 = (3, 5)
//  || v3 || = 5.83095
//

#define P
#ifdef P5

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

// CVec2 類別
class CVec2 {
private:
	float _fx, _fy;
public:
	CVec2(float x = 1.0f, float y = 1.0f): _fx(x), _fy(y){}

	CVec2 operator+(const CVec2& vv) {
		CVec2 sum; sum._fx = 0; sum._fy = 0;
		sum._fx = this->_fx + vv._fx;
		sum._fy = this->_fy + vv._fy;
		return(sum);
	}
	float operator*(const CVec2& vv) {
		return((this->_fx * vv._fx) + (this->_fy * vv._fy));
	}
	float operator~() {
		return(sqrtf((this->_fx * this->_fx) + (this->_fy * this->_fy)));
	}
	void show();

};

	void CVec2::show() {
		cout << "("<< _fx << "," << _fy << ") " << endl;
	}


int main(void)
{
	CVec2 v1, v2(2,4), v3;
	cout << "v1 = "; v1.show();
	cout << "v2 = "; v2.show();
	cout << "v1 * v2 = " << v1 * v2 << endl;
	v3 = v1 + v2;
	cout << "v3 = "; v3.show();
	cout << "||v3|| = " << ~v3 << endl;  // ~ 為一元運算子, 放在物件之前
	system("pause"); return(0);
}

#endif