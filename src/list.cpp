#include"list.hpp"


void List::add_el(int z,elem* p)
{
	elem* tmp = first;	
	tmp = new elem(z,p);
	if (first != nullptr)
		first->next = tmp;
	tmp->first = first;
	tmp->next = nullptr;
	first = tmp;

}

void List::display()
{
	elem* tmp = first;
	while (tmp->first != nullptr)
	{
		std::cout << tmp->val << "  ";
		tmp = tmp->first;
	}
	std::cout << tmp->val << " \n";
	
	while (tmp != nullptr)
	{
		std::cout << tmp->val << "  ";
		tmp = tmp->next;
	}

}

void List::create_cikl()
{
	elem* tmp = nullptr;
	add_el(1);
	add_el(2);
	add_el(3);
	add_el(4);
	add_el(5);
	add_el(6);
	add_el(7);
	tmp = first;
	for (int i = 0; i < 3; i++)
	{
		tmp = tmp->first;
	}
	tmp->first = first;
}

void List::show_cikl()
{
	elem* tmp = first;
	for(int i = 0; i < 15; i++)
	{
		std::cout << tmp->val << "  ";
		tmp = tmp->first;
	}
}


bool List::two_p()
{
	elem* tmp1 = first;
	elem* tmp2 = first;

	// std::cout<<";"<<std::endl;
	
	do
	{
		tmp1 = tmp1->first;
		if(tmp1!=NULL)
			tmp1 = tmp1->first;

		tmp2 = tmp2->first;
		// std::cout<<";"<<std::endl;
	}while (tmp1 != NULL && tmp2 != NULL && tmp1!=tmp2);

	return tmp1 == tmp2;

	// return true;
}

bool List::two_p1()
{
	return false;
}

bool List::nazad_cikl()
{
	elem* tmp1 = first;
	elem* tmp = first;
	elem* tmpp = first;
	

	if(tmp1->next!=nullptr)
		tmp1=tmp1->first;

	do
	{
		tmpp=tmp1;
		tmp=tmp1;
		tmp1=tmp1->first;
		
		tmp->next=tmpp->first;
		tmp->first=tmpp->next;
		

	} while (tmp1!=NULL&&tmp1!=first);
	 
	do
	{
		tmpp=tmp1;
		tmp=tmp1;
		tmp1=tmp1->first;
		
		tmp->next=tmpp->first;
		tmp->first=tmpp->next;
		

	} while (tmp1!=NULL&&tmp1!=first);
	

	if(tmp1!=NULL)
	{
		return true;
	}
	return false; 


}


