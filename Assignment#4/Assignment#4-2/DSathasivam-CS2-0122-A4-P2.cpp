//Daren Sathasivam
//CSCI-2, 0122
//Assignment#4, Problem #2
//Create a base class for workers then implement four different derived jobs from workers. Then write a function that takes in the base class argument within the main that will output the salaries of the different jobs(printSalary). Check with output of name, salary, and weekly salary.

#include <iostream>
#include <string>
#include <iomanip>
#include "worker.h"
#include "doctor.h"
#include "lawyer.h"
#include "softwareEngineer.h"
#include "salesPerson.h"

using namespace std;

void printSalary(worker &w);

int main()
{
    cout << fixed << showpoint << setprecision(2); //for 2 decimals bc money
    
    // doctors earn $294,000 per year
    doctor d("Bartholemeu", 294000); //take in string name and double salary(for each type)
    cout << d.getName()<< endl;
    printSalary(d);
    cout << d.salaryPerWeek() << "\n \n";
    
    //lawyers earn $144,230 per year,
    lawyer l("Ghazy", 144230);
    cout << l.getName() << endl;
    printSalary(l);
    cout << l.salaryPerWeek() << "\n \n";
    
    // software engineers earn $108,080 per year
    softwareEngineer se("Tutor Tom", 108080);
    cout << se.getName() << endl;
    printSalary(se);
    cout << se.salaryPerWeek() << "\n \n";
    
    // salespeople earn $64,310 per year
    salesPerson sp("Mercedes Man", 64310);
    cout << sp.getName() << endl;
    printSalary(sp);
    cout << sp.salaryPerWeek() << "\n \n";
    
    return 0;
}

void printSalary(worker &w)
{
    cout << w.getSalary() << endl; //print salary from what is accessed by specific worker
}
