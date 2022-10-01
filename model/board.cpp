//
// Created by jussymi on 9/22/22.
//

#include "board.h"

board::board(int row, int column, int nbColor) : row_(row), column_(column), nb_color(nbColor) {this->square_=std::vector<nodes>(row_);}

void board::init_board() {
    he2b::nvs::randomize();
    for (auto &n:square_)
        n.column = std::vector<node>(column_);
    for (int i = 0; i < this->row_; ++i) {
        for (int j = 0; j < this->column_; ++j) {
            auto randv = he2b::nvs::random_value(1, nb_color);
            square_[i].column[j].node_color = static_cast<color>(randv);
        }
    }
}


int board::getRow() const {
    return row_;
}

int board::getColumn() const {
    return column_;
}

color board::get_color_at(position p) {
    return square_[p.x_].column[p._y].node_color;
}

void board::set_color_at(position p, color c) {
square_[p.x_].column[p._y].node_color=c;
}

int board::getNbColor() const {
    return nb_color;
}
