//
//  worker.h
//  Assignment#4
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef worker_h
#define worker_h

#include <stdio.h>
#include <string>

class worker
{
private:
    std::string name;
    double salary;
public:
    //get and set vars
    void setName(std::string name);
    std::string getName();
    void setSalary(double salary);
    double getSalary();
    //pure virtual function for salaryPerWeek
    virtual double salaryPerWeek() = 0;
    
    //constructor, copy constructor, and destructor
    worker(std::string n, double s);
    worker(const worker& w);
    ~worker();
};

#endif /* worker_h */
