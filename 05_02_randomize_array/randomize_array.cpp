#include "InitNums.h"
#include <iostream>
using namespace std;
void MyRandomizeArray(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		int x = getRandomInt(0, 100) % n;
		swap(nums[i], nums[x]);
	}
}
void Test_Randomize_Array() {
	cout << endl;
	cout << "---Test_Randomize_Array START---" << endl;
	vector<int> nums(InitNums());
	cout << "Before processing: " << endl;
	printNums(nums);
	MyRandomizeArray(nums);
	cout << "After processing: " << endl;
	printNums(nums);
	cout << "---Test_Randomize_Array END---" << endl;
	cout << endl;
}

