#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    auto start = high_resolution_clock::now();

    insertionSort(arr, n);

    auto end = high_resolution_clock::now();

    auto duration = (end - start);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Time taken by Insertion Sort: " << duration.count() << " seconds" << endl;

    return 0;
}
