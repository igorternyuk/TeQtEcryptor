#include "mainwindow.hpp"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    MainWindow w;
    w.move(QApplication::desktop()->rect().center() - w.rect().center());
    w.show();
    return app.exec();
}
