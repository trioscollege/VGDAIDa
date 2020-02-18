#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

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
int linear_search_unordered(const vector<T>& v, const T& value)
{
	for (size_t i=0; i<v.size(); ++i)
		if (v[i] == value)
			return (int)i;  // found

	return -1;  // not found
}


template <typename T>
int linear_search_ordered(const vector<T>& v, const T& value)
{
	for (size_t i=0; i<v.size(); ++i)
		if (v[i] == value)
			return (int)i;  // found
		else if (v[i] > value)
			return -1;  // not found

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
	int n = 100000;  // number of items
	int m = 100000;  // number of searches


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

	cout << "initializing..." << endl;

	// clever approach: populate in order, then shuffle
	for (int i=0; i<n; ++i)
		v.push_back(i);
	shuffle(v);

	//
	// Sorting
	//

	clock_t t0, t1;

	cout << "sorting " << n << " values using bubble sort... ";
	cout.flush();
	t0 = clock();
	bubble_sort(v);
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";

	cout << "sorting " << n << " values using std::sort... ";
	cout.flush();
	t0 = clock();
	std::sort(v.begin(), v.end());
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";


	//
	// Searching
	//

	cout << "looking up " << m << " random values using linear search (unordered)... ";
	t0 = clock();
	cout.flush();
	for (int i=0; i<m; i++) {
		int target = rand() % (2*n);
		linear_search_unordered(v, target);
	}
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";

	cout << "looking up " << m << " random values using linear search (ordered)... ";
	t0 = clock();
	cout.flush();
	for (int i=0; i<m; i++) {
		int target = rand() % (2*n);
		linear_search_ordered(v, target);
	}
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";

	cout << "looking up " << m << " random values using binary search... ";
	t0 = clock();
	cout.flush();
	for (int i=0; i<m; i++) {
		int target = rand() % (2*n);
		binary_search(v, target);
	}
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";

	cout << "looking up " << m << " random values using std::find... ";
	t0 = clock();
	cout.flush();
	for (int i=0; i<m; i++) {
		int target = rand() % (2*n);
		std::find(v.begin(), v.end(), target);
	}
	t1 = clock();
	cout << (t1-t0)/double(CLOCKS_PER_SEC) << " seconds\n";
}
