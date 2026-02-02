#include <iostream>
#include <algorithm>
using namespace std;

void Bubblesort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        cout << arr[i] << " ";

    }
    cout << endl;
}

int main()
{
    int arr[] = { 100,20,10,30,50,60,70,80,40 };
    int size = sizeof(arr) / sizeof(arr[0]);

    Bubblesort(arr, size);
    print(arr, size);



}
