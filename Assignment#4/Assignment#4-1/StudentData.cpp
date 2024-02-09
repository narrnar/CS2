//
//  StudentData.cpp
//  Assignment#4-1
//
//  Created by Daren Sivam on 4/21/22.
//

#include "StudentData.h"

//set studentData variables and return studentData variables
void StudentData::setStudentID(int id)
{
    this->studentID = id;
}
int StudentData::getStudentID()
{
    return studentID;
}
void StudentData::setIncomingFreshman(bool freshman)
{
    this->incomingFreshman = freshman;
}
bool StudentData::getIncomingFreshman()
{
    return incomingFreshman;
}
