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
struct node{
    color node_color;
    node()=default;
};
struct nodes{
    std::vector<node>column;

};

/**
 * structure to defined position inside the board
 *
 */
struct position {
    int x_;
    int _y;

/**
 * Position constructor
 * @param row of a square in the board
 * @param col of the square in the board
 */
    position(int row, int col) {
        x_ = row;
        _y = col;
    }

    /**
     * Default constructor for implicit creation
     */
    position() = default;

    /**
     * Copy constructor of position
     * @param rsh another position
     */
    position(const position &rsh) {
        x_ = rsh.x_;
        _y = rsh._y;
    }

    /**
     * operator () for predicate in finding element in a vector
     * @param rsh other position for compare
     * @return true/false
     */
    bool operator()(position &rsh) const {
        return this->operator==(rsh);
    }

    /**
     * assign operator
     * @param rsh position object for assignation
     * @return position object
     */
    position &operator=(position rsh) {
        std::swap(x_, rsh.x_);
        std::swap(_y, rsh._y);
        return *this;
    }

    /**
     * equal operator for comparing two position
     * @param rsh other position for comparing
     * @return true/false
     */
    bool operator==(position &rsh) const {
        return this->x_ == rsh.x_ && this->_y == rsh._y;
    }
};

/**
 * game board structure
 */
class board {
private:
    int row_;
    int column_;
    int nb_color;

public:
    int getNbColor() const;

/**
 * Initialize board by creating each attribute and filling the board
 */
void init_board();

private:
    std::vector<nodes> square_;



public:
    /**
     * Board constructor
     * @param row for board size
     * @param column for board size
     * @param nbColor to fill the board randomly
     */
    board(int row, int column, int nbColor);

    /**
     * default constructor
     */
    board() = default;

    /**
     * getter for row
     * @return  row
     */
    int getRow() const;

/**
 * getter for column
 * @return column
 */
    int getColumn() const;


    /**
     * return a color at a certain position
     * @return color enum
     */
    color get_color_at(position);

    /**
     * set a color at a specific position
     */
    void set_color_at(position, color);


};


#endif //FLOODIT_BOARD_H
