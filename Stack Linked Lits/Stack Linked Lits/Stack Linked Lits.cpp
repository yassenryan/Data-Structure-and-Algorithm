#include <iostream>
using namespace std;

class Node {
public:
	int Data;
	Node* Next;
	Node() {
		Data = 0;
		Next = NULL;
	}
};

class Stack {

	Node* Top;
public:
	Stack() {
		Top = NULL;
	}

	bool isemp() {
		return(Top == NULL);
	}

	void Push(int item) {
		Node* newnode = new Node();
		newnode->Data = item;
		if (isemp()) {
			Top = newnode;
			newnode->Next = NULL;
		}
		else {
			newnode->Next = Top;
			Top = newnode;
		}

	}

	int Pop() {

		int val;

		Node* delptr = Top;
		val = Top->Data;
		Top = Top->Next;
		delete delptr;
		return val;
	}

	int Peak()
	{
		return Top->Data;
	}

	int count()
	{
		int counter = 0;
		Node* Temp = Top;
		while (Temp != NULL) {
			counter++;
			Temp = Temp->Next;
		}

		return counter;

	}

	void Display() {
		Node* Temp;
		Temp = Top;
		while (Temp != NULL)
		{
			cout << Temp->Data << " ";
			Temp = Temp->Next;
		}
		cout << endl;

	}

	bool isfound(int key) {
		bool found = false;
		Node* Temp = Top;

		while (Temp != NULL)
		{
			if (Temp->Data == key) {
				found = true;
			}

			Temp = Temp->Next;
		}
		return found;

	}

	bool isfull(int item) {
		Node* ptr = new Node();
		if (ptr == NULL) {
			cout << "Can't add a new item , already full" << endl;
		}
		else {
			Push(item);
		}
	}

};


int main()
{
	int item;
	Stack s1;
	for (int i = 0; i < 3; i++) {
		cout << "Enter item to push " << endl;
		cin >> item;
		s1.Push(item);
		s1.Display();
	}

	//	cout << s1.Pop() << " Was deleted from stack" << endl;
		//s1.Display();

		//cout << s1.Pop() << " Was deleted from stack" << endl;
		//s1.Display();
	cout << s1.count() << " Is the number of items in the stack" << endl;
	cout << "Enter the value u wanna search for" << endl;
	cin >> item;
	if (s1.isfound(item))
		cout << "Item was found" << endl;
	else
		cout << "Can't find item" << endl;


}
