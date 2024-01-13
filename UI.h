#include <iostream>
#include <string>
#include <vector>
#include "DL.h"

using namespace std;

int menu1();
int menu2();
void endProgram();
void printOnScreen();

int menu1()
{
    string op;
    cout << endl
         << "\t Menu 1 \t" << endl;
    cout << "-----------------------" << endl;
    cout << " 1. Load 100 records" << endl;
    cout << " 2. Load 1000 records" << endl;
    cout << " 3. Load 10000 records" << endl;
    cout << " 4. Load 100000 records" << endl;
    cout << " 5. Load 500000 records" << endl;
    cout << " 0. Back"
         << endl;

Menu:
    cout << " Your Choice: ";
    cin >> op;
    int num = stoi(op);

    if (num >= 0 && num <= 5)
        return num;

    else
    {
        cout << "Invalid Choice!" << endl
             << endl;
        goto Menu;
    }
}

int menu2()
{
    string op;
    cout << endl
         << "\t Menu 2 \t" << endl;
    cout << "-----------------------" << endl;
    cout << " 1. Bubble Sort" << endl;
    cout << " 2. Selection Sort" << endl;
    cout << " 3. Insertion Sort" << endl;
    cout << " 4. Merge Sort" << endl;
    cout << " 5. Quick Sort" << endl;
    cout << " 6. Heap Sort" << endl;
    cout << " 7. Counting Sort" << endl;
    cout << " 8. Radix Sort" << endl;
    cout << " 9. Bucket Sort" << endl;
    cout << " 0. Back"
         << endl;

Menu:
    cout << " Your Choice: ";
    cin >> op;
    int num = stoi(op);

    if (num >= 0 && num <= 9)
        return num;

    else
    {
        cout << "Invalid Choice!" << endl
             << endl;
        goto Menu;
    }
}

void endProgram()
{
    cout << endl << "Program Termianted " << endl;
}

void printOnScreen(vector<Organization*> arr)
{
    cout << endl;

    for( int i = 0; i < arr.size(); i++ )
    {
        cout<< arr[i]->index 
            << " , " << arr[i]->organization 
            << " , " << arr[i]->name 
            << " , " << arr[i]->website
            << " , " << arr[i]->country 
            << " , " << arr[i]->description 
            << " , " << arr[i]->founded 
            << " , " << arr[i]->industry
            << " , " << arr[i]->employees
            << endl;
    }
}