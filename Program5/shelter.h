//Ryan Bornhorst
//cs162
//program #5

//This is the header file that contains the Shelter class and node for the LLL
#ifndef SHELTER_H
#define SHELTER_H

#include "animal.h"

class Shelter
{
public:
	Shelter();//constructor
	~Shelter();//destructor
	void New_Arrival();//read in a new animal to the shelter
	void Display_all_breeds(char breed[]);//display if breed searched matches
	void Display_all();//display animals in shelter
	void Display_by_name();//display by name using LLL

private:
	struct node//node for linked list
	{
		node*next;//pointer to next node
		Animal* data;//data stored in the linked list
	};

	int max_num;//maximum entries
	int animal_num;//number of animals
	Animal* animals;//pointer to animal class
	void Array_size();//increase the size of the array if necessary
	void insert(Animal* insert);//insert a new animal into the list

	node* head;	//pointer to head

};


#endif
