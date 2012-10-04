#include <QApplication>
#include <QtWebKit>
#include <QDebug>
#include "qexfmview.h"
#include "qexfmserial.h"
#include <QtCore/QList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QExfmView *view = new QExfmView();
    view->load(QUrl("http://ex.fm/labs/full-screen/grmnygrmny"));
    view->setFocus();
    view->show();

    QExfmSerial *serial = new QExfmSerial();


    QObject::connect(serial, SIGNAL(next()), view, SLOT(triggerNextSong()));
    QObject::connect(serial, SIGNAL(prev()), view, SLOT(triggerPrevSong()));
    return app.exec();
}


