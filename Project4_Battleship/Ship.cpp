/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Sameer Ali & Yaozong Huang
 * samali & yaozongh
 *
 * Project 4: Battleship
 *
 * Implementing the Ships aspect of Battleship, where each ship is
 * constructed from two positions (Position class). The ship has properties
 * that are used in gameplay.
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    start = Position();
    end = Position();
    num_hits = 0;
    size = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    int startRow = start_in.get_row();
    int startCol = start_in.get_col();
    int endRow = end_in.get_row();
    int endCol = end_in.get_col();
    
    start = Position(startRow, startCol);
    end = Position(endRow, endCol);
    
    if (is_horizontal()) {
        if (startCol <= endCol) {
            size = endCol - startCol + 1;
        }
        else if (endCol < startCol) {
            size = startCol - endCol + 1;
        }
    }
    else {
        if (startRow <= endRow) {
            size = endRow - startRow + 1;
        }
        else if (endRow < startRow) {
            size = startRow - endRow + 1;
        }
    }
    
    num_hits = 0;
    
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    return size;
}

bool Ship::is_horizontal() {
    if (start.get_row() == end.get_row()) {
        return true;
    }
    else {
        return false;
    }
}

bool Ship::has_position(Position pos) {
    int posRow = pos.get_row();
    int posCol = pos.get_col();
    
    int startRow = start.get_row();
    int startCol = start.get_col();
    int endRow = end.get_row();
    int endCol = end.get_col();
    
    if (((posRow >= startRow) && (posRow <= endRow)) &&
        ((posCol >= startCol) && (posCol <= endCol))) {
        return true;
    }
    else if (((posRow >= endRow) && (posRow <= startRow)) &&
             ((posCol >= endCol) && (posCol <= startCol))) {
        return true;
    }
    else{
        return false;
    }
}

void Ship::hit() {
    if (num_hits < size) {
        num_hits++;
    }
    return;
}

bool Ship::has_sunk() {
    if (num_hits == size) {
        return true;
    }
    else {
        return false;
    }
}
