//
//  doctor.cpp
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#include "doctor.h"
//doctor input under base worker for name and salary
doctor::doctor(std::string n, double s) : worker(n, s)
{
}
//doctors make $294,000
double doctor::salaryPerWeek()
{
    return getSalary() / 52.0; //salary / 52 weeks in a year
}
