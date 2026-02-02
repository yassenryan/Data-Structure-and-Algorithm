#include <iostream>
#include <string>
using namespace std;
const int maxsize = 100;
template <class t>
class stack {
private:
    int top;
    t item[maxsize];

public:
    stack() :top(-1){}
    
    void push(t val) {
        if (top >= maxsize - 1)
            cout << "Can't add new item ,Stack is full" << endl;
        else {
            top++;
            item[top] = val;
        }
    }

    bool isemp() {
        return (top == -1);
    }

    void pop()
    {
        if (isemp())
            cout << "Stack is already empty" << endl;
        else
            top--;
    }

    void pop(t &val)
    {
        if (isemp())
            cout << "Stack is already empty" << endl;
        else {
            val = item[top];
            top--;
        }
    }

    void gettop(t &stacktop)
    {
        if (isemp()) {
            cout << "Stack is already empty" << endl;
        }
        else {
            stacktop = item[top];
            cout << "Top element = " << stacktop << endl;
        }
    }

    void print() {
        cout << "[ ";
        for (int i = top; i >= 0; i--) {
            cout << item[i] << " ";
        }
        
        cout << " ]" << endl;
    }
};


int main()
{

    stack <char> s;
    s.push('d');
    s.push('s');
    s.push('f');
    s.push('y');
    s.pop();
    s.push('m');
    s.print();




}