#include <vector>
#include <iostream>
using namespace std;
class MyMatrix {
public:
	MyMatrix();
	MyMatrix(int rows, int cols);
	MyMatrix(int rows, int cols, vector<vector<int>>& nums);
	
	const int& getRows() const;
	const int& getCols() const;
	const int& getNum(int row, int col) const;
	bool setNum(int row, int col, int val);
private:
	const int _rows;
	const int _cols;
	vector<vector<int>> _data;
};

ostream& operator<< (ostream& os, MyMatrix& m);
const MyMatrix operator*(const MyMatrix& a, const MyMatrix& b);