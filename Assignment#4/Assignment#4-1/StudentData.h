//
//  StudentData.h
//  Assignment#4-1
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef StudentData_h
#define StudentData_h

#include <stdio.h>
#include "PersonData.h"

class StudentData:public PersonData
{
private: //not in person data
    int studentID;
    bool incomingFreshman;
public:
    void setStudentID(int id);
    int getStudentID();
    void setIncomingFreshman(bool freshman);
    bool getIncomingFreshman();
};

#endif /* StudentData_h */
