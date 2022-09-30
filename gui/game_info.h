//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_GAME_INFO_H
#define FLOODIT_GAME_INFO_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class game_info; }
QT_END_NAMESPACE

class game_info : public QWidget {
Q_OBJECT

public:
    explicit game_info(QWidget *parent = nullptr);

    bool close_windows() {
        return this->close();
    }

    ~game_info() override;

private:
    std::array<int, 3> board_information;
public:
    const std::array<int, 3> &getBoardInformation() const;

private:
    Ui::game_info *ui;
private slots:

    void send_to_game();

};


#endif //FLOODIT_GAME_INFO_H
