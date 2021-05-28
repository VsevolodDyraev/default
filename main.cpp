#include <iostream>

#include"include/roman.hpp"
using namespace std;

int main()
{
    //std::string s="DCCCXCIX";
    Roman_Arabic r("DCCCXCIX");
    r.display();
    r.add_arabic(338);
    r.display();
    r.add_roman("CCCLXXXVII");
    r.display();

    std::cout<<std::endl;
    return 0;
}