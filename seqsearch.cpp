#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int numsInFile();

int seqsearch(int arr[], int n, int x)
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

	ifile.open("1000.txt");

	if(ifile.fail())
	{
		cout<<"Invalid filename" << endl;
		exit(0);
	}

	int* dyArr = new int[numsInFile()];
	char trash;
	ifile >> trash;
	int num = 0;
	for(int i = 0; !ifile.eof(); i++)
	{
		ifile>>num >> trash;
		if (!ifile.good())
			break;
		(dyArr[i])= num;
	}

	ifile.close();
	return (dyArr);

}

int numsInFile()
{
	ifstream ifile;
	char trash;
	ifile.open("1000.txt");

	ifile >> trash;
	int i;
	int num = 0;
	for (i=0; ifile.good(); i++)
	{
		ifile>> num >> trash;
		if (!ifile.good())
			break;
		cout << num << trash;
	}
	return i;
}

//driver code
int main(void)
{	
	int* arr = readDataFile();
	
	int x = 2;

	auto start = high_resolution_clock::now();

	int result = seqsearch(arr, numsInFile(), x);

	auto stop = high_resolution_clock::now();

	(result == -1)
		? cout << "Element is not present in array"
		: cout << "\nElement is present at index: " << result;

	cout << endl;

	auto duration = duration_cast<milliseconds>(stop - start);
	cout<<"Time taken by function: " <<duration.count()<< "milliseconds"<< endl;

	delete [] arr;
	return 0;
}
