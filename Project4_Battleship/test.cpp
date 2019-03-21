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
    test_ship();
    test_player();
    return 0;
}

void test_position() {
    // Write your tests here
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

