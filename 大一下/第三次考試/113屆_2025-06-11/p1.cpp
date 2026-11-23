//  程式設計二，第三次上機考試，第 1 題 (3+3+2分)
//
//  考題重點: 各類運算子的撰寫
//  Vec2 為一個二維向量的類別，包含 X/Y 座標(float 型別)，完成類別的宣告並完成以下的個別需求
//
//  基本要求：
//    1. 座標宣告為私有的，成員函式都是公有的
//    2. 建構元並滿足主程式 v1 與 v2 的宣告
//    3. 運算子多載的主體可寫在類別宣告內
//
//  需求一 (3分)：
//    撰寫 *、-、/ 三個運算子，讓程式能正常行
//    * → 執行向量的內積 (a,b) * (c,d) = a*c + b*d
//    - → 向量相減，傳回 Vec2
//    / → 常數 (float 型別) 相除，例如 (a,b)/c 的結果為 (a/c , b/c)，傳回 Vec2
//
//  需求二 (3分)：
//    撰寫 dist() 成員函式，回傳值為該向量的長度平方，型別為 float
//    撰寫 > 運算子，讓程式能正常執行，包含 物件 > 物件、物件 > 數值、數值 > 物件
//    其中 數值 > 物件 必須使用 friend 函式
//    > 的比較基礎是向量距離原點的距離
//
//  需求三 (2分)：
//    撰寫 = 設定運算子，並能實現 v1 = v2 = v3 執行需求
//
//  PS：成員函式都可以寫在類別內
//
//  要求：主程式所有程式碼都不能更動
//

#define P
#ifdef P1

#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "functions.h"

using namespace std;

class Vec2
{
public:
    Vec2(float ix = 0.0f,float iy = 0.0f):x(ix),y(iy) {}
    float operator*(Vec2 &m1) 
    {
        return(x * m1.x + y * m1.y);
    }
    Vec2 operator-(Vec2 &m) 
    {
        return Vec2(x - m.x, y - m.y);
    }

    Vec2 operator/ (float p) 
    {
        return Vec2 (x / p, y / p);
    }
    void show(int px, int py, char* str);
    float dist()
    {
        return(x * x + y * y);
    }
   
    bool operator>(Vec2 &m)
    {
        if (x * x + y * y > m.x * m.x + m.y * m. y)
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    bool operator>(float p)
    {
        if (x*x+y*y>p*p)
        {
            return(true);
        }
        else
        {
            return false;
        }
    }
    friend bool operator>(float p,Vec2 &m) 
    {
        if (p*p > m.x*m.x+m.y*m.y)
        {
            return(true);

        }
        else
        {
            return false;
        }
    }

    Vec2 &operator = (Vec2 &m) 
    {
        x = m.x, y = m.y;
        return(*this);
    }
private:
    float x, y;
};
// Vec2 類別

    // Part 1 算數運算子
    // * → 內積，傳回 float

    // - → 向量相減，傳回 Vec2

    // / → 常數除法，傳回 Vec2

    // Part 2 關係運算子
    // dist() → 向量長度平方，回傳值 float 型別

    // > → 比較向量距離原點的距離 (物件 > 物件), 回傳值 bool 型別

    // > → 物件 > 數值 , 回傳值 bool 型別

    // friend > → 數值 > 物件 , 回傳值 bool 型別。 友誼函式

    // Part 3 = 設定運算子
    // = → 設定運算子，需支援 v1 = v2 = v3 用法

    void Vec2::show(int px, int py, char* str) {  // show 成員函式，內容不要修改
        std::stringstream ss;
        ss << str << "(" << x << "," << y << ")" << endl; // _x 與 _y 可依照所宣告的成員變數修改
        std::string result = ss.str();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(px, py, (char*)result.c_str());
    }

// 一般 show() 函式，內容不要修改
void show(int px, int py, char* str) {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(px, py, str);
}

// 主程式內容都不要修改
int main()
{
    initwindow(SCREENWIDTH, SCREENWIDTH, "P1");    // 開啟視窗
    srand((unsigned int)time(NULL));
    std::stringstream ss;
    int px = -250, py = 300;

    setcolor(COLOR_WHITE);
    Vec2 v1(5), v2(-1, 1), v3(3, 2), v4;  // 以 Vec2 類別宣告這些物件
    v1.show(X(px), Y(py), " v1 : ");
    v2.show(X(px), Y(py -= 40), " v2 : ");
    v3.show(X(px), Y(py -= 40), " v3 : ");
    v4.show(X(px), Y(py -= 40), " v4 : ");

    setcolor(COLOR_YELLOW);
    show(X(px), Y(py -= 40), "-----------  Part 1 --------------");
    ss << " v2 * v3 = " << v2 * v3 << endl;
    show(X(px), Y(py -= 40), (char*)((ss.str()).c_str()));
    v4 = v1 - v3;
    v4.show(X(px), Y(py -= 40), " v4 = v1 - v3 => v4 : ");
    v1 = v3 / 2.0f;
    v1.show(X(px), Y(py -= 40), " v1 = v3/2.0f => v1 : ");

    setcolor(COLOR_LIGHTGREEN);
    show(X(px), Y(py -= 40), "-----------  Part 2 -------------");
    if (v4 - v2 > v3) show(X(px), Y(py -= 40), " v4-v2 > v3 ");
    else show(X(px), Y(py -= 40), " v3 >= v4-v2 ");
    if (v3 > 2) show(X(px), Y(py -= 40), " v3 > 2 ");
    else show(X(px), Y(py -= 40), " 2 >= v3 ");
    if (1 > v2) show(X(px), Y(py -= 40), " 1 > v2 ");
    else show(X(px), Y(py -= 40), " v2 >= 1 ");

    setcolor(COLOR_WHITE);
    show(X(px), Y(py -= 40), "-----------  Part 3 -------------");
    v2 = v3 = v4 - v1;
    v2.show(X(px), Y(py -= 40), " v2 : ");
    v3.show(X(px), Y(py -= 40), " v3 : ");
    v4.show(X(px), Y(py -= 40), " v4 : ");

    while (!kbhit()) { delay(200); } return 0;
}

#endif