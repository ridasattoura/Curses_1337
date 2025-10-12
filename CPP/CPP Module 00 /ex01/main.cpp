/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:40:39 by risattou          #+#    #+#             */
/*   Updated: 2025/10/12 16:18:21 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>


std::string get_nonempty_input(std::string value) {
    std::string input;
    while (true) {
        std::cout << value;
        getline(std::cin, input); // Reads the whole line, including spaces
        if (!input.empty()) // Check if input is not empty
            break;
        std::cout << "Input cannot be empty. Please try again." << std::endl;
    }
    return input;
}
std::string checkdigit(std::string prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    
    while (true) {
        // Check if empty
        if (line.empty()) {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
            std::cout << prompt;
            std::getline(std::cin, line);
            continue;
        }
        // Check if all characters are digits
        bool is_digit = true;
        for (size_t i = 0; i < line.length(); i++) {
            if (!std::isdigit(static_cast<unsigned char>(line[i]))) {
                is_digit = false;
                break;
            }
        }
        if (is_digit) {
            // Valid input
            return line;
        } else {
            std::cout << "Invalid input. Please enter digits only." << std::endl;
            std::cout << prompt;
            std::getline(std::cin, line);
        }
    }
}
Contact func(){
    std::string a,aa,b,c,d;
    a = get_nonempty_input("first name: ");
    aa = get_nonempty_input("last name: ");
    b = get_nonempty_input( "nickname: ");
    c = checkdigit("phone number: ");
    d = get_nonempty_input("darkest secret: ");
    Contact new_contact = Contact::create(a, aa, b, c, d);
    return new_contact;
}
int str_to_int(const std::string& str) {
    std::istringstream iss(str);
    int num;
    iss >> num;
    if (!iss.fail() && iss.eof())
        return num;
    return -1;
}
int main(){
    std::string adam = "";
    PhoneBook contact;
    int index = 0;
    while(1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> adam;
        std::cin.ignore();
        if(adam == "ADD")
        {
            contact.addcontact(func(),index);
        }
        else if(adam == "SEARCH")
        {
            std::cout<<  "     Index|First Name| Last Name|  Nickname|" << std::endl;
            std::cout << "----------|----------|----------|----------|" << std::endl;
            for(int i = 0; i < index && i < 8; i++)
            {
                std::cout << "         " <<i  << "|";
                contact.print(contact.getcontact(i).getfirst_name());
                std::cout << "|";
                contact.print(contact.getcontact(i).getlast_name());
                std::cout << "|";
                contact.print(contact.getcontact(i).getnickname());
                std::cout << "|";
                std::cout << std::endl;
            }
            std::cout << "Enter a index (between 0 and 7) to view details :" << std::endl;
            std::cin >> adam;
            std::cin.ignore();
            int num = str_to_int(adam);
            if(num >= 0 && num < index && num < 8)
                contact.getcontact(num).viewlist();
            else
                std::cout << "Invalid index" << std::endl;

        }
        else if(adam == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "try again\n" << std::endl;
        }
    }
}