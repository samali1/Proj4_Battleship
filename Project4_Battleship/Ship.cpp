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
    Position::
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
    int row = pos.get_row();
    int col = pos.get_col();
    
    
    
    return false;
}

void Ship::hit() {
    // TODO: write implementation here.
    return;
}

bool Ship::has_sunk() {
    // TODO: write implementation here.
    return false;
}
