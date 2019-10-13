#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_angle_valueChanged(int arg1);

    void on_tx_valueChanged(int arg1);

    void on_ty_valueChanged(int arg1);

    void on_sx_valueChanged(int arg1);

    void on_sy_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
