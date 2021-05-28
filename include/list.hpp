#pragma once
#include<iostream>


struct elem
{
	int val;
	elem* first;
	elem* next;
	
	elem(int z = 0,elem* p=nullptr,elem* _p =nullptr)
	{
		val = z;
		first = p;
		next = _p;
	}
	
};


class List
{
private:
	elem* first;

public:
	List(){}

	void add_el(int z = 0,elem* p=nullptr);
	void display();

	//---------------------------------
	void create_cikl();
	void show_cikl();
	
	//------------------------------------
	bool two_p();
	bool two_p1();
	bool nazad_cikl();
};





