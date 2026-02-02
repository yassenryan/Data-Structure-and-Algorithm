#include <iostream>
using namespace std;

class Node {
public:
	int Data;
	Node* Right;
	Node* Left;

	Node(int item) {
		Right = Left = NULL;
		Data = item;
	}
};


class BST {
public:
	Node* Root;

	BST() {
		Root = NULL;
	}

	Node* Insert(Node* r,int item) {

		if (r == NULL) {
			Node* newnode = new Node(item);
			r = newnode;
		}

		else if (item < r->Data) {
			r->Left = Insert(r->Left, item);
		}
		else {
			r->Right = Insert(r->Right, item);
		}
		return r;
	}

	void Insert(int item) {
		Root = Insert(Root, item);
	}

	void Preorder(Node* r)//root left right
	{
		if (r == NULL)
			return;
		else
		{
			cout << r->Data << "  ";
			Preorder(r->Left);
			Preorder(r->Right);
		}
	}

	void Inorder(Node* r)//left root right
	{
		if (r == NULL)
			return;
		else
		{

			Inorder(r->Left);
			cout << r->Data << "  ";
			Inorder(r->Right);

		}
	}

	void Postorder(Node* r)//left right roor
	{
		if (r == NULL)
			return;
		else
		{

			Postorder(r->Left);
			Postorder(r->Right);
			cout << r->Data << "  ";
		}
	}

	Node* Search(Node* r, int key) {
		if (r == NULL) {
			return r;
		}
		else if (key == r->Data) {
			return r;
		}
		else if (key < r->Data)
		{
		return	Search(r->Left, key);
		}
		else if (key > r->Data) {
		return	Search(r->Right, key);
		}



	}

	bool Search(int key) {
		Node* Result = Search(Root, key);

		if (Result == NULL)
		{
			return false;
		}
		else
			return true;

	}

	Node* Findmin(Node* r) {
		if (r == NULL)
			return NULL;
		else if (r->Left == NULL)
			return r;
		else
		return Findmin(r->Left);
	}

	Node* Findmax(Node* r) {
		if (r == NULL)
			return NULL;
		else if (r->Right == NULL)
			return r;
		else
			return Findmax(r->Right);
	}

	Node* Delete(Node* r, int key) {
		if (r == NULL)
			return NULL;
		if (key < r->Data)
			r->Left = Delete(r->Left, key);
		else if (key > r->Data)
			r->Right = Delete(r->Right, key);
		else
		{
			if (r->Left == NULL && r->Right == NULL)
				r = NULL;
			else if (r->Left != NULL && r->Right == NULL)//one child onz left
			{
				r->Data = r->Left->Data;
				delete r->Left;
				r->Left = NULL; 
			}
			else if (r->Left == NULL && r->Right != NULL)
			{
				r->Data = r->Right->Data;
				delete r->Right;
				r->Right = NULL;
			}
			else
			{
				Node* max = Findmax(r->Left);
				r->Data = max->Data;
				r->Left = Delete(r->Left, max->Data); 
			

			}
		}

		return r;
	}

};


int main()
{
	BST btree;
	btree.Insert(45);
	btree.Insert(15);
	btree.Insert(79);
	btree.Insert(90);
	btree.Insert(10);
	btree.Insert(55);
	btree.Insert(12);
	btree.Insert(20);
	btree.Insert(50);

	cout << " Display the Tree Contenet \n";
	btree.Preorder(btree.Root);
	/*cout << "\n..............................................................................\n";
	btree.Inorder(btree.Root);
	cout << "\n..............................................................................\n";
	btree.Postorder(btree.Root);
	cout << "\n..............................................................................\n";*/

	/*cout << "ENter item to search for" << endl;
	int key;
	cin >> key;
	if (btree.Search(key))
		cout << "Item found" << endl;
	else
		cout << "Item not found" << endl;*/
	/*Node* max = btree.Findmax(btree.Root);
	if (max == 0)
		cout << "Tree is Empty" << endl;
	else
		cout << "The maximum item in the tree = " << max->Data << endl;

	Node* min = btree.Findmin(btree.Root);
	if (min == 0)
		cout << "Tree is Empty" << endl;
	else
		cout << "The minimum item in the tree = " << min->Data << endl;
	int item*/

	cout << "\nDelete items" << endl;
	Node* result = btree.Delete(btree.Root, 12);
	btree.Preorder(btree.Root);
	cout << endl;

	cout << "\nDelete items" << endl;
	result = btree.Delete(btree.Root, 15);
	btree.Preorder(btree.Root);
}
