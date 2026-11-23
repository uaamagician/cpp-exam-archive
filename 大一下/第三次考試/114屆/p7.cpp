#define P7
#ifdef P7
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "functions.h"

namespace math_tool {
    struct vec2 {
        int x, y;
    };
    float distance(vec2 a ,vec2 b){ { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); } }
};
using namespace math_tool;

class Box {
private:
    vec2 vec;
    int color;
public:
    Box() :vec({ 0 }), color(0) {};
    void setting(int a, int b, int c){ vec.x = a; vec.y = b; color = c;}
    void draw() {drawColorBox(vec.x,vec.y,color);}
    float getdis(vec2& v) { return distance(vec,v); }
    int getColor() { return color; }
};

class player {
private:
    vec2 vec;
public:
    player() :vec({0}){};
    void update(char c) {
        switch (c) {
        case 'w':
            vec.y += 20;
            break;
        case 's': 
            vec.y -= 20;
            break;
        case 'a':
            vec.x -= 20;
            break;
        case 'd':
            vec.x += 20;
            break;
        }
        
    }
    void draw(int c) { drawBoxMan(vec.x, vec.y, c); }
    vec2 getPos() { return vec; }
};

class Box_manager {
public:
    static void draw(std::vector<Box>& boxes ) {
        for (auto& boxPtr : boxes) {
            boxPtr.draw();
        }
    }
    static int dis(std::vector<Box>& boxes, player& p) {
        int color_temp = boxes[0].getColor();
        float cur, dis;
        cur = dis = boxes[0].getdis(p.getPos());
        for (auto& boxPtr : boxes) {
            cur = boxPtr.getdis(p.getPos());
            if (cur < dis) {
                dis = cur;
                color_temp = boxPtr.getColor();
            }
        }
        return color_temp;
    }


};

int main(void)
{
    initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
    int i = 0;
    player p;                       
    std::vector<Box> boxes(5);
    boxes[0].setting(0, 0, COLOR_LIGHTRED);
    boxes[1].setting(200, 200, COLOR_LIGHTGREEN);
    boxes[2].setting(-200, 200, COLOR_LIGHTBLUE);
    boxes[3].setting(-200, -200, COLOR_YELLOW);
    boxes[4].setting(200, -200, COLOR_LIGHTCYAN);

    Box_manager::draw(boxes);
    p.draw(Box_manager::dis(boxes, p));
    swapbuffers();
    while (i < 100)
    {
        cleardevice();      
        Box_manager::draw(boxes);
        p.update(getch());
        p.draw(Box_manager::dis(boxes, p));
        swapbuffers();  
        rewind(stdin);      
        i++;
    }
    cleardevice();
    swapbuffers();
    while (!kbhit()) { delay(200); } return 0;
}

#endif