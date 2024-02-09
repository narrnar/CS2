//
//  LinkedList.cpp
//  Assignment#3
//
//  Created by Daren Sivam on 4/5/22.
//

#include "LinkedList.h"

//defualt constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

//copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
    head = nullptr;                 //head is null
    Node *node = rhs.head;          //node point to head of rhs
    while(node != nullptr)          //loop until it reaches nullptr/end of rhs
    {
        insertToRear(node->value);  //insert elements at the rear
        node = node->next;
    }
}
//destructor for linked list
LinkedList::~LinkedList()
{
    Node *node;
    node = head;
    while (node != nullptr)
    {
        Node *n = node->next;
        delete node;
        node = n;                //use a temp val to prevent crashing after deletion
    }
}
//assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(this== &rhs)
        return *this;
    LinkedList copy = LinkedList(rhs);
    this->swap(copy); //swap the heads of the linked lists
    return *this;
}
//insert val at end of list
void LinkedList::insertToRear(const ItemType &val)
{
    Node *node;
    if(head == nullptr)  //add to front if list is empty
    {
        node = new Node;    //link new node to old top node
        node->value = val;
        node->next = head;  //head pointer to new top node
        head = node;
    }
    else
    {
        node = head;                    //add to rear if not empty
        while(node->next != nullptr)
            node = node->next;
            Node *current = new Node;
            current->value = val;
            node->next = current;       //node points at the last node once it hits the line
            current->next = nullptr;    //after the last node stored in the list
    }
}
//prints the LinkedList
void LinkedList::printList() const
{
    Node *node;
    node = head;
    if(head == nullptr) //if list is empty
    {
        std::cout << "Empty list!" << std::endl;
    }
    else                //if list isn't empty, print out values in list
    {
        while(node != nullptr)  //loop until end/nullptr of list
        {
            std::cout << node->value;
            node = node->next;
        }
    }
}
//return bool val if there is an element stored in ith position of linked list
bool LinkedList::get(int i, ItemType& item) const
{
    if(i >= 0 && i < size())    //if i is within the list
    {
        int j = 0;
        Node *current = head;
        while(j < i)        //loop until ith node
        {
            current = current->next;
            j++;
        }
        item = current->value; //item found and set to value
        return true;
    }
    return false;   //no valid value in ith position in the list
}
//reverses the LinkedList
void LinkedList::reverseList()
{
    if(head == nullptr || head->next == nullptr)    //if list empty or only one item
    {
        return;
    }
    LinkedList list;
    Node *ogList = head->next;
    Node *revList = head;
    revList->next = nullptr;
    while(ogList != nullptr)  //loop until end/nullptr of original list
    {
        Node *temp = ogList;        //go down original list
        ogList = ogList->next;
        temp->next = revList;       //set temp as head of the reversed list
        revList = temp;
    }
     head = revList;        //set head to value at revList
}
//prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
    LinkedList revList(*this);
    revList.reverseList();      //reverse list
    revList.printList();        //print list once reversed
}
//append values from "other" onto the end of the list
void LinkedList::append(const LinkedList &other)
{
    Node *node = other.head;        //initialize node to "other"
    while(node != nullptr)          //add new vals onto rear of list if not at end
    {
        insertToRear(node->value);
        node = node->next;
    }
}
//exchange values between the two lists
void LinkedList::swap(LinkedList &other)
{
    /*LinkedList temp(*this); //referneced from lecture notes but not proper
    *this = other;
    other = temp; */
    std::swap(head, other.head); //referenced from tutor, Xizhen Yang
}
//returns the number of items stored within the linked list
int LinkedList::size() const
{
   if(head == nullptr) //if empty return 0
   {
       return 0;
   }
    Node *node = head;
    int count = 0;
    while(node != nullptr)      //loop until end of list
    {
        count++;                //increment count everytime it loops through to keep track
        node = node->next;      //of number of items within the linked list
    }
    return count;           //return number of times it it has looped which is the number of
}                           //values stored within the list

