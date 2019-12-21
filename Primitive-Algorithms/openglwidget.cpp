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
    switch (typeShape) {
    case 0:{
        if(MouseAux%2 != 0) {
            setPixel(finalPos.x(),500-finalPos.y());
        }else{
            Line l;
            l.lineBresenham(xAtPress,yAtPress,xAtRelease,yAtRelease);
            //resetValues();
        }
    }break;
    case 1:{
        if(MouseAux%2 != 0) {
            setPixel(finalPos.x(),500-finalPos.y());
        }else{
        Line l;
        l.lineBresenham3D(xAtPress,yAtPress,0,xAtRelease,yAtRelease,0);}
    }break;
    case 2:{
        if(MouseAux%2 != 0) {
            setPixel(finalPos.x(),500-finalPos.y());
        }else{
            Circle c;
            c.circleMidpoint(xAtRelease,yAtRelease,abs(xAtRelease-xAtPress));
            //resetValues();
        }
    }break;
    case 3:{
        if(MouseAux%2 != 0) {
            setPixel(finalPos.x(),500-finalPos.y());
        }else{
            Ellipse e;
            e.ellipseMidpoint(xAtRelease,yAtRelease,abs(xAtPress-xAtRelease),abs(yAtPress-yAtRelease));
            //resetValues();
        }
    }break;
    case 4: {
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
        p.translatePolygon(points,4,tx,ty);
        wcPt2D pivot;
        pivot.x=0,pivot.y=0;
        p.rotatePolygon(points,4,pivot,angle);
        qDebug() <<"angle--->" << angle;
        wcPt2D fixed;
        fixed.x=100,fixed.y=150;
        //p.rotatePolygon(points,4,pivot,50.0);
        p.scalePolygon(points,4,fixed,sx,sy);
        glFlush();
    }break;
    case 5:{
        GLint nCtrlPts = 4, nBezCurvePts =1000;
        BezierCurve b;
        wcPt3D p={float(x),float(y), 0.0};
        vec.push_back(p);
        setPixel(x,y);
        //glFlush();
        qDebug() << p.x << p.y << p.z ;
        b.bezier(vec, vec.size(), nBezCurvePts);
    }break;
    default:{}break;
    }
    glFlush();
}
void OpenglWidget::mouseReleaseEvent(QMouseEvent *event)
{

    finalPos=event->pos();
    if(MouseAux%2!=0){
        xAtPress=event->x();
        yAtPress=500-event->y();
        qDebug() <<"AtPress"<< xAtPress << "-" << yAtPress ;

    }
    else{
        xAtRelease=event->x();
        yAtRelease=500-event->y();
        qDebug() <<"relseaPress"<< xAtRelease << "-" << yAtRelease ;

    }
    x=event->x();
    y=500-event->y();
    ++MouseAux;
    update();

}

void OpenglWidget::resetValues()
{
    this->xAtPress=0;
    this->yAtPress=0;
    this->xAtRelease=0;
    this->yAtRelease=0;
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
