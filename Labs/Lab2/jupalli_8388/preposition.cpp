#include <iostream>
using namespace std;

bool conjunction1(bool p, bool q) {
    return p && q;
}

bool disjunction1(bool p, bool q) {
    return p || q;
}

bool negation1(bool p) {
    return !p;
}

bool exclusive_or(bool p, bool q) {
    return conjunction1(disjunction1(p, q), negation1(conjunction1(p, q)));
}

bool conditional1(bool p, bool q) {
    return disjunction1(negation1(p), q);
}

bool bi_conditional(bool p, bool q) {
    return conjunction1(conditional1(p, q), conditional1(q, p));
}

bool evaluate_expression(const string& expr, bool p, bool q, bool r) {
    for (int i = 0; i < expr.length(); i++) {
        switch (expr[i]) {
        case '^':
            return conjunction1(p, q);
        case '~':
            return negation1(p);
        case 'v':
            return disjunction1(p, q);
        case 'x':
            return exclusive_or(p, q);
        case '>':
            return conditional1(p, q);
        case '=':
            return bi_conditional(p, q);
        default:
            break;
        }
    }
    return false;
}

int main() {
    string expr;
    cout << "Enter a logical expression: ";
    cin >> expr;

    cout << "p\tq\tr\t" << expr << endl;

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool result = evaluate_expression(expr, p, q, r);
                cout << (p ? "T" : "F") << "\t"
                    << (q ? "T" : "F") << "\t"
                    << (r ? "T" : "F") << "\t"
                    << (result ? "T" : "F") << endl;
            }
        }
    }
    return 0;
}
