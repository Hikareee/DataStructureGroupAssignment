#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    srand((unsigned)time(0));
    int randomNumber;
    int MAXI = 100; // size of the array
    string outstr("{");
    for (int i = 0; i < MAXI; i++)
    {
        randomNumber = (rand() % MAXI) + 1;
        cout << randomNumber << ", ";
    }

    return 0;
}
