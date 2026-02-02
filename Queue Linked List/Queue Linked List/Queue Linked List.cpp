#include <cassert>
#include <iostream>
#include <cassert>
using namespace std;

template <class t>

class linkedqueue {

	struct Node {
		t Data;
		Node* Next;
	};

	Node* Front;
	Node* Rear;
	int length;
public:

	linkedqueue() {
		Front = Rear = NULL;
		length = 0;
	}

	bool isemp()// momken te3mlha bel lenght if lenght==0 return
	{
		return(Front == NULL && Rear == NULL);
	}


	void Enqueue(t val) {
		Node* newnode = new Node;
		newnode->Data = val;
		newnode->Next = NULL;
		if (isemp()) {
			Rear = Front = newnode;
		}
		else
		{
			Rear->Next = newnode;
			Rear = newnode;
		}
		length++;
	}

	void Dequeue() {

		if (isemp()) {
			cout << "Already empty" << endl;
			return;
		}

		Node* Temp = Front;

		if (Front == Rear) {
			Front = Rear = NULL;
		}

		else {
			Front = Front->Next;
		}

		delete Temp;
		length--;

	}

	t getFront() {
		assert(!isemp());
		return Front->Data;
	}
	t getRear() {
		assert(!isemp());
		return Rear->Data;
	}

	void clearall() {
		while (Front != NULL)
		{
			Dequeue();
		}
	}

	void Display()
	{
		if (isemp())
			cout << "Already empty";
		else {
			Node* Temp = Front;
			while (Temp != NULL)
			{
				cout << Temp->Data << " ";
				Temp = Temp->Next;
			}
			cout << endl;
		}


	}
};

int main()
{
	linkedqueue <int>q1;

	q1.Enqueue(10);
	q1.Enqueue(20);
	q1.Enqueue(30);
	q1.Enqueue(40);
	q1.Display();
	q1.Dequeue();
	q1.Display();
	q1.clearall();
	q1.Display();


}

