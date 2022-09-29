//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_COLOR_BUTTON_H
#define FLOODIT_COLOR_BUTTON_H


#include <QPushButton>
#include "../model/board.h"
class color_button : QPushButton {
Q_OBJECT
color button_color;
signals:
    void sendValue(color&);
protected:
    void mousePressEvent(QMouseEvent*)override;
public:
    explicit color_button(QWidget*parent= nullptr,const color=color::BLACK);

    color getButtonColor() const;

};


#endif //FLOODIT_COLOR_BUTTON_H
