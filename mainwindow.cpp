#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QTime>


QSerialPort serial;
QByteArray serialData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName("COM3");
    serial.setBaudRate(serial.Baud9600);
    serial.setDataBits(serial.Data8);
    serial.setParity(serial.NoParity);
    serial.setStopBits(serial.OneStop);
    serial.setFlowControl(serial.NoFlowControl);
    connect(&serial, SIGNAL(readyRead()), this, SLOT(readData()));
    serial.open(QIODevice::ReadWrite);



    tempMeter = new ManoMeter(this);
    humiMeter = new ManoMeter(this);
    nc        = new ManoMeter(this);
    tempMeter->setMaximum(100);
    humiMeter->setMaximum(100);
    nc->setMaximum(-100);
    //tempMeter->setSuffix("\u00B0c");
    //humiMeter->setSuffix("%");
    tempMeter->setSuffix("  :PSI");
    humiMeter->setSuffix("  :PSI");
    nc->setSuffix("  :inHg");
    ui->verticalLayout->addWidget(tempMeter);
    ui->verticalLayout_3->addWidget(humiMeter);
    ui->verticalLayout_2->addWidget(nc);

    QPixmap p(":/green");
    ui->led->setPixmap(p);
    ui->led_2->setPixmap(p);
    ui->led_3->setPixmap(p);

    QPixmap d(":/Standard");
    ui->label_4->setPixmap(d);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readData()
{
    QByteArray tmp = serial.readAll();
        if(tmp.endsWith('\x0A')){
            serialData.append(tmp);
                QString str = serialData;
                QStringList list = str.split(",");
                if(list.length() >= 3){
                    tempMeter->setValue(list[0].toInt());
                    humiMeter->setValue(list[1].toInt());
                    nc->setValue(list[2].toInt());
                    serialData.clear();
                }

        }else serialData.append(tmp);
}

void MainWindow::on_pushButton_clicked()
{
    //ui->label_5->setText("SET ALARM");
}



void MainWindow::on_pushButton_3_clicked()
{
    //ui->label_5->setText("STOP ALARM");
    QPixmap p(":/green");
    ui->led->setPixmap(p);
    ui->led_2->setPixmap(p);
    ui->led_3->setPixmap(p);
}

void MainWindow::on_pushButton_2_released()
{
    QPixmap p(":/green");
    ui->led->setPixmap(p);
    ui->led_2->setPixmap(p);
    ui->led_3->setPixmap(p);
}

void MainWindow::on_pushButton_2_pressed()
{
    QPixmap p(":/red");
    ui->led->setPixmap(p);
    ui->led_2->setPixmap(p);
    ui->led_3->setPixmap(p);
    serial.write("1");
}
