#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <QColor>
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <QtWidgets>
#include <QDebug>
#define RGB_MIN 1
#define RGB_MAX 255

class OpenglWidget: public QOpenGLWidget,public QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenglWidget(QWidget *parent=nullptr);
//protected:
    void initializeGL() override;
    void paintGL() override;
    void paintLine();
    void resizeGL(int w,int h) override;
private:
    void qColorToRGB(const QColor &C,float &r,float &g,float &b) const;
    float normalize_0_1(float val,float min,float max)const;
};

#endif // OPENGLWIDGET_H
