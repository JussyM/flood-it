//
// Created by jussymi on 9/29/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_floodit_gui.h" resolved

#include <QLabel>
#include "floodit_gui.h"
#include "ui_floodit_gui.h"
#include "color_button.h"


floodit_gui::floodit_gui(QWidget *parent) :
        QWidget(parent), ui(new Ui::floodit_gui) {
    ui->setupUi(this);
    this->ui->msgLabel->setText("HELLO YOU STUPID BITCH "
                                "THIS IS FLOOD-IT GAME MADE BY ME JUSSY-MI SO\n "
                                "I'M SURE YOU KNOW THE RULES NORMALLY AFTER\n A "
                                "MAX OF TRY YOU FAIL BUT SINCE I'M A GOOD MAN\n "
                                "I WILL LET'S YOU PLAY UNTIL YOU WIN NO LIMIT ENJOY ... ");
}

floodit_gui::~floodit_gui() {
    delete ui;
}

void floodit_gui::init_and_show(game game_) {
    auto get_detail = game_.get_row_and_col();
    for (int i = 0; i < get_detail.first; ++i) {
        for (int j = 0; j < get_detail.second; ++j) {
            auto pos = position(i,j);
            auto square_color = game_.get_color_at(pos);
            auto square_label = new QLabel();
            switch (square_color) {
                case BLUE:
                    square_label->setStyleSheet("background : blue");
                    break;
                case GREEN:
                    square_label->setStyleSheet("background : green");
                    break;
                case YELLOW:
                    square_label->setStyleSheet("background : yellow");
                    break;
                case PINK:
                    square_label->setStyleSheet("background : pink");
                    break;
                case BLACK:
                    square_label->setStyleSheet("background : black");
                    break;
                case RED:
                    square_label->setStyleSheet("background : red");
                    break;
                case PURPLE:
                    square_label->setStyleSheet("background : purple");
                    break;
                case ORANGE:
                    square_label->setStyleSheet("background : orange");
                    break;
            }
            this->ui->gameLayout->addWidget(square_label,i,j);
        }

    }
    this->ui->maxturn->setText(QString::number(game_.getMaxclick()));
    this->ui->nbturn->setText(QString::number(game_.getNbclick()));
}

void floodit_gui::init_color_button(game g_) {
auto nb_colors = g_.get_nb_color();
this->color_buttons.reserve(nb_colors);
    for (int i = 1; i <=nb_colors; ++i) {
        auto c = static_cast<color>(i);
        auto button_color = new color_button(nullptr, c);
        switch (c) {
            case BLUE:
                button_color->setStyleSheet("background : blue");
                break;
            case GREEN:
                button_color->setStyleSheet("background : green");
                break;
            case YELLOW:
                button_color->setStyleSheet("background : yellow");
                break;
            case PINK:
                button_color->setStyleSheet("background : pink");
                break;
            case BLACK:
                button_color->setStyleSheet("background : black");
                break;
            case RED:
                button_color->setStyleSheet("background : red");
                break;
            case PURPLE:
                button_color->setStyleSheet("background : purple");
                break;
            case ORANGE:
                button_color->setStyleSheet("background : orange");
                break;
        }
        this->color_buttons.push_back(button_color);
        this->ui->colorLayout->addWidget(button_color);
    }
}

const std::vector<color_button *> &floodit_gui::getColorButtons() const {
    return color_buttons;
}

void floodit_gui::update(game g) {
    for (auto element:this->ui->gameLayout->children())
        delete element;

    init_and_show(g);
}

void floodit_gui::show_win_msg() {
this->ui->msgLabel->setText("THE GAME IS OVER YOU OFFICIALLY WIN");
}
