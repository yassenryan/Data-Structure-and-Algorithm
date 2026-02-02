#include <iostream>
using namespace std;
#include <queue>
template <class t>
class linkedlist {
	struct Node {
		t Data;
		Node* Next;
	};
	Node* First;
	Node* Last;
	int length;
public:
	linkedlist()
	{
		First = Last = NULL;
		length = 0;
	}

	bool isemp() {
		return(length == 0);
	}

	void insertfirst(t val) {

		Node* newnode = new Node();
		newnode->Data = val;
		if (isemp()) {
			First = Last = newnode;
			newnode->Next = NULL;
		}
		else {
			newnode->Next = First;
			First = newnode;
		}
		length++;
	}

	void insertlast(t val) {

		Node* newnode = new Node();
		newnode->Data = val;
		if (isemp()) {
			First = Last = newnode;
			newnode->Next = NULL;
		}
		else {
			Last->Next = newnode;
			newnode->Next = NULL;
			Last = newnode;
		}
		length++;
	}

	void insertatpos(int pos, t val) {

		Node* newnode = new Node();
		newnode->Data = val;
		if (pos<0 || pos>length)
			cout << "Out Of Range" << endl;
		else if (isemp() || pos == 0)
			insertfirst(val);
		else if (pos == length)
			insertlast(val);
		else
		{
			Node* Temp = First;
			for (size_t i = 1; i < pos; i++)
			{
				Temp = Temp->Next;
			}
			newnode->Next = Temp->Next;
			Temp->Next = newnode;
			length++;
		}

	}

	void print() {
		if (isemp())
			cout << "List is empty" << endl;
		else
		{
			Node* Temp = First;
			while (Temp != NULL)
			{
				cout << Temp->Data << " ";
				Temp = Temp->Next;
			}
			cout << endl;


		}
	}

	void removefirst() {
		if (isemp())
			cout << "Already empty" << endl;
		else if (length == 1)
		{
			delete First;
			First = Last = NULL;
			length--;
		}
		else {
			Node* Temp = First;
			First = First->Next;
			delete Temp;
			length--;
		}
	}

	void removelast() {
		if (isemp())
			cout << "Already empty" << endl;
		else if (length == 1)
		{
			delete First;
			First = Last = NULL;
			length--;
		}
		else {
			Node* Temp = First->Next;
			Node* prevtemp = First;
			while (Temp != Last) {
				prevtemp = Temp;
				Temp = Temp->Next;
			}
			delete Temp;
			prevtemp->Next = NULL;
			Last = prevtemp;
			length--;
		}
	}

	void removethe(t val) {
		if (isemp())
			cout << "Already empty" << endl;
		else if (length == 1)
		{
			delete First;
			First = Last = NULL;
			length--;
		}
		else {
			Node* Temp = First->Next;
			Node* prevtemp = First;
			while (Temp->Data != val) {
				prevtemp = Temp;
				Temp = Temp->Next;
			}
			prevtemp->Next = Temp->Next;
			delete Temp;
			length--;
		}
	}


	void reverse() {
		if (isemp())
			cout << "List is empty" << endl;
		else if (length == 1)
			cout << First->Data << endl;
		else {
			Node* curr = First;
			Node* temp = curr->Next;//as next indicator
			Node* prev = NULL;

			while (temp != NULL) {
				temp = curr->Next;
				curr->Next = prev;
				prev = curr;
				curr = temp;
			}
			First = prev;


		}





	}



};

int main()
{
	linkedlist<int>l;
	l.insertfirst(15);
	l.insertatpos(1, 25);
	l.insertatpos(1, 35);
	l.insertlast(35);
	l.print();
	/*l.removefirst();
	l.print();
	l.removelast();
	l.print();
	l.insertfirst(80);
	l.print();
	l.removethe(35);
	l.print();
	*/l.reverse();
	l.print();
}
