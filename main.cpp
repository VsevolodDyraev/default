#include <iostream>
#include "text.h"
#include <cstdlib>  

int main()
{
    Text t1;
    int tmp;
    std::string _val;
    std::string _key;
    
    while(1)
    {
        
        system("clear");
        std::cout<<"0. exit\n";
        std::cout<<"1. go right\n";
        std::cout<<"2. go left\n";
        std::cout<<"3. go up\n";
        std::cout<<"4. add left\n";
        std::cout<<"5. add right\n";
        std::cout<<"6. add left with key\n";
        std::cout<<"7. add right with key\n";
        std::cout<<"8. delete branch\n";
        std::cout<<"9. find to key\n";
        std::cout<<t1<<std::endl;
    
        std::cin>>tmp;

        try
        {
            switch (tmp)
            {
            case 0:
                return 0;
                break;
            case 1:
                t1.right();
                break;
            case 2:
                t1.left();
                break;
            case 3:
                t1.up();
                break;
            case 4:
                std::cin>>_val;
                t1.add_l(_val);
                break;
            case 5:
                std::cin>>_val;
                t1.add_r(_val);
                break;
            case 6:
                std::cin>>_val;
                std::cin>>_key;
                t1.add_l(_val,_key);
                break;
            case 7:
                std::cin>>_val;
                std::cin>>_key;
                t1.add_r(_val,_key);
                break;
            case 8:
                t1.del_branch();
                break;
            
            case 9:
                std::cin>>_key;
                t1.find(_key);
                char c;
                std::cin>>c;
                break;
            

            default:
                break;
            }
        }
        catch(const char* e)
        {
            std::cout << e << "\nContinious? (y/n)\n";
            char c;
            std::cin>>c;
            if(c=='n')return 0;

        }
        

    }

    // system("clear");
    return 0;
}