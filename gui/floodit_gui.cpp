//
// Created by jussymi on 9/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_floodit_gui.h" resolved

#include "floodit_gui.h"
#include "ui_floodit_gui.h"


floodit_gui::floodit_gui(QWidget *parent) :
        QWidget(parent), ui(new Ui::floodit_gui) {
    ui->setupUi(this);
}

floodit_gui::~floodit_gui() {
    delete ui;
}
