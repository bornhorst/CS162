//Ryan Bornhorst

#ifndef SHELTER_H
#define SHELTER_H

#include "animal.h"


class Shelter
{
	public:
		Shelter();//constructor
		~Shelter();//destructor
		void New_Arrival();//read in a new animal to the shelter
		void Display_all_breeds(char breed[]);
		void Display_all();
		void Display_by_name();
		void Compare_Name();
		void firstNode(struct node*head);
	private:
		struct node
		{
			node* next;
			Animal data;
		};		

			
		int max_num;//maximum entries
		int animal_num;//number of animals
		Animal* animals;//pointer to animal class
		void Array_size();//increase the size of the array if necessary
		
		node* head;
	
};


#endif
