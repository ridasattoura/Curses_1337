#include <iostream>
class PhoneBook{
    
};
class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
}

int main(){
    std::string adam = "";
    while(1)
    {
        std::cin >> adam;
        if(adam == "ADD")
        {

        }
        else if(adam == "SEARCH")
        {
            // call function for search
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