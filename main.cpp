#include <iostream>
using namespace std;

void allocateArray(int*& arr, int size) {
    arr = new int[size];
}

void initializeArray(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

void addElement(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    ++size;
}

void insertElement(int*& arr, int& size, int index, int value) {
    if (index < 0 || index > size) return;
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    newArr[index] = value;
    for (int i = index; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    ++size;
}

void deleteElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) return;
    int* newArr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    --size;
}

int main() {
    int* arr = nullptr;
    int size = 0;

    allocateArray(arr, 5);
    initializeArray(arr, 5, 10);
    printArray(arr, 5);

    addElement(arr, size, 20);
    printArray(arr, size);

    insertElement(arr, size, 2, 30);
    printArray(arr, size);

    deleteElement(arr, size, 3);
    printArray(arr, size);

    deleteArray(arr);

    return 0;
}
