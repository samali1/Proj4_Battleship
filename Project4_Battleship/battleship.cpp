/**
 * Copyright 2019 Umich EECS 183
 *
 * battleship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Project 4: Battleship
 *
 * Drive of the Battleship game.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <utility>
#include <limits>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


int main() {

/* 
    TODO: implement the following steps. 
    
    (Note: some menus and prompts should be printed using 
       functions utility.cpp, see sample runs.)

    1. You must enter your name.

        Prompt: "Enter your name:"

    2. Print prompt and get user input from keyboard to specify whether 
    not to read your grid from a file. The input must be the chracter 'y' or 'n'.

        Prompt: "Read your grid from file grid1.txt? (y or n):"
        Note: You may assume that a user will enter correct, valid input. 

    3. Print prompt and get user input from keyboard to specify whether 
    not to read the CPU's grid from a file. The input must be the chracter 'y' or 'n'.

        Prompt: "Read CPU grid from file grid2.txt? (y or n):"
        Note: You may assume that a user will enter correct, valid input. 
    
    4. Print menu and get the menu choice from keyboard to select the 
    difficulty of the AI or quit the game. Make use of get_menu_choice in utility.cpp. 
        
        Prompts: "Starting game with EASY AI"
                 "Starting game with MEDIUM AI"
                 "Starting game with CPU EMULATION"
        Note 1: the medium AI is not available unless you implement S'more. 
        Note 2: CPU emulation is for debugging purposes and will NOT be autograder tested.

    5. Start the game with given difficulty and MAX_ROUNDS number of rounds.

    (Note: you will only play one instance of the game, i.e., after the game ends, 
       the program ends.)
*/
    Game();
    print_initial_header();
    string player1name;
    string player2name = "CPU";
    cout << "Enter your name: " << player1name << endl;
    getline(cin, player1name);
    
    char userChoice;
    cout << "Read your grid from file grid1.txt? (y or n):";
    cin >> userChoice;
    cout << endl;
    string grid1 = "";
    if (userChoice == 'y') {
        grid1 = "grid1.txt";
    }
    
    char userChoice2;
    cout << "Read CPU grid from file grid2.txt? (y or n):";
    cin >> userChoice2;
    cout << endl;
    string grid2 = "";
    if (userChoice2 == 'y') {
        grid2 = "grid2.txt";
    }
    
    Player p1(player1name);
    Player p2(player2name);
    Game battleship(p1, grid1, p2, grid2);
    
    int gameChoice = get_menu_choice();
    
    while (gameChoice == 2) {
        cout << "Under Construction" << endl;
        gameChoice = get_menu_choice();
    }
    if (gameChoice == 1) {
        cout << "Starting game with EASY AI" << endl;
        battleship.start(EASY, MAX_ROUNDS);
    }
    if (gameChoice == 3) {
        cout << "Starting game with CPU EMULATION" << endl;
        battleship.start(EMULATE, MAX_ROUNDS);
    }
    if (gameChoice == 4) {
        print_closer();
    }
}
