#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "InitNums.h"
using namespace std;
namespace {	
	default_random_engine e(time(NULL));
}
vector<int> InitNums(int n, int st, int ed) {
	vector<int> tmp;
	uniform_int_distribution<int> u(st, ed);
	for (int i=0; i<n; ++i) {
		tmp.push_back(u(e));
	}	
	return tmp;
}

vector<double> InitDoubleNums(int n, double st, double ed) {
	vector<double> tmp;
	uniform_real_distribution<double> u(st, ed);
	for (int i=0; i<n; ++i) {
		tmp.push_back(u(e));
	}	
	//cout << u.max() << endl;
	//cout << u.min() << endl;
	return tmp;
}
/*
void printNums(vector<int> &nums) {
	copy(nums.begin(), nums.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}*/

int getRandomInt(int st, int ed)
{
	uniform_int_distribution<int> u(st, ed);
	//default_random_engine e(time(NULL));
	return u(e);
}