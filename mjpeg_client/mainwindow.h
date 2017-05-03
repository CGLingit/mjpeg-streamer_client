#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"camclient.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CamClient camClient;
public slots:
    void showImage(QImage img);//显示新的图像信息
};

#endif // MAINWINDOW_H
