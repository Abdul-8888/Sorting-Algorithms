#include "UI.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
    int op, choice = 0;
    vector <Organization*> list;

Menu1:
    choice = menu1();

    if( choice == 0 )
        goto EndProgram;

    load(choice, list);

Menu2:
    op = menu2();

    if( op == 0 )
        goto Menu1;

    else
    {
        auto start = steady_clock::now();

        if( op == 1 )
        {
            bubbleSort(list, list.size());
        }

        else if( op == 2 )
        {
            selectionSort(list, list.size());
        }

        else if( op == 3 )
        {
            insertionSort(list, list.size());
        }

        else if( op == 4 )
        {
            mergeSort(list, 0, list.size() - 1 );
        }

        else if( op == 5 )
        {
            quickSort(list, 0, list.size() - 1);
        }

        else if( op == 6 )
        {
            heapSort(list, list.size());
        }

        else if( op == 7 )
        {
            countingSort(list);
        }

        else if( op == 8 )
        {
            radixSort(list);
        }

        else if( op == 9 )
        {
            bucketSort(list);
        }

        auto end = steady_clock::now();
        auto nanosecond = duration_cast<nanoseconds>( end - start );
        cout <<endl << " time = " << nanosecond.count() <<endl;

        //printOnScreen(list);

        goto Menu2;
    }

EndProgram:
    store(list, choice);
    endProgram();

    return 0;
}
