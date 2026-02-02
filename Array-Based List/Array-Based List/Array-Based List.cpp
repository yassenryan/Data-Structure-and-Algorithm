#include <iostream>
using namespace std;

template <class t>

class Arraybased {
	int* arr;
	int length;
	int maxsize;
public:
	Arraybased(int newsize) {
		if (newsize < 0)
			maxsize = 10;
		else
			maxsize = newsize;
		arr = new int[maxsize];
		length = 0;
	}

	bool isemp() {
		return(length == 0);
	}

	bool isfull() {
		return(length == maxsize);
	}
	int getsize() {
		return length;
	}

	void print() {
		for (size_t i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void insertat(int pos, t newitem) {
		if (isfull())
			cout << "Array is already full" << endl;
		else if (pos<0 || pos>length)
			cout << "Out of range" << endl;
		else
		{
			for (int i = length; i > pos; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[pos] = newitem;
			length++;
		}
	}

	void insertend(t newitem) {
		if (isfull())
			cout << "Array is already full" << endl;
		else {
			arr[length] = newitem;
			length++;
		}
	}

	void Deleteat(int pos) {
		if (isemp())
			cout << "Array is already empty" << endl;
		else if (pos < 0 || pos >= length)
			cout << "Out of range" << endl;
		else
		{
			for (int i = pos; i < length - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			length--;
		}
	}

	int search(t item)
	{
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == item)
				return i;
		}

		return-1;

	}

	void insertnoduplicate(t newitem) {
		if (search(newitem) == -1)
			insertend(newitem);

		else
			cout << "This item is already here" << endl;
	}

	void updateat(int pos, t newitem)
	{
		if (pos < 0 || pos >= length)
			cout << "Out of range" << endl;
		else
			arr[pos] = newitem;
	}

	t getvalat(int pos)
	{
		return arr[pos];
	}




};

int main()
{
	Arraybased <int> a(6);
	a.insertat(0, 10);
	a.insertend(20);
	a.insertend(30);
	a.insertend(40);
	a.insertend(50);
	a.insertend(60);
	a.print();

	a.insertend(70);
	a.print();
	a.Deleteat(2);
	a.insertend(70);
	a.print();
	a.insertnoduplicate(20);

}

