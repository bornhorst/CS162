//Ryan Bornhorst
#include "animal.h"
#include "shelter.h"
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

//constructor
//initialize all private variables
Shelter::Shelter()
{
	max_num = 20;//set max_number of entries to 20
	animals = new Animal[max_num];//create an array of class Animal
	animal_num = 0;//initialize animal count to zero
	head = NULL;//ill do that later
}


//destructor
//deallocate memory
Shelter::~Shelter()
{
	delete[] animals;//deallocate memory from animal class array
}



//function that reads in a new arrival to the animal shelter from the user
//increases the size of the array if user inputs more than 5 animals
void Shelter::New_Arrival()
{


	if(animal_num >= max_num)//if maximum entries reached
		Array_size();//increase size of array
	animals[animal_num].Read();//read in animals info
			++animal_num;	
}



//function that allows the breed char array argument to be displayed
//if it is found within the animal shelter.  It will display all animals 
//with matching breeds.
void Shelter::Display_all_breeds(char breed[])
{
	if(animal_num == 0)
	{//no animals have been entered into the shleter
		cout<<"No animals have been entered."<<endl;
		return;
	}
        
	for(int i = 0;i < animal_num;++i)
	{//output the animals infomation if breed matches
		animals[i].Display(breed);//call display(breed)from Animal class
		cout<<endl;
	}
}



//function that displays all animals located within the shelter and
//their information
void Shelter::Display_all()
{

	if(animal_num == 0)
	{//no animals have been entered into the shelter yet
		cout<<"No animals have been entered."<<endl;
		return;//return to menu
	}
	for(int i = 0;i < animal_num;++i)
		animals[i].Display();//display animals info located in Animal class

}



//function that increases the size of the array if the max amount of 
//animals have been entered
void Shelter::Array_size()
{
	max_num = max_num + 10;//increas size of array by 10
	Animal* new_animal = new Animal[max_num];//create new animal class pointer
	
	for(int i = 0;i < animal_num;++i)
		new_animal[i] = animals[i];//switch old array into new array
	delete[] animals;//deallocate memory
	animals = new_animal;	
}
void firstNode(struct node*head)
{
	head->data = animals.Display();
	head->next = NULL;
	
}
void Display_by_name()
{

		
}
		
bool Compare_Name()
{
	
}

