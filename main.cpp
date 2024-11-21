#include <iostream>
using namespace std;

void countElements(int* array, int size, int* negativeCount, int* positiveCount, int* zeroCount) {
    *negativeCount = 0;
    *positiveCount = 0;
    *zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            (*negativeCount)++;
        }
        else if (array[i] > 0) {
            (*positiveCount)++;
        }
        else {
            (*zeroCount)++;
        }
    }
}

int main() {
    int arr[] = { 0, -1, 5, 0, -3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int negativeCount = 0;
    int positiveCount = 0;
    int zeroCount = 0;

    countElements(arr, size, &negativeCount, &positiveCount, &zeroCount);

    cout << "Amount of negative elements: " << negativeCount << endl;
    cout << "Amount of positive elements: " << positiveCount << endl;
    cout << "Amount of null elements: " << zeroCount << endl;

    return 0;
}
