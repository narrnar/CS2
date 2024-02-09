//
//  Arena.cpp
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#include "Arena.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Robot.h"


///////////////////////////////////////////////////////////////////////////
//  Arena implementations
///////////////////////////////////////////////////////////////////////////
Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        std::cout << "***** Arena created with invalid size " << nRows << " by "
             << nCols << "!" << std::endl;
        std::exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nRobots = 0;
}
Arena::~Arena()
{
      //Delete the player and all remaining dynamically allocated robots.
    std::cerr << "Entering Arena destructor" << std::endl;
    delete m_player;
    for (int i = 0; i < m_nRobots; i++)
    {
        delete m_robots[i];
    }
    std::cerr << "Leaving Arena destructor" << std::endl;
}
int Arena::rows() const
{
      //Return the number of rows in the arena.
    return m_rows;
}
int Arena::cols() const
{
      //Return the number of columns in the arena.
    return m_cols;
}
Player* Arena::player() const
{
    return m_player;
}
int Arena::robotCount() const
{
    return m_nRobots;
}
int Arena::nRobotsAt(int r, int c) const
{
    //Return the number of robots at row r, column c.
    int usercount = 0;
    for (int i = 0; i != m_nRobots; i++) //for loop when robots is not 0
    {
        if(m_robots[i]->row() == r && m_robots[i]->col() == c) //increment usercount
        {
            usercount++;
        }
    }
    return usercount;
}
void Arena::display(std::string msg) const
{
      // Position (row,col) in the arena coordinate system is represented in
      // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
        // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';
        // Indicate each robot's position
      // If one robot is at some grid point, set the char to 'R'.
      //  If it's 2 through 8, set it to '2' through '8'.
      //  For 9 or more, set it to '9'.
    for (r = 0; r < rows(); r++)
    {
        for(c=0; c < cols(); c++)
        {
            if(nRobotsAt(r + 1, c + 1) == 1) //if 1 robot
            {
                grid[r][c] = 'R';
            }
            else if(nRobotsAt(r + 1, c + 1) > 1 && nRobotsAt(r + 1, c + 1) < 9) //if 2-8 robots
            {
                grid[r][c] = '0' + nRobotsAt(r + 1, c + 1);
            }
            else if(nRobotsAt(r + 1, c + 1) > 9) //if 9+ robots
            {
                grid[r][c] = '9';
            }
        }
    }
    
        // Indicate player's position
    if (m_player != nullptr)
    {
          // Set the char to '@', unless there's also a robot there,
          // in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }
        // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            std::cout << grid[r][c];
        std::cout << std::endl;
    }
    std::cout << std::endl;
        // Write message, robot, and player info
    std::cout << std::endl;
    if (msg != "")
        std::cout << msg << std::endl;
    std::cout << "There are " << robotCount() << " robots remaining." << std::endl;
    if (m_player == nullptr)
        std::cout << "There is no player." << std::endl;
    else
    {
        if (m_player->age() > 0)
            std::cout << "The player has lasted " << m_player->age() << " steps." <<
std::endl;
        if (m_player->isDead())
            std::cout << "The player is dead." << std::endl;
    }
}
bool Arena::addRobot(int r, int c)
{
      // If MAXROBOTS have already been added, return false.  Otherwise,
      // dynamically allocate a new robot at coordinates (r,c).  Save the
      // pointer to the newly allocated robot and return true.
    if(m_nRobots == MAXROBOTS) //reached max number of robots
    {
        std::cout << "Max robots reached!\n";
        return false;
    }
    else
    {
        m_robots[m_nRobots] = new Robot(this, r, c); //dyn allocate robot class then increment
        m_nRobots++;
        return true;
    }
}
bool Arena::addPlayer(int r, int c)
{
      // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;
      // Dynamically allocate a new Player and add it to the arena
    m_player = new Player(this, r, c);
    return true;
}
void Arena::damageRobotAt(int r, int c)
{
      // Damage one robot at row r, column c if at least one is there.
      // If the robot does not survive the damage, destroy it.
    bool robotStatus = false;
    int i = 0;
    if(nRobotsAt(r, c) == 0)
    {
       return;
    }
    for(int i = 0; i < m_nRobots; i++) //damage robot at r,c if one is present
    {
        if(nRobotsAt(r, c) > 0)
        {
            if(m_robots[i]->row() == r && m_robots[i]->col() == c)
            {
                robotStatus = m_robots[i]->takeDamageAndLive(); //robot survives
                break;
            }
        }
    }
    if(robotStatus == true) //check robot damage status
    {
        m_nRobots -= 1;
        return;
    }
    m_robots[i] = m_robots[--m_nRobots];
    delete m_robots[i]; //robot is destroyed
}
bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
      // Have the k-th robot in the arena make one move.
      // If that move results in that robot being in the same
      // position as the player, the player dies.
        m_robots[k]->move();
        if(m_robots[k]->row() == m_player->row() && m_robots[k]->col() == m_player->col())
        {
            m_player->setDead();
        }
    }
      // return true if the player is still alive, false otherwise
    return ! m_player->isDead();
}

