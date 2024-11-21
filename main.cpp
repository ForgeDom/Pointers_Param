#include <iostream>
using namespace std;

int* insertBlock(int* array, int size, int* block, int blockSize, int index, int& newSize) {
    if (index < 0 || index > size) {
        cout << "Invalid index." << endl;
        return nullptr;
    }

    newSize = size + blockSize;
    int* newArray = new int[newSize];

    for (int i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < blockSize; ++i) {
        newArray[index + i] = block[i];
    }
    for (int i = index; i < size; ++i) {
        newArray[i + blockSize] = array[i];
    }

    return newArray;
}

int main() {
    int size = 5;
    int* array = new int[size] {1, 2, 3, 4, 5};
    int blockSize = 3;
    int* block = new int[blockSize] {10, 20, 30};

    int index = 2;
    int newSize;
    int* updatedArray = insertBlock(array, size, block, blockSize, index, newSize);

    if (updatedArray) {
        cout << "Updated array: ";
        for (int i = 0; i < newSize; ++i) {
            cout << updatedArray[i] << " ";
        }
        cout << endl;
    }

    delete[] array;
    delete[] block;
    delete[] updatedArray;

    return 0;
}
