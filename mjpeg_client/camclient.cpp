#include "camclient.h"
#include<QFile>
CamClient::CamClient(QObject *parent) :
    QObject(parent)
{
    connect(&tcpSocket,SIGNAL(readyRead()),
            this,SLOT(readImage()));
}
//实现和服务器的连接
void CamClient::connectToHost(QHostAddress addr, quint16 port)
{
    tcpSocket.connectToHost(addr,port);
}

void CamClient::requestImage()
{
    //向服务器发送请求消息
    QByteArray imgReqArray;
    imgReqArray.append("GET /?action=stream HTTP/1.1\r\n\r\n");
    tcpSocket.write(imageArray);
}
void CamClient::readImage()
{
    /*接收服务器的数据  保存到缓存*/
    imageArray.append(tcpSocket.readAll());

    /*过滤数据 FFD8 ... FFD9*/
    char spos[3]={(unsigned char)0xff,(unsigned char)0xd8};
    char epos[3]={(unsigned char)0xff,(unsigned char)0xd9};
    /*找FFD8*/
    int startpos=imageArray.indexOf(spos,0);
    /*找不到FFD8*/
    if(startpos==-1)
    {
        imageArray.clear();
        return;
    }
     int endpos=imageArray.indexOf(epos,startpos);
     if(endpos==-1)
     {
         return;
     }
     /*把数据缓存到Buffer*/
     QByteArray imageBuffer=imageArray.mid(startpos,endpos-startpos+2);

#if 0
    /*保存数据到文件中*/
    QFile myfile("test.jpeg");
    myfile.open(QIODevice::WriteOnly | QIODevice::Append);
    /*写入数据*/
    myfile.write(imageBuffer);
    /*关闭文件*/
    myfile.close();
    /*清除缓存*/
#endif
/*加载Buffer数据*/
    image.loadFromData(imageBuffer,"JPEG");

    /*接收到完整的图像帧后发信号给MainWindow*/
    emit newImageReady(image);

    imageArray.clear();
}
