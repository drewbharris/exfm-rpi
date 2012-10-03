#include <QApplication>
#include "html5applicationviewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Html5ApplicationViewer viewer;
    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.showExpanded();
    viewer.loadUrl(QUrl(QLatin1String("http://ex.fm/labs/full-screen/grmnygrmny")));
    viewer.showFullScreen();

    return app.exec();
}
