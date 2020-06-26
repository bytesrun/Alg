#include "mymatrix.h"
#include "InitNums.h"
MyMatrix::MyMatrix() : _rows(0), _cols(0){
	
}

MyMatrix::MyMatrix(int rows, int cols) : _rows(rows), _cols(cols) {
	for (int i = 0; i < rows; ++i) {
		vector<int> tmp = InitNums(cols, 1, 10);
		printNums(tmp);
		_data.push_back(tmp);
	}
}

MyMatrix::MyMatrix(int rows, int cols, vector<vector<int>>& nums) : _rows(rows), _cols(cols) {
	try {
		for (int i = 0; i < _rows; ++i) {
			_data.push_back({});
			for (int j = 0; j < _cols; ++j) {
				_data[i].push_back(nums[i][j]);
			}
		}
	}
	catch(...) {
		MyMatrix(rows, cols);
	}
}

const int& MyMatrix::getRows() const {
	return _rows;
}

const int& MyMatrix::getCols() const {
	return _cols;
}

const int& MyMatrix::MyMatrix::getNum(int row, int col) const{
	return _data[row][col];
}

bool MyMatrix::setNum(int row, int col, int val) {
	if (row < 0 || row >= _rows) return false;
	if (col < 0 || col >= _cols) return false;
	_data[row][col] = val;
	return true;
}

std::ostream& operator<< (ostream& os, MyMatrix& m) {
	os << "Matrix: " << endl;//Generally this should be deleted.
	int rows = m.getRows();
	int cols = m.getCols();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			os << m.getNum(i, j) << " ";
		}
		os << endl;
	}
	os << "---------------" << endl;//Generally this should be deleted.
	return os;
}

const MyMatrix operator*(const MyMatrix& a, const MyMatrix& b) {
	if (a.getCols() != b.getRows()) {
		return MyMatrix();
	}
	MyMatrix ans(a.getRows(), b.getCols());
	for (int i = 0; i < a.getRows(); ++i) {		
		for (int j = 0; j < b.getCols(); ++j) {
			//ans[i][j] = 0;
			ans.setNum(i, j, 0);
			int res = 0;
			for (int k = 0; k < a.getCols(); ++k) {
				//ans[i][j] = ans[i][j] + a[i][k] * b[k][j];
				res = res + a.getNum(i, k) * b.getNum(k, j);
			}
			ans.setNum(i, j, res);
		}
	}
	return ans;
}


