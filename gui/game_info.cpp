//
// Created by jussymi on 9/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_game_info.h" resolved

#include "game_info.h"
#include "ui_game_info.h"


game_info::game_info(QWidget *parent) :
        QWidget(parent), ui(new Ui::game_info) {
    ui->setupUi(this);
    launch_game = new QPushButton(this);
    launch_game->setObjectName(QString::fromUtf8("launch_game"));
    launch_game->setGeometry(QRect(190, 260, 80, 26));
    launch_game->setText(QCoreApplication::translate("game_info", "GO", nullptr));

}

game_info::~game_info() {
    delete ui;
}

void game_info::set_data_game() {
    auto row = this->ui->rowspin->value();
    auto col = this->ui->columspin->value();
    auto nb_color = this->ui->nbcolor->value();
    this->board_information={row,col,nb_color};
}

const std::array<int, 3> &game_info::getBoardInformation() const {
    return board_information;
}

QPushButton *game_info::getLaunchGame() const {
    return launch_game;
}


