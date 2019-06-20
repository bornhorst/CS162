//Ryan Bornhorst
//cs162 
//Program #5

//This is the main file that calls functions from the shelter and prompts the user
//with a menu for the animal shelter.
#include "animal.h"
#include "shelter.h"
#include <iostream>
using namespace std;


int animal_menu();//prototype for displaying a menu

int main()
{
	Shelter new_shelter;//creat animal shelter object

	int user_input = 0;//initialize user input to 0
	char repeat = 'y';//initialize repeat variably to yes
	while (repeat == 'y' || repeat == 'Y')
	{//continue until user wants to leave the shelter page

			user_input = animal_menu();//set user input to menu choice
			if (user_input == 1)//allow user to enter in a new animal
				new_shelter.New_Arrival();
			else if (user_input == 2)//display all animals in the shelter
				new_shelter.Display_all();
			else if (user_input == 3)//allow user to search the shelter for a specific breed
			{
				char breed[20];//initialize breed to 20 chars
				cout << "Enter the breed you are looking for: ";
				cin.get(breed, 20, '\n');
				cin.ignore(100, '\n');
				new_shelter.Display_all_breeds(breed);//display animal if breed matches
			}
			else if (user_input == 4) //leave the shelter menu
			{
				new_shelter.Display_by_name();
			}
			else if (user_input == 5)//leave the shelter menu
			{
				cout << "Have a nice day!" << endl;
				return 0;//exit
			}
			cout << "Would you like to go back to the shelter menu? (y or n)";
			cin >> repeat;//prompt user to continue browsing the shelter menu
			cin.ignore(100, '\n');
			if (repeat == 'n' || repeat == 'N')
			{
				cout << "Thank you for visiting the shelter!" << endl;
				return 0;//exit the shelter page if user says no
			}		
	}

	return 0;
}
int animal_menu()
{
	int user_input = 0;//initialize user input to zero
	cout<<"\nWelcome to the Animal Shelter page!"<<endl<<endl;
	cout<<"Please choose from the following list."<<endl;
	cout<<"Enter the corresponding number."<<endl;
	cout<<"1. Add a new arrival to the shelter"<<endl;
	cout<<"2. Display all animals in the shelter"<<endl;
	cout<<"3. Find a specific breed of animal"<<endl;
	cout<<"4. Display animals in the shelter alphabetically\n";	
	cout<<"5. Leave the shelter page"<<endl;
	cin>>user_input;
	cin.ignore(100, '\n');
	return user_input;

}

