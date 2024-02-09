//
//  salesPerson.cpp
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#include "salesPerson.h"
//sales input under base worker for name and salary
salesPerson::salesPerson(std::string n, double s) : worker(n, s)
{
}
//sales people make $64,310
double salesPerson::salaryPerWeek()
{
    return getSalary() / 52.0; //salary / 52 weeks in a year
}
