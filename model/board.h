//
// Created by jussymi on 9/22/22.
//

#ifndef FLOODIT_BOARD_H
#define FLOODIT_BOARD_H

#include <array>
#include "random.hpp"

enum color {
    BLUE = 1, GREEN, YELLOW, PINK, BLACK, RED, PURPLE, ORANGE
};

struct position {
    int x_;
    int _y;

    position(int row, int col) {
        x_ = row;
        _y = col;
    }
    bool operator==(position&rsh) const
    {
        return this->x_==rsh.x_ && this->_y==rsh._y;
    }
};

class board {
    int row_;
    int column_;
    int nb_color;
    color **square_;
public:
    color **getSquare() const;

public:
    board(int row, int column, int nbColor);
    bool is_the_same();

    board();

    void init_board();


};


#endif //FLOODIT_BOARD_H
