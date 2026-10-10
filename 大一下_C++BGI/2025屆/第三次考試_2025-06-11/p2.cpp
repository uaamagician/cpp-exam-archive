//  程式設計II，第三次上機考試 ，第 2 題 (3+2分)
//
// 考題重點：
// 1. 動態記憶體配置的維護
// 2. 繼承子類別呼叫父類別的拷貝建構元
// 3. 虛擬解構元
//
//  完成以下兩個類別的內容：
//  CShape 類別
//     【被保護的(protected)】成員變數 x/y 座標(float 型別)，與顏色 (int 型別的【指標變數】)
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0.0, 0.0, COLOR_WHITE
//                 記得要【為顏色取的空間】，並設定變數的內容
//        拷貝建構元 
//        解構元：釋放 顏色 所取得的空間
//                輸出 CShape 解構元被執行的訊息
//        setPos()函式 : 兩個引數，設定 x/y 座標
//        純虛擬函式 draw()
//  CCircle 類別公有繼承自 CShape 類別 
//     私有的成員變數儲存【半徑】，int 型別
//     公有的成員函式
//        建構元 : 有四個引數，x/y 座標、顏色與半徑，
//                 其中 x/y 座標與顏色，【不能給】引數預設值，半徑必須給預設值 10
//                 指定呼叫 CShape 類別的建構元
//        解構元 ：根據所給程式，輸出 CCircle 解構元被執行的訊息
//        拷貝建構元 : 【指定呼叫】 CShape 的拷貝建構元
//        void draw() 函式 : 呼叫 circle() 以半徑畫圓
//        void setRadius() 函式 : 1 個引數，設定半徑 
//        showRadius() 函式：顯示半徑數值於圓的右邊，根據所給的函式即可
//
//   需求一(3分)：
//   讓主程式能正常執行，並顯示三個垂直排列的圓，圓的顏色為黃色
//   半徑分別為 30, 45, 68，三個圓垂直排列顯示，並且各自顯示半徑
//   且程式結束時不會出現錯誤訊息
// 
//   需求二(2分)：
//   CShape 類別中新增純虛擬函式 draw(), 沒有回傳值沒有引數。
//   以 CShape 宣告指標變數，並透過 new 指向 CCircle 為其取得空間
//   宣告時給初始值為 0, -200, 13, 40
//   程式結束前以 delete 釋放所取得的資源，必須看到 CCircle 與 CShape 的解構元被執行的訊息
// 
//   讓主程式能正常執行，並顯示如圖 p2.jpg 的結果【前三個圓個顏色要一樣喔】
//   且結束時不會出現錯誤訊息
//

#define P
#ifdef P2
#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "functions.h"
using namespace std;

class CShape
{
public:
    CShape(float ix = 0.0f ,float iy=0.0f,int icolor= COLOR_WHITE):x(ix),y(iy) 
    {
        color = new int;
        *color = icolor;
    }
    CShape(const CShape& m)
    {
        x = m.x;
        y = m.y;
        color = new int;
        color = m.color;
    }
    virtual ~CShape()
    {
        delete color;
        settextstyle(3, 0, 24);
        setcolor(COLOR_WHITE);
        outtextxy(X(x), Y((y - 100)), "CShape 解構元被執行");
    }
    virtual void draw() = 0;
    void setPos(float ix, float iy) { x = ix; y = iy; }
protected:
    float x, y;
    int* color;
};

// ====== CShape 類別 ======
// 包含建構元、拷貝建構元、虛擬解構元
// 動態配置顏色指標變數，純虛擬函式 draw()
// 【被保護的(protected)】成員變數 x / y 座標(float 型別)，與顏色(int 型別的【指標變數】)
    // 建構元

    // 拷貝建構元

    // 虛擬解構元，記得釋放儲存顏色變數，同時包含以下三行
          // _x 與 _y 可依照自己宣告的變數更名

    // setPos 函式

    //----------------- Part 2 -----------------
    // 宣告 draw() 為純虛擬函式


// ====== CCircle 類別 ======
// 包含建構元、拷貝建構元、解構元、draw()、setRadius()、showRadius()
// 私有的成員變數儲存【半徑】，int 型別
    // 建構元

    // 拷貝建構元
class CCircle : public CShape
{
public:
    CCircle(float ix ,float iy,int icolor,int ir = 10):CShape(ix,iy,icolor),r(ir) {}
    ~CCircle() {
        settextstyle(3, 0, 24);
        setcolor(COLOR_WHITE);
        outtextxy(X(x), Y((y - 60)), "CCircle 解構元被執行 ");
    }
    CCircle(CCircle &c):CShape(c) {
        x = c.x;
        y = c.y;
        color = new int;
        color = c.color;
        r = c.r;
    }
    void draw() { // draw 函式
        setcolor(*color); // 顏色使用儲存顏色的指標變數
        circle(X(x), Y(y), r);  // 半徑可依照自己的宣告修改
    }
    void setRadius(int ir) { r = ir; }
    void showRadius() {  // CCircle 成員函式，不要修改內容
        std::stringstream ss;
        ss << "Radius = " << std::fixed << std::setprecision(1) << r;  // _radius 可依照自己的宣告修改
        std::string result = ss.str();
        settextstyle(3, 0, 24);
        setcolor(COLOR_WHITE);
        outtextxy(X(x + 40), Y(y), (char*)result.c_str());
    }
private:
    int r;
};




    
    
    // setRadius 函式

 


// 主程式不要更動內容
int main() {
    initwindow(SCREENWIDTH, SCREENWIDTH, "P2");

    settextstyle(3, 0, 24);
    outtextxy(X(-120), Y((370)), "-------------- Part 1 ----------------------");
    // -------------- Part 1 ----------------------
    CCircle c1(0, 300, COLOR_YELLOW, 30);
    CCircle c2(c1);
    c2.setPos(0, 200);
    c2.setRadius(45);
    CCircle c3 = c2;
    c3.setPos(0, 0);
    c3.setRadius(68);

    c1.draw(); c1.showRadius();
    c2.draw(); c2.showRadius();
    c3.draw(); c3.showRadius();

    settextstyle(3, 0, 24);
    outtextxy(X(-120), Y(-120), "-------------- Part 2 ----------------------");

    // -------------- Part 2 ----------------------
    CShape* p;              // CShape 宣告指標變數
    p = new CCircle(0, -200, 13, 40);              // 以 new 取得 CCircle 物件，給初始值 0, -200, 13, 40
    p->draw();                // 呼叫 draw() 函式
    delete p;                // 以 delete 釋放取得的資源

    while (!kbhit()) { delay(200); }
    return 0;
}

#endif
