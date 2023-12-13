#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graph->setInteraction(QCP::iRangeZoom, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_1_clicked()
{
    dt = 0.5;
    return;
}

void MainWindow::on_radioButton_2_clicked()
{
    if (true) { dt = 0.2; };
    return;
}


void MainWindow::on_radioButton_3_clicked()
{
    if (true) { dt = 0.1; };
    return;
}


void MainWindow::on_radioButton_4_clicked()
{
    if (true) { dt = 0.01; };
    return;
}

void MainWindow::on_pushButton_1_clicked()
{
    //Button Start
    //Enter values

    a = ui->numAngle->value();
    v = ui->numSpeed->value();
    S = ui->numSize->value();
    m = ui->numWeight->value();
    y = ui->numHeight->value();
    x = 0;

    beta = 0.5 * C * S * rho;
    k = beta / m;
    cosa = cos(a * PI / 180);
    sina = sin(a * PI / 180);
    vx = v * cosa;
    vy = v * sina;

    //Check if dx is not marked

    if (dt == 0)
    {
        QMessageBox::critical(this, "Message","You did not set accuracy!");
    }
    else
    {
        QList<double> X;
        QList<double> Y;
        while (y>=0)
        {
            //Calculations
            root = sqrt(vx * vx + vy * vy);
            vx = vx - k * vx * root * dt;
            vy = vy - (g + k * vy * root) * dt;

            x = x + vx * dt;
            X.append(x);
            y = y + vy * dt;
            Y.append(y);

            //Find max height

            if (y_max < y)
            {
                y_max = y;
            }
        }

        int n = X.size();
        QVector<double> Xs(n);
        QVector<double> Ys(n);
        Xs = X.toVector();
        Ys = Y.toVector();

        // создаем график и добавляем данные:
        ui->graph->addGraph();
        ui->graph->graph(0)->setData(Xs,Ys);
        // задаем имена осей координат
        ui->graph->xAxis->setLabel("Distance");
        ui->graph->yAxis->setLabel("Height");
        ui->graph->replot();

        distance = x;
        end_speed = root;
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graph->graph(0)->data()->clear();
    ui->graph->replot();

    ui->label_11->setText("0");
    ui->label_12->setText("0");
    ui->label_13->setText("0");
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_11->setText(QString::number(distance));
    ui->label_12->setText(QString::number(y_max));
    ui->label_13->setText(QString::number(end_speed));
}

