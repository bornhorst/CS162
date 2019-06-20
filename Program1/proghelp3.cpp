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
void drink_size( char sizes[]);
int main()
{
	
	cout<< endl << endl <<"Hello !!!!!!" << endl << endl << " Welcome to our coffee house. We have Mochas, Espresos, Lattes, Cappucinos, and Macchiatos " << endl << endl;

while(prompt())
{
	char sizes[6];
        cout << "What size coffee would you like? : You can choose from Tall, Venti, and Grande" << endl;
        cin.get(sizes, 6, '\n');
        cin.ignore(100, '\n');
	drink_size(sizes);
	
	
	char item[30];
	cout<<"What is the name of the coffee you would like?";
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
	cout<<"1.Order coffe through our menu"<<endl;
	cout<<"2.Exit the program"<<endl;
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
	cout<< endl << endl << "How would you like to order? Would you like to type in what you would like?  Or choose from a menu? " << endl <<
	endl << "T == You want to type in your order" << endl << "M == You want to order through our menu" << endl << "L == If you want to quit  will direct you to do so" << endl;
	cin>>find;
	cin.ignore(100,'\n');
	find = toupper(find);
	cout<<endl;
	if(find == 'T')
		return true;
	else
		return false;
}
//compare items
void compare(char drinks[])
{
		// Latte combos
	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 't' && drinks[3] == 't' && drinks[4] == 'e')
		cout<<endl << endl << "Yes, you can order a Latte here."<<endl;
	if(drinks[0] == 'a' && drinks[1] == 'l' && drinks[2] == 't' && drinks[3] == 't' && drinks[4] == 'e')
		cout <<endl << endl << "Yes, you can order a Latte here." << endl;
	if(drinks[0] == 'l' && drinks[1] == 't' && drinks[2] == 'a' && drinks[3] == 't' && drinks[4] == 'e')
                cout <<endl << endl << "Yes, you can order a latte here." << endl;
	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 'e' && drinks[3] == 't' && drinks[4] == 't')
                cout <<endl << endl << "Yes, you can order a Latte here." << endl;
	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 't' && drinks[3] == 'e' && drinks[4] == 't')
                cout <<endl << endl << "Yes, you can order a Latte here." << endl;
	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 't' && drinks[3] == 't' && drinks[4] != 'e')
                cout <<endl << endl << "Yes, you can order a Latte here." << endl;
	if(drinks[0] == 'l' && drinks[1] == 'a' && drinks[2] == 't' && drinks[3] == 'e')
                cout<<endl << endl <<"Yes, you can order a Latte here."<<endl;
 	if(drinks[0] == 'l' && drinks[1] == 't' && drinks[2] == 't' && drinks[3] == 'e')
                cout<<endl << endl <<"Yes, you can order a Latte here."<<endl;
	if(drinks[0] == 'a' && drinks[1] == 't' && drinks[2] == 't' && drinks[3] == 'e')
                cout<<endl << endl <<"Yes, you can order a Latte here."<<endl;
		// Espresso combos
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] == 'o')
		cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 's' && drinks[1] == 'e' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] == 'o')
		cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 'p' && drinks[2] == 's' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'r' && drinks[3] == 'p' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
 	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'e' && drinks[4] == 'r' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
 	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 's' && drinks[5] == 'e' && drinks[6] == 's' && drinks[7] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
 	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 'o' && drinks[7] == 's')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 's' && drinks[7] != 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 'e' && drinks[5] == 's' && drinks[6] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'r' && drinks[4] == 's' && drinks[5] == 's' && drinks[6] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0] == 'e' && drinks[1] == 's' && drinks[2] == 'p' && drinks[3] == 'e' && drinks[4] == 's' && drinks[5] == 's' && drinks[6] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;
	if(drinks[0]  == 's' && drinks[1] == 'p' && drinks[2] == 'r' && drinks[3] == 'e' && drinks[4] == 's' && drinks[5] == 's' && drinks[6] == 'o')
                cout <<endl << endl << "Yes, you can order a Espresso here." << endl;

		// Macchiato combos
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'i' && drinks[6] == 'a' && drinks[7] == 't'&& drinks[8] =='o')
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'a' && drinks[1] == 'm' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'i' && drinks[6] == 'a' && drinks[7] == 't'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'c' && drinks[2] == 'a' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'i' && drinks[6] == 'a' && drinks[7] == 't'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'h' && drinks[4] == 'c' && drinks[5] == 'i' && drinks[6] == 'a' && drinks[7] == 't'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'i' && drinks[5] == 'h' && drinks[6] == 'a' && drinks[7] == 't'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'a' && drinks[6] == 'i' && drinks[7] == 't'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'i' && drinks[6] == 't' && drinks[7] == 'a'&& drinks[8] =='o' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
	if(drinks[0] == 'm' && drinks[1] == 'a' && drinks[2] == 'c' && drinks[3] == 'c' && drinks[4] == 'h' && drinks[5] == 'i' && drinks[6] == 'a' && drinks[7] == 'o'&& drinks[8] =='t' )
                cout <<endl << endl << "Yes, you can order a Macchiato here." << endl;
		//Cappuccino combos
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'a' && drinks[1] == 'c' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'p' && drinks[2] == 'a' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'u' && drinks[4] == 'p' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'c' && drinks[5] == 'u' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'i' && drinks[7] == 'c'&& drinks[8] =='n' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'n'&& drinks[8] =='i' && drinks[9] == 'o')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
	if(drinks[0] == 'c' && drinks[1] == 'a' && drinks[2] == 'p' && drinks[3] == 'p' && drinks[4] == 'u' && drinks[5] == 'c' && drinks[6] == 'c' && drinks[7] == 'i'&& drinks[8] =='o' && drinks[9] == 'n')
                cout <<endl << endl << "Yes, you can order a Cappuccino here." << endl;
		// Mocha combos
	if(drinks[0] == 'm' && drinks[1] == 'o' && drinks[2] == 'c' && drinks[3] == 'h' && drinks[4] == 'a')
		cout << endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'o' && drinks[1] == 'm' && drinks[2] == 'c' && drinks[3] == 'h' && drinks[4] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
 	if(drinks[0] == 'm' && drinks[1] == 'c' && drinks[2] == 'o' && drinks[3] == 'h' && drinks[4] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'm' && drinks[1] == 'o' && drinks[2] == 'c' && drinks[3] == 'a' && drinks[4] == 'h')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'm' && drinks[1] == 'o' && drinks[2] == 'c' && drinks[3] == 'h' && drinks[4] != 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;	
	if(drinks[0] == 'm' && drinks[1] == 'o' && drinks[2] == 'c' && drinks[3] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'm' && drinks[1] == 'o' && drinks[2] == 'h' && drinks[3] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'm' && drinks[1] == 'c' && drinks[2] == 'h' && drinks[3] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;
	if(drinks[0] == 'o' && drinks[1] == 'c' && drinks[2] == 'h' && drinks[3] == 'a')
                cout <<endl << endl << "Yes, you can order a Mocha here. " << endl;

}
void drink_size( char sizes[])
{
	if(sizes[0] == 't' && sizes[1] == 'a' && sizes[2] == 'l' && sizes[3] == 'l')
		cout << " Our Tall coffee comes in 12 ounces." << endl;
	if(sizes[0] == 'v' && sizes[1] == 'e' && sizes[2] == 'n' && sizes[3] == 't' && sizes[4] == 'i')
		cout << " Our Venti coffee comes in 20 ounces. " << endl;
	if(sizes[0] == 'g' && sizes[1] == 'r' && sizes[2] == 'a' && sizes[3] == 'n' && sizes[4] == 'd' && sizes[5] == 'e')
		cout << " Our Grande coffee comes in 16 ounces. " << endl;
}
