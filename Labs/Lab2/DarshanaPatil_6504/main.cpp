//Darshana Patil

#include<iostream>
#include<vector>

using namespace std;

int procesOperations(int currentValue, int total, char queue)
{
		if (queue != ' ')
		{
			if (queue == '+')
			{
			    total += currentValue;
				return total;
				
			}
			else if (queue == '*')
			{
				total = total * currentValue;
				return total;
			}
			else if (queue == '-')
			{
				total -= currentValue;
				return total;
			}
			else if (queue == '=')
			{
				if (currentValue != 0)
				{
					total = currentValue;
					return total;
				}
				
			}

		}
		
}

int processCurrentValue(int curr, char input)
{
	curr *= 10;
	curr += (input - '0');

	return curr;
}


int main()
{
	int total = 0;
	int currentValue = 0;

	char input, queue = ' ';

	do {
		cout << "Total Value = " << total << endl;
		cout << "Current Value = " << currentValue << endl;
		cout << "queue = " << queue << endl;

		cin >> input;
		if (input >= '0' && input <= '9')
		{
			currentValue=processCurrentValue(currentValue,input);

		}
		else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '=' || input == 'c')
		{
			total = procesOperations(currentValue, total, queue);
			currentValue = 0;
			queue = input;
		}

		if (input == 'c')
		{
			total = 0;
			currentValue = 0;
			queue = ' ';
		}

	} while (input != 'q');

	return input;

}
