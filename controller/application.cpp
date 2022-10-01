//
// Created by jussymi on 9/29/22.
//

#include "application.h"

application::application(QObject *parent) : QObject(parent) {
   this->user_input = new game_info();
    this->gui = new floodit_gui();
}

void application::start() {
    QObject::connect(this->user_input->getLaunchGame(), SIGNAL(clicked()), this, SLOT(received_data()));
    this->user_input->show();
    received_data();
}

void application::set_color(color& c) {
    this->game_.setTheChosenOne(c);
    this->game_.update_game();
    if(this->game_.is_over())
        this->gui->show_win_msg();
    this->gui->update(this->game_);
}

void application::received_data() {
    this->user_input->set_data_game();
    auto data = this->user_input->getBoardInformation();
    this->game_ = game();
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
