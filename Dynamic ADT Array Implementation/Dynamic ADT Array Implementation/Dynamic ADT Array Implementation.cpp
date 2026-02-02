#include <iostream>
using namespace std;

class Array {
private:
    int size;     
    int length;   
    int* items;   

public:
    Array(int arrsize) {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }

    ~Array() {
        delete[] items;
    }

    void Fill() {
        int noi;
        cout << "How many items you want to fill? ";
        cin >> noi;
        if (noi > size) {
            cout << "Error: Number of items exceeds array size!" << endl;
            return;
        }
        for (int i = 0; i < noi; i++) {
            cout << "Enter item " << i << ": ";
            cin >> items[i];
            length++;
        }
    }

    void Display() {
        cout << "[ ";
        for (int i = 0; i < length; i++) {
            cout << items[i] << (i == length - 1 ? "" : ", ");
        }
        cout << " ]" << endl;
    }

    void Append(int newitem) {
        if (length < size) {
            items[length++] = newitem;
        }
        else {
            cout << "Error: Array is full!" << endl;
        }
    }

    void Insert(int index, int newitem) {
        if (index < 0 || index > length || length >= size) {
            cout << "Error: Invalid index or array full!" << endl;
            return;
        }
        for (int i = length; i > index; i--) {
            items[i] = items[i - 1];
        }
        items[index] = newitem;
        length++;
    }

    void Delete(int index) {
        if (index >= 0 && index < length) {
            for (int i = index; i < length - 1; i++) {
                items[i] = items[i + 1];
            }
            length--;        }
        else {
            cout << "Error: Index out of range!" << endl;
        }
    }

    void Enlarge(int newsize) {
        if (newsize <= size) {
            cout << "Error: New size must be larger!" << endl;
            return;
        }
        int* old = items;
        items = new int[newsize];
        size = newsize;
        for (int i = 0; i < length; i++) {
            items[i] = old[i];
        }
        delete[] old; 
    }

    void Merge(Array& other) {
        int newsize = size + other.size;
        int* old = items;
        items = new int[newsize];

        for (int i = 0; i < length; i++) {
            items[i] = old[i];
        }

        for (int i = 0; i < other.length; i++) {
            items[length + i] = other.items[i];
        }

        length += other.length;
        size = newsize;
        delete[] old;
    }

    int Search(int key) {
        for (int i = 0; i < length; i++) {
            if (items[i] == key) return i;
        }
        return -1;
    }
};

int main() {
    Array a1(5);s
    a1.Append(10);
    a1.Append(20);
    a1.Append(30);

    cout << "Array 1: ";
    a1.Display();

    a1.Insert(1, 15);
    cout << "After inserting 15 at index 1: ";
    a1.Display();

    a1.Delete(2);
    cout << "After deleting item at index 2: ";
    a1.Display();

    return 0;
}