#include <QtWidgets/QApplication>

#include "encodegui.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    EncodeGUI *egui = new EncodeGUI();
    egui->show();
    return(a.exec());
}