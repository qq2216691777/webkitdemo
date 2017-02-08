#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("/usr/local/Trolltech/Qt-4.8.6/plugins");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
