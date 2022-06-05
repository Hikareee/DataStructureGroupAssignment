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
    int arr[] = { 12, 193, 45, 193, 12, 349, 3933, 930, 19 };
    int size = sizeof(arr) / sizeof(int);

    cout << "Pre bubble sort: ";
    show(arr, size);
    bubblesort(arr, size);
    cout << "Post bubble sort: ";
    show(arr, size);
    auto done = high_resolution_clock::now();

    cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
    return 0;
}
