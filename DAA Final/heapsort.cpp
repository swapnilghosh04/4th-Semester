#include <iostream>

void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int length;
    std::cout << "Enter the number of elements: ";
    std::cin >> length;
    int* array = new int[length];
    std::cout << "Enter " << length << " array elements" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "a[" << i << "] = ";
        std::cin >> array[i];
    }
    heapSort(array, length);
    std::cout << "Sorted array is \n";
    printArray(array, length);
}
