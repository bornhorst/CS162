#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void getusersize(char input_size[]);
void getusercoffee( char input_coffee[]);
bool again();


int main()
{
	do
	{
		
		char input_size[5];
        	char input_coffee[10];
		getusersize(input_size);
		getusercoffee(input_coffee);
  
	
		cout << "You have ordered a:" << " " << input_size << " " << input_coffee << endl << endl;

	}
	while(again());
	return 0;
}

void getusersize(char input_size[])
{
	bool variable;
	char tall[] = "TALL";
	char venti[] = "VENTI";
	char g[] = "GRANDE";
	do
	{
		cout << "Enter the size of the coffee. The avaible options are tall, venti, grande. \n";
		cin.width(5);
		cin >> input_size;
		cin.ignore(500, '\n');
       	 	for(int i =0; input_size[i] != '\0'; ++i)
		      input_size[i] = toupper(input_size[i]);
		
		if(input_size[0] == tall[0] && input_size[1] == tall[1] && input_size[2] == tall[2] && input_size[3] == tall[3] || 
	   	   input_size[0] == tall[0] && input_size[1] == tall[1] && input_size[2] == tall[2] 				|| 
		   input_size[0] == tall[0] && input_size[1] == tall[1] && 			       input_size[2] == tall[2] || 
		   input_size[0] == tall[0] 				&& input_size[1] == tall[2] && input_size[2] == tall[3] || 	
		   			       input_size[0] == tall[1] && input_size[1] == tall[2] && input_size[2] == tall[3] ||   
		   input_size[0] == tall[1] && input_size[1] == tall[0] && input_size[2] == tall[2] && input_size[2] == tall[2]	|| 
		   input_size[0] == tall[0] && input_size[1] == tall[2] && input_size[2] == tall[1] && input_size[2] == tall[2] || 		   
		  	 
		    input_size[0] == venti[0] && input_size[1] == venti[1] && input_size[2] == venti[2] && input_size[3] == venti[3] && input_size[4] == venti[4] ||
		    input_size[0] == venti[0] && input_size[1] == venti[1] && input_size[2] == venti[2] && input_size[3] == venti[4]                              ||
		    input_size[0] == venti[0] && input_size[1] == venti[1] && input_size[2] == venti[2]         	             && input_size[3] == venti[4] ||	
		    input_size[0] == venti[0] && input_size[1] == venti[1] &&    			   input_size[2] == venti[3] && input_size[3] == venti[4] || 
		    input_size[0] == venti[0] && 			      input_size[1] == venti[2] && input_size[2] == venti[3] && input_size[3] == venti[4] || 
		    				 input_size[0] == venti[1] && input_size[1] == venti[2] && input_size[2] == venti[3] && input_size[3] == venti[4] ||
		    input_size[0] == venti[1] && input_size[1] == venti[0] && input_size[2] == venti[2] && input_size[3] == venti[3] && input_size[4] == venti[4] ||
                    input_size[0] == venti[0] && input_size[1] == venti[2] && input_size[2] == venti[1] && input_size[3] == venti[3] && input_size[4] == venti[4] ||
                    input_size[0] == venti[0] && input_size[1] == venti[1] && input_size[2] == venti[3] && input_size[3] == venti[2] && input_size[4] == venti[4] ||
                    input_size[0] == venti[0] && input_size[1] == venti[1] && input_size[2] == venti[2] && input_size[3] == venti[4] && input_size[4] == venti[3] ||

		    input_size[0] == g[0] && input_size[1] == g[1] && input_size[2] == g[2] && input_size[3] == g[3] && input_size[4] == g[4] && input_size[5] ==g[5] ||
	 	    input_size[0] == g[0] && input_size[1] == g[1] && input_size[2] == g[2] && input_size[3] == g[3] && input_size[4] == g[4] 			      ||
	            input_size[0] == g[0] && input_size[1] == g[1] && input_size[2] == g[2] && input_size[3] == g[3] && 			 input_size[4] == g[5]||	 
		    input_size[0] == g[0] && input_size[1] == g[1] && input_size[2] == g[2] && 				input_size[3] == g[4] && input_size[4] == g[5]||
		    input_size[0] == g[0] && input_size[1] == g[1] && 			       input_size[2] == g[3] && input_size[3] == g[4] && input_size[4] == g[5]||
		    input_size[0] == g[0] && 			      input_size[1] == g[2] && input_size[2] == g[3] && input_size[3] == g[4] && input_size[4] == g[5]||	
		     			     input_size[0] == g[1] && input_size[1] == g[2] && input_size[2] == g[3] && input_size[3] == g[4] && input_size[4] == g[5] )
               
			variable = true;
                else
                        variable = false;		
}
	
	while(variable != true);
}

void getusercoffee(char input_coffee[])
{


	cout << "What type of coffee would you like? We have Latte, Espresso, Mocha, and Cappuccino. \n";
	cin.width(10);
	cin  >> input_coffee;
	cin.ignore(256,'\n');

	for(int i =0; input_coffee[i] != '\0'; ++i)
	
		input_coffee[i] = toupper(input_coffee[i]);

}


bool again()
{  
	
	char more;
	do
	{
    		cout << "Would you like to order more coffe? Yes= y or No= n \n";
    		cin >> more;
    		cin.ignore(100, '\n');
    		if(more == 'y')
        		return true;
    		else
        		return false;
	}
	while(!( more == 'n' || more == 'y'));

}
