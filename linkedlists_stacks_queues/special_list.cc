#include <iostream>

using namespace std;

typedef struct Node {
	struct Node *next;
	struct Node *arbit;
	int val;
} Node;

Node * GetNewNode()
{
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->arbit = NULL;
	return new_node;
}

Node * CopyNode(Node * node)
{
	Node *copy = GetNewNode();
	copy->val = node->val;
	return copy;
}

void PrintNodes(const Node *head)
{
	for (const Node *itr = head; itr; itr = itr->next) {
		cout << itr->val << " ";
		if (itr->arbit) {
	       		cout << itr->arbit->val;
		}
		cout << endl;
	}
}

Node * CloneList(Node *head)
{
	Node *orig;
	for (orig = head; orig; orig = orig->next->next) {
		Node *copy_node = CopyNode(orig);
		copy_node->next = orig->next;
		orig->next = copy_node;
	}
	cout << "-----" << endl;
	PrintNodes(head);

	for (orig = head; orig; orig = orig->next->next) {
		orig->next->arbit = orig->arbit ? orig->arbit->next : NULL;
	}
	cout << "-----" << endl;
	PrintNodes(head);

	Node *copy_head = head ? head->next : NULL;
	Node *copy;
	for (orig = head, copy = copy_head; copy->next; copy = copy->next, orig = orig->next) {
		orig->next = orig->next->next;
		copy->next = copy->next->next;
	}
	orig->next = NULL;

	cout << "-----" << endl;
	PrintNodes(copy_head);
	return copy_head;
}

Node * CreateList(int num) {
	Node *head = NULL;
	Node *t = NULL;
       	Node *prev = NULL;

	for (int i = 0; i < num; i++) {
		t = GetNewNode();
		cin >> t->val;
		if (!head) {
			head = t;
			prev = t;
		} else {
			prev->next = t;
			prev = t;
		}
	}

	Node *t1 = head;
	for (int i = 0; i < num; i++) {
		int arbit;
		cout << "Enter arbit location for " << t1->val << " ";
		cin >> arbit;
		Node *arbit_node = head;
		while (arbit_node) {
			if (arbit_node->val == arbit) {
				break;
			}
			arbit_node = arbit_node->next;
		}
		t1->arbit = arbit_node;
		t1 = t1->next;
	}

	return head;
}

void FreeList(Node *head)
{
	while (head) {
		Node *temp = head;
		head = head->next;
		delete(temp);
	}
}


int main()
{
	int num;

	cout << "Enter number of values: ";
	cin >> num;
	Node *head = CreateList(num);

	cout << "-----" << endl;
	PrintNodes(head);
	Node *copy = CloneList(head);
	cout << "-----" << endl;
	PrintNodes(copy);
		
	FreeList(head);
	FreeList(copy);
	return 0;
}
