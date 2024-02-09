//
//  softwareEngineer.cpp
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#include "softwareEngineer.h"
//soft eng input under base worker for name and salary
softwareEngineer::softwareEngineer(std::string n, double s) : worker(n, s)
{
}
//software engineers make $108,080
double softwareEngineer::salaryPerWeek()
{
    return getSalary() / 52.0; //salary / 52 weeks in a year
}
