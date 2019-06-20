//Ryan Bornhorst
//cs162
//Program 2
//4-30-15

/***********************************************************************************************************
Program that asks a user to enter a phrase.  The program will then take the phrase and turn it into a 
variable name.  It will remove whitespace and place underscores between words.  Capitalize the first
word in the phrase.  Remove vowels from the words as well as small insignificant words such as "the", "at",
"is", "to", and "of". The variable name cannot be longer than 21 characters.  The user can then decide up
to a max of 5 times if they are satisfied with the word produced by the program.




Algorithm

1. Ask the user to enter in a phrase as an array they would like to use to generate a variable name.
	1.1 If the first character of the phrase is not a letter or if the phrase starts with 
	    a single vowel the user will be asked to re-enter the phrase.
	1.2 Else the phrase is accepted and the program moves on to the next step.
2. Capitalize the first word of the phrase.
	2.1 If the first character of the array is a letter then it will be capitalized.
3. While there are spaces contained within the name, either remove the spaces or turn them into 
   underscores.
	3.1 If the space exists between words containing letters then an underscore will be placed
	    where the space existed.
	3.2 If the space exists between a word and a non-word or two non-words then the space will 
	    be removed.
4. While there are vowels contained within the name.
	4.1 If the vowel is lowercase, remove it from the array.
		4.11 All characters at locations greater than the vowel characters location are 
		     shifted one array location towards the location of the vowel that was removed.
	4.2 If the vowel is uppercase, remove it from the array.
		4.21 All characters at locations greater than the vowel characters location are
		     shifted one array location towards the location of the vowel that was removed.
5. Remove certain words from the phrase.
	5.1 If the array contains the word "the" with whitespace on both sides of the word, then it
	    is removed from the array.
	    5.11 All characters at locations greater than the elements containing the word "the" will
	         be shifted three array locations towards the location of the "t" in the word "the".
	5.2 If the array contains the word "at" with whitespace on both sides of the word, then it
	    is removed from the array.
	    5.21 All characters at locations greater than the elements containing the word "at" will
		 be shifted two array locations towards the location of the "a" in the word "at".
	5.3 If the array contains the word "is" with whitespace on both sides of the word, then it 
	    is removed from the array.
	    5.31 All characters at locations greater than the elements containing the word "is" will
		 be shifted two array locations towards the location of the "i" in the word "is".
	5.4 If the array contains the word "to" with whitespace on both sides of the word, then it
	    is removed from the array.
	    5.41 All characters at locations greater than the elements containing the word "to" will
		 be shifted two array locations towards the location of the "t" in the word "to".
	5.5 If the array contains the word "of" with whitespace on both sides of the word, then it
	    is removed from the array.
	    5.51 All characters at locations greater than the elements containing the word "of" will
		 be shifted two array locations towards the location of the "o" in the word "of".
6. Display the created variable name to the user.
	6.1 If the variable name is longer than twenty-one characters then ask the user to enter in 
	    a new name and start over.
7. Ask the user if they would like to change the created variable name.
	7.1 If they select "yes" then repeat steps one through six.
		7.11 The user has five chances to change the created variable name.
		7.12 Display the amount of attempts the user has already forgone.
	7.2 If the user selects "no". 
		7.22 Display the chosen variable name to the user.
	7.3 If the user uses all five chances to change the variable name.
		7.31 On the fourth chance, warn the user that this is their last chance to change
		     the name.
		7.32 On the last chance tell them that they ran out of chances and now they are stuck
		     with a variable name.  Display the variable name.
***********************************************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void phrase(char name[]);//function prototype for getting a phrase
void uppercase(char name[]);//function prototype for capitalizing first word
void spaces(char name[]);//function prototype for removing spaces and adding underscores
void novowels(char name[]);//function prototype for removing vowels
void skip_words(char name[]);//function prototype for skipping certain words
int word_size(char name[]);//function prototype for checking appropriate variable name size
int again(char name[],int count);//function prototype for asking user if they would like to make a change

const int SIZE = 40;//constant integer used to generate a constant array size of 40



int main()//main function
{
	char name[SIZE];//initialize array name of SIZE
	int count = 0;//initialize integer count to zero
	int go_again1 = 0;//initialize go_again1 to zero
	int go_again2 = 0;//initialize go_again2 to zero
do
{//loop executes as long as go_again2 is returning a 1
	go_again1 = 0;//reinitialize within the loop
	go_again2 = 0;//reinitialize within the loop
	
	do
	{//loop executs as long as go_again1 is returning a 1
		phrase(name);//calling the name function
		skip_words(name);//calling the word skipping function
		uppercase(name);//calling the function that capitalizes first word
		spaces(name);//calling function that removes whitespace and places underscores between words
		novowels(name);//calling function that removes vowels
		go_again1 = word_size(name);//setting go_again1 to integer value of word_size function
	}while(go_again1 == 1);
	
	count += 1;//places a counter within the loop to count iterations
	go_again2 = again(name,count);//set to integer value of again function return
}while(go_again2 == 1 && count < 5);


return 0;
}



//function that asks user for a phrase, will only accept if the first character
//is a letter, and the first word cannot be a single vowel
//a single vowel will make the first character a space or underscore
//Accepts the name array as an argument
void phrase(char name[])
{
	bool phrase = false;//initialize bool variable to false
do
{//executes until an appropriate input is entered
	cout <<"\nEnter in a phrase to generate a variable name:   ";//ask user for a phrase
	cin.get(name, SIZE, '\n');//store as array name
	cin.ignore(100, '\n');
	cout << endl;
	if(!((name[1] >= 'A' && name[1] <= 'Z') || (name[1] >= 'a' && name[1] <= 'z')))
	{//warning message if first character is not a letter
		cout <<"\nThe first character must be a letter and the"
	             <<" first word \ncannot be a single vowel.\n";
		phrase = true;//phrase is true
	}
	else
		phrase = false;//phrase is false
}while(phrase == true);//while phrase is true or while first character is not a letter
}



//function that adds uppercase letter to first word
//Accepts the name array as an argument
void uppercase(char name[])
{
	int length = 0;//initialize length to zero
	length = SIZE;//length equals const int size
	for(int i = 0;i < length;++i)//go through each character in name
	{
		if(name[i] >= 'A' && name[i] <= 'z')
		{//if first character is a letter then it will be capitalized
		name[i] = toupper(name[i]);
		break;//stop after the first letter
		}
	}
}



//function that removes whitespace from between non-words  
//and puts underscores between words
//Accepts the name array as an argument
void spaces(char name[])
{
	int length = 0;
	length = SIZE;
	for(int i = 0;i < length;++i)
	{//go through each character of name array
		do
		{//executes while there is whitespace in the array
			if(name[i] == ' ')
			{//if there is a space between 2 words then an underscore will be written over it
				if((name[i-1] >= 'A' && name[i-1] <= 'z')&&(name[i+1] >= 'A' && name[i+1] <= 'z'))
					name[i] = '_';	//places underscores between words
				else//else remove whitespace if there is a space between non-words
					strcpy(name + i, name + (i + 1));//removes extra whitespace by shifting array to name[i] position
			}
		}while(name[i] == ' ');
	
	}
	
}



//function that removes vowels from the character array
//Accepts the name array as an argument
void novowels(char name[])
{

	int length = 0;
	length = SIZE;

	for(int i = 0;i < length;++i)
	{
		do
		{//executes until all vowels are removed
			if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
				strcpy(name + i, name + (i + 1));//if lowercase vowel is found, then array is shifted to overwrite that element

			else if(name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U')
				strcpy(name + i, name + (i + 1));//if uppercase vowel is found, then array is shifted to overwrite that element

		}while(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'
	       	       || name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U');
	}
}



//function that skips words like "the","at","is","to","of"
//Accepts the name array as an argument
void skip_words(char name[])
{
	int length = 0;
	length = SIZE;
	
	for(int i = 0;i < length;++i)
	{//this will shift  the array enough characters over to remove each word
		if(name[i-1] == ' ' && name[i] == 't' && name[i+1] == 'h' && name[i+2] == 'e' && name[i+4] == ' ')
			strcpy(name + i, name + (i + 3));//"the" has 3 letters so it gets shifted 3 spots
		else if(name[i-1] == ' ' && name[i] == 'a' && name[i+1] == 't' && name[i+2] == ' ')
			strcpy(name + i, name + (i + 2));//"at" has 2 letters so it gets shifted 2 spots
		else if(name[i-1] == ' ' && name[i] == 'i' && name[i+1] == 's' && name[i+2] == ' ')
			strcpy(name + i, name + (i + 2));//"is" has 2 letters so it gets shifted 2 spots
		else if(name[i-1] == ' ' && name[i] == 't' && name[i+1] == 'o' && name[i+2] == ' ')
			strcpy(name + i, name + (i + 2));//"to" has 2 letters so it gets shifted 2 spots
		else if(name[i-1] == ' ' && name[i] == 'o' && name[i+1] == 'f' && name[i+2] == ' ')
			strcpy(name + i, name + (i + 2));//"of" has 2 letters so it gets shifted 2 spots
	}
}



//function that makes sure the variable word is 21 characters or less
//Accepts the name array as an argument
//Returns either integer 1 or 0
int word_size(char name[])
{
	int length = 0;
	length = 22;//set array length to 22 characters to include null character
	if(strlen(name) >= length)
	{//determines if variable name is within range
		cout <<"\nThe variable name created exceeds 21 characters! You will need to start over.\n\n";
		return 1;//if greater than 21 chars, display error message and return 1 so loop restarts
	}
	else
		return 0;//exit loop by returning 0
}



//function that allows user to change name 5 times maximum
//Accepts the name array and integer that counts loop iterations as an argument
//Returns either integer 1 or 0
int again(char name[],int count)
{

	char change = 'a';//initialize change variable to random character value

while(!(change == 'Y' || change == 'N'))
{//loop that executes if user types something different than expected
	if(count < 5)
	{//executes up to five times
		cout << "The variable name created is:  "<< name<<endl<<endl;//shows variable name and asks user if they want to change it
		cout << "Would you like to change it? (y or n)";
		cin >>change;
		cin.ignore(100, '\n');
		cout<<endl;
	}
	change = toupper(change);//capitalize change variable
	if(count == 5)//if variable has been changed 5 times
	{//display message informing user they ran out of trys and display variable name
		cout<<"Sorry, you ran out of opportunities to change your name. You're stuck with:  "<<name<<endl<<endl;
		return 0;//exit the loop by returning 0
	}
	if(count < 5)//if variable has been changed less than 5 times
	{
		if(change == 'Y')
		{//if user selects to change name, display how many times they changed it and show them max opportunities to change
			cout<< "You have changed the name "<<count<<" times.\n"
	    	            <<"You only have 5 opportunities to change it!\n";
			if(count == 4)//if name has been changed 4 times, show user they have one more chance
			cout<<"\nThis is your last chance!! You have no more opportunites!!\n\n";
			return 1;//return 1 to stay in the loop and make changes
		}
	}
	if(change == 'N')
        {//if user is satisfied with the name, display the name to them and end the program
		cout<<"\nThe variable name you chose is:  "<<name<<"\nHope you like it!\n"<<endl;
		return 0;

	}
}

}
