#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool Conjunction(bool p, bool q) {
    return p && q;
}

bool Disjunction(bool p, bool q) {
    return p || q;
}

bool Negation(bool p) {
    return !p;
}

bool Exclusiveor(bool p, bool q) {
    return Conjunction(Disjunction(p, q), Negation(Conjunction(p, q)));
}

bool Conditional(bool p, bool q) {
    return Conjunction(Disjunction(p, q), Negation(p));
}

bool BiConditional(bool p, bool q) {
    return Conjunction(Conditional(p, q), Conditional(q, p));
}

int PrecedenceOperator(char op) {

    if (op == '~') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    if (op == '^') return 1;
    if (op == '>') return 0;
    if (op == '=') return 0;

}


bool ApplyOperator(char op, bool p1, bool p2) {

    switch (op) {

    case '&': return p1 && p2;
    case '|': return p1 || p2;
    case '^': return p1 ^ p2;
    case '>': return (!p1 || p2);
    case '=': return (p1 == p2);

    }

    return false;
}
bool EvaluateExpressionOperator(const string& expr, const vector<bool>& values) {

    vector<bool> expressionvector;
    vector<char> operatorvector;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (isalpha(ch)) {
            if (ch >= 'A' && ch < 'A' + values.size()) {
                expressionvector.push_back(values[ch - 'A']);
            }
            else {
                cout << "Variable " << ch << " Out of range." << endl;

                return false;

            }
        }

        else if (ch == '~') {
            if (!expressionvector.empty()) {
                expressionvector.back() = !expressionvector.back();
            }
            else {
                cout << "Invalid NOT Operation" << endl;

                return false;

            }
        }

        else if (ch == '&' || ch == '|' || ch == '^' || ch == '>' || ch == '=') {
            while (!operatorvector.empty() && PrecedenceOperator(operatorvector.back()) >= PrecedenceOperator(ch)) {
                char op = operatorvector.back();
                operatorvector.pop_back();
                bool right = expressionvector.back();
                expressionvector.pop_back();
                bool left = expressionvector.back();
                expressionvector.pop_back();
                expressionvector.push_back(ApplyOperator(op, left, right));
            }
            operatorvector.push_back(ch);
        }
    }

    while (!operatorvector.empty()) {
        char op = operatorvector.back(); operatorvector.pop_back();
        bool right = expressionvector.back();
        expressionvector.pop_back();
        bool left = expressionvector.back();
        expressionvector.pop_back();
        expressionvector.push_back(ApplyOperator(op, left, right));
    }

    return expressionvector.back();

}
void TruthTable(int nV, const string& expression) {
    int NumberRows = pow(2, nV);
    vector<string> variables(nV);

    for (int i = 0; i < nV; ++i) {
        variables[i] = 'A' + i;
    }
    for (int i = 0; i < variables.size(); ++i) {
        cout << variables[i] << " ";
    }
    cout << expression << endl;

    for (int i = 0; i < NumberRows; ++i) {
        vector<bool> values(nV);
        for (int j = 0; j < nV; ++j) {
            values[j] = (i & (1 << (nV - j - 1))) != 0;
            cout << values[j] << " ";
        }

        bool result = EvaluateExpressionOperator(expression, values);
        cout << result << endl;

    }
}

int main() {
    int NumberOfVariables;
    string Expression;

    cout << "Enter Number of Variables: ";
    cin >> NumberOfVariables;
    cout << "Enter Logical Expression: " << endl;
    cin >> Expression;

    TruthTable(NumberOfVariables, Expression);

    return 0;
}
