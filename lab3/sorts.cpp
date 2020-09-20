#include "sorts.h"


int Sorts::bubbleSort(int* arr, int size)
{
    int numOfComparisons = 0, tmp;
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;


            }
            numOfComparisons+=1;
        }
    }

    return numOfComparisons;
}

int Sorts::insertionSort(int* arr, int size)
{
    int numOfComparisons = 0, hold;
    for (int pass = 0; pass < size-1; pass++)
    {
        for (int j = pass+1; j < size; j++)
        {
            if (arr[pass] > arr[j])
            {
                hold = arr[j];
                arr[j] = arr[pass];
                arr[pass] = hold;


            }
            numOfComparisons+=1;
        }
    }

    return numOfComparisons;
}
