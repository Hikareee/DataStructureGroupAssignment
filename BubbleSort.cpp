#include <iostream>
#include <chrono>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
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

	ifile.open("1000.txt");

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
	ifile.open("1000.txt");

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

void bubble(int a[], int n) {
    int i = n - 1;
    while (i > 0) {
        if (a[i] < a[i - 1]) {
            swap(a, i, i - 1);
        }
        i--;
    }
}
void bubblesort(int a[], int n) {
    int i = 0;
    while (i < n - 1) {
        bubble(a, n);
        i++;
    }
}

void show(int a[], int n) {
    int i = 0;
    while (i < n) {
        cout << a[i] << ", ";
        i++;
    }
    cout << endl;
}

int main() {

    auto started = high_resolution_clock::now();
	int* arr = readDataFile();
	int size = numsInFile();

    cout << "Pre bubble sort: ";
    show(arr, size);
    bubblesort(arr, size);
    cout << "Post bubble sort: ";
    show(arr, size);
    auto done = high_resolution_clock::now();

    cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
    return 0;
}
