#ifndef SHAPE_H
#define SHAPE_H
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
class Shape
{
public:
    Shape() {}
    void setPixel (GLint xCoord, GLint yCoord)
    {
        glBegin (GL_POINTS);
            glVertex2i (xCoord, yCoord);
        glEnd ( );
    }
};
#endif // SHAPE_H
