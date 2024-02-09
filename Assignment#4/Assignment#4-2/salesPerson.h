//
//  salesPerson.h
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef salesPerson_h
#define salesPerson_h

#include <stdio.h>
#include "worker.h"
#include <string>

class salesPerson: public worker
{
public:
    salesPerson(std::string n, double s);
    double salaryPerWeek();
};

#endif /* salesPerson_h */
