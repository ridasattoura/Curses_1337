/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:30:53 by risattou          #+#    #+#             */
/*   Updated: 2025/10/12 14:40:21 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact() {}
        Contact(std::string a,std::string aa,std::string b,std::string c,std::string d)
        std::string getfirst_name()
        std::string getlast_name()
        std::string getnickname()
        void viewlist()
};

#endif