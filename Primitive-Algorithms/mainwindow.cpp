#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->widget->paintLine();
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->openGLWidget->typeShape=index;
    ui->openGLWidget->repaint();
}

void MainWindow::on_comboBox_2_activated(int index)
{
    ui->openGLWidget->colorChosed=index;
    ui->openGLWidget->repaint();
}

void MainWindow::on_angle_valueChanged(int arg1)
{
    ui->openGLWidget->angle=arg1;
    ui->openGLWidget->repaint();
}
void MainWindow::on_tx_valueChanged(int arg1)
{
    ui->openGLWidget->tx=arg1;
    ui->openGLWidget->repaint();
}
void MainWindow::on_ty_valueChanged(int arg1)
{
    ui->openGLWidget->ty=arg1;
    ui->openGLWidget->repaint();
}

void MainWindow::on_sx_valueChanged(int arg1)
{
    ui->openGLWidget->sx=arg1;
    ui->openGLWidget->repaint();
}

void MainWindow::on_sy_valueChanged(int arg1)
{
    ui->openGLWidget->sy=arg1;
    ui->openGLWidget->repaint();

}
