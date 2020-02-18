#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


template <typename T>
void bubble_sort(vector<T>& v)
{
	for (int i=(int)v.size()-1; i>=0; --i)
		for (int j=1; j<=i; ++j)
			if (v[j-1] > v[j]) {
				T tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;
			}
}


template <typename T>
int linear_search(const vector<T>& v, const T& value)
{
	for (size_t i=0; i<v.size(); ++i)
		if (v[i] == value)
			return (int)i;  // found

	return -1;  // not found
}


template <typename T>
int binary_search(const vector<T>& v, const T& value)
{
	int low = 0;
	int high = (int)v.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (v[mid] > value)
			high = mid - 1;
		else if (v[mid] < value)
			low = mid + 1;
		else
			return mid;  // found
	}

	return -1;  // not found
}


template <typename T>
void print(vector<T>& v)
{
	for (size_t i=0; i<v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}


template <typename T>
void shuffle(vector<T>& v)
{
	for (size_t i=0; i<v.size(); ++i) {
		size_t j = rand() % v.size();
		// swap values at i and j
		T tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
}


int main(void)
{
	vector<int> v;
	int n = 10;

	// initialize random number generator
	srand((unsigned)time(0));

	//
	// initialize vector with random values
	//

	/*
	// naive approach: cannot ensure unique values!
	for (int i=0; i<n; ++i)
		v.push_back(rand()%n);
	*/

	// clever approach: populate in order, then shuffle
	for (int i=0; i<n; ++i)
		v.push_back(i);
	shuffle(v);

	//
	// Sorting
	//

	// print unordered
	print(v);
	// sort it
	bubble_sort(v);
	// print ordered
	print(v);

	//
	// Searching
	//

	int target1 = rand() % n;      // random existing target
	int target2 = n + rand() % n;  // random nonexisting target

	//
	// find target1
	//

	// using linear search
	if (linear_search(v, target1) >= 0)
		cout << "Found " << target1 << " using linear search\n";
	else
		cout << "Didn't find " << target1 << " using linear search\n";

	// using binary search
	if (binary_search(v, target1) >= 0)
		cout << "Found " << target1 << " using binary search\n";
	else
		cout << "Didn't find " << target1 << " using binary search\n";

	//
	// find target2
	//

	// using linear search
	if (linear_search(v, target2) >= 0)
		cout << "Found " << target2 << " using linear search\n";
	else
		cout << "Didn't find " << target2 << " using linear search\n";

	// using binary search
	if (binary_search(v, target2) >= 0)
		cout << "Found " << target2 << " using binary search\n";
	else
		cout << "Didn't find " << target2 << " using binary search\n";
}
