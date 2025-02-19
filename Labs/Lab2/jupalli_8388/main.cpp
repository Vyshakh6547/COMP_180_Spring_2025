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

bool evaluateExpression(bool p, bool q, bool r, const string& expr) {
    if (expr == "p") return p;
    if (expr == "q") return q;
    if (expr == "r") return r;
    if (expr == "~p") return negation1(p);
    if (expr == "~q") return negation1(q);
    if (expr == "~r") return negation1(r);
    if (expr == "p^q") return conjunction1(p, q);
    if (expr == "pvq") return disjunction1(p, q);
    if (expr == "pxq") return exclusive_or(p, q);
    if (expr == "p>q") return conditional1(p, q);
    if (expr == "p=q") return bi_conditional(p, q);
    if (expr == "p^q^r") return conjunction1(conjunction1(p, q), r);
    if (expr == "pvqvr") return disjunction1(disjunction1(p, q), r);
    if (expr == "pxqxr") return exclusive_or(exclusive_or(p, q), r);
    if (expr == "p>q>r") return conditional1(p, conditional1(q, r));
    if (expr == "p=q=r") return bi_conditional(bi_conditional(p, q), r);
    if (expr == "(p^q)v(r)") return disjunction1(conjunction1(p, q), r);
    if (expr == "(pvq)^r") return conjunction1(disjunction1(p, q), r);

    return false;
}

int main() {
    string expr;
    cout << "Enter a logical expression (use p, q, r, ~ for NOT, ^ for AND, v for OR, x for XOR, > for IMPLIES, = for IFF): ";
    cin >> expr;

    cout << "p\tq\tr\t" << expr << endl;

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool result = evaluateExpression(p, q, r, expr);
                cout << (p ? "T" : "F") << "\t"
                    << (q ? "T" : "F") << "\t"
                    << (r ? "T" : "F") << "\t"
                    << (result ? "T" : "F") << endl;
            }
        }
    }
    return 0;
}
