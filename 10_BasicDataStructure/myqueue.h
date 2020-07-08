#include <iostream>
#include <memory>

using namespace std;
template <typename T, int N = 20>
class MyQueue {
public:
	MyQueue(int n = N) : _sz(n), _front(0), _tail(0), _ptr(new T[n], [](T* p){
		if(p) delete[] p;
		cout << "MyQueue Shared_ptr Free" << endl;
	}) {}
	bool empty() {
		return _front == _tail;
	}
	
	bool full() {
		return size() == N - 1;
	}
	
	int size() {
		return ((_tail - _front) + _sz) % _sz;
	}
	
	bool push(T e) {
		if (full()) {
			cout << "MyQueue is full" << endl;
			return false;
		}
		//cout << "MyQueue::push  " << e << endl;
		*(_ptr.get() + _tail) = e;
		_tail += 1;
		return true;
	}
	
	T front() {
		return *(_ptr.get() + _front);
	}
	
	bool pop() {
		if (_front == _tail) {
			cout << "MyQueue is empty()" << endl;
			return false;
		}
		_front = (_front + 1) % _sz;
		return true;
	}
	
	void print() {		
		//cout << "MyQueue::print  _front: " << _front << " _tail: " << _tail << endl;
		if (_front == _tail) {
			cout << "MyQueue is empty" << endl;
			return;
		}
		for (size_t i = _front; i != _tail; i = (i + 1) % _sz) {
			cout << *(_ptr.get() + i) << " ";
		}
		cout << endl;
	}
	
private:
	int _sz;
	shared_ptr<T> _ptr;
	int _front;
	int _tail;
};