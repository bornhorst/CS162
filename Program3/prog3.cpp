//Ryan Bornhorst
//cs162
//program 3
//5-15-15
/*******************************************************************************************
Algorithm

1. Ask the user which file they would like to open.
2. Check to see if we are in the file that the user chose to open.
3. While we are in the file, ask the user how many courses they would
   like to add to the file.
	3.1 Store the users response as an integer.
4. Prompt the user to input the department of the course.
	4.1 Store the input into the struct school in the element
	    department.
5. Prompt the user to input the course number for the course.
	5.1 Store the input into the struct school in the element
	    course.
6. Prompt the user to input the description of the course.
	6.1 Store the input into the struct school in the element
	    description.
7. Prompt the user to input the term of the course.
	7.1 Store the input into the struct school in the element
	    term.
8. Prompt the user to input the year of the course.
	8.1 Store the input into the struct school in the element
	    year.
9. Display all of the course information that was input from the user
   and stored in the struct.
10.Write all of the course information that was input from the user
   and store it into the file "school.dat".
	10.1 Open the file for appending.
	10.2 Check to see if user is connected to the file.
	10.3 If the user is connected then write the data to the file.
	10.4 Close the file.
11.Read all of the data from the file and count the number of entries.
	11.1 Open the file.
	11.2 Check to see if user is connected to the file.
	11.3 If the user is connected then read the data from the file.
	11.4 Close the file
	11.5 After the contents have been read from the file, count the
	     number of elements stored in the file and the return the 
	     integer value.
	11.6 This value will be used to display the correct amount of
	     data taken from the user and write the correct amount of 
             data to the file "school.dat".
12.Once the amount of courses entered equals the amount of courses the 
   user requested to add to the file, ask the user if they would like
   to add more courses to the file.
	12.1  If the user would like to add more courses to the file
	      then ask them how many courses they would like to add
	      and restart from step #4.
13.The program will continue to add the users data to the file until 
   the user decides that they do not wish to add any more data.
14.Once the program has finished execution the user can then pull up
   a copy of the file "school.dat" and view all of the course information
   that was saved to the file.
	14.1 If the user would like to add more information to the file
	     after viewing then the user can run the program again and 
	     append the existing file.
	14.2 If the user would like to remove the data from the file
	     then they can type rm school.dat in the inux prompt and
	     start the program again from scratch.
*******************************************************************************************/


