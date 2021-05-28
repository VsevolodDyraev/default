#include<iostream>
#include"list.hpp"


int main()
{

	List l1;
	List l2;


	l1.add_el(1);
	l1.add_el(2);
	l1.add_el(3);
	l1.add_el(4);
	
   // bool t;

	l1.display();
    
    std::cout<< "\ncirl est':";
    std::cout<< l1.two_p();
    std::cout<<'-';
    std::cout<< l1.nazad_cikl();
    std::cout<<std::endl;
	// std::cout << "\ncirl est':  "<<t<<std::endl;

	l2.create_cikl();
	l2.show_cikl();
	std::cout<< "\ncirl est':";
    std::cout<< l2.two_p();
    std::cout<<'-';
    std::cout<< l2.nazad_cikl();
    std::cout<<std::endl;

	return 0;
}