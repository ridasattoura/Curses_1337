/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:34:05 by risattou          #+#    #+#             */
/*   Updated: 2025/10/12 14:39:49 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
Constact::Contact(std::string a,std::string aa,std::string b,std::string c,std::string d)
{
    first_name = a;
    last_name = aa;
    nickname = b;
    phone_number = c;
    darkest_secret = d;
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