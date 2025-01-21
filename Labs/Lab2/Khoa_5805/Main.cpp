/*
Thai Dang Khoa Tran
COMP 180
Lab 2: User-Defined Functions Lab
*/

#include <iostream>;
#include <vector>

using namespace std;

int validInputNum(int value, int inputValue) {
	value *= 10;
	value += (inputValue - 48);

	return value;
}

int calOperator(int totalVal, int curVal, char op) {
	if (op == '+') return totalVal + curVal;
	if (op == '-') return totalVal - curVal;
	if (op == '*') return totalVal * curVal;
	if (op == '/') return totalVal / curVal;
	if (op == '=') {
		if (curVal != 0) return curVal;
	}

	return totalVal;
}

int main() {
	vector<char> opList;

	char input, queue = ' ';
	int totalValue = 0, currValue = 0;
	cout << "Here is Calculator Simulator!" << endl;
	do {
		cout << "Total value: " << totalValue << endl;
		cout << "Current value: " << currValue << endl;
		cout << "Valid input: 0-9, +, -, *, /, (=) equal sign, (c)lear, (q)uit" << endl;
		cin >> input;

		if (input >= '0' && input <= '9') {
			currValue = validInputNum(currValue, input);
		}
		else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '=') {
			if (queue != ' ') {
				totalValue = calOperator(totalValue, currValue, queue);
				currValue = 0;
				queue = input;
			}
			else {
				totalValue = currValue;
				currValue = 0;
				queue = input;
			}
		}
		else if (input == 'c') {
			totalValue = 0;
			currValue = 0;
			queue = ' ';
		}
	} while (input != 'q');
	return 0;
}