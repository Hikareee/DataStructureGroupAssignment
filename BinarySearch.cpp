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

int numsinFile();
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int n, int x)
{
    // search space is nums[low…high]
    int low = 0, high = n - 1;

    // loop till the search space is exhausted
    while (low <= high)
    {
        // find the mid-value in the search space and
        // compares it with the target

        int mid = (low + high) / 2;    // overflow can happen
        // int mid = low + (high - low)/2;
        // int mid = high - (high - low)/2;

        // target value is found
        if (x == arr[mid]) {
            return mid;
        }

        // if the target is less than the middle element, discard all elements
        // in the right search space, including the middle element
        else if (x < arr[mid]) {
            high = mid - 1;
        }

        // if the target is more than the middle element, discard all elements
        // in the left search space, including the middle element
        else {
            low = mid + 1;
        }
    }

    // target doesn't exist in the array
    return -1;
}
void Show(int Entries, int Arr[]) {
    for (int i = 0; i < Entries; i++) {
        cout << Arr[i] << '\t';
        if (!(i % 10)) {
            cout << endl;
        }
    }
}
void readFromFile(char FileName[], int storage[], int& noOfEn) {
    ifstream take(FileName);
    take >> noOfEn;
    for (int i = 0; i < noOfEn; i++) {
        take >> storage[i];

    }
}

int main(void)
{
    int count, stor[500];
    char filename[12] = { "500test.txt" };
    readFromFile(filename, stor, count);
    int x = 248;
    auto started = std::chrono::high_resolution_clock::now();
    int result = binarySearch(stor, count, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    Show(count, stor);
    // Calculating total time taken by the program.
    auto done = std::chrono::high_resolution_clock::now();

    cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
    return 0;


}
