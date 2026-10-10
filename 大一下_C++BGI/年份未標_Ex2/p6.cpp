#define P
#ifdef P6

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

// CVec2 類別
class vec2 {
private:
	float x, y;
public:
	vec2(int x=1.0f, int y = 1.0f):x(x),y(y) {}
	vec2 operator+(const vec2& vec) {
		vec2 temp;
		temp.x = this->x + vec.x;
		temp.y = this->y + vec.y;
		return temp;
	}
	float operator*(const vec2& vec) {return this->x * vec.x + this->y * vec.y;	}
	float operator~() { return sqrtf(this->x * this->x + this->y * this->y); }
	void show() { cout << "(" << x << "," << y << ") " << endl; }

};


	


int main(void)
{
	vec2 v1, v2(2,4), v3;
	cout << "v1 = "; v1.show();
	cout << "v2 = "; v2.show();
	cout << "v1 * v2 = " << v1 * v2 << endl;
	v3 = v1 + v2;
	cout << "v3 = "; v3.show();
	cout << "||v3|| = " << ~v3 << endl;  // ~ 為一元運算子, 放在物件之前
	system("pause"); return(0);
}

#endif