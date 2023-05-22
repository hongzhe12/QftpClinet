#include "clinet.h"
#include <QApplication>
#include "person.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //    Clinet w;
    person w;
    w.show();
    return a.exec();
}
