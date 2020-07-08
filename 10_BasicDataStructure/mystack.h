#include <memory>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <memory>
using namespace std;

template <typename T, int N = 20>
class MyStack {
public:
	explicit MyStack(int n = N) : _ptr(new T[N], [](T *p) {
		if (p) delete[] p;
		//cout << "Shared_ptr Free" << endl;
	}) {}
	
	T top() {
		if (_top == -1) {
			throw underflow_error("Stack is empty");
		}
		
		return *(_ptr.get() + _top);
	}
	
	void pop() {
		if (_top == -1) {
			throw underflow_error("Stack is empty");
		}
		--_top;
	}
	
	void push(T e) {
		if (_top + 1 == N) {
			cout << "Stack is already full." << endl;
			return;
		}
		//*(_ptr.get() + (++top)) = e;
		*(_ptr.get() + (++_top)) = e;
	}
	
	void print() {
		if (_top == -1) {
			cout << "stack empty" << endl;
			return;
		}
		for (size_t i = 0; i <= _top; ++i) {
			cout << *(_ptr.get() + i) << " ";			
		}
		cout << endl;
	}
	
private:
	shared_ptr<T> _ptr;
	int _top = -1;
};