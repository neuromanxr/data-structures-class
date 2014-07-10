#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <algorithm>

/*

CIS 3130 ASSIGNMENT # 6     KELVIN LEE
Three sorting methods

*/

using namespace std;

void readInData(int n, int dataArray[][3]);
void threeSort(int n, int dataArray[][3]);
int sPartition(int dataArray[][3], int sLeft, int sRight, int col);
void quicksort(int dataArray[][3], int sLeft, int sRight, int col);
void shiftRight(int dataArray[][3], int low, int high, int col);
void heapify(int dataArray[][3], int low, int high, int col);
void heapSort(int dataArray[][3], int sizeOfArray, int col);
void compareSorts(int, int, int, char);

const int DATASET10 = 10;
const int DATASET50 = 50;
const int DATASET100 = 100;

int bubbleSortSwapCount = 0;
int bubbleSortCompCount = 0;
int quickSortSwapCount = 0;
int quickSortCompCount = 0;
int heapSortSwapCount = 0;
int heapSortCompCount = 0;

int numbersArray[100][3];
ofstream output("output.txt");

int main()
{

    readInData(DATASET10, numbersArray);    // read in data set array with 10 numbers
    threeSort(DATASET10, numbersArray);     // sort the 10 numbers

    readInData(DATASET50, numbersArray);
    threeSort(DATASET50, numbersArray);

    readInData(DATASET100, numbersArray);
    threeSort(DATASET100, numbersArray);

    cout << endl;
    output << endl;
    compareSorts(bubbleSortCompCount, quickSortCompCount, heapSortCompCount, 'c');
    compareSorts(bubbleSortSwapCount, quickSortSwapCount, heapSortSwapCount, 's');

    return 0;
}

void readInData(int n, int dataArray[][3])
{
    if (n == 10)
    {
        cout << endl;
        cout << "10 numbers in almost sorted order (two or three numbers interchanged)" << endl;
        cout << "10 numbers in random order" << endl;
        cout << "10 numbers in reverse order" << endl;

        output << endl;
        output << "10 numbers in almost sorted order (two or three numbers interchanged)" << endl;
        output << "10 numbers in random order" << endl;
        output << "10 numbers in reverse order" << endl;

        ifstream dataIn("dataset10.txt");
        if (dataIn)
        {
            cout << "File open successful" << endl;

            // read in data file
            for (int i = 0; i < n; i++)
            {
                dataIn >> dataArray[i][0] >> dataArray[i][1] >> dataArray[i][2];
            }

            for (int i = 0; i < n; i++)
            {
                cout << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
                output << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
            }

            dataIn.close();
        }
    }
    if (n == 50)
    {
        cout << endl;
        cout << "50 numbers in almost sorted order (a few out of order)" << endl;
        cout << "50 numbers in random order" << endl;
        cout << "50 numbers in reverse order" << endl;

        output << endl;
        output << "50 numbers in almost sorted order (a few out of order)" << endl;
        output << "50 numbers in random order" << endl;
        output << "50 numbers in reverse order" << endl;

        ifstream dataIn("dataset50.txt");
        if (dataIn)
        {
            cout << "File open successful" << endl;

            // read in data file
            for (int i = 0; i < n; i++)
            {
                dataIn >> dataArray[i][0] >> dataArray[i][1] >> dataArray[i][2];
            }

            for (int i = 0; i < n; i++)
            {
                cout << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
                output << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
            }

            dataIn.close();
        }
    }
    if (n == 100)
    {
        cout << endl;
        cout << "100 numbers in almost sorted order (a few out of order)" << endl;
        cout << "100 numbers in random order" << endl;
        cout << "100 numbers in reverse order" << endl;

        output << endl;
        output << "100 numbers in almost sorted order (a few out of order)" << endl;
        output << "100 numbers in random order" << endl;
        output << "100 numbers in reverse order" << endl;

        ifstream dataIn("dataset100.txt");
        if (dataIn)
        {
            cout << "File open successful" << endl;

            // read in data file
            for (int i = 0; i < n; i++)
            {
                dataIn >> dataArray[i][0] >> dataArray[i][1] >> dataArray[i][2];
            }

            for (int i = 0; i < n; i++)
            {
                cout << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
                output << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
            }

            dataIn.close();
        }
    }
}

