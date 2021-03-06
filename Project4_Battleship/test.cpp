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
    test_game();
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
    Position pos12;
    Position pos13;
    Position pos14;
    cout << "Getting position from reading grid2.txt" << endl;
    
    // reading
    ifstream reading;
    reading.open("grid2.txt");
    pos12.read(reading);
    cout << "Expected (2,5), actual: ";
    cout << pos12.get_row() << " " << pos12.get_col() << endl;
    pos13.read(reading);
    cout << "Expected (2,6), actual: ";
    cout << pos13.get_row() << " " << pos13.get_col();
    reading.close();
    reading.open("grid1.txt");
    cout << endl;
    pos14.read(reading);
    cout << "Expected (7,1), actual: ";
    cout << pos14.get_row() << " " << pos14.get_col() << endl;
    reading.close();
    
    // writing
    ofstream writing;
    writing.open("grid3.txt");
    pos12.write(writing);
    
    cout << endl;
    
    
    return;
}

void test_ship() {
    Ship defaultCon;
    
    Position start('1','A');
    Position end('1','C');
    Position pos('1','b');
    Position pos1('2','A');
    Position pos2('1','a');
    Position pos3('1','c');
    Position pos4('1','h');
    Position pos5('8','a');
    Position pos6('8','H');
    
    Ship nonDefault(start, end);
    
    // testing Constructors
    
    cout << defaultCon.get_start() << " ";
    cout << defaultCon.get_end() << " ";
    cout << defaultCon.get_size() << endl;
    cout << "DefShip has no size, expect 1, actual: " <<  defaultCon.has_sunk() << endl;
    
    cout << endl;
    
    cout << nonDefault.get_start() << " ";
    cout << nonDefault.get_end() << " ";
    cout << nonDefault.get_size() << endl;
    cout << "Position (1,B) is in the range, expect: 1, actual: "
         << nonDefault.has_position(pos) << endl;
    cout << "Position (2,A) is not in the range, expect: 0, actual: "
         << nonDefault.has_position(pos1) << endl;
    cout << "Position (1,A) is in the range, expect: 1, actual: "
    << nonDefault.has_position(pos2) << endl;
    cout << "Position (1,C) is in the range, expect: 1, actual: "
    << nonDefault.has_position(pos3) << endl;
    cout << "Position (1,H) is not in the range, expect: 0, actual: "
    << nonDefault.has_position(pos4) << endl;
    cout << "Position (8,A) is not in the range, expect: 0, actual: "
    << nonDefault.has_position(pos5) << endl;
    cout << "Position (8,H) is not in the range, expect: 0, actual: "
    << nonDefault.has_position(pos6) << endl;
    
    
    cout << endl;
    
    // testing hitting and if a ship has sunk
    
    cout << "NonShip is not sunk, expect 0, actual: " << nonDefault.has_sunk() << endl;
    int size = nonDefault.get_size();
    for (int i = 0; i < size-1; i++) {
        nonDefault.hit();
    }
    cout << "NonShip is not sunk, expect 0, actual: " << nonDefault.has_sunk() << endl;
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
    
    cout << endl;
    return;
}

