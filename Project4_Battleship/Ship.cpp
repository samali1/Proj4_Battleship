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
 * Ship shit
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    Position start;
    Position end;
    num_hits = 0;
    size = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    int startRow = start_in.get_row();
    int startCol = start_in.get_col();
    int endRow = end_in.get_row();
    int endCol = end_in.get_col();
    
    start.set_row(startRow);
    start.set_col(startCol);
    end.set_row(endRow);
    end.set_col(endCol);
    
    if (
    
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
    if (((posRow >= startRow) && (posRow <= endRow)) && ((posCol >= starCol) && (posCol <= endCol))) {
        return true;
    }
    else if (((posRow >= startRow) && (posRow <= endRow)) && ((posCol >= starCol) && (posCol <= endCol))) {
    }
    
    return false;
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
