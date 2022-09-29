//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_FLOODIT_GUI_H
#define FLOODIT_FLOODIT_GUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class floodit_gui; }
QT_END_NAMESPACE

class floodit_gui : public QWidget {
Q_OBJECT

public:
    explicit floodit_gui(QWidget *parent = nullptr);

    ~floodit_gui() override;

private:
    Ui::floodit_gui *ui;
};


#endif //FLOODIT_FLOODIT_GUI_H
