#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
	int key;
	int val;
	Node *prev;
	Node *next;
};

Node *GetNewNode(int k, int v) {
	Node *new_node = new Node;
	new_node->key = k;
	new_node->val = v;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

class DLL {
	private:
		Node *head;

	public:
		DLL() { head = NULL; }
		~DLL() { }
		void AddAtHead(Node *node);
		Node *Remove(Node *node);
		void RemoveDelete(Node *node);
		Node *GetHead() { return head; }
		Node *GetTail() { return head ? head->prev : NULL; }
		void PrintList();
};

void DLL::AddAtHead(Node *node) {
	if (!head) {
		head = node;
		node->prev = node;
		node->next = node;
		return;
	}
	node->next = head;
	node->prev = head->prev;
	head->prev = node;
	node->prev->next = node;
	head = node;
}

Node *DLL::Remove(Node *node) {
	if (head == node) {
		if (head->next == head) {
			head = NULL;
			return node;
		} else {
			Node *prev_head = head;
			head = head->next;
			return Remove(prev_head);
		}
	}
	Node *prev = node->prev;
	Node *next = node->next;
	prev->next = next;
	next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void DLL::RemoveDelete(Node *node) {
	Remove(node);
	delete node;
}

void DLL::PrintList() {
	Node *itr = head;
	if (!itr) {
		return;
	}
	cout << "---" << endl;
	do {
		cout << itr->key << " " << itr->val << endl;
		itr = itr->next;
	} while (itr != head);
	cout << "---" << endl;
}

class MyCache {
	protected:
		unordered_map <int, Node *> key_node_map;
		DLL cache_list;
		int capacity;
		int size;
	public:
		int Get(int key);
		void Set(int key, int val);
		void Remove(int key);
		Node *GetMyCacheListTail() { return cache_list.GetTail(); }
		virtual void evict() = 0;
		void PrintContents();
};

void MyCache::PrintContents() {
	cache_list.PrintList();
}

void MyCache::Set(int key, int val) {
	Node *node = GetNewNode(key, val);
	if (size == capacity) {
		evict();
	}
	cache_list.AddAtHead(node);
	key_node_map[key] = node;
	size++;
}

int MyCache::Get(int key) {
	Node *node = key_node_map[key];
	if (!node) {
		return -1;
	}
	node = cache_list.Remove(node);
	cache_list.AddAtHead(node);
	return node->val;	
}

void MyCache::Remove(int key) {
	Node *node = key_node_map[key];
	if (!node) {
		return;
	}
	cache_list.RemoveDelete(node);
	key_node_map.erase(key);
	size--;
}

class MyLRU:public MyCache {
	public:
		MyLRU(int cache_size) {
			capacity = cache_size;
			size = 0;
		}
		~MyLRU() {}
		void evict();
};

void MyLRU::evict() {
	Node *node = GetMyCacheListTail();
	if (!node) {
		//Scream
	};
	Remove(node->key);
}

int main() {
	MyLRU lru(4);
	lru.Set(2, 4);
	lru.PrintContents();
	lru.Set(3, 6);
	lru.PrintContents();
	lru.Set(4, 8);
	lru.PrintContents();
	lru.Set(5, 10);
	lru.PrintContents();

	cout << lru.Get(2) << endl;
	cout << lru.Get(3) << endl;
	cout << lru.Get(4) << endl;
	lru.Set(6, 12);
	lru.PrintContents();
	lru.Set(7, 14);
	lru.PrintContents();
	lru.Set(8, 16);
	lru.PrintContents();
	lru.Set(9, 19);
	lru.PrintContents();

	cout << lru.Get(5) << endl;

	lru.Remove(9);
	lru.PrintContents();
	lru.Remove(7);
	lru.PrintContents();
	lru.Remove(6);
	lru.PrintContents();
	lru.Remove(8);
	lru.PrintContents();
	return 0;
}
