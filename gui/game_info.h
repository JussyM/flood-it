//
// Created by jussymi on 9/29/22.
//

#ifndef FLOODIT_GAME_INFO_H
#define FLOODIT_GAME_INFO_H

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class game_info; }
QT_END_NAMESPACE

class game_info : public QWidget {
Q_OBJECT

public:
    /**
     *
     * @param parent
     */
    explicit game_info(QWidget *parent = nullptr);

/**
 *
 * @return
 */
    bool close_windows() {
        return this->close();
    }

    /**
     *
     */
    ~game_info() override;

private:
    std::array<int, 3> board_information;
public:
    /**
     *
     * @return
     */
    [[nodiscard]] const std::array<int, 3> &getBoardInformation() const;

private:
    Ui::game_info *ui;
    QPushButton *launch_game;
public:
    /**
     *
     * @return
     */
    QPushButton *getLaunchGame() const;

/**
 *
 */
    void set_data_game();

};


#endif //FLOODIT_GAME_INFO_H
