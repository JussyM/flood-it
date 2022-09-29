//
// Created by jussymi on 9/27/22.
//

#ifndef FLOODIT_GAME_H
#define FLOODIT_GAME_H

#include "board.h"
using direction=std::pair<int,int>;
/**
 * Defined direction for getting the neighbors of a square
 */
struct _direction
{
static constexpr const direction UP{-1,0};
static constexpr const direction DOWN{1,0};
static constexpr const direction LEFT{0,1};
static constexpr const direction RIGHT{0,-1};

};
class game {
public:
    /**
     * set color
     * @param theChosenOne
     */
    void setTheChosenOne(color theChosenOne);
    /**
     * game constructor
     */
    game(int,int,int);
    /**
     * another constructor i really don't know why he's their
     */
    game();
    /**
     * initialize game
     */
    void initialize();
    /**
     * update the board when player choose his color
     */
    void update_game();



private:
    std::vector<position> square_token;
    board game_board;
    color the_chosen_one;
    /**
     * get all the neighbors of a particular position
     * @return std::array of position
     */
    std::array<position,4> get_neighbours(position);
    /**
     * verify if a position is inside the board
     * @param p the position for verification
     * @return true/false
     */
    bool is_inside_board(position p);
    /**
     * return true if the position given as argument has a neighbor that has already been took
     * @param p for verification
     * @return true/false
     */
    bool has_super_neighbor(position p);
    /**
     * verify if the position is already inside the square_toke list
     * @param p for verification
     * @return true/false
     */
    bool inside_squre_token(position p);




};


#endif //FLOODIT_GAME_H
