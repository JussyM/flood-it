#include <QApplication>
#include <QPushButton>
#include "model/game.h"
#include "gui/floodit_gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto g_= game();
    g_.initialize();
    auto gui = new floodit_gui();
    gui->init_and_show(g_);
    gui->show();
    return QApplication::exec();
}
