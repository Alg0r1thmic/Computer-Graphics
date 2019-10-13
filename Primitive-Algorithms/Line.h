#ifndef LINE_H
#define LINE_H
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>
#include "Shape.h"
#include "iostream"
#include <vector>
using namespace std;
class Line:public Shape
{
public:
    Line() {}
    //Draw line if X distance is greater than Y
    void lineBresenhamX(int x0, int y0, int x1, int y1, int dx, int dy)
    {
        int i, j, k;
        i = 2 * dy - dx;
        j = 2 * dy;
        k = 2 * (dy - dx);
        if (!(x0 < x1)) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        setPixel(x0, y0);
        while (x0 < x1) {
            if (i < 0)
                i += j;
            else {
                if (y0 < y1)
                    ++y0;
                else
                    --y0;
                i += k;
            }
            ++x0;
            setPixel(x0, y0);
        }
    }
    //Draw line if X distance is lesser than Y
    void lineBresenhamY(int x0, int y0, int x1, int y1, int dx, int dy)
    {
        int i, j, k;
        i = 2 * dx - dy;
        j = 2 * dx;
        k = 2 * (dx - dy);
        if (!(y0 < y1)) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        setPixel(x0, y0);
        while (y0 < y1) {
            if (i < 0)
                i += j;
            else {
                if (x0 > x1)
                    --x0;
                else
                    ++x0;
                i += k;
            }
            ++y0;
            setPixel(x0, y0);
        }
    }
    //Called by mouse(), will call the appropriate function depending on the length of the X and Y axis
    void lineBresenham(int x0, int y0, int x1, int y1)
    {
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);

        if (dx >= dy)
            this->lineBresenhamX(x0, y0, x1, y1, dx, dy);
        else
            this->lineBresenhamY(x0, y0, x1, y1, dx, dy);
    }
    void lineBresenham3D(int x1,int y1,int z1,int x2,int y2,int z2){
        setPixel3D(x1,y1,z1);
        int xs,ys,zs,p1,p2;
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int dz = abs(z2 - z1);
        if (x2 > x1)
            xs = 1;
        else
            xs = -1;
        if (y2 > y1)
            ys = 1;
        else
            ys = -1;
        if (z2 > z1)
            zs = 1;
        else
            zs = -1;

        // Driving axis is X-axis"
        if (dx >= dy and dx >= dz){
            p1 = 2 * dy - dx ;
            p2 = 2 * dz - dx ;
            while (x1 != x2){
                x1 += xs;
                if (p1 >= 0){
                    y1 += ys ;
                    p1 -= 2 * dx ;
                }
                if (p2 >= 0){
                    z1 += zs;
                    p2 -= 2 * dx;
                }
                p1 += 2 * dy ;
                p2 += 2 * dz ;
                setPixel3D(x1,y1,z1);
            }
        }
        // Driving axis is Y-axis"
        else if (dy >= dx and dy >= dz){
            p1 = 2 * dx - dy;
            p2 = 2 * dz - dy;
            while (y1 != y2){
                y1 += ys;
                if (p1 >= 0){
                    x1 += xs;
                    p1 -= 2 * dy;
                }
                if (p2 >= 0){
                    z1 += zs;
                    p2 -= 2 * dy;
                }
                p1 += 2 * dx;
                p2 += 2 * dz;
                setPixel3D(x1,y1,z1);
            }

        }
        //Driving axis is Z-axis"
        else {
            p1 = 2 * dy - dz;
            p2 = 2 * dx - dz;
            while (z1 != z2){
                z1 += zs;
                if (p1 >= 0){
                    y1 += ys;
                    p1 -= 2 * dz;
                }
                if (p2 >= 0){
                    x1 += xs;
                    p2 -= 2 * dz;
                }
                p1 += 2 * dy;
                p2 += 2 * dx;
                setPixel3D(x1,y1,z1);
            }
        }
    }
};

#endif // LINE_H
