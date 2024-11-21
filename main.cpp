#include <iostream>
using namespace std;

int* isSubset(int* A, int sizeA, int* B, int sizeB) {
    if (sizeB > sizeA) {
        return nullptr;
    }

    for (int i = 0; i <= sizeA - sizeB; ++i) {
        bool isMatch = true;
        for (int j = 0; j < sizeB; ++j) {
            if (A[i + j] != B[j]) {
                isMatch = false;
                break;
            }
        }
        if (isMatch) {
            return &A[i];
        }
    }

    return nullptr;
}

int main() {
    int A[] = { 1, 2, 3, 4, 5, 6 };
    int B[] = { 3, 4, 5 };

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    int* result = isSubset(A, sizeA, B, sizeB);

    if (result) {
        cout << "Array B is a subset of array A." << endl;
        cout << "Starting position of the subset: " << (result - A) << endl;
    }
    else {
        cout << "Array B is not a subset of array A." << endl;
    }

    return 0;
}
