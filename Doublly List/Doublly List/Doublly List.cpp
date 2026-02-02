#include <iostream>
using namespace std;

template <class t>

class doublylist {

public:
    struct Node {
        t data;
        Node* next;
        Node* prev;
    };

    int length = 0;
    Node* first;
    Node* last;

    doublylist() {
        length = 0;
        first = NULL;
        last = NULL;
    }

    bool isemp() {
        return(length == 0);
    }

    void insertfirst(t val) {
        Node* newnode = new Node;
        newnode->data = val;

        if (isemp())
        {
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else {
            newnode->next = first;
            first->prev = newnode;
            first = newnode;
            newnode->prev = NULL;
        }
        length++;
    }

    void insertlast(t val) {
        Node* newnode = new Node;
        newnode->data = val;

        if (isemp())
        {
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else {

            last->next = newnode;
            newnode->prev = last;
            newnode->next = NULL;
            last = newnode;

        }
        length++;
    }

    void insertat(int pos, t val) {
        if (pos<0 || pos>length)
            cout << "Out Of Range" << endl;
        else {
            if (isemp() || pos == 0)
                insertfirst(val);
            else if (pos == length)
                insertlast(val);
            else {
                Node* curr = first;
                Node* newnode = new Node;
                newnode->data = val;
                for (int i = 1; i < pos; i++) {
                    curr = curr->next;
                }
                Node* Temp = curr->next;
                newnode->prev = curr;
                newnode->next = Temp;
                curr->next = newnode;
                Temp->prev = newnode;
                length++;
            }
        }
    }

    void removefirst() {
        if (isemp())
            cout << "Already empty" << endl;
        else {
            if (length == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                Node* curr = first;
                first = first->next;
                first->prev = NULL;
                delete curr;
            }
            length--;
        }
    }

    void removelast() {
        if (isemp())
            cout << "Already empty" << endl;
        else {
            if (length == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                Node* curr = last;
                last = last->prev;
                last->next = NULL;
                delete curr;
            }
            length--;
        }
    }

    void removethe(t val) {
        if (isemp())
            cout << "already empty" << endl;
        else if (first->data == val)
            removefirst();
        else if (last->data == val)
            removelast();
        else {
            Node* curr = first;

            while (curr != NULL && curr->data != val)
            {
                curr = curr->next;
            }
            if (curr == NULL)
                cout << "Item isn't here" << endl;
            else {
                Node* curprev = curr->prev;
                Node* curnext = curr->next;

                curnext->prev = curprev;
                curprev->next = curnext;
                delete curr;
                length--;
            }
        }
    }

    void display() {
        Node* Temp = first;

        while (Temp != NULL) {
            cout << Temp->data << " ";
            Temp = Temp->next;
        }
        cout << endl;

    }


    void reversdisplay() {
        Node* Temp = last;

        while (Temp != NULL) {
            cout << Temp->data << " ";
            Temp = Temp->prev;
        }
        cout << endl;

    }


};


int main()
{
    doublylist <int>d;
    d.insertfirst(10);
    d.insertlast(20);
    d.insertlast(30);
    d.insertlast(40);
    d.insertlast(50);
    d.display();
    d.reversdisplay();
    d.insertat(1, 15);
    d.display();
    d.removefirst();
    d.display();
    d.removelast();
    d.display();
    d.removethe(16);
    d.removethe(20);
    d.display();





}
