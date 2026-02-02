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


class Queue {
public:
	Node* Front;
	Node* Rear;
	
	Queue() {
		Front = NULL;
		Rear = NULL;
	}

	bool isemp() {
		return(Front == NULL && Rear == NULL);
	}

	void Enqueue(int value) {
		Node* newnode = new Node;
		newnode->Data = value;

		if (isemp())
			Rear = Front = newnode;
		else
		{
			Rear->Next = newnode;
			Rear = newnode;
		}
	}

	int Dequeue()
	{
		int delval = -1;
		if (isemp())
			cout << "Queue is already empty" << endl;
		else if (Front == Rear) {
			delete Front;
			Front = Rear = NULL;
		}
		else {
			Node* delptr = Front;
			Front = Front->Next;
			delval = delptr->Data;
			delete delptr;
		}
		return delval;


	}

	void Display()
	{
		if (isemp())
			cout << "Queue is empty" << endl;
		else {
			Node* Temp = Front;
			while (Temp != NULL) {
				cout << Temp->Data << " ";
				Temp = Temp->Next;
			}
			cout << endl;
		}
	}

	int getfront()
	{
		return Front->Data;
	}

	int getrear()
	{
		return Rear->Data;
	}

	int count()
	{
		int counter = 0;
		Node* Temp = Front;

		while (Temp != NULL)
		{
			counter++;
			Temp = Temp->Next;
		}
		return counter;
	}
	
	bool isfound(int key)
	{
		Node* Temp = Front;
		bool found = false;
		while (Temp != NULL)
		{
		
			if (Temp->Data == key)
				found = true;
			Temp = Temp->Next;
		}
		return found;

	}

	void Clear()
	{
		while (!isemp())
		{
			Dequeue();
		}


	}

};



int main()
{
	int item;
	Queue q1;
	for (int i = 0; i < 3; i++) {
		cout << "Enter an item to add to the queue" << endl;
		cin >> item;
		q1.Enqueue(item);
		q1.Display();
	}

//	q1.Dequeue();
//	q1.Display();
	cout << "*********" << endl;
	q1.Clear();
	q1.Display();

}	
