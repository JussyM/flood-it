//
// Created by jussymi on 9/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_game_info.h" resolved

#include "game_info.h"
#include "ui_game_info.h"


game_info::game_info(QWidget *parent) :
        QWidget(parent), ui(new Ui::game_info) {
    ui->setupUi(this);
}

game_info::~game_info() {
    delete ui;
}
