#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iterator>
#include <algorithm>

#include "InitNums.h"
#include "InsertionSort.h"
#include "FindMaxSubArray.h"
using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "HELLO WORLD" << std::endl;
	test();
	vector<int> nums(InitNums(10));	
	vector<int> nums2(nums);
	printNums(nums);
	InsertionSort(nums);
	printNums(nums);

	printNums(nums2);
	InsertionSort_r(nums2);
	printNums(nums2);
	
	Test_FindMaxSubArray();
	
	return 0;
}