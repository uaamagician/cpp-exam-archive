//  程式設計II，第三次上機考試 ，第 4 題 (4 分)
//
//  完成以下三個類別的內容：
//
//  CShape 類別
//     被保護的成員包含：
//          int 型別的成員變數 X/Y 座標與顏色
//     公有成員函式：
//          建構元 : 三個 int 型別的引數，x/y 座標與顏色，皆有預設值 0, 0, COLOR_WHITE
//          解構元 : 無引數，輸出 CShape 解構元被呼叫
//          setPos 函式 : 兩個 int 型別的引數，設定 x/y 座標
//          draw 函式 : 無引數，呼叫 drawColorBox() 畫色塊，顏色用成員變數
//
//  CRectangle 類別公有繼承自 CShape 類別 
//     私有包含：
//          int 型別的成員變數，儲存邊長大小
//     公有成員函式：
//          建構元 : 四個 int 型別的引數，x/y 座標、顏色、邊長大小，都沒有預設值
//                 呼叫 CShape 建構元時，將 x/y/顏色 傳給 CShape
//          setSize 函式 : 一個 int 型別的引數，邊長大小
//          draw 函式 : 無引數，呼叫 drawRect() 畫矩形，寬度為 邊長大小 * 2，高度為 邊長大小
//
//  CCircle 類別公有繼承自 CShape 類別 
//     私有包含：
//          int 型別儲存【半徑】的成員變數，
//     公有成員函式：
//          建構元 : 四個 int 型別的引數，x/y 座標、顏色、半徑，沒有預設值
//                 呼叫 CShape 建構元時，將 x/y/顏色 傳給 CShape
//          setRadius 函式 : 一個 int 型別的引數，設定 半徑
//          draw 函式 : 無引數，呼叫 circle() 畫圓，
//
//  主程式
//	宣告 CShape * 型別的一維指標陣列 pShape[5]
//  依照主程式的註解，使用 new 為其取得相對應的物件與初始值
//  單獨畫出 pShape[0] 所指向的第 1 與第 2 個物件 (呼叫 draw 函式)
//	搭配迴圈依序畫出 pShape[1] 到 pShape[4] 這四個物件 (呼叫 draw 函式)
//
//  釋放資源：
//      以 delete 分別釋放 pShape[0] 與 pShape[1] 到 pShape[4] 的資源
//      pShape[1] 到 pShape[4] 可搭配迴圈釋放
//      釋放 pShape[0] 時，注意寫法
//
//  記得改寫 draw 函式時必須宣告為【虛擬的】
//
//  程式結束時輸出應看到六個 CShape 解構元被呼叫的訊息，
//  結果如圖 p4.jpg 所示。
//

#define P
#ifdef P4

#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;
int py = 380;  // 不要修改

class CShape
{
public:
    CShape(int ix = 0, int iy = 0, int icolor = COLOR_WHITE):x(ix),y(iy),color(icolor) {};
    virtual ~CShape() {  // 不要修改內容
        settextstyle(4, 0, 13);
        setcolor(COLOR_WHITE);
        outtextxy(X(-120), Y((py -= 20)), "CShape 解構元被呼叫");
    }
    virtual void draw() { drawColorBox(x, y, color); }
    void setPos(int ix, int iy) { x = ix;  y = iy; }
   

protected:
    int x , y , color;
};


// CShape 類別
// 被保護的成員包含：int 型別的成員變數 X/Y 座標與顏色
// 皆有預設值 0, 0, COLOR_WHITE

// 公有成員函式
    // - 建構元 
    
    // 虛擬解構元 
   

    // - setPos 函式 : 兩個 int 型別的引數，設定 x/y 座標
    

    // - draw 虛擬函式 : 無引數，呼叫 drawColorBox() 畫色塊
        
class CRentangle:public CShape
{
public:
    CRentangle(int ix, int iy, int icolor, int is) :CShape(ix, iy, icolor),s(is) {}
    void setsize(int is) { s = is; }
    void draw() {  // 直接使用, 不需修改, 變數名稱自行修改
        setcolor(color);
        drawRect(x, y, s * 2, s);
    }
private:
    int s;
};
//  CRectangle 類別公有繼承自 CShape 類別 
//  CRectangle 類別成員函式
// - 建構元 ， 記得呼叫 CShape 建構元時，將 x/y/顏色 傳給 CShape
// - setSize 函式 : 一個 int 型別的引數，設定邊長大小
// - draw 函式 : 無引數，呼叫 drawRect() 畫矩形  
    
class CCircle :public CShape
{
public:
    CCircle(int ix, int iy, int icolor, int ir) :CShape(ix, iy, icolor), r(ir) {}
    void setradius(int ir) { r = ir; }
    void draw() { // 直接使用, 不需修改, 變數名稱自行修改
        setcolor(color);
        circle(X(x), Y(y), r);  // 注意 circle() 需要轉 X(), Y()
    }
private:
    int r;
};

// CCircle 類別公有繼承自 CShape 類別 
// CCircle 類別成員函式
// - setRadius 函式 : 一個 int 型別的引數，設定半徑
// - 建構元，記得呼叫 CShape 建構元時，將 x/y/顏色 傳給 CShape
// - draw 函式 : 無引數，呼叫 circle() 畫圓
   


int main() {
    initwindow(SCREENWIDTH, SCREENWIDTH, "P4");

    CShape* p[5];                // 宣告 CShape * 指標陣列，大小為 5

   // 配置 5 個物件
    p[0] = new CShape[2]; // [0] 配置兩個 CShape 物件 (用 new CShape[2])
    p[1] = new CRentangle (-200, 200, COLOR_YELLOW, 60);    // 矩形 → 左上方
   p[2] = new CRentangle(-200, -200, COLOR_LIGHTRED, 80); // 矩形 → 左下方
   p[3] = new CCircle(200, 200, COLOR_GREEN, 50);         // 圓 → 右上方
   p[4] = new CCircle(200, -200, COLOR_BROWN, 70);        // 圓 → 右下方

    // 單獨畫出 pShape[0] 中的第 1 與第 2 個物件
   p[0][0].draw();   
   p[0][1].setPos(100, 0); // 畫出[0] 第 1 個 CShape 物件
   p[0][1].draw();                           // 設定[0] 第 2 個 CShape 物件的位置, 呼叫 setPos (100, 0)
                                    // 畫出[0] 第 2 個 CShape 物件

    // 依序畫出 pShape[1] 到 pShape[4] → 呼叫 draw() (多型測試)
   for (int i = 1; i < 5; i++)
   {
       p[i]->draw();
   }
   for (int i = 1; i < 5; i++)
   {
       delete p[i];
   }
   // 釋放取得的資源
   // 釋放 pShape[0] 所取得的空間
   delete[] p[0];
   // 釋放 pShape[1] 到 pShape[4] 所取得的空間

    while (!kbhit()) { delay(200); }
    return 0;
}

#endif