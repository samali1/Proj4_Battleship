/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.h
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 * Project 4: Battleship
 *
 * Represents a ship.
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "Position.h"
#include "utility.h"


class Ship {
 public:

    /**
     * Requires: Nothing.
     * Modifies: start, end, size, num_hits.
     * Effects:  Default contructor. Sets start and end to origin (0,0),
     *           num_hits to 0, and size to 0.
     */
    Ship();

    /**
     * Requires: start_in and end_in both represent valid and distinct
     *           positions on the grid and align either vertically or horizontally.
     *           Diagonal or L-shaped ships are not allowed. 
     * Modifies: start, end, size, num_hits.
     * Effects:  Non-default contructor. Sets start and end to start_in and
     *           end_in respectively and num_hits to 0.
     *           The size should be determined by the start and end positions.
     *
     * Note:     You will want to implement the member function
     *           is_horizontal() before implementing this constructor.
     */
    Ship(Position start_in, Position end_in);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the start position of the ship.
     */
    Position get_start();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the end position of the ship.
     */
    Position get_end();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the size of the ship.
     */
    int get_size();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if the ship is horizontal and false if the ship
     *           is vertical.
     */
    bool is_horizontal();

    /**
     * Requires: pos must be a valid position in the grid.
     * Modifies: Nothing.
     * Effects:  Returns true if pos is in the range [start, end] or [end, start].
     *           Otherwise, return false.
     */
    bool has_position(Position pos);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Increments the num_hits if num_hits is less than size
     */
    void hit();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if the num_hits equals the size of the ship.
     *           Otherwise, return false.
     */
    bool has_sunk();

 private:
    Position start;
    Position end;
    int size;
    int num_hits;
};

#endif  // SHIP_H_
