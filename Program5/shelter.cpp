//Ryan Bornhorst
//cs162
//program #5


#include "shelter.h"
#include "animal.h"
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
	head = NULL; //set head equal to null
}


//destructor
//deallocate memory
Shelter::~Shelter()
{
	delete[] animals;//deallocate memory from animal class array

	while (head != NULL)
	{
		node* temp = head;
		head = head->next;
		delete temp;	//deallocate memory from the linked list
	}
}

//function that reads in a new arrival to the animal shelter from the user
//increases the size of the array if user inputs more than 5 animals
void Shelter::New_Arrival()
{
	if (animal_num >= max_num)//if maximum entries reached
		Array_size();//increase size of array
	animals[animal_num].Read();//read in animals info
	++animal_num;
}



//function that allows the breed char array argument to be displayed
//if it is found within the animal shelter.  It will display all animals 
//with matching breeds.
void Shelter::Display_all_breeds(char breed[])
{
	if (animal_num == 0)
	{//no animals have been entered into the shleter
		cout << "No animals have been entered." << endl;
		return;
	}

	for (int i = 0; i < animal_num; ++i)
	{//output the animals infomation if breed matches
		animals[i].Display(breed);//call display(breed)from Animal class
		cout << endl;
	}
}



//function that displays all animals located within the shelter and
//their information
void Shelter::Display_all()
{

	if (animal_num == 0)
	{//no animals have been entered into the shelter yet
		cout << "No animals have been entered." << endl;
		return;//return to menu
	}
	for (int i = 0; i < animal_num; ++i)
		animals[i].Display();//display animals info located in Animal class

}



//function that increases the size of the array if the max amount of 
//animals have been entered
void Shelter::Array_size()
{
	max_num = max_num + 10;//increase size of array by 10
	Animal* new_animal = new Animal[max_num];//create new animal class pointer

	for (int i = 0; i < animal_num; ++i)
		new_animal[i] = animals[i];//switch old array into new array
	delete[] animals;//deallocate memory
	animals = new_animal;
}



//function that displays the animals connected in a linearly linked list
//animals will be displayed in alphabetical order by their name
void Shelter::Display_by_name()
{
	if(animal_num ==0)
	{//no animals in the shelter
		cout<<"No animals have been entered."<<endl;
		return;
	}
	// create the linked list
	if (head != NULL)
	{
		// delete the old linked list
		while (head != NULL)
		{
			node *temp = head;	// get the current node
			head = head->next;// go to the next node

			delete head;// clear the current node
		}
	}

	for (int i = 0; i < animal_num; i++)
	{
		insert(new Animal(animals[i]));	// create a copy for the linked list
	}

	cout << "\nAlphabetical List of Animals in the Shelter" <<endl;
	node* current = head;
	while (current != NULL)
	{//output all of the animals information to the user in alphabetical order

		cout<<current->data->Display();

		//I left this in here b/c this is how I originally retrieved the data for my LLL
		//It was kind of an exhaustive method that tested each item for the animal
		//Then I realized I could just make the Display() function a char and link it to 
		//the data.  The function above is not a pointer but the ones below are.  I'm not
		//sure which is the more correct way to do this but I assume the above since it works
		//and only uses one line of code.

/*		cout<<"\nANIMAL INFORMATION"<<endl;
		cout <<"Name: ";
		cout << current->data->getName()<< std::endl;
		
		cout<<"Age: ";
		cout<<current->data->getAge()<<endl;
		cout<<"Behavior: ";
		cout<<current->data->getBehavior()<<endl;
		cout<<"Breed: ";
		cout<<current->data->getBreed()<<endl;
*/
		current = current->next;//traverse through the list

	}
}


//function that builds the linked list.  Places the first animal at the head of the list
//then compares each new animal entered into the list to determine which order they
//should be placed into.  Takes a pointer to an animal name as the argument
void Shelter::insert(Animal* insert)
{
	if (head == NULL)
	{
		// insert into the head of the list
		head = new node;
		head->data = insert;
		head->next = NULL;
	}
	else
	{
		node* current = head;	// current pointer
		node* previous = current;// holds the prev node to make the link to the newly inserted node
		// determines the order of the linked list
		while (current != NULL && current->data->Compare_Name(insert->getName()) <= 0)
		{//while current... sort the names of the animals in order
			previous = current;// save prev node
			current = current->next;// iterate through the list
		}

		if (current == NULL)
		{
			// add to end of list
			current = new node;// insert into the list
			current->data = insert;
			current->next = NULL;
			previous->next = current;// link the nodes together
		}
		else if (current == head)
		{
			// add a new head
			head = new node;
			head->data = insert;
			head->next = current;
		}
		else
		{
			// add in front of current
			previous->next = new node;
			previous->next->data = insert;
			previous->next->next = current;
		}
	}
}
