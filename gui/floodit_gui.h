//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_FLOODIT_GUI_H
#define FLOODIT_FLOODIT_GUI_H

#include <QWidget>
#include <QPushButton>
#include "../model/game.h"
#include "color_button.h"


QT_BEGIN_NAMESPACE
namespace Ui { class floodit_gui; }
QT_END_NAMESPACE

class floodit_gui : public QWidget {
Q_OBJECT

public:
    explicit floodit_gui(QWidget *parent = nullptr);
    ~floodit_gui() override;
    void init_and_show(game);
    void init_color_button(game);

private:

    std::vector<color_button*> color_buttons;
public:
    [[nodiscard]] const std::vector<color_button *> &getColorButtons() const;
    void update(game);

private:
    Ui::floodit_gui *ui;
};


#endif //FLOODIT_FLOODIT_GUI_H
