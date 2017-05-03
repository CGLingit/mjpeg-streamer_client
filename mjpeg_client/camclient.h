#ifndef CAMCLIENT_H
#define CAMCLIENT_H

#include <QObject>
#include<QHostAddress>
#include<QTcpSocket>
#include<QByteArray>
#include<QImage>
class CamClient : public QObject
{
    Q_OBJECT
public:
    explicit CamClient(QObject *parent = 0);
    void connectToHost(QHostAddress addr,quint16 port);
    void requestImage(void);
protected:
    QTcpSocket tcpSocket;
    QByteArray imageArray;
    QImage image;

signals:
    void newImageReady(QImage img);
public slots:
    void readImage();//接收数据保存数据

};

#endif // CAMCLIENT_H
