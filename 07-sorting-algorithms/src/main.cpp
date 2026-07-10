#include <iostream>
#include <vector>
using namespace std;

// Print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort - repeatedly swaps adjacent elements if they are in wrong order
int bubbleSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Bubble Sort result: ";
    printArray(arr);
    return comparisons;
}

// Selection Sort - finds the minimum element and places it at the correct position
int selectionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    cout << "Selection Sort result: ";
    printArray(arr);
    return comparisons;
}

// Insertion Sort - builds the sorted array one element at a time
int insertionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Insertion Sort result: ";
    printArray(arr);
    return comparisons;
}

int main() {
    vector<int> originalArray;
    int n;

    cout << "=== Sorting Algorithms Comparison ===" << endl;
    cout << "How many numbers do you want to enter? ";
    cin >> n;

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        originalArray.push_back(num);
    }

    cout << "\nOriginal array: ";
    printArray(originalArray);
    cout << endl;

    int bubbleComparisons = bubbleSort(originalArray);
    int selectionComparisons = selectionSort(originalArray);
    int insertionComparisons = insertionSort(originalArray);

    cout << "\n=== Comparison Count ===" << endl;
    cout << "Bubble Sort: " << bubbleComparisons << " comparisons" << endl;
    cout << "Selection Sort: " << selectionComparisons << " comparisons" << endl;
    cout << "Insertion Sort: " << insertionComparisons << " comparisons" << endl;

    return 0;
}