/*******************************************************************************************
The purpose of this program is to allow a user to input the classes they have left to take
before they graduate.  The user will be prompted for the department, course number, 
course description, the term, and the year that they plan on taking the course.  All of the 
users inputs will be written to and stored in a data file where the user can add to them
later.  This program will also display all of the items on the data file so the  user can 
check to see if they have added all of the classes they need to add.
********************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

//constants (size of arrays)
const int DEPT = 20; //size of department array
const int DESC = 50; //size of course description array
const int TERM = 10; // size of term array

//struct that contains all of the elements necessary to make a data file for school courses
struct school
{
    char department[DEPT];//array that contains the department 
    int course;//int value for the course number
    char description[DESC];//array that contains course description
    char term[TERM];//array that contains a specific term
    int year;//int value that stores the year
};

//function prototypes
void read(school & new_course); //reads data from the user
void display(school & new_course);//displays data read from the user back to them
int load_file(school courses[]);//returns the amount of data stored in the file


//main function that executes the program
int main()
{
     school total_courses[25];  //at most there can be 25 courses
     int num_courses = 0; //initialize courses to 0
     int count = 0;      //counter
     int i = 0;//initialize i to 0
     char repeat = 'Y';//initialize repeat to char Y
     int loop_count = 0;//initialize loop count to 0
     num_courses = load_file(total_courses);//set num_courses equal to the amount of courses in the file

     while(repeat == 'Y')
     {//executes as long as the user has more courses to add to the file
	cout<<"How many courses would you like to add to the file? (integer)";//prompt the user for how many courses they would like to add
	cin >> count;
	cin.ignore(100, '\n');
     
     	int max_number = count + num_courses;//set max_number of courses equal to count plus courses in the file
   
     	for (i = num_courses; i < max_number && i < 25; ++i)
          	read(total_courses[i]);//prompts the user for each course item
	
     	num_courses = i;//now number of courses is set to i
     
     	for (i = loop_count; i < num_courses; ++i)
        	display(total_courses[i]);//displays all of the courses that were written into the file
		cout<<"Would you like to add more courses to the file? (y or n)";
		cin >>repeat;//asks the user if they would like to add more courses
		cin.ignore(100,'\n');
		repeat = toupper(repeat);
		++loop_count;//counts the number of times the loop has ran
     }
return 0;//exit
}



//function that prompts the user for the department, course number, course description
//the term, and the year. Reads the data back into the struct.  It takes the variable
//assigned to the struct as an argument
void read(school & new_course)
{
    cout << "Enter the department of the course: ";
    cin.get(new_course.department, DEPT ,'\n');
    cin.ignore(100,'\n');
    cout << "Enter in the course number: ";
    cin >> new_course.course;
    cin.ignore(100, '\n');
    cout << "Enter in a description of the course:\n";
    cin.get(new_course.description, DESC,'\n');
    cin.ignore(100,'\n');
    cout << "What term do you plan on taking the course? ";
    cin.get(new_course.term,TERM,'\n');
    cin.ignore(100, '\n');
    cout << "What year do you plan on taking the course? ";
    cin >> new_course.year;
    cin.ignore(100, '\n');
    
}


//displays back to the user the information written into the struct.  Also writes data to the file
//"school.dat".  Takes the variable assigned to the struct as an argument.
void display(school & new_course)
{
   //outputs all of the data to the user
   cout << new_course.department <<" "<< new_course.course <<'\n' <<new_course.description<<'\n'
	<< new_course.term<<" "<<new_course.year
        << endl <<endl;
       
   ofstream file_out;//creates an output stream file_out
   file_out.open("school.dat",ios::app);//opens "school.dat"
   if (file_out) //checks to see if we are connected to the file
   {
      file_out << new_course.department<<':'<< new_course.course <<':' <<new_course.description<<':'
               << new_course.term<<':'<<new_course.year//writes the data to the file
	       <<endl;
    file_out.close();//close the file
	}
}



//function that reads in the information about the courses from a file filling up 
//the array of courses passed in as an argument and returning the
//amount of courses that were read in
int load_file(school courses[])
{
    char file_name[30];//create an array called file_name or size 30
    ifstream in_file;//create an input stream variable in_file
    int i = 0;//initialize i to 0
    
    cout << "Please enter the name of the file: (\"school.dat\")";//allow user to input the file they want to work in
    cin.width(30);
    cin >> file_name;
    cin.ignore(100,'\n');
    
    //connect to the file the user requested
    in_file.open(file_name);
    if (in_file) //check to see if we are in the file
    {
        //set up the file for reading
        in_file.get(courses[i].department, DEPT, ':');
        in_file.ignore(100,':');
        while (!in_file.eof() && i < 25)  //able to read the file if this executs
        {      //read in the contents of the file
               in_file>>courses[i].course;
               in_file.ignore(100,':');
               in_file.get(courses[i].description,DESC,':');
               in_file.ignore(100,'\n');
	       in_file.get(courses[i].term,TERM,':');
	       in_file.ignore(100,'\n');
	       in_file>>courses[i].year;
	       in_file.ignore(100,'\n');
               ++i; //move to the next entry of the file
               
               //set up the file for reading again
               in_file.get(courses[i].department,DEPT,':');
               in_file.ignore(100,':');
         }
         in_file.close();//close the file
     }
     return i;//return the amount of courses stored in the file
}
