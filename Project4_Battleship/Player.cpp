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

//he
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
    Position shipStart = ship.get_start();
    Position shipEnd = ship.get_end();
    int startRow = shipStart.get_row();
    int startCol = shipStart.get_col();
    int endRow = shipEnd.get_row();
    int endCol = shipEnd.get_col();
    if (!(num_ships == MAX_NUM_SHIPS)) {
        if (ship.is_horizontal()) {
            if (endCol < startCol) {
                for (int i = endCol; i <= startCol; i++) {
                    grid[startRow][i] = SHIP_LETTER;
                }
            }
            else if (startCol < endCol) {
                for (int i = startCol; i <= endCol; i++) {
                    grid[startRow][i] = SHIP_LETTER;
                }
            }
            ships[num_ships] = ship;
            num_ships++;
            remaining_ships++;
        }
        else {
            if (endRow < startRow) {
                for (int j = endRow; j <= startRow; j++) {
                    grid[j][endCol] = SHIP_LETTER;
                }
            }
            else if (startRow < endRow) {
                for (int j = startRow; j <= endRow; j++) {
                grid[j][endCol] = SHIP_LETTER;
                }
            }
            ships[num_ships] = ship;
            num_ships++;
            remaining_ships++;
        }
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
    int rowVal = pos.get_row();
    int colVal = pos.get_col();
    if (opponent.position_not_hit(pos)) {
        for (int i = 0; i < opponent.num_ships; i++) {
            if (opponent.ships[i].has_position(pos)) {
                opponent.grid[rowVal][colVal] = HIT_LETTER;
                opponent_grid[rowVal][colVal] = HIT_LETTER;
                opponent.ships[i].hit();
                if (opponent.ships[i].has_sunk()) {
                    opponent.remaining_ships -= 1;
                    int shipSize = opponent.ships[i].get_size();
                    announce_ship_sunk(shipSize);
                }
                cout << name << " " << pos << " hit" << endl;
            }
        }
        opponent.grid[rowVal][colVal] = MISS_LETTER;
        opponent_grid[rowVal][colVal] = MISS_LETTER;
        cout << name << " " << pos << " miss" << endl;
    }
}

void Player::announce_ship_sunk(int size) {
    if (size == 2) {
        cout << "Congratulations " << name << "!" << " You sunk a Destroyer"  << endl;
    }
    else if (size == 3) {
        cout << "Congratulations " << name << "!" << " You sunk a Submarine"  << endl;
    }
    else if (size == 4) {
        cout << "Congratulations " << name << "!"
             << " You sunk a Battleship" << endl;
    }
    else if (size == 5) {
        cout << "Congratulations " << name << "!" << " You sunk a Carrier"
             << endl;
    }
}

bool Player::load_grid_file(string filename) {
    ifstream myfile;
    myfile.open (filename);
    
    while (!(num_ships > MAX_NUM_SHIPS)) {
        if (!myfile.fail()) {
            Position pos1;
            Position pos2;
            myfile >> pos1 >> pos2;
            Ship tempShip(pos1, pos2);
            add_ship(tempShip);
        }
        else {
            return false;
        }
    }
    return true;
}

bool Player::destroyed() {
    if (remaining_ships == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_opponent_grid() {
    ::print_grid(opponent_grid);
}
