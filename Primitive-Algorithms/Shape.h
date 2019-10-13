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
    void setPixel3D(GLint x,GLint y,GLint z)
    {
        glBegin(GL_POINTS);
            glVertex3i(x,y,z);
        glEnd();
    }
};
#endif // SHAPE_H
