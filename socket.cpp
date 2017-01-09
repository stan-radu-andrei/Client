#include "socket.h"

Socket::Socket(QObject *parent) : QObject(parent)
{

}
void Socket::Connect()
{
    socket = new QTcpSocket(this);

    socket->connectToHost("google.com",80);
    //connect
    if(socket->waitForConnected(3000))
    {
        qDebug()<<"Connected";
        //send
        socket->write("hello\r\n\r\n");

        socket->waitForBytesWritten(1000);

        socket->waitForReadyRead(3000);
        qDebug()<<"Reading:"<<socket->bytesAvailable();

        qDebug()<<socket->readAll();

        socket->close();
    }
    else
    {
        qDebug()<<"Not Connected";
    }


    //sent

    //got

    //close
}
