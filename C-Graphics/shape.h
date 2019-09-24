#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
class Shape
{
public:
    Shape();
    virtual void paint()=0;
    void setPixel(int x,int y);
    void mouse(int btn,int state,int x,int y);
    void keyInput(unsigned char key,int x,int y);
    void drawScene(void);
    void setup();
public:
    bool drawLine;
};

#endif // SHAPE_H
