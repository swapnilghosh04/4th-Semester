#include<iostream>

class MergeSort {
    void merge(int arr[], int low, int mid, int high) {
        int lengthl = (mid - low) + 1, lengthr = (high - mid), l, r, index;
        int left[lengthl], right[lengthr];
        for(int i = 0, j = low; j <= mid; i++, j++) {
            left[i] = arr[j];
        }
        for(int i = 0, j = (mid + 1); j <= high; i++, j++) {
            right[i] = arr[j];
        }
        l = 0;
        r = 0;
        index = low;
        while((l < lengthl) && (r < lengthr)) {
            if(left[l] <= right[r]) {
                arr[index] = left[l];
                l++;
                index++;
            } else {
                arr[index] = right[r];
                r++;
                index++;
            }
            comparison++;
        }
        while(l < lengthl) {
            arr[index] = left[l];
            l++;
            index++;
        }
        while(r < lengthr) {
            arr[index] = right[r];
            r++;
            index++;
        }
    }

public:
    int comparison = 0;
    void mergeSort(int arr[], int low, int high) {
        if(low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, (mid + 1), high);
            merge(arr, low, mid, high);
        }
    }

    void display(int array[], int length) {
        std::cout << "[ ";
        for (int i = 0; i < length; i++) {
            std::cout << array[i];
            if (i != (length - 1))
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
};

int main() {
    MergeSort ob;
    int length;
    std::cout << "Enter the number of elements: ";
    std::cin >> length;
    int* array = new int[length];
    for (int i = 0; i < length; i++) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> array[i];
    }
    ob.mergeSort(array, 0, (length - 1));
    std::cout << "Sorted array" << std::endl;
    ob.display(array, length);
    std::cout << "Number of comparisons: " << ob.comparison;
    return 0;
}
