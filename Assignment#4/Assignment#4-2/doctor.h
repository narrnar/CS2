//
//  doctor.h
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef doctor_h
#define doctor_h

#include <stdio.h>
#include "worker.h"
#include <string>

class doctor: public worker
{
public:
    doctor(std::string n, double s);
    double salaryPerWeek();
};

#endif /* doctor_h */
