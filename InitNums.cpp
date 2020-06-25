#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

vector<int> InitNums(int n) {
	vector<int> tmp;
	uniform_int_distribution<int> u(-100, 100);
	default_random_engine e(time(NULL));
	for (int i=0; i<n; ++i) {
		tmp.push_back(u(e));
	}	
	return tmp;
}

void printNums(vector<int> &nums) {
	copy(nums.begin(), nums.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
