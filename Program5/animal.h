//Ryan Bornhorst
//cs162
//Program #5



//Algorithm
/***********************************************************************************************
Program prompts the user with a list of choices.  These choices include adding a new animals 
information into the animal shelter, displaying the information of all the animals contained 
in the animal shelter, searching for a specific animal contained in the animal shelter by typing 
in the breed they are looking for, and a choice to exit the animal shelter menu.

If the user chooses to enter a new animals information into the system.  The user will be prompted 
for the animals name.  Name will be stored in a character array.  The user will be prompted for 
the animals age.  The age will be stored as an integer.  The user will be prompted for the animals
behavior.  The behavior will be stored as an array of characters.  Once the behavior has been put 
into the program the user will be asked if they would like to enter in more animal behavior.  The 
user can type in a new behavior up to a max of ten behaviors.  Next the user will be prompted to 
enter in the breed of the animal.  The user will then be asked if they would like to enter in 
another breed.  The user may enter in up to a max of ten breeds.  After all information has been 
entered by the user the program will then ask the user if they would like to go back to the shelter
menu.  If the user selects yes then they will return to the menu, if no then they will exit the
program.  

If the user chooses to display all of the animals in the program.  After having read in information 
about each animal from the user.  The information is stored in a class called animals and each 
different animals information is stored into an array of classes.  The display function will go 
through each item stored in the array and display it onto the screen so that when the user chooses 
the option to display information, each animals name, age, behaviors, and breeds will be outputted 
onto the screen.  If the user chooses to display information about the animals before any have been
put in then the program will let the user know that no animals exist in the database.  After all 
of the information has been displayed to the user the program will then ask the user if they would 
like to go back to the shelter menu.  If the user selects yes then they will return to the menu, if 
no then they will exit the program.

If the user chooses to search for a specific breed of animal.  After having read in information about
each animal from the user.  The information is stored in a class called animals and each different 
animals information is stored into an array of classes.  The search for a breed function will go 
through each item stored in the array of breeds and compare to the breed that was input by the user.

If the user chooses to display all of the animals in the program in alphabetical order.  After having
read in information about each animal from the user. The animals information will be stored into a 
linear linked list.  Once the first animals information has been entered the list will be created.
Each animal after the first will then be added to the linked list. The order of the list will 
depend on the animals first name.  The list will be sorted by the animals name and each animal that
is added will have its name copared to the other animals in the list to determin where it will be
linked. If there is no information in the list then the program will notify the user that no animals 
are in the shelter.  After all of the information has been displayed to the user the program will
ask the user if they would like to go back to the shelter menu.  If the user selects yes then they will
return to the menu, if no then they will exit the program.

If the program finds a match then it will display all of the information about the animal that 
matched the breed wanted by the user.  After searching through all the arrays of breeds and no match 
is found by the program, the program will then output to the user that no match could be found.  If 
the user decides to search from an animal breed before any animals have been submitted by the user 
then the program will output to the user that no animals exist in the shelter yet.  After all of the 
information has been displayed to the user the program will then ask the user if they would like to 
go back to the shelter menu.  If the user selects yes then they will return to the menu, if no then 
they will exit the program.

If the user selects to exit the shelter menu, then the program will stop running and thank the user 
for visiting the animal shelter.
***************************************************************************************************/

//This is the header file that contains the Animal class
#ifndef ANIMAL_H
#define ANIMAL_H
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal();//constructor
	Animal(const Animal& other);	// copy constructor
	~Animal();//destructor
	void Read();//read in new animals information from the user
	void Display(char breed[]);//display if breed matches
	char Display();//display all 	
	int Compare_Name(char other[]);
	char* getName() { return name; };//function that simply returns an animals name
	int getAge() { return age; };//function that returns animal age
	char* getBreed() {//function that returns an animal breed
		for(int i = 0; i < breed_num;++i)
			return breeds[i]; };
	char* getBehavior() {//function that returns animal behavior
		for(int i = 0;i < behavior_num;++i)
			return behavior[i]; };

private:
	char* name;//pointer to name variable
	int age;//age variable
	int behavior_num;//number of behaviors
	int breed_num;//number of breeds
	char** behavior;//pointer to behavior array
	char** breeds;//pointer to breed array

	bool Breed_compare(char breed[]);//returns true if breed matches
};

#endif
