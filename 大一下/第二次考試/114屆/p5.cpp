#define P
#ifdef P5

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

// CCircle 類別宣告
class ccircle {
private:
	float x, y;
	float d2;
public:
	ccircle(float x=3,float y=3) :x(x),y(y),d2(x* x + y * y){}
	bool operator<(const ccircle& c) { return(this->d2<c.d2) ? true: false; };
	bool operator<(const int n) { return(this->d2 < n*n) ? true : false; };
	friend bool operator<(const int n, const ccircle& c);
	float getDist2()const { return d2; }
	void show() { cout << sqrtf(d2) << endl; }

};
bool operator<(const int n,const ccircle& c) { return(n*n < c.d2) ? true : false; };

	

int main(void)
{
	ccircle c1, c2(-4.0f, 3.0f);
	cout << "c1 與圓點距離 = "; c1.show();
	cout << "c2 與圓點距離 = "; c2.show();

	if (c1 < c2) cout << "c1 比 c2 更靠近原點" << endl;
	else cout << "c2 比 c1 更靠近原點" << endl;

	if (c1 < 3) cout << "c1 離原點距離小於 3" << endl;
	else cout << "c1 離原點距離大於 3" << endl;

	if (4 < c2 ) cout <<  "c2 離原點距離大於 4" << endl;
	else cout << "c2 離原點距離小於 4" << endl;

	cout << "\n\n";
	ccircle c3(2.0f, 2.0f), c4(1.0f, 2.0f);
	cout << "c3 與圓點距離 = "; c3.show();
	cout << "c4 與圓點距離 = "; c4.show();

	if (c3 < c4) cout << "c3 比 c4 更靠近原點" << endl;
	else cout << "c4 比 c3 更靠近原點" << endl;

	if (c3 < 3) cout << "c3 離原點距離小於 3" << endl;
	else cout << "c3 離原點距離大於 3" << endl;

	if (4 < c4) cout << "c4 離原點距離大於 4" << endl;
	else cout << "c4 離原點距離小於 4" << endl;
	system("pause"); return(0);
}

#endif