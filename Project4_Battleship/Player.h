/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.h
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 * Project 4: Battleship
 *
 * Represents a player.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "Position.h"
#include "Ship.h"
#include "utility.h"

using namespace std;

class Player {
 public:
    /**
     * Requires: Nothing.
     * Modifies: name, num_ships, remaining_ships, grid, opponent_grid.
     * Effects:  Default contructor. Sets name to an empty string,
     *           num_ships to 0, remaining_ships to 0, and initialize the grid.
     *
     * Note:     You will want to implement the member function
     *           init_grid() before implementing this constructor.
     */
    Player();

    /**
     * Requires: name_val is not an empty string.
     * Modifies: name, num_ships, remaining_ships, grid, opponent_grid.
     * Effects:  Non-default contructor. Sets name to name_val,
     *           num_ships to 0, remaining_ships to 0, and initialize the grid.
     *
     * Note:     You will want to implement the member function
     *           init_grid() before implementing this constructor.
     */
    Player(string name_val);
    
    /**
     * Requires: Nothing.
     * Modifies: grid, opponent_grid.
     * Effects:  Sets each element in both grid and opponent_grid to
     *           EMPTY_LETTER.
     */
    void init_grid();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the player.
     */
    string get_name();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of ships of the player.
     */
    int get_num_ships();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of remaining ships of the player.
     */
    int get_remaining_ships();

    /**
     * Requires: row and col are valid positions in grid.
     * Modifies: Nothing.
     * Effects:  Returns the element at row, col of grid.
     */
    char get_grid_at(int row, int col);

    /**
     * Requires: row and col are valid positions in opponent_grid.
     * Modifies: Nothing.
     * Effects:  Returns the element at row, col of opponent_grid.
     */
    char get_opponent_grid_at(int row, int col);

    /**
     * Requires: ship is a valid ship with start/end positions that 
     *           do not intersect with previously added ships. 
     * Modifies: ships, num_ships, remaining_ships, grid.
     * Effects:  Adds the ship to the next available index of ships and
     *           increment num_ships and remaining_ships.
     *           Set the positions on grid with SHIP_LETTER based on the
     *           start and end of ship. If num_ships >= MAX_NUM_SHIPS,
     *           the function should return without making any changes. 
     */
    void add_ship(Ship ship);

    /**
     * Requires: pos is a valid position.
     * Modifies: Nothing.
     * Effects:  Returns true if the position on grid is EMPTY_LETTER or
     *           SHIP_LETTER. Otherwise, return false.
     *
     *          (ie. This tests if pos has already been attacked. Any position
     *           not attacked yet will either be EMPTY_LETTER or SHIP_LETTER)
     */
    bool position_not_hit(Position pos);

    /**
     * Requires: pos is a valid position.
     * Modifies: opponent, opponent_grid, cout.
     * Effects:  If the pos is not hit for the opponent, and the opponent
     *           has a ship that has pos, hit that ship and mark both the
     *           opponent's grid and the current player's opponent_grid as
     *           HIT_LETTER at pos.
     *
     *           Otherwise, if pos is not a position in the opponent's ships
     *           (i.e. a miss), mark both the opponent's grid and the current
     *           player's opponent_grid as MISS_LETTER.
     *
     *
     *           On hit, print the attacking player's name, the position,
     *           and "hit".
     *           On miss, print the attacking player's name, the position,
     *           and "miss".
     *
     *           If hitting the ship causes that ship to
     *           sink, decrement the opponent's remaining_ships, and use
     *           announce_ship_sunk() to print message.
     *
     * Example:
     *           [name] [pos] hit
     *           [name] [pos] miss
     */
    void attack(Player &opponent, Position pos);

    /**
     * Requires: size is [2, 5].
     * Modifies: cout.
     * Effects:  Prints a congratulating message followed by the name and the
     *           type of ships that was sunk.
     *
     * Example:
     *           if size = 2: "Congratulations [name]! You sunk a Destroyer"
     *           if size = 3: "Congratulations [name]! You sunk a Submarine"
     *           if size = 4: "Congratulations [name]! You sunk a Battleship"
     *           if size = 5: "Congratulations [name]! You sunk a Carrier"
     */
    void announce_ship_sunk(int size);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if remaining_ships equal zero.
     *           Otherwise return false.
     */
    bool destroyed();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints grid.
     */
    void print_grid();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints opponent_grid.
     */
    void print_opponent_grid();

    /**
     * Requires: Nothing.
     * Modifies: ships, num_ships, remaining_ships, grid.
     * Effects: use filename to open a file stream and read in the start
     *          and end positions for each ship to be added. Returns true
     *          if the file opened successfully; false otherwise.
     *
     *          Note: should call add_ship function.
     *
     *          Note: The number of ships in the file <filename> may not
     *                be exactly MAX_NUM_SHIPS.
     */
    bool load_grid_file(string filename);

 private:
    string name;
    int num_ships;
    int remaining_ships;
    Ship ships[MAX_NUM_SHIPS];
    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    char opponent_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];

};

#endif  // PLAYER_H_