#include<iostream>
#include <vector>
#include "MySet.h"
using namespace std;


int main()
{
	int choice;
	int item;
	MySet ms,ms1;

	ms.addItem(2);
	ms.addItem(4);
	ms.addItem(5);
	ms.addItem(6);

	ms1.addItem(2);
	ms1.addItem(4);
	ms1.addItem(5);
	ms1.addItem(6);

	cout << "Size of set 1 - " << ms.size() << endl;
	cout << "Size of set 2 -" << ms1.size() << endl;


	cout << "enter element to remove - " << endl;
	cin >> item;
	ms.removeItem(item);
	cout << "size after removing  - " << ms.size() << endl;


	cout << "Size of set - ";
	cout << ms.size() << endl;

	if (ms.isSubSetOf(ms1)) cout << "Myset is subset of set2" << endl;
	else cout << "Myset is not subset of set2" << endl;



	return 0;

}