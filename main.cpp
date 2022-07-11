#include "mainwindow.h"
#include <iostream>
#include "contocorrente.h"
#include "bonifico.h"
#include "investimento.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