void test_player() {
    
    // testing Default Constructor
    Player p1;
    cout << "Expected: \"\", actual: " << p1.get_name() << endl;
    
    cout << endl;
    
    // testing Non-default Constructor
    Player p2("Sameer");
    cout << "Expected: \"Sameer\", actual: " << p2.get_name() << endl;
    
    cout << endl;
    
    // testing add_ship and counters
    Position start('1','A');
    Position end('1','C');
    Ship ship(start, end);
    
    Position start1('3','B');
    Position end1('5','b');
    Ship ship1(start1, end1);
    
    p2.add_ship(ship);
    cout << "Grid with one ship" << endl;
    p2.print_grid();
    cout << "Num of ships: " << p2.get_num_ships() << " "
         << "and remaining ships: " << p2.get_remaining_ships() << endl;
    p2.add_ship(ship1);
    cout << "Grid with two ships" << endl;
    p2.print_grid();
    cout << "Num of ships: " << p2.get_num_ships() << " "
         << "and remaining ships: " << p2.get_remaining_ships() << endl;
    
    cout << endl;
    cout << endl;
    
    // testing adding more ships
    
    Player test;
    
    Position start2('1','A');
    Position end2('1','C');
    Ship ship2(start2, end2);
    
    Position start3('4','B');
    Position end3('3','b');
    Ship ship3(start3, end3);
    
    Position start4(6,1);
    Position end4(6,5);
    Ship ship4(start4, end4);
    
    Position start5('1','H');
    Position end5('3','H');
    Ship ship5(start5, end5);
    
    Position start6('5','F');
    Position end6('5','C');
    Ship ship6(start6, end6);
    
    Position start7('4','A');
    Position end7('5','A');
    Ship ship7(start7, end7);
    
    test.add_ship(ship2);
    test.add_ship(ship3);
    test.add_ship(ship4);
    test.add_ship(ship5);
    cout << "Num of ships: " << test.get_num_ships()
         << " and remaining ships: " << test.get_remaining_ships() << endl;
    test.add_ship(ship6);
    cout << "Num of ships: " << test.get_num_ships()
         << " and remaining ships: " << test.get_remaining_ships() << endl;
    test.print_grid();
    cout << "Trying to add a 6th ship" << endl;
    test.add_ship(ship7);
    test.print_grid();
    
    cout << endl;
    
    // testing position_not_hit
    Position onShip('1','A');
    Position onShip1('1','B');
    Position onShip2('1','c');
    Position empty(1,4);
    Position empty2(7,7);
    
    cout << "Expected: 1, actual: " << test.position_not_hit(onShip) << endl;
    cout << "Expected: 1, actual: " << test.position_not_hit(onShip1) << endl;
    cout << "Expected: 1, actual: " << test.position_not_hit(empty) << endl;
    cout << "Expected: 1, actual: " << test.position_not_hit(empty2) << endl;
    
    cout << endl;
    
    // testing attack
    p2.attack(test, empty);
    test.print_grid();
    cout << endl;
    p2.attack(test, onShip);
    test.print_grid();
    cout << endl;
    p2.attack(test, empty2);
    test.print_grid();
    cout << endl;
    p2.attack(test, onShip);
    test.print_grid();
    cout << endl;
    p2.attack(test, onShip1);
    test.print_grid();
    cout << endl;
    p2.attack(test, onShip2);
    test.print_grid();
    cout << endl;
    p2.attack(test, empty);
    test.print_grid();
    cout << endl;
    
    // testing edge cases
    Position edgeCase(0,0);
    
    
    // testing more attack
    
    Position anotherShip('5','C');
    Position anotherShip1('5','D');
    Position anotherShip2('5','E');
    Position anotherShip3('5','F');
    
    p2.attack(test, anotherShip);
    cout << endl;
    p2.attack(test, anotherShip1);
    cout << endl;
    p2.attack(test, anotherShip2);
    cout << endl;
    p2.attack(test, anotherShip3);
    cout << endl;
    test.print_grid();
    
    test.attack(p2, onShip);
    test.print_opponent_grid();
    
    cout << endl;
    // testing Destroyed
    
    // testing load_grid_file
    Player p3("Frank");

    string filename = "grid1.txt";
    p3.load_grid_file(filename);
    p3.print_grid();
    cout << endl;
    
    Player p4("Frank2");

    string filename1 = "grid2.txt";
    p4.load_grid_file(filename1);
    p4.print_grid();
}

