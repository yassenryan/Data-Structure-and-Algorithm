#include <algorithm>
#include <iostream>
using namespace std;


void InsertionSort(int arr[], int size) {

	int key, j;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];

			j = j - 1;
		}

		arr[j + 1] = key;
	}
}


void print(int arr[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	int arr[] = { 80,90,60,40,30,50,20,10,100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertionSort(arr, size);
	print(arr, size);


}
