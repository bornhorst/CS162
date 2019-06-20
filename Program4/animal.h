//Ryan Bornhorst
//cs162
//program #4

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
******************************************************************************************************/


#ifndef ANIMAL_H
#define ANIMAL_H
class Animal
{
	public:
		Animal();//constructor
		~Animal();//destructor
		void Read();//read in new animals information from the user
		void Display(char breed[]);//display if breed matches
		void Display();//display all 	
		char* get_name(); //this wil only return a single char

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
