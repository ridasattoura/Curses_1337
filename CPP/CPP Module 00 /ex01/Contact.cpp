/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:34:05 by risattou          #+#    #+#             */
/*   Updated: 2025/10/12 16:00:42 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
Contact Contact::create(std::string a, std::string aa, std::string b,
                     std::string c, std::string d)
{
    Contact new_contact;
    new_contact.first_name = a;
    new_contact.last_name = aa;
    new_contact.nickname = b;
    new_contact.phone_number = c;
    new_contact.darkest_secret = d;
    return new_contact;
}
    


void Contact::viewlist()
{
    std::cout <<"first_name :" <<first_name << std:: endl <<
    "last_name :"<< last_name << std:: endl <<
    "nickname :" << nickname << std::endl <<
    "phone_number :"<< phone_number << std::endl <<
    "darkest_secret :" << darkest_secret  << std:: endl;
}
std::string Contact::getfirst_name()
{
     return first_name;
}
std::string Contact::getlast_name()
{
     return last_name; 
}
std::string Contact::getnickname()
{
     return nickname; 
}