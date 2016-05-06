#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manometer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void readData();

    void on_pushButton_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_2_released();

    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;

    ManoMeter           *tempMeter;
    ManoMeter           *humiMeter;
    ManoMeter           *nc;
};

#endif // MAINWINDOW_H
