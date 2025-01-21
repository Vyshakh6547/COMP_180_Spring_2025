/*
jupalli Bhavanand
lab-01
*/
#include <iostream>
using namespace std;


int add(int num1, int num2) {
	return num1 + num2;

}
int sub(int num3, int num4) {
	 return num3 - num4;
}
int multiply(int num5, int num6) {
	return num5 * num6;
}

int division(int num7, int num8) {
	return num7 / num8;
}

int main() {
	int total_value = 0;
	int current_value = 0;
	char input, queue = ' ';


	

	do {
		cout << "totalvalue" << total_value << endl;
		cout << "currentvalue" << current_value << endl;
		cout << "to exit press p" << endl;
		cout << "queue" << queue << endl;
		cin >> input;
		if (input >= '0' && input <= '9') {
			current_value *= 10;
			current_value += (input - '0');
		}
		else if (input == '+' || input == '-' || input == '/' || input == '*' || input == '=') {
			if (queue != ' ') {
				if (queue == '+') {
					total_value = add(total_value,current_value);
					current_value = 0;
					queue = input;
				}
				else if (queue == '-') {
					total_value = sub(total_value, current_value);
					current_value = 0;
					queue = input;
				}
				else if (queue == '/') {
					total_value = division(total_value, current_value);
					current_value = 0;
					queue = input;
				}
				else if (queue == '*') {
					total_value = multiply(total_value, current_value);
					current_value = 0;
					queue = input;
				}
				else if (queue == '=') {
					if (current_value != 0) total_value = current_value;
					current_value = 0;
					queue = input;
				}
			}
			else {
				total_value = current_value;
				current_value = 0;
				queue = input;
			}

		}

	} while (input != 'p');










	return 0;
}
