#include <iostream>
using namespace std;

void calculateSumAndProduct(int* array, int size, int* sum, int* product) {
    *sum = 0;
    *product = 1;

    for (int i = 0; i < size; ++i) {
        *sum += array[i];
        *product *= array[i];
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    int product = 0;

    calculateSumAndProduct(arr, size, &sum, &product);

    cout << "Sum: " << sum << endl;
    cout << "Mult: " << product << endl;

    return 0;
}
