#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

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

	ifile.open("100.txt");

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
	ifile.open("100.txt");

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

void insertIth(int a[], int n, int i)
{
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[j + 1] = key;
}


void insSort(int a[], int n)
{
    int i = 1;
    while (i < n)
    {
        insertIth(a, n, i);
        i = i + 1;
    }
}


void display(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << a[i] << ", ";
        i++;
    }
    cout << endl;
}

int main()
{
	cout << "Pre sort: ";
	int* arr = readDataFile(); 

	int size = numsInFile();

    auto started = high_resolution_clock::now();
	
    insSort(arr, size);
	cout << "\n";
	cout << "Post sort: ";
    display(arr, size);
    auto done = high_resolution_clock::now();
	cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
    return 0;
}