void threeSort(int n, int dataArray[][3])
{
    // bubble sort
    // should put in seperate function
    bool swapped = true;
    int i = 0;
    int temp;

    while (swapped)
    {
        swapped = false;
        i++;
        for (int j = 0; j < n - i; j++)
        {
            if (dataArray[j][0] > dataArray[j + 1][0])  // sort the first column
            {
                temp = dataArray[j][0];
                dataArray[j][0] = dataArray[j + 1][0];
                dataArray[j + 1][0] = temp;
                swapped = true;
                bubbleSortSwapCount++;
            }
            if (dataArray[j][1] > dataArray[j + 1][1])  // sort the second column
            {
                temp = dataArray[j][1];
                dataArray[j][1] = dataArray[j + 1][1];
                dataArray[j + 1][1] = temp;
                swapped = true;
                bubbleSortSwapCount++;
            }
            if (dataArray[j][2] > dataArray[j + 1][2])  // sort the third column
            {
                temp = dataArray[j][2];
                dataArray[j][2] = dataArray[j + 1][2];
                dataArray[j + 1][2] = temp;
                swapped = true;
                bubbleSortSwapCount++;
            }
            bubbleSortCompCount++;
        }
    }
    cout << endl;
    cout << "BUBBLESORT" << endl;
    output << endl;
    output << "BUBBLESORT" << endl;
    for (int i = 0; i < n; i++)     // check that the array is sorted
    {
        cout << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
        output << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
    }
//    cout << "swap count " << bubbleSortSwapCount << endl;
//    cout << "comp count " << bubbleSortCompCount << endl;

    readInData(n, dataArray);       // reset the data for sorting again

    quicksort(dataArray, 0, (n - 1), 0);
    quicksort(dataArray, 0, (n - 1), 1);
    quicksort(dataArray, 0, (n - 1), 2);
    cout << endl;
    cout << "QUICKSORT" << endl;
    output << endl;
    output << "QUICKSORT" << endl;
    for (int i = 0; i < n; i++)     // check that the array is sorted
    {
        cout << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
        output << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
    }
//    cout << "swap count " << quickSortSwapCount << endl;
//    cout << "comp count " << quickSortCompCount << endl;

    readInData(n, dataArray);       // reset the data for sorting again

    heapSort(dataArray, n, 0);
    heapSort(dataArray, n, 1);
    heapSort(dataArray, n, 2);
    cout << endl;
    cout << "HEAPSORT" << endl;
    output << endl;
    output << "HEAPSORT" << endl;
    for (int i = 0; i < n; i++)     // check that the array is sorted
    {
        cout << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
        output << numbersArray[i][0] << " " << numbersArray[i][1] << " " << numbersArray[i][2] << endl;
    }
//    cout << "swap count " << heapSortSwapCount << endl;
//    cout << "comp count " << heapSortCompCount << endl;
}

int sPartition(int dataArray[][3], int sLeft, int sRight, int col)
{
    int pivot = dataArray[sRight][col];

    while (sLeft < sRight)
    {
        while (dataArray[sLeft][col] < pivot)
            sLeft++;

        while (dataArray[sRight][col] > pivot)
            sRight--;

        if (dataArray[sLeft][col] == dataArray[sRight][col])
            sLeft++;
        else if (sLeft < sRight)
        {
            int tmp = dataArray[sLeft][col];
            dataArray[sLeft][col] = dataArray[sRight][col];
            dataArray[sRight][col] = tmp;
            quickSortSwapCount++;
        }
        quickSortCompCount++;
    }

    return sRight;
}

// The quicksort recursive function
void quicksort(int dataArray[][3], int sLeft, int sRight, int col)
{
    if (sLeft < sRight)
    {
        int j = sPartition(dataArray, sLeft, sRight, col);
        quicksort(dataArray, sLeft, j - 1, col);
        quicksort(dataArray, j + 1, sRight, col);
    }
}

// heapsort functions
void shiftRight(int dataArray[][3], int low, int high, int col)
{
    int root = low;
    while ((root * 2) + 1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /* Check if root is less than left child */
        if (dataArray[swapIdx][col] < dataArray[leftChild][col])
        {
            swapIdx = leftChild;
            heapSortCompCount++;
        }
        /* If right child exists check if it is less than current root */
        if ((rightChild <= high) && (dataArray[swapIdx][col] < dataArray[rightChild][col]))
        {
            swapIdx = rightChild;
            heapSortCompCount++;
        }
        /* Make the biggest element of root, left and right child the root */
        if (swapIdx != root)
        {
            int tmp = dataArray[root][col];
            dataArray[root][col] = dataArray[swapIdx][col];
            dataArray[swapIdx][col] = tmp;
            /* Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself */
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
void heapify(int dataArray[][3], int low, int high, int col)
{
    /* Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child */
    int midIdx = (high - low - 1) / 2;
    while (midIdx >= 0)
    {
        shiftRight(dataArray, midIdx, high, col);
        --midIdx;
    }
    return;
}
void heapSort(int dataArray[][3], int sizeOfArray, int col)
{
    assert(dataArray);
    assert(sizeOfArray > 0);
    /* This will put max element in the index 0 */
    heapify(dataArray, 0, sizeOfArray - 1, col);
    int high = sizeOfArray - 1;
    while (high > 0)
    {
        /* Swap max element with high index in the array */
        int tmp = dataArray[high][col];
        dataArray[high][col] = dataArray[0][col];
        dataArray[0][col] = tmp;
        --high;
        /* Ensure heap property on remaining elements */
        shiftRight(dataArray, 0, high, col);
        heapSortSwapCount++;
    }
    return;
}

void compareSorts(int bSort, int qSort, int hSort, char soc)
{
    int temp[3] = {bSort, qSort, hSort};

    cout << "bubblesort: " << temp[0] << endl;
    cout << "quicksort: " << temp[1] << endl;
    cout << "heapsort: " << temp[2] << endl;
    cout << endl;
    output << "bubblesort: " << temp[0] << endl;
    output << "quicksort: " << temp[1] << endl;
    output << "heapsort: " << temp[2] << endl;
    output << endl;

    sort(temp, temp + 3);

    if (soc == 'c')
    {
        cout << "Comparison - " << endl;
        cout << "Most " << temp[2] << endl;
        cout << "Middle " << temp[1] << endl;
        cout << "Least " << temp[0] << endl;
        cout << endl;
        output << "Comparison - " << endl;
        output << "Most " << temp[2] << endl;
        output << "Middle " << temp[1] << endl;
        output << "Least " << temp[0] << endl;
        output << endl;
    }
    else
    {
        cout << "Swaps - " << endl;
        cout << "Most " << temp[2] << endl;
        cout << "Middle " << temp[1] << endl;
        cout << "Least " << temp[0] << endl;
        cout << endl;
        output << "Swaps - " << endl;
        output << "Most " << temp[2] << endl;
        output << "Middle " << temp[1] << endl;
        output << "Least " << temp[0] << endl;
        output << endl;
    }

}

