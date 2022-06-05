// C++ program to implement recursive Binary Search
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <chrono>
#include <bits.h>

using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half  
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half 
		else
			r = m - 1;
	}

	// if we reach here, then element was not present
	return -1;
}
  
int numsInFile();

int seqsearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int* readDataFile()
{
	fstream ifile;
	string datafile;

	ifile.open("onethousand.txt");

	if (ifile.fail())
	{
		cout << "Invalid filename" << endl;
		exit(0);
	}

	int* dyArr = new int[numsInFile()];
	char trash;
	ifile >> trash;
	int num = 0;
	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> num >> trash;
		if (!ifile.good())
			break;
		(dyArr[i]) = num;
	}

	ifile.close();
	return (dyArr);

}

int numsInFile()
{
	ifstream ifile;
	char trash;
	ifile.open("onethousand.txt");

	ifile >> trash;
	int i;
	int num = 0;
	for (i = 0; ifile.good(); i++)
	{
		ifile >> num >> trash;
		if (!ifile.good())
			break;
		cout << num << trash;
	}
	return i;
}

int main(void)
{
	cout << "The array:\n ";
	int* arr = readDataFile();
    int x = 929;
    auto started = std::chrono::high_resolution_clock::now();
    int result = binarySearch(arr, 0,numsInFile(), x);
	auto done = std::chrono::high_resolution_clock::now();
    (result == -1)
        ? cout << "\nElement is not present in array"
        : cout << "\nElement is present at index " << result;
    cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
    return 0;
}