void test_game() {
    // testing Non-default Constructors
    string frank = "Frank";
    Player Frank(frank);
    string sameer = "Sameer";
    Player Sameer(sameer);
    Player p1;
    Player p2;
    string grid1 = "grid1.txt";
    string grid2 = "grid2.txt";
    string grid3 = "yeet.txt";
    string grid4 = "";
    string grid5 = " ";
    
    Game nonDef(Frank, grid1, Sameer, grid2);
    Game badNonDef2(Frank, grid1, Sameer, grid3);
    Game emptyDef(Frank, grid1, Sameer, grid4);
    Game emptyDef1(Frank, grid4, Sameer, grid2);
    Game emptyDef2(Frank, grid4, Sameer, grid5);
    Game gameTwo(p1, "grid1.txt", p2, "grid2.txt");
    Game gameThree(Frank, "", p2, "grid2.txt");
    Game gameFour(p1, "", p2, "");
    Game gameFive(p1, "grid1.txt", Sameer, "");
    
    
    // more testing for Constructor
    Game goodGame(Sameer, grid1, Frank, grid2);
    
    cout << endl;
    
    // testing check_valid_move
    Game testGame;
    
    string validMove = "1A";
    string validMove1 = "2F";
    string validMove2 = "8H";
    string validMove3 = "8A";
    string validMove4 = "1H";
    string validMove5 = "3c";
    string invalidMove = "10A";
    string invalidMove1 = "*B";
    string invalidMove2 = "B";
    string invalidMove3 = "BB";
    string invalidMove4 = "0A";
    string invalidMove5 = "18";
    
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove)
         << endl;
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove1)
         << endl;
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove2)
         << endl;
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove3)
         << endl;
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove4)
         << endl;
    cout << "Expected: 1, actual: " << nonDef.check_valid_move(validMove5)
         << endl;
    
    cout << endl;
    
    nonDef.check_valid_move(invalidMove);
    nonDef.check_valid_move(invalidMove1);
    nonDef.check_valid_move(invalidMove2);
    nonDef.check_valid_move(invalidMove3);
    nonDef.check_valid_move(invalidMove4);
    nonDef.check_valid_move(invalidMove5);
    
    cout << endl;
    
    // trying to test Game again
    Game gameOne;
    Game();
    
    cout << gameOne.get_p1().get_name();
    
    // testing getters part 2 (pls work for fuck's sake)
    
    cout << gameOne.get_p1().get_name();
    cout << gameOne.get_p2().get_name();
    cout << gameTwo.get_p1().get_name();
    cout << gameTwo.get_p2().get_name();
    cout << gameThree.get_p1().get_name();
    cout << gameThree.get_p2().get_name();
    cout << gameFour.get_p1().get_name();
    cout << gameFour.get_p2().get_name();
    cout << gameFive.get_p1().get_name();
    cout << gameFive.get_p2().get_name();
    
    cout << endl;
    
    cout << gameOne.get_p1().get_num_ships();
    cout << gameOne.get_p2().get_num_ships();
    cout << gameTwo.get_p1().get_num_ships();
    cout << gameTwo.get_p2().get_num_ships();
    cout << gameThree.get_p1().get_num_ships();
    cout << gameThree.get_p2().get_num_ships();
    cout << gameFour.get_p1().get_num_ships();
    cout << gameFour.get_p2().get_num_ships();
    cout << gameFive.get_p1().get_num_ships();
    cout << gameFive.get_p2().get_num_ships();
    
    cout << endl;
    
    cout << gameOne.get_p1().get_remaining_ships();
    cout << gameOne.get_p2().get_remaining_ships();
    cout << gameTwo.get_p1().get_remaining_ships();
    cout << gameTwo.get_p2().get_remaining_ships();
    cout << gameThree.get_p1().get_remaining_ships();
    cout << gameThree.get_p2().get_remaining_ships();
    cout << gameFour.get_p1().get_remaining_ships();
    cout << gameFour.get_p2().get_remaining_ships();
    cout << gameFive.get_p1().get_remaining_ships();
    cout << gameFive.get_p2().get_remaining_ships();
    
    cout << endl;
    
    cout << "Printing the grids of player 1 and player 2" << endl;
    gameOne.get_p1().print_grid();
    cout << endl;
    gameOne.get_p2().print_grid();
    cout << endl;
    gameTwo.get_p1().print_grid();
    cout << endl;
    gameTwo.get_p2().print_grid();
    cout << endl;
    gameThree.get_p1().print_grid();
    cout << endl;
    gameThree.get_p2().print_grid();
    cout << endl;
    gameFive.get_p1().print_grid();
    cout << endl;
    gameFive.get_p2().print_grid();
    cout << endl;
    
    
    // testing Game getters (?)
    nonDef.get_p1();
    nonDef.get_p2();
    
    badNonDef2.get_p1();
    badNonDef2.get_p2();
    
    emptyDef.get_p1();
    emptyDef.get_p2();
    
    emptyDef1.get_p1();
    emptyDef1.get_p2();
    
    emptyDef1.get_p1();
    emptyDef1.get_p2();
    
    testGame.get_p1();
    testGame.get_p2();
    
}
