#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
    public:
        Contact getcontact(int index);
        void addcontact(Contact s,int &index);
        void print(const std::string& str);
};

#endif