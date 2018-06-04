#include "Strings.h"
using namespace std;

void newObj(const Strings &);

int main()
{	//Use all four constructors...
	Strings obj1; //Default
	Strings obj2 = "Test"; //Char * parameter
	Strings obj3(3); //int parameter
	Strings obj4 = obj2; //Copy Constructor

	cout << "Object 2 contains: " << obj2 << endl; //Using stream << operator
	cout << "Object 2 has a length of: " << obj2.length() << endl; //Using length method
	cout << "obj2[1] contains: " << obj2[1] << endl; //Using overloaded [] operator
	cout << "obj2 + obj4 is: " << obj2 + obj4 << endl; //Using overloaded + operator
	cout << "obj2 + wow results: " << (obj2 + "wow") << endl; //Using overloaded + operator
	cout << "Number of objects created: " << obj1.countT() << endl; //Using countT method
	cout << "Number of objects alive: " << obj1.countA() << endl; //Using countA method
	cout << "Calling function to create new object." << endl << endl;

	newObj(obj2);

	cout << "Number of objects created: " << obj1.countT() << endl;
	cout << "Number of objects alive: " << obj1.countA() << endl;
	cout << "Creating new objects to compare..." << endl << endl;

	Strings obj6 = "Test2"; //Char * constructor
	Strings obj7 = "Tes"; //Char * constructor

	if (obj2 < obj6)
	{ //Using overloaded < operator, return type: bool, argument: Strings
		cout << "obj2 is less than obj6." << endl;
	}
	else
	{
		cout << "obj2 is not less than obj6." << endl;
	}

	if (obj2 > obj7)
	{ //Using overloaded > operator, return type: bool, argument: Strings
		cout << "obj2 is greater than obj7." << endl;
	}
	else
	{
		cout << "obj2 is not greater than obj7." << endl;
	}

	if (obj2 == obj4)
	{ //Using overloaded == operator, return type: bool, argument: Strings
		cout << "obj2 is equal to obj4." << endl;
	}
	else
	{
		cout << "obj2 is not equal to obj4" << endl;
	}

	cout << endl << "Enter a string into obj1:" << endl;
	cin >> obj1; //Using overloaded stream >> operator to get string from console line
	cout << "obj1 contains: " << obj1 << endl;

	if (obj2 < "Test2")
	{ //Using overloaded < operator, return type: bool, argument: Char *
		cout << "obj2 is less than " << '"' << "Test2" << '"' << "." << endl;
	}
	else
	{
		cout << "obj2 is not less than " << '"' << "Test2" << '"' << "." << endl;
	}

	if (obj2 > "Tes")
	{ //Using overloaded > operator, return type: bool, argument: Char *
		cout << "obj2 is greater than " << '"' << "Tes" << '"' << "." << endl;
	}
	else
	{
		cout << "obj2 is not greater than " << '"' << "Tes" << '"' << "." << endl;
	}

	if (obj2 == "Test")
	{ //Using overloaded == operator, return type: bool, argument: Char *
		cout << "obj2 is equal to " << '"' << "Test" << '"' << "." << endl;
	}
	else
	{
		cout << "obj2 is not equal to " << '"' << "Test" << '"' << "." << endl;
	}

	Strings obj8; //Default (void) constructors...
	Strings obj9;
	Strings obj10;
	Strings obj11;

	obj11 = "Sample"; //Set using the overloaded = operator with argument Char *

	obj10 = obj9 = obj8 = obj1; //Multiple assignments using the overloaded = operator

	cout << endl << "obj8, 9 and 10 output in order: "
		<< obj8 << obj9 << obj10 << endl 
		<< "obj11: " << obj11 << endl;

	cout << "Number of objects created: " << obj1.countT() << endl;
	cout << "Number of objects still alive: " << obj1.countA() << endl;

	system("pause");
	obj1.free(); //Deletes dynamically allocated tempStr from memory
	return 0;
}

void newObj(const Strings &copy)
{
	Strings obj5("Begin"); //Uses Char * constructor
	cout << "Making obj5 equal obj2 after creating it. (assignment)" << endl;
	obj5 = copy; //This still calls copy constructor, overwriting "Begin" in obj5
	cout << "Now obj5 is: " << obj5 << endl
		<< "Number of objects created: " << obj5.countT() << endl
		<< "Number of objects alive: " << obj5.countA() << endl
		<< "Terminating function to end obj5." << endl << endl;
}