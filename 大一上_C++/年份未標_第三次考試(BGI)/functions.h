#pragma once

#define SCREENWIDTH  900
#define SCREENHEIGHT 900

#define M_PI 3.1415926f
#define ATOR(x)  ((x)*M_PI/180.f)
//
// 在畫圖時，使用笛卡兒座標系(2D平面)，螢幕正中心點是 (0,0)
//
#define X(x) (SCREENWIDTH/2 + (x))  // 轉換到畫圖的座標
#define Y(y) (SCREENHEIGHT/2 - (y))

void drawRect(int cx, int cy, int width, int height);
void drawRectRot(int cx, int cy, int width, int height, float angle);

void drawTri(int cx, int cy, int length);
void drawTriRot(int cx, int cy, int length, float angle);

void drawSquare(int cx, int cy, int length);
void drawSquRot(int cx, int cy, int length, float angle);

void move_handler(int x, int y);
void lbDown_handler(int x, int y);
void lbUp_handler(int x, int y);