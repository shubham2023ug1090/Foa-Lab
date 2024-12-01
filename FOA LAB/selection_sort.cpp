#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
       
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

       
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    
    auto start = high_resolution_clock::now();

    selectionSort(arr, n);

    
    auto end = high_resolution_clock::now();

    
    auto duration = (end - start);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Time taken by Selection Sort: " << duration.count() << " seconds" << endl;

    return 0;
}
