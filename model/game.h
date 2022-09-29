//
// Created by jussymi on 9/27/22.
//

#ifndef FLOODIT_GAME_H
#define FLOODIT_GAME_H

#include "board.h"
using direction=std::pair<int,int>;
struct _direction
{
static constexpr const direction UP{-1,0};
static constexpr const direction DOWN{1,0};
static constexpr const direction LEFT{0,1};
static constexpr const direction RIGHT{0,-1};

};
class game {
    color the_chosen_one;
    std::vector<position> square_token;
    board game_board;
public:
    game(int,int,int);
    game();
    void initialize();



};


#endif //FLOODIT_GAME_H
