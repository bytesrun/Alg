#ifndef _INIT_NUMS_H_
#define _INIT_NUMS_H_
#include <vector>
using namespace std;

vector<int> InitNums(int n = 10, int st = -100, int ed = 100);
void printNums(vector<int> &nums);
int getRandomInt(int st = 100, int ed = 100);
#endif