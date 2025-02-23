/*
Thai Dang Khoa Tran
COMP 180
Propositional Logic Lab
*/
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool logicCal(char op, bool val1, bool val2) {
	switch (op) {
	case '&': return val1 && val2;
	case '|': return val1 || val2;
	case '~': return !val1;
	case '^': return (val1 && !val2) || (!val1 && val2);
	case '>': return (!val1 || val2);
	case '=': return (val1 && val2) || (!val1 && !val2);
	default: return false;
	}
}

char printTF(bool val) {
	if (val) return 'T';
	return 'F';
}

void print1param(char inp, char op) {
	cout << inp << "    " << op << inp << endl;
	for (bool val : {false, true}) {
		cout << printTF(val) << "    " << printTF(logicCal(op, val, val)) << endl;
	}
}

void print2param(vector<char> var, vector<char> op, string statement) {
	char val1 = var[0];
	char val2 = var[1];
	bool prevFirstVal;
	bool prevSecondVal;

	cout << val1 << "\t" << val2;

	for (int i = 0; i < op.size(); i++) {
		cout << "\t" << statement.substr(0, 1 + (i + 1) * 2);
	}

	cout << endl;

	for (bool pVal : {false, true}) {
		for (bool qVal : {false, true}) {
			cout << printTF(pVal) << "\t" << printTF(qVal);
			prevFirstVal = logicCal(op[0], pVal, qVal);
			for (int i = 0; i < op.size(); i++) {
				string substr = statement.substr(0, 1 + (i + 2) * 2);
				cout << "\t" << printTF(prevFirstVal);
				if (i < op.size() - 1) {
					if (substr.back() == val1) prevSecondVal = pVal;
					else prevSecondVal = qVal;
					prevFirstVal = logicCal(op[i + 1], prevFirstVal, prevSecondVal);
				}
			}
			cout << endl;
		}
	}
}

void print3param(vector<char> var, vector<char> op, string statement) {
	char val1 = var[0];
	char val2 = var[1];
	char val3 = var[2];
	bool prevFirstVal;
	bool prevSecondVal;

	cout << val1 << "\t" << val2 << "\t" << val3;

	for (int i = 0; i < op.size(); i++) {
		cout << "\t" << statement.substr(0, 1 + (i + 1) * 2);
	}

	cout << endl;

	for (bool pVal : {false, true}) {
		for (bool qVal : {false, true}) {
			for (bool rVal : {false, true}) {
				cout << printTF(pVal) << "\t" << printTF(qVal) << "\t" << printTF(rVal);
				prevFirstVal = logicCal(op[0], pVal, qVal);
				for (int i = 0; i < op.size(); i++) {
					string substr = statement.substr(0, 1 + (i + 2) * 2);
					cout << "\t" << printTF(prevFirstVal);
					if (i < op.size() - 1) {
						if (substr.back() == val1) prevSecondVal = pVal;
						else if (substr.back() == val2) prevSecondVal = qVal;
						else prevSecondVal = rVal;
						prevFirstVal = logicCal(op[i + 1], prevFirstVal, prevSecondVal);
					}
				}
				cout << endl;
			}
		}
	}
}

int main() {
	string statement;
	vector<char> variables;
	vector<char> op;

	cout << "Conjunction(and): &" << endl;
	cout << "Disjunction(or): |" << endl;
	cout << "Negation(not): ~" << endl;
	cout << "Exclusive or (xor): ^" << endl;
	cout << "Conditional(implication): >" << endl;
	cout << "Bi - Conditional: =" << endl;
	cout << "Enter a propositional logical statement: " << endl;
	cin >> statement;

	for (char c : statement) {
		if (isalpha(c) && count(variables.begin(), variables.end(), c) == 0) {
			variables.push_back(c);
		}
		else op.push_back(c);
	}

	cout << "Truth Table:\n";

	if (variables.size() == 3) {
		print3param(variables, op, statement);
	}
	if (variables.size() == 2) {
		print2param(variables, op, statement);
	}
	if (variables.size() == 1) {
		print1param(op.front(), *variables.begin());
	}

	return 0;
}