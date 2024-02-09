//
//  PersonData.cpp
//  Assignment#4-1
//
//  Created by Daren Sivam on 4/21/22.
//

#include "PersonData.h"

//set/mutate variables and get/return variables
void PersonData::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
std::string PersonData::getLastName()
{
    return lastName;
}

void PersonData::setFirstName(std::string firstName)
{
    this->firstName = firstName;

}
std::string PersonData::getFirstName()
{
    return firstName;
}

void PersonData::setAddress(std::string address)
{
    this->address = address;
}
std::string PersonData::getAddress()
{
    return address;
}

void PersonData::setCity(std::string city)
{
    this->city = city;
}
std::string PersonData::getCity()
{
    return city;
}

void PersonData::setState(std::string state)
{
    this->state = state;
}
std::string PersonData::getState()
{
    return state;
}

void PersonData::setZip(int zip)
{
    this->zip = zip;
}
int PersonData::getZip()
{
    return zip;
}

void PersonData::setPhone(std::string phone)
{
    this->phone = phone;
}
std::string PersonData::getPhone()
{
    return phone;
}
