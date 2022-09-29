//
// Created by jussymi on 9/27/22.
//

#ifndef FLOODIT_GAME_H
#define FLOODIT_GAME_H

#include "board.h"
class game {
    color the_chosen_one;
    std::vector<position> occupied_;
    board game_board;
    game(int,int,int);
    game();
    void initialize();


};


#endif //FLOODIT_GAME_H
