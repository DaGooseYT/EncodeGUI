#include "../include/encodegui.hpp"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    EncodeGUI w;
    w.show();
    return a.exec();
}