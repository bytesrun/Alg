#ifndef _INIT_NUMS_H_
#define _INIT_NUMS_H_
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

vector<int> InitNums(int n = 10, int st = -100, int ed = 100);
vector<double> InitDoubleNums(int n = 10, double st = -1.0, double ed = 1.0);
//void printNums(vector<int> &nums);
template <typename T>
void printNums(vector<T> &nums) {
	copy(nums.begin(), nums.end(), ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}
int getRandomInt(int st = 100, int ed = 100);
#endif