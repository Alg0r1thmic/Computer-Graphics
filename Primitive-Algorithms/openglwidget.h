#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <iostream>
#include <QColor>
#include <cmath>
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <QtWidgets>
#include <QDebug>
#include <QMouseEvent>
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#define RGB_MIN 1
#define RGB_MAX 255

class OpenglWidget: public QOpenGLWidget
{
    Q_OBJECT
    //CONSTANTES GLOBAIS
    const float color[5][3] = {{1.0, 1.0, 1.0}, //branco
                               {1.0, 0.0, 0.0}, //vermelho
                               {0.0, 1.0, 0.0}, //verde
                               {0.0, 0.0, 1.0}, //azul
                               {1.0, 1.0, 0.0} }; // amarelo

    int MouseAux=0;
    QPoint MousePoint;
    QVector<QRect> rects;
public:
    OpenglWidget(QWidget *parent=nullptr);
//protected:
    void initializeGL() override;
    void paintGL() override;
    //void resizeGL(int w,int h) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void bresenhamLine(int x1, int y1, int x2, int y2){

        int dx, dy, incE, incNE, d, x, y;
        int slope;

        if (x1 == x2){
            x = x1;
            if (y1 == y2){
                setPixel(x1, y1);
            }
            else if( y1 <= y2 ) {
                for(y = y1; y < y2; ++y){
                    setPixel(x, y);
                }
            }
            else {
                for(y = y2; y < y1; ++y){
                    setPixel(x, y);
                }
            }
            return;
        }
        // Onde inverte a linha x1 > x2
        if (x1 > x2){
            bresenhamLine(x2, y2, x1, y1);
            return;
        }
        //a diferença entre os pontos.
        dx = x2 - x1;
        dy = y2 - y1;

        //se dy > 0 o ponto vai pra NE, se não vai pra E
        if (dy < 0){
            slope = -1;
            dy = -dy;
        }
        else{
            slope = 1;
        }
        // Constante de Bresenham
        incE = 2 * dy;
        incNE = 2 * dy - 2 * dx;
        d = 2 * dy - dx;
        y = y1;

        for (x = x1; x <= x2; x++){
            //printf("%d %d\n", x1, x2);
            setPixel(x, y);
            if (d <= 0) {
                d += incE;
            } else {
                d += incNE;
                y += slope;
            }
        }
    }
private:
    void qColorToRGB(const QColor &C,float &r,float &g,float &b) const;
    float normalize_0_1(float val,float min,float max)const;
    int colorChosed=0;
    float lineSize=3.0;
    int xAtPress,yAtPress,xAtRelease,yAtRelease;
};

#endif // OPENGLWIDGET_H
