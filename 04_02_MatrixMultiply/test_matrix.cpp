#include "mymatrix.h"
#include <iostream>
void Test_Matrix() {
	std::cout << "---Test Matrix Multiply START---" << std::endl;
	MyMatrix ma(2, 2);
	MyMatrix mb(2, 3);
	MyMatrix mc = ma*mb;
	std::cout << ma <<endl << mb << endl << mc;	
	std::cout << "---Test Matrix Multiply END---" << std::endl;
}