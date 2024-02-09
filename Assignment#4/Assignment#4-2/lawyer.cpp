//
//  lawyer.cpp
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#include "lawyer.h"
//lawyer input under base worker for name and salary
lawyer::lawyer(std::string n, double s) : worker(n, s)
{
}
//lawyers make $144,230
double lawyer::salaryPerWeek()
{
    return getSalary() / 52.0; //salary / 52 weeks in a year
}
