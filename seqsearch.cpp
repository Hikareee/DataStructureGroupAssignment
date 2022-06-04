#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int numsinFile();

int search(int arr[], int n, int x)
{
	int i;
	for (i= 0; i < n; i++)
		if(arr[i] == x)
			return i;
	return -1;
}

int* readDataFile()
{
	fstream ifile;
	string datafile;
	//cout<<"Enter the name of the data file to read: " << endl;
	// cin>> datafile;
	ifile.open("10.txt");

	if(ifile.fail())
	{
		cout<<"Invalid filename" << endl;
		exit(0);
	}

	int* dyArr = new int[numsInFile()];
	int num = 0;
	for(int i = 0; !ifile.eof(); i++)
	{
		ifile>>num;
		ifile.ignore();
		(dyArr[i])= num;
	}

	ifile.close();
	return (dyArr);
}

int numsInFile()
{
	ifstream ifile;
	ifile.open("10.txt");

	int i;
	int num = 0;
	for (i=0; ifile.good(); i++)
	{
		ifile>> num;
		ifile.ignore(1);
	}
	return i;
}



int main(void)
{
	int* arr = readDataFile();
	int x = ;
	auto start = high_resolution_clock::now();
	int result = search(arr, numsInFile(), x);
	auto stop = high_resolution_clock::now();
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index" << result;
	cout << endl;

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count()<< "microseconds" << endl;

	delete [] arr;
	return 0;
}

