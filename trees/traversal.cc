#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct node_s
{
	int val;
	struct node_s *left;
	struct node_s *right;
} node_t;
	

void DFT(node_t * root) {
	if (!root) {
		return;
	}
	
	printf("%d\n", root->val);
	DFT(root->left);
	DFT(root->right);
}

void dftIter(node_t * root) {
	stack <node_t *> st;

	st.push(root);
	while (!st.empty()) {
		node_t *n = st.top();
		st.pop();

		if (n) {
			printf("%d\n", n->val);
		}
		st.push(n->right);
		st.push(n->left);
	}
}

void bftIter(node_t * root) {
	queue <node_t *> q;
	
	q.push(root);
	while (!q.empty()) {
		node_t *n = q.front();
		q.pop();

		if (n) {
			printf("%d\n", n->val);
		}
		q.push(n->left);
		q.push(n->right);
	}
}

void DFTPrint(node_t * root, int k) {
	if (!root) {
		return;
	}
	
	if (k == 1) {
		printf("%d\n", root->val);
	} else {
		DFTPrint(root->left, k - 1);
		DFTPrint(root->right, k - 1);
	}
}

// Segment trees
// Best for binary associative operations
If range within [l-r]
	return val in node
Else if range completely outside
	return 0
Else
	return sum(l) + sum(r)
		

// Binary index trees
2 rules
1 based index
1) Every value at power of 2 index should keep the sum of everything until that number
2) At every index, find the highest power of 2 value it is divisible by and make sure it has the sum of all the (highest power of 2 value) numbers before it

Sum(0-index): ans = 0
Follow the path from root -> index
If going right, ans += cur
If node reached, ans += cur

Sum(l-r)
	Sum(0-r) - Sum(0-l)

Update(index, delta (value before - new value))
Follow path from root->index
If going left, cur += delta
If node reached, cur += delta

// isBST
Don't just do in order - It doesn't work
Keep track of the last element while doing in order and see if you encounter a number smaller than prev
bool isBST(Node *root) {
	if (!root) {
		return true;
	}

	if (isBST(root->left) {
		if (maxSoFar < root->val) {
			maxSoFar = root->val;
			return isBST(root->right);
		}
	}
	return false;
}

// Interval trees
Given a bunch of intervals, find if [lo, hi] has overlap
1) Compare root
2) Recurse for left if left.max > x.lo
3) Else recurse for right if right.max > x.lo

//B Tree
//B+ Tree


int main() {
	return 0;
}
