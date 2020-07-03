#include "InitNums.h"
#include <vector>
#include <iostream>
#include <algorithm>
//#include <map>
#include <unordered_map>
#include <list>
using namespace std;

void countSort(vector<int>& nums, int iMin, int iMax) {
	int n = iMax - iMin + 1;
	vector<int> cnts(n, 0);
	for (auto &x : nums) {
		cnts[x - iMin]++;
	}
	int k = 0;
	for (int i = iMin; i <= iMax; ++i) {
		if (cnts[i - iMin] == 0) continue;
		fill_n(nums.begin() + k, cnts[i - iMin], i);
		k += cnts[i - iMin];
	}
}
void radixSort(vector<int>& nums, int digits) {
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < digits; ++i) {
		for (auto& y : nums) {
			int x = y;
			for (int j = 0; j < i; ++j) {
				x = x / 10;
			}
			x = x % 10;
			mp[x].push_back(y);
		}
		int k = 0;
		for (int m = 0; m <= 9; ++m) {
			for (auto x : mp[m]) {
				nums[k++] = x;
			}
		}
		mp.clear();
	}
}
void bucketSort(vector<double>& nums) {
	int n = nums.size();
	vector<list<double>> bucket(n);
	for (auto x : nums) {
		bucket[x * n].push_back(x);
	}
	int k = 0;
	for (auto& lst : bucket) {
		lst.sort();
		for (auto x : lst) {
			nums[k++] = x;
		}
	}
}

void TestCountSort(){
	cout << "---TestCountSort START---" << endl;
	vector<int> nums(InitNums(10, 10, 20));
	printNums(nums);
	countSort(nums, 10, 20);
	printNums(nums);
	cout << "---TestCountSort END---" << endl;
}

void TestRadixSort() {
	cout << endl;
	cout << "---TestRadixSort START---" << endl;
	vector<int> nums(InitNums(15, 9980, 9999));
	printNums(nums);
	radixSort(nums, 4);
	printNums(nums);
	cout << "---TestRadixSort END---" << endl;
}

void TestBucketSort() {
	cout << endl;
	cout << "---TestBucketSort START---" << endl;
	vector<double> nums(InitDoubleNums(8, 0, 0.9999));
	printNums(nums);
	bucketSort(nums);
	printNums(nums);
	cout << "---TestBucketSort END---" << endl;
}