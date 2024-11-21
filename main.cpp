#include <iostream>
using namespace std;

void removeBlock(int arr[], int& size, int startIdx, int blockSize) {
    for (int i = startIdx; i < size - blockSize; ++i) {
        arr[i] = arr[i + blockSize];
    }
    size -= blockSize;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int size = 8;
    int startIdx = 2;
    int blockSize = 3;

    removeBlock(arr, size, startIdx, blockSize);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
