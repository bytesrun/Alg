#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "InitNums.h"
using namespace std;

vector<int> FindMaxCrossSubArray(vector<int>& nums, int st, int ed) {
	//if (st == ed) return {nums[st], st, ed};
	int sum = 0;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int mid = (st + ed)/2;
	int left = mid;
	int right = mid;
	
	for (int i = mid; i >= 0; --i) {
		sum += nums[i];
		if (sum > left_sum) {
			left_sum = sum;
			left = i;
		}
	}
	
	sum = 0;
	for (int i = mid + 1; i <= ed; ++i) {
		sum += nums[i];
		if (sum > right_sum) {
			right_sum = sum;
			right = i;
		}
	}
	
	return {left_sum + right_sum, left, right};
}
//return: sum, start pos, end pos
vector<int> FindMaxSubArray(vector<int>& nums, int st, int ed) {
	if (st == ed) {
		return {nums[st], st, ed};
	}
	
	int mid = st + (ed-st)/2;
	vector<int> leftRes = FindMaxSubArray(nums, st, mid);
	vector<int> rightRes = FindMaxSubArray(nums, mid + 1, ed);
	vector<int> midRes = FindMaxCrossSubArray(nums, st, ed);
	if (leftRes[0] >= rightRes[0] && leftRes[0] >= midRes[0]) {
		return leftRes;
	}
	else if (rightRes[0] >= leftRes[0] && rightRes[0] >= midRes[0]) {
		return rightRes;
	}
	
	return midRes;
}

void Test_FindMaxSubArray(int n, vector<int>* pNums) {
	cout << "---Test_FindMaxSubArray START---" << endl;
	vector<int> nums;
	if (pNums) {
		copy(pNums->begin(), pNums->end(), back_inserter(nums));
	}
	else {
		vector<int> tmp(InitNums(n));
		copy(tmp.begin(), tmp.end(), back_inserter(nums));
	}	
	printNums(nums);
	vector<int> res(FindMaxSubArray(nums, 0, nums.size()-1));
	printNums(res);
	cout << "----Test_FindMaxSubArray END---" << endl;
	
}