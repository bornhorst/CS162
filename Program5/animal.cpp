//Ryan Bornhorst
//cs162
//program #5


#include "animal.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
//constructor
//initialize all private variables in class Animal
Animal::Animal()
{
	name = NULL;//initialize to NULL
	age = 0;//initialize to zero
	behavior = new char*[10];//create new array of 10 
	breeds = new char*[10];//create new array of 10 
	behavior_num = 0;//initialize to zero
	breed_num = 0;//initialize to zero
}

// copy constructor
Animal::Animal(const Animal& other)
{//copy everything from constructor for animal object
	name = other.name;
	age = other.age;
	behavior = new char*[10];
	breeds = new char*[10];
	behavior_num = other.behavior_num;
	breed_num = other.breed_num;

	// copy the arrays
	for (int i = 0; i < breed_num; i++)
	{
		breeds[i] = new char[strlen(other.breeds[i])];
		strcpy(breeds[i], other.breeds[i]);
	}

	// copy the arrays
	for (int i = 0; i < behavior_num; i++)
	{
		behavior[i] = new char[strlen(other.behavior[i])];
		strcpy(behavior[i], other.behavior[i]);
	}
}

//destructor
//deallocates memory from dynamic arrays
Animal::~Animal()
{
	delete name;//deallocate memory for name
	for (int i = 0; i < breed_num; ++i)
		delete[] breeds[i];
	delete[] breeds;//deallocate memory from breed array

	for (int i = 0; i < behavior_num; ++i)
		delete[] behavior[i];
	delete[] behavior;//deallocate memory from behavior array
}



//function that compares the names of two animals
//returns an integer value
int Animal::Compare_Name(char other[])
{
	return strcmp(name, other);//compare animal name to other
}

//function that reads in information from the user about an animal.Takes no arguments
//and returns nothing but prompts user for all of the animals information
void Animal::Read()
{
	char temp[100];
	name = new char[30];
	cout << "Enter the animals name: ";
	cin>>name;
	cin.ignore(100, '\n');

	cout << "Enter the animals age: ";
	cin >> age;//read in age from user
	cin.ignore(100, '\n');

	char behave = 'y';//initialize behave to yes
	while (behave == 'y' || behave == 'Y')
	{//add behaviors until user is done
		if (behavior_num < 10)
		{//add until max is reached
			cout << "Enter the animals behavior: ";
			cin.get(temp, 100, '\n');
			cin.ignore(100,'\n');
			behavior[behavior_num] = new char[strlen(temp)+1];
			strcpy(behavior[behavior_num],temp);
			++behavior_num;
			cout << "Enter more behaviors? (y or n)";
			cin >> behave;
			cin.ignore(100, '\n');
		}
		else//max has been reached
		{
			cout << "Max behaviors have been entered." << endl;
			behave = 'n';
		}
	}

	char check_breed = 'y';//initialize check breed to yes
	while (check_breed == 'Y' || check_breed == 'y')
	{//keep going until user wants to stop adding breeds
		if (breed_num < 10)
		{//add until max is reached
			cout << "Enter the animals breed: ";
			cin.get(temp, 100, '\n');
			cin.ignore(100, '\n');
			breeds[breed_num] = new char[strlen(temp)+1];
			strcpy(breeds[breed_num],temp);
			++breed_num;//increment counter
			cout << "Enter another breed? (y or n)";
			cin >> check_breed;
			cin.ignore(100, '\n');
		}
		else//max has been reached
		{
			cout << "Max breeds have been entered." << endl;
			check_breed = 'n';
		}
	}
}



//function that displays the information of the animal if the argument matches 
//the breed of the animal.  Takes a char array as an argument for the animals 
//breed
void Animal::Display(char breed[])
{
	if (Breed_compare(breed) == true)
		Display();//display info if breed matches
}



//function that compares the argument char array breed with the breeds that are stored
//returns true if the breeds match else it returns false
bool Animal::Breed_compare(char breed[])
{
	for (int i = 0; i < breed_num; ++i)
	{//compare all of the breeds to the keyword searched for
		if (strcmp(breeds[i], breed) == 0)
			return true;//if match, return true	
	}
	return false;//no match
}



//function that displays all of the animals information. 
char Animal::Display()
{
	cout << "\nANIMAL INFORMATION" << endl;
	cout << "Name:";//display name
	for (int i = 0; name[i] != '\0'; ++i)
		cout << name[i];
	cout << endl;
	cout << "Age: " << age << endl;//display age
	cout << "\nBehavior" << endl;//display behavior
	cout << "----------" << endl;
	for (int i = 0; i < behavior_num; ++i)
	{
		for (int j = 0; j < strlen(behavior[i]); ++j)
			cout << behavior[i][j];
		cout << endl;
	}
	cout << "\nBreed" << endl;//display breed
	cout << "-------" << endl;
	for (int i = 0; i < breed_num; ++i)
	{
		for (int j = 0; j<strlen(breeds[i]); ++j)
			cout << breeds[i][j];
		cout << endl;
	}
}


