#ifndef  STRINGS_H
#define STRINGS_H

#include <iostream>
#include <fstream>
using namespace std;

class Strings
{
private:
	char *str; //Pointer to first character of string
	static char *tempStr; //Used for returning + operator objects
	int size; //Size of String
	static int numOfStr; //Number of objects created
	static int numOfAlive; //Number of created objects still alive
	static int tempSize; //Size of tempStr
	static int copied; //Used to count the number of times copy constructor is used
						//So numOfStr is only incremented every other time the copy-uct is used
	void subError(); //Subscript error if sub < 0 || sub >= size
public:
	Strings();
	Strings(char *);
	explicit Strings(int);
	Strings(const Strings &);
	~Strings();
	void free();
	int length() const;
	int countT();
	int countA();
	char &operator[] (const int &);
	char *operator + (const Strings &right);
	char *operator + (char *);
	Strings &operator = (const Strings &right);
	Strings &operator = (char *);
	bool operator < (const Strings &right);
	bool operator < (char *);
	bool operator > (const Strings &right);
	bool operator > (char *);
	bool operator == (const Strings &right);
	bool operator == (char *);
	friend ostream& operator << (ostream& stream, Strings ob);
	friend istream& operator >> (istream& stream, Strings &ob);
};

#endif // ! STRINGS_H

