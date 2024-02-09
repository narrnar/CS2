//Daren Sathasivam
//CSCI-2 0122 Professor Ambrosio
//Organize the cpp file provided under multiple different classes and .h files to create a game. A user can input different keys to either stand, move, or shoot towards a certain direction and the objective is to survive for as many loops or "steps" as possible. A user can also input "q" to quit the game. The player is indicated by an "@" and a robot is indicated by an "R" unless there are multiple, which is then indicated by the number of robots occupying that spot. A player dies if they are in the same position as a "Robot" and is indicated by a *.

#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <set>
#include <cstdlib>
#include <cassert>
#include "Arena.h"
#include "Robot.h"
#include "Player.h"
#include "Game.h"
#include "globals.h"
using namespace std;

/*
class streambuf_switcher
{
public:
streambuf_switcher(ios& dest, ios& src)
: dest_stream(dest), saved_streambuf(dest.rdbuf(src.rdbuf()))
{}
~streambuf_switcher()
{
dest_stream.rdbuf(saved_streambuf);
}
private:
ios & dest_stream;
streambuf* saved_streambuf;
};
set<void*> addrs;
bool recordaddrs = false;
void* operator new(size_t n)
{
void* p = malloc(n);
if (recordaddrs && (n == sizeof(Robot) || n == sizeof(Player)))
{
recordaddrs = false;
addrs.insert(p);
recordaddrs = true;
}
return p;
}
void operator delete(void* p) noexcept
{
if (recordaddrs)
{
recordaddrs = false;
set<void*>::iterator it = addrs.find(p);
if (it != addrs.end())
addrs.erase(it);
recordaddrs = true;
}
free(p);
}
int randReturn = -1;
int TESTrand()
{
return randReturn != -1 ? randReturn : rand();
}
void testone(int n)
{
streambuf_switcher sso(cout, cerr);
switch (n)
{
default: {
cout << "Bad argument" << endl;
} break; case  1: {
Arena a(15, 18);
a.addPlayer(2, 2);
Robot r(&a, 5, 17);
assert(r.row() == 5 && r.col() == 17);
} break; case  2: {
Arena a(20, 40);
a.addPlayer(1, 1);
Robot r(&a, 12, 22);
for (int k = 0; k < 8; k++)
{
int oldr = r.row();
int oldc = r.col();
r.move();
assert((r.row() == oldr && abs(r.col() - oldc) == 1) ||
(r.col() == oldc && abs(r.row() - oldr) == 1));
}
} break; case  3: {
bool moved = false;
for (int k = 0; k < 50; k++)
{
Arena a(1, 40);
a.addPlayer(1, 1);
Robot r(&a, 1, 40);
for (int m = 0; m < 20 && r.col() > 1; m++)
{
int oldc = r.col();
r.move();
assert(r.row() == 1 && r.col() <= 40 &&
abs(r.col() - oldc) <= 1);
if (r.col() != oldc)
moved = true;
}
}
assert(moved);
} break; case  4: {
bool moved = false;
for (int k = 0; k < 50; k++)
{
Arena a(20, 1);
a.addPlayer(1, 1);
Robot r(&a, 20, 1);
for (int m = 0; m < 20 && r.row() > 1; m++)
{
int oldr = r.row();
r.move();
assert(r.col() == 1 && r.row() <= 20 &&
abs(r.row() - oldr) <= 1);
if (r.row() != oldr)
moved = true;
}
}
assert(moved);
} break; case  5: {
bool moved = false;
for (int k = 0; k < 50; k++)
{
Arena a(1, 40);
a.addPlayer(1, 40);
Robot r(&a, 1, 1);
for (int m = 0; m < 20 && r.col() < 40; m++)
{
int oldc = r.col();
r.move();
assert(r.row() == 1 && r.col() >= 1 &&
abs(r.col() - oldc) <= 1);
if (r.col() != oldc)
moved = true;
}
}
assert(moved);
} break; case  6: {
bool moved = false;
for (int k = 0; k < 50; k++)
{
Arena a(20, 1);
a.addPlayer(20, 1);
Robot r(&a, 1, 1);
for (int m = 0; m < 20 && r.row() < 20; m++)
{
int oldr = r.row();
r.move();
assert(r.col() == 1 && r.row() >= 1 &&
abs(r.row() - oldr) <= 1);
if (r.row() != oldr)
moved = true;
}
}
assert(moved);
}break;case  7: {
Arena a(10, 20);
a.addPlayer(1, 1);
Robot r(&a, 5, 7);
assert(r.takeDamageAndLive());
assert(!r.takeDamageAndLive());
}break;case  8: {
Arena a(10, 20);
Player p(&a, 2, 3);
assert(p.row() == 2 && p.col() == 3);
} break; case  9: {
Arena a(10, 20);
Player p(&a, 2, 3);
assert(!p.isDead());
p.setDead();
assert(p.isDead());
} break; case 10: {
Arena a(10, 20);
a.addPlayer(8, 12);
Player* p = a.player();
p->move(UP);
assert(p->row() == 7 && p->col() == 12);
p->move(DOWN);
assert(p->row() == 8 && p->col() == 12);
p->move(LEFT);
assert(p->row() == 8 && p->col() == 11);
p->move(RIGHT);
assert(p->row() == 8 && p->col() == 12);
} break; case 11: {
Arena a(15, 18);
a.addPlayer(1, 1);
Player* p = a.player();
p->move(LEFT);
assert(p->row() == 1 && p->col() == 1 && !p->isDead());
p->move(UP);
assert(p->row() == 1 && p->col() == 1 && !p->isDead());
} break; case 12: {
Arena a(15, 18);
a.addPlayer(15, 18);
Player* p = a.player();
p->move(RIGHT);
assert(p->row() == 15 && p->col() == 18 && !p->isDead());
p->move(DOWN);
assert(p->row() == 15 && p->col() == 18 && !p->isDead());
} break; case 13: {
Arena a(19, 37);
assert(a.rows() == 19 && a.cols() == 37);
} break; case 14: {
Arena a(10, 20);
a.addPlayer(3, 6);
a.addRobot(7, 5);
assert(a.nRobotsAt(7, 5) == 1 && a.nRobotsAt(7, 6) == 0);
} break; case 15: {
Arena a(10, 20);
a.addPlayer(3, 6);
a.addRobot(7, 5);
a.addRobot(4, 7);
a.addRobot(7, 5);
assert(a.nRobotsAt(7, 5) == 2 && a.robotCount() == 3);
} break;
    case 16: {
Arena a(10, 20);
a.addPlayer(3, 6);
a.addRobot(3, 4);
assert(a.nRobotsAt(3, 4) == 1 && a.nRobotsAt(3, 5) == 0);
a.damageRobotAt(3, 5);
a.damageRobotAt(3, 5);
assert(a.nRobotsAt(3, 4) == 1 && a.nRobotsAt(3, 5) == 0);
} break;
    case 17: {
Arena a(10, 20);
a.addPlayer(3, 6);
a.addRobot(3, 4);
a.addRobot(3, 5);
a.addRobot(3, 8);
a.addRobot(3, 5);
int oldCount = a.robotCount();
a.damageRobotAt(3, 8);
assert(a.nRobotsAt(3, 8) == 1 && a.robotCount() == oldCount);
a.damageRobotAt(3, 4);
assert(a.nRobotsAt(3, 8) == 1 && a.robotCount() == oldCount);
assert(a.nRobotsAt(3, 4) == 1);
a.damageRobotAt(3, 8);
assert(a.nRobotsAt(3, 8) == 0 && a.robotCount() == oldCount - 1);
assert(a.nRobotsAt(3, 4) == 1);
} break;
    case 18: {
Arena a(10, 20);
a.addPlayer(3, 6);
a.addRobot(3, 4);
a.addRobot(3, 5);
a.addRobot(3, 8);
a.addRobot(3, 5);
int oldCount = a.robotCount();
a.damageRobotAt(3, 5);
assert(a.nRobotsAt(3, 5) == 2 && a.robotCount() == oldCount);
a.damageRobotAt(3, 5);
assert((a.nRobotsAt(3, 5) == 1 && a.robotCount() == oldCount - 1) ||
(a.nRobotsAt(3, 5) == 2 && a.robotCount() == oldCount));
a.damageRobotAt(3, 5);
assert(a.nRobotsAt(3, 5) == 1 && a.robotCount() == oldCount - 1);
a.damageRobotAt(3, 5);
assert(a.nRobotsAt(3, 5) == 0 && a.robotCount() == oldCount - 2);
} break; case 19: {
Arena a(10, 20);
a.addPlayer(3, 9);
a.addRobot(3, 15);  //  too far
a.addRobot(7, 9);
int oldCount = a.robotCount();
randReturn = 1;  // shooting hits
a.player()->shoot(RIGHT);
a.player()->shoot(RIGHT);
assert(a.nRobotsAt(3, 15) == 1 && a.nRobotsAt(7, 9) == 1 &&
a.robotCount() == oldCount);
a.player()->shoot(DOWN);
a.player()->shoot(DOWN);
assert(a.nRobotsAt(3, 15) == 1 && a.nRobotsAt(7, 9) == 0 &&
a.robotCount() == oldCount - 1);
} break; case 20: {
Arena a(10, 20);
a.addPlayer(3, 9);
a.addRobot(3, 5);
a.addRobot(3, 4);
a.addRobot(3, 7);
a.addRobot(3, 3);
a.addRobot(3, 6);
int oldCount = a.robotCount();
randReturn = 1;  // shooting hits
a.player()->shoot(LEFT);
a.player()->shoot(LEFT);
for (int c = 3; c <= 6; c++)
assert(a.nRobotsAt(3, c) == 1);
assert(a.nRobotsAt(3, 7) == 0 && a.robotCount() == oldCount - 1);
} break; case 21: {
Arena a(10, 20);
a.addPlayer(5, 9);
a.addRobot(3, 9);
a.addRobot(3, 9);
int oldCount = a.robotCount();
randReturn = 1;  // shooting hits
a.player()->shoot(UP);
a.player()->shoot(UP);
a.player()->shoot(UP);
assert(a.nRobotsAt(3, 9) == 1 && a.robotCount() == oldCount - 1);
a.player()->shoot(UP);
assert(a.nRobotsAt(3, 9) == 0 && a.robotCount() == oldCount - 2);
} break; case 22: {
Arena a(10, 20);
a.addPlayer(4, 6);
a.addRobot(3, 3);
a.addRobot(3, 5);
a.addRobot(3, 5);
int oldCount = a.robotCount();
randReturn = 1;  // shooting would hit if there were a robot
a.player()->shoot(LEFT);
assert(a.nRobotsAt(3, 5) == 2 && a.nRobotsAt(3, 3) == 1 &&
a.robotCount() == oldCount);
} break; case 23: {
Arena a(10, 20);
a.addPlayer(6, 15);
for (int r = 1; r <= 10; r++)
for (int c = 1; c <= 13; c++)
assert(a.addRobot(r, c));
assert(!a.addRobot(5, 15));
} break; case 24: {
Arena a(10, 20);
a.addPlayer(6, 6);
a.addRobot(4, 6);
a.addRobot(5, 8);
a.moveRobots();
assert(a.nRobotsAt(4, 6) == 0 &&
(a.nRobotsAt(3, 6) + a.nRobotsAt(5, 6) +
a.nRobotsAt(4, 5) + a.nRobotsAt(4, 7)) == 1);
assert(a.nRobotsAt(5, 8) == 0 &&
(a.nRobotsAt(4, 8) + a.nRobotsAt(6, 8) +
a.nRobotsAt(5, 7) + a.nRobotsAt(5, 9)) == 1);
} break; case 25: {
Arena a(10, 20);
a.addPlayer(7, 7);
for (int k = 0; k < MAXROBOTS / 4; k++)
{
a.addRobot(6, 7);
a.addRobot(8, 7);
a.addRobot(7, 6);
a.addRobot(7, 8);
}
assert(!a.player()->isDead());
a.moveRobots();
assert(a.player()->isDead());
} break; case 26: {
Arena a(1, 3);
a.addPlayer(1, 1);
Player* p = a.player();
for (int j = 0; j < 10; j++)
a.addRobot(1, 3);
assert(!p->isDead());
a.moveRobots();
int k;
for (k = 0; k < 100; k++)
{
assert(!p->isDead());
bool b = a.moveRobots();
if (!b || a.nRobotsAt(1, 1) > 0 || p->isDead())
{
assert(!b && a.nRobotsAt(1, 1) > 0 &&
p->isDead());
break;
}
}
assert(k < 100);
} break; case 27: {
ostringstream oss;
streambuf_switcher sso2(cout, oss);
Arena a(2, 3);
a.addPlayer(1, 2);
a.addRobot(1, 3);
a.addRobot(2, 2);
a.display("");
string s = oss.str();
assert(s.find(".@R") != string::npos);
assert(s.find(".R.") != string::npos);
} break; case 28: {
ostringstream oss;
streambuf_switcher sso2(cout, oss);
Arena a(2, 3);
a.addPlayer(1, 2);
for (int k = 1; k <= 8; k++)
a.addRobot(1, 3);
a.addRobot(2, 2);
a.display("");
string s = oss.str();
assert(s.find(".@8") != string::npos);
} break; case 29: {
ostringstream oss;
streambuf_switcher sbs(cout, oss);
Arena a(2, 3);
a.addPlayer(1, 2);
for (int k = 1; k <= 10; k++)
a.addRobot(1, 3);
a.addRobot(2, 2);
a.display("");
string s = oss.str();
assert(s.find(".@9") != string::npos);
} break; case 30: {
recordaddrs = true;
int oldn = addrs.size();
{
Arena a(10, 20);
int oldn2 = addrs.size();
assert(oldn2 >= oldn);
a.addPlayer(4, 3);
a.addRobot(5, 6);
a.addRobot(5, 7);
a.addRobot(5, 8);
assert(addrs.size() == oldn2 + 4);
}
assert(addrs.size() == oldn);
recordaddrs = false;
} break; case 31: {
Arena a(1, 40);
a.addPlayer(1, 2);
recordaddrs = true;
int oldn = addrs.size();
a.addRobot(1, 5);
assert(addrs.size() == oldn + 1);
a.damageRobotAt(1, 5);
a.damageRobotAt(1, 5);
assert(addrs.size() == oldn);
recordaddrs = false;
} break; case 32: {
Arena a(1, 40);
a.addPlayer(1, 2);
for (int k = 0; k < 25; k++)
{
a.addRobot(1, 1);
a.addRobot(1, 3);
}
a.addRobot(1, 40);
for (int k = 0; k < 25; k++)
{
a.addRobot(1, 1);
a.addRobot(1, 3);
}
assert(a.robotCount() == 101);
for (int k = 0; k < 50; k++)
{
a.damageRobotAt(1, 1);
a.damageRobotAt(1, 1);
a.damageRobotAt(1, 3);
a.damageRobotAt(1, 3);
}
assert(a.robotCount() == 1 && a.nRobotsAt(1, 40) == 1 &&
a.nRobotsAt(1, 1) == 0 && a.nRobotsAt(1, 3) == 0);
Player* p = a.player();
assert(!p->isDead());
for (int k = 0; k < 10; k++)
{
a.moveRobots();
assert(!p->isDead());
for (int c = 1; c <= 4; c++)
{
a.damageRobotAt(1, c);
assert(a.nRobotsAt(1, c) == 0);
}
}
} break; case 33: {
Arena a(10, 2);
a.addPlayer(1, 1);
a.addRobot(10, 2);
for (int k = 0; k < 10000 && !a.player()->isDead() &&
a.robotCount() != 0; k++)
{
a.player()->takeComputerChosenTurn();
a.moveRobots();
}
assert(!a.player()->isDead() && a.robotCount() == 0);
} break; case 34: {
Arena a(10, 10);
a.addPlayer(6, 6);
assert(a.player()->row() == 6 && a.player()->col() == 6);
a.addRobot(5, 6);
a.addRobot(7, 6);
a.addRobot(6, 5);
a.addRobot(6, 7);
a.player()->takeComputerChosenTurn();
assert(!(a.player()->row() == 6 && a.player()->col() == 6));
} break; case 35: {
Arena a(10, 10);
a.addPlayer(6, 6);
a.addRobot(4, 6);
a.addRobot(5, 7);
a.addRobot(6, 8);
a.addRobot(7, 7);
a.addRobot(8, 6);
a.addRobot(7, 5);
a.addRobot(6, 4);
a.addRobot(5, 5);
a.player()->takeComputerChosenTurn();
assert(a.player()->row() == 6 && a.player()->col() == 6);
} break;
}
}
int main()
{
cout << "Enter test number: ";
int n;
cin >> n;
testone(n);
cout << "Passed" << endl;
}   */


int main()
{
      // Initialize the random number generator.  (You don't need to
      // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(15, 18, 80);
      // Play the game
    g.play();
}
