//
//  Game.h
//  Assignment#2
//
//  Created by Daren Sivam on 3/23/22.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>

class Arena;
class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();
        // Mutators
    void play();
  private:
    Arena* m_arena;
};

#endif /* Game_h */
