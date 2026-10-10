//  程式設計II，第三次上機考試 ，第 3 題 (4 分)
//
//  考題重點: 物件間資料的傳遞
//
//  CMouse 類別包含：
//      私有包含：
//          int 型別的成員變數 x、y 與顏色 color
//          bool 型別的變數 btracer
//          CMouse 的【指標變數】 target
//
//      公有成員函式：
//          建構元 : 沒有引數，直接設定 x 與 y 為 0, 0，color 為 COLOR_YELLOW
//                   成員變數 btracer 為 false (預設為【被】追蹤者)，target 為 nullptr
//          setTracer 函式 : 一個 bool 型別的引數，設定 btracer 為傳入的值
//          setTarget 函式 : 一個 CMouse 型別的【參照】引數，設定 target 為指向該傳入【物件的位址】
//          getPos 函式    : 兩個 int 型別以【傳參照或指標】的形式傳入，將目前老鼠的位置利用該傳入的變數傳回給呼叫者
//          updatePos 函式 : 無引數，透過 target 所指向的被追蹤者，呼叫其 getPos 函式，取得被追蹤者的座標，並設定給【自己】
//          draw 函式      : 無引數，根據自己的狀態(追蹤還是被追蹤)呼叫對應的函式畫出自己
//          update 函式    : 一個 char 型別的引數，處理 'w'/'s'/'a'/'d' 四個鍵，更新自己的位置
//
//  完成以下的程式碼，並控制四方塊上下左右移動，追蹤者保持在玩家控制方塊的正下方。
//  參考 p3.exe
//

#define P
#ifdef P3

#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

class CMouse
{
public:
    CMouse(int ix=0, int iy=0, int icolor=COLOR_YELLOW):x(ix),y(iy),color(icolor) 
    {
        btracer = false;
        target = nullptr;
    }
    void setTracer(bool bt) { btracer = bt; }
    void setTarget(CMouse& m) { target = &m; }
    void getPos(int* ix, int* iy) { *ix = x, * iy = y; }
    void updatePos() { target->getPos(&x,&y); }
    void draw()
    {
        drawBoxMan(x, y - 100, color); // 追蹤者呼叫drawBoxMan，位置在 Y 軸往下 100 單位的地方
        drawColorBox(x, y, color);
    }
    void update(char cIn);
    

private:
    int x, y, color;
    bool btracer;
    CMouse* target;
};

// CMouse 類別
// 私有成員變數
    // int 型別的成員變數 x、y 與顏色 color
    // bool 型別的變數 btracer
    // CMouse 的【指標變數】 target
// 公有成員函式
    // - draw()         → 根據追蹤狀態畫出自己
    // - getPos()       → 傳回目前座標 (透過指標傳出)
    // - setTracer()    → 設定是否為追蹤者
    // - setTarget()    → 設定 target 指向某個 CMouse 物件
    // - updatePos()    → 透過 target 的 getPos() 更新自己的座標
    // - update()       → 處理 w/s/a/d 鍵盤輸入，更新自己的位置


 // CMouse draw() 函式
    


void CMouse::update(char cIn) // CMouse 的 update 函式的內容, 直接使用
{
    switch (cIn) {
    case 'w': // 往上
        y = y + 20; break;
    case 's': // 往下
        y = y - 20; break;
    case 'a': // 往左
        x = x - 20; break;
    case 'd': // 往右
        x = x + 20; break;
    }
}

int main()
{
    char cIn;
    int i = 0;
    initwindow(SCREENWIDTH, SCREENWIDTH, "P3");  // 開啟視窗

    CMouse m1, m2;        // 宣告兩個 CMouse 物件
    m2.setTarget(m1);                     // m2 追蹤 m1 → 設定 target
    m2.updatePos();                      // m2 呼叫 updatePos 函式 同步 m1 的目前位置
    m2.setTracer(true);                      // 設定 m2 為追蹤者

    while (i < 10)  // 移動 10 次程式就會離開迴圈
    {
        cleardevice();     // 清除畫面
        m1.draw();                   // m1 呼叫 draw() 函式，畫出 m1 (被追蹤者 → 玩家控制)
        m2.draw();                   // m2 呼叫 draw() 函式，畫出 m2 (追蹤者 → 保持在 m1 下方)
        swapbuffers();     // 交換顯示緩衝區，顯示畫面

        cIn = getch();     // 等待使用者按鍵 → 控制 m1
        m1.update(cIn);                   // 更新 m1 的位置
        m2.updatePos();                   // m2 呼叫 updatePos 函式 (同步 m1 位置)
                           // m2 呼叫 updatePos 函式 (同步 m1 位置)
        rewind(stdin);     // 清除輸入緩衝區
        i++;               // 更新次數 +1
    }

    cleardevice();   // 清除畫面
    swapbuffers();   // 更新畫面
    while (!kbhit()) { delay(200); }  // 等待按鍵後結束程式
    return 0;
}

#endif