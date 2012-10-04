#include "qexfmview.h"
#include <qextserialport.h>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>

QExfmView::QExfmView(QWidget *parent) :
    QWebView(parent)
{
    QExfmView::port = new QextSerialPort("/dev/ttyUSB0");
    port->setBaudRate(BAUD9600);
    connect(port, SIGNAL(readyRead()), this, SLOT(onDataAvailable()));
    bool res = false;
    res = port->open(QIODevice::ReadOnly);

    if(res)
    {
        qDebug("Opened");
    }
    else
    {
        qDebug("Failed to connect");
        qDebug() << port->errorString();
    }
}

void QExfmView::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape){
        QApplication::quit();
    }
    else if (event->key() == Qt::Key_F){
        QExfmView::toggleFullScreen();
    }
}

void QExfmView::onDataAvailable(){
    QByteArray data = QExfmView::port->readLine();
    qDebug(data);
}

void QExfmView::toggleFullScreen(){
    if (QExfmView::isFullScreen()){
        QExfmView::show();
    }
    else{
        QExfmView::showFullScreen();
    }
}
