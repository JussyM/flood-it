//
// Created by jussymi on 9/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_game_info.h" resolved

#include "game_info.h"
#include "ui_game_info.h"


game_info::game_info(QWidget *parent) :
        QWidget(parent), ui(new Ui::game_info) {
    ui->setupUi(this);
    QObject::connect(this->ui->launchGame, SIGNAL(clicked()), this, SLOT(send_to_game()));
}

game_info::~game_info() {
    delete ui;
}

void game_info::send_to_game() {
    auto row = this->ui->rowspin->value();
    auto col = this->ui->columspin->value();
    auto nb_color = this->ui->nbcolor->value();
    this->board_information={row,col,nb_color};
}

const std::array<int, 3> &game_info::getBoardInformation() const {
    return board_information;
}


