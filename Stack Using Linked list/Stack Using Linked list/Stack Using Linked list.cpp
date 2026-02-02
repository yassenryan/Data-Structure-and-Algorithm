#include <iostream>
using namespace std;
template <class t>
class stack {

    struct Node {
        t Data;
        Node* Next;
    };

    Node* Top;
public:
    stack() :Top(NULL) {}

    bool isemp() {
        return(Top == NULL);

    }

    void push(t item) {
        Node* newnode = new Node;
        newnode->Data = item;
        newnode->Next = Top;
        Top = newnode;

    }

    void pop() {
        if (isemp())
            cout << "Stack is empty" << endl;
        else
        {
            Node* Temp = Top;
            Top = Top->Next;
            Temp = Temp->Next = NULL;
            delete Temp;

        }

    }

    void pop(t& stacktop) {
        if (isemp())
            cout << "Stack is empty" << endl;
        else
        {
            Node* Temp = Top;
            Top = Top->Next;
            stacktop = Temp->Data;
            Temp = Temp->Next = NULL;
            delete Temp;

        }

    }

    void gettop(t& stacktop) {
        if (isemp())
            cout << "Stack is empty" << endl;
        else
        {
            stacktop = Top->Data;

        }

    }

    void display() {
        if (isemp())
            cout << "Stack is empty" << endl;
        else
        {
            Node* Temp = Top;
            while (Temp != NULL) {
                cout << Temp->Data << " ";
                Temp = Temp->Next;
            }
            cout << endl;
        }

    }

};


int main()
{

    stack<int>s;

    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.display();
    int y = 0;
    s.gettop(y);
    cout << y << endl;

}
