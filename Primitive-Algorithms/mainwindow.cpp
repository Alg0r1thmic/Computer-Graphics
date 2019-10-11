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

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{

}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{

}
