#include <iostream>

class HeapSort {
    void heapify(int arr[], int N, int i, int &comparison) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[largest]) {
            largest = l;
            comparison++;
        }
        if (r < N && arr[r] > arr[largest]) {
            largest = r;
            comparison++;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, N, largest, comparison);
        }
    }

public:
    int comparison = 0;
    void heapSort(int arr[], int N) {
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i, comparison);
        for (int i = N - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0, comparison);
        }
    }

    void display(int arr[], int n) {
        int i;
        std::cout << "[ ";
        for (i = 0; i < (n - 1); i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[i] << " ]" << std::endl;
    }
};

int main() {
    HeapSort ob;
    int length;
    std::cout << "Enter the number of elements: ";
    std::cin >> length;
    int* array = new int[length];
    for (int i = 0; i < length; i++) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> array[i];
    }
    ob.heapSort(array, length);
    std::cout << "Sorted array is" << std::endl;
    ob.display(array, length);
    std::cout << "Number of comparisons: " << ob.comparison;
    delete[] array;  // Added to avoid memory leak
    return 0;
}

