#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <fstream>
#include "BL.h"

using namespace std;

void load(int op, vector<Organization*> &arr);
string parseRecord(string record, int field);
void store( vector<Organization*> &arr, int op );
void bubbleSort(vector<Organization*> &arr, int n);
void selectionSort(vector<Organization*> &arr, int n);
int findMinimum(vector<Organization*> &arr, int start, int end);
void insertionSort(vector<Organization*> &arr, int n);
void mergeSort(vector<Organization*> &arr, int start, int end);
void merge(vector<Organization*> &arr, int start, int mid, int end);
void quickSort(vector<Organization*> &arr, int start, int end);
int partition(vector<Organization*> &arr, int start, int end);
void heapSort(vector<Organization*> &heapArr, int size);
void heapify(vector<Organization*> &heapArr, int size, int index);
int parentIndex(int i);
int leftChildIndex(int i);
int rightChildIndex(int i);
void countingSort(vector<Organization*> &arr);
int maxElement( vector<Organization*> arr );
void radixSort(vector<Organization*> &arr);
void countingSort(vector<Organization*> &arr, int place);
void bucketSort(vector<Organization*> &arr);

//_______________________________________________Loading Data form File
void load(int op, vector<Organization*> &arr)
{
    fstream file;

    if (op == 1)
        file.open("organizations-100.csv", ios::in);
    else if (op == 2)
        file.open("organizations-1000.csv", ios::in);
    else if (op == 3)
        file.open("organizations-10000.csv", ios::in);
    else if ( op == 4 )
        file.open("organizations-100000.csv", ios::in);
    else
        file.open("organizations-500000.csv", ios::in);

    string line, word, temp;

    getline(file, line);

    while (getline(file, line))
    {
        Organization *node = new Organization();
        std::istringstream(parseRecord(line, 0)) >> node->index;
        node->organization = parseRecord(line, 1);
        node->name = parseRecord(line, 2);
        node->website = parseRecord(line, 3);
        node->country = parseRecord(line, 4);
        node->description = parseRecord(line, 5);
        node->founded = parseRecord(line, 6);
        node->industry = parseRecord(line, 7);
        std::istringstream(parseRecord(line, 8)) >> node->employees;
        arr.push_back(node);
    }
    file.close();
}

