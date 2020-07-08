#include <iostream>
#include <vector>
#include <exception>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include "InitNums.h"
#include "mystack.h"
#include "myqueue.h"
#include "mylist.h"

using namespace std;
void testMyStack() {
	cout << "---TestMyStack START---" << endl;
	//0:push 1:top 2:pop
	MyStack<int> st;
	
	for (int i = 0; i < 10; ++i) {
		cout << "Test: " << i << endl;
		int opd = 0;
		if (i > 3) opd = getRandomInt() % 3;	
		int e = getRandomInt();
		st.print();
		try {
			//cout << "opd: " << opd << " ";
			switch (opd) {
				case 0:
					cout << "push: " << e << endl;
					st.push(e);
					break;
				case 1:
					cout << "top: " << st.top() << endl;
					break;
				
				case 2:
					cout << "pop: " << endl;
					st.pop();
					break;				
			}
		} catch (const exception& ep) {
			cout << ep.what() << " ";
		}
		st.print();
		cout << endl;
	}
	cout << "---TestMyStack END---" << endl << endl;
}

void testMyQueue() {
	cout << "---TestMyQueue START---" << endl;
	MyQueue<int> q;
	//0: push 1:front 2: pop
	int opd = 0;
	for (int i = 0; i < 10; ++i) {
		cout << "Test " << i << endl;
		q.print();
		opd = 0;		
		if (i > 3) {
			opd = getRandomInt() % 3;
		}
		//cout << "opd: " << opd << endl;		
		int e = getRandomInt();
		switch (opd) {
			case 0:		
				cout << "push: " << e << endl;
				q.push(e);
				break;
			case 1:
				cout << "front: " << q.front() << endl;
				break;
			case 2:
				cout << "pop" << endl;
				q.pop();
				break;
		}
		q.print();
		cout << endl;
	}
	cout << "---TestMyQueue END---" << endl << endl;
}


void testMyList() {
	cout << "---TestMyList START---" << endl;
	MyListNode dummy(-1);
	//0: insert element 1: insert pointer
	//2: del element 3: del pointer
	int opd = 0;
	int tmp = 0;
	unordered_map<int, MyListNode*> mp;
	vector<int> vals;
	for (int i = 0; i < 10; ++i) {
		tmp = getRandomInt();
		cout << "Test " << i << endl;
		printList(dummy.next);
		MyListNode *p = new MyListNode(tmp);
		//mp[tmp] = p;
		int id = 0;
		int key = 0;
		if (i < 5) {
			opd = getRandomInt() % 2;
		}
		else {
			//opd = getRandomInt() % 2 + 2;
			opd = getRandomInt() % 4;
		}
		cout << "opd: " <<  opd << endl;
		switch (opd) {
			case 0:
				cout << "insert element: " << p->val << endl;
				insertNode(&dummy, p->val);
				vals.push_back(p->val);				
				break;
			case 1:
				cout << "insert element: " << p->val << "pointer" << endl;
				mp[tmp] = p;
				vals.push_back(tmp);
				insertNode(&dummy, p);
				break;
			case 2:				
				key = vals.back();
				vals.pop_back();
				cout << "delete element: " << key << endl;				
				delNode(dummy.next, key);
				break;
			case 3:					
				key = vals.back();
				vals.pop_back();		
				if (mp.find(key)!= mp.end()) {
					cout << "delete element: " << key << " pointer" << endl;
					delNode(mp[key]);
					mp.erase(key);
				}
				else {
					cout << "delete element: " << key << endl;
					delNode(dummy.next, key);
				}				
				break;
		}
		sort(vals.begin(), vals.end());
		//vals.erase(unique(vals.begin(), vals.end()), vals.end());
		printList(dummy.next);
		cout << endl;
		//printNums(vals);
		
	}
	cout << "---TestMyList END---" << endl;
}