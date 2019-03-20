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
 * Ship implementation **FIXME**
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
    // TODO: write implementation here.
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    // TODO: write implementation here.
    return -1;
}

bool Ship::is_horizontal() {
    int row;
    
    if (start[0] == 
    
    return false;
}

bool Ship::has_position(Position pos) {
    // TODO: write implementation here.
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
