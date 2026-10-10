//  程式設計II，第三次上機考試 ，第 5 題 (4 分)
//
//  完成以下 CBox 類別的內容：
//  CBox 類別
//      私有成員變數：
//          int 型別 _size；Box 的尺寸
//          靜態整數(int)成員變數：紀錄目前已建立了多少個 CBox 物件
//
//      公有成員函式：
//          CBox( )；建構元，設定 _size 為傳入值，紀錄物件數量的靜態成員變數內容加 1
//          ~CBox()；解構元，紀錄物件數量的靜態成員變數內容減 1
//          draw 函式 : 一個 int 型別的引數 (y 座標)，呼叫 drawSizeBox(0, y, COLOR_LIGHTGREEN, _size) 畫出 Box
//          showTotalCount 【靜態】成員函式 : 無引數，顯示目前已建立的 CBox 物件總數
//
//  主程式：根據主程式所提供的註解，完成相關的程式碼
//      宣告 CBox * 型別的一維指標陣列 pBox[5]
//      使用迴圈建立 5 個 CBox 物件，大小依序為 20, 40, 60, 80, 100
//      每建立一個 CBox 物件後，呼叫 CBox::showTotalCount() 顯示目前總數
//      以迴圈呼叫各 CBox 物件的 draw() 函式，將 Box 垂直排列畫出來
//          座標可設定為 (0, y)，y 座標依序遞減，間距可自訂
//      最後使用迴圈 delete 各 CBox 物件
//      每 delete 一個物件後，再呼叫 CBox::showTotalCount() 顯示目前總數
//
//  【請注意】
//      必須正確定義 static 成員變數
//      必須正確實作 static 函式 showTotalCount()
//      draw() 函式須呼叫 functions.h 中提供的 drawSizeBox() 來畫 Box
//

#define P5
#ifdef P5

#include ".\\BGIKernel\\graphics.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "functions.h"

using namespace std;
int py = 300;  // 全域變數，用於訊息輸出時的 Y 座標偏移


class CBox
{
public:
    CBox(int i_size):_size(i_size) { count++; }
    ~CBox() { count--; }
    void draw(int y) { drawSizeBox(0, y, COLOR_LIGHTGREEN, _size); }
    static void showTotalCount() { // 函式內容如下，不要修改
        settextstyle(3, 0, 24);
        setcolor(COLOR_WHITE);
        std::stringstream ss;
        ss << "目前 CBox 總數 = " << count << endl;  // 靜態成員變數可依照自己的宣告修改
        outtextxy(X(-300), Y((py -= 40)), (char*)(ss.str().c_str()));
    }
private:
    int _size;
    int static count;
};


// CBox 類別
//      私有成員變數：
//          int 型別 _size；Box 的尺寸
//          靜態整數(int)成員變數：紀錄目前已建立了多少個 CBox 物件
//      公有成員函式：
//          CBox( )；建構元，設定 _size 為傳入值，紀錄物件數量的靜態成員變數內容加 1
//          ~CBox()；解構元，紀錄物件數量的靜態成員變數內容減 1
//          draw 函式 : 一個 int 型別的引數 (y 座標)，呼叫 drawSizeBox(0, y, COLOR_LIGHTGREEN, _size) 畫出 Box
    // 繪圖函式，y 由外部傳入，畫出 Box
   

    // showTotalCount【靜態】成員函式 : 無引數，顯示目前已建立的 CBox 物件總數
   


// 類別外定義 static 成員變數
int CBox ::count = 0;

int main() {
    initwindow(SCREENWIDTH, SCREENWIDTH, "P5");
    CBox* c[5];                // 以 CBox 宣告包含五個元素的一維指標陣列
    int sizeArray[5] = { 20, 40, 60, 80, 100 }; // 各 CBox 尺寸

    // 建立 CBox，並顯示總數
    for (int i = 0; i < 5; i++) {
        c[i] = new CBox(sizeArray[i]);
                           // new 出 CBox 物件，設定 size
        c[i]->showTotalCount();                    // 顯示總數（靜態函式）
    }

    // 繪圖：透過各物件的 draw() 函式畫出 Box，垂直排列
    for (int i = 0; i < 5; i++) {
        int y = 300 - i * 100;             // 每個 Box 的 y 座標逐漸下降
        c[i]->draw(y);                                  // 呼叫各自的 draw(y)
    }

    // 刪除物件，並顯示剩餘總數
    for (int i = 0; i < 5; i++) {
        delete c[i];                            // 刪除物件
        c[i]->showTotalCount();                           // 顯示總數
    }

    while (!kbhit()) { delay(200); }
    return 0;
}

#endif