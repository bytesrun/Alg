#include "testheap.h"
#include "InitNums.h"
#include <vector>
#include <iostream>
using namespace std;

int left(int i) {
	int tmp = i << 1;
	return tmp + 1;
}

int right(int i) {
	return left(i) + 1;
}

void maxHeapify(vector<int>& nums, int i, int sz) {
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

void buildMaxHeap(vector<int>& nums) {
	int n = nums.size();
	int id = n / 2 - 1;
	if (id < 0) return;
	for (int i = id; i >= 0; --i) {
		maxHeapify(nums, i, n);
	}
}

void HeapSort(vector<int>& nums) {
	buildMaxHeap(nums);
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		swap(nums[0], nums[n - i - 1]);
		maxHeapify(nums, 0, n - i - 1);
	}
}

void TestHeap() {
	cout << endl;
	cout << "---TestHeap START---" << endl;
	vector<int> nums(InitNums(10, -5, 7));
	cout << "Before processing: " << endl;
	printNums(nums);
	buildMaxHeap(nums);
	printNums(nums);
	HeapSort(nums);	
	cout << "After processing: " << endl;
	printNums(nums);
	cout << "---TestHeap END---" << endl;
}

