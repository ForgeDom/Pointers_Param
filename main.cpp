#include <iostream>
using namespace std;

int* appendBlock(int* array, int size, int* block, int blockSize, int& newSize) {
    newSize = size + blockSize;
    int* newArray = new int[newSize];

    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < blockSize; ++i) {
        newArray[size + i] = block[i];
    }

    return newArray;
}

int main() {
    int size = 5;
    int* array = new int[size] {1, 2, 3, 4, 5};
    int blockSize = 3;
    int* block = new int[blockSize] {6, 7, 8};

    int newSize;
    int* extendedArray = appendBlock(array, size, block, blockSize, newSize);

    cout << "Extended array: ";
    for (int i = 0; i < newSize; ++i) {
        cout << extendedArray[i] << " ";
    }
    cout << endl;

    delete[] array;
    delete[] block;
    delete[] extendedArray;

    return 0;
}
