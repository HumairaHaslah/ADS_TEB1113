#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // first element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] < pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]); 
            i++;
            j--;
        }
    }
    swap(arr[low], arr[j]);
    return j;      
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {56, 72, 30, 15, 78, 54, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array (quick sort): ";
    printArray(arr, n);

    return 0;
}
