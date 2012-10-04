#ifndef QEXFMVIEW_H
#define QEXFMVIEW_H

#include <QWebView>
#include <qextserialport.h>

class QExfmView : public QWebView
{
    Q_OBJECT
public:
    explicit QExfmView(QWidget *parent = 0);
    void toggleFullScreen();

private:
    QextSerialPort * port;
    
signals:
    
public slots:
    void onDataAvailable();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    
};

#endif // QEXFMVIEW_H
