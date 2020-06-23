#include <iostream>
#include <vector>
#include "InsertionSort.h"
#include <random>
#include <ctime>
#include <iterator>
#include <algorithm>
using namespace std;

vector<int> InitNums(int n=10) {
	vector<int> tmp;
	uniform_int_distribution<int> u(0, 100);
	default_random_engine e(time(NULL));
	for (int i=0; i<10; ++i) {
		tmp.push_back(u(e));
	}	
	return tmp;
}

void printNums(vector<int> &nums) {
	copy(nums.begin(), nums.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
int main(int argc, char *argv[]) {
	std::cout << "HELLO WORLD" << std::endl;
	test();
	vector<int> nums(InitNums(10));
	
	printNums(nums);
	InsertionSort(nums);
	printNums(nums);
	
	return 0;
}