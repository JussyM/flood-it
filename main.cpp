#include <QApplication>
#include <QPushButton>
#include "model/game.h"
#include "gui/floodit_gui.h"
#include "controller/application.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto app = new application(nullptr);
    app->start();
    return QApplication::exec();
}
