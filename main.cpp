#include <iostream>
using namespace std;

void distributeElements(int* arr, int size, int*& positiveArr, int& positiveSize, int*& negativeArr, int& negativeSize, int*& zeroArr, int& zeroSize) {
    positiveSize = negativeSize = zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            ++positiveSize;
        }
        else if (arr[i] < 0) {
            ++negativeSize;
        }
        else {
            ++zeroSize;
        }
    }

    positiveArr = new int[positiveSize];
    negativeArr = new int[negativeSize];
    zeroArr = new int[zeroSize];

    int p = 0, n = 0, z = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveArr[p++] = arr[i];
        }
        else if (arr[i] < 0) {
            negativeArr[n++] = arr[i];
        }
        else {
            zeroArr[z++] = arr[i];
        }
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, -2, 0, 4, -5, 6, 0, -3 };
    int size = 8;

    int* positiveArr = nullptr;
    int* negativeArr = nullptr;
    int* zeroArr = nullptr;

    int positiveSize, negativeSize, zeroSize;

    distributeElements(arr, size, positiveArr, positiveSize, negativeArr, negativeSize, zeroArr, zeroSize);

    cout << "Positive elements: ";
    printArray(positiveArr, positiveSize);

    cout << "Negative elements: ";
    printArray(negativeArr, negativeSize);

    cout << "Zero elements: ";
    printArray(zeroArr, zeroSize);

    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;

    return 0;
}
