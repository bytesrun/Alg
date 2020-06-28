#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iterator>
#include <algorithm>

#include "InitNums.h"

#include "configure.h"

#ifdef INSERT_SORT
# include "InsertionSort.h"
#endif

#ifdef FIND_MAX_SUBARRAY
# include "FindMaxSubArray.h"
#endif 

#ifdef MATRIX_MULTIPLY
#include "test_matrix.h"
#endif

#ifdef RANDOMIZE_ARRAY
#include "randomize_array.h"
#endif

using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "HELLO TEST " << std::endl;	
	
#ifdef INSERT_SORT
	test();
	Test_InsertSort();
	Test_InsertSort_r();
#endif

#ifdef FIND_MAX_SUBARRAY
	Test_FindMaxSubArray();
#endif

#ifdef MATRIX_MULTIPLY	
	Test_Matrix();
#endif

#ifdef RANDOMIZE_ARRAY
	Test_Randomize_Array();
#endif
	
	return 0;
}