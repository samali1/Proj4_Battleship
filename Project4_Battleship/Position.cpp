/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Sameer Ali & Yaozong Huang
 * samali & yaozongh
 *
 * Project 4: Battleship
 *
 * Implementing the position aspect of Battleship.
 */

#include "Position.h"
#include "utility.h"



Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
}

Position::Position(char row_in, char col_in) {
    int rowVal = 0;
    rowVal = (int) row_in;
    rowVal = rowVal - 49;
    row = check_range(rowVal);
    
    int colVal = 0;
    colVal = (int) col_in;
    colVal = colVal - 65;
    col = check_range(colVal);
}

int Position::get_row() {
    return check_range(row);
}

void Position::set_row(int row_in) {
    row = check_range(row_in);
}

int Position::get_col() {
    return check_range(col);
}

void Position::set_col(int col_in) {
    col = check_range(col_in);
}

void Position::read(istream &is) {
    int rowVal;
    char colChar;
    is >> rowVal;
    if (!is.fail()) {
        is >> colChar;
        colChar = toupper(colChar);
        row = check_range(rowVal - 1);
        int colVal = 0;
        colVal = (int) colChar;
        col = check_range(colVal - 65);
    }
    else {
        is.clear();
        char openPar;
        char endPar;
        char comma;
        is >> openPar >> rowVal >> comma >> colChar >> endPar;
        row = check_range(rowVal - 1);
        colChar = toupper(colChar);
        int colVal = 0;
        colVal = (int) colChar;
        col = check_range(colVal - 65);
    }
}

void Position::write(ostream &os) {
    char colOut = col + 'A';
    int rowOut = row + 1;
    os << "(" << rowOut << "," << colOut << ")";
}

int Position::check_range(int val) {
    if ( (val >= 0) && (val <= MAX_GRID_SIZE)) {
        return val;
    }
    else {
        if (val < MAX_GRID_SIZE - 1 - val) {
            return 0;
        }
        else {
            return MAX_GRID_SIZE - 1;
        }
    }
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

