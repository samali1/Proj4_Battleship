/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

int main() {
    test_position();
    // test_ship();
    // test_player();
    return 0;
}

void test_position() {
    // testing Default Constructor
    Position pos;
    
    cout << "Getting position" << endl;
    cout << pos.get_row() << " ";
    cout << pos.get_col() << " ";
    cout << endl;
    
    cout << endl;
    
    // testing Non-default Constructors
    
    // Constructor 1
    Position pos1(0,0);
    Position pos2(1,3);
    Position pos3(8,8);
    Position pos4(0,8);
    
    cout << "Getting positions" << endl;
    cout << pos1.get_row() << " ";
    cout << pos1.get_col() << " ";
    cout << endl;
    cout << pos2.get_row() << " ";
    cout << pos2.get_col() << " ";
    cout << endl;
    cout << pos3.get_row() << " ";
    cout << pos3.get_col() << " ";
    cout << endl;
    cout << pos4.get_row() << " ";
    cout << pos4.get_col() << " ";
    cout << endl;
    
    cout << endl;
    
    // Constructor 2
    Position pos5('1','A');
    Position pos6('1','a');
    Position pos7('3','C');
    Position pos8('4','h');
    
    cout << "Getting positions" << endl;
    cout << pos5.get_row() << " ";
    cout << pos5.get_col() << " ";
    cout << endl;
    cout << pos6.get_row() << " ";
    cout << pos6.get_col() << " ";
    cout << endl;
    cout << pos7.get_row() << " ";
    cout << pos7.get_col() << " ";
    cout << endl;
    cout << pos8.get_row() << " ";
    cout << pos8.get_col() << " ";
    cout << endl;
    
    cout << endl;
    
    // testing Setters
    int row = 0, col = 0;
    int row1 = 2, col1 = 0;
    int row2 = 1, col2 = 4;
    
    Position pos9;
    Position pos10;
    Position pos11;
    
    pos9.set_row(row);
    pos9.set_col(col);
    pos10.set_row(row1);
    pos10.set_col(col1);
    pos11.set_row(row2);
    pos11.set_col(col2);
    
    cout << "Getting position based on setters" << endl;
    cout << pos9.get_row() << " ";
    cout << pos9.get_col() << " ";
    cout << endl;
    cout << pos10.get_row() << " ";
    cout << pos10.get_col() << " ";
    cout << endl;
    cout << pos11.get_row() << " ";
    cout << pos11.get_col() << " ";
    cout << endl;
    
    cout << endl;
    
    // testing reading and writing positions
    
    
    return;
}

void test_ship() {
    Ship defaultCon;
    
    Position start('1','A');
    Position end('1','C');
    Ship nonDefault(start, end);
    
    // testing Constructors
    
    cout << defaultCon.get_start() << " ";
    cout << defaultCon.get_end() << " ";
    cout << defaultCon.get_size() << endl;
    cout << "DefShip has no size, expect 1, actual :" <<  defaultCon.has_sunk() << endl;
    
    cout << endl;
    
    cout << nonDefault.get_start() << " ";
    cout << nonDefault.get_end() << " ";
    cout << nonDefault.get_size();
    
    cout << endl;
    
    // testing hitting and if a ship has sunk
    
    cout << "NonShip is not sunk, expect 0, actual: " << nonDefault.has_sunk() << endl;
    int size = nonDefault.get_size();
    for (int i = 0; i < size; i++) {
        nonDefault.hit();
    }
    cout << "NonShip has sunk, expect 1, actual: " << nonDefault.has_sunk() << endl;
    
    cout << endl;
    
    // testing vertical ship
    
    Position start1('1','C');
    Position end1('3','C');
    Ship verticalShip(start1, end1);
    
    cout << verticalShip.get_start() << " ";
    cout << verticalShip.get_end() << " ";
    cout << verticalShip.get_size() << endl;
    cout << "VerShip is not sunk, expect 0, actual: " << verticalShip.has_sunk() << endl;
    int size1 = verticalShip.get_size();
    for (int i = 0; i < size1; i++) {
        verticalShip.hit();
    }
    cout << "VerShip is sunk, expect 1, actual: " << verticalShip.has_sunk() << endl;
    
    cout << endl;
    
    // testing when end position comes before start (on grid)
    
    //Vertical
    Position start2(2,3);
    Position end2(0,3);
    Ship endBeforeStart(start2, end2);
    
    cout << endBeforeStart.get_start() << " ";
    cout << endBeforeStart.get_end() << " ";
    cout << endBeforeStart.get_size() << endl;
    cout << "eBsShip is not sunk, expect 0, actual: " << endBeforeStart.has_sunk() << endl;
    int size2 = endBeforeStart.get_size();
    for (int i = 0; i < size2; i++) {
        endBeforeStart.hit();
    }
    cout << "eBsShip is sunk, expect 1, actual: " << endBeforeStart.has_sunk() << endl;
    
    cout << endl;
    
    //Horizontal
    Position start3(2,7);
    Position end3(2,3);
    Ship endBeforeStart1(start3, end3);
    
    cout << endBeforeStart1.get_start() << " ";
    cout << endBeforeStart1.get_end() << " ";
    cout << endBeforeStart1.get_size() << endl;
    cout << "eBs2Ship is not sunk, expect 0, actual: " << endBeforeStart1.has_sunk() << endl;
    int size3 = endBeforeStart1.get_size();
    for (int i = 0; i < size3-1; i++) {
        endBeforeStart1.hit();
    }
    cout << "eBs2Ship has still not sunk, expect 0, actual: " << endBeforeStart1.has_sunk() << endl;
    return;
}

void test_player() {
    // Write your tests here
    return;
}

