#include "qexfmview.h"
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QWebSettings>
#include <QWebFrame>

QExfmView::QExfmView(QWidget *parent) :
    QWebView(parent)
{

}

void QExfmView::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape){
        QApplication::quit();
    }
    else if (event->key() == Qt::Key_F){
        QExfmView::toggleFullScreen();
    }
}

void QExfmView::triggerNextSong(){
    this->page()->mainFrame()->evaluateJavaScript("exPlayQueue.next();");
}

void QExfmView::triggerPrevSong(){
    this->page()->mainFrame()->evaluateJavaScript("exPlayQueue.previous();");
}

void QExfmView::toggleFullScreen(){
    if (QExfmView::isFullScreen()){
        QExfmView::show();
    }
    else{
        QExfmView::showFullScreen();
    }
}
