#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Functor Print: prints it's argument
class Print
{
public:
	void operator() (int x)
	{
		cout << x << " ";
	}
};


// Functor Square: squares it's argument
class Square
{
public:
	// note: pass by reference
	void operator() (int& x)
	{
		x = x * x;
	}
};


// Functor Accumulate: adds it's argument to a running total
class Accumulate
{
	int sum;

public:
	
	Accumulate() : sum(0) { }

	void operator() (int x)
	{
		sum += x;
	}

	int getSum()
	{
		return sum;
	}

	int reset()
	{
		sum = 0;
	}
};


int main(void)
{
	list<int> lst;
	vector<int> vec;

	for (int i=0; i<10; ++i) {
		lst.push_back(i);
		vec.push_back(i);
	}

	Square sq;

	// square all elements of vec
	for_each(vec.begin(), vec.end(), sq);

	Print p;

	// print vector and list
	for_each(lst.begin(), lst.end(), p);   cout << endl;
	for_each(vec.begin(), vec.end(), p);   cout << endl;

	Accumulate acc1, acc2;

	// compute sums
	acc1 = for_each(lst.begin(), lst.end(), acc1);
	acc2 = for_each(vec.begin(), vec.end(), acc2);

	// print sums
	cout << "List Sum = " << acc1.getSum() << endl;
	cout << "Vector Sum = " << acc2.getSum() << endl;

	// add sum of vector elements to acc1
	acc1 = for_each(vec.begin(), vec.end(), acc1);
	cout << "Total Sum = " << acc1.getSum() << endl;
}
