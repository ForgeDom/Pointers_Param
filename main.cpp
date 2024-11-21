#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            ++newSize;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newArr[j++] = arr[i];
        }
    }

    delete[] arr;
    size = newSize;
    return newArr;
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int* arr = new int[6] {2, 3, 4, 5, 6, 7};
    int size = 6;

    cout << "Original array: ";
    printArray(arr, size);

    arr = removePrimes(arr, size);

    cout << "Array after removing primes: ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}
