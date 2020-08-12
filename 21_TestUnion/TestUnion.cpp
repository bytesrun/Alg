#include <vector>
#include <iostream>
#include "InitNums.h"

class MyUnion {
public:
	explicit MyUnion(std::vector<int>& nums) : _dat(nums) {
		int n = nums.size();
		std::fill_n(std::back_inserter(_rank), n, 1);
		for (int i = 0; i < n; ++i) {
			_par.push_back(i);
		}
	}
	
	int findParent(int id) {
		/*int tmp = id;
		while (_par[id] != id) {
			id = _par[id];
		}
		return _par[tmp] = id;*/
		if (_par[id] != id) {
			_par[id] = findParent(_par[id]);
		}
		return _par[id];
	}
	
	bool Union(int a, int b) {
		int pa = findParent(a);
		int pb = findParent(b);
		if (pa == pb) return false;
		if (_rank[pa] < _rank[pb]) {
			_par[pa] = pb;
		}
		else {
			_par[pb] = pa;
		}
		if (_rank[pa] == _rank[pb]) ++_rank[pa];
		return true;
	}
	
	std::vector<std::vector<int>> groups() {
		for (int i = 0; i < _dat.size(); ++i) {
			Union(i, _dat[i]);
		}
		printNums(_par);
	}
public:
	std::vector<int> _dat;
	std::vector<int> _par;
	std::vector<int> _rank;	
};

void TestUnion() {
	std::cout << "-----*TEST UNION START*------" << std::endl;
	vector<int> nums;
	for (int i = 0; i < 10; ++i) {
		int tmp = getRandomInt(0, 100) % 10;
		nums.push_back(tmp);
	}
	printNums(nums);
	MyUnion un(nums);
	printNums(un._par);
	un.groups();
	std::cout << "-----*TEST UNION END*------" << std::endl;
}