//
//  PersonData.h
//  Assignment#4-1
//
//  Created by Daren Sivam on 4/21/22.
//

#ifndef PersonData_h
#define PersonData_h

#include <stdio.h>
#include <string>

class PersonData
{
private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    std::string phone;
public:
    void setLastName(std::string lastName);
    std::string getLastName();

    void setFirstName(std::string firstName);
    std::string getFirstName();

    void setAddress(std::string address);
    std::string getAddress();

    void setCity(std::string city);
    std::string getCity();

    void setState(std::string state);
    std::string getState();

    void setZip(int zip);
    int getZip();

    void setPhone(std::string phone);
    std::string getPhone();
};

#endif /* PersonData_h */
