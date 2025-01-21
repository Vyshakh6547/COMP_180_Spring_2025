#include <vector>
#include<iostream>

using namespace std;

int ProcessQueue(int total, int current, char oper)
{
    if (oper == '+') return total + current;
    if (oper == '-') return total - current;
    if (oper == '/') return total / current;
    if (oper == '*') return total * current;
    if (oper == '=' && current != 0) return current;
    if (oper == ' ') return total;

}

int main() {
    vector<char> opQueue;
    int totalValue = 0, currValue = 0;
    char input, queue = ' ';
    opQueue.push_back(input);
    totalValue = ProcessQueue(totalValue, currValue, queue);
    for (auto op : opQueue) {
        cout << op;
    }
    do {
        cout << "Total Value =" << totalValue << endl;
        cout << "Current Value = " << currValue << endl;
        cin >> input;
        if (input >= '0' && input <= '9') {
            currValue *= 10;
            currValue += (input - '0');
        }
        if (input == '+' || input == '-' || input == '*' || input == '/' || input == '=') {
            if (queue != ' ')
            {
                if (queue == '+')
                {
                    totalValue += currValue;
                    currValue = 0;
                    queue = input;
                }
                else if (queue == '-')
                {
                    totalValue -= currValue;
                    currValue = 0;
                    queue = input;
                }
                else if (queue == '*')
                {
                    totalValue *= currValue;
                    currValue = 0;
                    queue = input;
                }
                else if (queue == '/')
                {
                    totalValue /= currValue;
                    currValue = 0;
                    queue = input;
                }
                else if (queue == '=')
                {
                    if (currValue != 0) totalValue = currValue;
                    currValue = 0;
                    queue = input;
                }
            }
            else {
                totalValue = currValue;
                currValue = 0;
                queue = input;
            }

        }

    } while (input != 'q');

    return 0;
}
