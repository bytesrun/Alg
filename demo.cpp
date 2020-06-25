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
	
	
	Test_InsertSort();
	Test_InsertSort_r();
	
	Test_FindMaxSubArray();
	
	return 0;
}