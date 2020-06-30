#include "testheap.h"
#include "InitNums.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int left(int i) {
	int tmp = i << 1;
	return tmp + 1;
}

int right(int i) {
	return left(i) + 1;
}

template <typename T>
void maxHeapify(vector<T>& nums, int i, int sz) {
	if (i >= sz) return;
	int subL = left(i);
	int maxId = i;
	if (subL < sz && nums[maxId] < nums[subL]) {
		maxId = subL;
	}
	int subR = right(i);
	if (subR < sz && nums[maxId] < nums[subR]) {
		maxId = subR;
	}
	if (i == maxId) return;
	swap(nums[i], nums[maxId]);
	maxHeapify(nums, maxId, sz);
}

template <typename T>
void buildMaxHeap(vector<T>& nums) {
	int n = nums.size();
	int id = n / 2 - 1;
	if (id < 0) return;
	for (int i = id; i >= 0; --i) {
		maxHeapify(nums, i, n);
	}
}

template <typename T>
void HeapSort(vector<T>& nums) {
	buildMaxHeap(nums);
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		swap(nums[0], nums[n - i - 1]);
		maxHeapify(nums, 0, n - i - 1);
	}
}

void TestHeapSort() {
	cout << endl;
	cout << "---TestHeap START---" << endl;
	vector<int> nums(InitNums(10, -5, 7));
	cout << "Before processing: " << endl;
	printNums(nums);
	//buildMaxHeap(nums);
	//printNums(nums);
	HeapSort(nums);	
	cout << "After processing: " << endl;
	printNums(nums);
	cout << "---TestHeap END---" << endl;
}

template <typename T>
class MyPriorityQueue {
	public:
		bool empty() {
			return _data.empty();
		}
		
		//push
		bool insert(T val) {			
			auto it = find(_data.begin(), _data.end(), val);
			if (it != _data.end()) return false;
			//for (auto x : _data) {
			//	if (x == val) return false;
			//}			
			_data.push_back(val - 1);
			increase_key(_data.size() - 1, val);
			return true;
		}
		
		//top
		T maximum() {
			return _data[0];
		}
		
		//top & pop
		T extract_max() {
			swap(_data[0], _data.back());
			T tmp = _data.back();
			_data.pop_back();
			maxHeapify(_data, 0, _data.size());
			return tmp;
		}
		
	private:	
		bool increase_key(int pos, T newVal) {
			if (newVal < _data[pos]) return false;
			_data[pos] = newVal;
			int sz = _data.size();
			while (pos > 0) {
				int parent = (pos - 1) / 2;
				if (_data[pos] > _data[parent]) {
					swap(_data[pos], _data[parent]);
				}
				pos = parent;
				parent = (pos - 1) / 2;
			}
			return true;
		}
	private:
		vector<T> _data;
};

void TestPriorityQueue(){
	cout << "---Test Priority Queue START---" << endl;
	vector<int> nums(InitNums(10, -50, 50));
	MyPriorityQueue<int> q;
	for (int i = 0; i < 10; ++i)
	{
		cout << "Input nums: " << endl;
		copy(nums.begin(), nums.begin() + i + 1, ostream_iterator<int>(cout, " "));
		q.insert(nums[i]);
		
		if (i % 3 == 1){
			cout << "Extract_Max: " << q.extract_max() << endl << endl;
		}
		else {
			cout << "Max: " << q.maximum() << endl << endl;
		}
		
		
	}	
}
