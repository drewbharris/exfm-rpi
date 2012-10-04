#ifndef QEXFMVIEW_H
#define QEXFMVIEW_H

#include <QWebView>

class QExfmView : public QWebView
{
    Q_OBJECT
public:
    explicit QExfmView(QWidget *parent = 0);
    void toggleFullScreen();

private:
    
signals:
    
public slots:
    void triggerNextSong();
    void triggerPrevSong();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    
};

#endif // QEXFMVIEW_H
