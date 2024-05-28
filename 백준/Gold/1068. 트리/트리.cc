#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

typedef struct node
{
	vector<node*> childs;
	int data;
	int childCnt = 0;
	node* parent;
}Node;

void DFS(Node* root)
{
	for (int i = 0; i < root->childCnt; i++)
	{
		if (root->childs[i] != nullptr)
		{
			DFS(root->childs[i]);
		}
	}
	if (root->childCnt == 1 && root->childs[0] == nullptr)
	{
		ans++;
		return;
	}
	else if (root->childCnt == 0)
	{
		ans++;
	}
	
}

int main()
{
	vector<Node> Tree;
	Node* temp;

	int cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		temp = new Node;
		temp->data = i;
		Tree.push_back(*temp);
		delete temp;
	}

	int inputParent;
	Node* root = nullptr;
	for (int i = 0; i < cnt; i++)
	{
		cin >> inputParent;
		if (inputParent != -1)
		{
			Tree[i].parent = &Tree[inputParent];
			Tree[inputParent].childs.push_back(&Tree[i]);
			Tree[inputParent].childCnt++;
		}
		else
		{
			root = &Tree[i];
			Tree[i].parent = nullptr;
		}
	}

	int cuttingNode;
	Node* CuttedNode;
	Node* CuttedNodeParent;
	cin >> cuttingNode;

	CuttedNode = &Tree[cuttingNode];
	CuttedNodeParent = Tree[cuttingNode].parent;
	Tree[cuttingNode].parent = nullptr;

	
	if (&Tree[cuttingNode] != root)
	{
		for (int i = 0; i < CuttedNodeParent->childCnt; i++)
		{
			if (CuttedNodeParent->childs[i]->data == CuttedNode->data)
			{
				CuttedNodeParent->childs[i] = nullptr;
				break;
			}
		}

		DFS(root);
	}
	
	cout << ans;

	return 0;

}