#include <iostream>
class Contact
{
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
        void viewlist(){
            std::cout << first_name <<
            last_name <<
            nickname <<
            phone_number <<
            darkest_secret  << std:: endl;
        }
};
class PhoneBook{
    private:
        Contact contacts[8];
    public:
        PhoneBook(){};
        void addcantact(Contact s,int &index)
        {
            if(index >= 8)
                contacts[index%8] = s;
            else
                contacts[index] = s;
            index++;
        }
        void cat()
        {
            int i = 0;
            while(i<8)
            {
                std::cout << i << "  ";
                contacts[i++].viewlist();
            }
        }
};

int main()
{
    Contact toto1("1ghg","1ghg","g1hg","1ghg","1ghg");
    Contact toto2("2ghg","2ghg","g2hg","2ghg","2ghg");
    Contact toto3("3ghg","3ghg","g3hg","3ghg","3ghg");
    Contact toto4("4ghg","4ghg","g4hg","4ghg","4ghg");
    Contact toto5("5ghg","5ghg","g5hg","5ghg","5ghg");
    Contact toto6("6ghg","6ghg","g6hg","6ghg","6ghg");
    Contact toto7("7ghg","7ghg","g7hg","7ghg","7ghg");
    Contact toto8("8ghg","8ghg","g8hg","8ghg","8ghg");
    Contact toto9("9ghg","9ghg","g9hg","9ghg","9ghg");
    Contact toto0("0ghg","0ghg","g0hg","0ghg","0ghg");
    Contact totoq("qghg","qghg","gqhg","qghg","qghg");
    Contact totow("wghg","wghg","gwhg","wghg","wghg");
    // toto.viewlist();
    int i =0;
    PhoneBook wa7d;
    wa7d.addcantact(toto1,i);
    wa7d.addcantact(toto2,i);
    wa7d.addcantact(toto3,i);
    wa7d.addcantact(toto4,i);
    wa7d.addcantact(toto5,i);
    wa7d.addcantact(toto6,i);
    wa7d.addcantact(toto7,i);
    wa7d.addcantact(toto8,i);
    wa7d.addcantact(toto9,i);
    wa7d.addcantact(toto0,i);
    wa7d.addcantact(totoq,i);
    wa7d.addcantact(totow,i);
    // wa7d.addcantact(toto,i);
    
        wa7d.cat();
     
    std::cout << i << std::endl;


}
//01234567
//89012345
//67890123