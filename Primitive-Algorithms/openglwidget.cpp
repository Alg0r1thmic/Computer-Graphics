#include "openglwidget.h"

OpenglWidget::OpenglWidget(QWidget *parent)
    :QOpenGLWidget{parent}
{

}

void OpenglWidget::initializeGL()
{
    //Seta todos os pixels como preto
    glClearColor (0.0, 0.0, 0.0, 0.0);
    //Defini até onde se pode desenhar, os parametros sao os max e min de cada coordenada.
    glOrtho (0.0, width(), 0.0, height(), -1.0, 1.0);
    //Faz a projeção de acordo com as coordenadas do OpenGL (é diferente dos pixel da tela do PC)
    glMatrixMode (GL_PROJECTION);

}
void OpenglWidget::paintGL()
{
    glColor3f(color[colorChosed][0], color[colorChosed][1], color[colorChosed][2]);
    //for (const auto &r: rects) {
    //if(MouseAux%2==0)
    circleMidpoint(100,100,6);
    //bresenham(xAtPress,yAtPress, xAtRelease, yAtRelease);
        //bresenhamCircle(r.right(), r.top(), r.right(), 500-r.bottom());
        //bresenhamCircle(r.left(), r.top(), r.left(), 500-r.bottom());
        //bresenhamCircle(r.left(), 500-r.bottom(), r.right(), 500-r.bottom());
    //}

    if(MouseAux%2 != 0) {
        setPixel(MousePoint.x(), MousePoint.y());
    }

    glFlush();

}
/*
void OpenglWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}
*/

void OpenglWidget::mouseReleaseEvent(QMouseEvent *event)
{

    if(MouseAux%2!=0){
        xAtPress=event->x();
        yAtPress=event->y();
    }
    else{
        xAtRelease=event->x();
        yAtRelease=event->y();
    }
    qDebug() <<"press event"<< xAtPress << "-" << yAtPress ;

    ++MouseAux;
    update();
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
