#include <iostream>
#include <algorithm>
using namespace std;

void SelectionSort(int arr[], int n) {

	int minidx;


	for (int i = 0; i < n - 1; i++) {
		minidx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				
				minidx = j;
				swap(arr[minidx], arr[i]);

			}
		}
	}
}

void print(int arr[],int n)
{
	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;

}











int main()
{
	int arr[] = { 60,40,50,30,10,20 };
	int size = sizeof(arr) / sizeof arr[0];
	SelectionSort(arr, size);
	cout << "After sort" << endl;
	print(arr, size);
}