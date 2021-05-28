#pragma once
#include<string>
#include<vector>

class  Roman_Arabic 
{
protected:
    std::string roman;
    int arabic;
    bool proverka_rom(const std::string&);

public:
    Roman_Arabic();
    Roman_Arabic(int);
    Roman_Arabic(std::string);
    
    void add_arabic(int);
    void add_roman(std::string);

    std::string perevod_arabic_in_roman(const int&); 
    int perevod_roman_in_arabic(const std::string&); 

    void display();
    int ret_arabic();
    std::string ret_roman();



};

