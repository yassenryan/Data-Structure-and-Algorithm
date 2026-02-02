#include <iostream>
using namespace std;

void Merge(int arrA[], int sa, int arrB[], int sb, int arrC[]) {

    int adex = 0;
    int bdex = 0;
    int cdex = 0;

    while (adex < sa && bdex < sb) {

        if (arrA[adex] < arrB[bdex]) {
            arrC[cdex++] = arrA[adex++];
        }
        else {
            arrC[cdex++] = arrB[bdex++];
        }

    }

    while (adex < sa) {
        arrC[cdex++] = arrA[adex++];
    }

    while (bdex < sb) {
        arrC[cdex++] = arrB[bdex++];
    }
}


int main()
{
    int arr1[] = { 4,8,9,2,1,3 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int key = 2;

    int arr2[] = { 5,7,11 };

    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int total = size1 + size2;

    int* arrT = new int[total];
    Merge(arr1, size1, arr2, size2, arrT);

    for (int i = 0; i < total; i++) {

        cout << arrT[i] << " ";

    }
}
