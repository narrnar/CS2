//
//  Arena.h
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#ifndef Arena_h
#define Arena_h

#include <stdio.h>
#include "globals.h"
#include <string>

class Player;  // This is needed to let the compiler know that Player and Robot is a
class Robot;   // type name, since it's mentioned in the Arena declaration.

class Arena
{
  public:
        // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(std::string msg) const;
        // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();
  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
};

#endif /* Arena_h */
