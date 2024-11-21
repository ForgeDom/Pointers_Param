#include <iostream>
using namespace std;

int* removeNegatives(int* array, int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            ++newSize;
        }
    }

    int* newArray = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            newArray[index++] = array[i];
        }
    }

    return newArray;
}

int main() {
    int size = 6;
    int* array = new int[size] {1, -3, 5, -7, 9, -11};

    int newSize;
    int* filteredArray = removeNegatives(array, size, newSize);

    cout << "New array: ";
    for (int i = 0; i < newSize; ++i) {
        cout << filteredArray[i] << " ";
    }
    cout << endl;

    delete[] array;
    delete[] filteredArray;

    return 0;
}
