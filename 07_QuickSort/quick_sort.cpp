#include <iostream>
#include <vector>
#include <utility>
#include "InitNums.h"
using namespace std;

int partition(vector<int>& nums, int st, int ed) {
	int x = nums[ed - 1];
	int i = st - 1;
	for (int j = st; j < ed - 1; ++j) {
		if (nums[j] <= x) {
			swap(nums[++i], nums[j]);
		}
	}
	swap(nums[++i], nums[ed - 1]);
	return i;
}

void quickSort(vector<int>& nums, int st, int ed) {
	if (st < ed) {
		int q = partition(nums, st, ed);
		quickSort(nums, st, q);
		quickSort(nums, q + 1, ed);
	}
}
//int randomizedPartition(vector<int>& nums, int st, int ed);
//void randomizedQuickSort(vector<int>& nums, int st, int ed);
void testQuickSort() {
	cout << "---TestQuickSort START---" << endl;
	for (int i = 0; i < 5; ++i) {
		vector<int> nums(InitNums(10, -5, 10));
		cout << "Test " << i << " :" << endl;		
		printNums(nums);
		quickSort(nums, 0, nums.size());
		printNums(nums)	;	
		cout << endl;
	}
	cout <<"---TestQuickSort END---" << endl;
}

int randomizedPartition(vector<int>& nums, int st, int ed) {
	int id = getRandomInt(st, ed - 1);
	int x = nums[id];
	swap(nums[id], nums[ed - 1]);
	int i = st - 1;
	for (int j = st; j < ed - 1; ++j) {
		if (nums[j] <= x) {
			swap(nums[++i], nums[j]);
		}
	}
	swap(nums[++i], nums[ed - 1]);
	return i;
}

void randomizedQuickSort(vector<int>& nums, int st, int ed) {
	if (st < ed) {
		int q = randomizedPartition(nums, st, ed);
		randomizedQuickSort(nums, st, q);
		randomizedQuickSort(nums, q + 1, ed);
	}
}


void testRandomizedQuickSort() {
	cout << "---RandomizedTestQuickSort START---" << endl;
	for (int i = 0; i < 5; ++i) {
		vector<int> nums(InitNums(10, -5, 10));
		cout << "Test " << i << " :" << endl;		
		printNums(nums);
		randomizedQuickSort(nums, 0, nums.size());
		printNums(nums)	;	
		cout << endl;
	}
	cout <<"---RandomizedTestQuickSort END---" << endl;
}