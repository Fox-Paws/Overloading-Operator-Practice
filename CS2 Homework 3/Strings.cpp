#include "Strings.h"
using namespace std;

//Initialize static variables for increment (++ or --)
int Strings::numOfStr = 0;
int Strings::numOfAlive = 0;
int Strings::tempSize = 0;
int Strings::copied = 0;
char *Strings::tempStr = NULL;

void Strings::subError()
{
	cout << "\n\nSubscript out of bounds. Terminating program.\n";
	system("pause");
	exit(EXIT_FAILURE);
}

Strings::Strings()
{ //For creating empty string object, adds to counters
	numOfStr++;
	numOfAlive++;
}

Strings::Strings(char *in)
{ //Create Strings object containing a provided string, eg Strings s = "Text";
	size = strlen(in);
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = in[i];
	}
	str[size] = '\0';
	numOfStr++;
	numOfAlive++;
}

Strings::Strings(int size) //Uses explicit in header to only use if it is matched EXACTLY
{ //Create Strings object of a specific size, eg Strings s(3); creates Strings object of size 3
	this->size = size;
	str = new char[this->size];
	numOfStr++;
	numOfAlive++;
}

Strings::Strings(const Strings &right)
{ //Copy constructor
	size = right.size;
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = right.str[i];
	}
	str[size] = '\0';
	if ((copied % 2) == 0)
	{ //Only increments numOfStr every other time copy constructor is used
		//Because copy constructor is called twice every time it is used
		numOfStr++;
		copied++;
	}
	numOfAlive++;
}

Strings::~Strings()
{ //Destructor deletes array and pointer, decrements alive object count
	delete[] str;
	str = 0;
	numOfAlive--;
}

void Strings::free()
{ //Deletes the static char array, since it is uneccessary to do so when a single object is destroyed
	delete[] tempStr;
	tempStr = 0;
}

int Strings::length() const
{
	return size;
}

int Strings::countT()
{ //Returns number of objects created
	return numOfStr;
}

int Strings::countA()
{ //Returns number of objects still alive
	return numOfAlive;
}

char &Strings::operator[] (const int &sub)
{
	if (sub < 0 || sub >= size)
	{
		subError();
	}
	return str[sub];
}

char *Strings::operator + (const Strings &right)
{ //Adds two Strings objects together: obj1 + obj2 means obj1.str + obj2.str
	delete[] tempStr;
	tempSize = 0;
	tempSize = (size + right.size);
	tempStr = new char[tempSize + 1];
	for (int i = 0; i < tempSize; i++)
	{
		if (i < size)
		{
			tempStr[i] = str[i];
		}
		else
		{
			tempStr[i] = right.str[i - size];
		}
	}
	tempStr[tempSize] = '\0';
	return tempStr;
}

char *Strings::operator + (char *in)
{ //Adds a Strings object with a provided string: obj1 + "Text"
	delete[] tempStr;
	tempSize = 0;
	tempSize = (size + strlen(in));
	tempStr = new char[tempSize + 1];
	for (int i = 0; i < tempSize; i++)
	{
		if (i < size)
		{
			tempStr[i] = str[i];
		}
		else
		{
			tempStr[i] = in[i - size];
		}
	}
	tempStr[tempSize] = '\0';
	return tempStr;
}

Strings &Strings::operator = (const Strings &right)
{ //Assigns right object's values to calling object. obj1 = obj2
	if (this != &right)
	{
		delete[] str;
		this->size = (right.size);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = right.str[i];
		}
		str[size] = '\0';
	}
	return *this;
}

Strings &Strings::operator = (char *in)
{ //Assigns the provided string to the existing object. obj1 = "Text"
	delete[] str;
	size = strlen(in);
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = in[i];
	}
	str[size] = '\0';
	return *this;
}

bool Strings::operator < (const Strings &right)
{ //Compares two Strings objects
	int tempS = right.size;
	if (size < tempS)
	{
		tempS = size;
	}

	for (int i = 0; i < tempS; i++) //Compares number of characters of shortest string
	{								//Avoids subscript errors
		if (str[i] < right.str[i])
		{
			return true;
		}
	}
	
	if (size < right.size) //If only runs if both strings are the same until the comparison stopped
	{ //If that is the case, the shorter string will be "less than" the longer one
		return true;
	}
	else
	{
		return false;
	}
}

bool Strings::operator < (char *in)
{
	int tempS = strlen(in);
	if (size < tempS)
	{
		tempS = size;
	}

	for (int i = 0; i < tempS; i++)
	{
		if (str[i] < in[i])
		{
			return true;
		}
	}
	
	if (size < strlen(in))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Strings::operator > (const Strings &right)
{
	int tempS = right.size;
	if (size < tempS)
	{
		tempS = size;
	}

	for (int i = 0; i < tempS; i++)
	{
		if (str[i] > right.str[i])
		{
			return true;
		}
	}

	if (size > right.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Strings::operator > (char *in)
{
	int tempS = strlen(in);
	if (size < tempS)
	{
		tempS = size;
	}

	for (int i = 0; i < tempS; i++)
	{
		if (str[i] > in[i])
		{
			return true;
		}
	}

	if (size > strlen(in))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Strings::operator == (const Strings &right)
{
	if (size == right.size) //Two strings can't be the same if they aren't the same size
	{
		for (int i = 0; i < size; i++)
		{ //By this point we already know both strings are the same length, no subscript errors possible
			if (str[i] != right.str[i])
			{
				return false; //If a single character is different, this return will end the function
			}
		}
		return true; //If For loop is done, that means both strings are the same
	}				//Because For loop only starts if they are the same length and tests for differences
	else
	{
		return false;
	}
}

bool Strings::operator == (char *in)
{
	if (size == strlen(in))
	{
		for (int i = 0; i < size; i++)
		{
			if (str[i] != in[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

ostream &operator << (ostream &stream, Strings ob)
{
	stream << ob.str;
	return stream;
}

istream &operator >> (istream &stream, Strings &ob)
{ //Uses a little more memory to GET the input, but only ends up using as much as is needed
	delete[] ob.str; //We're putting a new string in here, so out goes the old one
	char temp[1000]; //1000 characters should be enough
	stream.getline(temp, 1000, '\n'); //Set delimiter, just in case
	ob.size = (stream.gcount() - 1); //gcount() gets number of characters input, including the '\n', so -1
	ob.str = new char[ob.size + 1]; //Exact size of the input, needs room for '\0' so + 1
	for (int i = 0; i < ob.size; i++)
	{ //Only want to copy as much as is neccessary, so strcpy would try to copy all 1000 of temp
		ob.str[i] = temp[i];
	}
	ob.str[ob.size] = '\0'; //Slap the null terminator in the last slot
							//Since subscript starts at 0, '\0' goes in at the subscript of ob.size
	return stream;
}