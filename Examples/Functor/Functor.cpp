#include <string>
#include <iostream>
using namespace std;


struct Greeter
{
	void operator() (const string& name)
	{
		cout << "Hello " << name << endl;
	}
};


class NamedGreeter
{
	string name;

public:

	NamedGreeter(const string& name) : name(name) { }

	void operator() (const string& name)
	{
		cout << "Hello " << name << ", my name is " << this->name << endl;
	}
};


class GrumpyGreeter
{
	int annoyance;

public:
	
	GrumpyGreeter() : annoyance(0) { }

	void operator() (const string& name)
	{
		if (annoyance < 3)
			cout << "Hello " << name << endl;
		else
			cout << "Fuck off " << name << endl;
		++annoyance;
	}

	void haveCoffeeAndSmoke()
	{
		annoyance -= 2;
	}
};


int main()
{
	Greeter greet;
	greet("Joe");
	greet("Sally");
	greet("Bubba");
	greet("Peter");

	cout << endl;

	NamedGreeter ngreet1("Amy"), ngreet2("John");
	ngreet1("Joe");
	ngreet1("Sally");
	ngreet2("Bubba");
	ngreet2("Peter");

	cout << endl;

	GrumpyGreeter ggreet;
	ggreet("Joe");
	ggreet("Sally");
	ggreet("Bubba");
	ggreet("Peter");

	ggreet.haveCoffeeAndSmoke();

	ggreet("Peter");
}
