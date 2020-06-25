#include <vector>
#include <iostream>
#include "InitNums.h"
using namespace std;
void test() {
	std::cout << "TEST" << std::endl;
}
void InsertionSort(vector<int> &nums) {
	int len = nums.size();
	if (len <= 1) return;
	
	for (int j=1; j<len; ++j) {
		int key = nums[j];
		int i = 0;
		for ( i=j-1; i>=0; --i) {
			if (nums[i] > key) {
				nums[i+1] = nums[i];
			}
			else {				
				break;
			}
		}
		nums[i+1] = key;		
	}
}

void re_helper(vector<int>& nums, int ed) {
	if (ed == 0) return;
	re_helper(nums, ed-1);
	int key = nums[ed];
	int i = ed - 1;
	for (; i >= 0; --i) {
		if (nums[i] <= key) {
			break;
		}
		nums[i + 1] = nums[i];
	}
	nums[i + 1] = key;
}
	

void InsertionSort_r(vector<int>& nums) {
	re_helper(nums, nums.size()-1);
}

void Test_InsertSort() {
	cout << "---Test InsertionSort START---" << endl;
	vector<int> nums(InitNums(10));	
	printNums(nums);
	InsertionSort(nums);
	printNums(nums);	
	cout << "---Test InsertionSort END---" << endl << endl;
}
void Test_InsertSort_r() {
	cout << "---Test InsertionSort_r START---" << endl;
	vector<int> nums(InitNums(10));	
	printNums(nums);
	InsertionSort_r(nums);
	printNums(nums);
	cout << "---Test InsertionSort_r END---" << endl << endl;
}