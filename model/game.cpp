//
// Created by jussymi on 9/27/22.
//

#include "game.h"

game::game(int row, int col, int nb_color) {
    this->game_board = board(row,col,nb_color);
}

game::game() {
    this->game_board = board(10,10,6);

}

void game::initialize() {
    this->game_board.init_board();

}
