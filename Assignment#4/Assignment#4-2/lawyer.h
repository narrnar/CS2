//
//  lawyer.h
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef lawyer_h
#define lawyer_h

#include <stdio.h>
#include "worker.h"
#include <string>

class lawyer: public worker
{
public:
    lawyer(std::string n, double s);
    double salaryPerWeek();
};

#endif /* lawyer_h */
