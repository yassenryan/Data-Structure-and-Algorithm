#include <iostream>
using namespace std;
#include <cassert>

class arrayqueuetype {

	int rear;

	int front;

	int length;

	int* arr;

int maxsize; public:

	arrayqueuetype(int size) {

		maxsize = size;

		rear = maxsize - 1;



		arr = new int[size];

		front = 0;

		length = 0;

	}


	void enqueue(int item) {

		if (isfull())

			cout << "Can't enqueue already full" << endl;

		else {

			rear = (rear + 1) % maxsize;

			arr[rear] = item;

			length++;

		}

	}


	bool isemp() {

		return(length == 0);

	}


	bool isfull() {

		return(length == maxsize);

	}


	void delqueue() {

		if (isemp())

			cout << "already empty" << endl;

		else {

			front = (front + 1) % maxsize;

			--length;

		}

	}


	int getfront() {

		assert(!isemp());

		return arr[front];

	}


	int getrear() {

		assert(!isemp());

		return arr[rear];

	}


	void display() {

		if (isemp())

			cout << "Already empty" << endl;

		else {

			int cur = front;

			for (int i = 0; i < length; i++)

			{

				cout << arr[cur] << " ";

				cur = (cur + 1) % maxsize;

			}

			cout << endl;


		}


	}

};



int main() {

	arrayqueuetype q(10);

	q.enqueue(10);

	q.enqueue(20);

	q.enqueue(30);

	q.enqueue(40);

	q.enqueue(50);

	q.enqueue(60);

	q.enqueue(70);

	q.enqueue(80);

	q.enqueue(90);

	q.enqueue(100);

	q.enqueue(110);

	q.enqueue(120);

	q.display();


}