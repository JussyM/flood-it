//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_APPLICATION_H
#define FLOODIT_APPLICATION_H


#include <QObject>
#include "../gui/game_info.h"
#include "../model/game.h"
#include "../gui/floodit_gui.h"

class application : public QObject{
Q_OBJECT
private:
    game_info * user_input;
    floodit_gui * gui;
    game game_;
public:
    explicit application(QObject *parent= nullptr);
    void start();
public slots:
void set_color(color&);
void received_data();

};


#endif //FLOODIT_APPLICATION_H
