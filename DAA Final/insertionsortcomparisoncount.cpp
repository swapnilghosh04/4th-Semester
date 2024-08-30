#include <iostream>

class InsertionSort {
public:
    int comparison = 0;
    void insertionSort(int arr[], int size) {
        arr[-1] = -999;
        for(int i = -1; i < (size - 1); i++) {
            int j = i, next = arr[j + 1];
            for (comparison++; arr[j] > next; comparison++) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = next;
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
    InsertionSort ob;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> arr[i];
    }
    ob.insertionSort(arr, size);
    std::cout << "The sorted array is" << std::endl;
    ob.display(arr, size);
    std::cout << "Number of comparisons: " << ob.comparison;
    return 0;
}
