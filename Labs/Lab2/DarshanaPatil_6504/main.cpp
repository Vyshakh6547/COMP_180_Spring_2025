#include<iostream>

using namespace std;

bool processAndOperation(bool p, bool q)
{
    return p && q;
}

bool processOrOperation(bool p, bool q)
{

    return p || q;

}

bool processNegationOperation(bool p)
{
    return !p;
}

bool processExclusiveOrOpeation(bool p, bool q) {
    return processAndOperation(processOrOperation(p, q), processNegationOperation(processAndOperation(p, q)));
}

bool processConditionalOperation(bool p, bool q) {
    return processOrOperation(processNegationOperation(p), q);
}

bool processBi_conditionalOperation(bool p, bool q) {
    return processAndOperation(processConditionalOperation(p, q), processConditionalOperation(q, p));
}

bool generateTruthTable(const string& input, bool p, bool q, bool r)
{
    bool result;
    for (int i = 0; i < input.length(); i++)
    {
           switch (input[i])
           {
           case '&':
                 result =  processAndOperation(p, q);
                   return result;
                   break;
           case '~':
                    result =  processNegationOperation(p);
                      return result;
                   break;
           case '|':
                   result = processOrOperation(p, q);
                   return result ;
                   break;
           case '^':
                    result = processExclusiveOrOpeation(p, q);
                    return result ;
                    break;
           case '>':
                    result = processConditionalOperation(p, q);
                    return result ;
                    break;
           case '=':
                   result = processBi_conditionalOperation(p, q);
                   return result ;
                   break;
           default:
               break;
           }
       }
    
    return false;
}

int main()
{
    bool p, q, result;
    string input;
    int currValue;


//        cout << "1. Conjuction(and) &" << endl;
//        cout << "2. Disjuction (or) | " << endl;
//        cout << " 3. Negation (not) ~" << endl;
//        cout << "4. Exclusive or (xor) ^" << endl;
//        cout << "5. Conditional (implication) >" << endl;
//        cout << " 6. Bi- conditional = " << endl;

        cout << "s Enter the operation you want to do -" << endl;
        cin >> input;
        
        cout << "p   ";
        cout<<  "q   ";
        cout<<  "r   " << input << endl;

       
        for (int p = 0; p <= 1; p++)
        {
                for (int q = 0; q <= 1; q++)
                {
                    for (int r = 0; r <= 1; r++)
                    {
                        bool op= generateTruthTable(input, p, q, r);
                        cout << (p ? "1" : "0") << "\t"
                            << (q ? "1" : "0") << "\t"
                            << (r ? "1" : "0") << "\t"
                            << (op ? "1" : "0") << endl;
                    }
                }
            }

    return 0;
}
