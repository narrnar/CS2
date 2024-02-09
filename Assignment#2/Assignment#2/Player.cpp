//
//  Player.cpp
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#include "Player.h"
#include <iostream>
#include "Arena.h"
#include "globals.h"

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////
Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        std::cout << "***** The player must be in some Arena!" << std::endl;
        std::exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        std::cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << std::endl;
        std::exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}
int Player::row() const
{
      //Return what row the player is at.
    return m_row;
}
int Player::col() const
{
      // Return what column the player is at.
    return m_col;
}
int Player::age() const
{
      // Return the player's age.
    return m_age;
}
std::string Player::takeComputerChosenTurn()
{
    // Your replacement implementation should do something intelligent
    // and return a string that describes what happened.  When you've
    // decided what action to take, take it by calling move, shoot, or stand.
    // This function must return one of the following four strings:
    //     "Moved."
    //     "Shot and hit!"
    //     "Shot and missed!"
    //     "Stood."
    // Here's one possible strategy:
    //   If moving in some direction would put me in less immediate danger
    //     than standing, then move in that direction.
    //   else shoot in the direction of the nearest robot I can hit.
    // A more aggressive strategy is possible, where you hunt down robots.
    int dir = rand() % 4;
    int alter;
    if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_arena->nRobotsAt(m_row, m_col + 1) == 0)
    {
        alter = rand() % 10;
        if(alter !=0)
        {
            if(shoot(dir))
            {
                return "Shot and hit!";
            }
            else
            {
                return "Shot and missed!";
            }
        }
        else
        {
            stand();
            return "Stood!";
        }
    }
    else
    {
        move(dir);
        return "Moved!";
    }
}
void Player::stand()
{
    m_age++;
}
void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
      case UP:
        // Move the player up/down one row/col if possible. Increment age if moved.
            if(m_row > 1)
            {
                m_row -= 1;
                m_age ++;
                break;
            }
            stand();
            break;
      case DOWN:
            if(m_row < m_arena->rows())
            {
                m_row += 1;
                m_age++;
                break;
            }
            stand();
            break;
      case LEFT:
            if(m_col > 1)
            {
                m_col -= 1;
                m_age++;
                break;
            }
            stand();
            break;
      case RIGHT:
            if(m_col < m_arena->cols())
            {
                m_col += 1;
                m_age++;
                break;
            }
            stand();
            break;
    }
}
bool Player::shoot(int dir)
{
    m_age++;
    if (std::rand() % 3 == 0)    // miss with 1/3 probability
    {
        return false;
    }
      // Damage the nearest robot in direction dir, returning
      // true if a robot is hit and damaged, false if not hit.
    else if(dir == UP)
    {
        for(int i = 0; i < MAXSHOTLEN; i++)     //cannot exceed the max shot length
        {
            if(m_arena->nRobotsAt(m_row - i, m_col) > 0 && (m_row - i) > 0) //m_row - is UP
            {
                m_arena->damageRobotAt(m_row - i, m_col);
                return true;                //return true if damages robots
            }
        }
    }
    else if(dir == DOWN)
    {
        for(int i = 0; i < MAXSHOTLEN; i++)
        {
            if(m_arena->nRobotsAt(m_row + i, m_col) > 0 && (m_row + i) > 0)
            {
                m_arena->damageRobotAt(m_row + i, m_col);
                return true;
            }
        }
    }
    else if(dir == LEFT)
    {
        for(int i = 0; i < MAXSHOTLEN; i++)
        {
            if(m_arena->nRobotsAt(m_row, m_col - i) > 0 && (m_col - i) > 0)
            {
                m_arena->damageRobotAt(m_row, m_col - i);
                return true;
            }
        }
    }
    else if(dir == RIGHT)
    {
        for(int i = 0; i < MAXSHOTLEN; i++)
        {
            if(m_arena->nRobotsAt(m_row, m_col + i) > 0 && (m_col + i) > 0)
            {
                m_arena->damageRobotAt(m_row, m_col + i);
                return true;
            }
        }
    }
    return false;
}
bool Player::isDead() const
{
      //Return whether the player is dead.
    return m_dead;
}
void Player::setDead()
{
    m_dead = true;
}
