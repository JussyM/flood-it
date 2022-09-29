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
