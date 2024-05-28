#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	char data;
	node* leftChild;
	node* rightChild;
	node* parent;
}Node;

void PreOrder(Node* root)
{
	cout << root->data;

	if (root->leftChild != nullptr)
	{
		PreOrder(root->leftChild);
	}
	if (root->rightChild != nullptr)
	{
		PreOrder(root->rightChild);
	}
	
}

void InOrder(Node* root)
{
	if (root->leftChild != nullptr)
	{
		InOrder(root->leftChild);
	}
	cout << root->data;
	if (root->rightChild != nullptr)
	{
		InOrder(root->rightChild);
	}

}

void PostOrder(Node* root)
{
	if (root->leftChild != nullptr)
	{
		PostOrder(root->leftChild);
	}
	if (root->rightChild != nullptr)
	{
		PostOrder(root->rightChild);
	}
	cout << root->data;
}

int main()
{
	vector<Node> Tree;
	Node A;
	A.data = 'A';
	Tree.push_back(A);

	Node* temp;

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		temp = new Node;
		temp->data = 'B' + i;
		Tree.push_back(*temp);
		delete temp;
	}

	char input_parent;
	char input_child1;
	char input_child2;

	for (int i = 0; i < cnt; i++)
	{
		cin >> input_parent;
		cin >> input_child1;
		input_parent = input_parent - 'A';

		if (input_child1 != '.')
		{
			input_child1 = input_child1 - 'A';
			Tree[input_parent].leftChild = &Tree[input_child1];
			Tree[input_child1].parent = &Tree[input_parent];
		}
		else
		{
			Tree[input_parent].leftChild = nullptr;
		}

		cin >> input_child2;
		
		if (input_child2 != '.')
		{
			input_child2 = input_child2 - 'A';
			Tree[input_parent].rightChild = &Tree[input_child2];
			Tree[input_child2].parent = &Tree[input_parent];
		}
		else
		{
			Tree[input_parent].rightChild = nullptr;
		}
	}
	
	PreOrder(&Tree[0]);
	cout << '\n';
	InOrder(&Tree[0]);
	cout << '\n';
	PostOrder(&Tree[0]);

	return 0;

}