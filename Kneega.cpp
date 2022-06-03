#include <iostream>
#include <Hashing.h>
#include <BinarySearch.h>
#include <Array 10.h>
#include <Array 100.h>
#include <Array 1000.h>
#include <Array 10000.h>

using namespace std;

int main(){
    int arr[10] = { 7, 8, 10, 4, 1, 1, 10, 4, 8, 2 };
    int x = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
    
}