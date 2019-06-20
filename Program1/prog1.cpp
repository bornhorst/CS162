//Ryan Bornhorst

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
char variable;
char name();

variable = name();

return 0;

}



//function that allows user to input a variable name
//checks to make sure that the name is within 21 chars
char name()
{
char name[23];
int length;
bool j = false;

while(j == false)
{
	cout <<"\nEnter a variable name: ";
	cin.get(name, 23, '\n');
	cin.ignore(100, '\n');
	cout <<name <<endl <<endl;
	length = strlen(name);
	if(length <= 21)
		j = true;
	else
		cout <<"\nKeep the variable at 21 characters or less.\n\n";
	cout <<endl <<length <<endl;
}
return name;
}

