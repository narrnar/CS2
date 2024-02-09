//
//  softwareEngineer.h
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef softwareEngineer_h
#define softwareEngineer_h

#include <stdio.h>
#include "worker.h"
#include <string>

class softwareEngineer: public worker
{
public:
    softwareEngineer(std::string n, double s);
    double salaryPerWeek();
};

#endif /* softwareEngineer_h */
