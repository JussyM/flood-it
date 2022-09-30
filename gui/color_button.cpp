//
// Created by jussymi on 9/29/22.
//

#include "color_button.h"

void color_button::mousePressEvent(QMouseEvent *event) {
    event->accept();
   emit sendValue(this->button_color);
}

color_button::color_button(QWidget *parent, const color c): QPushButton(parent),button_color(c) {}

[[maybe_unused]] color color_button::getButtonColor() const {
    return button_color;
}
