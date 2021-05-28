#include "roman.hpp"
#include <stack>
#include <math.h>
#include <iostream>

int sw_rom(char c);
std::string raspr_rang_arab(int z,int rang);
int raspr_rang_proverka(char c);


Roman_Arabic::Roman_Arabic()
{
    arabic = 0;
    roman = "";
}
//-----------------------------------------------main operations
//---------------------------------------------------------

int Roman_Arabic::perevod_roman_in_arabic(const std::string& s)
{
    std::stack<int> tmp;
    int pred=0;
    bool f = false;

    if(!proverka_rom(s))
        throw(std::logic_error("perevod roman: wrong symb!"));

    for(int i=0;i<s.size();i++)
    {
        tmp.push(sw_rom(s[i]));
    }
    
    pred = tmp.top();
    tmp.pop();
    int res=pred;
    
    while(!tmp.empty())
    {
        if(pred<=tmp.top())
        {
            pred=tmp.top();
            tmp.pop();
            res+=pred;
        }
        else
        {
            pred=tmp.top();
            tmp.pop();
            res-=pred;
        }
    }
    return res;
}

int sw_rom(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
    }
    return 0;
}



//---------------------------------------------------------

std::string Roman_Arabic::perevod_arabic_in_roman(const int& z)
{
    if(z>=4000)
        throw(std::logic_error("perevod arabic in roman:too mach z"));

    int tmp = z;
    int tmpN  = 0;
    std::stack<std::string> ss;
    std::stack<int> tmpS;
    int step =0;
    std::string res="";

    for(int i=1;tmp!=0;i++)
    {
        step = exp(i*log(10));
        tmpS.push(tmp%step);
        tmp-=tmpS.top();
    }


    int i=tmpS.size()-1;
    while(!tmpS.empty())
    {
        int g = tmpS.top()/pow(10,i);
        res+=raspr_rang_arab(g,i);
        //std::cout<<g<<" "<<raspr_rang_arab(g,i)<<std::endl;
        tmpS.pop();
        i--;
    }

    return res;
}

std::string sw_arab(int rang)
{
    switch(rang)
    {
        case 1:
            return "I";
        case 2:
            return "V";
        case 3:
            return "X";
        case 4:
            return "L";
        case 5:
            return "C";
        case 6:
            return "D";
        case 7:
            return "M";
        default:
            break;
    }
    return 0;
}

std::string raspr_rang_arab(int z,int rang)
{
    std::string tmp="";
    int rang2=rang*2;
    //std::cout<<z<<std::endl;
    switch (z)
    {
    case 1:
        tmp = sw_arab(z+rang2);
        break;
    case 2:
        for(int i=0;i<2;i++)
            tmp += sw_arab(1+rang2);
        break;
    case 3:
        for(int i=0;i<3;i++)
            tmp += sw_arab(1+rang2);
        break;
    case 4:
        tmp+=sw_arab(1+rang2);
        tmp+=sw_arab(2+rang2);
        break;
    case 5:
        tmp+=sw_arab(2+rang2);
        break;
    case 6:
        tmp+=sw_arab(2+rang2);
        tmp+=sw_arab(1+rang2);
        break;
    case 7:
        tmp+=sw_arab(2+rang2);
        tmp+=sw_arab(1+rang2);
        tmp+=sw_arab(1+rang2);
        break;
    case 8:

        tmp+=sw_arab(2+rang2);
        tmp+=sw_arab(1+rang2);
        tmp+=sw_arab(1+rang2);
        tmp+=sw_arab(1+rang2);
        break;
    case 9:

        tmp+=sw_arab(1+rang2);
        tmp+=sw_arab(3+rang2);
        break;
    
    default:
        std::cout<<std::endl<<z<<std::endl;
        throw(std::logic_error("respr rang err"));
        break;
    }
    return tmp;
}

//-------------------------------------------------------------------------

bool Roman_Arabic::proverka_rom(const std::string&s)
{
    if(s.size()==1)
        return true;

    std::stack<char> pred;
    int count=0;
    int max;
    int ind_m;
    if(sw_rom(s[0])>sw_rom(s[1]))
    {
        max=sw_rom(s[0]);
        ind_m=0;
    }
    else
    {
        max=sw_rom(s[1]);
        ind_m=1;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='I'||s[i]=='V'||s[i]=='X'||s[i]=='L'||s[i]=='C'||s[i]=='D'||s[i]=='M')
        {
            continue;
        }
        else
        {
            throw(std::logic_error("prov: wrong symb!"));
        }  
    }

    for(int i=0;i<s.size()-1;i++)
    {
        if(sw_rom(s[i+1])>sw_rom(s[i]))
        {
            if(max<=sw_rom(s[i+1])&&(i-ind_m)*(i-ind_m)>1)
                return false;
            //std::cout<<"<"<<max<<">";
            if(count!=0)
                return false;
            if(s[i]=='V'||s[i]=='L'||s[i]=='D')
                return false;
            if(raspr_rang_proverka(s[i+1])-raspr_rang_proverka(s[i])>1)
                return false;
            count=0;
        }
        if(s[i+1]==s[i])
        {
            //std::cout<<'|'<<" ";
            count++;
            if(count>2)
                return false;
        }
        else
            count = 0;

    }




    return true;
}

int raspr_rang_proverka(char c)
{
    switch (c)
    {
    case 'I':
    case 'V':
        return 1;    
    case 'X':
    case 'L':
        return 2;
    case 'C':
    case 'D':
        return 3;
    case 'M':
        return 4;
    default:
        break;
    }
    return 0;
}


//--------------------------------------------DLS

Roman_Arabic::Roman_Arabic(int a)
{   
    if(a>4000)
        throw(std::logic_error("inic: wrong numb arabic! too mach"));
    arabic = a;
    roman = perevod_arabic_in_roman(arabic);
}

Roman_Arabic::Roman_Arabic(std::string s)
{
    if(!proverka_rom(s))
        throw(std::logic_error("inic: wrong rom symb!"));
    roman=s;
    arabic = perevod_roman_in_arabic(roman);
}

void Roman_Arabic::add_arabic(int a)
{
    if(a>4000)
        throw(std::logic_error("add_arabic: wrong numb arabic! too mach"));
    arabic = a;
    roman = perevod_arabic_in_roman(arabic);
}

void Roman_Arabic::add_roman(std::string s)
{
    if(!proverka_rom(s))
        throw(std::logic_error("add_roman: wrong rom symb!"));
    roman=s;
    arabic = perevod_roman_in_arabic(roman);
}

void Roman_Arabic::display()
{
    std::cout<<arabic<<" : "<<roman<<std::endl;
}

int Roman_Arabic::ret_arabic()
{
    return arabic;
}

std::string Roman_Arabic::ret_roman()
{
    return roman;
}







