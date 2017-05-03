#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*连接服务器*/
    camClient.connectToHost(QHostAddress("192.168.199.171"),8080);
    /*向服务器发送请求消息*/
    camClient.requestImage();

    /*槽函数的关联*/
    connect(&camClient,SIGNAL(newImageReady(QImage)),
            this,SLOT(showImage(QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showImage(QImage img)
{
    /*显示 转换*/
    ui->imageLabel->setPixmap(QPixmap::fromImage(img));
}
