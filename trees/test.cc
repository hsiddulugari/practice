#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
struct Node {
	int val;
	vector <Node *> children;
};

Node *GetNode(int val)
{
	Node *node = new Node;
	node->val = val;
	node->children.clear();
	return node;
}

void MakeChild(Node *root, Node *child)
{
	if (!root) {
		return;
	}

	root->children.push_back(child);
}

*/

struct Node {
	int val;
	Node *left;
	Node *right;
};

Node *GetNode(int val)
{
	Node *node = new Node;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void MakeChild(Node *root, Node *left, Node *right)
{
	if (!root) {
		return;
	}

	root->left = left;
	root->right = right;
}

/*
void DFT(Node *head)
{
	stack <Node *> s;
	Node *temp;

	s.push(head);
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		cout << temp->val << " ";
		for (auto child:temp->children) {
			s.push(child);
		}
	}
}

void LOT(Node *head)
{
	queue <Node *> q;
	Node *temp;

	q.push(head);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		for (auto child:temp->children) {
			q.push(child);
		}
	}
}
*/

Node *DCA(Node *root, Node *node_A, Node *node_B)
           {
             if (!root) {
               return NULL;
             }


             if (root == node_A || root == node_B) {
		     return root;
             }

             Node *left = DCA(root->left, node_A, node_B);
             Node *right = DCA(root->right, node_A, node_B);

	     if (left && right) {
		     return root;
	     }

	     return (left != NULL) ? left : right;
}

/*
Node *DeepCopy(Node *head)
{

  if (!head) {
    return NULL;
  }
  Node *copyHeadMain = GetNode(head->val);
  Node *copyHead = copyHeadMain;
  queue <Node *> q;
  queue <Node *> copyq;
  Node *temp;
  Node *copyTemp;

  q.push(head);
  copyq.push(copyHead);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    copyTemp = copyq.front();
    copyq.pop();

    for (auto child: temp->children) {
      Node *copyChild = GetNode(child->val);
      copyTemp->children.push_back(copyChild);
      q.push(child);
      copyq.push(copyChild);
    }
  }
    return copyHeadMain;
}
*/


int
main()
{
	Node *head = GetNode(10);
	Node *node1 = GetNode(20);
	Node *node2 = GetNode(30);
	Node *node3 = GetNode(40);
	Node *node4 = GetNode(50);
	Node *node5 = GetNode(60);
	Node *node6 = GetNode(70);

	//MakeChild(head, node1);
	//MakeChild(head, node2);

	//MakeChild(node1, node3);
	//MakeChild(node1, node4);
	MakeChild(head, node1, node2);
	MakeChild(node1, node3, node4);

	Node *dst = DCA(head, node5, node6);
	cout << dst->val << endl;

//	LOT(head);
	cout << endl;
//	DFT(head);
	cout << endl;

//	Node *copy = DeepCopy(head);
//	LOT(copy);

	// Delete nodes
	return 0;
}
