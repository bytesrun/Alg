#include <vector>
#include <iostream>
#include <algorithm>
#include "InitNums.h"
using namespace std;
int FindMin(vector<int>& nums) {
	int ans = nums[0];
	int i = 1;
	for (; i + 1 < nums.size(); ++i) {
		int tmp = min(nums[i], nums[i + 1]);
		ans = min(ans, tmp);
	}
	if (i < nums.size()) ans = min(ans, nums[i]);
	
	return ans;
}

int FindMax(vector<int>& nums) {
	int ans = nums[0];
	int i = 1;
	for (; i + 1 < nums.size(); ++i) {
		int tmp = max(nums[i], nums[i + 1]);
		ans = max(ans, tmp);
	}
	if (i < nums.size()) ans = max(ans, nums[i]);
	
	return ans;
}

void testMinMax() {
	cout << endl;	
	cout << "---Test Min & Max START---" << endl;
	for (int i = 0; i < 5; ++i) {
		vector<int> nums(InitNums());
		cout << nums;
		cout << "Min: " << FindMin(nums) << endl;
		cout << "Max: " << FindMax(nums) << endl << endl;
	}		
	cout << "---Test Min & Max End---" << endl;
}

int partition(vector<int>& nums, int st, int ed) {
	if (st == ed - 1) return st;
	int id = getRandomInt(st, ed - 1);
	swap(nums[ed - 1], nums[id]);
	int q = st - 1;
	for (int i = st; i < ed - 1; ++i) {
		if (nums[i] < nums[ed - 1]) {
			swap(nums[++q], nums[i]);
		}
	}
	swap(nums[++q], nums[ed - 1]);
	return q;
}	

int RandomizedSelect(vector<int>& nums, int st, int ed, int k) {
	if (st == ed - 1) return nums[st];
	int q = partition(nums, st, ed);
	if (q + 1 == k) return nums[q];
	if (q + 1 < k) {
		return RandomizedSelect(nums, q + 1, ed, k);
	}
	else {
		return RandomizedSelect(nums, st, q, k);
	}	
}

int partition(vector<int> & nums, int st, int ed, int key) {
	int q = st - 1;
	bool bKey = true;
	for (int i = st; i < ed - 1; ++i) {
		if (nums[i] < key) {
			swap(nums[++q], nums[i]);
		}
		else if (nums[i] == key && bKey) {
			swap(nums[i--], nums[ed - 1]);
			bKey = false;
		}
	}
	swap(nums[++q], nums[ed - 1]);
	return q;
}

int getMedianKey(vector<int>& nums, int st, int ed) {
	int len = ed - st;
	//if (len < 5) return nums[st + (ed - st) / 2];
	int n = len / 5;
	int m = len % 5;
	//vector<vector<int>> subArrays;
	vector<int> medianNums;
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		auto it = nums.begin() + i * 5;
		tmp.push_back(*it);
		it = next(it);
		for (; it != nums.begin() + i * 5 + 5; ++it) {
			auto lst = tmp.begin();
			while (lst != tmp.end() && *lst < *it) {
				++lst;
			}
			tmp.insert(lst, *it);
		}
		//subArrays.push_back(tmp);
		medianNums.push_back(tmp[2]);
	}
	for (int i = 0; i < m; ++i) {
		vector<int> tmp;
		auto it = nums.begin() + n * 5;
		tmp.push_back(*it);
		it = next(it);
		for (; it != nums.end(); ++it) {
			auto lst = tmp.begin();
			while (lst != tmp.end() && *lst < *it) {
				++lst;
			}
			tmp.insert(lst, *it);
		}
		//subArrays.push_back(tmp);
		medianNums.push_back(tmp[(m - 1) / 2]);
	}	
	int sz = medianNums.size();
	return medianNums[sz/2];
	
}

int select(vector<int>& nums, int st, int ed, int k) {	
	int median = getMedianKey(nums, 0, ed);
	int q = partition(nums, st, ed, median);
	if (q + 1 == k) return nums[q];
	if (q + 1 < k) {
		return select(nums, q + 1, ed, k);
	}
	else {
		return select(nums, st, q, k);
	}	
}

void RandomizedSelect_KthElement() {
	cout << endl;
	cout << "---RandomizedSelect_KthElement START---" << endl;
	
	for (int i = 0; i < 5; ++i) {
		vector<int> nums(InitNums());
		cout << nums;
		
		int k = getRandomInt(1, nums.size());
		int tmp = RandomizedSelect(nums, 0, nums.size(), k);
		sort(nums.begin(), nums.end());
		
		cout << nums;		
		cout << k << "th Element: " << tmp << endl << endl;
	}
	
	cout << "---RandomizedSelect_KthElement End---" << endl;
}

void Select_KthElement() {
	cout << endl;
	cout << "---Select_KthElement START---" << endl;
	for (int i = 0; i < 5; ++i) {
		vector<int> nums(InitNums());
		cout << nums;
		
		int k = getRandomInt(1, nums.size());
		int tmp = select(nums, 0, nums.size(), k);
		sort(nums.begin(), nums.end());
		
		cout << nums;		
		cout << k << "th Element: " << tmp << endl << endl;
	}
	cout << "---Select_KthElement End---" << endl;
}
