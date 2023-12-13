#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include <QMainWindow>
#include <QDebug>
#define PI 3.14159265

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();


    void on_pushButton_2_clicked();

    void on_groupBox_2_clicked();

    void on_groupBox_2_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;      // Объявляем графическое полотно
    QCPGraph *graph;             // Объявляем график


private: double a, v, S, m, vx, vy, cosa, sina, beta, k, x, y, root;
private: float dt = 0;

private: double distance, end_speed;
    const float rho = 1.29;
    const float C = 0.15;
    const float g = 9.81;

private: double y_max = 0;
};
#endif // MAINWINDOW_H
