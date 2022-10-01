//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_COLOR_BUTTON_H
#define FLOODIT_COLOR_BUTTON_H


#include <QPushButton>
#include "../model/board.h"
#include "QMouseEvent"

class color_button : public QPushButton {
Q_OBJECT
    color button_color;
protected:
    /**
     *
     */
    void mousePressEvent(QMouseEvent *) override;

signals:

    /**
     *
     */
    void sendValue(color &);

public:
    /**
     *
     * @param parent
     */
    explicit color_button(QWidget *parent = nullptr, color= color::BLACK);

/**
 *
 * @return
 */
    [[maybe_unused]] color getButtonColor() const;


};


#endif //FLOODIT_COLOR_BUTTON_H
