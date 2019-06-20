#include<iostream>
#include<cstring>
#include<cctype> 

using namespace std;

char coffee_size();
void display_size(char size);
int flavor();
void display_flavor(int flav);
bool next_customer();
int how_many();
bool prompt();
void compare(char drinks[]);

int main()
{
	
	
while(prompt())
{
	char item[30];
	cout<<"What would you like to find?";
	cin.get(item, 30, '\n');
	cin.ignore(100, '\n');
	compare(item);
	
}

while(next_customer())
{
	int total_coff = how_many();
	int count = 0;
        
	while(count < total_coff)
	{
		char coff_size = coffee_size();
		int flav = flavor();
	

		cout<<"You ordered a ";
		display_size(coff_size);
		cout<<" ";
		display_flavor(flav);
		cout<<endl;
		count += 1;
	}
}       
return 0;
}


//gets size of coffee from customer
char coffee_size()
{
	char coff_size;
	cout<<"What size of coffee would you like?"<<endl;
	cout<<"Please choose the letter that matches the size."<<endl;
	cout<<"Small(s), Medium(m), or Large(l)."<<endl;
	cin>>coff_size;
	cin.ignore(100, '\n');
	return coff_size;
}

//displays the size of the coffee
void display_size(char size)
{

	if(size == 's')
		cout<<"Tall";
	else if(size == 'm')
		cout<<"Grande";
	else if(size == 'l')
		cout<<"Venti";
}

//ask user for coffee flavor
int flavor()
{
	char milk;
	char extra_milk;
	char foam;
	char chocolate;
	cout<<"Would you like to add milk? (y or n)"<<endl;
	cin>>milk;
	cin.ignore(100,'\n');
	cout<<"Would you like to add foam? (y or n)"<<endl;
	cin>>foam;
	cin.ignore(100,'\n');
	cout<<"Would you like to add chocolate syrup? (y or n)"<<endl;
	cin>>chocolate;
	cin.ignore(100, '\n');
	if(milk == 'y')
	{
		cout<<"Do you prefer a small or large amount of milk? (s or l)"<<endl;
		cin>>extra_milk;
		cin.ignore(100, '\n');
	}

	if(milk == 'n' && foam == 'n' && chocolate == 'n')
		return 1;//espresso
	else if(milk == 'n' && foam == 'y' && chocolate == 'n')
		return 2;//macchiato
	else if(milk == 'y' && foam == 'y' && chocolate == 'n' && extra_milk == 's')
		return 3;//cappuccino
	else if(milk == 'y' && extra_milk == 'l')
		return 4;//Latte
	else if(milk == 'n' && foam == 'n' && chocolate == 'y')
		return 5;//expresso mocha
	else if(milk == 'n' && foam == 'y' && chocolate == 'y')
		return 6;//macchiato mocha
	else if(milk == 'y' && foam == 'y' && chocolate == 'y' && extra_milk == 's')
		return 7;//mocho cappuccino
	else if(milk == 'y' && extra_milk == 'l' && chocolate == 'y')
		return 8;//mocha latte
	else
		return 9;
	
}

//displays the flavor
void display_flavor(int flav)
{
	if(flav == 1)
		cout<<"Espresso";
	else if(flav == 2)
		cout<<"Macchiato";
	else if(flav == 3)
		cout<<"Cappuccino";
	else if(flav == 4)
		cout<<"Latte";
	else if(flav == 5)
		cout<<"Mocha Espresso";
	else if(flav == 6)
		cout<<"Mocha Macchiato";
	else if(flav == 7)
		cout<<"Mocha Cappuccino";
	else if(flav == 8)
		cout<<"Mocha Latte";
	else if(flav == 9)
	{
		cout<<"Your choices do not correspond to anything on the menu."<<
		      "Let me ask you again."<<endl;
	}
}

//how many coffees does user want?
int how_many()
{
	int total_orders = 10;
while(!(total_orders > 0 && total_orders <= 5))
{ 
	cout<<"How many coffees would you like to order? (max of 5)";
	cin>>total_orders;
	cin.ignore(100,'\n');
}
	return total_orders;
}
//check to see if there is another customer
bool next_customer()
{
	int new_order = 0;
	cout<<"Please choose."<<endl;
	cout<<"1.Submit new order"<<endl;
	cout<<"2.Exit the menu"<<endl;
	cin>>new_order;
	cin.ignore(100, '\n');
	if(new_order == 1)
		return true;
	else
		return false;
}
//find something in the store
bool prompt()
{
	char find;
	cout<<"Would you like to find something in our store? (y or n)";
	cin>>find;
	cin.ignore(100,'\n');
	cout<<endl;
	if(find == 'y')
		return true;
	else
		return false;
}
//compare items
void compare(char drinks[])
{

	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 't' && drinks[3] == 't' && drinks[4] == 'e')
		cout<<"Yes, you can order a Latte here."<<endl;
} 
