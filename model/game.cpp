//
// Created by jussymi on 9/27/22.
//

#include <algorithm>
#include "game.h"

game::game(int row, int col, int nb_color) {
    this->game_board = board(row, col, nb_color);
}

game::game() {
    this->game_board = board(10, 10, 6);

}

void game::initialize() {
    this->game_board.init_board();
    this->square_token.emplace_back(0, 0);

}

void game::setTheChosenOne(color theChosenOne) {
    the_chosen_one = theChosenOne;
}

std::array<position, 4> game::get_neighbours(position p) {
    return std::array<position, 4>{position(p.x_ + _direction::UP.first, p._y + _direction::UP.second),
                                   position(p.x_ + _direction::DOWN.first, p._y + _direction::DOWN.second),
                                   position(p.x_ + _direction::LEFT.first, p._y + _direction::LEFT.second),
                                   position(p.x_ + _direction::RIGHT.first, p._y + _direction::RIGHT.second)};
}

bool game::is_inside_board(position p) {
    return p.x_ >= 0 && p.x_ < this->game_board.getRow() && p._y >= 0 && p._y > game_board.getColumn();
}

void game::update_game() {
    position node_center{};
    int i;
    int j;
    if (square_token.size() == 1) {
        game_board.set_color_at(square_token.at(0), the_chosen_one);
        j = 1;
    } else { j = 0; }
    for (i = 0; i < game_board.getRow(); ++i) {
        for (; j < game_board.getColumn(); ++j) {
            auto tmp = position(i, j);
            if (!inside_squre_token(tmp)) {
                node_center = tmp;
                if (has_super_neighbor(node_center)) {
                    auto n = get_neighbours(node_center);
                    std::for_each(n.begin(), n.end(), [this](position p) {
                        auto square_color = this->game_board.get_color_at(p);
                        if (!this->inside_squre_token(p) && this->is_inside_board(p) &&
                            square_color == the_chosen_one) {
                            this->square_token.push_back(p);
                            this->game_board.set_color_at(p, the_chosen_one);
                        }

                    });
                    this->game_board.set_color_at(node_center, the_chosen_one);
                }

            }

        }
    }

}

bool game::has_super_neighbor(position p) {
    auto n = get_neighbours(p);
    for (auto const &p1: n) {
        return std::any_of(square_token.begin(), square_token.end(), p1);
    }
    return false;
}

bool game::inside_squre_token(position p) {
    return std::any_of(square_token.begin(), square_token.end(), p);
}
