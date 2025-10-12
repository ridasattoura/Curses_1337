#include "PhoneBook.hpp"

Contact PhoneBook::getcontact(int index)
{
    if (index >= 0 && index < 8)
        return contacts[index];
    return contacts[0];
}

void PhoneBook::addcontact(Contact s,int &index)
{
    if(index >= 8)
        contacts[index%8] = s;
    else
        contacts[index] = s;
    index++;
}

void PhoneBook::print(const std::string& str) 
{
    if (str.length() > 10) {
        std::cout << str.substr(0, 9) << ".";
    } else {
        str.length() < 10 ? std::cout << std::string(10 - str.length(), ' ') << str : std::cout << str;
    }
}