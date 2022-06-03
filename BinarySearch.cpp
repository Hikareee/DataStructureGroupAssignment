#include <iostream>


using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarr
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarr
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in arr
    return -1;
}


using namespace std;

int main() {
    int arr[10] = { 7, 8, 10, 4, 1, 1, 10, 4, 8, 2 };
    int x = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;

}

