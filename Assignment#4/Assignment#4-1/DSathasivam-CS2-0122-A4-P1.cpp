//Daren Sathasivam
//CSCI-2, 0122
//Assignment #4, Problem #1
//Create two classes, PersonData and StudentData. StudentData is derived from base PersonData. Main program demonstrates an object of the StudentData class and outputs given information.

#include <iostream>
#include "PersonData.h"
#include "StudentData.h"

using namespace std;

int main()
{
    //create an instance of studentData test
    StudentData test;
    //set its fields inherited from PersonData class using setter/mutate methods
    test.setLastName("Scott");
    test.setFirstName("Travis");
    test.setAddress("12345 Rodeo Drive");
    test.setCity("Beverly Hills");
    test.setState("Californa");
    test.setZip(90210);
    test.setPhone("310-123-4567");
    //set studentID and incomingFreshman using setter/mutate methods
    test.setStudentID(123);
    test.setIncomingFreshman(true);
   
    //output StudentData test
    cout << "Student Information: \n";
    //print studentData using get methods inherited from base PersonData class
    cout << "Student's name: " << test.getFirstName() << " "<< test.getLastName() << endl;
    cout << "Student's address: " << test.getAddress() << endl;
    cout << "Student's city: " << test.getCity() << endl;
    cout << "Student's state: " << test.getState() << endl;
    cout << "Student's phone number: " << test.getPhone() << endl;
    cout << "Student's zip code: " << test.getZip() << endl;
    //print studentID and incomingFreshman using get methods from StudentData class
    cout << "Student's ID: " << test.getStudentID() << endl;
    cout << "Is the student an incoming fresh man?(1 yes,0 No): " << test.getIncomingFreshman() << endl;
     
    return 0;
}
