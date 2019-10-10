#include "openglwidget.h"

OpenglWidget::OpenglWidget(QWidget *parent)
    :QOpenGLWidget{parent}
{

}

void OpenglWidget::initializeGL()
{
    float r,g,b,a=normalize_0_1(255.0f,RGB_MIN,RGB_MAX);
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black,r,g,b);
    glClearColor(r,g,b,a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void OpenglWidget::paintGL()
{

    float r,g,b;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);
        qColorToRGB(Qt::blue,r,g,b);
        glColor3f(r,g,b);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,0.0f,0.0f);
    glEnd();
}

void OpenglWidget::paintLine()
{
    float r,g,b;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
        qColorToRGB(Qt::red,r,g,b);
        glColor3f(r,g,b);
        glVertex3f(-1.0,0.0f,0.0f);
        glVertex3f(1.0,0.0f,0.0f);
    glEnd();
}
void OpenglWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void OpenglWidget::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
    int red=C.red();
    int green=C.green();
    int blue=C.blue();
    r=normalize_0_1(red,RGB_MIN,RGB_MAX);
    g=normalize_0_1(green,RGB_MIN,RGB_MAX);
    b=normalize_0_1(blue,RGB_MIN,RGB_MAX);

}

float OpenglWidget::normalize_0_1(float val, float min, float max) const
{
    return (val-min)/(max-min);
}