string parseRecord(string record, int field)
{
    int commaCount = 0;
    string item;

    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

//_______________________________________________Storing Data in File
void store( vector<Organization*> &arr, int op )
{
    fstream file;

    if (op == 1)
        file.open("organizations-100.csv", ios::in);
    else if (op == 2)
        file.open("organizations-1000.csv", ios::in);
    else if (op == 3)
        file.open("organizations-10000.csv", ios::in);
    else if ( op == 4 )
        file.open("organizations-100000.csv", ios::in);
    else
        file.open("organizations-500000.csv", ios::in);
    
    for (int i = 0; i < arr.size(); i++)
    {
        file << arr[i]->index <<"," << arr[i]->organization <<"," << arr[i]->name <<"," << arr[i]->website <<"," << arr[i]->country <<"," << arr[i]->description <<"," << arr[i]->founded <<"," << arr[i]->industry <<"," << arr[i]->employees <<endl;
    }
    
    file.close(); 
}

//_______________________________________________Bubble Sort
void bubbleSort(vector<Organization*> &arr, int n)
{
    for (int x = 0; x < n - 1; x++)
    {
        bool isSwapped = false;
        for (int y = 0; y < n - x - 1; y++)
        {
            if (arr[y]->employees > arr[y + 1]->employees)
            {
                swap(arr[y], arr[y + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}

//_________________________________________________Selection Sort
void selectionSort(vector<Organization*> &arr, int n)
{
    for (int x = 0; x < n - 1; x++)
    {
        int minIndex = findMinimum(arr, x, n);
        swap(arr[x], arr[minIndex]);
    }
}

int findMinimum(vector<Organization*> &arr, int start, int end)
{
    Organization *min = arr[start];
    int minIndex = start;
    for (int x = start; x < end; x++)
    {
        if (min->employees > arr[x]->employees)
        {
            min = arr[x];
            minIndex = x;
        }
    }
    return minIndex;
}

//____________________________________________________Insertion Sort
void insertionSort(vector<Organization*> &arr, int n)
{
    for (int x = 1; x < n; x++)
    {
        Organization *key = arr[x];
        int y = x - 1;
        while (y >= 0 && arr[y]->employees > key->employees)
        {
            arr[y + 1] = arr[y];
            y--;
        }
        arr[y + 1] = key;
    }
}

//_______________________________________________________Merge Sort
void mergeSort(vector<Organization*> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(vector<Organization*> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    queue<Organization*> tempArr;
    while (i <= mid && j <= end)
    {
        if (arr[i]->employees < arr[j]->employees)
        {
            tempArr.push(arr[i]);
            i++;
        }
        else
        {
            tempArr.push(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tempArr.push(arr[i]);
        i++;
    }
    while (j <= end)
    {
        tempArr.push(arr[j]);
        j++;
    }
    for (int x = start; x <= end; x++)
    {
        arr[x] = tempArr.front();
        tempArr.pop();
    }
}

//__________________________________________________________Quick Sort
  void quickSort(vector<Organization*> &arr, int start, int end)
  {
    if (start >= end)
      return;

    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
  }

int partition(vector<Organization*> &arr, int start, int end)
  {

    int pivot = arr[start]->employees;

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
      if (arr[i]->employees <= pivot)
        count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
      while (arr[i]->employees <= pivot)
      {
        i++;
      }
      while (arr[j]->employees > pivot)
      {
        j--;
      }
      if (i < pivotIndex && j > pivotIndex)
      {
        swap(arr[i++], arr[j--]);
      }
    }

    return pivotIndex;
  }


//___________________________________________________________Heap Sort
void heapSort(vector<Organization*> &heapArr, int size)
{
    for (int x = (size / 2) - 1; x >= 0; x--)
    {
        heapify(heapArr, size, x);
    }
    for (int x = size - 1; x > 0; x--)
    {
        swap(heapArr[0], heapArr[x]);
        heapify(heapArr, x, 0);
    }
}

void heapify(vector<Organization*> &heapArr, int size, int index)
{
    int maxIndex;
    while (true)
    {
        int lIdx = leftChildIndex(index);
        int rIdx = rightChildIndex(index);
        if (rIdx >= size)
        {
            if (lIdx >= size)
                return;
            else
                maxIndex = lIdx;
        }
        else
        {
            if (heapArr[lIdx]->employees >= heapArr[rIdx]->employees)
                maxIndex = lIdx;
            else
                maxIndex = rIdx;
        }
        if (heapArr[index]->employees < heapArr[maxIndex]->employees)
        {
            swap(heapArr[index], heapArr[maxIndex]);
            index = maxIndex;
        }
        else
            return;
    }
}

int parentIndex(int i)
{
    return (i - 1) / 2;
}
int leftChildIndex(int i)
{
    return (2 * i) + 1;
}
int rightChildIndex(int i)
{
    return (2 * i) + 2;
}

//_________________________________________________________Counting Sort
void countingSort(vector<Organization*> &arr)
{
    int max = maxElement(arr);
    vector<int> count(max + 1);
    vector<Organization*> output(arr.size());

    for( int i = 0; i < count.size(); i++ )
    {
        count[i] = 0;
    }
    for (int x = 0; x < arr.size(); x++)
    {
        count[arr[x]->employees]++;
    }
    for (int x = 1; x < count.size(); x++)
    {
        count[x] = count[x - 1] + count[x];
    }
    for (int x = arr.size() - 1; x >= 0; x--)
    {
        int index = count[arr[x]->employees] - 1;
        count[arr[x]->employees]--;
        output[index] = arr[x];
    }
    for (int x = 0; x < output.size(); x++)
    {
        arr[x] = output[x];
    }
}

int maxElement( vector<Organization*> arr )
{
    Organization *temp = arr[0];
    int idx = 0;

    for( int i = 0; i < arr.size(); i++ )
    {
        if( arr[i]->employees > temp->employees )
        {
            temp = arr[i];
            idx = i;
        }
    }

    return arr[idx]->employees;
}

//__________________________________________________________Radix Sort
void radixSort(vector<Organization*> &arr)
{
    int max = maxElement(arr);
    int place = 1;
    while ((max / place) > 0)
    {
        countingSort(arr, place);
        place = place * 10;
    }
}

void countingSort(vector<Organization*> &arr, int place)
{
    vector<int> count(10);
    vector<Organization*> output(arr.size());
    for (int x = 0; x < arr.size(); x++)
    {
        count[(arr[x]->employees / place) % 10]++;
    }
    for (int x = 1; x < count.size(); x++)
    {
        count[x] = count[x - 1] + count[x];
    }
    for (int x = arr.size() - 1; x >= 0; x--)
    {
        int index = count[(arr[x]->employees / place) % 10] - 1;
        count[(arr[x]->employees / place) % 10]--;
        output[index] = arr[x];
    }
    for (int x = 0; x < output.size(); x++)
    {
        arr[x] = output[x];
    }
}

//_________________________________________________________Bucket Sort
void bucketSort(vector<Organization*> &arr)
{
    vector<vector<Organization*>> bucket(arr.size());

    for (int x = 0; x < arr.size(); x++)
    {
        bucket[int(arr[x]->employees / arr.size())].push_back(arr[x]);
    }
    for (int x = 0; x < bucket.size(); x++)
    {
        insertionSort(bucket[x], bucket[x].size());
    }
    int index = 0;
    for (int x = 0; x < bucket.size(); x++)
    {
        for (int y = 0; y < bucket[x].size(); y++)
        {
            arr[index] = bucket[x][y];
            index++;
        }
    }
}