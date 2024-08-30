#include <iostream>

class QuickSortCormen {
    int partition(int arr[], int low, int high) {
        int x, i, j;
        x = arr[high];
        i = low - 1;
        for (j = low; j < high; j++) {
            if (arr[j] <= x) {
                i++;
                std::swap(arr[i], arr[j]);
            }
            comparison++;
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

public:
    int comparison = 0;
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, (pivot - 1));
            quickSort(arr, (pivot + 1), high);
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
    QuickSortCormen ob;
    int length;
    std::cout << "Enter the number of elements: ";
    std::cin >> length;
    int* array = new int[length];
    for (int i = 0; i < length; i++) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> array[i];
    }
    ob.quickSort(array, 0, (length - 1));
    std::cout << "Sorted array is" << std::endl;
    ob.display(array, length);
    std::cout << "Number of comparisons: " << ob.comparison;
    return 0;
}
