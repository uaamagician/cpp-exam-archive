//  程式設計II，第三次上機考試 ，第 7 題 (5 分)
// 
//  功能要求：畫面上四個象限中間與圓點(0,0)個有一個顏色方塊， BoxMan 預設出現在圓點(0,0)
//            以'w'、's'、'a'、'd' 四個鍵來控制 BoxMan 移動
//            BoxMan 臉的顏色則依照距離其最近的彩色方塊而變化
//            控制 BoxMan 往上，然後往左走到第二象限的顏色點、
//            然後往下、往右、再往上，再往左，最後回到原點，讓 BoxMan 的臉隨著要求改變顏色
//   
//   CCBox 類別：負責畫面上固定的顏色方塊
//    私有成員變數： int 型別 _x, _y, _color
//    公有成員函式：
//      建構元 : 三個 int 型別的引數，x/y 座標與顏色，皆有預設值
//      draw 函式 : 無引數，呼叫 drawColorBox 畫出色塊
//      getPos 函式 : 兩個 int 型別的傳入【參照或指標】參數，傳回 _x 與 _y
//      getColor 函式 : 無引數，回傳 color
//      setPos 函式 : 兩個 int 型別的引數，設定座標
//      setColor 函式 : 一個 int 型別的引數，設定顏色
// 
//  CCBoxMgr 類別：負責管理多個 CCBox（共 5 個，）
//    私有成員變數：
//      int 型別 _boxCount (CBox 的個數)
//      CCBox * 型別的指標變數 _pboxes
//    公有成員函式：
//      建構元 : 初始化 _boxCount，並配置 5 個固定位置與顏色的 CCBox
//      解構元 : 正確釋放 _pboxes 所取得的陣列空間
//      drawAllBoxes 函式 : 無引數，畫出所有 CCBox 繪製自己
//      getBox 函式 : 一個 int 型別的引數，傳回對應索引的 CCBox 參考
//      getBoxCount 函式 : 無引數，傳回 _boxCount 整數值
// 
//  CBoxMan 類別：可移動的 BoxMan，其顏色由距離最近的 CCBox 決定
//    私有成員變數： int 型別 _x, _y，int 型別 _faceColor， BoxMan 臉部顏色
//    公有成員函式：
//      建構元 : 
//          兩個 int 型別的引數，x/y 座標，皆有預設值 0,0，
//          _faceColor 則直接設定成 COLOR_WHITE    
//      update 函式 : 
//          一個 char 型別的引數，處理鍵盤 w/s/a/d 移動指令
//          更新 boxman 位置, 並重新設定應有的臉部顏色
//      draw 函式 : 繪製 BoxMan
// 
//	輸出的結果參考 p7.exe
//

#define P
#ifdef P7
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

 // CCBox 類別函式
 // - draw()       → 畫色塊
 // - getPos()     → 傳回位置 (傳指標)
 // - getColor()   → 傳回顏色
 // - setPos()     → 設定座標
 // - setColor()   → 設定顏色


// CCBoxMgr 類別函式
// - 建構元
// has-a → CCBox 指標變數
// int 型別 _boxCount (CBox 的個數)，設定 _boxCount 內容為 5
// 以 new 取得 _boxCount 個數的 CCBox 物件，並設定個別 CCBox 的初始值如下
    {0, 0, COLOR_LIGHTRED},
    {200, 200, COLOR_LIGHTGREEN},
    {-200, 200, COLOR_LIGHTBLUE},
    {-200, -200, COLOR_YELLOW},
    {200, -200, COLOR_LIGHTCYAN}

// 解構元釋放所取得的空間 
// - drawAllBoxes() → 畫出所有 CCBox
// - getBox(i)      → 傳回第 i 個 CCBox 的參考
// - getBoxCount()  → 傳回目前 box 數量 

// 以 CCBoxMgr 宣告一個全域物件, 讓 CBoxMan 可在類別成員函式內使用
     

// CBoxMan 類別函式
// - update(c) → 處理 w/s/a/d 鍵盤輸入，更新位置
     switch (cIn) {
        case 'w': // 往上
            _y = _y + 20; break;
        case 's': // 往下
            _y = _y - 20; break;
        case 'a': // 往左
            _x = _x - 20; break;
        case 'd': // 往右
            _x = _x + 20; break;
     }
    // 同時更新 BoxMan 的臉部顏色
 
// - draw()    → 計算與每個 CCBox 的距離，取得顏色並畫出 BoxMan
    { // 單純畫出 BoxMan，顏色使用 _faceColor      
        drawBoxMan(_x, _y, _faceColor);
    }

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
    char cIn;
    int i = 0;
    CBoxMan myBoxMan(0, 0); // BoxMan 初始在畫面中心
    while (i < 100)      // // 最多執行 100 次移動
    {
        cleardevice();      // 清除畫面
                            // 由 CCBoxMgr 透過全域物件畫出所有 color box
                            // 畫 BoxMan
        swapbuffers();      // 顯示畫面
        cIn = getch();
                            // 呼叫 BoxMan 的 update
        rewind(stdin);      // 清空輸入緩衝區
        i++;
    }
    cleardevice();
    swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

#endif