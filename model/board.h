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
    position()=default;
    position(const position&rsh)
    {
        x_=rsh.x_;
        _y=rsh._y;
    }
    bool operator()(position&rsh) const
    {
        return this->operator==(rsh);
    }
    position & operator=(position rsh)
    {
        std::swap(x_,rsh.x_);
        std::swap(_y,rsh._y);
        return *this;
    }
    bool operator==(position&rsh) const
    {
        return this->x_==rsh.x_ && this->_y==rsh._y;
    }
};

class board {
private:
    int row_;
    int column_;
    int nb_color;
    color **square_;
    color **getSquare() const;

public:
    board(int row, int column, int nbColor);
    bool is_the_same();

    board();
    int getRow() const;

    int getColumn() const;

    void init_board();
    color get_color_at(position);
    void set_color_at(position,color);


};


#endif //FLOODIT_BOARD_H
