//
// Created by jussymi on 9/29/22.
//

#include "application.h"
#include "../gui/color_button.h"

application::application(QObject *parent) : QObject(parent) {
    this->user_input = new game_info();
    this->gui = new floodit_gui();
}

void application::start() {
    QObject::connect(this->user_input->getLaunchGame(), SIGNAL(clicked()), this, SLOT(received_data()));
    this->user_input->show();
}

void application::set_color(color& c) {
    this->game_.setTheChosenOne(c);
    this->game_.update_game();
    this->gui->update(this->game_);
}

void application::received_data() {
    this->user_input->set_data_game();
    auto data = this->user_input->getBoardInformation();
    this->game_ = game(data[0], data[1], data[2]);
    this->game_.initialize();
    this->user_input->close_windows();
    this->gui->init_and_show(this->game_);
    this->gui->init_color_button(this->game_);
    auto connect_function = [this](color_button *button) {
        QObject::connect(button, SIGNAL(sendValue(color&)), this, SLOT(set_color(color&)));
    };
    auto buttons = this->gui->getColorButtons();
    std::for_each(buttons.begin(), buttons.end(), connect_function);
    this->gui->show();
}
