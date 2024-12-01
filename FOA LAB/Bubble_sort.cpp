#include <iostream>
#include <chrono> // Library to measure time

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 2, 22, 1, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Record start time
    auto start = high_resolution_clock::now();

    bubbleSort(arr, n);

    // Record end time
    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = (end - start);
    


    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Time taken by Bubble Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
