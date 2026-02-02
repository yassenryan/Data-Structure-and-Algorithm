#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool arepair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;
    if (open == '[' && close == ']')
        return true;
    return false;
}

bool areBalanced(string exp) {

    stack<char>s;
    for (size_t i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty()|| !arepair(s.top(), exp[i]))
                return false;
            else {
                s.pop();
            }
        }
    }
    return s.empty();


}




int main()
{


    string exp;
    cout << "enter an expression" << endl;
    cin >> exp;
    if (areBalanced(exp))
        cout << "balanced" << endl;
    else
        cout << "Not balanced" << endl;
        
        
        
}
