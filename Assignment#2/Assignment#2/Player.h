//
//  Player.h
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <string>

class Arena;  // This is needed to let the compiler know that Arena is a
              // type name, since it's mentioned in the Player declaration.
class Player
{
  public:
        // Constructor
    Player(Arena *ap, int r, int c);
        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
        // Mutators
    std::string takeComputerChosenTurn();
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();
  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

#endif /* Player_h */
