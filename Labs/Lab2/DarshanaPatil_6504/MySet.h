#pragma once
#include<vector>
using namespace std;

class MySet
{

private:
	vector<int> items;

public:
	MySet();
	void addItem(int);
	void removeItem(int);
	bool isItemOf(int item);
	bool isSubSetOf(MySet);
	int size();
};

