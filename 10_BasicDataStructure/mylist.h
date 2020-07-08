#include <iostream>
#include <memory>

struct MyListNode {
	MyListNode() : prev(nullptr), next(nullptr) {}
	MyListNode(int i) : val(i), prev(nullptr), next(nullptr) {}
	~MyListNode() {cout << "MyListNode::Destructor val: " << val << endl;}
	int val;
	MyListNode *prev;
	MyListNode *next;
};

MyListNode* insertNode(MyListNode* head, MyListNode *e) {
	if (!head) return e;
	e->prev = head;
	e->next = head->next;
	head->next = e;
	if(e->next) e->next->prev = e;
	return e;
}

MyListNode* insertNode(MyListNode* head, const int& e) {
	MyListNode *p = new MyListNode();
	p->val = e;
	//if(!head) return head;
	return insertNode(head, p);
}

void delNode(MyListNode *pD) {
	MyListNode *nxt = pD->next;
	if (nxt) nxt->prev = pD->prev;
	if (pD->prev) pD->prev->next = nxt;
	delete pD;
	pD = nullptr;
}

void delNode(MyListNode* head, int e) {
	if (!head) return;
	while (head != nullptr) {
		if (head->val == e) {
			break;
		}
		head = head->next;
	}
	delNode(head);
}

void printList(MyListNode* head) {
	if (!head) {
		cout << "MyList is empty" << endl;
		return;
	}
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
