#include "kmltool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon appIcon(":/images/icons/64x64/google_earth.png");
    a.setWindowIcon(appIcon);

    KmlTool w;
    w.show();

    return a.exec();
}
