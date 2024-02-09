//Daren Sathasivam
//CSCI-2, 0122,
//Assignment #3
//Utilize LinkedList class and implement several different functions similar to that of the ones taught within the lectures. Solution should output the same as sample given. 

/*
#include <iostream>
#include <string>
 #include <cassert>
#include "LinkedList.h"

using namespace std;

int main()
{
   
    //pass parameter by const reference
    LinkedList ls;
    ls.insertToRear("Carl");
    ls.insertToRear("Hariette");
    ls.insertToRear("Eddie");
    ls.insertToRear("Laura");
    ls.insertToRear("Judy");
    ls.insertToRear("Steve");
     for (int k = 0; k < ls.size(); k++)
    {
       string x;
       ls.get(k, x);
       cout << x << endl;
    }
    
    //print list and reversed list
    LinkedList ls2;
    ls2.insertToRear("Cory");
    ls2.insertToRear("Topanga");
    ls2.insertToRear("Shawn");
    ls2.insertToRear("Eric");
     
    ls2.printList();
    ls2.printReverse();
    
    //append function
    LinkedList e1;
    e1.insertToRear("devoe");
    e1.insertToRear("biv");
    e1.insertToRear("bell");
    LinkedList e2;
    e2.insertToRear("Big Boi");
    e2.insertToRear("Andre");
    e1.append(e2);  // adds contents of e2 to the end of e1
    string s;
    assert(e1.size() == 5  &&  e1.get(3, s)  &&  s == "Big Boi");
    assert(e2.size() == 2  &&  e2.get(1, s)  &&  s == "Andre");
    e1.printList();
    
    
    //reverseList function
    LinkedList e3;
    e3.insertToRear("Norm");
    e3.insertToRear("Cliff");
    e3.insertToRear("Carla");
    e3.insertToRear("Sam");
    e3.reverseList();  // reverses the contents of e3
    string s3;
    assert(e3.size() == 4  &&  e3.get(0, s3)  &&  s3 == "Sam");
    e3.printList();
    
    
    //swap function
    LinkedList e4;
    e4.insertToRear("D");
    e4.insertToRear("C");
    e4.insertToRear("B");
    e4.insertToRear("A");
    LinkedList e5;
    e5.insertToRear("Z");
    e5.insertToRear("Y");
    e5.insertToRear("X");
    e4.swap(e5);  // exchange contents of e4 and e5
    string s5;
    assert(e4.size() == 3  &&  e4.get(0, s5)  &&  s5 == "Z");
    assert(e5.size() == 4  &&  e5.get(2, s5)  &&  s5 == "B");
    e4.printList();
    e5.printList();
    
    
} */


#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <csignal>
#include <regex>
#include <type_traits>
#include <set>
#include <iostream>
#include "LinkedList.h"
using namespace std;
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
if (recordaddrs && n == sizeof(Node))
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
void operator delete(void* p, std::size_t s) noexcept
{
s = addrs.size();   // these two lines do nothing other than
s += s;               // getting rid of unused var warning on g++
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
void testone(int n)
{
LinkedList empty;
LinkedList l1;
l1.insertToRear("7"); l1.insertToRear("8"); l1.insertToRear("9");
LinkedList l2;
l2.insertToRear("3"); l2.insertToRear("4");
ItemType x;
switch (n)
{
default: {
cout << "Bad argument" << endl;
} break; case 1: {
assert(empty.size() == 0);
} break; case 2: {
assert(l1.size() == 3);
} break; case 3: {
assert(!empty.get(0, x));
} break; case 4: {
assert(l1.get(0, x) && x == "7");
} break; case 5: {
assert(l1.get(2, x) && x == "9");
} break; case 6: {
assert(!l1.get(3, x));
} break; case 7: {
LinkedList l3(l1);
assert(l3.size() == 3);
assert(l1.size() == 3);
assert(l1.get(1, x) && x == "8");
} break; case 8: {
LinkedList l3;
l3 = l1;
assert(l3.size() == 3);
assert(l1.size() == 3);
assert(l1.get(1, x) && x == "8");
} break; case 9: {
LinkedList l3(empty);
assert(l3.size() == 0);
} break; case 10: {
l1.reverseList();
assert(l1.get(0, x) && x == "9");
} break; case 11: {
l1.reverseList();
assert(l1.get(2, x) && x == "7");
} break; case 12: {
empty.reverseList();
assert(empty.size() == 0);
} break; case 13: {
ostringstream strCout;
streambuf_switcher sso(cout, strCout);
l1.printList();
string str = strCout.str();
regex e("7.*8.*9"); // 7 followed by 8 followed by 9
assert(regex_search(str, e));
} break; case 14: {
ostringstream strCout;
streambuf_switcher sso(cout, strCout);
l1.printReverse();
string str = strCout.str();
regex e("9.*8.*7"); // 9 followed by 8 followed by 7
assert(regex_search(str, e));
// make sure they didn't take off const after printReverse
assert((is_same<decltype(&LinkedList::printReverse), void
(LinkedList::*)() const>::value));
} break; case 15: {
recordaddrs = true;
{
LinkedList l;
int oldn = addrs.size();
l.insertToRear("1");
l.insertToRear("1");
l.insertToRear("1");
l.insertToRear("1");
assert(addrs.size() == oldn + 4);
}
assert(addrs.size() == 0);
recordaddrs = false;
} break; case 16: {
recordaddrs = true;
int oldn = addrs.size();
l1.append(l2);
assert(addrs.size() == oldn + 2);
assert(l1.size() == 5);
assert(l1.get(0, x) && x == "7");
assert(l1.get(4, x) && x == "4");
recordaddrs = false;
} break; case 17: {
LinkedList l;
recordaddrs = true;
int oldn = addrs.size();
l.append(l2);
assert(l.size() == 2);
assert(l2.size() == 2);
assert(addrs.size() == oldn + 2);
recordaddrs = false;
} break; case 18: {
l1.swap(l2);
assert(l1.size() == 2);
assert(l2.size() == 3);
assert(l1.get(0, x) && x == "3");
assert(l1.get(1, x) && x == "4");
assert(l2.get(0, x) && x == "7");
assert(l2.get(2, x) && x == "9");
} break; case 19: {
LinkedList l;
l1.swap(l);
assert(l.size() == 3);
assert(l.get(0, x) && x == "7");
assert(l1.size() == 0);
assert(!l1.get(0, x));
} break; case 20: {
int oldn = 0;
{
LinkedList l;
recordaddrs = true;
oldn = addrs.size();
l.insertToRear("1");
assert(l.size() == 1);
assert(addrs.size() == oldn + 1);
}
assert(addrs.size() == 0);
recordaddrs = false;
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
}
