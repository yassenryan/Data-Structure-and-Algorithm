#include <iostream>
#include <algorithm> 
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;

}
int main() {

    int arr[] = { 1, 2, 3, 4, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, size, 9);

    if (result != -1) {
        cout << "Element " << 9 << " found at index: " << result << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    return 0;
}