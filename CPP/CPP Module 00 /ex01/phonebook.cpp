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
        {
            first_name = a;
            last_name = aa;
            nickname = b;
            phone_number = c;
            darkest_secret = d;
        }
        std::string getfirst_name() const { return first_name; }
        std::string getlast_name() const { return last_name; }
        std::string getnickname() const { return nickname; }
        void viewlist(){
            std::cout <<"first_name :" <<first_name << std:: endl <<
            "last_name :"<< last_name << std:: endl <<
            "nickname :" << nickname << std::endl <<
            "phone_number :"<< phone_number << std::endl <<
            "darkest_secret :" << darkest_secret  << std:: endl;
        }
};

class PhoneBook{
    private:
        Contact contacts[8];
    public:
        PhoneBook(){};
        Contact getcontact(int index) const { return contacts[index]; }
        void addcantact(Contact s,int &index)
        {
            if(index >= 8)
                contacts[index%8] = s;
            else
                contacts[index] = s;
            index++;
        }
        void print(const std::string& str) 
        {
            if (str.length() > 10) {
                std::cout << str.substr(0, 9) << ".";
            } else {
                str.length() < 10 ? std::cout << std::string(10 - str.length(), ' ') << str : std::cout << str;
            }
        }
};

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
std::string checkdigit(std::string line) {
    while (true) {
        // Check if empty
        if (line.empty()) {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
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
            std::cout << "phone number: ";
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
    Contact new_contact(a,aa,b,c,d);
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
            contact.addcantact(func(),index);
        }
        else if(adam == "SEARCH")
        {
            for(int i = 0; i < index && i < 8; i++)
            {
                std::cout<<  "     Index|First Name| Last Name|  Nickname" << std::endl;
                std::cout << "----------|----------|----------|----------" << std::endl;
                std::cout << "       " <<i  << " | ";
                contact.print(contact.getcontact(i).getfirst_name());
                std::cout << " | ";
                contact.print(contact.getcontact(i).getlast_name());
                std::cout << " | ";
                contact.print(contact.getcontact(i).getnickname());
                std::cout << std::endl;
            }
            std::cout << "Enter a index to view details :" << std::endl;
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