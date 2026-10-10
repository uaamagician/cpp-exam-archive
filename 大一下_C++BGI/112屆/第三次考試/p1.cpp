//  程式設計II，第三次上機考試 ，第 1 題 (5 分)
// 
// 宣告 CVec2 類別裡面包含
//
//   公有包含
//       向量的 x y 座標
//       建構元：有兩個 float 型別的引數，引數的預設值都是 1.0f         
//               也就是設定預設的向量內容為 (1.0f, 1.0f)
//       四個運算子 -  *(兩個)  = 
//       -運算子 ：也就 物件-物件，執行兩個向量的相減，回傳值為 CVec2 物件 
//       *運算子 ：也就 物件*物件，執行向量的內積，回傳值為 float 型別
//				   也就是 (a,b)*(c,d) 的結果是 傳回 a*c+b*d
//       *運算子 ：也就 常數*物件，純量與向量相乘，回傳值為 CVec2 物件
//					s*(c,d) = (s*c, s*d), 回傳 (s*c, s*d)
//					定義成友宜函式
//       =運算子 ：也就 物件=物件，執行向量內容的設定，回傳值為 CVec2 的參照物件 // 
//       show 函式 : 如題目所給，不用撰寫 
// 
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如下的結果
// 
//  v1 = (1, 1)
//  v2 = (2, 4)
//  v3 = (0, 2)
//  v1 - v3 = (1, -1)
//  v1 * v2 = 6
//	v4 = (v1 * v3) * v2 = (4, 8)
//  

#define P
#ifdef P1

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// CVec2 類別
class CVec2 {
public:
	float x, y;
	CVec2(float f1 = 1.0f, float f2 = 1.0f) {
		x = f1; y = f2;
	}
	CVec2 operator-(const CVec2& mm) {
		CVec2 t;
		t.x = this->x - mm.x;
		t.y = this->y - mm.y;
		return(t);
	}
	float operator*(const CVec2& mm) {
		return((this->x) * (mm.x) + (this->y) * (mm.y));
	}
	friend CVec2 operator*(float ff, const CVec2& mm) {
		CVec2 t;
		t.x = ff * mm.x;
		t.y = ff * mm.y;
		return(t);
	}
	CVec2& operator=(const CVec2& mm) {
		this->x = mm.x;
		this->y = mm.y;
		return(*this);
	}
	void show() {
		cout << "(" << x << "," << y << ")";
	}
	

};





int main(void)
{
	CVec2 v1, v2(2, 4), v3(0,2), v4;
	cout << "v1 = "; v1.show(); cout << endl;
	cout << "v2 = "; v2.show(); cout << endl;
	cout << "v3 = "; v3.show(); cout << endl;
	cout << "v1 - v3 = "; (v1-v3).show(); cout << endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
	v4 = v1 * v3 * v2;
	cout << "v4 = (v1 * v3) * v2 = "; v4.show(); cout << endl;
	system("pause"); return(0);
}

#endif