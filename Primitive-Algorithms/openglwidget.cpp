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
    //Circle c;
    //c.circleMidpoint(200,200,100);
    //Ellipse e;
    //e.ellipseMidpoint(200,200,30,60);
    //Line l;
    //l.bresenham(40,50,250,300);
    wcPt2D *points=new wcPt2D[4];
    points[0].x=50,points[0].y=190;
    points[1].x=50,points[1].y=290;
    points[2].x=270,points[2].y=290;
    points[3].x=270,points[3].y=190;

    Polygon p;
    glBegin (GL_POLYGON);
        glVertex2f(points[0].x,points[0].y);
        glVertex2f(points[1].x,points[1].y);
        glVertex2f(points[2].x,points[2].y);
        glVertex2f(points[3].x,points[3].y);
    glEnd ();
    //p.translatePolygon(points,4,50,50);
    //wcPt2D pivot;
    //pivot.x=0,pivot.y=0;
    //p.rotatePolygon(points,4,pivot,50.0);
    //p.scalePolygon(points,4,pivot,20,30);
    //bresenham(xAtPress,yAtPress, xAtRelease, yAtRelease);
        //bresenhamCircle(r.right(), r.top(), r.right(), 500-r.bottom());
        //bresenhamCircle(r.left(), r.top(), r.left(), 500-r.bottom());
        //bresenhamCircle(r.left(), 500-r.bottom(), r.right(), 500-r.bottom());
    //}

    //if(MouseAux%2 != 0) {
     //   setPixel(MousePoint.x(), MousePoint.y());
    //}
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
