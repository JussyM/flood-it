//
// Created by jussymi on 9/22/22.
//

#include "board.h"

board::board(int row, int column, int nbColor) : row_(row), column_(column), nb_color(nbColor) {}

board::board() {

}

void board::init_board() {
    he2b::nvs::randomize();
    for (int i = 0; i < this->row_; ++i) {
        for (int j = 0; j < this->column_; ++j) {
            auto randv = he2b::nvs::random_value(1, 8);
            square_[i][j] = static_cast<color>(randv);
        }
    }
}

color **board::getSquare() const {
    return square_;
}

int board::getRow() const {
    return row_;
}

int board::getColumn() const {
    return column_;
}

color board::get_color_at(position p) {
    return square_[p.x_][p._y];
}

void board::set_color_at(position p, color c) {
square_[p.x_][p._y]=c;
}
