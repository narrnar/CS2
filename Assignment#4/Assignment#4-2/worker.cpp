//
//  worker.cpp
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#include "worker.h"
//constructor
worker::worker(std::string n, double s)
{
    name = n;
    salary = s;
}
//default copy constructor
worker::worker(const worker& w)
{
}
//default destructor
worker::~worker()
{
}
//set/mutate variables and get/return vars
void worker::setName(std::string name)
{
    this->name = name;
}
std::string worker::getName()
{
    return name;
}
void worker::setSalary(double salary)
{
    this->salary = salary;
}
double worker::getSalary()
{
    return salary;
}
