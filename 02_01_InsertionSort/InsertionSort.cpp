#include <vector>
#include <iostream>
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