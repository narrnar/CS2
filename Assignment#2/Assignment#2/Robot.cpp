//
//  Robot.cpp
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#include "Robot.h"
#include <iostream>
#include <cmath>
#include "Arena.h"
#include "globals.h"

///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////
Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        std::cout << "***** A robot must be in some Arena!" << std::endl;
        std::exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        std::cout << "***** Robot created with invalid coordinates (" << r << ","
             << c << ")!" << std::endl;
        std::exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_health = 2;
}
int Robot::row() const
{
    return m_row;   //return row
}
int Robot::col() const
{
    return m_col;   //return col
}
void Robot::move()
{
      // Attempt to move in a random direction; if we can't move, don't move
    switch (std::rand() % 4)
    {
      case UP:
        if(m_row > 1)   //check if UP then go up one row
        {
            m_row -= 1;
        }
        break;
      case DOWN:
        if(m_row < m_arena->rows())  //check if DOWN then go down one row
        {
            m_row += 1;
        }
        break;
      case LEFT:
        if(m_col > 1) //check if LEFT then go down one col
        {
            m_col -= 1;
        }
        break;
      case RIGHT:
        if(m_col < m_arena->cols()) //check if RIGHT then go up one col
        {
            m_col += 1;
        }
        break;
    }
}
bool Robot::takeDamageAndLive()
{
      // If the robot has been hit once before, return false (since a
      // second hit kills a robot).  Otherwise, return true (since the robot
      // survived the damage).
    m_health--;
    if(m_health == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
