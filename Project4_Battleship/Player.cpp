/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Sameer Ali & Yaozong Huang
 * samali & yaozongh
 *
 * Project 4: Battleship
 *
 * Player implementation. ***FIX DESC***
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            grid[i][j] = EMPTY_LETTER;
        }
    }
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            opponent_grid[i][j] = EMPTY_LETTER;
        }
    }
}

string Player::get_name() {
    return name;
}

int Player::get_num_ships() {
    return num_ships;
}

int Player::get_remaining_ships() {
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}

char Player::get_opponent_grid_at(int row, int col) {
    return opponent_grid[row][col];
}

void Player::add_ship(Ship ship) {
    ship.get_start();
    ship.get_end();
    while (num_ships < MAX_NUM_SHIPS) {
    
    }
    
}

bool Player::position_not_hit(Position pos) {
    int rowVal = pos.get_row();
    int colVal = pos.get_col();
    char boardValue = grid[rowVal][colVal];
    if (boardValue == EMPTY_LETTER || boardValue == SHIP_LETTER) {
        return true;
    }
    return false;
}

void Player::attack(Player &opponent, Position pos) {
    // TODO: write implementation here.
    return;
}

void Player::announce_ship_sunk(int size) {
    // TODO: write implementation here.
    return;
}

bool Player::load_grid_file(string filename) {
    // TODO: write implementation here.
    return false;
}

bool Player::destroyed() {
    if (remaining_ships == 0) {
        return true;
    }
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_opponent_grid() {
    ::print_grid(opponent_grid);
}
